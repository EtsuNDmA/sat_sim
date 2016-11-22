%% Загрузим данные
% Проверим, существует ли файл с орбитальными данными и данными по
% магнитному полю

fid1=fopen('orbitData.mat', 'r+');
fid2=fopen('magnData.mat', 'r+');
if fid1>0 && fid2>0
    fclose(fid1);
    fclose(fid2);
    load('orbitData.mat');
    load('magnData.mat');
    % Если параметры изменились, то считаем заново
    if ~((svDeltaStepCM      == DeltaStepCM) && ...
        (svMaxStepCM         == MaxStepCM) && ...
        (svteme2eci_order    == teme2eci_order) && ...
        (sveqeterms          == eqeterms) && ...
        (svteme2eci_opt      == teme2eci_opt) && ...
        (isequal(svTLEstr1,TLEstr1)) && ...
        (isequal(svTLEstr2,TLEstr2)) && ...
        (svtwoline2rv_whichconst == twoline2rv_whichconst) && ...
        (svtwoline2rv_typerun    == twoline2rv_typerun) && ...
        (svtwoline2rv_typeinput	 == twoline2rv_typeinput) && ...
        (svtimezone          == timezone) && ...
        (svdut1              == dut1) && ...
        (svdat               == dat) && ...
        (svMearth            == Mearth) && ...
        (svMuEarth           == MuEarth) && ...
        (svlod               == lod) && ...
        (svxp                == xp) && ...
        (svyp                == yp) && ...
        (svddpsi             == ddpsi) && ...
        (svddeps             == ddeps))
        
        orbitMode=0;
    else
        orbitMode=1;
    end;
else
    orbitMode=0;
end;
%% Расчет магнитного поля
if orbitMode==0
    svMagn          =zeros(MaxStepCM,3);
    svMagnDipolECEF =zeros(MaxStepCM,3);
    for StepCM=1:MaxStepCM
        %% Модель диполя
        normRecef=norm(svrecef(StepCM,:)); % км
        MagnFieldECEFdipol=(3*(MagnMomentum*svrecef(StepCM,:)')*svrecef(StepCM,:)-normRecef^2*MagnMomentum)/normRecef^5;% нТл
        [MagnFieldDipol_j,~,~] = ecef2eci(MagnFieldECEFdipol',[0 0 0]',[0 0 0]',...
            ttt,jdut1,lod,xp,yp,eqeterms,ddpsi,ddeps);
        %% Модель IGRF 11
        %Найдем магнитное поле в NED
        % !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        % Тут есть заплатка "decyear(year,mon,day,hr,minute,sec)-2" - минус 2
        % нужен,т.к. igrf11 не работает после 2014 года!!!!!!!!!!!!!!!!!!!!!!!
        % !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        [MagnFieldNED, MagnHoorizIntens, MagnDecl, MagnIncl, MagnTotalIntens]...
            = igrf11magm(hellp*1000, latgd/d2r, lon/d2r, decyear(year,mon,day,hr,minute,sec)-2);
        %Пересчитаем в ECEF
        [MagnFieldECEF(1),MagnFieldECEF(2),MagnFieldECEF(3)] = ned2ecef( ...
            MagnFieldNED(:,1)',MagnFieldNED(:,2)',MagnFieldNED(:,3)',...
            latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
        %Выше мы посчитали координаты конца вектора магнитной индукции в ECEF,
        %нужно еще вычесть координаты начала координат NED в ECEF

        [x0ecef,y0ecef,z0ecef] = ned2ecef( ...
            0,0,0,...
            latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
        MagnFieldECEF=MagnFieldECEF-[x0ecef y0ecef z0ecef];
        
        % Сохраним результаты
        svMagn(StepCM,:)            =MagnFieldECEF;
        svMagnDipolECEF(StepCM,:)   =MagnFieldECEFdipol;
        svMagnDipolb(StepCM,:)      =MagnFieldDipol_b;
    end;
    
end;
StepCM=1;


%% --------Test02----------
% [xx,xy,xz] = ned2ecef( ...
%     1,0,0,...
%     latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
% [yx,yy,yz] = ned2ecef( ...
%     0,1,0,...
%     latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
% [zx,zy,zz] = ned2ecef( ...
%     0,0,1,...
%     latgd, lon, hellp*1000, wgs84Ellipsoid, 'radians');
% xx=xx-x0ecef;
% xy=xy-y0ecef;
% xz=xz-z0ecef;
% yx=yx-x0ecef;
% yy=yy-y0ecef;
% yz=yz-z0ecef;
% zx=zx-x0ecef;
% zy=zy-y0ecef;
% zz=zz-z0ecef;

%fprintf('%f   %f   %f \n',xx,yx,zx)

%% --------Test01----------
% lat=-89.9:5:89.9;
% long=0:20:179.9;
% h=600;
% k=1;
% d2r=pi/180;
% for i=1:length(lat)
%     for j=1:length(h)
%         for s=1:length(long)
%             [MagnFieldNED, MagnHoorizIntens, MagnDecl, MagnIncl, MagnTotalIntens]...
%                 = igrf11magm(h(j), lat(i), long(s), decyear(2014,12,31));
%             MagnField(k,:)=MagnFieldNED*MagnTotalIntens;
%             MTI(k)=MagnTotalIntens;
%             lat1(k)=d2r*lat(i);
%             long1(k)=d2r*long(s);
%             h1(k)=h(j)+6600;
%             k=k+1;
%         end;
%     end;
% end;
% hold on
% grid on
% 
% [MagnFieldECEF(:,1),MagnFieldECEF(:,2),MagnFieldECEF(:,3)] = ned2ecef( ...
%     MagnField(:,1)',MagnField(:,2)',MagnField(:,3)', lat1, long1, h1, wgs84Ellipsoid, 'radians');
% quiver3(h1.*cos(lat1).*cos(long1),h1.*cos(lat1).*sin(long1),h1.*sin(lat1),...
%    MagnFieldECEF(:,1)',MagnFieldECEF(:,2)',MagnFieldECEF(:,3)');
% plot3(h1.*cos(lat1).*cos(long1),h1.*cos(lat1).*sin(long1),h1.*sin(lat1),'r+');

%plot(h1.*cos(lat1).*cos(long1),h1.*sin(lat1),'*r');
%quiver(h1.*cos(lat1).*cos(long1),h1.*sin(lat1),...
%    MagnField(:,1)',MagnField(:,3)')