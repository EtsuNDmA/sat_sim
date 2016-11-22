classdef StarSensor < handle
    %RateSensor модель звездного датчика
    %   Detailed explanation goes here
    
properties(GetAccess = 'public', SetAccess = 'public')
    dcm;
    %delay;
    failure = 0;
    h = 1;
end

properties(GetAccess = 'private', SetAccess = 'private')
    meas;
end

methods
    function obj = StarSensor(dcm)
        if ~isequal(size(dcm),[3 3])
            error 'Wrong size of dcm'
        end
        %if delay>obj.h
        %    error 'Delay must be less or equal to h'
        %end

        obj.dcm = dcm;
        %obj.delay = delay;
        obj.meas = [1 1; 0 0; 0 0; 0 0];
    end

    function meas_output = measure(obj,Qjb)
        Qjp = quatmultiply(Qjb',dcm2quat(obj.dcm))';
        obj.meas = [obj.meas(:,2), Qjp];
        dalayed_meas = obj.meas(:,1); % 1 step delay

        switch obj.failure
            case 0
                meas_output = dalayed_meas;
            otherwise
                disp('Invalid failure flag')
        end
    end
end

end

