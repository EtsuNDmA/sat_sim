function [R,B,nB] = mfcalc( x,y,z,a,d,N,I,type )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
nmax=length(x)*length(y)*length(z);
Ba=zeros(nmax,3);
Bb=zeros(nmax,3);
Bc=zeros(nmax,3);
B=zeros(nmax,3);
R=zeros(nmax,3);
nB=zeros(length(x),length(y),length(z));
if strcmp(type,'square')
	n=1;
	A1=[-a a -d/2;
		a a -d/2;
		a -a -d/2;
		-a -a -d/2];
	A2=[-a a d/2;
		a a d/2;
		a -a d/2;
		-a -a d/2];
	B1=[-d/2 -a a;
		-d/2 a a;
		-d/2 a -a;
		-d/2 -a -a];
	B2=[d/2 -a a;
		d/2 a a;
		d/2 a -a;
		d/2 -a -a];
	C1=[-a -d/2 a;
		a -d/2 a;
		a -d/2 -a;
		-a -d/2 -a];
	C2=[-a d/2 a;
		a d/2 a;
		a d/2 -a;
		-a d/2 -a];
	for k=1:length(z)
		for j=1:length(y)
			for i=1:length(x)
				X=x(i);Y=y(j);Z=z(k);
				% Катушки на оси Z
				Ba(n,:)=mfframe(A1,[X Y Z],I(1),N(1))+mfframe(A2,[X Y Z],I(1),N(1));
				% Катушки на оси X
				Bb(n,:)=mfframe(B1,[X Y Z],I(2),N(2))+mfframe(B2,[X Y Z],I(2),N(2));
				% Катушки на ост Y
				Bc(n,:)=mfframe(C1,[X Y Z],I(3),N(3))+mfframe(C2,[X Y Z],I(3),N(3));
				B(n,:)=Ba(n,:)+Bb(n,:)+Bc(n,:);
				R(n,1:3)=[X Y Z];
				nB(i,j,k)=norm(B(n,:));
				n=n+1;
			end
		end
	end
elseif strcmp(type,'circ')
	n=1;
	for k=1:length(z)
		for j=1:length(y)
			for i=1:length(x)
				X=x(i);Y=y(j);Z=z(k);
				% Катушки на оси Z
				[Br1,Bz1]=mfcirc(a,[X Y Z+d/2],I(1)*N(1));
				[Br2,Bz2]=mfcirc(a,[X Y Z-d/2],I(1)*N(1));
				if X==0 && Y==0
					Ba(n,:)=[0 0 Bz1+Bz2];
				else
					Ba(n,:)=[Br1*X/sqrt(X^2+Y^2), Br1*Y/sqrt(X^2+Y^2), Bz1]+...
						[Br2*X/sqrt(X^2+Y^2), Br2*Y/sqrt(X^2+Y^2), Bz2];
				end;
				% Катушки на оси X
				[Br1,Bz1]=mfcirc(a,[-Z Y X+d/2],I(2)*N(2));
				[Br2,Bz2]=mfcirc(a,[-Z Y X-d/2],I(2)*N(2));
				if Z==0 && Y==0
					Bb(n,:)=[Bz1+Bz2 0 0];
				else
					Bb(n,:)=[Bz1, Br1*Y/sqrt(Z^2+Y^2), Br1*Z/sqrt(Z^2+Y^2)]+...
						[Bz2, Br2*Y/sqrt(Z^2+Y^2), Br2*Z/sqrt(Z^2+Y^2)];
				end;
				% Катушки на оси Y
				[Br1,Bz1]=mfcirc(a,[X Z -Y+d/2],I(3)*N(3));
				[Br2,Bz2]=mfcirc(a,[X Z -Y-d/2],I(3)*N(3));
				if X==0 && Z==0
					Bc(n,:)=[0 Bz1+Bz2 0];
				else
					Bc(n,:)=[Br1*X/sqrt(X^2+Z^2), Bz1, Br1*Z/sqrt(X^2+Z^2)]+...
						[Br2*X/sqrt(X^2+Z^2), Bz2, Br2*Z/sqrt(X^2+Z^2)];
				end;
				B(n,:)=Ba(n,:)+Bb(n,:)+Bc(n,:);
				R(n,1:3)=[X Y Z];
				nB(i,j,k)=norm(B(n,:));
				n=n+1;
			end
		end
	end
else	

end

