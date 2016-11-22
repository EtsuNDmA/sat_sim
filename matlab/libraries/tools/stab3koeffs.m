% Расчет оптимальных коэффициентов стабилизации.
clear all;
close all;
l1=zeros(100,100);
l2=zeros(100,100);
l3=zeros(100,100);
l4=zeros(100,100);
l5=zeros(100,100);
l6=zeros(100,100);
l5=zeros(100,100);
l6=zeros(100,100);
%Главные моменты инерции

% A=2600;
% B=2448;
% C=402;

A=1000;B=900;C=800;
for i=1:100;
    for j=1:100;
        k1(j)=j*0.00001;
        k2(i)=0.1+i*0.01;
		%Собственные значения
        l1(i,j)=(-k2(i)-sqrt(k2(i)^2-4*A*k1(j)))/(2*A);
        l2(i,j)=(-k2(i)-sqrt(k2(i)^2-4*B*k1(j)))/(2*B);
        l3(i,j)=(-k2(i)-sqrt(k2(i)^2-4*C*k1(j)))/(2*C);
        l4(i,j)=(-k2(i)+sqrt(k2(i)^2-4*A*k1(j)))/(2*A);
        l5(i,j)=(-k2(i)+sqrt(k2(i)^2-4*B*k1(j)))/(2*B);
        l6(i,j)=(-k2(i)+sqrt(k2(i)^2-4*C*k1(j)))/(2*C);
        l=[l1(i,j) l2(i,j) l3(i,j) l4(i,j) l5(i,j) l6(i,j)];
		%Ищем самый неустойчивый корень(наибольший)
        L1(i,j)=max(real([l1(i,j) l4(i,j)]));
		L2(i,j)=max(real([l2(i,j) l5(i,j)]));
		L3(i,j)=max(real([l3(i,j) l6(i,j) l1(i,j) l2(i,j) l4(i,j) l5(i,j)]));
    end;
end;
K1=[k1(1) k1(end)];
fmax=0.1/180*pi;
nnmax=0.5*sin(fmax);
wmax=0.01/180*pi;
Tmax=0.1;
% K2=(-nnmax*K1+Tmax)/wmax;
%Для недиагонального ТИ
maxJ=1000;
K2=(-nnmax*K1+Tmax/maxJ)/wmax;

% figure;
% plot(K1,K2,'LineWidth',2);
% hold on;
% contour(k1,k2,L1,10);
% surf(k1,k2,L1);
% xlabel k11;
% ylabel k21;
% grid on;

% figure;
% plot(K1,K2,'LineWidth',2);
% hold on;
% contour(k1,k2,L2,10);
% surf(k1,k2,L2);
% xlabel k12;
% ylabel k22;
% grid on;

figure;
plot(K1,K2,'LineWidth',2);
hold on;
contour(k1,k2,L3,50);
% surf(k1,k2,L3);
xlabel k13;
ylabel k23;
grid on;
% hold on;
% plot(real(l1),imag(l1),'+','Color',[0.5 0.5 0.5]);
% plot(real(l2),imag(l2),'+','Color',[0.5 0.5 0.5]);
% plot(real(l3),imag(l3),'+','Color',[0.5 0.5 0.5]);
% plot(real(l4),imag(l4),'+','Color',[0.5 0.5 0.5]);
% plot(real(l5),imag(l5),'+','Color',[0.5 0.5 0.5]);
% plot(real(l6),imag(l6),'+','Color',[0.5 0.5 0.5]);
% 
% h1=plot(real(l1(1,1)),imag(l1(1,1)),'r+');
% h2=plot(real(l2(1,1)),imag(l2(1,1)),'g+');
% h3=plot(real(l3(1,1)),imag(l3(1,1)),'b+');
% h4=plot(real(l4(1,1)),imag(l4(1,1)),'r+');
% h5=plot(real(l5(1,1)),imag(l5(1,1)),'b+');
% h6=plot(real(l6(1,1)),imag(l6(1,1)),'g+');
% grid on
% for i=1:50;
%     for j=1:50;
%         set(h1,'XData',real(l1(i,j)),'YData',imag(l1(i,j)));
%         set(h2,'XData',real(l2(i,j)),'YData',imag(l2(i,j)));
%         set(h3,'XData',real(l3(i,j)),'YData',imag(l3(i,j)));
%         set(h4,'XData',real(l4(i,j)),'YData',imag(l4(i,j)));
%         set(h5,'XData',real(l5(i,j)),'YData',imag(l5(i,j)));
%         set(h6,'XData',real(l6(i,j)),'YData',imag(l6(i,j)));
%         pause(0.01);
%     end;
% end;