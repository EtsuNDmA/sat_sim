function [Qjo_est, Worb_est_j] = filter_orb(logorb, Qjb_est, StepModel, DeltaStepModel)
%orb_filter ���������� ������������ ������
% =========================================================================
% ======== ��� �� ����� ��������. �������� ���������� ������ ==============
% =========================================================================
% ���������� ����������� ����� iorb, jorb korb � �������� �� J2000
    currenttime = StepModel*DeltaStepModel/60;
    r = interp1(logorb.tsince, logorb.rj2000, currenttime);
    v = interp1(logorb.tsince, logorb.vj2000, currenttime);
    jorb=r/norm(r);
    korb=cross(v,r)/norm(cross(v,r));
    iorb=cross(jorb,korb);
% ������� ������������ ��������� �� J2000 � ����������� ��
    DCMjo=[iorb',jorb',korb'];
% ���������� �������� �� J2000 � ���
    Qjo_est=dcm2quat(DCMjo')';
    if Qjo_est(1)<0
        Qjo_est=-Qjo_est;
    end
    Worb_est_j = cross(r, v)/(r*r')';
    
end

