clear all
close all
clc

a=1;

k=1.116;

d=k*a;
N=[100 100 100];
I=[3 0 0];
tic;xx=0:0.01:0.39;[R,B,nB]=mfcalc( xx,xx,xx,a,d,N,I,'circ');
clc
t=toc
%%

BX(:,:)=100-abs(nB(1,:,:)/nB(1,1,1))*100;
subplot(2,2,1);
contour(xx/a,xx/a,BX,[-5 -4 -3 -2 -1 1 2 3 4 5],'ShowText','on','LineWidth',2)
xlabel Z
ylabel Y
grid on;
set(gca,'GridLineStyle','-');

BY(:,:)=100-abs(nB(:,1,:)/nB(1,1,1))*100;
subplot(2,2,2);
contour(xx/a,xx/a,BY,[-5 -4 -3 -2 -1 1 2 3 4 5],'ShowText','on','LineWidth',2)
xlabel Z
ylabel X
grid on;
set(gca,'GridLineStyle','-');

BZ(:,:)=100-abs(nB(:,:,1)/nB(1,1,1))*100;
subplot(2,2,3);
contour(xx/a,xx/a,BZ,[-5 -4 -3 -2 -1 1 2 3 4 5],'ShowText','on','LineWidth',2)
xlabel X
ylabel Y
grid on;
set(gca,'GridLineStyle','-');

subplot(2,2,4);
contour(xx/a,xx/a,BX,[-1 1],'ShowText','on','LineWidth',2)
hold on;
contour(xx/a,xx/a,BY,[-1 1],'ShowText','on','LineWidth',2)
contour(xx/a,xx/a,BZ,[-1 1],'ShowText','on','LineWidth',2)
text(-0.25,0.25,sprintf('d=%0.1f',d))
grid on;
set(gca,'GridLineStyle','-');
axis('equal')
