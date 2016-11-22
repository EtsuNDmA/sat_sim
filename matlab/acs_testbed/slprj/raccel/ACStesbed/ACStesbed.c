#include "__cf_ACStesbed.h"
#include <math.h>
#include "ACStesbed.h"
#include "ACStesbed_private.h"
#include "ACStesbed_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 2 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
const boolean_T gbl_raccel_isMultitasking = 1 ;
#else
const boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
const boolean_T gbl_raccel_tid01eq = 0 ; const int_T gbl_raccel_NumST = 6 ;
const char_T * gbl_raccel_Version = "8.5 (R2013b) 08-Aug-2013" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\ACStesbed\\ACStesbed_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
const BusObject ACStesbed_rtZBusObject = { { 0.0 , 0.0 , 0.0 } , { 0.0 , 0.0
, 0.0 } , { 0.0 , 0.0 , 0.0 } , { 0.0 , 0.0 , 0.0 } , { 0.0 , 0.0 , 0.0 } } ;
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void fri4zeczvq ( SimStruct * const rtS ) { if ( ssGetTaskTime (
rtS , 0 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset ( rtS ) ; } } void
f3tc5mwqyz ( SimStruct * const rtS ) { ssSetSolverNeedsReset ( rtS ) ; } void
e5wfebyea4 ( dmxskfrz2h * localDW ) { localDW -> lggvt2ioqm = 0 ; } void
p0vdevk3x1 ( SimStruct * const rtS , real_T maudr00odw , real_T gewvozca5r ,
real_T p1m1oo3sdu , real_T co1y0npz4d , real_T g3oii5p4ay , real_T ezygnxhmp5
, real_T bxfr00c5zn , real_T * htakh3tv3v , real_T mtfgysrxxh [ 3 ] ,
dmxskfrz2h * localDW , oj32fzmstd * localP ) { real_T jl22qfdigp ; jl22qfdigp
= maudr00odw + localP -> Constant_Value ; if ( ssIsMajorTimeStep ( rtS ) ) {
if ( localDW -> lggvt2ioqm != 0 ) { ssSetSolverNeedsReset ( rtS ) ; localDW
-> lggvt2ioqm = 0 ; } jl22qfdigp = muDoubleScalarSqrt ( jl22qfdigp ) ; } else
{ if ( jl22qfdigp < 0.0 ) { jl22qfdigp = - muDoubleScalarSqrt (
muDoubleScalarAbs ( jl22qfdigp ) ) ; } else { jl22qfdigp = muDoubleScalarSqrt
( jl22qfdigp ) ; } localDW -> lggvt2ioqm = 1 ; } * htakh3tv3v = localP ->
Gain_Gain * jl22qfdigp ; jl22qfdigp *= localP -> Gain1_Gain ; mtfgysrxxh [ 0
] = ( p1m1oo3sdu - gewvozca5r ) / jl22qfdigp ; mtfgysrxxh [ 1 ] = (
co1y0npz4d - g3oii5p4ay ) / jl22qfdigp ; mtfgysrxxh [ 2 ] = ( bxfr00c5zn -
ezygnxhmp5 ) / jl22qfdigp ; } void nc5u50jta2 ( SimStruct * const rtS ) { if
( ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset
( rtS ) ; } } void nws40mclpe ( SimStruct * const rtS , h4iasb5pte * localDW
) { ssSetSolverNeedsReset ( rtS ) ; switch ( localDW -> pyge1tac5l ) { case 0
: ssSetSolverNeedsReset ( rtS ) ; break ; case 1 : ssSetSolverNeedsReset (
rtS ) ; break ; case 2 : ssSetSolverNeedsReset ( rtS ) ; break ; } localDW ->
pyge1tac5l = - 1 ; } void eeuk0bnkti ( h4iasb5pte * localDW ) { localDW ->
pyge1tac5l = - 1 ; localDW -> m4c02ikbg1 = 0 ; localDW -> iq1hnty4rc = 0 ;
localDW -> hrkt2hcocj = 0 ; } void o132e2hrwv ( real_T lk5yn01b43 , real_T
igihmdkbau , real_T opvldjancg , ppxmmlhmiq * localB , h4iasb5pte * localDW ,
p4bsjadjac * localZCSV ) { localZCSV -> p41xajlv1g [ 0 ] = 0.0 ; localZCSV ->
p41xajlv1g [ 1 ] = 0.0 ; if ( ( igihmdkbau > lk5yn01b43 ) && ( igihmdkbau >
opvldjancg ) ) { localZCSV -> p41xajlv1g [ 0 ] = 1.0 ; } else { if (
opvldjancg > lk5yn01b43 ) { localZCSV -> p41xajlv1g [ 1 ] = 1.0 ; } } {
localZCSV -> bwrmhxxylm = 0.0 ; } if ( localDW -> pyge1tac5l == 0 ) {
localZCSV -> bwrmhxxylm = localB -> fwdepyepsg ; } { localZCSV -> g50xs5r3vz
= 0.0 ; } if ( localDW -> pyge1tac5l == 1 ) { localZCSV -> g50xs5r3vz =
localB -> jea3ib45lq ; } { localZCSV -> dduw5qfbkp = 0.0 ; } if ( localDW ->
pyge1tac5l == 2 ) { localZCSV -> dduw5qfbkp = localB -> p2vvijwdyj ; } } void
azz3d4nxce ( SimStruct * const rtS , real_T lk5yn01b43 , real_T igihmdkbau ,
real_T opvldjancg , real_T jautdjk1eb , real_T hgmdlfu242 , real_T psnq5apkya
, real_T a1t4mjaq2j , real_T jwwcum0heq , real_T g3k04yx2hq , real_T *
d5l114dofg , real_T * idw2bnt5im , real_T * mtatrlkgji , real_T * aweaz3zeyc
, ppxmmlhmiq * localB , h4iasb5pte * localDW , a0yd1qizj0 * localP ) { int8_T
rtPrevAction ; int8_T rtAction ; real_T i2bs5a3qqm ; real_T tmp ;
rtPrevAction = localDW -> pyge1tac5l ; if ( ssIsMajorTimeStep ( rtS ) ) { if
( ( igihmdkbau > lk5yn01b43 ) && ( igihmdkbau > opvldjancg ) ) { rtAction = 0
; } else if ( opvldjancg > lk5yn01b43 ) { rtAction = 1 ; } else { rtAction =
2 ; } localDW -> pyge1tac5l = rtAction ; } else { rtAction = localDW ->
pyge1tac5l ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : ssSetSolverNeedsReset ( rtS ) ; break ; case 1 :
ssSetSolverNeedsReset ( rtS ) ; break ; case 2 : ssSetSolverNeedsReset ( rtS
) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction
) { if ( ssGetTaskTime ( rtS , 0 ) != ssGetTStart ( rtS ) ) {
ssSetSolverNeedsReset ( rtS ) ; } } i2bs5a3qqm = ( ( igihmdkbau - lk5yn01b43
) - opvldjancg ) + localP -> Constant_Value ; if ( ssIsMajorTimeStep ( rtS )
) { if ( localDW -> m4c02ikbg1 != 0 ) { ssSetSolverNeedsReset ( rtS ) ;
localDW -> m4c02ikbg1 = 0 ; } localB -> fwdepyepsg = muDoubleScalarSqrt (
i2bs5a3qqm ) ; } else { if ( i2bs5a3qqm < 0.0 ) { localB -> fwdepyepsg = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( i2bs5a3qqm ) ) ; } else { localB ->
fwdepyepsg = muDoubleScalarSqrt ( i2bs5a3qqm ) ; } localDW -> m4c02ikbg1 = 1
; } * mtatrlkgji = localP -> Gain_Gain * localB -> fwdepyepsg ; if (
ssIsMajorTimeStep ( rtS ) ) { localDW -> kuwvje3v02 = ( localB -> fwdepyepsg
!= 0.0 ) ; } if ( localDW -> kuwvje3v02 ) { i2bs5a3qqm = localP ->
Constant1_Value ; } else { i2bs5a3qqm = localP -> Constant2_Value [ 0 ] ; }
if ( localDW -> kuwvje3v02 ) { tmp = localB -> fwdepyepsg ; } else { tmp =
localP -> Constant2_Value [ 1 ] ; } i2bs5a3qqm /= tmp ; * idw2bnt5im = (
jautdjk1eb + hgmdlfu242 ) * i2bs5a3qqm * localP -> Gain1_Gain ; * aweaz3zeyc
= ( psnq5apkya + a1t4mjaq2j ) * i2bs5a3qqm * localP -> Gain3_Gain ; *
d5l114dofg = ( jwwcum0heq - g3k04yx2hq ) * i2bs5a3qqm * localP -> Gain4_Gain
; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( localDW -> occ4jhal5v ) ; }
break ; case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( rtS ,
0 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset ( rtS ) ; } } i2bs5a3qqm
= ( ( opvldjancg - lk5yn01b43 ) - igihmdkbau ) + localP ->
Constant_Value_pc3s5n5ig0 ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( localDW
-> iq1hnty4rc != 0 ) { ssSetSolverNeedsReset ( rtS ) ; localDW -> iq1hnty4rc
= 0 ; } localB -> jea3ib45lq = muDoubleScalarSqrt ( i2bs5a3qqm ) ; } else {
if ( i2bs5a3qqm < 0.0 ) { localB -> jea3ib45lq = - muDoubleScalarSqrt (
muDoubleScalarAbs ( i2bs5a3qqm ) ) ; } else { localB -> jea3ib45lq =
muDoubleScalarSqrt ( i2bs5a3qqm ) ; } localDW -> iq1hnty4rc = 1 ; } *
aweaz3zeyc = localP -> Gain_Gain_g0crcybw52 * localB -> jea3ib45lq ; if (
ssIsMajorTimeStep ( rtS ) ) { localDW -> krlfahjhyu = ( localB -> jea3ib45lq
!= 0.0 ) ; } if ( localDW -> krlfahjhyu ) { i2bs5a3qqm = localP ->
Constant1_Value_pvid3jlafh ; } else { i2bs5a3qqm = localP ->
Constant2_Value_bgmtgxyswg [ 0 ] ; } if ( localDW -> krlfahjhyu ) { tmp =
localB -> jea3ib45lq ; } else { tmp = localP -> Constant2_Value_bgmtgxyswg [
1 ] ; } i2bs5a3qqm /= tmp ; * idw2bnt5im = ( jwwcum0heq + g3k04yx2hq ) *
i2bs5a3qqm * localP -> Gain1_Gain_cmjmtszzlh ; * mtatrlkgji = ( psnq5apkya +
a1t4mjaq2j ) * i2bs5a3qqm * localP -> Gain2_Gain ; * d5l114dofg = (
hgmdlfu242 - jautdjk1eb ) * i2bs5a3qqm * localP -> Gain3_Gain_fjdyxqygiq ; if
( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( localDW -> k5kqzwhgid ) ; }
break ; case 2 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( rtS ,
0 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset ( rtS ) ; } } i2bs5a3qqm
= ( ( lk5yn01b43 - igihmdkbau ) - opvldjancg ) + localP ->
Constant_Value_elm2slanqm ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( localDW
-> hrkt2hcocj != 0 ) { ssSetSolverNeedsReset ( rtS ) ; localDW -> hrkt2hcocj
= 0 ; } localB -> p2vvijwdyj = muDoubleScalarSqrt ( i2bs5a3qqm ) ; } else {
if ( i2bs5a3qqm < 0.0 ) { localB -> p2vvijwdyj = - muDoubleScalarSqrt (
muDoubleScalarAbs ( i2bs5a3qqm ) ) ; } else { localB -> p2vvijwdyj =
muDoubleScalarSqrt ( i2bs5a3qqm ) ; } localDW -> hrkt2hcocj = 1 ; } *
idw2bnt5im = localP -> Gain_Gain_ocfwspzgot * localB -> p2vvijwdyj ; if (
ssIsMajorTimeStep ( rtS ) ) { localDW -> a0o3qpslv4 = ( localB -> p2vvijwdyj
!= 0.0 ) ; } if ( localDW -> a0o3qpslv4 ) { i2bs5a3qqm = localP ->
Constant1_Value_cf4j34iv2x ; } else { i2bs5a3qqm = localP ->
Constant2_Value_pt2pqq3qma [ 0 ] ; } if ( localDW -> a0o3qpslv4 ) { tmp =
localB -> p2vvijwdyj ; } else { tmp = localP -> Constant2_Value_pt2pqq3qma [
1 ] ; } i2bs5a3qqm /= tmp ; * mtatrlkgji = ( jautdjk1eb + hgmdlfu242 ) *
i2bs5a3qqm * localP -> Gain1_Gain_dvdkv5tz32 ; * aweaz3zeyc = ( jwwcum0heq +
g3k04yx2hq ) * i2bs5a3qqm * localP -> Gain2_Gain_atvqpareya ; * d5l114dofg =
( a1t4mjaq2j - psnq5apkya ) * i2bs5a3qqm * localP -> Gain3_Gain_clfc33gypf ;
if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( localDW -> gvkoaih0tt ) ; }
break ; } } real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T lo
; uint32_T hi ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if
( lo < hi ) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; }
return ( real_T ) * u * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T y ; real_T sr ; real_T
si ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void MWDSPCG_Pseudoinverse_D ( const real_T pS [ ] ,
const real_T pU [ ] , const real_T pV [ ] , real_T pX [ ] , const int32_T M ,
const int32_T N ) { int32_T ppSIdx ; real_T tol ; real_T cabsS ; int32_T P_p
; int32_T rank ; int32_T ppXIdx ; int32_T ppUIdx ; int32_T ppVIdx ; int32_T j
; int32_T k ; rank = 0 ; P_p = muIntScalarMin_sint32 ( M , N ) ; cabsS =
muDoubleScalarAbs ( pS [ 0 ] ) ; if ( 0.0 < cabsS ) { rank = 1 ; tol = (
real_T ) muIntScalarMax_sint32 ( M , N ) * pS [ 0U ] * 2.2204460492503131E-16
; ppSIdx = P_p ; while ( P_p > 0 ) { cabsS = muDoubleScalarAbs ( pS [ ppSIdx
- 1 ] ) ; ppSIdx -- ; if ( cabsS >= tol ) { rank = P_p ; P_p = 0 ; } P_p -- ;
} } ppXIdx = 0 ; for ( P_p = 0 ; P_p < N * M ; P_p ++ ) { pX [ ppXIdx ] = 0.0
; ppXIdx ++ ; } if ( rank != 0 ) { ppXIdx = 0 ; for ( j = 0 ; j < M ; j ++ )
{ for ( P_p = 0 ; P_p < N ; P_p ++ ) { ppVIdx = P_p ; ppUIdx = j ; ppSIdx = 0
; for ( k = 0 ; k < rank ; k ++ ) { cabsS = pV [ ppVIdx ] * pU [ ppUIdx ] /
pS [ ppSIdx ] ; pX [ ppXIdx ] += cabsS ; ppSIdx ++ ; ppVIdx += N ; ppUIdx +=
M ; } ppXIdx ++ ; } } } } void LUf_int32_Treal_T ( real_T outU [ ] , real_T
outP [ ] , const int32_T N ) { int32_T k ; int32_T c ; int32_T r ; int32_T
idx ; real_T tmp ; int32_T p ; real_T mTmp ; boolean_T isDiagZero ; real_T
mAccum ; for ( k = 0 ; k < N ; k ++ ) { outP [ k ] = ( real_T ) k + 1.0 ; }
for ( k = 0 ; k < N ; k ++ ) { p = k ; idx = k * N ; mTmp = outU [ idx + k ]
; if ( mTmp < 0.0 ) { mTmp = - mTmp ; } for ( r = k + 1 ; r < N ; r ++ ) {
tmp = outU [ idx + r ] ; if ( tmp < 0.0 ) { tmp = - tmp ; } if ( tmp > mTmp )
{ p = r ; mTmp = tmp ; } } if ( p != k ) { for ( c = 0 ; c < N ; c ++ ) { idx
= c * N ; mTmp = outU [ idx + p ] ; tmp = outU [ idx + k ] ; outU [ idx + p ]
= tmp ; outU [ idx + k ] = mTmp ; } tmp = outP [ p ] ; outP [ p ] = outP [ k
] ; outP [ k ] = tmp ; } idx = k * N + k ; isDiagZero = FALSE ; if ( outU [
idx ] == 0.0 ) { isDiagZero = TRUE ; } if ( ! isDiagZero ) { p = k * N ; for
( r = k + 1 ; r < N ; r ++ ) { mTmp = outU [ p + r ] ; tmp = outU [ idx ] ;
outU [ p + r ] = mTmp / tmp ; } for ( c = k + 1 ; c < N ; c ++ ) { idx = c *
N ; for ( r = k + 1 ; r < N ; r ++ ) { mAccum = outU [ idx + r ] ; mTmp =
outU [ p + r ] ; tmp = outU [ idx + k ] * mTmp ; mAccum -= tmp ; outU [ idx +
r ] = mAccum ; } } } } } void rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( const
real_T u0 [ 9 ] , const real_T u1 [ 3 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ;
int32_T r ; int32_T r_p ; int32_T r_e ; real_T maxval ; real_T a ; int32_T
rtemp ; memcpy ( & A [ 0 ] , & u0 [ 0 ] , 9U * sizeof ( real_T ) ) ; r = 0 ;
r_p = 1 ; r_e = 2 ; maxval = muDoubleScalarAbs ( u0 [ 0 ] ) ; a =
muDoubleScalarAbs ( u0 [ 1 ] ) ; if ( a > maxval ) { maxval = a ; r = 1 ; r_p
= 0 ; } if ( muDoubleScalarAbs ( u0 [ 2 ] ) > maxval ) { r = 2 ; r_p = 1 ;
r_e = 0 ; } A [ r_p ] = u0 [ r_p ] / u0 [ r ] ; A [ r_e ] /= A [ r ] ; A [ 3
+ r_p ] -= A [ 3 + r ] * A [ r_p ] ; A [ 3 + r_e ] -= A [ 3 + r ] * A [ r_e ]
; A [ 6 + r_p ] -= A [ 6 + r ] * A [ r_p ] ; A [ 6 + r_e ] -= A [ 6 + r ] * A
[ r_e ] ; if ( muDoubleScalarAbs ( A [ 3 + r_e ] ) > muDoubleScalarAbs ( A [
3 + r_p ] ) ) { rtemp = r_p + 1 ; r_p = r_e ; r_e = rtemp - 1 ; } A [ 3 + r_e
] /= A [ 3 + r_p ] ; A [ 6 + r_e ] -= A [ 3 + r_e ] * A [ 6 + r_p ] ; maxval
= u1 [ r_p ] - u1 [ r ] * A [ r_p ] ; a = ( ( u1 [ r_e ] - u1 [ r ] * A [ r_e
] ) - A [ 3 + r_e ] * maxval ) / A [ 6 + r_e ] ; maxval -= A [ 6 + r_p ] * a
; maxval /= A [ 3 + r_p ] ; y [ 0 ] = ( ( u1 [ r ] - A [ 6 + r ] * a ) - A [
3 + r ] * maxval ) / A [ r ] ; y [ 1 ] = maxval ; y [ 2 ] = a ; } void
MdlInitialize ( void ) { int32_T i ; if ( ssIsFirstInitCond ( rtS ) ) { rtB .
hqqy53kfyu [ 0 ] = rtP . Merge_InitialOutput [ 0 ] ; rtB . hqqy53kfyu [ 1 ] =
rtP . Merge_InitialOutput [ 1 ] ; rtB . hqqy53kfyu [ 2 ] = rtP .
Merge_InitialOutput [ 2 ] ; rtB . hqqy53kfyu [ 3 ] = rtP .
Merge_InitialOutput [ 3 ] ; } if ( ssIsFirstInitCond ( rtS ) ) { rtX .
b1lr14rcuj [ 0 ] = 0.0 ; rtX . b1lr14rcuj [ 1 ] = 0.0 ; rtX . b1lr14rcuj [ 2
] = 0.0 ; rtX . b1lr14rcuj [ 3 ] = 0.0 ; } rtDW . evzrtqyrte . IcNeedsLoading
= 1 ; if ( ssIsFirstInitCond ( rtS ) ) { rtX . ba1rjb3ky4 [ 0 ] = 0.0 ; rtX .
ba1rjb3ky4 [ 1 ] = - 0.0001 ; rtX . ba1rjb3ky4 [ 2 ] = 0.0 ; } rtDW .
l3ydkkphoy . IcNeedsLoading = 1 ; rtX . hod35jdtrz [ 0 ] = rtP .
Integrator_IC ; rtX . hod35jdtrz [ 1 ] = rtP . Integrator_IC ; rtX .
hod35jdtrz [ 2 ] = rtP . Integrator_IC ; rtDW . h1cj2y3ic5 [ 0 ] = rtB .
jx00cruu0k [ 0 ] ; rtDW . h1cj2y3ic5 [ 1 ] = rtB . jx00cruu0k [ 1 ] ; rtDW .
h1cj2y3ic5 [ 2 ] = rtB . jx00cruu0k [ 2 ] ; rtX . hc2wlzjerw [ 0 ] = rtP .
IntegratorLimited_IC ; rtX . hc2wlzjerw [ 1 ] = rtP . IntegratorLimited_IC ;
rtX . hc2wlzjerw [ 2 ] = rtP . IntegratorLimited_IC ; rtX . abpf02yfny [ 0 ]
= rtP . IntegratorLimited_IC_fejwzsem04 [ 0 ] ; rtX . abpf02yfny [ 1 ] = rtP
. IntegratorLimited_IC_fejwzsem04 [ 1 ] ; rtX . abpf02yfny [ 2 ] = rtP .
IntegratorLimited_IC_fejwzsem04 [ 2 ] ; rtDW . cht01inrsx = 1U ; for ( i = 0
; i < 9 ; i ++ ) { rtDW . g5fe22mv15 [ i ] = rtP . DiscreteTimeIntegrator1_IC
; } rtDW . i5firivfli [ 0 ] = rtP . DiscreteTimeIntegrator2_IC ; rtDW .
i5firivfli [ 1 ] = rtP . DiscreteTimeIntegrator2_IC ; rtDW . i5firivfli [ 2 ]
= rtP . DiscreteTimeIntegrator2_IC ; if ( ssIsFirstInitCond ( rtS ) ) { rtB .
l2aegg0det [ 0 ] = rtP . Merge_InitialOutput_poz11gcqai [ 0 ] ; rtB .
l2aegg0det [ 1 ] = rtP . Merge_InitialOutput_poz11gcqai [ 1 ] ; rtB .
l2aegg0det [ 2 ] = rtP . Merge_InitialOutput_poz11gcqai [ 2 ] ; rtB .
l2aegg0det [ 3 ] = rtP . Merge_InitialOutput_poz11gcqai [ 3 ] ; } if (
ssIsFirstInitCond ( rtS ) ) { rtX . gffjebdga3 [ 0 ] = - 0.28363024691244415
; rtX . gffjebdga3 [ 1 ] = - 0.053720952345011438 ; rtX . gffjebdga3 [ 2 ] =
0.65359343075197518 ; rtX . gffjebdga3 [ 3 ] = - 0.699631023892876 ; } rtDW .
phnnzeax4q . IcNeedsLoading = 1 ; rtX . ipddjaa3ie [ 0 ] = rtP .
IntegratorLimited_IC_k0pmcuud0v ; rtX . ipddjaa3ie [ 1 ] = rtP .
IntegratorLimited_IC_k0pmcuud0v ; rtX . ipddjaa3ie [ 2 ] = rtP .
IntegratorLimited_IC_k0pmcuud0v ; rtX . bhzxtdpm0j [ 0 ] = rtP .
IntegratorLimited_IC_fuyeuczoy3 [ 0 ] ; rtX . bhzxtdpm0j [ 1 ] = rtP .
IntegratorLimited_IC_fuyeuczoy3 [ 1 ] ; rtX . bhzxtdpm0j [ 2 ] = rtP .
IntegratorLimited_IC_fuyeuczoy3 [ 2 ] ; if ( ssIsFirstInitCond ( rtS ) ) {
rtB . elhnkqcp4v [ 0 ] = rtP . Merge_InitialOutput_iavc5wanks [ 0 ] ; rtB .
elhnkqcp4v [ 1 ] = rtP . Merge_InitialOutput_iavc5wanks [ 1 ] ; rtB .
elhnkqcp4v [ 2 ] = rtP . Merge_InitialOutput_iavc5wanks [ 2 ] ; rtB .
elhnkqcp4v [ 3 ] = rtP . Merge_InitialOutput_iavc5wanks [ 3 ] ; } if (
ssIsFirstInitCond ( rtS ) ) { rtX . hiwmnibigx [ 0 ] = 0.0 ; rtX . hiwmnibigx
[ 1 ] = 0.0 ; rtX . hiwmnibigx [ 2 ] = 0.0 ; rtX . hiwmnibigx [ 3 ] = 0.0 ; }
rtDW . g0vm4fxb3p . IcNeedsLoading = 1 ; rtDW . le5srsw3mq = 1U ; for ( i = 0
; i < 9 ; i ++ ) { rtDW . jbnlmtknpk [ i ] = rtP .
DiscreteTimeIntegrator1_IC_ht15kdk502 ; } rtDW . olom3dwhnc [ 0 ] = rtP .
DiscreteTimeIntegrator2_IC_liuu5c3kzq ; rtDW . olom3dwhnc [ 1 ] = rtP .
DiscreteTimeIntegrator2_IC_liuu5c3kzq ; rtDW . olom3dwhnc [ 2 ] = rtP .
DiscreteTimeIntegrator2_IC_liuu5c3kzq ; if ( ssIsFirstInitCond ( rtS ) ) {
rtB . e2ozyjspf1 [ 0 ] = rtP . Merge_InitialOutput_bepp0144uv [ 0 ] ; rtB .
e2ozyjspf1 [ 1 ] = rtP . Merge_InitialOutput_bepp0144uv [ 1 ] ; rtB .
e2ozyjspf1 [ 2 ] = rtP . Merge_InitialOutput_bepp0144uv [ 2 ] ; rtB .
e2ozyjspf1 [ 3 ] = rtP . Merge_InitialOutput_bepp0144uv [ 3 ] ; } } void
MdlEnable ( void ) { rtDW . epdi02vhe4 = 1U ; rtDW . j0qx5gs3ge = 1U ; rtDW .
hfkomryudx = 1U ; rtDW . oslrfkshxj = 1U ; } void MdlStart ( void ) {
uint32_T tseed ; int32_T r ; int32_T t ; real_T tmp ; { { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
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
kvbynbt23x = 0 ; rtDW . bpfxbpnxdk = 0 ; rtDW . frxkwgelef = 0 ; rtDW .
ftycguxnii = 0 ; rtB . n1iqi5rfxp [ 0 ] = rtP . Constant_Value_jrc3i5y0a4 [ 0
] ; rtB . n1iqi5rfxp [ 1 ] = rtP . Constant_Value_jrc3i5y0a4 [ 1 ] ; rtB .
n1iqi5rfxp [ 2 ] = rtP . Constant_Value_jrc3i5y0a4 [ 2 ] ; tmp =
muDoubleScalarFloor ( rtP . WhiteNoise_Seed ) ; if ( muDoubleScalarIsNaN (
tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp =
muDoubleScalarRem ( tmp , 4.294967296E+9 ) ; } tseed = tmp < 0.0 ? ( uint32_T
) - ( int32_T ) ( uint32_T ) - tmp : ( uint32_T ) tmp ; r = ( int32_T ) (
tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( ( ( ( tseed -
( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed < 1U ) {
tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . hvy1dfvqu0 = tseed ; rtDW . m5suqpxty3 =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . hvy1dfvqu0 ) * rtP . WhiteNoise_StdDev
+ rtP . WhiteNoise_Mean ; rtB . jx00cruu0k [ 0 ] = rtP .
Constant_Value_m3cuqn51ns [ 0 ] ; rtB . jx00cruu0k [ 1 ] = rtP .
Constant_Value_m3cuqn51ns [ 1 ] ; rtB . jx00cruu0k [ 2 ] = rtP .
Constant_Value_m3cuqn51ns [ 2 ] ; { void * signalProbe = ( NULL ) ; unsigned
int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout"
, "<ddeltaD>" , "<ddeltaD>" , "ACStesbed/Actuators/Bus Selector1" , 1 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . hzkxwtgg3y . SignalProbe = signalProbe ; } { void * signalProbe = (
NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "deltaD" , "deltaD" , "ACStesbed/Actuators/Subsystem"
, 1 , "linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] )
) ; rtDW . ethxueuerq . SignalProbe = signalProbe ; } rtDW . l33pfglk2a = 0 ;
rtDW . fy4uwny3eb = 0 ; { void * signalProbe = ( NULL ) ; unsigned int dims [
1 ] = { 4 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" , "Qob_mes"
, "Qob_mes" , "ACStesbed/CentralComputer/SatAttitude/BINS" , 1 , "linear" , 1
, 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW .
mohxnwpvy0 . SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ;
unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "deltaW_mes" , "deltaW_mes" ,
"ACStesbed/CentralComputer/SatAttitude/BINS" , 2 , "linear" , 1 , 0 , &
signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . fs3xofbgsa .
SignalProbe = signalProbe ; } memset ( & rtB . f22csweirk [ 0 ] , 0 , 9U *
sizeof ( real_T ) ) ; rtB . f22csweirk [ 0 ] = 1.0 ; rtB . f22csweirk [ 4 ] =
1.0 ; rtB . f22csweirk [ 8 ] = 1.0 ; rtDW . mf41bf444w = - 1 ; e5wfebyea4 ( &
rtDW . p0vdevk3x14 ) ; eeuk0bnkti ( & rtDW . azz3d4nxcem ) ; rtB . p0m1jnhybt
[ 0 ] = rtP . Constant1_Value_fg2gdmjirg [ 0 ] ; rtB . p0m1jnhybt [ 1 ] = rtP
. Constant1_Value_fg2gdmjirg [ 1 ] ; rtB . p0m1jnhybt [ 2 ] = rtP .
Constant1_Value_fg2gdmjirg [ 2 ] ; rtB . p0m1jnhybt [ 3 ] = rtP .
Constant1_Value_fg2gdmjirg [ 3 ] ; rtDW . huixms4qzu = 0 ; { void *
signalProbe = ( NULL ) ; unsigned int dims [ 1 ] = { 3 } ;
rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" , "<W>" , "<W>" ,
"ACStesbed/Object/Torques/Bus Selector" , 2 , "linear" , 1 , 0 , &
signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . iyqxvnatsr .
SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ; unsigned int
dims [ 1 ] = { 4 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" ,
"<Qjo>" , "<Qjo>" , "ACStesbed/Object/Torques/Bus Selector" , 4 , "linear" ,
1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW .
h4jqbncwhd . SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ;
unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Trw" , "Trw" , "ACStesbed/Object/Torques/Saturation"
, 1 , "linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] )
) ; rtDW . hu21nqqcni . SignalProbe = signalProbe ; } { void * signalProbe =
( NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Tg" , "Tg" , "ACStesbed/Object/Torques/Tgrav" , 1 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . oawgrr5lku . SignalProbe = signalProbe ; } { void * signalProbe = (
NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "" , "" , "ACStesbed/Object/Torques/Tgrav/Add" , 1 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . behvht2jjq . SignalProbe = signalProbe ; } { void * signalProbe = (
NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Tg1" , "Tg1" , "ACStesbed/Object/Torques/Tgrav/Gain2"
, 1 , "linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] )
) ; rtDW . jjiadmicyc . SignalProbe = signalProbe ; } { void * signalProbe =
( NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Tg2" , "Tg2" , "ACStesbed/Object/Torques/Tgrav/Gain3"
, 1 , "linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] )
) ; rtDW . bgsuqbvq3e . SignalProbe = signalProbe ; } { void * signalProbe =
( NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Tg3" , "Tg3" , "ACStesbed/Object/Torques/Tgrav/Gain4"
, 1 , "linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] )
) ; rtDW . m10l43wuz3 . SignalProbe = signalProbe ; } tmp =
muDoubleScalarFloor ( rtP . WhiteNoise_Seed_kw4ej5243j ) ; if (
muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; }
else { tmp = muDoubleScalarRem ( tmp , 4.294967296E+9 ) ; } tseed = tmp < 0.0
? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp : ( uint32_T ) tmp ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . k2mw3e5m15 = tseed ; rtDW . phocmexnl1 =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k2mw3e5m15 ) * rtP .
WhiteNoise_StdDev_esrovvidoo + rtP . WhiteNoise_Mean_fpnv13epd5 ; rtDW .
pfcneilmew = 0 ; { void * signalProbe = ( NULL ) ; unsigned int dims [ 1 ] =
{ 3 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" , "<ddeltaD>" ,
"<ddeltaD>" , "ACStesbed/TestBedComputer/Actuators/Bus Selector1" , 1 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . hzkxwtgg3yv . SignalProbe = signalProbe ; } { void * signalProbe = (
NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "deltaD" , "deltaD" ,
"ACStesbed/TestBedComputer/Actuators/Subsystem" , 1 , "linear" , 1 , 0 , &
signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW . ethxueuerq5 .
SignalProbe = signalProbe ; } { { FWksInfo * fromwksInfo ; if ( ( fromwksInfo
= ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) {
ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data0_i0n1gmpn4i ; fromwksInfo ->
nDataPoints = 980 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time0_ckirflsq1k ; rtDW . hqwrc0ipzd . TimePtr [ 0 ] =
fromwksInfo -> time ; rtDW . hqwrc0ipzd . DataPtr [ 0 ] = fromwksInfo -> data
; rtDW . hqwrc0ipzd . RSimInfoPtr [ 0 ] = fromwksInfo ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data1_naxvmyfyud ; fromwksInfo ->
nDataPoints = 980 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time1_fbttqagftm ; rtDW . hqwrc0ipzd . TimePtr [ 1 ] =
fromwksInfo -> time ; rtDW . hqwrc0ipzd . DataPtr [ 1 ] = fromwksInfo -> data
; rtDW . hqwrc0ipzd . RSimInfoPtr [ 1 ] = fromwksInfo ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data2_mxf1q2pwwa ; fromwksInfo ->
nDataPoints = 980 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time2_p5mrmwomhx ; rtDW . hqwrc0ipzd . TimePtr [ 2 ] =
fromwksInfo -> time ; rtDW . hqwrc0ipzd . DataPtr [ 2 ] = fromwksInfo -> data
; rtDW . hqwrc0ipzd . RSimInfoPtr [ 2 ] = fromwksInfo ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data3_atkkn5wa2c ; fromwksInfo ->
nDataPoints = 980 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time3_hofsogvoq5 ; rtDW . hqwrc0ipzd . TimePtr [ 3 ] =
fromwksInfo -> time ; rtDW . hqwrc0ipzd . DataPtr [ 3 ] = fromwksInfo -> data
; rtDW . hqwrc0ipzd . RSimInfoPtr [ 3 ] = fromwksInfo ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "InData" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 3 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace_Data4_bp4l4d2qb1 ; fromwksInfo ->
nDataPoints = 980 ; fromwksInfo -> time = ( double * ) rtP .
FromWorkspace_Time4_kus2hl432n ; rtDW . hqwrc0ipzd . TimePtr [ 4 ] =
fromwksInfo -> time ; rtDW . hqwrc0ipzd . DataPtr [ 4 ] = fromwksInfo -> data
; rtDW . hqwrc0ipzd . RSimInfoPtr [ 4 ] = fromwksInfo ; } } { int_T i1 ;
int_T * iw_PrevIndex = & rtDW . nrfurckayn . PrevIndex [ 0 ] ; void * *
pw_TimePtr = & rtDW . hqwrc0ipzd . TimePtr [ 0 ] ; for ( i1 = 0 ; i1 < 5 ; i1
++ ) { iw_PrevIndex [ i1 ] = 0 ; } } } rtDW . nrel2zbbl0 = - 1 ; e5wfebyea4 (
& rtDW . orebwtip3e ) ; eeuk0bnkti ( & rtDW . iry0wsg2k5 ) ; rtDW .
ej43nvwcyh = 0 ; rtDW . oxif3bzbeo = 0 ; { void * signalProbe = ( NULL ) ;
unsigned int dims [ 1 ] = { 4 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "Qob_mes" , "Qob_mes" ,
"ACStesbed/TestBedComputer/ModelCentralComputer/SatAttitude/BINS" , 1 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . mohxnwpvy0k . SignalProbe = signalProbe ; } { void * signalProbe = (
NULL ) ; unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "deltaW_mes" , "deltaW_mes" ,
"ACStesbed/TestBedComputer/ModelCentralComputer/SatAttitude/BINS" , 2 ,
"linear" , 1 , 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ;
rtDW . fs3xofbgsah . SignalProbe = signalProbe ; } memset ( & rtB .
mzppckyb2r [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; rtB . mzppckyb2r [ 0 ] =
1.0 ; rtB . mzppckyb2r [ 4 ] = 1.0 ; rtB . mzppckyb2r [ 8 ] = 1.0 ; rtDW .
lqwl4atrcd = - 1 ; e5wfebyea4 ( & rtDW . ammeeph1io ) ; eeuk0bnkti ( & rtDW .
jtgflhe3su ) ; { void * signalProbe = ( NULL ) ; unsigned int dims [ 1 ] = {
3 } ; rtwSignalProbeCreateInstance ( "tmp_raccel_logsout" , "<W>" , "<W>" ,
"ACStesbed/TestBedComputer/ModelObject/Torques/Bus Selector" , 2 , "zoh" , 1
, 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW .
iyqxvnatsrh . SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ;
unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "<L>" , "<L>" ,
"ACStesbed/TestBedComputer/ModelObject/Torques/Bus Selector" , 4 , "zoh" , 1
, 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW .
h4jqbncwhda . SignalProbe = signalProbe ; } { void * signalProbe = ( NULL ) ;
unsigned int dims [ 1 ] = { 3 } ; rtwSignalProbeCreateInstance (
"tmp_raccel_logsout" , "" , "" ,
"ACStesbed/TestBedComputer/ModelObject/Torques/Saturation" , 1 , "linear" , 1
, 0 , & signalProbe , "double" , 0 , 1 , & ( dims [ 0 ] ) ) ; rtDW .
hu21nqqcnih . SignalProbe = signalProbe ; } MdlInitialize ( ) ; MdlEnable ( )
; } void MdlOutputs ( int_T tid ) { BusObject nsjhwaxccv ; real_T ivszce53hq
[ 4 ] ; real_T lzn15zslbh [ 3 ] ; int32_T k ; int32_T idxB ; int32_T idxout ;
real_T lxxfjgwry0 [ 9 ] ; real_T bguqm55hxa [ 3 ] ; real_T enzyytwikn ;
real_T dwafzsky2m [ 3 ] ; real_T m2b1vgca5s [ 9 ] ; real_T nfwwjxsmuk ;
int8_T rtPrevAction ; int8_T rtAction ; real_T hu2gcgsgxf ; real_T aif0nk4dcs
; real_T emposknhj1 ; real_T mkoj55axg1 ; real_T nqj0afcuu5 [ 9 ] ; real_T
hppokvvgcu [ 9 ] ; real_T b5ijoe3553 [ 9 ] ; real_T c5vurnmczn [ 9 ] ; real_T
jyfgwidcz5 [ 9 ] ; real_T ctzdfomcpm [ 9 ] ; real_T e2tqctvrj0 [ 9 ] ; real_T
dm2gdf32t4 [ 9 ] ; real_T ldts3pfwss [ 9 ] ; real_T iq4emno1ma [ 9 ] ; real_T
bdpgngpz5w [ 9 ] ; real_T fnycyg1v5p [ 9 ] ; real_T evh2fnt51m [ 9 ] ; real_T
i3lhpgmarw [ 9 ] ; real_T i2qc4thdsu [ 9 ] ; real_T i241sj2ime [ 9 ] ; real_T
iy3cnrq0gy [ 9 ] ; real_T esdznxyznf [ 9 ] ; real_T dankg43h1a [ 9 ] ; real_T
miibb21mr5 [ 9 ] ; real_T nvadtslxwe [ 9 ] ; real_T e5iefyi14b [ 27 ] ;
real_T o1pxccaw [ 81 ] ; real_T linqmin2eg [ 9 ] ; real_T a0or232nx [ 3 ] ;
real_T cutepw41tb [ 9 ] ; real_T mvynztlmk [ 4 ] ; real_T d2tx5zonyh [ 27 ] ;
real_T mc04dsskwn [ 81 ] ; real_T agjzcrqgsk [ 9 ] ; real_T im2l3qmlta [ 3 ]
; real_T k0cv2hfydh [ 9 ] ; real_T nemx5em4o [ 4 ] ; int32_T i ; int32_T i_p
; real_T m2b1vgca5s_p [ 9 ] ; real_T kpgrz5rhip_idx ; real_T kpgrz5rhip_idx_p
; real_T kpgrz5rhip_idx_e ; real_T kpgrz5rhip_idx_i ; real_T lkkogows30_idx ;
real_T lkkogows30_idx_p ; real_T lkkogows30_idx_e ; real_T kr12ccbspc_idx ;
real_T kr12ccbspc_idx_p ; real_T kr12ccbspc_idx_e ; srClearBC ( rtDW .
kkm1wjx4mr ) ; srClearBC ( rtDW . lflksa1zm2 ) ; srClearBC ( rtDW .
mo3k54wqkm ) ; srClearBC ( rtDW . emy0hrjuzr ) ; srClearBC ( rtDW .
g325dldung ) ; srClearBC ( rtDW . p0vdevk3x14 . espotkwrxj ) ; srClearBC (
rtDW . azz3d4nxcem . occ4jhal5v ) ; srClearBC ( rtDW . azz3d4nxcem .
k5kqzwhgid ) ; srClearBC ( rtDW . azz3d4nxcem . gvkoaih0tt ) ; srClearBC (
rtDW . azz3d4nxcem . fw1wxjvjvv ) ; lxxfjgwry0 [ 0 ] = rtP .
Constant_Value_hwdenieqz1 ; { real_T * pDataValues = ( real_T * ) rtDW .
bknzq3wgub . DataPtr [ 0 ] ; real_T * pTimeValues = ( real_T * ) rtDW .
bknzq3wgub . TimePtr [ 0 ] ; int_T currTimeIndex = rtDW . fibx4ptf5m .
PrevIndex [ 0 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t >=
pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & nsjhwaxccv . j2000 [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
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
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . j2000 [ 0
] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; }
} } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
nsjhwaxccv . j2000 [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
nsjhwaxccv . j2000 [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 1 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 1 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 1 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & nsjhwaxccv . vj2000 [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
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
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . vj2000 [
0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ;
} } } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
nsjhwaxccv . vj2000 [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
nsjhwaxccv . vj2000 [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 2 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 2 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 2 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & nsjhwaxccv . Worbj [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
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
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . Worbj [ 0
] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; }
} } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
nsjhwaxccv . Worbj [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
nsjhwaxccv . Worbj [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 3 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 3 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 3 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & nsjhwaxccv . rsun [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
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
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . rsun [ 0
] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; }
} } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
nsjhwaxccv . rsun [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
nsjhwaxccv . rsun [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 , f1
, f2 ) ; pDataValues += numPoints ; } } } } } } { real_T * pDataValues = (
real_T * ) rtDW . bknzq3wgub . DataPtr [ 4 ] ; real_T * pTimeValues = (
real_T * ) rtDW . bknzq3wgub . TimePtr [ 4 ] ; int_T currTimeIndex = rtDW .
fibx4ptf5m . PrevIndex [ 4 ] ; real_T t = ssGetTaskTime ( rtS , 0 ) ; if ( t
>= pTimeValues [ 979 ] ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++
elIdx ) { ( & nsjhwaxccv . rrsuno [ 0 ] ) [ elIdx ] = pDataValues [ 979 ] ;
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
elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . rrsuno [
0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ; pDataValues += numPoints ;
} } } else { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( &
nsjhwaxccv . rrsuno [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ;
pDataValues += numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1
) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { d1
= pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; ( &
nsjhwaxccv . rrsuno [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1 , d2 ,
f1 , f2 ) ; pDataValues += numPoints ; } } } } } } lkkogows30_idx =
nsjhwaxccv . j2000 [ 0 ] ; lkkogows30_idx_p = nsjhwaxccv . j2000 [ 1 ] ;
lkkogows30_idx_e = nsjhwaxccv . j2000 [ 2 ] ; kr12ccbspc_idx = nsjhwaxccv .
rsun [ 0 ] ; kr12ccbspc_idx_p = nsjhwaxccv . rsun [ 1 ] ; kr12ccbspc_idx_e =
nsjhwaxccv . rsun [ 2 ] ; rtB . njvqg5q4aw [ 0 ] = nsjhwaxccv . j2000 [ 0 ] +
rtP . Noise_Value [ 0 ] ; rtB . njvqg5q4aw [ 1 ] = nsjhwaxccv . j2000 [ 1 ] +
rtP . Noise_Value [ 1 ] ; rtB . njvqg5q4aw [ 2 ] = nsjhwaxccv . j2000 [ 2 ] +
rtP . Noise_Value [ 2 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB .
jmiuxj1x02 [ 0 ] = rtB . njvqg5q4aw [ 0 ] ; rtB . jmiuxj1x02 [ 1 ] = rtB .
njvqg5q4aw [ 1 ] ; rtB . jmiuxj1x02 [ 2 ] = rtB . njvqg5q4aw [ 2 ] ;
bguqm55hxa [ 0 ] = rtB . jmiuxj1x02 [ 0 ] * rtB . jmiuxj1x02 [ 0 ] ;
bguqm55hxa [ 1 ] = rtB . jmiuxj1x02 [ 1 ] * rtB . jmiuxj1x02 [ 1 ] ;
bguqm55hxa [ 2 ] = rtB . jmiuxj1x02 [ 2 ] * rtB . jmiuxj1x02 [ 2 ] ;
enzyytwikn = ( bguqm55hxa [ 0 ] + bguqm55hxa [ 1 ] ) + bguqm55hxa [ 2 ] ; if
( enzyytwikn < 0.0 ) { rtB . pdvhflqrm1 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( enzyytwikn ) ) ; } else { rtB . pdvhflqrm1 =
muDoubleScalarSqrt ( enzyytwikn ) ; } rtB . mtdbzc3klf [ 0 ] = rtB .
jmiuxj1x02 [ 0 ] * 0.0 ; rtB . mtdbzc3klf [ 1 ] = rtB . jmiuxj1x02 [ 1 ] *
0.0 ; rtB . mtdbzc3klf [ 2 ] = rtB . jmiuxj1x02 [ 2 ] * 0.0 ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB . pdvhflqrm1 > rtP .
Switch_Threshold ) { kpgrz5rhip_idx = rtB . jmiuxj1x02 [ 0 ] ;
kpgrz5rhip_idx_e = rtB . jmiuxj1x02 [ 1 ] ; kpgrz5rhip_idx_i = rtB .
jmiuxj1x02 [ 2 ] ; } else { kpgrz5rhip_idx = rtB . mtdbzc3klf [ 0 ] ;
kpgrz5rhip_idx_e = rtB . mtdbzc3klf [ 1 ] ; kpgrz5rhip_idx_i = rtB .
mtdbzc3klf [ 2 ] ; } if ( rtB . pdvhflqrm1 > rtP . Switch_Threshold ) {
kpgrz5rhip_idx_p = rtB . pdvhflqrm1 ; } else { kpgrz5rhip_idx_p = rtP .
Constant_Value_bxenkd0bbl ; } rtB . oducdqkgjs [ 0 ] = kpgrz5rhip_idx /
kpgrz5rhip_idx_p ; rtB . oducdqkgjs [ 1 ] = kpgrz5rhip_idx_e /
kpgrz5rhip_idx_p ; rtB . oducdqkgjs [ 2 ] = kpgrz5rhip_idx_i /
kpgrz5rhip_idx_p ; } rtB . e2xzeznz0p [ 0 ] = nsjhwaxccv . vj2000 [ 0 ] + rtP
. Noise1_Value [ 0 ] ; rtB . e2xzeznz0p [ 1 ] = nsjhwaxccv . vj2000 [ 1 ] +
rtP . Noise1_Value [ 1 ] ; rtB . e2xzeznz0p [ 2 ] = nsjhwaxccv . vj2000 [ 2 ]
+ rtP . Noise1_Value [ 2 ] ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB .
fnbs1jnt55 [ 0 ] = rtB . e2xzeznz0p [ 1 ] * rtB . jmiuxj1x02 [ 2 ] - rtB .
e2xzeznz0p [ 2 ] * rtB . jmiuxj1x02 [ 1 ] ; rtB . fnbs1jnt55 [ 1 ] = rtB .
e2xzeznz0p [ 2 ] * rtB . jmiuxj1x02 [ 0 ] - rtB . e2xzeznz0p [ 0 ] * rtB .
jmiuxj1x02 [ 2 ] ; rtB . fnbs1jnt55 [ 2 ] = rtB . e2xzeznz0p [ 0 ] * rtB .
jmiuxj1x02 [ 1 ] - rtB . e2xzeznz0p [ 1 ] * rtB . jmiuxj1x02 [ 0 ] ;
enzyytwikn = ( rtB . fnbs1jnt55 [ 0 ] * rtB . fnbs1jnt55 [ 0 ] + rtB .
fnbs1jnt55 [ 1 ] * rtB . fnbs1jnt55 [ 1 ] ) + rtB . fnbs1jnt55 [ 2 ] * rtB .
fnbs1jnt55 [ 2 ] ; if ( enzyytwikn < 0.0 ) { rtB . pnzjj5cy3t = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( enzyytwikn ) ) ; } else { rtB .
pnzjj5cy3t = muDoubleScalarSqrt ( enzyytwikn ) ; } rtB . o3hbrpucbz [ 0 ] =
rtB . fnbs1jnt55 [ 0 ] * 0.0 ; rtB . o3hbrpucbz [ 1 ] = rtB . fnbs1jnt55 [ 1
] * 0.0 ; rtB . o3hbrpucbz [ 2 ] = rtB . fnbs1jnt55 [ 2 ] * 0.0 ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB . pnzjj5cy3t > rtP .
Switch_Threshold_gdocqrc4t2 ) { kpgrz5rhip_idx = rtB . fnbs1jnt55 [ 0 ] ;
kpgrz5rhip_idx_e = rtB . fnbs1jnt55 [ 1 ] ; kpgrz5rhip_idx_i = rtB .
fnbs1jnt55 [ 2 ] ; } else { kpgrz5rhip_idx = rtB . o3hbrpucbz [ 0 ] ;
kpgrz5rhip_idx_e = rtB . o3hbrpucbz [ 1 ] ; kpgrz5rhip_idx_i = rtB .
o3hbrpucbz [ 2 ] ; } if ( rtB . pnzjj5cy3t > rtP .
Switch_Threshold_gdocqrc4t2 ) { kpgrz5rhip_idx_p = rtB . pnzjj5cy3t ; } else
{ kpgrz5rhip_idx_p = rtP . Constant_Value_h3j41jz2o2 ; } rtB . dwojgwe1xs [ 0
] = kpgrz5rhip_idx / kpgrz5rhip_idx_p ; rtB . dwojgwe1xs [ 1 ] =
kpgrz5rhip_idx_e / kpgrz5rhip_idx_p ; rtB . dwojgwe1xs [ 2 ] =
kpgrz5rhip_idx_i / kpgrz5rhip_idx_p ; rtB . afwtugkazt [ 0 ] = rtB .
oducdqkgjs [ 1 ] * rtB . dwojgwe1xs [ 2 ] - rtB . oducdqkgjs [ 2 ] * rtB .
dwojgwe1xs [ 1 ] ; rtB . afwtugkazt [ 1 ] = rtB . oducdqkgjs [ 2 ] * rtB .
dwojgwe1xs [ 0 ] - rtB . oducdqkgjs [ 0 ] * rtB . dwojgwe1xs [ 2 ] ; rtB .
afwtugkazt [ 2 ] = rtB . oducdqkgjs [ 0 ] * rtB . dwojgwe1xs [ 1 ] - rtB .
oducdqkgjs [ 1 ] * rtB . dwojgwe1xs [ 0 ] ; m2b1vgca5s [ 0 ] = rtB .
afwtugkazt [ 0 ] ; m2b1vgca5s [ 1 ] = rtB . afwtugkazt [ 1 ] ; m2b1vgca5s [ 2
] = rtB . afwtugkazt [ 2 ] ; m2b1vgca5s [ 3 ] = rtB . oducdqkgjs [ 0 ] ;
m2b1vgca5s [ 4 ] = rtB . oducdqkgjs [ 1 ] ; m2b1vgca5s [ 5 ] = rtB .
oducdqkgjs [ 2 ] ; m2b1vgca5s [ 6 ] = rtB . dwojgwe1xs [ 0 ] ; m2b1vgca5s [ 7
] = rtB . dwojgwe1xs [ 1 ] ; m2b1vgca5s [ 8 ] = rtB . dwojgwe1xs [ 2 ] ; for
( i_p = 0 ; i_p < 3 ; i_p ++ ) { nvadtslxwe [ 3 * i_p ] = m2b1vgca5s [ i_p ]
; nvadtslxwe [ 1 + 3 * i_p ] = m2b1vgca5s [ i_p + 3 ] ; nvadtslxwe [ 2 + 3 *
i_p ] = m2b1vgca5s [ i_p + 6 ] ; } bguqm55hxa [ 0 ] = nvadtslxwe [ 0 ] ;
bguqm55hxa [ 1 ] = nvadtslxwe [ 4 ] ; bguqm55hxa [ 2 ] = nvadtslxwe [ 8 ] ;
nfwwjxsmuk = ( nvadtslxwe [ 0 ] + nvadtslxwe [ 4 ] ) + nvadtslxwe [ 8 ] ;
rtPrevAction = rtDW . bwuwpskbe1 ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
nfwwjxsmuk > 0.0 ) { rtAction = 0 ; } else { rtAction = 1 ; } rtDW .
bwuwpskbe1 = rtAction ; } else { rtAction = rtDW . bwuwpskbe1 ; } if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
ssSetSolverNeedsReset ( rtS ) ; break ; case 1 : ssSetSolverNeedsReset ( rtS
) ; switch ( rtDW . jenrmeyvts ) { case 0 : ssSetSolverNeedsReset ( rtS ) ;
break ; case 1 : ssSetSolverNeedsReset ( rtS ) ; break ; case 2 :
ssSetSolverNeedsReset ( rtS ) ; break ; } rtDW . jenrmeyvts = - 1 ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset (
rtS ) ; } } nfwwjxsmuk += rtP . Constant_Value ; if ( ssIsMajorTimeStep ( rtS
) ) { if ( rtDW . pzmje2aewl != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW .
pzmje2aewl = 0 ; } nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else {
if ( nfwwjxsmuk < 0.0 ) { nfwwjxsmuk = - muDoubleScalarSqrt (
muDoubleScalarAbs ( nfwwjxsmuk ) ) ; } else { nfwwjxsmuk = muDoubleScalarSqrt
( nfwwjxsmuk ) ; } rtDW . pzmje2aewl = 1 ; } rtB . hqqy53kfyu [ 0 ] = rtP .
Gain_Gain * nfwwjxsmuk ; nfwwjxsmuk *= rtP . Gain1_Gain ; rtB . hqqy53kfyu [
1 ] = ( nvadtslxwe [ 7 ] - nvadtslxwe [ 5 ] ) / nfwwjxsmuk ; rtB . hqqy53kfyu
[ 2 ] = ( nvadtslxwe [ 2 ] - nvadtslxwe [ 6 ] ) / nfwwjxsmuk ; rtB .
hqqy53kfyu [ 3 ] = ( nvadtslxwe [ 3 ] - nvadtslxwe [ 1 ] ) / nfwwjxsmuk ; if
( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . kkm1wjx4mr ) ; } break ;
case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset ( rtS ) ; } } rtPrevAction =
rtDW . jenrmeyvts ; if ( ( nvadtslxwe [ 4 ] > nvadtslxwe [ 0 ] ) && (
nvadtslxwe [ 4 ] > nvadtslxwe [ 8 ] ) ) { rtAction = 0 ; } else if (
nvadtslxwe [ 8 ] > nvadtslxwe [ 0 ] ) { rtAction = 1 ; } else { rtAction = 2
; } rtDW . jenrmeyvts = rtAction ; if ( rtPrevAction != rtAction ) { switch (
rtPrevAction ) { case 0 : ssSetSolverNeedsReset ( rtS ) ; break ; case 1 :
ssSetSolverNeedsReset ( rtS ) ; break ; case 2 : ssSetSolverNeedsReset ( rtS
) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction
) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetSolverNeedsReset ( rtS ) ; } } nfwwjxsmuk = ( ( nvadtslxwe [ 4 ] -
nvadtslxwe [ 0 ] ) - nvadtslxwe [ 8 ] ) + rtP . Constant_Value_itf12sgtld ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . kvbynbt23x != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . kvbynbt23x = 0 ; } nfwwjxsmuk =
muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if ( nfwwjxsmuk < 0.0 ) {
nfwwjxsmuk = - muDoubleScalarSqrt ( muDoubleScalarAbs ( nfwwjxsmuk ) ) ; }
else { nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } rtDW . kvbynbt23x =
1 ; } rtB . hqqy53kfyu [ 2 ] = rtP . Gain_Gain_iz22fd4qci * nfwwjxsmuk ; if (
nfwwjxsmuk != 0.0 ) { kpgrz5rhip_idx = rtP . Constant1_Value ; } else {
kpgrz5rhip_idx = rtP . Constant2_Value [ 0 ] ; nfwwjxsmuk = rtP .
Constant2_Value [ 1 ] ; } nfwwjxsmuk = kpgrz5rhip_idx / nfwwjxsmuk ;
bguqm55hxa [ 0 ] = ( nvadtslxwe [ 1 ] + nvadtslxwe [ 3 ] ) * nfwwjxsmuk ;
bguqm55hxa [ 1 ] = ( nvadtslxwe [ 5 ] + nvadtslxwe [ 7 ] ) * nfwwjxsmuk ;
bguqm55hxa [ 2 ] = ( nvadtslxwe [ 2 ] - nvadtslxwe [ 6 ] ) * nfwwjxsmuk ; rtB
. hqqy53kfyu [ 1 ] = rtP . Gain1_Gain_grzyqbqehm * bguqm55hxa [ 0 ] ; rtB .
hqqy53kfyu [ 3 ] = rtP . Gain3_Gain * bguqm55hxa [ 1 ] ; rtB . hqqy53kfyu [ 0
] = rtP . Gain4_Gain * bguqm55hxa [ 2 ] ; srUpdateBC ( rtDW . lflksa1zm2 ) ;
break ; case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( rtS ,
1 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset ( rtS ) ; } } nfwwjxsmuk
= ( ( nvadtslxwe [ 8 ] - nvadtslxwe [ 0 ] ) - nvadtslxwe [ 4 ] ) + rtP .
Constant_Value_gaw1lrkj5p ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
bpfxbpnxdk != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . bpfxbpnxdk = 0 ; }
nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } else { if ( nfwwjxsmuk <
0.0 ) { nfwwjxsmuk = - muDoubleScalarSqrt ( muDoubleScalarAbs ( nfwwjxsmuk )
) ; } else { nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; } rtDW .
bpfxbpnxdk = 1 ; } rtB . hqqy53kfyu [ 3 ] = rtP . Gain_Gain_oxcvfncqox *
nfwwjxsmuk ; if ( nfwwjxsmuk != 0.0 ) { kpgrz5rhip_idx = rtP .
Constant1_Value_odsqffacyt ; } else { kpgrz5rhip_idx = rtP .
Constant2_Value_jxofe5s4po [ 0 ] ; nfwwjxsmuk = rtP .
Constant2_Value_jxofe5s4po [ 1 ] ; } nfwwjxsmuk = kpgrz5rhip_idx / nfwwjxsmuk
; bguqm55hxa [ 0 ] = ( nvadtslxwe [ 2 ] + nvadtslxwe [ 6 ] ) * nfwwjxsmuk ;
bguqm55hxa [ 1 ] = ( nvadtslxwe [ 5 ] + nvadtslxwe [ 7 ] ) * nfwwjxsmuk ;
bguqm55hxa [ 2 ] = ( nvadtslxwe [ 3 ] - nvadtslxwe [ 1 ] ) * nfwwjxsmuk ; rtB
. hqqy53kfyu [ 1 ] = rtP . Gain1_Gain_bmy2by4h1w * bguqm55hxa [ 0 ] ; rtB .
hqqy53kfyu [ 2 ] = rtP . Gain2_Gain * bguqm55hxa [ 1 ] ; rtB . hqqy53kfyu [ 0
] = rtP . Gain3_Gain_pjvn2rjs3s * bguqm55hxa [ 2 ] ; srUpdateBC ( rtDW .
mo3k54wqkm ) ; break ; case 2 : if ( rtAction != rtPrevAction ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) { ssSetSolverNeedsReset (
rtS ) ; } } nfwwjxsmuk = ( ( nvadtslxwe [ 0 ] - nvadtslxwe [ 4 ] ) -
nvadtslxwe [ 8 ] ) + rtP . Constant_Value_pnagrbecg0 ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtDW . frxkwgelef != 0 ) { ssSetSolverNeedsReset ( rtS ) ;
rtDW . frxkwgelef = 0 ; } nfwwjxsmuk = muDoubleScalarSqrt ( nfwwjxsmuk ) ; }
else { if ( nfwwjxsmuk < 0.0 ) { nfwwjxsmuk = - muDoubleScalarSqrt (
muDoubleScalarAbs ( nfwwjxsmuk ) ) ; } else { nfwwjxsmuk = muDoubleScalarSqrt
( nfwwjxsmuk ) ; } rtDW . frxkwgelef = 1 ; } rtB . hqqy53kfyu [ 1 ] = rtP .
Gain_Gain_pkrlyfmnay * nfwwjxsmuk ; if ( nfwwjxsmuk != 0.0 ) { kpgrz5rhip_idx
= rtP . Constant1_Value_joyqlwe5wz ; } else { kpgrz5rhip_idx = rtP .
Constant2_Value_jw5vkxzlyu [ 0 ] ; nfwwjxsmuk = rtP .
Constant2_Value_jw5vkxzlyu [ 1 ] ; } nfwwjxsmuk = kpgrz5rhip_idx / nfwwjxsmuk
; bguqm55hxa [ 0 ] = ( nvadtslxwe [ 1 ] + nvadtslxwe [ 3 ] ) * nfwwjxsmuk ;
bguqm55hxa [ 1 ] = ( nvadtslxwe [ 2 ] + nvadtslxwe [ 6 ] ) * nfwwjxsmuk ;
bguqm55hxa [ 2 ] = ( nvadtslxwe [ 7 ] - nvadtslxwe [ 5 ] ) * nfwwjxsmuk ; rtB
. hqqy53kfyu [ 2 ] = rtP . Gain1_Gain_co11ew42wt * bguqm55hxa [ 0 ] ; rtB .
hqqy53kfyu [ 3 ] = rtP . Gain2_Gain_dbcigpbpah * bguqm55hxa [ 1 ] ; rtB .
hqqy53kfyu [ 0 ] = rtP . Gain3_Gain_keytyfb2hv * bguqm55hxa [ 2 ] ;
srUpdateBC ( rtDW . emy0hrjuzr ) ; break ; } if ( ssIsMajorTimeStep ( rtS ) )
{ srUpdateBC ( rtDW . g325dldung ) ; } break ; } if ( rtB . hqqy53kfyu [ 0 ]
>= rtP . Switch_Threshold_cstc3foesz ) { hu2gcgsgxf = rtP .
Constant_Value_eabu3cwr2x ; } else { hu2gcgsgxf = rtP .
Constant1_Value_gxe1evpehu ; } kpgrz5rhip_idx = hu2gcgsgxf * rtB . hqqy53kfyu
[ 0 ] ; kpgrz5rhip_idx_e = hu2gcgsgxf * rtB . hqqy53kfyu [ 1 ] ;
kpgrz5rhip_idx_i = hu2gcgsgxf * rtB . hqqy53kfyu [ 2 ] ; kpgrz5rhip_idx_p =
hu2gcgsgxf * rtB . hqqy53kfyu [ 3 ] ; hu2gcgsgxf = ( ( kpgrz5rhip_idx *
kpgrz5rhip_idx + kpgrz5rhip_idx_e * kpgrz5rhip_idx_e ) + kpgrz5rhip_idx_i *
kpgrz5rhip_idx_i ) + kpgrz5rhip_idx_p * kpgrz5rhip_idx_p ; rtB . awz2s5os2f =
kpgrz5rhip_idx / hu2gcgsgxf ; nfwwjxsmuk = ( ( rtP . Qjo_init_Value [ 0 ] *
rtP . Qob_init_Value [ 0 ] - rtP . Qjo_init_Value [ 1 ] * rtP .
Qob_init_Value [ 1 ] ) - rtP . Qjo_init_Value [ 2 ] * rtP . Qob_init_Value [
2 ] ) - rtP . Qjo_init_Value [ 3 ] * rtP . Qob_init_Value [ 3 ] ; if (
nfwwjxsmuk >= rtP . Switch_Threshold_cnjrei0kod ) { enzyytwikn = rtP .
Constant_Value_lkzxmgm0bn ; } else { enzyytwikn = rtP .
Constant1_Value_chkyuiwcbu ; } rtB . ber5tetftf [ 0 ] = enzyytwikn *
nfwwjxsmuk ; rtB . ber5tetftf [ 1 ] = ( ( ( rtP . Qjo_init_Value [ 0 ] * rtP
. Qob_init_Value [ 1 ] + rtP . Qjo_init_Value [ 1 ] * rtP . Qob_init_Value [
0 ] ) + rtP . Qjo_init_Value [ 2 ] * rtP . Qob_init_Value [ 3 ] ) - rtP .
Qjo_init_Value [ 3 ] * rtP . Qob_init_Value [ 2 ] ) * enzyytwikn ; rtB .
ber5tetftf [ 2 ] = ( ( ( rtP . Qjo_init_Value [ 0 ] * rtP . Qob_init_Value [
2 ] - rtP . Qjo_init_Value [ 1 ] * rtP . Qob_init_Value [ 3 ] ) + rtP .
Qjo_init_Value [ 2 ] * rtP . Qob_init_Value [ 0 ] ) + rtP . Qjo_init_Value [
3 ] * rtP . Qob_init_Value [ 1 ] ) * enzyytwikn ; rtB . ber5tetftf [ 3 ] = (
( ( rtP . Qjo_init_Value [ 0 ] * rtP . Qob_init_Value [ 3 ] + rtP .
Qjo_init_Value [ 1 ] * rtP . Qob_init_Value [ 2 ] ) - rtP . Qjo_init_Value [
2 ] * rtP . Qob_init_Value [ 1 ] ) + rtP . Qjo_init_Value [ 3 ] * rtP .
Qob_init_Value [ 0 ] ) * enzyytwikn ; } if ( rtDW . evzrtqyrte .
IcNeedsLoading ) { rtX . b1lr14rcuj [ 0 ] = rtB . ber5tetftf [ 0 ] ; rtX .
b1lr14rcuj [ 1 ] = rtB . ber5tetftf [ 1 ] ; rtX . b1lr14rcuj [ 2 ] = rtB .
ber5tetftf [ 2 ] ; rtX . b1lr14rcuj [ 3 ] = rtB . ber5tetftf [ 3 ] ; } rtB .
cjc4bi0q0l [ 0 ] = rtX . b1lr14rcuj [ 0 ] ; rtB . cjc4bi0q0l [ 1 ] = rtX .
b1lr14rcuj [ 1 ] ; rtB . cjc4bi0q0l [ 2 ] = rtX . b1lr14rcuj [ 2 ] ; rtB .
cjc4bi0q0l [ 3 ] = rtX . b1lr14rcuj [ 3 ] ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { rtB . j55ahl4b2c = - kpgrz5rhip_idx_e / hu2gcgsgxf ; rtB . mbcfnz4gfg =
- kpgrz5rhip_idx_i / hu2gcgsgxf ; rtB . j4celd1eit = - kpgrz5rhip_idx_p /
hu2gcgsgxf ; } rtB . bwyuqwyvcb = ( ( rtB . awz2s5os2f * rtB . cjc4bi0q0l [ 0
] - rtB . j55ahl4b2c * rtB . cjc4bi0q0l [ 1 ] ) - rtB . mbcfnz4gfg * rtB .
cjc4bi0q0l [ 2 ] ) - rtB . j4celd1eit * rtB . cjc4bi0q0l [ 3 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . bn411rqyba = ( rtB . bwyuqwyvcb >= rtP .
Switch_Threshold_l3zqxo5bwe ) ; } if ( rtDW . bn411rqyba ) { nfwwjxsmuk = rtP
. Constant_Value_ok5wcdghto ; } else { nfwwjxsmuk = rtP .
Constant1_Value_nmcgqsupce ; } rtB . fz0figaoto [ 0 ] = nfwwjxsmuk * rtB .
bwyuqwyvcb ; rtB . fz0figaoto [ 1 ] = ( ( ( rtB . awz2s5os2f * rtB .
cjc4bi0q0l [ 1 ] + rtB . j55ahl4b2c * rtB . cjc4bi0q0l [ 0 ] ) + rtB .
mbcfnz4gfg * rtB . cjc4bi0q0l [ 3 ] ) - rtB . j4celd1eit * rtB . cjc4bi0q0l [
2 ] ) * nfwwjxsmuk ; rtB . fz0figaoto [ 2 ] = ( ( ( rtB . awz2s5os2f * rtB .
cjc4bi0q0l [ 2 ] - rtB . j55ahl4b2c * rtB . cjc4bi0q0l [ 3 ] ) + rtB .
mbcfnz4gfg * rtB . cjc4bi0q0l [ 0 ] ) + rtB . j4celd1eit * rtB . cjc4bi0q0l [
1 ] ) * nfwwjxsmuk ; rtB . fz0figaoto [ 3 ] = ( ( ( rtB . awz2s5os2f * rtB .
cjc4bi0q0l [ 3 ] + rtB . j55ahl4b2c * rtB . cjc4bi0q0l [ 2 ] ) - rtB .
mbcfnz4gfg * rtB . cjc4bi0q0l [ 1 ] ) + rtB . j4celd1eit * rtB . cjc4bi0q0l [
0 ] ) * nfwwjxsmuk ; enzyytwikn = ( ( rtB . fz0figaoto [ 0 ] * rtB .
fz0figaoto [ 0 ] + rtB . fz0figaoto [ 1 ] * rtB . fz0figaoto [ 1 ] ) + rtB .
fz0figaoto [ 2 ] * rtB . fz0figaoto [ 2 ] ) + rtB . fz0figaoto [ 3 ] * rtB .
fz0figaoto [ 3 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . ftycguxnii
!= 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . ftycguxnii = 0 ; } enzyytwikn
= muDoubleScalarSqrt ( enzyytwikn ) ; } else { if ( enzyytwikn < 0.0 ) {
enzyytwikn = - muDoubleScalarSqrt ( muDoubleScalarAbs ( enzyytwikn ) ) ; }
else { enzyytwikn = muDoubleScalarSqrt ( enzyytwikn ) ; } rtDW . ftycguxnii =
1 ; } hu2gcgsgxf = rtB . fz0figaoto [ 1 ] / enzyytwikn ; aif0nk4dcs = rtB .
fz0figaoto [ 3 ] / enzyytwikn ; nfwwjxsmuk = rtB . fz0figaoto [ 0 ] /
enzyytwikn ; enzyytwikn = rtB . fz0figaoto [ 2 ] / enzyytwikn ; emposknhj1 =
( ( hu2gcgsgxf * aif0nk4dcs + nfwwjxsmuk * enzyytwikn ) * rtP .
Gain_Gain_npjumclfz3 * rtP . Constant2_Value_lni0tz223k [ 0 ] + ( enzyytwikn
* aif0nk4dcs - nfwwjxsmuk * hu2gcgsgxf ) * rtP . Gain1_Gain_kvzh5djr2r * rtP
. Constant2_Value_lni0tz223k [ 1 ] ) + ( ( rtP . Constant_Value_f0cxdn1qgj -
hu2gcgsgxf * hu2gcgsgxf ) - enzyytwikn * enzyytwikn ) * rtP .
Gain2_Gain_mmkmfnjizh * rtP . Constant2_Value_lni0tz223k [ 2 ] ; lxxfjgwry0 [
1 ] = emposknhj1 ; mkoj55axg1 = ( ( ( rtP . Constant_Value_knvnx2wekq -
enzyytwikn * enzyytwikn ) - aif0nk4dcs * aif0nk4dcs ) * rtP .
Gain2_Gain_cpzoqqauxm * rtP . Constant2_Value_lni0tz223k [ 0 ] + ( hu2gcgsgxf
* enzyytwikn + nfwwjxsmuk * aif0nk4dcs ) * rtP . Gain_Gain_lryaod0efo * rtP .
Constant2_Value_lni0tz223k [ 1 ] ) + ( hu2gcgsgxf * aif0nk4dcs - nfwwjxsmuk *
enzyytwikn ) * rtP . Gain1_Gain_kdfxi3p2kc * rtP . Constant2_Value_lni0tz223k
[ 2 ] ; enzyytwikn = ( ( ( rtP . Constant_Value_m4jcoxsqs0 - hu2gcgsgxf *
hu2gcgsgxf ) - aif0nk4dcs * aif0nk4dcs ) * rtP . Gain2_Gain_nthqdz0l5g * rtP
. Constant2_Value_lni0tz223k [ 1 ] + ( hu2gcgsgxf * enzyytwikn - nfwwjxsmuk *
aif0nk4dcs ) * rtP . Gain_Gain_gb54frueuf * rtP . Constant2_Value_lni0tz223k
[ 0 ] ) + ( nfwwjxsmuk * hu2gcgsgxf + enzyytwikn * aif0nk4dcs ) * rtP .
Gain1_Gain_dl4zducw3w * rtP . Constant2_Value_lni0tz223k [ 2 ] ; dwafzsky2m [
0 ] = rtP . Gain_Gain_hiaz1ngjp4 * mkoj55axg1 ; dwafzsky2m [ 1 ] = rtP .
Gain_Gain_hiaz1ngjp4 * enzyytwikn ; dwafzsky2m [ 2 ] = rtP .
Gain_Gain_hiaz1ngjp4 * emposknhj1 ; lxxfjgwry0 [ 2 ] = dwafzsky2m [ 1 ] ;
lxxfjgwry0 [ 3 ] = dwafzsky2m [ 2 ] ; lxxfjgwry0 [ 4 ] = rtP .
Constant_Value_hwdenieqz1 ; lxxfjgwry0 [ 5 ] = mkoj55axg1 ; lxxfjgwry0 [ 6 ]
= enzyytwikn ; lxxfjgwry0 [ 7 ] = dwafzsky2m [ 0 ] ; lxxfjgwry0 [ 8 ] = rtP .
Constant_Value_hwdenieqz1 ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { m2b1vgca5s [
3 * i_p ] = lxxfjgwry0 [ i_p ] ; m2b1vgca5s [ 1 + 3 * i_p ] = lxxfjgwry0 [
i_p + 3 ] ; m2b1vgca5s [ 2 + 3 * i_p ] = lxxfjgwry0 [ i_p + 6 ] ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( & rtB . iooczl3zbj [ 0 ] , & rtP .
ChangeMe3_Value [ 0 ] , 9U * sizeof ( real_T ) ) ; } for ( i_p = 0 ; i_p < 3
; i_p ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { m2b1vgca5s_p [ i_p + 3 * i ] =
0.0 ; m2b1vgca5s_p [ i_p + 3 * i ] += rtB . iooczl3zbj [ 3 * i ] * m2b1vgca5s
[ i_p ] ; m2b1vgca5s_p [ i_p + 3 * i ] += rtB . iooczl3zbj [ 3 * i + 1 ] *
m2b1vgca5s [ i_p + 3 ] ; m2b1vgca5s_p [ i_p + 3 * i ] += rtB . iooczl3zbj [ 3
* i + 2 ] * m2b1vgca5s [ i_p + 6 ] ; } } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { nvadtslxwe [ i_p + 3 * i ] = 0.0 ; nvadtslxwe
[ i_p + 3 * i ] += m2b1vgca5s_p [ 3 * i ] * rtP . Constant1_Value_hk3avlia0e
[ i_p ] ; nvadtslxwe [ i_p + 3 * i ] += m2b1vgca5s_p [ 3 * i + 1 ] * rtP .
Constant1_Value_hk3avlia0e [ i_p + 3 ] ; nvadtslxwe [ i_p + 3 * i ] +=
m2b1vgca5s_p [ 3 * i + 2 ] * rtP . Constant1_Value_hk3avlia0e [ i_p + 6 ] ; }
} if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ; i < 9 ; i ++ ) { rtB .
ihj3tr11iv [ i ] = rtP . Constant_Value_gvhcouy2li [ i ] + rtP .
Constant_Value_egr1tn4q2z [ i ] ; } rtB . n1iqi5rfxp [ 0 ] = rtP .
Constant_Value_jrc3i5y0a4 [ 0 ] ; rtB . n1iqi5rfxp [ 1 ] = rtP .
Constant_Value_jrc3i5y0a4 [ 1 ] ; rtB . n1iqi5rfxp [ 2 ] = rtP .
Constant_Value_jrc3i5y0a4 [ 2 ] ; } if ( rtDW . l3ydkkphoy . IcNeedsLoading )
{ rtX . ba1rjb3ky4 [ 0 ] = rtB . n1iqi5rfxp [ 0 ] ; rtX . ba1rjb3ky4 [ 1 ] =
rtB . n1iqi5rfxp [ 1 ] ; rtX . ba1rjb3ky4 [ 2 ] = rtB . n1iqi5rfxp [ 2 ] ; }
rtB . lronvhy5ya [ 0 ] = rtX . ba1rjb3ky4 [ 0 ] ; rtB . lronvhy5ya [ 1 ] =
rtX . ba1rjb3ky4 [ 1 ] ; rtB . lronvhy5ya [ 2 ] = rtX . ba1rjb3ky4 [ 2 ] ;
for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { dwafzsky2m [ i_p ] = rtB . ihj3tr11iv [
i_p + 6 ] * rtB . lronvhy5ya [ 2 ] + ( rtB . ihj3tr11iv [ i_p + 3 ] * rtB .
lronvhy5ya [ 1 ] + rtB . ihj3tr11iv [ i_p ] * rtB . lronvhy5ya [ 0 ] ) ; }
lzn15zslbh [ 0 ] = rtX . hod35jdtrz [ 0 ] ; lzn15zslbh [ 1 ] = rtX .
hod35jdtrz [ 1 ] ; lzn15zslbh [ 2 ] = rtX . hod35jdtrz [ 2 ] ; if (
ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB . m0g2rkinvl [ 0 ] = rtP . Output_Gain
[ 0 ] * rtDW . m5suqpxty3 ; rtB . m0g2rkinvl [ 1 ] = rtP . Output_Gain [ 1 ]
* rtDW . m5suqpxty3 ; rtB . m0g2rkinvl [ 2 ] = rtP . Output_Gain [ 2 ] * rtDW
. m5suqpxty3 ; } rtB . o5eruvbnew [ 0 ] = ( dwafzsky2m [ 0 ] + lzn15zslbh [ 0
] ) + rtB . m0g2rkinvl [ 0 ] ; rtB . o5eruvbnew [ 1 ] = ( dwafzsky2m [ 1 ] +
lzn15zslbh [ 1 ] ) + rtB . m0g2rkinvl [ 1 ] ; rtB . o5eruvbnew [ 2 ] = (
dwafzsky2m [ 2 ] + lzn15zslbh [ 2 ] ) + rtB . m0g2rkinvl [ 2 ] ; if (
ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB . kwssbn0ne4 [ 0 ] = rtB . o5eruvbnew [
0 ] ; rtB . kwssbn0ne4 [ 1 ] = rtB . o5eruvbnew [ 1 ] ; rtB . kwssbn0ne4 [ 2
] = rtB . o5eruvbnew [ 2 ] ; } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { rtB .
jx00cruu0k [ 0 ] = rtP . Constant_Value_m3cuqn51ns [ 0 ] ; rtB . jx00cruu0k [
1 ] = rtP . Constant_Value_m3cuqn51ns [ 1 ] ; rtB . jx00cruu0k [ 2 ] = rtP .
Constant_Value_m3cuqn51ns [ 2 ] ; rtB . lcvceh3hv3 [ 0 ] = rtDW . h1cj2y3ic5
[ 0 ] ; rtB . lcvceh3hv3 [ 1 ] = rtDW . h1cj2y3ic5 [ 1 ] ; rtB . lcvceh3hv3 [
2 ] = rtDW . h1cj2y3ic5 [ 2 ] ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB
. nfbfh1ljmc [ 0 ] = rtB . kwssbn0ne4 [ 0 ] - rtB . lcvceh3hv3 [ 0 ] ; rtB .
nfbfh1ljmc [ 1 ] = rtB . kwssbn0ne4 [ 1 ] - rtB . lcvceh3hv3 [ 1 ] ; rtB .
nfbfh1ljmc [ 2 ] = rtB . kwssbn0ne4 [ 2 ] - rtB . lcvceh3hv3 [ 2 ] ; } for (
i_p = 0 ; i_p < 3 ; i_p ++ ) { lzn15zslbh [ i_p ] = 0.0 ; lzn15zslbh [ i_p ]
+= nvadtslxwe [ i_p ] * rtB . nfbfh1ljmc [ 0 ] ; lzn15zslbh [ i_p ] +=
nvadtslxwe [ i_p + 3 ] * rtB . nfbfh1ljmc [ 1 ] ; lzn15zslbh [ i_p ] +=
nvadtslxwe [ i_p + 6 ] * rtB . nfbfh1ljmc [ 2 ] ; } rtB . e14rgshsrb [ 0 ] =
rtP . Gain1_Gain_a0a5bf0urx * lzn15zslbh [ 0 ] ; rtB . e14rgshsrb [ 1 ] = rtP
. Gain1_Gain_a0a5bf0urx * lzn15zslbh [ 1 ] ; rtB . e14rgshsrb [ 2 ] = rtP .
Gain1_Gain_a0a5bf0urx * lzn15zslbh [ 2 ] ; if ( ssGetLogOutput ( rtS ) ) { {
{ void * signalProbe = ( void * ) rtDW . hzkxwtgg3y . SignalProbe ; real_T t
; void * u ; t = ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB .
e14rgshsrb [ 0 ] ; rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } }
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX . hc2wlzjerw [ 0 ] >= rtP .
IntegratorLimited_UpperSat ) { rtX . hc2wlzjerw [ 0 ] = rtP .
IntegratorLimited_UpperSat ; } else if ( rtX . hc2wlzjerw [ 0 ] <= rtP .
IntegratorLimited_LowerSat ) { rtX . hc2wlzjerw [ 0 ] = rtP .
IntegratorLimited_LowerSat ; } if ( rtX . hc2wlzjerw [ 1 ] >= rtP .
IntegratorLimited_UpperSat ) { rtX . hc2wlzjerw [ 1 ] = rtP .
IntegratorLimited_UpperSat ; } else if ( rtX . hc2wlzjerw [ 1 ] <= rtP .
IntegratorLimited_LowerSat ) { rtX . hc2wlzjerw [ 1 ] = rtP .
IntegratorLimited_LowerSat ; } if ( rtX . hc2wlzjerw [ 2 ] >= rtP .
IntegratorLimited_UpperSat ) { rtX . hc2wlzjerw [ 2 ] = rtP .
IntegratorLimited_UpperSat ; } else if ( rtX . hc2wlzjerw [ 2 ] <= rtP .
IntegratorLimited_LowerSat ) { rtX . hc2wlzjerw [ 2 ] = rtP .
IntegratorLimited_LowerSat ; } } rtB . kfrkptukdf [ 0 ] = rtX . hc2wlzjerw [
0 ] ; rtB . kfrkptukdf [ 1 ] = rtX . hc2wlzjerw [ 1 ] ; rtB . kfrkptukdf [ 2
] = rtX . hc2wlzjerw [ 2 ] ; if ( ssGetLogOutput ( rtS ) ) { { { void *
signalProbe = ( void * ) rtDW . ethxueuerq . SignalProbe ; real_T t ; void *
u ; t = ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . kfrkptukdf [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtX . abpf02yfny [ 0 ] >= rtP .
IntegratorLimited_UpperSat_ntkxmpf0qj ) { rtX . abpf02yfny [ 0 ] = rtP .
IntegratorLimited_UpperSat_ntkxmpf0qj ; } else if ( rtX . abpf02yfny [ 0 ] <=
rtP . IntegratorLimited_LowerSat_oacseuhnry ) { rtX . abpf02yfny [ 0 ] = rtP
. IntegratorLimited_LowerSat_oacseuhnry ; } if ( rtX . abpf02yfny [ 1 ] >=
rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ) { rtX . abpf02yfny [ 1 ] = rtP
. IntegratorLimited_UpperSat_ntkxmpf0qj ; } else if ( rtX . abpf02yfny [ 1 ]
<= rtP . IntegratorLimited_LowerSat_oacseuhnry ) { rtX . abpf02yfny [ 1 ] =
rtP . IntegratorLimited_LowerSat_oacseuhnry ; } if ( rtX . abpf02yfny [ 2 ]
>= rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ) { rtX . abpf02yfny [ 2 ] =
rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ; } else if ( rtX . abpf02yfny [
2 ] <= rtP . IntegratorLimited_LowerSat_oacseuhnry ) { rtX . abpf02yfny [ 2 ]
= rtP . IntegratorLimited_LowerSat_oacseuhnry ; } } rtB . kta3wrejd4 [ 0 ] =
rtX . abpf02yfny [ 0 ] ; rtB . kta3wrejd4 [ 1 ] = rtX . abpf02yfny [ 1 ] ;
rtB . kta3wrejd4 [ 2 ] = rtX . abpf02yfny [ 2 ] ; lzn15zslbh [ 0 ] = rtP .
Gain1_Gain_i0dny2tgg4 * rtB . kta3wrejd4 [ 0 ] ; lzn15zslbh [ 1 ] = rtP .
Gain1_Gain_i0dny2tgg4 * rtB . kta3wrejd4 [ 1 ] ; lzn15zslbh [ 2 ] = rtP .
Gain1_Gain_i0dny2tgg4 * rtB . kta3wrejd4 [ 2 ] ; dwafzsky2m [ 0 ] = rtB .
fz0figaoto [ 0 ] * rtB . fz0figaoto [ 1 ] ; dwafzsky2m [ 1 ] = rtB .
fz0figaoto [ 0 ] * rtB . fz0figaoto [ 2 ] ; dwafzsky2m [ 2 ] = rtB .
fz0figaoto [ 0 ] * rtB . fz0figaoto [ 3 ] ; for ( i_p = 0 ; i_p < 3 ; i_p ++
) { rtB . gcm3v00fw3 [ i_p ] = 0.0 ; rtB . gcm3v00fw3 [ i_p ] += rtB .
iooczl3zbj [ i_p ] * dwafzsky2m [ 0 ] ; rtB . gcm3v00fw3 [ i_p ] += rtB .
iooczl3zbj [ i_p + 3 ] * dwafzsky2m [ 1 ] ; rtB . gcm3v00fw3 [ i_p ] += rtB .
iooczl3zbj [ i_p + 6 ] * dwafzsky2m [ 2 ] ; } if ( ssIsSampleHit ( rtS , 3 ,
0 ) ) { rtB . bilokkqatz [ 0 ] = rtP . Kang_Gain * rtB . gcm3v00fw3 [ 0 ] ;
rtB . bilokkqatz [ 1 ] = rtP . Kang_Gain * rtB . gcm3v00fw3 [ 1 ] ; rtB .
bilokkqatz [ 2 ] = rtP . Kang_Gain * rtB . gcm3v00fw3 [ 2 ] ; } if (
ssIsSampleHit ( rtS , 4 , 0 ) ) { nfwwjxsmuk = ( muDoubleScalarPower ( rtB .
jmiuxj1x02 [ 0 ] , 2.0 ) + muDoubleScalarPower ( rtB . jmiuxj1x02 [ 1 ] , 2.0
) ) + muDoubleScalarPower ( rtB . jmiuxj1x02 [ 2 ] , 2.0 ) ; rtB . kcl5mw42rb
[ 0 ] = rtP . Gain_Gain_imjwpylc20 * rtB . fnbs1jnt55 [ 0 ] / nfwwjxsmuk ;
rtB . kcl5mw42rb [ 1 ] = rtP . Gain_Gain_imjwpylc20 * rtB . fnbs1jnt55 [ 1 ]
/ nfwwjxsmuk ; rtB . kcl5mw42rb [ 2 ] = rtP . Gain_Gain_imjwpylc20 * rtB .
fnbs1jnt55 [ 2 ] / nfwwjxsmuk ; } mkoj55axg1 = ( ( rtB . cjc4bi0q0l [ 0 ] *
rtB . cjc4bi0q0l [ 0 ] + rtB . cjc4bi0q0l [ 1 ] * rtB . cjc4bi0q0l [ 1 ] ) +
rtB . cjc4bi0q0l [ 2 ] * rtB . cjc4bi0q0l [ 2 ] ) + rtB . cjc4bi0q0l [ 3 ] *
rtB . cjc4bi0q0l [ 3 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
l33pfglk2a != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . l33pfglk2a = 0 ; }
mkoj55axg1 = muDoubleScalarSqrt ( mkoj55axg1 ) ; } else { if ( mkoj55axg1 <
0.0 ) { mkoj55axg1 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( mkoj55axg1 )
) ; } else { mkoj55axg1 = muDoubleScalarSqrt ( mkoj55axg1 ) ; } rtDW .
l33pfglk2a = 1 ; } emposknhj1 = rtB . cjc4bi0q0l [ 2 ] / mkoj55axg1 ;
enzyytwikn = rtB . cjc4bi0q0l [ 3 ] / mkoj55axg1 ; hu2gcgsgxf = rtB .
cjc4bi0q0l [ 1 ] / mkoj55axg1 ; mkoj55axg1 = rtB . cjc4bi0q0l [ 0 ] /
mkoj55axg1 ; rtB . p05flgh0s0 [ 0 ] = rtB . kwssbn0ne4 [ 0 ] - ( ( ( ( rtP .
Constant_Value_gfamwgvgio - emposknhj1 * emposknhj1 ) - enzyytwikn *
enzyytwikn ) * rtP . Gain2_Gain_hsczlo4ztj * rtB . kcl5mw42rb [ 0 ] + (
hu2gcgsgxf * emposknhj1 + mkoj55axg1 * enzyytwikn ) * rtP .
Gain_Gain_mwczkktdza * rtB . kcl5mw42rb [ 1 ] ) + ( hu2gcgsgxf * enzyytwikn -
mkoj55axg1 * emposknhj1 ) * rtP . Gain1_Gain_jcffkkjw2g * rtB . kcl5mw42rb [
2 ] ) ; rtB . p05flgh0s0 [ 1 ] = rtB . kwssbn0ne4 [ 1 ] - ( ( ( ( rtP .
Constant_Value_alyo2kghso - hu2gcgsgxf * hu2gcgsgxf ) - enzyytwikn *
enzyytwikn ) * rtP . Gain2_Gain_bnubngmvnh * rtB . kcl5mw42rb [ 1 ] + (
hu2gcgsgxf * emposknhj1 - mkoj55axg1 * enzyytwikn ) * rtP .
Gain_Gain_keh1ebxthv * rtB . kcl5mw42rb [ 0 ] ) + ( mkoj55axg1 * hu2gcgsgxf +
emposknhj1 * enzyytwikn ) * rtP . Gain1_Gain_kck2izenjg * rtB . kcl5mw42rb [
2 ] ) ; rtB . p05flgh0s0 [ 2 ] = rtB . kwssbn0ne4 [ 2 ] - ( ( ( hu2gcgsgxf *
enzyytwikn + mkoj55axg1 * emposknhj1 ) * rtP . Gain_Gain_m1esafctux * rtB .
kcl5mw42rb [ 0 ] + ( emposknhj1 * enzyytwikn - mkoj55axg1 * hu2gcgsgxf ) *
rtP . Gain1_Gain_gpeez3rcld * rtB . kcl5mw42rb [ 1 ] ) + ( ( rtP .
Constant_Value_jrgvdhmfe2 - hu2gcgsgxf * hu2gcgsgxf ) - emposknhj1 *
emposknhj1 ) * rtP . Gain2_Gain_nv4m22xdcw * rtB . kcl5mw42rb [ 2 ] ) ; for (
i_p = 0 ; i_p < 3 ; i_p ++ ) { dwafzsky2m [ i_p ] = rtB . iooczl3zbj [ i_p +
6 ] * rtB . p05flgh0s0 [ 2 ] + ( rtB . iooczl3zbj [ i_p + 3 ] * rtB .
p05flgh0s0 [ 1 ] + rtB . iooczl3zbj [ i_p ] * rtB . p05flgh0s0 [ 0 ] ) ; }
rtB . p4tfma3j1a [ 0 ] = rtP . Krate_Gain * dwafzsky2m [ 0 ] + rtB .
bilokkqatz [ 0 ] ; rtB . p4tfma3j1a [ 1 ] = rtP . Krate_Gain * dwafzsky2m [ 1
] + rtB . bilokkqatz [ 1 ] ; rtB . p4tfma3j1a [ 2 ] = rtP . Krate_Gain *
dwafzsky2m [ 2 ] + rtB . bilokkqatz [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0
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
Saturation_LowerSat ? 0 : - 1 ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB
. l4ynfqsuix [ 0 ] = rtDW . o1tdlyssu3 [ 0 ] == 1 ? rtP . Saturation_UpperSat
: rtDW . o1tdlyssu3 [ 0 ] == - 1 ? rtP . Saturation_LowerSat : rtB .
jty1zsef01 [ 0 ] ; rtB . l4ynfqsuix [ 1 ] = rtDW . o1tdlyssu3 [ 1 ] == 1 ?
rtP . Saturation_UpperSat : rtDW . o1tdlyssu3 [ 1 ] == - 1 ? rtP .
Saturation_LowerSat : rtB . jty1zsef01 [ 1 ] ; rtB . l4ynfqsuix [ 2 ] = rtDW
. o1tdlyssu3 [ 2 ] == 1 ? rtP . Saturation_UpperSat : rtDW . o1tdlyssu3 [ 2 ]
== - 1 ? rtP . Saturation_LowerSat : rtB . jty1zsef01 [ 2 ] ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { kpgrz5rhip_idx = rtP .
Gain1_Gain_dkf041qpaw * rtB . l4ynfqsuix [ 0 ] ; if ( kpgrz5rhip_idx >= rtP .
Saturation_UpperSat_faael1sbi5 ) { rtB . ajquw4hgfb [ 0 ] = rtP .
Saturation_UpperSat_faael1sbi5 ; } else if ( kpgrz5rhip_idx <= rtP .
Saturation_LowerSat_agytdqopmw ) { rtB . ajquw4hgfb [ 0 ] = rtP .
Saturation_LowerSat_agytdqopmw ; } else { rtB . ajquw4hgfb [ 0 ] =
kpgrz5rhip_idx ; } kpgrz5rhip_idx = rtP . Gain1_Gain_dkf041qpaw * rtB .
l4ynfqsuix [ 1 ] ; if ( kpgrz5rhip_idx >= rtP .
Saturation_UpperSat_faael1sbi5 ) { rtB . ajquw4hgfb [ 1 ] = rtP .
Saturation_UpperSat_faael1sbi5 ; } else if ( kpgrz5rhip_idx <= rtP .
Saturation_LowerSat_agytdqopmw ) { rtB . ajquw4hgfb [ 1 ] = rtP .
Saturation_LowerSat_agytdqopmw ; } else { rtB . ajquw4hgfb [ 1 ] =
kpgrz5rhip_idx ; } kpgrz5rhip_idx = rtP . Gain1_Gain_dkf041qpaw * rtB .
l4ynfqsuix [ 2 ] ; if ( kpgrz5rhip_idx >= rtP .
Saturation_UpperSat_faael1sbi5 ) { rtB . ajquw4hgfb [ 2 ] = rtP .
Saturation_UpperSat_faael1sbi5 ; } else if ( kpgrz5rhip_idx <= rtP .
Saturation_LowerSat_agytdqopmw ) { rtB . ajquw4hgfb [ 2 ] = rtP .
Saturation_LowerSat_agytdqopmw ; } else { rtB . ajquw4hgfb [ 2 ] =
kpgrz5rhip_idx ; } rtB . piiwfosis5 [ 0 ] = rtB . e14rgshsrb [ 0 ] ; rtB .
piiwfosis5 [ 1 ] = rtB . e14rgshsrb [ 1 ] ; rtB . piiwfosis5 [ 2 ] = rtB .
e14rgshsrb [ 2 ] ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { memset ( & rtB .
golhlydrqf [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; rtB . golhlydrqf [ 0 ] =
rtB . kwssbn0ne4 [ 0 ] ; rtB . golhlydrqf [ 4 ] = rtB . kwssbn0ne4 [ 1 ] ;
rtB . golhlydrqf [ 8 ] = rtB . kwssbn0ne4 [ 2 ] ; } if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { nqj0afcuu5 [ 0 ] = rtB . kwssbn0ne4 [ 1 ] ; nqj0afcuu5 [ 1 ] =
rtB . kwssbn0ne4 [ 0 ] ; nqj0afcuu5 [ 2 ] = rtP . Constant_Value_kejneha0ij ;
nqj0afcuu5 [ 3 ] = rtB . kwssbn0ne4 [ 2 ] ; nqj0afcuu5 [ 4 ] = rtP .
Constant_Value_kejneha0ij ; nqj0afcuu5 [ 5 ] = rtB . kwssbn0ne4 [ 0 ] ;
nqj0afcuu5 [ 6 ] = rtP . Constant_Value_kejneha0ij ; nqj0afcuu5 [ 7 ] = rtB .
kwssbn0ne4 [ 2 ] ; nqj0afcuu5 [ 8 ] = rtB . kwssbn0ne4 [ 1 ] ; memcpy ( & rtB
. golhlydrqf [ 9 ] , & nqj0afcuu5 [ 0 ] , 9U * sizeof ( real_T ) ) ;
hppokvvgcu [ 0 ] = rtP . Constant_Value_bc5jwlnuhr ; hppokvvgcu [ 1 ] = rtB .
kwssbn0ne4 [ 2 ] ; } if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB . bz3arzyxmq
[ 0 ] = rtP . Gain_Gain_n3x52x0hib * rtB . kwssbn0ne4 [ 0 ] ; rtB .
bz3arzyxmq [ 1 ] = rtP . Gain_Gain_n3x52x0hib * rtB . kwssbn0ne4 [ 1 ] ; rtB
. bz3arzyxmq [ 2 ] = rtP . Gain_Gain_n3x52x0hib * rtB . kwssbn0ne4 [ 2 ] ; }
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { hppokvvgcu [ 2 ] = rtB . bz3arzyxmq [
1 ] ; hppokvvgcu [ 3 ] = rtB . bz3arzyxmq [ 2 ] ; hppokvvgcu [ 4 ] = rtP .
Constant_Value_bc5jwlnuhr ; hppokvvgcu [ 5 ] = rtB . kwssbn0ne4 [ 0 ] ;
hppokvvgcu [ 6 ] = rtB . kwssbn0ne4 [ 1 ] ; hppokvvgcu [ 7 ] = rtB .
bz3arzyxmq [ 0 ] ; hppokvvgcu [ 8 ] = rtP . Constant_Value_bc5jwlnuhr ; for (
i_p = 0 ; i_p < 3 ; i_p ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB .
c0wivtryvw [ i_p + 3 * i ] = 0.0 ; rtB . c0wivtryvw [ i_p + 3 * i ] += rtB .
golhlydrqf [ 3 * i ] * hppokvvgcu [ i_p ] ; rtB . c0wivtryvw [ i_p + 3 * i ]
+= rtB . golhlydrqf [ 3 * i + 1 ] * hppokvvgcu [ i_p + 3 ] ; rtB . c0wivtryvw
[ i_p + 3 * i ] += rtB . golhlydrqf [ 3 * i + 2 ] * hppokvvgcu [ i_p + 6 ] ;
} } } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { if ( rtDW . cht01inrsx != 0 ) {
for ( i = 0 ; i < 18 ; i ++ ) { rtDW . loaxlm1yp2 [ i ] = 0.0 ; rtB .
bqng0z1mqz [ i ] = rtDW . loaxlm1yp2 [ i ] ; } } else { for ( i = 0 ; i < 18
; i ++ ) { rtB . bqng0z1mqz [ i ] = rtP .
DiscreteTimeIntegrator_gainval_nclh2cnkov * rtB . c0wivtryvw [ i ] + rtDW .
loaxlm1yp2 [ i ] ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ;
i < 18 ; i ++ ) { rtB . nowaxdrerk [ i ] = rtB . golhlydrqf [ i ] + rtB .
bqng0z1mqz [ i ] ; } } rtB . ajml5jquws [ 0 ] = rtP .
Constant_Value_pakwzwri3w ; mkoj55axg1 = ( ( rtB . fz0figaoto [ 0 ] * rtB .
fz0figaoto [ 0 ] + rtB . fz0figaoto [ 1 ] * rtB . fz0figaoto [ 1 ] ) + rtB .
fz0figaoto [ 2 ] * rtB . fz0figaoto [ 2 ] ) + rtB . fz0figaoto [ 3 ] * rtB .
fz0figaoto [ 3 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . fy4uwny3eb
!= 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . fy4uwny3eb = 0 ; } mkoj55axg1
= muDoubleScalarSqrt ( mkoj55axg1 ) ; } else { if ( mkoj55axg1 < 0.0 ) {
mkoj55axg1 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( mkoj55axg1 ) ) ; }
else { mkoj55axg1 = muDoubleScalarSqrt ( mkoj55axg1 ) ; } rtDW . fy4uwny3eb =
1 ; } emposknhj1 = rtB . fz0figaoto [ 1 ] / mkoj55axg1 ; enzyytwikn = rtB .
fz0figaoto [ 3 ] / mkoj55axg1 ; hu2gcgsgxf = rtB . fz0figaoto [ 0 ] /
mkoj55axg1 ; mkoj55axg1 = rtB . fz0figaoto [ 2 ] / mkoj55axg1 ; aif0nk4dcs =
( ( emposknhj1 * enzyytwikn + hu2gcgsgxf * mkoj55axg1 ) * rtP .
Gain_Gain_aylskoktgk * rtP . Constant_Value_lrvvatbdw3 [ 0 ] + ( mkoj55axg1 *
enzyytwikn - hu2gcgsgxf * emposknhj1 ) * rtP . Gain1_Gain_cphlya4qdx * rtP .
Constant_Value_lrvvatbdw3 [ 1 ] ) + ( ( rtP . Constant_Value_mx1msscuqd -
emposknhj1 * emposknhj1 ) - mkoj55axg1 * mkoj55axg1 ) * rtP .
Gain2_Gain_ohkyc5atre * rtP . Constant_Value_lrvvatbdw3 [ 2 ] ; rtB .
ajml5jquws [ 1 ] = aif0nk4dcs ; nfwwjxsmuk = ( ( ( rtP .
Constant_Value_l4fxoeulw2 - mkoj55axg1 * mkoj55axg1 ) - enzyytwikn *
enzyytwikn ) * rtP . Gain2_Gain_m0t2xxz40v * rtP . Constant_Value_lrvvatbdw3
[ 0 ] + ( emposknhj1 * mkoj55axg1 + hu2gcgsgxf * enzyytwikn ) * rtP .
Gain_Gain_frcbiltvyt * rtP . Constant_Value_lrvvatbdw3 [ 1 ] ) + ( emposknhj1
* enzyytwikn - hu2gcgsgxf * mkoj55axg1 ) * rtP . Gain1_Gain_hlgkmxw45m * rtP
. Constant_Value_lrvvatbdw3 [ 2 ] ; mkoj55axg1 = ( ( ( rtP .
Constant_Value_dvdmweasr4 - emposknhj1 * emposknhj1 ) - enzyytwikn *
enzyytwikn ) * rtP . Gain2_Gain_h305jf3sv3 * rtP . Constant_Value_lrvvatbdw3
[ 1 ] + ( emposknhj1 * mkoj55axg1 - hu2gcgsgxf * enzyytwikn ) * rtP .
Gain_Gain_jlgfxmogcv * rtP . Constant_Value_lrvvatbdw3 [ 0 ] ) + ( hu2gcgsgxf
* emposknhj1 + mkoj55axg1 * enzyytwikn ) * rtP . Gain1_Gain_hdwvivfv4n * rtP
. Constant_Value_lrvvatbdw3 [ 2 ] ; rtB . ajml5jquws [ 2 ] = rtP .
Gain_Gain_akwngypvn3 * mkoj55axg1 ; rtB . ajml5jquws [ 3 ] = rtP .
Gain_Gain_akwngypvn3 * aif0nk4dcs ; rtB . ajml5jquws [ 4 ] = rtP .
Constant_Value_pakwzwri3w ; rtB . ajml5jquws [ 5 ] = nfwwjxsmuk ; rtB .
ajml5jquws [ 6 ] = mkoj55axg1 ; rtB . ajml5jquws [ 7 ] = rtP .
Gain_Gain_akwngypvn3 * nfwwjxsmuk ; rtB . ajml5jquws [ 8 ] = rtP .
Constant_Value_pakwzwri3w ; if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { for ( i =
0 ; i < 9 ; i ++ ) { if ( rtDW . epdi02vhe4 != 0 ) { rtB . nowaxdrerk [ i +
18 ] = rtDW . g5fe22mv15 [ i ] ; } else { rtB . nowaxdrerk [ i + 18 ] = rtP .
DiscreteTimeIntegrator1_gainval * rtB . ajml5jquws [ i ] + rtDW . g5fe22mv15
[ i ] ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( & e5iefyi14b [
0 ] , & rtB . nowaxdrerk [ 0 ] , 27U * sizeof ( real_T ) ) ; i = MWDSP_SVD_D
( & e5iefyi14b [ 0U ] , 3 , 9 , & mvynztlmk [ 0U ] , & cutepw41tb [ 0U ] , &
a0or232nx [ 0U ] , & linqmin2eg [ 0U ] , & o1pxccaw [ 0U ] , 1 ) ; if ( i ==
0 ) { MWDSPCG_Pseudoinverse_D ( & mvynztlmk [ 0U ] , & linqmin2eg [ 0U ] , &
o1pxccaw [ 0U ] , & rtB . cd1svnc4xn [ 0U ] , 3 , 9 ) ; } } rtB . nye3sr1z21
[ 0 ] = rtB . kwssbn0ne4 [ 1 ] * lzn15zslbh [ 2 ] - rtB . kwssbn0ne4 [ 2 ] *
lzn15zslbh [ 1 ] ; rtB . nye3sr1z21 [ 1 ] = rtB . kwssbn0ne4 [ 2 ] *
lzn15zslbh [ 0 ] - rtB . kwssbn0ne4 [ 0 ] * lzn15zslbh [ 2 ] ; rtB .
nye3sr1z21 [ 2 ] = rtB . kwssbn0ne4 [ 0 ] * lzn15zslbh [ 1 ] - rtB .
kwssbn0ne4 [ 1 ] * lzn15zslbh [ 0 ] ; if ( ssIsSampleHit ( rtS , 5 , 0 ) ) {
if ( rtDW . j0qx5gs3ge != 0 ) { rtB . hvzm4sux2r [ 0 ] = rtDW . i5firivfli [
0 ] ; rtB . hvzm4sux2r [ 1 ] = rtDW . i5firivfli [ 1 ] ; rtB . hvzm4sux2r [ 2
] = rtDW . i5firivfli [ 2 ] ; } else { rtB . hvzm4sux2r [ 0 ] = rtP .
DiscreteTimeIntegrator2_gainval * rtB . nye3sr1z21 [ 0 ] + rtDW . i5firivfli
[ 0 ] ; rtB . hvzm4sux2r [ 1 ] = rtP . DiscreteTimeIntegrator2_gainval * rtB
. nye3sr1z21 [ 1 ] + rtDW . i5firivfli [ 1 ] ; rtB . hvzm4sux2r [ 2 ] = rtP .
DiscreteTimeIntegrator2_gainval * rtB . nye3sr1z21 [ 2 ] + rtDW . i5firivfli
[ 2 ] ; } } lzn15zslbh [ 0 ] = ( 0.0 - lzn15zslbh [ 0 ] ) - rtB . hvzm4sux2r
[ 0 ] ; lzn15zslbh [ 1 ] = ( 0.0 - lzn15zslbh [ 1 ] ) - rtB . hvzm4sux2r [ 1
] ; lzn15zslbh [ 2 ] = ( 0.0 - lzn15zslbh [ 2 ] ) - rtB . hvzm4sux2r [ 2 ] ;
for ( i_p = 0 ; i_p < 9 ; i_p ++ ) { lxxfjgwry0 [ i_p ] = rtB . cd1svnc4xn [
i_p + 18 ] * lzn15zslbh [ 2 ] + ( rtB . cd1svnc4xn [ i_p + 9 ] * lzn15zslbh [
1 ] + rtB . cd1svnc4xn [ i_p ] * lzn15zslbh [ 0 ] ) ; } b5ijoe3553 [ 0 ] =
lxxfjgwry0 [ 0 ] ; b5ijoe3553 [ 1 ] = lxxfjgwry0 [ 3 ] ; b5ijoe3553 [ 2 ] =
lxxfjgwry0 [ 4 ] ; b5ijoe3553 [ 3 ] = lxxfjgwry0 [ 3 ] ; b5ijoe3553 [ 4 ] =
lxxfjgwry0 [ 1 ] ; b5ijoe3553 [ 5 ] = lxxfjgwry0 [ 5 ] ; b5ijoe3553 [ 6 ] =
lxxfjgwry0 [ 4 ] ; b5ijoe3553 [ 7 ] = lxxfjgwry0 [ 5 ] ; b5ijoe3553 [ 8 ] =
lxxfjgwry0 [ 2 ] ; memcpy ( & rtB . gdzioetcaj [ 0 ] , & b5ijoe3553 [ 0 ] ,
9U * sizeof ( real_T ) ) ; rtB . p5kqeroffv [ 0 ] = lxxfjgwry0 [ 6 ] / rtP .
Constant3_Value ; rtB . p5kqeroffv [ 1 ] = lxxfjgwry0 [ 7 ] / rtP .
Constant3_Value ; rtB . p5kqeroffv [ 2 ] = lxxfjgwry0 [ 8 ] / rtP .
Constant3_Value ; if ( ssGetLogOutput ( rtS ) ) { { { void * signalProbe = (
void * ) rtDW . mohxnwpvy0 . SignalProbe ; real_T t ; void * u ; t =
ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . fz0figaoto [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
fs3xofbgsa . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . p05flgh0s0 [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
jhekd05k4p = ( rtB . cjc4bi0q0l [ 0 ] >= rtP . Switch_Threshold_ocvrgqhwfd )
; } mkoj55axg1 = ( rtP . Constant_Value_egwar5iee0 - ( ( ( rtB . cjc4bi0q0l [
0 ] * rtB . cjc4bi0q0l [ 0 ] + rtB . cjc4bi0q0l [ 1 ] * rtB . cjc4bi0q0l [ 1
] ) + rtB . cjc4bi0q0l [ 2 ] * rtB . cjc4bi0q0l [ 2 ] ) + rtB . cjc4bi0q0l [
3 ] * rtB . cjc4bi0q0l [ 3 ] ) ) * rtP . HighGainQuaternionNormalization_Gain
; rtB . pbw2adbesb = ( ( rtB . cjc4bi0q0l [ 1 ] * rtB . kwssbn0ne4 [ 0 ] +
rtB . cjc4bi0q0l [ 2 ] * rtB . kwssbn0ne4 [ 1 ] ) + rtB . cjc4bi0q0l [ 3 ] *
rtB . kwssbn0ne4 [ 2 ] ) * - 0.5 + mkoj55axg1 * rtB . cjc4bi0q0l [ 0 ] ; rtB
. ab5xgw0342 = ( ( rtB . cjc4bi0q0l [ 0 ] * rtB . kwssbn0ne4 [ 0 ] + rtB .
cjc4bi0q0l [ 2 ] * rtB . kwssbn0ne4 [ 2 ] ) - rtB . cjc4bi0q0l [ 3 ] * rtB .
kwssbn0ne4 [ 1 ] ) * 0.5 + mkoj55axg1 * rtB . cjc4bi0q0l [ 1 ] ; rtB .
ct3c5eoli2 = ( ( rtB . cjc4bi0q0l [ 0 ] * rtB . kwssbn0ne4 [ 1 ] + rtB .
cjc4bi0q0l [ 3 ] * rtB . kwssbn0ne4 [ 0 ] ) - rtB . cjc4bi0q0l [ 1 ] * rtB .
kwssbn0ne4 [ 2 ] ) * 0.5 + mkoj55axg1 * rtB . cjc4bi0q0l [ 2 ] ; rtB .
crik5dobwi = ( ( rtB . cjc4bi0q0l [ 0 ] * rtB . kwssbn0ne4 [ 2 ] + rtB .
cjc4bi0q0l [ 1 ] * rtB . kwssbn0ne4 [ 1 ] ) - rtB . cjc4bi0q0l [ 2 ] * rtB .
kwssbn0ne4 [ 0 ] ) * 0.5 + mkoj55axg1 * rtB . cjc4bi0q0l [ 3 ] ; c5vurnmczn [
0 ] = rtP . Constant3_Value_oayr5juvkv ; c5vurnmczn [ 1 ] = rtB . fz0figaoto
[ 3 ] ; c5vurnmczn [ 2 ] = rtP . Gain8_Gain * rtB . fz0figaoto [ 2 ] ;
c5vurnmczn [ 3 ] = rtP . Gain6_Gain * rtB . fz0figaoto [ 3 ] ; c5vurnmczn [ 4
] = rtP . Constant3_Value_oayr5juvkv ; c5vurnmczn [ 5 ] = rtB . fz0figaoto [
1 ] ; c5vurnmczn [ 6 ] = rtB . fz0figaoto [ 2 ] ; c5vurnmczn [ 7 ] = rtP .
Gain7_Gain * rtB . fz0figaoto [ 1 ] ; c5vurnmczn [ 8 ] = rtP .
Constant3_Value_oayr5juvkv ; for ( i = 0 ; i < 9 ; i ++ ) { rtB . o1klch4xqt
[ i ] = c5vurnmczn [ i ] ; nvadtslxwe [ i ] = rtB . o1klch4xqt [ i ] ; }
LUf_int32_Treal_T ( nvadtslxwe , lzn15zslbh , 3 ) ; for ( i = 0 ; i < 3 ; i
++ ) { k = ( int32_T ) muDoubleScalarFloor ( lzn15zslbh [ i ] ) - 1 ; if ( k
< 0 ) { k = 0 ; } else { if ( k >= 3 ) { k = 2 ; } } m2b1vgca5s [ i ] = rtB .
f22csweirk [ k ] ; m2b1vgca5s [ 3 + i ] = rtB . f22csweirk [ 3 + k ] ;
m2b1vgca5s [ 6 + i ] = rtB . f22csweirk [ 6 + k ] ; } for ( i_p = 0 ; i_p < 3
; i_p ++ ) { idxout = i_p * 3 ; i = 1 ; idxB = idxout + 1 ; nfwwjxsmuk =
m2b1vgca5s [ idxB ] ; k = 0 ; while ( k < 1 ) { nfwwjxsmuk -= nvadtslxwe [ i
] * m2b1vgca5s [ idxout ] ; i += 3 ; k = 1 ; } m2b1vgca5s [ idxB ] =
nfwwjxsmuk ; i = 2 ; idxB = idxout + 2 ; nfwwjxsmuk = m2b1vgca5s [ idxB ] ;
for ( k = 0 ; k < 2 ; k ++ ) { nfwwjxsmuk -= m2b1vgca5s [ idxout + k ] *
nvadtslxwe [ i ] ; i += 3 ; } m2b1vgca5s [ idxB ] = nfwwjxsmuk ; } for ( i_p
= 0 ; i_p < 3 ; i_p ++ ) { idxout = i_p * 3 ; i = idxout + 2 ; rtB .
ctfm1d5uqu [ i ] = m2b1vgca5s [ i ] / nvadtslxwe [ 8 ] ; i = 7 ; idxB =
idxout + 1 ; nfwwjxsmuk = m2b1vgca5s [ idxB ] ; k = 2 ; while ( k > 1 ) {
nfwwjxsmuk -= rtB . ctfm1d5uqu [ idxout + 2 ] * nvadtslxwe [ i ] ; i -= 3 ; k
= 1 ; } rtB . ctfm1d5uqu [ idxB ] = nfwwjxsmuk / nvadtslxwe [ i ] ; i = 6 ;
nfwwjxsmuk = m2b1vgca5s [ idxout ] ; for ( k = 2 ; k > 0 ; k -- ) {
nfwwjxsmuk -= rtB . ctfm1d5uqu [ idxout + k ] * nvadtslxwe [ i ] ; i -= 3 ; }
rtB . ctfm1d5uqu [ idxout ] = nfwwjxsmuk / nvadtslxwe [ i ] ; } for ( i_p = 0
; i_p < 3 ; i_p ++ ) { rtB . lqnx4g1go5 [ i_p ] = 0.0 ; rtB . lqnx4g1go5 [
i_p ] += rtB . ctfm1d5uqu [ i_p ] * rtB . p05flgh0s0 [ 0 ] ; rtB . lqnx4g1go5
[ i_p ] += rtB . ctfm1d5uqu [ i_p + 3 ] * rtB . p05flgh0s0 [ 1 ] ; rtB .
lqnx4g1go5 [ i_p ] += rtB . ctfm1d5uqu [ i_p + 6 ] * rtB . p05flgh0s0 [ 2 ] ;
} if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . l3eb5r4yyc = rtP . Gain5_Gain
* rtP . a_Value ; } rtB . kfrivtgbni [ 0 ] = ( rtB . p05flgh0s0 [ 0 ] - rtP .
a_Value * rtB . fz0figaoto [ 1 ] ) * rtB . l3eb5r4yyc ; rtB . kfrivtgbni [ 1
] = ( rtB . p05flgh0s0 [ 1 ] - rtP . a_Value * rtB . fz0figaoto [ 2 ] ) * rtB
. l3eb5r4yyc ; rtB . kfrivtgbni [ 2 ] = ( rtB . p05flgh0s0 [ 2 ] - rtP .
a_Value * rtB . fz0figaoto [ 3 ] ) * rtB . l3eb5r4yyc ; lzn15zslbh [ 0 ] =
nsjhwaxccv . vj2000 [ 0 ] ; lzn15zslbh [ 1 ] = nsjhwaxccv . vj2000 [ 1 ] ;
lzn15zslbh [ 2 ] = nsjhwaxccv . vj2000 [ 2 ] ; rtB . iloozpnfyr [ 0 ] =
nsjhwaxccv . j2000 [ 0 ] ; rtB . iloozpnfyr [ 1 ] = nsjhwaxccv . j2000 [ 1 ]
; rtB . iloozpnfyr [ 2 ] = nsjhwaxccv . j2000 [ 2 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . lagfvd2ei5 = rtP . Gain_Gain_av3hfhcgyv * rtP .
Constant_Value_bw3vkbj2eu ; } nfwwjxsmuk = rtB . kfrkptukdf [ 0 ] * rtB .
kfrkptukdf [ 0 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { jyfgwidcz5 [ 0 ] =
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
rtP . Constant_Value_dlgbgdxgmn ; } enzyytwikn = rtB . kfrkptukdf [ 1 ] * rtB
. kfrkptukdf [ 1 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { e2tqctvrj0 [ 0 ]
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
rtP . Constant_Value_pnej1bop5b ; } hu2gcgsgxf = rtB . kfrkptukdf [ 2 ] * rtB
. kfrkptukdf [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { ldts3pfwss [ 0 ]
= rtP . Constant_Value_irpm3cwjza ; ldts3pfwss [ 1 ] = rtP . Constant4_Value
[ 2 ] ; ldts3pfwss [ 2 ] = rtP . Gain_Gain_nogset3ro3 * rtP . Constant4_Value
[ 1 ] ; ldts3pfwss [ 3 ] = rtP . Gain_Gain_nogset3ro3 * rtP . Constant4_Value
[ 2 ] ; ldts3pfwss [ 4 ] = rtP . Constant_Value_irpm3cwjza ; ldts3pfwss [ 5 ]
= rtP . Constant4_Value [ 0 ] ; ldts3pfwss [ 6 ] = rtP . Constant4_Value [ 1
] ; ldts3pfwss [ 7 ] = rtP . Gain_Gain_nogset3ro3 * rtP . Constant4_Value [ 0
] ; ldts3pfwss [ 8 ] = rtP . Constant_Value_irpm3cwjza ; for ( i_p = 0 ; i_p
< 3 ; i_p ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtB . fafimnaesx [ i_p + 3 *
i ] = 0.0 ; rtB . fafimnaesx [ i_p + 3 * i ] += ldts3pfwss [ 3 * i ] *
ldts3pfwss [ i_p ] ; rtB . fafimnaesx [ i_p + 3 * i ] += ldts3pfwss [ 3 * i +
1 ] * ldts3pfwss [ i_p + 3 ] ; rtB . fafimnaesx [ i_p + 3 * i ] += ldts3pfwss
[ 3 * i + 2 ] * ldts3pfwss [ i_p + 6 ] ; } } iq4emno1ma [ 0 ] = rtP .
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
iq4emno1ma [ i_p + 6 ] ; } } } for ( i = 0 ; i < 9 ; i ++ ) { nvadtslxwe [ i
] = ( ( ( ( nfwwjxsmuk * rtB . fyykrlz50p [ i ] + rtB . kfrkptukdf [ 0 ] *
rtB . ehlhfalizh [ i ] ) + rtB . kfrkptukdf [ 0 ] * rtB . g1xui3hmed [ i ] )
* rtB . lagfvd2ei5 + rtP . Constant1_Value_de0q5adpcb [ i ] ) + ( (
enzyytwikn * rtB . a1254pdgfh [ i ] + rtB . kfrkptukdf [ 1 ] * rtB .
e22yyth3y4 [ i ] ) + rtB . kfrkptukdf [ 1 ] * rtB . dhwvhv3uh5 [ i ] ) * rtB
. hdj40uot1u ) + ( ( hu2gcgsgxf * rtB . fafimnaesx [ i ] + rtB . kfrkptukdf [
2 ] * rtB . ee2go4u05y [ i ] ) + rtB . kfrkptukdf [ 2 ] * rtB . pijgu4gjiu [
i ] ) * rtB . gutdju0mn5 ; } mkoj55axg1 = ( rtB . iloozpnfyr [ 0 ] * rtB .
iloozpnfyr [ 0 ] + rtB . iloozpnfyr [ 1 ] * rtB . iloozpnfyr [ 1 ] ) + rtB .
iloozpnfyr [ 2 ] * rtB . iloozpnfyr [ 2 ] ; if ( mkoj55axg1 < 0.0 ) { rtB .
cz3ja34zrq = - muDoubleScalarSqrt ( muDoubleScalarAbs ( mkoj55axg1 ) ) ; }
else { rtB . cz3ja34zrq = muDoubleScalarSqrt ( mkoj55axg1 ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . jrnny2qloo = ( rtB . cz3ja34zrq > rtP .
Switch_Threshold_dkimt1f1tz ) ; } if ( rtDW . jrnny2qloo ) { ivszce53hq [ 0 ]
= rtB . iloozpnfyr [ 0 ] ; ivszce53hq [ 1 ] = rtB . iloozpnfyr [ 1 ] ;
ivszce53hq [ 2 ] = rtB . iloozpnfyr [ 2 ] ; ivszce53hq [ 3 ] = rtB .
cz3ja34zrq ; } else { rtB . dufe500tdo [ 0 ] = rtB . iloozpnfyr [ 0 ] * 0.0 ;
rtB . dufe500tdo [ 1 ] = rtB . iloozpnfyr [ 1 ] * 0.0 ; rtB . dufe500tdo [ 2
] = rtB . iloozpnfyr [ 2 ] * 0.0 ; ivszce53hq [ 0 ] = rtB . dufe500tdo [ 0 ]
; ivszce53hq [ 1 ] = rtB . dufe500tdo [ 1 ] ; ivszce53hq [ 2 ] = rtB .
dufe500tdo [ 2 ] ; ivszce53hq [ 3 ] = rtP . Constant_Value_hh2kih5qyy ; }
dwafzsky2m [ 0 ] = ivszce53hq [ 0 ] / ivszce53hq [ 3 ] ; dwafzsky2m [ 1 ] =
ivszce53hq [ 1 ] / ivszce53hq [ 3 ] ; dwafzsky2m [ 2 ] = ivszce53hq [ 2 ] /
ivszce53hq [ 3 ] ; rtB . cznp4l44bm [ 3 ] = dwafzsky2m [ 0 ] ; rtB .
cznp4l44bm [ 4 ] = dwafzsky2m [ 1 ] ; rtB . cznp4l44bm [ 5 ] = dwafzsky2m [ 2
] ; rtB . dfeof1aiqk [ 0 ] = lzn15zslbh [ 1 ] * rtB . iloozpnfyr [ 2 ] -
lzn15zslbh [ 2 ] * rtB . iloozpnfyr [ 1 ] ; rtB . dfeof1aiqk [ 1 ] =
lzn15zslbh [ 2 ] * rtB . iloozpnfyr [ 0 ] - lzn15zslbh [ 0 ] * rtB .
iloozpnfyr [ 2 ] ; rtB . dfeof1aiqk [ 2 ] = lzn15zslbh [ 0 ] * rtB .
iloozpnfyr [ 1 ] - lzn15zslbh [ 1 ] * rtB . iloozpnfyr [ 0 ] ; mkoj55axg1 = (
rtB . dfeof1aiqk [ 0 ] * rtB . dfeof1aiqk [ 0 ] + rtB . dfeof1aiqk [ 1 ] *
rtB . dfeof1aiqk [ 1 ] ) + rtB . dfeof1aiqk [ 2 ] * rtB . dfeof1aiqk [ 2 ] ;
if ( mkoj55axg1 < 0.0 ) { rtB . ox2cje3ogi = - muDoubleScalarSqrt (
muDoubleScalarAbs ( mkoj55axg1 ) ) ; } else { rtB . ox2cje3ogi =
muDoubleScalarSqrt ( mkoj55axg1 ) ; } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW
. ctt5abpcf5 = ( rtB . ox2cje3ogi > rtP . Switch_Threshold_gnlntr1le3 ) ; }
if ( rtDW . ctt5abpcf5 ) { ivszce53hq [ 0 ] = rtB . dfeof1aiqk [ 0 ] ;
ivszce53hq [ 1 ] = rtB . dfeof1aiqk [ 1 ] ; ivszce53hq [ 2 ] = rtB .
dfeof1aiqk [ 2 ] ; ivszce53hq [ 3 ] = rtB . ox2cje3ogi ; } else { rtB .
juc40yv1j4 [ 0 ] = rtB . dfeof1aiqk [ 0 ] * 0.0 ; rtB . juc40yv1j4 [ 1 ] =
rtB . dfeof1aiqk [ 1 ] * 0.0 ; rtB . juc40yv1j4 [ 2 ] = rtB . dfeof1aiqk [ 2
] * 0.0 ; ivszce53hq [ 0 ] = rtB . juc40yv1j4 [ 0 ] ; ivszce53hq [ 1 ] = rtB
. juc40yv1j4 [ 1 ] ; ivszce53hq [ 2 ] = rtB . juc40yv1j4 [ 2 ] ; ivszce53hq [
3 ] = rtP . Constant_Value_hgpikmmnsj ; } lzn15zslbh [ 0 ] = ivszce53hq [ 0 ]
/ ivszce53hq [ 3 ] ; lzn15zslbh [ 1 ] = ivszce53hq [ 1 ] / ivszce53hq [ 3 ] ;
lzn15zslbh [ 2 ] = ivszce53hq [ 2 ] / ivszce53hq [ 3 ] ; rtB . cznp4l44bm [ 6
] = lzn15zslbh [ 0 ] ; rtB . cznp4l44bm [ 7 ] = lzn15zslbh [ 1 ] ; rtB .
cznp4l44bm [ 8 ] = lzn15zslbh [ 2 ] ; rtB . cznp4l44bm [ 0 ] = dwafzsky2m [ 1
] * lzn15zslbh [ 2 ] - dwafzsky2m [ 2 ] * lzn15zslbh [ 1 ] ; rtB . cznp4l44bm
[ 1 ] = dwafzsky2m [ 2 ] * lzn15zslbh [ 0 ] - dwafzsky2m [ 0 ] * lzn15zslbh [
2 ] ; rtB . cznp4l44bm [ 2 ] = dwafzsky2m [ 0 ] * lzn15zslbh [ 1 ] -
dwafzsky2m [ 1 ] * lzn15zslbh [ 0 ] ; rtB . aps03o1u4v = ( rtB . cznp4l44bm [
0 ] + rtB . cznp4l44bm [ 4 ] ) + rtB . cznp4l44bm [ 8 ] ; rtPrevAction = rtDW
. mf41bf444w ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB . aps03o1u4v > 0.0
) { rtAction = 0 ; } else { rtAction = 1 ; } rtDW . mf41bf444w = rtAction ; }
else { rtAction = rtDW . mf41bf444w ; } if ( rtPrevAction != rtAction ) {
switch ( rtPrevAction ) { case 0 : f3tc5mwqyz ( rtS ) ; break ; case 1 :
nws40mclpe ( rtS , & rtDW . azz3d4nxcem ) ; break ; } } switch ( rtAction ) {
case 0 : if ( rtAction != rtPrevAction ) { fri4zeczvq ( rtS ) ; } p0vdevk3x1
( rtS , rtB . aps03o1u4v , rtB . cznp4l44bm [ 5 ] , rtB . cznp4l44bm [ 7 ] ,
rtB . cznp4l44bm [ 2 ] , rtB . cznp4l44bm [ 6 ] , rtB . cznp4l44bm [ 1 ] ,
rtB . cznp4l44bm [ 3 ] , & rtB . l2aegg0det [ 0 ] , & rtB . l2aegg0det [ 1 ]
, & rtDW . p0vdevk3x14 , ( oj32fzmstd * ) & rtP . p0vdevk3x14 ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . p0vdevk3x14 . espotkwrxj )
; } break ; case 1 : if ( rtAction != rtPrevAction ) { nc5u50jta2 ( rtS ) ; }
azz3d4nxce ( rtS , rtB . cznp4l44bm [ 0 ] , rtB . cznp4l44bm [ 4 ] , rtB .
cznp4l44bm [ 8 ] , rtB . cznp4l44bm [ 1 ] , rtB . cznp4l44bm [ 3 ] , rtB .
cznp4l44bm [ 5 ] , rtB . cznp4l44bm [ 7 ] , rtB . cznp4l44bm [ 2 ] , rtB .
cznp4l44bm [ 6 ] , & rtB . l2aegg0det [ 0 ] , & rtB . l2aegg0det [ 1 ] , &
rtB . l2aegg0det [ 2 ] , & rtB . l2aegg0det [ 3 ] , & rtB . azz3d4nxcem , &
rtDW . azz3d4nxcem , ( a0yd1qizj0 * ) & rtP . azz3d4nxcem ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . azz3d4nxcem . fw1wxjvjvv )
; } break ; } rtB . olx5gr2zcm = - rtB . l2aegg0det [ 1 ] ; rtB . jzubqdhmue
= - rtB . l2aegg0det [ 2 ] ; rtB . mupkswka3h = - rtB . l2aegg0det [ 3 ] ;
rtB . gnf3ee0yie [ 0 ] = ( ( rtB . lronvhy5ya [ 1 ] * rtB . kta3wrejd4 [ 2 ]
- rtB . lronvhy5ya [ 2 ] * rtB . kta3wrejd4 [ 1 ] ) + rtB . ajquw4hgfb [ 0 ]
) * rtP . Gain_Gain_mpiyuuuwgr ; rtB . gnf3ee0yie [ 1 ] = ( ( rtB .
lronvhy5ya [ 2 ] * rtB . kta3wrejd4 [ 0 ] - rtB . lronvhy5ya [ 0 ] * rtB .
kta3wrejd4 [ 2 ] ) + rtB . ajquw4hgfb [ 1 ] ) * rtP . Gain_Gain_mpiyuuuwgr ;
rtB . gnf3ee0yie [ 2 ] = ( ( rtB . lronvhy5ya [ 0 ] * rtB . kta3wrejd4 [ 1 ]
- rtB . lronvhy5ya [ 1 ] * rtB . kta3wrejd4 [ 0 ] ) + rtB . ajquw4hgfb [ 2 ]
) * rtP . Gain_Gain_mpiyuuuwgr ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
jgvugjcell [ 0 ] = rtB . gnf3ee0yie [ 0 ] >= rtP .
Saturation_UpperSat_hafkqiwfxz ? 1 : rtB . gnf3ee0yie [ 0 ] > rtP .
Saturation_LowerSat_jlais4nb4c ? 0 : - 1 ; rtDW . jgvugjcell [ 1 ] = rtB .
gnf3ee0yie [ 1 ] >= rtP . Saturation_UpperSat_hafkqiwfxz ? 1 : rtB .
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
gnf3ee0yie [ 2 ] ; mkoj55axg1 = ( ( rtB . l2aegg0det [ 0 ] * rtB . l2aegg0det
[ 0 ] + rtB . olx5gr2zcm * rtB . olx5gr2zcm ) + rtB . jzubqdhmue * rtB .
jzubqdhmue ) + rtB . mupkswka3h * rtB . mupkswka3h ; emposknhj1 = rtB .
l2aegg0det [ 0 ] / mkoj55axg1 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
p0m1jnhybt [ 0 ] = rtP . Constant1_Value_fg2gdmjirg [ 0 ] ; rtB . p0m1jnhybt
[ 1 ] = rtP . Constant1_Value_fg2gdmjirg [ 1 ] ; rtB . p0m1jnhybt [ 2 ] = rtP
. Constant1_Value_fg2gdmjirg [ 2 ] ; rtB . p0m1jnhybt [ 3 ] = rtP .
Constant1_Value_fg2gdmjirg [ 3 ] ; } if ( rtDW . phnnzeax4q . IcNeedsLoading
) { rtX . gffjebdga3 [ 0 ] = rtB . p0m1jnhybt [ 0 ] ; rtX . gffjebdga3 [ 1 ]
= rtB . p0m1jnhybt [ 1 ] ; rtX . gffjebdga3 [ 2 ] = rtB . p0m1jnhybt [ 2 ] ;
rtX . gffjebdga3 [ 3 ] = rtB . p0m1jnhybt [ 3 ] ; } ivszce53hq [ 0 ] = rtX .
gffjebdga3 [ 0 ] ; ivszce53hq [ 1 ] = rtX . gffjebdga3 [ 1 ] ; ivszce53hq [ 2
] = rtX . gffjebdga3 [ 2 ] ; ivszce53hq [ 3 ] = rtX . gffjebdga3 [ 3 ] ;
enzyytwikn = - rtB . olx5gr2zcm / mkoj55axg1 ; hu2gcgsgxf = - rtB .
jzubqdhmue / mkoj55axg1 ; mkoj55axg1 = - rtB . mupkswka3h / mkoj55axg1 ; rtB
. jbdetydqg0 = ( ( emposknhj1 * ivszce53hq [ 0 ] - enzyytwikn * ivszce53hq [
1 ] ) - hu2gcgsgxf * ivszce53hq [ 2 ] ) - mkoj55axg1 * ivszce53hq [ 3 ] ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtB . jbdetydqg0 > 0.0 ) { rtDW . amy2z0blur = 1 ; } else if ( rtB .
jbdetydqg0 < 0.0 ) { rtDW . amy2z0blur = - 1 ; } else { rtDW . amy2z0blur = 0
; } } rtB . ol0ojtxxkn = rtDW . amy2z0blur ; } kpgrz5rhip_idx = rtB .
ol0ojtxxkn * rtB . jbdetydqg0 ; kpgrz5rhip_idx_e = ( ( ( emposknhj1 *
ivszce53hq [ 1 ] + enzyytwikn * ivszce53hq [ 0 ] ) + hu2gcgsgxf * ivszce53hq
[ 3 ] ) - mkoj55axg1 * ivszce53hq [ 2 ] ) * rtB . ol0ojtxxkn ;
kpgrz5rhip_idx_i = ( ( ( emposknhj1 * ivszce53hq [ 2 ] - enzyytwikn *
ivszce53hq [ 3 ] ) + hu2gcgsgxf * ivszce53hq [ 0 ] ) + mkoj55axg1 *
ivszce53hq [ 1 ] ) * rtB . ol0ojtxxkn ; kpgrz5rhip_idx_p = ( ( ( emposknhj1 *
ivszce53hq [ 3 ] + enzyytwikn * ivszce53hq [ 2 ] ) - hu2gcgsgxf * ivszce53hq
[ 1 ] ) + mkoj55axg1 * ivszce53hq [ 0 ] ) * rtB . ol0ojtxxkn ; mkoj55axg1 = (
( kpgrz5rhip_idx * kpgrz5rhip_idx + kpgrz5rhip_idx_e * kpgrz5rhip_idx_e ) +
kpgrz5rhip_idx_i * kpgrz5rhip_idx_i ) + kpgrz5rhip_idx_p * kpgrz5rhip_idx_p ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . huixms4qzu != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . huixms4qzu = 0 ; } mkoj55axg1 =
muDoubleScalarSqrt ( mkoj55axg1 ) ; } else { if ( mkoj55axg1 < 0.0 ) {
mkoj55axg1 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( mkoj55axg1 ) ) ; }
else { mkoj55axg1 = muDoubleScalarSqrt ( mkoj55axg1 ) ; } rtDW . huixms4qzu =
1 ; } emposknhj1 = kpgrz5rhip_idx_i / mkoj55axg1 ; enzyytwikn =
kpgrz5rhip_idx_p / mkoj55axg1 ; hu2gcgsgxf = kpgrz5rhip_idx_e / mkoj55axg1 ;
mkoj55axg1 = kpgrz5rhip_idx / mkoj55axg1 ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { rtB . neym5ecad1 [ 0 ] = rtP . Gain1_Gain_cz2xpyyxre * rtP .
ChangeMe_Value [ 0 ] ; rtB . neym5ecad1 [ 1 ] = rtP . Gain1_Gain_cz2xpyyxre *
rtP . ChangeMe_Value [ 1 ] ; rtB . neym5ecad1 [ 2 ] = rtP .
Gain1_Gain_cz2xpyyxre * rtP . ChangeMe_Value [ 2 ] ; } rtB . h5ipoluxjw [ 0 ]
= rtP . Constant1_Value_pibyfcp5ht [ 0 ] * rtB . kfrkptukdf [ 0 ] * rtP .
Gain2_Gain_g3pgvavbec ; rtB . h5ipoluxjw [ 1 ] = rtP .
Constant1_Value_pibyfcp5ht [ 1 ] * rtB . kfrkptukdf [ 0 ] * rtP .
Gain2_Gain_g3pgvavbec ; rtB . h5ipoluxjw [ 2 ] = rtP .
Constant1_Value_pibyfcp5ht [ 2 ] * rtB . kfrkptukdf [ 0 ] * rtP .
Gain2_Gain_g3pgvavbec ; rtB . klwhzltza0 [ 0 ] = rtP .
Constant2_Value_erhep10kxc [ 0 ] * rtB . kfrkptukdf [ 1 ] * rtP .
Gain3_Gain_nlnczbyk1z ; rtB . klwhzltza0 [ 1 ] = rtP .
Constant2_Value_erhep10kxc [ 1 ] * rtB . kfrkptukdf [ 1 ] * rtP .
Gain3_Gain_nlnczbyk1z ; rtB . klwhzltza0 [ 2 ] = rtP .
Constant2_Value_erhep10kxc [ 2 ] * rtB . kfrkptukdf [ 1 ] * rtP .
Gain3_Gain_nlnczbyk1z ; rtB . ixebsztwtv [ 0 ] = rtP .
Constant3_Value_au20vl24uo [ 0 ] * rtB . kfrkptukdf [ 2 ] * rtP .
Gain4_Gain_obkdmqncg2 ; rtB . ixebsztwtv [ 1 ] = rtP .
Constant3_Value_au20vl24uo [ 1 ] * rtB . kfrkptukdf [ 2 ] * rtP .
Gain4_Gain_obkdmqncg2 ; rtB . ixebsztwtv [ 2 ] = rtP .
Constant3_Value_au20vl24uo [ 2 ] * rtB . kfrkptukdf [ 2 ] * rtP .
Gain4_Gain_obkdmqncg2 ; rtB . fwgif0j4xy [ 0 ] = ( ( rtB . neym5ecad1 [ 0 ] +
rtB . h5ipoluxjw [ 0 ] ) + rtB . klwhzltza0 [ 0 ] ) + rtB . ixebsztwtv [ 0 ]
; rtB . fwgif0j4xy [ 1 ] = ( ( rtB . neym5ecad1 [ 1 ] + rtB . h5ipoluxjw [ 1
] ) + rtB . klwhzltza0 [ 1 ] ) + rtB . ixebsztwtv [ 1 ] ; rtB . fwgif0j4xy [
2 ] = ( ( rtB . neym5ecad1 [ 2 ] + rtB . h5ipoluxjw [ 2 ] ) + rtB .
klwhzltza0 [ 2 ] ) + rtB . ixebsztwtv [ 2 ] ; lzn15zslbh [ 0 ] = ( ( ( ( rtP
. Constant_Value_ej4q1vwpv0 - emposknhj1 * emposknhj1 ) - enzyytwikn *
enzyytwikn ) * rtP . Gain2_Gain_f1yzxme32r * rtP . Constant_Value_o4e4fo4gkj
[ 0 ] + ( hu2gcgsgxf * emposknhj1 + mkoj55axg1 * enzyytwikn ) * rtP .
Gain_Gain_itterqoc4x * rtP . Constant_Value_o4e4fo4gkj [ 1 ] ) + ( hu2gcgsgxf
* enzyytwikn - mkoj55axg1 * emposknhj1 ) * rtP . Gain1_Gain_ofwpfqh4qc * rtP
. Constant_Value_o4e4fo4gkj [ 2 ] ) * rtB . fwgif0j4xy [ 0 ] ; lzn15zslbh [ 1
] = ( ( ( ( rtP . Constant_Value_d4om0ngdo1 - hu2gcgsgxf * hu2gcgsgxf ) -
enzyytwikn * enzyytwikn ) * rtP . Gain2_Gain_lanpf0cnyt * rtP .
Constant_Value_o4e4fo4gkj [ 1 ] + ( hu2gcgsgxf * emposknhj1 - mkoj55axg1 *
enzyytwikn ) * rtP . Gain_Gain_jfem1ifujv * rtP . Constant_Value_o4e4fo4gkj [
0 ] ) + ( mkoj55axg1 * hu2gcgsgxf + emposknhj1 * enzyytwikn ) * rtP .
Gain1_Gain_o3l0m0cqsz * rtP . Constant_Value_o4e4fo4gkj [ 2 ] ) * rtB .
fwgif0j4xy [ 1 ] ; lzn15zslbh [ 2 ] = ( ( ( hu2gcgsgxf * enzyytwikn +
mkoj55axg1 * emposknhj1 ) * rtP . Gain_Gain_kbkv433xum * rtP .
Constant_Value_o4e4fo4gkj [ 0 ] + ( emposknhj1 * enzyytwikn - mkoj55axg1 *
hu2gcgsgxf ) * rtP . Gain1_Gain_aw5xkpj1cf * rtP . Constant_Value_o4e4fo4gkj
[ 1 ] ) + ( ( rtP . Constant_Value_pbdti2yadl - hu2gcgsgxf * hu2gcgsgxf ) -
emposknhj1 * emposknhj1 ) * rtP . Gain2_Gain_oat3nps3gi * rtP .
Constant_Value_o4e4fo4gkj [ 2 ] ) * rtB . fwgif0j4xy [ 2 ] ; rtB . ep30hm0x0x
[ 0 ] = rtP . Gain5_Gain_fzoolgsndi * lzn15zslbh [ 0 ] ; rtB . ep30hm0x0x [ 1
] = rtP . Gain5_Gain_fzoolgsndi * lzn15zslbh [ 1 ] ; rtB . ep30hm0x0x [ 2 ] =
rtP . Gain5_Gain_fzoolgsndi * lzn15zslbh [ 2 ] ; rtB . fpwu5qnsdz [ 0 ] = ( (
rtB . bj3cbec4w1 [ 0 ] + rtB . ep30hm0x0x [ 0 ] ) + 0.0 ) + 0.0 ; rtB .
fpwu5qnsdz [ 1 ] = ( ( rtB . bj3cbec4w1 [ 1 ] + rtB . ep30hm0x0x [ 1 ] ) +
0.0 ) + 0.0 ; rtB . fpwu5qnsdz [ 2 ] = ( ( rtB . bj3cbec4w1 [ 2 ] + rtB .
ep30hm0x0x [ 2 ] ) + 0.0 ) + 0.0 ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
lzn15zslbh [ i_p ] = 0.0 ; lzn15zslbh [ i_p ] += nvadtslxwe [ i_p ] * rtB .
lronvhy5ya [ 0 ] ; lzn15zslbh [ i_p ] += nvadtslxwe [ i_p + 3 ] * rtB .
lronvhy5ya [ 1 ] ; lzn15zslbh [ i_p ] += nvadtslxwe [ i_p + 6 ] * rtB .
lronvhy5ya [ 2 ] ; } kpgrz5rhip_idx = rtB . lronvhy5ya [ 1 ] * lzn15zslbh [ 2
] ; aif0nk4dcs = rtB . lronvhy5ya [ 2 ] * lzn15zslbh [ 0 ] ; kpgrz5rhip_idx_e
= rtB . lronvhy5ya [ 0 ] * lzn15zslbh [ 1 ] ; kpgrz5rhip_idx_i = rtB .
lronvhy5ya [ 2 ] * lzn15zslbh [ 1 ] ; kpgrz5rhip_idx_p = rtB . lronvhy5ya [ 0
] * lzn15zslbh [ 2 ] ; nfwwjxsmuk = rtB . lronvhy5ya [ 1 ] * lzn15zslbh [ 0 ]
; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { lzn15zslbh [ i_p ] = 0.0 ; lzn15zslbh
[ i_p ] += rtP . Constant_Value_e4va2nj2ny [ i_p ] * rtB . lronvhy5ya [ 0 ] ;
lzn15zslbh [ i_p ] += rtP . Constant_Value_e4va2nj2ny [ i_p + 3 ] * rtB .
lronvhy5ya [ 1 ] ; lzn15zslbh [ i_p ] += rtP . Constant_Value_e4va2nj2ny [
i_p + 6 ] * rtB . lronvhy5ya [ 2 ] ; } lzn15zslbh [ 0 ] = ( rtB . fpwu5qnsdz
[ 0 ] - lzn15zslbh [ 0 ] ) - ( kpgrz5rhip_idx - kpgrz5rhip_idx_i ) ;
lzn15zslbh [ 1 ] = ( rtB . fpwu5qnsdz [ 1 ] - lzn15zslbh [ 1 ] ) - (
aif0nk4dcs - kpgrz5rhip_idx_p ) ; lzn15zslbh [ 2 ] = ( rtB . fpwu5qnsdz [ 2 ]
- lzn15zslbh [ 2 ] ) - ( kpgrz5rhip_idx_e - nfwwjxsmuk ) ;
rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( nvadtslxwe , lzn15zslbh , rtB .
pirqrlkfn1 ) ; mkoj55axg1 = ( rtP . Constant_Value_fjgr21kt5s - ( ( (
ivszce53hq [ 0 ] * ivszce53hq [ 0 ] + ivszce53hq [ 1 ] * ivszce53hq [ 1 ] ) +
ivszce53hq [ 2 ] * ivszce53hq [ 2 ] ) + ivszce53hq [ 3 ] * ivszce53hq [ 3 ] )
) * rtP . HighGainQuaternionNormalization_Gain_ob3hm0wdis ; rtB . bivwrzak4c
= ( ( ivszce53hq [ 1 ] * rtB . lronvhy5ya [ 0 ] + ivszce53hq [ 2 ] * rtB .
lronvhy5ya [ 1 ] ) + ivszce53hq [ 3 ] * rtB . lronvhy5ya [ 2 ] ) * - 0.5 +
mkoj55axg1 * ivszce53hq [ 0 ] ; rtB . mdhwvkkkpg = ( ( ivszce53hq [ 0 ] * rtB
. lronvhy5ya [ 0 ] + ivszce53hq [ 2 ] * rtB . lronvhy5ya [ 2 ] ) - ivszce53hq
[ 3 ] * rtB . lronvhy5ya [ 1 ] ) * 0.5 + mkoj55axg1 * ivszce53hq [ 1 ] ; rtB
. kknubsmket = ( ( ivszce53hq [ 0 ] * rtB . lronvhy5ya [ 1 ] + ivszce53hq [ 3
] * rtB . lronvhy5ya [ 0 ] ) - ivszce53hq [ 1 ] * rtB . lronvhy5ya [ 2 ] ) *
0.5 + mkoj55axg1 * ivszce53hq [ 2 ] ; rtB . pok3faxosu = ( ( ivszce53hq [ 0 ]
* rtB . lronvhy5ya [ 2 ] + ivszce53hq [ 1 ] * rtB . lronvhy5ya [ 1 ] ) -
ivszce53hq [ 2 ] * rtB . lronvhy5ya [ 0 ] ) * 0.5 + mkoj55axg1 * ivszce53hq [
3 ] ; if ( ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * )
rtDW . iyqxvnatsr . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime (
rtS , 0 ) ; u = ( void * ) & rtB . lronvhy5ya [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } rtB . iklax5zz5j [
0 ] = rtB . l2aegg0det [ 0 ] ; rtB . iklax5zz5j [ 1 ] = rtB . olx5gr2zcm ;
rtB . iklax5zz5j [ 2 ] = rtB . jzubqdhmue ; rtB . iklax5zz5j [ 3 ] = rtB .
mupkswka3h ; if ( ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void
* ) rtDW . h4jqbncwhd . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime
( rtS , 0 ) ; u = ( void * ) & rtB . iklax5zz5j [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
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
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } rtB . dbwyygj2mo [
0 ] = rtP . Gain6_Gain_nptkktx5dl * rtB . fwgif0j4xy [ 0 ] ; rtB . dbwyygj2mo
[ 1 ] = rtP . Gain6_Gain_nptkktx5dl * rtB . fwgif0j4xy [ 1 ] ; rtB .
dbwyygj2mo [ 2 ] = rtP . Gain6_Gain_nptkktx5dl * rtB . fwgif0j4xy [ 2 ] ; if
( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtB . nx1aqqkpv1 [ 0 ] = rtP .
Output_Gain_ba0gpqdttx [ 0 ] * rtDW . phocmexnl1 ; rtB . nx1aqqkpv1 [ 1 ] =
rtP . Output_Gain_ba0gpqdttx [ 1 ] * rtDW . phocmexnl1 ; rtB . nx1aqqkpv1 [ 2
] = rtP . Output_Gain_ba0gpqdttx [ 2 ] * rtDW . phocmexnl1 ; } lzn15zslbh [ 0
] = rtP . Gain_Gain_ovaf4mtkfv * kr12ccbspc_idx - lkkogows30_idx ; lzn15zslbh
[ 1 ] = rtP . Gain_Gain_ovaf4mtkfv * kr12ccbspc_idx_p - lkkogows30_idx_p ;
lzn15zslbh [ 2 ] = rtP . Gain_Gain_ovaf4mtkfv * kr12ccbspc_idx_e -
lkkogows30_idx_e ; mkoj55axg1 = ( ( ivszce53hq [ 0 ] * ivszce53hq [ 0 ] +
ivszce53hq [ 1 ] * ivszce53hq [ 1 ] ) + ivszce53hq [ 2 ] * ivszce53hq [ 2 ] )
+ ivszce53hq [ 3 ] * ivszce53hq [ 3 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtDW . pfcneilmew != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW .
pfcneilmew = 0 ; } mkoj55axg1 = muDoubleScalarSqrt ( mkoj55axg1 ) ; } else {
if ( mkoj55axg1 < 0.0 ) { mkoj55axg1 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( mkoj55axg1 ) ) ; } else { mkoj55axg1 = muDoubleScalarSqrt
( mkoj55axg1 ) ; } rtDW . pfcneilmew = 1 ; } emposknhj1 = ivszce53hq [ 2 ] /
mkoj55axg1 ; enzyytwikn = ivszce53hq [ 3 ] / mkoj55axg1 ; hu2gcgsgxf =
ivszce53hq [ 1 ] / mkoj55axg1 ; mkoj55axg1 = ivszce53hq [ 0 ] / mkoj55axg1 ;
rtB . i1cyqesfho = ( ( ( rtP . Constant_Value_nt3nodlo0n - emposknhj1 *
emposknhj1 ) - enzyytwikn * enzyytwikn ) * rtP . Gain2_Gain_b455g1loe1 *
lzn15zslbh [ 0 ] + ( hu2gcgsgxf * emposknhj1 + mkoj55axg1 * enzyytwikn ) *
rtP . Gain_Gain_pxe1qwiizn * lzn15zslbh [ 1 ] ) + ( hu2gcgsgxf * enzyytwikn -
mkoj55axg1 * emposknhj1 ) * rtP . Gain1_Gain_huu1lmrels * lzn15zslbh [ 2 ] ;
rtB . e1jmsnwsko = ( ( ( rtP . Constant_Value_jy4gaazlnd - hu2gcgsgxf *
hu2gcgsgxf ) - enzyytwikn * enzyytwikn ) * rtP . Gain2_Gain_bujbdfke15 *
lzn15zslbh [ 1 ] + ( hu2gcgsgxf * emposknhj1 - mkoj55axg1 * enzyytwikn ) *
rtP . Gain_Gain_j0vyy2fy2r * lzn15zslbh [ 0 ] ) + ( mkoj55axg1 * hu2gcgsgxf +
emposknhj1 * enzyytwikn ) * rtP . Gain1_Gain_fkwqudcabt * lzn15zslbh [ 2 ] ;
rtB . h2b1u411ed = ( ( hu2gcgsgxf * enzyytwikn + mkoj55axg1 * emposknhj1 ) *
rtP . Gain_Gain_bigflic040 * lzn15zslbh [ 0 ] + ( emposknhj1 * enzyytwikn -
mkoj55axg1 * hu2gcgsgxf ) * rtP . Gain1_Gain_hfanpouy13 * lzn15zslbh [ 1 ] )
+ ( ( rtP . Constant_Value_mctqlak3ab - hu2gcgsgxf * hu2gcgsgxf ) -
emposknhj1 * emposknhj1 ) * rtP . Gain2_Gain_o4dc4ko20g * lzn15zslbh [ 2 ] ;
mkoj55axg1 = ( rtB . i1cyqesfho * rtB . i1cyqesfho + rtB . e1jmsnwsko * rtB .
e1jmsnwsko ) + rtB . h2b1u411ed * rtB . h2b1u411ed ; if ( mkoj55axg1 < 0.0 )
{ rtB . ia5lss0zy0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( mkoj55axg1 )
) ; } else { rtB . ia5lss0zy0 = muDoubleScalarSqrt ( mkoj55axg1 ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . et15tz1dc1 = ( rtB . ia5lss0zy0 > rtP .
Switch_Threshold_jv24xn0sxc ) ; } if ( ! rtDW . et15tz1dc1 ) { rtB .
ps4hnijzog [ 0 ] = rtB . i1cyqesfho * 0.0 ; rtB . ps4hnijzog [ 1 ] = rtB .
e1jmsnwsko * 0.0 ; rtB . ps4hnijzog [ 2 ] = rtB . h2b1u411ed * 0.0 ; } if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
hzkxwtgg3yv . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . e14rgshsrb [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtX .
ipddjaa3ie [ 0 ] >= rtP . IntegratorLimited_UpperSat_fwrvmo440m ) { rtX .
ipddjaa3ie [ 0 ] = rtP . IntegratorLimited_UpperSat_fwrvmo440m ; } else if (
rtX . ipddjaa3ie [ 0 ] <= rtP . IntegratorLimited_LowerSat_m3ljhooqpl ) { rtX
. ipddjaa3ie [ 0 ] = rtP . IntegratorLimited_LowerSat_m3ljhooqpl ; } if ( rtX
. ipddjaa3ie [ 1 ] >= rtP . IntegratorLimited_UpperSat_fwrvmo440m ) { rtX .
ipddjaa3ie [ 1 ] = rtP . IntegratorLimited_UpperSat_fwrvmo440m ; } else if (
rtX . ipddjaa3ie [ 1 ] <= rtP . IntegratorLimited_LowerSat_m3ljhooqpl ) { rtX
. ipddjaa3ie [ 1 ] = rtP . IntegratorLimited_LowerSat_m3ljhooqpl ; } if ( rtX
. ipddjaa3ie [ 2 ] >= rtP . IntegratorLimited_UpperSat_fwrvmo440m ) { rtX .
ipddjaa3ie [ 2 ] = rtP . IntegratorLimited_UpperSat_fwrvmo440m ; } else if (
rtX . ipddjaa3ie [ 2 ] <= rtP . IntegratorLimited_LowerSat_m3ljhooqpl ) { rtX
. ipddjaa3ie [ 2 ] = rtP . IntegratorLimited_LowerSat_m3ljhooqpl ; } } rtB .
hfr3g5fo5z [ 0 ] = rtX . ipddjaa3ie [ 0 ] ; rtB . hfr3g5fo5z [ 1 ] = rtX .
ipddjaa3ie [ 1 ] ; rtB . hfr3g5fo5z [ 2 ] = rtX . ipddjaa3ie [ 2 ] ; if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
ethxueuerq5 . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . hfr3g5fo5z [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
c3goefzgk3 [ 0 ] = rtP . Constant_Value_lcleawr1lx [ 0 ] ; rtB . c3goefzgk3 [
1 ] = rtP . Constant_Value_lcleawr1lx [ 1 ] ; rtB . c3goefzgk3 [ 2 ] = rtP .
Constant_Value_lcleawr1lx [ 2 ] ; } if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtX . bhzxtdpm0j [ 0 ] >= rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ) { rtX
. bhzxtdpm0j [ 0 ] = rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ; } else if
( rtX . bhzxtdpm0j [ 0 ] <= rtP . IntegratorLimited_LowerSat_l15h4cnjuq ) {
rtX . bhzxtdpm0j [ 0 ] = rtP . IntegratorLimited_LowerSat_l15h4cnjuq ; } if (
rtX . bhzxtdpm0j [ 1 ] >= rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ) { rtX
. bhzxtdpm0j [ 1 ] = rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ; } else if
( rtX . bhzxtdpm0j [ 1 ] <= rtP . IntegratorLimited_LowerSat_l15h4cnjuq ) {
rtX . bhzxtdpm0j [ 1 ] = rtP . IntegratorLimited_LowerSat_l15h4cnjuq ; } if (
rtX . bhzxtdpm0j [ 2 ] >= rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ) { rtX
. bhzxtdpm0j [ 2 ] = rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ; } else if
( rtX . bhzxtdpm0j [ 2 ] <= rtP . IntegratorLimited_LowerSat_l15h4cnjuq ) {
rtX . bhzxtdpm0j [ 2 ] = rtP . IntegratorLimited_LowerSat_l15h4cnjuq ; } }
rtB . l4ag020lhf [ 0 ] = rtX . bhzxtdpm0j [ 0 ] ; rtB . l4ag020lhf [ 1 ] =
rtX . bhzxtdpm0j [ 1 ] ; rtB . l4ag020lhf [ 2 ] = rtX . bhzxtdpm0j [ 2 ] ;
lzn15zslbh [ 0 ] = rtP . Gain1_Gain_n011xbqfsl * rtB . l4ag020lhf [ 0 ] ;
lzn15zslbh [ 1 ] = rtP . Gain1_Gain_n011xbqfsl * rtB . l4ag020lhf [ 1 ] ;
lzn15zslbh [ 2 ] = rtP . Gain1_Gain_n011xbqfsl * rtB . l4ag020lhf [ 2 ] ; {
real_T * pDataValues = ( real_T * ) rtDW . hqwrc0ipzd . DataPtr [ 0 ] ;
real_T * pTimeValues = ( real_T * ) rtDW . hqwrc0ipzd . TimePtr [ 0 ] ; int_T
currTimeIndex = rtDW . nrfurckayn . PrevIndex [ 0 ] ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 979 ] ) { { int_T elIdx ;
for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . j2000 [ 0 ] ) [
elIdx ] = pDataValues [ 979 ] ; pDataValues += 980 ; } } } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
hqwrc0ipzd . RSimInfoPtr [ 0 ] ; numPoints = fromwksInfo -> nDataPoints ;
lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0
; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint -
1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
nrfurckayn . PrevIndex [ 0 ] = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx
) { ( & nsjhwaxccv . j2000 [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ]
; pDataValues += numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ;
elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . j2000 [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else {
real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ;
real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0
; elIdx < 3 ; ++ elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues
[ TimeIndex + 1 ] ; ( & nsjhwaxccv . j2000 [ 0 ] ) [ elIdx ] = ( real_T )
rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } }
{ real_T * pDataValues = ( real_T * ) rtDW . hqwrc0ipzd . DataPtr [ 1 ] ;
real_T * pTimeValues = ( real_T * ) rtDW . hqwrc0ipzd . TimePtr [ 1 ] ; int_T
currTimeIndex = rtDW . nrfurckayn . PrevIndex [ 1 ] ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 979 ] ) { { int_T elIdx ;
for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . vj2000 [ 0 ] ) [
elIdx ] = pDataValues [ 979 ] ; pDataValues += 980 ; } } } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
hqwrc0ipzd . RSimInfoPtr [ 1 ] ; numPoints = fromwksInfo -> nDataPoints ;
lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0
; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint -
1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
nrfurckayn . PrevIndex [ 1 ] = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx
) { ( & nsjhwaxccv . vj2000 [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ]
; pDataValues += numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ;
elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . vj2000 [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else {
real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ;
real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0
; elIdx < 3 ; ++ elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues
[ TimeIndex + 1 ] ; ( & nsjhwaxccv . vj2000 [ 0 ] ) [ elIdx ] = ( real_T )
rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } }
{ real_T * pDataValues = ( real_T * ) rtDW . hqwrc0ipzd . DataPtr [ 2 ] ;
real_T * pTimeValues = ( real_T * ) rtDW . hqwrc0ipzd . TimePtr [ 2 ] ; int_T
currTimeIndex = rtDW . nrfurckayn . PrevIndex [ 2 ] ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 979 ] ) { { int_T elIdx ;
for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . Worbj [ 0 ] ) [
elIdx ] = pDataValues [ 979 ] ; pDataValues += 980 ; } } } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
hqwrc0ipzd . RSimInfoPtr [ 2 ] ; numPoints = fromwksInfo -> nDataPoints ;
lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0
; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint -
1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
nrfurckayn . PrevIndex [ 2 ] = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx
) { ( & nsjhwaxccv . Worbj [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ]
; pDataValues += numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ;
elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . Worbj [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else {
real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ;
real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0
; elIdx < 3 ; ++ elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues
[ TimeIndex + 1 ] ; ( & nsjhwaxccv . Worbj [ 0 ] ) [ elIdx ] = ( real_T )
rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } }
{ real_T * pDataValues = ( real_T * ) rtDW . hqwrc0ipzd . DataPtr [ 3 ] ;
real_T * pTimeValues = ( real_T * ) rtDW . hqwrc0ipzd . TimePtr [ 3 ] ; int_T
currTimeIndex = rtDW . nrfurckayn . PrevIndex [ 3 ] ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 979 ] ) { { int_T elIdx ;
for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . rsun [ 0 ] ) [
elIdx ] = pDataValues [ 979 ] ; pDataValues += 980 ; } } } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
hqwrc0ipzd . RSimInfoPtr [ 3 ] ; numPoints = fromwksInfo -> nDataPoints ;
lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0
; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint -
1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
nrfurckayn . PrevIndex [ 3 ] = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx
) { ( & nsjhwaxccv . rsun [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ] ;
pDataValues += numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ;
elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . rsun [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else {
real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ;
real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0
; elIdx < 3 ; ++ elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues
[ TimeIndex + 1 ] ; ( & nsjhwaxccv . rsun [ 0 ] ) [ elIdx ] = ( real_T )
rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } }
{ real_T * pDataValues = ( real_T * ) rtDW . hqwrc0ipzd . DataPtr [ 4 ] ;
real_T * pTimeValues = ( real_T * ) rtDW . hqwrc0ipzd . TimePtr [ 4 ] ; int_T
currTimeIndex = rtDW . nrfurckayn . PrevIndex [ 4 ] ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t >= pTimeValues [ 979 ] ) { { int_T elIdx ;
for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . rrsuno [ 0 ] ) [
elIdx ] = pDataValues [ 979 ] ; pDataValues += 980 ; } } } else { int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
hqwrc0ipzd . RSimInfoPtr [ 4 ] ; numPoints = fromwksInfo -> nDataPoints ;
lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0
; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint -
1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
nrfurckayn . PrevIndex [ 4 ] = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { { int_T elIdx ; for ( elIdx = 0 ; elIdx < 3 ; ++ elIdx
) { ( & nsjhwaxccv . rrsuno [ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex ]
; pDataValues += numPoints ; } } } else { { int_T elIdx ; for ( elIdx = 0 ;
elIdx < 3 ; ++ elIdx ) { ( & nsjhwaxccv . rrsuno [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex + 1 ] ; pDataValues += numPoints ; } } } } else {
real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ;
real_T d2 ; int_T TimeIndex = currTimeIndex ; { int_T elIdx ; for ( elIdx = 0
; elIdx < 3 ; ++ elIdx ) { d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues
[ TimeIndex + 1 ] ; ( & nsjhwaxccv . rrsuno [ 0 ] ) [ elIdx ] = ( real_T )
rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } }
rtB . lkkogows30i [ 0 ] = nsjhwaxccv . j2000 [ 0 ] ; rtB . lkkogows30i [ 1 ]
= nsjhwaxccv . j2000 [ 1 ] ; rtB . lkkogows30i [ 2 ] = nsjhwaxccv . j2000 [ 2
] ; mkoj55axg1 = ( rtB . lkkogows30i [ 0 ] * rtB . lkkogows30i [ 0 ] + rtB .
lkkogows30i [ 1 ] * rtB . lkkogows30i [ 1 ] ) + rtB . lkkogows30i [ 2 ] * rtB
. lkkogows30i [ 2 ] ; if ( mkoj55axg1 < 0.0 ) { rtB . bu0zd3hop0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( mkoj55axg1 ) ) ; } else { rtB .
bu0zd3hop0 = muDoubleScalarSqrt ( mkoj55axg1 ) ; } if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . hs4d4btmzy = ( rtB . bu0zd3hop0 > rtP .
Switch_Threshold_g4wyietdsx ) ; } if ( rtDW . hs4d4btmzy ) { kpgrz5rhip_idx =
rtB . lkkogows30i [ 0 ] ; kpgrz5rhip_idx_e = rtB . lkkogows30i [ 1 ] ;
kpgrz5rhip_idx_i = rtB . lkkogows30i [ 2 ] ; kpgrz5rhip_idx_p = rtB .
bu0zd3hop0 ; } else { rtB . md555povbw [ 0 ] = rtB . lkkogows30i [ 0 ] * 0.0
; rtB . md555povbw [ 1 ] = rtB . lkkogows30i [ 1 ] * 0.0 ; rtB . md555povbw [
2 ] = rtB . lkkogows30i [ 2 ] * 0.0 ; kpgrz5rhip_idx = rtB . md555povbw [ 0 ]
; kpgrz5rhip_idx_e = rtB . md555povbw [ 1 ] ; kpgrz5rhip_idx_i = rtB .
md555povbw [ 2 ] ; kpgrz5rhip_idx_p = rtP . Constant_Value_nbket1mlnp ; } rtB
. eqdklum1kz [ 0 ] = kpgrz5rhip_idx / kpgrz5rhip_idx_p ; rtB . eqdklum1kz [ 1
] = kpgrz5rhip_idx_e / kpgrz5rhip_idx_p ; rtB . eqdklum1kz [ 2 ] =
kpgrz5rhip_idx_i / kpgrz5rhip_idx_p ; rtB . aff2guamhh [ 0 ] = nsjhwaxccv .
vj2000 [ 1 ] * rtB . lkkogows30i [ 2 ] - nsjhwaxccv . vj2000 [ 2 ] * rtB .
lkkogows30i [ 1 ] ; rtB . aff2guamhh [ 1 ] = nsjhwaxccv . vj2000 [ 2 ] * rtB
. lkkogows30i [ 0 ] - nsjhwaxccv . vj2000 [ 0 ] * rtB . lkkogows30i [ 2 ] ;
rtB . aff2guamhh [ 2 ] = nsjhwaxccv . vj2000 [ 0 ] * rtB . lkkogows30i [ 1 ]
- nsjhwaxccv . vj2000 [ 1 ] * rtB . lkkogows30i [ 0 ] ; mkoj55axg1 = ( rtB .
aff2guamhh [ 0 ] * rtB . aff2guamhh [ 0 ] + rtB . aff2guamhh [ 1 ] * rtB .
aff2guamhh [ 1 ] ) + rtB . aff2guamhh [ 2 ] * rtB . aff2guamhh [ 2 ] ; if (
mkoj55axg1 < 0.0 ) { rtB . eaiuep244b = - muDoubleScalarSqrt (
muDoubleScalarAbs ( mkoj55axg1 ) ) ; } else { rtB . eaiuep244b =
muDoubleScalarSqrt ( mkoj55axg1 ) ; } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW
. cgqmbfzh11 = ( rtB . eaiuep244b > rtP . Switch_Threshold_msevguw5vk ) ; }
if ( rtDW . cgqmbfzh11 ) { kpgrz5rhip_idx = rtB . aff2guamhh [ 0 ] ;
kpgrz5rhip_idx_e = rtB . aff2guamhh [ 1 ] ; kpgrz5rhip_idx_i = rtB .
aff2guamhh [ 2 ] ; kpgrz5rhip_idx_p = rtB . eaiuep244b ; } else { rtB .
bqyj10kjri [ 0 ] = rtB . aff2guamhh [ 0 ] * 0.0 ; rtB . bqyj10kjri [ 1 ] =
rtB . aff2guamhh [ 1 ] * 0.0 ; rtB . bqyj10kjri [ 2 ] = rtB . aff2guamhh [ 2
] * 0.0 ; kpgrz5rhip_idx = rtB . bqyj10kjri [ 0 ] ; kpgrz5rhip_idx_e = rtB .
bqyj10kjri [ 1 ] ; kpgrz5rhip_idx_i = rtB . bqyj10kjri [ 2 ] ;
kpgrz5rhip_idx_p = rtP . Constant_Value_oj52tmdbor ; } rtB . hzwurxk4ri [ 0 ]
= kpgrz5rhip_idx / kpgrz5rhip_idx_p ; rtB . hzwurxk4ri [ 1 ] =
kpgrz5rhip_idx_e / kpgrz5rhip_idx_p ; rtB . hzwurxk4ri [ 2 ] =
kpgrz5rhip_idx_i / kpgrz5rhip_idx_p ; rtB . iex2hnoztb [ 0 ] = rtB .
eqdklum1kz [ 1 ] * rtB . hzwurxk4ri [ 2 ] - rtB . eqdklum1kz [ 2 ] * rtB .
hzwurxk4ri [ 1 ] ; rtB . iex2hnoztb [ 1 ] = rtB . eqdklum1kz [ 2 ] * rtB .
hzwurxk4ri [ 0 ] - rtB . eqdklum1kz [ 0 ] * rtB . hzwurxk4ri [ 2 ] ; rtB .
iex2hnoztb [ 2 ] = rtB . eqdklum1kz [ 0 ] * rtB . hzwurxk4ri [ 1 ] - rtB .
eqdklum1kz [ 1 ] * rtB . hzwurxk4ri [ 0 ] ; m2b1vgca5s [ 0 ] = rtB .
iex2hnoztb [ 0 ] ; m2b1vgca5s [ 1 ] = rtB . iex2hnoztb [ 1 ] ; m2b1vgca5s [ 2
] = rtB . iex2hnoztb [ 2 ] ; m2b1vgca5s [ 3 ] = rtB . eqdklum1kz [ 0 ] ;
m2b1vgca5s [ 4 ] = rtB . eqdklum1kz [ 1 ] ; m2b1vgca5s [ 5 ] = rtB .
eqdklum1kz [ 2 ] ; m2b1vgca5s [ 6 ] = rtB . hzwurxk4ri [ 0 ] ; m2b1vgca5s [ 7
] = rtB . hzwurxk4ri [ 1 ] ; m2b1vgca5s [ 8 ] = rtB . hzwurxk4ri [ 2 ] ; for
( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . naewu0mfbx [ 3 * i_p ] = m2b1vgca5s [
i_p ] ; rtB . naewu0mfbx [ 1 + 3 * i_p ] = m2b1vgca5s [ i_p + 3 ] ; rtB .
naewu0mfbx [ 2 + 3 * i_p ] = m2b1vgca5s [ i_p + 6 ] ; } bguqm55hxa [ 0 ] =
rtB . naewu0mfbx [ 0 ] ; bguqm55hxa [ 1 ] = rtB . naewu0mfbx [ 4 ] ;
bguqm55hxa [ 2 ] = rtB . naewu0mfbx [ 8 ] ; rtB . g2zpeh00jx = ( rtB .
naewu0mfbx [ 0 ] + rtB . naewu0mfbx [ 4 ] ) + rtB . naewu0mfbx [ 8 ] ;
rtPrevAction = rtDW . nrel2zbbl0 ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtB . g2zpeh00jx > 0.0 ) { rtAction = 0 ; } else { rtAction = 1 ; } rtDW .
nrel2zbbl0 = rtAction ; } else { rtAction = rtDW . nrel2zbbl0 ; } if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 : f3tc5mwqyz (
rtS ) ; break ; case 1 : nws40mclpe ( rtS , & rtDW . iry0wsg2k5 ) ; break ; }
} switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { fri4zeczvq
( rtS ) ; } p0vdevk3x1 ( rtS , rtB . g2zpeh00jx , rtB . naewu0mfbx [ 5 ] ,
rtB . naewu0mfbx [ 7 ] , rtB . naewu0mfbx [ 2 ] , rtB . naewu0mfbx [ 6 ] ,
rtB . naewu0mfbx [ 1 ] , rtB . naewu0mfbx [ 3 ] , & rtB . elhnkqcp4v [ 0 ] ,
& rtB . elhnkqcp4v [ 1 ] , & rtDW . orebwtip3e , ( oj32fzmstd * ) & rtP .
orebwtip3e ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
orebwtip3e . espotkwrxj ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { nc5u50jta2 ( rtS ) ; } azz3d4nxce ( rtS , rtB . naewu0mfbx [ 0 ] , rtB .
naewu0mfbx [ 4 ] , rtB . naewu0mfbx [ 8 ] , rtB . naewu0mfbx [ 1 ] , rtB .
naewu0mfbx [ 3 ] , rtB . naewu0mfbx [ 5 ] , rtB . naewu0mfbx [ 7 ] , rtB .
naewu0mfbx [ 2 ] , rtB . naewu0mfbx [ 6 ] , & rtB . elhnkqcp4v [ 0 ] , & rtB
. elhnkqcp4v [ 1 ] , & rtB . elhnkqcp4v [ 2 ] , & rtB . elhnkqcp4v [ 3 ] , &
rtB . iry0wsg2k5 , & rtDW . iry0wsg2k5 , ( a0yd1qizj0 * ) & rtP . iry0wsg2k5
) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . iry0wsg2k5 .
fw1wxjvjvv ) ; } break ; } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
gpsddborgv = ( rtB . elhnkqcp4v [ 0 ] >= rtP . Switch_Threshold_i0bmwnwue3 )
; } if ( rtDW . gpsddborgv ) { mkoj55axg1 = rtP . Constant_Value_oc4kpc4egn ;
} else { mkoj55axg1 = rtP . Constant1_Value_bzw0ndzkcq ; } kpgrz5rhip_idx =
mkoj55axg1 * rtB . elhnkqcp4v [ 0 ] ; kpgrz5rhip_idx_e = mkoj55axg1 * rtB .
elhnkqcp4v [ 1 ] ; kpgrz5rhip_idx_i = mkoj55axg1 * rtB . elhnkqcp4v [ 2 ] ;
kpgrz5rhip_idx_p = mkoj55axg1 * rtB . elhnkqcp4v [ 3 ] ; mkoj55axg1 = ( (
kpgrz5rhip_idx * kpgrz5rhip_idx + kpgrz5rhip_idx_e * kpgrz5rhip_idx_e ) +
kpgrz5rhip_idx_i * kpgrz5rhip_idx_i ) + kpgrz5rhip_idx_p * kpgrz5rhip_idx_p ;
emposknhj1 = kpgrz5rhip_idx / mkoj55axg1 ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { nfwwjxsmuk = ( ( rtP . Qjo_init_Value_gqletaanjz [ 0 ] * rtP .
Qob_init_Value_onwkle1j2e [ 0 ] - rtP . Qjo_init_Value_gqletaanjz [ 1 ] * rtP
. Qob_init_Value_onwkle1j2e [ 1 ] ) - rtP . Qjo_init_Value_gqletaanjz [ 2 ] *
rtP . Qob_init_Value_onwkle1j2e [ 2 ] ) - rtP . Qjo_init_Value_gqletaanjz [ 3
] * rtP . Qob_init_Value_onwkle1j2e [ 3 ] ; if ( nfwwjxsmuk >= rtP .
Switch_Threshold_i3smlivfgb ) { enzyytwikn = rtP . Constant_Value_huezfbtji2
; } else { enzyytwikn = rtP . Constant1_Value_idmny2apeg ; } rtB . mt30lpgnlb
[ 0 ] = enzyytwikn * nfwwjxsmuk ; rtB . mt30lpgnlb [ 1 ] = ( ( ( rtP .
Qjo_init_Value_gqletaanjz [ 0 ] * rtP . Qob_init_Value_onwkle1j2e [ 1 ] + rtP
. Qjo_init_Value_gqletaanjz [ 1 ] * rtP . Qob_init_Value_onwkle1j2e [ 0 ] ) +
rtP . Qjo_init_Value_gqletaanjz [ 2 ] * rtP . Qob_init_Value_onwkle1j2e [ 3 ]
) - rtP . Qjo_init_Value_gqletaanjz [ 3 ] * rtP . Qob_init_Value_onwkle1j2e [
2 ] ) * enzyytwikn ; rtB . mt30lpgnlb [ 2 ] = ( ( ( rtP .
Qjo_init_Value_gqletaanjz [ 0 ] * rtP . Qob_init_Value_onwkle1j2e [ 2 ] - rtP
. Qjo_init_Value_gqletaanjz [ 1 ] * rtP . Qob_init_Value_onwkle1j2e [ 3 ] ) +
rtP . Qjo_init_Value_gqletaanjz [ 2 ] * rtP . Qob_init_Value_onwkle1j2e [ 0 ]
) + rtP . Qjo_init_Value_gqletaanjz [ 3 ] * rtP . Qob_init_Value_onwkle1j2e [
1 ] ) * enzyytwikn ; rtB . mt30lpgnlb [ 3 ] = ( ( ( rtP .
Qjo_init_Value_gqletaanjz [ 0 ] * rtP . Qob_init_Value_onwkle1j2e [ 3 ] + rtP
. Qjo_init_Value_gqletaanjz [ 1 ] * rtP . Qob_init_Value_onwkle1j2e [ 2 ] ) -
rtP . Qjo_init_Value_gqletaanjz [ 2 ] * rtP . Qob_init_Value_onwkle1j2e [ 1 ]
) + rtP . Qjo_init_Value_gqletaanjz [ 3 ] * rtP . Qob_init_Value_onwkle1j2e [
0 ] ) * enzyytwikn ; } if ( rtDW . g0vm4fxb3p . IcNeedsLoading ) { rtX .
hiwmnibigx [ 0 ] = rtB . mt30lpgnlb [ 0 ] ; rtX . hiwmnibigx [ 1 ] = rtB .
mt30lpgnlb [ 1 ] ; rtX . hiwmnibigx [ 2 ] = rtB . mt30lpgnlb [ 2 ] ; rtX .
hiwmnibigx [ 3 ] = rtB . mt30lpgnlb [ 3 ] ; } rtB . enst2mfa5p [ 0 ] = rtX .
hiwmnibigx [ 0 ] ; rtB . enst2mfa5p [ 1 ] = rtX . hiwmnibigx [ 1 ] ; rtB .
enst2mfa5p [ 2 ] = rtX . hiwmnibigx [ 2 ] ; rtB . enst2mfa5p [ 3 ] = rtX .
hiwmnibigx [ 3 ] ; enzyytwikn = - kpgrz5rhip_idx_e / mkoj55axg1 ; hu2gcgsgxf
= - kpgrz5rhip_idx_i / mkoj55axg1 ; mkoj55axg1 = - kpgrz5rhip_idx_p /
mkoj55axg1 ; rtB . iugw0131dq = ( ( emposknhj1 * rtB . enst2mfa5p [ 0 ] -
enzyytwikn * rtB . enst2mfa5p [ 1 ] ) - hu2gcgsgxf * rtB . enst2mfa5p [ 2 ] )
- mkoj55axg1 * rtB . enst2mfa5p [ 3 ] ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . gpuflrf0yn = ( rtB . iugw0131dq >= rtP . Switch_Threshold_oly1kcdrtr )
; } if ( rtDW . gpuflrf0yn ) { aif0nk4dcs = rtP . Constant_Value_deca5ebbvm ;
} else { aif0nk4dcs = rtP . Constant1_Value_cfl4aorgnt ; } rtB . j2s0rzuesy [
0 ] = aif0nk4dcs * rtB . iugw0131dq ; rtB . j2s0rzuesy [ 1 ] = ( ( (
emposknhj1 * rtB . enst2mfa5p [ 1 ] + enzyytwikn * rtB . enst2mfa5p [ 0 ] ) +
hu2gcgsgxf * rtB . enst2mfa5p [ 3 ] ) - mkoj55axg1 * rtB . enst2mfa5p [ 2 ] )
* aif0nk4dcs ; rtB . j2s0rzuesy [ 2 ] = ( ( ( emposknhj1 * rtB . enst2mfa5p [
2 ] - enzyytwikn * rtB . enst2mfa5p [ 3 ] ) + hu2gcgsgxf * rtB . enst2mfa5p [
0 ] ) + mkoj55axg1 * rtB . enst2mfa5p [ 1 ] ) * aif0nk4dcs ; rtB . j2s0rzuesy
[ 3 ] = ( ( ( emposknhj1 * rtB . enst2mfa5p [ 3 ] + enzyytwikn * rtB .
enst2mfa5p [ 2 ] ) - hu2gcgsgxf * rtB . enst2mfa5p [ 1 ] ) + mkoj55axg1 * rtB
. enst2mfa5p [ 0 ] ) * aif0nk4dcs ; dwafzsky2m [ 0 ] = rtB . j2s0rzuesy [ 0 ]
* rtB . j2s0rzuesy [ 1 ] ; dwafzsky2m [ 1 ] = rtB . j2s0rzuesy [ 0 ] * rtB .
j2s0rzuesy [ 2 ] ; dwafzsky2m [ 2 ] = rtB . j2s0rzuesy [ 0 ] * rtB .
j2s0rzuesy [ 3 ] ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . b01symif3z [
i_p ] = 0.0 ; rtB . b01symif3z [ i_p ] += rtP . ChangeMe3_Value_g3bcdwbqnq [
i_p ] * dwafzsky2m [ 0 ] ; rtB . b01symif3z [ i_p ] += rtP .
ChangeMe3_Value_g3bcdwbqnq [ i_p + 3 ] * dwafzsky2m [ 1 ] ; rtB . b01symif3z
[ i_p ] += rtP . ChangeMe3_Value_g3bcdwbqnq [ i_p + 6 ] * dwafzsky2m [ 2 ] ;
} if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . k4n51klhzm [ 0 ] = rtP .
Kang_Gain_n0feef1eux * rtB . b01symif3z [ 0 ] ; rtB . k4n51klhzm [ 1 ] = rtP
. Kang_Gain_n0feef1eux * rtB . b01symif3z [ 1 ] ; rtB . k4n51klhzm [ 2 ] =
rtP . Kang_Gain_n0feef1eux * rtB . b01symif3z [ 2 ] ; } nfwwjxsmuk = (
muDoubleScalarPower ( rtB . lkkogows30i [ 0 ] , 2.0 ) + muDoubleScalarPower (
rtB . lkkogows30i [ 1 ] , 2.0 ) ) + muDoubleScalarPower ( rtB . lkkogows30i [
2 ] , 2.0 ) ; dwafzsky2m [ 0 ] = rtP . Gain_Gain_bmoksmecff * rtB .
aff2guamhh [ 0 ] / nfwwjxsmuk ; dwafzsky2m [ 1 ] = rtP . Gain_Gain_bmoksmecff
* rtB . aff2guamhh [ 1 ] / nfwwjxsmuk ; dwafzsky2m [ 2 ] = rtP .
Gain_Gain_bmoksmecff * rtB . aff2guamhh [ 2 ] / nfwwjxsmuk ; kpgrz5rhip_idx =
( ( rtB . enst2mfa5p [ 0 ] * rtB . enst2mfa5p [ 0 ] + rtB . enst2mfa5p [ 1 ]
* rtB . enst2mfa5p [ 1 ] ) + rtB . enst2mfa5p [ 2 ] * rtB . enst2mfa5p [ 2 ]
) + rtB . enst2mfa5p [ 3 ] * rtB . enst2mfa5p [ 3 ] ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtDW . ej43nvwcyh != 0 ) { ssSetSolverNeedsReset ( rtS ) ;
rtDW . ej43nvwcyh = 0 ; } kpgrz5rhip_idx = muDoubleScalarSqrt (
kpgrz5rhip_idx ) ; } else { if ( kpgrz5rhip_idx < 0.0 ) { kpgrz5rhip_idx = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( kpgrz5rhip_idx ) ) ; } else {
kpgrz5rhip_idx = muDoubleScalarSqrt ( kpgrz5rhip_idx ) ; } rtDW . ej43nvwcyh
= 1 ; } mkoj55axg1 = rtB . enst2mfa5p [ 2 ] / kpgrz5rhip_idx ; emposknhj1 =
rtB . enst2mfa5p [ 3 ] / kpgrz5rhip_idx ; enzyytwikn = rtB . enst2mfa5p [ 1 ]
/ kpgrz5rhip_idx ; kpgrz5rhip_idx = rtB . enst2mfa5p [ 0 ] / kpgrz5rhip_idx ;
rtB . cy0g41je3i [ 0 ] = rtB . lcvceh3hv3 [ 0 ] - ( ( ( ( rtP .
Constant_Value_gxdrvm4bpy - mkoj55axg1 * mkoj55axg1 ) - emposknhj1 *
emposknhj1 ) * rtP . Gain2_Gain_heaghzzgpx * dwafzsky2m [ 0 ] + ( enzyytwikn
* mkoj55axg1 + kpgrz5rhip_idx * emposknhj1 ) * rtP . Gain_Gain_pgxythkq3t *
dwafzsky2m [ 1 ] ) + ( enzyytwikn * emposknhj1 - kpgrz5rhip_idx * mkoj55axg1
) * rtP . Gain1_Gain_aytyfi3wnb * dwafzsky2m [ 2 ] ) ; rtB . cy0g41je3i [ 1 ]
= rtB . lcvceh3hv3 [ 1 ] - ( ( ( ( rtP . Constant_Value_cictyeh5tj -
enzyytwikn * enzyytwikn ) - emposknhj1 * emposknhj1 ) * rtP .
Gain2_Gain_fmqrns42ku * dwafzsky2m [ 1 ] + ( enzyytwikn * mkoj55axg1 -
kpgrz5rhip_idx * emposknhj1 ) * rtP . Gain_Gain_i0c4kruuzt * dwafzsky2m [ 0 ]
) + ( kpgrz5rhip_idx * enzyytwikn + mkoj55axg1 * emposknhj1 ) * rtP .
Gain1_Gain_epqkenchvx * dwafzsky2m [ 2 ] ) ; rtB . cy0g41je3i [ 2 ] = rtB .
lcvceh3hv3 [ 2 ] - ( ( ( enzyytwikn * emposknhj1 + kpgrz5rhip_idx *
mkoj55axg1 ) * rtP . Gain_Gain_e3nk2dcxil * dwafzsky2m [ 0 ] + ( mkoj55axg1 *
emposknhj1 - kpgrz5rhip_idx * enzyytwikn ) * rtP . Gain1_Gain_gnp24rmnoz *
dwafzsky2m [ 1 ] ) + ( ( rtP . Constant_Value_c1xelsucey - enzyytwikn *
enzyytwikn ) - mkoj55axg1 * mkoj55axg1 ) * rtP . Gain2_Gain_evefvpl1an *
dwafzsky2m [ 2 ] ) ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { dwafzsky2m [ i_p ]
= rtP . ChangeMe3_Value_g3bcdwbqnq [ i_p + 6 ] * rtB . cy0g41je3i [ 2 ] + (
rtP . ChangeMe3_Value_g3bcdwbqnq [ i_p + 3 ] * rtB . cy0g41je3i [ 1 ] + rtP .
ChangeMe3_Value_g3bcdwbqnq [ i_p ] * rtB . cy0g41je3i [ 0 ] ) ; } rtB .
nxenwlnc5v [ 0 ] = rtP . Krate_Gain_piyaqat3c3 * dwafzsky2m [ 0 ] + rtB .
k4n51klhzm [ 0 ] ; rtB . nxenwlnc5v [ 1 ] = rtP . Krate_Gain_piyaqat3c3 *
dwafzsky2m [ 1 ] + rtB . k4n51klhzm [ 1 ] ; rtB . nxenwlnc5v [ 2 ] = rtP .
Krate_Gain_piyaqat3c3 * dwafzsky2m [ 2 ] + rtB . k4n51klhzm [ 2 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
bguqm55hxa [ i_p ] = rtP . ChangeMe3_Value_g3bcdwbqnq [ i_p + 6 ] * rtB .
lcvceh3hv3 [ 2 ] + ( rtP . ChangeMe3_Value_g3bcdwbqnq [ i_p + 3 ] * rtB .
lcvceh3hv3 [ 1 ] + rtP . ChangeMe3_Value_g3bcdwbqnq [ i_p ] * rtB .
lcvceh3hv3 [ 0 ] ) ; } rtB . kasev2hfro [ 0 ] = rtB . lcvceh3hv3 [ 1 ] *
bguqm55hxa [ 2 ] - rtB . lcvceh3hv3 [ 2 ] * bguqm55hxa [ 1 ] ; rtB .
kasev2hfro [ 1 ] = rtB . lcvceh3hv3 [ 2 ] * bguqm55hxa [ 0 ] - rtB .
lcvceh3hv3 [ 0 ] * bguqm55hxa [ 2 ] ; rtB . kasev2hfro [ 2 ] = rtB .
lcvceh3hv3 [ 0 ] * bguqm55hxa [ 1 ] - rtB . lcvceh3hv3 [ 1 ] * bguqm55hxa [ 0
] ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . oxns51znjb [ i_p ] = 0.0 ; rtB
. oxns51znjb [ i_p ] += rtP . ChangeMe1_Value_fak2wrhghj [ i_p ] * rtB .
lcvceh3hv3 [ 0 ] ; rtB . oxns51znjb [ i_p ] += rtP .
ChangeMe1_Value_fak2wrhghj [ i_p + 3 ] * rtB . lcvceh3hv3 [ 1 ] ; rtB .
oxns51znjb [ i_p ] += rtP . ChangeMe1_Value_fak2wrhghj [ i_p + 6 ] * rtB .
lcvceh3hv3 [ 2 ] ; } rtB . cxydpocexq [ 0 ] = rtB . lcvceh3hv3 [ 1 ] * rtP .
ChangeMe2_Value_bojzs0xv5c [ 2 ] - rtB . lcvceh3hv3 [ 2 ] * rtP .
ChangeMe2_Value_bojzs0xv5c [ 1 ] ; rtB . cxydpocexq [ 1 ] = rtB . lcvceh3hv3
[ 2 ] * rtP . ChangeMe2_Value_bojzs0xv5c [ 0 ] - rtB . lcvceh3hv3 [ 0 ] * rtP
. ChangeMe2_Value_bojzs0xv5c [ 2 ] ; rtB . cxydpocexq [ 2 ] = rtB .
lcvceh3hv3 [ 0 ] * rtP . ChangeMe2_Value_bojzs0xv5c [ 1 ] - rtB . lcvceh3hv3
[ 1 ] * rtP . ChangeMe2_Value_bojzs0xv5c [ 0 ] ; } rtB . eek0a0qnzz [ 0 ] = (
( rtB . nxenwlnc5v [ 0 ] - rtB . kasev2hfro [ 0 ] ) - rtB . oxns51znjb [ 0 ]
) - rtB . cxydpocexq [ 0 ] ; rtB . eek0a0qnzz [ 1 ] = ( ( rtB . nxenwlnc5v [
1 ] - rtB . kasev2hfro [ 1 ] ) - rtB . oxns51znjb [ 1 ] ) - rtB . cxydpocexq
[ 1 ] ; rtB . eek0a0qnzz [ 2 ] = ( ( rtB . nxenwlnc5v [ 2 ] - rtB .
kasev2hfro [ 2 ] ) - rtB . oxns51znjb [ 2 ] ) - rtB . cxydpocexq [ 2 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . l2ulz1zonw [ 0 ] = rtB . eek0a0qnzz [ 0
] >= rtP . Saturation_UpperSat_pmclfotbip ? 1 : rtB . eek0a0qnzz [ 0 ] > rtP
. Saturation_LowerSat_hmweagl2k5 ? 0 : - 1 ; rtDW . l2ulz1zonw [ 1 ] = rtB .
eek0a0qnzz [ 1 ] >= rtP . Saturation_UpperSat_pmclfotbip ? 1 : rtB .
eek0a0qnzz [ 1 ] > rtP . Saturation_LowerSat_hmweagl2k5 ? 0 : - 1 ; rtDW .
l2ulz1zonw [ 2 ] = rtB . eek0a0qnzz [ 2 ] >= rtP .
Saturation_UpperSat_pmclfotbip ? 1 : rtB . eek0a0qnzz [ 2 ] > rtP .
Saturation_LowerSat_hmweagl2k5 ? 0 : - 1 ; } if ( ssIsSampleHit ( rtS , 2 , 0
) ) { rtB . dc1j3uzyrw [ 0 ] = rtDW . l2ulz1zonw [ 0 ] == 1 ? rtP .
Saturation_UpperSat_pmclfotbip : rtDW . l2ulz1zonw [ 0 ] == - 1 ? rtP .
Saturation_LowerSat_hmweagl2k5 : rtB . eek0a0qnzz [ 0 ] ; rtB . dc1j3uzyrw [
1 ] = rtDW . l2ulz1zonw [ 1 ] == 1 ? rtP . Saturation_UpperSat_pmclfotbip :
rtDW . l2ulz1zonw [ 1 ] == - 1 ? rtP . Saturation_LowerSat_hmweagl2k5 : rtB .
eek0a0qnzz [ 1 ] ; rtB . dc1j3uzyrw [ 2 ] = rtDW . l2ulz1zonw [ 2 ] == 1 ?
rtP . Saturation_UpperSat_pmclfotbip : rtDW . l2ulz1zonw [ 2 ] == - 1 ? rtP .
Saturation_LowerSat_hmweagl2k5 : rtB . eek0a0qnzz [ 2 ] ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { kpgrz5rhip_idx = rtP .
Gain1_Gain_ftwdy5cupq * rtB . dc1j3uzyrw [ 0 ] ; if ( kpgrz5rhip_idx >= rtP .
Saturation_UpperSat_kvg53uzs0w ) { rtB . knm4o3kbgk [ 0 ] = rtP .
Saturation_UpperSat_kvg53uzs0w ; } else if ( kpgrz5rhip_idx <= rtP .
Saturation_LowerSat_ak0p0zlbrx ) { rtB . knm4o3kbgk [ 0 ] = rtP .
Saturation_LowerSat_ak0p0zlbrx ; } else { rtB . knm4o3kbgk [ 0 ] =
kpgrz5rhip_idx ; } kpgrz5rhip_idx = rtP . Gain1_Gain_ftwdy5cupq * rtB .
dc1j3uzyrw [ 1 ] ; if ( kpgrz5rhip_idx >= rtP .
Saturation_UpperSat_kvg53uzs0w ) { rtB . knm4o3kbgk [ 1 ] = rtP .
Saturation_UpperSat_kvg53uzs0w ; } else if ( kpgrz5rhip_idx <= rtP .
Saturation_LowerSat_ak0p0zlbrx ) { rtB . knm4o3kbgk [ 1 ] = rtP .
Saturation_LowerSat_ak0p0zlbrx ; } else { rtB . knm4o3kbgk [ 1 ] =
kpgrz5rhip_idx ; } kpgrz5rhip_idx = rtP . Gain1_Gain_ftwdy5cupq * rtB .
dc1j3uzyrw [ 2 ] ; if ( kpgrz5rhip_idx >= rtP .
Saturation_UpperSat_kvg53uzs0w ) { rtB . knm4o3kbgk [ 2 ] = rtP .
Saturation_UpperSat_kvg53uzs0w ; } else if ( kpgrz5rhip_idx <= rtP .
Saturation_LowerSat_ak0p0zlbrx ) { rtB . knm4o3kbgk [ 2 ] = rtP .
Saturation_LowerSat_ak0p0zlbrx ; } else { rtB . knm4o3kbgk [ 2 ] =
kpgrz5rhip_idx ; } rtB . gxs3gozf4z [ 0 ] = rtB . e14rgshsrb [ 0 ] ; rtB .
gxs3gozf4z [ 1 ] = rtB . e14rgshsrb [ 1 ] ; rtB . gxs3gozf4z [ 2 ] = rtB .
e14rgshsrb [ 2 ] ; } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { memset ( & rtB .
cz1nz0dwmw [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; rtB . cz1nz0dwmw [ 0 ] =
rtB . lcvceh3hv3 [ 0 ] ; rtB . cz1nz0dwmw [ 4 ] = rtB . lcvceh3hv3 [ 1 ] ;
rtB . cz1nz0dwmw [ 8 ] = rtB . lcvceh3hv3 [ 2 ] ; } if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { bdpgngpz5w [ 0 ] = rtB . lcvceh3hv3 [ 1 ] ; bdpgngpz5w [ 1 ] =
rtB . lcvceh3hv3 [ 0 ] ; bdpgngpz5w [ 2 ] = rtP . Constant_Value_fnng3n2cqs ;
bdpgngpz5w [ 3 ] = rtB . lcvceh3hv3 [ 2 ] ; bdpgngpz5w [ 4 ] = rtP .
Constant_Value_fnng3n2cqs ; bdpgngpz5w [ 5 ] = rtB . lcvceh3hv3 [ 0 ] ;
bdpgngpz5w [ 6 ] = rtP . Constant_Value_fnng3n2cqs ; bdpgngpz5w [ 7 ] = rtB .
lcvceh3hv3 [ 2 ] ; bdpgngpz5w [ 8 ] = rtB . lcvceh3hv3 [ 1 ] ; memcpy ( & rtB
. cz1nz0dwmw [ 9 ] , & bdpgngpz5w [ 0 ] , 9U * sizeof ( real_T ) ) ;
fnycyg1v5p [ 0 ] = rtP . Constant_Value_aav3mecjn5 ; fnycyg1v5p [ 1 ] = rtB .
lcvceh3hv3 [ 2 ] ; } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { rtB . i3r4txwmvn
[ 0 ] = rtP . Gain_Gain_ltta3l4gzo * rtB . lcvceh3hv3 [ 0 ] ; rtB .
i3r4txwmvn [ 1 ] = rtP . Gain_Gain_ltta3l4gzo * rtB . lcvceh3hv3 [ 1 ] ; rtB
. i3r4txwmvn [ 2 ] = rtP . Gain_Gain_ltta3l4gzo * rtB . lcvceh3hv3 [ 2 ] ; }
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { fnycyg1v5p [ 2 ] = rtB . i3r4txwmvn [
1 ] ; fnycyg1v5p [ 3 ] = rtB . i3r4txwmvn [ 2 ] ; fnycyg1v5p [ 4 ] = rtP .
Constant_Value_aav3mecjn5 ; fnycyg1v5p [ 5 ] = rtB . lcvceh3hv3 [ 0 ] ;
fnycyg1v5p [ 6 ] = rtB . lcvceh3hv3 [ 1 ] ; fnycyg1v5p [ 7 ] = rtB .
i3r4txwmvn [ 0 ] ; fnycyg1v5p [ 8 ] = rtP . Constant_Value_aav3mecjn5 ; for (
i_p = 0 ; i_p < 3 ; i_p ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { rtB .
jnibcpqu24 [ i_p + 3 * i ] = 0.0 ; rtB . jnibcpqu24 [ i_p + 3 * i ] += rtB .
cz1nz0dwmw [ 3 * i ] * fnycyg1v5p [ i_p ] ; rtB . jnibcpqu24 [ i_p + 3 * i ]
+= rtB . cz1nz0dwmw [ 3 * i + 1 ] * fnycyg1v5p [ i_p + 3 ] ; rtB . jnibcpqu24
[ i_p + 3 * i ] += rtB . cz1nz0dwmw [ 3 * i + 2 ] * fnycyg1v5p [ i_p + 6 ] ;
} } } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { if ( rtDW . le5srsw3mq != 0 ) {
for ( i = 0 ; i < 18 ; i ++ ) { rtDW . gj2ukru0nb [ i ] = 0.0 ; rtB .
j3qp0rot4z [ i ] = rtDW . gj2ukru0nb [ i ] ; } } else { for ( i = 0 ; i < 18
; i ++ ) { rtB . j3qp0rot4z [ i ] = rtP .
DiscreteTimeIntegrator_gainval_nlfnzii0in * rtB . jnibcpqu24 [ i ] + rtDW .
gj2ukru0nb [ i ] ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( i = 0 ;
i < 18 ; i ++ ) { rtB . afjv1quvm5 [ i ] = rtB . cz1nz0dwmw [ i ] + rtB .
j3qp0rot4z [ i ] ; } } rtB . bv5rymkkje [ 0 ] = rtP .
Constant_Value_drjehzq42h ; kpgrz5rhip_idx = ( ( rtB . j2s0rzuesy [ 0 ] * rtB
. j2s0rzuesy [ 0 ] + rtB . j2s0rzuesy [ 1 ] * rtB . j2s0rzuesy [ 1 ] ) + rtB
. j2s0rzuesy [ 2 ] * rtB . j2s0rzuesy [ 2 ] ) + rtB . j2s0rzuesy [ 3 ] * rtB
. j2s0rzuesy [ 3 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
oxif3bzbeo != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . oxif3bzbeo = 0 ; }
kpgrz5rhip_idx = muDoubleScalarSqrt ( kpgrz5rhip_idx ) ; } else { if (
kpgrz5rhip_idx < 0.0 ) { kpgrz5rhip_idx = - muDoubleScalarSqrt (
muDoubleScalarAbs ( kpgrz5rhip_idx ) ) ; } else { kpgrz5rhip_idx =
muDoubleScalarSqrt ( kpgrz5rhip_idx ) ; } rtDW . oxif3bzbeo = 1 ; }
mkoj55axg1 = rtB . j2s0rzuesy [ 1 ] / kpgrz5rhip_idx ; emposknhj1 = rtB .
j2s0rzuesy [ 3 ] / kpgrz5rhip_idx ; enzyytwikn = rtB . j2s0rzuesy [ 0 ] /
kpgrz5rhip_idx ; kpgrz5rhip_idx = rtB . j2s0rzuesy [ 2 ] / kpgrz5rhip_idx ;
hu2gcgsgxf = ( ( mkoj55axg1 * emposknhj1 + enzyytwikn * kpgrz5rhip_idx ) *
rtP . Gain_Gain_jl2l3kvkt1 * rtP . Constant_Value_ba4yjgwi4a [ 0 ] + (
kpgrz5rhip_idx * emposknhj1 - enzyytwikn * mkoj55axg1 ) * rtP .
Gain1_Gain_mxggrkn41e * rtP . Constant_Value_ba4yjgwi4a [ 1 ] ) + ( ( rtP .
Constant_Value_me5yv0jtlt - mkoj55axg1 * mkoj55axg1 ) - kpgrz5rhip_idx *
kpgrz5rhip_idx ) * rtP . Gain2_Gain_fvc01em23y * rtP .
Constant_Value_ba4yjgwi4a [ 2 ] ; rtB . bv5rymkkje [ 1 ] = hu2gcgsgxf ;
aif0nk4dcs = ( ( ( rtP . Constant_Value_bs5xuxpbbf - kpgrz5rhip_idx *
kpgrz5rhip_idx ) - emposknhj1 * emposknhj1 ) * rtP . Gain2_Gain_ftpblpfslm *
rtP . Constant_Value_ba4yjgwi4a [ 0 ] + ( mkoj55axg1 * kpgrz5rhip_idx +
enzyytwikn * emposknhj1 ) * rtP . Gain_Gain_hxfbfej4zq * rtP .
Constant_Value_ba4yjgwi4a [ 1 ] ) + ( mkoj55axg1 * emposknhj1 - enzyytwikn *
kpgrz5rhip_idx ) * rtP . Gain1_Gain_aw0t0ojudt * rtP .
Constant_Value_ba4yjgwi4a [ 2 ] ; kpgrz5rhip_idx = ( ( ( rtP .
Constant_Value_lb5gk2wltw - mkoj55axg1 * mkoj55axg1 ) - emposknhj1 *
emposknhj1 ) * rtP . Gain2_Gain_cdkrn1kfio * rtP . Constant_Value_ba4yjgwi4a
[ 1 ] + ( mkoj55axg1 * kpgrz5rhip_idx - enzyytwikn * emposknhj1 ) * rtP .
Gain_Gain_arguqsa2xk * rtP . Constant_Value_ba4yjgwi4a [ 0 ] ) + ( enzyytwikn
* mkoj55axg1 + kpgrz5rhip_idx * emposknhj1 ) * rtP . Gain1_Gain_mwe5i1fuoh *
rtP . Constant_Value_ba4yjgwi4a [ 2 ] ; rtB . bv5rymkkje [ 2 ] = rtP .
Gain_Gain_oi1dmjf42c * kpgrz5rhip_idx ; rtB . bv5rymkkje [ 3 ] = rtP .
Gain_Gain_oi1dmjf42c * hu2gcgsgxf ; rtB . bv5rymkkje [ 4 ] = rtP .
Constant_Value_drjehzq42h ; rtB . bv5rymkkje [ 5 ] = aif0nk4dcs ; rtB .
bv5rymkkje [ 6 ] = kpgrz5rhip_idx ; rtB . bv5rymkkje [ 7 ] = rtP .
Gain_Gain_oi1dmjf42c * aif0nk4dcs ; rtB . bv5rymkkje [ 8 ] = rtP .
Constant_Value_drjehzq42h ; if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { for ( i =
0 ; i < 9 ; i ++ ) { if ( rtDW . hfkomryudx != 0 ) { rtB . afjv1quvm5 [ i +
18 ] = rtDW . jbnlmtknpk [ i ] ; } else { rtB . afjv1quvm5 [ i + 18 ] = rtP .
DiscreteTimeIntegrator1_gainval_lb44ya5e4p * rtB . bv5rymkkje [ i ] + rtDW .
jbnlmtknpk [ i ] ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { memcpy ( &
d2tx5zonyh [ 0 ] , & rtB . afjv1quvm5 [ 0 ] , 27U * sizeof ( real_T ) ) ; i =
MWDSP_SVD_D ( & d2tx5zonyh [ 0U ] , 3 , 9 , & nemx5em4o [ 0U ] , & k0cv2hfydh
[ 0U ] , & im2l3qmlta [ 0U ] , & agjzcrqgsk [ 0U ] , & mc04dsskwn [ 0U ] , 1
) ; if ( i == 0 ) { MWDSPCG_Pseudoinverse_D ( & nemx5em4o [ 0U ] , &
agjzcrqgsk [ 0U ] , & mc04dsskwn [ 0U ] , & rtB . kizx1ijhue [ 0U ] , 3 , 9 )
; } } rtB . nif420hiph [ 0 ] = rtB . lcvceh3hv3 [ 1 ] * lzn15zslbh [ 2 ] -
rtB . lcvceh3hv3 [ 2 ] * lzn15zslbh [ 1 ] ; rtB . nif420hiph [ 1 ] = rtB .
lcvceh3hv3 [ 2 ] * lzn15zslbh [ 0 ] - rtB . lcvceh3hv3 [ 0 ] * lzn15zslbh [ 2
] ; rtB . nif420hiph [ 2 ] = rtB . lcvceh3hv3 [ 0 ] * lzn15zslbh [ 1 ] - rtB
. lcvceh3hv3 [ 1 ] * lzn15zslbh [ 0 ] ; if ( ssIsSampleHit ( rtS , 5 , 0 ) )
{ if ( rtDW . oslrfkshxj != 0 ) { rtB . d2ywubqjk2 [ 0 ] = rtDW . olom3dwhnc
[ 0 ] ; rtB . d2ywubqjk2 [ 1 ] = rtDW . olom3dwhnc [ 1 ] ; rtB . d2ywubqjk2 [
2 ] = rtDW . olom3dwhnc [ 2 ] ; } else { rtB . d2ywubqjk2 [ 0 ] = rtP .
DiscreteTimeIntegrator2_gainval_pfnmbeyr34 * rtB . nif420hiph [ 0 ] + rtDW .
olom3dwhnc [ 0 ] ; rtB . d2ywubqjk2 [ 1 ] = rtP .
DiscreteTimeIntegrator2_gainval_pfnmbeyr34 * rtB . nif420hiph [ 1 ] + rtDW .
olom3dwhnc [ 1 ] ; rtB . d2ywubqjk2 [ 2 ] = rtP .
DiscreteTimeIntegrator2_gainval_pfnmbeyr34 * rtB . nif420hiph [ 2 ] + rtDW .
olom3dwhnc [ 2 ] ; } } lzn15zslbh [ 0 ] = ( 0.0 - lzn15zslbh [ 0 ] ) - rtB .
d2ywubqjk2 [ 0 ] ; lzn15zslbh [ 1 ] = ( 0.0 - lzn15zslbh [ 1 ] ) - rtB .
d2ywubqjk2 [ 1 ] ; lzn15zslbh [ 2 ] = ( 0.0 - lzn15zslbh [ 2 ] ) - rtB .
d2ywubqjk2 [ 2 ] ; for ( i_p = 0 ; i_p < 9 ; i_p ++ ) { c5vurnmczn [ i_p ] =
rtB . kizx1ijhue [ i_p + 18 ] * lzn15zslbh [ 2 ] + ( rtB . kizx1ijhue [ i_p +
9 ] * lzn15zslbh [ 1 ] + rtB . kizx1ijhue [ i_p ] * lzn15zslbh [ 0 ] ) ; }
evh2fnt51m [ 0 ] = c5vurnmczn [ 0 ] ; evh2fnt51m [ 1 ] = c5vurnmczn [ 3 ] ;
evh2fnt51m [ 2 ] = c5vurnmczn [ 4 ] ; evh2fnt51m [ 3 ] = c5vurnmczn [ 3 ] ;
evh2fnt51m [ 4 ] = c5vurnmczn [ 1 ] ; evh2fnt51m [ 5 ] = c5vurnmczn [ 5 ] ;
evh2fnt51m [ 6 ] = c5vurnmczn [ 4 ] ; evh2fnt51m [ 7 ] = c5vurnmczn [ 5 ] ;
evh2fnt51m [ 8 ] = c5vurnmczn [ 2 ] ; memcpy ( & rtB . gzh1neeoux [ 0 ] , &
evh2fnt51m [ 0 ] , 9U * sizeof ( real_T ) ) ; rtB . auwd4r4mkz [ 0 ] =
c5vurnmczn [ 6 ] / rtP . Constant3_Value_ozgyx12s5q ; rtB . auwd4r4mkz [ 1 ]
= c5vurnmczn [ 7 ] / rtP . Constant3_Value_ozgyx12s5q ; rtB . auwd4r4mkz [ 2
] = c5vurnmczn [ 8 ] / rtP . Constant3_Value_ozgyx12s5q ; if ( ssGetLogOutput
( rtS ) ) { { { void * signalProbe = ( void * ) rtDW . mohxnwpvy0k .
SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0 ) ; u = (
void * ) & rtB . j2s0rzuesy [ 0 ] ; rtwSignalProbeAppendSample ( signalProbe
, t , u ) ; } } } if ( ssGetLogOutput ( rtS ) ) { { { void * signalProbe = (
void * ) rtDW . fs3xofbgsah . SignalProbe ; real_T t ; void * u ; t =
ssGetTaskTime ( rtS , 0 ) ; u = ( void * ) & rtB . cy0g41je3i [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . aekk1bjgtl = ( rtB . enst2mfa5p [ 0 ] >=
rtP . Switch_Threshold_ih32etj225 ) ; } kpgrz5rhip_idx = ( rtP .
Constant_Value_hbjvgrrmsz - ( ( ( rtB . enst2mfa5p [ 0 ] * rtB . enst2mfa5p [
0 ] + rtB . enst2mfa5p [ 1 ] * rtB . enst2mfa5p [ 1 ] ) + rtB . enst2mfa5p [
2 ] * rtB . enst2mfa5p [ 2 ] ) + rtB . enst2mfa5p [ 3 ] * rtB . enst2mfa5p [
3 ] ) ) * rtP . HighGainQuaternionNormalization_Gain_nnwvygfxro ; rtB .
ckqhlb32gd = ( ( rtB . enst2mfa5p [ 1 ] * rtB . lcvceh3hv3 [ 0 ] + rtB .
enst2mfa5p [ 2 ] * rtB . lcvceh3hv3 [ 1 ] ) + rtB . enst2mfa5p [ 3 ] * rtB .
lcvceh3hv3 [ 2 ] ) * - 0.5 + kpgrz5rhip_idx * rtB . enst2mfa5p [ 0 ] ; rtB .
leq1llgjf0 = ( ( rtB . enst2mfa5p [ 0 ] * rtB . lcvceh3hv3 [ 0 ] + rtB .
enst2mfa5p [ 2 ] * rtB . lcvceh3hv3 [ 2 ] ) - rtB . enst2mfa5p [ 3 ] * rtB .
lcvceh3hv3 [ 1 ] ) * 0.5 + kpgrz5rhip_idx * rtB . enst2mfa5p [ 1 ] ; rtB .
jmzzln4ohz = ( ( rtB . enst2mfa5p [ 0 ] * rtB . lcvceh3hv3 [ 1 ] + rtB .
enst2mfa5p [ 3 ] * rtB . lcvceh3hv3 [ 0 ] ) - rtB . enst2mfa5p [ 1 ] * rtB .
lcvceh3hv3 [ 2 ] ) * 0.5 + kpgrz5rhip_idx * rtB . enst2mfa5p [ 2 ] ; rtB .
htxixjme3q = ( ( rtB . enst2mfa5p [ 0 ] * rtB . lcvceh3hv3 [ 2 ] + rtB .
enst2mfa5p [ 1 ] * rtB . lcvceh3hv3 [ 1 ] ) - rtB . enst2mfa5p [ 2 ] * rtB .
lcvceh3hv3 [ 0 ] ) * 0.5 + kpgrz5rhip_idx * rtB . enst2mfa5p [ 3 ] ;
i3lhpgmarw [ 0 ] = rtP . Constant3_Value_owr20rawcp ; i3lhpgmarw [ 1 ] = rtB
. j2s0rzuesy [ 3 ] ; i3lhpgmarw [ 2 ] = rtP . Gain8_Gain_hmjcxkynt4 * rtB .
j2s0rzuesy [ 2 ] ; i3lhpgmarw [ 3 ] = rtP . Gain6_Gain_h3125rb23e * rtB .
j2s0rzuesy [ 3 ] ; i3lhpgmarw [ 4 ] = rtP . Constant3_Value_owr20rawcp ;
i3lhpgmarw [ 5 ] = rtB . j2s0rzuesy [ 1 ] ; i3lhpgmarw [ 6 ] = rtB .
j2s0rzuesy [ 2 ] ; i3lhpgmarw [ 7 ] = rtP . Gain7_Gain_gmfxftd3mb * rtB .
j2s0rzuesy [ 1 ] ; i3lhpgmarw [ 8 ] = rtP . Constant3_Value_owr20rawcp ; for
( i = 0 ; i < 9 ; i ++ ) { rtB . becyljpaab [ i ] = i3lhpgmarw [ i ] ;
m2b1vgca5s [ i ] = rtB . becyljpaab [ i ] ; } LUf_int32_Treal_T ( m2b1vgca5s
, lzn15zslbh , 3 ) ; for ( i = 0 ; i < 3 ; i ++ ) { k = ( int32_T )
muDoubleScalarFloor ( lzn15zslbh [ i ] ) - 1 ; if ( k < 0 ) { k = 0 ; } else
{ if ( k >= 3 ) { k = 2 ; } } nvadtslxwe [ i ] = rtB . mzppckyb2r [ k ] ;
nvadtslxwe [ 3 + i ] = rtB . mzppckyb2r [ 3 + k ] ; nvadtslxwe [ 6 + i ] =
rtB . mzppckyb2r [ 6 + k ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { idxout =
i_p * 3 ; i = 1 ; idxB = idxout + 1 ; nfwwjxsmuk = nvadtslxwe [ idxB ] ; k =
0 ; while ( k < 1 ) { nfwwjxsmuk -= m2b1vgca5s [ i ] * nvadtslxwe [ idxout ]
; i += 3 ; k = 1 ; } nvadtslxwe [ idxB ] = nfwwjxsmuk ; i = 2 ; idxB = idxout
+ 2 ; nfwwjxsmuk = nvadtslxwe [ idxB ] ; for ( k = 0 ; k < 2 ; k ++ ) {
nfwwjxsmuk -= nvadtslxwe [ idxout + k ] * m2b1vgca5s [ i ] ; i += 3 ; }
nvadtslxwe [ idxB ] = nfwwjxsmuk ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
idxout = i_p * 3 ; i = idxout + 2 ; rtB . kbnlvlyzzj [ i ] = nvadtslxwe [ i ]
/ m2b1vgca5s [ 8 ] ; i = 7 ; idxB = idxout + 1 ; nfwwjxsmuk = nvadtslxwe [
idxB ] ; k = 2 ; while ( k > 1 ) { nfwwjxsmuk -= rtB . kbnlvlyzzj [ idxout +
2 ] * m2b1vgca5s [ i ] ; i -= 3 ; k = 1 ; } rtB . kbnlvlyzzj [ idxB ] =
nfwwjxsmuk / m2b1vgca5s [ i ] ; i = 6 ; nfwwjxsmuk = nvadtslxwe [ idxout ] ;
for ( k = 2 ; k > 0 ; k -- ) { nfwwjxsmuk -= rtB . kbnlvlyzzj [ idxout + k ]
* m2b1vgca5s [ i ] ; i -= 3 ; } rtB . kbnlvlyzzj [ idxout ] = nfwwjxsmuk /
m2b1vgca5s [ i ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . b5lvehq0lb [
i_p ] = 0.0 ; rtB . b5lvehq0lb [ i_p ] += rtB . kbnlvlyzzj [ i_p ] * rtB .
cy0g41je3i [ 0 ] ; rtB . b5lvehq0lb [ i_p ] += rtB . kbnlvlyzzj [ i_p + 3 ] *
rtB . cy0g41je3i [ 1 ] ; rtB . b5lvehq0lb [ i_p ] += rtB . kbnlvlyzzj [ i_p +
6 ] * rtB . cy0g41je3i [ 2 ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
lssfrykd20 = rtP . Gain5_Gain_bz0vauxshy * rtP . a_Value_f5j011wiug ; } rtB .
c1g3rp4u4f [ 0 ] = ( rtB . cy0g41je3i [ 0 ] - rtP . a_Value_f5j011wiug * rtB
. j2s0rzuesy [ 1 ] ) * rtB . lssfrykd20 ; rtB . c1g3rp4u4f [ 1 ] = ( rtB .
cy0g41je3i [ 1 ] - rtP . a_Value_f5j011wiug * rtB . j2s0rzuesy [ 2 ] ) * rtB
. lssfrykd20 ; rtB . c1g3rp4u4f [ 2 ] = ( rtB . cy0g41je3i [ 2 ] - rtP .
a_Value_f5j011wiug * rtB . j2s0rzuesy [ 3 ] ) * rtB . lssfrykd20 ; lzn15zslbh
[ 0 ] = nsjhwaxccv . vj2000 [ 0 ] ; lzn15zslbh [ 1 ] = nsjhwaxccv . vj2000 [
1 ] ; lzn15zslbh [ 2 ] = nsjhwaxccv . vj2000 [ 2 ] ; rtB . iezlupw440 [ 0 ] =
nsjhwaxccv . j2000 [ 0 ] ; rtB . iezlupw440 [ 1 ] = nsjhwaxccv . j2000 [ 1 ]
; rtB . iezlupw440 [ 2 ] = nsjhwaxccv . j2000 [ 2 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtB . flsiozqty3 = rtP . Gain_Gain_aa0vtk0zmd * rtP .
Constant_Value_k0wcldte3h ; } nfwwjxsmuk = rtB . hfr3g5fo5z [ 0 ] * rtB .
hfr3g5fo5z [ 0 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { i2qc4thdsu [ 0 ] =
rtP . Constant_Value_hwvscamm31 ; i2qc4thdsu [ 1 ] = rtP .
Constant2_Value_c3n5xbbf35 [ 2 ] ; i2qc4thdsu [ 2 ] = rtP .
Gain_Gain_ojc15iu5jd * rtP . Constant2_Value_c3n5xbbf35 [ 1 ] ; i2qc4thdsu [
3 ] = rtP . Gain_Gain_ojc15iu5jd * rtP . Constant2_Value_c3n5xbbf35 [ 2 ] ;
i2qc4thdsu [ 4 ] = rtP . Constant_Value_hwvscamm31 ; i2qc4thdsu [ 5 ] = rtP .
Constant2_Value_c3n5xbbf35 [ 0 ] ; i2qc4thdsu [ 6 ] = rtP .
Constant2_Value_c3n5xbbf35 [ 1 ] ; i2qc4thdsu [ 7 ] = rtP .
Gain_Gain_ojc15iu5jd * rtP . Constant2_Value_c3n5xbbf35 [ 0 ] ; i2qc4thdsu [
8 ] = rtP . Constant_Value_hwvscamm31 ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . oras35y0me [ i_p + 3 * i ] = 0.0 ; rtB .
oras35y0me [ i_p + 3 * i ] += i2qc4thdsu [ 3 * i ] * i2qc4thdsu [ i_p ] ; rtB
. oras35y0me [ i_p + 3 * i ] += i2qc4thdsu [ 3 * i + 1 ] * i2qc4thdsu [ i_p +
3 ] ; rtB . oras35y0me [ i_p + 3 * i ] += i2qc4thdsu [ 3 * i + 2 ] *
i2qc4thdsu [ i_p + 6 ] ; } } i241sj2ime [ 0 ] = rtP .
Constant_Value_c2kug4uglk ; i241sj2ime [ 1 ] = rtP .
Constant5_Value_gn0gckpuzn [ 2 ] ; i241sj2ime [ 2 ] = rtP .
Gain_Gain_kqt10qghkc * rtP . Constant5_Value_gn0gckpuzn [ 1 ] ; i241sj2ime [
3 ] = rtP . Gain_Gain_kqt10qghkc * rtP . Constant5_Value_gn0gckpuzn [ 2 ] ;
i241sj2ime [ 4 ] = rtP . Constant_Value_c2kug4uglk ; i241sj2ime [ 5 ] = rtP .
Constant5_Value_gn0gckpuzn [ 0 ] ; i241sj2ime [ 6 ] = rtP .
Constant5_Value_gn0gckpuzn [ 1 ] ; i241sj2ime [ 7 ] = rtP .
Gain_Gain_kqt10qghkc * rtP . Constant5_Value_gn0gckpuzn [ 0 ] ; i241sj2ime [
8 ] = rtP . Constant_Value_c2kug4uglk ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . jczx5mmtny [ i_p + 3 * i ] = 0.0 ; rtB .
jczx5mmtny [ i_p + 3 * i ] += i241sj2ime [ 3 * i ] * i2qc4thdsu [ i_p ] ; rtB
. jczx5mmtny [ i_p + 3 * i ] += i241sj2ime [ 3 * i + 1 ] * i2qc4thdsu [ i_p +
3 ] ; rtB . jczx5mmtny [ i_p + 3 * i ] += i241sj2ime [ 3 * i + 2 ] *
i2qc4thdsu [ i_p + 6 ] ; } } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { for ( i = 0
; i < 3 ; i ++ ) { rtB . py34oc2tac [ i_p + 3 * i ] = 0.0 ; rtB . py34oc2tac
[ i_p + 3 * i ] += i2qc4thdsu [ 3 * i ] * i241sj2ime [ i_p ] ; rtB .
py34oc2tac [ i_p + 3 * i ] += i2qc4thdsu [ 3 * i + 1 ] * i241sj2ime [ i_p + 3
] ; rtB . py34oc2tac [ i_p + 3 * i ] += i2qc4thdsu [ 3 * i + 2 ] * i241sj2ime
[ i_p + 6 ] ; } } rtB . ldef0mrlxf = rtP . Gain_Gain_jjixz4kmpu * rtP .
Constant_Value_pxpcd5bk3c ; } enzyytwikn = rtB . hfr3g5fo5z [ 1 ] * rtB .
hfr3g5fo5z [ 1 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { iy3cnrq0gy [ 0 ] =
rtP . Constant_Value_kvybbzfnrt ; iy3cnrq0gy [ 1 ] = rtP .
Constant3_Value_a5rnl3iohi [ 2 ] ; iy3cnrq0gy [ 2 ] = rtP .
Gain_Gain_nb04rhjuqe * rtP . Constant3_Value_a5rnl3iohi [ 1 ] ; iy3cnrq0gy [
3 ] = rtP . Gain_Gain_nb04rhjuqe * rtP . Constant3_Value_a5rnl3iohi [ 2 ] ;
iy3cnrq0gy [ 4 ] = rtP . Constant_Value_kvybbzfnrt ; iy3cnrq0gy [ 5 ] = rtP .
Constant3_Value_a5rnl3iohi [ 0 ] ; iy3cnrq0gy [ 6 ] = rtP .
Constant3_Value_a5rnl3iohi [ 1 ] ; iy3cnrq0gy [ 7 ] = rtP .
Gain_Gain_nb04rhjuqe * rtP . Constant3_Value_a5rnl3iohi [ 0 ] ; iy3cnrq0gy [
8 ] = rtP . Constant_Value_kvybbzfnrt ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . fqa1obuxcx [ i_p + 3 * i ] = 0.0 ; rtB .
fqa1obuxcx [ i_p + 3 * i ] += iy3cnrq0gy [ 3 * i ] * iy3cnrq0gy [ i_p ] ; rtB
. fqa1obuxcx [ i_p + 3 * i ] += iy3cnrq0gy [ 3 * i + 1 ] * iy3cnrq0gy [ i_p +
3 ] ; rtB . fqa1obuxcx [ i_p + 3 * i ] += iy3cnrq0gy [ 3 * i + 2 ] *
iy3cnrq0gy [ i_p + 6 ] ; } } esdznxyznf [ 0 ] = rtP .
Constant_Value_aawk2y00ma ; esdznxyznf [ 1 ] = rtP .
Constant6_Value_fhjuxteqna [ 2 ] ; esdznxyznf [ 2 ] = rtP .
Gain_Gain_fazvlmdyvx * rtP . Constant6_Value_fhjuxteqna [ 1 ] ; esdznxyznf [
3 ] = rtP . Gain_Gain_fazvlmdyvx * rtP . Constant6_Value_fhjuxteqna [ 2 ] ;
esdznxyznf [ 4 ] = rtP . Constant_Value_aawk2y00ma ; esdznxyznf [ 5 ] = rtP .
Constant6_Value_fhjuxteqna [ 0 ] ; esdznxyznf [ 6 ] = rtP .
Constant6_Value_fhjuxteqna [ 1 ] ; esdznxyznf [ 7 ] = rtP .
Gain_Gain_fazvlmdyvx * rtP . Constant6_Value_fhjuxteqna [ 0 ] ; esdznxyznf [
8 ] = rtP . Constant_Value_aawk2y00ma ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . jp33z3cm2q [ i_p + 3 * i ] = 0.0 ; rtB .
jp33z3cm2q [ i_p + 3 * i ] += esdznxyznf [ 3 * i ] * iy3cnrq0gy [ i_p ] ; rtB
. jp33z3cm2q [ i_p + 3 * i ] += esdznxyznf [ 3 * i + 1 ] * iy3cnrq0gy [ i_p +
3 ] ; rtB . jp33z3cm2q [ i_p + 3 * i ] += esdznxyznf [ 3 * i + 2 ] *
iy3cnrq0gy [ i_p + 6 ] ; } } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { for ( i = 0
; i < 3 ; i ++ ) { rtB . lna01hcwqs [ i_p + 3 * i ] = 0.0 ; rtB . lna01hcwqs
[ i_p + 3 * i ] += iy3cnrq0gy [ 3 * i ] * esdznxyznf [ i_p ] ; rtB .
lna01hcwqs [ i_p + 3 * i ] += iy3cnrq0gy [ 3 * i + 1 ] * esdznxyznf [ i_p + 3
] ; rtB . lna01hcwqs [ i_p + 3 * i ] += iy3cnrq0gy [ 3 * i + 2 ] * esdznxyznf
[ i_p + 6 ] ; } } rtB . af0aib4ixg = rtP . Gain_Gain_anyjlb3pu0 * rtP .
Constant_Value_kpvlwz5g2c ; } hu2gcgsgxf = rtB . hfr3g5fo5z [ 2 ] * rtB .
hfr3g5fo5z [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { dankg43h1a [ 0 ] =
rtP . Constant_Value_amfkvbii2o ; dankg43h1a [ 1 ] = rtP .
Constant4_Value_ohaes1tek1 [ 2 ] ; dankg43h1a [ 2 ] = rtP .
Gain_Gain_nqjty0rsxr * rtP . Constant4_Value_ohaes1tek1 [ 1 ] ; dankg43h1a [
3 ] = rtP . Gain_Gain_nqjty0rsxr * rtP . Constant4_Value_ohaes1tek1 [ 2 ] ;
dankg43h1a [ 4 ] = rtP . Constant_Value_amfkvbii2o ; dankg43h1a [ 5 ] = rtP .
Constant4_Value_ohaes1tek1 [ 0 ] ; dankg43h1a [ 6 ] = rtP .
Constant4_Value_ohaes1tek1 [ 1 ] ; dankg43h1a [ 7 ] = rtP .
Gain_Gain_nqjty0rsxr * rtP . Constant4_Value_ohaes1tek1 [ 0 ] ; dankg43h1a [
8 ] = rtP . Constant_Value_amfkvbii2o ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . artk3v2gtx [ i_p + 3 * i ] = 0.0 ; rtB .
artk3v2gtx [ i_p + 3 * i ] += dankg43h1a [ 3 * i ] * dankg43h1a [ i_p ] ; rtB
. artk3v2gtx [ i_p + 3 * i ] += dankg43h1a [ 3 * i + 1 ] * dankg43h1a [ i_p +
3 ] ; rtB . artk3v2gtx [ i_p + 3 * i ] += dankg43h1a [ 3 * i + 2 ] *
dankg43h1a [ i_p + 6 ] ; } } miibb21mr5 [ 0 ] = rtP .
Constant_Value_ebfrcaxa1u ; miibb21mr5 [ 1 ] = rtP .
Constant7_Value_ihkbrtwf0t [ 2 ] ; miibb21mr5 [ 2 ] = rtP .
Gain_Gain_ldb0s3bi33 * rtP . Constant7_Value_ihkbrtwf0t [ 1 ] ; miibb21mr5 [
3 ] = rtP . Gain_Gain_ldb0s3bi33 * rtP . Constant7_Value_ihkbrtwf0t [ 2 ] ;
miibb21mr5 [ 4 ] = rtP . Constant_Value_ebfrcaxa1u ; miibb21mr5 [ 5 ] = rtP .
Constant7_Value_ihkbrtwf0t [ 0 ] ; miibb21mr5 [ 6 ] = rtP .
Constant7_Value_ihkbrtwf0t [ 1 ] ; miibb21mr5 [ 7 ] = rtP .
Gain_Gain_ldb0s3bi33 * rtP . Constant7_Value_ihkbrtwf0t [ 0 ] ; miibb21mr5 [
8 ] = rtP . Constant_Value_ebfrcaxa1u ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
for ( i = 0 ; i < 3 ; i ++ ) { rtB . fylvlnipqh [ i_p + 3 * i ] = 0.0 ; rtB .
fylvlnipqh [ i_p + 3 * i ] += miibb21mr5 [ 3 * i ] * dankg43h1a [ i_p ] ; rtB
. fylvlnipqh [ i_p + 3 * i ] += miibb21mr5 [ 3 * i + 1 ] * dankg43h1a [ i_p +
3 ] ; rtB . fylvlnipqh [ i_p + 3 * i ] += miibb21mr5 [ 3 * i + 2 ] *
dankg43h1a [ i_p + 6 ] ; } } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { for ( i = 0
; i < 3 ; i ++ ) { rtB . dnccwxtqix [ i_p + 3 * i ] = 0.0 ; rtB . dnccwxtqix
[ i_p + 3 * i ] += dankg43h1a [ 3 * i ] * miibb21mr5 [ i_p ] ; rtB .
dnccwxtqix [ i_p + 3 * i ] += dankg43h1a [ 3 * i + 1 ] * miibb21mr5 [ i_p + 3
] ; rtB . dnccwxtqix [ i_p + 3 * i ] += dankg43h1a [ 3 * i + 2 ] * miibb21mr5
[ i_p + 6 ] ; } } } for ( i = 0 ; i < 9 ; i ++ ) { m2b1vgca5s [ i ] = ( ( ( (
nfwwjxsmuk * rtB . oras35y0me [ i ] + rtB . hfr3g5fo5z [ 0 ] * rtB .
jczx5mmtny [ i ] ) + rtB . hfr3g5fo5z [ 0 ] * rtB . py34oc2tac [ i ] ) * rtB
. flsiozqty3 + rtP . Constant1_Value_hao4x44ah2 [ i ] ) + ( ( enzyytwikn *
rtB . fqa1obuxcx [ i ] + rtB . hfr3g5fo5z [ 1 ] * rtB . jp33z3cm2q [ i ] ) +
rtB . hfr3g5fo5z [ 1 ] * rtB . lna01hcwqs [ i ] ) * rtB . ldef0mrlxf ) + ( (
hu2gcgsgxf * rtB . artk3v2gtx [ i ] + rtB . hfr3g5fo5z [ 2 ] * rtB .
fylvlnipqh [ i ] ) + rtB . hfr3g5fo5z [ 2 ] * rtB . dnccwxtqix [ i ] ) * rtB
. af0aib4ixg ; } kpgrz5rhip_idx = ( rtB . iezlupw440 [ 0 ] * rtB . iezlupw440
[ 0 ] + rtB . iezlupw440 [ 1 ] * rtB . iezlupw440 [ 1 ] ) + rtB . iezlupw440
[ 2 ] * rtB . iezlupw440 [ 2 ] ; if ( kpgrz5rhip_idx < 0.0 ) { rtB .
a5hluyc4z4 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( kpgrz5rhip_idx ) ) ;
} else { rtB . a5hluyc4z4 = muDoubleScalarSqrt ( kpgrz5rhip_idx ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . jmvufartxc = ( rtB . a5hluyc4z4 > rtP .
Switch_Threshold_oksbac2myv ) ; } if ( rtDW . jmvufartxc ) { kpgrz5rhip_idx =
rtB . iezlupw440 [ 0 ] ; kpgrz5rhip_idx_e = rtB . iezlupw440 [ 1 ] ;
kpgrz5rhip_idx_i = rtB . iezlupw440 [ 2 ] ; kpgrz5rhip_idx_p = rtB .
a5hluyc4z4 ; } else { rtB . fc4jnd0tfk [ 0 ] = rtB . iezlupw440 [ 0 ] * 0.0 ;
rtB . fc4jnd0tfk [ 1 ] = rtB . iezlupw440 [ 1 ] * 0.0 ; rtB . fc4jnd0tfk [ 2
] = rtB . iezlupw440 [ 2 ] * 0.0 ; kpgrz5rhip_idx = rtB . fc4jnd0tfk [ 0 ] ;
kpgrz5rhip_idx_e = rtB . fc4jnd0tfk [ 1 ] ; kpgrz5rhip_idx_i = rtB .
fc4jnd0tfk [ 2 ] ; kpgrz5rhip_idx_p = rtP . Constant_Value_epdybnohto ; }
dwafzsky2m [ 0 ] = kpgrz5rhip_idx / kpgrz5rhip_idx_p ; dwafzsky2m [ 1 ] =
kpgrz5rhip_idx_e / kpgrz5rhip_idx_p ; dwafzsky2m [ 2 ] = kpgrz5rhip_idx_i /
kpgrz5rhip_idx_p ; rtB . keil2t0ysq [ 3 ] = dwafzsky2m [ 0 ] ; rtB .
keil2t0ysq [ 4 ] = dwafzsky2m [ 1 ] ; rtB . keil2t0ysq [ 5 ] = dwafzsky2m [ 2
] ; rtB . po2fokcy2h [ 0 ] = lzn15zslbh [ 1 ] * rtB . iezlupw440 [ 2 ] -
lzn15zslbh [ 2 ] * rtB . iezlupw440 [ 1 ] ; rtB . po2fokcy2h [ 1 ] =
lzn15zslbh [ 2 ] * rtB . iezlupw440 [ 0 ] - lzn15zslbh [ 0 ] * rtB .
iezlupw440 [ 2 ] ; rtB . po2fokcy2h [ 2 ] = lzn15zslbh [ 0 ] * rtB .
iezlupw440 [ 1 ] - lzn15zslbh [ 1 ] * rtB . iezlupw440 [ 0 ] ; kpgrz5rhip_idx
= ( rtB . po2fokcy2h [ 0 ] * rtB . po2fokcy2h [ 0 ] + rtB . po2fokcy2h [ 1 ]
* rtB . po2fokcy2h [ 1 ] ) + rtB . po2fokcy2h [ 2 ] * rtB . po2fokcy2h [ 2 ]
; if ( kpgrz5rhip_idx < 0.0 ) { rtB . hwft0ux5xv = - muDoubleScalarSqrt (
muDoubleScalarAbs ( kpgrz5rhip_idx ) ) ; } else { rtB . hwft0ux5xv =
muDoubleScalarSqrt ( kpgrz5rhip_idx ) ; } if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . idulg0qqat = ( rtB . hwft0ux5xv > rtP . Switch_Threshold_lodxyjq4uq )
; } if ( rtDW . idulg0qqat ) { kpgrz5rhip_idx = rtB . po2fokcy2h [ 0 ] ;
kpgrz5rhip_idx_e = rtB . po2fokcy2h [ 1 ] ; kpgrz5rhip_idx_i = rtB .
po2fokcy2h [ 2 ] ; kpgrz5rhip_idx_p = rtB . hwft0ux5xv ; } else { rtB .
bkwjtfsi54 [ 0 ] = rtB . po2fokcy2h [ 0 ] * 0.0 ; rtB . bkwjtfsi54 [ 1 ] =
rtB . po2fokcy2h [ 1 ] * 0.0 ; rtB . bkwjtfsi54 [ 2 ] = rtB . po2fokcy2h [ 2
] * 0.0 ; kpgrz5rhip_idx = rtB . bkwjtfsi54 [ 0 ] ; kpgrz5rhip_idx_e = rtB .
bkwjtfsi54 [ 1 ] ; kpgrz5rhip_idx_i = rtB . bkwjtfsi54 [ 2 ] ;
kpgrz5rhip_idx_p = rtP . Constant_Value_eovzc0nuc4 ; } lzn15zslbh [ 0 ] =
kpgrz5rhip_idx / kpgrz5rhip_idx_p ; lzn15zslbh [ 1 ] = kpgrz5rhip_idx_e /
kpgrz5rhip_idx_p ; lzn15zslbh [ 2 ] = kpgrz5rhip_idx_i / kpgrz5rhip_idx_p ;
rtB . keil2t0ysq [ 6 ] = lzn15zslbh [ 0 ] ; rtB . keil2t0ysq [ 7 ] =
lzn15zslbh [ 1 ] ; rtB . keil2t0ysq [ 8 ] = lzn15zslbh [ 2 ] ; rtB .
keil2t0ysq [ 0 ] = dwafzsky2m [ 1 ] * lzn15zslbh [ 2 ] - dwafzsky2m [ 2 ] *
lzn15zslbh [ 1 ] ; rtB . keil2t0ysq [ 1 ] = dwafzsky2m [ 2 ] * lzn15zslbh [ 0
] - dwafzsky2m [ 0 ] * lzn15zslbh [ 2 ] ; rtB . keil2t0ysq [ 2 ] = dwafzsky2m
[ 0 ] * lzn15zslbh [ 1 ] - dwafzsky2m [ 1 ] * lzn15zslbh [ 0 ] ; rtB .
ffoa23fpkv = ( rtB . keil2t0ysq [ 0 ] + rtB . keil2t0ysq [ 4 ] ) + rtB .
keil2t0ysq [ 8 ] ; rtPrevAction = rtDW . lqwl4atrcd ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtB . ffoa23fpkv > 0.0 ) { rtAction = 0 ; } else { rtAction
= 1 ; } rtDW . lqwl4atrcd = rtAction ; } else { rtAction = rtDW . lqwl4atrcd
; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
f3tc5mwqyz ( rtS ) ; break ; case 1 : nws40mclpe ( rtS , & rtDW . jtgflhe3su
) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction
) { fri4zeczvq ( rtS ) ; } p0vdevk3x1 ( rtS , rtB . ffoa23fpkv , rtB .
keil2t0ysq [ 5 ] , rtB . keil2t0ysq [ 7 ] , rtB . keil2t0ysq [ 2 ] , rtB .
keil2t0ysq [ 6 ] , rtB . keil2t0ysq [ 1 ] , rtB . keil2t0ysq [ 3 ] , & rtB .
e2ozyjspf1 [ 0 ] , & rtB . e2ozyjspf1 [ 1 ] , & rtDW . ammeeph1io , (
oj32fzmstd * ) & rtP . ammeeph1io ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . ammeeph1io . espotkwrxj ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { nc5u50jta2 ( rtS ) ; } azz3d4nxce ( rtS , rtB .
keil2t0ysq [ 0 ] , rtB . keil2t0ysq [ 4 ] , rtB . keil2t0ysq [ 8 ] , rtB .
keil2t0ysq [ 1 ] , rtB . keil2t0ysq [ 3 ] , rtB . keil2t0ysq [ 5 ] , rtB .
keil2t0ysq [ 7 ] , rtB . keil2t0ysq [ 2 ] , rtB . keil2t0ysq [ 6 ] , & rtB .
e2ozyjspf1 [ 0 ] , & rtB . e2ozyjspf1 [ 1 ] , & rtB . e2ozyjspf1 [ 2 ] , &
rtB . e2ozyjspf1 [ 3 ] , & rtB . jtgflhe3su , & rtDW . jtgflhe3su , (
a0yd1qizj0 * ) & rtP . jtgflhe3su ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . jtgflhe3su . fw1wxjvjvv ) ; } break ; } rtB . goqp2hsxiw
[ 0 ] = ( ( rtB . lcvceh3hv3 [ 1 ] * rtB . l4ag020lhf [ 2 ] - rtB .
lcvceh3hv3 [ 2 ] * rtB . l4ag020lhf [ 1 ] ) + rtB . knm4o3kbgk [ 0 ] ) * rtP
. Gain_Gain_goqw3vji4e ; rtB . goqp2hsxiw [ 1 ] = ( ( rtB . lcvceh3hv3 [ 2 ]
* rtB . l4ag020lhf [ 0 ] - rtB . lcvceh3hv3 [ 0 ] * rtB . l4ag020lhf [ 2 ] )
+ rtB . knm4o3kbgk [ 1 ] ) * rtP . Gain_Gain_goqw3vji4e ; rtB . goqp2hsxiw [
2 ] = ( ( rtB . lcvceh3hv3 [ 0 ] * rtB . l4ag020lhf [ 1 ] - rtB . lcvceh3hv3
[ 1 ] * rtB . l4ag020lhf [ 0 ] ) + rtB . knm4o3kbgk [ 2 ] ) * rtP .
Gain_Gain_goqw3vji4e ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . jk3cciiee0 [
0 ] = rtB . goqp2hsxiw [ 0 ] >= rtP . Saturation_UpperSat_kq1vntuako ? 1 :
rtB . goqp2hsxiw [ 0 ] > rtP . Saturation_LowerSat_iborwhdlaq ? 0 : - 1 ;
rtDW . jk3cciiee0 [ 1 ] = rtB . goqp2hsxiw [ 1 ] >= rtP .
Saturation_UpperSat_kq1vntuako ? 1 : rtB . goqp2hsxiw [ 1 ] > rtP .
Saturation_LowerSat_iborwhdlaq ? 0 : - 1 ; rtDW . jk3cciiee0 [ 2 ] = rtB .
goqp2hsxiw [ 2 ] >= rtP . Saturation_UpperSat_kq1vntuako ? 1 : rtB .
goqp2hsxiw [ 2 ] > rtP . Saturation_LowerSat_iborwhdlaq ? 0 : - 1 ; } rtB .
h04s5dfqra [ 0 ] = rtDW . jk3cciiee0 [ 0 ] == 1 ? rtP .
Saturation_UpperSat_kq1vntuako : rtDW . jk3cciiee0 [ 0 ] == - 1 ? rtP .
Saturation_LowerSat_iborwhdlaq : rtB . goqp2hsxiw [ 0 ] ; rtB . h04s5dfqra [
1 ] = rtDW . jk3cciiee0 [ 1 ] == 1 ? rtP . Saturation_UpperSat_kq1vntuako :
rtDW . jk3cciiee0 [ 1 ] == - 1 ? rtP . Saturation_LowerSat_iborwhdlaq : rtB .
goqp2hsxiw [ 1 ] ; rtB . h04s5dfqra [ 2 ] = rtDW . jk3cciiee0 [ 2 ] == 1 ?
rtP . Saturation_UpperSat_kq1vntuako : rtDW . jk3cciiee0 [ 2 ] == - 1 ? rtP .
Saturation_LowerSat_iborwhdlaq : rtB . goqp2hsxiw [ 2 ] ; rtB . c2bqn2vvuz [
0 ] = ( ( rtB . h04s5dfqra [ 0 ] + 0.0 ) + 0.0 ) + 0.0 ; rtB . c2bqn2vvuz [ 1
] = ( ( rtB . h04s5dfqra [ 1 ] + 0.0 ) + 0.0 ) + 0.0 ; rtB . c2bqn2vvuz [ 2 ]
= ( ( rtB . h04s5dfqra [ 2 ] + 0.0 ) + 0.0 ) + 0.0 ; for ( i_p = 0 ; i_p < 3
; i_p ++ ) { lzn15zslbh [ i_p ] = 0.0 ; lzn15zslbh [ i_p ] += m2b1vgca5s [
i_p ] * rtB . lcvceh3hv3 [ 0 ] ; lzn15zslbh [ i_p ] += m2b1vgca5s [ i_p + 3 ]
* rtB . lcvceh3hv3 [ 1 ] ; lzn15zslbh [ i_p ] += m2b1vgca5s [ i_p + 6 ] * rtB
. lcvceh3hv3 [ 2 ] ; } aif0nk4dcs = rtB . lcvceh3hv3 [ 2 ] * lzn15zslbh [ 0 ]
; kpgrz5rhip_idx_e = rtB . lcvceh3hv3 [ 0 ] * lzn15zslbh [ 1 ] ;
kpgrz5rhip_idx_p = rtB . lcvceh3hv3 [ 0 ] * lzn15zslbh [ 2 ] ; nfwwjxsmuk =
rtB . lcvceh3hv3 [ 1 ] * lzn15zslbh [ 0 ] ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . f3f3ebtfsq [ i_p ] = 0.0 ;
rtB . f3f3ebtfsq [ i_p ] += rtP . Constant_Value_dx3sborzrl [ i_p ] * rtB .
lcvceh3hv3 [ 0 ] ; rtB . f3f3ebtfsq [ i_p ] += rtP .
Constant_Value_dx3sborzrl [ i_p + 3 ] * rtB . lcvceh3hv3 [ 1 ] ; rtB .
f3f3ebtfsq [ i_p ] += rtP . Constant_Value_dx3sborzrl [ i_p + 6 ] * rtB .
lcvceh3hv3 [ 2 ] ; } } lzn15zslbh [ 0 ] = ( rtB . c2bqn2vvuz [ 0 ] - rtB .
f3f3ebtfsq [ 0 ] ) - ( rtB . lcvceh3hv3 [ 1 ] * lzn15zslbh [ 2 ] - rtB .
lcvceh3hv3 [ 2 ] * lzn15zslbh [ 1 ] ) ; lzn15zslbh [ 1 ] = ( rtB . c2bqn2vvuz
[ 1 ] - rtB . f3f3ebtfsq [ 1 ] ) - ( aif0nk4dcs - kpgrz5rhip_idx_p ) ;
lzn15zslbh [ 2 ] = ( rtB . c2bqn2vvuz [ 2 ] - rtB . f3f3ebtfsq [ 2 ] ) - (
kpgrz5rhip_idx_e - nfwwjxsmuk ) ; rt_mldivide_U1d3x3_U2d3_Yd3x1_snf (
m2b1vgca5s , lzn15zslbh , rtB . n0xo0shoih ) ; if ( ssIsSampleHit ( rtS , 5 ,
0 ) ) { if ( ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * )
rtDW . iyqxvnatsrh . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime (
rtS , 5 ) ; u = ( void * ) & rtB . lcvceh3hv3 [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) { { { void *
signalProbe = ( void * ) rtDW . h4jqbncwhda . SignalProbe ; real_T t ; void *
u ; t = ssGetTaskTime ( rtS , 1 ) ; u = ( void * ) & rtB . c3goefzgk3 [ 0 ] ;
rtwSignalProbeAppendSample ( signalProbe , t , u ) ; } } } } if (
ssGetLogOutput ( rtS ) ) { { { void * signalProbe = ( void * ) rtDW .
hu21nqqcnih . SignalProbe ; real_T t ; void * u ; t = ssGetTaskTime ( rtS , 0
) ; u = ( void * ) & rtB . h04s5dfqra [ 0 ] ; rtwSignalProbeAppendSample (
signalProbe , t , u ) ; } } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { rtDW . evzrtqyrte . IcNeedsLoading = 0 ; rtDW . l3ydkkphoy .
IcNeedsLoading = 0 ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) { rtDW . m5suqpxty3
= rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . hvy1dfvqu0 ) * rtP .
WhiteNoise_StdDev + rtP . WhiteNoise_Mean ; } if ( ssIsSampleHit ( rtS , 5 ,
0 ) ) { rtDW . h1cj2y3ic5 [ 0 ] += rtP . DiscreteTimeIntegrator_gainval * rtB
. n0xo0shoih [ 0 ] ; rtDW . h1cj2y3ic5 [ 1 ] += rtP .
DiscreteTimeIntegrator_gainval * rtB . n0xo0shoih [ 1 ] ; rtDW . h1cj2y3ic5 [
2 ] += rtP . DiscreteTimeIntegrator_gainval * rtB . n0xo0shoih [ 2 ] ; } {
enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( rtX . hc2wlzjerw [ 0 ] == rtP .
IntegratorLimited_UpperSat ) { switch ( rtDW . f0rotw3bar [ 0 ] ) { case
INTG_UPPER_SAT : if ( rtB . piiwfosis5 [ 0 ] < 0.0 ) { ssSetSolverNeedsReset
( rtS ) ; rtDW . f0rotw3bar [ 0 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( rtB . piiwfosis5 [ 0 ] >= 0.0 ) { rtDW .
f0rotw3bar [ 0 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ;
default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB . piiwfosis5 [ 0 ] < 0.0 )
{ rtDW . f0rotw3bar [ 0 ] = INTG_LEAVING_UPPER_SAT ; } else { rtDW .
f0rotw3bar [ 0 ] = INTG_UPPER_SAT ; } break ; } } else if ( rtX . hc2wlzjerw
[ 0 ] == rtP . IntegratorLimited_LowerSat ) { switch ( rtDW . f0rotw3bar [ 0
] ) { case INTG_LOWER_SAT : if ( rtB . piiwfosis5 [ 0 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . f0rotw3bar [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
piiwfosis5 [ 0 ] <= 0.0 ) { rtDW . f0rotw3bar [ 0 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . piiwfosis5 [ 0 ] > 0.0 ) { rtDW . f0rotw3bar [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . f0rotw3bar [ 0 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . f0rotw3bar [ 0 ] = INTG_NORMAL ; } if ( rtX .
hc2wlzjerw [ 1 ] == rtP . IntegratorLimited_UpperSat ) { switch ( rtDW .
f0rotw3bar [ 1 ] ) { case INTG_UPPER_SAT : if ( rtB . piiwfosis5 [ 1 ] < 0.0
) { ssSetSolverNeedsReset ( rtS ) ; rtDW . f0rotw3bar [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
piiwfosis5 [ 1 ] >= 0.0 ) { rtDW . f0rotw3bar [ 1 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . piiwfosis5 [ 1 ] < 0.0 ) { rtDW . f0rotw3bar [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . f0rotw3bar [ 1 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . hc2wlzjerw [ 1 ] == rtP .
IntegratorLimited_LowerSat ) { switch ( rtDW . f0rotw3bar [ 1 ] ) { case
INTG_LOWER_SAT : if ( rtB . piiwfosis5 [ 1 ] > 0.0 ) { ssSetSolverNeedsReset
( rtS ) ; rtDW . f0rotw3bar [ 1 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( rtB . piiwfosis5 [ 1 ] <= 0.0 ) { rtDW .
f0rotw3bar [ 1 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ;
default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB . piiwfosis5 [ 1 ] > 0.0 )
{ rtDW . f0rotw3bar [ 1 ] = INTG_LEAVING_LOWER_SAT ; } else { rtDW .
f0rotw3bar [ 1 ] = INTG_LOWER_SAT ; } break ; } } else { rtDW . f0rotw3bar [
1 ] = INTG_NORMAL ; } if ( rtX . hc2wlzjerw [ 2 ] == rtP .
IntegratorLimited_UpperSat ) { switch ( rtDW . f0rotw3bar [ 2 ] ) { case
INTG_UPPER_SAT : if ( rtB . piiwfosis5 [ 2 ] < 0.0 ) { ssSetSolverNeedsReset
( rtS ) ; rtDW . f0rotw3bar [ 2 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( rtB . piiwfosis5 [ 2 ] >= 0.0 ) { rtDW .
f0rotw3bar [ 2 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( rtS ) ; } break ;
default : ssSetSolverNeedsReset ( rtS ) ; if ( rtB . piiwfosis5 [ 2 ] < 0.0 )
{ rtDW . f0rotw3bar [ 2 ] = INTG_LEAVING_UPPER_SAT ; } else { rtDW .
f0rotw3bar [ 2 ] = INTG_UPPER_SAT ; } break ; } } else if ( rtX . hc2wlzjerw
[ 2 ] == rtP . IntegratorLimited_LowerSat ) { switch ( rtDW . f0rotw3bar [ 2
] ) { case INTG_LOWER_SAT : if ( rtB . piiwfosis5 [ 2 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . f0rotw3bar [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
piiwfosis5 [ 2 ] <= 0.0 ) { rtDW . f0rotw3bar [ 2 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . piiwfosis5 [ 2 ] > 0.0 ) { rtDW . f0rotw3bar [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . f0rotw3bar [ 2 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . f0rotw3bar [ 2 ] = INTG_NORMAL ; } } { enum {
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
} break ; } } else { rtDW . hxjtibst42 [ 2 ] = INTG_NORMAL ; } } if (
ssIsSampleHit ( rtS , 5 , 0 ) ) { rtDW . cht01inrsx = 0U ; memcpy ( & rtDW .
loaxlm1yp2 [ 0 ] , & rtB . bqng0z1mqz [ 0 ] , 18U * sizeof ( real_T ) ) ;
rtDW . epdi02vhe4 = 0U ; memcpy ( & rtDW . g5fe22mv15 [ 0 ] , & rtB .
nowaxdrerk [ 18 ] , 9U * sizeof ( real_T ) ) ; rtDW . j0qx5gs3ge = 0U ; rtDW
. i5firivfli [ 0 ] = rtB . hvzm4sux2r [ 0 ] ; rtDW . i5firivfli [ 1 ] = rtB .
hvzm4sux2r [ 1 ] ; rtDW . i5firivfli [ 2 ] = rtB . hvzm4sux2r [ 2 ] ; } rtDW
. phnnzeax4q . IcNeedsLoading = 0 ; if ( ssIsSampleHit ( rtS , 4 , 0 ) ) {
rtDW . phocmexnl1 = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k2mw3e5m15 ) * rtP
. WhiteNoise_StdDev_esrovvidoo + rtP . WhiteNoise_Mean_fpnv13epd5 ; } { enum
{ INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( rtX . ipddjaa3ie [ 0 ] == rtP .
IntegratorLimited_UpperSat_fwrvmo440m ) { switch ( rtDW . kazdxyylc3 [ 0 ] )
{ case INTG_UPPER_SAT : if ( rtB . gxs3gozf4z [ 0 ] < 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . kazdxyylc3 [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
gxs3gozf4z [ 0 ] >= 0.0 ) { rtDW . kazdxyylc3 [ 0 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . gxs3gozf4z [ 0 ] < 0.0 ) { rtDW . kazdxyylc3 [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . kazdxyylc3 [ 0 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . ipddjaa3ie [ 0 ] == rtP .
IntegratorLimited_LowerSat_m3ljhooqpl ) { switch ( rtDW . kazdxyylc3 [ 0 ] )
{ case INTG_LOWER_SAT : if ( rtB . gxs3gozf4z [ 0 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . kazdxyylc3 [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
gxs3gozf4z [ 0 ] <= 0.0 ) { rtDW . kazdxyylc3 [ 0 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . gxs3gozf4z [ 0 ] > 0.0 ) { rtDW . kazdxyylc3 [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . kazdxyylc3 [ 0 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . kazdxyylc3 [ 0 ] = INTG_NORMAL ; } if ( rtX .
ipddjaa3ie [ 1 ] == rtP . IntegratorLimited_UpperSat_fwrvmo440m ) { switch (
rtDW . kazdxyylc3 [ 1 ] ) { case INTG_UPPER_SAT : if ( rtB . gxs3gozf4z [ 1 ]
< 0.0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . kazdxyylc3 [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
gxs3gozf4z [ 1 ] >= 0.0 ) { rtDW . kazdxyylc3 [ 1 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . gxs3gozf4z [ 1 ] < 0.0 ) { rtDW . kazdxyylc3 [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . kazdxyylc3 [ 1 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . ipddjaa3ie [ 1 ] == rtP .
IntegratorLimited_LowerSat_m3ljhooqpl ) { switch ( rtDW . kazdxyylc3 [ 1 ] )
{ case INTG_LOWER_SAT : if ( rtB . gxs3gozf4z [ 1 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . kazdxyylc3 [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
gxs3gozf4z [ 1 ] <= 0.0 ) { rtDW . kazdxyylc3 [ 1 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . gxs3gozf4z [ 1 ] > 0.0 ) { rtDW . kazdxyylc3 [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . kazdxyylc3 [ 1 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . kazdxyylc3 [ 1 ] = INTG_NORMAL ; } if ( rtX .
ipddjaa3ie [ 2 ] == rtP . IntegratorLimited_UpperSat_fwrvmo440m ) { switch (
rtDW . kazdxyylc3 [ 2 ] ) { case INTG_UPPER_SAT : if ( rtB . gxs3gozf4z [ 2 ]
< 0.0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . kazdxyylc3 [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
gxs3gozf4z [ 2 ] >= 0.0 ) { rtDW . kazdxyylc3 [ 2 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . gxs3gozf4z [ 2 ] < 0.0 ) { rtDW . kazdxyylc3 [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . kazdxyylc3 [ 2 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . ipddjaa3ie [ 2 ] == rtP .
IntegratorLimited_LowerSat_m3ljhooqpl ) { switch ( rtDW . kazdxyylc3 [ 2 ] )
{ case INTG_LOWER_SAT : if ( rtB . gxs3gozf4z [ 2 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . kazdxyylc3 [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
gxs3gozf4z [ 2 ] <= 0.0 ) { rtDW . kazdxyylc3 [ 2 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . gxs3gozf4z [ 2 ] > 0.0 ) { rtDW . kazdxyylc3 [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . kazdxyylc3 [ 2 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . kazdxyylc3 [ 2 ] = INTG_NORMAL ; } } { enum {
INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( rtX . bhzxtdpm0j [ 0 ] == rtP .
IntegratorLimited_UpperSat_ib2vfv1ckh ) { switch ( rtDW . pynovrdqcu [ 0 ] )
{ case INTG_UPPER_SAT : if ( rtB . dc1j3uzyrw [ 0 ] < 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . pynovrdqcu [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
dc1j3uzyrw [ 0 ] >= 0.0 ) { rtDW . pynovrdqcu [ 0 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . dc1j3uzyrw [ 0 ] < 0.0 ) { rtDW . pynovrdqcu [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . pynovrdqcu [ 0 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . bhzxtdpm0j [ 0 ] == rtP .
IntegratorLimited_LowerSat_l15h4cnjuq ) { switch ( rtDW . pynovrdqcu [ 0 ] )
{ case INTG_LOWER_SAT : if ( rtB . dc1j3uzyrw [ 0 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . pynovrdqcu [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
dc1j3uzyrw [ 0 ] <= 0.0 ) { rtDW . pynovrdqcu [ 0 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . dc1j3uzyrw [ 0 ] > 0.0 ) { rtDW . pynovrdqcu [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . pynovrdqcu [ 0 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . pynovrdqcu [ 0 ] = INTG_NORMAL ; } if ( rtX .
bhzxtdpm0j [ 1 ] == rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ) { switch (
rtDW . pynovrdqcu [ 1 ] ) { case INTG_UPPER_SAT : if ( rtB . dc1j3uzyrw [ 1 ]
< 0.0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . pynovrdqcu [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
dc1j3uzyrw [ 1 ] >= 0.0 ) { rtDW . pynovrdqcu [ 1 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . dc1j3uzyrw [ 1 ] < 0.0 ) { rtDW . pynovrdqcu [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . pynovrdqcu [ 1 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . bhzxtdpm0j [ 1 ] == rtP .
IntegratorLimited_LowerSat_l15h4cnjuq ) { switch ( rtDW . pynovrdqcu [ 1 ] )
{ case INTG_LOWER_SAT : if ( rtB . dc1j3uzyrw [ 1 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . pynovrdqcu [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
dc1j3uzyrw [ 1 ] <= 0.0 ) { rtDW . pynovrdqcu [ 1 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . dc1j3uzyrw [ 1 ] > 0.0 ) { rtDW . pynovrdqcu [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . pynovrdqcu [ 1 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . pynovrdqcu [ 1 ] = INTG_NORMAL ; } if ( rtX .
bhzxtdpm0j [ 2 ] == rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ) { switch (
rtDW . pynovrdqcu [ 2 ] ) { case INTG_UPPER_SAT : if ( rtB . dc1j3uzyrw [ 2 ]
< 0.0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . pynovrdqcu [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( rtB .
dc1j3uzyrw [ 2 ] >= 0.0 ) { rtDW . pynovrdqcu [ 2 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . dc1j3uzyrw [ 2 ] < 0.0 ) { rtDW . pynovrdqcu [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } else { rtDW . pynovrdqcu [ 2 ] = INTG_UPPER_SAT ;
} break ; } } else if ( rtX . bhzxtdpm0j [ 2 ] == rtP .
IntegratorLimited_LowerSat_l15h4cnjuq ) { switch ( rtDW . pynovrdqcu [ 2 ] )
{ case INTG_LOWER_SAT : if ( rtB . dc1j3uzyrw [ 2 ] > 0.0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . pynovrdqcu [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( rtB .
dc1j3uzyrw [ 2 ] <= 0.0 ) { rtDW . pynovrdqcu [ 2 ] = INTG_LOWER_SAT ;
ssSetSolverNeedsReset ( rtS ) ; } break ; default : ssSetSolverNeedsReset (
rtS ) ; if ( rtB . dc1j3uzyrw [ 2 ] > 0.0 ) { rtDW . pynovrdqcu [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } else { rtDW . pynovrdqcu [ 2 ] = INTG_LOWER_SAT ;
} break ; } } else { rtDW . pynovrdqcu [ 2 ] = INTG_NORMAL ; } } rtDW .
g0vm4fxb3p . IcNeedsLoading = 0 ; if ( ssIsSampleHit ( rtS , 5 , 0 ) ) { rtDW
. le5srsw3mq = 0U ; memcpy ( & rtDW . gj2ukru0nb [ 0 ] , & rtB . j3qp0rot4z [
0 ] , 18U * sizeof ( real_T ) ) ; rtDW . hfkomryudx = 0U ; memcpy ( & rtDW .
jbnlmtknpk [ 0 ] , & rtB . afjv1quvm5 [ 18 ] , 9U * sizeof ( real_T ) ) ;
rtDW . oslrfkshxj = 0U ; rtDW . olom3dwhnc [ 0 ] = rtB . d2ywubqjk2 [ 0 ] ;
rtDW . olom3dwhnc [ 1 ] = rtB . d2ywubqjk2 [ 1 ] ; rtDW . olom3dwhnc [ 2 ] =
rtB . d2ywubqjk2 [ 2 ] ; } UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives (
void ) { { ( ( XDot * ) ssGetdX ( rtS ) ) -> b1lr14rcuj [ 0 ] = rtB .
pbw2adbesb ; ( ( XDot * ) ssGetdX ( rtS ) ) -> b1lr14rcuj [ 1 ] = rtB .
ab5xgw0342 ; ( ( XDot * ) ssGetdX ( rtS ) ) -> b1lr14rcuj [ 2 ] = rtB .
ct3c5eoli2 ; ( ( XDot * ) ssGetdX ( rtS ) ) -> b1lr14rcuj [ 3 ] = rtB .
crik5dobwi ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> ba1rjb3ky4 [ 0 ] = rtB .
pirqrlkfn1 [ 0 ] ; ( ( XDot * ) ssGetdX ( rtS ) ) -> ba1rjb3ky4 [ 1 ] = rtB .
pirqrlkfn1 [ 1 ] ; ( ( XDot * ) ssGetdX ( rtS ) ) -> ba1rjb3ky4 [ 2 ] = rtB .
pirqrlkfn1 [ 2 ] ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> hod35jdtrz [ 0 ] =
rtB . nx1aqqkpv1 [ 0 ] ; ( ( XDot * ) ssGetdX ( rtS ) ) -> hod35jdtrz [ 1 ] =
rtB . nx1aqqkpv1 [ 1 ] ; ( ( XDot * ) ssGetdX ( rtS ) ) -> hod35jdtrz [ 2 ] =
rtB . nx1aqqkpv1 [ 2 ] ; } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( rtDW .
f0rotw3bar [ 0 ] != INTG_UPPER_SAT ) && ( rtDW . f0rotw3bar [ 0 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> hc2wlzjerw [ 0 ] = rtB
. piiwfosis5 [ 0 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
hc2wlzjerw [ 0 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
hc2wlzjerw [ 0 ] = 0.0 ; if ( ( rtDW . f0rotw3bar [ 0 ] == INTG_UPPER_SAT )
|| ( rtDW . f0rotw3bar [ 0 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> hc2wlzjerw [ 0 ] = TRUE ; } } if ( ( rtDW
. f0rotw3bar [ 1 ] != INTG_UPPER_SAT ) && ( rtDW . f0rotw3bar [ 1 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> hc2wlzjerw [ 1 ] = rtB
. piiwfosis5 [ 1 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
hc2wlzjerw [ 1 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
hc2wlzjerw [ 1 ] = 0.0 ; if ( ( rtDW . f0rotw3bar [ 1 ] == INTG_UPPER_SAT )
|| ( rtDW . f0rotw3bar [ 1 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> hc2wlzjerw [ 1 ] = TRUE ; } } if ( ( rtDW
. f0rotw3bar [ 2 ] != INTG_UPPER_SAT ) && ( rtDW . f0rotw3bar [ 2 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> hc2wlzjerw [ 2 ] = rtB
. piiwfosis5 [ 2 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
hc2wlzjerw [ 2 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
hc2wlzjerw [ 2 ] = 0.0 ; if ( ( rtDW . f0rotw3bar [ 2 ] == INTG_UPPER_SAT )
|| ( rtDW . f0rotw3bar [ 2 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> hc2wlzjerw [ 2 ] = TRUE ; } } } { enum {
INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( rtDW . hxjtibst42 [ 0 ] !=
INTG_UPPER_SAT ) && ( rtDW . hxjtibst42 [ 0 ] != INTG_LOWER_SAT ) ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 0 ] = rtB . l4ynfqsuix [ 0 ] ; ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) -> abpf02yfny [ 0 ] = FALSE ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 0 ] = 0.0 ; if ( ( rtDW
. hxjtibst42 [ 0 ] == INTG_UPPER_SAT ) || ( rtDW . hxjtibst42 [ 0 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
abpf02yfny [ 0 ] = TRUE ; } } if ( ( rtDW . hxjtibst42 [ 1 ] !=
INTG_UPPER_SAT ) && ( rtDW . hxjtibst42 [ 1 ] != INTG_LOWER_SAT ) ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 1 ] = rtB . l4ynfqsuix [ 1 ] ; ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) -> abpf02yfny [ 1 ] = FALSE ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 1 ] = 0.0 ; if ( ( rtDW
. hxjtibst42 [ 1 ] == INTG_UPPER_SAT ) || ( rtDW . hxjtibst42 [ 1 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
abpf02yfny [ 1 ] = TRUE ; } } if ( ( rtDW . hxjtibst42 [ 2 ] !=
INTG_UPPER_SAT ) && ( rtDW . hxjtibst42 [ 2 ] != INTG_LOWER_SAT ) ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 2 ] = rtB . l4ynfqsuix [ 2 ] ; ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) -> abpf02yfny [ 2 ] = FALSE ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> abpf02yfny [ 2 ] = 0.0 ; if ( ( rtDW
. hxjtibst42 [ 2 ] == INTG_UPPER_SAT ) || ( rtDW . hxjtibst42 [ 2 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
abpf02yfny [ 2 ] = TRUE ; } } } { ( ( XDot * ) ssGetdX ( rtS ) ) ->
gffjebdga3 [ 0 ] = rtB . bivwrzak4c ; ( ( XDot * ) ssGetdX ( rtS ) ) ->
gffjebdga3 [ 1 ] = rtB . mdhwvkkkpg ; ( ( XDot * ) ssGetdX ( rtS ) ) ->
gffjebdga3 [ 2 ] = rtB . kknubsmket ; ( ( XDot * ) ssGetdX ( rtS ) ) ->
gffjebdga3 [ 3 ] = rtB . pok3faxosu ; } { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; if ( ( rtDW . kazdxyylc3 [ 0 ] != INTG_UPPER_SAT ) && (
rtDW . kazdxyylc3 [ 0 ] != INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS )
) -> ipddjaa3ie [ 0 ] = rtB . gxs3gozf4z [ 0 ] ; ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> ipddjaa3ie [ 0 ] = FALSE ; } else { ( (
XDot * ) ssGetdX ( rtS ) ) -> ipddjaa3ie [ 0 ] = 0.0 ; if ( ( rtDW .
kazdxyylc3 [ 0 ] == INTG_UPPER_SAT ) || ( rtDW . kazdxyylc3 [ 0 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
ipddjaa3ie [ 0 ] = TRUE ; } } if ( ( rtDW . kazdxyylc3 [ 1 ] !=
INTG_UPPER_SAT ) && ( rtDW . kazdxyylc3 [ 1 ] != INTG_LOWER_SAT ) ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> ipddjaa3ie [ 1 ] = rtB . gxs3gozf4z [ 1 ] ; ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) -> ipddjaa3ie [ 1 ] = FALSE ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> ipddjaa3ie [ 1 ] = 0.0 ; if ( ( rtDW
. kazdxyylc3 [ 1 ] == INTG_UPPER_SAT ) || ( rtDW . kazdxyylc3 [ 1 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
ipddjaa3ie [ 1 ] = TRUE ; } } if ( ( rtDW . kazdxyylc3 [ 2 ] !=
INTG_UPPER_SAT ) && ( rtDW . kazdxyylc3 [ 2 ] != INTG_LOWER_SAT ) ) { ( (
XDot * ) ssGetdX ( rtS ) ) -> ipddjaa3ie [ 2 ] = rtB . gxs3gozf4z [ 2 ] ; ( (
XDis * ) ssGetContStateDisabled ( rtS ) ) -> ipddjaa3ie [ 2 ] = FALSE ; }
else { ( ( XDot * ) ssGetdX ( rtS ) ) -> ipddjaa3ie [ 2 ] = 0.0 ; if ( ( rtDW
. kazdxyylc3 [ 2 ] == INTG_UPPER_SAT ) || ( rtDW . kazdxyylc3 [ 2 ] ==
INTG_LOWER_SAT ) ) { ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
ipddjaa3ie [ 2 ] = TRUE ; } } } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT
, INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( rtDW .
pynovrdqcu [ 0 ] != INTG_UPPER_SAT ) && ( rtDW . pynovrdqcu [ 0 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> bhzxtdpm0j [ 0 ] = rtB
. dc1j3uzyrw [ 0 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
bhzxtdpm0j [ 0 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
bhzxtdpm0j [ 0 ] = 0.0 ; if ( ( rtDW . pynovrdqcu [ 0 ] == INTG_UPPER_SAT )
|| ( rtDW . pynovrdqcu [ 0 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> bhzxtdpm0j [ 0 ] = TRUE ; } } if ( ( rtDW
. pynovrdqcu [ 1 ] != INTG_UPPER_SAT ) && ( rtDW . pynovrdqcu [ 1 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> bhzxtdpm0j [ 1 ] = rtB
. dc1j3uzyrw [ 1 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
bhzxtdpm0j [ 1 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
bhzxtdpm0j [ 1 ] = 0.0 ; if ( ( rtDW . pynovrdqcu [ 1 ] == INTG_UPPER_SAT )
|| ( rtDW . pynovrdqcu [ 1 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> bhzxtdpm0j [ 1 ] = TRUE ; } } if ( ( rtDW
. pynovrdqcu [ 2 ] != INTG_UPPER_SAT ) && ( rtDW . pynovrdqcu [ 2 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot * ) ssGetdX ( rtS ) ) -> bhzxtdpm0j [ 2 ] = rtB
. dc1j3uzyrw [ 2 ] ; ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
bhzxtdpm0j [ 2 ] = FALSE ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
bhzxtdpm0j [ 2 ] = 0.0 ; if ( ( rtDW . pynovrdqcu [ 2 ] == INTG_UPPER_SAT )
|| ( rtDW . pynovrdqcu [ 2 ] == INTG_LOWER_SAT ) ) { ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> bhzxtdpm0j [ 2 ] = TRUE ; } } } { ( (
XDot * ) ssGetdX ( rtS ) ) -> hiwmnibigx [ 0 ] = rtB . ckqhlb32gd ; ( ( XDot
* ) ssGetdX ( rtS ) ) -> hiwmnibigx [ 1 ] = rtB . leq1llgjf0 ; ( ( XDot * )
ssGetdX ( rtS ) ) -> hiwmnibigx [ 2 ] = rtB . jmzzln4ohz ; ( ( XDot * )
ssGetdX ( rtS ) ) -> hiwmnibigx [ 3 ] = rtB . htxixjme3q ; } } void
MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ;
_rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; if ( rtDW .
bwuwpskbe1 == 1 ) { } _rtZCSV -> jdg5fgght1 = rtB . bwyuqwyvcb - rtP .
Switch_Threshold_l3zqxo5bwe ; { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( rtDW .
f0rotw3bar [ 0 ] == INTG_LEAVING_UPPER_SAT && rtX . hc2wlzjerw [ 0 ] >= rtP .
IntegratorLimited_UpperSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> fxw0wciwbi [ 0 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> fxw0wciwbi [ 0 ] = rtX . hc2wlzjerw [ 0 ] - rtP .
IntegratorLimited_UpperSat ; } if ( rtDW . f0rotw3bar [ 0 ] ==
INTG_LEAVING_LOWER_SAT && rtX . hc2wlzjerw [ 0 ] <= rtP .
IntegratorLimited_LowerSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> cxcnp3omib [ 0 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> cxcnp3omib [ 0 ] = rtX . hc2wlzjerw [ 0 ] - rtP .
IntegratorLimited_LowerSat ; } if ( rtDW . f0rotw3bar [ 1 ] ==
INTG_LEAVING_UPPER_SAT && rtX . hc2wlzjerw [ 1 ] >= rtP .
IntegratorLimited_UpperSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> fxw0wciwbi [ 1 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> fxw0wciwbi [ 1 ] = rtX . hc2wlzjerw [ 1 ] - rtP .
IntegratorLimited_UpperSat ; } if ( rtDW . f0rotw3bar [ 1 ] ==
INTG_LEAVING_LOWER_SAT && rtX . hc2wlzjerw [ 1 ] <= rtP .
IntegratorLimited_LowerSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> cxcnp3omib [ 1 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> cxcnp3omib [ 1 ] = rtX . hc2wlzjerw [ 1 ] - rtP .
IntegratorLimited_LowerSat ; } if ( rtDW . f0rotw3bar [ 2 ] ==
INTG_LEAVING_UPPER_SAT && rtX . hc2wlzjerw [ 2 ] >= rtP .
IntegratorLimited_UpperSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> fxw0wciwbi [ 2 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> fxw0wciwbi [ 2 ] = rtX . hc2wlzjerw [ 2 ] - rtP .
IntegratorLimited_UpperSat ; } if ( rtDW . f0rotw3bar [ 2 ] ==
INTG_LEAVING_LOWER_SAT && rtX . hc2wlzjerw [ 2 ] <= rtP .
IntegratorLimited_LowerSat ) { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS )
) -> cxcnp3omib [ 2 ] = 0.0 ; } else { ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> cxcnp3omib [ 2 ] = rtX . hc2wlzjerw [ 2 ] - rtP .
IntegratorLimited_LowerSat ; } } { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; if ( rtDW . hxjtibst42 [ 0 ] == INTG_LEAVING_UPPER_SAT &&
rtX . abpf02yfny [ 0 ] >= rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ) { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> o3jzv1jvx5 [ 0 ] = 0.0 ; }
else { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> o3jzv1jvx5 [ 0 ] =
rtX . abpf02yfny [ 0 ] - rtP . IntegratorLimited_UpperSat_ntkxmpf0qj ; } if (
rtDW . hxjtibst42 [ 0 ] == INTG_LEAVING_LOWER_SAT && rtX . abpf02yfny [ 0 ]
<= rtP . IntegratorLimited_LowerSat_oacseuhnry ) { ( ( ZCV * )
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
-> of1glfyyn3 [ 0 ] = rtB . jty1zsef01 [ 0 ] - rtP . Saturation_UpperSat ;
_rtZCSV -> fqt0mvrdyk [ 0 ] = rtB . jty1zsef01 [ 0 ] - rtP .
Saturation_LowerSat ; _rtZCSV -> of1glfyyn3 [ 1 ] = rtB . jty1zsef01 [ 1 ] -
rtP . Saturation_UpperSat ; _rtZCSV -> fqt0mvrdyk [ 1 ] = rtB . jty1zsef01 [
1 ] - rtP . Saturation_LowerSat ; _rtZCSV -> of1glfyyn3 [ 2 ] = rtB .
jty1zsef01 [ 2 ] - rtP . Saturation_UpperSat ; _rtZCSV -> fqt0mvrdyk [ 2 ] =
rtB . jty1zsef01 [ 2 ] - rtP . Saturation_LowerSat ; _rtZCSV -> conutdf0a1 =
rtB . cjc4bi0q0l [ 0 ] - rtP . Switch_Threshold_ocvrgqhwfd ; _rtZCSV ->
on4aexigh0 = rtB . cz3ja34zrq - rtP . Switch_Threshold_dkimt1f1tz ; _rtZCSV
-> jvmb2fyiro = rtB . ox2cje3ogi - rtP . Switch_Threshold_gnlntr1le3 ;
_rtZCSV -> c1rvp53ssv = 0.0 ; if ( rtB . aps03o1u4v > 0.0 ) { _rtZCSV ->
c1rvp53ssv = 1.0 ; } { real_T * zcsv = & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> azz3d4nxcem . p41xajlv1g [ 0 ] ) ;
int_T i ; for ( i = 0 ; i < 5 ; i ++ ) { zcsv [ i ] = 0.0 ; } } if ( rtDW .
mf41bf444w == 1 ) { o132e2hrwv ( rtB . cznp4l44bm [ 0 ] , rtB . cznp4l44bm [
4 ] , rtB . cznp4l44bm [ 8 ] , & rtB . azz3d4nxcem , & rtDW . azz3d4nxcem , &
_rtZCSV -> azz3d4nxcem ) ; } _rtZCSV -> msqpbrzbho [ 0 ] = rtB . gnf3ee0yie [
0 ] - rtP . Saturation_UpperSat_hafkqiwfxz ; _rtZCSV -> lkeql2wcuq [ 0 ] =
rtB . gnf3ee0yie [ 0 ] - rtP . Saturation_LowerSat_jlais4nb4c ; _rtZCSV ->
msqpbrzbho [ 1 ] = rtB . gnf3ee0yie [ 1 ] - rtP .
Saturation_UpperSat_hafkqiwfxz ; _rtZCSV -> lkeql2wcuq [ 1 ] = rtB .
gnf3ee0yie [ 1 ] - rtP . Saturation_LowerSat_jlais4nb4c ; _rtZCSV ->
msqpbrzbho [ 2 ] = rtB . gnf3ee0yie [ 2 ] - rtP .
Saturation_UpperSat_hafkqiwfxz ; _rtZCSV -> lkeql2wcuq [ 2 ] = rtB .
gnf3ee0yie [ 2 ] - rtP . Saturation_LowerSat_jlais4nb4c ; _rtZCSV ->
l2ciyo4le3 = rtB . jbdetydqg0 ; _rtZCSV -> oysbzpsleq = rtB . ia5lss0zy0 -
rtP . Switch_Threshold_jv24xn0sxc ; { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; if ( rtDW . kazdxyylc3 [ 0 ] == INTG_LEAVING_UPPER_SAT &&
rtX . ipddjaa3ie [ 0 ] >= rtP . IntegratorLimited_UpperSat_fwrvmo440m ) { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> mbnhcly4p4 [ 0 ] = 0.0 ; }
else { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> mbnhcly4p4 [ 0 ] =
rtX . ipddjaa3ie [ 0 ] - rtP . IntegratorLimited_UpperSat_fwrvmo440m ; } if (
rtDW . kazdxyylc3 [ 0 ] == INTG_LEAVING_LOWER_SAT && rtX . ipddjaa3ie [ 0 ]
<= rtP . IntegratorLimited_LowerSat_m3ljhooqpl ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> nj1x2icp01 [ 0 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> nj1x2icp01 [ 0 ] = rtX .
ipddjaa3ie [ 0 ] - rtP . IntegratorLimited_LowerSat_m3ljhooqpl ; } if ( rtDW
. kazdxyylc3 [ 1 ] == INTG_LEAVING_UPPER_SAT && rtX . ipddjaa3ie [ 1 ] >= rtP
. IntegratorLimited_UpperSat_fwrvmo440m ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> mbnhcly4p4 [ 1 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> mbnhcly4p4 [ 1 ] = rtX .
ipddjaa3ie [ 1 ] - rtP . IntegratorLimited_UpperSat_fwrvmo440m ; } if ( rtDW
. kazdxyylc3 [ 1 ] == INTG_LEAVING_LOWER_SAT && rtX . ipddjaa3ie [ 1 ] <= rtP
. IntegratorLimited_LowerSat_m3ljhooqpl ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> nj1x2icp01 [ 1 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> nj1x2icp01 [ 1 ] = rtX .
ipddjaa3ie [ 1 ] - rtP . IntegratorLimited_LowerSat_m3ljhooqpl ; } if ( rtDW
. kazdxyylc3 [ 2 ] == INTG_LEAVING_UPPER_SAT && rtX . ipddjaa3ie [ 2 ] >= rtP
. IntegratorLimited_UpperSat_fwrvmo440m ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> mbnhcly4p4 [ 2 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> mbnhcly4p4 [ 2 ] = rtX .
ipddjaa3ie [ 2 ] - rtP . IntegratorLimited_UpperSat_fwrvmo440m ; } if ( rtDW
. kazdxyylc3 [ 2 ] == INTG_LEAVING_LOWER_SAT && rtX . ipddjaa3ie [ 2 ] <= rtP
. IntegratorLimited_LowerSat_m3ljhooqpl ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> nj1x2icp01 [ 2 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> nj1x2icp01 [ 2 ] = rtX .
ipddjaa3ie [ 2 ] - rtP . IntegratorLimited_LowerSat_m3ljhooqpl ; } } { enum {
INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( rtDW . pynovrdqcu [ 0 ] ==
INTG_LEAVING_UPPER_SAT && rtX . bhzxtdpm0j [ 0 ] >= rtP .
IntegratorLimited_UpperSat_ib2vfv1ckh ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> lxorc1vviq [ 0 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> lxorc1vviq [ 0 ] = rtX .
bhzxtdpm0j [ 0 ] - rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ; } if ( rtDW
. pynovrdqcu [ 0 ] == INTG_LEAVING_LOWER_SAT && rtX . bhzxtdpm0j [ 0 ] <= rtP
. IntegratorLimited_LowerSat_l15h4cnjuq ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> aa4hlipmit [ 0 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> aa4hlipmit [ 0 ] = rtX .
bhzxtdpm0j [ 0 ] - rtP . IntegratorLimited_LowerSat_l15h4cnjuq ; } if ( rtDW
. pynovrdqcu [ 1 ] == INTG_LEAVING_UPPER_SAT && rtX . bhzxtdpm0j [ 1 ] >= rtP
. IntegratorLimited_UpperSat_ib2vfv1ckh ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> lxorc1vviq [ 1 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> lxorc1vviq [ 1 ] = rtX .
bhzxtdpm0j [ 1 ] - rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ; } if ( rtDW
. pynovrdqcu [ 1 ] == INTG_LEAVING_LOWER_SAT && rtX . bhzxtdpm0j [ 1 ] <= rtP
. IntegratorLimited_LowerSat_l15h4cnjuq ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> aa4hlipmit [ 1 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> aa4hlipmit [ 1 ] = rtX .
bhzxtdpm0j [ 1 ] - rtP . IntegratorLimited_LowerSat_l15h4cnjuq ; } if ( rtDW
. pynovrdqcu [ 2 ] == INTG_LEAVING_UPPER_SAT && rtX . bhzxtdpm0j [ 2 ] >= rtP
. IntegratorLimited_UpperSat_ib2vfv1ckh ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> lxorc1vviq [ 2 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> lxorc1vviq [ 2 ] = rtX .
bhzxtdpm0j [ 2 ] - rtP . IntegratorLimited_UpperSat_ib2vfv1ckh ; } if ( rtDW
. pynovrdqcu [ 2 ] == INTG_LEAVING_LOWER_SAT && rtX . bhzxtdpm0j [ 2 ] <= rtP
. IntegratorLimited_LowerSat_l15h4cnjuq ) { ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> aa4hlipmit [ 2 ] = 0.0 ; } else { ( (
ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> aa4hlipmit [ 2 ] = rtX .
bhzxtdpm0j [ 2 ] - rtP . IntegratorLimited_LowerSat_l15h4cnjuq ; } } _rtZCSV
-> noc1howb5m = rtB . bu0zd3hop0 - rtP . Switch_Threshold_g4wyietdsx ;
_rtZCSV -> nlcmaie0u2 = rtB . eaiuep244b - rtP . Switch_Threshold_msevguw5vk
; _rtZCSV -> lgcrwrzhuk = 0.0 ; if ( rtB . g2zpeh00jx > 0.0 ) { _rtZCSV ->
lgcrwrzhuk = 1.0 ; } { real_T * zcsv = & ( ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> iry0wsg2k5 . p41xajlv1g [ 0 ] ) ;
int_T i ; for ( i = 0 ; i < 5 ; i ++ ) { zcsv [ i ] = 0.0 ; } } if ( rtDW .
nrel2zbbl0 == 1 ) { o132e2hrwv ( rtB . naewu0mfbx [ 0 ] , rtB . naewu0mfbx [
4 ] , rtB . naewu0mfbx [ 8 ] , & rtB . iry0wsg2k5 , & rtDW . iry0wsg2k5 , &
_rtZCSV -> iry0wsg2k5 ) ; } _rtZCSV -> eww3ne2iiy = rtB . elhnkqcp4v [ 0 ] -
rtP . Switch_Threshold_i0bmwnwue3 ; _rtZCSV -> ld3212p11x = rtB . iugw0131dq
- rtP . Switch_Threshold_oly1kcdrtr ; _rtZCSV -> orsixo5y1m [ 0 ] = rtB .
eek0a0qnzz [ 0 ] - rtP . Saturation_UpperSat_pmclfotbip ; _rtZCSV ->
f4jdxybzpf [ 0 ] = rtB . eek0a0qnzz [ 0 ] - rtP .
Saturation_LowerSat_hmweagl2k5 ; _rtZCSV -> orsixo5y1m [ 1 ] = rtB .
eek0a0qnzz [ 1 ] - rtP . Saturation_UpperSat_pmclfotbip ; _rtZCSV ->
f4jdxybzpf [ 1 ] = rtB . eek0a0qnzz [ 1 ] - rtP .
Saturation_LowerSat_hmweagl2k5 ; _rtZCSV -> orsixo5y1m [ 2 ] = rtB .
eek0a0qnzz [ 2 ] - rtP . Saturation_UpperSat_pmclfotbip ; _rtZCSV ->
f4jdxybzpf [ 2 ] = rtB . eek0a0qnzz [ 2 ] - rtP .
Saturation_LowerSat_hmweagl2k5 ; _rtZCSV -> gjzxypbad0 = rtB . enst2mfa5p [ 0
] - rtP . Switch_Threshold_ih32etj225 ; _rtZCSV -> nhedzlvqro = rtB .
a5hluyc4z4 - rtP . Switch_Threshold_oksbac2myv ; _rtZCSV -> blcdcguqy1 = rtB
. hwft0ux5xv - rtP . Switch_Threshold_lodxyjq4uq ; _rtZCSV -> kast2133x5 =
0.0 ; if ( rtB . ffoa23fpkv > 0.0 ) { _rtZCSV -> kast2133x5 = 1.0 ; } {
real_T * zcsv = & ( ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ->
jtgflhe3su . p41xajlv1g [ 0 ] ) ; int_T i ; for ( i = 0 ; i < 5 ; i ++ ) {
zcsv [ i ] = 0.0 ; } } if ( rtDW . lqwl4atrcd == 1 ) { o132e2hrwv ( rtB .
keil2t0ysq [ 0 ] , rtB . keil2t0ysq [ 4 ] , rtB . keil2t0ysq [ 8 ] , & rtB .
jtgflhe3su , & rtDW . jtgflhe3su , & _rtZCSV -> jtgflhe3su ) ; } _rtZCSV ->
eng02qphle [ 0 ] = rtB . goqp2hsxiw [ 0 ] - rtP .
Saturation_UpperSat_kq1vntuako ; _rtZCSV -> pirmbnon5t [ 0 ] = rtB .
goqp2hsxiw [ 0 ] - rtP . Saturation_LowerSat_iborwhdlaq ; _rtZCSV ->
eng02qphle [ 1 ] = rtB . goqp2hsxiw [ 1 ] - rtP .
Saturation_UpperSat_kq1vntuako ; _rtZCSV -> pirmbnon5t [ 1 ] = rtB .
goqp2hsxiw [ 1 ] - rtP . Saturation_LowerSat_iborwhdlaq ; _rtZCSV ->
eng02qphle [ 2 ] = rtB . goqp2hsxiw [ 2 ] - rtP .
Saturation_UpperSat_kq1vntuako ; _rtZCSV -> pirmbnon5t [ 2 ] = rtB .
goqp2hsxiw [ 2 ] - rtP . Saturation_LowerSat_iborwhdlaq ; } void MdlTerminate
( void ) { { int_T i1 ; void * * pw_RSimInfoPtr = & rtDW . bknzq3wgub .
RSimInfoPtr [ 0 ] ; for ( i1 = 0 ; i1 < 5 ; i1 ++ ) { rt_FREE (
pw_RSimInfoPtr [ i1 ] ) ; } } { void * signalProbe = ( void * ) rtDW .
hzkxwtgg3y . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . ethxueuerq . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . mohxnwpvy0 . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . fs3xofbgsa . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . iyqxvnatsr . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . h4jqbncwhd . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . hu21nqqcni . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . oawgrr5lku . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . behvht2jjq . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . jjiadmicyc . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . bgsuqbvq3e . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . m10l43wuz3 . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . hzkxwtgg3yv . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . ethxueuerq5 . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { int_T i1 ; void * *
pw_RSimInfoPtr = & rtDW . hqwrc0ipzd . RSimInfoPtr [ 0 ] ; for ( i1 = 0 ; i1
< 5 ; i1 ++ ) { rt_FREE ( pw_RSimInfoPtr [ i1 ] ) ; } } { void * signalProbe
= ( void * ) rtDW . mohxnwpvy0k . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . fs3xofbgsah . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . iyqxvnatsrh . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
{ void * signalProbe = ( void * ) rtDW . h4jqbncwhda . SignalProbe ; const
char * fileName = rt_GetMatSignalLoggingFileName ( ) ;
rtwSignalProbeSaveDatasetMatFile ( signalProbe , fileName ) ;
rtwSignalProbeDestroyInstance ( signalProbe ) ; } { void * signalProbe = (
void * ) rtDW . hu21nqqcnih . SignalProbe ; const char * fileName =
rt_GetMatSignalLoggingFileName ( ) ; rtwSignalProbeSaveDatasetMatFile (
signalProbe , fileName ) ; rtwSignalProbeDestroyInstance ( signalProbe ) ; }
} void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 30 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 6 ) ; ssSetNumBlocks ( rtS , 1487 ) ;
ssSetNumBlockIO ( rtS , 201 ) ; ssSetNumBlockParams ( rtS , 39790 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 0.01 ) ;
ssSetSampleTime ( rtS , 3 , 0.09 ) ; ssSetSampleTime ( rtS , 4 , 0.1 ) ;
ssSetSampleTime ( rtS , 5 , 1.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; ssSetOffsetTime ( rtS , 4 , 0.0 ) ;
ssSetOffsetTime ( rtS , 5 , 0.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 466111879U ) ; ssSetChecksumVal ( rtS ,
1 , 3418754736U ) ; ssSetChecksumVal ( rtS , 2 , 1722666805U ) ;
ssSetChecksumVal ( rtS , 3 , 1673784402U ) ; } SimStruct *
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
rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "ACStesbed" ) ;
ssSetPath ( rtS , "ACStesbed" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 5000.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; ssSetRTWLogInfo (
rtS , & rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] =
{ 4 , 3 , 3 , 3 , 3 , 4 , 3 , 3 , 4 , 3 , 18 , 9 , 3 , 18 , 9 , 3 } ; static
int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 4
, 3 , 3 , 3 , 3 , 4 , 3 , 3 , 4 , 3 , 18 , 9 , 3 , 18 , 9 , 3 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds
[ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE
, SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "ACStesbed/CentralComputer/SatAttitude/BINS/quatint/q0\nq1\nq2\nq3" ,
"ACStesbed/Object/TestBedDynamics/Integrator" ,
"ACStesbed/Sensors/RateSensor/Integrator" ,
"ACStesbed/Actuators/Subsystem/Integrator\nLimited" ,
"ACStesbed/Actuators/RWmodel/Integrator\nLimited" ,
"ACStesbed/Object/TestBedDynamics/quatint/q0\nq1\nq2\nq3" ,
"ACStesbed/TestBedComputer/Actuators/Subsystem/Integrator\nLimited" ,
"ACStesbed/TestBedComputer/Actuators/RWmodel/Integrator\nLimited" ,
 "ACStesbed/TestBedComputer/ModelCentralComputer/SatAttitude/BINS/quatint/q0\nq1\nq2\nq3"
,
 "ACStesbed/TestBedComputer/ModelObject/TestBedDynamics/Discrete-Time\nIntegrator"
,
 "ACStesbed/CentralComputer/ModelOfObject/InertiaIdentification/Discrete-Time\nIntegrator"
,
 "ACStesbed/CentralComputer/ModelOfObject/InertiaIdentification/Discrete-Time\nIntegrator1"
,
 "ACStesbed/CentralComputer/ModelOfObject/InertiaIdentification/Discrete-Time\nIntegrator2"
,
 "ACStesbed/TestBedComputer/ModelCentralComputer/ModelOfObject/InertiaIdentification/Discrete-Time\nIntegrator"
,
 "ACStesbed/TestBedComputer/ModelCentralComputer/ModelOfObject/InertiaIdentification/Discrete-Time\nIntegrator1"
,
 "ACStesbed/TestBedComputer/ModelCentralComputer/ModelOfObject/InertiaIdentification/Discrete-Time\nIntegrator2"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [
] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 16 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 16 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . b1lr14rcuj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . ba1rjb3ky4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . hod35jdtrz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . hc2wlzjerw [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . abpf02yfny [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . gffjebdga3 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . ipddjaa3ie [ 0 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . bhzxtdpm0j [ 0 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . hiwmnibigx [ 0 ] ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) rtDW . h1cj2y3ic5 ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) rtDW . loaxlm1yp2 ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) rtDW . g5fe22mv15 ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) rtDW . i5firivfli ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) rtDW . gj2ukru0nb ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) rtDW . jbnlmtknpk ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) rtDW . olom3dwhnc ; }
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
; } { static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 30
] ; static real_T absTol [ 30 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 30 ] = { 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static uint8_T
zcAttributes [ 79 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL_DN ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ;
static ssNonContDerivSigInfo nonContDerivSigInfo [ 22 ] = { { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . gxs3gozf4z [ 0 ] ) , ( NULL ) } , { 3 *
sizeof ( real_T ) , ( char * ) ( & rtB . dc1j3uzyrw [ 0 ] ) , ( NULL ) } , {
3 * sizeof ( real_T ) , ( char * ) ( & rtB . nx1aqqkpv1 [ 0 ] ) , ( NULL ) }
, { 3 * sizeof ( real_T ) , ( char * ) ( & rtB . neym5ecad1 [ 0 ] ) , ( NULL
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
( char * ) ( & rtB . piiwfosis5 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real_T
) , ( char * ) ( & rtB . ajquw4hgfb [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . l4ynfqsuix [ 0 ] ) , ( NULL ) } , { 3 *
sizeof ( real_T ) , ( char * ) ( & rtB . lcvceh3hv3 [ 0 ] ) , ( NULL ) } , {
3 * sizeof ( real_T ) , ( char * ) ( & rtB . kwssbn0ne4 [ 0 ] ) , ( NULL ) }
} ; ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.01 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 22 ) ; ssSetNonContDerivSigInfos ( rtS ,
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
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 79 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 79 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 466111879U ) ; ssSetChecksumVal ( rtS , 1 ,
3418754736U ) ; ssSetChecksumVal ( rtS , 2 , 1722666805U ) ; ssSetChecksumVal
( rtS , 3 , 1673784402U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 42 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
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
= ( sysRanDType * ) & rtDW . azz3d4nxcem . gvkoaih0tt ; systemRan [ 19 ] = (
sysRanDType * ) & rtDW . azz3d4nxcem . occ4jhal5v ; systemRan [ 20 ] = (
sysRanDType * ) & rtDW . azz3d4nxcem . k5kqzwhgid ; systemRan [ 21 ] = (
sysRanDType * ) & rtDW . azz3d4nxcem . fw1wxjvjvv ; systemRan [ 22 ] = (
sysRanDType * ) & rtDW . p0vdevk3x14 . espotkwrxj ; systemRan [ 23 ] = &
rtAlwaysEnabled ; systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] = &
rtAlwaysEnabled ; systemRan [ 26 ] = ( sysRanDType * ) & rtDW . iry0wsg2k5 .
gvkoaih0tt ; systemRan [ 27 ] = ( sysRanDType * ) & rtDW . iry0wsg2k5 .
occ4jhal5v ; systemRan [ 28 ] = ( sysRanDType * ) & rtDW . iry0wsg2k5 .
k5kqzwhgid ; systemRan [ 29 ] = ( sysRanDType * ) & rtDW . iry0wsg2k5 .
fw1wxjvjvv ; systemRan [ 30 ] = ( sysRanDType * ) & rtDW . orebwtip3e .
espotkwrxj ; systemRan [ 31 ] = & rtAlwaysEnabled ; systemRan [ 32 ] = &
rtAlwaysEnabled ; systemRan [ 33 ] = & rtAlwaysEnabled ; systemRan [ 34 ] = &
rtAlwaysEnabled ; systemRan [ 35 ] = ( sysRanDType * ) & rtDW . jtgflhe3su .
gvkoaih0tt ; systemRan [ 36 ] = ( sysRanDType * ) & rtDW . jtgflhe3su .
occ4jhal5v ; systemRan [ 37 ] = ( sysRanDType * ) & rtDW . jtgflhe3su .
k5kqzwhgid ; systemRan [ 38 ] = ( sysRanDType * ) & rtDW . jtgflhe3su .
fw1wxjvjvv ; systemRan [ 39 ] = ( sysRanDType * ) & rtDW . ammeeph1io .
espotkwrxj ; systemRan [ 40 ] = & rtAlwaysEnabled ; systemRan [ 41 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
