  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
      section.nData     = 209;
      section.data(209)  = dumData; %prealloc
      
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
	
	  ;% rtP.Constant_Value_jjhmxiynvf
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% rtP.Gain_Gain_gq1q0o0dgd
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% rtP.Gain1_Gain_gwhqm0umwh
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% rtP.Constant_Value_bqgjtgwncf
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 36;
	
	  ;% rtP.Gain_Gain_gqxkss2f4q
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 37;
	
	  ;% rtP.Constant1_Value_e2tnprjcds
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 38;
	
	  ;% rtP.Constant2_Value_ox4kgnjx1u
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 39;
	
	  ;% rtP.Gain1_Gain_plbazqymln
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 41;
	
	  ;% rtP.Gain3_Gain_lnfk34izw1
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 42;
	
	  ;% rtP.Gain4_Gain_frwaasjnjn
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 43;
	
	  ;% rtP.Constant_Value_pc3s5n5ig0
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 44;
	
	  ;% rtP.Gain_Gain_g0crcybw52
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 45;
	
	  ;% rtP.Constant1_Value_pvid3jlafh
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 46;
	
	  ;% rtP.Constant2_Value_bgmtgxyswg
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 47;
	
	  ;% rtP.Gain1_Gain_cmjmtszzlh
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 49;
	
	  ;% rtP.Gain2_Gain_lbyqu50w0f
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 50;
	
	  ;% rtP.Gain3_Gain_fjdyxqygiq
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 51;
	
	  ;% rtP.Constant_Value_elm2slanqm
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 52;
	
	  ;% rtP.Gain_Gain_ocfwspzgot
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 53;
	
	  ;% rtP.Constant1_Value_cf4j34iv2x
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 54;
	
	  ;% rtP.Constant2_Value_pt2pqq3qma
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 55;
	
	  ;% rtP.Gain1_Gain_dvdkv5tz32
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 57;
	
	  ;% rtP.Gain2_Gain_atvqpareya
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 58;
	
	  ;% rtP.Gain3_Gain_clfc33gypf
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 59;
	
	  ;% rtP.Constant4_Value
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 60;
	
	  ;% rtP.Constant_Value_ok5wcdghto
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 90;
	
	  ;% rtP.FromWorkspace_Time0
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 91;
	
	  ;% rtP.FromWorkspace_Data0
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 1071;
	
	  ;% rtP.FromWorkspace_Time1
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 4011;
	
	  ;% rtP.FromWorkspace_Data1
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 4991;
	
	  ;% rtP.FromWorkspace_Time2
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 7931;
	
	  ;% rtP.FromWorkspace_Data2
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 8911;
	
	  ;% rtP.FromWorkspace_Time3
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 11851;
	
	  ;% rtP.FromWorkspace_Data3
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 12831;
	
	  ;% rtP.FromWorkspace_Time4
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 15771;
	
	  ;% rtP.FromWorkspace_Data4
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 16751;
	
	  ;% rtP.Noise_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 19691;
	
	  ;% rtP.Switch_Threshold
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 19694;
	
	  ;% rtP.Noise1_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 19695;
	
	  ;% rtP.Switch_Threshold_gdocqrc4t2
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 19698;
	
	  ;% rtP.Merge_InitialOutput
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 19699;
	
	  ;% rtP.Switch_Threshold_cstc3foesz
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 19703;
	
	  ;% rtP.Qjo_init_Value
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 19704;
	
	  ;% rtP.Qob_init_Value
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 19708;
	
	  ;% rtP.Switch_Threshold_cnjrei0kod
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 19712;
	
	  ;% rtP.Constant1_Value_nmcgqsupce
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 19713;
	
	  ;% rtP.Switch_Threshold_l3zqxo5bwe
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 19714;
	
	  ;% rtP.Constant_Value_jd4yybwihf
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 19715;
	
	  ;% rtP.Constant_Value_gvhcouy2li
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 19716;
	
	  ;% rtP.Constant_Value_egr1tn4q2z
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 19725;
	
	  ;% rtP.Constant_Value_jrc3i5y0a4
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 19734;
	
	  ;% rtP.Integrator_IC
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 19737;
	
	  ;% rtP.WhiteNoise_Mean
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 19738;
	
	  ;% rtP.WhiteNoise_StdDev
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 19739;
	
	  ;% rtP.WhiteNoise_Seed
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 19740;
	
	  ;% rtP.Output_Gain
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 19741;
	
	  ;% rtP.Gain_Gain_imjwpylc20
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 19744;
	
	  ;% rtP.Constant_Value_gfamwgvgio
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 19745;
	
	  ;% rtP.Gain2_Gain_hsczlo4ztj
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 19746;
	
	  ;% rtP.Gain_Gain_mwczkktdza
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 19747;
	
	  ;% rtP.Gain1_Gain_jcffkkjw2g
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 19748;
	
	  ;% rtP.Gain_Gain_keh1ebxthv
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 19749;
	
	  ;% rtP.Constant_Value_alyo2kghso
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 19750;
	
	  ;% rtP.Gain2_Gain_bnubngmvnh
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 19751;
	
	  ;% rtP.Gain1_Gain_kck2izenjg
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 19752;
	
	  ;% rtP.Gain_Gain_m1esafctux
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 19753;
	
	  ;% rtP.Gain1_Gain_gpeez3rcld
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 19754;
	
	  ;% rtP.Constant_Value_jrgvdhmfe2
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 19755;
	
	  ;% rtP.Gain2_Gain_nv4m22xdcw
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 19756;
	
	  ;% rtP.ChangeMe_Value
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 19757;
	
	  ;% rtP.Gain1_Gain_cz2xpyyxre
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 19760;
	
	  ;% rtP.Constant1_Value_pibyfcp5ht
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 19761;
	
	  ;% rtP.IntegratorLimited_IC
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 19764;
	
	  ;% rtP.IntegratorLimited_UpperSat
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 19765;
	
	  ;% rtP.IntegratorLimited_LowerSat
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 19766;
	
	  ;% rtP.Gain2_Gain_g3pgvavbec
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 19767;
	
	  ;% rtP.Constant2_Value_erhep10kxc
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 19768;
	
	  ;% rtP.Gain3_Gain_nlnczbyk1z
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 19771;
	
	  ;% rtP.Constant3_Value
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 19772;
	
	  ;% rtP.Gain4_Gain_obkdmqncg2
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 19775;
	
	  ;% rtP.Gain6_Gain
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 19776;
	
	  ;% rtP.Constant1_Value_fciw0lu1dl
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 19777;
	
	  ;% rtP.Constant3_Value_cxfy0sjqiz
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 19778;
	
	  ;% rtP.Gain_Gain_fzpdiqcchq
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 19779;
	
	  ;% rtP.ChangeMe3_Value
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 19780;
	
	  ;% rtP.Kang_Gain
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 19789;
	
	  ;% rtP.Krate_Gain
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 19790;
	
	  ;% rtP.ChangeMe1_Value
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 19791;
	
	  ;% rtP.ChangeMe2_Value
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 19800;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 19803;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 19804;
	
	  ;% rtP.IntegratorLimited_IC_fejwzsem04
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 19805;
	
	  ;% rtP.IntegratorLimited_UpperSat_ntkxmpf0qj
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 19808;
	
	  ;% rtP.IntegratorLimited_LowerSat_oacseuhnry
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 19809;
	
	  ;% rtP.Gain1_Gain_dkf041qpaw
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 19810;
	
	  ;% rtP.Saturation_UpperSat_faael1sbi5
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 19811;
	
	  ;% rtP.Saturation_LowerSat_agytdqopmw
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 19812;
	
	  ;% rtP.Constant3_Value_lg1rqkvsmt
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 19813;
	
	  ;% rtP.Constant_Value_csl0xc4ep4
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 19814;
	
	  ;% rtP.Constant1_Value_d0nljg3n4k
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 19815;
	
	  ;% rtP.Switch_Threshold_ocvrgqhwfd
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 19816;
	
	  ;% rtP.Constant_Value_egwar5iee0
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 19817;
	
	  ;% rtP.HighGainQuaternionNormalization_Gain
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 19818;
	
	  ;% rtP.Constant3_Value_oayr5juvkv
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 19819;
	
	  ;% rtP.Gain8_Gain
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 19820;
	
	  ;% rtP.Gain6_Gain_lwc3ps4rex
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 19821;
	
	  ;% rtP.Gain7_Gain
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 19822;
	
	  ;% rtP.a_Value
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 19823;
	
	  ;% rtP.Gain5_Gain
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 19824;
	
	  ;% rtP.Constant1_Value_de0q5adpcb
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 19825;
	
	  ;% rtP.Constant_Value_bw3vkbj2eu
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 19834;
	
	  ;% rtP.Gain_Gain_av3hfhcgyv
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 19835;
	
	  ;% rtP.Constant_Value_bin4grumgj
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 19836;
	
	  ;% rtP.Constant2_Value_jf2fosnw3b
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 19837;
	
	  ;% rtP.Gain_Gain_mbuijwi5jm
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 19840;
	
	  ;% rtP.Constant_Value_jgjdenbdkp
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 19841;
	
	  ;% rtP.Constant5_Value
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 19842;
	
	  ;% rtP.Gain_Gain_hsvk1ppevl
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 19845;
	
	  ;% rtP.Constant_Value_dlgbgdxgmn
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 19846;
	
	  ;% rtP.Gain_Gain_dxvjzvgyer
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 19847;
	
	  ;% rtP.Constant_Value_p2yj2qsewh
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 19848;
	
	  ;% rtP.Constant3_Value_fjjscdcrzj
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 19849;
	
	  ;% rtP.Gain_Gain_e42rl13cmn
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 19852;
	
	  ;% rtP.Constant_Value_fn2jvveflf
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 19853;
	
	  ;% rtP.Constant6_Value
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 19854;
	
	  ;% rtP.Gain_Gain_eiuk4co0u1
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 19857;
	
	  ;% rtP.Constant_Value_pnej1bop5b
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 19858;
	
	  ;% rtP.Gain_Gain_ikyjnkugqm
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 19859;
	
	  ;% rtP.Constant_Value_irpm3cwjza
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 19860;
	
	  ;% rtP.Constant4_Value_arg3ksqg5d
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 19861;
	
	  ;% rtP.Gain_Gain_nogset3ro3
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 19864;
	
	  ;% rtP.Constant_Value_aecujgzxyb
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 19865;
	
	  ;% rtP.Constant7_Value
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 19866;
	
	  ;% rtP.Gain_Gain_ocowllqul3
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 19869;
	
	  ;% rtP.Constant_Value_e4va2nj2ny
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 19870;
	
	  ;% rtP.Constant_Value_hh2kih5qyy
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 19879;
	
	  ;% rtP.Switch_Threshold_dkimt1f1tz
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 19880;
	
	  ;% rtP.Constant_Value_hgpikmmnsj
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 19881;
	
	  ;% rtP.Switch_Threshold_gnlntr1le3
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 19882;
	
	  ;% rtP.Merge_InitialOutput_poz11gcqai
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 19883;
	
	  ;% rtP.Gain_Gain_mpiyuuuwgr
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 19887;
	
	  ;% rtP.Saturation_UpperSat_hafkqiwfxz
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 19888;
	
	  ;% rtP.Saturation_LowerSat_jlais4nb4c
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 19889;
	
	  ;% rtP.Constant_Value_o4e4fo4gkj
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 19890;
	
	  ;% rtP.Constant1_Value_fg2gdmjirg
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 19893;
	
	  ;% rtP.Constant_Value_ej4q1vwpv0
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 19897;
	
	  ;% rtP.Gain2_Gain_f1yzxme32r
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 19898;
	
	  ;% rtP.Gain_Gain_itterqoc4x
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 19899;
	
	  ;% rtP.Gain1_Gain_ofwpfqh4qc
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 19900;
	
	  ;% rtP.Gain_Gain_jfem1ifujv
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 19901;
	
	  ;% rtP.Constant_Value_d4om0ngdo1
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 19902;
	
	  ;% rtP.Gain2_Gain_lanpf0cnyt
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 19903;
	
	  ;% rtP.Gain1_Gain_o3l0m0cqsz
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 19904;
	
	  ;% rtP.Gain_Gain_kbkv433xum
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 19905;
	
	  ;% rtP.Gain1_Gain_aw5xkpj1cf
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 19906;
	
	  ;% rtP.Constant_Value_pbdti2yadl
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 19907;
	
	  ;% rtP.Gain2_Gain_oat3nps3gi
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 19908;
	
	  ;% rtP.Gain5_Gain_fzoolgsndi
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 19909;
	
	  ;% rtP.Constant_Value_fjgr21kt5s
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 19910;
	
	  ;% rtP.HighGainQuaternionNormalization_Gain_ob3hm0wdis
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 19911;
	
	  ;% rtP.WhiteNoise_Mean_fpnv13epd5
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 19912;
	
	  ;% rtP.WhiteNoise_StdDev_esrovvidoo
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 19913;
	
	  ;% rtP.WhiteNoise_Seed_kw4ej5243j
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 19914;
	
	  ;% rtP.Output_Gain_ba0gpqdttx
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 19915;
	
	  ;% rtP.Gain_Gain_ovaf4mtkfv
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 19918;
	
	  ;% rtP.Constant_Value_ez3apkr1wy
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 19919;
	
	  ;% rtP.Constant_Value_nt3nodlo0n
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 19920;
	
	  ;% rtP.Gain2_Gain_b455g1loe1
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 19921;
	
	  ;% rtP.Gain_Gain_pxe1qwiizn
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 19922;
	
	  ;% rtP.Gain1_Gain_huu1lmrels
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 19923;
	
	  ;% rtP.Gain_Gain_j0vyy2fy2r
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 19924;
	
	  ;% rtP.Constant_Value_jy4gaazlnd
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 19925;
	
	  ;% rtP.Gain2_Gain_bujbdfke15
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 19926;
	
	  ;% rtP.Gain1_Gain_fkwqudcabt
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 19927;
	
	  ;% rtP.Gain_Gain_bigflic040
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 19928;
	
	  ;% rtP.Gain1_Gain_hfanpouy13
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 19929;
	
	  ;% rtP.Constant_Value_mctqlak3ab
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 19930;
	
	  ;% rtP.Gain2_Gain_o4dc4ko20g
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 19931;
	
	  ;% rtP.Switch_Threshold_jv24xn0sxc
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 19932;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    nTotSects     = 1;
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
      section.nData     = 102;
      section.data(102)  = dumData; %prealloc
      
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
	
	  ;% rtB.e2xzeznz0p
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% rtB.fnbs1jnt55
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% rtB.pnzjj5cy3t
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 16;
	
	  ;% rtB.o3hbrpucbz
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 17;
	
	  ;% rtB.hqqy53kfyu
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
	  ;% rtB.awz2s5os2f
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 24;
	
	  ;% rtB.ber5tetftf
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 25;
	
	  ;% rtB.cjc4bi0q0l
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 29;
	
	  ;% rtB.j55ahl4b2c
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 33;
	
	  ;% rtB.mbcfnz4gfg
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 34;
	
	  ;% rtB.j4celd1eit
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 35;
	
	  ;% rtB.bwyuqwyvcb
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 36;
	
	  ;% rtB.fz0figaoto
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 37;
	
	  ;% rtB.ihj3tr11iv
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 41;
	
	  ;% rtB.n1iqi5rfxp
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 50;
	
	  ;% rtB.lronvhy5ya
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 53;
	
	  ;% rtB.m0g2rkinvl
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 56;
	
	  ;% rtB.o5eruvbnew
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 59;
	
	  ;% rtB.kwssbn0ne4
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 62;
	
	  ;% rtB.kcl5mw42rb
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 65;
	
	  ;% rtB.p05flgh0s0
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 68;
	
	  ;% rtB.neym5ecad1
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 71;
	
	  ;% rtB.obj5e4e3db
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 74;
	
	  ;% rtB.h5ipoluxjw
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 77;
	
	  ;% rtB.klwhzltza0
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 80;
	
	  ;% rtB.ixebsztwtv
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 83;
	
	  ;% rtB.fwgif0j4xy
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 86;
	
	  ;% rtB.dbwyygj2mo
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 89;
	
	  ;% rtB.nye0gvpgkn
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 92;
	
	  ;% rtB.iooczl3zbj
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 95;
	
	  ;% rtB.gcm3v00fw3
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 104;
	
	  ;% rtB.bilokkqatz
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 107;
	
	  ;% rtB.p4tfma3j1a
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 110;
	
	  ;% rtB.brbbovdl2o
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 113;
	
	  ;% rtB.e2dsphxszg
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 116;
	
	  ;% rtB.gdyvpgriuc
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 119;
	
	  ;% rtB.jty1zsef01
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 122;
	
	  ;% rtB.l4ynfqsuix
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 125;
	
	  ;% rtB.kta3wrejd4
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 128;
	
	  ;% rtB.ajquw4hgfb
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 131;
	
	  ;% rtB.jaerpbqnqm
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 134;
	
	  ;% rtB.p5kqeroffv
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 137;
	
	  ;% rtB.pbw2adbesb
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 138;
	
	  ;% rtB.ab5xgw0342
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 139;
	
	  ;% rtB.ct3c5eoli2
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 140;
	
	  ;% rtB.crik5dobwi
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 141;
	
	  ;% rtB.o1klch4xqt
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 142;
	
	  ;% rtB.f22csweirk
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 151;
	
	  ;% rtB.ctfm1d5uqu
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 160;
	
	  ;% rtB.lqnx4g1go5
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 169;
	
	  ;% rtB.l3eb5r4yyc
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 172;
	
	  ;% rtB.kfrivtgbni
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 173;
	
	  ;% rtB.iloozpnfyr
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 176;
	
	  ;% rtB.lagfvd2ei5
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 179;
	
	  ;% rtB.fyykrlz50p
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 180;
	
	  ;% rtB.ehlhfalizh
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 189;
	
	  ;% rtB.g1xui3hmed
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 198;
	
	  ;% rtB.hdj40uot1u
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 207;
	
	  ;% rtB.a1254pdgfh
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 208;
	
	  ;% rtB.e22yyth3y4
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 217;
	
	  ;% rtB.dhwvhv3uh5
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 226;
	
	  ;% rtB.gutdju0mn5
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 235;
	
	  ;% rtB.fafimnaesx
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 236;
	
	  ;% rtB.ee2go4u05y
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 245;
	
	  ;% rtB.pijgu4gjiu
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 254;
	
	  ;% rtB.cz3ja34zrq
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 263;
	
	  ;% rtB.dfeof1aiqk
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 264;
	
	  ;% rtB.ox2cje3ogi
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 267;
	
	  ;% rtB.cznp4l44bm
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 268;
	
	  ;% rtB.aps03o1u4v
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 277;
	
	  ;% rtB.l2aegg0det
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 278;
	
	  ;% rtB.olx5gr2zcm
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 282;
	
	  ;% rtB.jzubqdhmue
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 283;
	
	  ;% rtB.mupkswka3h
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 284;
	
	  ;% rtB.gnf3ee0yie
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 285;
	
	  ;% rtB.bj3cbec4w1
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 288;
	
	  ;% rtB.p0m1jnhybt
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 291;
	
	  ;% rtB.jbdetydqg0
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 295;
	
	  ;% rtB.ol0ojtxxkn
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 296;
	
	  ;% rtB.ep30hm0x0x
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 297;
	
	  ;% rtB.fpwu5qnsdz
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 300;
	
	  ;% rtB.pirqrlkfn1
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 303;
	
	  ;% rtB.bivwrzak4c
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 306;
	
	  ;% rtB.mdhwvkkkpg
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 307;
	
	  ;% rtB.kknubsmket
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 308;
	
	  ;% rtB.pok3faxosu
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 309;
	
	  ;% rtB.iklax5zz5j
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 310;
	
	  ;% rtB.nx1aqqkpv1
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 314;
	
	  ;% rtB.i1cyqesfho
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 317;
	
	  ;% rtB.e1jmsnwsko
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 318;
	
	  ;% rtB.h2b1u411ed
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 319;
	
	  ;% rtB.ia5lss0zy0
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 320;
	
	  ;% rtB.ps4hnijzog
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 321;
	
	  ;% rtB.juc40yv1j4
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 324;
	
	  ;% rtB.dufe500tdo
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 327;
	
	  ;% rtB.p2vvijwdyj
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 330;
	
	  ;% rtB.jea3ib45lq
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 331;
	
	  ;% rtB.fwdepyepsg
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 332;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 6;
    sectIdxOffset = 1;
    
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
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.m5suqpxty3
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.phocmexnl1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtDW.bknzq3wgub.TimePtr
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hzkxwtgg3y.SignalProbe
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 5;
	
	  ;% rtDW.ethxueuerq.SignalProbe
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtDW.ehpedqcs01.LoggedData
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtDW.p03mfiplmx.LoggedData
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtDW.mohxnwpvy0.SignalProbe
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 9;
	
	  ;% rtDW.fs3xofbgsa.SignalProbe
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 10;
	
	  ;% rtDW.pmtqmlg3ku.LoggedData
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 11;
	
	  ;% rtDW.b1zuzcjxt3.LoggedData
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 12;
	
	  ;% rtDW.iyqxvnatsr.SignalProbe
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 13;
	
	  ;% rtDW.h4jqbncwhd.SignalProbe
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtDW.hu21nqqcni.SignalProbe
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtDW.oawgrr5lku.SignalProbe
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtDW.j2htmj0bku.LoggedData
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rtDW.behvht2jjq.SignalProbe
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtDW.jjiadmicyc.SignalProbe
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtDW.bgsuqbvq3e.SignalProbe
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtDW.m10l43wuz3.SignalProbe
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rtDW.on4t34edga.LoggedData
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rtDW.pnelhmbdiq.LoggedData
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rtDW.af5udyqtv3.LoggedData
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.hvy1dfvqu0
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.k2mw3e5m15
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.fibx4ptf5m.PrevIndex
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.evzrtqyrte.IcNeedsLoading
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 5;
	
	  ;% rtDW.l3ydkkphoy.IcNeedsLoading
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtDW.phnnzeax4q.IcNeedsLoading
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtDW.ibmaa0h4pk
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtDW.o1tdlyssu3
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 11;
	
	  ;% rtDW.hxjtibst42
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 14;
	
	  ;% rtDW.jgvugjcell
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 17;
	
	  ;% rtDW.amy2z0blur
	  section.data(9).logicalSrcIdx = 33;
	  section.data(9).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% rtDW.ks4j0in3rc
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.g1vf00axpm
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.bwuwpskbe1
	  section.data(3).logicalSrcIdx = 36;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.kkm1wjx4mr
	  section.data(4).logicalSrcIdx = 37;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.g325dldung
	  section.data(5).logicalSrcIdx = 38;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.l33pfglk2a
	  section.data(6).logicalSrcIdx = 39;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.lk4bn0tg11
	  section.data(7).logicalSrcIdx = 40;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.awulziwiby
	  section.data(8).logicalSrcIdx = 41;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.mf41bf444w
	  section.data(9).logicalSrcIdx = 42;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.espotkwrxj
	  section.data(10).logicalSrcIdx = 43;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.fw1wxjvjvv
	  section.data(11).logicalSrcIdx = 44;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.huixms4qzu
	  section.data(12).logicalSrcIdx = 45;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.pfcneilmew
	  section.data(13).logicalSrcIdx = 46;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.jamdmknkze
	  section.data(14).logicalSrcIdx = 47;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.pyge1tac5l
	  section.data(15).logicalSrcIdx = 48;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.occ4jhal5v
	  section.data(16).logicalSrcIdx = 49;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.k5kqzwhgid
	  section.data(17).logicalSrcIdx = 50;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.gvkoaih0tt
	  section.data(18).logicalSrcIdx = 51;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.hrkt2hcocj
	  section.data(19).logicalSrcIdx = 52;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.iq1hnty4rc
	  section.data(20).logicalSrcIdx = 53;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.m4c02ikbg1
	  section.data(21).logicalSrcIdx = 54;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.lggvt2ioqm
	  section.data(22).logicalSrcIdx = 55;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.jenrmeyvts
	  section.data(23).logicalSrcIdx = 56;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.lflksa1zm2
	  section.data(24).logicalSrcIdx = 57;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.mo3k54wqkm
	  section.data(25).logicalSrcIdx = 58;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.emy0hrjuzr
	  section.data(26).logicalSrcIdx = 59;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.frxkwgelef
	  section.data(27).logicalSrcIdx = 60;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.bpfxbpnxdk
	  section.data(28).logicalSrcIdx = 61;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.kvbynbt23x
	  section.data(29).logicalSrcIdx = 62;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDW.pzmje2aewl
	  section.data(30).logicalSrcIdx = 63;
	  section.data(30).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.bn411rqyba
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jhekd05k4p
	  section.data(2).logicalSrcIdx = 65;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jrnny2qloo
	  section.data(3).logicalSrcIdx = 66;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.ctt5abpcf5
	  section.data(4).logicalSrcIdx = 67;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.et15tz1dc1
	  section.data(5).logicalSrcIdx = 68;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.a0o3qpslv4
	  section.data(6).logicalSrcIdx = 69;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.krlfahjhyu
	  section.data(7).logicalSrcIdx = 70;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.kuwvje3v02
	  section.data(8).logicalSrcIdx = 71;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
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


  targMap.checksum0 = 2895350130;
  targMap.checksum1 = 186074619;
  targMap.checksum2 = 3193846734;
  targMap.checksum3 = 2883452240;

