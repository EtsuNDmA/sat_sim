function [params,satrec]=InitialData(MaxTimeModel,DeltaStepCM)
%% Константы
	params.d2r=pi/180; %Deg2Rad
	params.au2km= 149597870.0; % au to km
	params.ORB2LVLH=[1 0 0;0 0 1;0 -1 0];
	params.LVLH2ORB=[1 0 0;0 0 -1;0 1 0];
%% Время расчета орбиты
	params.MaxStepCM=floor(MaxTimeModel/DeltaStepCM);
	params.DeltaStepCM=DeltaStepCM;
%% Перевод из TEME в ECI
%order       - number of terms for nutation   4, 50, 106, ...
	params.teme2eci_order = 4;
%eqeterms    - number of terms for eqe (equation of equinoxes - 
% для вычисления истинного гринвичского звездного времени), 0, 2
	params.eqeterms = 0;
%opt         - option for processing          
%               a - complete nutation
%               b - truncated nutation
%               c - truncated transf matrix
	params.teme2eci_opt = 'b'; 

%% Параметры времени
    params.timezone = 3;
% Взял отсюда ftp://hpiers.obspm.fr/iers/series/opa/eopc04
    params.dut1 = 0.999;% UT1-UTC error,sec
    params.dat = 35;% TAI-UTC, sec, http://stjarnhimlen.se/comp/time.html
%% Параметры Земли
%Ускорение свободного падения  в ОСК, м/с2
	params.g=[0 0 9.8];
%Масса Земли, кг
    params.Mearth=5.97219e24;
% Геоцентрическая гравитационная постоянная Земли, м3/с2
    params.MuEarth=3.986004415e14;
% Вычисление магнитного поля по модели наклоненного диполя
%Коэффициенты IGRF12 на 2015 год
    params.g10=-29442.0;       % нТл
    params.g11=-1501.0;        % нТл
    params.h11=4797.1;         % нТл
% Средний радиус Земли, км
    params.RmeanEarth=6371.200;
% Магнитный дипольный момент Земли
    params.MagnMomentum=(params.RmeanEarth)^3*[params.g11 params.h11 params.g10];
%% Параметры атмосферы
% ftp://ftp.kiam1.rssi.ru/pub/gps/solar/solarinex.txt
    params.F107=141.000;
    params.F81=128.568;
    params.Kp=2;
% Коэффициент диффузионного обтекания
	params.DiffusCoeff=0.65;
	params.PlanesArea=[1.670*7.180, 1.670*7.180]*2;
%% Ориентация Земли
% Взял отсюда ftp://hpiers.obspm.fr/iers/series/opa/eopc04 (http://www.celestrak.com/SpaceData/EOP-format.asp)
    params.lod = 0.0019859;%lenght of day, sec
    params.xp= 0.003493*4.8481368e-6;%polar motion coefficient, rad
    params.yp= 0.378324*4.8481368e-6;%polar motion coefficient, rad
    params.ddpsi=2.511312*4.8481368e-6;%delta psi correction to gcrf   rad
    params.ddeps=0.999000*4.8481368e-6;%delta eps correction to gcrf   rad

%% Параметры аппарата
% Момент инерции в связанных осях (кг м^2)
%     Jxx_b = 1930;
%     Jyy_b = 1895;
%     Jzz_b = 365;
%     Jxy_b = 0;
%     Jxz_b = 0;
%     Jyx_b = 0;
%     Jyz_b = 0;
%     Jzx_b = 0;
%     Jzy_b = 0;

    Jxx_b = 820;
    Jyy_b = 820;
    Jzz_b = 220;
    Jxy_b = 0;
    Jxz_b = 0;
    Jyz_b = 0;

%Батареи сложены
    % Jxx_b = 221;
    % Jyy_b = 295;
    % Jzz_b = 365;
    % Jxy_b = 0;
    % Jxz_b = 0;
    % Jyx_b = 0;
    % Jyz_b = 0;
    % Jzx_b = 0;
    % Jzy_b = 0;

    params.J_b = [Jxx_b Jxy_b Jxz_b;
           Jxy_b Jyy_b Jyz_b;
           Jxz_b Jyz_b Jzz_b];
    params.invJ_b=params.J_b^-1;
	
	params.Mass=200;
	
	params.Rcm=[0.0005 -0.0005 0.0000];
% Jbody_b=[1000 0 0;
% 		0 1000 0;
% 		0 0 1000]

%% Начальные параметры орбиты
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
%% Инициализация SGP4
    params.twoline2rv_whichconst	= 84;   % Используем эллипсойд WGS-84
    params.twoline2rv_typerun		= 'c';	% [c]atalog, [m]anual, [v]erification mode
    params.twoline2rv_typeinput		= 'd';	% [m]fe, [e]poch, [d]ayofyear
% Инициализируем SGP4 из TLE
    [satrec,~,~,~] = twoline2rv(params.twoline2rv_whichconst, ...
        params.TLEstr1, params.TLEstr2, params.twoline2rv_typerun,...
		params.twoline2rv_typeinput);
% Вычисляем время
	times=TimeOrbit(satrec.epochyr,satrec.epochdays,params,0);
% Вычисляем положение
	[satrec, Rteme, Vteme] = sgp4(satrec,0);
	Ateme = zeros(1,3);
