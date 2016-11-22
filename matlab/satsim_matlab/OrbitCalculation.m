%% �������� ������
% ��������, ���������� �� ���� � ������������ ������� � ������� ��
% ���������� ����

fid1=fopen('orbitData.mat', 'r+');
fid2=fopen('magnData.mat', 'r+');
if fid1>0 && fid2>0
    fclose(fid1);
    fclose(fid2);
    load('orbitData.mat');
    load('magnData.mat');
    % ���� ��������� ����������, �� ������� ������
    if ~((svDeltaStepCM      == DeltaStepCM) && ...
        (svMaxStepCM         == MaxStepCM) && ...
        (svteme2eci_order    == teme2eci_order) && ...
        (sveqeterms          == eqeterms) && ...
        (svteme2eci_opt      == teme2eci_opt) && ...
        (isequal(svTLEstr1,TLEstr1)) && ...
        (isequal(svTLEstr2,TLEstr2)) && ...
        (svtwoline2rv_whichconst == twoline2rv_whichconst) && ...
        (svtwoline2rv_typerun    == twoline2rv_typerun) && ...
        (svtwoline2rv_typeinput	 == twoline2rv_typeinput) && ...
        (svtimezone          == timezone) && ...
        (svdut1              == dut1) && ...
        (svdat               == dat) && ...
        (svMearth            == Mearth) && ...
        (svMuEarth           == MuEarth) && ...
        (svlod               == lod) && ...
        (svxp                == xp) && ...
        (svyp                == yp) && ...
        (svddpsi             == ddpsi) && ...
        (svddeps             == ddeps))
        
        orbitMode=0;
    else
        orbitMode=1;
    end;
else
    orbitMode=0;
end;
%% ������ ������
if orbitMode==0
    svRteme     = zeros(MaxStepCM,3);
    svVteme     = zeros(MaxStepCM,3);
    svAteme     = zeros(MaxStepCM,3);
    svrj2000    = zeros(MaxStepCM,3);
    svvj2000    = zeros(MaxStepCM,3);
    svaj2000    = zeros(MaxStepCM,3);
    svrecef     = zeros(MaxStepCM,3);
    svvecef     = zeros(MaxStepCM,3);
    svaecef     = zeros(MaxStepCM,3);
    svQjo       = zeros(MaxStepCM,4);
    svlatgc     = zeros(MaxStepCM,1);
    svlatgd     = zeros(MaxStepCM,1);
    svlon       = zeros(MaxStepCM,1);
    svhellp     = zeros(MaxStepCM,1);
    svWorb_j    = zeros(MaxStepCM,3);
    
    svMagn          = zeros(MaxStepCM,3);
    svMagnDipolECEF = zeros(MaxStepCM,3);
    svMagnDipolECI  = zeros(MaxStepCM,3);
    for StepCM=1:MaxStepCM
        % ��������� �����
        TimeOrbit;
        % ������������ ����� ������ ���������
        [satrec, r, v] = sgp4(satrec,tsince);
        Rteme = r;
        Vteme = v;
        Ateme = zeros(1,3);
        % ��������������� ������ ��������� �� TEME � J2000
        [rj2000,vj2000,aj2000] = teme2eci  ( Rteme',Vteme',Ateme',ttt,...
            teme2eci_order,eqeterms,teme2eci_opt );
        % ��������������� ��������� �������� �� ECEF
        [recef,vecef,aecef] = eci2ecef( rj2000,vj2000,aj2000,ttt,jdut1,lod,xp,yp,eqeterms,ddpsi,ddeps );
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
        %�������� ����������
        svRteme(StepCM,:)   = Rteme;
        svVteme(StepCM,:)   = Vteme;
        svAteme(StepCM,:)   = Ateme;
        svrj2000(StepCM,:)  = rj2000;
        svvj2000(StepCM,:)  = vj2000;
        svaj2000(StepCM,:)  = aj2000;
        svrecef(StepCM,:)   = recef;
        svvecef(StepCM,:)   = vecef;
        svaecef(StepCM,:)   = aecef;
        svQjo(StepCM,:)     = Qjo';
        svlatgc(StepCM,:)   = latgc;
        svlatgd(StepCM,:)   = latgd;
        svlon(StepCM,:)     = lon;
        svhellp(StepCM,:)   = hellp;
        svWorb_j(StepCM,:)  = Worb_j';
        if mod(StepCM/MaxStepCM*100,2)==0
            dddd=floor(StepCM/MaxStepCM*100);
            disp(dddd);
        end;
        
        %% ���������� ��������� ����
        %������ ������
        normRecef=norm(recef); % ��
        MagnFieldECEFdipol=(3*(MagnMomentum*recef)*recef'-normRecef^2*MagnMomentum)/normRecef^5;% ���
        [MagnFieldDipol_j,~,~] = ecef2eci(MagnFieldECEFdipol',[0 0 0]',[0 0 0]',...
            ttt,jdut1,lod,xp,yp,eqeterms,ddpsi,ddeps);
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
%         svMagn(StepCM,:)            = MagnFieldECEF;
        svMagnDipolECEF(StepCM,:)   = MagnFieldECEFdipol;
        svMagnDipolECI(StepCM,:)    = MagnFieldDipol_j;
    end;
    % �������� ���������
    svDeltaStepCM       = DeltaStepCM;
    svMaxStepCM         = MaxStepCM;
    svteme2eci_order    = teme2eci_order;
    sveqeterms          = eqeterms;
    svteme2eci_opt      = teme2eci_opt;
    svTLEstr1           = TLEstr1;
    svTLEstr2           = TLEstr2;
    svtwoline2rv_whichconst	= twoline2rv_whichconst;
    svtwoline2rv_typerun    = twoline2rv_typerun;
    svtwoline2rv_typeinput	= twoline2rv_typeinput;
    svtimezone          = timezone;
    svdut1              = dut1;
    svdat               = dat;
    svMearth            = Mearth;
    svMuEarth           = MuEarth;
    svlod               = lod;
    svxp                = xp;
    svyp                = yp;
    svddpsi             = ddpsi;
    svddeps             = ddeps;
    save('orbitData',...
        'svRteme','svVteme','svAteme','svrj2000','svvj2000','svaj2000', ...
        'svrecef','svvecef','svaecef','svQjo','svlatgc',...
        'svlatgd','svlon','svhellp','svWorb_j', 'svDeltaStepCM',...
        'svMaxStepCM','svteme2eci_order','sveqeterms','svteme2eci_opt',...
        'svTLEstr1','svTLEstr2','svtwoline2rv_whichconst',...
        'svtwoline2rv_typerun','svtwoline2rv_typeinput','svtimezone',...
        'svdut1','svdat','svMearth','svMuEarth','svlod','svxp','svyp',...
        'svddpsi','svddeps');
    save('magnData','svMagn','svMagnDipolECEF','svMagnDipolECI');
end;
StepCM=1;