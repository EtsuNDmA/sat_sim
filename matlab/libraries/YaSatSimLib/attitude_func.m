function dx = attitude_func(t, x)
%odefunct Кинематика, динамика ТТ и упругих колебаний, динамика СБ
% Входы:
%    t - ...
%    x - [rigid_ang_rate - угловая скорость твердого тела,
%        sp1_ang_rate - относительная угловая скорость панели СБ1,
%        sp2_ang_rate - относительная угловая скорость панели СБ2,
%        dflex - вектор 1-х производных ортогональных координат в
%            пространстве Галеркина,
%        flex - вектор ортогональных координат в пространстве Галеркина,
%        quat - кватернион ориентации,
%        sp1_ang - относительный поворот СБ1,
%        sp2_ang - относительный поворот СБ1]
% Глобальные переменные:
%    dxparams - структура параметров:
%        .invA,
%        .invInertia,
%        .Inertia,
%        .Torque,
%        .flexparams - структура параметров осцилляторов
%            .freq,
%            .dempf,
%            .fi = [fi_rw_1; ...; fi_rw_N]
%                N - количество мод колебаний
%        .sp1_eps - угловое ускорение СБ1,
%        .sp2_eps - угловое ускорение СБ2
global dxparams
invInertia = dxparams.invInertia;
Inertia = dxparams.Inertia;
Torque = dxparams.Torque;
freq = dxparams.flexparams.freq;
dempf = dxparams.flexparams.dempf;
fi = dxparams.flexparams.fi;
sp1_eps = dxparams.sp1_eps;
sp2_eps = dxparams.sp2_eps;
N = size(fi,1);

rigid_ang_rate = x(1:3, 1);
sp1_ang_rate = x(4, 1);
sp2_ang_rate = x(5, 1);
dflex = x(6:6+N-1, 1);
flex = x(6+N:6+2*N-1, 1);
quat = x(6+2*N:6+2*N+3, 1);

dx(1:5, 1) = [invInertia*(Torque'-cross(rigid_ang_rate,Inertia*rigid_ang_rate));
                sp1_eps;
                sp2_eps];
dx(6:6+N-1, 1) = -2*dempf'.*freq'.*dflex-4*pi^2*freq'.^2.*flex+fi*Torque';
dx(6+N:6+2*N-1, 1) = dflex;
dx(6+2*N:6+2*N+3, 1) = [ -0.5*rigid_ang_rate'*quat(2:4);
                      0.5*(quat(1)*rigid_ang_rate+cross(quat(2:4),rigid_ang_rate))
                    ];
dx(6+2*N+4, 1) = sp1_ang_rate;
dx(6+2*N+5, 1) = sp2_ang_rate;

end

