function [D,Ad] = kab2(A,B,p)
[nax,nay]=size(A)
[nbx,nby]=size(B)
%sorting etallon roots
pr=p(imag(p)==0)
pi1=p(imag(p)>0)
pi2=conj(pi1)
lpi=length(pi1)
lpr=length(pr)
if lpi==0
    psort=pr
else
    for i=1:1:lpi
    pi(2*i-1,1)=pi1(i)
    pi(2*i,1)=pi2(i)
    end
    psort=[pi;pr]
end
%sorting eigenvalues A
a=eig(A)
ar=a(imag(a)==0)
ai1=a(imag(a)>0)
ai2=conj(ai1)
lai=length(ai1)
lar=length(ar)
if lai==0
    asort=ar
else
    for i=1:1:lai
    ai(2*i-1,1)=ai1(i)
    ai(2*i,1)=ai2(i)
    end
    asort=[ai;ar]
end
% search feedback matrix
   % calculating number of steps
mod2=mod(nax,2)
if mod2==1
    k=(nax-1)/2+1
else k=nax/2
end
if mod2==0
    k1=k
else k1=k-1
end
   % move conjugate pairs eig of A
Da=0
At=A'
Ak=At
Bk=B'
for i=1:1:lai
    Al=asort(2*i-1)*eye(nax)
    As=Ak-Al
    t=null(As)
    T1=[real(t),imag(t)]
    B1=Bk*T1
    iB1=pinv(B1)
    P1=[real(asort(2*i-1)),imag(asort(2*i-1));imag(asort(2*i)),real(asort(2*i))]
    F1=[real(psort(2*i-1)),imag(psort(2*i-1));imag(psort(2*i)),real(psort(2*i))]
    dA1=P1-F1
    DA=T1*dA1*iB1*Bk
    Ak=Ak-DA
    Da=DA+Da
end
   % move real pairs eig of A
for i=1:1:(k1-lai)   
    Al1=asort(2*(i+lai)-1)*eye(nax)
    Al2=asort(2*(i+lai))*eye(nax)
    As1=Ak-Al1
    As2=Ak-Al2
    t1=null(As1)
    t2=null(As2)
    T1=[t1,t2]
    B1=Bk*T1
    iB1=pinv(B1)
    P1=[real(asort(2*(i+lai)-1)),imag(asort(2*(i+lai)-1));imag(asort(2*(i+lai))),real(asort(2*(i+lai)))]
    F1=[real(psort(2*(i+lai)-1)),imag(psort(2*(i+lai)-1));imag(psort(2*(i+lai))),real(psort(2*(i+lai)))]
    dA1=P1-F1
    DA=T1*dA1*iB1*Bk
    Ak=Ak-DA
    Da=DA+Da
end  
   % move nonpair eig of A
if mod2==0
    Dt=Da*pinv(Bk)
    D=Dt'
    Adt=At-Da
    Ad=Adt'
else
    Al=asort(nax)*eye(nax)
    As=Ak-Al
    t=null(As)
    T1=t
    B1=Bk*T1
    iB1=pinv(B1)
    P1=asort(nax)
    F1=psort(nax)
    dA1=P1-F1
    DA=T1*dA1*iB1*Bk
    Ak=Ak-DA
    Da=DA+Da
    Dt=Da*pinv(Bk)
    D=Dt'
    Adt=At-Da
    Ad=Adt'
end

