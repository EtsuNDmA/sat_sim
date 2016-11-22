  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 349;
      section.data(349)  = dumData; %prealloc
      
	  ;% rtP.Constant_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Gain_Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Gain1_Gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.Constant2_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.Constant1_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtP.Constant_Value_itf12sgtld
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.Gain_Gain_iz22fd4qci
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.Gain1_Gain_grzyqbqehm
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtP.Gain3_Gain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtP.Gain4_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rtP.Constant2_Value_jxofe5s4po
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rtP.Constant1_Value_odsqffacyt
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% rtP.Constant_Value_gaw1lrkj5p
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% rtP.Gain_Gain_oxcvfncqox
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% rtP.Gain1_Gain_bmy2by4h1w
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% rtP.Gain2_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% rtP.Gain3_Gain_pjvn2rjs3s
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% rtP.Constant2_Value_jw5vkxzlyu
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% rtP.Constant1_Value_joyqlwe5wz
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% rtP.Constant_Value_pnagrbecg0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% rtP.Gain_Gain_pkrlyfmnay
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% rtP.Gain1_Gain_co11ew42wt
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% rtP.Gain2_Gain_dbcigpbpah
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% rtP.Gain3_Gain_keytyfb2hv
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% rtP.Constant_Value_bxenkd0bbl
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% rtP.Constant_Value_h3j41jz2o2
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% rtP.Constant1_Value_gxe1evpehu
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% rtP.Constant_Value_eabu3cwr2x
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 30;
	
	  ;% rtP.Constant1_Value_chkyuiwcbu
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 31;
	
	  ;% rtP.Constant_Value_lkzxmgm0bn
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% rtP.Constant1_Value_idmny2apeg
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% rtP.Constant_Value_huezfbtji2
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% rtP.Constant1_Value_hk3avlia0e
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% rtP.Constant_Value_hwdenieqz1
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 44;
	
	  ;% rtP.Constant2_Value_lni0tz223k
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 45;
	
	  ;% rtP.Constant_Value_ok5wcdghto
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 48;
	
	  ;% rtP.FromWorkspace_Time0
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 49;
	
	  ;% rtP.FromWorkspace_Data0
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 1029;
	
	  ;% rtP.FromWorkspace_Time1
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 3969;
	
	  ;% rtP.FromWorkspace_Data1
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 4949;
	
	  ;% rtP.FromWorkspace_Time2
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 7889;
	
	  ;% rtP.FromWorkspace_Data2
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 8869;
	
	  ;% rtP.FromWorkspace_Time3
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 11809;
	
	  ;% rtP.FromWorkspace_Data3
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 12789;
	
	  ;% rtP.FromWorkspace_Time4
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 15729;
	
	  ;% rtP.FromWorkspace_Data4
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 16709;
	
	  ;% rtP.Noise_Value
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 19649;
	
	  ;% rtP.Switch_Threshold
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 19652;
	
	  ;% rtP.Noise1_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 19653;
	
	  ;% rtP.Switch_Threshold_gdocqrc4t2
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 19656;
	
	  ;% rtP.Merge_InitialOutput
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 19657;
	
	  ;% rtP.Switch_Threshold_cstc3foesz
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 19661;
	
	  ;% rtP.Qjo_init_Value
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 19662;
	
	  ;% rtP.Qob_init_Value
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 19666;
	
	  ;% rtP.Switch_Threshold_cnjrei0kod
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 19670;
	
	  ;% rtP.Constant1_Value_nmcgqsupce
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 19671;
	
	  ;% rtP.Switch_Threshold_l3zqxo5bwe
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 19672;
	
	  ;% rtP.Gain_Gain_npjumclfz3
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 19673;
	
	  ;% rtP.Gain1_Gain_kvzh5djr2r
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 19674;
	
	  ;% rtP.Constant_Value_f0cxdn1qgj
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 19675;
	
	  ;% rtP.Gain2_Gain_mmkmfnjizh
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 19676;
	
	  ;% rtP.Constant_Value_knvnx2wekq
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 19677;
	
	  ;% rtP.Gain2_Gain_cpzoqqauxm
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 19678;
	
	  ;% rtP.Gain_Gain_lryaod0efo
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 19679;
	
	  ;% rtP.Gain1_Gain_kdfxi3p2kc
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 19680;
	
	  ;% rtP.Gain_Gain_gb54frueuf
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 19681;
	
	  ;% rtP.Constant_Value_m4jcoxsqs0
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 19682;
	
	  ;% rtP.Gain2_Gain_nthqdz0l5g
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 19683;
	
	  ;% rtP.Gain1_Gain_dl4zducw3w
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 19684;
	
	  ;% rtP.Gain_Gain_hiaz1ngjp4
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 19685;
	
	  ;% rtP.ChangeMe3_Value
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 19686;
	
	  ;% rtP.Constant_Value_gvhcouy2li
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 19695;
	
	  ;% rtP.Constant_Value_egr1tn4q2z
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 19704;
	
	  ;% rtP.Constant_Value_jrc3i5y0a4
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 19713;
	
	  ;% rtP.Integrator_IC
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 19716;
	
	  ;% rtP.WhiteNoise_Mean
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 19717;
	
	  ;% rtP.WhiteNoise_StdDev
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 19718;
	
	  ;% rtP.WhiteNoise_Seed
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 19719;
	
	  ;% rtP.Output_Gain
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 19720;
	
	  ;% rtP.Constant_Value_m3cuqn51ns
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 19723;
	
	  ;% rtP.DiscreteTimeIntegrator_gainval
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 19726;
	
	  ;% rtP.Gain1_Gain_a0a5bf0urx
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 19727;
	
	  ;% rtP.IntegratorLimited_IC
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 19728;
	
	  ;% rtP.IntegratorLimited_UpperSat
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 19729;
	
	  ;% rtP.IntegratorLimited_LowerSat
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 19730;
	
	  ;% rtP.IntegratorLimited_IC_fejwzsem04
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 19731;
	
	  ;% rtP.IntegratorLimited_UpperSat_ntkxmpf0qj
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 19734;
	
	  ;% rtP.IntegratorLimited_LowerSat_oacseuhnry
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 19735;
	
	  ;% rtP.Gain1_Gain_i0dny2tgg4
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 19736;
	
	  ;% rtP.Kang_Gain
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 19737;
	
	  ;% rtP.Gain_Gain_imjwpylc20
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 19738;
	
	  ;% rtP.Constant_Value_gfamwgvgio
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 19739;
	
	  ;% rtP.Gain2_Gain_hsczlo4ztj
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 19740;
	
	  ;% rtP.Gain_Gain_mwczkktdza
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 19741;
	
	  ;% rtP.Gain1_Gain_jcffkkjw2g
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 19742;
	
	  ;% rtP.Gain_Gain_keh1ebxthv
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 19743;
	
	  ;% rtP.Constant_Value_alyo2kghso
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 19744;
	
	  ;% rtP.Gain2_Gain_bnubngmvnh
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 19745;
	
	  ;% rtP.Gain1_Gain_kck2izenjg
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 19746;
	
	  ;% rtP.Gain_Gain_m1esafctux
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 19747;
	
	  ;% rtP.Gain1_Gain_gpeez3rcld
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 19748;
	
	  ;% rtP.Constant_Value_jrgvdhmfe2
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 19749;
	
	  ;% rtP.Gain2_Gain_nv4m22xdcw
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 19750;
	
	  ;% rtP.Krate_Gain
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 19751;
	
	  ;% rtP.ChangeMe1_Value
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 19752;
	
	  ;% rtP.ChangeMe2_Value
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 19761;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 19764;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 19765;
	
	  ;% rtP.Gain1_Gain_dkf041qpaw
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 19766;
	
	  ;% rtP.Saturation_UpperSat_faael1sbi5
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 19767;
	
	  ;% rtP.Saturation_LowerSat_agytdqopmw
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 19768;
	
	  ;% rtP.Constant_Value_lrvvatbdw3
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 19769;
	
	  ;% rtP.Constant3_Value
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 19772;
	
	  ;% rtP.Constant_Value_kejneha0ij
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 19773;
	
	  ;% rtP.Constant_Value_bc5jwlnuhr
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 19774;
	
	  ;% rtP.Gain_Gain_n3x52x0hib
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 19775;
	
	  ;% rtP.DiscreteTimeIntegrator_gainval_nclh2cnkov
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 19776;
	
	  ;% rtP.Constant_Value_pakwzwri3w
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 19777;
	
	  ;% rtP.Gain_Gain_aylskoktgk
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 19778;
	
	  ;% rtP.Gain1_Gain_cphlya4qdx
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 19779;
	
	  ;% rtP.Constant_Value_mx1msscuqd
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 19780;
	
	  ;% rtP.Gain2_Gain_ohkyc5atre
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 19781;
	
	  ;% rtP.Constant_Value_l4fxoeulw2
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 19782;
	
	  ;% rtP.Gain2_Gain_m0t2xxz40v
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 19783;
	
	  ;% rtP.Gain_Gain_frcbiltvyt
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 19784;
	
	  ;% rtP.Gain1_Gain_hlgkmxw45m
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 19785;
	
	  ;% rtP.Gain_Gain_jlgfxmogcv
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 19786;
	
	  ;% rtP.Constant_Value_dvdmweasr4
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 19787;
	
	  ;% rtP.Gain2_Gain_h305jf3sv3
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 19788;
	
	  ;% rtP.Gain1_Gain_hdwvivfv4n
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 19789;
	
	  ;% rtP.Gain_Gain_akwngypvn3
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 19790;
	
	  ;% rtP.DiscreteTimeIntegrator1_gainval
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 19791;
	
	  ;% rtP.DiscreteTimeIntegrator1_IC
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 19792;
	
	  ;% rtP.DiscreteTimeIntegrator2_gainval
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 19793;
	
	  ;% rtP.DiscreteTimeIntegrator2_IC
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 19794;
	
	  ;% rtP.Constant_Value_csl0xc4ep4
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 19795;
	
	  ;% rtP.Constant1_Value_d0nljg3n4k
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 19796;
	
	  ;% rtP.Switch_Threshold_ocvrgqhwfd
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 19797;
	
	  ;% rtP.Constant_Value_egwar5iee0
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 19798;
	
	  ;% rtP.HighGainQuaternionNormalization_Gain
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 19799;
	
	  ;% rtP.Constant3_Value_oayr5juvkv
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 19800;
	
	  ;% rtP.Gain8_Gain
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 19801;
	
	  ;% rtP.Gain6_Gain
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 19802;
	
	  ;% rtP.Gain7_Gain
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 19803;
	
	  ;% rtP.a_Value
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 19804;
	
	  ;% rtP.Gain5_Gain
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 19805;
	
	  ;% rtP.Constant1_Value_de0q5adpcb
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 19806;
	
	  ;% rtP.Constant_Value_bw3vkbj2eu
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 19815;
	
	  ;% rtP.Gain_Gain_av3hfhcgyv
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 19816;
	
	  ;% rtP.Constant_Value_bin4grumgj
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 19817;
	
	  ;% rtP.Constant2_Value_jf2fosnw3b
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 19818;
	
	  ;% rtP.Gain_Gain_mbuijwi5jm
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 19821;
	
	  ;% rtP.Constant_Value_jgjdenbdkp
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 19822;
	
	  ;% rtP.Constant5_Value
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 19823;
	
	  ;% rtP.Gain_Gain_hsvk1ppevl
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 19826;
	
	  ;% rtP.Constant_Value_dlgbgdxgmn
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 19827;
	
	  ;% rtP.Gain_Gain_dxvjzvgyer
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 19828;
	
	  ;% rtP.Constant_Value_p2yj2qsewh
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 19829;
	
	  ;% rtP.Constant3_Value_fjjscdcrzj
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 19830;
	
	  ;% rtP.Gain_Gain_e42rl13cmn
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 19833;
	
	  ;% rtP.Constant_Value_fn2jvveflf
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 19834;
	
	  ;% rtP.Constant6_Value
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 19835;
	
	  ;% rtP.Gain_Gain_eiuk4co0u1
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 19838;
	
	  ;% rtP.Constant_Value_pnej1bop5b
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 19839;
	
	  ;% rtP.Gain_Gain_ikyjnkugqm
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 19840;
	
	  ;% rtP.Constant_Value_irpm3cwjza
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 19841;
	
	  ;% rtP.Constant4_Value
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 19842;
	
	  ;% rtP.Gain_Gain_nogset3ro3
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 19845;
	
	  ;% rtP.Constant_Value_aecujgzxyb
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 19846;
	
	  ;% rtP.Constant7_Value
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 19847;
	
	  ;% rtP.Gain_Gain_ocowllqul3
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 19850;
	
	  ;% rtP.Constant_Value_e4va2nj2ny
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 19851;
	
	  ;% rtP.Constant_Value_hh2kih5qyy
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 19860;
	
	  ;% rtP.Switch_Threshold_dkimt1f1tz
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 19861;
	
	  ;% rtP.Constant_Value_hgpikmmnsj
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 19862;
	
	  ;% rtP.Switch_Threshold_gnlntr1le3
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 19863;
	
	  ;% rtP.Merge_InitialOutput_poz11gcqai
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 19864;
	
	  ;% rtP.Gain_Gain_mpiyuuuwgr
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 19868;
	
	  ;% rtP.Saturation_UpperSat_hafkqiwfxz
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 19869;
	
	  ;% rtP.Saturation_LowerSat_jlais4nb4c
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 19870;
	
	  ;% rtP.Constant_Value_o4e4fo4gkj
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 19871;
	
	  ;% rtP.Constant1_Value_fg2gdmjirg
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 19874;
	
	  ;% rtP.Constant_Value_ej4q1vwpv0
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 19878;
	
	  ;% rtP.Gain2_Gain_f1yzxme32r
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 19879;
	
	  ;% rtP.Gain_Gain_itterqoc4x
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 19880;
	
	  ;% rtP.Gain1_Gain_ofwpfqh4qc
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 19881;
	
	  ;% rtP.Gain_Gain_jfem1ifujv
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 19882;
	
	  ;% rtP.Constant_Value_d4om0ngdo1
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 19883;
	
	  ;% rtP.Gain2_Gain_lanpf0cnyt
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 19884;
	
	  ;% rtP.Gain1_Gain_o3l0m0cqsz
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 19885;
	
	  ;% rtP.Gain_Gain_kbkv433xum
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 19886;
	
	  ;% rtP.Gain1_Gain_aw5xkpj1cf
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 19887;
	
	  ;% rtP.Constant_Value_pbdti2yadl
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 19888;
	
	  ;% rtP.Gain2_Gain_oat3nps3gi
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 19889;
	
	  ;% rtP.ChangeMe_Value
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 19890;
	
	  ;% rtP.Gain1_Gain_cz2xpyyxre
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 19893;
	
	  ;% rtP.Constant1_Value_pibyfcp5ht
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 19894;
	
	  ;% rtP.Gain2_Gain_g3pgvavbec
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 19897;
	
	  ;% rtP.Constant2_Value_erhep10kxc
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 19898;
	
	  ;% rtP.Gain3_Gain_nlnczbyk1z
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 19901;
	
	  ;% rtP.Constant3_Value_au20vl24uo
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 19902;
	
	  ;% rtP.Gain4_Gain_obkdmqncg2
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 19905;
	
	  ;% rtP.Gain5_Gain_fzoolgsndi
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 19906;
	
	  ;% rtP.Constant_Value_fjgr21kt5s
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 19907;
	
	  ;% rtP.HighGainQuaternionNormalization_Gain_ob3hm0wdis
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 19908;
	
	  ;% rtP.Gain6_Gain_nptkktx5dl
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 19909;
	
	  ;% rtP.WhiteNoise_Mean_fpnv13epd5
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 19910;
	
	  ;% rtP.WhiteNoise_StdDev_esrovvidoo
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 19911;
	
	  ;% rtP.WhiteNoise_Seed_kw4ej5243j
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 19912;
	
	  ;% rtP.Output_Gain_ba0gpqdttx
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 19913;
	
	  ;% rtP.Gain_Gain_ovaf4mtkfv
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 19916;
	
	  ;% rtP.Constant_Value_ez3apkr1wy
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 19917;
	
	  ;% rtP.Constant_Value_nt3nodlo0n
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 19918;
	
	  ;% rtP.Gain2_Gain_b455g1loe1
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 19919;
	
	  ;% rtP.Gain_Gain_pxe1qwiizn
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 19920;
	
	  ;% rtP.Gain1_Gain_huu1lmrels
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 19921;
	
	  ;% rtP.Gain_Gain_j0vyy2fy2r
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 19922;
	
	  ;% rtP.Constant_Value_jy4gaazlnd
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 19923;
	
	  ;% rtP.Gain2_Gain_bujbdfke15
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 19924;
	
	  ;% rtP.Gain1_Gain_fkwqudcabt
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 19925;
	
	  ;% rtP.Gain_Gain_bigflic040
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 19926;
	
	  ;% rtP.Gain1_Gain_hfanpouy13
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 19927;
	
	  ;% rtP.Constant_Value_mctqlak3ab
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 19928;
	
	  ;% rtP.Gain2_Gain_o4dc4ko20g
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 19929;
	
	  ;% rtP.Switch_Threshold_jv24xn0sxc
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 19930;
	
	  ;% rtP.IntegratorLimited_IC_k0pmcuud0v
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 19931;
	
	  ;% rtP.IntegratorLimited_UpperSat_fwrvmo440m
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 19932;
	
	  ;% rtP.IntegratorLimited_LowerSat_m3ljhooqpl
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 19933;
	
	  ;% rtP.Constant_Value_lcleawr1lx
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 19934;
	
	  ;% rtP.IntegratorLimited_IC_fuyeuczoy3
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 19937;
	
	  ;% rtP.IntegratorLimited_UpperSat_ib2vfv1ckh
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 19940;
	
	  ;% rtP.IntegratorLimited_LowerSat_l15h4cnjuq
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 19941;
	
	  ;% rtP.Gain1_Gain_n011xbqfsl
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 19942;
	
	  ;% rtP.ChangeMe3_Value_g3bcdwbqnq
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 19943;
	
	  ;% rtP.Constant_Value_deca5ebbvm
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 19952;
	
	  ;% rtP.Constant_Value_oc4kpc4egn
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 19953;
	
	  ;% rtP.Constant1_Value_bzw0ndzkcq
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 19954;
	
	  ;% rtP.FromWorkspace_Time0_ckirflsq1k
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 19955;
	
	  ;% rtP.FromWorkspace_Data0_i0n1gmpn4i
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 20935;
	
	  ;% rtP.FromWorkspace_Time1_fbttqagftm
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 23875;
	
	  ;% rtP.FromWorkspace_Data1_naxvmyfyud
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 24855;
	
	  ;% rtP.FromWorkspace_Time2_p5mrmwomhx
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 27795;
	
	  ;% rtP.FromWorkspace_Data2_mxf1q2pwwa
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 28775;
	
	  ;% rtP.FromWorkspace_Time3_hofsogvoq5
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 31715;
	
	  ;% rtP.FromWorkspace_Data3_atkkn5wa2c
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 32695;
	
	  ;% rtP.FromWorkspace_Time4_kus2hl432n
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 35635;
	
	  ;% rtP.FromWorkspace_Data4_bp4l4d2qb1
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 36615;
	
	  ;% rtP.Constant_Value_nbket1mlnp
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 39555;
	
	  ;% rtP.Switch_Threshold_g4wyietdsx
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 39556;
	
	  ;% rtP.Constant_Value_oj52tmdbor
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 39557;
	
	  ;% rtP.Switch_Threshold_msevguw5vk
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 39558;
	
	  ;% rtP.Merge_InitialOutput_iavc5wanks
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 39559;
	
	  ;% rtP.Switch_Threshold_i0bmwnwue3
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 39563;
	
	  ;% rtP.Qjo_init_Value_gqletaanjz
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 39564;
	
	  ;% rtP.Qob_init_Value_onwkle1j2e
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 39568;
	
	  ;% rtP.Switch_Threshold_i3smlivfgb
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 39572;
	
	  ;% rtP.Constant1_Value_cfl4aorgnt
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 39573;
	
	  ;% rtP.Switch_Threshold_oly1kcdrtr
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 39574;
	
	  ;% rtP.Kang_Gain_n0feef1eux
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 39575;
	
	  ;% rtP.Gain_Gain_bmoksmecff
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 39576;
	
	  ;% rtP.Constant_Value_gxdrvm4bpy
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 39577;
	
	  ;% rtP.Gain2_Gain_heaghzzgpx
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 39578;
	
	  ;% rtP.Gain_Gain_pgxythkq3t
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 39579;
	
	  ;% rtP.Gain1_Gain_aytyfi3wnb
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 39580;
	
	  ;% rtP.Gain_Gain_i0c4kruuzt
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 39581;
	
	  ;% rtP.Constant_Value_cictyeh5tj
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 39582;
	
	  ;% rtP.Gain2_Gain_fmqrns42ku
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 39583;
	
	  ;% rtP.Gain1_Gain_epqkenchvx
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 39584;
	
	  ;% rtP.Gain_Gain_e3nk2dcxil
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 39585;
	
	  ;% rtP.Gain1_Gain_gnp24rmnoz
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 39586;
	
	  ;% rtP.Constant_Value_c1xelsucey
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 39587;
	
	  ;% rtP.Gain2_Gain_evefvpl1an
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 39588;
	
	  ;% rtP.Krate_Gain_piyaqat3c3
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 39589;
	
	  ;% rtP.ChangeMe1_Value_fak2wrhghj
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 39590;
	
	  ;% rtP.ChangeMe2_Value_bojzs0xv5c
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 39599;
	
	  ;% rtP.Saturation_UpperSat_pmclfotbip
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 39602;
	
	  ;% rtP.Saturation_LowerSat_hmweagl2k5
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 39603;
	
	  ;% rtP.Gain1_Gain_ftwdy5cupq
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 39604;
	
	  ;% rtP.Saturation_UpperSat_kvg53uzs0w
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 39605;
	
	  ;% rtP.Saturation_LowerSat_ak0p0zlbrx
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 39606;
	
	  ;% rtP.Constant_Value_ba4yjgwi4a
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 39607;
	
	  ;% rtP.Constant3_Value_ozgyx12s5q
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 39610;
	
	  ;% rtP.Constant_Value_fnng3n2cqs
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 39611;
	
	  ;% rtP.Constant_Value_aav3mecjn5
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 39612;
	
	  ;% rtP.Gain_Gain_ltta3l4gzo
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 39613;
	
	  ;% rtP.DiscreteTimeIntegrator_gainval_nlfnzii0in
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 39614;
	
	  ;% rtP.Constant_Value_drjehzq42h
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 39615;
	
	  ;% rtP.Gain_Gain_jl2l3kvkt1
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 39616;
	
	  ;% rtP.Gain1_Gain_mxggrkn41e
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 39617;
	
	  ;% rtP.Constant_Value_me5yv0jtlt
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 39618;
	
	  ;% rtP.Gain2_Gain_fvc01em23y
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 39619;
	
	  ;% rtP.Constant_Value_bs5xuxpbbf
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 39620;
	
	  ;% rtP.Gain2_Gain_ftpblpfslm
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 39621;
	
	  ;% rtP.Gain_Gain_hxfbfej4zq
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 39622;
	
	  ;% rtP.Gain1_Gain_aw0t0ojudt
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 39623;
	
	  ;% rtP.Gain_Gain_arguqsa2xk
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 39624;
	
	  ;% rtP.Constant_Value_lb5gk2wltw
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 39625;
	
	  ;% rtP.Gain2_Gain_cdkrn1kfio
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 39626;
	
	  ;% rtP.Gain1_Gain_mwe5i1fuoh
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 39627;
	
	  ;% rtP.Gain_Gain_oi1dmjf42c
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 39628;
	
	  ;% rtP.DiscreteTimeIntegrator1_gainval_lb44ya5e4p
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 39629;
	
	  ;% rtP.DiscreteTimeIntegrator1_IC_ht15kdk502
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 39630;
	
	  ;% rtP.DiscreteTimeIntegrator2_gainval_pfnmbeyr34
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 39631;
	
	  ;% rtP.DiscreteTimeIntegrator2_IC_liuu5c3kzq
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 39632;
	
	  ;% rtP.Constant_Value_bifugeoxsi
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 39633;
	
	  ;% rtP.Constant1_Value_i2bviibqa1
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 39634;
	
	  ;% rtP.Switch_Threshold_ih32etj225
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 39635;
	
	  ;% rtP.Constant_Value_hbjvgrrmsz
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 39636;
	
	  ;% rtP.HighGainQuaternionNormalization_Gain_nnwvygfxro
	  section.data(309).logicalSrcIdx = 308;
	  section.data(309).dtTransOffset = 39637;
	
	  ;% rtP.Constant3_Value_owr20rawcp
	  section.data(310).logicalSrcIdx = 309;
	  section.data(310).dtTransOffset = 39638;
	
	  ;% rtP.Gain8_Gain_hmjcxkynt4
	  section.data(311).logicalSrcIdx = 310;
	  section.data(311).dtTransOffset = 39639;
	
	  ;% rtP.Gain6_Gain_h3125rb23e
	  section.data(312).logicalSrcIdx = 311;
	  section.data(312).dtTransOffset = 39640;
	
	  ;% rtP.Gain7_Gain_gmfxftd3mb
	  section.data(313).logicalSrcIdx = 312;
	  section.data(313).dtTransOffset = 39641;
	
	  ;% rtP.a_Value_f5j011wiug
	  section.data(314).logicalSrcIdx = 313;
	  section.data(314).dtTransOffset = 39642;
	
	  ;% rtP.Gain5_Gain_bz0vauxshy
	  section.data(315).logicalSrcIdx = 314;
	  section.data(315).dtTransOffset = 39643;
	
	  ;% rtP.Constant1_Value_hao4x44ah2
	  section.data(316).logicalSrcIdx = 315;
	  section.data(316).dtTransOffset = 39644;
	
	  ;% rtP.Constant_Value_k0wcldte3h
	  section.data(317).logicalSrcIdx = 316;
	  section.data(317).dtTransOffset = 39653;
	
	  ;% rtP.Gain_Gain_aa0vtk0zmd
	  section.data(318).logicalSrcIdx = 317;
	  section.data(318).dtTransOffset = 39654;
	
	  ;% rtP.Constant_Value_hwvscamm31
	  section.data(319).logicalSrcIdx = 318;
	  section.data(319).dtTransOffset = 39655;
	
	  ;% rtP.Constant2_Value_c3n5xbbf35
	  section.data(320).logicalSrcIdx = 319;
	  section.data(320).dtTransOffset = 39656;
	
	  ;% rtP.Gain_Gain_ojc15iu5jd
	  section.data(321).logicalSrcIdx = 320;
	  section.data(321).dtTransOffset = 39659;
	
	  ;% rtP.Constant_Value_c2kug4uglk
	  section.data(322).logicalSrcIdx = 321;
	  section.data(322).dtTransOffset = 39660;
	
	  ;% rtP.Constant5_Value_gn0gckpuzn
	  section.data(323).logicalSrcIdx = 322;
	  section.data(323).dtTransOffset = 39661;
	
	  ;% rtP.Gain_Gain_kqt10qghkc
	  section.data(324).logicalSrcIdx = 323;
	  section.data(324).dtTransOffset = 39664;
	
	  ;% rtP.Constant_Value_pxpcd5bk3c
	  section.data(325).logicalSrcIdx = 324;
	  section.data(325).dtTransOffset = 39665;
	
	  ;% rtP.Gain_Gain_jjixz4kmpu
	  section.data(326).logicalSrcIdx = 325;
	  section.data(326).dtTransOffset = 39666;
	
	  ;% rtP.Constant_Value_kvybbzfnrt
	  section.data(327).logicalSrcIdx = 326;
	  section.data(327).dtTransOffset = 39667;
	
	  ;% rtP.Constant3_Value_a5rnl3iohi
	  section.data(328).logicalSrcIdx = 327;
	  section.data(328).dtTransOffset = 39668;
	
	  ;% rtP.Gain_Gain_nb04rhjuqe
	  section.data(329).logicalSrcIdx = 328;
	  section.data(329).dtTransOffset = 39671;
	
	  ;% rtP.Constant_Value_aawk2y00ma
	  section.data(330).logicalSrcIdx = 329;
	  section.data(330).dtTransOffset = 39672;
	
	  ;% rtP.Constant6_Value_fhjuxteqna
	  section.data(331).logicalSrcIdx = 330;
	  section.data(331).dtTransOffset = 39673;
	
	  ;% rtP.Gain_Gain_fazvlmdyvx
	  section.data(332).logicalSrcIdx = 331;
	  section.data(332).dtTransOffset = 39676;
	
	  ;% rtP.Constant_Value_kpvlwz5g2c
	  section.data(333).logicalSrcIdx = 332;
	  section.data(333).dtTransOffset = 39677;
	
	  ;% rtP.Gain_Gain_anyjlb3pu0
	  section.data(334).logicalSrcIdx = 333;
	  section.data(334).dtTransOffset = 39678;
	
	  ;% rtP.Constant_Value_amfkvbii2o
	  section.data(335).logicalSrcIdx = 334;
	  section.data(335).dtTransOffset = 39679;
	
	  ;% rtP.Constant4_Value_ohaes1tek1
	  section.data(336).logicalSrcIdx = 335;
	  section.data(336).dtTransOffset = 39680;
	
	  ;% rtP.Gain_Gain_nqjty0rsxr
	  section.data(337).logicalSrcIdx = 336;
	  section.data(337).dtTransOffset = 39683;
	
	  ;% rtP.Constant_Value_ebfrcaxa1u
	  section.data(338).logicalSrcIdx = 337;
	  section.data(338).dtTransOffset = 39684;
	
	  ;% rtP.Constant7_Value_ihkbrtwf0t
	  section.data(339).logicalSrcIdx = 338;
	  section.data(339).dtTransOffset = 39685;
	
	  ;% rtP.Gain_Gain_ldb0s3bi33
	  section.data(340).logicalSrcIdx = 339;
	  section.data(340).dtTransOffset = 39688;
	
	  ;% rtP.Constant_Value_dx3sborzrl
	  section.data(341).logicalSrcIdx = 340;
	  section.data(341).dtTransOffset = 39689;
	
	  ;% rtP.Constant_Value_epdybnohto
	  section.data(342).logicalSrcIdx = 341;
	  section.data(342).dtTransOffset = 39698;
	
	  ;% rtP.Switch_Threshold_oksbac2myv
	  section.data(343).logicalSrcIdx = 342;
	  section.data(343).dtTransOffset = 39699;
	
	  ;% rtP.Constant_Value_eovzc0nuc4
	  section.data(344).logicalSrcIdx = 343;
	  section.data(344).dtTransOffset = 39700;
	
	  ;% rtP.Switch_Threshold_lodxyjq4uq
	  section.data(345).logicalSrcIdx = 344;
	  section.data(345).dtTransOffset = 39701;
	
	  ;% rtP.Merge_InitialOutput_bepp0144uv
	  section.data(346).logicalSrcIdx = 345;
	  section.data(346).dtTransOffset = 39702;
	
	  ;% rtP.Gain_Gain_goqw3vji4e
	  section.data(347).logicalSrcIdx = 346;
	  section.data(347).dtTransOffset = 39706;
	
	  ;% rtP.Saturation_UpperSat_kq1vntuako
	  section.data(348).logicalSrcIdx = 347;
	  section.data(348).dtTransOffset = 39707;
	
	  ;% rtP.Saturation_LowerSat_iborwhdlaq
	  section.data(349).logicalSrcIdx = 348;
	  section.data(349).dtTransOffset = 39708;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtP.jtgflhe3su.Constant_Value
	  section.data(1).logicalSrcIdx = 349;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.jtgflhe3su.Gain_Gain
	  section.data(2).logicalSrcIdx = 350;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.jtgflhe3su.Constant1_Value
	  section.data(3).logicalSrcIdx = 351;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.jtgflhe3su.Constant2_Value
	  section.data(4).logicalSrcIdx = 352;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.jtgflhe3su.Gain1_Gain
	  section.data(5).logicalSrcIdx = 353;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtP.jtgflhe3su.Gain3_Gain
	  section.data(6).logicalSrcIdx = 354;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.jtgflhe3su.Gain4_Gain
	  section.data(7).logicalSrcIdx = 355;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.jtgflhe3su.Constant_Value_pc3s5n5ig0
	  section.data(8).logicalSrcIdx = 356;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtP.jtgflhe3su.Gain_Gain_g0crcybw52
	  section.data(9).logicalSrcIdx = 357;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtP.jtgflhe3su.Constant1_Value_pvid3jlafh
	  section.data(10).logicalSrcIdx = 358;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rtP.jtgflhe3su.Constant2_Value_bgmtgxyswg
	  section.data(11).logicalSrcIdx = 359;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rtP.jtgflhe3su.Gain1_Gain_cmjmtszzlh
	  section.data(12).logicalSrcIdx = 360;
	  section.data(12).dtTransOffset = 13;
	
	  ;% rtP.jtgflhe3su.Gain2_Gain
	  section.data(13).logicalSrcIdx = 361;
	  section.data(13).dtTransOffset = 14;
	
	  ;% rtP.jtgflhe3su.Gain3_Gain_fjdyxqygiq
	  section.data(14).logicalSrcIdx = 362;
	  section.data(14).dtTransOffset = 15;
	
	  ;% rtP.jtgflhe3su.Constant_Value_elm2slanqm
	  section.data(15).logicalSrcIdx = 363;
	  section.data(15).dtTransOffset = 16;
	
	  ;% rtP.jtgflhe3su.Gain_Gain_ocfwspzgot
	  section.data(16).logicalSrcIdx = 364;
	  section.data(16).dtTransOffset = 17;
	
	  ;% rtP.jtgflhe3su.Constant1_Value_cf4j34iv2x
	  section.data(17).logicalSrcIdx = 365;
	  section.data(17).dtTransOffset = 18;
	
	  ;% rtP.jtgflhe3su.Constant2_Value_pt2pqq3qma
	  section.data(18).logicalSrcIdx = 366;
	  section.data(18).dtTransOffset = 19;
	
	  ;% rtP.jtgflhe3su.Gain1_Gain_dvdkv5tz32
	  section.data(19).logicalSrcIdx = 367;
	  section.data(19).dtTransOffset = 21;
	
	  ;% rtP.jtgflhe3su.Gain2_Gain_atvqpareya
	  section.data(20).logicalSrcIdx = 368;
	  section.data(20).dtTransOffset = 22;
	
	  ;% rtP.jtgflhe3su.Gain3_Gain_clfc33gypf
	  section.data(21).logicalSrcIdx = 369;
	  section.data(21).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtP.ammeeph1io.Constant_Value
	  section.data(1).logicalSrcIdx = 370;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.ammeeph1io.Gain_Gain
	  section.data(2).logicalSrcIdx = 371;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.ammeeph1io.Gain1_Gain
	  section.data(3).logicalSrcIdx = 372;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtP.iry0wsg2k5.Constant_Value
	  section.data(1).logicalSrcIdx = 373;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.iry0wsg2k5.Gain_Gain
	  section.data(2).logicalSrcIdx = 374;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.iry0wsg2k5.Constant1_Value
	  section.data(3).logicalSrcIdx = 375;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.iry0wsg2k5.Constant2_Value
	  section.data(4).logicalSrcIdx = 376;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.iry0wsg2k5.Gain1_Gain
	  section.data(5).logicalSrcIdx = 377;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtP.iry0wsg2k5.Gain3_Gain
	  section.data(6).logicalSrcIdx = 378;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.iry0wsg2k5.Gain4_Gain
	  section.data(7).logicalSrcIdx = 379;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.iry0wsg2k5.Constant_Value_pc3s5n5ig0
	  section.data(8).logicalSrcIdx = 380;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtP.iry0wsg2k5.Gain_Gain_g0crcybw52
	  section.data(9).logicalSrcIdx = 381;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtP.iry0wsg2k5.Constant1_Value_pvid3jlafh
	  section.data(10).logicalSrcIdx = 382;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rtP.iry0wsg2k5.Constant2_Value_bgmtgxyswg
	  section.data(11).logicalSrcIdx = 383;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rtP.iry0wsg2k5.Gain1_Gain_cmjmtszzlh
	  section.data(12).logicalSrcIdx = 384;
	  section.data(12).dtTransOffset = 13;
	
	  ;% rtP.iry0wsg2k5.Gain2_Gain
	  section.data(13).logicalSrcIdx = 385;
	  section.data(13).dtTransOffset = 14;
	
	  ;% rtP.iry0wsg2k5.Gain3_Gain_fjdyxqygiq
	  section.data(14).logicalSrcIdx = 386;
	  section.data(14).dtTransOffset = 15;
	
	  ;% rtP.iry0wsg2k5.Constant_Value_elm2slanqm
	  section.data(15).logicalSrcIdx = 387;
	  section.data(15).dtTransOffset = 16;
	
	  ;% rtP.iry0wsg2k5.Gain_Gain_ocfwspzgot
	  section.data(16).logicalSrcIdx = 388;
	  section.data(16).dtTransOffset = 17;
	
	  ;% rtP.iry0wsg2k5.Constant1_Value_cf4j34iv2x
	  section.data(17).logicalSrcIdx = 389;
	  section.data(17).dtTransOffset = 18;
	
	  ;% rtP.iry0wsg2k5.Constant2_Value_pt2pqq3qma
	  section.data(18).logicalSrcIdx = 390;
	  section.data(18).dtTransOffset = 19;
	
	  ;% rtP.iry0wsg2k5.Gain1_Gain_dvdkv5tz32
	  section.data(19).logicalSrcIdx = 391;
	  section.data(19).dtTransOffset = 21;
	
	  ;% rtP.iry0wsg2k5.Gain2_Gain_atvqpareya
	  section.data(20).logicalSrcIdx = 392;
	  section.data(20).dtTransOffset = 22;
	
	  ;% rtP.iry0wsg2k5.Gain3_Gain_clfc33gypf
	  section.data(21).logicalSrcIdx = 393;
	  section.data(21).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtP.orebwtip3e.Constant_Value
	  section.data(1).logicalSrcIdx = 394;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.orebwtip3e.Gain_Gain
	  section.data(2).logicalSrcIdx = 395;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.orebwtip3e.Gain1_Gain
	  section.data(3).logicalSrcIdx = 396;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtP.azz3d4nxcem.Constant_Value
	  section.data(1).logicalSrcIdx = 397;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.azz3d4nxcem.Gain_Gain
	  section.data(2).logicalSrcIdx = 398;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.azz3d4nxcem.Constant1_Value
	  section.data(3).logicalSrcIdx = 399;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.azz3d4nxcem.Constant2_Value
	  section.data(4).logicalSrcIdx = 400;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.azz3d4nxcem.Gain1_Gain
	  section.data(5).logicalSrcIdx = 401;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtP.azz3d4nxcem.Gain3_Gain
	  section.data(6).logicalSrcIdx = 402;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.azz3d4nxcem.Gain4_Gain
	  section.data(7).logicalSrcIdx = 403;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.azz3d4nxcem.Constant_Value_pc3s5n5ig0
	  section.data(8).logicalSrcIdx = 404;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtP.azz3d4nxcem.Gain_Gain_g0crcybw52
	  section.data(9).logicalSrcIdx = 405;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtP.azz3d4nxcem.Constant1_Value_pvid3jlafh
	  section.data(10).logicalSrcIdx = 406;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rtP.azz3d4nxcem.Constant2_Value_bgmtgxyswg
	  section.data(11).logicalSrcIdx = 407;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rtP.azz3d4nxcem.Gain1_Gain_cmjmtszzlh
	  section.data(12).logicalSrcIdx = 408;
	  section.data(12).dtTransOffset = 13;
	
	  ;% rtP.azz3d4nxcem.Gain2_Gain
	  section.data(13).logicalSrcIdx = 409;
	  section.data(13).dtTransOffset = 14;
	
	  ;% rtP.azz3d4nxcem.Gain3_Gain_fjdyxqygiq
	  section.data(14).logicalSrcIdx = 410;
	  section.data(14).dtTransOffset = 15;
	
	  ;% rtP.azz3d4nxcem.Constant_Value_elm2slanqm
	  section.data(15).logicalSrcIdx = 411;
	  section.data(15).dtTransOffset = 16;
	
	  ;% rtP.azz3d4nxcem.Gain_Gain_ocfwspzgot
	  section.data(16).logicalSrcIdx = 412;
	  section.data(16).dtTransOffset = 17;
	
	  ;% rtP.azz3d4nxcem.Constant1_Value_cf4j34iv2x
	  section.data(17).logicalSrcIdx = 413;
	  section.data(17).dtTransOffset = 18;
	
	  ;% rtP.azz3d4nxcem.Constant2_Value_pt2pqq3qma
	  section.data(18).logicalSrcIdx = 414;
	  section.data(18).dtTransOffset = 19;
	
	  ;% rtP.azz3d4nxcem.Gain1_Gain_dvdkv5tz32
	  section.data(19).logicalSrcIdx = 415;
	  section.data(19).dtTransOffset = 21;
	
	  ;% rtP.azz3d4nxcem.Gain2_Gain_atvqpareya
	  section.data(20).logicalSrcIdx = 416;
	  section.data(20).dtTransOffset = 22;
	
	  ;% rtP.azz3d4nxcem.Gain3_Gain_clfc33gypf
	  section.data(21).logicalSrcIdx = 417;
	  section.data(21).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtP.p0vdevk3x14.Constant_Value
	  section.data(1).logicalSrcIdx = 418;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.p0vdevk3x14.Gain_Gain
	  section.data(2).logicalSrcIdx = 419;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.p0vdevk3x14.Gain1_Gain
	  section.data(3).logicalSrcIdx = 420;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 192;
      section.data(192)  = dumData; %prealloc
      
	  ;% rtB.njvqg5q4aw
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.jmiuxj1x02
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtB.pdvhflqrm1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtB.mtdbzc3klf
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtB.oducdqkgjs
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% rtB.e2xzeznz0p
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% rtB.fnbs1jnt55
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 16;
	
	  ;% rtB.pnzjj5cy3t
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% rtB.o3hbrpucbz
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
	  ;% rtB.dwojgwe1xs
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 23;
	
	  ;% rtB.afwtugkazt
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 26;
	
	  ;% rtB.hqqy53kfyu
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 29;
	
	  ;% rtB.awz2s5os2f
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 33;
	
	  ;% rtB.ber5tetftf
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 34;
	
	  ;% rtB.cjc4bi0q0l
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 38;
	
	  ;% rtB.j55ahl4b2c
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 42;
	
	  ;% rtB.mbcfnz4gfg
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 43;
	
	  ;% rtB.j4celd1eit
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 44;
	
	  ;% rtB.bwyuqwyvcb
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 45;
	
	  ;% rtB.fz0figaoto
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 46;
	
	  ;% rtB.iooczl3zbj
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 50;
	
	  ;% rtB.ihj3tr11iv
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 59;
	
	  ;% rtB.n1iqi5rfxp
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 68;
	
	  ;% rtB.lronvhy5ya
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 71;
	
	  ;% rtB.m0g2rkinvl
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 74;
	
	  ;% rtB.o5eruvbnew
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 77;
	
	  ;% rtB.kwssbn0ne4
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 80;
	
	  ;% rtB.jx00cruu0k
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 83;
	
	  ;% rtB.lcvceh3hv3
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 86;
	
	  ;% rtB.nfbfh1ljmc
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 89;
	
	  ;% rtB.e14rgshsrb
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 92;
	
	  ;% rtB.kfrkptukdf
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 95;
	
	  ;% rtB.kta3wrejd4
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 98;
	
	  ;% rtB.gcm3v00fw3
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 101;
	
	  ;% rtB.bilokkqatz
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 104;
	
	  ;% rtB.kcl5mw42rb
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 107;
	
	  ;% rtB.p05flgh0s0
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 110;
	
	  ;% rtB.p4tfma3j1a
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 113;
	
	  ;% rtB.brbbovdl2o
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 116;
	
	  ;% rtB.e2dsphxszg
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 119;
	
	  ;% rtB.gdyvpgriuc
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 122;
	
	  ;% rtB.jty1zsef01
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 125;
	
	  ;% rtB.l4ynfqsuix
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 128;
	
	  ;% rtB.ajquw4hgfb
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 131;
	
	  ;% rtB.piiwfosis5
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 134;
	
	  ;% rtB.golhlydrqf
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 137;
	
	  ;% rtB.bz3arzyxmq
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 155;
	
	  ;% rtB.c0wivtryvw
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 158;
	
	  ;% rtB.bqng0z1mqz
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 176;
	
	  ;% rtB.ajml5jquws
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 194;
	
	  ;% rtB.nowaxdrerk
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 203;
	
	  ;% rtB.cd1svnc4xn
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 230;
	
	  ;% rtB.nye3sr1z21
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 257;
	
	  ;% rtB.hvzm4sux2r
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 260;
	
	  ;% rtB.gdzioetcaj
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 263;
	
	  ;% rtB.p5kqeroffv
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 272;
	
	  ;% rtB.pbw2adbesb
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 275;
	
	  ;% rtB.ab5xgw0342
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 276;
	
	  ;% rtB.ct3c5eoli2
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 277;
	
	  ;% rtB.crik5dobwi
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 278;
	
	  ;% rtB.o1klch4xqt
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 279;
	
	  ;% rtB.f22csweirk
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 288;
	
	  ;% rtB.ctfm1d5uqu
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 297;
	
	  ;% rtB.lqnx4g1go5
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 306;
	
	  ;% rtB.l3eb5r4yyc
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 309;
	
	  ;% rtB.kfrivtgbni
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 310;
	
	  ;% rtB.iloozpnfyr
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 313;
	
	  ;% rtB.lagfvd2ei5
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 316;
	
	  ;% rtB.fyykrlz50p
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 317;
	
	  ;% rtB.ehlhfalizh
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 326;
	
	  ;% rtB.g1xui3hmed
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 335;
	
	  ;% rtB.hdj40uot1u
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 344;
	
	  ;% rtB.a1254pdgfh
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 345;
	
	  ;% rtB.e22yyth3y4
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 354;
	
	  ;% rtB.dhwvhv3uh5
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 363;
	
	  ;% rtB.gutdju0mn5
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 372;
	
	  ;% rtB.fafimnaesx
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 373;
	
	  ;% rtB.ee2go4u05y
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 382;
	
	  ;% rtB.pijgu4gjiu
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 391;
	
	  ;% rtB.cz3ja34zrq
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 400;
	
	  ;% rtB.dfeof1aiqk
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 401;
	
	  ;% rtB.ox2cje3ogi
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 404;
	
	  ;% rtB.cznp4l44bm
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 405;
	
	  ;% rtB.aps03o1u4v
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 414;
	
	  ;% rtB.l2aegg0det
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 415;
	
	  ;% rtB.olx5gr2zcm
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 419;
	
	  ;% rtB.jzubqdhmue
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 420;
	
	  ;% rtB.mupkswka3h
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 421;
	
	  ;% rtB.gnf3ee0yie
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 422;
	
	  ;% rtB.bj3cbec4w1
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 425;
	
	  ;% rtB.p0m1jnhybt
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 428;
	
	  ;% rtB.jbdetydqg0
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 432;
	
	  ;% rtB.ol0ojtxxkn
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 433;
	
	  ;% rtB.neym5ecad1
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 434;
	
	  ;% rtB.h5ipoluxjw
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 437;
	
	  ;% rtB.klwhzltza0
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 440;
	
	  ;% rtB.ixebsztwtv
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 443;
	
	  ;% rtB.fwgif0j4xy
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 446;
	
	  ;% rtB.ep30hm0x0x
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 449;
	
	  ;% rtB.fpwu5qnsdz
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 452;
	
	  ;% rtB.pirqrlkfn1
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 455;
	
	  ;% rtB.bivwrzak4c
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 458;
	
	  ;% rtB.mdhwvkkkpg
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 459;
	
	  ;% rtB.kknubsmket
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 460;
	
	  ;% rtB.pok3faxosu
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 461;
	
	  ;% rtB.iklax5zz5j
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 462;
	
	  ;% rtB.dbwyygj2mo
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 466;
	
	  ;% rtB.nx1aqqkpv1
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 469;
	
	  ;% rtB.i1cyqesfho
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 472;
	
	  ;% rtB.e1jmsnwsko
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 473;
	
	  ;% rtB.h2b1u411ed
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 474;
	
	  ;% rtB.ia5lss0zy0
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 475;
	
	  ;% rtB.hfr3g5fo5z
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 476;
	
	  ;% rtB.c3goefzgk3
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 479;
	
	  ;% rtB.l4ag020lhf
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 482;
	
	  ;% rtB.lkkogows30i
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 485;
	
	  ;% rtB.bu0zd3hop0
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 488;
	
	  ;% rtB.eqdklum1kz
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 489;
	
	  ;% rtB.aff2guamhh
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 492;
	
	  ;% rtB.eaiuep244b
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 495;
	
	  ;% rtB.hzwurxk4ri
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 496;
	
	  ;% rtB.iex2hnoztb
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 499;
	
	  ;% rtB.naewu0mfbx
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 502;
	
	  ;% rtB.g2zpeh00jx
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 511;
	
	  ;% rtB.elhnkqcp4v
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 512;
	
	  ;% rtB.mt30lpgnlb
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 516;
	
	  ;% rtB.enst2mfa5p
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 520;
	
	  ;% rtB.iugw0131dq
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 524;
	
	  ;% rtB.j2s0rzuesy
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 525;
	
	  ;% rtB.b01symif3z
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 529;
	
	  ;% rtB.k4n51klhzm
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 532;
	
	  ;% rtB.cy0g41je3i
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 535;
	
	  ;% rtB.nxenwlnc5v
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 538;
	
	  ;% rtB.kasev2hfro
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 541;
	
	  ;% rtB.oxns51znjb
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 544;
	
	  ;% rtB.cxydpocexq
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 547;
	
	  ;% rtB.eek0a0qnzz
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 550;
	
	  ;% rtB.dc1j3uzyrw
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 553;
	
	  ;% rtB.knm4o3kbgk
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 556;
	
	  ;% rtB.gxs3gozf4z
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 559;
	
	  ;% rtB.cz1nz0dwmw
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 562;
	
	  ;% rtB.i3r4txwmvn
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 580;
	
	  ;% rtB.jnibcpqu24
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 583;
	
	  ;% rtB.j3qp0rot4z
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 601;
	
	  ;% rtB.bv5rymkkje
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 619;
	
	  ;% rtB.afjv1quvm5
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 628;
	
	  ;% rtB.kizx1ijhue
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 655;
	
	  ;% rtB.nif420hiph
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 682;
	
	  ;% rtB.d2ywubqjk2
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 685;
	
	  ;% rtB.gzh1neeoux
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 688;
	
	  ;% rtB.auwd4r4mkz
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 697;
	
	  ;% rtB.ckqhlb32gd
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 700;
	
	  ;% rtB.leq1llgjf0
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 701;
	
	  ;% rtB.jmzzln4ohz
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 702;
	
	  ;% rtB.htxixjme3q
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 703;
	
	  ;% rtB.becyljpaab
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 704;
	
	  ;% rtB.mzppckyb2r
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 713;
	
	  ;% rtB.kbnlvlyzzj
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 722;
	
	  ;% rtB.b5lvehq0lb
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 731;
	
	  ;% rtB.lssfrykd20
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 734;
	
	  ;% rtB.c1g3rp4u4f
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 735;
	
	  ;% rtB.iezlupw440
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 738;
	
	  ;% rtB.flsiozqty3
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 741;
	
	  ;% rtB.oras35y0me
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 742;
	
	  ;% rtB.jczx5mmtny
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 751;
	
	  ;% rtB.py34oc2tac
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 760;
	
	  ;% rtB.ldef0mrlxf
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 769;
	
	  ;% rtB.fqa1obuxcx
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 770;
	
	  ;% rtB.jp33z3cm2q
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 779;
	
	  ;% rtB.lna01hcwqs
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 788;
	
	  ;% rtB.af0aib4ixg
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 797;
	
	  ;% rtB.artk3v2gtx
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 798;
	
	  ;% rtB.fylvlnipqh
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 807;
	
	  ;% rtB.dnccwxtqix
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 816;
	
	  ;% rtB.a5hluyc4z4
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 825;
	
	  ;% rtB.po2fokcy2h
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 826;
	
	  ;% rtB.hwft0ux5xv
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 829;
	
	  ;% rtB.keil2t0ysq
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 830;
	
	  ;% rtB.ffoa23fpkv
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 839;
	
	  ;% rtB.e2ozyjspf1
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 840;
	
	  ;% rtB.goqp2hsxiw
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 844;
	
	  ;% rtB.h04s5dfqra
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 847;
	
	  ;% rtB.c2bqn2vvuz
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 850;
	
	  ;% rtB.f3f3ebtfsq
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 853;
	
	  ;% rtB.n0xo0shoih
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 856;
	
	  ;% rtB.bkwjtfsi54
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 859;
	
	  ;% rtB.fc4jnd0tfk
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 862;
	
	  ;% rtB.bqyj10kjri
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 865;
	
	  ;% rtB.md555povbw
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 868;
	
	  ;% rtB.ps4hnijzog
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 871;
	
	  ;% rtB.juc40yv1j4
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 874;
	
	  ;% rtB.dufe500tdo
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 877;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.jtgflhe3su.p2vvijwdyj
	  section.data(1).logicalSrcIdx = 192;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.jtgflhe3su.jea3ib45lq
	  section.data(2).logicalSrcIdx = 193;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.jtgflhe3su.fwdepyepsg
	  section.data(3).logicalSrcIdx = 194;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.iry0wsg2k5.p2vvijwdyj
	  section.data(1).logicalSrcIdx = 195;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.iry0wsg2k5.jea3ib45lq
	  section.data(2).logicalSrcIdx = 196;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.iry0wsg2k5.fwdepyepsg
	  section.data(3).logicalSrcIdx = 197;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.azz3d4nxcem.p2vvijwdyj
	  section.data(1).logicalSrcIdx = 198;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.azz3d4nxcem.jea3ib45lq
	  section.data(2).logicalSrcIdx = 199;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.azz3d4nxcem.fwdepyepsg
	  section.data(3).logicalSrcIdx = 200;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 16;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.h1cj2y3ic5
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.loaxlm1yp2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtDW.g5fe22mv15
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 21;
	
	  ;% rtDW.i5firivfli
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 30;
	
	  ;% rtDW.gj2ukru0nb
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 33;
	
	  ;% rtDW.jbnlmtknpk
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 51;
	
	  ;% rtDW.olom3dwhnc
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 60;
	
	  ;% rtDW.m5suqpxty3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 63;
	
	  ;% rtDW.phocmexnl1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% rtDW.bknzq3wgub.TimePtr
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hzkxwtgg3y.SignalProbe
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 5;
	
	  ;% rtDW.ethxueuerq.SignalProbe
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtDW.ehpedqcs01.LoggedData
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtDW.j12o25heky.LoggedData
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtDW.mohxnwpvy0.SignalProbe
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 9;
	
	  ;% rtDW.fs3xofbgsa.SignalProbe
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 10;
	
	  ;% rtDW.pmtqmlg3ku.LoggedData
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 11;
	
	  ;% rtDW.b1zuzcjxt3.LoggedData
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 12;
	
	  ;% rtDW.iyqxvnatsr.SignalProbe
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 13;
	
	  ;% rtDW.h4jqbncwhd.SignalProbe
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtDW.hu21nqqcni.SignalProbe
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtDW.oawgrr5lku.SignalProbe
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtDW.j2htmj0bku.LoggedData
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rtDW.behvht2jjq.SignalProbe
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtDW.jjiadmicyc.SignalProbe
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtDW.bgsuqbvq3e.SignalProbe
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtDW.m10l43wuz3.SignalProbe
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rtDW.i013afts1o.LoggedData
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rtDW.pnelhmbdiq.LoggedData
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rtDW.hzkxwtgg3yv.SignalProbe
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 24;
	
	  ;% rtDW.ethxueuerq5.SignalProbe
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 25;
	
	  ;% rtDW.hqwrc0ipzd.TimePtr
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 26;
	
	  ;% rtDW.pmws4cv3vf.LoggedData
	  section.data(24).logicalSrcIdx = 32;
	  section.data(24).dtTransOffset = 31;
	
	  ;% rtDW.ljepzqod3x.LoggedData
	  section.data(25).logicalSrcIdx = 33;
	  section.data(25).dtTransOffset = 32;
	
	  ;% rtDW.mohxnwpvy0k.SignalProbe
	  section.data(26).logicalSrcIdx = 34;
	  section.data(26).dtTransOffset = 33;
	
	  ;% rtDW.fs3xofbgsah.SignalProbe
	  section.data(27).logicalSrcIdx = 35;
	  section.data(27).dtTransOffset = 34;
	
	  ;% rtDW.hqqwk24acd.LoggedData
	  section.data(28).logicalSrcIdx = 36;
	  section.data(28).dtTransOffset = 35;
	
	  ;% rtDW.cendn5ypmp.LoggedData
	  section.data(29).logicalSrcIdx = 37;
	  section.data(29).dtTransOffset = 36;
	
	  ;% rtDW.iyqxvnatsrh.SignalProbe
	  section.data(30).logicalSrcIdx = 38;
	  section.data(30).dtTransOffset = 37;
	
	  ;% rtDW.h4jqbncwhda.SignalProbe
	  section.data(31).logicalSrcIdx = 39;
	  section.data(31).dtTransOffset = 38;
	
	  ;% rtDW.hu21nqqcnih.SignalProbe
	  section.data(32).logicalSrcIdx = 40;
	  section.data(32).dtTransOffset = 39;
	
	  ;% rtDW.af5udyqtv3.LoggedData
	  section.data(33).logicalSrcIdx = 41;
	  section.data(33).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.hvy1dfvqu0
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.k2mw3e5m15
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% rtDW.fibx4ptf5m.PrevIndex
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.evzrtqyrte.IcNeedsLoading
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 5;
	
	  ;% rtDW.l3ydkkphoy.IcNeedsLoading
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtDW.phnnzeax4q.IcNeedsLoading
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtDW.nrfurckayn.PrevIndex
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtDW.g0vm4fxb3p.IcNeedsLoading
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 13;
	
	  ;% rtDW.f0rotw3bar
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 14;
	
	  ;% rtDW.hxjtibst42
	  section.data(8).logicalSrcIdx = 51;
	  section.data(8).dtTransOffset = 17;
	
	  ;% rtDW.o1tdlyssu3
	  section.data(9).logicalSrcIdx = 52;
	  section.data(9).dtTransOffset = 20;
	
	  ;% rtDW.jgvugjcell
	  section.data(10).logicalSrcIdx = 53;
	  section.data(10).dtTransOffset = 23;
	
	  ;% rtDW.amy2z0blur
	  section.data(11).logicalSrcIdx = 54;
	  section.data(11).dtTransOffset = 26;
	
	  ;% rtDW.kazdxyylc3
	  section.data(12).logicalSrcIdx = 55;
	  section.data(12).dtTransOffset = 27;
	
	  ;% rtDW.pynovrdqcu
	  section.data(13).logicalSrcIdx = 56;
	  section.data(13).dtTransOffset = 30;
	
	  ;% rtDW.l2ulz1zonw
	  section.data(14).logicalSrcIdx = 57;
	  section.data(14).dtTransOffset = 33;
	
	  ;% rtDW.jk3cciiee0
	  section.data(15).logicalSrcIdx = 58;
	  section.data(15).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% rtDW.ks4j0in3rc
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.g1vf00axpm
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.bwuwpskbe1
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.kkm1wjx4mr
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.g325dldung
	  section.data(5).logicalSrcIdx = 63;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ftycguxnii
	  section.data(6).logicalSrcIdx = 64;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.l33pfglk2a
	  section.data(7).logicalSrcIdx = 65;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.fy4uwny3eb
	  section.data(8).logicalSrcIdx = 66;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.lk4bn0tg11
	  section.data(9).logicalSrcIdx = 67;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.awulziwiby
	  section.data(10).logicalSrcIdx = 68;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.mf41bf444w
	  section.data(11).logicalSrcIdx = 69;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.huixms4qzu
	  section.data(12).logicalSrcIdx = 70;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.pfcneilmew
	  section.data(13).logicalSrcIdx = 71;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.jamdmknkze
	  section.data(14).logicalSrcIdx = 72;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.ly50w4j0zu
	  section.data(15).logicalSrcIdx = 73;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.krtnuqdnk0
	  section.data(16).logicalSrcIdx = 74;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.nrel2zbbl0
	  section.data(17).logicalSrcIdx = 75;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.ej43nvwcyh
	  section.data(18).logicalSrcIdx = 76;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.oxif3bzbeo
	  section.data(19).logicalSrcIdx = 77;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.ms3ry1pdxh
	  section.data(20).logicalSrcIdx = 78;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.j3jyokwsdh
	  section.data(21).logicalSrcIdx = 79;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.lqwl4atrcd
	  section.data(22).logicalSrcIdx = 80;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.jenrmeyvts
	  section.data(23).logicalSrcIdx = 81;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.lflksa1zm2
	  section.data(24).logicalSrcIdx = 82;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.mo3k54wqkm
	  section.data(25).logicalSrcIdx = 83;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.emy0hrjuzr
	  section.data(26).logicalSrcIdx = 84;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.frxkwgelef
	  section.data(27).logicalSrcIdx = 85;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.bpfxbpnxdk
	  section.data(28).logicalSrcIdx = 86;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.kvbynbt23x
	  section.data(29).logicalSrcIdx = 87;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDW.pzmje2aewl
	  section.data(30).logicalSrcIdx = 88;
	  section.data(30).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.cht01inrsx
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.epdi02vhe4
	  section.data(2).logicalSrcIdx = 90;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.j0qx5gs3ge
	  section.data(3).logicalSrcIdx = 91;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.le5srsw3mq
	  section.data(4).logicalSrcIdx = 92;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.hfkomryudx
	  section.data(5).logicalSrcIdx = 93;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.oslrfkshxj
	  section.data(6).logicalSrcIdx = 94;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtDW.bn411rqyba
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jhekd05k4p
	  section.data(2).logicalSrcIdx = 96;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jrnny2qloo
	  section.data(3).logicalSrcIdx = 97;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.ctt5abpcf5
	  section.data(4).logicalSrcIdx = 98;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.et15tz1dc1
	  section.data(5).logicalSrcIdx = 99;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.hs4d4btmzy
	  section.data(6).logicalSrcIdx = 100;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.cgqmbfzh11
	  section.data(7).logicalSrcIdx = 101;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.gpsddborgv
	  section.data(8).logicalSrcIdx = 102;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.gpuflrf0yn
	  section.data(9).logicalSrcIdx = 103;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.aekk1bjgtl
	  section.data(10).logicalSrcIdx = 104;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.jmvufartxc
	  section.data(11).logicalSrcIdx = 105;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.idulg0qqat
	  section.data(12).logicalSrcIdx = 106;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.jtgflhe3su.fw1wxjvjvv
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jtgflhe3su.pyge1tac5l
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jtgflhe3su.occ4jhal5v
	  section.data(3).logicalSrcIdx = 109;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.jtgflhe3su.k5kqzwhgid
	  section.data(4).logicalSrcIdx = 110;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.jtgflhe3su.gvkoaih0tt
	  section.data(5).logicalSrcIdx = 111;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.jtgflhe3su.hrkt2hcocj
	  section.data(6).logicalSrcIdx = 112;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.jtgflhe3su.iq1hnty4rc
	  section.data(7).logicalSrcIdx = 113;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.jtgflhe3su.m4c02ikbg1
	  section.data(8).logicalSrcIdx = 114;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.jtgflhe3su.a0o3qpslv4
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jtgflhe3su.krlfahjhyu
	  section.data(2).logicalSrcIdx = 116;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jtgflhe3su.kuwvje3v02
	  section.data(3).logicalSrcIdx = 117;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.ammeeph1io.espotkwrxj
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ammeeph1io.lggvt2ioqm
	  section.data(2).logicalSrcIdx = 119;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.iry0wsg2k5.fw1wxjvjvv
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.iry0wsg2k5.pyge1tac5l
	  section.data(2).logicalSrcIdx = 121;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.iry0wsg2k5.occ4jhal5v
	  section.data(3).logicalSrcIdx = 122;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.iry0wsg2k5.k5kqzwhgid
	  section.data(4).logicalSrcIdx = 123;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.iry0wsg2k5.gvkoaih0tt
	  section.data(5).logicalSrcIdx = 124;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.iry0wsg2k5.hrkt2hcocj
	  section.data(6).logicalSrcIdx = 125;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.iry0wsg2k5.iq1hnty4rc
	  section.data(7).logicalSrcIdx = 126;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.iry0wsg2k5.m4c02ikbg1
	  section.data(8).logicalSrcIdx = 127;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.iry0wsg2k5.a0o3qpslv4
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.iry0wsg2k5.krlfahjhyu
	  section.data(2).logicalSrcIdx = 129;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.iry0wsg2k5.kuwvje3v02
	  section.data(3).logicalSrcIdx = 130;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.orebwtip3e.espotkwrxj
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.orebwtip3e.lggvt2ioqm
	  section.data(2).logicalSrcIdx = 132;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.azz3d4nxcem.fw1wxjvjvv
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.azz3d4nxcem.pyge1tac5l
	  section.data(2).logicalSrcIdx = 134;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.azz3d4nxcem.occ4jhal5v
	  section.data(3).logicalSrcIdx = 135;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.azz3d4nxcem.k5kqzwhgid
	  section.data(4).logicalSrcIdx = 136;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.azz3d4nxcem.gvkoaih0tt
	  section.data(5).logicalSrcIdx = 137;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.azz3d4nxcem.hrkt2hcocj
	  section.data(6).logicalSrcIdx = 138;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.azz3d4nxcem.iq1hnty4rc
	  section.data(7).logicalSrcIdx = 139;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.azz3d4nxcem.m4c02ikbg1
	  section.data(8).logicalSrcIdx = 140;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.azz3d4nxcem.a0o3qpslv4
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.azz3d4nxcem.krlfahjhyu
	  section.data(2).logicalSrcIdx = 142;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.azz3d4nxcem.kuwvje3v02
	  section.data(3).logicalSrcIdx = 143;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.p0vdevk3x14.espotkwrxj
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.p0vdevk3x14.lggvt2ioqm
	  section.data(2).logicalSrcIdx = 145;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 466111879;
  targMap.checksum1 = 3418754736;
  targMap.checksum2 = 1722666805;
  targMap.checksum3 = 1673784402;

