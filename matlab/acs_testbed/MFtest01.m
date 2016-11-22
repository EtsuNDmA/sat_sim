clear
close all
clc
% ������ �������
a=1.5;
% ���������� ����� ���������
k=1.1;
d=k*a;
% ���������� ������
N=[100 100 100];
% ��� � ����� �������
I=[3 0 0];
%% ������
tic;
    xx=[0:0.002:0.4];
	[R,B,nB]=mfcalc( xx,xx,xx,a,d,N,I,'circ');
t=toc;
fprintf('������ ���������� �� %d ���. \n',t)
fprintf('����������� ����:\n \tBnom=%.2f (���)\n',nB(1,1,1)*1e9)
%% �������
figure
BX(:,:)=100-abs(nB(1,:,:)/nB(1,1,1))*100;
subplot(2,2,1);
contour(xx/a,xx/a,BX,[-5 -4 -3 -2 -1 1 2 3 4 5],'ShowText','on','LineWidth',2)
xlabel Z/a
ylabel Y/a
grid on;
set(gca,'GridLineStyle','-','XLim',[0 .4],'YLim',[0 .4],'DataAspectRatio',[1 1 1]);



BY(:,:)=100-abs(nB(:,1,:)/nB(1,1,1))*100;
subplot(2,2,2);
contour(xx/a,xx/a,BY,[-5 -4 -3 -2 -1 1 2 3 4 5],'ShowText','on','LineWidth',2)
xlabel Z/a
ylabel X/a
grid on;
set(gca,'GridLineStyle','-','XLim',[0 .4],'YLim',[0 .4]);



BZ(:,:)=100-abs(nB(:,:,1)/nB(1,1,1))*100;
subplot(2,2,3);
contour(xx/a,xx/a,BZ,[-5 -4 -3 -2 -1 1 2 3 4 5],'ShowText','on','LineWidth',2)
xlabel X/a
ylabel Y/a
grid on;
set(gca,'GridLineStyle','-','XLim',[0 .4],'YLim',[0 .4]);



subplot(2,2,4);
contour(xx/a,xx/a,abs(BX),[-1  1],'ShowText','on','LineWidth',2)
hold on;
contour(xx/a,xx/a,BZ,[-1  1],'ShowText','on','LineWidth',2)
theta=0:0.1:pi/2;
rho1=ones(1,length(theta))*0.2;
rho2=ones(1,length(theta))*0.3;
rho3=ones(1,length(theta))*0.4;
polar(theta,rho1,'r')
polar(theta,rho2,'r')
polar(theta,rho3,'r')

grid on;
set(gca,'GridLineStyle','-','XLim',[0 .4],'YLim',[0 .4]);
axis equal
