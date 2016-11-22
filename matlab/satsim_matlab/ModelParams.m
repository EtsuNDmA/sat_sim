%%%%%%%%%%%%%%%%%%%%
% ��������� ������ % 
%%%%%%%%%%%%%%%%%%%%
d2r=pi/180; %Deg2Rad
%% ����� ������������� � ���
MaxTimeModel = 31536000%100*60*10*100;
%% ��� ������������� � ���
DeltaStepModel = 60*1000;%0.020;
MaxStepModel = floor(MaxTimeModel/DeltaStepModel);

%% ������� �� TEME � ECI
%order       - number of terms for nutation   4, 50, 106, ...
teme2eci_order = 4;
%eqeterms    - number of terms for eqe        0, 2
teme2eci_eqeterms = 2;
%opt         - option for processing          
%               a - complete nutation
%               b - truncated nutation
%               c - truncated transf matrix
teme2eci_opt = 'a'; 

%% ������������� SGP4
twoline2rv_whichconst	= 84;   % ���������� ��������� WGS-84
twoline2rv_typerun      = 'c';	% [c]atalog, [m]anual, [v]erification mode
twoline2rv_typeinput	= 'd';	% [m]fe, [e]poch, [d]ayofyear

%% ��������� ��������
%������ ������� � ��������� ���� (�� �^2)
Jxx_b = 365;
Jyy_b = 335;
Jzz_b = 473;
Jxy_b = 0;
Jxz_b = 0;
Jyx_b = 0;
Jyz_b = 0;
Jzx_b = 0;
Jzy_b = 0;

J_b = [Jxx_b Jxy_b Jxz_b;
       Jyx_b Jyy_b Jyz_b;
       Jzx_b Jzy_b Jzz_b];
invJ_b=J_b^-1;