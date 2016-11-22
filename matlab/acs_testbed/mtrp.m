function K = mtrp(a,b,A,B)
% W=skewsym(X(5:7)')*p.J;
% g=quatrotate([X(1)+1,X(2:4)'],[0 -9.8 0]);
% G=-p.M*skewsym(g);
% D=skewsym(X(2:4))+eye(3);

% A=[0 -0.5*X(5:7)' zeros(1,6);
% 	0.5*X(5:7) zeros(3) D zeros(3);
% 	zeros(3,1) -p.Kl*eye(3)*(X(1)+1) -p.Kw*eye(3)-W G;
% 	zeros(3,10)]
% eig(A)
% B=[zeros(7,3);
% 	eye(3)];

F3=b;
F2=a*eye(3);
F1=a*eye(3);
F0=a*eye(3);

A0=A;
B0=B;
Bld0=[eye(7) zeros(7,3)];
	fprintf('cond(Bld0)=%e\n',cond(Bld0))
Bldpi0=pinv(Bld0);
	fprintf('cond(B0)=%e\n',cond(B0))
Bpi0=pinv(B0);

A1=Bld0*A0*Bldpi0;
B1=Bld0*A0*B0;
Bld1=[eye(4) zeros(4,3)];
Bldpi1=pinv(Bld1);
	fprintf('cond(Bld1)=%e\n',cond(Bld1))
Bpi1=pinv(B1);
	fprintf('cond(B1)=%e\n',cond(B1))

A2=Bld1*A1*Bldpi1;
B2=Bld1*A1*B1;
Bld2=[1 zeros(1,3)];
Bldpi2=pinv(Bld2);
	fprintf('cond(Bld2)=%e\n',cond(Bld2))
Bpi2=pinv(B2);
	fprintf('cond(B2)=%e\n',cond(B2))

A3=Bld2*A2*Bldpi2;
B3=Bld2*A2*B2;
T3=B3;
Ahat3=A3;
Bhat3=1;
Bhatpi3=Bhat3^-1;

Khat3=Bhatpi3*Ahat3-F3*Bhatpi3;
Tpi3=pinv(T3);
	fprintf('cond(T3)=%e\n',cond(T3))
K3=Tpi3*Khat3;


Bm2=Bpi2+K3*Bld2;
K2=Bm2*A2-F2*Bm2;

Bm1=Bpi1+K2*Bld1;
K1=Bm1*A1-F1*Bm1;

Bm0=Bpi0+K1*Bld0;
K0=Bm0*A0-F0*Bm0;
K=K0;

end

