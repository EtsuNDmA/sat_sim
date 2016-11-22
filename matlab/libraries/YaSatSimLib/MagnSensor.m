classdef MagnSensor < handle
    %RateSensor модель магнитометра
    %   Detailed explanation goes here
    
    properties(GetAccess = 'public', SetAccess = 'public')
        sig_v;
        sf;
        dcm;
        delay;
        failure = 0;
        h = 0.1;
        bias;
    end
    properties(GetAccess = 'private', SetAccess = 'private')
        meas;
    end
    
    methods
        function obj = MagnSensor(dcm,sf,bias,sig_v,delay)
            if ~isequal(size(dcm),[3 3])
                error 'Wrong size of dcm'
            end
            if ~isequal(size(sf),[3 3])
                error 'Wrong size of sf'
            end
            if ~isnumeric(sig_v)
                error 'Wrong type sig_v'
            end
            if delay>obj.h
                error 'Delay must be less or equal to 0.1'
            end
            
            obj.dcm = dcm;
            obj.sf = sf;
            obj.sig_v = sig_v;
            obj.delay = delay;
            obj.bias = bias;
            obj.meas = zeros(3,2);
        end
        
        function magn_meas_output = measure(obj,mag_field)
            m = obj.dcm*((eye(3)+obj.sf)*mag_field+obj.bias+obj.sig_v^2*randn(3,1));
            obj.meas = [obj.meas(:,2), m];
            dalayed_meas = obj.meas(:,2)*(1-obj.delay/obj.h)+obj.meas(:,1)*obj.delay/obj.h;
            
            switch obj.failure
                case 0
                    magn_meas_output = dalayed_meas;
                otherwise
                    disp('Invalid failure flag')
            end
        end
    end
    
end

