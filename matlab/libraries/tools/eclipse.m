
function [beta,ecl] = eclipse(H)
%Compute percentage of eclips
%   Detailed explanation goes here
	h=H/6371;
	beta=0:1:90;
	for i=1:length(h)
		ecl(i,:)=real(1/pi*acos(sqrt(2*h(i)+h(i)^2)/(1+h(i))./cos(deg2rad(beta))));
	end;
	plot(beta,ecl);
	grid on
	xlabel('\beta (deg)')
	ylabel('T_e / T_o')
end

