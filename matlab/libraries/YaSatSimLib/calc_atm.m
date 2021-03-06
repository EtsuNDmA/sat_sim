function Rho = calc_atm(logorb, params)
%calc_atm  ������ ��������� � ������ ����� ������
    
    Rho = zeros(size(logorb.rj2000,1),1);

    if (logorb.epochyr < 57)
        year= logorb.epochyr + 2000;
    else
        year= logorb.epochyr + 1900;
    end;
    for i=1:size(logorb.rj2000,1)
        [mon, day, ~, ~, ~] = days2mdh(year, logorb.dayofyear(i));
    % jdut1 � ����������� �������
        jdut1_mn = jday(...
            year,...
            mon,...
            day,...
            0.0,...
            0.0,...
            0.0 ...
        );
    % �������� ����� � ����������� �������
        gst_mn = gstime(jdut1_mn);
        Rho(i) = atmgost(...
        	logorb.rj2000(i,:),...
            logorb.hellp(i),...
            logorb.dayofyear(i),...
            logorb.utc(i),...
            gst_mn,...
            logorb.rtasc(i),...
            logorb.decl(i),...
            params.F107,...
            params.F81,...
            params.Kp...
        ); 
    end
end

