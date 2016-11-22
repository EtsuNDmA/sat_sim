function [Qjo_est, Worb_est_j] = filter_orb(logorb, Qjb_est, StepModel, DeltaStepModel)
%orb_filter Построение орбитального базиса
% =========================================================================
% ======== Это по факту заплатка. написать нормальный фильтр ==============
% =========================================================================
% Рассчитаем орбитальный базис iorb, jorb korb в проекции на J2000
    currenttime = StepModel*DeltaStepModel/60;
    r = interp1(logorb.tsince, logorb.rj2000, currenttime);
    v = interp1(logorb.tsince, logorb.vj2000, currenttime);
    jorb=r/norm(r);
    korb=cross(v,r)/norm(cross(v,r));
    iorb=cross(jorb,korb);
% Матрица направляющих косинусов от J2000 к орбитальной СК
    DCMjo=[iorb',jorb',korb'];
% Кватернион поворота от J2000 к ОСК
    Qjo_est=dcm2quat(DCMjo')';
    if Qjo_est(1)<0
        Qjo_est=-Qjo_est;
    end
    Worb_est_j = cross(r, v)/(r*r')';
    
end

