function A=skewsym(a)
[n,m]=size(a);
if n>m
	a=a';
end;
A=zeros(3);
A(1,2)=-a(3);
A(1,3)=a(2);
A(2,1)=a(3);
A(2,3)=-a(1);
A(3,1)=-a(2);
A(3,2)=a(1);
% A=[0 -a(3) a(2);
% 	a(3) 0 -a(1);
% 	-a(2) a(1) 0];
end

