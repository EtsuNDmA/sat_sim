addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\SGP4_matlab'
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\m_map'
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\ukf'
% clc
clear all
close all
%% �����, �� ������� �������������� ������,���
Torb=98*60*10;      
%% ��� ������������� �������� ��, ���
DeltaStepCM = 60; 
%% �������������� ��������� ������, ������, ������ � �.�.
[params,satrec_0]=InitialData(Torb,DeltaStepCM);
k_quat=1;
% ������������ ������
[OrbData,MagnData,SunData]=OrbitCalculation(params,satrec_0);
% ������������ ��������� ��� timeseries, ����� �������� �� ���� � simulink
	% ������ �������
	ttime=[1:params.MaxStepCM]'*params.DeltaStepCM;
	% ������
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
	% ��������
	load('InputBusObj.mat')
	
disp('====Initialisation OK====')

	