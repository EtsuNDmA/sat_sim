function J = hsinertia(I,m,a,A)
%hustinertia ��������� ���������� ������� ������� ��� �������� ������ �
%	�������� �������� ������ (Huygens�Steiner theorem). �������� ���������
%   ������ �� ��������������
%   �����: I - ������ ������� � ������� ������
%		   m - ����� ����
%		   a - ������ �� �� � ����� �����, ���������� � ���������� ������
%          A - ������� ��������
%   ������: J - ����� ������ �������
% 
J=A'*I*A+m*(a'*a*eye(3)-a*a');
end

