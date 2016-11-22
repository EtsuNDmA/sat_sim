#include "__cf_ACStesbed1.h"
#include <math.h>
#include "ACStesbed1.h"
#include "ACStesbed1_private.h"
#include "ACStesbed1_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
const boolean_T gbl_raccel_isMultitasking = 1 ;
#else
const boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
const boolean_T gbl_raccel_tid01eq = 0 ; const int_T gbl_raccel_NumST = 5 ;
const char_T * gbl_raccel_Version = "8.5 (R2013b) 08-Aug-2013" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\ACStesbed1\\ACStesbed1_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
const BusObject ACStesbed1_rtZBusObject = { { 0.0 , 0.0 , 0.0 } , { 0.0 , 0.0
, 0.0 } , { 0.0 , 0.0 , 0.0 } , { 0.0 , 0.0 , 0.0 } , { 0.0 , 0.0 , 0.0 } } ;
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T lo
; uint32_T hi ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if
( lo < hi ) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; }
return ( real_T ) * u * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T y ; real_T sr ; real_T
si ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void LUf_int32_Treal_T ( real_T outU [ ] , real_T outP [
] , const int32_T N ) { int32_T k ; int32_T c ; int32_T r ; int32_T idx ;
real_T tmp ; int32_T p ; real_T mTmp ; boolean_T isDiagZero ; real_T mAccum ;
for ( k = 0 ; k < N ; k ++ ) { outP [ k ] = ( real_T ) k + 1.0 ; } for ( k =
0 ; k < N ; k ++ ) { p = k ; idx = k * N ; mTmp = outU [ idx + k ] ; if (
mTmp < 0.0 ) { mTmp = - mTmp ; } for ( r = k + 1 ; r < N ; r ++ ) { tmp =
outU [ idx + r ] ; if ( tmp < 0.0 ) { tmp = - tmp ; } if ( tmp > mTmp ) { p =
r ; mTmp = tmp ; } } if ( p != k ) { for ( c = 0 ; c < N ; c ++ ) { idx = c *
N ; mTmp = outU [ idx + p ] ; tmp = outU [ idx + k ] ; outU [ idx + p ] = tmp
; outU [ idx + k ] = mTmp ; } tmp = outP [ p ] ; outP [ p ] = outP [ k ] ;
outP [ k ] = tmp ; } idx = k * N + k ; isDiagZero = FALSE ; if ( outU [ idx ]
== 0.0 ) { isDiagZero = TRUE ; } if ( ! isDiagZero ) { p = k * N ; for ( r =
k + 1 ; r < N ; r ++ ) { mTmp = outU [ p + r ] ; tmp = outU [ idx ] ; outU [
p + r ] = mTmp / tmp ; } for ( c = k + 1 ; c < N ; c ++ ) { idx = c * N ; for
( r = k + 1 ; r < N ; r ++ ) { mAccum = outU [ idx + r ] ; mTmp = outU [ p +
r ] ; tmp = outU [ idx + k ] * mTmp ; mAccum -= tmp ; outU [ idx + r ] =
mAccum ; } } } } } void rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( const real_T u0 [
9 ] , const real_T u1 [ 3 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; int32_T r ;
int32_T r_p ; int32_T r_e ; real_T maxval ; real_T a ; int32_T rtemp ; memcpy
( & A [ 0 ] , & u0 [ 0 ] , 9U * sizeof ( real_T ) ) ; r = 0 ; r_p = 1 ; r_e =
2 ; maxval = muDoubleScalarAbs ( u0 [ 0 ] ) ; a = muDoubleScalarAbs ( u0 [ 1
] ) ; if ( a > maxval ) { maxval = a ; r = 1 ; r_p = 0 ; } if (
muDoubleScalarAbs ( u0 [ 2 ] ) > maxval ) { r = 2 ; r_p = 1 ; r_e = 0 ; } A [
r_p ] = u0 [ r_p ] / u0 [ r ] ; A [ r_e ] /= A [ r ] ; A [ 3 + r_p ] -= A [ 3
+ r ] * A [ r_p ] ; A [ 3 + r_e ] -= A [ 3 + r ] * A [ r_e ] ; A [ 6 + r_p ]
-= A [ 6 + r ] * A [ r_p ] ; A [ 6 + r_e ] -= A [ 6 + r ] * A [ r_e ] ; if (
muDoubleScalarAbs ( A [ 3 + r_e ] ) > muDoubleScalarAbs ( A [ 3 + r_p ] ) ) {
rtemp = r_p + 1 ; r_p = r_e ; r_e = rtemp - 1 ; } A [ 3 + r_e ] /= A [ 3 +
r_p ] ; A [ 6 + r_e ] -= A [ 3 + r_e ] * A [ 6 + r_p ] ; maxval = u1 [ r_p ]
- u1 [ r ] * A [ r_p ] ; a = ( ( u1 [ r_e ] - u1 [ r ] * A [ r_e ] ) - A [ 3
+ r_e ] * maxval ) / A [ 6 + r_e ] ; maxval -= A [ 6 + r_p ] * a ; maxval /=
A [ 3 + r_p ] ; y [ 0 ] = ( ( u1 [ r ] - A [ 6 + r ] * a ) - A [ 3 + r ] *
maxval ) / A [ r ] ; y [ 1 ] = maxval ; y [ 2 ] = a ; } void MdlInitialize (
void ) { if ( ssIsFirstInitCond ( rtS ) ) { rtB . hqqy53kfyu [ 0 ] = rtP .
Merge_InitialOutput [ 0 ] ; rtB . hqqy53kfyu [ 1 ] = rtP .
Merge_InitialOutput [ 1 ] ; rtB . hqqy53kfyu [ 2 ] = rtP .
Merge_InitialOutput [ 2 ] ; rtB . hqqy53kfyu [ 3 ] = rtP .
Merge_InitialOutput [ 3 ] ; } if ( ssIsFirstInitCond ( rtS ) ) { rtX .
b1lr14rcuj [ 0 ] = 0.0 ; rtX . b1lr14rcuj [ 1 ] = 0.0 ; rtX . b1lr14rcuj [ 2
] = 0.0 ; rtX . b1lr14rcuj [ 3 ] = 0.0 ; } rtDW . evzrtqyrte . IcNeedsLoading
= 1 ; if ( ssIsFirstInitCond ( rtS ) ) { rtX . ba1rjb3ky4 [ 0 ] = 0.0 ; rtX .
ba1rjb3ky4 [ 1 ] = - 0.0001 ; rtX . ba1rjb3ky4 [ 2 ] = 0.0 ; } rtDW .
l3ydkkphoy . IcNeedsLoading = 1 ; rtX . hod35jdtrz [ 0 ] = rtP .
Integrator_IC ; rtX . hod35jdtrz [ 1 ] = rtP . Integrator_IC ; rtX .
hod35jdtrz [ 2 ] = rtP . Integrator_IC ; rtX . al32ndubg1 [ 0 ] = rtP .
IntegratorLimited_IC ; rtX . al32ndubg1 [ 1 ] = rtP . IntegratorLimited_IC ;
rtX . al32ndubg1 [ 2 ] = rtP . IntegratorLimited_IC ; rtX . abpf02yfny [ 0 ]
= rtP . IntegratorLimited_IC_fejwzsem04 [ 0 ] ; rtX . abpf02yfny [ 1 ] = rtP
. IntegratorLimited_IC_fejwzsem04 [ 1 ] ; rtX . abpf02yfny [ 2 ] = rtP .
IntegratorLimited_IC_fejwzsem04 [ 2 ] ; if ( ssIsFirstInitCond ( rtS ) ) {
rtB . l2aegg0det [ 0 ] = rtP . Merge_InitialOutput_poz11gcqai [ 0 ] ; rtB .
l2aegg0det [ 1 ] = rtP . Merge_InitialOutput_poz11gcqai [ 1 ] ; rtB .
l2aegg0det [ 2 ] = rtP . Merge_InitialOutput_poz11gcqai [ 2 ] ; rtB .
l2aegg0det [ 3 ] = rtP . Merge_InitialOutput_poz11gcqai [ 3 ] ; } if (
ssIsFirstInitCond ( rtS ) ) { rtX . gffjebdga3 [ 0 ] = 0.74236445279750729 ;
rtX . gffjebdga3 [ 1 ] = 0.651265752605938 ; rtX . gffjebdga3 [ 2 ] = -
0.078072152852283819 ; rtX . gffjebdga3 [ 3 ] = - 0.13803143719562005 ; }
rtDW . phnnzeax4q . IcNeedsLoading = 1 ; } void MdlStart ( void ) { uint32_T
tseed ; int32_T r ; int32_T t ; real_T tmp ; { { FWksInfo * fromwksInfo ; if
( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == (
NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints =
980 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time0 ; rtDW .
bknzq3wgub . TimePtr [ 0 ] = fromwksInfo -> time ; rtDW . bknzq3wgub .
DataPtr [ 0 ] = fromwksInfo -> data ; rtDW . bknzq3wgub . RSimInfoPtr [ 0 ] =
fromwksInfo ; } } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo
* ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus (
rtS , "from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data1 ; fromwksInfo -> nDataPoints =
980 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time1 ; rtDW .
bknzq3wgub . TimePtr [ 1 ] = fromwksInfo -> time ; rtDW . bknzq3wgub .
DataPtr [ 1 ] = fromwksInfo -> data ; rtDW . bknzq3wgub . RSimInfoPtr [ 1 ] =
fromwksInfo ; } } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo
* ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus (
rtS , "from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data2 ; fromwksInfo -> nDataPoints =
980 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time2 ; rtDW .
bknzq3wgub . TimePtr [ 2 ] = fromwksInfo -> time ; rtDW . bknzq3wgub .
DataPtr [ 2 ] = fromwksInfo -> data ; rtDW . bknzq3wgub . RSimInfoPtr [ 2 ] =
fromwksInfo ; } } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo
* ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus (
rtS , "from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data3 ; fromwksInfo -> nDataPoints =
980 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time3 ; rtDW .
bknzq3wgub . TimePtr [ 3 ] = fromwksInfo -> time ; rtDW . bknzq3wgub .
DataPtr [ 3 ] = fromwksInfo -> data ; rtDW . bknzq3wgub . RSimInfoPtr [ 3 ] =
fromwksInfo ; } } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo
* ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus (
rtS , "from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data4 ; fromwksInfo -> nDataPoints =
980 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time4 ; rtDW .
bknzq3wgub . TimePtr [ 4 ] = fromwksInfo -> time ; rtDW . bknzq3wgub .
DataPtr [ 4 ] = fromwksInfo -> data ; rtDW . bknzq3wgub . RSimInfoPtr [ 4 ] =
fromwksInfo ; } } { int_T i1 ; int_T * iw_PrevIndex = & rtDW . fibx4ptf5m .
PrevIndex [ 0 ] ; void * * pw_TimePtr = & rtDW . bknzq3wgub . TimePtr [ 0 ] ;
for ( i1 = 0 ; i1 < 5 ; i1 ++ ) { iw_PrevIndex [ i1 ] = 0 ; } } } rtDW .
bwuwpskbe1 = - 1 ; rtDW . pzmje2aewl = 0 ; rtDW . jenrmeyvts = - 1 ; rtDW .
kvbynbt23x = 0 ; rtDW . bpfxbpnxdk = 0 ; rtDW . frxkwgelef = 0 ; rtB .
n1iqi5rfxp [ 0 ] = rtP . Constant_Value_jrc3i5y0a4 [ 0 ] ; rtB . n1iqi5rfxp [
1 ] = rtP . Constant_Value_jrc3i5y0a4 [ 1 ] ; rtB . n1iqi5rfxp [ 2 ] = rtP .
Constant_Value_jrc3i5y0a4 [ 2 ] ; tmp = muDoubleScalarFloor ( rtP .
WhiteNoise_Seed ) ; if ( muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf (
tmp ) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem ( tmp , 4.294967296E+9
) ; } tseed = tmp < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp : (
uint32_T ) tmp ; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed &
32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U )
+ t ) + r ; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed >
2147483646U ) { tseed = 2147483646U ; } } rtDW . hvy1dfvqu0 = tseed ; rtDW .
m5suqpxty3 = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . hvy1dfvqu0 ) * rtP .
WhiteNoise_StdDev + rtP . WhiteNoise_Mean ; rtDW . l33pfglk2a = 0 ; { void *
signalProbe = ( NULL ) ; unsigned int dims [ 1 ] = { 3 } ;
rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" , "<ddeltaD>" ,
"<ddeltaD>" , "ACStesbed1/Actuators/Bus Selector1" , 1 , "linear" , 1 , 0 , &
signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . hzkxwtgg3y .
SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ; unsigned int
dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" ,
"deltaD" , "deltaD" , "ACStesbed1/Actuators/Subsystem" , 1 , "linear" , 1 , 0
, & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . ethxueuerq .
SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ; unsigned int
dims [ 1 ] = { 4 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" ,
"Qob_mes" , "Qob_mes" , "ACStesbed1/CentralComputer/SatAttitude/BINS" , 1 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . mohxnwpvy0 . SignalProbe = signalProbe ; } { void * signalProbe = (
NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "deltaW_mes" , "deltaW_mes" ,
"ACStesbed1/CentralComputer/SatAttitude/BINS" , 2 , "linear" , 1 , 0 , &
signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . fs3xofbgsa .
SignalProbe = signalProbe ; } memset ( & rtB . f22csweirk [ 0 ] , 0 , 9U *
sizeof ( real_T ) ) ; rtB . f22csweirk [ 0 ] = 1.0 ; rtB . f22csweirk [ 4 ] =
1.0 ; rtB . f22csweirk [ 8 ] = 1.0 ; rtDW . mf41bf444w = - 1 ; rtDW .
lggvt2ioqm = 0 ; rtDW . pyge1tac5l = - 1 ; rtDW . m4c02ikbg1 = 0 ; rtDW .
iq1hnty4rc = 0 ; rtDW . hrkt2hcocj = 0 ; rtB . p0m1jnhybt [ 0 ] = rtP .
Constant1_Value_fg2gdmjirg [ 0 ] ; rtB . p0m1jnhybt [ 1 ] = rtP .
Constant1_Value_fg2gdmjirg [ 1 ] ; rtB . p0m1jnhybt [ 2 ] = rtP .
Constant1_Value_fg2gdmjirg [ 2 ] ; rtB . p0m1jnhybt [ 3 ] = rtP .
Constant1_Value_fg2gdmjirg [ 3 ] ; rtDW . huixms4qzu = 0 ; { void *
signalProbe = ( NULL ) ; unsigned int dims [ 1 ] = { 3 } ;
rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" , "<W>" , "<W>" ,
"ACStesbed1/Object/Torques/Bus Selector" , 2 , "linear" , 1 , 0 , &
signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . iyqxvnatsr .
SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ; unsigned int
dims [ 1 ] = { 4 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" ,
"<Qjo>" , "<Qjo>" , "ACStesbed1/Object/Torques/Bus Selector" , 4 , "linear" ,
1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW .
h4jqbncwhd . SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ;
unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Trw" , "Trw" , "ACStesbed1/Object/Torques/Saturation"
, 1 , "linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] )
) ; rtDW . hu21nqqcni . SignalProbe = signalProbe ; } { void * signalProbe =
( NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Tg" , "Tg" , "ACStesbed1/Object/Torques/Tgrav" , 1 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . oawgrr5lku . SignalProbe = signalProbe ; } { void * signalProbe = (
NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "" , "" , "ACStesbed1/Object/Torques/Tgrav/Add" , 1 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . behvht2jjq . SignalProbe = signalProbe ; } { void * signalProbe = (
NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Tg1" , "Tg1" ,
"ACStesbed1/Object/Torques/Tgrav/Gain2" , 1 , "linear" , 1 , 0 , &
signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . jjiadmicyc .
SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ; unsigned int
dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" ,
"Tg2" , "Tg2" , "ACStesbed1/Object/Torques/Tgrav/Gain3" , 1 , "linear" , 1 ,
0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . bgsuqbvq3e
. SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ; unsigned
int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout"
, "Tg3" , "Tg3" , "ACStesbed1/Object/Torques/Tgrav/Gain4" , 1 , "linear" , 1
, 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW .
m10l43wuz3 . SignalProbe = signalProbe ; } tmp = muDoubleScalarFloor ( rtP .
WhiteNoise_Seed_kw4ej5243j ) ; if ( muDoubleScalarIsNaN ( tmp ) ||
muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem
( tmp , 4.294967296E+9 ) ; } tseed = tmp < 0.0 ? ( uint32_T ) - ( int32_T ) (
uint32_T ) - tmp : ( uint32_T ) tmp ; r = ( int32_T ) ( tseed >> 16U ) ; t =
( int32_T ) ( tseed & 32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r <<
16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed < 1U ) { tseed = 1144108930U ;
} else { if ( tseed > 2147483646U ) { tseed = 2147483646U ; } } rtDW .
k2mw3e5m15 = tseed ; rtDW . phocmexnl1 = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW
. k2mw3e5m15 ) * rtP . WhiteNoise_StdDev_esrovvidoo + rtP .
WhiteNoise_Mean_fpnv13epd5 ; rtDW . pfcneilmew = 0 ; MdlInitialize ( ) ; }
void MdlOutputs ( int_T tid ) { BusObject la1hfx5r2w ; real_T ivszce53hq [ 4
] ; real_T oydzcnlmnv [ 3 ] ; int32_T k ; int32_T idxB ; int32_T idxLU ;
real_T bguqm55hxa [ 3 ] ; real_T enzyytwikn ; real_T m2b1vgca5s [ 9 ] ;
real_T nfwwjxsmuk ; int8_T rtPrevAction ; int8_T rtAction ; real_T hu2gcgsgxf
; real_T pmaszljcaa [ 9 ] ; real_T jyfgwidcz5 [ 9 ] ; real_T ctzdfomcpm [ 9 ]
; real_T e2tqctvrj0 [ 9 ] ; real_T dm2gdf32t4 [ 9 ] ; real_T ldts3pfwss [ 9 ]
; real_T iq4emno1ma [ 9 ] ; real_T nvadtslxwe [ 9 ] ; real_T jqwtr5xyw4 [ 9 ]
; int32_T i ; int32_T i_p ; real_T hqjmealduc_p [ 10 ] ; real_T
kpgrz5rhip_idx ; real_T oducdqkgjs_idx ; real_T oducdqkgjs_idx_p ; real_T
oducdqkgjs_idx_e ; real_T kpgrz5rhip_idx_p ; real_T kpgrz5rhip_idx_e ;
srClearBC ( rtDW . kkm1wjx4mr ) ; srClearBC ( rtDW . lflksa1zm2 ) ; srClearBC
( rtDW . mo3k54wqkm ) ; srClearBC ( rtDW . emy0hrjuzr ) ; srClearBC ( rtDW .
g325dldung ) ; srClearBC ( rtDW . espotkwrxj ) ; srClearBC ( rtDW .
occ4jhal5v ) ; srClearBC ( rtDW . k5kqzwhgid ) ; srClearBC ( rtDW .
gvkoaih0tt ) ; srClearBC ( rtDW . fw1wxjvjvv ) ; { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 0 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 0 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 0 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & la1hfx5r2w . j2000 [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
pDataValues += 980 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . bknzq3wgub . RSimInfoPtr [ 0 ] ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . fibx4ptf5m . PrevIndex [ 0 ] =
currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 =
pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & la1hfx5r2w . j2000 [ 0
] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; }
} } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
la1hfx5r2w . j2000 [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
la1hfx5r2w . j2000 [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 1 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 1 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 1 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & la1hfx5r2w . vj2000 [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
pDataValues += 980 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . bknzq3wgub . RSimInfoPtr [ 1 ] ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . fibx4ptf5m . PrevIndex [ 1 ] =
currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 =
pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & la1hfx5r2w . vj2000 [
0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ;
} } } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
la1hfx5r2w . vj2000 [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
la1hfx5r2w . vj2000 [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 2 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 2 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 2 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & la1hfx5r2w . Worbj [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
pDataValues += 980 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . bknzq3wgub . RSimInfoPtr [ 2 ] ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . fibx4ptf5m . PrevIndex [ 2 ] =
currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 =
pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & la1hfx5r2w . Worbj [ 0
] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; }
} } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
la1hfx5r2w . Worbj [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
la1hfx5r2w . Worbj [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 3 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 3 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 3 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & la1hfx5r2w . rsun [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
pDataValues += 980 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . bknzq3wgub . RSimInfoPtr [ 3 ] ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . fibx4ptf5m . PrevIndex [ 3 ] =
currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 =
pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & la1hfx5r2w . rsun [ 0
] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; }
} } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
la1hfx5r2w . rsun [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
la1hfx5r2w . rsun [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 , f1
, f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 4 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 4 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 4 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & la1hfx5r2w . rrsuno [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
pDataValues += 980 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . bknzq3wgub . RSimInfoPtr [ 4 ] ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . fibx4ptf5m . PrevIndex [ 4 ] =
currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 =
pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & la1hfx5r2w . rrsuno [
0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ;
} } } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
la1hfx5r2w . rrsuno [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
la1hfx5r2w . rrsuno [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } } } rtB . njvqg5q4aw [ 0 ] =
la1hfx5r2w . j2000 [ 0 ] + rtP . Noise_Value [ 0 ] ; rtB . njvqg5q4aw [ 1 ] =
la1hfx5r2w . j2000 [ 1 ] + rtP . Noise_Value [ 1 ] ; rtB . njvqg5q4aw [ 2 ] =
la1hfx5r2w . j2000 [ 2 ] + rtP . Noise_Value [ 2 ] ; if ( ssIsSampleHit ( rtS
, 4 , 0 ) ) { rtB . jmiuxj1x02 [ 0 ] = rtB . njvqg5q4aw [ 0 ] ; rtB .
jmiuxj1x02 [ 1 ] = rtB . njvqg5q4aw [ 1 ] ; rtB . jmiuxj1x02 [ 2 ] = rtB .
njvqg5q4aw [ 2 ] ; bguqm55hxa [ 0 ] = rtB . jmiuxj1x02 [ 0 ] * rtB .
jmiuxj1x02 [ 0 ] ; bguqm55hxa [ 1 ] = rtB . jmiuxj1x02 [ 1 ] * rtB .
jmiuxj1x02 [ 1 ] ; bguqm55hxa [ 2 ] = rtB . jmiuxj1x02 [ 2 ] * rtB .
jmiuxj1x02 [ 2 ] ; enzyytwikn = ( bguqm55hxa [ 0 ] + bguqm55hxa [ 1 ] ) +
bguqm55hxa [ 2 ] ; if ( enzyytwikn < 0.0 ) { rtB . pdvhflqrm1 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( enzyytwikn ) ) ; } else { rtB .
pdvhflqrm1 = muDoubleScalarSqrt ( enzyytwikn ) ; } rtB . mtdbzc3klf [ 0 ] =
rtB . jmiuxj1x02 [ 0 ] * 0.0 ; rtB . mtdbzc3klf [ 1 ] = rtB . jmiuxj1x02 [ 1
] * 0.0 ; rtB . mtdbzc3klf [ 2 ] = rtB . jmiuxj1x02 [ 2 ] * 0.0 ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB . pdvhflqrm1 > rtP .
Switch_Threshold ) { enzyytwikn = rtB . jmiuxj1x02 [ 0 ] ; kpgrz5rhip_idx_p =
rtB . jmiuxj1x02 [ 1 ] ; kpgrz5rhip_idx_e = rtB . jmiuxj1x02 [ 2 ] ; } else {
enzyytwikn = rtB . mtdbzc3klf [ 0 ] ; kpgrz5rhip_idx_p = rtB . mtdbzc3klf [ 1
] ; kpgrz5rhip_idx_e = rtB . mtdbzc3klf [ 2 ] ; } if ( rtB . pdvhflqrm1 > rtP
. Switch_Threshold ) { kpgrz5rhip_idx = rtB . pdvhflqrm1 ; } else {
kpgrz5rhip_idx = rtP . Constant_Value_bxenkd0bbl ; } oducdqkgjs_idx_e =
enzyytwikn / kpgrz5rhip_idx ; oducdqkgjs_idx = kpgrz5rhip_idx_p /
kpgrz5rhip_idx ; oducdqkgjs_idx_p = kpgrz5rhip_idx_e / kpgrz5rhip_idx ; } rtB
. e2xzeznz0p [ 0 ] = la1hfx5r2w . vj2000 [ 0 ] + rtP . Noise1_Value [ 0 ] ;
rtB . e2xzeznz0p [ 1 ] = la1hfx5r2w . vj2000 [ 1 ] + rtP . Noise1_Value [ 1 ]
; rtB . e2xzeznz0p [ 2 ] = la1hfx5r2w . vj2000 [ 2 ] + rtP . Noise1_Value [ 2
] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB . fnbs1jnt55 [ 0 ] = rtB .
e2xzeznz0p [ 1 ] * rtB . jmiuxj1x02 [ 2 ] - rtB . e2xzeznz0p [ 2 ] * rtB .
jmiuxj1x02 [ 1 ] ; rtB . fnbs1jnt55 [ 1 ] = rtB . e2xzeznz0p [ 2 ] * rtB .
jmiuxj1x02 [ 0 ] - rtB . e2xzeznz0p [ 0 ] * rtB . jmiuxj1x02 [ 2 ] ; rtB .
fnbs1jnt55 [ 2 ] = rtB . e2xzeznz0p [ 0 ] * rtB . jmiuxj1x02 [ 1 ] - rtB .
e2xzeznz0p [ 1 ] * rtB . jmiuxj1x02 [ 0 ] ; bguqm55hxa [ 0 ] = rtB .
fnbs1jnt55 [ 0 ] * rtB . fnbs1jnt55 [ 0 ] ; bguqm55hxa [ 1 ] = rtB .
fnbs1jnt55 [ 1 ] * rtB . fnbs1jnt55 [ 1 ] ; bguqm55hxa [ 2 ] = rtB .
fnbs1jnt55 [ 2 ] * rtB . fnbs1jnt55 [ 2 ] ; enzyytwikn = ( bguqm55hxa [ 0 ] +
bguqm55hxa [ 1 ] ) + bguqm55hxa [ 2 ] ; if ( enzyytwikn < 0.0 ) { rtB .
pnzjj5cy3t = - muDoubleScalarSqrt ( muDoubleScalarAbs ( enzyytwikn ) ) ; }
else { rtB . pnzjj5cy3t = muDoubleScalarSqrt ( enzyytwikn ) ; } rtB .
o3hbrpucbz [ 0 ] = rtB . fnbs1jnt55 [ 0 ] * 0.0 ; rtB . o3hbrpucbz [ 1 ] =
rtB . fnbs1jnt55 [ 1 ] * 0.0 ; rtB . o3hbrpucbz [ 2 ] = rtB . fnbs1jnt55 [ 2
] * 0.0 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB . pnzjj5cy3t >
rtP . Switch_Threshold_gdocqrc4t2 ) { enzyytwikn = rtB . fnbs1jnt55 [ 0 ] ;
kpgrz5rhip_idx_p = rtB . fnbs1jnt55 [ 1 ] ; kpgrz5rhip_idx_e = rtB .
fnbs1jnt55 [ 2 ] ; } else { enzyytwikn = rtB . o3hbrpucbz [ 0 ] ;
kpgrz5rhip_idx_p = rtB . o3hbrpucbz [ 1 ] ; kpgrz5rhip_idx_e = rtB .
o3hbrpucbz [ 2 ] ; } if ( rtB . pnzjj5cy3t > rtP .
Switch_Threshold_gdocqrc4t2 ) { kpgrz5rhip_idx = rtB . pnzjj5cy3t ; } else {
kpgrz5rhip_idx = rtP . Constant_Value_h3j41jz2o2 ; } bguqm55hxa [ 0 ] =
enzyytwikn / kpgrz5rhip_idx ; bguqm55hxa [ 1 ] = kpgrz5rhip_idx_p /
kpgrz5rhip_idx ; bguqm55hxa [ 2 ] = kpgrz5rhip_idx_e / kpgrz5rhip_idx ;
m2b1vgca5s [ 0 ] = oducdqkgjs_idx * bguqm55hxa [ 2 ] - oducdqkgjs_idx_p *
bguqm55hxa [ 1 ] ; m2b1vgca5s [ 1 ] = oducdqkgjs_idx_p * bguqm55hxa [ 0 ] -
oducdqkgjs_idx_e * bguqm55hxa [ 2 ] ; m2b1vgca5s [ 2 ] = oducdqkgjs_idx_e *
bguqm55hxa [ 1 ] - oducdqkgjs_idx * bguqm55hxa [ 0 ] ; m2b1vgca5s [ 3 ] =
oducdqkgjs_idx_e ; m2b1vgca5s [ 4 ] = oducdqkgjs_idx ; m2b1vgca5s [ 5 ] =
oducdqkgjs_idx_p ; m2b1vgca5s [ 6 ] = bguqm55hxa [ 0 ] ; m2b1vgca5s [ 7 ] =
bguqm55hxa [ 1 ] ; m2b1vgca5s [ 8 ] = bguqm55hxa [ 2 ] ; for ( i_p = 0 ; i_p
< 3 ; i_p ++ ) { nvadtslxwe [ 3 * i_p ] = m2b1vgca5s [ i_p ] ; nvadtslxwe [ 1
+ 3 * i_p ] = m2b1vgca5s [ i_p + 3 ] ; nvadtslxwe [ 2 + 3 * i_p ] =
m2b1vgca5s [ i_p + 6 ] ; } bguqm55hxa [ 0 ] = nvadtslxwe [ 0 ] ; bguqm55hxa [
1 ] = nvadtslxwe [ 4 ] ; bguqm55hxa [ 2 ] = nvadtslxwe [ 8 ] ; nfwwjxsmuk = (
nvadtslxwe [ 0 ] + nvadtslxwe [ 4 ] ) + nvadtslxwe [ 8 ] ; rtPrevAction =
rtDW . bwuwpskbe1 ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( nfwwjxsmuk > 0.0
) { rtAction = 0 ; } else { rtAction = 1 ; } rtDW . bwuwpskbe1 = rtAction ; }
else { rtAction = rtDW . bwuwpskbe1 ; } if ( rtPrevAction != rtAction ) {
switch ( rtPrevAction ) { case 0 : ssSetSolverNeedsReset ( rtS ) ; break ;
case 1 : ssSetSolverNeedsReset ( rtS ) ; switch ( rtDW . jenrmeyvts ) { case
0 : ssSetSolverNeedsReset ( rtS ) ; break ; case 1 : ssSetSolverNeedsReset (
rtS ) ; break ; case 2 : ssSetSolverNeedsReset ( rtS ) ; break ; } rtDW .
jenrmeyvts = - 1 ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction
!= rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetSolverNeedsReset ( rtS ) ; } } nfwwjxsmuk += rtP . Constant_Value ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . pzmje2aewl != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . pzmje2aewl = 0 ; } nfwwjxsmuk =
muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if ( nfwwjxsmuk < 0.0 ) {
nfwwjxsmuk = - muDoubleScalarSqrt ( muDoubleScalarAbs ( nfwwjxsmuk ) ) ; }
else { nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } rtDW . pzmje2aewl =
1 ; } rtB . hqqy53kfyu [ 0 ] = rtP . Gain_Gain * nfwwjxsmuk ; nfwwjxsmuk *=
rtP . Gain1_Gain ; rtB . hqqy53kfyu [ 1 ] = ( nvadtslxwe [ 7 ] - nvadtslxwe [
5 ] ) / nfwwjxsmuk ; rtB . hqqy53kfyu [ 2 ] = ( nvadtslxwe [ 2 ] - nvadtslxwe
[ 6 ] ) / nfwwjxsmuk ; rtB . hqqy53kfyu [ 3 ] = ( nvadtslxwe [ 3 ] -
nvadtslxwe [ 1 ] ) / nfwwjxsmuk ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . kkm1wjx4mr ) ; } break ; case 1 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetSolverNeedsReset ( rtS ) ; } } rtPrevAction = rtDW . jenrmeyvts ; if ( (
nvadtslxwe [ 4 ] > nvadtslxwe [ 0 ] ) && ( nvadtslxwe [ 4 ] > nvadtslxwe [ 8
] ) ) { rtAction = 0 ; } else if ( nvadtslxwe [ 8 ] > nvadtslxwe [ 0 ] ) {
rtAction = 1 ; } else { rtAction = 2 ; } rtDW . jenrmeyvts = rtAction ; if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
ssSetSolverNeedsReset ( rtS ) ; break ; case 1 : ssSetSolverNeedsReset ( rtS
) ; break ; case 2 : ssSetSolverNeedsReset ( rtS ) ; break ; } } switch (
rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime (
rtS , 1 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset ( rtS ) ; } }
nfwwjxsmuk = ( ( nvadtslxwe [ 4 ] - nvadtslxwe [ 0 ] ) - nvadtslxwe [ 8 ] ) +
rtP . Constant_Value_itf12sgtld ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtDW . kvbynbt23x != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . kvbynbt23x
= 0 ; } nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if (
nfwwjxsmuk < 0.0 ) { nfwwjxsmuk = - muDoubleScalarSqrt ( muDoubleScalarAbs (
nfwwjxsmuk ) ) ; } else { nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; }
rtDW . kvbynbt23x = 1 ; } rtB . hqqy53kfyu [ 2 ] = rtP . Gain_Gain_iz22fd4qci
* nfwwjxsmuk ; if ( nfwwjxsmuk != 0.0 ) { oducdqkgjs_idx_e = rtP .
Constant1_Value ; } else { oducdqkgjs_idx_e = rtP . Constant2_Value [ 0 ] ;
nfwwjxsmuk = rtP . Constant2_Value [ 1 ] ; } nfwwjxsmuk = oducdqkgjs_idx_e /
nfwwjxsmuk ; bguqm55hxa [ 0 ] = ( nvadtslxwe [ 1 ] + nvadtslxwe [ 3 ] ) *
nfwwjxsmuk ; bguqm55hxa [ 1 ] = ( nvadtslxwe [ 5 ] + nvadtslxwe [ 7 ] ) *
nfwwjxsmuk ; bguqm55hxa [ 2 ] = ( nvadtslxwe [ 2 ] - nvadtslxwe [ 6 ] ) *
nfwwjxsmuk ; rtB . hqqy53kfyu [ 1 ] = rtP . Gain1_Gain_grzyqbqehm *
bguqm55hxa [ 0 ] ; rtB . hqqy53kfyu [ 3 ] = rtP . Gain3_Gain * bguqm55hxa [ 1
] ; rtB . hqqy53kfyu [ 0 ] = rtP . Gain4_Gain * bguqm55hxa [ 2 ] ; srUpdateBC
( rtDW . lflksa1zm2 ) ; break ; case 1 : if ( rtAction != rtPrevAction ) { if
( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset
( rtS ) ; } } nfwwjxsmuk = ( ( nvadtslxwe [ 8 ] - nvadtslxwe [ 0 ] ) -
nvadtslxwe [ 4 ] ) + rtP . Constant_Value_gaw1lrkj5p ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtDW . bpfxbpnxdk != 0 ) { ssSetSolverNeedsReset ( rtS ) ;
rtDW . bpfxbpnxdk = 0 ; } nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; }
else { if ( nfwwjxsmuk < 0.0 ) { nfwwjxsmuk = - muDoubleScalarSqrt (
muDoubleScalarAbs ( nfwwjxsmuk ) ) ; } else { nfwwjxsmuk = muDoubleScalarSqrt
( nfwwjxsmuk ) ; } rtDW . bpfxbpnxdk = 1 ; } rtB . hqqy53kfyu [ 3 ] = rtP .
Gain_Gain_oxcvfncqox * nfwwjxsmuk ; if ( nfwwjxsmuk != 0.0 ) {
oducdqkgjs_idx_e = rtP . Constant1_Value_odsqffacyt ; } else {
oducdqkgjs_idx_e = rtP . Constant2_Value_jxofe5s4po [ 0 ] ; nfwwjxsmuk = rtP
. Constant2_Value_jxofe5s4po [ 1 ] ; } nfwwjxsmuk = oducdqkgjs_idx_e /
nfwwjxsmuk ; bguqm55hxa [ 0 ] = ( nvadtslxwe [ 2 ] + nvadtslxwe [ 6 ] ) *
nfwwjxsmuk ; bguqm55hxa [ 1 ] = ( nvadtslxwe [ 5 ] + nvadtslxwe [ 7 ] ) *
nfwwjxsmuk ; bguqm55hxa [ 2 ] = ( nvadtslxwe [ 3 ] - nvadtslxwe [ 1 ] ) *
nfwwjxsmuk ; rtB . hqqy53kfyu [ 1 ] = rtP . Gain1_Gain_bmy2by4h1w *
bguqm55hxa [ 0 ] ; rtB . hqqy53kfyu [ 2 ] = rtP . Gain2_Gain * bguqm55hxa [ 1
] ; rtB . hqqy53kfyu [ 0 ] = rtP . Gain3_Gain_pjvn2rjs3s * bguqm55hxa [ 2 ] ;
srUpdateBC ( rtDW . mo3k54wqkm ) ; break ; case 2 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetSolverNeedsReset ( rtS ) ; } } nfwwjxsmuk = ( ( nvadtslxwe [ 0 ] -
nvadtslxwe [ 4 ] ) - nvadtslxwe [ 8 ] ) + rtP . Constant_Value_pnagrbecg0 ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . frxkwgelef != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . frxkwgelef = 0 ; } nfwwjxsmuk =
muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if ( nfwwjxsmuk < 0.0 ) {
nfwwjxsmuk = - muDoubleScalarSqrt ( muDoubleScalarAbs ( nfwwjxsmuk ) ) ; }
else { nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } rtDW . frxkwgelef =
1 ; } rtB . hqqy53kfyu [ 1 ] = rtP . Gain_Gain_pkrlyfmnay * nfwwjxsmuk ; if (
nfwwjxsmuk != 0.0 ) { oducdqkgjs_idx_e = rtP . Constant1_Value_joyqlwe5wz ; }
else { oducdqkgjs_idx_e = rtP . Constant2_Value_jw5vkxzlyu [ 0 ] ; nfwwjxsmuk
= rtP . Constant2_Value_jw5vkxzlyu [ 1 ] ; } nfwwjxsmuk = oducdqkgjs_idx_e /
nfwwjxsmuk ; bguqm55hxa [ 0 ] = ( nvadtslxwe [ 1 ] + nvadtslxwe [ 3 ] ) *
nfwwjxsmuk ; bguqm55hxa [ 1 ] = ( nvadtslxwe [ 2 ] + nvadtslxwe [ 6 ] ) *
nfwwjxsmuk ; bguqm55hxa [ 2 ] = ( nvadtslxwe [ 7 ] - nvadtslxwe [ 5 ] ) *
nfwwjxsmuk ; rtB . hqqy53kfyu [ 2 ] = rtP . Gain1_Gain_co11ew42wt *
bguqm55hxa [ 0 ] ; rtB . hqqy53kfyu [ 3 ] = rtP . Gain2_Gain_dbcigpbpah *
bguqm55hxa [ 1 ] ; rtB . hqqy53kfyu [ 0 ] = rtP . Gain3_Gain_keytyfb2hv *
bguqm55hxa [ 2 ] ; srUpdateBC ( rtDW . emy0hrjuzr ) ; break ; } if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . g325dldung ) ; } break ; }
if ( rtB . hqqy53kfyu [ 0 ] >= rtP . Switch_Threshold_cstc3foesz ) {
hu2gcgsgxf = rtP . Constant_Value_eabu3cwr2x ; } else { hu2gcgsgxf = rtP .
Constant1_Value_gxe1evpehu ; } enzyytwikn = hu2gcgsgxf * rtB . hqqy53kfyu [ 0
] ; kpgrz5rhip_idx_p = hu2gcgsgxf * rtB . hqqy53kfyu [ 1 ] ; kpgrz5rhip_idx_e
= hu2gcgsgxf * rtB . hqqy53kfyu [ 2 ] ; kpgrz5rhip_idx = hu2gcgsgxf * rtB .
hqqy53kfyu [ 3 ] ; hu2gcgsgxf = ( ( enzyytwikn * enzyytwikn +
kpgrz5rhip_idx_p * kpgrz5rhip_idx_p ) + kpgrz5rhip_idx_e * kpgrz5rhip_idx_e )
+ kpgrz5rhip_idx * kpgrz5rhip_idx ; rtB . awz2s5os2f = enzyytwikn /
hu2gcgsgxf ; nfwwjxsmuk = ( ( rtP . Qjo_init_Value [ 0 ] * rtP .
Qob_init_Value [ 0 ] - rtP . Qjo_init_Value [ 1 ] * rtP . Qob_init_Value [ 1
] ) - rtP . Qjo_init_Value [ 2 ] * rtP . Qob_init_Value [ 2 ] ) - rtP .
Qjo_init_Value [ 3 ] * rtP . Qob_init_Value [ 3 ] ; if ( nfwwjxsmuk >= rtP .
Switch_Threshold_cnjrei0kod ) { enzyytwikn = rtP . Constant_Value_lkzxmgm0bn
; } else { enzyytwikn = rtP . Constant1_Value_chkyuiwcbu ; } rtB . ber5tetftf
[ 0 ] = enzyytwikn * nfwwjxsmuk ; rtB . ber5tetftf [ 1 ] = ( ( ( rtP .
Qjo_init_Value [ 0 ] * rtP . Qob_init_Value [ 1 ] + rtP . Qjo_init_Value [ 1
] * rtP . Qob_init_Value [ 0 ] ) + rtP . Qjo_init_Value [ 2 ] * rtP .
Qob_init_Value [ 3 ] ) - rtP . Qjo_init_Value [ 3 ] * rtP . Qob_init_Value [
2 ] ) * enzyytwikn ; rtB . ber5tetftf [ 2 ] = ( ( ( rtP . Qjo_init_Value [ 0
] * rtP . Qob_init_Value [ 2 ] - rtP . Qjo_init_Value [ 1 ] * rtP .
Qob_init_Value [ 3 ] ) + rtP . Qjo_init_Value [ 2 ] * rtP . Qob_init_Value [
0 ] ) + rtP . Qjo_init_Value [ 3 ] * rtP . Qob_init_Value [ 1 ] ) *
enzyytwikn ; rtB . ber5tetftf [ 3 ] = ( ( ( rtP . Qjo_init_Value [ 0 ] * rtP
. Qob_init_Value [ 3 ] + rtP . Qjo_init_Value [ 1 ] * rtP . Qob_init_Value [
2 ] ) - rtP . Qjo_init_Value [ 2 ] * rtP . Qob_init_Value [ 1 ] ) + rtP .
Qjo_init_Value [ 3 ] * rtP . Qob_init_Value [ 0 ] ) * enzyytwikn ; } if (
rtDW . evzrtqyrte . IcNeedsLoading ) { rtX . b1lr14rcuj [ 0 ] = rtB .
ber5tetftf [ 0 ] ; rtX . b1lr14rcuj [ 1 ] = rtB . ber5tetftf [ 1 ] ; rtX .
b1lr14rcuj [ 2 ] = rtB . ber5tetftf [ 2 ] ; rtX . b1lr14rcuj [ 3 ] = rtB .
ber5tetftf [ 3 ] ; } rtB . cjc4bi0q0l [ 0 ] = rtX . b1lr14rcuj [ 0 ] ; rtB .
cjc4bi0q0l [ 1 ] = rtX . b1lr14rcuj [ 1 ] ; rtB . cjc4bi0q0l [ 2 ] = rtX .
b1lr14rcuj [ 2 ] ; rtB . cjc4bi0q0l [ 3 ] = rtX . b1lr14rcuj [ 3 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . j55ahl4b2c = - kpgrz5rhip_idx_p /
hu2gcgsgxf ; rtB . mbcfnz4gfg = - kpgrz5rhip_idx_e / hu2gcgsgxf ; rtB .
j4celd1eit = - kpgrz5rhip_idx / hu2gcgsgxf ; } rtB . bwyuqwyvcb = ( ( rtB .
awz2s5os2f * rtB . cjc4bi0q0l [ 0 ] - rtB . j55ahl4b2c * rtB . cjc4bi0q0l [ 1
] ) - rtB . mbcfnz4gfg * rtB . cjc4bi0q0l [ 2 ] ) - rtB . j4celd1eit * rtB .
cjc4bi0q0l [ 3 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . bn411rqyba = (
rtB . bwyuqwyvcb >= rtP . Switch_Threshold_l3zqxo5bwe ) ; } if ( rtDW .
bn411rqyba ) { nfwwjxsmuk = rtP . Constant_Value_ok5wcdghto ; } else {
nfwwjxsmuk = rtP . Constant1_Value_nmcgqsupce ; } rtB . fz0figaoto [ 0 ] =
nfwwjxsmuk * rtB . bwyuqwyvcb ; rtB . fz0figaoto [ 1 ] = ( ( ( rtB .
awz2s5os2f * rtB . cjc4bi0q0l [ 1 ] + rtB . j55ahl4b2c * rtB . cjc4bi0q0l [ 0
] ) + rtB . mbcfnz4gfg * rtB . cjc4bi0q0l [ 3 ] ) - rtB . j4celd1eit * rtB .
cjc4bi0q0l [ 2 ] ) * nfwwjxsmuk ; rtB . fz0figaoto [ 2 ] = ( ( ( rtB .
awz2s5os2f * rtB . cjc4bi0q0l [ 2 ] - rtB . j55ahl4b2c * rtB . cjc4bi0q0l [ 3
] ) + rtB . mbcfnz4gfg * rtB . cjc4bi0q0l [ 0 ] ) + rtB . j4celd1eit * rtB .
cjc4bi0q0l [ 1 ] ) * nfwwjxsmuk ; rtB . fz0figaoto [ 3 ] = ( ( ( rtB .
awz2s5os2f * rtB . cjc4bi0q0l [ 3 ] + rtB . j55ahl4b2c * rtB . cjc4bi0q0l [ 2
] ) - rtB . mbcfnz4gfg * rtB . cjc4bi0q0l [ 1 ] ) + rtB . j4celd1eit * rtB .
cjc4bi0q0l [ 0 ] ) * nfwwjxsmuk ; oducdqkgjs_idx = rtB . fz0figaoto [ 0 ] -
rtP . Constant_Value_jd4yybwihf ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for
( i = 0 ; i < 9 ; i ++ ) { rtB . ihj3tr11iv [ i ] = rtP .
Constant_Value_gvhcouy2li [ i ] + rtP . Constant_Value_egr1tn4q2z [ i ] ; }
rtB . n1iqi5rfxp [ 0 ] = rtP . Constant_Value_jrc3i5y0a4 [ 0 ] ; rtB .
n1iqi5rfxp [ 1 ] = rtP . Constant_Value_jrc3i5y0a4 [ 1 ] ; rtB . n1iqi5rfxp [
2 ] = rtP . Constant_Value_jrc3i5y0a4 [ 2 ] ; } if ( rtDW . l3ydkkphoy .
IcNeedsLoading ) { rtX . ba1rjb3ky4 [ 0 ] = rtB . n1iqi5rfxp [ 0 ] ; rtX .
ba1rjb3ky4 [ 1 ] = rtB . n1iqi5rfxp [ 1 ] ; rtX . ba1rjb3ky4 [ 2 ] = rtB .
n1iqi5rfxp [ 2 ] ; } rtB . lronvhy5ya [ 0 ] = rtX . ba1rjb3ky4 [ 0 ] ; rtB .
lronvhy5ya [ 1 ] = rtX . ba1rjb3ky4 [ 1 ] ; rtB . lronvhy5ya [ 2 ] = rtX .
ba1rjb3ky4 [ 2 ] ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { bguqm55hxa [ i_p ] =
rtB . ihj3tr11iv [ i_p + 6 ] * rtB . lronvhy5ya [ 2 ] + ( rtB . ihj3tr11iv [
i_p + 3 ] * rtB . lronvhy5ya [ 1 ] + rtB . ihj3tr11iv [ i_p ] * rtB .
lronvhy5ya [ 0 ] ) ; } oydzcnlmnv [ 0 ] = rtX . hod35jdtrz [ 0 ] ; oydzcnlmnv
[ 1 ] = rtX . hod35jdtrz [ 1 ] ; oydzcnlmnv [ 2 ] = rtX . hod35jdtrz [ 2 ] ;
if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB . m0g2rkinvl [ 0 ] = rtP .
Output_Gain [ 0 ] * rtDW . m5suqpxty3 ; rtB . m0g2rkinvl [ 1 ] = rtP .
Output_Gain [ 1 ] * rtDW . m5suqpxty3 ; rtB . m0g2rkinvl [ 2 ] = rtP .
Output_Gain [ 2 ] * rtDW . m5suqpxty3 ; } rtB . o5eruvbnew [ 0 ] = (
bguqm55hxa [ 0 ] + oydzcnlmnv [ 0 ] ) + rtB . m0g2rkinvl [ 0 ] ; rtB .
o5eruvbnew [ 1 ] = ( bguqm55hxa [ 1 ] + oydzcnlmnv [ 1 ] ) + rtB . m0g2rkinvl
[ 1 ] ; rtB . o5eruvbnew [ 2 ] = ( bguqm55hxa [ 2 ] + oydzcnlmnv [ 2 ] ) +
rtB . m0g2rkinvl [ 2 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB .
kwssbn0ne4 [ 0 ] = rtB . o5eruvbnew [ 0 ] ; rtB . kwssbn0ne4 [ 1 ] = rtB .
o5eruvbnew [ 1 ] ; rtB . kwssbn0ne4 [ 2 ] = rtB . o5eruvbnew [ 2 ] ;
nfwwjxsmuk = ( muDoubleScalarPower ( rtB . jmiuxj1x02 [ 0 ] , 2.0 ) +
muDoubleScalarPower ( rtB . jmiuxj1x02 [ 1 ] , 2.0 ) ) + muDoubleScalarPower
( rtB . jmiuxj1x02 [ 2 ] , 2.0 ) ; rtB . kcl5mw42rb [ 0 ] = rtP .
Gain_Gain_imjwpylc20 * rtB . fnbs1jnt55 [ 0 ] / nfwwjxsmuk ; rtB . kcl5mw42rb
[ 1 ] = rtP . Gain_Gain_imjwpylc20 * rtB . fnbs1jnt55 [ 1 ] / nfwwjxsmuk ;
rtB . kcl5mw42rb [ 2 ] = rtP . Gain_Gain_imjwpylc20 * rtB . fnbs1jnt55 [ 2 ]
/ nfwwjxsmuk ; } enzyytwikn = ( ( rtB . cjc4bi0q0l [ 0 ] * rtB . cjc4bi0q0l [
0 ] + rtB . cjc4bi0q0l [ 1 ] * rtB . cjc4bi0q0l [ 1 ] ) + rtB . cjc4bi0q0l [
2 ] * rtB . cjc4bi0q0l [ 2 ] ) + rtB . cjc4bi0q0l [ 3 ] * rtB . cjc4bi0q0l [
3 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . l33pfglk2a != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . l33pfglk2a = 0 ; } enzyytwikn =
muDoubleScalarSqrt ( enzyytwikn ) ; } else { if ( enzyytwikn < 0.0 ) {
enzyytwikn = - muDoubleScalarSqrt ( muDoubleScalarAbs ( enzyytwikn ) ) ; }
else { enzyytwikn = muDoubleScalarSqrt ( enzyytwikn ) ; } rtDW . l33pfglk2a =
1 ; } hu2gcgsgxf = rtB . cjc4bi0q0l [ 2 ] / enzyytwikn ; nfwwjxsmuk = rtB .
cjc4bi0q0l [ 3 ] / enzyytwikn ; oducdqkgjs_idx_p = rtB . cjc4bi0q0l [ 1 ] /
enzyytwikn ; enzyytwikn = rtB . cjc4bi0q0l [ 0 ] / enzyytwikn ; rtB .
p05flgh0s0 [ 0 ] = rtB . kwssbn0ne4 [ 0 ] - ( ( ( ( rtP .
Constant_Value_gfamwgvgio - hu2gcgsgxf * hu2gcgsgxf ) - nfwwjxsmuk *
nfwwjxsmuk ) * rtP . Gain2_Gain_hsczlo4ztj * rtB . kcl5mw42rb [ 0 ] + (
oducdqkgjs_idx_p * hu2gcgsgxf + enzyytwikn * nfwwjxsmuk ) * rtP .
Gain_Gain_mwczkktdza * rtB . kcl5mw42rb [ 1 ] ) + ( oducdqkgjs_idx_p *
nfwwjxsmuk - enzyytwikn * hu2gcgsgxf ) * rtP . Gain1_Gain_jcffkkjw2g * rtB .
kcl5mw42rb [ 2 ] ) ; rtB . p05flgh0s0 [ 1 ] = rtB . kwssbn0ne4 [ 1 ] - ( ( (
( rtP . Constant_Value_alyo2kghso - oducdqkgjs_idx_p * oducdqkgjs_idx_p ) -
nfwwjxsmuk * nfwwjxsmuk ) * rtP . Gain2_Gain_bnubngmvnh * rtB . kcl5mw42rb [
1 ] + ( oducdqkgjs_idx_p * hu2gcgsgxf - enzyytwikn * nfwwjxsmuk ) * rtP .
Gain_Gain_keh1ebxthv * rtB . kcl5mw42rb [ 0 ] ) + ( enzyytwikn *
oducdqkgjs_idx_p + hu2gcgsgxf * nfwwjxsmuk ) * rtP . Gain1_Gain_kck2izenjg *
rtB . kcl5mw42rb [ 2 ] ) ; rtB . p05flgh0s0 [ 2 ] = rtB . kwssbn0ne4 [ 2 ] -
( ( ( oducdqkgjs_idx_p * nfwwjxsmuk + enzyytwikn * hu2gcgsgxf ) * rtP .
Gain_Gain_m1esafctux * rtB . kcl5mw42rb [ 0 ] + ( hu2gcgsgxf * nfwwjxsmuk -
enzyytwikn * oducdqkgjs_idx_p ) * rtP . Gain1_Gain_gpeez3rcld * rtB .
kcl5mw42rb [ 1 ] ) + ( ( rtP . Constant_Value_jrgvdhmfe2 - oducdqkgjs_idx_p *
oducdqkgjs_idx_p ) - hu2gcgsgxf * hu2gcgsgxf ) * rtP . Gain2_Gain_nv4m22xdcw
* rtB . kcl5mw42rb [ 2 ] ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
neym5ecad1 [ 0 ] = rtP . Gain1_Gain_cz2xpyyxre * rtP . ChangeMe_Value [ 0 ] ;
rtB . neym5ecad1 [ 1 ] = rtP . Gain1_Gain_cz2xpyyxre * rtP . ChangeMe_Value [
1 ] ; rtB . neym5ecad1 [ 2 ] = rtP . Gain1_Gain_cz2xpyyxre * rtP .
ChangeMe_Value [ 2 ] ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX .
al32ndubg1 [ 0 ] >= rtP . IntegratorLimited_UpperSat ) { rtX . al32ndubg1 [ 0
] = rtP . IntegratorLimited_UpperSat ; } else if ( rtX . al32ndubg1 [ 0 ] <=
rtP . IntegratorLimited_LowerSat ) { rtX . al32ndubg1 [ 0 ] = rtP .
IntegratorLimited_LowerSat ; } if ( rtX . al32ndubg1 [ 1 ] >= rtP .
IntegratorLimited_UpperSat ) { rtX . al32ndubg1 [ 1 ] = rtP .
IntegratorLimited_UpperSat ; } else if ( rtX . al32ndubg1 [ 1 ] <= rtP .
IntegratorLimited_LowerSat ) { rtX . al32ndubg1 [ 1 ] = rtP .
IntegratorLimited_LowerSat ; } if ( rtX . al32ndubg1 [ 2 ] >= rtP .
IntegratorLimited_UpperSat ) { rtX . al32ndubg1 [ 2 ] = rtP .
IntegratorLimited_UpperSat ; } else if ( rtX . al32ndubg1 [ 2 ] <= rtP .
IntegratorLimited_LowerSat ) { rtX . al32ndubg1 [ 2 ] = rtP .
IntegratorLimited_LowerSat ; } } rtB . obj5e4e3db [ 0 ] = rtX . al32ndubg1 [
0 ] ; rtB . obj5e4e3db [ 1 ] = rtX . al32ndubg1 [ 1 ] ; rtB . obj5e4e3db [ 2
] = rtX . al32ndubg1 [ 2 ] ; rtB . h5ipoluxjw [ 0 ] = rtP .
Constant1_Value_pibyfcp5ht [ 0 ] * rtB . obj5e4e3db [ 0 ] * rtP .
Gain2_Gain_g3pgvavbec ; rtB . h5ipoluxjw [ 1 ] = rtP .
Constant1_Value_pibyfcp5ht [ 1 ] * rtB . obj5e4e3db [ 0 ] * rtP .
Gain2_Gain_g3pgvavbec ; rtB . h5ipoluxjw [ 2 ] = rtP .
Constant1_Value_pibyfcp5ht [ 2 ] * rtB . obj5e4e3db [ 0 ] * rtP .
Gain2_Gain_g3pgvavbec ; rtB . klwhzltza0 [ 0 ] = rtP .
Constant2_Value_erhep10kxc [ 0 ] * rtB . obj5e4e3db [ 1 ] * rtP .
Gain3_Gain_nlnczbyk1z ; rtB . klwhzltza0 [ 1 ] = rtP .
Constant2_Value_erhep10kxc [ 1 ] * rtB . obj5e4e3db [ 1 ] * rtP .
Gain3_Gain_nlnczbyk1z ; rtB . klwhzltza0 [ 2 ] = rtP .
Constant2_Value_erhep10kxc [ 2 ] * rtB . obj5e4e3db [ 1 ] * rtP .
Gain3_Gain_nlnczbyk1z ; rtB . ixebsztwtv [ 0 ] = rtP . Constant3_Value [ 0 ]
* rtB . obj5e4e3db [ 2 ] * rtP . Gain4_Gain_obkdmqncg2 ; rtB . ixebsztwtv [ 1
] = rtP . Constant3_Value [ 1 ] * rtB . obj5e4e3db [ 2 ] * rtP .
Gain4_Gain_obkdmqncg2 ; rtB . ixebsztwtv [ 2 ] = rtP . Constant3_Value [ 2 ]
* rtB . obj5e4e3db [ 2 ] * rtP . Gain4_Gain_obkdmqncg2 ; rtB . fwgif0j4xy [ 0
] = ( ( rtB . neym5ecad1 [ 0 ] + rtB . h5ipoluxjw [ 0 ] ) + rtB . klwhzltza0
[ 0 ] ) + rtB . ixebsztwtv [ 0 ] ; rtB . fwgif0j4xy [ 1 ] = ( ( rtB .
neym5ecad1 [ 1 ] + rtB . h5ipoluxjw [ 1 ] ) + rtB . klwhzltza0 [ 1 ] ) + rtB
. ixebsztwtv [ 1 ] ; rtB . fwgif0j4xy [ 2 ] = ( ( rtB . neym5ecad1 [ 2 ] +
rtB . h5ipoluxjw [ 2 ] ) + rtB . klwhzltza0 [ 2 ] ) + rtB . ixebsztwtv [ 2 ]
; rtB . dbwyygj2mo [ 0 ] = rtP . Gain6_Gain * rtB . fwgif0j4xy [ 0 ] ; rtB .
dbwyygj2mo [ 1 ] = rtP . Gain6_Gain * rtB . fwgif0j4xy [ 1 ] ; rtB .
dbwyygj2mo [ 2 ] = rtP . Gain6_Gain * rtB . fwgif0j4xy [ 2 ] ; hqjmealduc_p [
0 ] = oducdqkgjs_idx ; hqjmealduc_p [ 1 ] = rtB . fz0figaoto [ 1 ] ;
hqjmealduc_p [ 2 ] = rtB . fz0figaoto [ 2 ] ; hqjmealduc_p [ 3 ] = rtB .
fz0figaoto [ 3 ] ; hqjmealduc_p [ 4 ] = rtB . p05flgh0s0 [ 0 ] ; hqjmealduc_p
[ 5 ] = rtB . p05flgh0s0 [ 1 ] ; hqjmealduc_p [ 6 ] = rtB . p05flgh0s0 [ 2 ]
; hqjmealduc_p [ 7 ] = rtB . dbwyygj2mo [ 0 ] ; hqjmealduc_p [ 8 ] = rtB .
dbwyygj2mo [ 1 ] ; hqjmealduc_p [ 9 ] = rtB . dbwyygj2mo [ 2 ] ; for ( i_p =
0 ; i_p < 3 ; i_p ++ ) { oydzcnlmnv [ i_p ] = 0.0 ; for ( i = 0 ; i < 10 ; i
++ ) { oydzcnlmnv [ i_p ] += rtP . Constant4_Value [ 3 * i + i_p ] *
hqjmealduc_p [ i ] ; } } rtB . nye0gvpgkn [ 0 ] = oydzcnlmnv [ 0 ] * rtP .
Constant1_Value_fciw0lu1dl / rtP . Constant3_Value_cxfy0sjqiz * rtP .
Gain_Gain_fzpdiqcchq ; rtB . nye0gvpgkn [ 1 ] = oydzcnlmnv [ 1 ] * rtP .
Constant1_Value_fciw0lu1dl / rtP . Constant3_Value_cxfy0sjqiz * rtP .
Gain_Gain_fzpdiqcchq ; rtB . nye0gvpgkn [ 2 ] = oydzcnlmnv [ 2 ] * rtP .
Constant1_Value_fciw0lu1dl / rtP . Constant3_Value_cxfy0sjqiz * rtP .
Gain_Gain_fzpdiqcchq ; if ( ssGetLogOutput ( rtS ) ) { { { void * signalProbe
= ( void * ) rtDW . hzkxwtgg3y . SignalProbe ; real_T t ; void * u ; t =
ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . nye0gvpgkn [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
ethxueuerq . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . obj5e4e3db [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy (
& rtB . iooczl3zbj [ 0 ] , & rtP . ChangeMe3_Value [ 0 ] , 9U * sizeof (
real_T ) ) ; } oydzcnlmnv [ 0 ] = rtB . fz0figaoto [ 0 ] * rtB . fz0figaoto [
1 ] ; oydzcnlmnv [ 1 ] = rtB . fz0figaoto [ 0 ] * rtB . fz0figaoto [ 2 ] ;
oydzcnlmnv [ 2 ] = rtB . fz0figaoto [ 0 ] * rtB . fz0figaoto [ 3 ] ; for (
i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . gcm3v00fw3 [ i_p ] = 0.0 ; rtB .
gcm3v00fw3 [ i_p ] += rtB . iooczl3zbj [ i_p ] * oydzcnlmnv [ 0 ] ; rtB .
gcm3v00fw3 [ i_p ] += rtB . iooczl3zbj [ i_p + 3 ] * oydzcnlmnv [ 1 ] ; rtB .
gcm3v00fw3 [ i_p ] += rtB . iooczl3zbj [ i_p + 6 ] * oydzcnlmnv [ 2 ] ; } if
( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . bilokkqatz [ 0 ] = rtP . Kang_Gain
* rtB . gcm3v00fw3 [ 0 ] ; rtB . bilokkqatz [ 1 ] = rtP . Kang_Gain * rtB .
gcm3v00fw3 [ 1 ] ; rtB . bilokkqatz [ 2 ] = rtP . Kang_Gain * rtB .
gcm3v00fw3 [ 2 ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { oydzcnlmnv [ i_p ]
= 0.0 ; oydzcnlmnv [ i_p ] += rtB . iooczl3zbj [ i_p ] * rtB . p05flgh0s0 [ 0
] ; oydzcnlmnv [ i_p ] += rtB . iooczl3zbj [ i_p + 3 ] * rtB . p05flgh0s0 [ 1
] ; oydzcnlmnv [ i_p ] += rtB . iooczl3zbj [ i_p + 6 ] * rtB . p05flgh0s0 [ 2
] ; } rtB . p4tfma3j1a [ 0 ] = rtP . Krate_Gain * oydzcnlmnv [ 0 ] + rtB .
bilokkqatz [ 0 ] ; rtB . p4tfma3j1a [ 1 ] = rtP . Krate_Gain * oydzcnlmnv [ 1
] + rtB . bilokkqatz [ 1 ] ; rtB . p4tfma3j1a [ 2 ] = rtP . Krate_Gain *
oydzcnlmnv [ 2 ] + rtB . bilokkqatz [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { bguqm55hxa [ i_p ] = rtB .
iooczl3zbj [ i_p + 6 ] * rtB . kwssbn0ne4 [ 2 ] + ( rtB . iooczl3zbj [ i_p +
3 ] * rtB . kwssbn0ne4 [ 1 ] + rtB . iooczl3zbj [ i_p ] * rtB . kwssbn0ne4 [
0 ] ) ; } rtB . brbbovdl2o [ 0 ] = rtB . kwssbn0ne4 [ 1 ] * bguqm55hxa [ 2 ]
- rtB . kwssbn0ne4 [ 2 ] * bguqm55hxa [ 1 ] ; rtB . brbbovdl2o [ 1 ] = rtB .
kwssbn0ne4 [ 2 ] * bguqm55hxa [ 0 ] - rtB . kwssbn0ne4 [ 0 ] * bguqm55hxa [ 2
] ; rtB . brbbovdl2o [ 2 ] = rtB . kwssbn0ne4 [ 0 ] * bguqm55hxa [ 1 ] - rtB
. kwssbn0ne4 [ 1 ] * bguqm55hxa [ 0 ] ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
rtB . e2dsphxszg [ i_p ] = 0.0 ; rtB . e2dsphxszg [ i_p ] += rtP .
ChangeMe1_Value [ i_p ] * rtB . kwssbn0ne4 [ 0 ] ; rtB . e2dsphxszg [ i_p ]
+= rtP . ChangeMe1_Value [ i_p + 3 ] * rtB . kwssbn0ne4 [ 1 ] ; rtB .
e2dsphxszg [ i_p ] += rtP . ChangeMe1_Value [ i_p + 6 ] * rtB . kwssbn0ne4 [
2 ] ; } rtB . gdyvpgriuc [ 0 ] = rtB . kwssbn0ne4 [ 1 ] * rtP .
ChangeMe2_Value [ 2 ] - rtB . kwssbn0ne4 [ 2 ] * rtP . ChangeMe2_Value [ 1 ]
; rtB . gdyvpgriuc [ 1 ] = rtB . kwssbn0ne4 [ 2 ] * rtP . ChangeMe2_Value [ 0
] - rtB . kwssbn0ne4 [ 0 ] * rtP . ChangeMe2_Value [ 2 ] ; rtB . gdyvpgriuc [
2 ] = rtB . kwssbn0ne4 [ 0 ] * rtP . ChangeMe2_Value [ 1 ] - rtB . kwssbn0ne4
[ 1 ] * rtP . ChangeMe2_Value [ 0 ] ; } rtB . jty1zsef01 [ 0 ] = ( ( rtB .
p4tfma3j1a [ 0 ] - rtB . brbbovdl2o [ 0 ] ) - rtB . e2dsphxszg [ 0 ] ) - rtB
. gdyvpgriuc [ 0 ] ; rtB . jty1zsef01 [ 1 ] = ( ( rtB . p4tfma3j1a [ 1 ] -
rtB . brbbovdl2o [ 1 ] ) - rtB . e2dsphxszg [ 1 ] ) - rtB . gdyvpgriuc [ 1 ]
; rtB . jty1zsef01 [ 2 ] = ( ( rtB . p4tfma3j1a [ 2 ] - rtB . brbbovdl2o [ 2
] ) - rtB . e2dsphxszg [ 2 ] ) - rtB . gdyvpgriuc [ 2 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . o1tdlyssu3 [ 0 ] = rtB . jty1zsef01 [ 0
] >= rtP . Saturation_UpperSat ? 1 : rtB . jty1zsef01 [ 0 ] > rtP .
Saturation_LowerSat ? 0 : - 1 ; rtDW . o1tdlyssu3 [ 1 ] = rtB . jty1zsef01 [
1 ] >= rtP . Saturation_UpperSat ? 1 : rtB . jty1zsef01 [ 1 ] > rtP .
Saturation_LowerSat ? 0 : - 1 ; rtDW . o1tdlyssu3 [ 2 ] = rtB . jty1zsef01 [
2 ] >= rtP . Saturation_UpperSat ? 1 : rtB . jty1zsef01 [ 2 ] > rtP .
Saturation_LowerSat ? 0 : - 1 ; } oydzcnlmnv [ 0 ] = rtDW . o1tdlyssu3 [ 0 ]
== 1 ? rtP . Saturation_UpperSat : rtDW . o1tdlyssu3 [ 0 ] == - 1 ? rtP .
Saturation_LowerSat : rtB . jty1zsef01 [ 0 ] ; oydzcnlmnv [ 1 ] = rtDW .
o1tdlyssu3 [ 1 ] == 1 ? rtP . Saturation_UpperSat : rtDW . o1tdlyssu3 [ 1 ]
== - 1 ? rtP . Saturation_LowerSat : rtB . jty1zsef01 [ 1 ] ; oydzcnlmnv [ 2
] = rtDW . o1tdlyssu3 [ 2 ] == 1 ? rtP . Saturation_UpperSat : rtDW .
o1tdlyssu3 [ 2 ] == - 1 ? rtP . Saturation_LowerSat : rtB . jty1zsef01 [ 2 ]
; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . l4ynfqsuix [ 0 ] = oydzcnlmnv
[ 0 ] ; rtB . l4ynfqsuix [ 1 ] = oydzcnlmnv [ 1 ] ; rtB . l4ynfqsuix [ 2 ] =
oydzcnlmnv [ 2 ] ; } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX . abpf02yfny
[ 0 ] >= rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ) { rtX . abpf02yfny [ 0
] = rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ; } else if ( rtX .
abpf02yfny [ 0 ] <= rtP . IntegratorLimited_LowerSat_oacseuhnry ) { rtX .
abpf02yfny [ 0 ] = rtP . IntegratorLimited_LowerSat_oacseuhnry ; } if ( rtX .
abpf02yfny [ 1 ] >= rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ) { rtX .
abpf02yfny [ 1 ] = rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ; } else if (
rtX . abpf02yfny [ 1 ] <= rtP . IntegratorLimited_LowerSat_oacseuhnry ) { rtX
. abpf02yfny [ 1 ] = rtP . IntegratorLimited_LowerSat_oacseuhnry ; } if ( rtX
. abpf02yfny [ 2 ] >= rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ) { rtX .
abpf02yfny [ 2 ] = rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ; } else if (
rtX . abpf02yfny [ 2 ] <= rtP . IntegratorLimited_LowerSat_oacseuhnry ) { rtX
. abpf02yfny [ 2 ] = rtP . IntegratorLimited_LowerSat_oacseuhnry ; } } rtB .
kta3wrejd4 [ 0 ] = rtX . abpf02yfny [ 0 ] ; rtB . kta3wrejd4 [ 1 ] = rtX .
abpf02yfny [ 1 ] ; rtB . kta3wrejd4 [ 2 ] = rtX . abpf02yfny [ 2 ] ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { oducdqkgjs_idx_e = rtP .
Gain1_Gain_dkf041qpaw * rtB . l4ynfqsuix [ 0 ] ; if ( oducdqkgjs_idx_e >= rtP
. Saturation_UpperSat_faael1sbi5 ) { rtB . ajquw4hgfb [ 0 ] = rtP .
Saturation_UpperSat_faael1sbi5 ; } else if ( oducdqkgjs_idx_e <= rtP .
Saturation_LowerSat_agytdqopmw ) { rtB . ajquw4hgfb [ 0 ] = rtP .
Saturation_LowerSat_agytdqopmw ; } else { rtB . ajquw4hgfb [ 0 ] =
oducdqkgjs_idx_e ; } oducdqkgjs_idx_e = rtP . Gain1_Gain_dkf041qpaw * rtB .
l4ynfqsuix [ 1 ] ; if ( oducdqkgjs_idx_e >= rtP .
Saturation_UpperSat_faael1sbi5 ) { rtB . ajquw4hgfb [ 1 ] = rtP .
Saturation_UpperSat_faael1sbi5 ; } else if ( oducdqkgjs_idx_e <= rtP .
Saturation_LowerSat_agytdqopmw ) { rtB . ajquw4hgfb [ 1 ] = rtP .
Saturation_LowerSat_agytdqopmw ; } else { rtB . ajquw4hgfb [ 1 ] =
oducdqkgjs_idx_e ; } oducdqkgjs_idx_e = rtP . Gain1_Gain_dkf041qpaw * rtB .
l4ynfqsuix [ 2 ] ; if ( oducdqkgjs_idx_e >= rtP .
Saturation_UpperSat_faael1sbi5 ) { rtB . ajquw4hgfb [ 2 ] = rtP .
Saturation_UpperSat_faael1sbi5 ; } else if ( oducdqkgjs_idx_e <= rtP .
Saturation_LowerSat_agytdqopmw ) { rtB . ajquw4hgfb [ 2 ] = rtP .
Saturation_LowerSat_agytdqopmw ; } else { rtB . ajquw4hgfb [ 2 ] =
oducdqkgjs_idx_e ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB .
jaerpbqnqm [ 0 ] = rtB . nye0gvpgkn [ 0 ] ; rtB . jaerpbqnqm [ 1 ] = rtB .
nye0gvpgkn [ 1 ] ; rtB . jaerpbqnqm [ 2 ] = rtB . nye0gvpgkn [ 2 ] ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . p5kqeroffv = 0.0 / rtP .
Constant3_Value_lg1rqkvsmt ; } if ( ssGetLogOutput ( rtS ) ) { { { void *
signalProbe = ( void * ) rtDW . mohxnwpvy0 . SignalProbe ; real_T t ; void *
u ; t = ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . fz0figaoto [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
fs3xofbgsa . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . p05flgh0s0 [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
jhekd05k4p = ( rtB . cjc4bi0q0l [ 0 ] >= rtP . Switch_Threshold_ocvrgqhwfd )
; } oducdqkgjs_idx_e = ( rtP . Constant_Value_egwar5iee0 - ( ( ( rtB .
cjc4bi0q0l [ 0 ] * rtB . cjc4bi0q0l [ 0 ] + rtB . cjc4bi0q0l [ 1 ] * rtB .
cjc4bi0q0l [ 1 ] ) + rtB . cjc4bi0q0l [ 2 ] * rtB . cjc4bi0q0l [ 2 ] ) + rtB
. cjc4bi0q0l [ 3 ] * rtB . cjc4bi0q0l [ 3 ] ) ) * rtP .
HighGainQuaternionNormalization_Gain ; rtB . pbw2adbesb = ( ( rtB .
cjc4bi0q0l [ 1 ] * rtB . kwssbn0ne4 [ 0 ] + rtB . cjc4bi0q0l [ 2 ] * rtB .
kwssbn0ne4 [ 1 ] ) + rtB . cjc4bi0q0l [ 3 ] * rtB . kwssbn0ne4 [ 2 ] ) * -
0.5 + oducdqkgjs_idx_e * rtB . cjc4bi0q0l [ 0 ] ; rtB . ab5xgw0342 = ( ( rtB
. cjc4bi0q0l [ 0 ] * rtB . kwssbn0ne4 [ 0 ] + rtB . cjc4bi0q0l [ 2 ] * rtB .
kwssbn0ne4 [ 2 ] ) - rtB . cjc4bi0q0l [ 3 ] * rtB . kwssbn0ne4 [ 1 ] ) * 0.5
+ oducdqkgjs_idx_e * rtB . cjc4bi0q0l [ 1 ] ; rtB . ct3c5eoli2 = ( ( rtB .
cjc4bi0q0l [ 0 ] * rtB . kwssbn0ne4 [ 1 ] + rtB . cjc4bi0q0l [ 3 ] * rtB .
kwssbn0ne4 [ 0 ] ) - rtB . cjc4bi0q0l [ 1 ] * rtB . kwssbn0ne4 [ 2 ] ) * 0.5
+ oducdqkgjs_idx_e * rtB . cjc4bi0q0l [ 2 ] ; rtB . crik5dobwi = ( ( rtB .
cjc4bi0q0l [ 0 ] * rtB . kwssbn0ne4 [ 2 ] + rtB . cjc4bi0q0l [ 1 ] * rtB .
kwssbn0ne4 [ 1 ] ) - rtB . cjc4bi0q0l [ 2 ] * rtB . kwssbn0ne4 [ 0 ] ) * 0.5
+ oducdqkgjs_idx_e * rtB . cjc4bi0q0l [ 3 ] ; pmaszljcaa [ 0 ] = rtP .
Constant3_Value_oayr5juvkv ; pmaszljcaa [ 1 ] = rtB . fz0figaoto [ 3 ] ;
pmaszljcaa [ 2 ] = rtP . Gain8_Gain * rtB . fz0figaoto [ 2 ] ; pmaszljcaa [ 3
] = rtP . Gain6_Gain_lwc3ps4rex * rtB . fz0figaoto [ 3 ] ; pmaszljcaa [ 4 ] =
rtP . Constant3_Value_oayr5juvkv ; pmaszljcaa [ 5 ] = rtB . fz0figaoto [ 1 ]
; pmaszljcaa [ 6 ] = rtB . fz0figaoto [ 2 ] ; pmaszljcaa [ 7 ] = rtP .
Gain7_Gain * rtB . fz0figaoto [ 1 ] ; pmaszljcaa [ 8 ] = rtP .
Constant3_Value_oayr5juvkv ; for ( i = 0 ; i < 9 ; i ++ ) { rtB . o1klch4xqt
[ i ] = pmaszljcaa [ i ] ; m2b1vgca5s [ i ] = rtB . o1klch4xqt [ i ] ; }
LUf_int32_Treal_T ( m2b1vgca5s , oydzcnlmnv , 3 ) ; for ( k = 0 ; k < 3 ; k
++ ) { i = ( int32_T ) muDoubleScalarFloor ( oydzcnlmnv [ k ] ) - 1 ; if ( i
< 0 ) { i = 0 ; } else { if ( i >= 3 ) { i = 2 ; } } jqwtr5xyw4 [ k ] = rtB .
f22csweirk [ i ] ; jqwtr5xyw4 [ 3 + k ] = rtB . f22csweirk [ 3 + i ] ;
jqwtr5xyw4 [ 6 + k ] = rtB . f22csweirk [ 6 + i ] ; } for ( i_p = 0 ; i_p < 3
; i_p ++ ) { i = i_p * 3 ; idxLU = 1 ; idxB = i + 1 ; nfwwjxsmuk = jqwtr5xyw4
[ idxB ] ; k = 0 ; while ( k < 1 ) { nfwwjxsmuk -= m2b1vgca5s [ idxLU ] *
jqwtr5xyw4 [ i ] ; idxLU += 3 ; k = 1 ; } jqwtr5xyw4 [ idxB ] = nfwwjxsmuk ;
idxLU = 2 ; idxB = i + 2 ; nfwwjxsmuk = jqwtr5xyw4 [ idxB ] ; for ( k = 0 ; k
< 2 ; k ++ ) { nfwwjxsmuk -= jqwtr5xyw4 [ i + k ] * m2b1vgca5s [ idxLU ] ;
idxLU += 3 ; } jqwtr5xyw4 [ idxB ] = nfwwjxsmuk ; } for ( i_p = 0 ; i_p < 3 ;
i_p ++ ) { i = i_p * 3 ; k = i + 2 ; rtB . ctfm1d5uqu [ k ] = jqwtr5xyw4 [ k
] / m2b1vgca5s [ 8 ] ; idxLU = 7 ; idxB = i + 1 ; nfwwjxsmuk = jqwtr5xyw4 [
idxB ] ; k = 2 ; while ( k > 1 ) { nfwwjxsmuk -= rtB . ctfm1d5uqu [ i + 2 ] *
m2b1vgca5s [ idxLU ] ; idxLU -= 3 ; k = 1 ; } rtB . ctfm1d5uqu [ idxB ] =
nfwwjxsmuk / m2b1vgca5s [ idxLU ] ; idxLU = 6 ; nfwwjxsmuk = jqwtr5xyw4 [ i ]
; for ( k = 2 ; k > 0 ; k -- ) { nfwwjxsmuk -= rtB . ctfm1d5uqu [ i + k ] *
m2b1vgca5s [ idxLU ] ; idxLU -= 3 ; } rtB . ctfm1d5uqu [ i ] = nfwwjxsmuk /
m2b1vgca5s [ idxLU ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB .
lqnx4g1go5 [ i_p ] = 0.0 ; rtB . lqnx4g1go5 [ i_p ] += rtB . ctfm1d5uqu [ i_p
] * rtB . p05flgh0s0 [ 0 ] ; rtB . lqnx4g1go5 [ i_p ] += rtB . ctfm1d5uqu [
i_p + 3 ] * rtB . p05flgh0s0 [ 1 ] ; rtB . lqnx4g1go5 [ i_p ] += rtB .
ctfm1d5uqu [ i_p + 6 ] * rtB . p05flgh0s0 [ 2 ] ; } if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { rtB . l3eb5r4yyc = rtP . Gain5_Gain * rtP . a_Value ; } rtB .
kfrivtgbni [ 0 ] = ( rtB . p05flgh0s0 [ 0 ] - rtP . a_Value * rtB .
fz0figaoto [ 1 ] ) * rtB . l3eb5r4yyc ; rtB . kfrivtgbni [ 1 ] = ( rtB .
p05flgh0s0 [ 1 ] - rtP . a_Value * rtB . fz0figaoto [ 2 ] ) * rtB .
l3eb5r4yyc ; rtB . kfrivtgbni [ 2 ] = ( rtB . p05flgh0s0 [ 2 ] - rtP .
a_Value * rtB . fz0figaoto [ 3 ] ) * rtB . l3eb5r4yyc ; oydzcnlmnv [ 0 ] =
la1hfx5r2w . vj2000 [ 0 ] ; oydzcnlmnv [ 1 ] = la1hfx5r2w . vj2000 [ 1 ] ;
oydzcnlmnv [ 2 ] = la1hfx5r2w . vj2000 [ 2 ] ; rtB . iloozpnfyr [ 0 ] =
la1hfx5r2w . j2000 [ 0 ] ; rtB . iloozpnfyr [ 1 ] = la1hfx5r2w . j2000 [ 1 ]
; rtB . iloozpnfyr [ 2 ] = la1hfx5r2w . j2000 [ 2 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . lagfvd2ei5 = rtP . Gain_Gain_av3hfhcgyv * rtP .
Constant_Value_bw3vkbj2eu ; } nfwwjxsmuk = rtB . obj5e4e3db [ 0 ] * rtB .
obj5e4e3db [ 0 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { jyfgwidcz5 [ 0 ] =
rtP . Constant_Value_bin4grumgj ; jyfgwidcz5 [ 1 ] = rtP .
Constant2_Value_jf2fosnw3b [ 2 ] ; jyfgwidcz5 [ 2 ] = rtP .
Gain_Gain_mbuijwi5jm * rtP . Constant2_Value_jf2fosnw3b [ 1 ] ; jyfgwidcz5 [
3 ] = rtP . Gain_Gain_mbuijwi5jm * rtP . Constant2_Value_jf2fosnw3b [ 2 ] ;
jyfgwidcz5 [ 4 ] = rtP . Constant_Value_bin4grumgj ; jyfgwidcz5 [ 5 ] = rtP .
Constant2_Value_jf2fosnw3b [ 0 ] ; jyfgwidcz5 [ 6 ] = rtP .
Constant2_Value_jf2fosnw3b [ 1 ] ; jyfgwidcz5 [ 7 ] = rtP .
Gain_Gain_mbuijwi5jm * rtP . Constant2_Value_jf2fosnw3b [ 0 ] ; jyfgwidcz5 [
8 ] = rtP . Constant_Value_bin4grumgj ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . fyykrlz50p [ i_p + 3 * i ] = 0.0 ; rtB .
fyykrlz50p [ i_p + 3 * i ] += jyfgwidcz5 [ 3 * i ] * jyfgwidcz5 [ i_p ] ; rtB
. fyykrlz50p [ i_p + 3 * i ] += jyfgwidcz5 [ 3 * i + 1 ] * jyfgwidcz5 [ i_p +
3 ] ; rtB . fyykrlz50p [ i_p + 3 * i ] += jyfgwidcz5 [ 3 * i + 2 ] *
jyfgwidcz5 [ i_p + 6 ] ; } } ctzdfomcpm [ 0 ] = rtP .
Constant_Value_jgjdenbdkp ; ctzdfomcpm [ 1 ] = rtP . Constant5_Value [ 2 ] ;
ctzdfomcpm [ 2 ] = rtP . Gain_Gain_hsvk1ppevl * rtP . Constant5_Value [ 1 ] ;
ctzdfomcpm [ 3 ] = rtP . Gain_Gain_hsvk1ppevl * rtP . Constant5_Value [ 2 ] ;
ctzdfomcpm [ 4 ] = rtP . Constant_Value_jgjdenbdkp ; ctzdfomcpm [ 5 ] = rtP .
Constant5_Value [ 0 ] ; ctzdfomcpm [ 6 ] = rtP . Constant5_Value [ 1 ] ;
ctzdfomcpm [ 7 ] = rtP . Gain_Gain_hsvk1ppevl * rtP . Constant5_Value [ 0 ] ;
ctzdfomcpm [ 8 ] = rtP . Constant_Value_jgjdenbdkp ; for ( i_p = 0 ; i_p < 3
; i_p ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtB . ehlhfalizh [ i_p + 3 * i ]
= 0.0 ; rtB . ehlhfalizh [ i_p + 3 * i ] += ctzdfomcpm [ 3 * i ] * jyfgwidcz5
[ i_p ] ; rtB . ehlhfalizh [ i_p + 3 * i ] += ctzdfomcpm [ 3 * i + 1 ] *
jyfgwidcz5 [ i_p + 3 ] ; rtB . ehlhfalizh [ i_p + 3 * i ] += ctzdfomcpm [ 3 *
i + 2 ] * jyfgwidcz5 [ i_p + 6 ] ; } } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . g1xui3hmed [ i_p + 3 * i ] = 0.0 ; rtB .
g1xui3hmed [ i_p + 3 * i ] += jyfgwidcz5 [ 3 * i ] * ctzdfomcpm [ i_p ] ; rtB
. g1xui3hmed [ i_p + 3 * i ] += jyfgwidcz5 [ 3 * i + 1 ] * ctzdfomcpm [ i_p +
3 ] ; rtB . g1xui3hmed [ i_p + 3 * i ] += jyfgwidcz5 [ 3 * i + 2 ] *
ctzdfomcpm [ i_p + 6 ] ; } } rtB . hdj40uot1u = rtP . Gain_Gain_dxvjzvgyer *
rtP . Constant_Value_dlgbgdxgmn ; } enzyytwikn = rtB . obj5e4e3db [ 1 ] * rtB
. obj5e4e3db [ 1 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { e2tqctvrj0 [ 0 ]
= rtP . Constant_Value_p2yj2qsewh ; e2tqctvrj0 [ 1 ] = rtP .
Constant3_Value_fjjscdcrzj [ 2 ] ; e2tqctvrj0 [ 2 ] = rtP .
Gain_Gain_e42rl13cmn * rtP . Constant3_Value_fjjscdcrzj [ 1 ] ; e2tqctvrj0 [
3 ] = rtP . Gain_Gain_e42rl13cmn * rtP . Constant3_Value_fjjscdcrzj [ 2 ] ;
e2tqctvrj0 [ 4 ] = rtP . Constant_Value_p2yj2qsewh ; e2tqctvrj0 [ 5 ] = rtP .
Constant3_Value_fjjscdcrzj [ 0 ] ; e2tqctvrj0 [ 6 ] = rtP .
Constant3_Value_fjjscdcrzj [ 1 ] ; e2tqctvrj0 [ 7 ] = rtP .
Gain_Gain_e42rl13cmn * rtP . Constant3_Value_fjjscdcrzj [ 0 ] ; e2tqctvrj0 [
8 ] = rtP . Constant_Value_p2yj2qsewh ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . a1254pdgfh [ i_p + 3 * i ] = 0.0 ; rtB .
a1254pdgfh [ i_p + 3 * i ] += e2tqctvrj0 [ 3 * i ] * e2tqctvrj0 [ i_p ] ; rtB
. a1254pdgfh [ i_p + 3 * i ] += e2tqctvrj0 [ 3 * i + 1 ] * e2tqctvrj0 [ i_p +
3 ] ; rtB . a1254pdgfh [ i_p + 3 * i ] += e2tqctvrj0 [ 3 * i + 2 ] *
e2tqctvrj0 [ i_p + 6 ] ; } } dm2gdf32t4 [ 0 ] = rtP .
Constant_Value_fn2jvveflf ; dm2gdf32t4 [ 1 ] = rtP . Constant6_Value [ 2 ] ;
dm2gdf32t4 [ 2 ] = rtP . Gain_Gain_eiuk4co0u1 * rtP . Constant6_Value [ 1 ] ;
dm2gdf32t4 [ 3 ] = rtP . Gain_Gain_eiuk4co0u1 * rtP . Constant6_Value [ 2 ] ;
dm2gdf32t4 [ 4 ] = rtP . Constant_Value_fn2jvveflf ; dm2gdf32t4 [ 5 ] = rtP .
Constant6_Value [ 0 ] ; dm2gdf32t4 [ 6 ] = rtP . Constant6_Value [ 1 ] ;
dm2gdf32t4 [ 7 ] = rtP . Gain_Gain_eiuk4co0u1 * rtP . Constant6_Value [ 0 ] ;
dm2gdf32t4 [ 8 ] = rtP . Constant_Value_fn2jvveflf ; for ( i_p = 0 ; i_p < 3
; i_p ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtB . e22yyth3y4 [ i_p + 3 * i ]
= 0.0 ; rtB . e22yyth3y4 [ i_p + 3 * i ] += dm2gdf32t4 [ 3 * i ] * e2tqctvrj0
[ i_p ] ; rtB . e22yyth3y4 [ i_p + 3 * i ] += dm2gdf32t4 [ 3 * i + 1 ] *
e2tqctvrj0 [ i_p + 3 ] ; rtB . e22yyth3y4 [ i_p + 3 * i ] += dm2gdf32t4 [ 3 *
i + 2 ] * e2tqctvrj0 [ i_p + 6 ] ; } } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . dhwvhv3uh5 [ i_p + 3 * i ] = 0.0 ; rtB .
dhwvhv3uh5 [ i_p + 3 * i ] += e2tqctvrj0 [ 3 * i ] * dm2gdf32t4 [ i_p ] ; rtB
. dhwvhv3uh5 [ i_p + 3 * i ] += e2tqctvrj0 [ 3 * i + 1 ] * dm2gdf32t4 [ i_p +
3 ] ; rtB . dhwvhv3uh5 [ i_p + 3 * i ] += e2tqctvrj0 [ 3 * i + 2 ] *
dm2gdf32t4 [ i_p + 6 ] ; } } rtB . gutdju0mn5 = rtP . Gain_Gain_ikyjnkugqm *
rtP . Constant_Value_pnej1bop5b ; } hu2gcgsgxf = rtB . obj5e4e3db [ 2 ] * rtB
. obj5e4e3db [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { ldts3pfwss [ 0 ]
= rtP . Constant_Value_irpm3cwjza ; ldts3pfwss [ 1 ] = rtP .
Constant4_Value_arg3ksqg5d [ 2 ] ; ldts3pfwss [ 2 ] = rtP .
Gain_Gain_nogset3ro3 * rtP . Constant4_Value_arg3ksqg5d [ 1 ] ; ldts3pfwss [
3 ] = rtP . Gain_Gain_nogset3ro3 * rtP . Constant4_Value_arg3ksqg5d [ 2 ] ;
ldts3pfwss [ 4 ] = rtP . Constant_Value_irpm3cwjza ; ldts3pfwss [ 5 ] = rtP .
Constant4_Value_arg3ksqg5d [ 0 ] ; ldts3pfwss [ 6 ] = rtP .
Constant4_Value_arg3ksqg5d [ 1 ] ; ldts3pfwss [ 7 ] = rtP .
Gain_Gain_nogset3ro3 * rtP . Constant4_Value_arg3ksqg5d [ 0 ] ; ldts3pfwss [
8 ] = rtP . Constant_Value_irpm3cwjza ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . fafimnaesx [ i_p + 3 * i ] = 0.0 ; rtB .
fafimnaesx [ i_p + 3 * i ] += ldts3pfwss [ 3 * i ] * ldts3pfwss [ i_p ] ; rtB
. fafimnaesx [ i_p + 3 * i ] += ldts3pfwss [ 3 * i + 1 ] * ldts3pfwss [ i_p +
3 ] ; rtB . fafimnaesx [ i_p + 3 * i ] += ldts3pfwss [ 3 * i + 2 ] *
ldts3pfwss [ i_p + 6 ] ; } } iq4emno1ma [ 0 ] = rtP .
Constant_Value_aecujgzxyb ; iq4emno1ma [ 1 ] = rtP . Constant7_Value [ 2 ] ;
iq4emno1ma [ 2 ] = rtP . Gain_Gain_ocowllqul3 * rtP . Constant7_Value [ 1 ] ;
iq4emno1ma [ 3 ] = rtP . Gain_Gain_ocowllqul3 * rtP . Constant7_Value [ 2 ] ;
iq4emno1ma [ 4 ] = rtP . Constant_Value_aecujgzxyb ; iq4emno1ma [ 5 ] = rtP .
Constant7_Value [ 0 ] ; iq4emno1ma [ 6 ] = rtP . Constant7_Value [ 1 ] ;
iq4emno1ma [ 7 ] = rtP . Gain_Gain_ocowllqul3 * rtP . Constant7_Value [ 0 ] ;
iq4emno1ma [ 8 ] = rtP . Constant_Value_aecujgzxyb ; for ( i_p = 0 ; i_p < 3
; i_p ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtB . ee2go4u05y [ i_p + 3 * i ]
= 0.0 ; rtB . ee2go4u05y [ i_p + 3 * i ] += iq4emno1ma [ 3 * i ] * ldts3pfwss
[ i_p ] ; rtB . ee2go4u05y [ i_p + 3 * i ] += iq4emno1ma [ 3 * i + 1 ] *
ldts3pfwss [ i_p + 3 ] ; rtB . ee2go4u05y [ i_p + 3 * i ] += iq4emno1ma [ 3 *
i + 2 ] * ldts3pfwss [ i_p + 6 ] ; } } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . pijgu4gjiu [ i_p + 3 * i ] = 0.0 ; rtB .
pijgu4gjiu [ i_p + 3 * i ] += ldts3pfwss [ 3 * i ] * iq4emno1ma [ i_p ] ; rtB
. pijgu4gjiu [ i_p + 3 * i ] += ldts3pfwss [ 3 * i + 1 ] * iq4emno1ma [ i_p +
3 ] ; rtB . pijgu4gjiu [ i_p + 3 * i ] += ldts3pfwss [ 3 * i + 2 ] *
iq4emno1ma [ i_p + 6 ] ; } } } for ( i = 0 ; i < 9 ; i ++ ) { jqwtr5xyw4 [ i
] = ( ( ( ( nfwwjxsmuk * rtB . fyykrlz50p [ i ] + rtB . obj5e4e3db [ 0 ] *
rtB . ehlhfalizh [ i ] ) + rtB . obj5e4e3db [ 0 ] * rtB . g1xui3hmed [ i ] )
* rtB . lagfvd2ei5 + rtP . Constant1_Value_de0q5adpcb [ i ] ) + ( (
enzyytwikn * rtB . a1254pdgfh [ i ] + rtB . obj5e4e3db [ 1 ] * rtB .
e22yyth3y4 [ i ] ) + rtB . obj5e4e3db [ 1 ] * rtB . dhwvhv3uh5 [ i ] ) * rtB
. hdj40uot1u ) + ( ( hu2gcgsgxf * rtB . fafimnaesx [ i ] + rtB . obj5e4e3db [
2 ] * rtB . ee2go4u05y [ i ] ) + rtB . obj5e4e3db [ 2 ] * rtB . pijgu4gjiu [
i ] ) * rtB . gutdju0mn5 ; } oducdqkgjs_idx_e = ( rtB . iloozpnfyr [ 0 ] *
rtB . iloozpnfyr [ 0 ] + rtB . iloozpnfyr [ 1 ] * rtB . iloozpnfyr [ 1 ] ) +
rtB . iloozpnfyr [ 2 ] * rtB . iloozpnfyr [ 2 ] ; if ( oducdqkgjs_idx_e < 0.0
) { rtB . cz3ja34zrq = - muDoubleScalarSqrt ( muDoubleScalarAbs (
oducdqkgjs_idx_e ) ) ; } else { rtB . cz3ja34zrq = muDoubleScalarSqrt (
oducdqkgjs_idx_e ) ; } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . jrnny2qloo =
( rtB . cz3ja34zrq > rtP . Switch_Threshold_dkimt1f1tz ) ; } if ( rtDW .
jrnny2qloo ) { ivszce53hq [ 0 ] = rtB . iloozpnfyr [ 0 ] ; ivszce53hq [ 1 ] =
rtB . iloozpnfyr [ 1 ] ; ivszce53hq [ 2 ] = rtB . iloozpnfyr [ 2 ] ;
ivszce53hq [ 3 ] = rtB . cz3ja34zrq ; } else { rtB . dufe500tdo [ 0 ] = rtB .
iloozpnfyr [ 0 ] * 0.0 ; rtB . dufe500tdo [ 1 ] = rtB . iloozpnfyr [ 1 ] *
0.0 ; rtB . dufe500tdo [ 2 ] = rtB . iloozpnfyr [ 2 ] * 0.0 ; ivszce53hq [ 0
] = rtB . dufe500tdo [ 0 ] ; ivszce53hq [ 1 ] = rtB . dufe500tdo [ 1 ] ;
ivszce53hq [ 2 ] = rtB . dufe500tdo [ 2 ] ; ivszce53hq [ 3 ] = rtP .
Constant_Value_hh2kih5qyy ; } bguqm55hxa [ 0 ] = ivszce53hq [ 0 ] /
ivszce53hq [ 3 ] ; bguqm55hxa [ 1 ] = ivszce53hq [ 1 ] / ivszce53hq [ 3 ] ;
bguqm55hxa [ 2 ] = ivszce53hq [ 2 ] / ivszce53hq [ 3 ] ; rtB . cznp4l44bm [ 3
] = bguqm55hxa [ 0 ] ; rtB . cznp4l44bm [ 4 ] = bguqm55hxa [ 1 ] ; rtB .
cznp4l44bm [ 5 ] = bguqm55hxa [ 2 ] ; rtB . dfeof1aiqk [ 0 ] = oydzcnlmnv [ 1
] * rtB . iloozpnfyr [ 2 ] - oydzcnlmnv [ 2 ] * rtB . iloozpnfyr [ 1 ] ; rtB
. dfeof1aiqk [ 1 ] = oydzcnlmnv [ 2 ] * rtB . iloozpnfyr [ 0 ] - oydzcnlmnv [
0 ] * rtB . iloozpnfyr [ 2 ] ; rtB . dfeof1aiqk [ 2 ] = oydzcnlmnv [ 0 ] *
rtB . iloozpnfyr [ 1 ] - oydzcnlmnv [ 1 ] * rtB . iloozpnfyr [ 0 ] ;
oducdqkgjs_idx_e = ( rtB . dfeof1aiqk [ 0 ] * rtB . dfeof1aiqk [ 0 ] + rtB .
dfeof1aiqk [ 1 ] * rtB . dfeof1aiqk [ 1 ] ) + rtB . dfeof1aiqk [ 2 ] * rtB .
dfeof1aiqk [ 2 ] ; if ( oducdqkgjs_idx_e < 0.0 ) { rtB . ox2cje3ogi = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( oducdqkgjs_idx_e ) ) ; } else { rtB
. ox2cje3ogi = muDoubleScalarSqrt ( oducdqkgjs_idx_e ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . ctt5abpcf5 = ( rtB . ox2cje3ogi > rtP .
Switch_Threshold_gnlntr1le3 ) ; } if ( rtDW . ctt5abpcf5 ) { ivszce53hq [ 0 ]
= rtB . dfeof1aiqk [ 0 ] ; ivszce53hq [ 1 ] = rtB . dfeof1aiqk [ 1 ] ;
ivszce53hq [ 2 ] = rtB . dfeof1aiqk [ 2 ] ; ivszce53hq [ 3 ] = rtB .
ox2cje3ogi ; } else { rtB . juc40yv1j4 [ 0 ] = rtB . dfeof1aiqk [ 0 ] * 0.0 ;
rtB . juc40yv1j4 [ 1 ] = rtB . dfeof1aiqk [ 1 ] * 0.0 ; rtB . juc40yv1j4 [ 2
] = rtB . dfeof1aiqk [ 2 ] * 0.0 ; ivszce53hq [ 0 ] = rtB . juc40yv1j4 [ 0 ]
; ivszce53hq [ 1 ] = rtB . juc40yv1j4 [ 1 ] ; ivszce53hq [ 2 ] = rtB .
juc40yv1j4 [ 2 ] ; ivszce53hq [ 3 ] = rtP . Constant_Value_hgpikmmnsj ; }
oydzcnlmnv [ 0 ] = ivszce53hq [ 0 ] / ivszce53hq [ 3 ] ; oydzcnlmnv [ 1 ] =
ivszce53hq [ 1 ] / ivszce53hq [ 3 ] ; oydzcnlmnv [ 2 ] = ivszce53hq [ 2 ] /
ivszce53hq [ 3 ] ; rtB . cznp4l44bm [ 6 ] = oydzcnlmnv [ 0 ] ; rtB .
cznp4l44bm [ 7 ] = oydzcnlmnv [ 1 ] ; rtB . cznp4l44bm [ 8 ] = oydzcnlmnv [ 2
] ; rtB . cznp4l44bm [ 0 ] = bguqm55hxa [ 1 ] * oydzcnlmnv [ 2 ] - bguqm55hxa
[ 2 ] * oydzcnlmnv [ 1 ] ; rtB . cznp4l44bm [ 1 ] = bguqm55hxa [ 2 ] *
oydzcnlmnv [ 0 ] - bguqm55hxa [ 0 ] * oydzcnlmnv [ 2 ] ; rtB . cznp4l44bm [ 2
] = bguqm55hxa [ 0 ] * oydzcnlmnv [ 1 ] - bguqm55hxa [ 1 ] * oydzcnlmnv [ 0 ]
; bguqm55hxa [ 0 ] = rtB . cznp4l44bm [ 0 ] ; bguqm55hxa [ 1 ] = rtB .
cznp4l44bm [ 4 ] ; bguqm55hxa [ 2 ] = rtB . cznp4l44bm [ 8 ] ; rtB .
aps03o1u4v = ( rtB . cznp4l44bm [ 0 ] + rtB . cznp4l44bm [ 4 ] ) + rtB .
cznp4l44bm [ 8 ] ; rtPrevAction = rtDW . mf41bf444w ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtB . aps03o1u4v > 0.0 ) { rtAction = 0 ; } else { rtAction
= 1 ; } rtDW . mf41bf444w = rtAction ; } else { rtAction = rtDW . mf41bf444w
; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
ssSetSolverNeedsReset ( rtS ) ; break ; case 1 : ssSetSolverNeedsReset ( rtS
) ; switch ( rtDW . pyge1tac5l ) { case 0 : ssSetSolverNeedsReset ( rtS ) ;
break ; case 1 : ssSetSolverNeedsReset ( rtS ) ; break ; case 2 :
ssSetSolverNeedsReset ( rtS ) ; break ; } rtDW . pyge1tac5l = - 1 ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { if (
ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset (
rtS ) ; } } nfwwjxsmuk = rtB . aps03o1u4v + rtP . Constant_Value_jjhmxiynvf ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . lggvt2ioqm != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . lggvt2ioqm = 0 ; } nfwwjxsmuk =
muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if ( nfwwjxsmuk < 0.0 ) {
nfwwjxsmuk = - muDoubleScalarSqrt ( muDoubleScalarAbs ( nfwwjxsmuk ) ) ; }
else { nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } rtDW . lggvt2ioqm =
1 ; } rtB . l2aegg0det [ 0 ] = rtP . Gain_Gain_gq1q0o0dgd * nfwwjxsmuk ;
nfwwjxsmuk *= rtP . Gain1_Gain_gwhqm0umwh ; rtB . l2aegg0det [ 1 ] = ( rtB .
cznp4l44bm [ 7 ] - rtB . cznp4l44bm [ 5 ] ) / nfwwjxsmuk ; rtB . l2aegg0det [
2 ] = ( rtB . cznp4l44bm [ 2 ] - rtB . cznp4l44bm [ 6 ] ) / nfwwjxsmuk ; rtB
. l2aegg0det [ 3 ] = ( rtB . cznp4l44bm [ 3 ] - rtB . cznp4l44bm [ 1 ] ) /
nfwwjxsmuk ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
espotkwrxj ) ; } break ; case 1 : if ( rtAction != rtPrevAction ) { if (
ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset (
rtS ) ; } } rtPrevAction = rtDW . pyge1tac5l ; if ( ssIsMajorTimeStep ( rtS )
) { if ( ( rtB . cznp4l44bm [ 4 ] > rtB . cznp4l44bm [ 0 ] ) && ( rtB .
cznp4l44bm [ 4 ] > rtB . cznp4l44bm [ 8 ] ) ) { rtAction = 0 ; } else if (
rtB . cznp4l44bm [ 8 ] > rtB . cznp4l44bm [ 0 ] ) { rtAction = 1 ; } else {
rtAction = 2 ; } rtDW . pyge1tac5l = rtAction ; } else { rtAction = rtDW .
pyge1tac5l ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : ssSetSolverNeedsReset ( rtS ) ; break ; case 1 :
ssSetSolverNeedsReset ( rtS ) ; break ; case 2 : ssSetSolverNeedsReset ( rtS
) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction
) { if ( ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) {
ssSetSolverNeedsReset ( rtS ) ; } } nfwwjxsmuk = ( ( rtB . cznp4l44bm [ 4 ] -
rtB . cznp4l44bm [ 0 ] ) - rtB . cznp4l44bm [ 8 ] ) + rtP .
Constant_Value_bqgjtgwncf ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
m4c02ikbg1 != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . m4c02ikbg1 = 0 ; }
rtB . fwdepyepsg = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if (
nfwwjxsmuk < 0.0 ) { rtB . fwdepyepsg = - muDoubleScalarSqrt (
muDoubleScalarAbs ( nfwwjxsmuk ) ) ; } else { rtB . fwdepyepsg =
muDoubleScalarSqrt ( nfwwjxsmuk ) ; } rtDW . m4c02ikbg1 = 1 ; } rtB .
l2aegg0det [ 2 ] = rtP . Gain_Gain_gqxkss2f4q * rtB . fwdepyepsg ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . kuwvje3v02 = ( rtB . fwdepyepsg != 0.0 )
; } if ( rtDW . kuwvje3v02 ) { oducdqkgjs_idx_e = rtP .
Constant1_Value_e2tnprjcds ; } else { oducdqkgjs_idx_e = rtP .
Constant2_Value_ox4kgnjx1u [ 0 ] ; } if ( rtDW . kuwvje3v02 ) {
oducdqkgjs_idx = rtB . fwdepyepsg ; } else { oducdqkgjs_idx = rtP .
Constant2_Value_ox4kgnjx1u [ 1 ] ; } nfwwjxsmuk = oducdqkgjs_idx_e /
oducdqkgjs_idx ; bguqm55hxa [ 0 ] = ( rtB . cznp4l44bm [ 1 ] + rtB .
cznp4l44bm [ 3 ] ) * nfwwjxsmuk ; bguqm55hxa [ 1 ] = ( rtB . cznp4l44bm [ 5 ]
+ rtB . cznp4l44bm [ 7 ] ) * nfwwjxsmuk ; bguqm55hxa [ 2 ] = ( rtB .
cznp4l44bm [ 2 ] - rtB . cznp4l44bm [ 6 ] ) * nfwwjxsmuk ; rtB . l2aegg0det [
1 ] = rtP . Gain1_Gain_plbazqymln * bguqm55hxa [ 0 ] ; rtB . l2aegg0det [ 3 ]
= rtP . Gain3_Gain_lnfk34izw1 * bguqm55hxa [ 1 ] ; rtB . l2aegg0det [ 0 ] =
rtP . Gain4_Gain_frwaasjnjn * bguqm55hxa [ 2 ] ; if ( ssIsMajorTimeStep ( rtS
) ) { srUpdateBC ( rtDW . occ4jhal5v ) ; } break ; case 1 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) {
ssSetSolverNeedsReset ( rtS ) ; } } nfwwjxsmuk = ( ( rtB . cznp4l44bm [ 8 ] -
rtB . cznp4l44bm [ 0 ] ) - rtB . cznp4l44bm [ 4 ] ) + rtP .
Constant_Value_pc3s5n5ig0 ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
iq1hnty4rc != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . iq1hnty4rc = 0 ; }
rtB . jea3ib45lq = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if (
nfwwjxsmuk < 0.0 ) { rtB . jea3ib45lq = - muDoubleScalarSqrt (
muDoubleScalarAbs ( nfwwjxsmuk ) ) ; } else { rtB . jea3ib45lq =
muDoubleScalarSqrt ( nfwwjxsmuk ) ; } rtDW . iq1hnty4rc = 1 ; } rtB .
l2aegg0det [ 3 ] = rtP . Gain_Gain_g0crcybw52 * rtB . jea3ib45lq ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . krlfahjhyu = ( rtB . jea3ib45lq != 0.0 )
; } if ( rtDW . krlfahjhyu ) { oducdqkgjs_idx_e = rtP .
Constant1_Value_pvid3jlafh ; } else { oducdqkgjs_idx_e = rtP .
Constant2_Value_bgmtgxyswg [ 0 ] ; } if ( rtDW . krlfahjhyu ) {
oducdqkgjs_idx = rtB . jea3ib45lq ; } else { oducdqkgjs_idx = rtP .
Constant2_Value_bgmtgxyswg [ 1 ] ; } nfwwjxsmuk = oducdqkgjs_idx_e /
oducdqkgjs_idx ; bguqm55hxa [ 0 ] = ( rtB . cznp4l44bm [ 2 ] + rtB .
cznp4l44bm [ 6 ] ) * nfwwjxsmuk ; bguqm55hxa [ 1 ] = ( rtB . cznp4l44bm [ 5 ]
+ rtB . cznp4l44bm [ 7 ] ) * nfwwjxsmuk ; bguqm55hxa [ 2 ] = ( rtB .
cznp4l44bm [ 3 ] - rtB . cznp4l44bm [ 1 ] ) * nfwwjxsmuk ; rtB . l2aegg0det [
1 ] = rtP . Gain1_Gain_cmjmtszzlh * bguqm55hxa [ 0 ] ; rtB . l2aegg0det [ 2 ]
= rtP . Gain2_Gain_lbyqu50w0f * bguqm55hxa [ 1 ] ; rtB . l2aegg0det [ 0 ] =
rtP . Gain3_Gain_fjdyxqygiq * bguqm55hxa [ 2 ] ; if ( ssIsMajorTimeStep ( rtS
) ) { srUpdateBC ( rtDW . k5kqzwhgid ) ; } break ; case 2 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) {
ssSetSolverNeedsReset ( rtS ) ; } } nfwwjxsmuk = ( ( rtB . cznp4l44bm [ 0 ] -
rtB . cznp4l44bm [ 4 ] ) - rtB . cznp4l44bm [ 8 ] ) + rtP .
Constant_Value_elm2slanqm ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
hrkt2hcocj != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . hrkt2hcocj = 0 ; }
rtB . p2vvijwdyj = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if (
nfwwjxsmuk < 0.0 ) { rtB . p2vvijwdyj = - muDoubleScalarSqrt (
muDoubleScalarAbs ( nfwwjxsmuk ) ) ; } else { rtB . p2vvijwdyj =
muDoubleScalarSqrt ( nfwwjxsmuk ) ; } rtDW . hrkt2hcocj = 1 ; } rtB .
l2aegg0det [ 1 ] = rtP . Gain_Gain_ocfwspzgot * rtB . p2vvijwdyj ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . a0o3qpslv4 = ( rtB . p2vvijwdyj != 0.0 )
; } if ( rtDW . a0o3qpslv4 ) { oducdqkgjs_idx_e = rtP .
Constant1_Value_cf4j34iv2x ; } else { oducdqkgjs_idx_e = rtP .
Constant2_Value_pt2pqq3qma [ 0 ] ; } if ( rtDW . a0o3qpslv4 ) {
oducdqkgjs_idx = rtB . p2vvijwdyj ; } else { oducdqkgjs_idx = rtP .
Constant2_Value_pt2pqq3qma [ 1 ] ; } nfwwjxsmuk = oducdqkgjs_idx_e /
oducdqkgjs_idx ; bguqm55hxa [ 0 ] = ( rtB . cznp4l44bm [ 1 ] + rtB .
cznp4l44bm [ 3 ] ) * nfwwjxsmuk ; bguqm55hxa [ 1 ] = ( rtB . cznp4l44bm [ 2 ]
+ rtB . cznp4l44bm [ 6 ] ) * nfwwjxsmuk ; bguqm55hxa [ 2 ] = ( rtB .
cznp4l44bm [ 7 ] - rtB . cznp4l44bm [ 5 ] ) * nfwwjxsmuk ; rtB . l2aegg0det [
2 ] = rtP . Gain1_Gain_dvdkv5tz32 * bguqm55hxa [ 0 ] ; rtB . l2aegg0det [ 3 ]
= rtP . Gain2_Gain_atvqpareya * bguqm55hxa [ 1 ] ; rtB . l2aegg0det [ 0 ] =
rtP . Gain3_Gain_clfc33gypf * bguqm55hxa [ 2 ] ; if ( ssIsMajorTimeStep ( rtS
) ) { srUpdateBC ( rtDW . gvkoaih0tt ) ; } break ; } if ( ssIsMajorTimeStep (
rtS ) ) { srUpdateBC ( rtDW . fw1wxjvjvv ) ; } break ; } rtB . olx5gr2zcm = -
rtB . l2aegg0det [ 1 ] ; rtB . jzubqdhmue = - rtB . l2aegg0det [ 2 ] ; rtB .
mupkswka3h = - rtB . l2aegg0det [ 3 ] ; rtB . gnf3ee0yie [ 0 ] = ( ( rtB .
lronvhy5ya [ 1 ] * rtB . kta3wrejd4 [ 2 ] - rtB . lronvhy5ya [ 2 ] * rtB .
kta3wrejd4 [ 1 ] ) + rtB . ajquw4hgfb [ 0 ] ) * rtP . Gain_Gain_mpiyuuuwgr ;
rtB . gnf3ee0yie [ 1 ] = ( ( rtB . lronvhy5ya [ 2 ] * rtB . kta3wrejd4 [ 0 ]
- rtB . lronvhy5ya [ 0 ] * rtB . kta3wrejd4 [ 2 ] ) + rtB . ajquw4hgfb [ 1 ]
) * rtP . Gain_Gain_mpiyuuuwgr ; rtB . gnf3ee0yie [ 2 ] = ( ( rtB .
lronvhy5ya [ 0 ] * rtB . kta3wrejd4 [ 1 ] - rtB . lronvhy5ya [ 1 ] * rtB .
kta3wrejd4 [ 0 ] ) + rtB . ajquw4hgfb [ 2 ] ) * rtP . Gain_Gain_mpiyuuuwgr ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . jgvugjcell [ 0 ] = rtB . gnf3ee0yie
[ 0 ] >= rtP . Saturation_UpperSat_hafkqiwfxz ? 1 : rtB . gnf3ee0yie [ 0 ] >
rtP . Saturation_LowerSat_jlais4nb4c ? 0 : - 1 ; rtDW . jgvugjcell [ 1 ] =
rtB . gnf3ee0yie [ 1 ] >= rtP . Saturation_UpperSat_hafkqiwfxz ? 1 : rtB .
gnf3ee0yie [ 1 ] > rtP . Saturation_LowerSat_jlais4nb4c ? 0 : - 1 ; rtDW .
jgvugjcell [ 2 ] = rtB . gnf3ee0yie [ 2 ] >= rtP .
Saturation_UpperSat_hafkqiwfxz ? 1 : rtB . gnf3ee0yie [ 2 ] > rtP .
Saturation_LowerSat_jlais4nb4c ? 0 : - 1 ; } rtB . bj3cbec4w1 [ 0 ] = rtDW .
jgvugjcell [ 0 ] == 1 ? rtP . Saturation_UpperSat_hafkqiwfxz : rtDW .
jgvugjcell [ 0 ] == - 1 ? rtP . Saturation_LowerSat_jlais4nb4c : rtB .
gnf3ee0yie [ 0 ] ; rtB . bj3cbec4w1 [ 1 ] = rtDW . jgvugjcell [ 1 ] == 1 ?
rtP . Saturation_UpperSat_hafkqiwfxz : rtDW . jgvugjcell [ 1 ] == - 1 ? rtP .
Saturation_LowerSat_jlais4nb4c : rtB . gnf3ee0yie [ 1 ] ; rtB . bj3cbec4w1 [
2 ] = rtDW . jgvugjcell [ 2 ] == 1 ? rtP . Saturation_UpperSat_hafkqiwfxz :
rtDW . jgvugjcell [ 2 ] == - 1 ? rtP . Saturation_LowerSat_jlais4nb4c : rtB .
gnf3ee0yie [ 2 ] ; oducdqkgjs_idx_e = ( ( rtB . l2aegg0det [ 0 ] * rtB .
l2aegg0det [ 0 ] + rtB . olx5gr2zcm * rtB . olx5gr2zcm ) + rtB . jzubqdhmue *
rtB . jzubqdhmue ) + rtB . mupkswka3h * rtB . mupkswka3h ; nfwwjxsmuk = rtB .
l2aegg0det [ 0 ] / oducdqkgjs_idx_e ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . p0m1jnhybt [ 0 ] = rtP . Constant1_Value_fg2gdmjirg [ 0 ] ; rtB .
p0m1jnhybt [ 1 ] = rtP . Constant1_Value_fg2gdmjirg [ 1 ] ; rtB . p0m1jnhybt
[ 2 ] = rtP . Constant1_Value_fg2gdmjirg [ 2 ] ; rtB . p0m1jnhybt [ 3 ] = rtP
. Constant1_Value_fg2gdmjirg [ 3 ] ; } if ( rtDW . phnnzeax4q .
IcNeedsLoading ) { rtX . gffjebdga3 [ 0 ] = rtB . p0m1jnhybt [ 0 ] ; rtX .
gffjebdga3 [ 1 ] = rtB . p0m1jnhybt [ 1 ] ; rtX . gffjebdga3 [ 2 ] = rtB .
p0m1jnhybt [ 2 ] ; rtX . gffjebdga3 [ 3 ] = rtB . p0m1jnhybt [ 3 ] ; }
ivszce53hq [ 0 ] = rtX . gffjebdga3 [ 0 ] ; ivszce53hq [ 1 ] = rtX .
gffjebdga3 [ 1 ] ; ivszce53hq [ 2 ] = rtX . gffjebdga3 [ 2 ] ; ivszce53hq [ 3
] = rtX . gffjebdga3 [ 3 ] ; oducdqkgjs_idx_p = - rtB . olx5gr2zcm /
oducdqkgjs_idx_e ; oducdqkgjs_idx = - rtB . jzubqdhmue / oducdqkgjs_idx_e ;
oducdqkgjs_idx_e = - rtB . mupkswka3h / oducdqkgjs_idx_e ; rtB . jbdetydqg0 =
( ( nfwwjxsmuk * ivszce53hq [ 0 ] - oducdqkgjs_idx_p * ivszce53hq [ 1 ] ) -
oducdqkgjs_idx * ivszce53hq [ 2 ] ) - oducdqkgjs_idx_e * ivszce53hq [ 3 ] ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtB . jbdetydqg0 > 0.0 ) { rtDW . amy2z0blur = 1 ; } else if ( rtB .
jbdetydqg0 < 0.0 ) { rtDW . amy2z0blur = - 1 ; } else { rtDW . amy2z0blur = 0
; } } rtB . ol0ojtxxkn = rtDW . amy2z0blur ; } enzyytwikn = rtB . ol0ojtxxkn
* rtB . jbdetydqg0 ; kpgrz5rhip_idx_p = ( ( ( nfwwjxsmuk * ivszce53hq [ 1 ] +
oducdqkgjs_idx_p * ivszce53hq [ 0 ] ) + oducdqkgjs_idx * ivszce53hq [ 3 ] ) -
oducdqkgjs_idx_e * ivszce53hq [ 2 ] ) * rtB . ol0ojtxxkn ; kpgrz5rhip_idx_e =
( ( ( nfwwjxsmuk * ivszce53hq [ 2 ] - oducdqkgjs_idx_p * ivszce53hq [ 3 ] ) +
oducdqkgjs_idx * ivszce53hq [ 0 ] ) + oducdqkgjs_idx_e * ivszce53hq [ 1 ] ) *
rtB . ol0ojtxxkn ; kpgrz5rhip_idx = ( ( ( nfwwjxsmuk * ivszce53hq [ 3 ] +
oducdqkgjs_idx_p * ivszce53hq [ 2 ] ) - oducdqkgjs_idx * ivszce53hq [ 1 ] ) +
oducdqkgjs_idx_e * ivszce53hq [ 0 ] ) * rtB . ol0ojtxxkn ; oducdqkgjs_idx_e =
( ( enzyytwikn * enzyytwikn + kpgrz5rhip_idx_p * kpgrz5rhip_idx_p ) +
kpgrz5rhip_idx_e * kpgrz5rhip_idx_e ) + kpgrz5rhip_idx * kpgrz5rhip_idx ; if
( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . huixms4qzu != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . huixms4qzu = 0 ; } oducdqkgjs_idx_e =
muDoubleScalarSqrt ( oducdqkgjs_idx_e ) ; } else { if ( oducdqkgjs_idx_e <
0.0 ) { oducdqkgjs_idx_e = - muDoubleScalarSqrt ( muDoubleScalarAbs (
oducdqkgjs_idx_e ) ) ; } else { oducdqkgjs_idx_e = muDoubleScalarSqrt (
oducdqkgjs_idx_e ) ; } rtDW . huixms4qzu = 1 ; } nfwwjxsmuk =
kpgrz5rhip_idx_e / oducdqkgjs_idx_e ; oducdqkgjs_idx_p = kpgrz5rhip_idx /
oducdqkgjs_idx_e ; oducdqkgjs_idx = kpgrz5rhip_idx_p / oducdqkgjs_idx_e ;
oducdqkgjs_idx_e = enzyytwikn / oducdqkgjs_idx_e ; oydzcnlmnv [ 0 ] = ( ( ( (
rtP . Constant_Value_ej4q1vwpv0 - nfwwjxsmuk * nfwwjxsmuk ) -
oducdqkgjs_idx_p * oducdqkgjs_idx_p ) * rtP . Gain2_Gain_f1yzxme32r * rtP .
Constant_Value_o4e4fo4gkj [ 0 ] + ( oducdqkgjs_idx * nfwwjxsmuk +
oducdqkgjs_idx_e * oducdqkgjs_idx_p ) * rtP . Gain_Gain_itterqoc4x * rtP .
Constant_Value_o4e4fo4gkj [ 1 ] ) + ( oducdqkgjs_idx * oducdqkgjs_idx_p -
oducdqkgjs_idx_e * nfwwjxsmuk ) * rtP . Gain1_Gain_ofwpfqh4qc * rtP .
Constant_Value_o4e4fo4gkj [ 2 ] ) * rtB . fwgif0j4xy [ 0 ] ; oydzcnlmnv [ 1 ]
= ( ( ( ( rtP . Constant_Value_d4om0ngdo1 - oducdqkgjs_idx * oducdqkgjs_idx )
- oducdqkgjs_idx_p * oducdqkgjs_idx_p ) * rtP . Gain2_Gain_lanpf0cnyt * rtP .
Constant_Value_o4e4fo4gkj [ 1 ] + ( oducdqkgjs_idx * nfwwjxsmuk -
oducdqkgjs_idx_e * oducdqkgjs_idx_p ) * rtP . Gain_Gain_jfem1ifujv * rtP .
Constant_Value_o4e4fo4gkj [ 0 ] ) + ( oducdqkgjs_idx_e * oducdqkgjs_idx +
nfwwjxsmuk * oducdqkgjs_idx_p ) * rtP . Gain1_Gain_o3l0m0cqsz * rtP .
Constant_Value_o4e4fo4gkj [ 2 ] ) * rtB . fwgif0j4xy [ 1 ] ; oydzcnlmnv [ 2 ]
= ( ( ( oducdqkgjs_idx * oducdqkgjs_idx_p + oducdqkgjs_idx_e * nfwwjxsmuk ) *
rtP . Gain_Gain_kbkv433xum * rtP . Constant_Value_o4e4fo4gkj [ 0 ] + (
nfwwjxsmuk * oducdqkgjs_idx_p - oducdqkgjs_idx_e * oducdqkgjs_idx ) * rtP .
Gain1_Gain_aw5xkpj1cf * rtP . Constant_Value_o4e4fo4gkj [ 1 ] ) + ( ( rtP .
Constant_Value_pbdti2yadl - oducdqkgjs_idx * oducdqkgjs_idx ) - nfwwjxsmuk *
nfwwjxsmuk ) * rtP . Gain2_Gain_oat3nps3gi * rtP . Constant_Value_o4e4fo4gkj
[ 2 ] ) * rtB . fwgif0j4xy [ 2 ] ; rtB . ep30hm0x0x [ 0 ] = rtP .
Gain5_Gain_fzoolgsndi * oydzcnlmnv [ 0 ] ; rtB . ep30hm0x0x [ 1 ] = rtP .
Gain5_Gain_fzoolgsndi * oydzcnlmnv [ 1 ] ; rtB . ep30hm0x0x [ 2 ] = rtP .
Gain5_Gain_fzoolgsndi * oydzcnlmnv [ 2 ] ; rtB . fpwu5qnsdz [ 0 ] = ( ( rtB .
bj3cbec4w1 [ 0 ] + rtB . ep30hm0x0x [ 0 ] ) + 0.0 ) + 0.0 ; rtB . fpwu5qnsdz
[ 1 ] = ( ( rtB . bj3cbec4w1 [ 1 ] + rtB . ep30hm0x0x [ 1 ] ) + 0.0 ) + 0.0 ;
rtB . fpwu5qnsdz [ 2 ] = ( ( rtB . bj3cbec4w1 [ 2 ] + rtB . ep30hm0x0x [ 2 ]
) + 0.0 ) + 0.0 ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { oydzcnlmnv [ i_p ] =
0.0 ; oydzcnlmnv [ i_p ] += rtP . Constant_Value_e4va2nj2ny [ i_p ] * rtB .
lronvhy5ya [ 0 ] ; oydzcnlmnv [ i_p ] += rtP . Constant_Value_e4va2nj2ny [
i_p + 3 ] * rtB . lronvhy5ya [ 1 ] ; oydzcnlmnv [ i_p ] += rtP .
Constant_Value_e4va2nj2ny [ i_p + 6 ] * rtB . lronvhy5ya [ 2 ] ; } for ( i_p
= 0 ; i_p < 3 ; i_p ++ ) { bguqm55hxa [ i_p ] = jqwtr5xyw4 [ i_p + 6 ] * rtB
. lronvhy5ya [ 2 ] + ( jqwtr5xyw4 [ i_p + 3 ] * rtB . lronvhy5ya [ 1 ] +
jqwtr5xyw4 [ i_p ] * rtB . lronvhy5ya [ 0 ] ) ; } oydzcnlmnv [ 0 ] = ( rtB .
fpwu5qnsdz [ 0 ] - oydzcnlmnv [ 0 ] ) - ( rtB . lronvhy5ya [ 1 ] * bguqm55hxa
[ 2 ] - rtB . lronvhy5ya [ 2 ] * bguqm55hxa [ 1 ] ) ; oydzcnlmnv [ 1 ] = (
rtB . fpwu5qnsdz [ 1 ] - oydzcnlmnv [ 1 ] ) - ( rtB . lronvhy5ya [ 2 ] *
bguqm55hxa [ 0 ] - rtB . lronvhy5ya [ 0 ] * bguqm55hxa [ 2 ] ) ; oydzcnlmnv [
2 ] = ( rtB . fpwu5qnsdz [ 2 ] - oydzcnlmnv [ 2 ] ) - ( rtB . lronvhy5ya [ 0
] * bguqm55hxa [ 1 ] - rtB . lronvhy5ya [ 1 ] * bguqm55hxa [ 0 ] ) ;
rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( jqwtr5xyw4 , oydzcnlmnv , rtB .
pirqrlkfn1 ) ; oducdqkgjs_idx_e = ( rtP . Constant_Value_fjgr21kt5s - ( ( (
ivszce53hq [ 0 ] * ivszce53hq [ 0 ] + ivszce53hq [ 1 ] * ivszce53hq [ 1 ] ) +
ivszce53hq [ 2 ] * ivszce53hq [ 2 ] ) + ivszce53hq [ 3 ] * ivszce53hq [ 3 ] )
) * rtP . HighGainQuaternionNormalization_Gain_ob3hm0wdis ; rtB . bivwrzak4c
= ( ( ivszce53hq [ 1 ] * rtB . lronvhy5ya [ 0 ] + ivszce53hq [ 2 ] * rtB .
lronvhy5ya [ 1 ] ) + ivszce53hq [ 3 ] * rtB . lronvhy5ya [ 2 ] ) * - 0.5 +
oducdqkgjs_idx_e * ivszce53hq [ 0 ] ; rtB . mdhwvkkkpg = ( ( ivszce53hq [ 0 ]
* rtB . lronvhy5ya [ 0 ] + ivszce53hq [ 2 ] * rtB . lronvhy5ya [ 2 ] ) -
ivszce53hq [ 3 ] * rtB . lronvhy5ya [ 1 ] ) * 0.5 + oducdqkgjs_idx_e *
ivszce53hq [ 1 ] ; rtB . kknubsmket = ( ( ivszce53hq [ 0 ] * rtB . lronvhy5ya
[ 1 ] + ivszce53hq [ 3 ] * rtB . lronvhy5ya [ 0 ] ) - ivszce53hq [ 1 ] * rtB
. lronvhy5ya [ 2 ] ) * 0.5 + oducdqkgjs_idx_e * ivszce53hq [ 2 ] ; rtB .
pok3faxosu = ( ( ivszce53hq [ 0 ] * rtB . lronvhy5ya [ 2 ] + ivszce53hq [ 1 ]
* rtB . lronvhy5ya [ 1 ] ) - ivszce53hq [ 2 ] * rtB . lronvhy5ya [ 0 ] ) *
0.5 + oducdqkgjs_idx_e * ivszce53hq [ 3 ] ; if ( ssGetLogOutput ( rtS ) ) { {
{ void * signalProbe = ( void * ) rtDW . iyqxvnatsr . SignalProbe ; real_T t
; void * u ; t = ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB .
lronvhy5ya [ 0 ] ; rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } }
rtB . iklax5zz5j [ 0 ] = rtB . l2aegg0det [ 0 ] ; rtB . iklax5zz5j [ 1 ] =
rtB . olx5gr2zcm ; rtB . iklax5zz5j [ 2 ] = rtB . jzubqdhmue ; rtB .
iklax5zz5j [ 3 ] = rtB . mupkswka3h ; if ( ssGetLogOutput ( rtS ) ) { { {
void * signalProbe = ( void * ) rtDW . h4jqbncwhd . SignalProbe ; real_T t ;
void * u ; t = ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . iklax5zz5j
[ 0 ] ; rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
hu21nqqcni . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . bj3cbec4w1 [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } if ( ssGetLogOutput ( rtS ) ) { { { void *
signalProbe = ( void * ) rtDW . oawgrr5lku . SignalProbe ; real_T t ; void *
u ; t = ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . ep30hm0x0x [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
behvht2jjq . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . fwgif0j4xy [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } if ( ssGetLogOutput ( rtS ) ) { { { void *
signalProbe = ( void * ) rtDW . jjiadmicyc . SignalProbe ; real_T t ; void *
u ; t = ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . h5ipoluxjw [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
bgsuqbvq3e . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . klwhzltza0 [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } if ( ssGetLogOutput ( rtS ) ) { { { void *
signalProbe = ( void * ) rtDW . m10l43wuz3 . SignalProbe ; real_T t ; void *
u ; t = ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . ixebsztwtv [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if ( ssIsSampleHit
( rtS , 4 , 0 ) ) { rtB . nx1aqqkpv1 [ 0 ] = rtP . Output_Gain_ba0gpqdttx [ 0
] * rtDW . phocmexnl1 ; rtB . nx1aqqkpv1 [ 1 ] = rtP . Output_Gain_ba0gpqdttx
[ 1 ] * rtDW . phocmexnl1 ; rtB . nx1aqqkpv1 [ 2 ] = rtP .
Output_Gain_ba0gpqdttx [ 2 ] * rtDW . phocmexnl1 ; } oydzcnlmnv [ 0 ] = rtP .
Gain_Gain_ovaf4mtkfv * la1hfx5r2w . rsun [ 0 ] - la1hfx5r2w . j2000 [ 0 ] ;
oydzcnlmnv [ 1 ] = rtP . Gain_Gain_ovaf4mtkfv * la1hfx5r2w . rsun [ 1 ] -
la1hfx5r2w . j2000 [ 1 ] ; oydzcnlmnv [ 2 ] = rtP . Gain_Gain_ovaf4mtkfv *
la1hfx5r2w . rsun [ 2 ] - la1hfx5r2w . j2000 [ 2 ] ; oducdqkgjs_idx_e = ( (
ivszce53hq [ 0 ] * ivszce53hq [ 0 ] + ivszce53hq [ 1 ] * ivszce53hq [ 1 ] ) +
ivszce53hq [ 2 ] * ivszce53hq [ 2 ] ) + ivszce53hq [ 3 ] * ivszce53hq [ 3 ] ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . pfcneilmew != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . pfcneilmew = 0 ; } oducdqkgjs_idx_e =
muDoubleScalarSqrt ( oducdqkgjs_idx_e ) ; } else { if ( oducdqkgjs_idx_e <
0.0 ) { oducdqkgjs_idx_e = - muDoubleScalarSqrt ( muDoubleScalarAbs (
oducdqkgjs_idx_e ) ) ; } else { oducdqkgjs_idx_e = muDoubleScalarSqrt (
oducdqkgjs_idx_e ) ; } rtDW . pfcneilmew = 1 ; } nfwwjxsmuk = ivszce53hq [ 2
] / oducdqkgjs_idx_e ; oducdqkgjs_idx_p = ivszce53hq [ 3 ] / oducdqkgjs_idx_e
; oducdqkgjs_idx = ivszce53hq [ 1 ] / oducdqkgjs_idx_e ; oducdqkgjs_idx_e =
ivszce53hq [ 0 ] / oducdqkgjs_idx_e ; rtB . i1cyqesfho = ( ( ( rtP .
Constant_Value_nt3nodlo0n - nfwwjxsmuk * nfwwjxsmuk ) - oducdqkgjs_idx_p *
oducdqkgjs_idx_p ) * rtP . Gain2_Gain_b455g1loe1 * oydzcnlmnv [ 0 ] + (
oducdqkgjs_idx * nfwwjxsmuk + oducdqkgjs_idx_e * oducdqkgjs_idx_p ) * rtP .
Gain_Gain_pxe1qwiizn * oydzcnlmnv [ 1 ] ) + ( oducdqkgjs_idx *
oducdqkgjs_idx_p - oducdqkgjs_idx_e * nfwwjxsmuk ) * rtP .
Gain1_Gain_huu1lmrels * oydzcnlmnv [ 2 ] ; rtB . e1jmsnwsko = ( ( ( rtP .
Constant_Value_jy4gaazlnd - oducdqkgjs_idx * oducdqkgjs_idx ) -
oducdqkgjs_idx_p * oducdqkgjs_idx_p ) * rtP . Gain2_Gain_bujbdfke15 *
oydzcnlmnv [ 1 ] + ( oducdqkgjs_idx * nfwwjxsmuk - oducdqkgjs_idx_e *
oducdqkgjs_idx_p ) * rtP . Gain_Gain_j0vyy2fy2r * oydzcnlmnv [ 0 ] ) + (
oducdqkgjs_idx_e * oducdqkgjs_idx + nfwwjxsmuk * oducdqkgjs_idx_p ) * rtP .
Gain1_Gain_fkwqudcabt * oydzcnlmnv [ 2 ] ; rtB . h2b1u411ed = ( (
oducdqkgjs_idx * oducdqkgjs_idx_p + oducdqkgjs_idx_e * nfwwjxsmuk ) * rtP .
Gain_Gain_bigflic040 * oydzcnlmnv [ 0 ] + ( nfwwjxsmuk * oducdqkgjs_idx_p -
oducdqkgjs_idx_e * oducdqkgjs_idx ) * rtP . Gain1_Gain_hfanpouy13 *
oydzcnlmnv [ 1 ] ) + ( ( rtP . Constant_Value_mctqlak3ab - oducdqkgjs_idx *
oducdqkgjs_idx ) - nfwwjxsmuk * nfwwjxsmuk ) * rtP . Gain2_Gain_o4dc4ko20g *
oydzcnlmnv [ 2 ] ; oducdqkgjs_idx_e = ( rtB . i1cyqesfho * rtB . i1cyqesfho +
rtB . e1jmsnwsko * rtB . e1jmsnwsko ) + rtB . h2b1u411ed * rtB . h2b1u411ed ;
if ( oducdqkgjs_idx_e < 0.0 ) { rtB . ia5lss0zy0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( oducdqkgjs_idx_e ) ) ; } else { rtB . ia5lss0zy0 =
muDoubleScalarSqrt ( oducdqkgjs_idx_e ) ; } if ( ssIsMajorTimeStep ( rtS ) )
{ rtDW . et15tz1dc1 = ( rtB . ia5lss0zy0 > rtP . Switch_Threshold_jv24xn0sxc
) ; } if ( ! rtDW . et15tz1dc1 ) { rtB . ps4hnijzog [ 0 ] = rtB . i1cyqesfho
* 0.0 ; rtB . ps4hnijzog [ 1 ] = rtB . e1jmsnwsko * 0.0 ; rtB . ps4hnijzog [
2 ] = rtB . h2b1u411ed * 0.0 ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate
( int_T tid ) { rtDW . evzrtqyrte . IcNeedsLoading = 0 ; rtDW . l3ydkkphoy .
IcNeedsLoading = 0 ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtDW . m5suqpxty3
= rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . hvy1dfvqu0 ) * rtP .
WhiteNoise_StdDev + rtP . WhiteNoise_Mean ; } { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; if ( rtX . al32ndubg1 [ 0 ] == rtP .
IntegratorLimited_UpperSat ) { switch ( rtDW . ibmaa0h4pk [ 0 ] ) { case
INTG_UPPER_SAT : if ( rtB . jaerpbqnqm [ 0 ] < 0.0 ) { ssSetSolverNeedsReset
( rtS ) ; rtDW . ibmaa0h4pk [ 0 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( rtB . jaerpbqnqm [ 0 ] >= 0.0 ) { rtDW .
ibmaa0h4pk [ 0 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ;
default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB . jaerpbqnqm [ 0 ] < 0.0 )
{ rtDW . ibmaa0h4pk [ 0 ] = INTG_LEAVING_UPPER_SAT ; } else { rtDW .
ibmaa0h4pk [ 0 ] = INTG_UPPER_SAT ; } break ; } } else if ( rtX . al32ndubg1
[ 0 ] == rtP . IntegratorLimited_LowerSat ) { switch ( rtDW . ibmaa0h4pk [ 0
] ) { case INTG_LOWER_SAT : if ( rtB . jaerpbqnqm [ 0 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . ibmaa0h4pk [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
jaerpbqnqm [ 0 ] <= 0.0 ) { rtDW . ibmaa0h4pk [ 0 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . jaerpbqnqm [ 0 ] > 0.0 ) { rtDW . ibmaa0h4pk [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . ibmaa0h4pk [ 0 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . ibmaa0h4pk [ 0 ] = INTG_NORMAL ; } if ( rtX .
al32ndubg1 [ 1 ] == rtP . IntegratorLimited_UpperSat ) { switch ( rtDW .
ibmaa0h4pk [ 1 ] ) { case INTG_UPPER_SAT : if ( rtB . jaerpbqnqm [ 1 ] < 0.0
) { ssSetSolverNeedsReset ( rtS ) ; rtDW . ibmaa0h4pk [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
jaerpbqnqm [ 1 ] >= 0.0 ) { rtDW . ibmaa0h4pk [ 1 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . jaerpbqnqm [ 1 ] < 0.0 ) { rtDW . ibmaa0h4pk [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . ibmaa0h4pk [ 1 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . al32ndubg1 [ 1 ] == rtP .
IntegratorLimited_LowerSat ) { switch ( rtDW . ibmaa0h4pk [ 1 ] ) { case
INTG_LOWER_SAT : if ( rtB . jaerpbqnqm [ 1 ] > 0.0 ) { ssSetSolverNeedsReset
( rtS ) ; rtDW . ibmaa0h4pk [ 1 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( rtB . jaerpbqnqm [ 1 ] <= 0.0 ) { rtDW .
ibmaa0h4pk [ 1 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ;
default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB . jaerpbqnqm [ 1 ] > 0.0 )
{ rtDW . ibmaa0h4pk [ 1 ] = INTG_LEAVING_LOWER_SAT ; } else { rtDW .
ibmaa0h4pk [ 1 ] = INTG_LOWER_SAT ; } break ; } } else { rtDW . ibmaa0h4pk [
1 ] = INTG_NORMAL ; } if ( rtX . al32ndubg1 [ 2 ] == rtP .
IntegratorLimited_UpperSat ) { switch ( rtDW . ibmaa0h4pk [ 2 ] ) { case
INTG_UPPER_SAT : if ( rtB . jaerpbqnqm [ 2 ] < 0.0 ) { ssSetSolverNeedsReset
( rtS ) ; rtDW . ibmaa0h4pk [ 2 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( rtB . jaerpbqnqm [ 2 ] >= 0.0 ) { rtDW .
ibmaa0h4pk [ 2 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ;
default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB . jaerpbqnqm [ 2 ] < 0.0 )
{ rtDW . ibmaa0h4pk [ 2 ] = INTG_LEAVING_UPPER_SAT ; } else { rtDW .
ibmaa0h4pk [ 2 ] = INTG_UPPER_SAT ; } break ; } } else if ( rtX . al32ndubg1
[ 2 ] == rtP . IntegratorLimited_LowerSat ) { switch ( rtDW . ibmaa0h4pk [ 2
] ) { case INTG_LOWER_SAT : if ( rtB . jaerpbqnqm [ 2 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . ibmaa0h4pk [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
jaerpbqnqm [ 2 ] <= 0.0 ) { rtDW . ibmaa0h4pk [ 2 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . jaerpbqnqm [ 2 ] > 0.0 ) { rtDW . ibmaa0h4pk [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . ibmaa0h4pk [ 2 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . ibmaa0h4pk [ 2 ] = INTG_NORMAL ; } } { enum {
INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( rtX . abpf02yfny [ 0 ] == rtP .
IntegratorLimited_UpperSat_ntkxmpf0qj ) { switch ( rtDW . hxjtibst42 [ 0 ] )
{ case INTG_UPPER_SAT : if ( rtB . l4ynfqsuix [ 0 ] < 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . hxjtibst42 [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
l4ynfqsuix [ 0 ] >= 0.0 ) { rtDW . hxjtibst42 [ 0 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . l4ynfqsuix [ 0 ] < 0.0 ) { rtDW . hxjtibst42 [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . hxjtibst42 [ 0 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . abpf02yfny [ 0 ] == rtP .
IntegratorLimited_LowerSat_oacseuhnry ) { switch ( rtDW . hxjtibst42 [ 0 ] )
{ case INTG_LOWER_SAT : if ( rtB . l4ynfqsuix [ 0 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . hxjtibst42 [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
l4ynfqsuix [ 0 ] <= 0.0 ) { rtDW . hxjtibst42 [ 0 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . l4ynfqsuix [ 0 ] > 0.0 ) { rtDW . hxjtibst42 [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . hxjtibst42 [ 0 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . hxjtibst42 [ 0 ] = INTG_NORMAL ; } if ( rtX .
abpf02yfny [ 1 ] == rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ) { switch (
rtDW . hxjtibst42 [ 1 ] ) { case INTG_UPPER_SAT : if ( rtB . l4ynfqsuix [ 1 ]
< 0.0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . hxjtibst42 [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
l4ynfqsuix [ 1 ] >= 0.0 ) { rtDW . hxjtibst42 [ 1 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . l4ynfqsuix [ 1 ] < 0.0 ) { rtDW . hxjtibst42 [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . hxjtibst42 [ 1 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . abpf02yfny [ 1 ] == rtP .
IntegratorLimited_LowerSat_oacseuhnry ) { switch ( rtDW . hxjtibst42 [ 1 ] )
{ case INTG_LOWER_SAT : if ( rtB . l4ynfqsuix [ 1 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . hxjtibst42 [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
l4ynfqsuix [ 1 ] <= 0.0 ) { rtDW . hxjtibst42 [ 1 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . l4ynfqsuix [ 1 ] > 0.0 ) { rtDW . hxjtibst42 [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . hxjtibst42 [ 1 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . hxjtibst42 [ 1 ] = INTG_NORMAL ; } if ( rtX .
abpf02yfny [ 2 ] == rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ) { switch (
rtDW . hxjtibst42 [ 2 ] ) { case INTG_UPPER_SAT : if ( rtB . l4ynfqsuix [ 2 ]
< 0.0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . hxjtibst42 [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
l4ynfqsuix [ 2 ] >= 0.0 ) { rtDW . hxjtibst42 [ 2 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . l4ynfqsuix [ 2 ] < 0.0 ) { rtDW . hxjtibst42 [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . hxjtibst42 [ 2 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . abpf02yfny [ 2 ] == rtP .
IntegratorLimited_LowerSat_oacseuhnry ) { switch ( rtDW . hxjtibst42 [ 2 ] )
{ case INTG_LOWER_SAT : if ( rtB . l4ynfqsuix [ 2 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . hxjtibst42 [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
l4ynfqsuix [ 2 ] <= 0.0 ) { rtDW . hxjtibst42 [ 2 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . l4ynfqsuix [ 2 ] > 0.0 ) { rtDW . hxjtibst42 [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . hxjtibst42 [ 2 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . hxjtibst42 [ 2 ] = INTG_NORMAL ; } } rtDW .
phnnzeax4q . IcNeedsLoading = 0 ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtDW
. phocmexnl1 = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k2mw3e5m15 ) * rtP .
WhiteNoise_StdDev_esrovvidoo + rtP . WhiteNoise_Mean_fpnv13epd5 ; }
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { { ( ( XDot * )
ssGetdX ( rtS ) ) -> b1lr14rcuj [ 0 ] = rtB . pbw2adbesb ; ( ( XDot * )
ssGetdX ( rtS ) ) -> b1lr14rcuj [ 1 ] = rtB . ab5xgw0342 ; ( ( XDot * )
ssGetdX ( rtS ) ) -> b1lr14rcuj [ 2 ] = rtB . ct3c5eoli2 ; ( ( XDot * )
ssGetdX ( rtS ) ) -> b1lr14rcuj [ 3 ] = rtB . crik5dobwi ; } { ( ( XDot * )
ssGetdX ( rtS ) ) -> ba1rjb3ky4 [ 0 ] = rtB . pirqrlkfn1 [ 0 ] ; ( ( XDot * )
ssGetdX ( rtS ) ) -> ba1rjb3ky4 [ 1 ] = rtB . pirqrlkfn1 [ 1 ] ; ( ( XDot * )
ssGetdX ( rtS ) ) -> ba1rjb3ky4 [ 2 ] = rtB . pirqrlkfn1 [ 2 ] ; } { ( ( XDot
* ) ssGetdX ( rtS ) ) -> hod35jdtrz [ 0 ] = rtB . nx1aqqkpv1 [ 0 ] ; ( ( XDot
* ) ssGetdX ( rtS ) ) -> hod35jdtrz [ 1 ] = rtB . nx1aqqkpv1 [ 1 ] ; ( ( XDot
* ) ssGetdX ( rtS ) ) -> hod35jdtrz [ 2 ] = rtB . nx1aqqkpv1 [ 2 ] ; } { enum
{ INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( rtDW . ibmaa0h4pk [ 0 ] !=
INTG_UPPER_SAT ) && ( rtDW . ibmaa0h4pk [ 0 ] != INTG_LOWER_SAT ) ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> al32ndubg1 [ 0 ] = rtB . jaerpbqnqm [ 0 ] ; ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) -> al32ndubg1 [ 0 ] = FALSE ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> al32ndubg1 [ 0 ] = 0.0 ; if ( ( rtDW
. ibmaa0h4pk [ 0 ] == INTG_UPPER_SAT ) || ( rtDW . ibmaa0h4pk [ 0 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
al32ndubg1 [ 0 ] = TRUE ; } } if ( ( rtDW . ibmaa0h4pk [ 1 ] !=
INTG_UPPER_SAT ) && ( rtDW . ibmaa0h4pk [ 1 ] != INTG_LOWER_SAT ) ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> al32ndubg1 [ 1 ] = rtB . jaerpbqnqm [ 1 ] ; ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) -> al32ndubg1 [ 1 ] = FALSE ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> al32ndubg1 [ 1 ] = 0.0 ; if ( ( rtDW
. ibmaa0h4pk [ 1 ] == INTG_UPPER_SAT ) || ( rtDW . ibmaa0h4pk [ 1 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
al32ndubg1 [ 1 ] = TRUE ; } } if ( ( rtDW . ibmaa0h4pk [ 2 ] !=
INTG_UPPER_SAT ) && ( rtDW . ibmaa0h4pk [ 2 ] != INTG_LOWER_SAT ) ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> al32ndubg1 [ 2 ] = rtB . jaerpbqnqm [ 2 ] ; ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) -> al32ndubg1 [ 2 ] = FALSE ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> al32ndubg1 [ 2 ] = 0.0 ; if ( ( rtDW
. ibmaa0h4pk [ 2 ] == INTG_UPPER_SAT ) || ( rtDW . ibmaa0h4pk [ 2 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
al32ndubg1 [ 2 ] = TRUE ; } } } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT
, INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( rtDW .
hxjtibst42 [ 0 ] != INTG_UPPER_SAT ) && ( rtDW . hxjtibst42 [ 0 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 0 ] = rtB
. l4ynfqsuix [ 0 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
abpf02yfny [ 0 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
abpf02yfny [ 0 ] = 0.0 ; if ( ( rtDW . hxjtibst42 [ 0 ] == INTG_UPPER_SAT )
|| ( rtDW . hxjtibst42 [ 0 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> abpf02yfny [ 0 ] = TRUE ; } } if ( ( rtDW
. hxjtibst42 [ 1 ] != INTG_UPPER_SAT ) && ( rtDW . hxjtibst42 [ 1 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 1 ] = rtB
. l4ynfqsuix [ 1 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
abpf02yfny [ 1 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
abpf02yfny [ 1 ] = 0.0 ; if ( ( rtDW . hxjtibst42 [ 1 ] == INTG_UPPER_SAT )
|| ( rtDW . hxjtibst42 [ 1 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> abpf02yfny [ 1 ] = TRUE ; } } if ( ( rtDW
. hxjtibst42 [ 2 ] != INTG_UPPER_SAT ) && ( rtDW . hxjtibst42 [ 2 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 2 ] = rtB
. l4ynfqsuix [ 2 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
abpf02yfny [ 2 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
abpf02yfny [ 2 ] = 0.0 ; if ( ( rtDW . hxjtibst42 [ 2 ] == INTG_UPPER_SAT )
|| ( rtDW . hxjtibst42 [ 2 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> abpf02yfny [ 2 ] = TRUE ; } } } { ( (
XDot * ) ssGetdX ( rtS ) ) -> gffjebdga3 [ 0 ] = rtB . bivwrzak4c ; ( ( XDot
* ) ssGetdX ( rtS ) ) -> gffjebdga3 [ 1 ] = rtB . mdhwvkkkpg ; ( ( XDot * )
ssGetdX ( rtS ) ) -> gffjebdga3 [ 2 ] = rtB . kknubsmket ; ( ( XDot * )
ssGetdX ( rtS ) ) -> gffjebdga3 [ 3 ] = rtB . pok3faxosu ; } } void
MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ;
_rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; if ( rtDW .
bwuwpskbe1 == 1 ) { } _rtZCSV -> jdg5fgght1 = rtB . bwyuqwyvcb - rtP .
Switch_Threshold_l3zqxo5bwe ; { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( rtDW .
ibmaa0h4pk [ 0 ] == INTG_LEAVING_UPPER_SAT && rtX . al32ndubg1 [ 0 ] >= rtP .
IntegratorLimited_UpperSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> l3y1u5obwt [ 0 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> l3y1u5obwt [ 0 ] = rtX . al32ndubg1 [ 0 ] - rtP .
IntegratorLimited_UpperSat ; } if ( rtDW . ibmaa0h4pk [ 0 ] ==
INTG_LEAVING_LOWER_SAT && rtX . al32ndubg1 [ 0 ] <= rtP .
IntegratorLimited_LowerSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> nasw0mlmjm [ 0 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> nasw0mlmjm [ 0 ] = rtX . al32ndubg1 [ 0 ] - rtP .
IntegratorLimited_LowerSat ; } if ( rtDW . ibmaa0h4pk [ 1 ] ==
INTG_LEAVING_UPPER_SAT && rtX . al32ndubg1 [ 1 ] >= rtP .
IntegratorLimited_UpperSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> l3y1u5obwt [ 1 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> l3y1u5obwt [ 1 ] = rtX . al32ndubg1 [ 1 ] - rtP .
IntegratorLimited_UpperSat ; } if ( rtDW . ibmaa0h4pk [ 1 ] ==
INTG_LEAVING_LOWER_SAT && rtX . al32ndubg1 [ 1 ] <= rtP .
IntegratorLimited_LowerSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> nasw0mlmjm [ 1 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> nasw0mlmjm [ 1 ] = rtX . al32ndubg1 [ 1 ] - rtP .
IntegratorLimited_LowerSat ; } if ( rtDW . ibmaa0h4pk [ 2 ] ==
INTG_LEAVING_UPPER_SAT && rtX . al32ndubg1 [ 2 ] >= rtP .
IntegratorLimited_UpperSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> l3y1u5obwt [ 2 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> l3y1u5obwt [ 2 ] = rtX . al32ndubg1 [ 2 ] - rtP .
IntegratorLimited_UpperSat ; } if ( rtDW . ibmaa0h4pk [ 2 ] ==
INTG_LEAVING_LOWER_SAT && rtX . al32ndubg1 [ 2 ] <= rtP .
IntegratorLimited_LowerSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> nasw0mlmjm [ 2 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> nasw0mlmjm [ 2 ] = rtX . al32ndubg1 [ 2 ] - rtP .
IntegratorLimited_LowerSat ; } } _rtZCSV -> of1glfyyn3 [ 0 ] = rtB .
jty1zsef01 [ 0 ] - rtP . Saturation_UpperSat ; _rtZCSV -> fqt0mvrdyk [ 0 ] =
rtB . jty1zsef01 [ 0 ] - rtP . Saturation_LowerSat ; _rtZCSV -> of1glfyyn3 [
1 ] = rtB . jty1zsef01 [ 1 ] - rtP . Saturation_UpperSat ; _rtZCSV ->
fqt0mvrdyk [ 1 ] = rtB . jty1zsef01 [ 1 ] - rtP . Saturation_LowerSat ;
_rtZCSV -> of1glfyyn3 [ 2 ] = rtB . jty1zsef01 [ 2 ] - rtP .
Saturation_UpperSat ; _rtZCSV -> fqt0mvrdyk [ 2 ] = rtB . jty1zsef01 [ 2 ] -
rtP . Saturation_LowerSat ; { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( rtDW .
hxjtibst42 [ 0 ] == INTG_LEAVING_UPPER_SAT && rtX . abpf02yfny [ 0 ] >= rtP .
IntegratorLimited_UpperSat_ntkxmpf0qj ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> o3jzv1jvx5 [ 0 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> o3jzv1jvx5 [ 0 ] = rtX .
abpf02yfny [ 0 ] - rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ; } if ( rtDW
. hxjtibst42 [ 0 ] == INTG_LEAVING_LOWER_SAT && rtX . abpf02yfny [ 0 ] <= rtP
. IntegratorLimited_LowerSat_oacseuhnry ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> nl0q2bqjk2 [ 0 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> nl0q2bqjk2 [ 0 ] = rtX .
abpf02yfny [ 0 ] - rtP . IntegratorLimited_LowerSat_oacseuhnry ; } if ( rtDW
. hxjtibst42 [ 1 ] == INTG_LEAVING_UPPER_SAT && rtX . abpf02yfny [ 1 ] >= rtP
. IntegratorLimited_UpperSat_ntkxmpf0qj ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> o3jzv1jvx5 [ 1 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> o3jzv1jvx5 [ 1 ] = rtX .
abpf02yfny [ 1 ] - rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ; } if ( rtDW
. hxjtibst42 [ 1 ] == INTG_LEAVING_LOWER_SAT && rtX . abpf02yfny [ 1 ] <= rtP
. IntegratorLimited_LowerSat_oacseuhnry ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> nl0q2bqjk2 [ 1 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> nl0q2bqjk2 [ 1 ] = rtX .
abpf02yfny [ 1 ] - rtP . IntegratorLimited_LowerSat_oacseuhnry ; } if ( rtDW
. hxjtibst42 [ 2 ] == INTG_LEAVING_UPPER_SAT && rtX . abpf02yfny [ 2 ] >= rtP
. IntegratorLimited_UpperSat_ntkxmpf0qj ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> o3jzv1jvx5 [ 2 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> o3jzv1jvx5 [ 2 ] = rtX .
abpf02yfny [ 2 ] - rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ; } if ( rtDW
. hxjtibst42 [ 2 ] == INTG_LEAVING_LOWER_SAT && rtX . abpf02yfny [ 2 ] <= rtP
. IntegratorLimited_LowerSat_oacseuhnry ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> nl0q2bqjk2 [ 2 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> nl0q2bqjk2 [ 2 ] = rtX .
abpf02yfny [ 2 ] - rtP . IntegratorLimited_LowerSat_oacseuhnry ; } } _rtZCSV
-> conutdf0a1 = rtB . cjc4bi0q0l [ 0 ] - rtP . Switch_Threshold_ocvrgqhwfd ;
_rtZCSV -> on4aexigh0 = rtB . cz3ja34zrq - rtP . Switch_Threshold_dkimt1f1tz
; _rtZCSV -> jvmb2fyiro = rtB . ox2cje3ogi - rtP .
Switch_Threshold_gnlntr1le3 ; _rtZCSV -> c1rvp53ssv = 0.0 ; if ( rtB .
aps03o1u4v > 0.0 ) { _rtZCSV -> c1rvp53ssv = 1.0 ; } { real_T * zcsv = & ( (
( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> p41xajlv1g [ 0 ] ) ; int_T i
; for ( i = 0 ; i < 5 ; i ++ ) { zcsv [ i ] = 0.0 ; } } if ( rtDW .
mf41bf444w == 1 ) { _rtZCSV -> p41xajlv1g [ 0 ] = 0.0 ; _rtZCSV -> p41xajlv1g
[ 1 ] = 0.0 ; if ( ( rtB . cznp4l44bm [ 4 ] > rtB . cznp4l44bm [ 0 ] ) && (
rtB . cznp4l44bm [ 4 ] > rtB . cznp4l44bm [ 8 ] ) ) { _rtZCSV -> p41xajlv1g [
0 ] = 1.0 ; } else { if ( rtB . cznp4l44bm [ 8 ] > rtB . cznp4l44bm [ 0 ] ) {
_rtZCSV -> p41xajlv1g [ 1 ] = 1.0 ; } } { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> bwrmhxxylm = 0.0 ; } if ( rtDW .
pyge1tac5l == 0 ) { _rtZCSV -> bwrmhxxylm = rtB . fwdepyepsg ; } { ( ( ZCV *
) ssGetSolverZcSignalVector ( rtS ) ) -> g50xs5r3vz = 0.0 ; } if ( rtDW .
pyge1tac5l == 1 ) { _rtZCSV -> g50xs5r3vz = rtB . jea3ib45lq ; } { ( ( ZCV *
) ssGetSolverZcSignalVector ( rtS ) ) -> dduw5qfbkp = 0.0 ; } if ( rtDW .
pyge1tac5l == 2 ) { _rtZCSV -> dduw5qfbkp = rtB . p2vvijwdyj ; } } _rtZCSV ->
msqpbrzbho [ 0 ] = rtB . gnf3ee0yie [ 0 ] - rtP .
Saturation_UpperSat_hafkqiwfxz ; _rtZCSV -> lkeql2wcuq [ 0 ] = rtB .
gnf3ee0yie [ 0 ] - rtP . Saturation_LowerSat_jlais4nb4c ; _rtZCSV ->
msqpbrzbho [ 1 ] = rtB . gnf3ee0yie [ 1 ] - rtP .
Saturation_UpperSat_hafkqiwfxz ; _rtZCSV -> lkeql2wcuq [ 1 ] = rtB .
gnf3ee0yie [ 1 ] - rtP . Saturation_LowerSat_jlais4nb4c ; _rtZCSV ->
msqpbrzbho [ 2 ] = rtB . gnf3ee0yie [ 2 ] - rtP .
Saturation_UpperSat_hafkqiwfxz ; _rtZCSV -> lkeql2wcuq [ 2 ] = rtB .
gnf3ee0yie [ 2 ] - rtP . Saturation_LowerSat_jlais4nb4c ; _rtZCSV ->
l2ciyo4le3 = rtB . jbdetydqg0 ; _rtZCSV -> oysbzpsleq = rtB . ia5lss0zy0 -
rtP . Switch_Threshold_jv24xn0sxc ; } void MdlTerminate ( void ) { { int_T i1
; void * * pw_RSimInfoPtr = & rtDW . bknzq3wgub . RSimInfoPtr [ 0 ] ; for (
i1 = 0 ; i1 < 5 ; i1 ++ ) { rt_FREE ( pw_RSimInfoPtr [ i1 ] ) ; } } { void *
signalProbe = ( void * ) rtDW . hzkxwtgg3y . SignalProbe ; const char *
fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . ethxueuerq . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . mohxnwpvy0 . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . fs3xofbgsa . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . iyqxvnatsr . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . h4jqbncwhd . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . hu21nqqcni . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . oawgrr5lku . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . behvht2jjq . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . jjiadmicyc . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . bgsuqbvq3e . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . m10l43wuz3 . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
} void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 20 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 5 ) ; ssSetNumBlocks ( rtS , 760 ) ;
ssSetNumBlockIO ( rtS , 102 ) ; ssSetNumBlockParams ( rtS , 19933 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 0.01 ) ;
ssSetSampleTime ( rtS , 3 , 0.09 ) ; ssSetSampleTime ( rtS , 4 , 0.1 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0 ) ;
ssSetOffsetTime ( rtS , 4 , 0.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 2895350130U ) ; ssSetChecksumVal ( rtS ,
1 , 186074619U ) ; ssSetChecksumVal ( rtS , 2 , 3193846734U ) ;
ssSetChecksumVal ( rtS , 3 , 2883452240U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = ( real_T * )
& rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 ,
sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS
, dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 15 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . B = & rtBTransTable ;
dtInfo . P = & rtPTransTable ; } ssSetRootSS ( rtS , rtS ) ; ssSetVersion (
rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "ACStesbed1" ) ;
ssSetPath ( rtS , "ACStesbed1" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 10000.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; ssSetRTWLogInfo (
rtS , & rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] =
{ 4 , 3 , 3 , 3 , 3 , 4 } ; static int_T rt_LoggedStateNumDimensions [ ] = {
1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 4 , 3
, 3 , 3 , 3 , 4 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 ,
0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = {
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"ACStesbed1/CentralComputer/SatAttitude/BINS/quatint/q0\nq1\nq2\nq3" ,
"ACStesbed1/Object/TestBedDynamics/Integrator" ,
"ACStesbed1/Sensors/RateSensor/Integrator" ,
"ACStesbed1/Actuators/Subsystem/Integrator\nLimited" ,
"ACStesbed1/Actuators/RWmodel/Integrator\nLimited" ,
"ACStesbed1/Object/TestBedDynamics/quatint/q0\nq1\nq2\nq3" } ; static const
char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 6 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 6 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . b1lr14rcuj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . ba1rjb3ky4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . hod35jdtrz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . al32ndubg1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . abpf02yfny [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . gffjebdga3 [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetSigLog ( ssGetRTWLogInfo ( rtS
) , "" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 1000 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo (
rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 20
] ; static real_T absTol [ 20 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ;
static uint8_T absTolControl [ 20 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static
uint8_T zcAttributes [ 36 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 19 ] =
{ { 3 * sizeof ( real_T ) , ( char * ) ( & rtB . nx1aqqkpv1 [ 0 ] ) , ( NULL
) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . ol0ojtxxkn ) , ( NULL )
} , { 9 * sizeof ( real_T ) , ( char * ) ( & rtB . pijgu4gjiu [ 0 ] ) , (
NULL ) } , { 9 * sizeof ( real_T ) , ( char * ) ( & rtB . ee2go4u05y [ 0 ] )
, ( NULL ) } , { 9 * sizeof ( real_T ) , ( char * ) ( & rtB . fafimnaesx [ 0
] ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . gutdju0mn5
) , ( NULL ) } , { 9 * sizeof ( real_T ) , ( char * ) ( & rtB . dhwvhv3uh5 [
0 ] ) , ( NULL ) } , { 9 * sizeof ( real_T ) , ( char * ) ( & rtB .
e22yyth3y4 [ 0 ] ) , ( NULL ) } , { 9 * sizeof ( real_T ) , ( char * ) ( &
rtB . a1254pdgfh [ 0 ] ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * )
( & rtB . hdj40uot1u ) , ( NULL ) } , { 9 * sizeof ( real_T ) , ( char * ) (
& rtB . g1xui3hmed [ 0 ] ) , ( NULL ) } , { 9 * sizeof ( real_T ) , ( char *
) ( & rtB . ehlhfalizh [ 0 ] ) , ( NULL ) } , { 9 * sizeof ( real_T ) , (
char * ) ( & rtB . fyykrlz50p [ 0 ] ) , ( NULL ) } , { 1 * sizeof ( real_T )
, ( char * ) ( & rtB . lagfvd2ei5 ) , ( NULL ) } , { 3 * sizeof ( real_T ) ,
( char * ) ( & rtB . jaerpbqnqm [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T
) , ( char * ) ( & rtB . ajquw4hgfb [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . l4ynfqsuix [ 0 ] ) , ( NULL ) } , { 3 *
sizeof ( real_T ) , ( char * ) ( & rtB . neym5ecad1 [ 0 ] ) , ( NULL ) } , {
3 * sizeof ( real_T ) , ( char * ) ( & rtB . kwssbn0ne4 [ 0 ] ) , ( NULL ) }
} ; ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.01 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 19 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 36 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 36 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2895350130U ) ; ssSetChecksumVal ( rtS , 1 ,
186074619U ) ; ssSetChecksumVal ( rtS , 2 , 3193846734U ) ; ssSetChecksumVal
( rtS , 3 , 2883452240U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 26 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . emy0hrjuzr ; systemRan [ 2 ] = ( sysRanDType * ) & rtDW . emy0hrjuzr ;
systemRan [ 3 ] = ( sysRanDType * ) & rtDW . emy0hrjuzr ; systemRan [ 4 ] = (
sysRanDType * ) & rtDW . lflksa1zm2 ; systemRan [ 5 ] = ( sysRanDType * ) &
rtDW . lflksa1zm2 ; systemRan [ 6 ] = ( sysRanDType * ) & rtDW . lflksa1zm2 ;
systemRan [ 7 ] = ( sysRanDType * ) & rtDW . mo3k54wqkm ; systemRan [ 8 ] = (
sysRanDType * ) & rtDW . mo3k54wqkm ; systemRan [ 9 ] = ( sysRanDType * ) &
rtDW . mo3k54wqkm ; systemRan [ 10 ] = ( sysRanDType * ) & rtDW . g325dldung
; systemRan [ 11 ] = ( sysRanDType * ) & rtDW . kkm1wjx4mr ; systemRan [ 12 ]
= & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ; systemRan [ 14 ]
= & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ; systemRan [ 16 ]
= & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ; systemRan [ 18 ]
= ( sysRanDType * ) & rtDW . gvkoaih0tt ; systemRan [ 19 ] = ( sysRanDType *
) & rtDW . occ4jhal5v ; systemRan [ 20 ] = ( sysRanDType * ) & rtDW .
k5kqzwhgid ; systemRan [ 21 ] = ( sysRanDType * ) & rtDW . fw1wxjvjvv ;
systemRan [ 22 ] = ( sysRanDType * ) & rtDW . espotkwrxj ; systemRan [ 23 ] =
& rtAlwaysEnabled ; systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] =
& rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS )
, & ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr (
ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr (
ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
