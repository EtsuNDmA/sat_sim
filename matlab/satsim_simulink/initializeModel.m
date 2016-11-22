clc
clear
close
% ��������� � ���� ������ ����� � ��� ��������
addpath(genpath('D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\'))
%% �����, �� ������� �������������� ������,���
Torb = 60*300;      
%% ��� ������������� �������� ��, ���
DeltaStepCM = 60; 
%% �������������� ��������� �������, ������, ������ � �.�.
[params, satrec0] = initial_data(Torb, DeltaStepCM);
% k_quat=1;
% ������������ ������
[orbData, magnData, sunData, atmData] = orbitCalculation(params, satrec0);
% ������������ ��������� ��� timeseries, ����� �������� �� ���� � simulink
	% ������ �������
	ttime = (1:params.MaxStepCM)*params.DeltaStepCM;
	% ����������� ������
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
    
	% ���������
	load('orbBus.mat')
	
% disp('====Initialisation OK====')

	