
if Ucoil==1 && norm(Hfw_p)>=Hlow
    Ucoil=1;
elseif Ucoil==0 && norm(Hfw_p)>=Hhigh
    Ucoil=1;
else
    Ucoil=0;
end;
MagnMomentReq_p    
Ucoil=