dOmega=[0 0.0002 0]';

a=0;
b=deg2rad(45);

M1=29.7;
J1=diag([630 36 652]);
a1=[0 -0.5 0]+[0 -4.1 0];
A1=angle2dcm(a,b,0,'YXZ');

M2=30.2;
J2=diag([950 24 962]);
a2=[0 -0.5 0]+[0 -5 0];
A2=angle2dcm(a,b,0,'YXZ');


J10=A1'*J1*A1
J20=A2'*J2*A2

Trw1=2*J10*dOmega
Trw2=2*J20*dOmega