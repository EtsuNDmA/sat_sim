%% Модель ДУСа
% Идеальный
% 	Wmes_b=W_b;
% Неидеальный
%     RSN=random('Normal',0,SigmaRSN,3,1);
%     RSB=0;
    RSN=random('Normal',0,1e-4,3,1);
    RSB=0;

    Wmes_b=(eye(3)+RSSE)*W_b+RSB+RSN;
%% БИНС
% Коррекция БИНС
    % Здесь Qjb - измерение звездного датчика
    if rem(StepACS,50)==0
        Nbb_mes=quatmultiply(quatinv(Qjb'),Qjb_mes')';
    else
        Nbb_mes=[1 0 0 0]';
    end;
% Кинематический контур управления
    if StepACS==1
        Qjb_mes=quatmultiply(Qjo',Nob')';
    end
    Qjb_mes=quatint(Qjb_mes',Wmes_b',2,DeltaStepACS)';
    % Корректируем БИНС
    Qjb_mes=quatmultiply(Qjb_mes',quatinv(Nbb_mes'))';
%     norm(Qjb_mes-Qjb)
    %Вычисленное на борту рассогласование
    Nob_mes=quatmultiply(quatinv(Qjo'),Qjb_mes')';
    
%% Модель СД
	Rsunb=quatrotate(Qjb_mes',rsun)';
	Rsunb_mes=Rsunb;
%% Солнечная ориентация
	if strcmp(Mode,'Sun')
		Trwreq_b=-(K1acsS*cross(Rsunb_mes',Raimb')'+K2acsS*Wmes_b);
	end;
%% 3-осная стабилизация 
% Динамический контур управления
    Worb_b=quatrotate(Qjb_mes',Worb_j')';
% Требуемый момент
%Alg1
    Wrelb=Wmes_b-Worb_b;
    Nf=Nob_mes(1)*Nob_mes(2:4);
    if strcmp(Mode,'Stab3')
        Trwreq_b=-J_b*(K1acs*Nf+K2acs*Wrelb);
	else
		Trwreq_b=[0 0 0]';
    end;
%     
    %Alg2
%         Wrelb=Wmes_b-Worb_b;
%         Nf=Nob_mes(1)*Nob_mes(2:4);
%         
%         Wturn=0.0017*3;
%         for i=1:3
%             if abs(Nf(i))<Wturn*K2acs/K1acs
%                 Trwreq_b(i,1)=-(K1acs*Nf(i)+K2acs*Wrelb(i));
%             else
%                 Trwreq_b(i,1)=-K2acs*(Wrelb(i)+sign(Nf(i))*Wturn);
%             end;
%         end;
    %Alg3
    %     if StepACS==1
    %         Tfwreq_b=[0;0;0];
    %         hist=0;
    %     else
    %         if abs(Nob(1))>0.3
    %             hist=Nob_mes(1);
    %         elseif svhist(StepACS-1)>=0
    %             hist=abs(Nob_mes(1));
    %         else
    %             hist=-abs(Nob_mes(1));
    %         end;
    %         Tfwreq_b=-(K1acs*hist*Nob_mes(2:4)+K2acs*(Wmes_b-Worb_b));
    %     end;
       % Tfwreq_b=-(K1acs*hist*Nob_mes(2:4)+K2acs*(Wmes_b-Worb_b));
        %Alg4
    %     hist=0.000001;
    %     if abs(Nob(1))>0.1
    %         histold=hist;
    %         hist=sign(Nob(1));
    %     else
    %         histold=hist;
    %         hist=sign(histold);
    %     end;
    %     Tfwreq_b=-(K1acs*hist*Nob_mes(2:4)+K2acs*(Wmes_b-Worb_b));
        %Tfwreq_b=-(K1acs*sign(Nob_mes(1))*Nob_mes(2:4)+K2acs*(Wmes_b-Worb_b));

    
        % Ограничим требуемый момент
    Trwreq_b=max(min(Trwreq_b,Trwmax),-Trwmax);
    

%% Модель магнитометра
Bmes_b=MagnFieldDipol_b;
%% Гашение угловой скорости, алгоритм -Bdot
    Bdot=zeros(3,1);
    if strcmp(Mode,'Detumbling')
        if norm(Wmes_b)>0.1*d2r
            Udempf=1;
        else
            Udempf=0;
        end;
        if Udempf==1
            if StepACS==1
                MagnMomentReq_b=zeros(3,1);
                MagnMomentReq_p=zeros(3,1);
                Bdot=zeros(3,1);
            else
                Bdot=Bmes_b-svBmesb(StepACS-1,:)';
                MagnMomentReq_b=-Kbdot*Bdot*10^-9/DeltaStepACS/norm(Bmes_b*10^-9)^2;
    %             MagnMomentReq_b=-sign(Bmes_b-svBmesb(StepACS-1))*MagnMomentMax;
                MagnMomentReq_p=quatrotate(QMbp,MagnMomentReq_b')';
            end;
        else
            MagnMomentReq_b=zeros(3,1);
            MagnMomentReq_p=zeros(3,1);
        end;
    end;
%% Разгрузка маховиков
    if Udempf==0
        if Uunload==1 && norm(Arw*Hrw_p)>=Hlow
            Uunload=1;
        elseif Uunload==0 && norm(Arw*Hrw_p)>=Hhigh
            Uunload=1;
        else
            Uunload=0;
        end;
        if Uunload==1
            MagnMomentReq_b=-Kul/norm(Bmes_b*10^-9)^2*cross(Bmes_b*10^-9,Arw*Hrw_p);
        else
            MagnMomentReq_b=[0;0;0];
        end;
        MagnMomentReq_p=quatrotate(QMbp,MagnMomentReq_b')';
    end;
%% Управление солнечными батареями
DA=spalpha1-atan2(Rsunb_mes(1),Rsunb_mes(2));
if abs(DA)>pi
	DA=DA-sign(DA)*2*pi;
end;
svDA(StepACS)=DA;

if DA>d2r*5
	spen=1;
elseif DA<-d2r*5
	spen=0;
end;
spu=(-0.0002+0.2*Wrel1(3))*spen;
dWrel1=[0;0;spu]-0.2*Wrel1;
dWrel2=[0;0;spu]-0.2*Wrel1;