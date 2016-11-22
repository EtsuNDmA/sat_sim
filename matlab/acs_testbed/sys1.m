clear all;
close all;
clc;
p.J=diag([8200 8200 3200]);
p.invJ=p.J^-1;
p.M=400;
p.Kl=0.026;
p.Kw=0.32;
p.a=-100;
p.b=-1;
X0=[0.01 0 0 0.1411 0.0001 0.0001 0.0001 0.0001 0.0001 0.0001]';

W=p.J^-1*skewsym(X0(5:7)')*p.J;
g=quatrotate([X0(1)+1,X0(2:4)'],[0 -9.8 0]);
G=-p.M*skewsym(g);
D=skewsym(X0(2:4))+eye(3);

A=[0 -0.5*X0(5:7)' zeros(1,6);
	0.5*X0(5:7) zeros(3) D zeros(3);
	zeros(3,1) -p.Kl*p.J*(X0(1)+1) -p.Kw*p.J-W G;
	zeros(3,10)];
B=[zeros(7,3);
	eye(3)];

% p.K = mtrp(p.a,p.b,A,B);
	p.K=[zeros(3,7),eye(3)];

lambda = eig(A-B*p.K)
figure;plot(real(lambda),imag(lambda),'r*');grid on;

%%
tic
[T,X] = ode45(@(t,X)func1(t,X,p),[0.1:0.1:100],X0);
toc
figure;
plot(T,X(:,2:4));
grid on;
figure;
plot(T,X(:,5:7));
grid on;
figure;
plot(T,X(:,8:10));
grid on;