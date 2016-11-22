function [params,satrec] = initialData(maxTimeModel, deltaStepCM)
%% ���������
	params.D2R = pi/180; %Deg2Rad
	params.AU2KM = 149597870.0; % au to km
	params.ORB2LVLH = [1 0 0;0 0 1;0 -1 0];
	params.LVLH2ORB = [1 0 0;0 0 -1;0 1 0];
%% ����� ������� ������
	params.maxStepCM = floor(maxTimeModel/deltaStepCM);
	params.deltaStepCM = deltaStepCM;
%% ������� �� TEME � ECI
%order       - number of terms for nutation   4, 50, 106, ...
	params.teme2eciOrder = 4;
%eqeterms    - number of terms for eqe (equation of equinoxes - 
% ��� ���������� ��������� ������������ ��������� �������), 0, 2
	params.eqeterms = 0;
%opt         - option for processing          
%               a - complete nutation
%               b - truncated nutation
%               c - truncated transf matrix
	params.teme2eciOpt = 'b'; 

%% ��������� �������
    params.timezone = 3;
% ���� ������ ftp://hpiers.obspm.fr/iers/series/opa/eopc04
    params.dut1 = 0.999;% UT1-UTC error,sec
    params.dat = 35;% TAI-UTC, sec, http://stjarnhimlen.se/comp/time.html
%% ��������� �����
%��������� ���������� �������  � ���, �/�2
	params.g = [0 0 9.8];
%����� �����, ��
    params.Mearth = 5.97219e24;
% ��������������� �������������� ���������� �����, �3/�2
    params.MuEarth = 3.986004415e14;
% ���������� ���������� ���� �� ������ ������������ ������
%������������ IGRF12 �� 2015 ���
    params.g10 = -29442.0;       % ���
    params.g11 = -1501.0;        % ���
    params.h11 = 4797.1;         % ���
% ������� ������ �����, ��
    params.RmeanEarth = 6371.200;
% ��������� ��������� ������ �����
    params.MagnMomentum = (params.RmeanEarth)^3*[params.g11 params.h11 params.g10];
%% ��������� ���������
% ftp://ftp.kiam1.rssi.ru/pub/gps/solar/solarinex.txt
    params.F107 = 141.000;
    params.F81 = 128.568;
    params.Kp = 2;
% ����������� ������������� ���������
	params.DiffusCoeff = 0.65;
	params.PlanesArea = [1.670*7.180, 1.670*7.180]*2;
%% ���������� �����
% ���� ������ ftp://hpiers.obspm.fr/iers/series/opa/eopc04 (http://www.celestrak.com/SpaceData/EOP-format.asp)
    params.lod = 0.0019859; % lenght of day, sec
    params.xp = 0.003493*4.8481368e-6; % polar motion coefficient, rad
    params.yp = 0.378324*4.8481368e-6; % polar motion coefficient, rad
    params.ddpsi = 2.511312*4.8481368e-6; % delta psi correction to gcrf   rad
    params.ddeps = 0.999000*4.8481368e-6; % delta eps correction to gcrf   rad

%% ��������� ��������
% ������ ������� � ��������� ���� (�� �^2)

    Jxx_b = 820;
    Jyy_b = 820;
    Jzz_b = 220;
    Jxy_b = 0;
    Jxz_b = 0;
    Jyz_b = 0;

    params.J_b = [Jxx_b Jxy_b Jxz_b;
                  Jxy_b Jyy_b Jyz_b;
                  Jxz_b Jyz_b Jzz_b];
    params.invJ_b = params.J_b^-1;
	
	params.Mass = 200;
	
	params.Rcm = [0.0005 -0.0005 0.0000];

%% ��������� ��������� ������
% COSMOS 2503 TLE
%     params.TLEstr1	= ...
%     '1 40420U 15009A   15077.18255940 -.00000061  00000-0  00000+0 0  9996';
%     params.TLEstr2    = ...
%     '2 40420  97.6355  36.9133 0009893 226.8258 190.0104 15.03370136  2831';
% SAC-D    TLE
	params.TLEstr1	= ...
	'1 37673U 11024A   15155.65200456  .00000263  00000-0  49400-4 0  9991';
	params.TLEstr2    = ...
	'2 37673  98.0111 162.8129 0001487  97.9991  18.6294 14.72280601214098';
% CBERS-4 TLE
% 	params.TLEstr1	= ...
% 	'1 40336U 14079A   15156.15603142  .00000029  00000-0  25296-4 0  9996';
% 	params.TLEstr2	= ...
% 	'2 40336  98.5254 231.4827 0001842  94.4898 265.6507 14.35426857 25817';
%% ������������� SGP4
    params.twoline2rvWhichconst = 84;  % ���������� ��������� WGS-84
    params.twoline2rvTyperun = 'c';	% [c]atalog, [m]anual, [v]erification mode
    params.twoline2rvTypeinput = 'd';	% [m]fe, [e]poch, [d]ayofyear
% �������������� SGP4 �� TLE
    [satrec,~,~,~] = twoline2rv(params.twoline2rvWhichconst, ...
                                params.TLEstr1, ...
                                params.TLEstr2, ...
                                params.twoline2rvTyperun, ...
		                        params.twoline2rvTypeinput);
