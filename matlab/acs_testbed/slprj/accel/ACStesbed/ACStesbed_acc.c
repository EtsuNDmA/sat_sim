#include "__cf_ACStesbed.h"
#include <math.h>
#include "ACStesbed_acc.h"
#include "ACStesbed_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T lo ; uint32_T
hi ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi
) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return (
real_T ) * u * 4.6566128752457969E-10 ; } real_T rt_nrand_Upu32_Yd_f_pw_snf (
uint32_T * u ) { real_T y ; real_T sr ; real_T si ; do { sr = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void MWDSPCG_Pseudoinverse_D ( const real_T pS [ ] ,
const real_T pU [ ] , const real_T pV [ ] , real_T pX [ ] , const int32_T M ,
const int32_T N ) { int32_T ppSIdx ; real_T tol ; real_T cabsS ; int32_T P ;
int32_T rank ; int32_T ppXIdx ; int32_T ppUIdx ; int32_T ppVIdx ; int32_T j ;
int32_T k ; rank = 0 ; P = muIntScalarMin_sint32 ( M , N ) ; cabsS =
muDoubleScalarAbs ( pS [ 0 ] ) ; if ( 0.0 < cabsS ) { rank = 1 ; tol = (
real_T ) muIntScalarMax_sint32 ( M , N ) * pS [ 0U ] * 2.2204460492503131E-16
; ppSIdx = P ; while ( P > 0 ) { cabsS = muDoubleScalarAbs ( pS [ ppSIdx - 1
] ) ; ppSIdx -- ; if ( cabsS >= tol ) { rank = P ; P = 0 ; } P -- ; } }
ppXIdx = 0 ; for ( P = 0 ; P < N * M ; P ++ ) { pX [ ppXIdx ] = 0.0 ; ppXIdx
++ ; } if ( rank != 0 ) { ppXIdx = 0 ; for ( j = 0 ; j < M ; j ++ ) { for ( P
= 0 ; P < N ; P ++ ) { ppVIdx = P ; ppUIdx = j ; ppSIdx = 0 ; for ( k = 0 ; k
< rank ; k ++ ) { cabsS = pV [ ppVIdx ] * pU [ ppUIdx ] / pS [ ppSIdx ] ; pX
[ ppXIdx ] += cabsS ; ppSIdx ++ ; ppVIdx += N ; ppUIdx += M ; } ppXIdx ++ ; }
} } } void LUf_int32_Treal_T ( real_T outU [ ] , real_T outP [ ] , const
int32_T N ) { int32_T k ; int32_T c ; int32_T r ; int32_T idx ; real_T tmp ;
int32_T p ; real_T mTmp ; boolean_T isDiagZero ; real_T mAccum ; for ( k = 0
; k < N ; k ++ ) { outP [ k ] = ( real_T ) k + 1.0 ; } for ( k = 0 ; k < N ;
k ++ ) { p = k ; idx = k * N ; mTmp = outU [ idx + k ] ; if ( mTmp < 0.0 ) {
mTmp = - mTmp ; } for ( r = k + 1 ; r < N ; r ++ ) { tmp = outU [ idx + r ] ;
if ( tmp < 0.0 ) { tmp = - tmp ; } if ( tmp > mTmp ) { p = r ; mTmp = tmp ; }
} if ( p != k ) { for ( c = 0 ; c < N ; c ++ ) { idx = c * N ; mTmp = outU [
idx + p ] ; tmp = outU [ idx + k ] ; outU [ idx + p ] = tmp ; outU [ idx + k
] = mTmp ; } tmp = outP [ p ] ; outP [ p ] = outP [ k ] ; outP [ k ] = tmp ;
} idx = k * N + k ; isDiagZero = FALSE ; if ( outU [ idx ] == 0.0 ) {
isDiagZero = TRUE ; } if ( ! isDiagZero ) { p = k * N ; for ( r = k + 1 ; r <
N ; r ++ ) { mTmp = outU [ p + r ] ; tmp = outU [ idx ] ; outU [ p + r ] =
mTmp / tmp ; } for ( c = k + 1 ; c < N ; c ++ ) { idx = c * N ; for ( r = k +
1 ; r < N ; r ++ ) { mAccum = outU [ idx + r ] ; mTmp = outU [ p + r ] ; tmp
= outU [ idx + k ] * mTmp ; mAccum -= tmp ; outU [ idx + r ] = mAccum ; } } }
} } void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( const real_T u0 [ 3 ] , const
real_T u1 [ 9 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; real_T A_0 [ 9 ] ;
int32_T r1 ; int32_T r ; int32_T r_0 ; real_T maxval ; real_T a ; int32_T
rtemp ; for ( r1 = 0 ; r1 < 3 ; r1 ++ ) { A [ 3 * r1 ] = u1 [ r1 ] ; A [ 1 +
3 * r1 ] = u1 [ r1 + 3 ] ; A [ 2 + 3 * r1 ] = u1 [ r1 + 6 ] ; } memcpy ( &
A_0 [ 0 ] , & A [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 1 ; r = 2 ; r_0 = 3 ;
maxval = muDoubleScalarAbs ( A [ 0 ] ) ; a = muDoubleScalarAbs ( A [ 1 ] ) ;
if ( a > maxval ) { maxval = a ; r1 = 2 ; r = 1 ; } if ( muDoubleScalarAbs (
A [ 2 ] ) > maxval ) { r1 = 3 ; r = 2 ; r_0 = 1 ; } A_0 [ r - 1 ] = A [ r - 1
] / A [ r1 - 1 ] ; A_0 [ r_0 - 1 ] /= A_0 [ r1 - 1 ] ; A_0 [ r + 2 ] -= A_0 [
r - 1 ] * A_0 [ r1 + 2 ] ; A_0 [ r_0 + 2 ] -= A_0 [ r_0 - 1 ] * A_0 [ r1 + 2
] ; A_0 [ r + 5 ] -= A_0 [ r - 1 ] * A_0 [ r1 + 5 ] ; A_0 [ r_0 + 5 ] -= A_0
[ r_0 - 1 ] * A_0 [ r1 + 5 ] ; if ( muDoubleScalarAbs ( A_0 [ r_0 + 2 ] ) >
muDoubleScalarAbs ( A_0 [ r + 2 ] ) ) { rtemp = r ; r = r_0 ; r_0 = rtemp ; }
A_0 [ r_0 + 2 ] /= A_0 [ r + 2 ] ; A_0 [ r_0 + 5 ] -= A_0 [ r_0 + 2 ] * A_0 [
r + 5 ] ; maxval = u0 [ r - 1 ] - u0 [ r1 - 1 ] * A_0 [ r - 1 ] ; a = ( ( u0
[ r_0 - 1 ] - u0 [ r1 - 1 ] * A_0 [ r_0 - 1 ] ) - A_0 [ r_0 + 2 ] * maxval )
/ A_0 [ r_0 + 5 ] ; maxval -= A_0 [ r + 5 ] * a ; maxval /= A_0 [ r + 2 ] ; y
[ 0 ] = ( ( u0 [ r1 - 1 ] - A_0 [ r1 + 5 ] * a ) - A_0 [ r1 + 2 ] * maxval )
/ A_0 [ r1 - 1 ] ; y [ 1 ] = maxval ; y [ 2 ] = a ; } static void mdlOutputs
( SimStruct * S , int_T tid ) { real_T B_5_772_0 [ 3 ] ; real_T B_5_9_0 [ 4 ]
; real_T B_5_66_0 [ 4 ] ; real_T B_5_840_0 [ 3 ] ; real_T B_5_663_0 [ 3 ] ;
int32_T k ; int32_T idxB ; int32_T idxLU ; real_T y [ 3 ] ; real_T y_0 [ 9 ]
; real_T rtb_B_5_731_0 [ 3 ] ; real_T rtb_B_5_767_0 ; real_T rtb_B_5_766_0 ;
real_T rtb_B_5_785_0 ; real_T rtb_B_5_842_0 ; real_T rtb_B_5_424_0 [ 9 ] ;
real_T rtb_B_5_159_0 [ 6 ] ; real_T rtb_B_5_574_0 ; real_T rtb_B_5_594_0 [ 9
] ; int8_T rtPrevAction ; int8_T rtAction ; real_T rtb_B_5_326_0 [ 9 ] ;
real_T rtb_B_5_340_0 [ 9 ] ; real_T rtb_B_5_497_0 [ 9 ] ; real_T
rtb_B_5_512_0 [ 9 ] ; real_T rtb_B_5_534_0 [ 9 ] ; real_T rtb_B_5_549_0 [ 9 ]
; real_T rtb_B_5_571_0 [ 9 ] ; real_T rtb_B_5_586_0 [ 9 ] ; real_T
rtb_B_5_646_0 [ 9 ] ; real_T rtb_B_5_252_0 [ 9 ] ; real_T rtb_B_5_655_0 [ 9 ]
; real_T rtb_B_5_659_0 [ 18 ] ; int32_T i ; int32_T i_0 ; real_T B [ 9 ] ;
real_T tmp [ 6 ] ; real_T y_1 [ 6 ] ; real_T B_5_578_0_idx ; real_T
B_5_578_0_idx_0 ; real_T B_5_155_0_idx ; real_T B_5_155_0_idx_0 ; real_T
B_5_155_0_idx_1 ; B_ACStesbed_T * _rtB ; P_ACStesbed_T * _rtP ;
DW_ACStesbed_T * _rtDW ; _rtDW = ( ( DW_ACStesbed_T * ) ssGetRootDWork ( S )
) ; _rtP = ( ( P_ACStesbed_T * ) ssGetDefaultParam ( S ) ) ; _rtB = ( (
B_ACStesbed_T * ) _ssGetBlockIO ( S ) ) ; _rtB -> B_5_0_0 [ 0 ] = ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> pqr_CSTATE [ 0 ] ; _rtB ->
B_5_0_0 [ 1 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> pqr_CSTATE [
1 ] ; _rtB -> B_5_0_0 [ 2 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) )
-> pqr_CSTATE [ 2 ] ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB -> B_5_1_0 [
i_0 ] = 0.0 ; _rtB -> B_5_1_0 [ i_0 ] += _rtP -> P_25 [ i_0 ] * _rtB ->
B_5_0_0 [ 0 ] ; _rtB -> B_5_1_0 [ i_0 ] += _rtP -> P_25 [ i_0 + 3 ] * _rtB ->
B_5_0_0 [ 1 ] ; _rtB -> B_5_1_0 [ i_0 ] += _rtP -> P_25 [ i_0 + 6 ] * _rtB ->
B_5_0_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { muDoubleScalarSinCos (
_rtP -> P_27 * _rtP -> P_26 [ 2 ] , & rtb_B_5_767_0 , & rtb_B_5_766_0 ) ;
B_5_578_0_idx = rtb_B_5_766_0 ; rtb_B_5_731_0 [ 0 ] = rtb_B_5_767_0 ;
muDoubleScalarSinCos ( _rtP -> P_27 * _rtP -> P_26 [ 1 ] , & rtb_B_5_767_0 ,
& rtb_B_5_766_0 ) ; B_5_578_0_idx_0 = rtb_B_5_766_0 ; rtb_B_5_731_0 [ 1 ] =
rtb_B_5_767_0 ; muDoubleScalarSinCos ( _rtP -> P_27 * _rtP -> P_26 [ 0 ] , &
rtb_B_5_767_0 , & rtb_B_5_766_0 ) ; _rtB -> B_5_5_0 = B_5_578_0_idx *
B_5_578_0_idx_0 * rtb_B_5_766_0 + rtb_B_5_731_0 [ 0 ] * rtb_B_5_731_0 [ 1 ] *
rtb_B_5_767_0 ; _rtB -> B_5_6_0 = B_5_578_0_idx * B_5_578_0_idx_0 *
rtb_B_5_767_0 - rtb_B_5_731_0 [ 0 ] * rtb_B_5_731_0 [ 1 ] * rtb_B_5_766_0 ;
_rtB -> B_5_7_0 = B_5_578_0_idx * rtb_B_5_731_0 [ 1 ] * rtb_B_5_766_0 +
rtb_B_5_731_0 [ 0 ] * B_5_578_0_idx_0 * rtb_B_5_767_0 ; _rtB -> B_5_8_0 =
rtb_B_5_731_0 [ 0 ] * B_5_578_0_idx_0 * rtb_B_5_766_0 - B_5_578_0_idx *
rtb_B_5_731_0 [ 1 ] * rtb_B_5_767_0 ; } if ( _rtDW -> q0q1q2q3_IWORK .
IcNeedsLoading ) { ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE [ 0 ] = _rtB -> B_5_5_0 ; ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 1 ] = _rtB -> B_5_6_0 ; ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 2 ] = _rtB ->
B_5_7_0 ; ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [
3 ] = _rtB -> B_5_8_0 ; } B_5_9_0 [ 0 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 0 ] ; B_5_9_0 [ 1 ] = ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 1 ] ; B_5_9_0
[ 2 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 2
] ; B_5_9_0 [ 3 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE [ 3 ] ; rtb_B_5_767_0 = ( ( B_5_9_0 [ 0 ] * B_5_9_0 [ 0 ] +
B_5_9_0 [ 1 ] * B_5_9_0 [ 1 ] ) + B_5_9_0 [ 2 ] * B_5_9_0 [ 2 ] ) + B_5_9_0 [
3 ] * B_5_9_0 [ 3 ] ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW ->
sqrt_DWORK1 != 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1 = 0 ;
} rtb_B_5_767_0 = muDoubleScalarSqrt ( rtb_B_5_767_0 ) ; } else { if (
rtb_B_5_767_0 < 0.0 ) { rtb_B_5_767_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_5_767_0 ) ) ; } else { rtb_B_5_767_0 =
muDoubleScalarSqrt ( rtb_B_5_767_0 ) ; } _rtDW -> sqrt_DWORK1 = 1 ; }
rtb_B_5_766_0 = B_5_9_0 [ 0 ] / rtb_B_5_767_0 ; B_5_578_0_idx_0 = B_5_9_0 [ 1
] / rtb_B_5_767_0 ; B_5_578_0_idx = B_5_9_0 [ 2 ] / rtb_B_5_767_0 ;
rtb_B_5_767_0 = B_5_9_0 [ 3 ] / rtb_B_5_767_0 ; B_5_663_0 [ 0 ] =
muDoubleScalarAtan2 ( ( B_5_578_0_idx_0 * B_5_578_0_idx + rtb_B_5_766_0 *
rtb_B_5_767_0 ) * 2.0 , ( ( rtb_B_5_766_0 * rtb_B_5_766_0 + B_5_578_0_idx_0 *
B_5_578_0_idx_0 ) - B_5_578_0_idx * B_5_578_0_idx ) - rtb_B_5_767_0 *
rtb_B_5_767_0 ) ; rtb_B_5_842_0 = ( B_5_578_0_idx_0 * rtb_B_5_767_0 -
rtb_B_5_766_0 * B_5_578_0_idx ) * - 2.0 ; if ( rtb_B_5_842_0 >= 1.0 ) {
rtb_B_5_842_0 = 1.0 ; } else { if ( rtb_B_5_842_0 <= - 1.0 ) { rtb_B_5_842_0
= - 1.0 ; } } B_5_663_0 [ 1 ] = muDoubleScalarAsin ( rtb_B_5_842_0 ) ;
rtb_B_5_842_0 = ( B_5_578_0_idx * rtb_B_5_767_0 + rtb_B_5_766_0 *
B_5_578_0_idx_0 ) * 2.0 ; rtb_B_5_766_0 = ( ( rtb_B_5_766_0 * rtb_B_5_766_0 -
B_5_578_0_idx_0 * B_5_578_0_idx_0 ) - B_5_578_0_idx * B_5_578_0_idx ) +
rtb_B_5_767_0 * rtb_B_5_767_0 ; B_5_663_0 [ 2 ] = muDoubleScalarAtan2 (
rtb_B_5_842_0 , rtb_B_5_766_0 ) ; rtb_B_5_731_0 [ 1 ] = _rtP -> P_28 *
B_5_663_0 [ 1 ] ; rtb_B_5_731_0 [ 2 ] = _rtP -> P_28 * B_5_663_0 [ 0 ] ;
muDoubleScalarSinCos ( _rtP -> P_28 * B_5_663_0 [ 2 ] , & rtb_B_5_767_0 , &
rtb_B_5_766_0 ) ; B_5_663_0 [ 0 ] = rtb_B_5_766_0 ; rtb_B_5_731_0 [ 0 ] =
rtb_B_5_767_0 ; muDoubleScalarSinCos ( rtb_B_5_731_0 [ 1 ] , & rtb_B_5_767_0
, & rtb_B_5_766_0 ) ; B_5_663_0 [ 1 ] = rtb_B_5_766_0 ; rtb_B_5_731_0 [ 1 ] =
rtb_B_5_767_0 ; muDoubleScalarSinCos ( rtb_B_5_731_0 [ 2 ] , & rtb_B_5_767_0
, & rtb_B_5_766_0 ) ; B_5_663_0 [ 2 ] = rtb_B_5_766_0 ; _rtB -> B_5_31_0 =
B_5_663_0 [ 0 ] * B_5_663_0 [ 1 ] * B_5_663_0 [ 2 ] - rtb_B_5_731_0 [ 0 ] *
rtb_B_5_731_0 [ 1 ] * rtb_B_5_767_0 ; rtb_B_5_842_0 = B_5_663_0 [ 0 ] *
rtb_B_5_731_0 [ 1 ] * rtb_B_5_767_0 + rtb_B_5_731_0 [ 0 ] * B_5_663_0 [ 1 ] *
B_5_663_0 [ 2 ] ; rtb_B_5_785_0 = B_5_663_0 [ 0 ] * rtb_B_5_731_0 [ 1 ] *
B_5_663_0 [ 2 ] - rtb_B_5_731_0 [ 0 ] * B_5_663_0 [ 1 ] * rtb_B_5_767_0 ;
B_5_578_0_idx = B_5_663_0 [ 0 ] * B_5_663_0 [ 1 ] * rtb_B_5_767_0 +
rtb_B_5_731_0 [ 0 ] * rtb_B_5_731_0 [ 1 ] * B_5_663_0 [ 2 ] ; for ( i_0 = 0 ;
i_0 < 3 ; i_0 ++ ) { _rtB -> B_5_36_0 [ i_0 ] = 0.0 ; _rtB -> B_5_36_0 [ i_0
] += _rtP -> P_29 [ i_0 ] * rtb_B_5_842_0 ; _rtB -> B_5_36_0 [ i_0 ] += _rtP
-> P_29 [ i_0 + 3 ] * rtb_B_5_785_0 ; _rtB -> B_5_36_0 [ i_0 ] += _rtP ->
P_29 [ i_0 + 6 ] * B_5_578_0_idx ; } ssCallAccelRunBlock ( S , 5 , 37 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_5_439_0 [ 0 ] = _rtB -> B_5_31_0 ; _rtB ->
B_5_439_0 [ 1 ] = _rtB -> B_5_36_0 [ 0 ] ; _rtB -> B_5_439_0 [ 2 ] = _rtB ->
B_5_36_0 [ 1 ] ; _rtB -> B_5_439_0 [ 3 ] = _rtB -> B_5_36_0 [ 2 ] ;
ssCallAccelRunBlock ( S , 5 , 39 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { memcpy ( & _rtB -> B_5_40_0 [ 0 ] , & _rtP -> P_30 [ 0 ] ,
9U * sizeof ( real_T ) ) ; _rtB -> B_5_41_0 = _rtP -> P_31 ; } rtb_B_5_424_0
[ 0 ] = _rtB -> B_5_41_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_5_43_0 [ 0 ] = _rtP -> P_32 [ 0 ] ; _rtB -> B_5_43_0 [ 1 ] = _rtP -> P_32 [
1 ] ; _rtB -> B_5_43_0 [ 2 ] = _rtP -> P_32 [ 2 ] ; _rtB -> B_5_50_0 = ( (
_rtP -> P_33 [ 0 ] * _rtP -> P_34 [ 0 ] - _rtP -> P_33 [ 1 ] * _rtP -> P_34 [
1 ] ) - _rtP -> P_33 [ 2 ] * _rtP -> P_34 [ 2 ] ) - _rtP -> P_33 [ 3 ] * _rtP
-> P_34 [ 3 ] ; _rtB -> B_5_55_0 = ( ( _rtP -> P_33 [ 0 ] * _rtP -> P_34 [ 1
] + _rtP -> P_33 [ 1 ] * _rtP -> P_34 [ 0 ] ) + _rtP -> P_33 [ 2 ] * _rtP ->
P_34 [ 3 ] ) - _rtP -> P_33 [ 3 ] * _rtP -> P_34 [ 2 ] ; _rtB -> B_5_60_0 = (
( _rtP -> P_33 [ 0 ] * _rtP -> P_34 [ 2 ] - _rtP -> P_33 [ 1 ] * _rtP -> P_34
[ 3 ] ) + _rtP -> P_33 [ 2 ] * _rtP -> P_34 [ 0 ] ) + _rtP -> P_33 [ 3 ] *
_rtP -> P_34 [ 1 ] ; _rtB -> B_5_65_0 = ( ( _rtP -> P_33 [ 0 ] * _rtP -> P_34
[ 3 ] + _rtP -> P_33 [ 1 ] * _rtP -> P_34 [ 2 ] ) - _rtP -> P_33 [ 2 ] * _rtP
-> P_34 [ 1 ] ) + _rtP -> P_33 [ 3 ] * _rtP -> P_34 [ 0 ] ; } if ( _rtDW ->
q0q1q2q3_IWORK_d . IcNeedsLoading ) { ( ( X_ACStesbed_T * ) ssGetContStates (
S ) ) -> q0q1q2q3_CSTATE_f [ 0 ] = _rtB -> B_5_50_0 ; ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_f [ 1 ] = _rtB -> B_5_55_0 ; ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_f [ 2 ] = _rtB
-> B_5_60_0 ; ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE_f [ 3 ] = _rtB -> B_5_65_0 ; } B_5_66_0 [ 0 ] = ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_f [ 0 ] ;
B_5_66_0 [ 1 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE_f [ 1 ] ; B_5_66_0 [ 2 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_f [ 2 ] ; B_5_66_0 [ 3 ] = ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_f [ 3 ] ;
rtb_B_5_842_0 = ( ( B_5_66_0 [ 0 ] * B_5_66_0 [ 0 ] + B_5_66_0 [ 1 ] *
B_5_66_0 [ 1 ] ) + B_5_66_0 [ 2 ] * B_5_66_0 [ 2 ] ) + B_5_66_0 [ 3 ] *
B_5_66_0 [ 3 ] ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_m
!= 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_m = 0 ; }
rtb_B_5_842_0 = muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } else { if (
rtb_B_5_842_0 < 0.0 ) { rtb_B_5_842_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_5_842_0 ) ) ; } else { rtb_B_5_842_0 =
muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } _rtDW -> sqrt_DWORK1_m = 1 ; }
rtb_B_5_785_0 = B_5_66_0 [ 1 ] / rtb_B_5_842_0 ; B_5_578_0_idx = B_5_66_0 [ 3
] / rtb_B_5_842_0 ; B_5_578_0_idx_0 = B_5_66_0 [ 0 ] / rtb_B_5_842_0 ;
rtb_B_5_842_0 = B_5_66_0 [ 2 ] / rtb_B_5_842_0 ; if ( ssIsSampleHit ( S , 1 ,
0 ) ) { _rtB -> B_5_89_0 = _rtP -> P_37 ; } rtb_B_5_766_0 = ( ( rtb_B_5_785_0
* B_5_578_0_idx + B_5_578_0_idx_0 * rtb_B_5_842_0 ) * _rtP -> P_35 * _rtB ->
B_5_43_0 [ 0 ] + ( rtb_B_5_842_0 * B_5_578_0_idx - B_5_578_0_idx_0 *
rtb_B_5_785_0 ) * _rtP -> P_36 * _rtB -> B_5_43_0 [ 1 ] ) + ( ( _rtB ->
B_5_89_0 - rtb_B_5_785_0 * rtb_B_5_785_0 ) - rtb_B_5_842_0 * rtb_B_5_842_0 )
* _rtP -> P_38 * _rtB -> B_5_43_0 [ 2 ] ; rtb_B_5_424_0 [ 1 ] = rtb_B_5_766_0
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_97_0 = _rtP -> P_39 ; }
rtb_B_5_767_0 = ( ( ( _rtB -> B_5_97_0 - rtb_B_5_842_0 * rtb_B_5_842_0 ) -
B_5_578_0_idx * B_5_578_0_idx ) * _rtP -> P_40 * _rtB -> B_5_43_0 [ 0 ] + (
rtb_B_5_785_0 * rtb_B_5_842_0 + B_5_578_0_idx_0 * B_5_578_0_idx ) * _rtP ->
P_41 * _rtB -> B_5_43_0 [ 1 ] ) + ( rtb_B_5_785_0 * B_5_578_0_idx -
B_5_578_0_idx_0 * rtb_B_5_842_0 ) * _rtP -> P_42 * _rtB -> B_5_43_0 [ 2 ] ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_119_0 = _rtP -> P_44 ; }
rtb_B_5_842_0 = ( ( ( _rtB -> B_5_119_0 - rtb_B_5_785_0 * rtb_B_5_785_0 ) -
B_5_578_0_idx * B_5_578_0_idx ) * _rtP -> P_45 * _rtB -> B_5_43_0 [ 1 ] + (
rtb_B_5_785_0 * rtb_B_5_842_0 - B_5_578_0_idx_0 * B_5_578_0_idx ) * _rtP ->
P_43 * _rtB -> B_5_43_0 [ 0 ] ) + ( B_5_578_0_idx_0 * rtb_B_5_785_0 +
rtb_B_5_842_0 * B_5_578_0_idx ) * _rtP -> P_46 * _rtB -> B_5_43_0 [ 2 ] ;
rtb_B_5_731_0 [ 0 ] = _rtP -> P_47 * rtb_B_5_767_0 ; rtb_B_5_731_0 [ 1 ] =
_rtP -> P_47 * rtb_B_5_842_0 ; rtb_B_5_731_0 [ 2 ] = _rtP -> P_47 *
rtb_B_5_766_0 ; rtb_B_5_424_0 [ 2 ] = rtb_B_5_731_0 [ 1 ] ; rtb_B_5_424_0 [ 3
] = rtb_B_5_731_0 [ 2 ] ; rtb_B_5_424_0 [ 4 ] = _rtB -> B_5_41_0 ;
rtb_B_5_424_0 [ 5 ] = rtb_B_5_767_0 ; rtb_B_5_424_0 [ 6 ] = rtb_B_5_842_0 ;
rtb_B_5_424_0 [ 7 ] = rtb_B_5_731_0 [ 0 ] ; rtb_B_5_424_0 [ 8 ] = _rtB ->
B_5_41_0 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { rtb_B_5_655_0 [ 3 * i_0 ] =
rtb_B_5_424_0 [ i_0 ] ; rtb_B_5_655_0 [ 1 + 3 * i_0 ] = rtb_B_5_424_0 [ i_0 +
3 ] ; rtb_B_5_655_0 [ 2 + 3 * i_0 ] = rtb_B_5_424_0 [ i_0 + 6 ] ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & _rtB -> B_5_139_0 [ 0 ] , & _rtP
-> P_48 [ 0 ] , 9U * sizeof ( real_T ) ) ; } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++
) { for ( i = 0 ; i < 3 ; i ++ ) { B [ i_0 + 3 * i ] = 0.0 ; B [ i_0 + 3 * i
] += _rtB -> B_5_139_0 [ 3 * i ] * rtb_B_5_655_0 [ i_0 ] ; B [ i_0 + 3 * i ]
+= _rtB -> B_5_139_0 [ 3 * i + 1 ] * rtb_B_5_655_0 [ i_0 + 3 ] ; B [ i_0 + 3
* i ] += _rtB -> B_5_139_0 [ 3 * i + 2 ] * rtb_B_5_655_0 [ i_0 + 6 ] ; } }
for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) {
rtb_B_5_424_0 [ i_0 + 3 * i ] = 0.0 ; rtb_B_5_424_0 [ i_0 + 3 * i ] += B [ 3
* i ] * _rtB -> B_5_40_0 [ i_0 ] ; rtb_B_5_424_0 [ i_0 + 3 * i ] += B [ 3 * i
+ 1 ] * _rtB -> B_5_40_0 [ i_0 + 3 ] ; rtb_B_5_424_0 [ i_0 + 3 * i ] += B [ 3
* i + 2 ] * _rtB -> B_5_40_0 [ i_0 + 6 ] ; } } if ( ssIsSampleHit ( S , 1 , 0
) ) { for ( i = 0 ; i < 9 ; i ++ ) { _rtB -> B_5_143_0 [ i ] = _rtP -> P_49 [
i ] + _rtP -> P_50 [ i ] ; } } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) {
rtb_B_5_731_0 [ i_0 ] = _rtB -> B_5_143_0 [ i_0 + 6 ] * _rtB -> B_5_1_0 [ 2 ]
+ ( _rtB -> B_5_143_0 [ i_0 + 3 ] * _rtB -> B_5_1_0 [ 1 ] + _rtB -> B_5_143_0
[ i_0 ] * _rtB -> B_5_1_0 [ 0 ] ) ; } B_5_663_0 [ 0 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> Integrator_CSTATE [ 0 ] ; B_5_663_0 [ 1 ] = ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> Integrator_CSTATE [ 1 ] ;
B_5_663_0 [ 2 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
Integrator_CSTATE [ 2 ] ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB ->
B_5_148_0 [ 0 ] = _rtP -> P_55 [ 0 ] * _rtDW -> NextOutput ; _rtB ->
B_5_148_0 [ 1 ] = _rtP -> P_55 [ 1 ] * _rtDW -> NextOutput ; _rtB ->
B_5_148_0 [ 2 ] = _rtP -> P_55 [ 2 ] * _rtDW -> NextOutput ; } _rtB ->
B_5_149_0 [ 0 ] = ( rtb_B_5_731_0 [ 0 ] + B_5_663_0 [ 0 ] ) + _rtB ->
B_5_148_0 [ 0 ] ; _rtB -> B_5_149_0 [ 1 ] = ( rtb_B_5_731_0 [ 1 ] + B_5_663_0
[ 1 ] ) + _rtB -> B_5_148_0 [ 1 ] ; _rtB -> B_5_149_0 [ 2 ] = ( rtb_B_5_731_0
[ 2 ] + B_5_663_0 [ 2 ] ) + _rtB -> B_5_148_0 [ 2 ] ; if ( ssIsSampleHit ( S
, 4 , 0 ) ) { _rtB -> B_5_150_0 [ 0 ] = _rtB -> B_5_149_0 [ 0 ] ; _rtB ->
B_5_150_0 [ 1 ] = _rtB -> B_5_149_0 [ 1 ] ; _rtB -> B_5_150_0 [ 2 ] = _rtB ->
B_5_149_0 [ 2 ] ; } ssCallAccelRunBlock ( S , 5 , 151 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_153_0 [ 0 ] = _rtP -> P_56
[ 0 ] ; _rtB -> B_5_153_0 [ 1 ] = _rtP -> P_56 [ 1 ] ; _rtB -> B_5_153_0 [ 2
] = _rtP -> P_56 [ 2 ] ; } _rtB -> B_5_154_0 [ 0 ] = _rtB -> B_5_151_0 .
vj2000 [ 0 ] + _rtB -> B_5_153_0 [ 0 ] ; _rtB -> B_5_154_0 [ 1 ] = _rtB ->
B_5_151_0 . vj2000 [ 1 ] + _rtB -> B_5_153_0 [ 1 ] ; _rtB -> B_5_154_0 [ 2 ]
= _rtB -> B_5_151_0 . vj2000 [ 2 ] + _rtB -> B_5_153_0 [ 2 ] ; if (
ssIsSampleHit ( S , 4 , 0 ) ) { B_5_155_0_idx_1 = _rtB -> B_5_154_0 [ 0 ] ;
B_5_155_0_idx = _rtB -> B_5_154_0 [ 1 ] ; B_5_155_0_idx_0 = _rtB -> B_5_154_0
[ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_156_0 [ 0 ] = _rtP
-> P_57 [ 0 ] ; _rtB -> B_5_156_0 [ 1 ] = _rtP -> P_57 [ 1 ] ; _rtB ->
B_5_156_0 [ 2 ] = _rtP -> P_57 [ 2 ] ; } _rtB -> B_5_157_0 [ 0 ] = _rtB ->
B_5_151_0 . j2000 [ 0 ] + _rtB -> B_5_156_0 [ 0 ] ; _rtB -> B_5_157_0 [ 1 ] =
_rtB -> B_5_151_0 . j2000 [ 1 ] + _rtB -> B_5_156_0 [ 1 ] ; _rtB -> B_5_157_0
[ 2 ] = _rtB -> B_5_151_0 . j2000 [ 2 ] + _rtB -> B_5_156_0 [ 2 ] ; if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_5_158_0 [ 0 ] = _rtB -> B_5_157_0 [
0 ] ; _rtB -> B_5_158_0 [ 1 ] = _rtB -> B_5_157_0 [ 1 ] ; _rtB -> B_5_158_0 [
2 ] = _rtB -> B_5_157_0 [ 2 ] ; _rtB -> B_5_160_0 [ 0 ] = B_5_155_0_idx *
_rtB -> B_5_158_0 [ 2 ] - B_5_155_0_idx_0 * _rtB -> B_5_158_0 [ 1 ] ; _rtB ->
B_5_160_0 [ 1 ] = B_5_155_0_idx_0 * _rtB -> B_5_158_0 [ 0 ] - B_5_155_0_idx_1
* _rtB -> B_5_158_0 [ 2 ] ; _rtB -> B_5_160_0 [ 2 ] = B_5_155_0_idx_1 * _rtB
-> B_5_158_0 [ 1 ] - B_5_155_0_idx * _rtB -> B_5_158_0 [ 0 ] ;
B_5_578_0_idx_0 = ( muDoubleScalarPower ( _rtB -> B_5_158_0 [ 0 ] , 2.0 ) +
muDoubleScalarPower ( _rtB -> B_5_158_0 [ 1 ] , 2.0 ) ) + muDoubleScalarPower
( _rtB -> B_5_158_0 [ 2 ] , 2.0 ) ; _rtB -> B_5_163_0 [ 0 ] = _rtP -> P_58 *
_rtB -> B_5_160_0 [ 0 ] / B_5_578_0_idx_0 ; _rtB -> B_5_163_0 [ 1 ] = _rtP ->
P_58 * _rtB -> B_5_160_0 [ 1 ] / B_5_578_0_idx_0 ; _rtB -> B_5_163_0 [ 2 ] =
_rtP -> P_58 * _rtB -> B_5_160_0 [ 2 ] / B_5_578_0_idx_0 ; } rtb_B_5_842_0 =
( ( B_5_66_0 [ 0 ] * B_5_66_0 [ 0 ] + B_5_66_0 [ 1 ] * B_5_66_0 [ 1 ] ) +
B_5_66_0 [ 2 ] * B_5_66_0 [ 2 ] ) + B_5_66_0 [ 3 ] * B_5_66_0 [ 3 ] ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_h != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_h = 0 ; } rtb_B_5_842_0 =
muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } else { if ( rtb_B_5_842_0 < 0.0 ) {
rtb_B_5_842_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_5_842_0 ) )
; } else { rtb_B_5_842_0 = muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } _rtDW ->
sqrt_DWORK1_h = 1 ; } rtb_B_5_785_0 = B_5_66_0 [ 2 ] / rtb_B_5_842_0 ;
B_5_578_0_idx = B_5_66_0 [ 3 ] / rtb_B_5_842_0 ; if ( ssIsSampleHit ( S , 1 ,
0 ) ) { _rtB -> B_5_174_0 = _rtP -> P_59 ; } B_5_578_0_idx_0 = B_5_66_0 [ 1 ]
/ rtb_B_5_842_0 ; rtb_B_5_842_0 = B_5_66_0 [ 0 ] / rtb_B_5_842_0 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_198_0 = _rtP -> P_64 ; _rtB ->
B_5_220_0 = _rtP -> P_69 ; } _rtB -> B_5_225_0 [ 0 ] = _rtB -> B_5_150_0 [ 0
] - ( ( ( ( _rtB -> B_5_174_0 - rtb_B_5_785_0 * rtb_B_5_785_0 ) -
B_5_578_0_idx * B_5_578_0_idx ) * _rtP -> P_60 * _rtB -> B_5_163_0 [ 0 ] + (
B_5_578_0_idx_0 * rtb_B_5_785_0 + rtb_B_5_842_0 * B_5_578_0_idx ) * _rtP ->
P_61 * _rtB -> B_5_163_0 [ 1 ] ) + ( B_5_578_0_idx_0 * B_5_578_0_idx -
rtb_B_5_842_0 * rtb_B_5_785_0 ) * _rtP -> P_62 * _rtB -> B_5_163_0 [ 2 ] ) ;
_rtB -> B_5_225_0 [ 1 ] = _rtB -> B_5_150_0 [ 1 ] - ( ( ( ( _rtB -> B_5_198_0
- B_5_578_0_idx_0 * B_5_578_0_idx_0 ) - B_5_578_0_idx * B_5_578_0_idx ) *
_rtP -> P_65 * _rtB -> B_5_163_0 [ 1 ] + ( B_5_578_0_idx_0 * rtb_B_5_785_0 -
rtb_B_5_842_0 * B_5_578_0_idx ) * _rtP -> P_63 * _rtB -> B_5_163_0 [ 0 ] ) +
( rtb_B_5_842_0 * B_5_578_0_idx_0 + rtb_B_5_785_0 * B_5_578_0_idx ) * _rtP ->
P_66 * _rtB -> B_5_163_0 [ 2 ] ) ; _rtB -> B_5_225_0 [ 2 ] = _rtB ->
B_5_150_0 [ 2 ] - ( ( ( B_5_578_0_idx_0 * B_5_578_0_idx + rtb_B_5_842_0 *
rtb_B_5_785_0 ) * _rtP -> P_67 * _rtB -> B_5_163_0 [ 0 ] + ( rtb_B_5_785_0 *
B_5_578_0_idx - rtb_B_5_842_0 * B_5_578_0_idx_0 ) * _rtP -> P_68 * _rtB ->
B_5_163_0 [ 1 ] ) + ( ( _rtB -> B_5_220_0 - B_5_578_0_idx_0 * B_5_578_0_idx_0
) - rtb_B_5_785_0 * rtb_B_5_785_0 ) * _rtP -> P_70 * _rtB -> B_5_163_0 [ 2 ]
) ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB -> B_5_436_0 [ i_0 ] = 0.0 ;
_rtB -> B_5_436_0 [ i_0 ] += rtb_B_5_424_0 [ i_0 ] * _rtB -> B_5_225_0 [ 0 ]
; _rtB -> B_5_436_0 [ i_0 ] += rtb_B_5_424_0 [ i_0 + 3 ] * _rtB -> B_5_225_0
[ 1 ] ; _rtB -> B_5_436_0 [ i_0 ] += rtb_B_5_424_0 [ i_0 + 6 ] * _rtB ->
B_5_225_0 [ 2 ] ; } ssCallAccelRunBlock ( S , 5 , 227 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsMajorTimeStep ( S ) ) { if ( ( ( X_ACStesbed_T * ) ssGetContStates
( S ) ) -> IntegratorLimited_CSTATE [ 0 ] >= _rtP -> P_72 ) { ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] =
_rtP -> P_72 ; } else if ( ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 0 ] <= _rtP -> P_73 ) { ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] = _rtP -> P_73 ; }
if ( ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 1 ] >= _rtP -> P_72 ) { ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = _rtP -> P_72 ; }
else if ( ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 1 ] <= _rtP -> P_73 ) { ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = _rtP -> P_73 ; }
if ( ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 2 ] >= _rtP -> P_72 ) { ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = _rtP -> P_72 ; }
else if ( ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 2 ] <= _rtP -> P_73 ) { ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = _rtP -> P_73 ; }
} _rtB -> B_5_744_0 [ 0 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 0 ] ; _rtB -> B_5_744_0 [ 1 ] = ( ( X_ACStesbed_T
* ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] ; _rtB ->
B_5_744_0 [ 2 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 2 ] ; ssCallAccelRunBlock ( S , 5 , 229 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsMajorTimeStep ( S ) ) { if ( ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 0 ]
>= _rtP -> P_75 ) { ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_d [ 0 ] = _rtP -> P_75 ; } else if ( ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 0 ]
<= _rtP -> P_76 ) { ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_d [ 0 ] = _rtP -> P_76 ; } if ( ( ( X_ACStesbed_T *
) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 1 ] >= _rtP -> P_75
) { ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_d [ 1 ] = _rtP -> P_75 ; } else if ( ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 1 ]
<= _rtP -> P_76 ) { ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_d [ 1 ] = _rtP -> P_76 ; } if ( ( ( X_ACStesbed_T *
) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ] >= _rtP -> P_75
) { ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_d [ 2 ] = _rtP -> P_75 ; } else if ( ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ]
<= _rtP -> P_76 ) { ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_d [ 2 ] = _rtP -> P_76 ; } } _rtB -> B_5_742_0 [ 0 ]
= ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d
[ 0 ] ; _rtB -> B_5_742_0 [ 1 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S )
) -> IntegratorLimited_CSTATE_d [ 1 ] ; _rtB -> B_5_742_0 [ 2 ] = ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ]
; rtb_B_5_731_0 [ 0 ] = _rtP -> P_77 * _rtB -> B_5_742_0 [ 0 ] ;
rtb_B_5_731_0 [ 1 ] = _rtP -> P_77 * _rtB -> B_5_742_0 [ 1 ] ; rtb_B_5_731_0
[ 2 ] = _rtP -> P_77 * _rtB -> B_5_742_0 [ 2 ] ; if ( ssIsSampleHit ( S , 4 ,
0 ) ) { B_5_578_0_idx = ( _rtB -> B_5_158_0 [ 0 ] * _rtB -> B_5_158_0 [ 0 ] +
_rtB -> B_5_158_0 [ 1 ] * _rtB -> B_5_158_0 [ 1 ] ) + _rtB -> B_5_158_0 [ 2 ]
* _rtB -> B_5_158_0 [ 2 ] ; if ( B_5_578_0_idx < 0.0 ) { _rtB -> B_5_234_0 =
- muDoubleScalarSqrt ( muDoubleScalarAbs ( B_5_578_0_idx ) ) ; } else { _rtB
-> B_5_234_0 = muDoubleScalarSqrt ( B_5_578_0_idx ) ; } _rtB -> B_5_235_0 [ 0
] = _rtB -> B_5_158_0 [ 0 ] * 0.0 ; _rtB -> B_5_235_0 [ 1 ] = _rtB ->
B_5_158_0 [ 1 ] * 0.0 ; _rtB -> B_5_235_0 [ 2 ] = _rtB -> B_5_158_0 [ 2 ] *
0.0 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_5_574_0 = _rtP -> P_78 ;
if ( _rtB -> B_5_234_0 > _rtP -> P_79 ) { B_5_578_0_idx = _rtB -> B_5_158_0 [
0 ] ; B_5_578_0_idx_0 = _rtB -> B_5_158_0 [ 1 ] ; rtb_B_5_842_0 = _rtB ->
B_5_158_0 [ 2 ] ; } else { B_5_578_0_idx = _rtB -> B_5_235_0 [ 0 ] ;
B_5_578_0_idx_0 = _rtB -> B_5_235_0 [ 1 ] ; rtb_B_5_842_0 = _rtB -> B_5_235_0
[ 2 ] ; } if ( _rtB -> B_5_234_0 > _rtP -> P_79 ) { rtb_B_5_785_0 = _rtB ->
B_5_234_0 ; } else { rtb_B_5_785_0 = _rtP -> P_78 ; } _rtB -> B_5_238_0 [ 0 ]
= B_5_578_0_idx / rtb_B_5_785_0 ; _rtB -> B_5_238_0 [ 1 ] = B_5_578_0_idx_0 /
rtb_B_5_785_0 ; _rtB -> B_5_238_0 [ 2 ] = rtb_B_5_842_0 / rtb_B_5_785_0 ; }
if ( ssIsSampleHit ( S , 4 , 0 ) ) { B_5_578_0_idx = ( _rtB -> B_5_160_0 [ 0
] * _rtB -> B_5_160_0 [ 0 ] + _rtB -> B_5_160_0 [ 1 ] * _rtB -> B_5_160_0 [ 1
] ) + _rtB -> B_5_160_0 [ 2 ] * _rtB -> B_5_160_0 [ 2 ] ; if ( B_5_578_0_idx
< 0.0 ) { _rtB -> B_5_241_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
B_5_578_0_idx ) ) ; } else { _rtB -> B_5_241_0 = muDoubleScalarSqrt (
B_5_578_0_idx ) ; } _rtB -> B_5_242_0 [ 0 ] = _rtB -> B_5_160_0 [ 0 ] * 0.0 ;
_rtB -> B_5_242_0 [ 1 ] = _rtB -> B_5_160_0 [ 1 ] * 0.0 ; _rtB -> B_5_242_0 [
2 ] = _rtB -> B_5_160_0 [ 2 ] * 0.0 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
if ( _rtB -> B_5_241_0 > _rtP -> P_81 ) { B_5_578_0_idx = _rtB -> B_5_160_0 [
0 ] ; B_5_578_0_idx_0 = _rtB -> B_5_160_0 [ 1 ] ; rtb_B_5_842_0 = _rtB ->
B_5_160_0 [ 2 ] ; } else { B_5_578_0_idx = _rtB -> B_5_242_0 [ 0 ] ;
B_5_578_0_idx_0 = _rtB -> B_5_242_0 [ 1 ] ; rtb_B_5_842_0 = _rtB -> B_5_242_0
[ 2 ] ; } if ( _rtB -> B_5_241_0 > _rtP -> P_81 ) { rtb_B_5_785_0 = _rtB ->
B_5_241_0 ; } else { rtb_B_5_785_0 = _rtP -> P_80 ; } _rtB -> B_5_245_0 [ 0 ]
= B_5_578_0_idx / rtb_B_5_785_0 ; _rtB -> B_5_245_0 [ 1 ] = B_5_578_0_idx_0 /
rtb_B_5_785_0 ; _rtB -> B_5_245_0 [ 2 ] = rtb_B_5_842_0 / rtb_B_5_785_0 ;
_rtB -> B_5_247_0 [ 0 ] = _rtB -> B_5_238_0 [ 1 ] * _rtB -> B_5_245_0 [ 2 ] -
_rtB -> B_5_238_0 [ 2 ] * _rtB -> B_5_245_0 [ 1 ] ; _rtB -> B_5_247_0 [ 1 ] =
_rtB -> B_5_238_0 [ 2 ] * _rtB -> B_5_245_0 [ 0 ] - _rtB -> B_5_238_0 [ 0 ] *
_rtB -> B_5_245_0 [ 2 ] ; _rtB -> B_5_247_0 [ 2 ] = _rtB -> B_5_238_0 [ 0 ] *
_rtB -> B_5_245_0 [ 1 ] - _rtB -> B_5_238_0 [ 1 ] * _rtB -> B_5_245_0 [ 0 ] ;
rtb_B_5_594_0 [ 0 ] = _rtB -> B_5_247_0 [ 0 ] ; rtb_B_5_594_0 [ 1 ] = _rtB ->
B_5_247_0 [ 1 ] ; rtb_B_5_594_0 [ 2 ] = _rtB -> B_5_247_0 [ 2 ] ;
rtb_B_5_594_0 [ 3 ] = _rtB -> B_5_238_0 [ 0 ] ; rtb_B_5_594_0 [ 4 ] = _rtB ->
B_5_238_0 [ 1 ] ; rtb_B_5_594_0 [ 5 ] = _rtB -> B_5_238_0 [ 2 ] ;
rtb_B_5_594_0 [ 6 ] = _rtB -> B_5_245_0 [ 0 ] ; rtb_B_5_594_0 [ 7 ] = _rtB ->
B_5_245_0 [ 1 ] ; rtb_B_5_594_0 [ 8 ] = _rtB -> B_5_245_0 [ 2 ] ; for ( i_0 =
0 ; i_0 < 3 ; i_0 ++ ) { rtb_B_5_252_0 [ 3 * i_0 ] = rtb_B_5_594_0 [ i_0 ] ;
rtb_B_5_252_0 [ 1 + 3 * i_0 ] = rtb_B_5_594_0 [ i_0 + 3 ] ; rtb_B_5_252_0 [ 2
+ 3 * i_0 ] = rtb_B_5_594_0 [ i_0 + 6 ] ; } B_5_578_0_idx = ( rtb_B_5_252_0 [
0 ] + rtb_B_5_252_0 [ 4 ] ) + rtb_B_5_252_0 [ 8 ] ; rtPrevAction = _rtDW ->
If_ActiveSubsystem ; if ( ssIsMajorTimeStep ( S ) ) { if ( B_5_578_0_idx >
0.0 ) { rtAction = 0 ; } else { rtAction = 1 ; } _rtDW -> If_ActiveSubsystem
= rtAction ; } else { rtAction = _rtDW -> If_ActiveSubsystem ; } if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
ssSetSolverNeedsReset ( S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ;
switch ( _rtDW -> FindMaximumDiagonalValue_ActiveSubsystem ) { case 0 :
ssSetSolverNeedsReset ( S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ;
break ; case 2 : ssSetSolverNeedsReset ( S ) ; break ; } _rtDW ->
FindMaximumDiagonalValue_ActiveSubsystem = - 1 ; break ; } } switch (
rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime (
S , 1 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } }
B_5_578_0_idx_0 = B_5_578_0_idx + _rtP -> P_0 ; if ( ssIsMajorTimeStep ( S )
) { if ( _rtDW -> sqrt_DWORK1_f != 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW
-> sqrt_DWORK1_f = 0 ; } B_5_578_0_idx_0 = muDoubleScalarSqrt (
B_5_578_0_idx_0 ) ; } else { if ( B_5_578_0_idx_0 < 0.0 ) { B_5_578_0_idx_0 =
- muDoubleScalarSqrt ( muDoubleScalarAbs ( B_5_578_0_idx_0 ) ) ; } else {
B_5_578_0_idx_0 = muDoubleScalarSqrt ( B_5_578_0_idx_0 ) ; } _rtDW ->
sqrt_DWORK1_f = 1 ; } _rtB -> B_5_257_0 [ 0 ] = _rtP -> P_1 * B_5_578_0_idx_0
; B_5_578_0_idx_0 *= _rtP -> P_2 ; _rtB -> B_5_257_0 [ 1 ] = ( rtb_B_5_252_0
[ 7 ] - rtb_B_5_252_0 [ 5 ] ) / B_5_578_0_idx_0 ; _rtB -> B_5_257_0 [ 2 ] = (
rtb_B_5_252_0 [ 2 ] - rtb_B_5_252_0 [ 6 ] ) / B_5_578_0_idx_0 ; _rtB ->
B_5_257_0 [ 3 ] = ( rtb_B_5_252_0 [ 3 ] - rtb_B_5_252_0 [ 1 ] ) /
B_5_578_0_idx_0 ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
PositiveTrace_SubsysRanBC ) ; } break ; case 1 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } rtPrevAction = _rtDW ->
FindMaximumDiagonalValue_ActiveSubsystem ; if ( ( rtb_B_5_252_0 [ 4 ] >
rtb_B_5_252_0 [ 0 ] ) && ( rtb_B_5_252_0 [ 4 ] > rtb_B_5_252_0 [ 8 ] ) ) {
rtAction = 0 ; } else if ( rtb_B_5_252_0 [ 8 ] > rtb_B_5_252_0 [ 0 ] ) {
rtAction = 1 ; } else { rtAction = 2 ; } _rtDW ->
FindMaximumDiagonalValue_ActiveSubsystem = rtAction ; if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : ssSetSolverNeedsReset ( S ) ;
break ; case 1 : ssSetSolverNeedsReset ( S ) ; break ; case 2 :
ssSetSolverNeedsReset ( S ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S
) ) { ssSetSolverNeedsReset ( S ) ; } } B_5_578_0_idx_0 = ( ( rtb_B_5_252_0 [
4 ] - rtb_B_5_252_0 [ 0 ] ) - rtb_B_5_252_0 [ 8 ] ) + _rtP -> P_3 ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_i != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_i = 0 ; } B_5_578_0_idx_0
= muDoubleScalarSqrt ( B_5_578_0_idx_0 ) ; } else { if ( B_5_578_0_idx_0 <
0.0 ) { B_5_578_0_idx_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
B_5_578_0_idx_0 ) ) ; } else { B_5_578_0_idx_0 = muDoubleScalarSqrt (
B_5_578_0_idx_0 ) ; } _rtDW -> sqrt_DWORK1_i = 1 ; } _rtB -> B_5_257_0 [ 2 ]
= _rtP -> P_4 * B_5_578_0_idx_0 ; if ( B_5_578_0_idx_0 != 0.0 ) {
B_5_578_0_idx = _rtP -> P_5 ; } else { B_5_578_0_idx = _rtP -> P_6 [ 0 ] ;
B_5_578_0_idx_0 = _rtP -> P_6 [ 1 ] ; } B_5_578_0_idx_0 = B_5_578_0_idx /
B_5_578_0_idx_0 ; _rtB -> B_5_257_0 [ 1 ] = ( rtb_B_5_252_0 [ 1 ] +
rtb_B_5_252_0 [ 3 ] ) * B_5_578_0_idx_0 * _rtP -> P_7 ; _rtB -> B_5_257_0 [ 3
] = ( rtb_B_5_252_0 [ 5 ] + rtb_B_5_252_0 [ 7 ] ) * B_5_578_0_idx_0 * _rtP ->
P_8 ; _rtB -> B_5_257_0 [ 0 ] = ( rtb_B_5_252_0 [ 2 ] - rtb_B_5_252_0 [ 6 ] )
* B_5_578_0_idx_0 * _rtP -> P_9 ; srUpdateBC ( _rtDW ->
MaximumValueatDCM22_SubsysRanBC ) ; break ; case 1 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } B_5_578_0_idx_0 = ( ( rtb_B_5_252_0 [ 8 ] -
rtb_B_5_252_0 [ 0 ] ) - rtb_B_5_252_0 [ 4 ] ) + _rtP -> P_10 ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_a != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_a = 0 ; } B_5_578_0_idx_0
= muDoubleScalarSqrt ( B_5_578_0_idx_0 ) ; } else { if ( B_5_578_0_idx_0 <
0.0 ) { B_5_578_0_idx_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
B_5_578_0_idx_0 ) ) ; } else { B_5_578_0_idx_0 = muDoubleScalarSqrt (
B_5_578_0_idx_0 ) ; } _rtDW -> sqrt_DWORK1_a = 1 ; } _rtB -> B_5_257_0 [ 3 ]
= _rtP -> P_11 * B_5_578_0_idx_0 ; if ( B_5_578_0_idx_0 != 0.0 ) {
B_5_578_0_idx = _rtP -> P_12 ; } else { B_5_578_0_idx = _rtP -> P_13 [ 0 ] ;
B_5_578_0_idx_0 = _rtP -> P_13 [ 1 ] ; } B_5_578_0_idx_0 = B_5_578_0_idx /
B_5_578_0_idx_0 ; _rtB -> B_5_257_0 [ 1 ] = ( rtb_B_5_252_0 [ 2 ] +
rtb_B_5_252_0 [ 6 ] ) * B_5_578_0_idx_0 * _rtP -> P_14 ; _rtB -> B_5_257_0 [
2 ] = ( rtb_B_5_252_0 [ 5 ] + rtb_B_5_252_0 [ 7 ] ) * B_5_578_0_idx_0 * _rtP
-> P_15 ; _rtB -> B_5_257_0 [ 0 ] = ( rtb_B_5_252_0 [ 3 ] - rtb_B_5_252_0 [ 1
] ) * B_5_578_0_idx_0 * _rtP -> P_16 ; srUpdateBC ( _rtDW ->
MaximumValueatDCM33_SubsysRanBC ) ; break ; case 2 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } B_5_578_0_idx_0 = ( ( rtb_B_5_252_0 [ 0 ] -
rtb_B_5_252_0 [ 4 ] ) - rtb_B_5_252_0 [ 8 ] ) + _rtP -> P_17 ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_da != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_da = 0 ; } B_5_578_0_idx_0
= muDoubleScalarSqrt ( B_5_578_0_idx_0 ) ; } else { if ( B_5_578_0_idx_0 <
0.0 ) { B_5_578_0_idx_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
B_5_578_0_idx_0 ) ) ; } else { B_5_578_0_idx_0 = muDoubleScalarSqrt (
B_5_578_0_idx_0 ) ; } _rtDW -> sqrt_DWORK1_da = 1 ; } _rtB -> B_5_257_0 [ 1 ]
= _rtP -> P_18 * B_5_578_0_idx_0 ; if ( B_5_578_0_idx_0 != 0.0 ) {
B_5_578_0_idx = _rtP -> P_19 ; } else { B_5_578_0_idx = _rtP -> P_20 [ 0 ] ;
B_5_578_0_idx_0 = _rtP -> P_20 [ 1 ] ; } B_5_578_0_idx_0 = B_5_578_0_idx /
B_5_578_0_idx_0 ; _rtB -> B_5_257_0 [ 2 ] = ( rtb_B_5_252_0 [ 1 ] +
rtb_B_5_252_0 [ 3 ] ) * B_5_578_0_idx_0 * _rtP -> P_21 ; _rtB -> B_5_257_0 [
3 ] = ( rtb_B_5_252_0 [ 2 ] + rtb_B_5_252_0 [ 6 ] ) * B_5_578_0_idx_0 * _rtP
-> P_22 ; _rtB -> B_5_257_0 [ 0 ] = ( rtb_B_5_252_0 [ 7 ] - rtb_B_5_252_0 [ 5
] ) * B_5_578_0_idx_0 * _rtP -> P_23 ; srUpdateBC ( _rtDW ->
MaximumValueatDCM11_SubsysRanBC ) ; break ; } if ( ssIsMajorTimeStep ( S ) )
{ srUpdateBC ( _rtDW -> NegativeTrace_SubsysRanBC ) ; } break ; }
rtb_B_5_574_0 = ( ( _rtB -> B_5_257_0 [ 0 ] * _rtB -> B_5_257_0 [ 0 ] + _rtB
-> B_5_257_0 [ 1 ] * _rtB -> B_5_257_0 [ 1 ] ) + _rtB -> B_5_257_0 [ 2 ] *
_rtB -> B_5_257_0 [ 2 ] ) + _rtB -> B_5_257_0 [ 3 ] * _rtB -> B_5_257_0 [ 3 ]
; _rtB -> B_5_263_0 = _rtB -> B_5_257_0 [ 0 ] / rtb_B_5_574_0 ; _rtB ->
B_5_266_0 = - _rtB -> B_5_257_0 [ 1 ] / rtb_B_5_574_0 ; _rtB -> B_5_269_0 = -
_rtB -> B_5_257_0 [ 2 ] / rtb_B_5_574_0 ; _rtB -> B_5_272_0 = - _rtB ->
B_5_257_0 [ 3 ] / rtb_B_5_574_0 ; } _rtB -> B_5_274_0 = ( ( _rtB -> B_5_263_0
* B_5_66_0 [ 0 ] - _rtB -> B_5_266_0 * B_5_66_0 [ 1 ] ) - _rtB -> B_5_269_0 *
B_5_66_0 [ 2 ] ) - _rtB -> B_5_272_0 * B_5_66_0 [ 3 ] ; _rtB -> B_5_730_0 = (
( _rtB -> B_5_263_0 * B_5_66_0 [ 1 ] + _rtB -> B_5_266_0 * B_5_66_0 [ 0 ] ) +
_rtB -> B_5_269_0 * B_5_66_0 [ 3 ] ) - _rtB -> B_5_272_0 * B_5_66_0 [ 2 ] ;
_rtB -> B_5_713_0 = ( ( _rtB -> B_5_263_0 * B_5_66_0 [ 2 ] - _rtB ->
B_5_266_0 * B_5_66_0 [ 3 ] ) + _rtB -> B_5_269_0 * B_5_66_0 [ 0 ] ) + _rtB ->
B_5_272_0 * B_5_66_0 [ 1 ] ; _rtB -> B_5_696_0 = ( ( _rtB -> B_5_263_0 *
B_5_66_0 [ 3 ] + _rtB -> B_5_266_0 * B_5_66_0 [ 2 ] ) - _rtB -> B_5_269_0 *
B_5_66_0 [ 1 ] ) + _rtB -> B_5_272_0 * B_5_66_0 [ 0 ] ; B_5_663_0 [ 0 ] =
_rtB -> B_5_274_0 * _rtB -> B_5_730_0 ; B_5_663_0 [ 1 ] = _rtB -> B_5_274_0 *
_rtB -> B_5_713_0 ; B_5_663_0 [ 2 ] = _rtB -> B_5_274_0 * _rtB -> B_5_696_0 ;
for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB -> B_5_291_0 [ i_0 ] = 0.0 ; _rtB
-> B_5_291_0 [ i_0 ] += _rtB -> B_5_139_0 [ i_0 ] * B_5_663_0 [ 0 ] ; _rtB ->
B_5_291_0 [ i_0 ] += _rtB -> B_5_139_0 [ i_0 + 3 ] * B_5_663_0 [ 1 ] ; _rtB
-> B_5_291_0 [ i_0 ] += _rtB -> B_5_139_0 [ i_0 + 6 ] * B_5_663_0 [ 2 ] ; }
if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> B_5_292_0 [ 0 ] = _rtP -> P_83 *
_rtB -> B_5_291_0 [ 0 ] ; _rtB -> B_5_292_0 [ 1 ] = _rtP -> P_83 * _rtB ->
B_5_291_0 [ 1 ] ; _rtB -> B_5_292_0 [ 2 ] = _rtP -> P_83 * _rtB -> B_5_291_0
[ 2 ] ; } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { B_5_663_0 [ i_0 ] = 0.0 ;
B_5_663_0 [ i_0 ] += _rtB -> B_5_139_0 [ i_0 ] * _rtB -> B_5_225_0 [ 0 ] ;
B_5_663_0 [ i_0 ] += _rtB -> B_5_139_0 [ i_0 + 3 ] * _rtB -> B_5_225_0 [ 1 ]
; B_5_663_0 [ i_0 ] += _rtB -> B_5_139_0 [ i_0 + 6 ] * _rtB -> B_5_225_0 [ 2
] ; } _rtB -> B_5_668_0 [ 0 ] = _rtP -> P_84 * B_5_663_0 [ 0 ] + _rtB ->
B_5_292_0 [ 0 ] ; _rtB -> B_5_668_0 [ 1 ] = _rtP -> P_84 * B_5_663_0 [ 1 ] +
_rtB -> B_5_292_0 [ 1 ] ; _rtB -> B_5_668_0 [ 2 ] = _rtP -> P_84 * B_5_663_0
[ 2 ] + _rtB -> B_5_292_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { for (
i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { y [ i_0 ] = _rtB -> B_5_139_0 [ i_0 + 6 ] *
_rtB -> B_5_150_0 [ 2 ] + ( _rtB -> B_5_139_0 [ i_0 + 3 ] * _rtB -> B_5_150_0
[ 1 ] + _rtB -> B_5_139_0 [ i_0 ] * _rtB -> B_5_150_0 [ 0 ] ) ; } tmp [ 0 ] =
_rtB -> B_5_150_0 [ 1 ] ; tmp [ 1 ] = _rtB -> B_5_150_0 [ 2 ] ; tmp [ 2 ] =
_rtB -> B_5_150_0 [ 0 ] ; tmp [ 3 ] = _rtB -> B_5_150_0 [ 2 ] ; tmp [ 4 ] =
_rtB -> B_5_150_0 [ 0 ] ; tmp [ 5 ] = _rtB -> B_5_150_0 [ 1 ] ; y_1 [ 0 ] = y
[ 2 ] ; y_1 [ 1 ] = y [ 0 ] ; y_1 [ 2 ] = y [ 1 ] ; y_1 [ 3 ] = y [ 1 ] ; y_1
[ 4 ] = y [ 2 ] ; y_1 [ 5 ] = y [ 0 ] ; for ( i_0 = 0 ; i_0 < 6 ; i_0 ++ ) {
rtb_B_5_159_0 [ i_0 ] = tmp [ i_0 ] * y_1 [ i_0 ] ; } _rtB -> B_5_298_0 [ 0 ]
= rtb_B_5_159_0 [ 0 ] - rtb_B_5_159_0 [ 3 ] ; _rtB -> B_5_298_0 [ 1 ] =
rtb_B_5_159_0 [ 1 ] - rtb_B_5_159_0 [ 4 ] ; _rtB -> B_5_298_0 [ 2 ] =
rtb_B_5_159_0 [ 2 ] - rtb_B_5_159_0 [ 5 ] ; memcpy ( & rtb_B_5_594_0 [ 0 ] ,
& _rtP -> P_85 [ 0 ] , 9U * sizeof ( real_T ) ) ; for ( i_0 = 0 ; i_0 < 3 ;
i_0 ++ ) { _rtB -> B_5_301_0 [ i_0 ] = 0.0 ; _rtB -> B_5_301_0 [ i_0 ] +=
_rtP -> P_85 [ i_0 ] * _rtB -> B_5_150_0 [ 0 ] ; _rtB -> B_5_301_0 [ i_0 ] +=
_rtP -> P_85 [ i_0 + 3 ] * _rtB -> B_5_150_0 [ 1 ] ; _rtB -> B_5_301_0 [ i_0
] += _rtP -> P_85 [ i_0 + 6 ] * _rtB -> B_5_150_0 [ 2 ] ; } _rtB -> B_5_305_0
[ 0 ] = _rtB -> B_5_150_0 [ 1 ] * _rtP -> P_86 [ 2 ] - _rtB -> B_5_150_0 [ 2
] * _rtP -> P_86 [ 1 ] ; _rtB -> B_5_305_0 [ 1 ] = _rtB -> B_5_150_0 [ 2 ] *
_rtP -> P_86 [ 0 ] - _rtB -> B_5_150_0 [ 0 ] * _rtP -> P_86 [ 2 ] ; _rtB ->
B_5_305_0 [ 2 ] = _rtB -> B_5_150_0 [ 0 ] * _rtP -> P_86 [ 1 ] - _rtB ->
B_5_150_0 [ 1 ] * _rtP -> P_86 [ 0 ] ; } _rtB -> B_5_306_0 [ 0 ] = ( ( _rtB
-> B_5_668_0 [ 0 ] - _rtB -> B_5_298_0 [ 0 ] ) - _rtB -> B_5_301_0 [ 0 ] ) -
_rtB -> B_5_305_0 [ 0 ] ; _rtB -> B_5_306_0 [ 1 ] = ( ( _rtB -> B_5_668_0 [ 1
] - _rtB -> B_5_298_0 [ 1 ] ) - _rtB -> B_5_301_0 [ 1 ] ) - _rtB -> B_5_305_0
[ 1 ] ; _rtB -> B_5_306_0 [ 2 ] = ( ( _rtB -> B_5_668_0 [ 2 ] - _rtB ->
B_5_298_0 [ 2 ] ) - _rtB -> B_5_301_0 [ 2 ] ) - _rtB -> B_5_305_0 [ 2 ] ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> Saturation_MODE [ 0 ] = _rtB ->
B_5_306_0 [ 0 ] >= _rtP -> P_87 ? 1 : _rtB -> B_5_306_0 [ 0 ] > _rtP -> P_88
? 0 : - 1 ; _rtDW -> Saturation_MODE [ 1 ] = _rtB -> B_5_306_0 [ 1 ] >= _rtP
-> P_87 ? 1 : _rtB -> B_5_306_0 [ 1 ] > _rtP -> P_88 ? 0 : - 1 ; _rtDW ->
Saturation_MODE [ 2 ] = _rtB -> B_5_306_0 [ 2 ] >= _rtP -> P_87 ? 1 : _rtB ->
B_5_306_0 [ 2 ] > _rtP -> P_88 ? 0 : - 1 ; } B_5_663_0 [ 0 ] = _rtDW ->
Saturation_MODE [ 0 ] == 1 ? _rtP -> P_87 : _rtDW -> Saturation_MODE [ 0 ] ==
- 1 ? _rtP -> P_88 : _rtB -> B_5_306_0 [ 0 ] ; B_5_663_0 [ 1 ] = _rtDW ->
Saturation_MODE [ 1 ] == 1 ? _rtP -> P_87 : _rtDW -> Saturation_MODE [ 1 ] ==
- 1 ? _rtP -> P_88 : _rtB -> B_5_306_0 [ 1 ] ; B_5_663_0 [ 2 ] = _rtDW ->
Saturation_MODE [ 2 ] == 1 ? _rtP -> P_87 : _rtDW -> Saturation_MODE [ 2 ] ==
- 1 ? _rtP -> P_88 : _rtB -> B_5_306_0 [ 2 ] ; if ( ssIsSampleHit ( S , 3 , 0
) ) { _rtB -> B_5_308_0 [ 0 ] = B_5_663_0 [ 0 ] ; _rtB -> B_5_308_0 [ 1 ] =
B_5_663_0 [ 1 ] ; _rtB -> B_5_308_0 [ 2 ] = B_5_663_0 [ 2 ] ; }
ssCallAccelRunBlock ( S , 5 , 309 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 3 , 0 ) ) { rtb_B_5_842_0 = _rtP -> P_89 * _rtB ->
B_5_308_0 [ 0 ] ; if ( rtb_B_5_842_0 >= _rtP -> P_90 ) { _rtB -> B_5_311_0 [
0 ] = _rtP -> P_90 ; } else if ( rtb_B_5_842_0 <= _rtP -> P_91 ) { _rtB ->
B_5_311_0 [ 0 ] = _rtP -> P_91 ; } else { _rtB -> B_5_311_0 [ 0 ] =
rtb_B_5_842_0 ; } rtb_B_5_842_0 = _rtP -> P_89 * _rtB -> B_5_308_0 [ 1 ] ; if
( rtb_B_5_842_0 >= _rtP -> P_90 ) { _rtB -> B_5_311_0 [ 1 ] = _rtP -> P_90 ;
} else if ( rtb_B_5_842_0 <= _rtP -> P_91 ) { _rtB -> B_5_311_0 [ 1 ] = _rtP
-> P_91 ; } else { _rtB -> B_5_311_0 [ 1 ] = rtb_B_5_842_0 ; } rtb_B_5_842_0
= _rtP -> P_89 * _rtB -> B_5_308_0 [ 2 ] ; if ( rtb_B_5_842_0 >= _rtP -> P_90
) { _rtB -> B_5_311_0 [ 2 ] = _rtP -> P_90 ; } else if ( rtb_B_5_842_0 <=
_rtP -> P_91 ) { _rtB -> B_5_311_0 [ 2 ] = _rtP -> P_91 ; } else { _rtB ->
B_5_311_0 [ 2 ] = rtb_B_5_842_0 ; } _rtB -> B_5_312_0 [ 0 ] = _rtB ->
B_5_436_0 [ 0 ] ; _rtB -> B_5_312_0 [ 1 ] = _rtB -> B_5_436_0 [ 1 ] ; _rtB ->
B_5_312_0 [ 2 ] = _rtB -> B_5_436_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0
) ) { _rtB -> B_5_313_0 [ 0 ] = _rtP -> P_92 [ 0 ] ; _rtB -> B_5_313_0 [ 1 ]
= _rtP -> P_92 [ 1 ] ; _rtB -> B_5_313_0 [ 2 ] = _rtP -> P_92 [ 2 ] ; _rtB ->
B_5_314_0 = _rtP -> P_93 ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) { memset ( &
_rtB -> B_5_328_0 [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; _rtB -> B_5_328_0 [
0 ] = _rtB -> B_5_150_0 [ 0 ] ; _rtB -> B_5_328_0 [ 4 ] = _rtB -> B_5_150_0 [
1 ] ; _rtB -> B_5_328_0 [ 8 ] = _rtB -> B_5_150_0 [ 2 ] ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_5_326_0 [ 0 ] = _rtB -> B_5_150_0 [ 1 ]
; rtb_B_5_326_0 [ 1 ] = _rtB -> B_5_150_0 [ 0 ] ; rtb_B_5_326_0 [ 2 ] = _rtP
-> P_94 ; rtb_B_5_326_0 [ 3 ] = _rtB -> B_5_150_0 [ 2 ] ; rtb_B_5_326_0 [ 4 ]
= _rtP -> P_94 ; rtb_B_5_326_0 [ 5 ] = _rtB -> B_5_150_0 [ 0 ] ;
rtb_B_5_326_0 [ 6 ] = _rtP -> P_94 ; rtb_B_5_326_0 [ 7 ] = _rtB -> B_5_150_0
[ 2 ] ; rtb_B_5_326_0 [ 8 ] = _rtB -> B_5_150_0 [ 1 ] ; memcpy ( & _rtB ->
B_5_328_0 [ 9 ] , & rtb_B_5_326_0 [ 0 ] , 9U * sizeof ( real_T ) ) ;
rtb_B_5_574_0 = _rtP -> P_95 ; rtb_B_5_340_0 [ 0 ] = _rtP -> P_95 ;
rtb_B_5_340_0 [ 1 ] = _rtB -> B_5_150_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 4
, 0 ) ) { _rtB -> B_5_332_0 [ 0 ] = _rtP -> P_96 * _rtB -> B_5_150_0 [ 0 ] ;
_rtB -> B_5_332_0 [ 1 ] = _rtP -> P_96 * _rtB -> B_5_150_0 [ 1 ] ; _rtB ->
B_5_332_0 [ 2 ] = _rtP -> P_96 * _rtB -> B_5_150_0 [ 2 ] ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_5_340_0 [ 2 ] = _rtB -> B_5_332_0 [ 1 ]
; rtb_B_5_340_0 [ 3 ] = _rtB -> B_5_332_0 [ 2 ] ; rtb_B_5_340_0 [ 4 ] =
rtb_B_5_574_0 ; rtb_B_5_340_0 [ 5 ] = _rtB -> B_5_150_0 [ 0 ] ; rtb_B_5_340_0
[ 6 ] = _rtB -> B_5_150_0 [ 1 ] ; rtb_B_5_340_0 [ 7 ] = _rtB -> B_5_332_0 [ 0
] ; rtb_B_5_340_0 [ 8 ] = rtb_B_5_574_0 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ )
{ for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> B_5_341_0 [ i_0 + 3 * i ] = 0.0 ;
_rtB -> B_5_341_0 [ i_0 + 3 * i ] += _rtB -> B_5_328_0 [ 3 * i ] *
rtb_B_5_340_0 [ i_0 ] ; _rtB -> B_5_341_0 [ i_0 + 3 * i ] += _rtB ->
B_5_328_0 [ 3 * i + 1 ] * rtb_B_5_340_0 [ i_0 + 3 ] ; _rtB -> B_5_341_0 [ i_0
+ 3 * i ] += _rtB -> B_5_328_0 [ 3 * i + 2 ] * rtb_B_5_340_0 [ i_0 + 6 ] ; }
} } if ( ssIsSampleHit ( S , 5 , 0 ) ) { if ( _rtDW ->
DiscreteTimeIntegrator_IC_LOADING != 0 ) { for ( i = 0 ; i < 18 ; i ++ ) {
_rtDW -> DiscreteTimeIntegrator_DSTATE [ i ] = 0.0 ; _rtB -> B_5_342_0 [ i ]
= _rtDW -> DiscreteTimeIntegrator_DSTATE [ i ] ; } } else { for ( i = 0 ; i <
18 ; i ++ ) { _rtB -> B_5_342_0 [ i ] = _rtP -> P_97 * _rtB -> B_5_341_0 [ i
] + _rtDW -> DiscreteTimeIntegrator_DSTATE [ i ] ; } } } if ( ssIsSampleHit (
S , 1 , 0 ) ) { for ( i = 0 ; i < 18 ; i ++ ) { _rtB -> B_5_418_0 [ i ] =
_rtB -> B_5_328_0 [ i ] + _rtB -> B_5_342_0 [ i ] ; } _rtB -> B_5_344_0 =
_rtP -> P_98 ; } _rtB -> B_5_416_0 [ 0 ] = _rtB -> B_5_344_0 ; rtb_B_5_842_0
= ( ( B_5_66_0 [ 0 ] * B_5_66_0 [ 0 ] + B_5_66_0 [ 1 ] * B_5_66_0 [ 1 ] ) +
B_5_66_0 [ 2 ] * B_5_66_0 [ 2 ] ) + B_5_66_0 [ 3 ] * B_5_66_0 [ 3 ] ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_n != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_n = 0 ; } rtb_B_5_842_0 =
muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } else { if ( rtb_B_5_842_0 < 0.0 ) {
rtb_B_5_842_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_5_842_0 ) )
; } else { rtb_B_5_842_0 = muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } _rtDW ->
sqrt_DWORK1_n = 1 ; } rtb_B_5_785_0 = B_5_66_0 [ 1 ] / rtb_B_5_842_0 ;
B_5_578_0_idx = B_5_66_0 [ 3 ] / rtb_B_5_842_0 ; B_5_578_0_idx_0 = B_5_66_0 [
0 ] / rtb_B_5_842_0 ; rtb_B_5_842_0 = B_5_66_0 [ 2 ] / rtb_B_5_842_0 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_368_0 = _rtP -> P_101 ; }
rtb_B_5_766_0 = ( ( rtb_B_5_785_0 * B_5_578_0_idx + B_5_578_0_idx_0 *
rtb_B_5_842_0 ) * _rtP -> P_99 * _rtB -> B_5_313_0 [ 0 ] + ( rtb_B_5_842_0 *
B_5_578_0_idx - B_5_578_0_idx_0 * rtb_B_5_785_0 ) * _rtP -> P_100 * _rtB ->
B_5_313_0 [ 1 ] ) + ( ( _rtB -> B_5_368_0 - rtb_B_5_785_0 * rtb_B_5_785_0 ) -
rtb_B_5_842_0 * rtb_B_5_842_0 ) * _rtP -> P_102 * _rtB -> B_5_313_0 [ 2 ] ;
_rtB -> B_5_416_0 [ 1 ] = rtb_B_5_766_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> B_5_376_0 = _rtP -> P_103 ; } rtb_B_5_767_0 = ( ( ( _rtB ->
B_5_376_0 - rtb_B_5_842_0 * rtb_B_5_842_0 ) - B_5_578_0_idx * B_5_578_0_idx )
* _rtP -> P_104 * _rtB -> B_5_313_0 [ 0 ] + ( rtb_B_5_785_0 * rtb_B_5_842_0 +
B_5_578_0_idx_0 * B_5_578_0_idx ) * _rtP -> P_105 * _rtB -> B_5_313_0 [ 1 ] )
+ ( rtb_B_5_785_0 * B_5_578_0_idx - B_5_578_0_idx_0 * rtb_B_5_842_0 ) * _rtP
-> P_106 * _rtB -> B_5_313_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> B_5_398_0 = _rtP -> P_108 ; } rtb_B_5_842_0 = ( ( ( _rtB -> B_5_398_0
- rtb_B_5_785_0 * rtb_B_5_785_0 ) - B_5_578_0_idx * B_5_578_0_idx ) * _rtP ->
P_109 * _rtB -> B_5_313_0 [ 1 ] + ( rtb_B_5_785_0 * rtb_B_5_842_0 -
B_5_578_0_idx_0 * B_5_578_0_idx ) * _rtP -> P_107 * _rtB -> B_5_313_0 [ 0 ] )
+ ( B_5_578_0_idx_0 * rtb_B_5_785_0 + rtb_B_5_842_0 * B_5_578_0_idx ) * _rtP
-> P_110 * _rtB -> B_5_313_0 [ 2 ] ; B_5_663_0 [ 0 ] = _rtP -> P_111 *
rtb_B_5_767_0 ; B_5_663_0 [ 1 ] = _rtP -> P_111 * rtb_B_5_842_0 ; B_5_663_0 [
2 ] = _rtP -> P_111 * rtb_B_5_766_0 ; _rtB -> B_5_416_0 [ 2 ] = B_5_663_0 [ 1
] ; _rtB -> B_5_416_0 [ 3 ] = B_5_663_0 [ 2 ] ; _rtB -> B_5_416_0 [ 4 ] =
_rtB -> B_5_344_0 ; _rtB -> B_5_416_0 [ 5 ] = rtb_B_5_767_0 ; _rtB ->
B_5_416_0 [ 6 ] = rtb_B_5_842_0 ; _rtB -> B_5_416_0 [ 7 ] = B_5_663_0 [ 0 ] ;
_rtB -> B_5_416_0 [ 8 ] = _rtB -> B_5_344_0 ; if ( ssIsSampleHit ( S , 5 , 0
) ) { for ( i = 0 ; i < 9 ; i ++ ) { if ( _rtDW ->
DiscreteTimeIntegrator1_SYSTEM_ENABLE != 0 ) { _rtB -> B_5_418_0 [ i + 18 ] =
_rtDW -> DiscreteTimeIntegrator1_DSTATE [ i ] ; } else { _rtB -> B_5_418_0 [
i + 18 ] = _rtP -> P_112 * _rtB -> B_5_416_0 [ i ] + _rtDW ->
DiscreteTimeIntegrator1_DSTATE [ i ] ; } } } if ( ssIsSampleHit ( S , 1 , 0 )
) { memcpy ( & _rtDW -> Pseudoinverse_X [ 0 ] , & _rtB -> B_5_418_0 [ 0 ] ,
27U * sizeof ( real_T ) ) ; idxLU = MWDSP_SVD_D ( & _rtDW -> Pseudoinverse_X
[ 0U ] , 3 , 9 , & _rtDW -> Pseudoinverse_S [ 0U ] , & _rtDW ->
Pseudoinverse_E [ 0U ] , & _rtDW -> Pseudoinverse_WORK [ 0U ] , & _rtDW ->
Pseudoinverse_U [ 0U ] , & _rtDW -> Pseudoinverse_V [ 0U ] , 1 ) ; if ( idxLU
== 0 ) { MWDSPCG_Pseudoinverse_D ( & _rtDW -> Pseudoinverse_S [ 0U ] , &
_rtDW -> Pseudoinverse_U [ 0U ] , & _rtDW -> Pseudoinverse_V [ 0U ] , & _rtB
-> B_5_419_0 [ 0U ] , 3 , 9 ) ; } } _rtB -> B_5_421_0 [ 0 ] = _rtB ->
B_5_150_0 [ 1 ] * rtb_B_5_731_0 [ 2 ] - _rtB -> B_5_150_0 [ 2 ] *
rtb_B_5_731_0 [ 1 ] ; _rtB -> B_5_421_0 [ 1 ] = _rtB -> B_5_150_0 [ 2 ] *
rtb_B_5_731_0 [ 0 ] - _rtB -> B_5_150_0 [ 0 ] * rtb_B_5_731_0 [ 2 ] ; _rtB ->
B_5_421_0 [ 2 ] = _rtB -> B_5_150_0 [ 0 ] * rtb_B_5_731_0 [ 1 ] - _rtB ->
B_5_150_0 [ 1 ] * rtb_B_5_731_0 [ 0 ] ; if ( ssIsSampleHit ( S , 5 , 0 ) ) {
if ( _rtDW -> DiscreteTimeIntegrator2_SYSTEM_ENABLE != 0 ) { _rtB ->
B_5_422_0 [ 0 ] = _rtDW -> DiscreteTimeIntegrator2_DSTATE [ 0 ] ; _rtB ->
B_5_422_0 [ 1 ] = _rtDW -> DiscreteTimeIntegrator2_DSTATE [ 1 ] ; _rtB ->
B_5_422_0 [ 2 ] = _rtDW -> DiscreteTimeIntegrator2_DSTATE [ 2 ] ; } else {
_rtB -> B_5_422_0 [ 0 ] = _rtP -> P_114 * _rtB -> B_5_421_0 [ 0 ] + _rtDW ->
DiscreteTimeIntegrator2_DSTATE [ 0 ] ; _rtB -> B_5_422_0 [ 1 ] = _rtP ->
P_114 * _rtB -> B_5_421_0 [ 1 ] + _rtDW -> DiscreteTimeIntegrator2_DSTATE [ 1
] ; _rtB -> B_5_422_0 [ 2 ] = _rtP -> P_114 * _rtB -> B_5_421_0 [ 2 ] + _rtDW
-> DiscreteTimeIntegrator2_DSTATE [ 2 ] ; } } rtb_B_5_731_0 [ 0 ] = ( 0.0 -
rtb_B_5_731_0 [ 0 ] ) - _rtB -> B_5_422_0 [ 0 ] ; rtb_B_5_731_0 [ 1 ] = ( 0.0
- rtb_B_5_731_0 [ 1 ] ) - _rtB -> B_5_422_0 [ 1 ] ; B_5_578_0_idx = ( 0.0 -
rtb_B_5_731_0 [ 2 ] ) - _rtB -> B_5_422_0 [ 2 ] ; rtb_B_5_731_0 [ 2 ] =
B_5_578_0_idx ; for ( i_0 = 0 ; i_0 < 9 ; i_0 ++ ) { y_0 [ i_0 ] = _rtB ->
B_5_419_0 [ i_0 + 18 ] * B_5_578_0_idx + ( _rtB -> B_5_419_0 [ i_0 + 9 ] *
rtb_B_5_731_0 [ 1 ] + _rtB -> B_5_419_0 [ i_0 ] * rtb_B_5_731_0 [ 0 ] ) ; }
_rtB -> B_5_434_0 [ 0 ] = y_0 [ 0 ] ; _rtB -> B_5_434_0 [ 1 ] = y_0 [ 3 ] ;
_rtB -> B_5_434_0 [ 2 ] = y_0 [ 4 ] ; _rtB -> B_5_434_0 [ 3 ] = y_0 [ 3 ] ;
_rtB -> B_5_434_0 [ 4 ] = y_0 [ 1 ] ; _rtB -> B_5_434_0 [ 5 ] = y_0 [ 5 ] ;
_rtB -> B_5_434_0 [ 6 ] = y_0 [ 4 ] ; _rtB -> B_5_434_0 [ 7 ] = y_0 [ 5 ] ;
_rtB -> B_5_434_0 [ 8 ] = y_0 [ 2 ] ; ssCallAccelRunBlock ( S , 5 , 435 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_5_436_0 [ 0 ] = y_0 [ 6 ] / _rtB ->
B_5_314_0 ; _rtB -> B_5_436_0 [ 1 ] = y_0 [ 7 ] / _rtB -> B_5_314_0 ; _rtB ->
B_5_436_0 [ 2 ] = y_0 [ 8 ] / _rtB -> B_5_314_0 ; ssCallAccelRunBlock ( S , 5
, 437 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 5 , 438 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
B_5_439_0 [ 0 ] = _rtB -> B_5_274_0 ; _rtB -> B_5_439_0 [ 1 ] = _rtB ->
B_5_730_0 ; _rtB -> B_5_439_0 [ 2 ] = _rtB -> B_5_713_0 ; _rtB -> B_5_439_0 [
3 ] = _rtB -> B_5_696_0 ; ssCallAccelRunBlock ( S , 5 , 440 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 441 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 442 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 5 , 443 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 444 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 445 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 446 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_5_447_0
= _rtP -> P_116 ; } rtb_B_5_842_0 = ( _rtB -> B_5_447_0 - ( ( ( B_5_66_0 [ 0
] * B_5_66_0 [ 0 ] + B_5_66_0 [ 1 ] * B_5_66_0 [ 1 ] ) + B_5_66_0 [ 2 ] *
B_5_66_0 [ 2 ] ) + B_5_66_0 [ 3 ] * B_5_66_0 [ 3 ] ) ) * _rtP -> P_117 ; _rtB
-> B_5_451_0 = ( ( B_5_66_0 [ 1 ] * _rtB -> B_5_150_0 [ 0 ] + B_5_66_0 [ 2 ]
* _rtB -> B_5_150_0 [ 1 ] ) + B_5_66_0 [ 3 ] * _rtB -> B_5_150_0 [ 2 ] ) * -
0.5 + rtb_B_5_842_0 * B_5_66_0 [ 0 ] ; _rtB -> B_5_452_0 = ( ( B_5_66_0 [ 0 ]
* _rtB -> B_5_150_0 [ 0 ] + B_5_66_0 [ 2 ] * _rtB -> B_5_150_0 [ 2 ] ) -
B_5_66_0 [ 3 ] * _rtB -> B_5_150_0 [ 1 ] ) * 0.5 + rtb_B_5_842_0 * B_5_66_0 [
1 ] ; _rtB -> B_5_453_0 = ( ( B_5_66_0 [ 0 ] * _rtB -> B_5_150_0 [ 1 ] +
B_5_66_0 [ 3 ] * _rtB -> B_5_150_0 [ 0 ] ) - B_5_66_0 [ 1 ] * _rtB ->
B_5_150_0 [ 2 ] ) * 0.5 + rtb_B_5_842_0 * B_5_66_0 [ 2 ] ; _rtB -> B_5_454_0
= ( ( B_5_66_0 [ 0 ] * _rtB -> B_5_150_0 [ 2 ] + B_5_66_0 [ 1 ] * _rtB ->
B_5_150_0 [ 1 ] ) - B_5_66_0 [ 2 ] * _rtB -> B_5_150_0 [ 0 ] ) * 0.5 +
rtb_B_5_842_0 * B_5_66_0 [ 3 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_5_455_0 = _rtP -> P_118 ; } _rtB -> B_5_465_0 [ 0 ] = _rtB -> B_5_455_0 ;
_rtB -> B_5_465_0 [ 1 ] = _rtB -> B_5_696_0 ; _rtB -> B_5_465_0 [ 2 ] = _rtP
-> P_119 * _rtB -> B_5_713_0 ; _rtB -> B_5_465_0 [ 3 ] = _rtP -> P_120 * _rtB
-> B_5_696_0 ; _rtB -> B_5_465_0 [ 4 ] = _rtB -> B_5_455_0 ; _rtB ->
B_5_465_0 [ 5 ] = _rtB -> B_5_730_0 ; _rtB -> B_5_465_0 [ 6 ] = _rtB ->
B_5_713_0 ; _rtB -> B_5_465_0 [ 7 ] = _rtP -> P_121 * _rtB -> B_5_730_0 ;
_rtB -> B_5_465_0 [ 8 ] = _rtB -> B_5_455_0 ; memcpy ( & rtb_B_5_424_0 [ 0 ]
, & _rtB -> B_5_465_0 [ 0 ] , 9U * sizeof ( real_T ) ) ; LUf_int32_Treal_T (
rtb_B_5_424_0 , rtb_B_5_731_0 , 3 ) ; for ( idxLU = 0 ; idxLU < 3 ; idxLU ++
) { i = ( int32_T ) muDoubleScalarFloor ( rtb_B_5_731_0 [ idxLU ] ) - 1 ; if
( i < 0 ) { i = 0 ; } else { if ( i >= 3 ) { i = 2 ; } } rtb_B_5_655_0 [
idxLU ] = _rtB -> B_5_467_0 [ i ] ; rtb_B_5_655_0 [ 3 + idxLU ] = _rtB ->
B_5_467_0 [ 3 + i ] ; rtb_B_5_655_0 [ 6 + idxLU ] = _rtB -> B_5_467_0 [ 6 + i
] ; } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { i = i_0 * 3 ; idxLU = 1 ; idxB = i
+ 1 ; B_5_578_0_idx_0 = rtb_B_5_655_0 [ idxB ] ; k = 0 ; while ( k < 1 ) {
B_5_578_0_idx_0 -= rtb_B_5_424_0 [ idxLU ] * rtb_B_5_655_0 [ i ] ; idxLU += 3
; k = 1 ; } rtb_B_5_655_0 [ idxB ] = B_5_578_0_idx_0 ; idxLU = 2 ; idxB = i +
2 ; B_5_578_0_idx_0 = rtb_B_5_655_0 [ idxB ] ; for ( k = 0 ; k < 2 ; k ++ ) {
B_5_578_0_idx_0 -= rtb_B_5_655_0 [ i + k ] * rtb_B_5_424_0 [ idxLU ] ; idxLU
+= 3 ; } rtb_B_5_655_0 [ idxB ] = B_5_578_0_idx_0 ; } for ( i_0 = 0 ; i_0 < 3
; i_0 ++ ) { i = i_0 * 3 ; idxLU = i + 2 ; _rtB -> B_5_470_0 [ idxLU ] =
rtb_B_5_655_0 [ idxLU ] / rtb_B_5_424_0 [ 8 ] ; idxLU = 7 ; idxB = i + 1 ;
B_5_578_0_idx_0 = rtb_B_5_655_0 [ idxB ] ; k = 2 ; while ( k > 1 ) {
B_5_578_0_idx_0 -= _rtB -> B_5_470_0 [ i + 2 ] * rtb_B_5_424_0 [ idxLU ] ;
idxLU -= 3 ; k = 1 ; } _rtB -> B_5_470_0 [ idxB ] = B_5_578_0_idx_0 /
rtb_B_5_424_0 [ idxLU ] ; idxLU = 6 ; B_5_578_0_idx_0 = rtb_B_5_655_0 [ i ] ;
for ( k = 2 ; k > 0 ; k -- ) { B_5_578_0_idx_0 -= _rtB -> B_5_470_0 [ i + k ]
* rtb_B_5_424_0 [ idxLU ] ; idxLU -= 3 ; } _rtB -> B_5_470_0 [ i ] =
B_5_578_0_idx_0 / rtb_B_5_424_0 [ idxLU ] ; } for ( i_0 = 0 ; i_0 < 3 ; i_0
++ ) { _rtB -> B_5_668_0 [ i_0 ] = 0.0 ; _rtB -> B_5_668_0 [ i_0 ] += _rtB ->
B_5_470_0 [ i_0 ] * _rtB -> B_5_225_0 [ 0 ] ; _rtB -> B_5_668_0 [ i_0 ] +=
_rtB -> B_5_470_0 [ i_0 + 3 ] * _rtB -> B_5_225_0 [ 1 ] ; _rtB -> B_5_668_0 [
i_0 ] += _rtB -> B_5_470_0 [ i_0 + 6 ] * _rtB -> B_5_225_0 [ 2 ] ; }
ssCallAccelRunBlock ( S , 5 , 472 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_473_0 = _rtP -> P_122 ; _rtB ->
B_5_474_0 = _rtP -> P_123 * _rtB -> B_5_473_0 ; } _rtB -> B_5_668_0 [ 0 ] = (
_rtB -> B_5_225_0 [ 0 ] - _rtB -> B_5_473_0 * _rtB -> B_5_730_0 ) * _rtB ->
B_5_474_0 ; _rtB -> B_5_668_0 [ 1 ] = ( _rtB -> B_5_225_0 [ 1 ] - _rtB ->
B_5_473_0 * _rtB -> B_5_713_0 ) * _rtB -> B_5_474_0 ; _rtB -> B_5_668_0 [ 2 ]
= ( _rtB -> B_5_225_0 [ 2 ] - _rtB -> B_5_473_0 * _rtB -> B_5_696_0 ) * _rtB
-> B_5_474_0 ; ssCallAccelRunBlock ( S , 5 , 478 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 479 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 480 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & _rtB -> B_5_481_0 [ 0 ] , & _rtP
-> P_124 [ 0 ] , 9U * sizeof ( real_T ) ) ; _rtB -> B_5_483_0 = _rtP -> P_126
* _rtP -> P_125 ; } B_5_578_0_idx_0 = _rtB -> B_5_744_0 [ 0 ] * _rtB ->
B_5_744_0 [ 0 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_5_497_0 [ 0 ] =
_rtP -> P_127 ; rtb_B_5_497_0 [ 1 ] = _rtP -> P_128 [ 2 ] ; rtb_B_5_497_0 [ 2
] = _rtP -> P_129 * _rtP -> P_128 [ 1 ] ; rtb_B_5_497_0 [ 3 ] = _rtP -> P_129
* _rtP -> P_128 [ 2 ] ; rtb_B_5_497_0 [ 4 ] = _rtP -> P_127 ; rtb_B_5_497_0 [
5 ] = _rtP -> P_128 [ 0 ] ; rtb_B_5_497_0 [ 6 ] = _rtP -> P_128 [ 1 ] ;
rtb_B_5_497_0 [ 7 ] = _rtP -> P_129 * _rtP -> P_128 [ 0 ] ; rtb_B_5_497_0 [ 8
] = _rtP -> P_127 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3
; i ++ ) { _rtB -> B_5_498_0 [ i_0 + 3 * i ] = 0.0 ; _rtB -> B_5_498_0 [ i_0
+ 3 * i ] += rtb_B_5_497_0 [ 3 * i ] * rtb_B_5_497_0 [ i_0 ] ; _rtB ->
B_5_498_0 [ i_0 + 3 * i ] += rtb_B_5_497_0 [ 3 * i + 1 ] * rtb_B_5_497_0 [
i_0 + 3 ] ; _rtB -> B_5_498_0 [ i_0 + 3 * i ] += rtb_B_5_497_0 [ 3 * i + 2 ]
* rtb_B_5_497_0 [ i_0 + 6 ] ; } } rtb_B_5_512_0 [ 0 ] = _rtP -> P_130 ;
rtb_B_5_512_0 [ 1 ] = _rtP -> P_131 [ 2 ] ; rtb_B_5_512_0 [ 2 ] = _rtP ->
P_132 * _rtP -> P_131 [ 1 ] ; rtb_B_5_512_0 [ 3 ] = _rtP -> P_132 * _rtP ->
P_131 [ 2 ] ; rtb_B_5_512_0 [ 4 ] = _rtP -> P_130 ; rtb_B_5_512_0 [ 5 ] =
_rtP -> P_131 [ 0 ] ; rtb_B_5_512_0 [ 6 ] = _rtP -> P_131 [ 1 ] ;
rtb_B_5_512_0 [ 7 ] = _rtP -> P_132 * _rtP -> P_131 [ 0 ] ; rtb_B_5_512_0 [ 8
] = _rtP -> P_130 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3
; i ++ ) { _rtB -> B_5_513_0 [ i_0 + 3 * i ] = 0.0 ; _rtB -> B_5_513_0 [ i_0
+ 3 * i ] += rtb_B_5_512_0 [ 3 * i ] * rtb_B_5_497_0 [ i_0 ] ; _rtB ->
B_5_513_0 [ i_0 + 3 * i ] += rtb_B_5_512_0 [ 3 * i + 1 ] * rtb_B_5_497_0 [
i_0 + 3 ] ; _rtB -> B_5_513_0 [ i_0 + 3 * i ] += rtb_B_5_512_0 [ 3 * i + 2 ]
* rtb_B_5_497_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for (
i = 0 ; i < 3 ; i ++ ) { _rtB -> B_5_515_0 [ i_0 + 3 * i ] = 0.0 ; _rtB ->
B_5_515_0 [ i_0 + 3 * i ] += rtb_B_5_497_0 [ 3 * i ] * rtb_B_5_512_0 [ i_0 ]
; _rtB -> B_5_515_0 [ i_0 + 3 * i ] += rtb_B_5_497_0 [ 3 * i + 1 ] *
rtb_B_5_512_0 [ i_0 + 3 ] ; _rtB -> B_5_515_0 [ i_0 + 3 * i ] +=
rtb_B_5_497_0 [ 3 * i + 2 ] * rtb_B_5_512_0 [ i_0 + 6 ] ; } } _rtB ->
B_5_520_0 = _rtP -> P_134 * _rtP -> P_133 ; } rtb_B_5_767_0 = _rtB ->
B_5_744_0 [ 1 ] * _rtB -> B_5_744_0 [ 1 ] ; if ( ssIsSampleHit ( S , 1 , 0 )
) { rtb_B_5_534_0 [ 0 ] = _rtP -> P_135 ; rtb_B_5_534_0 [ 1 ] = _rtP -> P_136
[ 2 ] ; rtb_B_5_534_0 [ 2 ] = _rtP -> P_137 * _rtP -> P_136 [ 1 ] ;
rtb_B_5_534_0 [ 3 ] = _rtP -> P_137 * _rtP -> P_136 [ 2 ] ; rtb_B_5_534_0 [ 4
] = _rtP -> P_135 ; rtb_B_5_534_0 [ 5 ] = _rtP -> P_136 [ 0 ] ; rtb_B_5_534_0
[ 6 ] = _rtP -> P_136 [ 1 ] ; rtb_B_5_534_0 [ 7 ] = _rtP -> P_137 * _rtP ->
P_136 [ 0 ] ; rtb_B_5_534_0 [ 8 ] = _rtP -> P_135 ; for ( i_0 = 0 ; i_0 < 3 ;
i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_5_535_0 [ i_0 + 3 * i ] =
0.0 ; _rtB -> B_5_535_0 [ i_0 + 3 * i ] += rtb_B_5_534_0 [ 3 * i ] *
rtb_B_5_534_0 [ i_0 ] ; _rtB -> B_5_535_0 [ i_0 + 3 * i ] += rtb_B_5_534_0 [
3 * i + 1 ] * rtb_B_5_534_0 [ i_0 + 3 ] ; _rtB -> B_5_535_0 [ i_0 + 3 * i ]
+= rtb_B_5_534_0 [ 3 * i + 2 ] * rtb_B_5_534_0 [ i_0 + 6 ] ; } }
rtb_B_5_549_0 [ 0 ] = _rtP -> P_138 ; rtb_B_5_549_0 [ 1 ] = _rtP -> P_139 [ 2
] ; rtb_B_5_549_0 [ 2 ] = _rtP -> P_140 * _rtP -> P_139 [ 1 ] ; rtb_B_5_549_0
[ 3 ] = _rtP -> P_140 * _rtP -> P_139 [ 2 ] ; rtb_B_5_549_0 [ 4 ] = _rtP ->
P_138 ; rtb_B_5_549_0 [ 5 ] = _rtP -> P_139 [ 0 ] ; rtb_B_5_549_0 [ 6 ] =
_rtP -> P_139 [ 1 ] ; rtb_B_5_549_0 [ 7 ] = _rtP -> P_140 * _rtP -> P_139 [ 0
] ; rtb_B_5_549_0 [ 8 ] = _rtP -> P_138 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ )
{ for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_5_550_0 [ i_0 + 3 * i ] = 0.0 ;
_rtB -> B_5_550_0 [ i_0 + 3 * i ] += rtb_B_5_549_0 [ 3 * i ] * rtb_B_5_534_0
[ i_0 ] ; _rtB -> B_5_550_0 [ i_0 + 3 * i ] += rtb_B_5_549_0 [ 3 * i + 1 ] *
rtb_B_5_534_0 [ i_0 + 3 ] ; _rtB -> B_5_550_0 [ i_0 + 3 * i ] +=
rtb_B_5_549_0 [ 3 * i + 2 ] * rtb_B_5_534_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ;
i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_5_552_0 [ i_0 +
3 * i ] = 0.0 ; _rtB -> B_5_552_0 [ i_0 + 3 * i ] += rtb_B_5_534_0 [ 3 * i ]
* rtb_B_5_549_0 [ i_0 ] ; _rtB -> B_5_552_0 [ i_0 + 3 * i ] += rtb_B_5_534_0
[ 3 * i + 1 ] * rtb_B_5_549_0 [ i_0 + 3 ] ; _rtB -> B_5_552_0 [ i_0 + 3 * i ]
+= rtb_B_5_534_0 [ 3 * i + 2 ] * rtb_B_5_549_0 [ i_0 + 6 ] ; } } _rtB ->
B_5_557_0 = _rtP -> P_142 * _rtP -> P_141 ; } rtb_B_5_766_0 = _rtB ->
B_5_744_0 [ 2 ] * _rtB -> B_5_744_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 )
) { rtb_B_5_571_0 [ 0 ] = _rtP -> P_143 ; rtb_B_5_571_0 [ 1 ] = _rtP -> P_144
[ 2 ] ; rtb_B_5_571_0 [ 2 ] = _rtP -> P_145 * _rtP -> P_144 [ 1 ] ;
rtb_B_5_571_0 [ 3 ] = _rtP -> P_145 * _rtP -> P_144 [ 2 ] ; rtb_B_5_571_0 [ 4
] = _rtP -> P_143 ; rtb_B_5_571_0 [ 5 ] = _rtP -> P_144 [ 0 ] ; rtb_B_5_571_0
[ 6 ] = _rtP -> P_144 [ 1 ] ; rtb_B_5_571_0 [ 7 ] = _rtP -> P_145 * _rtP ->
P_144 [ 0 ] ; rtb_B_5_571_0 [ 8 ] = _rtP -> P_143 ; for ( i_0 = 0 ; i_0 < 3 ;
i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_5_572_0 [ i_0 + 3 * i ] =
0.0 ; _rtB -> B_5_572_0 [ i_0 + 3 * i ] += rtb_B_5_571_0 [ 3 * i ] *
rtb_B_5_571_0 [ i_0 ] ; _rtB -> B_5_572_0 [ i_0 + 3 * i ] += rtb_B_5_571_0 [
3 * i + 1 ] * rtb_B_5_571_0 [ i_0 + 3 ] ; _rtB -> B_5_572_0 [ i_0 + 3 * i ]
+= rtb_B_5_571_0 [ 3 * i + 2 ] * rtb_B_5_571_0 [ i_0 + 6 ] ; } }
rtb_B_5_586_0 [ 0 ] = _rtP -> P_146 ; rtb_B_5_586_0 [ 1 ] = _rtP -> P_147 [ 2
] ; rtb_B_5_586_0 [ 2 ] = _rtP -> P_148 * _rtP -> P_147 [ 1 ] ; rtb_B_5_586_0
[ 3 ] = _rtP -> P_148 * _rtP -> P_147 [ 2 ] ; rtb_B_5_586_0 [ 4 ] = _rtP ->
P_146 ; rtb_B_5_586_0 [ 5 ] = _rtP -> P_147 [ 0 ] ; rtb_B_5_586_0 [ 6 ] =
_rtP -> P_147 [ 1 ] ; rtb_B_5_586_0 [ 7 ] = _rtP -> P_148 * _rtP -> P_147 [ 0
] ; rtb_B_5_586_0 [ 8 ] = _rtP -> P_146 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ )
{ for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_5_587_0 [ i_0 + 3 * i ] = 0.0 ;
_rtB -> B_5_587_0 [ i_0 + 3 * i ] += rtb_B_5_586_0 [ 3 * i ] * rtb_B_5_571_0
[ i_0 ] ; _rtB -> B_5_587_0 [ i_0 + 3 * i ] += rtb_B_5_586_0 [ 3 * i + 1 ] *
rtb_B_5_571_0 [ i_0 + 3 ] ; _rtB -> B_5_587_0 [ i_0 + 3 * i ] +=
rtb_B_5_586_0 [ 3 * i + 2 ] * rtb_B_5_571_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ;
i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_5_589_0 [ i_0 +
3 * i ] = 0.0 ; _rtB -> B_5_589_0 [ i_0 + 3 * i ] += rtb_B_5_571_0 [ 3 * i ]
* rtb_B_5_586_0 [ i_0 ] ; _rtB -> B_5_589_0 [ i_0 + 3 * i ] += rtb_B_5_571_0
[ 3 * i + 1 ] * rtb_B_5_586_0 [ i_0 + 3 ] ; _rtB -> B_5_589_0 [ i_0 + 3 * i ]
+= rtb_B_5_571_0 [ 3 * i + 2 ] * rtb_B_5_586_0 [ i_0 + 6 ] ; } } } for ( i =
0 ; i < 9 ; i ++ ) { rtb_B_5_424_0 [ i ] = ( ( ( ( B_5_578_0_idx_0 * _rtB ->
B_5_498_0 [ i ] + _rtB -> B_5_744_0 [ 0 ] * _rtB -> B_5_513_0 [ i ] ) + _rtB
-> B_5_744_0 [ 0 ] * _rtB -> B_5_515_0 [ i ] ) * _rtB -> B_5_483_0 + _rtB ->
B_5_481_0 [ i ] ) + ( ( rtb_B_5_767_0 * _rtB -> B_5_535_0 [ i ] + _rtB ->
B_5_744_0 [ 1 ] * _rtB -> B_5_550_0 [ i ] ) + _rtB -> B_5_744_0 [ 1 ] * _rtB
-> B_5_552_0 [ i ] ) * _rtB -> B_5_520_0 ) + ( ( rtb_B_5_766_0 * _rtB ->
B_5_572_0 [ i ] + _rtB -> B_5_744_0 [ 2 ] * _rtB -> B_5_587_0 [ i ] ) + _rtB
-> B_5_744_0 [ 2 ] * _rtB -> B_5_589_0 [ i ] ) * _rtB -> B_5_557_0 ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & rtb_B_5_594_0 [ 0 ] , & _rtP ->
P_149 [ 0 ] , 9U * sizeof ( real_T ) ) ; } ssCallAccelRunBlock ( S , 5 , 595
, SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_5_596_0 = _rtP -> P_150 ; } rtb_B_5_842_0 = ( ( B_5_9_0 [ 0 ] * B_5_9_0 [ 0
] + B_5_9_0 [ 1 ] * B_5_9_0 [ 1 ] ) + B_5_9_0 [ 2 ] * B_5_9_0 [ 2 ] ) +
B_5_9_0 [ 3 ] * B_5_9_0 [ 3 ] ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW
-> sqrt_DWORK1_o != 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
sqrt_DWORK1_o = 0 ; } rtb_B_5_842_0 = muDoubleScalarSqrt ( rtb_B_5_842_0 ) ;
} else { if ( rtb_B_5_842_0 < 0.0 ) { rtb_B_5_842_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_5_842_0 ) ) ; } else { rtb_B_5_842_0 =
muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } _rtDW -> sqrt_DWORK1_o = 1 ; }
rtb_B_5_785_0 = B_5_9_0 [ 3 ] / rtb_B_5_842_0 ; B_5_578_0_idx = B_5_9_0 [ 2 ]
/ rtb_B_5_842_0 ; B_5_578_0_idx_0 = B_5_9_0 [ 1 ] / rtb_B_5_842_0 ;
rtb_B_5_842_0 = B_5_9_0 [ 0 ] / rtb_B_5_842_0 ; rtb_B_5_646_0 [ 0 ] = ( (
rtb_B_5_842_0 * rtb_B_5_842_0 + B_5_578_0_idx_0 * B_5_578_0_idx_0 ) -
B_5_578_0_idx * B_5_578_0_idx ) - rtb_B_5_785_0 * rtb_B_5_785_0 ;
rtb_B_5_646_0 [ 3 ] = ( rtb_B_5_785_0 * rtb_B_5_842_0 + B_5_578_0_idx_0 *
B_5_578_0_idx ) * _rtP -> P_151 ; rtb_B_5_646_0 [ 6 ] = ( B_5_578_0_idx_0 *
rtb_B_5_785_0 - rtb_B_5_842_0 * B_5_578_0_idx ) * _rtP -> P_152 ;
rtb_B_5_646_0 [ 1 ] = ( B_5_578_0_idx_0 * B_5_578_0_idx - rtb_B_5_785_0 *
rtb_B_5_842_0 ) * _rtP -> P_153 ; rtb_B_5_646_0 [ 4 ] = ( ( rtb_B_5_842_0 *
rtb_B_5_842_0 - B_5_578_0_idx_0 * B_5_578_0_idx_0 ) + B_5_578_0_idx *
B_5_578_0_idx ) - rtb_B_5_785_0 * rtb_B_5_785_0 ; rtb_B_5_646_0 [ 7 ] = (
rtb_B_5_842_0 * B_5_578_0_idx_0 + B_5_578_0_idx * rtb_B_5_785_0 ) * _rtP ->
P_154 ; rtb_B_5_646_0 [ 2 ] = ( rtb_B_5_842_0 * B_5_578_0_idx +
B_5_578_0_idx_0 * rtb_B_5_785_0 ) * _rtP -> P_155 ; rtb_B_5_646_0 [ 5 ] = (
B_5_578_0_idx * rtb_B_5_785_0 - rtb_B_5_842_0 * B_5_578_0_idx_0 ) * _rtP ->
P_156 ; rtb_B_5_646_0 [ 8 ] = ( ( rtb_B_5_842_0 * rtb_B_5_842_0 -
B_5_578_0_idx_0 * B_5_578_0_idx_0 ) - B_5_578_0_idx * B_5_578_0_idx ) +
rtb_B_5_785_0 * rtb_B_5_785_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_5_647_0 = _rtP -> P_157 ; } rtb_B_5_842_0 = ( _rtB -> B_5_647_0 - ( ( (
B_5_9_0 [ 0 ] * B_5_9_0 [ 0 ] + B_5_9_0 [ 1 ] * B_5_9_0 [ 1 ] ) + B_5_9_0 [ 2
] * B_5_9_0 [ 2 ] ) + B_5_9_0 [ 3 ] * B_5_9_0 [ 3 ] ) ) * _rtP -> P_158 ;
_rtB -> B_5_651_0 = ( ( B_5_9_0 [ 1 ] * _rtB -> B_5_0_0 [ 0 ] + B_5_9_0 [ 2 ]
* _rtB -> B_5_0_0 [ 1 ] ) + B_5_9_0 [ 3 ] * _rtB -> B_5_0_0 [ 2 ] ) * - 0.5 +
rtb_B_5_842_0 * B_5_9_0 [ 0 ] ; _rtB -> B_5_652_0 = ( ( B_5_9_0 [ 0 ] * _rtB
-> B_5_0_0 [ 0 ] + B_5_9_0 [ 2 ] * _rtB -> B_5_0_0 [ 2 ] ) - B_5_9_0 [ 3 ] *
_rtB -> B_5_0_0 [ 1 ] ) * 0.5 + rtb_B_5_842_0 * B_5_9_0 [ 1 ] ; _rtB ->
B_5_653_0 = ( ( B_5_9_0 [ 0 ] * _rtB -> B_5_0_0 [ 1 ] + B_5_9_0 [ 3 ] * _rtB
-> B_5_0_0 [ 0 ] ) - B_5_9_0 [ 1 ] * _rtB -> B_5_0_0 [ 2 ] ) * 0.5 +
rtb_B_5_842_0 * B_5_9_0 [ 2 ] ; _rtB -> B_5_654_0 = ( ( B_5_9_0 [ 0 ] * _rtB
-> B_5_0_0 [ 2 ] + B_5_9_0 [ 1 ] * _rtB -> B_5_0_0 [ 1 ] ) - B_5_9_0 [ 2 ] *
_rtB -> B_5_0_0 [ 0 ] ) * 0.5 + rtb_B_5_842_0 * B_5_9_0 [ 3 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i
= 0 ; i < 3 ; i ++ ) { rtb_B_5_252_0 [ i_0 + 3 * i ] = 0.0 ; rtb_B_5_252_0 [
i_0 + 3 * i ] += rtb_B_5_594_0 [ 3 * i ] * _rtP -> P_161 [ i_0 ] ;
rtb_B_5_252_0 [ i_0 + 3 * i ] += rtb_B_5_594_0 [ 3 * i + 1 ] * _rtP -> P_161
[ i_0 + 3 ] ; rtb_B_5_252_0 [ i_0 + 3 * i ] += rtb_B_5_594_0 [ 3 * i + 2 ] *
_rtP -> P_161 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i
= 0 ; i < 3 ; i ++ ) { _rtB -> B_5_658_0 [ i_0 + 3 * i ] = 0.0 ; _rtB ->
B_5_658_0 [ i_0 + 3 * i ] += _rtP -> P_162 [ 3 * i ] * rtb_B_5_252_0 [ i_0 ]
; _rtB -> B_5_658_0 [ i_0 + 3 * i ] += _rtP -> P_162 [ 3 * i + 1 ] *
rtb_B_5_252_0 [ i_0 + 3 ] ; _rtB -> B_5_658_0 [ i_0 + 3 * i ] += _rtP ->
P_162 [ 3 * i + 2 ] * rtb_B_5_252_0 [ i_0 + 6 ] ; } } } for ( i_0 = 0 ; i_0 <
3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtb_B_5_252_0 [ i_0 + 3 * i ] =
0.0 ; rtb_B_5_252_0 [ i_0 + 3 * i ] += rtb_B_5_424_0 [ 3 * i ] * _rtP ->
P_159 [ i_0 ] ; rtb_B_5_252_0 [ i_0 + 3 * i ] += rtb_B_5_424_0 [ 3 * i + 1 ]
* _rtP -> P_159 [ i_0 + 3 ] ; rtb_B_5_252_0 [ i_0 + 3 * i ] += rtb_B_5_424_0
[ 3 * i + 2 ] * _rtP -> P_159 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ; i_0
++ ) { for ( i = 0 ; i < 3 ; i ++ ) { B [ i_0 + 3 * i ] = 0.0 ; B [ i_0 + 3 *
i ] += _rtP -> P_160 [ 3 * i ] * rtb_B_5_252_0 [ i_0 ] ; B [ i_0 + 3 * i ] +=
_rtP -> P_160 [ 3 * i + 1 ] * rtb_B_5_252_0 [ i_0 + 3 ] ; B [ i_0 + 3 * i ]
+= _rtP -> P_160 [ 3 * i + 2 ] * rtb_B_5_252_0 [ i_0 + 6 ] ; } } for ( i_0 =
0 ; i_0 < 3 ; i_0 ++ ) { rtb_B_5_659_0 [ 6 * i_0 ] = B [ 3 * i_0 ] ;
rtb_B_5_659_0 [ 1 + 6 * i_0 ] = B [ 3 * i_0 + 1 ] ; rtb_B_5_659_0 [ 2 + 6 *
i_0 ] = B [ 3 * i_0 + 2 ] ; } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) {
rtb_B_5_659_0 [ 3 + 6 * i_0 ] = _rtB -> B_5_658_0 [ 3 * i_0 ] ; rtb_B_5_659_0
[ 4 + 6 * i_0 ] = _rtB -> B_5_658_0 [ 3 * i_0 + 1 ] ; rtb_B_5_659_0 [ 5 + 6 *
i_0 ] = _rtB -> B_5_658_0 [ 3 * i_0 + 2 ] ; } for ( i_0 = 0 ; i_0 < 3 ; i_0
++ ) { rtb_B_5_731_0 [ i_0 ] = rtb_B_5_659_0 [ i_0 + 12 ] * _rtB -> B_5_0_0 [
2 ] + ( rtb_B_5_659_0 [ i_0 + 6 ] * _rtB -> B_5_0_0 [ 1 ] + rtb_B_5_659_0 [
i_0 ] * _rtB -> B_5_0_0 [ 0 ] ) ; } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) {
B_5_663_0 [ i_0 ] = 0.0 ; B_5_663_0 [ i_0 ] += rtb_B_5_659_0 [ 3 + i_0 ] *
_rtB -> B_5_0_0 [ 0 ] ; B_5_663_0 [ i_0 ] += rtb_B_5_659_0 [ i_0 + 9 ] * _rtB
-> B_5_0_0 [ 1 ] ; B_5_663_0 [ i_0 ] += rtb_B_5_659_0 [ i_0 + 15 ] * _rtB ->
B_5_0_0 [ 2 ] ; } _rtB -> B_5_667_0 [ 0 ] = ( ( _rtB -> B_5_1_0 [ 1 ] * _rtB
-> B_5_742_0 [ 2 ] - _rtB -> B_5_1_0 [ 2 ] * _rtB -> B_5_742_0 [ 1 ] ) + _rtB
-> B_5_311_0 [ 0 ] ) * _rtP -> P_163 ; _rtB -> B_5_667_0 [ 1 ] = ( ( _rtB ->
B_5_1_0 [ 2 ] * _rtB -> B_5_742_0 [ 0 ] - _rtB -> B_5_1_0 [ 0 ] * _rtB ->
B_5_742_0 [ 2 ] ) + _rtB -> B_5_311_0 [ 1 ] ) * _rtP -> P_163 ; _rtB ->
B_5_667_0 [ 2 ] = ( ( _rtB -> B_5_1_0 [ 0 ] * _rtB -> B_5_742_0 [ 1 ] - _rtB
-> B_5_1_0 [ 1 ] * _rtB -> B_5_742_0 [ 0 ] ) + _rtB -> B_5_311_0 [ 2 ] ) *
_rtP -> P_163 ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> Saturation_MODE_a [
0 ] = _rtB -> B_5_667_0 [ 0 ] >= _rtP -> P_164 ? 1 : _rtB -> B_5_667_0 [ 0 ]
> _rtP -> P_165 ? 0 : - 1 ; _rtDW -> Saturation_MODE_a [ 1 ] = _rtB ->
B_5_667_0 [ 1 ] >= _rtP -> P_164 ? 1 : _rtB -> B_5_667_0 [ 1 ] > _rtP ->
P_165 ? 0 : - 1 ; _rtDW -> Saturation_MODE_a [ 2 ] = _rtB -> B_5_667_0 [ 2 ]
>= _rtP -> P_164 ? 1 : _rtB -> B_5_667_0 [ 2 ] > _rtP -> P_165 ? 0 : - 1 ; }
_rtB -> B_5_668_0 [ 0 ] = _rtDW -> Saturation_MODE_a [ 0 ] == 1 ? _rtP ->
P_164 : _rtDW -> Saturation_MODE_a [ 0 ] == - 1 ? _rtP -> P_165 : _rtB ->
B_5_667_0 [ 0 ] ; _rtB -> B_5_668_0 [ 1 ] = _rtDW -> Saturation_MODE_a [ 1 ]
== 1 ? _rtP -> P_164 : _rtDW -> Saturation_MODE_a [ 1 ] == - 1 ? _rtP ->
P_165 : _rtB -> B_5_667_0 [ 1 ] ; _rtB -> B_5_668_0 [ 2 ] = _rtDW ->
Saturation_MODE_a [ 2 ] == 1 ? _rtP -> P_164 : _rtDW -> Saturation_MODE_a [ 2
] == - 1 ? _rtP -> P_165 : _rtB -> B_5_667_0 [ 2 ] ; if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> B_5_669_0 [ 0 ] = _rtP -> P_166 [ 0 ] ; _rtB -> B_5_669_0
[ 1 ] = _rtP -> P_166 [ 1 ] ; _rtB -> B_5_669_0 [ 2 ] = _rtP -> P_166 [ 2 ] ;
} rtb_B_5_842_0 = ( ( _rtB -> B_5_31_0 * _rtB -> B_5_31_0 + _rtB -> B_5_36_0
[ 0 ] * _rtB -> B_5_36_0 [ 0 ] ) + _rtB -> B_5_36_0 [ 1 ] * _rtB -> B_5_36_0
[ 1 ] ) + _rtB -> B_5_36_0 [ 2 ] * _rtB -> B_5_36_0 [ 2 ] ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_d != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_d = 0 ; } rtb_B_5_842_0 =
muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } else { if ( rtb_B_5_842_0 < 0.0 ) {
rtb_B_5_842_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_5_842_0 ) )
; } else { rtb_B_5_842_0 = muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } _rtDW ->
sqrt_DWORK1_d = 1 ; } rtb_B_5_785_0 = _rtB -> B_5_36_0 [ 1 ] / rtb_B_5_842_0
; B_5_578_0_idx = _rtB -> B_5_36_0 [ 2 ] / rtb_B_5_842_0 ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { _rtB -> B_5_680_0 = _rtP -> P_167 ; } B_5_578_0_idx_0 =
_rtB -> B_5_36_0 [ 0 ] / rtb_B_5_842_0 ; rtb_B_5_842_0 = _rtB -> B_5_31_0 /
rtb_B_5_842_0 ; _rtB -> B_5_696_0 = ( ( ( _rtB -> B_5_680_0 - rtb_B_5_785_0 *
rtb_B_5_785_0 ) - B_5_578_0_idx * B_5_578_0_idx ) * _rtP -> P_168 * _rtB ->
B_5_669_0 [ 0 ] + ( B_5_578_0_idx_0 * rtb_B_5_785_0 + rtb_B_5_842_0 *
B_5_578_0_idx ) * _rtP -> P_169 * _rtB -> B_5_669_0 [ 1 ] ) + (
B_5_578_0_idx_0 * B_5_578_0_idx - rtb_B_5_842_0 * rtb_B_5_785_0 ) * _rtP ->
P_170 * _rtB -> B_5_669_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> B_5_704_0 = _rtP -> P_172 ; } _rtB -> B_5_713_0 = ( ( ( _rtB -> B_5_704_0
- B_5_578_0_idx_0 * B_5_578_0_idx_0 ) - B_5_578_0_idx * B_5_578_0_idx ) *
_rtP -> P_173 * _rtB -> B_5_669_0 [ 1 ] + ( B_5_578_0_idx_0 * rtb_B_5_785_0 -
rtb_B_5_842_0 * B_5_578_0_idx ) * _rtP -> P_171 * _rtB -> B_5_669_0 [ 0 ] ) +
( rtb_B_5_842_0 * B_5_578_0_idx_0 + rtb_B_5_785_0 * B_5_578_0_idx ) * _rtP ->
P_174 * _rtB -> B_5_669_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> B_5_726_0 = _rtP -> P_177 ; } _rtB -> B_5_730_0 = ( ( B_5_578_0_idx_0 *
B_5_578_0_idx + rtb_B_5_842_0 * rtb_B_5_785_0 ) * _rtP -> P_175 * _rtB ->
B_5_669_0 [ 0 ] + ( rtb_B_5_785_0 * B_5_578_0_idx - rtb_B_5_842_0 *
B_5_578_0_idx_0 ) * _rtP -> P_176 * _rtB -> B_5_669_0 [ 1 ] ) + ( ( _rtB ->
B_5_726_0 - B_5_578_0_idx_0 * B_5_578_0_idx_0 ) - rtb_B_5_785_0 *
rtb_B_5_785_0 ) * _rtP -> P_178 * _rtB -> B_5_669_0 [ 2 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_732_0 [ 0 ] = _rtP -> P_180 *
_rtP -> P_179 [ 0 ] ; _rtB -> B_5_732_0 [ 1 ] = _rtP -> P_180 * _rtP -> P_179
[ 1 ] ; _rtB -> B_5_732_0 [ 2 ] = _rtP -> P_180 * _rtP -> P_179 [ 2 ] ; _rtB
-> B_5_733_0 [ 0 ] = _rtP -> P_181 [ 0 ] ; _rtB -> B_5_733_0 [ 1 ] = _rtP ->
P_181 [ 1 ] ; _rtB -> B_5_733_0 [ 2 ] = _rtP -> P_181 [ 2 ] ; _rtB ->
B_5_736_0 [ 0 ] = _rtP -> P_183 [ 0 ] ; _rtB -> B_5_736_0 [ 1 ] = _rtP ->
P_183 [ 1 ] ; _rtB -> B_5_736_0 [ 2 ] = _rtP -> P_183 [ 2 ] ; _rtB ->
B_5_739_0 [ 0 ] = _rtP -> P_185 [ 0 ] ; _rtB -> B_5_739_0 [ 1 ] = _rtP ->
P_185 [ 1 ] ; _rtB -> B_5_739_0 [ 2 ] = _rtP -> P_185 [ 2 ] ; } _rtB ->
B_5_742_0 [ 0 ] = ( ( _rtB -> B_5_733_0 [ 0 ] * _rtB -> B_5_744_0 [ 0 ] *
_rtP -> P_182 + _rtB -> B_5_732_0 [ 0 ] ) + _rtB -> B_5_736_0 [ 0 ] * _rtB ->
B_5_744_0 [ 1 ] * _rtP -> P_184 ) + _rtB -> B_5_739_0 [ 0 ] * _rtB ->
B_5_744_0 [ 2 ] * _rtP -> P_186 ; _rtB -> B_5_742_0 [ 1 ] = ( ( _rtB ->
B_5_733_0 [ 1 ] * _rtB -> B_5_744_0 [ 0 ] * _rtP -> P_182 + _rtB -> B_5_732_0
[ 1 ] ) + _rtB -> B_5_736_0 [ 1 ] * _rtB -> B_5_744_0 [ 1 ] * _rtP -> P_184 )
+ _rtB -> B_5_739_0 [ 1 ] * _rtB -> B_5_744_0 [ 2 ] * _rtP -> P_186 ; _rtB ->
B_5_742_0 [ 2 ] = ( ( _rtB -> B_5_733_0 [ 2 ] * _rtB -> B_5_744_0 [ 0 ] *
_rtP -> P_182 + _rtB -> B_5_732_0 [ 2 ] ) + _rtB -> B_5_736_0 [ 2 ] * _rtB ->
B_5_744_0 [ 1 ] * _rtP -> P_184 ) + _rtB -> B_5_739_0 [ 2 ] * _rtB ->
B_5_744_0 [ 2 ] * _rtP -> P_186 ; _rtB -> B_5_744_0 [ 0 ] = _rtB -> B_5_696_0
* _rtB -> B_5_742_0 [ 0 ] * _rtP -> P_187 ; _rtB -> B_5_744_0 [ 1 ] = _rtB ->
B_5_713_0 * _rtB -> B_5_742_0 [ 1 ] * _rtP -> P_187 ; _rtB -> B_5_744_0 [ 2 ]
= _rtB -> B_5_730_0 * _rtB -> B_5_742_0 [ 2 ] * _rtP -> P_187 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_5_745_0 [ 0 ] = _rtP -> P_188 [ 0 ]
; _rtB -> B_5_745_0 [ 1 ] = _rtP -> P_188 [ 1 ] ; _rtB -> B_5_745_0 [ 2 ] =
_rtP -> P_188 [ 2 ] ; } B_5_578_0_idx = ( ( _rtB -> B_5_668_0 [ 0 ] + _rtB ->
B_5_744_0 [ 0 ] ) + 0.0 ) + _rtB -> B_5_745_0 [ 0 ] ; B_5_578_0_idx_0 = ( (
_rtB -> B_5_668_0 [ 1 ] + _rtB -> B_5_744_0 [ 1 ] ) + 0.0 ) + _rtB ->
B_5_745_0 [ 1 ] ; rtb_B_5_842_0 = ( ( _rtB -> B_5_668_0 [ 2 ] + _rtB ->
B_5_744_0 [ 2 ] ) + 0.0 ) + _rtB -> B_5_745_0 [ 2 ] ; for ( i_0 = 0 ; i_0 < 3
; i_0 ++ ) { B_5_840_0 [ i_0 ] = 0.0 ; B_5_840_0 [ i_0 ] += _rtP -> P_189 [
i_0 ] * B_5_578_0_idx ; B_5_840_0 [ i_0 ] += _rtP -> P_189 [ i_0 + 3 ] *
B_5_578_0_idx_0 ; B_5_840_0 [ i_0 ] += _rtP -> P_189 [ i_0 + 6 ] *
rtb_B_5_842_0 ; } B_5_840_0 [ 0 ] = ( B_5_840_0 [ 0 ] - B_5_663_0 [ 0 ] ) - (
_rtB -> B_5_0_0 [ 1 ] * rtb_B_5_731_0 [ 2 ] - _rtB -> B_5_0_0 [ 2 ] *
rtb_B_5_731_0 [ 1 ] ) ; B_5_840_0 [ 1 ] = ( B_5_840_0 [ 1 ] - B_5_663_0 [ 1 ]
) - ( _rtB -> B_5_0_0 [ 2 ] * rtb_B_5_731_0 [ 0 ] - _rtB -> B_5_0_0 [ 0 ] *
rtb_B_5_731_0 [ 2 ] ) ; B_5_840_0 [ 2 ] = ( B_5_840_0 [ 2 ] - B_5_663_0 [ 2 ]
) - ( _rtB -> B_5_0_0 [ 0 ] * rtb_B_5_731_0 [ 1 ] - _rtB -> B_5_0_0 [ 1 ] *
rtb_B_5_731_0 [ 0 ] ) ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { B [ 3 * i_0 ] =
rtb_B_5_659_0 [ 6 * i_0 ] ; B [ 1 + 3 * i_0 ] = rtb_B_5_659_0 [ 6 * i_0 + 1 ]
; B [ 2 + 3 * i_0 ] = rtb_B_5_659_0 [ 6 * i_0 + 2 ] ; } memcpy ( &
rtb_B_5_252_0 [ 0 ] , & B [ 0 ] , 9U * sizeof ( real_T ) ) ;
rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( B_5_840_0 , rtb_B_5_252_0 , _rtB ->
B_5_757_0 ) ; B_5_840_0 [ 0 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) )
-> ubvbwb_CSTATE [ 0 ] ; B_5_840_0 [ 1 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> ubvbwb_CSTATE [ 1 ] ; B_5_840_0 [ 2 ] = ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> ubvbwb_CSTATE [ 2 ] ; _rtB ->
B_5_769_0 [ 0 ] = ( 0.0 - B_5_840_0 [ 0 ] * 0.0 ) / _rtB -> B_5_596_0 + (
B_5_840_0 [ 1 ] * _rtB -> B_5_0_0 [ 2 ] - B_5_840_0 [ 2 ] * _rtB -> B_5_0_0 [
1 ] ) ; _rtB -> B_5_769_0 [ 1 ] = ( 0.0 - B_5_840_0 [ 1 ] * 0.0 ) / _rtB ->
B_5_596_0 + ( B_5_840_0 [ 2 ] * _rtB -> B_5_0_0 [ 0 ] - B_5_840_0 [ 0 ] *
_rtB -> B_5_0_0 [ 2 ] ) ; _rtB -> B_5_769_0 [ 2 ] = ( 0.0 - B_5_840_0 [ 2 ] *
0.0 ) / _rtB -> B_5_596_0 + ( B_5_840_0 [ 0 ] * _rtB -> B_5_0_0 [ 1 ] -
B_5_840_0 [ 1 ] * _rtB -> B_5_0_0 [ 0 ] ) ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++
) { _rtB -> B_5_771_0 [ i_0 ] = 0.0 ; _rtB -> B_5_771_0 [ i_0 ] +=
rtb_B_5_646_0 [ 3 * i_0 ] * B_5_840_0 [ 0 ] ; _rtB -> B_5_771_0 [ i_0 ] +=
rtb_B_5_646_0 [ 3 * i_0 + 1 ] * B_5_840_0 [ 1 ] ; _rtB -> B_5_771_0 [ i_0 ]
+= rtb_B_5_646_0 [ 3 * i_0 + 2 ] * B_5_840_0 [ 2 ] ; } B_5_772_0 [ 0 ] = ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> xeyeze_CSTATE [ 0 ] ; B_5_772_0
[ 1 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> xeyeze_CSTATE [ 1 ]
; B_5_772_0 [ 2 ] = ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
xeyeze_CSTATE [ 2 ] ; ssCallAccelRunBlock ( S , 5 , 773 , SS_CALL_MDL_OUTPUTS
) ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_5_775_0 [ 0 ] = _rtP ->
P_195 [ 0 ] * _rtDW -> NextOutput_d ; _rtB -> B_5_775_0 [ 1 ] = _rtP -> P_195
[ 1 ] * _rtDW -> NextOutput_d ; _rtB -> B_5_775_0 [ 2 ] = _rtP -> P_195 [ 2 ]
* _rtDW -> NextOutput_d ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_5_777_0 = _rtP -> P_197 ; } B_5_840_0 [ 0 ] = _rtP -> P_196 * _rtB ->
B_5_151_0 . rsun [ 0 ] - _rtB -> B_5_151_0 . j2000 [ 0 ] ; B_5_840_0 [ 1 ] =
_rtP -> P_196 * _rtB -> B_5_151_0 . rsun [ 1 ] - _rtB -> B_5_151_0 . j2000 [
1 ] ; B_5_840_0 [ 2 ] = _rtP -> P_196 * _rtB -> B_5_151_0 . rsun [ 2 ] - _rtB
-> B_5_151_0 . j2000 [ 2 ] ; rtb_B_5_842_0 = ( ( _rtB -> B_5_31_0 * _rtB ->
B_5_31_0 + _rtB -> B_5_36_0 [ 0 ] * _rtB -> B_5_36_0 [ 0 ] ) + _rtB ->
B_5_36_0 [ 1 ] * _rtB -> B_5_36_0 [ 1 ] ) + _rtB -> B_5_36_0 [ 2 ] * _rtB ->
B_5_36_0 [ 2 ] ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_l
!= 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_l = 0 ; }
rtb_B_5_842_0 = muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } else { if (
rtb_B_5_842_0 < 0.0 ) { rtb_B_5_842_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_5_842_0 ) ) ; } else { rtb_B_5_842_0 =
muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } _rtDW -> sqrt_DWORK1_l = 1 ; }
rtb_B_5_785_0 = _rtB -> B_5_36_0 [ 1 ] / rtb_B_5_842_0 ; B_5_578_0_idx = _rtB
-> B_5_36_0 [ 2 ] / rtb_B_5_842_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> B_5_789_0 = _rtP -> P_198 ; } B_5_578_0_idx_0 = _rtB -> B_5_36_0 [ 0 ] /
rtb_B_5_842_0 ; rtb_B_5_842_0 = _rtB -> B_5_31_0 / rtb_B_5_842_0 ; _rtB ->
B_5_805_0 = ( ( ( _rtB -> B_5_789_0 - rtb_B_5_785_0 * rtb_B_5_785_0 ) -
B_5_578_0_idx * B_5_578_0_idx ) * _rtP -> P_199 * B_5_840_0 [ 0 ] + (
B_5_578_0_idx_0 * rtb_B_5_785_0 + rtb_B_5_842_0 * B_5_578_0_idx ) * _rtP ->
P_200 * B_5_840_0 [ 1 ] ) + ( B_5_578_0_idx_0 * B_5_578_0_idx - rtb_B_5_842_0
* rtb_B_5_785_0 ) * _rtP -> P_201 * B_5_840_0 [ 2 ] ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> B_5_813_0 = _rtP -> P_203 ; } _rtB -> B_5_822_0 = ( ( (
_rtB -> B_5_813_0 - B_5_578_0_idx_0 * B_5_578_0_idx_0 ) - B_5_578_0_idx *
B_5_578_0_idx ) * _rtP -> P_204 * B_5_840_0 [ 1 ] + ( B_5_578_0_idx_0 *
rtb_B_5_785_0 - rtb_B_5_842_0 * B_5_578_0_idx ) * _rtP -> P_202 * B_5_840_0 [
0 ] ) + ( rtb_B_5_842_0 * B_5_578_0_idx_0 + rtb_B_5_785_0 * B_5_578_0_idx ) *
_rtP -> P_205 * B_5_840_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> B_5_835_0 = _rtP -> P_208 ; } _rtB -> B_5_839_0 = ( ( B_5_578_0_idx_0 *
B_5_578_0_idx + rtb_B_5_842_0 * rtb_B_5_785_0 ) * _rtP -> P_206 * B_5_840_0 [
0 ] + ( rtb_B_5_785_0 * B_5_578_0_idx - rtb_B_5_842_0 * B_5_578_0_idx_0 ) *
_rtP -> P_207 * B_5_840_0 [ 1 ] ) + ( ( _rtB -> B_5_835_0 - B_5_578_0_idx_0 *
B_5_578_0_idx_0 ) - rtb_B_5_785_0 * rtb_B_5_785_0 ) * _rtP -> P_209 *
B_5_840_0 [ 2 ] ; B_5_840_0 [ 0 ] = _rtB -> B_5_805_0 ; B_5_840_0 [ 1 ] =
_rtB -> B_5_822_0 ; B_5_840_0 [ 2 ] = _rtB -> B_5_839_0 ; rtb_B_5_842_0 = (
B_5_840_0 [ 0 ] * B_5_840_0 [ 0 ] + B_5_840_0 [ 1 ] * B_5_840_0 [ 1 ] ) +
B_5_840_0 [ 2 ] * B_5_840_0 [ 2 ] ; if ( rtb_B_5_842_0 < 0.0 ) { _rtB ->
B_5_843_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_5_842_0 ) ) ; }
else { _rtB -> B_5_843_0 = muDoubleScalarSqrt ( rtb_B_5_842_0 ) ; } _rtB ->
B_5_844_0 [ 0 ] = B_5_840_0 [ 0 ] * 0.0 ; _rtB -> B_5_844_0 [ 1 ] = B_5_840_0
[ 1 ] * 0.0 ; _rtB -> B_5_844_0 [ 2 ] = B_5_840_0 [ 2 ] * 0.0 ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> Switch_Mode = ( _rtB -> B_5_843_0 > _rtP
-> P_210 ) ; } ssCallAccelRunBlock ( S , 5 , 846 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 847 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 848 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 849 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 850 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 5 , 851 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_ACStesbed_T * _rtB ;
P_ACStesbed_T * _rtP ; DW_ACStesbed_T * _rtDW ; _rtDW = ( ( DW_ACStesbed_T *
) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_ACStesbed_T * ) ssGetDefaultParam ( S
) ) ; _rtB = ( ( B_ACStesbed_T * ) _ssGetBlockIO ( S ) ) ; _rtDW ->
q0q1q2q3_IWORK . IcNeedsLoading = 0 ; _rtDW -> q0q1q2q3_IWORK_d .
IcNeedsLoading = 0 ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtDW -> NextOutput
= rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed ) * _rtP -> P_53 + _rtP ->
P_52 ; } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ]
== _rtP -> P_72 ) { switch ( _rtDW -> IntegratorLimited_MODE [ 0 ] ) { case
INTG_UPPER_SAT : if ( _rtB -> B_5_312_0 [ 0 ] < 0.0 ) { ssSetSolverNeedsReset
( S ) ; _rtDW -> IntegratorLimited_MODE [ 0 ] = INTG_LEAVING_UPPER_SAT ; }
break ; case INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_5_312_0 [ 0 ] >= 0.0 ) {
_rtDW -> IntegratorLimited_MODE [ 0 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( S ) ; } break ; default : ssSetSolverNeedsReset ( S )
; if ( _rtB -> B_5_312_0 [ 0 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 0
] = INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE [ 0 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] == _rtP -> P_73 ) {
switch ( _rtDW -> IntegratorLimited_MODE [ 0 ] ) { case INTG_LOWER_SAT : if (
_rtB -> B_5_312_0 [ 0 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE [ 0 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_5_312_0 [ 0 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE [ 0 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S ) ;
} break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_312_0 [ 0
] > 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 0 ] = INTG_LEAVING_LOWER_SAT ;
} else { _rtDW -> IntegratorLimited_MODE [ 0 ] = INTG_LOWER_SAT ; } break ; }
} else { _rtDW -> IntegratorLimited_MODE [ 0 ] = INTG_NORMAL ; } if ( ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ]
== _rtP -> P_72 ) { switch ( _rtDW -> IntegratorLimited_MODE [ 1 ] ) { case
INTG_UPPER_SAT : if ( _rtB -> B_5_312_0 [ 1 ] < 0.0 ) { ssSetSolverNeedsReset
( S ) ; _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_LEAVING_UPPER_SAT ; }
break ; case INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_5_312_0 [ 1 ] >= 0.0 ) {
_rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( S ) ; } break ; default : ssSetSolverNeedsReset ( S )
; if ( _rtB -> B_5_312_0 [ 1 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 1
] = INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE [ 1 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] == _rtP -> P_73 ) {
switch ( _rtDW -> IntegratorLimited_MODE [ 1 ] ) { case INTG_LOWER_SAT : if (
_rtB -> B_5_312_0 [ 1 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE [ 1 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_5_312_0 [ 1 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE [ 1 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S ) ;
} break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_312_0 [ 1
] > 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_LEAVING_LOWER_SAT ;
} else { _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_LOWER_SAT ; } break ; }
} else { _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_NORMAL ; } if ( ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ]
== _rtP -> P_72 ) { switch ( _rtDW -> IntegratorLimited_MODE [ 2 ] ) { case
INTG_UPPER_SAT : if ( _rtB -> B_5_312_0 [ 2 ] < 0.0 ) { ssSetSolverNeedsReset
( S ) ; _rtDW -> IntegratorLimited_MODE [ 2 ] = INTG_LEAVING_UPPER_SAT ; }
break ; case INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_5_312_0 [ 2 ] >= 0.0 ) {
_rtDW -> IntegratorLimited_MODE [ 2 ] = INTG_UPPER_SAT ;
ssSetSolverNeedsReset ( S ) ; } break ; default : ssSetSolverNeedsReset ( S )
; if ( _rtB -> B_5_312_0 [ 2 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 2
] = INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE [ 2 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] == _rtP -> P_73 ) {
switch ( _rtDW -> IntegratorLimited_MODE [ 2 ] ) { case INTG_LOWER_SAT : if (
_rtB -> B_5_312_0 [ 2 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE [ 2 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_5_312_0 [ 2 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE [ 2 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S ) ;
} break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_312_0 [ 2
] > 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 2 ] = INTG_LEAVING_LOWER_SAT ;
} else { _rtDW -> IntegratorLimited_MODE [ 2 ] = INTG_LOWER_SAT ; } break ; }
} else { _rtDW -> IntegratorLimited_MODE [ 2 ] = INTG_NORMAL ; } } { enum {
INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 0 ] == _rtP -> P_75 )
{ switch ( _rtDW -> IntegratorLimited_MODE_k [ 0 ] ) { case INTG_UPPER_SAT :
if ( _rtB -> B_5_308_0 [ 0 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_k [ 0 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_5_308_0 [ 0 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_k [ 0 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_308_0 [
0 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_k [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_k [ 0 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 0 ] == _rtP -> P_76 )
{ switch ( _rtDW -> IntegratorLimited_MODE_k [ 0 ] ) { case INTG_LOWER_SAT :
if ( _rtB -> B_5_308_0 [ 0 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_k [ 0 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_5_308_0 [ 0 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_k [ 0 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_308_0 [
0 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_k [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_k [ 0 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_k [ 0 ]
= INTG_NORMAL ; } if ( ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_d [ 1 ] == _rtP -> P_75 ) { switch ( _rtDW ->
IntegratorLimited_MODE_k [ 1 ] ) { case INTG_UPPER_SAT : if ( _rtB ->
B_5_308_0 [ 1 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_k [ 1 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_5_308_0 [ 1 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_k [ 1 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_308_0 [
1 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_k [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_k [ 1 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 1 ] == _rtP -> P_76 )
{ switch ( _rtDW -> IntegratorLimited_MODE_k [ 1 ] ) { case INTG_LOWER_SAT :
if ( _rtB -> B_5_308_0 [ 1 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_k [ 1 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_5_308_0 [ 1 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_k [ 1 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_308_0 [
1 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_k [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_k [ 1 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_k [ 1 ]
= INTG_NORMAL ; } if ( ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_d [ 2 ] == _rtP -> P_75 ) { switch ( _rtDW ->
IntegratorLimited_MODE_k [ 2 ] ) { case INTG_UPPER_SAT : if ( _rtB ->
B_5_308_0 [ 2 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_k [ 2 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_5_308_0 [ 2 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_k [ 2 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_308_0 [
2 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_k [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_k [ 2 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ] == _rtP -> P_76 )
{ switch ( _rtDW -> IntegratorLimited_MODE_k [ 2 ] ) { case INTG_LOWER_SAT :
if ( _rtB -> B_5_308_0 [ 2 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_k [ 2 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_5_308_0 [ 2 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_k [ 2 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_5_308_0 [
2 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_k [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_k [ 2 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_k [ 2 ]
= INTG_NORMAL ; } } if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtDW ->
DiscreteTimeIntegrator_IC_LOADING = 0U ; memcpy ( & _rtDW ->
DiscreteTimeIntegrator_DSTATE [ 0 ] , & _rtB -> B_5_342_0 [ 0 ] , 18U *
sizeof ( real_T ) ) ; _rtDW -> DiscreteTimeIntegrator1_SYSTEM_ENABLE = 0U ;
memcpy ( & _rtDW -> DiscreteTimeIntegrator1_DSTATE [ 0 ] , & _rtB ->
B_5_418_0 [ 18 ] , 9U * sizeof ( real_T ) ) ; _rtDW ->
DiscreteTimeIntegrator2_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE [ 0 ] = _rtB -> B_5_422_0 [ 0 ] ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE [ 1 ] = _rtB -> B_5_422_0 [ 1 ] ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE [ 2 ] = _rtB -> B_5_422_0 [ 2 ] ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtDW -> NextOutput_d =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_o ) * _rtP -> P_193 + _rtP
-> P_192 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_ACStesbed_T * _rtB ;
P_ACStesbed_T * _rtP ; DW_ACStesbed_T * _rtDW ; _rtDW = ( ( DW_ACStesbed_T *
) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_ACStesbed_T * ) ssGetDefaultParam ( S
) ) ; _rtB = ( ( B_ACStesbed_T * ) _ssGetBlockIO ( S ) ) ; { ( (
XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> pqr_CSTATE [ 0 ] = _rtB -> B_5_757_0
[ 0 ] ; ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> pqr_CSTATE [ 1 ] = _rtB
-> B_5_757_0 [ 1 ] ; ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> pqr_CSTATE [
2 ] = _rtB -> B_5_757_0 [ 2 ] ; } { ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) )
-> q0q1q2q3_CSTATE [ 0 ] = _rtB -> B_5_651_0 ; ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> q0q1q2q3_CSTATE [ 1 ] = _rtB -> B_5_652_0 ; ( (
XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE [ 2 ] = _rtB ->
B_5_653_0 ; ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE [ 3 ]
= _rtB -> B_5_654_0 ; } { ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) ->
q0q1q2q3_CSTATE_f [ 0 ] = _rtB -> B_5_451_0 ; ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_f [ 1 ] = _rtB -> B_5_452_0 ; ( (
XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_f [ 2 ] = _rtB ->
B_5_453_0 ; ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_f [ 3
] = _rtB -> B_5_454_0 ; } { ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) ->
Integrator_CSTATE [ 0 ] = _rtB -> B_5_775_0 [ 0 ] ; ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> Integrator_CSTATE [ 1 ] = _rtB -> B_5_775_0 [ 1 ] ; ( (
XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE [ 2 ] = _rtB ->
B_5_775_0 [ 2 ] ; } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( _rtDW ->
IntegratorLimited_MODE [ 0 ] != INTG_UPPER_SAT ) && ( _rtDW ->
IntegratorLimited_MODE [ 0 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] = _rtB -> B_5_312_0 [ 0 ] ;
( ( XDis_ACStesbed_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE [ 0 ] = FALSE ; } else { ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE [ 0 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE [ 0 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed_T * )
ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] = TRUE ; } }
if ( ( _rtDW -> IntegratorLimited_MODE [ 1 ] != INTG_UPPER_SAT ) && ( _rtDW
-> IntegratorLimited_MODE [ 1 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = _rtB -> B_5_312_0 [ 1
] ; ( ( XDis_ACStesbed_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE [ 1 ] = FALSE ; } else { ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE [ 1 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE [ 1 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed_T * )
ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = TRUE ; } }
if ( ( _rtDW -> IntegratorLimited_MODE [ 2 ] != INTG_UPPER_SAT ) && ( _rtDW
-> IntegratorLimited_MODE [ 2 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = _rtB -> B_5_312_0 [ 2
] ; ( ( XDis_ACStesbed_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE [ 2 ] = FALSE ; } else { ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE [ 2 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE [ 2 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed_T * )
ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = TRUE ; } }
} { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( _rtDW -> IntegratorLimited_MODE_k
[ 0 ] != INTG_UPPER_SAT ) && ( _rtDW -> IntegratorLimited_MODE_k [ 0 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) ->
IntegratorLimited_CSTATE_d [ 0 ] = _rtB -> B_5_308_0 [ 0 ] ; ( (
XDis_ACStesbed_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE_d [ 0 ] = FALSE ; } else { ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_d [ 0 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE_k [ 0 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE_k [ 0 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed_T *
) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE_d [ 0 ] = TRUE ;
} } if ( ( _rtDW -> IntegratorLimited_MODE_k [ 1 ] != INTG_UPPER_SAT ) && (
_rtDW -> IntegratorLimited_MODE_k [ 1 ] != INTG_LOWER_SAT ) ) { ( (
XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_d [ 1 ] =
_rtB -> B_5_308_0 [ 1 ] ; ( ( XDis_ACStesbed_T * ) ssGetContStateDisabled ( S
) ) -> IntegratorLimited_CSTATE_d [ 1 ] = FALSE ; } else { ( (
XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_d [ 1 ] =
0.0 ; if ( ( _rtDW -> IntegratorLimited_MODE_k [ 1 ] == INTG_UPPER_SAT ) || (
_rtDW -> IntegratorLimited_MODE_k [ 1 ] == INTG_LOWER_SAT ) ) { ( (
XDis_ACStesbed_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE_d [ 1 ] = TRUE ; } } if ( ( _rtDW ->
IntegratorLimited_MODE_k [ 2 ] != INTG_UPPER_SAT ) && ( _rtDW ->
IntegratorLimited_MODE_k [ 2 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed_T *
) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ] = _rtB -> B_5_308_0 [ 2
] ; ( ( XDis_ACStesbed_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE_d [ 2 ] = FALSE ; } else { ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE_k [ 2 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE_k [ 2 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed_T *
) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ] = TRUE ;
} } } { ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> ubvbwb_CSTATE [ 0 ] =
_rtB -> B_5_769_0 [ 0 ] ; ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) ->
ubvbwb_CSTATE [ 1 ] = _rtB -> B_5_769_0 [ 1 ] ; ( ( XDot_ACStesbed_T * )
ssGetdX ( S ) ) -> ubvbwb_CSTATE [ 2 ] = _rtB -> B_5_769_0 [ 2 ] ; } { ( (
XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> xeyeze_CSTATE [ 0 ] = _rtB ->
B_5_771_0 [ 0 ] ; ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) -> xeyeze_CSTATE [
1 ] = _rtB -> B_5_771_0 [ 1 ] ; ( ( XDot_ACStesbed_T * ) ssGetdX ( S ) ) ->
xeyeze_CSTATE [ 2 ] = _rtB -> B_5_771_0 [ 2 ] ; } }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_ACStesbed_T * _rtB ;
P_ACStesbed_T * _rtP ; ZCV_ACStesbed_T * _rtZCSV ; DW_ACStesbed_T * _rtDW ;
_rtDW = ( ( DW_ACStesbed_T * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( (
P_ACStesbed_T * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_ACStesbed_T * )
_ssGetBlockIO ( S ) ) ; { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( _rtDW ->
IntegratorLimited_MODE [ 0 ] == INTG_LEAVING_UPPER_SAT && ( ( X_ACStesbed_T *
) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] >= _rtP -> P_72 )
{ ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC [ 0 ] = 0.0 ; } else { ( ( ZCV_ACStesbed_T *
) ssGetSolverZcSignalVector ( S ) ) -> IntegratorLimited_IntgUpLimit_ZC [ 0 ]
= ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [
0 ] - _rtP -> P_72 ; } if ( _rtDW -> IntegratorLimited_MODE [ 0 ] ==
INTG_LEAVING_LOWER_SAT && ( ( X_ACStesbed_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 0 ] <= _rtP -> P_73 ) { ( ( ZCV_ACStesbed_T * )
ssGetSolverZcSignalVector ( S ) ) -> IntegratorLimited_IntgLoLimit_ZC [ 0 ] =
0.0 ; } else { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC [ 0 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] - _rtP -> P_73 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 1 ] == INTG_LEAVING_UPPER_SAT && ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ]
>= _rtP -> P_72 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) )
-> IntegratorLimited_IntgUpLimit_ZC [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC [ 1 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] - _rtP -> P_72 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 1 ] == INTG_LEAVING_LOWER_SAT && ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ]
<= _rtP -> P_73 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) )
-> IntegratorLimited_IntgLoLimit_ZC [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC [ 1 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] - _rtP -> P_73 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 2 ] == INTG_LEAVING_UPPER_SAT && ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ]
>= _rtP -> P_72 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) )
-> IntegratorLimited_IntgUpLimit_ZC [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC [ 2 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] - _rtP -> P_72 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 2 ] == INTG_LEAVING_LOWER_SAT && ( (
X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ]
<= _rtP -> P_73 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) )
-> IntegratorLimited_IntgLoLimit_ZC [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC [ 2 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] - _rtP -> P_73 ; }
} { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( _rtDW -> IntegratorLimited_MODE_k [
0 ] == INTG_LEAVING_UPPER_SAT && ( ( X_ACStesbed_T * ) ssGetContStates ( S )
) -> IntegratorLimited_CSTATE_d [ 0 ] >= _rtP -> P_75 ) { ( ( ZCV_ACStesbed_T
* ) ssGetSolverZcSignalVector ( S ) ) -> IntegratorLimited_IntgUpLimit_ZC_o [
0 ] = 0.0 ; } else { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgUpLimit_ZC_o [ 0 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 0 ] - _rtP -> P_75 ;
} if ( _rtDW -> IntegratorLimited_MODE_k [ 0 ] == INTG_LEAVING_LOWER_SAT && (
( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 0
] <= _rtP -> P_76 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgLoLimit_ZC_l [ 0 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_l [ 0 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 0 ] - _rtP -> P_76 ;
} if ( _rtDW -> IntegratorLimited_MODE_k [ 1 ] == INTG_LEAVING_UPPER_SAT && (
( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 1
] >= _rtP -> P_75 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgUpLimit_ZC_o [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_o [ 1 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 1 ] - _rtP -> P_75 ;
} if ( _rtDW -> IntegratorLimited_MODE_k [ 1 ] == INTG_LEAVING_LOWER_SAT && (
( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 1
] <= _rtP -> P_76 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgLoLimit_ZC_l [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_l [ 1 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 1 ] - _rtP -> P_76 ;
} if ( _rtDW -> IntegratorLimited_MODE_k [ 2 ] == INTG_LEAVING_UPPER_SAT && (
( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 2
] >= _rtP -> P_75 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgUpLimit_ZC_o [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_o [ 2 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ] - _rtP -> P_75 ;
} if ( _rtDW -> IntegratorLimited_MODE_k [ 2 ] == INTG_LEAVING_LOWER_SAT && (
( X_ACStesbed_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 2
] <= _rtP -> P_76 ) { ( ( ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgLoLimit_ZC_l [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_l [ 2 ] = ( ( X_ACStesbed_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_d [ 2 ] - _rtP -> P_76 ;
} } if ( _rtDW -> If_ActiveSubsystem == 1 ) { } _rtZCSV ->
Saturation_UprLim_ZC [ 0 ] = _rtB -> B_5_306_0 [ 0 ] - _rtP -> P_87 ; _rtZCSV
-> Saturation_LwrLim_ZC [ 0 ] = _rtB -> B_5_306_0 [ 0 ] - _rtP -> P_88 ;
_rtZCSV -> Saturation_UprLim_ZC [ 1 ] = _rtB -> B_5_306_0 [ 1 ] - _rtP ->
P_87 ; _rtZCSV -> Saturation_LwrLim_ZC [ 1 ] = _rtB -> B_5_306_0 [ 1 ] - _rtP
-> P_88 ; _rtZCSV -> Saturation_UprLim_ZC [ 2 ] = _rtB -> B_5_306_0 [ 2 ] -
_rtP -> P_87 ; _rtZCSV -> Saturation_LwrLim_ZC [ 2 ] = _rtB -> B_5_306_0 [ 2
] - _rtP -> P_88 ; _rtZCSV -> Saturation_UprLim_ZC_h [ 0 ] = _rtB ->
B_5_667_0 [ 0 ] - _rtP -> P_164 ; _rtZCSV -> Saturation_LwrLim_ZC_i [ 0 ] =
_rtB -> B_5_667_0 [ 0 ] - _rtP -> P_165 ; _rtZCSV -> Saturation_UprLim_ZC_h [
1 ] = _rtB -> B_5_667_0 [ 1 ] - _rtP -> P_164 ; _rtZCSV ->
Saturation_LwrLim_ZC_i [ 1 ] = _rtB -> B_5_667_0 [ 1 ] - _rtP -> P_165 ;
_rtZCSV -> Saturation_UprLim_ZC_h [ 2 ] = _rtB -> B_5_667_0 [ 2 ] - _rtP ->
P_164 ; _rtZCSV -> Saturation_LwrLim_ZC_i [ 2 ] = _rtB -> B_5_667_0 [ 2 ] -
_rtP -> P_165 ; _rtZCSV -> Switch_SwitchCond_ZC = _rtB -> B_5_843_0 - _rtP ->
P_210 ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 1580780481U ) ; ssSetChecksumVal ( S , 1 , 1117063620U ) ;
ssSetChecksumVal ( S , 2 , 1550795242U ) ; ssSetChecksumVal ( S , 3 ,
1665484139U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.2" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_ACStesbed_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_ACStesbed_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_ACStesbed_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & ACStesbed_rtDefaultP ) ; } static void mdlInitializeSampleTimes
( SimStruct * S ) { } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
