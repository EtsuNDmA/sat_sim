function [N] = quatint(quat0,omega,mode,step)
%�����: quat0 - ��������� ���������� (1�4)
%       omega - ������� �������� �� ������ ���� (1�3)
%       mode - ����� ������: 1 - ������������ ��������, 
%                            2 - �������������� ������������
%       step - ��� �������������� � �
%������: N - �������� ����������
%
%������� ����������� ������ ���������� O=quatint0
%� ���������� ������� ��������� omega, �� ���� h=0.2���
%�� ������ ����� ���������� N 

if mode==1
    theta=omega*step;   % ������ ���������� ��������
    thetaNorm=sqrt(theta*theta');
    if thetaNorm==0
        Q=[1 0 0 0];
    else
        S=sin(thetaNorm/2);
        e=theta/thetaNorm;
        Q=[cos(thetaNorm/2) e*S];
    end
        N=quatmultiply(quat0,Q);
        N=N/norm(N);
else
    O=quat0;
    Q(2:4)=omega*step*0.5;
    QP=Q(2)^2+Q(3)^2+Q(4)^2;
    OP=O(1)^2+O(2)^2+O(3)^2+O(4)^2;
    Q(1)=0.5*(3-OP-QP);
    N=quatmultiply(O,Q);
end

