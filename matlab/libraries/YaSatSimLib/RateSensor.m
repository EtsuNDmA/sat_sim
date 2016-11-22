classdef RateSensor < handle
    %RateSensor модель датчика угловой скорости
    %   Detailed explanation goes here
    
    properties(GetAccess = 'public', SetAccess = 'public')
        sig_u;
        sig_v;
        sf;
        dcm;
        delay;
        failure = 0;
        h = 0.1;
    end
    properties(GetAccess = 'private', SetAccess = 'private')
        bias;
        meas;
    end
    
    methods
        function obj = RateSensor(dcm,sf,sig_u,sig_v,delay)
            if ~isequal(size(dcm),[3 3])
                error 'Wrong size of dcm'
            end
            if ~isequal(size(sf),[3 3])
                error 'Wrong size of sf'
            end
            if ~isnumeric(sig_u)
                error 'Wrong type sig_u'
            end
            if ~isnumeric(sig_v)
                error 'Wrong type sig_v'
            end
            if delay>obj.h
                error 'Delay must be less or equal to 0.1'
            end
            
            obj.dcm = dcm;
            obj.sf = sf;
            obj.sig_u = sig_u;
            obj.sig_v = sig_v;
            obj.delay = delay;
            obj.bias = zeros(3,2);
            obj.meas = zeros(3,2);
        end
        
        function [rate_meas_output, bias] = measure(obj,rate)
            obj.bias(:,:) = [obj.bias(:,2), obj.bias(:,2)+obj.sig_u*sqrt(obj.h)*randn(3,1)];
            bias = obj.bias(:,2);
            
            m = obj.dcm*((eye(3)+obj.sf)*rate+0.5*(obj.bias(:,2)+obj.bias(:,1))+...
                sqrt(obj.sig_v^2/obj.h+obj.sig_u^2*obj.h/12)*randn(3,1));
            obj.meas = [obj.meas(:,2), m];
            dalayed_meas = obj.meas(:,2)*(1-obj.delay/obj.h)+obj.meas(:,1)*obj.delay/obj.h;
            
            switch obj.failure
                case 0
                    rate_meas_output = dalayed_meas;
                otherwise
                    disp('Invalid failure flag')
            end
        end
    end
    
end

