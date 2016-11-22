%%%%%%%%%%%%%%%%%%%%
% Параметры модели % 
%%%%%%%%%%%%%%%%%%%%
d2r=pi/180; %Deg2Rad
au2km= 149597870.0; % au to km
%% Время моделирования в сек
%MaxTimeModel = 24*60*60*20;    % Сутки
% MaxTimeModel = 100*60;         % Примерно 1 оборот
MaxTimeModel = 100
%MaxTimeModel = 60;             % Минута
% MaxTimeModel = 60*10;          % 10 минут
%MaxTimeModel = 60*30;          % 30 минут
%MaxTimeModel = 6;              % 2 секунды
%MaxTimeModel = 24*60*60*365;   % Год
% MaxTimeModel = 1200;
%% Шаг моделирования, сек
%DeltaStepModel = 60*60*24;	%Сутки
%DeltaStepModel = 60;       %Минута
%DeltaStepModel = 60*5;     %5 минут
DeltaStepModel = 0.05;    %Основной
%DeltaStepModel = 1;        %Секунда

MaxStepModel = floor(MaxTimeModel/DeltaStepModel);
StepModel = 1;
%% Шаг моделирования движения ЦМ, сек
DeltaStepCM = 0.05;       %
StepCM=1;
MaxStepCM = floor(MaxTimeModel/DeltaStepCM);
%% Шаг работы системы управления, сек
DeltaStepACS = 0.1;
% Начальный шаг
StepACS = 1;
MaxStepACS = floor(MaxTimeModel/DeltaStepACS);
%% Перевод из TEME в ECI
%order       - number of terms for nutation   4, 50, 106, ...
teme2eci_order = 4;
%eqeterms    - number of terms for eqe (equation of equinoxes - 
% для вычисления истинного гринвичского звездного времени), 0, 2
eqeterms = 0;
%opt         - option for processing          
%               a - complete nutation
%               b - truncated nutation
%               c - truncated transf matrix
teme2eci_opt = 'b'; 

%% Начальные параметры орбиты
% COSMOS 2503 TLE
    TLEstr1	= ...
    '1 40420U 15009A   15077.18255940 -.00000061  00000-0  00000+0 0  9996';
    TLEstr2    = ...
    '2 40420  97.6355  36.9133 0009893 226.8258 190.0104 15.03370136  2831';
% SAC-D    TLE
% 	TLEstr1	= ...
% 	'1 37673U 11024A   15155.65200456  .00000263  00000-0  49400-4 0  9991';
% 	TLEstr2    = ...
% 	'2 37673  98.0111 162.8129 0001487  97.9991  18.6294 14.72280601214098';
% CBERS-4 TLE
% 	TLEstr1	= ...
% 	'1 40336U 14079A   15156.15603142  .00000029  00000-0  25296-4 0  9996';
% 	TLEstr2	= ...
% 	'2 40336  98.5254 231.4827 0001842  94.4898 265.6507 14.35426857 25817';
%% Инициализация SGP4
    twoline2rv_whichconst	= 84;   % Используем эллипсойд WGS-84
    twoline2rv_typerun      = 'c';	% [c]atalog, [m]anual, [v]erification mode
    twoline2rv_typeinput	= 'd';	% [m]fe, [e]poch, [d]ayofyear
% Инициализируем SGP4 из TLE
    [satrec, startmfe, stopmfe, deltamin] = twoline2rv(twoline2rv_whichconst, ...
        TLEstr1, TLEstr2, twoline2rv_typerun,twoline2rv_typeinput);
%% Параметры времени
    timezone = 0;
% Взял отсюда ftp://hpiers.obspm.fr/iers/series/opa/eopc04
    dut1 = 0.999;% UT1-UTC error,sec
    dat = 35;% TAI-UTC, sec, http://stjarnhimlen.se/comp/time.html
%% Параметры Земли
%Масса Земли, кг
    Mearth=5.97219e24;
% Геоцентрическая гравитационная постоянная Земли, м3/с2
    MuEarth=3.986004415e14;
