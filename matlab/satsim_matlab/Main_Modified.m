% by Nikolaev DA
% This script execute simulation
% 
% StepModel | | | |... | | | | | | | |
% StepACS   |      ...     |       ...
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\SGP4_matlab'
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\MATLAB work\m_map'
addpath 'D:\Projects\yaliny-sat-cc\external\ACS_Matlab_Model\MATLAB work\src'
clc
% clear all
% close all
s = serial('COM5');
set(s,'BaudRate',921600,...
		'DataBits',8,...
		'StopBits',1,...
		'FlowControl','none',...
		'ByteOrder','littleEndian')
fopen(s);

Fd=200;
% for ii=1:13
%     for jj=1:13
        tic;
            InitialData;
			Gx=0;
			Gy=0;
			Gz=0;
			
            OrbitCalculation;
%         for i=1:MaxStepModel-1
% 		for i=1:100*60/DeltaStepModel-1
		for i=1:1000-1
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
j=1;

while j<=0.05*Fd;
	data=fread(s,1,'uint8');
	if data==192% Header 0xC0C0
		data=fread(s,1,'uint8');
		if data==192
			GxOld=Gx;
			GyOld=Gy;
			GzOld=Gz;
			Gx=fread(s,1,'uint32');
			Gy=fread(s,1,'uint32');
			Gz=fread(s,1,'uint32');
			Ax=fread(s,1,'int32');
			Ay=fread(s,1,'int32');
			Az=fread(s,1,'int32');
			ADD=fread(s,1,'uint16');
			CNT(j)=fread(s,1,'uint16');
			CRC=fread(s,1,'uint16');
			if j==1
				Dx=0;
				Dy=0;
				Dz=0;
				Dt=0;
			else
				Dx=Gx-GxOld;
				Dy=Gy-GyOld;
				Dz=Gz-GzOld;
				Dt=(CNT(j)-CNT(j-1))/Fd;
			end;
			% Detect zero crossing of angle counter
			if abs(Dx)>2^31 
				Dx=Dx-sign(Dx)*2^32;
			end;
			if abs(Dy)>2^31 
				Dy=Dy-sign(Dy)*2^32;
			end;
			if abs(Dz)>2^31 
				Dz=Dz-sign(Dz)*2^32;
			end;
			Wx(j)=Dx*1.15555553748E-6.*Dt;
			Wy(j)=Dy*1.15555553748E-6.*Dt;
			Wz(j)=Dz*1.15555553748E-6.*Dt;
			
			j=j+1;
		else
			data=0;
		end;
	else
		data=0;
	end;
end;
            if mod(StepModel,(DeltaStepACS/DeltaStepModel))==1
                ACS_Modified
				SolarPanelAttitude
            end

            SaveData;
            ProgressBar;
%             if Progress>0 && rem(Progress,2)==0
%                 MakePlots
%             end;
        %Next step
%             if Udempf==0 && ggg==0;
%                 pause;
%                 ggg=1;
%             end;
            StepModel = StepModel +1;
            StepACS = floor(StepModel/(DeltaStepACS/DeltaStepModel))+1;
            StepCM = floor(StepModel/(DeltaStepCM/DeltaStepModel))+1;

            
		end;
%     for vv=1:length(svWb)
%         nn(vv)=norm(svWb(vv,:)-svWorbb(vv,:));
%     end;
%     ind1x=find(nn>20/3600/180*pi,1,'last');
%     ind2x=find(svNob(:,1)>cos(1/60/180*pi/2),1,'first');
%     if isempty(ind1x)
%         ind1(ii,jj)=MaxStepModel;
%     else
%         ind1(ii,jj)=ind1x;
%     end;
%     if isempty(ind2x)
%         ind2(ii,jj)=MaxStepModel;
%     else
%         ind2(ii,jj)=ind2x;
%     end;
%     ind3(ii,jj)=max(ind1(ii,jj),ind2(ii,jj));
    
    StepACS=StepACS-1;
    StepCM=StepCM-1;
     
%     end;
% end;

% save(['Data' num2str(ii) '_' num2str(jj)],'svWb','svNob')

MakePlots
% PlotMap
fprintf('==========================================================\n');
fprintf('\t <strong> Параметры моделирования </strong> \n');


toc;
fprintf('==========================================================\n');
fclose(s)
delete(s)
clear s