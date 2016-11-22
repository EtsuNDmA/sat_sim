addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\SGP4_matlab'
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\m_map'
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\ukf'
% clc
clear all
close all
%% Время, на которое рассчитывается орбита,сек
Torb=98*60*10;      
%% Шаг моделирования движения ЦМ, сек
DeltaStepCM = 60; 
%% Инициализируем параметры объета, орбиты, модели и т.д.
[params,satrec_0]=InitialData(Torb,DeltaStepCM);
k_quat=1;
% Рассчитываем орбиту
[OrbData,MagnData,SunData]=OrbitCalculation(params,satrec_0);
% Переписываем структуры как timeseries, чтобы передать на шину в simulink
	% Вектор времени
	ttime=[1:params.MaxStepCM]'*params.DeltaStepCM;
	% Данные
	ts_j2000	=timeseries(OrbData.rj2000,ttime);
	ts_vj2000	=timeseries(OrbData.vj2000,ttime);
	ts_Worbj	=timeseries(OrbData.Worb_j,ttime);
	ts_MagnECI	=timeseries(MagnData.MagnDipolECI,ttime);
	ts_rsun		=timeseries(SunData.rsun,ttime);
	ts_rrsuno	=timeseries(SunData.rrsuno,ttime);
	InData=struct('j2000',ts_j2000,...
				'vj2000',ts_vj2000,...
				'Worbj',ts_Worbj,...
				'rsun',ts_rsun,...
				'rrsuno',ts_rrsuno);
	% Парметры
	load('InputBusObj.mat')
	
disp('====Initialisation OK====')

	