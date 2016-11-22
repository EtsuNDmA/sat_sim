%% Кинематика
    if StepACS==1
        Qjb=quatmultiply(Qjo',Nob')';
    end
    Qjb=quatint(Qjb',W_b',1,DeltaStepModel)';
    if Qjb(1)<0
        Qjb=-Qjb;
    end;
	% Рассогласования базисов
	Nob=quatmultiply(quatinv(Qjo'),Qjb')';
	if Nob(1)<0
		Nob=-Nob;
	end;
%% Динамика
% Динамика солнечных батарей
	Wrel1=Wrel1+DeltaStepModel*dWrel1;
	Wrel2=Wrel2+DeltaStepModel*dWrel2;
	spalpha1=spalpha1+DeltaStepModel*Wrel1(3);
	spalpha2=spalpha2+DeltaStepModel*Wrel2(3);
	
	spalpha1=atan2(sin(spalpha1),cos(spalpha1));
	spalpha2=atan2(sin(spalpha2),cos(spalpha2));
% Матрицы поворота СБ
	M_bs_sp1=angle2dcm(spalpha1,spbeta1,0,'ZXY');
	M_bs_sp2=angle2dcm(spalpha2,spbeta2,0,'ZXY');
% ЦМ панелей (БССК)
	OC1=OO1+M_bs_sp1'*O1C1;
	OC2=OO2+M_bs_sp2'*O2C2;
% ЦМ аппарата (БССК)
	OC=(OC0*BMASS+OC1*SPMASS+OC2*SPMASS)/MASS;
% Радиус-вектор из ЦМ СБ в ЦМ корпуса
	C1C=OC-OC1;
	C2C=OC-OC2;
% Тензор инерции СБ относительно точки крепления
	JO1=hsinertia(Jsp1,SPMASS,-OC1+OO1,M_bs_sp1);
	JO2=hsinertia(Jsp2,SPMASS,-OC2+OO2,M_bs_sp2);
% Момент инерции аппарата
	J_b=Jbody_b+hsinertia(Jsp1,SPMASS,C1C,M_bs_sp1)+hsinertia(Jsp2,SPMASS,C2C,M_bs_sp2);
	invJ_b=J_b^-1;
% Момент маховиков
    Hrw_p=Irw*RWRate;
    if StepModel==1
        Trw_b=zeros(3,1);
    else
        Trw_b=-Arw/DeltaStepModel*(Hrw_p-svHrwp(StepModel-1,:)')-cross(W_b,Arw*Hrw_p);
    end;
% Магнитный момент в связанных осях
    MagnFieldDipol_b=quatrotate(Qjb',MagnFieldDipol_j)';
    MagnMoment_b=quatrotate(quatinv(QMbp),MagnMoment_p')';
    Tm_b=cross(MagnMoment_b',MagnFieldDipol_b'*10^-9)';
% Гравитационный момент в связанных осях
    % Вектор от центра Земли к ЦМ аппарата в проекции на ССК
    jvert_b=quatrotate(Nob',jvert_o')';
    % Гравитационный момент
    Tgrav_b=3*MuEarth/norm(rj2000*1000)^3*cross(jvert_b',(J_b*jvert_b)')';
% Аэродинамический момент в связанных осях
	% Геометрия
% 	Rcp=[4.6*SPM1+[0; .635; -.76], 4.6*SPM2+[0; .635; .76]];
% 	PlanesNormals=[SPN1 SPN2];
%     Ta_b=taero(PlanesArea,PlanesNormals,quatrotate(Qjb',vj2000)',DiffusCoeff,Rcp,Rho);
	Ta_b=zeros(3,1);
% Гироскопический момент корпуса и СБ
    Tgyro_b=-cross(W_b',(J_b*W_b+JO1*Wrel1+JO2*Wrel2)')';
% Динамика аппарата
    T_b=Trw_b+Tgyro_b+Tgrav_b+Tm_b+Ta_b;
    W_b=W_b+DeltaStepModel*(invJ_b)*(T_b-JO1*dWrel1-JO2*dWrel2);
		%Неучтенные слагаемые
% 		cross(Wrel1',(Jsp1*(W_b+Wrel1))')'-...
% 		cross(Wrel2',(Jsp2*(W_b+Wrel2))')'-...
% 		cross(W_b',(Jsp1*Wrel1+Jsp2*Wrel2)')'-...
