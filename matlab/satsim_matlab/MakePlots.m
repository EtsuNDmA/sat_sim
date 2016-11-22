% Default Figure properties
set(0, 'DefaultAxesBox'       , 'on'             ,...
'DefaultAxesFontName'  , 'Times New Roman',...
'DefaultAxesFontSize'  , 14               ,...
'DefaultAxesFontWeight', 'bold'           ,...
'DefaultaxesLineWidth' , 1.7                );
set(0,'DefaultPatchLineWidth' , 1.7)
set(0, 'DefaultTextFontName'  , 'Times New Roman',...
'DefaultTextFontSize'  , 14               ,...
'DefaultTextFontWeight', 'bold'           ,...
'DefaultLineLineWidth' , 1.7                );
set(0, 'defaultfigurecolor', [1 1 1]);

close all

[xsph,ysph,zsph] = sphere;
hold on
figure(1)
    hold on
    grid on
    xlabel('x')
    ylabel('y')
    zlabel('z')
	surf(xsph*6378.137,ysph*6378.137,zsph*6378.137)
    plot3(0,0,0,'c+')
	plot3(svrj2000(1,1)',svrj2000(1,2)',svrj2000(1,3)','c+','MarkerSize',10)
	plot3(svrj2000(1:100:StepModel,1)',svrj2000(1:100:StepModel,2)',svrj2000(1:100:StepModel,3)','m')
	
	plot3(svrsuneci(10,1)'*10000,svrsuneci(10,2)'*10000,svrsuneci(10,3)'*10000,'Marker','p','MarkerSize',15,'MarkerEdgeColor',[0 0 0],'MarkerFaceColor','y')
%     plot3(svrecef(1:StepCM,1)',svrecef(1:StepCM,2)',svrecef(1:StepCM,3)','r-')
    title('Орбита в ECI')
	axis('equal')
    
    %quiver3(svR(:,1)',svR(:,2)',svR(:,3)',...
    %  svMagn(:,1)',svMagn(:,2)',svMagn(:,3)','k');

% hold on
% plot3(svrecef(:,1)',svrecef(:,2)',svrecef(:,3)','y*')
% quiver3(svrecef(:,1)',svrecef(:,2)',svrecef(:,3)',...
% svMagn(:,1)',svMagn(:,2)',svMagn(:,3)','k');
% quiver3(svrecef(:,1)',svrecef(:,2)',svrecef(:,3)',...
% svMagnDipol(:,1)',svMagnDipol(:,2)',svMagnDipol(:,3)','m');


% quiver3(svR(:,1)',svR(:,2)',svR(:,3)',...
%   sviorb(:,1)',sviorb(:,2)',sviorb(:,3)','r');
% quiver3(svR(:,1)',svR(:,2)',svR(:,3)',...
%   svjorb(:,1)',svjorb(:,2)',svjorb(:,3)','g');
% quiver3(svR(:,1)',svR(:,2)',svR(:,3)',...
%   svkorb(:,1)',svkorb(:,2)',svkorb(:,3)','b');

% quiver3(svR(:,1)',svR(:,2)',svR(:,3)',...
%    svxx',svxy',svxz','r');
% quiver3(svR(:,1)',svR(:,2)',svR(:,3)',...
%    svyx',svyy',svyz','g');
% quiver3(svR(:,1)',svR(:,2)',svR(:,3)',...
%    svzx',svzy',svzz','b');
%quiver(svlon',svlatgd',svMagn(:,1)',svMagn(:,2)')

% svWb1=zeros(length(svWb)/2,3);
% svWorbb1=zeros(length(svWorbb)/2,3);
% tic;svWb1=svWb(1:2:StepModel,:);toc;
% tic;svWorbb1=svWorbb(1:2:StepModel,:);toc;

[pitchmes, rollmes, yawmes]=quat2angle(svNobmes);
[pitch, roll, yaw]=quat2angle(svNob);

% figure(2)
%     subplot(1,2,1)
%         hold on;
%         plot(svNobmes(1:StepACS,1).*svNobmes(1:StepACS,2),(svWmesb(1:StepACS,1)-svWorbb(2:2:StepModel+1,1))/d2r,'c');
%         plot(svNob(1:StepModel-1,1).*svNob(1:StepModel-1,2),(svWb(1:StepModel-1,1)-svWorbb(1:StepModel-1,1))/d2r,'b');
%         plot(svNob(1,1).*svNob(1,2),(svWb(1,1)-svWorbb(1,1))/d2r,'m*');
%         plot([-pi pi],[-K1acs/K2acs*(-pi) -K1acs/K2acs*pi]/d2r,'r--');
%         grid on;title('Псевдо-Фазовая траектория 1');xlabel('N[1]*N[4]');ylabel('wz,deg/sec');
%         legend('Mesured','Real');
% 
%     subplot(1,2,2)
%         hold on;
%         plot(yawmes(1:StepACS)/d2r,(svWmesb(1:StepACS,1)-svWorbb(2:2:StepModel+1,1))/d2r,'c');
%         plot(yaw(1:StepModel-1)/d2r,(svWb(1:StepModel-1,1)-svWorbb(1:StepModel-1,1))/d2r,'b');
%         plot(yawmes(1)/d2r,(svWmesb(1,1)-svWorbb(1,1))/d2r,'m*');
%         plot((-pi:pi/20:pi)/d2r,-K1acs/K2acs*0.5*sin(-pi:pi/20:pi)/d2r,'r--');
%         grid on;title('Фазовая траектория 1');xlabel('fi,deg');ylabel('wz,deg/sec');
%         legend('Mesured','Real')
figure(3)
    subplot(1,2,1)
        hold on;
        plot(svNobmes(1:StepACS,1).*svNobmes(1:StepACS,3),(svWmesb(1:StepACS,2)-svWorbb(2:2:StepModel+1,2))/d2r,'c');
        plot(svNob(1:StepModel-1,1).*svNob(1:StepModel-1,3),(svWb(1:StepModel-1,2)-svWorbb(1:StepModel-1,2))/d2r,'b');
        plot(svNob(1,1).*svNob(1,3),(svWb(1,2)-svWorbb(1,2))/d2r,'m*');
        plot([-pi pi],[-K1acs/K2acs*(-pi) -K1acs/K2acs*pi]/d2r,'r--');
        grid on;title('Псевдо-Фазовая траектория 2');xlabel('N[1]*N[4]');ylabel('wz,deg/sec');
        legend('Mesured','Real');

    subplot(1,2,2)
        hold on;
        plot(pitchmes(1:StepACS)/d2r,(svWmesb(1:StepACS,2)-svWorbb(2:2:StepModel+1,2))/d2r,'c');
        plot(pitch(1:StepModel-1)/d2r,(svWb(1:StepModel-1,2)-svWorbb(1:StepModel-1,2))/d2r,'b');
        plot(pitchmes(1)/d2r,(svWmesb(1,2)-svWorbb(1,2))/d2r,'m*');
        plot((-pi:pi/20:pi)/d2r,-K1acs/K2acs*0.5*sin(-pi:pi/20:pi)/d2r,'r--');
        grid on;title('Фазовая траектория 2');xlabel('fi,deg');ylabel('wz,deg/sec');
        legend('Mesured','Real')
figure(4)
    subplot(1,2,1)
        hold on;
        plot(svNobmes(1:StepACS,1).*svNobmes(1:StepACS,4),(svWmesb(1:StepACS,3)-svWorbb(2:2:StepModel+1,3))/d2r,'c');
        plot(svNob(1:StepModel-1,1).*svNob(1:StepModel-1,4),(svWb(1:StepModel-1,3)-svWorbb(1:StepModel-1,3))/d2r,'b');
        plot(svNob(1,1).*svNob(1,4),(svWb(1,3)-svWorbb(1,3))/d2r,'m*');
        plot([-pi pi],[-K1acs/K2acs*(-pi) -K1acs/K2acs*pi]/d2r,'r--');
        grid on;title('Псевдо-Фазовая траектория 3');xlabel('N[1]*N[4]');ylabel('wz,deg/sec');
        legend('Mesured','Real');

    subplot(1,2,2)
        hold on;
        plot(pitchmes(1:StepACS)/d2r,(svWmesb(1:StepACS,3)-svWorbb(2:2:StepModel+1,3))/d2r,'c');
        plot(pitch(1:StepModel-1)/d2r,(svWb(1:StepModel-1,3)-svWorbb(1:StepModel-1,3))/d2r,'b');
        plot(pitchmes(1)/d2r,(svWmesb(1,3)-svWorbb(1,3))/d2r,'m*');
        plot((-pi:pi/20:pi)/d2r,-K1acs/K2acs*0.5*sin(-pi:pi/20:pi)/d2r,'r--');
        grid on;title('Фазовая траектория 3');xlabel('fi,deg');ylabel('wz,deg/sec');
        legend('Mesured','Real')
figure(5);plot(svWb(1:StepModel,:)-svWorbb(1:StepModel,:));grid on;title('W_b-Worb_b');legend('Wrel1','Wrel2','Wrel3');

figure(6);plot(svNormWb(1:StepModel));grid on;title('W_b');
figure(7);plot(svNob(1:StepModel,:));grid on;title('Nob');legend('Nob1','Nob2','Nob3','Nob4');

figure(8);
    subplot(3,2,1);
        plot(svTrwb(1:StepModel,:));
        grid on;title('Tfwb');legend('1','2','3');
    subplot(3,2,2);
        plot(svTmb(1:StepModel,:));
        grid on;title('Tmb');legend('1','2','3');
    subplot(3,2,3);
        plot(svTgyrob(1:StepModel,:));
        grid on;title('Tgyrob');legend('1','2','3');
    subplot(3,2,4);
    	plot(svTgravb(1:StepModel,:));
        grid on;title('Tgravb');legend('1','2','3');
	subplot(3,2,5);
		plot(svTab(1:StepModel,:));
        grid on;title('Tab');legend('1','2','3');
% Кинмомент маховиков и разгрузка
% for i=1:StepModel
%     normH(i)=norm(svHrwp(i,:));
% end;
figure
    hold on;
    plot(1:2:2*length(svUunload(1:StepACS)),svUunload(1:StepACS),'k');
    h01=area(1:2:2*length(svUunload(1:StepACS)),svUunload(1:StepACS)*5);
    set(h01,'FaceColor',[0.75,0.5,0.75]);
    
    plot(1:2:2*length(svUdempf(1:StepACS)),svUdempf(1:StepACS),'k');
    h01=area(1:2:2*length(svUdempf(1:StepACS)),svUdempf(1:StepACS)*max(max(svHrwp)));
    set(h01,'FaceColor',[0.5,0.75,0.75]);
    
    plot(1:2:2*length(svHrwreqp(1:StepACS,:)),svHrwreqp(1:StepACS,:),'-.');
    plot(svHrwp(1:StepModel,:));
    grid on;
%     plot(normH,'m','LineWidth',2);
	legend('','Uunload','','Udempf','Hrwreqp1','Hrwreqp2','Hrwreqp3','Hrwreqp4','Hrwp1','Hrwp2','Hrwp3','Hrwp4')
    plot([1 StepModel],[Hlow Hlow],'k--',[1 StepModel],[-Hlow -Hlow],'k--')
    plot([1 StepModel],[Hhigh Hhigh],'k--',[1 StepModel],[-Hhigh -Hhigh],'k--')
    plot([1 StepModel],[Hrwmax Hrwmax],'r--',[1 StepModel],[-Hrwmax -Hrwmax],'r--')
    
%     plot(svTrwb*10000,':');plot([1:2:2*length(svTrwreqb)],svTrwreqb*10000,'--');
%     legend('RWRateReq1','rWRateReq2','RWRateReq3','rWRate1','RWRate2','rWRate3',...
%         'Trwb1*10000','Trwb2*10000','Trwb3*10000','Trwreqb1*10000','Trwreqb2*10000','Trwreqb3*10000')