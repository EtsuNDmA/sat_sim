function times=timeOrbit(epochyr,epochdays,params,tsince)
%     // ----------------------------------------------------------------
%     // find sgp4epoch time of element set
%     // remember that sgp4 uses units of days from 0 jan 1950 (sgp4epoch)
%     // and minutes from the epoch (time)
%     // --------------------------------------------------------------

%     // ------------- temp fix for years from 1957-2056 ----------------
%     // ------ correct fix will occur when year is 4-digit in 2le ------
if (epochyr < 57)
    year= epochyr + 2000;
else
    year= epochyr + 1900;
end;

% Время с начала эпохи в минутах
tsincemin = tsince/60;

[mon,day,hr,minute,sec] = days2mdh ( year,epochdays );
minute=minute+tsincemin;
satrec.jdsatepoch = jday( year,mon,day,hr,minute,sec );
dayOfYear=fix(epochdays+( (sec/60.0 + minute ) / 60.0 + hr ) / 24.0);
% jdut1 в гринвичскую полночь
jdut1_mn = jday( year,mon,day, 0, 0, 0 );
% Звездное время в гринвичскую полночь
gst_mn = gstime(jdut1_mn);
satrec.jdsatepoch = jday( year,mon,day,hr,minute,sec );
[ut1, tut1, jdut1, utc, tai, tt, ttt, jdtt, tdb, ttdb, jdtdb, tcg, jdtcg, tcb, jdtcb ] ...
         = convtime ( year, mon, day, hr, minute, sec, params.timezone, params.dut1, params.dat );

times.ut1	=ut1;
times.tut1	=tut1;
times.jdut1	=jdut1;
times.utc	=utc;
times.tai	=tai;
times.tt	=tt;
times.ttt	=ttt;
times.jdtt	=jdtt;
times.tdb	=tdb;
times.ttdb	=ttdb;
times.jdtdb	=jdtdb;
times.tcg	=tcg;
times.jdtcg	=jdtcg;
times.tcb	=tcb;
times.jdtcb	=jdtcb;
times.dayOfYear = dayOfYear;
times.gst_mn = gst_mn;