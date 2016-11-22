#include "__cf_ACStesbed.h"
#ifndef RTW_HEADER_ACStesbed_h_
#define RTW_HEADER_ACStesbed_h_
#ifndef ACStesbed_COMMON_INCLUDES_
#define ACStesbed_COMMON_INCLUDES_
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
#include "dspsvd_rt.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "ACStesbed_types.h"
#define MODEL_NAME ACStesbed
#define NSAMPLE_TIMES (6) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (201) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (30)   
#elif NCSTATES != 30
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (NULL)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif
typedef struct { int8_T espotkwrxj ; int8_T lggvt2ioqm ; } dmxskfrz2h ;
typedef struct { real_T p2vvijwdyj ; real_T jea3ib45lq ; real_T fwdepyepsg ;
} ppxmmlhmiq ; typedef struct { int8_T fw1wxjvjvv ; int8_T pyge1tac5l ;
int8_T occ4jhal5v ; int8_T k5kqzwhgid ; int8_T gvkoaih0tt ; int8_T hrkt2hcocj
; int8_T iq1hnty4rc ; int8_T m4c02ikbg1 ; boolean_T a0o3qpslv4 ; boolean_T
krlfahjhyu ; boolean_T kuwvje3v02 ; } h4iasb5pte ; typedef struct { real_T
p41xajlv1g [ 2 ] ; real_T dduw5qfbkp ; real_T g50xs5r3vz ; real_T bwrmhxxylm
; } p4bsjadjac ; typedef struct { ZCSigState chuc5rqigq [ 2 ] ; ZCSigState
l4koostimi ; ZCSigState pj4lsjd341 ; ZCSigState o2gclvesp4 ; } fnlt43lw0a ;
typedef struct { real_T njvqg5q4aw [ 3 ] ; real_T jmiuxj1x02 [ 3 ] ; real_T
pdvhflqrm1 ; real_T mtdbzc3klf [ 3 ] ; real_T oducdqkgjs [ 3 ] ; real_T
e2xzeznz0p [ 3 ] ; real_T fnbs1jnt55 [ 3 ] ; real_T pnzjj5cy3t ; real_T
o3hbrpucbz [ 3 ] ; real_T dwojgwe1xs [ 3 ] ; real_T afwtugkazt [ 3 ] ; real_T
hqqy53kfyu [ 4 ] ; real_T awz2s5os2f ; real_T ber5tetftf [ 4 ] ; real_T
cjc4bi0q0l [ 4 ] ; real_T j55ahl4b2c ; real_T mbcfnz4gfg ; real_T j4celd1eit
; real_T bwyuqwyvcb ; real_T fz0figaoto [ 4 ] ; real_T iooczl3zbj [ 9 ] ;
real_T ihj3tr11iv [ 9 ] ; real_T n1iqi5rfxp [ 3 ] ; real_T lronvhy5ya [ 3 ] ;
real_T m0g2rkinvl [ 3 ] ; real_T o5eruvbnew [ 3 ] ; real_T kwssbn0ne4 [ 3 ] ;
real_T jx00cruu0k [ 3 ] ; real_T lcvceh3hv3 [ 3 ] ; real_T nfbfh1ljmc [ 3 ] ;
real_T e14rgshsrb [ 3 ] ; real_T kfrkptukdf [ 3 ] ; real_T kta3wrejd4 [ 3 ] ;
real_T gcm3v00fw3 [ 3 ] ; real_T bilokkqatz [ 3 ] ; real_T kcl5mw42rb [ 3 ] ;
real_T p05flgh0s0 [ 3 ] ; real_T p4tfma3j1a [ 3 ] ; real_T brbbovdl2o [ 3 ] ;
real_T e2dsphxszg [ 3 ] ; real_T gdyvpgriuc [ 3 ] ; real_T jty1zsef01 [ 3 ] ;
real_T l4ynfqsuix [ 3 ] ; real_T ajquw4hgfb [ 3 ] ; real_T piiwfosis5 [ 3 ] ;
real_T golhlydrqf [ 18 ] ; real_T bz3arzyxmq [ 3 ] ; real_T c0wivtryvw [ 18 ]
; real_T bqng0z1mqz [ 18 ] ; real_T ajml5jquws [ 9 ] ; real_T nowaxdrerk [ 27
] ; real_T cd1svnc4xn [ 27 ] ; real_T nye3sr1z21 [ 3 ] ; real_T hvzm4sux2r [
3 ] ; real_T gdzioetcaj [ 9 ] ; real_T p5kqeroffv [ 3 ] ; real_T pbw2adbesb ;
real_T ab5xgw0342 ; real_T ct3c5eoli2 ; real_T crik5dobwi ; real_T o1klch4xqt
[ 9 ] ; real_T f22csweirk [ 9 ] ; real_T ctfm1d5uqu [ 9 ] ; real_T lqnx4g1go5
[ 3 ] ; real_T l3eb5r4yyc ; real_T kfrivtgbni [ 3 ] ; real_T iloozpnfyr [ 3 ]
; real_T lagfvd2ei5 ; real_T fyykrlz50p [ 9 ] ; real_T ehlhfalizh [ 9 ] ;
real_T g1xui3hmed [ 9 ] ; real_T hdj40uot1u ; real_T a1254pdgfh [ 9 ] ;
real_T e22yyth3y4 [ 9 ] ; real_T dhwvhv3uh5 [ 9 ] ; real_T gutdju0mn5 ;
real_T fafimnaesx [ 9 ] ; real_T ee2go4u05y [ 9 ] ; real_T pijgu4gjiu [ 9 ] ;
real_T cz3ja34zrq ; real_T dfeof1aiqk [ 3 ] ; real_T ox2cje3ogi ; real_T
cznp4l44bm [ 9 ] ; real_T aps03o1u4v ; real_T l2aegg0det [ 4 ] ; real_T
olx5gr2zcm ; real_T jzubqdhmue ; real_T mupkswka3h ; real_T gnf3ee0yie [ 3 ]
; real_T bj3cbec4w1 [ 3 ] ; real_T p0m1jnhybt [ 4 ] ; real_T jbdetydqg0 ;
real_T ol0ojtxxkn ; real_T neym5ecad1 [ 3 ] ; real_T h5ipoluxjw [ 3 ] ;
real_T klwhzltza0 [ 3 ] ; real_T ixebsztwtv [ 3 ] ; real_T fwgif0j4xy [ 3 ] ;
real_T ep30hm0x0x [ 3 ] ; real_T fpwu5qnsdz [ 3 ] ; real_T pirqrlkfn1 [ 3 ] ;
real_T bivwrzak4c ; real_T mdhwvkkkpg ; real_T kknubsmket ; real_T pok3faxosu
; real_T iklax5zz5j [ 4 ] ; real_T dbwyygj2mo [ 3 ] ; real_T nx1aqqkpv1 [ 3 ]
; real_T i1cyqesfho ; real_T e1jmsnwsko ; real_T h2b1u411ed ; real_T
ia5lss0zy0 ; real_T hfr3g5fo5z [ 3 ] ; real_T c3goefzgk3 [ 3 ] ; real_T
l4ag020lhf [ 3 ] ; real_T lkkogows30i [ 3 ] ; real_T bu0zd3hop0 ; real_T
eqdklum1kz [ 3 ] ; real_T aff2guamhh [ 3 ] ; real_T eaiuep244b ; real_T
hzwurxk4ri [ 3 ] ; real_T iex2hnoztb [ 3 ] ; real_T naewu0mfbx [ 9 ] ; real_T
g2zpeh00jx ; real_T elhnkqcp4v [ 4 ] ; real_T mt30lpgnlb [ 4 ] ; real_T
enst2mfa5p [ 4 ] ; real_T iugw0131dq ; real_T j2s0rzuesy [ 4 ] ; real_T
b01symif3z [ 3 ] ; real_T k4n51klhzm [ 3 ] ; real_T cy0g41je3i [ 3 ] ; real_T
nxenwlnc5v [ 3 ] ; real_T kasev2hfro [ 3 ] ; real_T oxns51znjb [ 3 ] ; real_T
cxydpocexq [ 3 ] ; real_T eek0a0qnzz [ 3 ] ; real_T dc1j3uzyrw [ 3 ] ; real_T
knm4o3kbgk [ 3 ] ; real_T gxs3gozf4z [ 3 ] ; real_T cz1nz0dwmw [ 18 ] ;
real_T i3r4txwmvn [ 3 ] ; real_T jnibcpqu24 [ 18 ] ; real_T j3qp0rot4z [ 18 ]
; real_T bv5rymkkje [ 9 ] ; real_T afjv1quvm5 [ 27 ] ; real_T kizx1ijhue [ 27
] ; real_T nif420hiph [ 3 ] ; real_T d2ywubqjk2 [ 3 ] ; real_T gzh1neeoux [ 9
] ; real_T auwd4r4mkz [ 3 ] ; real_T ckqhlb32gd ; real_T leq1llgjf0 ; real_T
jmzzln4ohz ; real_T htxixjme3q ; real_T becyljpaab [ 9 ] ; real_T mzppckyb2r
[ 9 ] ; real_T kbnlvlyzzj [ 9 ] ; real_T b5lvehq0lb [ 3 ] ; real_T lssfrykd20
; real_T c1g3rp4u4f [ 3 ] ; real_T iezlupw440 [ 3 ] ; real_T flsiozqty3 ;
real_T oras35y0me [ 9 ] ; real_T jczx5mmtny [ 9 ] ; real_T py34oc2tac [ 9 ] ;
real_T ldef0mrlxf ; real_T fqa1obuxcx [ 9 ] ; real_T jp33z3cm2q [ 9 ] ;
real_T lna01hcwqs [ 9 ] ; real_T af0aib4ixg ; real_T artk3v2gtx [ 9 ] ;
real_T fylvlnipqh [ 9 ] ; real_T dnccwxtqix [ 9 ] ; real_T a5hluyc4z4 ;
real_T po2fokcy2h [ 3 ] ; real_T hwft0ux5xv ; real_T keil2t0ysq [ 9 ] ;
real_T ffoa23fpkv ; real_T e2ozyjspf1 [ 4 ] ; real_T goqp2hsxiw [ 3 ] ;
real_T h04s5dfqra [ 3 ] ; real_T c2bqn2vvuz [ 3 ] ; real_T f3f3ebtfsq [ 3 ] ;
real_T n0xo0shoih [ 3 ] ; real_T bkwjtfsi54 [ 3 ] ; real_T fc4jnd0tfk [ 3 ] ;
real_T bqyj10kjri [ 3 ] ; real_T md555povbw [ 3 ] ; real_T ps4hnijzog [ 3 ] ;
real_T juc40yv1j4 [ 3 ] ; real_T dufe500tdo [ 3 ] ; ppxmmlhmiq jtgflhe3su ;
ppxmmlhmiq iry0wsg2k5 ; ppxmmlhmiq azz3d4nxcem ; } B ; typedef struct {
real_T h1cj2y3ic5 [ 3 ] ; real_T loaxlm1yp2 [ 18 ] ; real_T g5fe22mv15 [ 9 ]
; real_T i5firivfli [ 3 ] ; real_T gj2ukru0nb [ 18 ] ; real_T jbnlmtknpk [ 9
] ; real_T olom3dwhnc [ 3 ] ; real_T m5suqpxty3 ; real_T phocmexnl1 ; struct
{ void * TimePtr [ 5 ] ; void * DataPtr [ 5 ] ; void * RSimInfoPtr [ 5 ] ; }
bknzq3wgub ; struct { void * SignalProbe ; } hzkxwtgg3y ; struct { void *
SignalProbe ; } ethxueuerq ; struct { void * LoggedData ; } ehpedqcs01 ;
struct { void * LoggedData ; } j12o25heky ; struct { void * SignalProbe ; }
mohxnwpvy0 ; struct { void * SignalProbe ; } fs3xofbgsa ; struct { void *
LoggedData ; } pmtqmlg3ku ; struct { void * LoggedData ; } b1zuzcjxt3 ;
struct { void * SignalProbe ; } iyqxvnatsr ; struct { void * SignalProbe ; }
h4jqbncwhd ; struct { void * SignalProbe ; } hu21nqqcni ; struct { void *
SignalProbe ; } oawgrr5lku ; struct { void * LoggedData ; } j2htmj0bku ;
struct { void * SignalProbe ; } behvht2jjq ; struct { void * SignalProbe ; }
jjiadmicyc ; struct { void * SignalProbe ; } bgsuqbvq3e ; struct { void *
SignalProbe ; } m10l43wuz3 ; struct { void * LoggedData ; } i013afts1o ;
struct { void * LoggedData ; } pnelhmbdiq ; struct { void * SignalProbe ; }
hzkxwtgg3yv ; struct { void * SignalProbe ; } ethxueuerq5 ; struct { void *
TimePtr [ 5 ] ; void * DataPtr [ 5 ] ; void * RSimInfoPtr [ 5 ] ; }
hqwrc0ipzd ; struct { void * LoggedData ; } pmws4cv3vf ; struct { void *
LoggedData ; } ljepzqod3x ; struct { void * SignalProbe ; } mohxnwpvy0k ;
struct { void * SignalProbe ; } fs3xofbgsah ; struct { void * LoggedData ; }
hqqwk24acd ; struct { void * LoggedData ; } cendn5ypmp ; struct { void *
SignalProbe ; } iyqxvnatsrh ; struct { void * SignalProbe ; } h4jqbncwhda ;
struct { void * SignalProbe ; } hu21nqqcnih ; struct { void * LoggedData ; }
af5udyqtv3 ; uint32_T hvy1dfvqu0 ; uint32_T k2mw3e5m15 ; struct { int_T
PrevIndex [ 5 ] ; } fibx4ptf5m ; struct { int_T IcNeedsLoading ; } evzrtqyrte
; struct { int_T IcNeedsLoading ; } l3ydkkphoy ; struct { int_T
IcNeedsLoading ; } phnnzeax4q ; struct { int_T PrevIndex [ 5 ] ; } nrfurckayn
; struct { int_T IcNeedsLoading ; } g0vm4fxb3p ; int_T f0rotw3bar [ 3 ] ;
int_T hxjtibst42 [ 3 ] ; int_T o1tdlyssu3 [ 3 ] ; int_T jgvugjcell [ 3 ] ;
int_T amy2z0blur ; int_T kazdxyylc3 [ 3 ] ; int_T pynovrdqcu [ 3 ] ; int_T
l2ulz1zonw [ 3 ] ; int_T jk3cciiee0 [ 3 ] ; int8_T ks4j0in3rc ; int8_T
g1vf00axpm ; int8_T bwuwpskbe1 ; int8_T kkm1wjx4mr ; int8_T g325dldung ;
int8_T ftycguxnii ; int8_T l33pfglk2a ; int8_T fy4uwny3eb ; int8_T lk4bn0tg11
; int8_T awulziwiby ; int8_T mf41bf444w ; int8_T huixms4qzu ; int8_T
pfcneilmew ; int8_T jamdmknkze ; int8_T ly50w4j0zu ; int8_T krtnuqdnk0 ;
int8_T nrel2zbbl0 ; int8_T ej43nvwcyh ; int8_T oxif3bzbeo ; int8_T ms3ry1pdxh
; int8_T j3jyokwsdh ; int8_T lqwl4atrcd ; int8_T jenrmeyvts ; int8_T
lflksa1zm2 ; int8_T mo3k54wqkm ; int8_T emy0hrjuzr ; int8_T frxkwgelef ;
int8_T bpfxbpnxdk ; int8_T kvbynbt23x ; int8_T pzmje2aewl ; uint8_T
cht01inrsx ; uint8_T epdi02vhe4 ; uint8_T j0qx5gs3ge ; uint8_T le5srsw3mq ;
uint8_T hfkomryudx ; uint8_T oslrfkshxj ; boolean_T bn411rqyba ; boolean_T
jhekd05k4p ; boolean_T jrnny2qloo ; boolean_T ctt5abpcf5 ; boolean_T
et15tz1dc1 ; boolean_T hs4d4btmzy ; boolean_T cgqmbfzh11 ; boolean_T
gpsddborgv ; boolean_T gpuflrf0yn ; boolean_T aekk1bjgtl ; boolean_T
jmvufartxc ; boolean_T idulg0qqat ; h4iasb5pte jtgflhe3su ; dmxskfrz2h
ammeeph1io ; h4iasb5pte iry0wsg2k5 ; dmxskfrz2h orebwtip3e ; h4iasb5pte
azz3d4nxcem ; dmxskfrz2h p0vdevk3x14 ; } DW ; typedef struct { real_T
b1lr14rcuj [ 4 ] ; real_T ba1rjb3ky4 [ 3 ] ; real_T hod35jdtrz [ 3 ] ; real_T
hc2wlzjerw [ 3 ] ; real_T abpf02yfny [ 3 ] ; real_T gffjebdga3 [ 4 ] ; real_T
ipddjaa3ie [ 3 ] ; real_T bhzxtdpm0j [ 3 ] ; real_T hiwmnibigx [ 4 ] ; } X ;
typedef struct { real_T b1lr14rcuj [ 4 ] ; real_T ba1rjb3ky4 [ 3 ] ; real_T
hod35jdtrz [ 3 ] ; real_T hc2wlzjerw [ 3 ] ; real_T abpf02yfny [ 3 ] ; real_T
gffjebdga3 [ 4 ] ; real_T ipddjaa3ie [ 3 ] ; real_T bhzxtdpm0j [ 3 ] ; real_T
hiwmnibigx [ 4 ] ; } XDot ; typedef struct { boolean_T b1lr14rcuj [ 4 ] ;
boolean_T ba1rjb3ky4 [ 3 ] ; boolean_T hod35jdtrz [ 3 ] ; boolean_T
hc2wlzjerw [ 3 ] ; boolean_T abpf02yfny [ 3 ] ; boolean_T gffjebdga3 [ 4 ] ;
boolean_T ipddjaa3ie [ 3 ] ; boolean_T bhzxtdpm0j [ 3 ] ; boolean_T
hiwmnibigx [ 4 ] ; } XDis ; typedef struct { real_T b1lr14rcuj [ 4 ] ; real_T
ba1rjb3ky4 [ 3 ] ; real_T hod35jdtrz [ 3 ] ; real_T hc2wlzjerw [ 3 ] ; real_T
abpf02yfny [ 3 ] ; real_T gffjebdga3 [ 4 ] ; real_T ipddjaa3ie [ 3 ] ; real_T
bhzxtdpm0j [ 3 ] ; real_T hiwmnibigx [ 4 ] ; } CStateAbsTol ; typedef struct
{ real_T jdg5fgght1 ; real_T fxw0wciwbi [ 3 ] ; real_T cxcnp3omib [ 3 ] ;
real_T o3jzv1jvx5 [ 3 ] ; real_T nl0q2bqjk2 [ 3 ] ; real_T of1glfyyn3 [ 3 ] ;
real_T fqt0mvrdyk [ 3 ] ; real_T conutdf0a1 ; real_T on4aexigh0 ; real_T
jvmb2fyiro ; real_T c1rvp53ssv ; real_T msqpbrzbho [ 3 ] ; real_T lkeql2wcuq
[ 3 ] ; real_T l2ciyo4le3 ; real_T oysbzpsleq ; real_T mbnhcly4p4 [ 3 ] ;
real_T nj1x2icp01 [ 3 ] ; real_T lxorc1vviq [ 3 ] ; real_T aa4hlipmit [ 3 ] ;
real_T noc1howb5m ; real_T nlcmaie0u2 ; real_T lgcrwrzhuk ; real_T eww3ne2iiy
; real_T ld3212p11x ; real_T orsixo5y1m [ 3 ] ; real_T f4jdxybzpf [ 3 ] ;
real_T gjzxypbad0 ; real_T nhedzlvqro ; real_T blcdcguqy1 ; real_T kast2133x5
; real_T eng02qphle [ 3 ] ; real_T pirmbnon5t [ 3 ] ; p4bsjadjac jtgflhe3su ;
p4bsjadjac iry0wsg2k5 ; p4bsjadjac azz3d4nxcem ; } ZCV ; typedef struct {
ZCSigState jij3bxd0sr ; ZCSigState aar0pwundm [ 3 ] ; ZCSigState dv3410dzwc [
3 ] ; ZCSigState i0ykjiswph [ 3 ] ; ZCSigState dwpzks2y0i [ 3 ] ; ZCSigState
l0b4y5ywr4 [ 3 ] ; ZCSigState g0p2gjqoaw [ 3 ] ; ZCSigState gl1h5qphdb ;
ZCSigState lv3cwkzogi ; ZCSigState f5z4jxh4zc ; ZCSigState l5pzboqmk1 ;
ZCSigState l4p2lv1tlb [ 3 ] ; ZCSigState kf5elx30y5 [ 3 ] ; ZCSigState
pad4jm2c10 ; ZCSigState m2zxdm0kun ; ZCSigState freimzsudt [ 3 ] ; ZCSigState
eeum4llgc5 [ 3 ] ; ZCSigState czvsxrntyd [ 3 ] ; ZCSigState i4hpd4u5kp [ 3 ]
; ZCSigState mdsszwkahk ; ZCSigState kobserce23 ; ZCSigState bkwaq4vfez ;
ZCSigState j3n5btwqb5 ; ZCSigState mveremkmpa ; ZCSigState euptdmep2c [ 3 ] ;
ZCSigState e5zwfhpidh [ 3 ] ; ZCSigState abj4ywa4lu ; ZCSigState a5ngtgeca1 ;
ZCSigState lpb1m4wk0q ; ZCSigState h4iazvqiyf ; ZCSigState jbxnrv4yt3 [ 3 ] ;
ZCSigState p3rzil2jjm [ 3 ] ; fnlt43lw0a jtgflhe3su ; fnlt43lw0a iry0wsg2k5 ;
fnlt43lw0a azz3d4nxcem ; } PrevZCX ; struct oj32fzmstd_ { real_T
Constant_Value ; real_T Gain_Gain ; real_T Gain1_Gain ; } ; struct
a0yd1qizj0_ { real_T Constant_Value ; real_T Gain_Gain ; real_T
Constant1_Value ; real_T Constant2_Value [ 2 ] ; real_T Gain1_Gain ; real_T
Gain3_Gain ; real_T Gain4_Gain ; real_T Constant_Value_pc3s5n5ig0 ; real_T
Gain_Gain_g0crcybw52 ; real_T Constant1_Value_pvid3jlafh ; real_T
Constant2_Value_bgmtgxyswg [ 2 ] ; real_T Gain1_Gain_cmjmtszzlh ; real_T
Gain2_Gain ; real_T Gain3_Gain_fjdyxqygiq ; real_T Constant_Value_elm2slanqm
; real_T Gain_Gain_ocfwspzgot ; real_T Constant1_Value_cf4j34iv2x ; real_T
Constant2_Value_pt2pqq3qma [ 2 ] ; real_T Gain1_Gain_dvdkv5tz32 ; real_T
Gain2_Gain_atvqpareya ; real_T Gain3_Gain_clfc33gypf ; } ; struct P_ { real_T
Constant_Value ; real_T Gain_Gain ; real_T Gain1_Gain ; real_T
Constant2_Value [ 2 ] ; real_T Constant1_Value ; real_T
Constant_Value_itf12sgtld ; real_T Gain_Gain_iz22fd4qci ; real_T
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
Constant_Value_lkzxmgm0bn ; real_T Constant1_Value_idmny2apeg ; real_T
Constant_Value_huezfbtji2 ; real_T Constant1_Value_hk3avlia0e [ 9 ] ; real_T
Constant_Value_hwdenieqz1 ; real_T Constant2_Value_lni0tz223k [ 3 ] ; real_T
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
Gain_Gain_npjumclfz3 ; real_T Gain1_Gain_kvzh5djr2r ; real_T
Constant_Value_f0cxdn1qgj ; real_T Gain2_Gain_mmkmfnjizh ; real_T
Constant_Value_knvnx2wekq ; real_T Gain2_Gain_cpzoqqauxm ; real_T
Gain_Gain_lryaod0efo ; real_T Gain1_Gain_kdfxi3p2kc ; real_T
Gain_Gain_gb54frueuf ; real_T Constant_Value_m4jcoxsqs0 ; real_T
Gain2_Gain_nthqdz0l5g ; real_T Gain1_Gain_dl4zducw3w ; real_T
Gain_Gain_hiaz1ngjp4 ; real_T ChangeMe3_Value [ 9 ] ; real_T
Constant_Value_gvhcouy2li [ 9 ] ; real_T Constant_Value_egr1tn4q2z [ 9 ] ;
real_T Constant_Value_jrc3i5y0a4 [ 3 ] ; real_T Integrator_IC ; real_T
WhiteNoise_Mean ; real_T WhiteNoise_StdDev ; real_T WhiteNoise_Seed ; real_T
Output_Gain [ 3 ] ; real_T Constant_Value_m3cuqn51ns [ 3 ] ; real_T
DiscreteTimeIntegrator_gainval ; real_T Gain1_Gain_a0a5bf0urx ; real_T
IntegratorLimited_IC ; real_T IntegratorLimited_UpperSat ; real_T
IntegratorLimited_LowerSat ; real_T IntegratorLimited_IC_fejwzsem04 [ 3 ] ;
real_T IntegratorLimited_UpperSat_ntkxmpf0qj ; real_T
IntegratorLimited_LowerSat_oacseuhnry ; real_T Gain1_Gain_i0dny2tgg4 ; real_T
Kang_Gain ; real_T Gain_Gain_imjwpylc20 ; real_T Constant_Value_gfamwgvgio ;
real_T Gain2_Gain_hsczlo4ztj ; real_T Gain_Gain_mwczkktdza ; real_T
Gain1_Gain_jcffkkjw2g ; real_T Gain_Gain_keh1ebxthv ; real_T
Constant_Value_alyo2kghso ; real_T Gain2_Gain_bnubngmvnh ; real_T
Gain1_Gain_kck2izenjg ; real_T Gain_Gain_m1esafctux ; real_T
Gain1_Gain_gpeez3rcld ; real_T Constant_Value_jrgvdhmfe2 ; real_T
Gain2_Gain_nv4m22xdcw ; real_T Krate_Gain ; real_T ChangeMe1_Value [ 9 ] ;
real_T ChangeMe2_Value [ 3 ] ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T Gain1_Gain_dkf041qpaw ; real_T
Saturation_UpperSat_faael1sbi5 ; real_T Saturation_LowerSat_agytdqopmw ;
real_T Constant_Value_lrvvatbdw3 [ 3 ] ; real_T Constant3_Value ; real_T
Constant_Value_kejneha0ij ; real_T Constant_Value_bc5jwlnuhr ; real_T
Gain_Gain_n3x52x0hib ; real_T DiscreteTimeIntegrator_gainval_nclh2cnkov ;
real_T Constant_Value_pakwzwri3w ; real_T Gain_Gain_aylskoktgk ; real_T
Gain1_Gain_cphlya4qdx ; real_T Constant_Value_mx1msscuqd ; real_T
Gain2_Gain_ohkyc5atre ; real_T Constant_Value_l4fxoeulw2 ; real_T
Gain2_Gain_m0t2xxz40v ; real_T Gain_Gain_frcbiltvyt ; real_T
Gain1_Gain_hlgkmxw45m ; real_T Gain_Gain_jlgfxmogcv ; real_T
Constant_Value_dvdmweasr4 ; real_T Gain2_Gain_h305jf3sv3 ; real_T
Gain1_Gain_hdwvivfv4n ; real_T Gain_Gain_akwngypvn3 ; real_T
DiscreteTimeIntegrator1_gainval ; real_T DiscreteTimeIntegrator1_IC ; real_T
DiscreteTimeIntegrator2_gainval ; real_T DiscreteTimeIntegrator2_IC ; real_T
Constant_Value_csl0xc4ep4 ; real_T Constant1_Value_d0nljg3n4k ; real_T
Switch_Threshold_ocvrgqhwfd ; real_T Constant_Value_egwar5iee0 ; real_T
HighGainQuaternionNormalization_Gain ; real_T Constant3_Value_oayr5juvkv ;
real_T Gain8_Gain ; real_T Gain6_Gain ; real_T Gain7_Gain ; real_T a_Value ;
real_T Gain5_Gain ; real_T Constant1_Value_de0q5adpcb [ 9 ] ; real_T
Constant_Value_bw3vkbj2eu ; real_T Gain_Gain_av3hfhcgyv ; real_T
Constant_Value_bin4grumgj ; real_T Constant2_Value_jf2fosnw3b [ 3 ] ; real_T
Gain_Gain_mbuijwi5jm ; real_T Constant_Value_jgjdenbdkp ; real_T
Constant5_Value [ 3 ] ; real_T Gain_Gain_hsvk1ppevl ; real_T
Constant_Value_dlgbgdxgmn ; real_T Gain_Gain_dxvjzvgyer ; real_T
Constant_Value_p2yj2qsewh ; real_T Constant3_Value_fjjscdcrzj [ 3 ] ; real_T
Gain_Gain_e42rl13cmn ; real_T Constant_Value_fn2jvveflf ; real_T
Constant6_Value [ 3 ] ; real_T Gain_Gain_eiuk4co0u1 ; real_T
Constant_Value_pnej1bop5b ; real_T Gain_Gain_ikyjnkugqm ; real_T
Constant_Value_irpm3cwjza ; real_T Constant4_Value [ 3 ] ; real_T
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
Gain2_Gain_oat3nps3gi ; real_T ChangeMe_Value [ 3 ] ; real_T
Gain1_Gain_cz2xpyyxre ; real_T Constant1_Value_pibyfcp5ht [ 3 ] ; real_T
Gain2_Gain_g3pgvavbec ; real_T Constant2_Value_erhep10kxc [ 3 ] ; real_T
Gain3_Gain_nlnczbyk1z ; real_T Constant3_Value_au20vl24uo [ 3 ] ; real_T
Gain4_Gain_obkdmqncg2 ; real_T Gain5_Gain_fzoolgsndi ; real_T
Constant_Value_fjgr21kt5s ; real_T
HighGainQuaternionNormalization_Gain_ob3hm0wdis ; real_T
Gain6_Gain_nptkktx5dl ; real_T WhiteNoise_Mean_fpnv13epd5 ; real_T
WhiteNoise_StdDev_esrovvidoo ; real_T WhiteNoise_Seed_kw4ej5243j ; real_T
Output_Gain_ba0gpqdttx [ 3 ] ; real_T Gain_Gain_ovaf4mtkfv ; real_T
Constant_Value_ez3apkr1wy ; real_T Constant_Value_nt3nodlo0n ; real_T
Gain2_Gain_b455g1loe1 ; real_T Gain_Gain_pxe1qwiizn ; real_T
Gain1_Gain_huu1lmrels ; real_T Gain_Gain_j0vyy2fy2r ; real_T
Constant_Value_jy4gaazlnd ; real_T Gain2_Gain_bujbdfke15 ; real_T
Gain1_Gain_fkwqudcabt ; real_T Gain_Gain_bigflic040 ; real_T
Gain1_Gain_hfanpouy13 ; real_T Constant_Value_mctqlak3ab ; real_T
Gain2_Gain_o4dc4ko20g ; real_T Switch_Threshold_jv24xn0sxc ; real_T
IntegratorLimited_IC_k0pmcuud0v ; real_T
IntegratorLimited_UpperSat_fwrvmo440m ; real_T
IntegratorLimited_LowerSat_m3ljhooqpl ; real_T Constant_Value_lcleawr1lx [ 3
] ; real_T IntegratorLimited_IC_fuyeuczoy3 [ 3 ] ; real_T
IntegratorLimited_UpperSat_ib2vfv1ckh ; real_T
IntegratorLimited_LowerSat_l15h4cnjuq ; real_T Gain1_Gain_n011xbqfsl ; real_T
ChangeMe3_Value_g3bcdwbqnq [ 9 ] ; real_T Constant_Value_deca5ebbvm ; real_T
Constant_Value_oc4kpc4egn ; real_T Constant1_Value_bzw0ndzkcq ; real_T
FromWorkspace_Time0_ckirflsq1k [ 980 ] ; real_T
FromWorkspace_Data0_i0n1gmpn4i [ 2940 ] ; real_T
FromWorkspace_Time1_fbttqagftm [ 980 ] ; real_T
FromWorkspace_Data1_naxvmyfyud [ 2940 ] ; real_T
FromWorkspace_Time2_p5mrmwomhx [ 980 ] ; real_T
FromWorkspace_Data2_mxf1q2pwwa [ 2940 ] ; real_T
FromWorkspace_Time3_hofsogvoq5 [ 980 ] ; real_T
FromWorkspace_Data3_atkkn5wa2c [ 2940 ] ; real_T
FromWorkspace_Time4_kus2hl432n [ 980 ] ; real_T
FromWorkspace_Data4_bp4l4d2qb1 [ 2940 ] ; real_T Constant_Value_nbket1mlnp ;
real_T Switch_Threshold_g4wyietdsx ; real_T Constant_Value_oj52tmdbor ;
real_T Switch_Threshold_msevguw5vk ; real_T Merge_InitialOutput_iavc5wanks [
4 ] ; real_T Switch_Threshold_i0bmwnwue3 ; real_T Qjo_init_Value_gqletaanjz [
4 ] ; real_T Qob_init_Value_onwkle1j2e [ 4 ] ; real_T
Switch_Threshold_i3smlivfgb ; real_T Constant1_Value_cfl4aorgnt ; real_T
Switch_Threshold_oly1kcdrtr ; real_T Kang_Gain_n0feef1eux ; real_T
Gain_Gain_bmoksmecff ; real_T Constant_Value_gxdrvm4bpy ; real_T
Gain2_Gain_heaghzzgpx ; real_T Gain_Gain_pgxythkq3t ; real_T
Gain1_Gain_aytyfi3wnb ; real_T Gain_Gain_i0c4kruuzt ; real_T
Constant_Value_cictyeh5tj ; real_T Gain2_Gain_fmqrns42ku ; real_T
Gain1_Gain_epqkenchvx ; real_T Gain_Gain_e3nk2dcxil ; real_T
Gain1_Gain_gnp24rmnoz ; real_T Constant_Value_c1xelsucey ; real_T
Gain2_Gain_evefvpl1an ; real_T Krate_Gain_piyaqat3c3 ; real_T
ChangeMe1_Value_fak2wrhghj [ 9 ] ; real_T ChangeMe2_Value_bojzs0xv5c [ 3 ] ;
real_T Saturation_UpperSat_pmclfotbip ; real_T Saturation_LowerSat_hmweagl2k5
; real_T Gain1_Gain_ftwdy5cupq ; real_T Saturation_UpperSat_kvg53uzs0w ;
real_T Saturation_LowerSat_ak0p0zlbrx ; real_T Constant_Value_ba4yjgwi4a [ 3
] ; real_T Constant3_Value_ozgyx12s5q ; real_T Constant_Value_fnng3n2cqs ;
real_T Constant_Value_aav3mecjn5 ; real_T Gain_Gain_ltta3l4gzo ; real_T
DiscreteTimeIntegrator_gainval_nlfnzii0in ; real_T Constant_Value_drjehzq42h
; real_T Gain_Gain_jl2l3kvkt1 ; real_T Gain1_Gain_mxggrkn41e ; real_T
Constant_Value_me5yv0jtlt ; real_T Gain2_Gain_fvc01em23y ; real_T
Constant_Value_bs5xuxpbbf ; real_T Gain2_Gain_ftpblpfslm ; real_T
Gain_Gain_hxfbfej4zq ; real_T Gain1_Gain_aw0t0ojudt ; real_T
Gain_Gain_arguqsa2xk ; real_T Constant_Value_lb5gk2wltw ; real_T
Gain2_Gain_cdkrn1kfio ; real_T Gain1_Gain_mwe5i1fuoh ; real_T
Gain_Gain_oi1dmjf42c ; real_T DiscreteTimeIntegrator1_gainval_lb44ya5e4p ;
real_T DiscreteTimeIntegrator1_IC_ht15kdk502 ; real_T
DiscreteTimeIntegrator2_gainval_pfnmbeyr34 ; real_T
DiscreteTimeIntegrator2_IC_liuu5c3kzq ; real_T Constant_Value_bifugeoxsi ;
real_T Constant1_Value_i2bviibqa1 ; real_T Switch_Threshold_ih32etj225 ;
real_T Constant_Value_hbjvgrrmsz ; real_T
HighGainQuaternionNormalization_Gain_nnwvygfxro ; real_T
Constant3_Value_owr20rawcp ; real_T Gain8_Gain_hmjcxkynt4 ; real_T
Gain6_Gain_h3125rb23e ; real_T Gain7_Gain_gmfxftd3mb ; real_T
a_Value_f5j011wiug ; real_T Gain5_Gain_bz0vauxshy ; real_T
Constant1_Value_hao4x44ah2 [ 9 ] ; real_T Constant_Value_k0wcldte3h ; real_T
Gain_Gain_aa0vtk0zmd ; real_T Constant_Value_hwvscamm31 ; real_T
Constant2_Value_c3n5xbbf35 [ 3 ] ; real_T Gain_Gain_ojc15iu5jd ; real_T
Constant_Value_c2kug4uglk ; real_T Constant5_Value_gn0gckpuzn [ 3 ] ; real_T
Gain_Gain_kqt10qghkc ; real_T Constant_Value_pxpcd5bk3c ; real_T
Gain_Gain_jjixz4kmpu ; real_T Constant_Value_kvybbzfnrt ; real_T
Constant3_Value_a5rnl3iohi [ 3 ] ; real_T Gain_Gain_nb04rhjuqe ; real_T
Constant_Value_aawk2y00ma ; real_T Constant6_Value_fhjuxteqna [ 3 ] ; real_T
Gain_Gain_fazvlmdyvx ; real_T Constant_Value_kpvlwz5g2c ; real_T
Gain_Gain_anyjlb3pu0 ; real_T Constant_Value_amfkvbii2o ; real_T
Constant4_Value_ohaes1tek1 [ 3 ] ; real_T Gain_Gain_nqjty0rsxr ; real_T
Constant_Value_ebfrcaxa1u ; real_T Constant7_Value_ihkbrtwf0t [ 3 ] ; real_T
Gain_Gain_ldb0s3bi33 ; real_T Constant_Value_dx3sborzrl [ 9 ] ; real_T
Constant_Value_epdybnohto ; real_T Switch_Threshold_oksbac2myv ; real_T
Constant_Value_eovzc0nuc4 ; real_T Switch_Threshold_lodxyjq4uq ; real_T
Merge_InitialOutput_bepp0144uv [ 4 ] ; real_T Gain_Gain_goqw3vji4e ; real_T
Saturation_UpperSat_kq1vntuako ; real_T Saturation_LowerSat_iborwhdlaq ;
a0yd1qizj0 jtgflhe3su ; oj32fzmstd ammeeph1io ; a0yd1qizj0 iry0wsg2k5 ;
oj32fzmstd orebwtip3e ; a0yd1qizj0 azz3d4nxcem ; oj32fzmstd p0vdevk3x14 ; } ;
extern P rtP ; extern const BusObject ACStesbed_rtZBusObject ; extern const
char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW
rtDW ; extern PrevZCX rtPrevZCX ; extern SimStruct * const rtS ; extern const
int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const int_T
gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern const
char * gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern
const int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ;
#endif
