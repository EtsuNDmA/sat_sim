function dX = func(t,X,p)
%u=zeros(6,1);
u=[-p.Kl*X(1)*X(2:4)-p.Kw*X(5:7);
	[0 0 0]']

% la00=x(1);
% la=x(2:4)';
% w=x(5:7)';
% r=x(8:10)';
% L=[0 -la(3) la(2);
%    la(3) 0 -la(1);
%    -la(2) la(1) 0];
% g=quatroatate(x(1:4),[0 -9.8 0]);
% 
% dx(1)=-0.5*la'*w;
% dx(2:4)=(0.5*(la00+1+L)*w)';
% dx(5:7)=-cross(w',(J*w)')+m*cross(g,r)+u(1:3);
% dx(8:10)=u(4:6);
W=skewsym(X(5:7)')*p.J;
g=quatrotate([X(1)+1,X(2:4)'],[0 -9.8 0]);
G=-p.M*skewsym(g);
D=skewsym(X(2:4))+eye(3);

A=[0 -0.5*X(5:7)' zeros(1,6);
	0.5*X(5:7) zeros(3) D zeros(3);
	zeros(3,1) zeros(3) W G;
	zeros(3,10)];
B=[zeros(4,6);
	eye(6)];
C=[eye(7),zeros(7,3)];

C1=[zeros(3,7),eye(3)];
invCC=[C;C1]^-1;
L1=invCC(:,1:7);
L2=invCC(:,8:10);
K=p.K;

x=X(1:10);
q=X(11:13);
y=C*x;

dx=A*x+B*u;
H=(C1*A*L2-K*C*A*L2)
F=(C1*A*L2*K+C1*A*L1-K*C*A*L1-K*C*A*L2*K)
E=(C1*B-K*C*B)
dq=H*q+F*y+E*u
pause(1)
dX=[dx;dq];