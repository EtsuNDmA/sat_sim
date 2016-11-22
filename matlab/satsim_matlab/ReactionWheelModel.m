%% ������ ��������� �������� ��������
	   
	%��������� ������������ ������
	if StepACS==1
        Hrwreq_p=zeros(4,1);
		Trwreq_p=zeros(4,1);
	else
		% ��������� ����������� ������ �� ������ �� 4-� ���������
		Trwreq_p=Lrw*Trwreq_b;
		% �������� ������������ ������
        Hrwreq_p=-DeltaStepACS*Trwreq_p+svHrwreqp(StepACS-1,:)';
	end
    Hrwreq_p=max(min(Hrwreq_p,Hrwmax),-Hrwmax);    
    % ��������� ��������
    RWRateReq=1/Irw*Hrwreq_p;
%% ������� ��� �������������� �����
% ����������� ��������� ���������
eps=(RWRateReq-RWRate)/DeltaStepACS;
% ��������� ������ � �����
eps=max(min(eps,Trwmax/Irw),-Trwmax/Irw);
% ����� �������� ���������
RWRate=RWRate+DeltaStepModel*eps;
% ��������� ������ � �����
RWRate=max(min(RWRate,RWRateMax),-RWRateMax);

%% ��������� �������
%RWRate=RWRateReq;