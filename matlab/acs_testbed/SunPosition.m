function [rsun,rsunecef,sunlight]=SunPosition(params,satrec,times,rj2000)
% Функция направление на Солнеце в ECEF а также свет/тень

% Найдем положение Солнца
	[rsun,~,~] = sun ( satrec.jdsatepoch );
% Перепроектируем положение Солнца на ECEF
	[rsunecef,~,~] = eci2ecef  ( rsun',[0;0;0],[0;0;0],times.ttt,times.jdut1,...
	params.lod,params.xp,params.yp,params.eqeterms,params.ddpsi,params.ddeps);
% В тени или на свету аппарат? (цилиндрическая тень)
	sunlight = sight( rsun*params.au2km,rj2000,'e');