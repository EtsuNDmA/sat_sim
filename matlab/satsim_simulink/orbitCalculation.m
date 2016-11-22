function [orbData,magnData,sunData,atmData]=orbitCalculation(params,satrec_0)
%% �������� ������
% ��������, ���������� �� ���� � ������������ ������� � ������� ��
% ���������� ����

fid1=fopen('orbitData.mat', 'r+');
fid2=fopen('savedparams.mat', 'r+');
if fid1>0 && fid2>0
    fclose(fid1);
    fclose(fid2);
    load('orbitData.mat');
    load('savedparams.mat');
    % ���� ��������� ����������, �� ������� ������
    newOrbit=...
		~((savedparams.DeltaStepCM			 == params.DeltaStepCM) && ...
        (savedparams.MaxStepCM				 == params.MaxStepCM) && ...
        (savedparams.teme2eci_order			 == params.teme2eci_order) && ...
        (savedparams.eqeterms				 == params.eqeterms) && ...
        (savedparams.teme2eci_opt			 == params.teme2eci_opt) && ...
        (savedparams.twoline2rv_whichconst   == params.twoline2rv_whichconst) && ...
        (savedparams.twoline2rv_typerun		 == params.twoline2rv_typerun) && ...
        (savedparams.twoline2rv_typeinput	 == params.twoline2rv_typeinput) && ...
        (savedparams.timezone				 == params.timezone) && ...
        (savedparams.dut1					 == params.dut1) && ...
        (savedparams.dat					 == params.dat) && ...
        (savedparams.Mearth					 == params.Mearth) && ...
        (savedparams.MuEarth				 == params.MuEarth) && ...
        (savedparams.lod					 == params.lod) && ...
        (savedparams.xp						 == params.xp) && ...
        (savedparams.yp						 == params.yp) && ...
        (savedparams.ddpsi					 == params.ddpsi) && ...
        (savedparams.ddeps					 == params.ddeps) && ...
		(isequal(savedparams.TLEstr1,params.TLEstr1)) && ...
        (isequal(savedparams.TLEstr2,params.TLEstr2)));
else
    newOrbit=true;
