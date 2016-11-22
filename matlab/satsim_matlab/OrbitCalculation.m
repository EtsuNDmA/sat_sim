%% Загрузим данные
% Проверим, существует ли файл с орбитальными данными и данными по
% магнитному полю

fid1=fopen('orbitData.mat', 'r+');
fid2=fopen('magnData.mat', 'r+');
if fid1>0 && fid2>0
    fclose(fid1);
    fclose(fid2);
    load('orbitData.mat');
    load('magnData.mat');
    % Если параметры изменились, то считаем заново
    if ~((svDeltaStepCM      == DeltaStepCM) && ...
        (svMaxStepCM         == MaxStepCM) && ...
        (svteme2eci_order    == teme2eci_order) && ...
        (sveqeterms          == eqeterms) && ...
        (svteme2eci_opt      == teme2eci_opt) && ...
        (isequal(svTLEstr1,TLEstr1)) && ...
        (isequal(svTLEstr2,TLEstr2)) && ...
        (svtwoline2rv_whichconst == twoline2rv_whichconst) && ...
        (svtwoline2rv_typerun    == twoline2rv_typerun) && ...
        (svtwoline2rv_typeinput	 == twoline2rv_typeinput) && ...
        (svtimezone          == timezone) && ...
        (svdut1              == dut1) && ...
        (svdat               == dat) && ...
        (svMearth            == Mearth) && ...
        (svMuEarth           == MuEarth) && ...
        (svlod               == lod) && ...
        (svxp                == xp) && ...
        (svyp                == yp) && ...
        (svddpsi             == ddpsi) && ...
        (svddeps             == ddeps))
        
        orbitMode=0;
    else
        orbitMode=1;
    end;
else
    orbitMode=0;
