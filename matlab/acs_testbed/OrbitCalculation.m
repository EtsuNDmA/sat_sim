function [OrbData,MagnData,SunData]=OrbitCalculation(params,satrec_0)
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
	MaxStepCM	= params.MaxStepCM;
	DeltaStepCM = params.DeltaStepCM;
	satrec		= satrec_0;
    OrbData.Rteme     = zeros(MaxStepCM,3);
    OrbData.Vteme     = zeros(MaxStepCM,3);
    OrbData.Ateme     = zeros(MaxStepCM,3);
    OrbData.rj2000    = zeros(MaxStepCM,3);
    OrbData.vj2000    = zeros(MaxStepCM,3);
    OrbData.aj2000    = zeros(MaxStepCM,3);
    OrbData.recef     = zeros(MaxStepCM,3);
    OrbData.vecef     = zeros(MaxStepCM,3);
    OrbData.aecef     = zeros(MaxStepCM,3);
    OrbData.Qjo       = zeros(MaxStepCM,4);
    OrbData.latgc     = zeros(MaxStepCM,1);
    OrbData.latgd     = zeros(MaxStepCM,1);
    OrbData.lon       = zeros(MaxStepCM,1);
    OrbData.hellp     = zeros(MaxStepCM,1);
    OrbData.Worb_j    = zeros(MaxStepCM,3);
    
%     MagnData.Magn          = zeros(MaxStepCM,3);
    MagnData.MagnDipolECEF = zeros(MaxStepCM,3);
    MagnData.MagnDipolECI  = zeros(MaxStepCM,3);
	
	SunData.rsun	 = zeros(MaxStepCM,3);
	SunData.rsunecef = zeros(MaxStepCM,3);
	SunData.rrsuno   = zeros(MaxStepCM,3);
	SunData.sunlight = zeros(MaxStepCM,1);
	
    for StepCM=1:MaxStepCM
		tsince=StepCM*DeltaStepCM;
		tsincemin=tsince/60;
        % ��������� �����
        times=TimeOrbit(satrec.epochyr,satrec.epochdays,params,tsince);
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
		OrbData.times(StepCM,:)	  = times;
        OrbData.Rteme(StepCM,:)   = Rteme;
        OrbData.Vteme(StepCM,:)   = Vteme;
        OrbData.Ateme(StepCM,:)   = Ateme;
        OrbData.rj2000(StepCM,:)  = rj2000;
        OrbData.vj2000(StepCM,:)  = vj2000;
        OrbData.aj2000(StepCM,:)  = aj2000;
        OrbData.recef(StepCM,:)   = recef;
        OrbData.vecef(StepCM,:)   = vecef;
        OrbData.aecef(StepCM,:)   = aecef;
        OrbData.Qjo(StepCM,:)     = Qjo';
        OrbData.latgc(StepCM,:)   = latgc;
        OrbData.latgd(StepCM,:)   = latgd;
        OrbData.lon(StepCM,:)     = lon;
        OrbData.hellp(StepCM,:)   = hellp;
        OrbData.Worb_j(StepCM,:)  = Worb_j';
        
        %% ���������� ��������� ����
        %������ ������
        normRecef=norm(recef); % ��
        MagnFieldECEFdipol=(3*(params.MagnMomentum*recef)*recef'-normRecef^2*params.MagnMomentum)/normRecef^5;% ���
        [MagnFieldDipol_j,~,~] = ...
			ecef2eci(MagnFieldECEFdipol',[0 0 0]',[0 0 0]',...
            times.ttt,times.jdut1,params.lod,params.xp,params.yp,...
			params.eqeterms,params.ddpsi,params.ddeps);
        %������ IGRF 11
        %������ ��������� ���� � NED
        % !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        % ��� ���� �������� "decyear(year,mon,day,hr,minute,sec)-2" - ����� 2
        % �����,�.�. igrf11 �� �������� ����� 2014 ����!!!!!!!!!!!!!!!!!!!!!!!
        % !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
%         [MagnFieldNED, MagnHoorizIntens, MagnDecl, MagnIncl, MagnTotalIntens]...
%             = igrf11magm(hellp*1000, latgd/d2r, lon/d2r, decyear(year,mon,day,hr,minute,sec)-2);
        %����������� � ECEF
%         [MagnFieldECEF(1),MagnFieldECEF(2),MagnFieldECEF(3)] = ned2ecef( ...
%             MagnFieldNED(:,1)',MagnFieldNED(:,2)',MagnFieldNED(:,3)',...
%             latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
        %���� �� ��������� ���������� ����� ������� ��������� �������� � ECEF,
        %����� ��� ������� ���������� ������ ��������� NED � ECEF
% 
%         [x0ecef,y0ecef,z0ecef] = ned2ecef( ...
%             0,0,0,...
%             latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
%         MagnFieldECEF=MagnFieldECEF-[x0ecef y0ecef z0ecef];
        
        % �������� ����������
%         MagnData.Magn(StepCM,:)            = MagnFieldECEF;
        MagnData.MagnDipolECEF(StepCM,:)   = MagnFieldECEFdipol;
        MagnData.MagnDipolECI(StepCM,:)    = MagnFieldDipol_j;
		%% ����������� �� ������ � ��������� ������
		[SunData.rsun(StepCM,:),SunData.rsunecef(StepCM,:),SunData.sunlight(StepCM,:)]=...
			SunPosition(params,satrec,times,OrbData.rj2000);
		% ������ ������ �� ������� � ������ � j2000, ��
		rrsun=SunData.rsun(StepCM,:)*params.au2km-OrbData.rj2000(StepCM,:);
		% ������ ������ �� ������� � ������ � ���, ��
		rrsuno=quatrotate(OrbData.Qjo(StepCM,:),rrsun);
		% ��������� ������ �� ������� � ������ � ���
		SunData.rrsuno(StepCM,:)=normr(rrsuno);
    end;
    % �������� ��������� � ������ �������� � ����
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
	
	save('savedparams','savedparams');
    save('orbitData','OrbData','MagnData','SunData');
end;