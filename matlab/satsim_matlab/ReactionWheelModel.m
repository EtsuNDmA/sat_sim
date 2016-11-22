%% Найдем требуемую скорость вращения
	   
	%Требуемый кинетический момент
	if StepACS==1
        Hrwreq_p=zeros(4,1);
		Trwreq_p=zeros(4,1);
	else
		% Требуемый управляющий момент на каждый из 4-х маховиков
		Trwreq_p=Lrw*Trwreq_b;
		% Требуемы кинетический момент
        Hrwreq_p=-DeltaStepACS*Trwreq_p+svHrwreqp(StepACS-1,:)';
	end
    Hrwreq_p=max(min(Hrwreq_p,Hrwmax),-Hrwmax);    
    % Требуемая скорость
    RWRateReq=1/Irw*Hrwreq_p;
%% Маховик как апериодическое звено
% Управляющее ускорение маховиков
eps=(RWRateReq-RWRate)/DeltaStepACS;
% Ограничим сверху и снизу
eps=max(min(eps,Trwmax/Irw),-Trwmax/Irw);
% Новая скорость маховиков
RWRate=RWRate+DeltaStepModel*eps;
% Ограничим сверху и снизу
RWRate=max(min(RWRate,RWRateMax),-RWRateMax);

%% Идеальный маховик
%RWRate=RWRateReq;