function dx = attitudefunc(t, x, dxparams)
%odefunct ����������, �������� �� � ������� ���������, �������� ��
%�����:
%    t - ...
%    x - [rigid_ang_rate - ������� �������� �������� ����,
%        sp1_ang_rate - ������������� ������� �������� ������ ��1,
%        sp2_ang_rate - ������������� ������� �������� ������ ��2,
%        dflex - ������ 1-� ����������� ������������� ��������� �
%            ������������ ���������,
%        flex - ������ ������������� ��������� � ������������ ���������,
%        quat - ���������� ����������,
%        sp1_ang - ������������� ������� ��1,
%        sp2_ang - ������������� ������� ��1]
%    dxparams - ��������� ����������:
%        .invA,
%        .invInertia,
%        .Inertia,
%        .Torque,
%        .flexparams - ��������� ���������� ������������
%            .freq,
%            .dempf,
%            .fi = [fi_rw_1; ...; fi_rw_N]
%                N - ���������� ��� ���������
%        sp1_eps - ������� ��������� ��1,
%        sp2_eps - ������� ��������� ��2
invA = dxparams.invA;
invInertia = dxparams.invInertia;
Inertia = dxparams.Inertia;
Torque = dxparams.Torque;
freq = dxparams.flexparams.freq;
dempf = dxparams.flexparams.dempf;
fi = dxparams.flexparams.fi;
sp1_eps = dxparams.sp1_eps;
sp2_eps = dxparams.sp2_eps;
N = size(fi,1);

rigid_ang_rate = x(1:3);
sp1_ang_rate = x(4);
sp2_ang_rate = x(5);
dflex = x(5:5+N-1);
flex = x(5+N:5+2*N-1);
quat = x(5+2*N:5+2*N+3);

dx(1:5+N-1) = invA*[  
                  invInertia*(Torque'-cross(rigid_ang_rate',Inertia*rigid_ang_rate'));
                  sp1_eps;
                  sp2_eps;
                  -2*dempf'.*freq'.*dflex'-4*pi^2*freq'.^2.*flex'+fi*Torque';]';
dx(5+N:5+2*N-1) = dflex;
dx(5+2*N:5+2*N+3) = [ -0.5*rigid_ang_rate*quat(2:4)';
                      0.5*(quat(1)*rigid_ang_rate'+cross(quat(2:4)',rigid_ang_rate'))
                    ]';
dx(5+2*N+4) = sp1_ang_rate;
dx(5+2*N+5) = sp2_ang_rate;

end