% ��������� �����
	times = timeOrbit(satrec.epochyr, satrec.epochdays, params, 0);
% ��������� ���������
	[satrec, Rteme, Vteme] = sgp4(satrec, 0);
	Ateme = zeros(1,3);
% ��������������� ������ ��������� �� TEME � J2000
	[rj2000, vj2000,~] = teme2eci(Rteme', Vteme', Ateme', times.ttt, ...
		params.teme2eci_order,params.eqeterms,params.teme2eci_opt );
% ���������� ����������� ����� iorb, jorb korb � �������� �� J2000
	jorb = rj2000/norm(rj2000);
	korb = cross(vj2000, rj2000)/norm(cross(vj2000, rj2000));
	iorb = cross(jorb, korb);
% ������� ������������ ��������� �� J2000 � ����������� ��
	DCMjo = [iorb';jorb';korb'];
	% ���������� �������� �� J2000 � ���
	params.Qjo = dcm2quat(DCMjo);

%% ��������� ������� �������� � ��������� ������
    % W_b = [0.0005;-0.0005;0.0005];
    params.W_b = [0 0 -0.0001];
    %W_b = [0.003*d2r;0;0.004*d2r];
%% ��������� ���������� ������������ O��
    params.Nob = [1 0 0 0];
	% ������������ �� LVLH
	NobLVLH(1) = params.Nob(1);
	NobLVLH(2:4) = params.ORB2LVLH*params.Nob(2:4)';
	[params.roll, params.pitch, params.yaw] = quat2angle(NobLVLH, 'XYZ');
% ��������� ���������� � ���
	params.Qjb = quatmultiply(params.Qjo, params.Nob);
%% ��������� �������
% 	% ����� � ������, �
% 	SPL=8.2;
% 	SPD=1.67;
% 	% �����, ��
% 	SPMASS=30;
% 	% ������ ������� ��-�� ������������ �� � ����������� ����, �
% 	Jsp=[672.4 0 0;
% 		0 175.1 0;
% 		0 0 27.9];
% 	% ����� ��������� � �������, �
% 	SPB1=[0;0.635;-0.760];
% 	SPB2=[0;0.635;0.760];
% 	
% 	SPM1=[-2.836442769909897e-01;
%      4.500607810263897e-01;
%      8.638876894778627e-01];
% 	SPN1=[4.500607810263897e-01;
%     -8.638876894778627e-01;
%     -2.836442769909897e-01];
% 	SPM2=[2.836442769909897e-01;
%     -4.500607810263897e-01;
%     -8.638876894778627e-01];
% 	SPN2=[4.500607810263897e-01;
%     -8.638876894778627e-01;
%     -2.836442769909897e-01];
%% ��������
% ��������� �������� ��������� (�^-1) � ��������� ��������� ��������
    RWRate = zeros(4, 1);
    RWRateReq = zeros(4, 1);
% ������� ������������ ���������
	params.rwgamma = 45;
	params.rwdelta = 55;
% ������ ������� ��������� ������������ ��� �������� 
    params.Irw = 0.01;
% ������������ ������ ��������� �*�
    params.Trwmax = 0.3;
% ������������ �������� �������� ���������
    params.RWRateMax = 1000;
% ������������ ���������
    params.Hrwmax = params.Irw*params.RWRateMax;
%% �������
% ��������� ��������� ��������� ������� - ��������� ������ (��/��)
    params.MagnMoment_p = [0 0 0];
    params.MagnMomentReq_p = [0 0 0];
% ��� �������
    params.QMbp=[1 0 0 0];
% ������������ ��������� ������ �*�2
    params.MagnMomentMax = 50;
% ������� ��������� ���������
    params.Uunload = 0;
% ������� ��������� �������������
    params.Udempf = 0;
% ������������ ��������� 
    params.Hlow = 0.2*params.Hrwmax;
    params.Hhigh = 0.8*params.Hrwmax;
%% ������ ������� �������� ����500
    params.RateSensorSampleTime = 0.01;
% ��������� ������������ ������ �������� ������� ��� �������������
% �����������, ����/���
%     RateSensorBias=0.1;
% ��������� ������������ ������ �������� ������� ��� ��������� �����������
% �� -40 �� 60, ����/���
%     RateSensorBiasT=0.5;

    params.VarRSB = [0 0 0];
% ����������� ����������� ������������
    RateSensorScaleErrorMax = 0.0008;
    params.RSSE=diag([random('Normal',0,RateSensorScaleErrorMax/3) ...
                      random('Normal',0,RateSensorScaleErrorMax/3)...
                      random('Normal',0,RateSensorScaleErrorMax/3)]);
% ������������ ��������� �������� ����, ����/���^0.5
%    RateSensorNoise=0.007;
    params.VarRSN = [1 1 1]*1e-15; % RateSensorNoise/60/sqrt(DeltaStepACS);

%% ����������
% ������������ � ������ ����������
    params.K1acs = 0.2;
    params.K2acs = 2;
%��� ���������� �� ������
    params.K1acsS = 5.4;
    params.K2acsS = 151;

    params.Kbdot = 1;

    params.Kul = 0.1;

%% ����� ������
%     Mode='Stab3';%'Detumbling','Sun','Stab3'
% ���, ������� ���������� �� ������
%     Raimb=[1 0 0];