end;
%% ������ ������
if newOrbit
	MaxStepCM         = params.MaxStepCM;
	DeltaStepCM       = params.DeltaStepCM;
	satrec		      = satrec_0;
    orbData.Rteme     = zeros(MaxStepCM,3);
    orbData.Vteme     = zeros(MaxStepCM,3);
    orbData.Ateme     = zeros(MaxStepCM,3);
    orbData.rj2000    = zeros(MaxStepCM,3);
    orbData.vj2000    = zeros(MaxStepCM,3);
    orbData.aj2000    = zeros(MaxStepCM,3);
    orbData.recef     = zeros(MaxStepCM,3);
    orbData.vecef     = zeros(MaxStepCM,3);
    orbData.aecef     = zeros(MaxStepCM,3);
    orbData.Qjo       = zeros(MaxStepCM,4);
    orbData.latgc     = zeros(MaxStepCM,1);
    orbData.latgd     = zeros(MaxStepCM,1);
    orbData.lon       = zeros(MaxStepCM,1);
    orbData.hellp     = zeros(MaxStepCM,1);
    orbData.Worb_j    = zeros(MaxStepCM,3);
    
    magnData.MagnDipolECEF = zeros(MaxStepCM,3);
    magnData.MagnDipolECI  = zeros(MaxStepCM,3);
	
	sunData.rsun	 = zeros(MaxStepCM,3);
	sunData.rsunecef = zeros(MaxStepCM,3);
	sunData.rrsuno   = zeros(MaxStepCM,3);
	sunData.sunlight = zeros(MaxStepCM,1);
    
    atmData.rho = zeros(MaxStepCM,1);
	
    for StepCM=1:MaxStepCM
		tsince=StepCM*DeltaStepCM;
		tsincemin=tsince/60;
        % ��������� �����
        times=timeOrbit(satrec.epochyr,satrec.epochdays,params,tsince);
        % ������������ ����� ������ ���������
        [satrec, Rteme, Vteme] = sgp4(satrec,tsincemin);
        Ateme = zeros(1,3);
        % ��������������� ������ ��������� �� TEME � J2000
        [rj2000,vj2000,aj2000] = teme2eci  ( Rteme',Vteme',Ateme',times.ttt,...
            params.teme2eci_order,params.eqeterms,params.teme2eci_opt );
        % ��������������� ��������� �������� �� ECEF
        [recef,vecef,aecef] = eci2ecef( rj2000,vj2000,aj2000,...
			times.ttt,times.jdut1,params.lod,params.xp,params.yp,...
			params.eqeterms,params.ddpsi,params.ddeps );
        % ���������� ����������� ����� iorb, jorb korb � �������� �� J2000
        jorb=rj2000/norm(rj2000);
        korb=cross(vj2000,rj2000)/norm(cross(vj2000,rj2000));
        iorb=cross(jorb,korb);
        % ������� ������������ ��������� �� J2000 � ����������� ��
        DCMjo=[iorb';jorb';korb'];
        % ���������� �������� �� J2000 � ���
        Qjo=dcm2quat(DCMjo)';
        if Qjo(1)<0
            Qjo=-Qjo;
        end;
        %������ ������������� ������, ������� � ������ ��� �����������
        [latgc,latgd,lon,hellp] = ijk2ll ( recef );
        %����������� ������� ��������
        Worb_j=cross(rj2000',vj2000')'/(rj2000'*rj2000);
        % �������� ���������� �������� ����
		orbData.times(StepCM,:)	  = times;
        orbData.Rteme(StepCM,:)   = Rteme;
        orbData.Vteme(StepCM,:)   = Vteme;
        orbData.Ateme(StepCM,:)   = Ateme;
        orbData.rj2000(StepCM,:)  = rj2000;
        orbData.vj2000(StepCM,:)  = vj2000;
        orbData.aj2000(StepCM,:)  = aj2000;
        orbData.recef(StepCM,:)   = recef;
        orbData.vecef(StepCM,:)   = vecef;
        orbData.aecef(StepCM,:)   = aecef;
        orbData.Qjo(StepCM,:)     = Qjo';
        orbData.latgc(StepCM,:)   = latgc;
        orbData.latgd(StepCM,:)   = latgd;
        orbData.lon(StepCM,:)     = lon;
        orbData.hellp(StepCM,:)   = hellp;
        orbData.Worb_j(StepCM,:)  = Worb_j';
        
        %% ���������� ��������� ����
        %������ ������
        normRecef=norm(recef); % ��
        MagnFieldECEFdipol=(3*(params.MagnMomentum*recef)*recef'-normRecef^2*params.MagnMomentum)/normRecef^5;% ���
        [MagnFieldDipol_j,~,~] = ...
			ecef2eci(MagnFieldECEFdipol',[0 0 0]',[0 0 0]',...
            times.ttt,times.jdut1,params.lod,params.xp,params.yp,...
			params.eqeterms,params.ddpsi,params.ddeps);
        magnData.MagnDipolECEF(StepCM,:) = MagnFieldECEFdipol;
        magnData.MagnDipolECI(StepCM,:) = MagnFieldDipol_j;
		%% ����������� �� ������ � ��������� ������
		[sunData.rsun(StepCM,:),sunData.rsunecef(StepCM,:),sunData.sunlight(StepCM,:),...
            sunData.rtasc,sunData.decl]=...
			sunPosition(params,satrec,times,orbData.rj2000);
		% ������ ������ �� ������� � ������ � j2000, ��
		rrsun=sunData.rsun(StepCM,:)*params.au2km-orbData.rj2000(StepCM,:);
		% ������ ������ �� ������� � ������ � ���, ��
		rrsuno=quatrotate(orbData.Qjo(StepCM,:),rrsun);
		% ��������� ������ �� ������� � ������ � ���
		sunData.rrsuno(StepCM,:)=normr(rrsuno);
        %% ��������� ���������
        atmData.rho(StepCM)=atmgost(rj2000,hellp,times.dayOfYear,times.utc,times.gst_mn,...
            sunData.rtasc,sunData.decl,params.F107,params.F81,params.Kp);
    end;
    %% �������� ��������� � ������ �������� � ����
    savedparams.DeltaStepCM       = params.DeltaStepCM;
    savedparams.MaxStepCM         = params.MaxStepCM;
    savedparams.teme2eci_order    = params.teme2eci_order;
    savedparams.eqeterms          = params.eqeterms;
    savedparams.teme2eci_opt      = params.teme2eci_opt;
    savedparams.TLEstr1           = params.TLEstr1;
    savedparams.TLEstr2           = params.TLEstr2;
    savedparams.twoline2rv_whichconst	= params.twoline2rv_whichconst;
    savedparams.twoline2rv_typerun      = params.twoline2rv_typerun;
    savedparams.twoline2rv_typeinput	= params.twoline2rv_typeinput;
    savedparams.timezone          = params.timezone;
    savedparams.dut1              = params.dut1;
    savedparams.dat               = params.dat;
    savedparams.Mearth            = params.Mearth;
    savedparams.MuEarth           = params.MuEarth;
    savedparams.lod               = params.lod;
    savedparams.xp                = params.xp;
    savedparams.yp                = params.yp;
    savedparams.ddpsi             = params.ddpsi;
    savedparams.ddeps             = params.ddeps;
	
	save('savedparams.mat','savedparams');
    save('orbitData.mat','orbData','magnData','sunData','atmData');
end;