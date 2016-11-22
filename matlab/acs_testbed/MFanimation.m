clear all
close all
clc

a=1.5;
d=2.5;
N=[100 100 100];
I=[3 3 3];
tic;xx=-2:0.1:2;[R,B,nB]=mfcalc( xx,xx,xx,a,d,N,I,'square');t=toc;
n=1;
a=((n-1)*(length(xx))^2+1):(n*(length(xx))^2);
%%
BB(:,:)=nB(:,1,:);
figure('Renderer','zbuffer');
surf(xx,xx,BB)
axis tight manual
set(gca,'nextplot','replacechildren')
F = getframe(gca);
[im,map]=rgb2ind(F.cdata,256,'nodither');
for n = 2:10
	BB(:,:)=nB(:,n,:);
%     contour(xx,xx,BB,50);
	surf(xx,xx,BB);
	ylim([-2 2])
	
	hold on;
	text(-1.7,1.7,sprintf('Y=%0.1f',xx(n)),'FontSize',20)
	plot([-d d]/2,[-1.8 -1.8],'ro');
	plot(xx(n),-1.8,'o');
	line([-2 2],[-1.8 -1.8],'LineWidth',2);
	hold off;
    drawnow
    F = getframe(gca);
	im(:,:,1,n)=rgb2ind(F.cdata,map,'nodither');
end
imwrite(im,map,'mfanimation1.gif','DelayTime',0.2,'LoopCount',inf);