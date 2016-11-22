% Анимация разворота в ОСК
for i=1:100:StepModel
    x(i,:)=quatrotate(svNob(i,:),[1 0 0]);
    y(i,:)=quatrotate(svNob(i,:),[0 1 0]);
    z(i,:)=quatrotate(svNob(i,:),[0 0 1]);
    
    xx(i,:)=quatrotate(svQjb(i,:),[1 0 0]);
    yy(i,:)=quatrotate(svQjb(i,:),[0 1 0]);
    zz(i,:)=quatrotate(svQjb(i,:),[0 0 1]);
end;

figure;
subplot(2,2,1)
    h01=plot3([0 0 0;x(1,1) y(1,1) z(1,1)],[0 0 0;x(1,2) y(1,2) z(1,2)],[0 0 0;x(1,3) y(1,3) z(1,3)]);
    title('Ориентация ССК относительно ОСК')
    grid on
    hold on
    legend('x','y','z')
    axis([-1.5 1.5 -1.5 1.5 -1.5 1.5])
    
subplot(2,2,2)
    h02=plot(svNob(1:StepModel,:));
    title('Кватернион ориентации ССК относительно ОСК')
    grid on
    hold on
    h03=plot(svNob(1:StepModel,:),'o','MarkerSize',6);
    h04=plot([1 1],[-1 1]','--','Color',[0.5 0.5 0.5]);

subplot(2,2,3)
    h11=plot3([0 0 0;xx(1,1) yy(1,1) zz(1,1)],[0 0 0;xx(1,2) yy(1,2) zz(1,2)],[0 0 0;xx(1,3) yy(1,3) zz(1,3)]);
    title('Ориентация ССК относительно ИСК')
    grid on
    hold on
    h12=plot3([0;svrsuneci(1,1)],[0;svrsuneci(1,2)],[0;svrsuneci(1,3)],'y');
    
    legend('x','y','z')
    axis([-1.5 1.5 -1.5 1.5 -1.5 1.5])
    
subplot(2,2,4)
    h13=plot(svQjb(1:StepModel,:));
    title('Кватернион ориентации ССК относительно ИСК')
    grid on
    hold on
    h14=plot(svQjb(1:StepModel,:),'o','MarkerSize',6);
    h15=plot([1 1],[-1 1]','--','Color',[0.5 0.5 0.5]);
    pause
for i=1:100:StepModel
    set(h01(1),'XData',[0;x(i,1)],'YData',[0;x(i,2)],'ZData',[0;x(i,3)])
    set(h01(2),'XData',[0;y(i,1)],'YData',[0;y(i,2)],'ZData',[0;y(i,3)])
    set(h01(3),'XData',[0;z(i,1)],'YData',[0;z(i,2)],'ZData',[0;z(i,3)])
    
    set(h03(1),'XData',i,'YData',svNob(i,1))
    set(h03(2),'XData',i,'YData',svNob(i,2))
    set(h03(3),'XData',i,'YData',svNob(i,3))
    set(h03(4),'XData',i,'YData',svNob(i,4))
    
    set(h04,'XData',[i i],'YData',[-1 1]);
    
    set(h11(1),'XData',[0;xx(i,1)],'YData',[0;xx(i,2)],'ZData',[0;xx(i,3)])
    set(h11(2),'XData',[0;yy(i,1)],'YData',[0;yy(i,2)],'ZData',[0;yy(i,3)])
    set(h11(3),'XData',[0;zz(i,1)],'YData',[0;zz(i,2)],'ZData',[0;zz(i,3)])
    
    set(h14(1),'XData',i,'YData',svQjb(i,1))
    set(h14(2),'XData',i,'YData',svQjb(i,2))
    set(h14(3),'XData',i,'YData',svQjb(i,3))
    set(h14(4),'XData',i,'YData',svQjb(i,4))
    
    set(h15,'XData',[i i],'YData',[-1 1]);
    
    pause(.1)
end;