% Вычисление магнитного поля по модели наклоненного диполя
%Коэффициенты IGRF12 на 2015 год
    g10=-29442.0;       % нТл
    g11=-1501.0;        % нТл
    h11=4797.1;         % нТл
% Средний радиус Земли, км
    RmeanEarth=6371.200;
% Магнитный дипольный момент Земли
    MagnMomentum=(RmeanEarth)^3*[g11 h11 g10];
%% Параметры атмосферы
% ftp://ftp.kiam1.rssi.ru/pub/gps/solar/solarinex.txt
    F107=141.000;
    F81=128.568;
    Kp=2;
% Коэффициент диффузионного обтекания
	DiffusCoeff=0.65;
	PlanesArea=[1.670*7.180, 1.670*7.180]*2;
%% Ориентация Земли
% Взял отсюда ftp://hpiers.obspm.fr/iers/series/opa/eopc04 (http://www.celestrak.com/SpaceData/EOP-format.asp)
    lod = 0.0019859;%lenght of day, sec
    xp= 0.003493*4.8481368e-6;%polar motion coefficient, rad
    yp= 0.378324*4.8481368e-6;%polar motion coefficient, rad
    ddpsi=2.511312*4.8481368e-6;%delta psi correction to gcrf   rad
    ddeps=0.999000*4.8481368e-6;%delta eps correction to gcrf   rad

%% Параметры аппарата
% Солнечные батареи
% 
% %От Андрея
% 	% Масса, кг
% 	SPMASS=64,5;
% 	% Тензор инерции от-но собственного ЦМ в собственных осях(x от крепления, z наверх), м
% 	Jsp=[1051.25 0.05 -.33;
% 		0.05 1094.85 16.20;
% 		-.33 16.20 61.22];
% 	Asp1=angle2dcm();
% 	Jsp1=Asp1*Jsp*Asp';
% 	% Точка крепления к корпусу (БССК), м
% 	OO1=[0 -0.285 -0.52];
% 	OO1=[0 -0.285 0.52];
% 	% ЦМ панелей (СБСК1 и СБСК2), м
% 	
% 	O1C1=[0 0.29 -6.31];
% 	O2C2=[0 0.29 6.31];
% 	
% 	O1C1=[0 0.345 -7.329];
% 	O2C2=[0 0.345 7.329];

%От Феди
	% Масса, кг
	SPMASS=75;
	% Тензор инерции от-но собственного ЦМ в собственных осях (x от крепления, z наверх), м
	Jsp=[ 84.362       0.383       375.36;
		  0.383        1004.1      0.242;
          941.7        0.242       1066.1];
	  
	%Переход к ЦСБСК
	Asp1=angle2dcm(pi/2,-pi/2,0,'XYZ');
	Asp2=angle2dcm(-pi/2,-pi/2,0,'XYZ');
	Jsp1=Asp1*Jsp*Asp1';
	Jsp2=Asp2*Jsp*Asp2';
	% Точка крепления к корпусу (БССК), м
	OO1=[0; -0.285; -0.52];
	OO2=[0; -0.285; 0.52];
	% ЦМ панелей (СБСК1 и СБСК2), м
	
	O1C1=[0; 0.345; -7.329];
	O2C2=[0; 0.345; 7.329];	
% Начальная скорость и ускорение СБ
	Wrel1=zeros(3,1);
	Wrel2=zeros(3,1);
	dWrel1=zeros(3,1);
	dWrel2=zeros(3,1);
% Начальная ориентация СБ
	spalpha1=-0.9;
	spbeta1=0;
	spalpha2=-0.9;
	spbeta2=0;
	
	spkp=0.0007;
	spu=0;
	spen=0;
	
% Корпус
	% Момент инерции в связанных осях (кг м^2)
    Jxx_b = 132;
    Jyy_b = 208;
    Jzz_b = 223;
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

    Jbody_b = [Jxx_b Jxy_b Jxz_b;
           Jxy_b Jyy_b Jyz_b;
           Jxz_b Jyz_b Jzz_b];
	% Масса корпуса
	BMASS=450;
	% Центр масс корпуса (БССК)
	OC0=[0; -0.7; 0];
