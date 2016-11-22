classdef SunSensor < handle
    %RateSensor модель солнечного
    %   Detailed explanation goes here
    
properties(GetAccess = 'public', SetAccess = 'public')
    sig_v;
    dcm;
    delay;
    failure = 0;
    h = 0.1;
    fov;
end

properties(GetAccess = 'private', SetAccess = 'private')
    meas;
end

methods
    function obj = SunSensor(dcm,fov,sig_v,delay)
        if ~isequal(size(dcm),[3 3])
            error 'Wrong size of dcm'
        end
        if ~isnumeric(sig_v)
            error 'Wrong type sig_v'
        end
        if delay>obj.h
            error 'Delay must be less or equal to 0.1'
        end

        obj.dcm = dcm;
        obj.sig_v = sig_v;
        obj.delay = delay;
        obj.fov = fov;
        obj.meas = zeros(3,2);
    end

    function meas_output = measure(obj,r_sun_b)
        r_sun_p = obj.dcm*r_sun_b;
        if obj.in_fov(r_sun_p)
            disp((eye(3)-r_sun_p*r_sun_p'))
            r_sun_meas = r_sun_p+obj.sig_v^2*(eye(3)-r_sun_p*r_sun_p')*randn(3,1);
        else
            r_sun_meas = [0 0 0]';
        end;   
        obj.meas = [obj.meas(:,2), r_sun_meas];
        dalayed_meas = obj.meas(:,2)*(1-obj.delay/obj.h)+obj.meas(:,1)*obj.delay/obj.h;

        switch obj.failure
            case 0
                meas_output = dalayed_meas;
            otherwise
                disp('Invalid failure flag')
        end
    end
end

methods (Access = 'private')
    function result = in_fov(obj,r)
        result = r(3)>= cos(obj.fov/2);
    end    
end
    
end

