% ������ ���������� ���� � ������ �����������
% ��������� ������ 'circ'/'square'
	type='square';%'square'/'circ'
	%������/�������� ����� �������� i-� ���� �������, �
	a=1.5;
	%���������� ����� i-� ����� �������,�
	d=3;
	%����� ������ � ������ �� ������� i-� ����
	N=100;
	%��� �
	I=3;
% �����
	x=-3.5:0.1:3.5;
	y=x;
	z=x;
% ������
	[R,B,nB]=mfcalc(x,y,z,a,d,N,I,type);