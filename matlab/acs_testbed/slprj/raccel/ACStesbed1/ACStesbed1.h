#include "__cf_ACStesbed1.h"
#ifndef RTW_HEADER_ACStesbed1_h_
#define RTW_HEADER_ACStesbed1_h_
#ifndef ACStesbed1_COMMON_INCLUDES_
#define ACStesbed1_COMMON_INCLUDES_
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "ACStesbed1_types.h"
#define MODEL_NAME ACStesbed1
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (102) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (20)   
#elif NCSTATES != 20
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (NULL)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif
typedef struct { real_T njvqg5q4aw [ 3 ] ; real_T jmiuxj1x02 [ 3 ] ; real_T
pdvhflqrm1 ; real_T mtdbzc3klf [ 3 ] ; real_T e2xzeznz0p [ 3 ] ; real_T
fnbs1jnt55 [ 3 ] ; real_T pnzjj5cy3t ; real_T o3hbrpucbz [ 3 ] ; real_T
hqqy53kfyu [ 4 ] ; real_T awz2s5os2f ; real_T ber5tetftf [ 4 ] ; real_T
cjc4bi0q0l [ 4 ] ; real_T j55ahl4b2c ; real_T mbcfnz4gfg ; real_T j4celd1eit
; real_T bwyuqwyvcb ; real_T fz0figaoto [ 4 ] ; real_T ihj3tr11iv [ 9 ] ;
real_T n1iqi5rfxp [ 3 ] ; real_T lronvhy5ya [ 3 ] ; real_T m0g2rkinvl [ 3 ] ;
real_T o5eruvbnew [ 3 ] ; real_T kwssbn0ne4 [ 3 ] ; real_T kcl5mw42rb [ 3 ] ;
real_T p05flgh0s0 [ 3 ] ; real_T neym5ecad1 [ 3 ] ; real_T obj5e4e3db [ 3 ] ;
real_T h5ipoluxjw [ 3 ] ; real_T klwhzltza0 [ 3 ] ; real_T ixebsztwtv [ 3 ] ;
real_T fwgif0j4xy [ 3 ] ; real_T dbwyygj2mo [ 3 ] ; real_T nye0gvpgkn [ 3 ] ;
real_T iooczl3zbj [ 9 ] ; real_T gcm3v00fw3 [ 3 ] ; real_T bilokkqatz [ 3 ] ;
real_T p4tfma3j1a [ 3 ] ; real_T brbbovdl2o [ 3 ] ; real_T e2dsphxszg [ 3 ] ;
real_T gdyvpgriuc [ 3 ] ; real_T jty1zsef01 [ 3 ] ; real_T l4ynfqsuix [ 3 ] ;
real_T kta3wrejd4 [ 3 ] ; real_T ajquw4hgfb [ 3 ] ; real_T jaerpbqnqm [ 3 ] ;
real_T p5kqeroffv ; real_T pbw2adbesb ; real_T ab5xgw0342 ; real_T ct3c5eoli2
; real_T crik5dobwi ; real_T o1klch4xqt [ 9 ] ; real_T f22csweirk [ 9 ] ;
real_T ctfm1d5uqu [ 9 ] ; real_T lqnx4g1go5 [ 3 ] ; real_T l3eb5r4yyc ;
real_T kfrivtgbni [ 3 ] ; real_T iloozpnfyr [ 3 ] ; real_T lagfvd2ei5 ;
real_T fyykrlz50p [ 9 ] ; real_T ehlhfalizh [ 9 ] ; real_T g1xui3hmed [ 9 ] ;
real_T hdj40uot1u ; real_T a1254pdgfh [ 9 ] ; real_T e22yyth3y4 [ 9 ] ;
real_T dhwvhv3uh5 [ 9 ] ; real_T gutdju0mn5 ; real_T fafimnaesx [ 9 ] ;
real_T ee2go4u05y [ 9 ] ; real_T pijgu4gjiu [ 9 ] ; real_T cz3ja34zrq ;
real_T dfeof1aiqk [ 3 ] ; real_T ox2cje3ogi ; real_T cznp4l44bm [ 9 ] ;
real_T aps03o1u4v ; real_T l2aegg0det [ 4 ] ; real_T olx5gr2zcm ; real_T
jzubqdhmue ; real_T mupkswka3h ; real_T gnf3ee0yie [ 3 ] ; real_T bj3cbec4w1
[ 3 ] ; real_T p0m1jnhybt [ 4 ] ; real_T jbdetydqg0 ; real_T ol0ojtxxkn ;
real_T ep30hm0x0x [ 3 ] ; real_T fpwu5qnsdz [ 3 ] ; real_T pirqrlkfn1 [ 3 ] ;
real_T bivwrzak4c ; real_T mdhwvkkkpg ; real_T kknubsmket ; real_T pok3faxosu
; real_T iklax5zz5j [ 4 ] ; real_T nx1aqqkpv1 [ 3 ] ; real_T i1cyqesfho ;
real_T e1jmsnwsko ; real_T h2b1u411ed ; real_T ia5lss0zy0 ; real_T ps4hnijzog
[ 3 ] ; real_T juc40yv1j4 [ 3 ] ; real_T dufe500tdo [ 3 ] ; real_T p2vvijwdyj
; real_T jea3ib45lq ; real_T fwdepyepsg ; } B ; typedef struct { real_T
m5suqpxty3 ; real_T phocmexnl1 ; struct { void * TimePtr [ 5 ] ; void *
DataPtr [ 5 ] ; void * RSimInfoPtr [ 5 ] ; } bknzq3wgub ; struct { void *
SignalProbe ; } hzkxwtgg3y ; struct { void * SignalProbe ; } ethxueuerq ;
struct { void * LoggedData ; } ehpedqcs01 ; struct { void * LoggedData ; }
p03mfiplmx ; struct { void * SignalProbe ; } mohxnwpvy0 ; struct { void *
SignalProbe ; } fs3xofbgsa ; struct { void * LoggedData ; } pmtqmlg3ku ;
struct { void * LoggedData ; } b1zuzcjxt3 ; struct { void * SignalProbe ; }
iyqxvnatsr ; struct { void * SignalProbe ; } h4jqbncwhd ; struct { void *
SignalProbe ; } hu21nqqcni ; struct { void * SignalProbe ; } oawgrr5lku ;
struct { void * LoggedData ; } j2htmj0bku ; struct { void * SignalProbe ; }
behvht2jjq ; struct { void * SignalProbe ; } jjiadmicyc ; struct { void *
SignalProbe ; } bgsuqbvq3e ; struct { void * SignalProbe ; } m10l43wuz3 ;
struct { void * LoggedData ; } on4t34edga ; struct { void * LoggedData ; }
pnelhmbdiq ; struct { void * LoggedData ; } af5udyqtv3 ; uint32_T hvy1dfvqu0
; uint32_T k2mw3e5m15 ; struct { int_T PrevIndex [ 5 ] ; } fibx4ptf5m ;
struct { int_T IcNeedsLoading ; } evzrtqyrte ; struct { int_T IcNeedsLoading
; } l3ydkkphoy ; struct { int_T IcNeedsLoading ; } phnnzeax4q ; int_T
ibmaa0h4pk [ 3 ] ; int_T o1tdlyssu3 [ 3 ] ; int_T hxjtibst42 [ 3 ] ; int_T
jgvugjcell [ 3 ] ; int_T amy2z0blur ; int8_T ks4j0in3rc ; int8_T g1vf00axpm ;
int8_T bwuwpskbe1 ; int8_T kkm1wjx4mr ; int8_T g325dldung ; int8_T l33pfglk2a
; int8_T lk4bn0tg11 ; int8_T awulziwiby ; int8_T mf41bf444w ; int8_T
espotkwrxj ; int8_T fw1wxjvjvv ; int8_T huixms4qzu ; int8_T pfcneilmew ;
int8_T jamdmknkze ; int8_T pyge1tac5l ; int8_T occ4jhal5v ; int8_T k5kqzwhgid
; int8_T gvkoaih0tt ; int8_T hrkt2hcocj ; int8_T iq1hnty4rc ; int8_T
m4c02ikbg1 ; int8_T lggvt2ioqm ; int8_T jenrmeyvts ; int8_T lflksa1zm2 ;
int8_T mo3k54wqkm ; int8_T emy0hrjuzr ; int8_T frxkwgelef ; int8_T bpfxbpnxdk
; int8_T kvbynbt23x ; int8_T pzmje2aewl ; boolean_T bn411rqyba ; boolean_T
jhekd05k4p ; boolean_T jrnny2qloo ; boolean_T ctt5abpcf5 ; boolean_T
et15tz1dc1 ; boolean_T a0o3qpslv4 ; boolean_T krlfahjhyu ; boolean_T
kuwvje3v02 ; } DW ; typedef struct { real_T b1lr14rcuj [ 4 ] ; real_T
ba1rjb3ky4 [ 3 ] ; real_T hod35jdtrz [ 3 ] ; real_T al32ndubg1 [ 3 ] ; real_T
abpf02yfny [ 3 ] ; real_T gffjebdga3 [ 4 ] ; } X ; typedef struct { real_T
b1lr14rcuj [ 4 ] ; real_T ba1rjb3ky4 [ 3 ] ; real_T hod35jdtrz [ 3 ] ; real_T
al32ndubg1 [ 3 ] ; real_T abpf02yfny [ 3 ] ; real_T gffjebdga3 [ 4 ] ; } XDot
; typedef struct { boolean_T b1lr14rcuj [ 4 ] ; boolean_T ba1rjb3ky4 [ 3 ] ;
boolean_T hod35jdtrz [ 3 ] ; boolean_T al32ndubg1 [ 3 ] ; boolean_T
abpf02yfny [ 3 ] ; boolean_T gffjebdga3 [ 4 ] ; } XDis ; typedef struct {
real_T b1lr14rcuj [ 4 ] ; real_T ba1rjb3ky4 [ 3 ] ; real_T hod35jdtrz [ 3 ] ;
real_T al32ndubg1 [ 3 ] ; real_T abpf02yfny [ 3 ] ; real_T gffjebdga3 [ 4 ] ;
} CStateAbsTol ; typedef struct { real_T jdg5fgght1 ; real_T l3y1u5obwt [ 3 ]
; real_T nasw0mlmjm [ 3 ] ; real_T of1glfyyn3 [ 3 ] ; real_T fqt0mvrdyk [ 3 ]
; real_T o3jzv1jvx5 [ 3 ] ; real_T nl0q2bqjk2 [ 3 ] ; real_T conutdf0a1 ;
real_T on4aexigh0 ; real_T jvmb2fyiro ; real_T c1rvp53ssv ; real_T msqpbrzbho
[ 3 ] ; real_T lkeql2wcuq [ 3 ] ; real_T l2ciyo4le3 ; real_T oysbzpsleq ;
real_T p41xajlv1g [ 2 ] ; real_T dduw5qfbkp ; real_T g50xs5r3vz ; real_T
bwrmhxxylm ; } ZCV ; typedef struct { ZCSigState jij3bxd0sr ; ZCSigState
mgseyeedyp [ 3 ] ; ZCSigState klnxthafhv [ 3 ] ; ZCSigState l0b4y5ywr4 [ 3 ]
; ZCSigState g0p2gjqoaw [ 3 ] ; ZCSigState i0ykjiswph [ 3 ] ; ZCSigState
dwpzks2y0i [ 3 ] ; ZCSigState gl1h5qphdb ; ZCSigState lv3cwkzogi ; ZCSigState
f5z4jxh4zc ; ZCSigState l5pzboqmk1 ; ZCSigState l4p2lv1tlb [ 3 ] ; ZCSigState
kf5elx30y5 [ 3 ] ; ZCSigState pad4jm2c10 ; ZCSigState m2zxdm0kun ; ZCSigState
chuc5rqigq [ 2 ] ; ZCSigState l4koostimi ; ZCSigState pj4lsjd341 ; ZCSigState
o2gclvesp4 ; } PrevZCX ; struct P_ { real_T Constant_Value ; real_T Gain_Gain
; real_T Gain1_Gain ; real_T Constant2_Value [ 2 ] ; real_T Constant1_Value ;
real_T Constant_Value_itf12sgtld ; real_T Gain_Gain_iz22fd4qci ; real_T
Gain1_Gain_grzyqbqehm ; real_T Gain3_Gain ; real_T Gain4_Gain ; real_T
Constant2_Value_jxofe5s4po [ 2 ] ; real_T Constant1_Value_odsqffacyt ; real_T
Constant_Value_gaw1lrkj5p ; real_T Gain_Gain_oxcvfncqox ; real_T
Gain1_Gain_bmy2by4h1w ; real_T Gain2_Gain ; real_T Gain3_Gain_pjvn2rjs3s ;
real_T Constant2_Value_jw5vkxzlyu [ 2 ] ; real_T Constant1_Value_joyqlwe5wz ;
real_T Constant_Value_pnagrbecg0 ; real_T Gain_Gain_pkrlyfmnay ; real_T
Gain1_Gain_co11ew42wt ; real_T Gain2_Gain_dbcigpbpah ; real_T
Gain3_Gain_keytyfb2hv ; real_T Constant_Value_bxenkd0bbl ; real_T
Constant_Value_h3j41jz2o2 ; real_T Constant1_Value_gxe1evpehu ; real_T
Constant_Value_eabu3cwr2x ; real_T Constant1_Value_chkyuiwcbu ; real_T
Constant_Value_lkzxmgm0bn ; real_T Constant_Value_jjhmxiynvf ; real_T
Gain_Gain_gq1q0o0dgd ; real_T Gain1_Gain_gwhqm0umwh ; real_T
Constant_Value_bqgjtgwncf ; real_T Gain_Gain_gqxkss2f4q ; real_T
Constant1_Value_e2tnprjcds ; real_T Constant2_Value_ox4kgnjx1u [ 2 ] ; real_T
Gain1_Gain_plbazqymln ; real_T Gain3_Gain_lnfk34izw1 ; real_T
Gain4_Gain_frwaasjnjn ; real_T Constant_Value_pc3s5n5ig0 ; real_T
Gain_Gain_g0crcybw52 ; real_T Constant1_Value_pvid3jlafh ; real_T
Constant2_Value_bgmtgxyswg [ 2 ] ; real_T Gain1_Gain_cmjmtszzlh ; real_T
Gain2_Gain_lbyqu50w0f ; real_T Gain3_Gain_fjdyxqygiq ; real_T
Constant_Value_elm2slanqm ; real_T Gain_Gain_ocfwspzgot ; real_T
Constant1_Value_cf4j34iv2x ; real_T Constant2_Value_pt2pqq3qma [ 2 ] ; real_T
Gain1_Gain_dvdkv5tz32 ; real_T Gain2_Gain_atvqpareya ; real_T
Gain3_Gain_clfc33gypf ; real_T Constant4_Value [ 30 ] ; real_T
Constant_Value_ok5wcdghto ; real_T FromWorkspace_Time0 [ 980 ] ; real_T
FromWorkspace_Data0 [ 2940 ] ; real_T FromWorkspace_Time1 [ 980 ] ; real_T
FromWorkspace_Data1 [ 2940 ] ; real_T FromWorkspace_Time2 [ 980 ] ; real_T
FromWorkspace_Data2 [ 2940 ] ; real_T FromWorkspace_Time3 [ 980 ] ; real_T
FromWorkspace_Data3 [ 2940 ] ; real_T FromWorkspace_Time4 [ 980 ] ; real_T
FromWorkspace_Data4 [ 2940 ] ; real_T Noise_Value [ 3 ] ; real_T
Switch_Threshold ; real_T Noise1_Value [ 3 ] ; real_T
Switch_Threshold_gdocqrc4t2 ; real_T Merge_InitialOutput [ 4 ] ; real_T
Switch_Threshold_cstc3foesz ; real_T Qjo_init_Value [ 4 ] ; real_T
Qob_init_Value [ 4 ] ; real_T Switch_Threshold_cnjrei0kod ; real_T
Constant1_Value_nmcgqsupce ; real_T Switch_Threshold_l3zqxo5bwe ; real_T
Constant_Value_jd4yybwihf ; real_T Constant_Value_gvhcouy2li [ 9 ] ; real_T
Constant_Value_egr1tn4q2z [ 9 ] ; real_T Constant_Value_jrc3i5y0a4 [ 3 ] ;
real_T Integrator_IC ; real_T WhiteNoise_Mean ; real_T WhiteNoise_StdDev ;
real_T WhiteNoise_Seed ; real_T Output_Gain [ 3 ] ; real_T
Gain_Gain_imjwpylc20 ; real_T Constant_Value_gfamwgvgio ; real_T
Gain2_Gain_hsczlo4ztj ; real_T Gain_Gain_mwczkktdza ; real_T
Gain1_Gain_jcffkkjw2g ; real_T Gain_Gain_keh1ebxthv ; real_T
Constant_Value_alyo2kghso ; real_T Gain2_Gain_bnubngmvnh ; real_T
Gain1_Gain_kck2izenjg ; real_T Gain_Gain_m1esafctux ; real_T
Gain1_Gain_gpeez3rcld ; real_T Constant_Value_jrgvdhmfe2 ; real_T
Gain2_Gain_nv4m22xdcw ; real_T ChangeMe_Value [ 3 ] ; real_T
Gain1_Gain_cz2xpyyxre ; real_T Constant1_Value_pibyfcp5ht [ 3 ] ; real_T
IntegratorLimited_IC ; real_T IntegratorLimited_UpperSat ; real_T
IntegratorLimited_LowerSat ; real_T Gain2_Gain_g3pgvavbec ; real_T
Constant2_Value_erhep10kxc [ 3 ] ; real_T Gain3_Gain_nlnczbyk1z ; real_T
Constant3_Value [ 3 ] ; real_T Gain4_Gain_obkdmqncg2 ; real_T Gain6_Gain ;
real_T Constant1_Value_fciw0lu1dl ; real_T Constant3_Value_cxfy0sjqiz ;
real_T Gain_Gain_fzpdiqcchq ; real_T ChangeMe3_Value [ 9 ] ; real_T Kang_Gain
; real_T Krate_Gain ; real_T ChangeMe1_Value [ 9 ] ; real_T ChangeMe2_Value [
3 ] ; real_T Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
IntegratorLimited_IC_fejwzsem04 [ 3 ] ; real_T
IntegratorLimited_UpperSat_ntkxmpf0qj ; real_T
IntegratorLimited_LowerSat_oacseuhnry ; real_T Gain1_Gain_dkf041qpaw ; real_T
Saturation_UpperSat_faael1sbi5 ; real_T Saturation_LowerSat_agytdqopmw ;
real_T Constant3_Value_lg1rqkvsmt ; real_T Constant_Value_csl0xc4ep4 ; real_T
Constant1_Value_d0nljg3n4k ; real_T Switch_Threshold_ocvrgqhwfd ; real_T
Constant_Value_egwar5iee0 ; real_T HighGainQuaternionNormalization_Gain ;
real_T Constant3_Value_oayr5juvkv ; real_T Gain8_Gain ; real_T
Gain6_Gain_lwc3ps4rex ; real_T Gain7_Gain ; real_T a_Value ; real_T
Gain5_Gain ; real_T Constant1_Value_de0q5adpcb [ 9 ] ; real_T
Constant_Value_bw3vkbj2eu ; real_T Gain_Gain_av3hfhcgyv ; real_T
Constant_Value_bin4grumgj ; real_T Constant2_Value_jf2fosnw3b [ 3 ] ; real_T
Gain_Gain_mbuijwi5jm ; real_T Constant_Value_jgjdenbdkp ; real_T
Constant5_Value [ 3 ] ; real_T Gain_Gain_hsvk1ppevl ; real_T
Constant_Value_dlgbgdxgmn ; real_T Gain_Gain_dxvjzvgyer ; real_T
Constant_Value_p2yj2qsewh ; real_T Constant3_Value_fjjscdcrzj [ 3 ] ; real_T
Gain_Gain_e42rl13cmn ; real_T Constant_Value_fn2jvveflf ; real_T
Constant6_Value [ 3 ] ; real_T Gain_Gain_eiuk4co0u1 ; real_T
Constant_Value_pnej1bop5b ; real_T Gain_Gain_ikyjnkugqm ; real_T
Constant_Value_irpm3cwjza ; real_T Constant4_Value_arg3ksqg5d [ 3 ] ; real_T
Gain_Gain_nogset3ro3 ; real_T Constant_Value_aecujgzxyb ; real_T
Constant7_Value [ 3 ] ; real_T Gain_Gain_ocowllqul3 ; real_T
Constant_Value_e4va2nj2ny [ 9 ] ; real_T Constant_Value_hh2kih5qyy ; real_T
Switch_Threshold_dkimt1f1tz ; real_T Constant_Value_hgpikmmnsj ; real_T
Switch_Threshold_gnlntr1le3 ; real_T Merge_InitialOutput_poz11gcqai [ 4 ] ;
real_T Gain_Gain_mpiyuuuwgr ; real_T Saturation_UpperSat_hafkqiwfxz ; real_T
Saturation_LowerSat_jlais4nb4c ; real_T Constant_Value_o4e4fo4gkj [ 3 ] ;
real_T Constant1_Value_fg2gdmjirg [ 4 ] ; real_T Constant_Value_ej4q1vwpv0 ;
real_T Gain2_Gain_f1yzxme32r ; real_T Gain_Gain_itterqoc4x ; real_T
Gain1_Gain_ofwpfqh4qc ; real_T Gain_Gain_jfem1ifujv ; real_T
Constant_Value_d4om0ngdo1 ; real_T Gain2_Gain_lanpf0cnyt ; real_T
Gain1_Gain_o3l0m0cqsz ; real_T Gain_Gain_kbkv433xum ; real_T
Gain1_Gain_aw5xkpj1cf ; real_T Constant_Value_pbdti2yadl ; real_T
Gain2_Gain_oat3nps3gi ; real_T Gain5_Gain_fzoolgsndi ; real_T
Constant_Value_fjgr21kt5s ; real_T
HighGainQuaternionNormalization_Gain_ob3hm0wdis ; real_T
WhiteNoise_Mean_fpnv13epd5 ; real_T WhiteNoise_StdDev_esrovvidoo ; real_T
WhiteNoise_Seed_kw4ej5243j ; real_T Output_Gain_ba0gpqdttx [ 3 ] ; real_T
Gain_Gain_ovaf4mtkfv ; real_T Constant_Value_ez3apkr1wy ; real_T
Constant_Value_nt3nodlo0n ; real_T Gain2_Gain_b455g1loe1 ; real_T
Gain_Gain_pxe1qwiizn ; real_T Gain1_Gain_huu1lmrels ; real_T
Gain_Gain_j0vyy2fy2r ; real_T Constant_Value_jy4gaazlnd ; real_T
Gain2_Gain_bujbdfke15 ; real_T Gain1_Gain_fkwqudcabt ; real_T
Gain_Gain_bigflic040 ; real_T Gain1_Gain_hfanpouy13 ; real_T
Constant_Value_mctqlak3ab ; real_T Gain2_Gain_o4dc4ko20g ; real_T
Switch_Threshold_jv24xn0sxc ; } ; extern P rtP ; extern const BusObject
ACStesbed1_rtZBusObject ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern PrevZCX rtPrevZCX ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ;
#endif
