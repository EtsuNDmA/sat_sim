function [rsun,rsunecef,sunlight,rtasc,decl]=sunPosition(params,satrec,times,rj2000)
% ������� ����������� �� ������� � ECEF � ����� ����/����

% ������ ��������� ������
	[rsun,rtasc,decl] = sun ( satrec.jdsatepoch );
% ��������������� ��������� ������ �� ECEF
	[rsunecef,~,~] = eci2ecef  ( rsun',[0;0;0],[0;0;0],times.ttt,times.jdut1,...
	params.lod,params.xp,params.yp,params.eqeterms,params.ddpsi,params.ddeps);
% � ���� ��� �� ����� �������? (�������������� ����)
	sunlight = sight( rsun*params.au2km,rj2000,'e');