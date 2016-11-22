function log = calc_orb(sgp4params, MaxStep, DeltaStep, earthparams)
%calc_orb вычисляет орбиту на период MaxStepModel*DeltaStepmodel 
%   с шагом StepMode
    log.tsince     = zeros(MaxStep,1);
    log.jdut1      = zeros(MaxStep,1);
    log.utc        = zeros(MaxStep,1);
    log.ttt        = zeros(MaxStep,1);
    log.deciyear   = zeros(MaxStep,1);
    log.dayofyear  = zeros(MaxStep,1);
    log.rj2000     = zeros(MaxStep,3);
    log.vj2000     = zeros(MaxStep,3);
    log.recef      = zeros(MaxStep,3);
    log.vecef      = zeros(MaxStep,3);
    log.latgc      = zeros(MaxStep,1);
    log.latgd      = zeros(MaxStep,1);
    log.lon        = zeros(MaxStep,1);
    log.hellp      = zeros(MaxStep,1);
    log.Worb_j     = zeros(MaxStep,3);

    log.epochyr    = sgp4params.satrec.epochyr;
    log.epochdays  = sgp4params.satrec.epochdays;
    
    if (sgp4params.satrec.epochyr < 57)
        year = sgp4params.satrec.epochyr + 2000;
    else
        year = sgp4params.satrec.epochyr + 1900;
    end;
    
    for Step=1:MaxStep
    
    % Время с начала эпохи в минутах
        tsince = (Step-1)*DeltaStep/60;
        [mon, day, hr, minute, sec] = days2mdh(year, sgp4params.satrec.epochdays);
        minute = minute+tsince;
        [~, ~, jdut1, utc, ~, ~, ttt, ~, ~, ~, ~, ~, ~, ~, ~ ] =...
            convtime(year, mon, day, hr, minute, sec,...
               earthparams.timezone, earthparams.dut1, earthparams.dat );
        sgp4params.satrec.jdsatepoch = jdut1;
        deciyear = decyear(year,mon,day,hr,minute,sec);
        dayofyear = fix(sgp4params.satrec.epochdays+((sec/60.0 + minute )/60.0+hr)/24.0);
    % Рассчитываем новый орбитальный вектор состояния
        [sgp4params.satrec, Rteme, Vteme] = sgp4(sgp4params.satrec,tsince);
        % Перепроектируем вектор состояния из TEME в J2000
        [rj2000,vj2000,~] = teme2eci  ( Rteme',Vteme',[0 0 0]',ttt,...
        sgp4params.teme2eci_order,sgp4params.eqeterms,sgp4params.teme2eci_opt );
    % Перепроектируем положение аппарата на ECEF
        [recef,vecef,~] = eci2ecef( rj2000,vj2000,[0 0 0]',ttt,jdut1,...
        earthparams.lod,earthparams.xp,earthparams.yp,sgp4params.eqeterms,...
        earthparams.ddpsi,earthparams.ddeps);
    %Найдем геодезическую широту, долготу и высоту над эллипсойдом
        [latgc,latgd,lon,hellp] = ijk2ll ( recef );
    %Орбитальная угловая скорость
        Worb_j=cross(rj2000',vj2000')'/(rj2000'*rj2000);
    % Сохраняем данные текущего цикла
        log.tsince(Step,:)     = tsince;
        log.jdut1(Step,:)      = jdut1;
        log.utc(Step,:)        = utc;
        log.ttt(Step,:)        = ttt;
        log.deciyear(Step,:)   = deciyear;
        log.dayofyear(Step,:)  = dayofyear;
        log.rj2000(Step,:)     = rj2000;
        log.vj2000(Step,:)     = vj2000;
        log.recef(Step,:)      = recef;
        log.vecef (Step,:)     = vecef;
        log.latgc(Step,:)      = latgc;
        log.latgd(Step,:)      = latgd;
        log.lon(Step,:)        = lon;
        log.hellp(Step,:)      = hellp;
        log.Worb_j(Step,:)     = Worb_j;
        
        if mod(Step/MaxStep*100,2)==0
            progress=floor(Step/MaxStep*100);
            disp(progress);
        end;
    end