function dX = func1(t,X,p)

W=p.invJ*skewsym(X(5:7)')*p.J;
g=quatrotate([X(1)+1,X(2:4)'],[0 -9.8 0]);
G=-p.M*skewsym(g);
D=skewsym(X(2:4))+eye(3);

A=[0 -0.5*X(5:7)' zeros(1,6);
	0.5*X(5:7) zeros(3) D zeros(3);
	zeros(3,1) -p.Kl*p.J*(X(1)+1) -p.Kw*p.J-W G;
	zeros(3,10)];
B=[zeros(7,3);
	eye(3)];

U=-p.K*X;

dX=A*X+B*U;
