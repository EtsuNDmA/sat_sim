% Анимация разворота в ОСК
for i=1:length(svQjb)
    xx(i,:)=quatrotate(svQjb(i,:),[1 0 0]);
    yy(i,:)=quatrotate(svQjb(i,:),[0 1 0]);
    zz(i,:)=quatrotate(svQjb(i,:),[0 0 1]);
end;

figure;
subplot(1,2,1)
    h11=plot3([0 0 0;xx(1,1) yy(1,1) zz(1,1)],[0 0 0;xx(1,2) yy(1,2) zz(1,2)],[0 0 0;xx(1,3) yy(1,3) zz(1,3)]);
    title('Ориентация ССК относительно ИСК')
    grid on
    hold on
    h12=plot3([0;0],[0;1/sqrt(2)],[0;1/sqrt(2)],'y');
    
    legend('x','y','z')
    axis([-1.5 1.5 -1.5 1.5 -1.5 1.5])
    
subplot(1,2,2)
    h13=plot(svQjb(1:end,:));
    title('Кватернион ориентации ССК относительно ИСК')
    grid on
    hold on
    h14=plot(svQjb(1:end,:),'o','MarkerSize',6);
    h15=plot([1 1],[-1 1]','--','Color',[0.5 0.5 0.5]);

for i=1:length(svQjb)
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