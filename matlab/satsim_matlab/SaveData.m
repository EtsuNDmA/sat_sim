    if StepModel==1
%         svMagn=zeros(MaxStepCM,3);
%         svMagnDipolECEF=zeros(MaxStepCM,3);
        svMagnDipolb=zeros(MaxStepCM,3);
        
        svrsunecef=zeros(MaxStepCM,3);
        svrsuneci=zeros(MaxStepCM,3);
        
        svWb=zeros(MaxStepModel,3);
        svNormWb=zeros(MaxStepModel,1);
        svWorbb=zeros(MaxStepModel,3);
        svNob=zeros(MaxStepModel,4);
        svQjb=zeros(MaxStepModel,4);
        
%         svHrwb=zeros(MaxStepModel,3);
        svHrwp=zeros(MaxStepModel,4);
        svRWRate=zeros(MaxStepModel,4);
        
		svWrel1=zeros(MaxStepModel,3);
		svWrel2=zeros(MaxStepModel,3);
		svspalpha1=0;
		svspalpha2=0;
		
		
        svTrwb=zeros(MaxStepModel,3);
        svTgravb=zeros(MaxStepModel,3);
        svTab=zeros(MaxStepModel,3);
        svTgyrob=zeros(MaxStepModel,3);
        svTmb=zeros(MaxStepModel,3);
        
        
        svMagnMomentp=zeros(MaxStepModel,3);
		
		svLightFlag=zeros(MaxStepModel,1);
        
        svQjbmes=zeros(MaxStepACS,4);
        svNobmes=zeros(MaxStepACS,4);
        svWmesb=zeros(MaxStepACS,3);
        svTrwreqb=zeros(MaxStepACS,3);
		svTrwreqp=zeros(MaxStepACS,4);
        svTb=zeros(MaxStepACS,3);
%         svHrwreqb=zeros(MaxStepACS,3);
        svHrwreqp=zeros(MaxStepACS,4);
        svRWRateReq=zeros(MaxStepACS,4);
        svBmesb=zeros(MaxStepACS,3);
        svBdot=zeros(MaxStepACS,3);
        svMagnMomentReqp=zeros(MaxStepACS,3);
        svUunload=zeros(MaxStepACS,1);
        svUdempf=zeros(MaxStepACS,1);
        svRsunb=zeros(MaxStepACS,3);
        svRsunb_mes=zeros(MaxStepACS,3);
		svdWrel1=zeros(MaxStepACS,3);
		svdWrel2=zeros(MaxStepACS,3);
    end;
%     svMagn(StepCM,:)=MagnFieldECEF;
%     svMagnDipolECEF(StepCM,:)=MagnFieldECEFdipol;
    svMagnDipolb(StepCM,:)=MagnFieldDipol_b;
    svrsunecef(StepCM,:)=rsunecef;
    svrsuneci(StepCM,:)=rsun;
    
    
    svWb(StepModel,:)=W_b;
    svNormWb(StepModel)=norm(W_b);
    svWorbb(StepModel,:)=Worb_b;
    svNob(StepModel,:)=Nob;
    svQjb(StepModel,:)=Qjb;
    
	svWrel1(StepModel,:)=Wrel1;
	svWrel2(StepModel,:)=Wrel2;
	svspalpha1(StepModel,:)=spalpha1;
	svspalpha2(StepModel,:)=spalpha2;
	
%     svHrwb(StepModel,:)=Hrw_b;
    svHrwp(StepModel,:)=Hrw_p;
    svRWRate(StepModel,:)=RWRate;
    svTrwb(StepModel,:)=Trw_b;
    svTgravb(StepModel,:)=Tgrav_b;
    svTab(StepModel,:)=Ta_b;
    svTgyrob(StepModel,:)=Tgyro_b;
    svTmb(StepModel,:)=Tm_b;
    
    svjvertb(StepModel,:)=jvert_b;
    
    svMagnMomentp(StepModel,:)=MagnMoment_p;
    
	svLightFlag(StepModel,:)=LightFlag;
	
    svQjbmes(StepACS,:)=Qjb_mes;
    svNobmes(StepACS,:)=Nob_mes;
    svWmesb(StepACS,:)=Wmes_b;
    svTrwreqb(StepACS,:)=Trwreq_b;
	svTrwreqp(StepACS,:)=Trwreq_p;
    svTb(StepACS,:)=T_b;
%     svHrwreqb(StepACS,:)=Hrwreq_b;
    svHrwreqp(StepACS,:)=Hrwreq_p;
    svRWRateReq(StepACS,:)=RWRateReq;
    svBmesb(StepACS,:)=Bmes_b;
    svBdot(StepACS,:)=Bdot;
    svMagnMomentReqp(StepACS,:)=MagnMomentReq_p;
    svUunload(StepACS,:)=Uunload;
    svUdempf(StepACS,:)=Udempf;
    svRsunb(StepACS,:)=Rsunb;
    svRsunb_mes(StepACS,:)=Rsunb_mes;
	
	svdWrel1(StepACS,:)=dWrel1;
	svdWrel2(StepACS,:)=dWrel2;
%     savelat1(StepModel,:)=lat1;
%     savelon1(StepModel,:)=lon1;
%     saveh1(StepModel,:)=h1;
    
%     savetsince(StepModel,:)=tsince;
%     savejdut1(StepModel,:)=jdut1;
%     savemon(StepModel,:)=mon;
%     saveday(StepModel,:)=day;
%     savehr(StepModel,:)=hr;
%     savemin(StepModel,:)=minute;
%     savesec(StepModel,:)=sec;
%     savesatrec(StepModel,:)=satrec;
%     saveincl(StepModel,:)=satrec.inclo;
    
    