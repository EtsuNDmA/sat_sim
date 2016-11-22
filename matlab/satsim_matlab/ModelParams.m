%%%%%%%%%%%%%%%%%%%%
% Параметры модели % 
%%%%%%%%%%%%%%%%%%%%
d2r=pi/180; %Deg2Rad
%% Время моделирования в сек
MaxTimeModel = 31536000%100*60*10*100;
%% Шаг моделирования в сек
DeltaStepModel = 60*1000;%0.020;
MaxStepModel = floor(MaxTimeModel/DeltaStepModel);

%% Перевод из TEME в ECI
%order       - number of terms for nutation   4, 50, 106, ...
teme2eci_order = 4;
%eqeterms    - number of terms for eqe        0, 2
teme2eci_eqeterms = 2;
%opt         - option for processing          
%               a - complete nutation
%               b - truncated nutation
%               c - truncated transf matrix
teme2eci_opt = 'a'; 

%% Инициализация SGP4
twoline2rv_whichconst	= 84;   % Используем эллипсойд WGS-84
twoline2rv_typerun      = 'c';	% [c]atalog, [m]anual, [v]erification mode
twoline2rv_typeinput	= 'd';	% [m]fe, [e]poch, [d]ayofyear

%% Параметры аппарата
%Момент инерции в связанных осях (кг м^2)
Jxx_b = 365;
Jyy_b = 335;
Jzz_b = 473;
Jxy_b = 0;
Jxz_b = 0;
Jyx_b = 0;
Jyz_b = 0;
Jzx_b = 0;
Jzy_b = 0;

J_b = [Jxx_b Jxy_b Jxz_b;
       Jyx_b Jyy_b Jyz_b;
       Jzx_b Jzy_b Jzz_b];
invJ_b=J_b^-1;