function [ Br,Bz ] = mfcirc(a,M,I )
%mfcirc Вычисляет магнитное поле круглого витка с током, лежащего в
%плоскости XOY и с центром в начале координат
%   a - радиус окружности
%   M - интересующая точка
%   I - ток
mu0=1.25663706e-6;
r=abs(M(1)+1i*M(2));
z=M(3);
% alpha=angle(M(1)+1i*M(2));
k=sqrt(4*r*a/((r+a)^2+z^2));
[K, E]=ellipke(k^2);
if r==0
	Br=0;
else
	Br=mu0*I*z/(2*pi*r)/sqrt((a+r)^2+z^2)*(-K+(a^2+r^2+z^2)/((a-r)^2+z^2)*E);
end;
Bz=mu0*I/(2*pi)/sqrt((a+r)^2+z^2)*(K+(a^2-r^2-z^2)/((a-r)^2+z^2)*E);

end

