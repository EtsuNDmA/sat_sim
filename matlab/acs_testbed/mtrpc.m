function K = mtrpc(a,b,A,C)

F3=b;
F2=a*eye(3);
F1=a*eye(3);
F0=a*eye(3);
%0-level
A0=A'
C0=C'
Cld0=[zeros(3,7) eye(3)]
	fprintf('cond(Cld0)=%e\n',cond(Cld0))
Cldpi0=pinv(Cld0)
	fprintf('cond(C0)=%e\n',cond(C0))
Cpi0=pinv(C0)
%1-level
A1=Cld0*A0*Cld0'
C1=Cld0*A0*C0
T1=C1
%1m-level
Ahat1=A1
Chat1=eye(3)
Chatpi1=pinv(Chat1)
Chatld1=[0 1 0;0 0 1;1 0 0];

A1=Bhatld1*A1*Bhatld1'


Khat1=Chatpi1*Ahat1-F1*Chatpi1
K1=pinv(T1)


Khat3=Chatpi3*Ahat3-F3*Chatpi3;
Tpi3=pinv(T3);
	fprintf('cond(T3)=%e\n',cond(T3))
K3=Tpi3*Khat3;

Cm2=Cpi2+K3*Cld2;
K2=Cm2*A2-F2*Cm2;

Cm1=Cpi1+K2*Cld1;
K1=Cm1*A1-F1*Cm1;

Cm0=Bpi0+K1*Cld0;
K0=Cm0*A0-F0*Cm0;
K=K0;

end

