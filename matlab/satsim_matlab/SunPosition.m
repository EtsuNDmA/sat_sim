% Найдем положение Солнца
	[rsun,rtasc,decl] = sun ( satrec.jdsatepoch );
% Перепроектируем положение Солнца на ECEF
	[rsunecef,~,~] = eci2ecef  ( rsun',[0;0;0],[0;0;0],ttt,jdut1,lod,xp,yp,eqeterms,ddpsi,ddeps );
% В тени или на свету аппарат? (цилиндрическая тень)
	LightFlag = sight( rsun*au2km,rj2000,'e');