end;
%% Расчет орбиты
if orbitMode==0
    svRteme     = zeros(MaxStepCM,3);
    svVteme     = zeros(MaxStepCM,3);
    svAteme     = zeros(MaxStepCM,3);
    svrj2000    = zeros(MaxStepCM,3);
    svvj2000    = zeros(MaxStepCM,3);
    svaj2000    = zeros(MaxStepCM,3);
    svrecef     = zeros(MaxStepCM,3);
    svvecef     = zeros(MaxStepCM,3);
    svaecef     = zeros(MaxStepCM,3);
    svQjo       = zeros(MaxStepCM,4);
    svlatgc     = zeros(MaxStepCM,1);
    svlatgd     = zeros(MaxStepCM,1);
    svlon       = zeros(MaxStepCM,1);
    svhellp     = zeros(MaxStepCM,1);
    svWorb_j    = zeros(MaxStepCM,3);
    
    svMagn          = zeros(MaxStepCM,3);
    svMagnDipolECEF = zeros(MaxStepCM,3);
    svMagnDipolECI  = zeros(MaxStepCM,3);
    for StepCM=1:MaxStepCM
        % Вычисляем время
        TimeOrbit;
        % Рассчитываем новый вектор состояния
        [satrec, r, v] = sgp4(satrec,tsince);
        Rteme = r;
        Vteme = v;
        Ateme = zeros(1,3);
        % Перепроектируем вектор состояния из TEME в J2000
        [rj2000,vj2000,aj2000] = teme2eci  ( Rteme',Vteme',Ateme',ttt,...
            teme2eci_order,eqeterms,teme2eci_opt );
        % Перепроектируем положение аппарата на ECEF
        [recef,vecef,aecef] = eci2ecef( rj2000,vj2000,aj2000,ttt,jdut1,lod,xp,yp,eqeterms,ddpsi,ddeps );
        % Рассчитаем орбитальный базис iorb, jorb korb в проекции на J2000
        jorb=rj2000/norm(rj2000);
        korb=cross(vj2000,rj2000)/norm(cross(vj2000,rj2000));
        iorb=cross(jorb,korb);
        % Матрица направляющих косинусов от J2000 к орбитальной СК
        DCMjo=[iorb';jorb';korb'];
        % Кватернион поворота от J2000 к ОСК
        Qjo=dcm2quat(DCMjo)';
        if Qjo(1)<0
            Qjo=-Qjo;
        end;
        %Найдем геодезическую широту, долготу и высоту над эллипсойдом
        [latgc,latgd,lon,hellp] = ijk2ll ( recef );
        %Орбитальная угловая скорость
        Worb_j=cross(rj2000',vj2000')'/(rj2000'*rj2000);
        %Сохраним результаты
        svRteme(StepCM,:)   = Rteme;
        svVteme(StepCM,:)   = Vteme;
        svAteme(StepCM,:)   = Ateme;
        svrj2000(StepCM,:)  = rj2000;
        svvj2000(StepCM,:)  = vj2000;
        svaj2000(StepCM,:)  = aj2000;
        svrecef(StepCM,:)   = recef;
        svvecef(StepCM,:)   = vecef;
        svaecef(StepCM,:)   = aecef;
        svQjo(StepCM,:)     = Qjo';
        svlatgc(StepCM,:)   = latgc;
        svlatgd(StepCM,:)   = latgd;
        svlon(StepCM,:)     = lon;
        svhellp(StepCM,:)   = hellp;
        svWorb_j(StepCM,:)  = Worb_j';
        if mod(StepCM/MaxStepCM*100,2)==0
            dddd=floor(StepCM/MaxStepCM*100);
            disp(dddd);
        end;
        
        %% Рассчитаем магнитное поле
        %Модель диполя
        normRecef=norm(recef); % км
        MagnFieldECEFdipol=(3*(MagnMomentum*recef)*recef'-normRecef^2*MagnMomentum)/normRecef^5;% нТл
        [MagnFieldDipol_j,~,~] = ecef2eci(MagnFieldECEFdipol',[0 0 0]',[0 0 0]',...
            ttt,jdut1,lod,xp,yp,eqeterms,ddpsi,ddeps);
        %Модель IGRF 11
        %Найдем магнитное поле в NED
        % !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        % Тут есть заплатка "decyear(year,mon,day,hr,minute,sec)-2" - минус 2
        % нужен,т.к. igrf11 не работает после 2014 года!!!!!!!!!!!!!!!!!!!!!!!
        % !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
%         [MagnFieldNED, MagnHoorizIntens, MagnDecl, MagnIncl, MagnTotalIntens]...
%             = igrf11magm(hellp*1000, latgd/d2r, lon/d2r, decyear(year,mon,day,hr,minute,sec)-2);
        %Пересчитаем в ECEF
%         [MagnFieldECEF(1),MagnFieldECEF(2),MagnFieldECEF(3)] = ned2ecef( ...
%             MagnFieldNED(:,1)',MagnFieldNED(:,2)',MagnFieldNED(:,3)',...
%             latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
        %Выше мы посчитали координаты конца вектора магнитной индукции в ECEF,
        %нужно еще вычесть координаты начала координат NED в ECEF
% 
%         [x0ecef,y0ecef,z0ecef] = ned2ecef( ...
%             0,0,0,...
%             latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
%         MagnFieldECEF=MagnFieldECEF-[x0ecef y0ecef z0ecef];
        
        % Сохраним результаты
%         svMagn(StepCM,:)            = MagnFieldECEF;
        svMagnDipolECEF(StepCM,:)   = MagnFieldECEFdipol;
        svMagnDipolECI(StepCM,:)    = MagnFieldDipol_j;
    end;
    % Сохраним параметры
    svDeltaStepCM       = DeltaStepCM;
    svMaxStepCM         = MaxStepCM;
    svteme2eci_order    = teme2eci_order;
    sveqeterms          = eqeterms;
    svteme2eci_opt      = teme2eci_opt;
    svTLEstr1           = TLEstr1;
    svTLEstr2           = TLEstr2;
    svtwoline2rv_whichconst	= twoline2rv_whichconst;
    svtwoline2rv_typerun    = twoline2rv_typerun;
    svtwoline2rv_typeinput	= twoline2rv_typeinput;
    svtimezone          = timezone;
    svdut1              = dut1;
    svdat               = dat;
    svMearth            = Mearth;
    svMuEarth           = MuEarth;
    svlod               = lod;
    svxp                = xp;
    svyp                = yp;
    svddpsi             = ddpsi;
    svddeps             = ddeps;
    save('orbitData',...
        'svRteme','svVteme','svAteme','svrj2000','svvj2000','svaj2000', ...
        'svrecef','svvecef','svaecef','svQjo','svlatgc',...
        'svlatgd','svlon','svhellp','svWorb_j', 'svDeltaStepCM',...
        'svMaxStepCM','svteme2eci_order','sveqeterms','svteme2eci_opt',...
        'svTLEstr1','svTLEstr2','svtwoline2rv_whichconst',...
        'svtwoline2rv_typerun','svtwoline2rv_typeinput','svtimezone',...
        'svdut1','svdat','svMearth','svMuEarth','svlod','svxp','svyp',...
        'svddpsi','svddeps');
    save('magnData','svMagn','svMagnDipolECEF','svMagnDipolECI');
end;
StepCM=1;