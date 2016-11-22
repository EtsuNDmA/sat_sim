clc
clear
close
% Добавляем в пути МАТЛАБ папку и все подпапки
addpath(genpath('D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\'))
%% Время, на которое рассчитывается орбита,сек
Torb = 60*300;      
%% Шаг моделирования движения ЦМ, сек
DeltaStepCM = 60; 
%% Инициализируем параметры объекта, орбиты, модели и т.д.
[params, satrec0] = initial_data(Torb, DeltaStepCM);
% k_quat=1;
% Рассчитываем орбиту
[orbData, magnData, sunData, atmData] = orbitCalculation(params, satrec0);
% Переписываем структуры как timeseries, чтобы передать на шину в simulink
	% Вектор времени
	ttime = (1:params.MaxStepCM)*params.DeltaStepCM;
	% Орбитальные данные
	ts_rj2000  = timeseries(orbData.rj2000, ttime);
	ts_vj2000 = timeseries(orbData.vj2000, ttime);
	ts_Worbj  = timeseries(orbData.Worb_j, ttime);
	ts_rsun   = timeseries(sunData.rsun, ttime);
	ts_rrsuno = timeseries(sunData.rrsuno, ttime);
    ts_MagnECI = timeseries(magnData.MagnDipolECI, ttime);
    ts_rho    = timeseries(atmData.rho, ttime);
	inOrbData = struct('r_j',ts_rj2000,...
                        'v_j',ts_vj2000,...
                        'wOrb_j',ts_Worbj,...
                        'rSun_j',ts_rsun,...
                        'rSun_o',ts_rrsuno,...
                        'magFieldEci',ts_MagnECI,...
                        'rhoAtm',ts_rho);
    
	% Параметры
	load('orbBus.mat')
	
% disp('====Initialisation OK====')

	