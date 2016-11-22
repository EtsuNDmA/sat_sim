clear all;
close all;
clc;
delta=deg2rad(45);
gamma=deg2rad(45);
Hmax=15;
sd=sin(delta);
cd=cos(delta);
sg=sin(gamma);
cg=cos(gamma);
% Матрица конфигурации
L=[-sd*cg -sd*cg -sd*cg -sd*cg;
	sd*sg -sd*sg -sd*sg sd*sg;
	-cd -cd cd cd];
% Максимальные значения кинмомента по осям
HXmax=4*Hmax*sd*cg;
HYmax=4*Hmax*sd*sg;
HZmax=4*Hmax*cd;
AM=Hmax*[1 1 1 1;
1 1 1 -1;
1 1 -1 1;
1 1 -1 -1;
1 -1 1 1;
1 -1 -1 1;
1 -1 -1 -1;
-1 1 1 1;
-1 1 1 -1;
-1 1 -1 -1;
-1 -1 1 1;
-1 -1 1 -1;
-1 -1 -1 1;
-1 -1 -1 -1]';
AAA=L*AM;

figure;
DT=delaunayTriangulation(AAA(1,:)',AAA(2,:)',AAA(3,:)');
tetramesh(DT,'CData',[0.5 0.5 0.5 0.5]);
hold on;
plot3(AAA(1,:),AAA(2,:),AAA(3,:),'+')
axis equal;
title('Область изменения кинетического момента момента');
% Моделирование отказа одного маховика
L1=[zeros(3,1) L(:,2:4)];
L2=[L(:,1) zeros(3,1) L(:,3:4)];
L3=[L(:,1:2) zeros(3,1) L(:,4)];
L4=[L(:,1:3) zeros(3,1)];

AAA1=L1*AM;
figure;
DT=delaunayTriangulation(AAA1(1,:)',AAA1(2,:)',AAA1(3,:)');
tetramesh(DT,'CData',[0.5 0.5 0.5 0.5]);
hold on;
plot3(AAA1(1,:),AAA1(2,:),AAA1(3,:),'+')
axis equal;
title('Область изменения кинетического момента момента при отказе 1-го маховика');

AAA2=L2*AM;
figure;
DT=delaunayTriangulation(AAA2(1,:)',AAA2(2,:)',AAA2(3,:)');
tetramesh(DT,'CData',[0.5 0.5 0.5 0.5]);
hold on;
plot3(AAA2(1,:),AAA2(2,:),AAA2(3,:),'+')
axis equal;
title('Область изменения кинетического момента момента при отказе 2-го маховика');