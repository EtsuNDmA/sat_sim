%% Работаем с БЧЭ500(IMU500)
clear all
close all
%Создаем соединение с последовательным портом
s = serial('COM5');
set(s,'BaudRate',921600,...
		'DataBits',8,...
		'StopBits',1,...
		'FlowControl','none',...
		'ByteOrder','littleEndian')
%Открываем соединение
fopen(s);
%Частота дискретизации, Гц
Fd=200;
%Время опроса датчика,с
Time=30*60;
%CRC detector oject. Default CRC-CCIT
det = crc.detector;

i=1;
tic
%% Цикл опроса датчика
h=waitbar(0,'Wait...');
while i<=Time*Fd;
	%Считываем данные пока не встретим хидер 0xC0C0
	Header1=fread(s,1,'uint8');
	if Header1==192% Header 0xC0
		Header2=fread(s,1,'uint8');
		if Header2==192% 0x0C
			%Детектировали начало пакета, считываем данные
% 			msg(1)=Header1;
% 			msg(2)=Header2;
% 			for j=2:32
% 				msg(j)=fread(s,1,'uint8');
% 			end;
			%Счетчик приращения угла
			Gx(i)=fread(s,1,'uint32');
			Gy(i)=fread(s,1,'uint32');
			Gz(i)=fread(s,1,'uint32');
			%Линейное ускорение
			Ax(i)=fread(s,1,'int32');
			Ay(i)=fread(s,1,'int32');
			Az(i)=fread(s,1,'int32');
			%Температура
			ADD(i)=fread(s,1,'uint16');
			%Счетчик фреймов
			CNT(i)=fread(s,1,'uint16');
			%%\ CRC-16/CCITT
			CRC(i)=
			
% 			
% 			msg1=de2bi(uint16(Header1),16,2,'left-msb');
% 			msg2=de2bi(uint16(Header2),16,2,'left-msb');
% 			msg3=de2bi(uint32(Gx(i)),32,2,'left-msb');
% 			msg4=de2bi(uint32(Gy(i)),32,2,'left-msb');
% 			msg5=de2bi(uint32(Gz(i)),32,2,'left-msb');
% 			msg6=de2bi(uint32(Ax(i)),32,2,'left-msb'); 
% 			msg7=de2bi(uint32(Ay(i)),32,2,'left-msb');
% 			msg8=de2bi(uint32(Az(i)),32,2,'left-msb');
% 			msg9=de2bi(uint16(ADD(i)),16,2,'left-msb');
% 			msg10=de2bi(uint16(CNT(i)),16,2,'left-msb');
% 			msg11=de2bi(uint16(CRC(i)),16,2,'left-msb');
% 			
%  			msg(i,:)=[msg1 msg2 msg3 msg4 msg5 msg6 msg7 msg8 msg9 msg10 msg11]';
			if i>1
				Dt(i-1)=(CNT(i)-CNT(i-1))/Fd;
				if Dt(i-1)<0
					Dt(i-1)=Dt(i-1)+(2^16)/Fd;
				end;
			end;
			if Gx(i)>2^31
				Dx(i)=Gx(i)-2^32;
			else
				Dx(i)=Gx(i);
			end;
			if Gy(i)>2^31
				Dy(i)=Gy(i)-2^32;
			else
				Dy(i)=Gy(i);
			end;
			if Gz(i)>2^31
				Dz(i)=Gz(i)-2^32;
			else
				Dz(i)=Gz(i);
			end;
			
			%Проверяем CRC
% 			[outdata error(i)] = detect(det,msg(i,:)');  
			
			i=i+1;
			
		else
			Header1=0;
			Header2=0;
		end;
	else
		Header1=0;
		Header2=0;
	end;
	Header1=0;
	Header2=0;
	waitbar(i/(Time*Fd),h);
end;
toc

Wx=Dx(2:end)*1.15555553748E-6.*Dt;
Wy=Dy(2:end)*1.15555553748E-6.*Dt;
Wz=Dz(2:end)*1.15555553748E-6.*Dt;

Mx=sum(Wx)/Time;
My=sum(Wy)/Time;
Mz=sum(Wz)/Time;

W=rad2deg(7.2921158553e-5);
disp(W*sind(55.7522200));
disp(Mx);



figure
title 'Угловая скорость, град/с'
	hold on;
	plot(Wx,'b');
	plot(Wy,'r');
	plot(Wz,'g');
	grid on
	legend Wx Wy Wz

figure
title 'Линейное ускорение, м/с'
	hold on;
	plot(Ax*5e-5,'b');
	plot(Ay*5e-5,'r');
	plot(Az*5e-5,'g');
	grid on;
	legend Ax Ay Az
%Закрываем и удаляем почледовательное соединение
fclose(s);
delete(s);
clear s;
close(h);
%% Вариация Аллана
addpath 'D:\Projects\MATLAB work\ACS\allan'
DATA.freq=Wx;
DATA.rate=200;
tau=1/200:0.1:Time/10;
[avar]=allan(DATA, tau);

figure;
loglog(avar.sig2);
grid on;

save('IMU500data','Fd','Time','Gx','Gy','Gz','Ax','Ay','Az','ADD','CNT','CRC',...
	'Dt','Dx','Dy','Dz','Wx','Wy','Wz','Mx','My','Mz','DATA','avar')