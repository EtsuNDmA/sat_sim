% by Nikolaev DA
% This script execute simulation
% 
% StepModel | | | |... | | | | | | | |
% StepACS   |      ...     |       ...
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\SGP4_matlab'
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\libraries\\m_map'
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\src'
clc
clear
close all

tic;
InitialData;
OrbitCalculation;
while StepModel<=MaxStepModel
	disp(StepModel)
	Time;
	if mod(StepModel,(DeltaStepCM/DeltaStepModel))==0 
		Orbit;
		SunPosition;
		Atmosphere;
		MagneticField;
	end
	ReactionWheelModel;
	MagnCoilModel;
	SpacecraftDynamics;
	if mod(StepModel,(DeltaStepACS/DeltaStepModel))==1
		ACS
% 				SolarPanelAttitude
	end

	SaveData;
	ProgressBar;
%             if Progress>0 && rem(Progress,0.4)==0
%                 close all;
% 				figure;
% 				plot([1:StepACS]*DeltaStepACS,atan2(svRsunb(1:StepACS,1),svRsunb(1:StepACS,2)),'r')
% 				hold on;
% 				plot([1:StepModel]*DeltaStepModel,svspalpha1(1:StepModel))
% 				figure;
% 				plot(svDA(1:StepACS-1))
% 				hold on;plot([0 StepACS-1],[d2r*10 d2r*10],'k--')
% 				plot([0 StepACS-1],[-d2r*10 -d2r*10],'k--')
%             end;
%Next step
%             if Udempf==0 && ggg==0;
%                 pause;
%                 ggg=1;
%             end;
	StepModel = StepModel +1;
	StepACS = floor(StepModel/(DeltaStepACS/DeltaStepModel))+1;
	StepCM = floor(StepModel/(DeltaStepCM/DeltaStepModel))+1;
	if StepModel==98*60/DeltaStepModel
		MakePlots
		pause
	end;
end;
  
%     StepACS=StepACS-1;
%     StepCM=StepCM-1;

% save(['Data' num2str(ii) '_' num2str(jj)],'svWb','svNob')
StepCM = StepCM - 1;
StepACS = StepACS - 1;
MakePlots
PlotMap
fprintf('==========================================================\n');
fprintf('\t <strong> Параметры моделирования </strong> \n');


toc;
fprintf('==========================================================\n');