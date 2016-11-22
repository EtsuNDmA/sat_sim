%     // ----------------------------------------------------------------
%     // find sgp4epoch time of element set
%     // remember that sgp4 uses units of days from 0 jan 1950 (sgp4epoch)
%     // and minutes from the epoch (time)
%     // --------------------------------------------------------------

%     // ------------- temp fix for years from 1957-2056 ----------------
%     // ------ correct fix will occur when year is 4-digit in 2le ------
if (satrec.epochyr < 57)
    year= satrec.epochyr + 2000;
else
    year= satrec.epochyr + 1900;
end;

% Время с начала эпохи в минутах
tsince = (StepModel-1)*DeltaStepModel/60;

[mon,day,hr,minute,sec] = days2mdh ( year,satrec.epochdays );
minute=minute+tsince;

satrec.jdsatepoch = jday( year,mon,day,hr,minute,sec );
DayOfYear=fix(satrec.epochdays+( (sec/60.0 + minute ) / 60.0 + hr ) / 24.0);
% jdut1 в гринвичскую полночь
jdut1_mn = jday( year,mon,day, 0, 0, 0 );
% Звездное время в гринвичскую полночь
gst_mn = gstime(jdut1_mn);
%
[ut1, tut1, jdut1, utc, tai, tt, ttt, jdtt, tdb, ttdb, jdtdb, tcg, jdtcg, tcb, jdtcb ] ...
         = convtime ( year, mon, day, hr, minute, sec, timezone, dut1, dat );