% Полная масса
	MASS=BMASS+2*SPMASS;
	
% Начальная угловая скорость в связанном базисе
    % W_b = [0.0005;-0.0005;0.0005];
%     W_b = [0;0;-0.001];
    W_b = [0.0*d2r;0;0.5*d2r];
% Начальная ориентация относительно OСК
    Nob = [1;0;0;0];
% 	Nob = [0;0;0;-1];


	
%% Маховики
% Начальные скорости маховиков (с^-1) и требуемая начальная скорость
    RWRate=zeros(4,1);
    RWRateReq=zeros(4,1);
% Матрица конфигурации маховиков
	rwgamma=45*d2r;
	rwdelta=55*d2r;
	sd=sin(rwdelta);
	cd=cos(rwdelta);
	sg=sin(rwgamma);
	cg=cos(rwgamma);
	Arw=[-sd*cg -sd*cg -sd*cg -sd*cg;
		  sd*sg -sd*sg -sd*sg  sd*sg;
		  -cd    -cd     cd     cd];
    Lrw=0.25*[-1 1 -1;-1 -1 -1;-1 -1 1;-1 1 1]*diag([1/sd/cg,1/sd/cg,1/cd]);
	clear sd sg cd cg;
% Момент инерции маховиков относительно оси вращения 
    Irw=0.01;
% Максимальный момент маховиков Н*м
    Trwmax=0.3;
% Максимальная скорость вращения маховиков
    RWRateMax=1000;
% Максимальный кинмомент
    Hrwmax=Irw*RWRateMax;
%Вектор от центра Земли к ЦМ аппарата в проекции на ОСК
    jvert_o=[0; 1; 0];
%% Катушки
% Начальное состояние магнитных катушек - магнитный момент (Дж/Тл)
    MagnMoment_p=[0;0;0];
    MagnMomentReq_p=[0;0;0];
% ПСК катушек
    QMbp=[1 0 0 0];
% Максимальный магнитный момент А*м2
    MagnMomentMax=50;
% Признак включения разгрузки
    Uunload=0;
% Признак включения демпфирования
    Udempf=0;
% Коэффициенты разгрузки 
    Hlow=0.01*Hrwmax;
    Hhigh=0.5*Hrwmax;
%% Датчик угловой скорости ТИУС500
% Случайная составляющая дрейфа нулевого сигнала при фиксированной
% температуре, град/час
    RateSensorBias=0.1;
% Случайная составляющая дрейфа нулевого сигнала при изменении температуры
% от -40 до 60, град/час
%     RateSensorBiasT=0.5;
% 
%     RSB=[random('Normal',0,RateSensorBiasT/3600/3)...
%         random('Normal',0,RateSensorBiasT/3600/3)...
%         random('Normal',0,RateSensorBiasT/3600/3)];
% Погрешность масштабного коэффициента
    RateSensorScaleErrorMax=0.0008;
    RSSE=diag( [random('Normal',0,RateSensorScaleErrorMax/3)...
                random('Normal',0,RateSensorScaleErrorMax/3)...
                random('Normal',0,RateSensorScaleErrorMax/3)]);
% Спектральная плотность мощности шума, град/час^0.5
    RateSensorNoise=0.005;
    SigmaRSN=RateSensorNoise/60/sqrt(DeltaStepACS);

%% Управление
%Коэффициенты в законе управления
% K1acs=2000;
% K2acs=15*2000;

    K1acs=0.09;
    K2acs=0.18;

%Для ориентации на Солнце
    K1acsS=0.09;
    K2acsS=0.18;

    Kbdot=1;

    Kul=0.1;

%% Режим работы
    Mode='Stab3';%'Detumbling','Sun','Stab3'
% Ось, которую направляем на Солнце
    Raimb=[1 0 0];