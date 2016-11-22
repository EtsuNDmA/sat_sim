p.J=diag([8200 8200 3200]);
p.invJ=p.J^-1;
p.mgr=4;
p.m=400;
p.Kl=0.026;
p.Kw=0.32;
p.a=-100;
p.b=-1;
% [la00 la1 la2 la3 w1 w2 w3 r1 r2 r3], la00=la0-1
X0=[0.0001001 0.098 0.099 0.01 0.0002 0.00015 0.0001 0.00014 0.00011 0.000109]';

L=skewsym(X0(2:4));
W=-p.invJ*skewsym(X0(5:7))*p.J;
g=quatrotate([X0(1)+1,X0(2:4)'],[0 -9.8 0]);
G=-p.m*skewsym(g);
D=L+eye(3);
Mu=p.mgr/p.m*eye(3);
% Якобиан
Mj(1:3,1)=2*9.8*p.m*cross([X0(4);X0(1)+1;X0(2)],X0(8:10));
Mj(1:3,2)=2*9.8*p.m*cross([X0(3);-X0(2);-X0(1)-1],X0(8:10));
Mj(1:3,3)=2*9.8*p.m*cross([X0(2);X0(3);X0(4)],X0(8:10));
Mj(1:3,4)=2*9.8*p.m*cross([X0(1)+1;-X0(4);-X0(2)],X0(8:10));
Mj(1:3,5:7)=skewsym(p.J*X0(5:7))-skewsym(X0(5:7))*p.J;
Mj(1:3,8:10)=9.8*p.m*skewsym(...
	[2*(X0(2)*X0(3)+(X0(1)+1)*X0(4));
	(X0(1)+1)^2-X0(2)^2+X0(3)^2-X0(4)^2;
	2*(X0(3)*X0(4)-(X0(1)+1)*X0(2))]);
A=[	0					-0.5*X0(5:7)'		zeros(1,3)			zeros(1,3);
    0.5*X0(5:7)			zeros(3)			0.5*D				zeros(3);
	p.invJ*Mj(:,1)		p.invJ*Mj(:,2:4)	p.invJ*Mj(:,5:7)	p.invJ*Mj(:,8:10);
	zeros(3,1)			zeros(3)			zeros(3)			zeros(3)];
% A=[		0		-0.5*X0(5:7)'				zeros(1,3)		zeros(1,3);
%    0.5*X0(5:7)		zeros(3)				0.5*D		zeros(3);
% 	zeros(3,1)		-p.Kl*p.J*(X(1)+1)		-p.Kw*p.J+W			G;
% 	zeros(3,1)		zeros(3)				zeros(3)	zeros(3)];
B=[zeros(4,3)	zeros(4,3);
	p.invJ		zeros(3);
	zeros(3)	Mu];
% B=[zeros(1,3);
%    zeros(3);
%    zeros(3);
%    M];

% C=[0 0 0 0 1 0 0 0 0 0;
%    0 0 0 0 0 1 0 0 0 0;
%    0 0 0 0 0 0 1 0 0 0];
C=[eye(7) zeros(7,3)];
% Матрица управляемости
MC=ctrb(A,B); 
fprintf('Rank of MC is %d\n',rank(MC))
% Матрица наблюдаемости
MO=obsv(A,C);
fprintf('Rank of MO is %d\n',rank(MO))