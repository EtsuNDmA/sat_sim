% ������ ��������� ������
	[rsun,rtasc,decl] = sun ( satrec.jdsatepoch );
% ��������������� ��������� ������ �� ECEF
	[rsunecef,~,~] = eci2ecef  ( rsun',[0;0;0],[0;0;0],ttt,jdut1,lod,xp,yp,eqeterms,ddpsi,ddeps );
% � ���� ��� �� ����� �������? (�������������� ����)
	LightFlag = sight( rsun*au2km,rj2000,'e');