% Перепроектируем вектор состояния из TEME в J2000
	[rj2000,vj2000,~] = teme2eci  ( Rteme',Vteme',Ateme',times.ttt,...
		params.teme2eci_order,params.eqeterms,params.teme2eci_opt );
% Рассчитаем орбитальный базис iorb, jorb korb в проекции на J2000
	jorb=rj2000/norm(rj2000);
	korb=cross(vj2000,rj2000)/norm(cross(vj2000,rj2000));
	iorb=cross(jorb,korb);
% Матрица направляющих косинусов от J2000 к орбитальной СК
	DCMjo=[iorb';jorb';korb'];
	% Кватернион поворота от J2000 к ОСК
	params.Qjo=dcm2quat(DCMjo);

%% Начальная угловая скорость в связанном базисе
    % W_b = [0.0005;-0.0005;0.0005];
    params.W_b = [0.0005;-0.0005;0.0005];
    %W_b = [0.003*d2r;0;0.004*d2r];
%% Начальная ориентация относительно OСК
    params.Nob = [1,0,0,0];
	% Спроектируем на LVLH
	NobLVLH(1)=params.Nob(1);
	NobLVLH(2:4)=params.ORB2LVLH*params.Nob(2:4)';
	[params.roll,params.pitch,params.yaw] = quat2angle(NobLVLH, 'XYZ');
% Начальная ориентация в ИСК
	params.Qjb=quatmultiply(params.Qjo,params.Nob);
	
% 	Nob = [0;0;0;-1];
%% Балансировочные грузы
 params.be1=[1 0 0];
 params.be2=[0 1 0];
 params.be3=[0 0 1];
 
 params.rho1=[1 0 0];
 params.rho2=[0 1 0];
 params.rho3=[0 0 1];
 params.sumrho=params.rho1+params.rho2+params.rho3;
 
 params.bmass=5;
 
 U=params.bmass*[ params.be1' params.be2' params.be3'];
 params.invU=U^-1;
 % Матрица коэффициентов усиления
 Kb=[1 0 0;
	 0 1 0;
	 0 0 1]*1e-12;
 % Для закона управления грузами
 params.KD=0.1;
 
 
%% Солнечные батареи
% 	% Длина и ширина, м
% 	SPL=8.2;
% 	SPD=1.67;
% 	% Масса, кг
% 	SPMASS=30;
% 	% Тензор инерции от-но собственного ЦМ в собственных осях, м
% 	Jsp=[672.4 0 0;
% 		0 175.1 0;
% 		0 0 27.9];
% 	% Точка крепления к корпусу, м
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
%% Маховики
% Начальные скорости маховиков (с^-1) и требуемая начальная скорость
    params.RWRate=[0; 0; 0];
    params.RWRateReq=[0; 0; 0];
% ПСК маховиков
    params.QRWbp=[1 0 0 0];
% Момент инерции маховиков относительно оси вращения 
    params.Irw=0.01;
% Максимальный момент маховиков Н*м
    params.Trwmax=0.50;
% Максимальная скорость вращения маховиков
    params.RWRateMax=500;
% Максимальный кинмомент
    params.Hrwmax=params.Irw*params.RWRateMax;
%Вектор от центра Земли к ЦМ аппарата в проекции на ОСК
    params.jvert_o=[0; 1; 0];
%% Катушки
% Начальное состояние магнитных катушек - магнитный момент (Дж/Тл)
    params.MagnMoment_p=[0;0;0];
    params.MagnMomentReq_p=[0;0;0];
% ПСК катушек
    params.QMbp=[1 0 0 0];
% Максимальный магнитный момент А*м2
    params.MagnMomentMax=50;
% Признак включения разгрузки
    params.Uunload=0;
% Признак включения демпфирования
    params.Udempf=0;
% Коэффициенты разгрузки 
    params.Hlow=0.2*params.Hrwmax;
    params.Hhigh=0.8*params.Hrwmax;
%% Датчик угловой скорости ТИУС500
params.RateSensorSampleTime=0.01;
% Случайная составляющая дрейфа нулевого сигнала при фиксированной
% температуре, град/час
%     RateSensorBias=0.1;
% Случайная составляющая дрейфа нулевого сигнала при изменении температуры
% от -40 до 60, град/час
%     RateSensorBiasT=0.5;

    params.VarRSB=[0 0 0];
% Погрешность масштабного коэффициента
    RateSensorScaleErrorMax=0.0008;
    params.RSSE=diag( [random('Normal',0,RateSensorScaleErrorMax/3)...
                random('Normal',0,RateSensorScaleErrorMax/3)...
                random('Normal',0,RateSensorScaleErrorMax/3)]);
% Спектральная плотность мощности шума, град/час^0.5
%     RateSensorNoise=0.007;
    params.VarRSN=[1 1 1]*1e-15;%RateSensorNoise/60/sqrt(DeltaStepACS);

%% Управление
%Коэффициенты в законе управления
% K1acs=2000;
% K2acs=15*2000;

    params.K1acs=0.05;
    params.K2acs=0.2;

%Для ориентации на Солнце
    params.K1acsS=5.4;
    params.K2acsS=151;

    params.Kbdot=1;

    params.Kul=0.1;

%% Режим работы
%     Mode='Stab3';%'Detumbling','Sun','Stab3'
% Ось, которую направляем на Солнце
%     Raimb=[1 0 0];