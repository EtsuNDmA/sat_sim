#include "__cf_ACStesbed1.h"
#include <math.h>
#include "ACStesbed1_acc.h"
#include "ACStesbed1_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
void ACStesbed1_PositiveTrace_Enable ( SimStruct * const S ) { if (
ssGetTaskTime ( S , 0 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S )
; } } void ACStesbed1_PositiveTrace_Disable ( SimStruct * const S ) {
ssSetSolverNeedsReset ( S ) ; } void ACStesbed1_PositiveTrace ( SimStruct *
const S , real_T rtu_traceDCM , real_T rtu_DCM , real_T rtu_DCM_p , real_T
rtu_DCM_i , real_T rtu_DCM_g , real_T rtu_DCM_m , real_T rtu_DCM_j , real_T *
rty_qwqxqyqz , real_T rty_qwqxqyqz_g [ 3 ] , B_PositiveTrace_ACStesbed1_T *
localB , DW_PositiveTrace_ACStesbed1_T * localDW ,
P_PositiveTrace_ACStesbed1_T * localP ) { real_T rtb_B_5_4_0 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { localB -> B_5_0_0 = localP -> P_0 ; }
rtb_B_5_4_0 = rtu_traceDCM + localB -> B_5_0_0 ; if ( ssIsMajorTimeStep ( S )
) { if ( localDW -> sqrt_DWORK1 != 0 ) { ssSetSolverNeedsReset ( S ) ;
localDW -> sqrt_DWORK1 = 0 ; } rtb_B_5_4_0 = muDoubleScalarSqrt ( rtb_B_5_4_0
) ; } else { if ( rtb_B_5_4_0 < 0.0 ) { rtb_B_5_4_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_5_4_0 ) ) ; } else { rtb_B_5_4_0 =
muDoubleScalarSqrt ( rtb_B_5_4_0 ) ; } localDW -> sqrt_DWORK1 = 1 ; } *
rty_qwqxqyqz = localP -> P_1 * rtb_B_5_4_0 ; rtb_B_5_4_0 *= localP -> P_2 ;
rty_qwqxqyqz_g [ 0 ] = ( rtu_DCM_p - rtu_DCM ) / rtb_B_5_4_0 ; rty_qwqxqyqz_g
[ 1 ] = ( rtu_DCM_i - rtu_DCM_g ) / rtb_B_5_4_0 ; rty_qwqxqyqz_g [ 2 ] = (
rtu_DCM_j - rtu_DCM_m ) / rtb_B_5_4_0 ; } void ACStesbed1_PositiveTrace_Term
( SimStruct * const S ) { } void ACStesbed1_NegativeTrace_Enable ( SimStruct
* const S ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } void ACStesbed1_NegativeTrace_Disable (
SimStruct * const S , DW_NegativeTrace_ACStesbed1_T * localDW ) {
ssSetSolverNeedsReset ( S ) ; switch ( localDW ->
FindMaximumDiagonalValue_ActiveSubsystem ) { case 0 : ssSetSolverNeedsReset (
S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ; break ; case 2 :
ssSetSolverNeedsReset ( S ) ; break ; } localDW ->
FindMaximumDiagonalValue_ActiveSubsystem = - 1 ; } void
ACStesbed1_NegativeTrace_ZC ( real_T rtu_DCM , real_T rtu_DCM_b , real_T
rtu_DCM_k , B_NegativeTrace_ACStesbed1_T * localB ,
DW_NegativeTrace_ACStesbed1_T * localDW , ZCV_NegativeTrace_ACStesbed1_T *
localZCSV ) { localZCSV -> FindMaximumDiagonalValue_IfInput_ZC [ 0 ] = 0.0 ;
localZCSV -> FindMaximumDiagonalValue_IfInput_ZC [ 1 ] = 0.0 ; if ( (
rtu_DCM_b > rtu_DCM ) && ( rtu_DCM_b > rtu_DCM_k ) ) { localZCSV ->
FindMaximumDiagonalValue_IfInput_ZC [ 0 ] = 1.0 ; } else { if ( rtu_DCM_k >
rtu_DCM ) { localZCSV -> FindMaximumDiagonalValue_IfInput_ZC [ 1 ] = 1.0 ; }
} { localZCSV -> Switch_SwitchCond_ZC_nf = 0.0 ; } if ( localDW ->
FindMaximumDiagonalValue_ActiveSubsystem == 0 ) { localZCSV ->
Switch_SwitchCond_ZC_nf = localB -> B_6_2_0 ; } { localZCSV ->
Switch_SwitchCond_ZC_l = 0.0 ; } if ( localDW ->
FindMaximumDiagonalValue_ActiveSubsystem == 1 ) { localZCSV ->
Switch_SwitchCond_ZC_l = localB -> B_7_2_0 ; } { localZCSV ->
Switch_SwitchCond_ZC_n = 0.0 ; } if ( localDW ->
FindMaximumDiagonalValue_ActiveSubsystem == 2 ) { localZCSV ->
Switch_SwitchCond_ZC_n = localB -> B_8_2_0 ; } } void
ACStesbed1_NegativeTrace ( SimStruct * const S , real_T rtu_DCM , real_T
rtu_DCM_b , real_T rtu_DCM_k , real_T rtu_DCM_k3 , real_T rtu_DCM_a , real_T
rtu_DCM_ky , real_T rtu_DCM_n , real_T rtu_DCM_as , real_T rtu_DCM_o , real_T
* rty_1 , real_T * rty_2 , real_T * rty_3 , real_T * rty_4 ,
B_NegativeTrace_ACStesbed1_T * localB , DW_NegativeTrace_ACStesbed1_T *
localDW , P_NegativeTrace_ACStesbed1_T * localP ) { int8_T rtPrevAction ;
int8_T rtAction ; real_T rtb_B_6_4_0 ; real_T tmp ; rtPrevAction = localDW ->
FindMaximumDiagonalValue_ActiveSubsystem ; if ( ssIsMajorTimeStep ( S ) ) {
if ( ( rtu_DCM_b > rtu_DCM ) && ( rtu_DCM_b > rtu_DCM_k ) ) { rtAction = 0 ;
} else if ( rtu_DCM_k > rtu_DCM ) { rtAction = 1 ; } else { rtAction = 2 ; }
localDW -> FindMaximumDiagonalValue_ActiveSubsystem = rtAction ; } else {
rtAction = localDW -> FindMaximumDiagonalValue_ActiveSubsystem ; } if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
ssSetSolverNeedsReset ( S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ;
break ; case 2 : ssSetSolverNeedsReset ( S ) ; break ; } } switch ( rtAction
) { case 0 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 )
!= ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit
( S , 1 , 0 ) ) { localB -> B_6_0_0 = localP -> P_0 ; } rtb_B_6_4_0 = ( (
rtu_DCM_b - rtu_DCM ) - rtu_DCM_k ) + localB -> B_6_0_0 ; if (
ssIsMajorTimeStep ( S ) ) { if ( localDW -> sqrt_DWORK1_a != 0 ) {
ssSetSolverNeedsReset ( S ) ; localDW -> sqrt_DWORK1_a = 0 ; } localB ->
B_6_2_0 = muDoubleScalarSqrt ( rtb_B_6_4_0 ) ; } else { if ( rtb_B_6_4_0 <
0.0 ) { localB -> B_6_2_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
rtb_B_6_4_0 ) ) ; } else { localB -> B_6_2_0 = muDoubleScalarSqrt (
rtb_B_6_4_0 ) ; } localDW -> sqrt_DWORK1_a = 1 ; } * rty_3 = localP -> P_1 *
localB -> B_6_2_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { localB -> B_6_7_0 =
localP -> P_2 ; localB -> B_6_8_0 [ 0 ] = localP -> P_3 [ 0 ] ; localB ->
B_6_8_0 [ 1 ] = localP -> P_3 [ 1 ] ; } if ( ssIsMajorTimeStep ( S ) ) {
localDW -> Switch_Mode_f = ( localB -> B_6_2_0 != 0.0 ) ; } if ( localDW ->
Switch_Mode_f ) { rtb_B_6_4_0 = localB -> B_6_7_0 ; } else { rtb_B_6_4_0 =
localB -> B_6_8_0 [ 0 ] ; } if ( localDW -> Switch_Mode_f ) { tmp = localB ->
B_6_2_0 ; } else { tmp = localB -> B_6_8_0 [ 1 ] ; } rtb_B_6_4_0 /= tmp ; *
rty_2 = ( rtu_DCM_k3 + rtu_DCM_a ) * rtb_B_6_4_0 * localP -> P_4 ; * rty_4 =
( rtu_DCM_ky + rtu_DCM_n ) * rtb_B_6_4_0 * localP -> P_5 ; * rty_1 = (
rtu_DCM_as - rtu_DCM_o ) * rtb_B_6_4_0 * localP -> P_6 ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW ->
MaximumValueatDCM22_SubsysRanBC ) ; } break ; case 1 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { localB
-> B_7_0_0 = localP -> P_7 ; } rtb_B_6_4_0 = ( ( rtu_DCM_k - rtu_DCM ) -
rtu_DCM_b ) + localB -> B_7_0_0 ; if ( ssIsMajorTimeStep ( S ) ) { if (
localDW -> sqrt_DWORK1_p != 0 ) { ssSetSolverNeedsReset ( S ) ; localDW ->
sqrt_DWORK1_p = 0 ; } localB -> B_7_2_0 = muDoubleScalarSqrt ( rtb_B_6_4_0 )
; } else { if ( rtb_B_6_4_0 < 0.0 ) { localB -> B_7_2_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_6_4_0 ) ) ; } else { localB ->
B_7_2_0 = muDoubleScalarSqrt ( rtb_B_6_4_0 ) ; } localDW -> sqrt_DWORK1_p = 1
; } * rty_4 = localP -> P_8 * localB -> B_7_2_0 ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { localB -> B_7_7_0 = localP -> P_9 ; localB -> B_7_8_0 [ 0 ] =
localP -> P_10 [ 0 ] ; localB -> B_7_8_0 [ 1 ] = localP -> P_10 [ 1 ] ; } if
( ssIsMajorTimeStep ( S ) ) { localDW -> Switch_Mode_k = ( localB -> B_7_2_0
!= 0.0 ) ; } if ( localDW -> Switch_Mode_k ) { rtb_B_6_4_0 = localB ->
B_7_7_0 ; } else { rtb_B_6_4_0 = localB -> B_7_8_0 [ 0 ] ; } if ( localDW ->
Switch_Mode_k ) { tmp = localB -> B_7_2_0 ; } else { tmp = localB -> B_7_8_0
[ 1 ] ; } rtb_B_6_4_0 /= tmp ; * rty_2 = ( rtu_DCM_as + rtu_DCM_o ) *
rtb_B_6_4_0 * localP -> P_11 ; * rty_3 = ( rtu_DCM_ky + rtu_DCM_n ) *
rtb_B_6_4_0 * localP -> P_12 ; * rty_1 = ( rtu_DCM_a - rtu_DCM_k3 ) *
rtb_B_6_4_0 * localP -> P_13 ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC (
localDW -> MaximumValueatDCM33_SubsysRanBC ) ; } break ; case 2 : if (
rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S
) ) { ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
localB -> B_8_0_0 = localP -> P_14 ; } rtb_B_6_4_0 = ( ( rtu_DCM - rtu_DCM_b
) - rtu_DCM_k ) + localB -> B_8_0_0 ; if ( ssIsMajorTimeStep ( S ) ) { if (
localDW -> sqrt_DWORK1 != 0 ) { ssSetSolverNeedsReset ( S ) ; localDW ->
sqrt_DWORK1 = 0 ; } localB -> B_8_2_0 = muDoubleScalarSqrt ( rtb_B_6_4_0 ) ;
} else { if ( rtb_B_6_4_0 < 0.0 ) { localB -> B_8_2_0 = - muDoubleScalarSqrt
( muDoubleScalarAbs ( rtb_B_6_4_0 ) ) ; } else { localB -> B_8_2_0 =
muDoubleScalarSqrt ( rtb_B_6_4_0 ) ; } localDW -> sqrt_DWORK1 = 1 ; } * rty_2
= localP -> P_15 * localB -> B_8_2_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
localB -> B_8_4_0 = localP -> P_16 ; localB -> B_8_5_0 [ 0 ] = localP -> P_17
[ 0 ] ; localB -> B_8_5_0 [ 1 ] = localP -> P_17 [ 1 ] ; } if (
ssIsMajorTimeStep ( S ) ) { localDW -> Switch_Mode = ( localB -> B_8_2_0 !=
0.0 ) ; } if ( localDW -> Switch_Mode ) { rtb_B_6_4_0 = localB -> B_8_4_0 ; }
else { rtb_B_6_4_0 = localB -> B_8_5_0 [ 0 ] ; } if ( localDW -> Switch_Mode
) { tmp = localB -> B_8_2_0 ; } else { tmp = localB -> B_8_5_0 [ 1 ] ; }
rtb_B_6_4_0 /= tmp ; * rty_3 = ( rtu_DCM_k3 + rtu_DCM_a ) * rtb_B_6_4_0 *
localP -> P_18 ; * rty_4 = ( rtu_DCM_as + rtu_DCM_o ) * rtb_B_6_4_0 * localP
-> P_19 ; * rty_1 = ( rtu_DCM_n - rtu_DCM_ky ) * rtb_B_6_4_0 * localP -> P_20
; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW ->
MaximumValueatDCM11_SubsysRanBC ) ; } break ; } } void
ACStesbed1_NegativeTrace_Term ( SimStruct * const S ) { } real_T
rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T lo ; uint32_T hi ; lo
= * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi ) { * u
= 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return ( real_T ) *
u * 4.6566128752457969E-10 ; } real_T rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T *
u ) { real_T y ; real_T sr ; real_T si ; do { sr = 2.0 *
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
} } void rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( const real_T u0 [ 9 ] , const
real_T u1 [ 3 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; int32_T r ; int32_T r_0
; int32_T r_1 ; real_T maxval ; real_T a ; int32_T rtemp ; memcpy ( & A [ 0 ]
, & u0 [ 0 ] , 9U * sizeof ( real_T ) ) ; r = 1 ; r_0 = 2 ; r_1 = 3 ; maxval
= muDoubleScalarAbs ( u0 [ 0 ] ) ; a = muDoubleScalarAbs ( u0 [ 1 ] ) ; if (
a > maxval ) { maxval = a ; r = 2 ; r_0 = 1 ; } if ( muDoubleScalarAbs ( u0 [
2 ] ) > maxval ) { r = 3 ; r_0 = 2 ; r_1 = 1 ; } A [ r_0 - 1 ] = u0 [ r_0 - 1
] / u0 [ r - 1 ] ; A [ r_1 - 1 ] /= A [ r - 1 ] ; A [ r_0 + 2 ] -= A [ r_0 -
1 ] * A [ r + 2 ] ; A [ r_1 + 2 ] -= A [ r_1 - 1 ] * A [ r + 2 ] ; A [ r_0 +
5 ] -= A [ r_0 - 1 ] * A [ r + 5 ] ; A [ r_1 + 5 ] -= A [ r_1 - 1 ] * A [ r +
5 ] ; if ( muDoubleScalarAbs ( A [ r_1 + 2 ] ) > muDoubleScalarAbs ( A [ r_0
+ 2 ] ) ) { rtemp = r_0 ; r_0 = r_1 ; r_1 = rtemp ; } A [ r_1 + 2 ] /= A [
r_0 + 2 ] ; A [ r_1 + 5 ] -= A [ r_1 + 2 ] * A [ r_0 + 5 ] ; maxval = u1 [
r_0 - 1 ] - u1 [ r - 1 ] * A [ r_0 - 1 ] ; a = ( ( u1 [ r_1 - 1 ] - u1 [ r -
1 ] * A [ r_1 - 1 ] ) - A [ r_1 + 2 ] * maxval ) / A [ r_1 + 5 ] ; maxval -=
A [ r_0 + 5 ] * a ; maxval /= A [ r_0 + 2 ] ; y [ 0 ] = ( ( u1 [ r - 1 ] - A
[ r + 5 ] * a ) - A [ r + 2 ] * maxval ) / A [ r - 1 ] ; y [ 1 ] = maxval ; y
[ 2 ] = a ; } static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T
B_20_405_0 [ 3 ] ; real_T B_20_622_0 [ 4 ] ; int32_T k ; int32_T idxB ;
int32_T idxout ; real_T y [ 3 ] ; real_T y_0 [ 9 ] ; real_T rtb_B_20_1129_0 [
9 ] ; real_T rtb_B_20_57_0 ; real_T rtb_B_20_897_0 ; real_T rtb_B_20_755_0 ;
real_T rtb_B_20_892_0 ; real_T rtb_B_20_21_0 [ 6 ] ; real_T rtb_B_20_574_0 [
9 ] ; real_T rtb_B_20_37_0 ; int8_T rtPrevAction ; int8_T rtAction ; real_T
rtb_B_20_1077_0 ; real_T rtb_B_20_1128_0 [ 3 ] ; real_T rtb_B_20_1060_0 ;
real_T rtb_B_20_1339_0 [ 3 ] ; real_T rtb_B_20_308_0 [ 9 ] ; real_T
rtb_B_20_1281_0 ; real_T rtb_B_20_322_0 [ 9 ] ; real_T rtb_B_20_468_0 ;
real_T rtb_B_20_482_0 [ 9 ] ; real_T rtb_B_20_497_0 [ 9 ] ; real_T
rtb_B_20_505_0 ; real_T rtb_B_20_519_0 [ 9 ] ; real_T rtb_B_20_534_0 [ 9 ] ;
real_T rtb_B_20_542_0 ; real_T rtb_B_20_556_0 [ 9 ] ; real_T rtb_B_20_571_0 [
9 ] ; real_T rtb_B_20_1031_0 [ 9 ] ; real_T rtb_B_20_1045_0 [ 9 ] ; real_T
rtb_B_20_1204_0 [ 9 ] ; real_T rtb_B_20_1219_0 [ 9 ] ; real_T rtb_B_20_1241_0
[ 9 ] ; real_T rtb_B_20_1256_0 [ 9 ] ; real_T rtb_B_20_1278_0 [ 9 ] ; real_T
rtb_B_20_1293_0 [ 9 ] ; real_T rtb_B_20_36_0 [ 9 ] ; real_T rtb_B_20_1301_0 [
9 ] ; real_T rtb_B_20_503_0 [ 9 ] ; real_T rtb_B_20_540_0 [ 9 ] ; real_T
rtb_B_20_1175_0 [ 9 ] ; int32_T i ; int32_T i_0 ; real_T tmp [ 6 ] ; real_T
y_1 [ 6 ] ; real_T tmp_0 [ 6 ] ; real_T y_2 [ 6 ] ; real_T B_20_43_0_idx ;
real_T B_20_43_0_idx_0 ; real_T B_20_43_0_idx_1 ; real_T B_20_43_0_idx_2 ;
real_T B_20_7_0_idx ; real_T B_20_7_0_idx_0 ; real_T B_20_7_0_idx_1 ; real_T
B_20_7_3_idx ; real_T B_20_7_3_idx_0 ; real_T B_20_7_3_idx_1 ; B_ACStesbed1_T
* _rtB ; P_ACStesbed1_T * _rtP ; DW_ACStesbed1_T * _rtDW ; _rtDW = ( (
DW_ACStesbed1_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_ACStesbed1_T * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_ACStesbed1_T * ) _ssGetBlockIO ( S )
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_0_0 = _rtP -> P_24 ; }
rtb_B_20_1129_0 [ 0 ] = _rtB -> B_20_0_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> B_20_2_0 [ 0 ] = _rtP -> P_25 [ 0 ] ; _rtB -> B_20_2_0 [ 1 ] = _rtP
-> P_25 [ 1 ] ; _rtB -> B_20_2_0 [ 2 ] = _rtP -> P_25 [ 2 ] ; _rtB ->
B_20_3_0 = _rtP -> P_26 ; rtb_B_20_57_0 = _rtP -> P_27 ; rtb_B_20_897_0 =
_rtP -> P_28 ; } ssCallAccelRunBlock ( S , 20 , 6 , SS_CALL_MDL_OUTPUTS ) ;
B_20_7_0_idx = _rtB -> B_20_835_0 . j2000 [ 0 ] ; B_20_7_0_idx_0 = _rtB ->
B_20_835_0 . j2000 [ 1 ] ; B_20_7_0_idx_1 = _rtB -> B_20_835_0 . j2000 [ 2 ]
; B_20_7_3_idx = _rtB -> B_20_835_0 . rsun [ 0 ] ; B_20_7_3_idx_0 = _rtB ->
B_20_835_0 . rsun [ 1 ] ; B_20_7_3_idx_1 = _rtB -> B_20_835_0 . rsun [ 2 ] ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_8_0 [ 0 ] = _rtP -> P_29 [
0 ] ; _rtB -> B_20_8_0 [ 1 ] = _rtP -> P_29 [ 1 ] ; _rtB -> B_20_8_0 [ 2 ] =
_rtP -> P_29 [ 2 ] ; } _rtB -> B_20_9_0 [ 0 ] = _rtB -> B_20_835_0 . j2000 [
0 ] + _rtB -> B_20_8_0 [ 0 ] ; _rtB -> B_20_9_0 [ 1 ] = _rtB -> B_20_835_0 .
j2000 [ 1 ] + _rtB -> B_20_8_0 [ 1 ] ; _rtB -> B_20_9_0 [ 2 ] = _rtB ->
B_20_835_0 . j2000 [ 2 ] + _rtB -> B_20_8_0 [ 2 ] ; if ( ssIsSampleHit ( S ,
4 , 0 ) ) { _rtB -> B_20_10_0 [ 0 ] = _rtB -> B_20_9_0 [ 0 ] ; _rtB ->
B_20_10_0 [ 1 ] = _rtB -> B_20_9_0 [ 1 ] ; _rtB -> B_20_10_0 [ 2 ] = _rtB ->
B_20_9_0 [ 2 ] ; rtb_B_20_755_0 = ( _rtB -> B_20_10_0 [ 0 ] * _rtB ->
B_20_10_0 [ 0 ] + _rtB -> B_20_10_0 [ 1 ] * _rtB -> B_20_10_0 [ 1 ] ) + _rtB
-> B_20_10_0 [ 2 ] * _rtB -> B_20_10_0 [ 2 ] ; if ( rtb_B_20_755_0 < 0.0 ) {
_rtB -> B_20_13_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_755_0
) ) ; } else { _rtB -> B_20_13_0 = muDoubleScalarSqrt ( rtb_B_20_755_0 ) ; }
_rtB -> B_20_14_0 [ 0 ] = _rtB -> B_20_10_0 [ 0 ] * 0.0 ; _rtB -> B_20_14_0 [
1 ] = _rtB -> B_20_10_0 [ 1 ] * 0.0 ; _rtB -> B_20_14_0 [ 2 ] = _rtB ->
B_20_10_0 [ 2 ] * 0.0 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_20_892_0
= _rtP -> P_30 ; if ( _rtB -> B_20_13_0 > _rtP -> P_31 ) { B_20_43_0_idx =
_rtB -> B_20_10_0 [ 0 ] ; B_20_43_0_idx_1 = _rtB -> B_20_10_0 [ 1 ] ;
B_20_43_0_idx_2 = _rtB -> B_20_10_0 [ 2 ] ; } else { B_20_43_0_idx = _rtB ->
B_20_14_0 [ 0 ] ; B_20_43_0_idx_1 = _rtB -> B_20_14_0 [ 1 ] ; B_20_43_0_idx_2
= _rtB -> B_20_14_0 [ 2 ] ; } if ( _rtB -> B_20_13_0 > _rtP -> P_31 ) {
B_20_43_0_idx_0 = _rtB -> B_20_13_0 ; } else { B_20_43_0_idx_0 = _rtP -> P_30
; } _rtB -> B_20_722_0 [ 0 ] = B_20_43_0_idx / B_20_43_0_idx_0 ; _rtB ->
B_20_722_0 [ 1 ] = B_20_43_0_idx_1 / B_20_43_0_idx_0 ; _rtB -> B_20_722_0 [ 2
] = B_20_43_0_idx_2 / B_20_43_0_idx_0 ; _rtB -> B_20_18_0 [ 0 ] = _rtP ->
P_32 [ 0 ] ; _rtB -> B_20_18_0 [ 1 ] = _rtP -> P_32 [ 1 ] ; _rtB -> B_20_18_0
[ 2 ] = _rtP -> P_32 [ 2 ] ; } _rtB -> B_20_19_0 [ 0 ] = _rtB -> B_20_835_0 .
vj2000 [ 0 ] + _rtB -> B_20_18_0 [ 0 ] ; _rtB -> B_20_19_0 [ 1 ] = _rtB ->
B_20_835_0 . vj2000 [ 1 ] + _rtB -> B_20_18_0 [ 1 ] ; _rtB -> B_20_19_0 [ 2 ]
= _rtB -> B_20_835_0 . vj2000 [ 2 ] + _rtB -> B_20_18_0 [ 2 ] ; if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_20_22_0 [ 0 ] = _rtB -> B_20_19_0 [
1 ] * _rtB -> B_20_10_0 [ 2 ] - _rtB -> B_20_19_0 [ 2 ] * _rtB -> B_20_10_0 [
1 ] ; _rtB -> B_20_22_0 [ 1 ] = _rtB -> B_20_19_0 [ 2 ] * _rtB -> B_20_10_0 [
0 ] - _rtB -> B_20_19_0 [ 0 ] * _rtB -> B_20_10_0 [ 2 ] ; _rtB -> B_20_22_0 [
2 ] = _rtB -> B_20_19_0 [ 0 ] * _rtB -> B_20_10_0 [ 1 ] - _rtB -> B_20_19_0 [
1 ] * _rtB -> B_20_10_0 [ 0 ] ; rtb_B_20_755_0 = ( _rtB -> B_20_22_0 [ 0 ] *
_rtB -> B_20_22_0 [ 0 ] + _rtB -> B_20_22_0 [ 1 ] * _rtB -> B_20_22_0 [ 1 ] )
+ _rtB -> B_20_22_0 [ 2 ] * _rtB -> B_20_22_0 [ 2 ] ; if ( rtb_B_20_755_0 <
0.0 ) { _rtB -> B_20_25_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
rtb_B_20_755_0 ) ) ; } else { _rtB -> B_20_25_0 = muDoubleScalarSqrt (
rtb_B_20_755_0 ) ; } _rtB -> B_20_26_0 [ 0 ] = _rtB -> B_20_22_0 [ 0 ] * 0.0
; _rtB -> B_20_26_0 [ 1 ] = _rtB -> B_20_22_0 [ 1 ] * 0.0 ; _rtB -> B_20_26_0
[ 2 ] = _rtB -> B_20_22_0 [ 2 ] * 0.0 ; } if ( ssIsSampleHit ( S , 1 , 0 ) )
{ if ( _rtB -> B_20_25_0 > _rtP -> P_34 ) { B_20_43_0_idx = _rtB -> B_20_22_0
[ 0 ] ; B_20_43_0_idx_1 = _rtB -> B_20_22_0 [ 1 ] ; B_20_43_0_idx_2 = _rtB ->
B_20_22_0 [ 2 ] ; } else { B_20_43_0_idx = _rtB -> B_20_26_0 [ 0 ] ;
B_20_43_0_idx_1 = _rtB -> B_20_26_0 [ 1 ] ; B_20_43_0_idx_2 = _rtB ->
B_20_26_0 [ 2 ] ; } if ( _rtB -> B_20_25_0 > _rtP -> P_34 ) { B_20_43_0_idx_0
= _rtB -> B_20_25_0 ; } else { B_20_43_0_idx_0 = _rtP -> P_33 ; } _rtB ->
B_20_719_0 [ 0 ] = B_20_43_0_idx / B_20_43_0_idx_0 ; _rtB -> B_20_719_0 [ 1 ]
= B_20_43_0_idx_1 / B_20_43_0_idx_0 ; _rtB -> B_20_719_0 [ 2 ] =
B_20_43_0_idx_2 / B_20_43_0_idx_0 ; _rtB -> B_20_830_0 [ 0 ] = _rtB ->
B_20_722_0 [ 1 ] * _rtB -> B_20_719_0 [ 2 ] - _rtB -> B_20_722_0 [ 2 ] * _rtB
-> B_20_719_0 [ 1 ] ; _rtB -> B_20_830_0 [ 1 ] = _rtB -> B_20_722_0 [ 2 ] *
_rtB -> B_20_719_0 [ 0 ] - _rtB -> B_20_722_0 [ 0 ] * _rtB -> B_20_719_0 [ 2
] ; _rtB -> B_20_830_0 [ 2 ] = _rtB -> B_20_722_0 [ 0 ] * _rtB -> B_20_719_0
[ 1 ] - _rtB -> B_20_722_0 [ 1 ] * _rtB -> B_20_719_0 [ 0 ] ; rtb_B_20_574_0
[ 0 ] = _rtB -> B_20_830_0 [ 0 ] ; rtb_B_20_574_0 [ 1 ] = _rtB -> B_20_830_0
[ 1 ] ; rtb_B_20_574_0 [ 2 ] = _rtB -> B_20_830_0 [ 2 ] ; rtb_B_20_574_0 [ 3
] = _rtB -> B_20_722_0 [ 0 ] ; rtb_B_20_574_0 [ 4 ] = _rtB -> B_20_722_0 [ 1
] ; rtb_B_20_574_0 [ 5 ] = _rtB -> B_20_722_0 [ 2 ] ; rtb_B_20_574_0 [ 6 ] =
_rtB -> B_20_719_0 [ 0 ] ; rtb_B_20_574_0 [ 7 ] = _rtB -> B_20_719_0 [ 1 ] ;
rtb_B_20_574_0 [ 8 ] = _rtB -> B_20_719_0 [ 2 ] ; for ( i_0 = 0 ; i_0 < 3 ;
i_0 ++ ) { rtb_B_20_36_0 [ 3 * i_0 ] = rtb_B_20_574_0 [ i_0 ] ; rtb_B_20_36_0
[ 1 + 3 * i_0 ] = rtb_B_20_574_0 [ i_0 + 3 ] ; rtb_B_20_36_0 [ 2 + 3 * i_0 ]
= rtb_B_20_574_0 [ i_0 + 6 ] ; } rtb_B_20_37_0 = ( rtb_B_20_36_0 [ 0 ] +
rtb_B_20_36_0 [ 4 ] ) + rtb_B_20_36_0 [ 8 ] ; rtPrevAction = _rtDW ->
If_ActiveSubsystem ; if ( ssIsMajorTimeStep ( S ) ) { if ( rtb_B_20_37_0 >
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
rtb_B_20_37_0 += _rtP -> P_0 ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW ->
sqrt_DWORK1_f != 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_f =
0 ; } rtb_B_20_37_0 = muDoubleScalarSqrt ( rtb_B_20_37_0 ) ; } else { if (
rtb_B_20_37_0 < 0.0 ) { rtb_B_20_37_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_20_37_0 ) ) ; } else { rtb_B_20_37_0 =
muDoubleScalarSqrt ( rtb_B_20_37_0 ) ; } _rtDW -> sqrt_DWORK1_f = 1 ; } _rtB
-> B_20_41_0 [ 0 ] = _rtP -> P_1 * rtb_B_20_37_0 ; rtb_B_20_37_0 *= _rtP ->
P_2 ; _rtB -> B_20_41_0 [ 1 ] = ( rtb_B_20_36_0 [ 7 ] - rtb_B_20_36_0 [ 5 ] )
/ rtb_B_20_37_0 ; _rtB -> B_20_41_0 [ 2 ] = ( rtb_B_20_36_0 [ 2 ] -
rtb_B_20_36_0 [ 6 ] ) / rtb_B_20_37_0 ; _rtB -> B_20_41_0 [ 3 ] = (
rtb_B_20_36_0 [ 3 ] - rtb_B_20_36_0 [ 1 ] ) / rtb_B_20_37_0 ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> PositiveTrace_SubsysRanBC )
; } break ; case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S
, 1 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } } rtPrevAction
= _rtDW -> FindMaximumDiagonalValue_ActiveSubsystem ; if ( ( rtb_B_20_36_0 [
4 ] > rtb_B_20_36_0 [ 0 ] ) && ( rtb_B_20_36_0 [ 4 ] > rtb_B_20_36_0 [ 8 ] )
) { rtAction = 0 ; } else if ( rtb_B_20_36_0 [ 8 ] > rtb_B_20_36_0 [ 0 ] ) {
rtAction = 1 ; } else { rtAction = 2 ; } _rtDW ->
FindMaximumDiagonalValue_ActiveSubsystem = rtAction ; if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : ssSetSolverNeedsReset ( S ) ;
break ; case 1 : ssSetSolverNeedsReset ( S ) ; break ; case 2 :
ssSetSolverNeedsReset ( S ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S
) ) { ssSetSolverNeedsReset ( S ) ; } } rtb_B_20_755_0 = ( ( rtb_B_20_36_0 [
4 ] - rtb_B_20_36_0 [ 0 ] ) - rtb_B_20_36_0 [ 8 ] ) + _rtP -> P_3 ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_i != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_i = 0 ; } rtb_B_20_755_0 =
muDoubleScalarSqrt ( rtb_B_20_755_0 ) ; } else { if ( rtb_B_20_755_0 < 0.0 )
{ rtb_B_20_755_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_755_0
) ) ; } else { rtb_B_20_755_0 = muDoubleScalarSqrt ( rtb_B_20_755_0 ) ; }
_rtDW -> sqrt_DWORK1_i = 1 ; } _rtB -> B_20_41_0 [ 2 ] = _rtP -> P_4 *
rtb_B_20_755_0 ; if ( rtb_B_20_755_0 != 0.0 ) { rtb_B_20_892_0 = _rtP -> P_5
; } else { rtb_B_20_892_0 = _rtP -> P_6 [ 0 ] ; rtb_B_20_755_0 = _rtP -> P_6
[ 1 ] ; } rtb_B_20_892_0 /= rtb_B_20_755_0 ; _rtB -> B_20_41_0 [ 1 ] = (
rtb_B_20_36_0 [ 1 ] + rtb_B_20_36_0 [ 3 ] ) * rtb_B_20_892_0 * _rtP -> P_7 ;
_rtB -> B_20_41_0 [ 3 ] = ( rtb_B_20_36_0 [ 5 ] + rtb_B_20_36_0 [ 7 ] ) *
rtb_B_20_892_0 * _rtP -> P_8 ; _rtB -> B_20_41_0 [ 0 ] = ( rtb_B_20_36_0 [ 2
] - rtb_B_20_36_0 [ 6 ] ) * rtb_B_20_892_0 * _rtP -> P_9 ; srUpdateBC ( _rtDW
-> MaximumValueatDCM22_SubsysRanBC ) ; break ; case 1 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } rtb_B_20_37_0 = ( ( rtb_B_20_36_0 [ 8 ] -
rtb_B_20_36_0 [ 0 ] ) - rtb_B_20_36_0 [ 4 ] ) + _rtP -> P_10 ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_a != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_a = 0 ; } rtb_B_20_37_0 =
muDoubleScalarSqrt ( rtb_B_20_37_0 ) ; } else { if ( rtb_B_20_37_0 < 0.0 ) {
rtb_B_20_37_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_37_0 ) )
; } else { rtb_B_20_37_0 = muDoubleScalarSqrt ( rtb_B_20_37_0 ) ; } _rtDW ->
sqrt_DWORK1_a = 1 ; } _rtB -> B_20_41_0 [ 3 ] = _rtP -> P_11 * rtb_B_20_37_0
; if ( rtb_B_20_37_0 != 0.0 ) { rtb_B_20_892_0 = _rtP -> P_12 ;
rtb_B_20_755_0 = rtb_B_20_37_0 ; } else { rtb_B_20_892_0 = _rtP -> P_13 [ 0 ]
; rtb_B_20_755_0 = _rtP -> P_13 [ 1 ] ; } rtb_B_20_37_0 = rtb_B_20_892_0 /
rtb_B_20_755_0 ; _rtB -> B_20_41_0 [ 1 ] = ( rtb_B_20_36_0 [ 2 ] +
rtb_B_20_36_0 [ 6 ] ) * rtb_B_20_37_0 * _rtP -> P_14 ; _rtB -> B_20_41_0 [ 2
] = ( rtb_B_20_36_0 [ 5 ] + rtb_B_20_36_0 [ 7 ] ) * rtb_B_20_37_0 * _rtP ->
P_15 ; _rtB -> B_20_41_0 [ 0 ] = ( rtb_B_20_36_0 [ 3 ] - rtb_B_20_36_0 [ 1 ]
) * rtb_B_20_37_0 * _rtP -> P_16 ; srUpdateBC ( _rtDW ->
MaximumValueatDCM33_SubsysRanBC ) ; break ; case 2 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } rtb_B_20_37_0 = ( ( rtb_B_20_36_0 [ 0 ] -
rtb_B_20_36_0 [ 4 ] ) - rtb_B_20_36_0 [ 8 ] ) + _rtP -> P_17 ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_da != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_da = 0 ; } rtb_B_20_37_0 =
muDoubleScalarSqrt ( rtb_B_20_37_0 ) ; } else { if ( rtb_B_20_37_0 < 0.0 ) {
rtb_B_20_37_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_37_0 ) )
; } else { rtb_B_20_37_0 = muDoubleScalarSqrt ( rtb_B_20_37_0 ) ; } _rtDW ->
sqrt_DWORK1_da = 1 ; } _rtB -> B_20_41_0 [ 1 ] = _rtP -> P_18 * rtb_B_20_37_0
; if ( rtb_B_20_37_0 != 0.0 ) { rtb_B_20_892_0 = _rtP -> P_19 ;
rtb_B_20_755_0 = rtb_B_20_37_0 ; } else { rtb_B_20_892_0 = _rtP -> P_20 [ 0 ]
; rtb_B_20_755_0 = _rtP -> P_20 [ 1 ] ; } rtb_B_20_37_0 = rtb_B_20_892_0 /
rtb_B_20_755_0 ; _rtB -> B_20_41_0 [ 2 ] = ( rtb_B_20_36_0 [ 1 ] +
rtb_B_20_36_0 [ 3 ] ) * rtb_B_20_37_0 * _rtP -> P_21 ; _rtB -> B_20_41_0 [ 3
] = ( rtb_B_20_36_0 [ 2 ] + rtb_B_20_36_0 [ 6 ] ) * rtb_B_20_37_0 * _rtP ->
P_22 ; _rtB -> B_20_41_0 [ 0 ] = ( rtb_B_20_36_0 [ 7 ] - rtb_B_20_36_0 [ 5 ]
) * rtb_B_20_37_0 * _rtP -> P_23 ; srUpdateBC ( _rtDW ->
MaximumValueatDCM11_SubsysRanBC ) ; break ; } if ( ssIsMajorTimeStep ( S ) )
{ srUpdateBC ( _rtDW -> NegativeTrace_SubsysRanBC ) ; } break ; } if ( ! (
_rtB -> B_20_41_0 [ 0 ] >= _rtP -> P_36 ) ) { rtb_B_20_57_0 = rtb_B_20_897_0
; } B_20_43_0_idx = rtb_B_20_57_0 * _rtB -> B_20_41_0 [ 0 ] ; B_20_43_0_idx_1
= rtb_B_20_57_0 * _rtB -> B_20_41_0 [ 1 ] ; B_20_43_0_idx_2 = rtb_B_20_57_0 *
_rtB -> B_20_41_0 [ 2 ] ; B_20_43_0_idx_0 = rtb_B_20_57_0 * _rtB -> B_20_41_0
[ 3 ] ; rtb_B_20_892_0 = ( ( B_20_43_0_idx * B_20_43_0_idx + B_20_43_0_idx_1
* B_20_43_0_idx_1 ) + B_20_43_0_idx_2 * B_20_43_0_idx_2 ) + B_20_43_0_idx_0 *
B_20_43_0_idx_0 ; _rtB -> B_20_49_0 = B_20_43_0_idx / rtb_B_20_892_0 ;
rtb_B_20_57_0 = ( ( _rtP -> P_38 [ 0 ] * _rtP -> P_39 [ 0 ] - _rtP -> P_38 [
1 ] * _rtP -> P_39 [ 1 ] ) - _rtP -> P_38 [ 2 ] * _rtP -> P_39 [ 2 ] ) - _rtP
-> P_38 [ 3 ] * _rtP -> P_39 [ 3 ] ; if ( rtb_B_20_57_0 >= _rtP -> P_41 ) {
rtb_B_20_897_0 = _rtP -> P_37 ; } else { rtb_B_20_897_0 = _rtP -> P_40 ; }
rtb_B_20_1281_0 = ( ( _rtP -> P_38 [ 0 ] * _rtP -> P_39 [ 3 ] + _rtP -> P_38
[ 1 ] * _rtP -> P_39 [ 2 ] ) - _rtP -> P_38 [ 2 ] * _rtP -> P_39 [ 1 ] ) +
_rtP -> P_38 [ 3 ] * _rtP -> P_39 [ 0 ] ; _rtB -> B_20_75_0 [ 0 ] =
rtb_B_20_897_0 * rtb_B_20_57_0 ; _rtB -> B_20_75_0 [ 1 ] = ( ( ( _rtP -> P_38
[ 0 ] * _rtP -> P_39 [ 1 ] + _rtP -> P_38 [ 1 ] * _rtP -> P_39 [ 0 ] ) + _rtP
-> P_38 [ 2 ] * _rtP -> P_39 [ 3 ] ) - _rtP -> P_38 [ 3 ] * _rtP -> P_39 [ 2
] ) * rtb_B_20_897_0 ; _rtB -> B_20_75_0 [ 2 ] = ( ( ( _rtP -> P_38 [ 0 ] *
_rtP -> P_39 [ 2 ] - _rtP -> P_38 [ 1 ] * _rtP -> P_39 [ 3 ] ) + _rtP -> P_38
[ 2 ] * _rtP -> P_39 [ 0 ] ) + _rtP -> P_38 [ 3 ] * _rtP -> P_39 [ 1 ] ) *
rtb_B_20_897_0 ; _rtB -> B_20_75_0 [ 3 ] = rtb_B_20_897_0 * rtb_B_20_1281_0 ;
} if ( _rtDW -> q0q1q2q3_IWORK . IcNeedsLoading ) { ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 0 ] = _rtB -> B_20_75_0 [ 0 ] ;
( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 1 ] =
_rtB -> B_20_75_0 [ 1 ] ; ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE [ 2 ] = _rtB -> B_20_75_0 [ 2 ] ; ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 3 ] = _rtB -> B_20_75_0 [ 3 ] ;
} _rtB -> B_20_76_0 [ 0 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE [ 0 ] ; _rtB -> B_20_76_0 [ 1 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 1 ] ; _rtB -> B_20_76_0 [ 2 ] =
( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE [ 2 ] ;
_rtB -> B_20_76_0 [ 3 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE [ 3 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_79_0 = - B_20_43_0_idx_1 / rtb_B_20_892_0 ; _rtB -> B_20_82_0 = -
B_20_43_0_idx_2 / rtb_B_20_892_0 ; _rtB -> B_20_85_0 = - B_20_43_0_idx_0 /
rtb_B_20_892_0 ; } _rtB -> B_20_87_0 = ( ( _rtB -> B_20_49_0 * _rtB ->
B_20_76_0 [ 0 ] - _rtB -> B_20_79_0 * _rtB -> B_20_76_0 [ 1 ] ) - _rtB ->
B_20_82_0 * _rtB -> B_20_76_0 [ 2 ] ) - _rtB -> B_20_85_0 * _rtB -> B_20_76_0
[ 3 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_88_0 = _rtP -> P_42
; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> Switch_Mode = ( _rtB ->
B_20_87_0 >= _rtP -> P_43 ) ; } if ( _rtDW -> Switch_Mode ) { rtb_B_20_37_0 =
_rtB -> B_20_3_0 ; } else { rtb_B_20_37_0 = _rtB -> B_20_88_0 ; } _rtB ->
B_20_928_0 [ 0 ] = rtb_B_20_37_0 * _rtB -> B_20_87_0 ; _rtB -> B_20_928_0 [ 1
] = ( ( ( _rtB -> B_20_49_0 * _rtB -> B_20_76_0 [ 1 ] + _rtB -> B_20_79_0 *
_rtB -> B_20_76_0 [ 0 ] ) + _rtB -> B_20_82_0 * _rtB -> B_20_76_0 [ 3 ] ) -
_rtB -> B_20_85_0 * _rtB -> B_20_76_0 [ 2 ] ) * rtb_B_20_37_0 ; _rtB ->
B_20_928_0 [ 2 ] = ( ( ( _rtB -> B_20_49_0 * _rtB -> B_20_76_0 [ 2 ] - _rtB
-> B_20_79_0 * _rtB -> B_20_76_0 [ 3 ] ) + _rtB -> B_20_82_0 * _rtB ->
B_20_76_0 [ 0 ] ) + _rtB -> B_20_85_0 * _rtB -> B_20_76_0 [ 1 ] ) *
rtb_B_20_37_0 ; _rtB -> B_20_928_0 [ 3 ] = ( ( ( _rtB -> B_20_49_0 * _rtB ->
B_20_76_0 [ 3 ] + _rtB -> B_20_79_0 * _rtB -> B_20_76_0 [ 2 ] ) - _rtB ->
B_20_82_0 * _rtB -> B_20_76_0 [ 1 ] ) + _rtB -> B_20_85_0 * _rtB -> B_20_76_0
[ 0 ] ) * rtb_B_20_37_0 ; rtb_B_20_57_0 = ( ( _rtB -> B_20_928_0 [ 0 ] * _rtB
-> B_20_928_0 [ 0 ] + _rtB -> B_20_928_0 [ 1 ] * _rtB -> B_20_928_0 [ 1 ] ) +
_rtB -> B_20_928_0 [ 2 ] * _rtB -> B_20_928_0 [ 2 ] ) + _rtB -> B_20_928_0 [
3 ] * _rtB -> B_20_928_0 [ 3 ] ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW
-> sqrt_DWORK1 != 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1 =
0 ; } rtb_B_20_57_0 = muDoubleScalarSqrt ( rtb_B_20_57_0 ) ; } else { if (
rtb_B_20_57_0 < 0.0 ) { rtb_B_20_57_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_20_57_0 ) ) ; } else { rtb_B_20_57_0 =
muDoubleScalarSqrt ( rtb_B_20_57_0 ) ; } _rtDW -> sqrt_DWORK1 = 1 ; }
rtb_B_20_897_0 = _rtB -> B_20_928_0 [ 1 ] / rtb_B_20_57_0 ; rtb_B_20_892_0 =
_rtB -> B_20_928_0 [ 3 ] / rtb_B_20_57_0 ; rtb_B_20_37_0 = _rtB -> B_20_928_0
[ 0 ] / rtb_B_20_57_0 ; rtb_B_20_57_0 = _rtB -> B_20_928_0 [ 2 ] /
rtb_B_20_57_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_128_0 =
_rtP -> P_46 ; } rtb_B_20_1077_0 = ( ( rtb_B_20_897_0 * rtb_B_20_892_0 +
rtb_B_20_37_0 * rtb_B_20_57_0 ) * _rtP -> P_44 * _rtB -> B_20_2_0 [ 0 ] + (
rtb_B_20_57_0 * rtb_B_20_892_0 - rtb_B_20_37_0 * rtb_B_20_897_0 ) * _rtP ->
P_45 * _rtB -> B_20_2_0 [ 1 ] ) + ( ( _rtB -> B_20_128_0 - rtb_B_20_897_0 *
rtb_B_20_897_0 ) - rtb_B_20_57_0 * rtb_B_20_57_0 ) * _rtP -> P_47 * _rtB ->
B_20_2_0 [ 2 ] ; rtb_B_20_1129_0 [ 1 ] = rtb_B_20_1077_0 ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { _rtB -> B_20_136_0 = _rtP -> P_48 ; } rtb_B_20_1060_0 = ( (
( _rtB -> B_20_136_0 - rtb_B_20_57_0 * rtb_B_20_57_0 ) - rtb_B_20_892_0 *
rtb_B_20_892_0 ) * _rtP -> P_49 * _rtB -> B_20_2_0 [ 0 ] + ( rtb_B_20_897_0 *
rtb_B_20_57_0 + rtb_B_20_37_0 * rtb_B_20_892_0 ) * _rtP -> P_50 * _rtB ->
B_20_2_0 [ 1 ] ) + ( rtb_B_20_897_0 * rtb_B_20_892_0 - rtb_B_20_37_0 *
rtb_B_20_57_0 ) * _rtP -> P_51 * _rtB -> B_20_2_0 [ 2 ] ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { _rtB -> B_20_158_0 = _rtP -> P_53 ; } rtb_B_20_57_0 = ( ( (
_rtB -> B_20_158_0 - rtb_B_20_897_0 * rtb_B_20_897_0 ) - rtb_B_20_892_0 *
rtb_B_20_892_0 ) * _rtP -> P_54 * _rtB -> B_20_2_0 [ 1 ] + ( rtb_B_20_897_0 *
rtb_B_20_57_0 - rtb_B_20_37_0 * rtb_B_20_892_0 ) * _rtP -> P_52 * _rtB ->
B_20_2_0 [ 0 ] ) + ( rtb_B_20_37_0 * rtb_B_20_897_0 + rtb_B_20_57_0 *
rtb_B_20_892_0 ) * _rtP -> P_55 * _rtB -> B_20_2_0 [ 2 ] ; rtb_B_20_1128_0 [
0 ] = _rtP -> P_56 * rtb_B_20_1060_0 ; rtb_B_20_1128_0 [ 1 ] = _rtP -> P_56 *
rtb_B_20_57_0 ; rtb_B_20_1128_0 [ 2 ] = _rtP -> P_56 * rtb_B_20_1077_0 ;
rtb_B_20_1129_0 [ 2 ] = rtb_B_20_1128_0 [ 1 ] ; rtb_B_20_1129_0 [ 3 ] =
rtb_B_20_1128_0 [ 2 ] ; rtb_B_20_1129_0 [ 4 ] = _rtB -> B_20_0_0 ;
rtb_B_20_1129_0 [ 5 ] = rtb_B_20_1060_0 ; rtb_B_20_1129_0 [ 6 ] =
rtb_B_20_57_0 ; rtb_B_20_1129_0 [ 7 ] = rtb_B_20_1128_0 [ 0 ] ;
rtb_B_20_1129_0 [ 8 ] = _rtB -> B_20_0_0 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ )
{ rtb_B_20_574_0 [ 3 * i_0 ] = _rtP -> P_57 * rtb_B_20_1129_0 [ i_0 ] ;
rtb_B_20_574_0 [ 1 + 3 * i_0 ] = rtb_B_20_1129_0 [ i_0 + 3 ] * _rtP -> P_57 ;
rtb_B_20_574_0 [ 2 + 3 * i_0 ] = rtb_B_20_1129_0 [ i_0 + 6 ] * _rtP -> P_57 ;
} if ( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i = 0 ; i < 9 ; i ++ ) { _rtB ->
B_20_179_0 [ i ] = _rtP -> P_58 [ i ] ; rtb_B_20_1301_0 [ i ] = _rtP -> P_60
[ i ] ; _rtB -> B_20_182_0 [ i ] = _rtP -> P_59 [ i ] + _rtP -> P_60 [ i ] ;
} _rtB -> B_20_183_0 [ 0 ] = _rtP -> P_61 [ 0 ] ; _rtB -> B_20_183_0 [ 1 ] =
_rtP -> P_61 [ 1 ] ; _rtB -> B_20_183_0 [ 2 ] = _rtP -> P_61 [ 2 ] ; } if (
_rtDW -> Integrator_IWORK . IcNeedsLoading ) { ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> Integrator_CSTATE [ 0 ] = _rtB -> B_20_183_0 [ 0 ]
; ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> Integrator_CSTATE [ 1 ] =
_rtB -> B_20_183_0 [ 1 ] ; ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
Integrator_CSTATE [ 2 ] = _rtB -> B_20_183_0 [ 2 ] ; } _rtB -> B_20_996_0 [ 0
] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> Integrator_CSTATE [ 0 ]
; _rtB -> B_20_996_0 [ 1 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) )
-> Integrator_CSTATE [ 1 ] ; _rtB -> B_20_996_0 [ 2 ] = ( ( X_ACStesbed1_T *
) ssGetContStates ( S ) ) -> Integrator_CSTATE [ 2 ] ; for ( i_0 = 0 ; i_0 <
3 ; i_0 ++ ) { rtb_B_20_1128_0 [ i_0 ] = _rtB -> B_20_182_0 [ i_0 + 6 ] *
_rtB -> B_20_996_0 [ 2 ] + ( _rtB -> B_20_182_0 [ i_0 + 3 ] * _rtB ->
B_20_996_0 [ 1 ] + _rtB -> B_20_182_0 [ i_0 ] * _rtB -> B_20_996_0 [ 0 ] ) ;
} B_20_405_0 [ 0 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
Integrator_CSTATE_n [ 0 ] ; B_20_405_0 [ 1 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> Integrator_CSTATE_n [ 1 ] ; B_20_405_0 [ 2 ] = ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> Integrator_CSTATE_n [ 2 ] ; if
( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_20_189_0 [ 0 ] = _rtP -> P_66 [ 0
] * _rtDW -> NextOutput ; _rtB -> B_20_189_0 [ 1 ] = _rtP -> P_66 [ 1 ] *
_rtDW -> NextOutput ; _rtB -> B_20_189_0 [ 2 ] = _rtP -> P_66 [ 2 ] * _rtDW
-> NextOutput ; } _rtB -> B_20_190_0 [ 0 ] = ( rtb_B_20_1128_0 [ 0 ] +
B_20_405_0 [ 0 ] ) + _rtB -> B_20_189_0 [ 0 ] ; _rtB -> B_20_190_0 [ 1 ] = (
rtb_B_20_1128_0 [ 1 ] + B_20_405_0 [ 1 ] ) + _rtB -> B_20_189_0 [ 1 ] ; _rtB
-> B_20_190_0 [ 2 ] = ( rtb_B_20_1128_0 [ 2 ] + B_20_405_0 [ 2 ] ) + _rtB ->
B_20_189_0 [ 2 ] ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_20_191_0 [
0 ] = _rtB -> B_20_190_0 [ 0 ] ; _rtB -> B_20_191_0 [ 1 ] = _rtB ->
B_20_190_0 [ 1 ] ; _rtB -> B_20_191_0 [ 2 ] = _rtB -> B_20_190_0 [ 2 ] ; } if
( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB
-> B_20_192_0 [ i_0 ] = 0.0 ; _rtB -> B_20_192_0 [ i_0 ] += _rtB ->
B_20_179_0 [ i_0 ] * _rtB -> B_20_191_0 [ 0 ] ; _rtB -> B_20_192_0 [ i_0 ] +=
_rtB -> B_20_179_0 [ i_0 + 3 ] * _rtB -> B_20_191_0 [ 1 ] ; _rtB ->
B_20_192_0 [ i_0 ] += _rtB -> B_20_179_0 [ i_0 + 6 ] * _rtB -> B_20_191_0 [ 2
] ; } } if ( ssIsMajorTimeStep ( S ) ) { if ( ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] >= _rtP -> P_68 ) {
( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [
0 ] = _rtP -> P_68 ; } else if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S )
) -> IntegratorLimited_CSTATE [ 0 ] <= _rtP -> P_69 ) { ( ( X_ACStesbed1_T *
) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] = _rtP -> P_69 ;
} if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 1 ] >= _rtP -> P_68 ) { ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = _rtP -> P_68 ; }
else if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 1 ] <= _rtP -> P_69 ) { ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = _rtP -> P_69 ; }
if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 2 ] >= _rtP -> P_68 ) { ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = _rtP -> P_68 ; }
else if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 2 ] <= _rtP -> P_69 ) { ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = _rtP -> P_69 ; }
} _rtB -> B_20_854_0 [ 0 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) )
-> IntegratorLimited_CSTATE [ 0 ] ; _rtB -> B_20_854_0 [ 1 ] = ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ]
; _rtB -> B_20_854_0 [ 2 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) )
-> IntegratorLimited_CSTATE [ 2 ] ; B_20_405_0 [ 0 ] = _rtP -> P_70 * _rtB ->
B_20_854_0 [ 0 ] ; B_20_405_0 [ 1 ] = _rtP -> P_70 * _rtB -> B_20_854_0 [ 1 ]
; B_20_405_0 [ 2 ] = _rtP -> P_70 * _rtB -> B_20_854_0 [ 2 ] ; if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_20_196_0 [ 0 ] = _rtP -> P_71 [ 0 ]
; _rtB -> B_20_196_0 [ 1 ] = _rtP -> P_71 [ 1 ] ; _rtB -> B_20_196_0 [ 2 ] =
_rtP -> P_71 [ 2 ] ; _rtB -> B_20_197_0 [ 0 ] = _rtDW ->
DiscreteTimeIntegrator_DSTATE [ 0 ] ; _rtB -> B_20_197_0 [ 1 ] = _rtDW ->
DiscreteTimeIntegrator_DSTATE [ 1 ] ; _rtB -> B_20_197_0 [ 2 ] = _rtDW ->
DiscreteTimeIntegrator_DSTATE [ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB -> B_20_198_0 [ i_0 ] = 0.0 ; _rtB
-> B_20_198_0 [ i_0 ] += _rtB -> B_20_179_0 [ i_0 ] * _rtB -> B_20_197_0 [ 0
] ; _rtB -> B_20_198_0 [ i_0 ] += _rtB -> B_20_179_0 [ i_0 + 3 ] * _rtB ->
B_20_197_0 [ 1 ] ; _rtB -> B_20_198_0 [ i_0 ] += _rtB -> B_20_179_0 [ i_0 + 6
] * _rtB -> B_20_197_0 [ 2 ] ; } } if ( ssIsMajorTimeStep ( S ) ) { if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 0
] >= _rtP -> P_74 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 0 ] = _rtP -> P_74 ; } else if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 0
] <= _rtP -> P_75 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 0 ] = _rtP -> P_75 ; } if ( ( ( X_ACStesbed1_T *
) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 1 ] >= _rtP -> P_74
) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 1 ] = _rtP -> P_74 ; } else if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 1
] <= _rtP -> P_75 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 1 ] = _rtP -> P_75 ; } if ( ( ( X_ACStesbed1_T *
) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 2 ] >= _rtP -> P_74
) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 2 ] = _rtP -> P_74 ; } else if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 2
] <= _rtP -> P_75 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 2 ] = _rtP -> P_75 ; } } _rtB -> B_20_199_0 [ 0
] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 0 ] ; _rtB -> B_20_199_0 [ 1 ] = ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 1
] ; _rtB -> B_20_199_0 [ 2 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) )
-> IntegratorLimited_CSTATE_m [ 2 ] ; rtb_B_20_1128_0 [ 0 ] = _rtP -> P_76 *
_rtB -> B_20_199_0 [ 0 ] ; rtb_B_20_1128_0 [ 1 ] = _rtP -> P_76 * _rtB ->
B_20_199_0 [ 1 ] ; rtb_B_20_1128_0 [ 2 ] = _rtP -> P_76 * _rtB -> B_20_199_0
[ 2 ] ; rtb_B_20_892_0 = ( _rtB -> B_20_192_0 [ 0 ] + B_20_405_0 [ 0 ] ) - (
_rtB -> B_20_198_0 [ 0 ] + rtb_B_20_1128_0 [ 0 ] ) ; rtb_B_20_1077_0 = ( _rtB
-> B_20_192_0 [ 1 ] + B_20_405_0 [ 1 ] ) - ( _rtB -> B_20_198_0 [ 1 ] +
rtb_B_20_1128_0 [ 1 ] ) ; rtb_B_20_57_0 = ( _rtB -> B_20_192_0 [ 2 ] +
B_20_405_0 [ 2 ] ) - ( _rtB -> B_20_198_0 [ 2 ] + rtb_B_20_1128_0 [ 2 ] ) ;
for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { rtb_B_20_1339_0 [ i_0 ] = rtb_B_20_574_0
[ i_0 + 6 ] * rtb_B_20_57_0 + ( rtb_B_20_574_0 [ i_0 + 3 ] * rtb_B_20_1077_0
+ rtb_B_20_574_0 [ i_0 ] * rtb_B_20_892_0 ) ; } _rtB -> B_20_1141_0 [ 0 ] =
_rtP -> P_77 * rtb_B_20_1339_0 [ 0 ] ; _rtB -> B_20_1141_0 [ 1 ] = _rtP ->
P_77 * rtb_B_20_1339_0 [ 1 ] ; _rtB -> B_20_1141_0 [ 2 ] = _rtP -> P_77 *
rtb_B_20_1339_0 [ 2 ] ; ssCallAccelRunBlock ( S , 20 , 205 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
B_20_206_0 [ 0 ] = _rtB -> B_20_1141_0 [ 0 ] ; _rtB -> B_20_206_0 [ 1 ] =
_rtB -> B_20_1141_0 [ 1 ] ; _rtB -> B_20_206_0 [ 2 ] = _rtB -> B_20_1141_0 [
2 ] ; ssCallAccelRunBlock ( S , 20 , 207 , SS_CALL_MDL_OUTPUTS ) ; }
rtb_B_20_1339_0 [ 0 ] = _rtB -> B_20_928_0 [ 0 ] * _rtB -> B_20_928_0 [ 1 ] ;
rtb_B_20_1339_0 [ 1 ] = _rtB -> B_20_928_0 [ 0 ] * _rtB -> B_20_928_0 [ 2 ] ;
rtb_B_20_1339_0 [ 2 ] = _rtB -> B_20_928_0 [ 0 ] * _rtB -> B_20_928_0 [ 3 ] ;
for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB -> B_20_209_0 [ i_0 ] = 0.0 ; _rtB
-> B_20_209_0 [ i_0 ] += _rtB -> B_20_179_0 [ i_0 ] * rtb_B_20_1339_0 [ 0 ] ;
_rtB -> B_20_209_0 [ i_0 ] += _rtB -> B_20_179_0 [ i_0 + 3 ] *
rtb_B_20_1339_0 [ 1 ] ; _rtB -> B_20_209_0 [ i_0 ] += _rtB -> B_20_179_0 [
i_0 + 6 ] * rtb_B_20_1339_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) {
_rtB -> B_20_210_0 [ 0 ] = _rtP -> P_78 * _rtB -> B_20_209_0 [ 0 ] ; _rtB ->
B_20_210_0 [ 1 ] = _rtP -> P_78 * _rtB -> B_20_209_0 [ 1 ] ; _rtB ->
B_20_210_0 [ 2 ] = _rtP -> P_78 * _rtB -> B_20_209_0 [ 2 ] ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { rtb_B_20_892_0 = ( muDoubleScalarPower ( _rtB
-> B_20_10_0 [ 0 ] , 2.0 ) + muDoubleScalarPower ( _rtB -> B_20_10_0 [ 1 ] ,
2.0 ) ) + muDoubleScalarPower ( _rtB -> B_20_10_0 [ 2 ] , 2.0 ) ; _rtB ->
B_20_213_0 [ 0 ] = _rtP -> P_79 * _rtB -> B_20_22_0 [ 0 ] / rtb_B_20_892_0 ;
_rtB -> B_20_213_0 [ 1 ] = _rtP -> P_79 * _rtB -> B_20_22_0 [ 1 ] /
rtb_B_20_892_0 ; _rtB -> B_20_213_0 [ 2 ] = _rtP -> P_79 * _rtB -> B_20_22_0
[ 2 ] / rtb_B_20_892_0 ; } rtb_B_20_1060_0 = ( ( _rtB -> B_20_76_0 [ 0 ] *
_rtB -> B_20_76_0 [ 0 ] + _rtB -> B_20_76_0 [ 1 ] * _rtB -> B_20_76_0 [ 1 ] )
+ _rtB -> B_20_76_0 [ 2 ] * _rtB -> B_20_76_0 [ 2 ] ) + _rtB -> B_20_76_0 [ 3
] * _rtB -> B_20_76_0 [ 3 ] ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW ->
sqrt_DWORK1_h != 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_h =
0 ; } rtb_B_20_1060_0 = muDoubleScalarSqrt ( rtb_B_20_1060_0 ) ; } else { if
( rtb_B_20_1060_0 < 0.0 ) { rtb_B_20_1060_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_20_1060_0 ) ) ; } else { rtb_B_20_1060_0 =
muDoubleScalarSqrt ( rtb_B_20_1060_0 ) ; } _rtDW -> sqrt_DWORK1_h = 1 ; }
rtb_B_20_1077_0 = _rtB -> B_20_76_0 [ 2 ] / rtb_B_20_1060_0 ; rtb_B_20_57_0 =
_rtB -> B_20_76_0 [ 3 ] / rtb_B_20_1060_0 ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> B_20_224_0 = _rtP -> P_80 ; } rtb_B_20_897_0 = _rtB -> B_20_76_0
[ 1 ] / rtb_B_20_1060_0 ; rtb_B_20_1060_0 = _rtB -> B_20_76_0 [ 0 ] /
rtb_B_20_1060_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_248_0 =
_rtP -> P_85 ; _rtB -> B_20_270_0 = _rtP -> P_90 ; } _rtB -> B_20_852_0 [ 0 ]
= _rtB -> B_20_191_0 [ 0 ] - ( ( ( ( _rtB -> B_20_224_0 - rtb_B_20_1077_0 *
rtb_B_20_1077_0 ) - rtb_B_20_57_0 * rtb_B_20_57_0 ) * _rtP -> P_81 * _rtB ->
B_20_213_0 [ 0 ] + ( rtb_B_20_897_0 * rtb_B_20_1077_0 + rtb_B_20_1060_0 *
rtb_B_20_57_0 ) * _rtP -> P_82 * _rtB -> B_20_213_0 [ 1 ] ) + (
rtb_B_20_897_0 * rtb_B_20_57_0 - rtb_B_20_1060_0 * rtb_B_20_1077_0 ) * _rtP
-> P_83 * _rtB -> B_20_213_0 [ 2 ] ) ; _rtB -> B_20_852_0 [ 1 ] = _rtB ->
B_20_191_0 [ 1 ] - ( ( ( ( _rtB -> B_20_248_0 - rtb_B_20_897_0 *
rtb_B_20_897_0 ) - rtb_B_20_57_0 * rtb_B_20_57_0 ) * _rtP -> P_86 * _rtB ->
B_20_213_0 [ 1 ] + ( rtb_B_20_897_0 * rtb_B_20_1077_0 - rtb_B_20_1060_0 *
rtb_B_20_57_0 ) * _rtP -> P_84 * _rtB -> B_20_213_0 [ 0 ] ) + (
rtb_B_20_1060_0 * rtb_B_20_897_0 + rtb_B_20_1077_0 * rtb_B_20_57_0 ) * _rtP
-> P_87 * _rtB -> B_20_213_0 [ 2 ] ) ; _rtB -> B_20_852_0 [ 2 ] = _rtB ->
B_20_191_0 [ 2 ] - ( ( ( rtb_B_20_897_0 * rtb_B_20_57_0 + rtb_B_20_1060_0 *
rtb_B_20_1077_0 ) * _rtP -> P_88 * _rtB -> B_20_213_0 [ 0 ] + (
rtb_B_20_1077_0 * rtb_B_20_57_0 - rtb_B_20_1060_0 * rtb_B_20_897_0 ) * _rtP
-> P_89 * _rtB -> B_20_213_0 [ 1 ] ) + ( ( _rtB -> B_20_270_0 -
rtb_B_20_897_0 * rtb_B_20_897_0 ) - rtb_B_20_1077_0 * rtb_B_20_1077_0 ) *
_rtP -> P_91 * _rtB -> B_20_213_0 [ 2 ] ) ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++
) { rtb_B_20_1339_0 [ i_0 ] = _rtB -> B_20_179_0 [ i_0 + 6 ] * _rtB ->
B_20_852_0 [ 2 ] + ( _rtB -> B_20_179_0 [ i_0 + 3 ] * _rtB -> B_20_852_0 [ 1
] + _rtB -> B_20_179_0 [ i_0 ] * _rtB -> B_20_852_0 [ 0 ] ) ; } _rtB ->
B_20_843_0 [ 0 ] = _rtP -> P_92 * rtb_B_20_1339_0 [ 0 ] + _rtB -> B_20_210_0
[ 0 ] ; _rtB -> B_20_843_0 [ 1 ] = _rtP -> P_92 * rtb_B_20_1339_0 [ 1 ] +
_rtB -> B_20_210_0 [ 1 ] ; _rtB -> B_20_843_0 [ 2 ] = _rtP -> P_92 *
rtb_B_20_1339_0 [ 2 ] + _rtB -> B_20_210_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { y [ i_0 ] = _rtB -> B_20_179_0
[ i_0 + 6 ] * _rtB -> B_20_191_0 [ 2 ] + ( _rtB -> B_20_179_0 [ i_0 + 3 ] *
_rtB -> B_20_191_0 [ 1 ] + _rtB -> B_20_179_0 [ i_0 ] * _rtB -> B_20_191_0 [
0 ] ) ; } tmp [ 0 ] = _rtB -> B_20_191_0 [ 1 ] ; tmp [ 1 ] = _rtB ->
B_20_191_0 [ 2 ] ; tmp [ 2 ] = _rtB -> B_20_191_0 [ 0 ] ; tmp [ 3 ] = _rtB ->
B_20_191_0 [ 2 ] ; tmp [ 4 ] = _rtB -> B_20_191_0 [ 0 ] ; tmp [ 5 ] = _rtB ->
B_20_191_0 [ 1 ] ; y_1 [ 0 ] = y [ 2 ] ; y_1 [ 1 ] = y [ 0 ] ; y_1 [ 2 ] = y
[ 1 ] ; y_1 [ 3 ] = y [ 1 ] ; y_1 [ 4 ] = y [ 2 ] ; y_1 [ 5 ] = y [ 0 ] ; for
( i_0 = 0 ; i_0 < 6 ; i_0 ++ ) { rtb_B_20_21_0 [ i_0 ] = tmp [ i_0 ] * y_1 [
i_0 ] ; } _rtB -> B_20_281_0 [ 0 ] = rtb_B_20_21_0 [ 0 ] - rtb_B_20_21_0 [ 3
] ; _rtB -> B_20_281_0 [ 1 ] = rtb_B_20_21_0 [ 1 ] - rtb_B_20_21_0 [ 4 ] ;
_rtB -> B_20_281_0 [ 2 ] = rtb_B_20_21_0 [ 2 ] - rtb_B_20_21_0 [ 5 ] ; memcpy
( & rtb_B_20_1301_0 [ 0 ] , & _rtP -> P_93 [ 0 ] , 9U * sizeof ( real_T ) ) ;
for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB -> B_20_284_0 [ i_0 ] = 0.0 ; _rtB
-> B_20_284_0 [ i_0 ] += _rtP -> P_93 [ i_0 ] * _rtB -> B_20_191_0 [ 0 ] ;
_rtB -> B_20_284_0 [ i_0 ] += _rtP -> P_93 [ i_0 + 3 ] * _rtB -> B_20_191_0 [
1 ] ; _rtB -> B_20_284_0 [ i_0 ] += _rtP -> P_93 [ i_0 + 6 ] * _rtB ->
B_20_191_0 [ 2 ] ; } _rtB -> B_20_288_0 [ 0 ] = _rtB -> B_20_191_0 [ 1 ] *
_rtP -> P_94 [ 2 ] - _rtB -> B_20_191_0 [ 2 ] * _rtP -> P_94 [ 1 ] ; _rtB ->
B_20_288_0 [ 1 ] = _rtB -> B_20_191_0 [ 2 ] * _rtP -> P_94 [ 0 ] - _rtB ->
B_20_191_0 [ 0 ] * _rtP -> P_94 [ 2 ] ; _rtB -> B_20_288_0 [ 2 ] = _rtB ->
B_20_191_0 [ 0 ] * _rtP -> P_94 [ 1 ] - _rtB -> B_20_191_0 [ 1 ] * _rtP ->
P_94 [ 0 ] ; } _rtB -> B_20_289_0 [ 0 ] = ( ( _rtB -> B_20_843_0 [ 0 ] - _rtB
-> B_20_281_0 [ 0 ] ) - _rtB -> B_20_284_0 [ 0 ] ) - _rtB -> B_20_288_0 [ 0 ]
; _rtB -> B_20_289_0 [ 1 ] = ( ( _rtB -> B_20_843_0 [ 1 ] - _rtB ->
B_20_281_0 [ 1 ] ) - _rtB -> B_20_284_0 [ 1 ] ) - _rtB -> B_20_288_0 [ 1 ] ;
_rtB -> B_20_289_0 [ 2 ] = ( ( _rtB -> B_20_843_0 [ 2 ] - _rtB -> B_20_281_0
[ 2 ] ) - _rtB -> B_20_284_0 [ 2 ] ) - _rtB -> B_20_288_0 [ 2 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> Saturation_MODE [ 0 ] = _rtB ->
B_20_289_0 [ 0 ] >= _rtP -> P_95 ? 1 : _rtB -> B_20_289_0 [ 0 ] > _rtP ->
P_96 ? 0 : - 1 ; _rtDW -> Saturation_MODE [ 1 ] = _rtB -> B_20_289_0 [ 1 ] >=
_rtP -> P_95 ? 1 : _rtB -> B_20_289_0 [ 1 ] > _rtP -> P_96 ? 0 : - 1 ; _rtDW
-> Saturation_MODE [ 2 ] = _rtB -> B_20_289_0 [ 2 ] >= _rtP -> P_95 ? 1 :
_rtB -> B_20_289_0 [ 2 ] > _rtP -> P_96 ? 0 : - 1 ; } rtb_B_20_1339_0 [ 0 ] =
_rtDW -> Saturation_MODE [ 0 ] == 1 ? _rtP -> P_95 : _rtDW -> Saturation_MODE
[ 0 ] == - 1 ? _rtP -> P_96 : _rtB -> B_20_289_0 [ 0 ] ; rtb_B_20_1339_0 [ 1
] = _rtDW -> Saturation_MODE [ 1 ] == 1 ? _rtP -> P_95 : _rtDW ->
Saturation_MODE [ 1 ] == - 1 ? _rtP -> P_96 : _rtB -> B_20_289_0 [ 1 ] ;
rtb_B_20_1339_0 [ 2 ] = _rtDW -> Saturation_MODE [ 2 ] == 1 ? _rtP -> P_95 :
_rtDW -> Saturation_MODE [ 2 ] == - 1 ? _rtP -> P_96 : _rtB -> B_20_289_0 [ 2
] ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> B_20_291_0 [ 0 ] =
rtb_B_20_1339_0 [ 0 ] ; _rtB -> B_20_291_0 [ 1 ] = rtb_B_20_1339_0 [ 1 ] ;
_rtB -> B_20_291_0 [ 2 ] = rtb_B_20_1339_0 [ 2 ] ; } ssCallAccelRunBlock ( S
, 20 , 292 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) {
rtb_B_20_892_0 = _rtP -> P_97 * _rtB -> B_20_291_0 [ 0 ] ; if (
rtb_B_20_892_0 >= _rtP -> P_98 ) { _rtB -> B_20_294_0 [ 0 ] = _rtP -> P_98 ;
} else if ( rtb_B_20_892_0 <= _rtP -> P_99 ) { _rtB -> B_20_294_0 [ 0 ] =
_rtP -> P_99 ; } else { _rtB -> B_20_294_0 [ 0 ] = rtb_B_20_892_0 ; }
rtb_B_20_892_0 = _rtP -> P_97 * _rtB -> B_20_291_0 [ 1 ] ; if (
rtb_B_20_892_0 >= _rtP -> P_98 ) { _rtB -> B_20_294_0 [ 1 ] = _rtP -> P_98 ;
} else if ( rtb_B_20_892_0 <= _rtP -> P_99 ) { _rtB -> B_20_294_0 [ 1 ] =
_rtP -> P_99 ; } else { _rtB -> B_20_294_0 [ 1 ] = rtb_B_20_892_0 ; }
rtb_B_20_892_0 = _rtP -> P_97 * _rtB -> B_20_291_0 [ 2 ] ; if (
rtb_B_20_892_0 >= _rtP -> P_98 ) { _rtB -> B_20_294_0 [ 2 ] = _rtP -> P_98 ;
} else if ( rtb_B_20_892_0 <= _rtP -> P_99 ) { _rtB -> B_20_294_0 [ 2 ] =
_rtP -> P_99 ; } else { _rtB -> B_20_294_0 [ 2 ] = rtb_B_20_892_0 ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_295_0 [ 0 ] = _rtP -> P_100 [ 0
] ; _rtB -> B_20_295_0 [ 1 ] = _rtP -> P_100 [ 1 ] ; _rtB -> B_20_295_0 [ 2 ]
= _rtP -> P_100 [ 2 ] ; _rtB -> B_20_296_0 = _rtP -> P_101 ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { memset ( & _rtB -> B_20_310_0 [ 0 ] , 0 , 9U
* sizeof ( real_T ) ) ; _rtB -> B_20_310_0 [ 0 ] = _rtB -> B_20_191_0 [ 0 ] ;
_rtB -> B_20_310_0 [ 4 ] = _rtB -> B_20_191_0 [ 1 ] ; _rtB -> B_20_310_0 [ 8
] = _rtB -> B_20_191_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
rtb_B_20_308_0 [ 0 ] = _rtB -> B_20_191_0 [ 1 ] ; rtb_B_20_308_0 [ 1 ] = _rtB
-> B_20_191_0 [ 0 ] ; rtb_B_20_308_0 [ 2 ] = _rtP -> P_102 ; rtb_B_20_308_0 [
3 ] = _rtB -> B_20_191_0 [ 2 ] ; rtb_B_20_308_0 [ 4 ] = _rtP -> P_102 ;
rtb_B_20_308_0 [ 5 ] = _rtB -> B_20_191_0 [ 0 ] ; rtb_B_20_308_0 [ 6 ] = _rtP
-> P_102 ; rtb_B_20_308_0 [ 7 ] = _rtB -> B_20_191_0 [ 2 ] ; rtb_B_20_308_0 [
8 ] = _rtB -> B_20_191_0 [ 1 ] ; memcpy ( & _rtB -> B_20_310_0 [ 9 ] , &
rtb_B_20_308_0 [ 0 ] , 9U * sizeof ( real_T ) ) ; rtb_B_20_1281_0 = _rtP ->
P_103 ; rtb_B_20_322_0 [ 0 ] = _rtP -> P_103 ; rtb_B_20_322_0 [ 1 ] = _rtB ->
B_20_191_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_20_314_0
[ 0 ] = _rtP -> P_104 * _rtB -> B_20_191_0 [ 0 ] ; _rtB -> B_20_314_0 [ 1 ] =
_rtP -> P_104 * _rtB -> B_20_191_0 [ 1 ] ; _rtB -> B_20_314_0 [ 2 ] = _rtP ->
P_104 * _rtB -> B_20_191_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
rtb_B_20_322_0 [ 2 ] = _rtB -> B_20_314_0 [ 1 ] ; rtb_B_20_322_0 [ 3 ] = _rtB
-> B_20_314_0 [ 2 ] ; rtb_B_20_322_0 [ 4 ] = rtb_B_20_1281_0 ; rtb_B_20_322_0
[ 5 ] = _rtB -> B_20_191_0 [ 0 ] ; rtb_B_20_322_0 [ 6 ] = _rtB -> B_20_191_0
[ 1 ] ; rtb_B_20_322_0 [ 7 ] = _rtB -> B_20_314_0 [ 0 ] ; rtb_B_20_322_0 [ 8
] = rtb_B_20_1281_0 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i <
6 ; i ++ ) { _rtB -> B_20_323_0 [ i_0 + 3 * i ] = 0.0 ; _rtB -> B_20_323_0 [
i_0 + 3 * i ] += _rtB -> B_20_310_0 [ 3 * i ] * rtb_B_20_322_0 [ i_0 ] ; _rtB
-> B_20_323_0 [ i_0 + 3 * i ] += _rtB -> B_20_310_0 [ 3 * i + 1 ] *
rtb_B_20_322_0 [ i_0 + 3 ] ; _rtB -> B_20_323_0 [ i_0 + 3 * i ] += _rtB ->
B_20_310_0 [ 3 * i + 2 ] * rtb_B_20_322_0 [ i_0 + 6 ] ; } } } if (
ssIsSampleHit ( S , 5 , 0 ) ) { if ( _rtDW ->
DiscreteTimeIntegrator_IC_LOADING != 0 ) { for ( i = 0 ; i < 18 ; i ++ ) {
_rtDW -> DiscreteTimeIntegrator_DSTATE_i [ i ] = 0.0 ; _rtB -> B_20_324_0 [ i
] = _rtDW -> DiscreteTimeIntegrator_DSTATE_i [ i ] ; } } else { for ( i = 0 ;
i < 18 ; i ++ ) { _rtB -> B_20_324_0 [ i ] = _rtP -> P_105 * _rtB ->
B_20_323_0 [ i ] + _rtDW -> DiscreteTimeIntegrator_DSTATE_i [ i ] ; } } } if
( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i = 0 ; i < 18 ; i ++ ) { _rtB ->
B_20_400_0 [ i ] = _rtB -> B_20_310_0 [ i ] + _rtB -> B_20_324_0 [ i ] ; }
_rtB -> B_20_326_0 = _rtP -> P_106 ; } _rtB -> B_20_398_0 [ 0 ] = _rtB ->
B_20_326_0 ; rtb_B_20_1060_0 = ( ( _rtB -> B_20_928_0 [ 0 ] * _rtB ->
B_20_928_0 [ 0 ] + _rtB -> B_20_928_0 [ 1 ] * _rtB -> B_20_928_0 [ 1 ] ) +
_rtB -> B_20_928_0 [ 2 ] * _rtB -> B_20_928_0 [ 2 ] ) + _rtB -> B_20_928_0 [
3 ] * _rtB -> B_20_928_0 [ 3 ] ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW
-> sqrt_DWORK1_n != 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
sqrt_DWORK1_n = 0 ; } rtb_B_20_1060_0 = muDoubleScalarSqrt ( rtb_B_20_1060_0
) ; } else { if ( rtb_B_20_1060_0 < 0.0 ) { rtb_B_20_1060_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_1060_0 ) ) ; } else {
rtb_B_20_1060_0 = muDoubleScalarSqrt ( rtb_B_20_1060_0 ) ; } _rtDW ->
sqrt_DWORK1_n = 1 ; } rtb_B_20_1077_0 = _rtB -> B_20_928_0 [ 1 ] /
rtb_B_20_1060_0 ; rtb_B_20_57_0 = _rtB -> B_20_928_0 [ 3 ] / rtb_B_20_1060_0
; rtb_B_20_897_0 = _rtB -> B_20_928_0 [ 0 ] / rtb_B_20_1060_0 ;
rtb_B_20_1060_0 = _rtB -> B_20_928_0 [ 2 ] / rtb_B_20_1060_0 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_350_0 = _rtP -> P_109 ; }
rtb_B_20_892_0 = ( ( rtb_B_20_1077_0 * rtb_B_20_57_0 + rtb_B_20_897_0 *
rtb_B_20_1060_0 ) * _rtP -> P_107 * _rtB -> B_20_295_0 [ 0 ] + (
rtb_B_20_1060_0 * rtb_B_20_57_0 - rtb_B_20_897_0 * rtb_B_20_1077_0 ) * _rtP
-> P_108 * _rtB -> B_20_295_0 [ 1 ] ) + ( ( _rtB -> B_20_350_0 -
rtb_B_20_1077_0 * rtb_B_20_1077_0 ) - rtb_B_20_1060_0 * rtb_B_20_1060_0 ) *
_rtP -> P_110 * _rtB -> B_20_295_0 [ 2 ] ; _rtB -> B_20_398_0 [ 1 ] =
rtb_B_20_892_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_358_0 =
_rtP -> P_111 ; } rtb_B_20_37_0 = ( ( ( _rtB -> B_20_358_0 - rtb_B_20_1060_0
* rtb_B_20_1060_0 ) - rtb_B_20_57_0 * rtb_B_20_57_0 ) * _rtP -> P_112 * _rtB
-> B_20_295_0 [ 0 ] + ( rtb_B_20_1077_0 * rtb_B_20_1060_0 + rtb_B_20_897_0 *
rtb_B_20_57_0 ) * _rtP -> P_113 * _rtB -> B_20_295_0 [ 1 ] ) + (
rtb_B_20_1077_0 * rtb_B_20_57_0 - rtb_B_20_897_0 * rtb_B_20_1060_0 ) * _rtP
-> P_114 * _rtB -> B_20_295_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> B_20_380_0 = _rtP -> P_116 ; } rtb_B_20_1060_0 = ( ( ( _rtB ->
B_20_380_0 - rtb_B_20_1077_0 * rtb_B_20_1077_0 ) - rtb_B_20_57_0 *
rtb_B_20_57_0 ) * _rtP -> P_117 * _rtB -> B_20_295_0 [ 1 ] + (
rtb_B_20_1077_0 * rtb_B_20_1060_0 - rtb_B_20_897_0 * rtb_B_20_57_0 ) * _rtP
-> P_115 * _rtB -> B_20_295_0 [ 0 ] ) + ( rtb_B_20_897_0 * rtb_B_20_1077_0 +
rtb_B_20_1060_0 * rtb_B_20_57_0 ) * _rtP -> P_118 * _rtB -> B_20_295_0 [ 2 ]
; rtb_B_20_1339_0 [ 0 ] = _rtP -> P_119 * rtb_B_20_37_0 ; rtb_B_20_1339_0 [ 1
] = _rtP -> P_119 * rtb_B_20_1060_0 ; rtb_B_20_1339_0 [ 2 ] = _rtP -> P_119 *
rtb_B_20_892_0 ; _rtB -> B_20_398_0 [ 2 ] = rtb_B_20_1339_0 [ 1 ] ; _rtB ->
B_20_398_0 [ 3 ] = rtb_B_20_1339_0 [ 2 ] ; _rtB -> B_20_398_0 [ 4 ] = _rtB ->
B_20_326_0 ; _rtB -> B_20_398_0 [ 5 ] = rtb_B_20_37_0 ; _rtB -> B_20_398_0 [
6 ] = rtb_B_20_1060_0 ; _rtB -> B_20_398_0 [ 7 ] = rtb_B_20_1339_0 [ 0 ] ;
_rtB -> B_20_398_0 [ 8 ] = _rtB -> B_20_326_0 ; if ( ssIsSampleHit ( S , 5 ,
0 ) ) { for ( i = 0 ; i < 9 ; i ++ ) { if ( _rtDW ->
DiscreteTimeIntegrator1_SYSTEM_ENABLE != 0 ) { _rtB -> B_20_400_0 [ i + 18 ]
= _rtDW -> DiscreteTimeIntegrator1_DSTATE [ i ] ; } else { _rtB -> B_20_400_0
[ i + 18 ] = _rtP -> P_120 * _rtB -> B_20_398_0 [ i ] + _rtDW ->
DiscreteTimeIntegrator1_DSTATE [ i ] ; } } } if ( ssIsSampleHit ( S , 1 , 0 )
) { memcpy ( & _rtDW -> Pseudoinverse_X [ 0 ] , & _rtB -> B_20_400_0 [ 0 ] ,
27U * sizeof ( real_T ) ) ; i = MWDSP_SVD_D ( & _rtDW -> Pseudoinverse_X [ 0U
] , 3 , 9 , & _rtDW -> Pseudoinverse_S [ 0U ] , & _rtDW -> Pseudoinverse_E [
0U ] , & _rtDW -> Pseudoinverse_WORK [ 0U ] , & _rtDW -> Pseudoinverse_U [ 0U
] , & _rtDW -> Pseudoinverse_V [ 0U ] , 1 ) ; if ( i == 0 ) {
MWDSPCG_Pseudoinverse_D ( & _rtDW -> Pseudoinverse_S [ 0U ] , & _rtDW ->
Pseudoinverse_U [ 0U ] , & _rtDW -> Pseudoinverse_V [ 0U ] , & _rtB ->
B_20_401_0 [ 0U ] , 3 , 9 ) ; } } _rtB -> B_20_403_0 [ 0 ] = _rtB ->
B_20_191_0 [ 1 ] * B_20_405_0 [ 2 ] - _rtB -> B_20_191_0 [ 2 ] * B_20_405_0 [
1 ] ; _rtB -> B_20_403_0 [ 1 ] = _rtB -> B_20_191_0 [ 2 ] * B_20_405_0 [ 0 ]
- _rtB -> B_20_191_0 [ 0 ] * B_20_405_0 [ 2 ] ; _rtB -> B_20_403_0 [ 2 ] =
_rtB -> B_20_191_0 [ 0 ] * B_20_405_0 [ 1 ] - _rtB -> B_20_191_0 [ 1 ] *
B_20_405_0 [ 0 ] ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { if ( _rtDW ->
DiscreteTimeIntegrator2_SYSTEM_ENABLE != 0 ) { _rtB -> B_20_404_0 [ 0 ] =
_rtDW -> DiscreteTimeIntegrator2_DSTATE [ 0 ] ; _rtB -> B_20_404_0 [ 1 ] =
_rtDW -> DiscreteTimeIntegrator2_DSTATE [ 1 ] ; _rtB -> B_20_404_0 [ 2 ] =
_rtDW -> DiscreteTimeIntegrator2_DSTATE [ 2 ] ; } else { _rtB -> B_20_404_0 [
0 ] = _rtP -> P_122 * _rtB -> B_20_403_0 [ 0 ] + _rtDW ->
DiscreteTimeIntegrator2_DSTATE [ 0 ] ; _rtB -> B_20_404_0 [ 1 ] = _rtP ->
P_122 * _rtB -> B_20_403_0 [ 1 ] + _rtDW -> DiscreteTimeIntegrator2_DSTATE [
1 ] ; _rtB -> B_20_404_0 [ 2 ] = _rtP -> P_122 * _rtB -> B_20_403_0 [ 2 ] +
_rtDW -> DiscreteTimeIntegrator2_DSTATE [ 2 ] ; } } B_20_405_0 [ 0 ] = ( 0.0
- B_20_405_0 [ 0 ] ) - _rtB -> B_20_404_0 [ 0 ] ; B_20_405_0 [ 1 ] = ( 0.0 -
B_20_405_0 [ 1 ] ) - _rtB -> B_20_404_0 [ 1 ] ; B_20_405_0 [ 2 ] = ( 0.0 -
B_20_405_0 [ 2 ] ) - _rtB -> B_20_404_0 [ 2 ] ; for ( i_0 = 0 ; i_0 < 9 ; i_0
++ ) { y_0 [ i_0 ] = _rtB -> B_20_401_0 [ i_0 + 18 ] * B_20_405_0 [ 2 ] + (
_rtB -> B_20_401_0 [ i_0 + 9 ] * B_20_405_0 [ 1 ] + _rtB -> B_20_401_0 [ i_0
] * B_20_405_0 [ 0 ] ) ; } _rtB -> B_20_416_0 [ 0 ] = y_0 [ 0 ] ; _rtB ->
B_20_416_0 [ 1 ] = y_0 [ 3 ] ; _rtB -> B_20_416_0 [ 2 ] = y_0 [ 4 ] ; _rtB ->
B_20_416_0 [ 3 ] = y_0 [ 3 ] ; _rtB -> B_20_416_0 [ 4 ] = y_0 [ 1 ] ; _rtB ->
B_20_416_0 [ 5 ] = y_0 [ 5 ] ; _rtB -> B_20_416_0 [ 6 ] = y_0 [ 4 ] ; _rtB ->
B_20_416_0 [ 7 ] = y_0 [ 5 ] ; _rtB -> B_20_416_0 [ 8 ] = y_0 [ 2 ] ;
ssCallAccelRunBlock ( S , 20 , 417 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_20_1333_0 [ 0 ] = y_0 [ 6 ] / _rtB -> B_20_296_0 ; _rtB -> B_20_1333_0 [ 1
] = y_0 [ 7 ] / _rtB -> B_20_296_0 ; _rtB -> B_20_1333_0 [ 2 ] = y_0 [ 8 ] /
_rtB -> B_20_296_0 ; ssCallAccelRunBlock ( S , 20 , 419 , SS_CALL_MDL_OUTPUTS
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 20 , 420 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 20 , 421 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 422 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 423 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 20 , 424 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 425 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 426 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 427 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_20_428_0 = _rtP -> P_124 ; _rtB -> B_20_429_0 = _rtP -> P_125 ; } if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> Switch_Mode_m = ( _rtB -> B_20_76_0 [ 0
] >= _rtP -> P_126 ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_431_0 = _rtP -> P_127 ; } rtb_B_20_1060_0 = ( _rtB -> B_20_431_0 - ( ( (
_rtB -> B_20_76_0 [ 0 ] * _rtB -> B_20_76_0 [ 0 ] + _rtB -> B_20_76_0 [ 1 ] *
_rtB -> B_20_76_0 [ 1 ] ) + _rtB -> B_20_76_0 [ 2 ] * _rtB -> B_20_76_0 [ 2 ]
) + _rtB -> B_20_76_0 [ 3 ] * _rtB -> B_20_76_0 [ 3 ] ) ) * _rtP -> P_128 ;
_rtB -> B_20_435_0 = ( ( _rtB -> B_20_76_0 [ 1 ] * _rtB -> B_20_191_0 [ 0 ] +
_rtB -> B_20_76_0 [ 2 ] * _rtB -> B_20_191_0 [ 1 ] ) + _rtB -> B_20_76_0 [ 3
] * _rtB -> B_20_191_0 [ 2 ] ) * - 0.5 + rtb_B_20_1060_0 * _rtB -> B_20_76_0
[ 0 ] ; _rtB -> B_20_436_0 = ( ( _rtB -> B_20_76_0 [ 0 ] * _rtB -> B_20_191_0
[ 0 ] + _rtB -> B_20_76_0 [ 2 ] * _rtB -> B_20_191_0 [ 2 ] ) - _rtB ->
B_20_76_0 [ 3 ] * _rtB -> B_20_191_0 [ 1 ] ) * 0.5 + rtb_B_20_1060_0 * _rtB
-> B_20_76_0 [ 1 ] ; _rtB -> B_20_437_0 = ( ( _rtB -> B_20_76_0 [ 0 ] * _rtB
-> B_20_191_0 [ 1 ] + _rtB -> B_20_76_0 [ 3 ] * _rtB -> B_20_191_0 [ 0 ] ) -
_rtB -> B_20_76_0 [ 1 ] * _rtB -> B_20_191_0 [ 2 ] ) * 0.5 + rtb_B_20_1060_0
* _rtB -> B_20_76_0 [ 2 ] ; _rtB -> B_20_438_0 = ( ( _rtB -> B_20_76_0 [ 0 ]
* _rtB -> B_20_191_0 [ 2 ] + _rtB -> B_20_76_0 [ 1 ] * _rtB -> B_20_191_0 [ 1
] ) - _rtB -> B_20_76_0 [ 2 ] * _rtB -> B_20_191_0 [ 0 ] ) * 0.5 +
rtb_B_20_1060_0 * _rtB -> B_20_76_0 [ 3 ] ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> B_20_439_0 = _rtP -> P_129 ; } _rtB -> B_20_449_0 [ 0 ] = _rtB ->
B_20_439_0 ; _rtB -> B_20_449_0 [ 1 ] = _rtB -> B_20_928_0 [ 3 ] ; _rtB ->
B_20_449_0 [ 2 ] = _rtP -> P_130 * _rtB -> B_20_928_0 [ 2 ] ; _rtB ->
B_20_449_0 [ 3 ] = _rtP -> P_131 * _rtB -> B_20_928_0 [ 3 ] ; _rtB ->
B_20_449_0 [ 4 ] = _rtB -> B_20_439_0 ; _rtB -> B_20_449_0 [ 5 ] = _rtB ->
B_20_928_0 [ 1 ] ; _rtB -> B_20_449_0 [ 6 ] = _rtB -> B_20_928_0 [ 2 ] ; _rtB
-> B_20_449_0 [ 7 ] = _rtP -> P_132 * _rtB -> B_20_928_0 [ 1 ] ; _rtB ->
B_20_449_0 [ 8 ] = _rtB -> B_20_439_0 ; memcpy ( & rtb_B_20_574_0 [ 0 ] , &
_rtB -> B_20_449_0 [ 0 ] , 9U * sizeof ( real_T ) ) ; LUf_int32_Treal_T (
rtb_B_20_574_0 , rtb_B_20_1339_0 , 3 ) ; for ( i = 0 ; i < 3 ; i ++ ) { k = (
int32_T ) muDoubleScalarFloor ( rtb_B_20_1339_0 [ i ] ) - 1 ; if ( k < 0 ) {
k = 0 ; } else { if ( k >= 3 ) { k = 2 ; } } rtb_B_20_1175_0 [ i ] = _rtB ->
B_20_451_0 [ k ] ; rtb_B_20_1175_0 [ 3 + i ] = _rtB -> B_20_451_0 [ 3 + k ] ;
rtb_B_20_1175_0 [ 6 + i ] = _rtB -> B_20_451_0 [ 6 + k ] ; } for ( i_0 = 0 ;
i_0 < 3 ; i_0 ++ ) { idxout = i_0 * 3 ; i = 1 ; idxB = idxout + 1 ;
rtb_B_20_37_0 = rtb_B_20_1175_0 [ idxB ] ; k = 0 ; while ( k < 1 ) {
rtb_B_20_37_0 -= rtb_B_20_574_0 [ i ] * rtb_B_20_1175_0 [ idxout ] ; i += 3 ;
k = 1 ; } rtb_B_20_1175_0 [ idxB ] = rtb_B_20_37_0 ; i = 2 ; idxB = idxout +
2 ; rtb_B_20_37_0 = rtb_B_20_1175_0 [ idxB ] ; for ( k = 0 ; k < 2 ; k ++ ) {
rtb_B_20_37_0 -= rtb_B_20_1175_0 [ idxout + k ] * rtb_B_20_574_0 [ i ] ; i +=
3 ; } rtb_B_20_1175_0 [ idxB ] = rtb_B_20_37_0 ; } for ( i_0 = 0 ; i_0 < 3 ;
i_0 ++ ) { idxout = i_0 * 3 ; i = idxout + 2 ; _rtB -> B_20_1176_0 [ i ] =
rtb_B_20_1175_0 [ i ] / rtb_B_20_574_0 [ 8 ] ; i = 7 ; idxB = idxout + 1 ;
rtb_B_20_37_0 = rtb_B_20_1175_0 [ idxB ] ; k = 2 ; while ( k > 1 ) {
rtb_B_20_37_0 -= _rtB -> B_20_1176_0 [ idxout + 2 ] * rtb_B_20_574_0 [ i ] ;
i -= 3 ; k = 1 ; } _rtB -> B_20_1176_0 [ idxB ] = rtb_B_20_37_0 /
rtb_B_20_574_0 [ i ] ; i = 6 ; rtb_B_20_37_0 = rtb_B_20_1175_0 [ idxout ] ;
for ( k = 2 ; k > 0 ; k -- ) { rtb_B_20_37_0 -= _rtB -> B_20_1176_0 [ idxout
+ k ] * rtb_B_20_574_0 [ i ] ; i -= 3 ; } _rtB -> B_20_1176_0 [ idxout ] =
rtb_B_20_37_0 / rtb_B_20_574_0 [ i ] ; } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) {
_rtB -> B_20_1333_0 [ i_0 ] = 0.0 ; _rtB -> B_20_1333_0 [ i_0 ] += _rtB ->
B_20_1176_0 [ i_0 ] * _rtB -> B_20_852_0 [ 0 ] ; _rtB -> B_20_1333_0 [ i_0 ]
+= _rtB -> B_20_1176_0 [ i_0 + 3 ] * _rtB -> B_20_852_0 [ 1 ] ; _rtB ->
B_20_1333_0 [ i_0 ] += _rtB -> B_20_1176_0 [ i_0 + 6 ] * _rtB -> B_20_852_0 [
2 ] ; } ssCallAccelRunBlock ( S , 20 , 456 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_457_0 = _rtP -> P_133 ; _rtB ->
B_20_458_0 = _rtP -> P_134 * _rtB -> B_20_457_0 ; } _rtB -> B_20_1333_0 [ 0 ]
= ( _rtB -> B_20_852_0 [ 0 ] - _rtB -> B_20_457_0 * _rtB -> B_20_928_0 [ 1 ]
) * _rtB -> B_20_458_0 ; _rtB -> B_20_1333_0 [ 1 ] = ( _rtB -> B_20_852_0 [ 1
] - _rtB -> B_20_457_0 * _rtB -> B_20_928_0 [ 2 ] ) * _rtB -> B_20_458_0 ;
_rtB -> B_20_1333_0 [ 2 ] = ( _rtB -> B_20_852_0 [ 2 ] - _rtB -> B_20_457_0 *
_rtB -> B_20_928_0 [ 3 ] ) * _rtB -> B_20_458_0 ; ssCallAccelRunBlock ( S ,
20 , 462 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 463 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 464 ,
SS_CALL_MDL_OUTPUTS ) ; rtb_B_20_1339_0 [ 0 ] = _rtB -> B_20_835_0 . vj2000 [
0 ] ; rtb_B_20_1339_0 [ 1 ] = _rtB -> B_20_835_0 . vj2000 [ 1 ] ;
rtb_B_20_1339_0 [ 2 ] = _rtB -> B_20_835_0 . vj2000 [ 2 ] ; _rtB ->
B_20_465_1 [ 0 ] = _rtB -> B_20_835_0 . j2000 [ 0 ] ; _rtB -> B_20_465_1 [ 1
] = _rtB -> B_20_835_0 . j2000 [ 1 ] ; _rtB -> B_20_465_1 [ 2 ] = _rtB ->
B_20_835_0 . j2000 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( &
rtb_B_20_1301_0 [ 0 ] , & _rtP -> P_135 [ 0 ] , 9U * sizeof ( real_T ) ) ;
rtb_B_20_1281_0 = _rtP -> P_136 ; rtb_B_20_468_0 = _rtP -> P_137 * _rtP ->
P_136 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> B_20_469_0 = _rtB ->
B_20_206_0 [ 0 ] * _rtB -> B_20_206_0 [ 0 ] ; } if ( ssIsSampleHit ( S , 1 ,
0 ) ) { rtb_B_20_482_0 [ 0 ] = _rtP -> P_138 ; rtb_B_20_482_0 [ 1 ] = _rtP ->
P_139 [ 2 ] ; rtb_B_20_482_0 [ 2 ] = _rtP -> P_140 * _rtP -> P_139 [ 1 ] ;
rtb_B_20_482_0 [ 3 ] = _rtP -> P_140 * _rtP -> P_139 [ 2 ] ; rtb_B_20_482_0 [
4 ] = _rtP -> P_138 ; rtb_B_20_482_0 [ 5 ] = _rtP -> P_139 [ 0 ] ;
rtb_B_20_482_0 [ 6 ] = _rtP -> P_139 [ 1 ] ; rtb_B_20_482_0 [ 7 ] = _rtP ->
P_140 * _rtP -> P_139 [ 0 ] ; rtb_B_20_482_0 [ 8 ] = _rtP -> P_138 ;
rtb_B_20_497_0 [ 0 ] = _rtP -> P_141 ; rtb_B_20_497_0 [ 1 ] = _rtP -> P_142 [
2 ] ; rtb_B_20_497_0 [ 2 ] = _rtP -> P_143 * _rtP -> P_142 [ 1 ] ;
rtb_B_20_497_0 [ 3 ] = _rtP -> P_143 * _rtP -> P_142 [ 2 ] ; rtb_B_20_497_0 [
4 ] = _rtP -> P_141 ; rtb_B_20_497_0 [ 5 ] = _rtP -> P_142 [ 0 ] ;
rtb_B_20_497_0 [ 6 ] = _rtP -> P_142 [ 1 ] ; rtb_B_20_497_0 [ 7 ] = _rtP ->
P_143 * _rtP -> P_142 [ 0 ] ; rtb_B_20_497_0 [ 8 ] = _rtP -> P_141 ; for (
i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtb_B_20_1129_0
[ i_0 + 3 * i ] = 0.0 ; rtb_B_20_1129_0 [ i_0 + 3 * i ] += rtb_B_20_482_0 [ 3
* i ] * rtb_B_20_482_0 [ i_0 ] ; rtb_B_20_1129_0 [ i_0 + 3 * i ] +=
rtb_B_20_482_0 [ 3 * i + 1 ] * rtb_B_20_482_0 [ i_0 + 3 ] ; rtb_B_20_1129_0 [
i_0 + 3 * i ] += rtb_B_20_482_0 [ 3 * i + 2 ] * rtb_B_20_482_0 [ i_0 + 6 ] ;
} } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) {
rtb_B_20_36_0 [ i_0 + 3 * i ] = 0.0 ; rtb_B_20_36_0 [ i_0 + 3 * i ] +=
rtb_B_20_497_0 [ 3 * i ] * rtb_B_20_482_0 [ i_0 ] ; rtb_B_20_36_0 [ i_0 + 3 *
i ] += rtb_B_20_497_0 [ 3 * i + 1 ] * rtb_B_20_482_0 [ i_0 + 3 ] ;
rtb_B_20_36_0 [ i_0 + 3 * i ] += rtb_B_20_497_0 [ 3 * i + 2 ] *
rtb_B_20_482_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i
= 0 ; i < 3 ; i ++ ) { rtb_B_20_308_0 [ i_0 + 3 * i ] = 0.0 ; rtb_B_20_308_0
[ i_0 + 3 * i ] += rtb_B_20_482_0 [ 3 * i ] * rtb_B_20_497_0 [ i_0 ] ;
rtb_B_20_308_0 [ i_0 + 3 * i ] += rtb_B_20_482_0 [ 3 * i + 1 ] *
rtb_B_20_497_0 [ i_0 + 3 ] ; rtb_B_20_308_0 [ i_0 + 3 * i ] += rtb_B_20_482_0
[ 3 * i + 2 ] * rtb_B_20_497_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ;
i_0 ++ ) { rtb_B_20_503_0 [ 3 * i_0 ] = ( ( rtb_B_20_1129_0 [ 3 * i_0 ] *
_rtB -> B_20_469_0 + rtb_B_20_36_0 [ 3 * i_0 ] * _rtB -> B_20_206_0 [ 0 ] ) +
rtb_B_20_308_0 [ 3 * i_0 ] * _rtB -> B_20_206_0 [ 0 ] ) * rtb_B_20_468_0 ;
rtb_B_20_503_0 [ 1 + 3 * i_0 ] = ( ( rtb_B_20_1129_0 [ 3 * i_0 + 1 ] * _rtB
-> B_20_469_0 + rtb_B_20_36_0 [ 3 * i_0 + 1 ] * _rtB -> B_20_206_0 [ 0 ] ) +
rtb_B_20_308_0 [ 3 * i_0 + 1 ] * _rtB -> B_20_206_0 [ 0 ] ) * rtb_B_20_468_0
; rtb_B_20_503_0 [ 2 + 3 * i_0 ] = ( ( rtb_B_20_1129_0 [ 3 * i_0 + 2 ] * _rtB
-> B_20_469_0 + rtb_B_20_36_0 [ 3 * i_0 + 2 ] * _rtB -> B_20_206_0 [ 0 ] ) +
rtb_B_20_308_0 [ 3 * i_0 + 2 ] * _rtB -> B_20_206_0 [ 0 ] ) * rtb_B_20_468_0
; } rtb_B_20_1281_0 = _rtP -> P_144 ; rtb_B_20_505_0 = _rtP -> P_145 * _rtP
-> P_144 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> B_20_506_0 = _rtB
-> B_20_206_0 [ 1 ] * _rtB -> B_20_206_0 [ 1 ] ; } if ( ssIsSampleHit ( S , 1
, 0 ) ) { rtb_B_20_519_0 [ 0 ] = _rtP -> P_146 ; rtb_B_20_519_0 [ 1 ] = _rtP
-> P_147 [ 2 ] ; rtb_B_20_519_0 [ 2 ] = _rtP -> P_148 * _rtP -> P_147 [ 1 ] ;
rtb_B_20_519_0 [ 3 ] = _rtP -> P_148 * _rtP -> P_147 [ 2 ] ; rtb_B_20_519_0 [
4 ] = _rtP -> P_146 ; rtb_B_20_519_0 [ 5 ] = _rtP -> P_147 [ 0 ] ;
rtb_B_20_519_0 [ 6 ] = _rtP -> P_147 [ 1 ] ; rtb_B_20_519_0 [ 7 ] = _rtP ->
P_148 * _rtP -> P_147 [ 0 ] ; rtb_B_20_519_0 [ 8 ] = _rtP -> P_146 ;
rtb_B_20_534_0 [ 0 ] = _rtP -> P_149 ; rtb_B_20_534_0 [ 1 ] = _rtP -> P_150 [
2 ] ; rtb_B_20_534_0 [ 2 ] = _rtP -> P_151 * _rtP -> P_150 [ 1 ] ;
rtb_B_20_534_0 [ 3 ] = _rtP -> P_151 * _rtP -> P_150 [ 2 ] ; rtb_B_20_534_0 [
4 ] = _rtP -> P_149 ; rtb_B_20_534_0 [ 5 ] = _rtP -> P_150 [ 0 ] ;
rtb_B_20_534_0 [ 6 ] = _rtP -> P_150 [ 1 ] ; rtb_B_20_534_0 [ 7 ] = _rtP ->
P_151 * _rtP -> P_150 [ 0 ] ; rtb_B_20_534_0 [ 8 ] = _rtP -> P_149 ; for (
i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtb_B_20_1129_0
[ i_0 + 3 * i ] = 0.0 ; rtb_B_20_1129_0 [ i_0 + 3 * i ] += rtb_B_20_519_0 [ 3
* i ] * rtb_B_20_519_0 [ i_0 ] ; rtb_B_20_1129_0 [ i_0 + 3 * i ] +=
rtb_B_20_519_0 [ 3 * i + 1 ] * rtb_B_20_519_0 [ i_0 + 3 ] ; rtb_B_20_1129_0 [
i_0 + 3 * i ] += rtb_B_20_519_0 [ 3 * i + 2 ] * rtb_B_20_519_0 [ i_0 + 6 ] ;
} } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) {
rtb_B_20_36_0 [ i_0 + 3 * i ] = 0.0 ; rtb_B_20_36_0 [ i_0 + 3 * i ] +=
rtb_B_20_534_0 [ 3 * i ] * rtb_B_20_519_0 [ i_0 ] ; rtb_B_20_36_0 [ i_0 + 3 *
i ] += rtb_B_20_534_0 [ 3 * i + 1 ] * rtb_B_20_519_0 [ i_0 + 3 ] ;
rtb_B_20_36_0 [ i_0 + 3 * i ] += rtb_B_20_534_0 [ 3 * i + 2 ] *
rtb_B_20_519_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i
= 0 ; i < 3 ; i ++ ) { rtb_B_20_308_0 [ i_0 + 3 * i ] = 0.0 ; rtb_B_20_308_0
[ i_0 + 3 * i ] += rtb_B_20_519_0 [ 3 * i ] * rtb_B_20_534_0 [ i_0 ] ;
rtb_B_20_308_0 [ i_0 + 3 * i ] += rtb_B_20_519_0 [ 3 * i + 1 ] *
rtb_B_20_534_0 [ i_0 + 3 ] ; rtb_B_20_308_0 [ i_0 + 3 * i ] += rtb_B_20_519_0
[ 3 * i + 2 ] * rtb_B_20_534_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ;
i_0 ++ ) { rtb_B_20_540_0 [ 3 * i_0 ] = ( ( rtb_B_20_1129_0 [ 3 * i_0 ] *
_rtB -> B_20_506_0 + rtb_B_20_36_0 [ 3 * i_0 ] * _rtB -> B_20_206_0 [ 1 ] ) +
rtb_B_20_308_0 [ 3 * i_0 ] * _rtB -> B_20_206_0 [ 1 ] ) * rtb_B_20_505_0 ;
rtb_B_20_540_0 [ 1 + 3 * i_0 ] = ( ( rtb_B_20_1129_0 [ 3 * i_0 + 1 ] * _rtB
-> B_20_506_0 + rtb_B_20_36_0 [ 3 * i_0 + 1 ] * _rtB -> B_20_206_0 [ 1 ] ) +
rtb_B_20_308_0 [ 3 * i_0 + 1 ] * _rtB -> B_20_206_0 [ 1 ] ) * rtb_B_20_505_0
; rtb_B_20_540_0 [ 2 + 3 * i_0 ] = ( ( rtb_B_20_1129_0 [ 3 * i_0 + 2 ] * _rtB
-> B_20_506_0 + rtb_B_20_36_0 [ 3 * i_0 + 2 ] * _rtB -> B_20_206_0 [ 1 ] ) +
rtb_B_20_308_0 [ 3 * i_0 + 2 ] * _rtB -> B_20_206_0 [ 1 ] ) * rtb_B_20_505_0
; } rtb_B_20_1281_0 = _rtP -> P_152 ; rtb_B_20_542_0 = _rtP -> P_153 * _rtP
-> P_152 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> B_20_543_0 = _rtB
-> B_20_206_0 [ 2 ] * _rtB -> B_20_206_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 1
, 0 ) ) { rtb_B_20_556_0 [ 0 ] = _rtP -> P_154 ; rtb_B_20_556_0 [ 1 ] = _rtP
-> P_155 [ 2 ] ; rtb_B_20_556_0 [ 2 ] = _rtP -> P_156 * _rtP -> P_155 [ 1 ] ;
rtb_B_20_556_0 [ 3 ] = _rtP -> P_156 * _rtP -> P_155 [ 2 ] ; rtb_B_20_556_0 [
4 ] = _rtP -> P_154 ; rtb_B_20_556_0 [ 5 ] = _rtP -> P_155 [ 0 ] ;
rtb_B_20_556_0 [ 6 ] = _rtP -> P_155 [ 1 ] ; rtb_B_20_556_0 [ 7 ] = _rtP ->
P_156 * _rtP -> P_155 [ 0 ] ; rtb_B_20_556_0 [ 8 ] = _rtP -> P_154 ;
rtb_B_20_1281_0 = _rtP -> P_157 ; rtb_B_20_571_0 [ 0 ] = _rtP -> P_157 ;
rtb_B_20_571_0 [ 1 ] = _rtP -> P_158 [ 2 ] ; rtb_B_20_571_0 [ 2 ] = _rtP ->
P_159 * _rtP -> P_158 [ 1 ] ; rtb_B_20_571_0 [ 3 ] = _rtP -> P_159 * _rtP ->
P_158 [ 2 ] ; rtb_B_20_571_0 [ 4 ] = _rtP -> P_157 ; rtb_B_20_571_0 [ 5 ] =
_rtP -> P_158 [ 0 ] ; rtb_B_20_571_0 [ 6 ] = _rtP -> P_158 [ 1 ] ;
rtb_B_20_571_0 [ 7 ] = _rtP -> P_159 * _rtP -> P_158 [ 0 ] ; rtb_B_20_571_0 [
8 ] = _rtP -> P_157 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i <
3 ; i ++ ) { rtb_B_20_1129_0 [ i_0 + 3 * i ] = 0.0 ; rtb_B_20_1129_0 [ i_0 +
3 * i ] += rtb_B_20_556_0 [ 3 * i ] * rtb_B_20_556_0 [ i_0 ] ;
rtb_B_20_1129_0 [ i_0 + 3 * i ] += rtb_B_20_556_0 [ 3 * i + 1 ] *
rtb_B_20_556_0 [ i_0 + 3 ] ; rtb_B_20_1129_0 [ i_0 + 3 * i ] +=
rtb_B_20_556_0 [ 3 * i + 2 ] * rtb_B_20_556_0 [ i_0 + 6 ] ; } } for ( i_0 = 0
; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtb_B_20_36_0 [ i_0 + 3
* i ] = 0.0 ; rtb_B_20_36_0 [ i_0 + 3 * i ] += rtb_B_20_571_0 [ 3 * i ] *
rtb_B_20_556_0 [ i_0 ] ; rtb_B_20_36_0 [ i_0 + 3 * i ] += rtb_B_20_571_0 [ 3
* i + 1 ] * rtb_B_20_556_0 [ i_0 + 3 ] ; rtb_B_20_36_0 [ i_0 + 3 * i ] +=
rtb_B_20_571_0 [ 3 * i + 2 ] * rtb_B_20_556_0 [ i_0 + 6 ] ; } } for ( i_0 = 0
; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { rtb_B_20_308_0 [ i_0 +
3 * i ] = 0.0 ; rtb_B_20_308_0 [ i_0 + 3 * i ] += rtb_B_20_556_0 [ 3 * i ] *
rtb_B_20_571_0 [ i_0 ] ; rtb_B_20_308_0 [ i_0 + 3 * i ] += rtb_B_20_556_0 [ 3
* i + 1 ] * rtb_B_20_571_0 [ i_0 + 3 ] ; rtb_B_20_308_0 [ i_0 + 3 * i ] +=
rtb_B_20_556_0 [ 3 * i + 2 ] * rtb_B_20_571_0 [ i_0 + 6 ] ; } } for ( i_0 = 0
; i_0 < 3 ; i_0 ++ ) { _rtB -> B_20_578_0 [ 3 * i_0 ] = ( ( rtb_B_20_1129_0 [
3 * i_0 ] * _rtB -> B_20_543_0 + rtb_B_20_36_0 [ 3 * i_0 ] * _rtB ->
B_20_206_0 [ 2 ] ) + rtb_B_20_308_0 [ 3 * i_0 ] * _rtB -> B_20_206_0 [ 2 ] )
* rtb_B_20_542_0 + ( ( rtb_B_20_1301_0 [ 3 * i_0 ] + rtb_B_20_503_0 [ 3 * i_0
] ) + rtb_B_20_540_0 [ 3 * i_0 ] ) ; _rtB -> B_20_578_0 [ 1 + 3 * i_0 ] = ( (
rtb_B_20_1129_0 [ 3 * i_0 + 1 ] * _rtB -> B_20_543_0 + rtb_B_20_36_0 [ 3 *
i_0 + 1 ] * _rtB -> B_20_206_0 [ 2 ] ) + rtb_B_20_308_0 [ 3 * i_0 + 1 ] *
_rtB -> B_20_206_0 [ 2 ] ) * rtb_B_20_542_0 + ( ( rtb_B_20_1301_0 [ 3 * i_0 +
1 ] + rtb_B_20_503_0 [ 3 * i_0 + 1 ] ) + rtb_B_20_540_0 [ 3 * i_0 + 1 ] ) ;
_rtB -> B_20_578_0 [ 2 + 3 * i_0 ] = ( ( rtb_B_20_1129_0 [ 3 * i_0 + 2 ] *
_rtB -> B_20_543_0 + rtb_B_20_36_0 [ 3 * i_0 + 2 ] * _rtB -> B_20_206_0 [ 2 ]
) + rtb_B_20_308_0 [ 3 * i_0 + 2 ] * _rtB -> B_20_206_0 [ 2 ] ) *
rtb_B_20_542_0 + ( ( rtb_B_20_1301_0 [ 3 * i_0 + 2 ] + rtb_B_20_503_0 [ 3 *
i_0 + 2 ] ) + rtb_B_20_540_0 [ 3 * i_0 + 2 ] ) ; } memcpy ( & _rtB ->
B_20_579_0 [ 0 ] , & _rtP -> P_160 [ 0 ] , 9U * sizeof ( real_T ) ) ; }
rtb_B_20_1060_0 = ( _rtB -> B_20_465_1 [ 0 ] * _rtB -> B_20_465_1 [ 0 ] +
_rtB -> B_20_465_1 [ 1 ] * _rtB -> B_20_465_1 [ 1 ] ) + _rtB -> B_20_465_1 [
2 ] * _rtB -> B_20_465_1 [ 2 ] ; if ( rtb_B_20_1060_0 < 0.0 ) { _rtB ->
B_20_582_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_1060_0 ) ) ;
} else { _rtB -> B_20_582_0 = muDoubleScalarSqrt ( rtb_B_20_1060_0 ) ; } _rtB
-> B_20_583_0 [ 0 ] = _rtB -> B_20_465_1 [ 0 ] * 0.0 ; _rtB -> B_20_583_0 [ 1
] = _rtB -> B_20_465_1 [ 1 ] * 0.0 ; _rtB -> B_20_583_0 [ 2 ] = _rtB ->
B_20_465_1 [ 2 ] * 0.0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_584_0 = _rtP -> P_161 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
Switch_Mode_f = ( _rtB -> B_20_582_0 > _rtP -> P_162 ) ; } if ( _rtDW ->
Switch_Mode_f ) { B_20_622_0 [ 0 ] = _rtB -> B_20_465_1 [ 0 ] ; B_20_622_0 [
1 ] = _rtB -> B_20_465_1 [ 1 ] ; B_20_622_0 [ 2 ] = _rtB -> B_20_465_1 [ 2 ]
; } else { B_20_622_0 [ 0 ] = _rtB -> B_20_583_0 [ 0 ] ; B_20_622_0 [ 1 ] =
_rtB -> B_20_583_0 [ 1 ] ; B_20_622_0 [ 2 ] = _rtB -> B_20_583_0 [ 2 ] ; } if
( _rtDW -> Switch_Mode_f ) { B_20_622_0 [ 3 ] = _rtB -> B_20_582_0 ; } else {
B_20_622_0 [ 3 ] = _rtB -> B_20_584_0 ; } rtb_B_20_1077_0 = B_20_622_0 [ 0 ]
/ B_20_622_0 [ 3 ] ; rtb_B_20_57_0 = B_20_622_0 [ 1 ] / B_20_622_0 [ 3 ] ;
rtb_B_20_892_0 = B_20_622_0 [ 2 ] / B_20_622_0 [ 3 ] ; _rtB -> B_20_600_0 [ 3
] = rtb_B_20_1077_0 ; _rtB -> B_20_600_0 [ 4 ] = rtb_B_20_57_0 ; _rtB ->
B_20_600_0 [ 5 ] = rtb_B_20_892_0 ; _rtB -> B_20_589_0 [ 0 ] =
rtb_B_20_1339_0 [ 1 ] * _rtB -> B_20_465_1 [ 2 ] - rtb_B_20_1339_0 [ 2 ] *
_rtB -> B_20_465_1 [ 1 ] ; _rtB -> B_20_589_0 [ 1 ] = rtb_B_20_1339_0 [ 2 ] *
_rtB -> B_20_465_1 [ 0 ] - rtb_B_20_1339_0 [ 0 ] * _rtB -> B_20_465_1 [ 2 ] ;
_rtB -> B_20_589_0 [ 2 ] = rtb_B_20_1339_0 [ 0 ] * _rtB -> B_20_465_1 [ 1 ] -
rtb_B_20_1339_0 [ 1 ] * _rtB -> B_20_465_1 [ 0 ] ; rtb_B_20_1060_0 = ( _rtB
-> B_20_589_0 [ 0 ] * _rtB -> B_20_589_0 [ 0 ] + _rtB -> B_20_589_0 [ 1 ] *
_rtB -> B_20_589_0 [ 1 ] ) + _rtB -> B_20_589_0 [ 2 ] * _rtB -> B_20_589_0 [
2 ] ; if ( rtb_B_20_1060_0 < 0.0 ) { _rtB -> B_20_592_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_1060_0 ) ) ; } else { _rtB
-> B_20_592_0 = muDoubleScalarSqrt ( rtb_B_20_1060_0 ) ; } _rtB -> B_20_593_0
[ 0 ] = _rtB -> B_20_589_0 [ 0 ] * 0.0 ; _rtB -> B_20_593_0 [ 1 ] = _rtB ->
B_20_589_0 [ 1 ] * 0.0 ; _rtB -> B_20_593_0 [ 2 ] = _rtB -> B_20_589_0 [ 2 ]
* 0.0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_594_0 = _rtP ->
P_163 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> Switch_Mode_j = ( _rtB ->
B_20_592_0 > _rtP -> P_164 ) ; } if ( _rtDW -> Switch_Mode_j ) { B_20_622_0 [
0 ] = _rtB -> B_20_589_0 [ 0 ] ; B_20_622_0 [ 1 ] = _rtB -> B_20_589_0 [ 1 ]
; B_20_622_0 [ 2 ] = _rtB -> B_20_589_0 [ 2 ] ; } else { B_20_622_0 [ 0 ] =
_rtB -> B_20_593_0 [ 0 ] ; B_20_622_0 [ 1 ] = _rtB -> B_20_593_0 [ 1 ] ;
B_20_622_0 [ 2 ] = _rtB -> B_20_593_0 [ 2 ] ; } if ( _rtDW -> Switch_Mode_j )
{ B_20_622_0 [ 3 ] = _rtB -> B_20_592_0 ; } else { B_20_622_0 [ 3 ] = _rtB ->
B_20_594_0 ; } rtb_B_20_1339_0 [ 0 ] = B_20_622_0 [ 0 ] / B_20_622_0 [ 3 ] ;
rtb_B_20_1339_0 [ 1 ] = B_20_622_0 [ 1 ] / B_20_622_0 [ 3 ] ; rtb_B_20_1339_0
[ 2 ] = B_20_622_0 [ 2 ] / B_20_622_0 [ 3 ] ; _rtB -> B_20_600_0 [ 6 ] =
rtb_B_20_1339_0 [ 0 ] ; _rtB -> B_20_600_0 [ 7 ] = rtb_B_20_1339_0 [ 1 ] ;
_rtB -> B_20_600_0 [ 8 ] = rtb_B_20_1339_0 [ 2 ] ; _rtB -> B_20_600_0 [ 0 ] =
rtb_B_20_57_0 * rtb_B_20_1339_0 [ 2 ] - rtb_B_20_892_0 * rtb_B_20_1339_0 [ 1
] ; _rtB -> B_20_600_0 [ 1 ] = rtb_B_20_892_0 * rtb_B_20_1339_0 [ 0 ] -
rtb_B_20_1077_0 * rtb_B_20_1339_0 [ 2 ] ; _rtB -> B_20_600_0 [ 2 ] =
rtb_B_20_1077_0 * rtb_B_20_1339_0 [ 1 ] - rtb_B_20_57_0 * rtb_B_20_1339_0 [ 0
] ; _rtB -> B_20_601_0 = ( _rtB -> B_20_600_0 [ 0 ] + _rtB -> B_20_600_0 [ 4
] ) + _rtB -> B_20_600_0 [ 8 ] ; rtPrevAction = _rtDW -> If_ActiveSubsystem_f
; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB -> B_20_601_0 > 0.0 ) { rtAction
= 0 ; } else { rtAction = 1 ; } _rtDW -> If_ActiveSubsystem_f = rtAction ; }
else { rtAction = _rtDW -> If_ActiveSubsystem_f ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 :
ACStesbed1_PositiveTrace_Disable ( S ) ; break ; case 1 :
ACStesbed1_NegativeTrace_Disable ( S , & _rtDW -> NegativeTrace_f ) ; break ;
} } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) {
ACStesbed1_PositiveTrace_Enable ( S ) ; } ACStesbed1_PositiveTrace ( S , _rtB
-> B_20_601_0 , _rtB -> B_20_600_0 [ 5 ] , _rtB -> B_20_600_0 [ 7 ] , _rtB ->
B_20_600_0 [ 2 ] , _rtB -> B_20_600_0 [ 6 ] , _rtB -> B_20_600_0 [ 1 ] , _rtB
-> B_20_600_0 [ 3 ] , & _rtB -> B_20_605_0 [ 0 ] , & _rtB -> B_20_605_0 [ 1 ]
, & _rtB -> PositiveTrace_p , & _rtDW -> PositiveTrace_p , (
P_PositiveTrace_ACStesbed1_T * ) & _rtP -> PositiveTrace_p ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> PositiveTrace_p .
PositiveTrace_SubsysRanBC ) ; } break ; case 1 : if ( rtAction !=
rtPrevAction ) { ACStesbed1_NegativeTrace_Enable ( S ) ; }
ACStesbed1_NegativeTrace ( S , _rtB -> B_20_600_0 [ 0 ] , _rtB -> B_20_600_0
[ 4 ] , _rtB -> B_20_600_0 [ 8 ] , _rtB -> B_20_600_0 [ 1 ] , _rtB ->
B_20_600_0 [ 3 ] , _rtB -> B_20_600_0 [ 5 ] , _rtB -> B_20_600_0 [ 7 ] , _rtB
-> B_20_600_0 [ 2 ] , _rtB -> B_20_600_0 [ 6 ] , & _rtB -> B_20_605_0 [ 0 ] ,
& _rtB -> B_20_605_0 [ 1 ] , & _rtB -> B_20_605_0 [ 2 ] , & _rtB ->
B_20_605_0 [ 3 ] , & _rtB -> NegativeTrace_f , & _rtDW -> NegativeTrace_f , (
P_NegativeTrace_ACStesbed1_T * ) & _rtP -> NegativeTrace_f ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> NegativeTrace_f .
NegativeTrace_SubsysRanBC ) ; } break ; } rtb_B_20_1060_0 = - _rtB ->
B_20_605_0 [ 1 ] ; rtb_B_20_1077_0 = - _rtB -> B_20_605_0 [ 2 ] ;
rtb_B_20_57_0 = - _rtB -> B_20_605_0 [ 3 ] ; _rtB -> B_20_612_0 [ 0 ] = ( (
_rtB -> B_20_996_0 [ 1 ] * _rtB -> B_20_854_0 [ 2 ] - _rtB -> B_20_996_0 [ 2
] * _rtB -> B_20_854_0 [ 1 ] ) + _rtB -> B_20_294_0 [ 0 ] ) * _rtP -> P_166 ;
_rtB -> B_20_612_0 [ 1 ] = ( ( _rtB -> B_20_996_0 [ 2 ] * _rtB -> B_20_854_0
[ 0 ] - _rtB -> B_20_996_0 [ 0 ] * _rtB -> B_20_854_0 [ 2 ] ) + _rtB ->
B_20_294_0 [ 1 ] ) * _rtP -> P_166 ; _rtB -> B_20_612_0 [ 2 ] = ( ( _rtB ->
B_20_996_0 [ 0 ] * _rtB -> B_20_854_0 [ 1 ] - _rtB -> B_20_996_0 [ 1 ] * _rtB
-> B_20_854_0 [ 0 ] ) + _rtB -> B_20_294_0 [ 2 ] ) * _rtP -> P_166 ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> Saturation_MODE_a [ 0 ] = _rtB ->
B_20_612_0 [ 0 ] >= _rtP -> P_167 ? 1 : _rtB -> B_20_612_0 [ 0 ] > _rtP ->
P_168 ? 0 : - 1 ; _rtDW -> Saturation_MODE_a [ 1 ] = _rtB -> B_20_612_0 [ 1 ]
>= _rtP -> P_167 ? 1 : _rtB -> B_20_612_0 [ 1 ] > _rtP -> P_168 ? 0 : - 1 ;
_rtDW -> Saturation_MODE_a [ 2 ] = _rtB -> B_20_612_0 [ 2 ] >= _rtP -> P_167
? 1 : _rtB -> B_20_612_0 [ 2 ] > _rtP -> P_168 ? 0 : - 1 ; } _rtB ->
B_20_1333_0 [ 0 ] = _rtDW -> Saturation_MODE_a [ 0 ] == 1 ? _rtP -> P_167 :
_rtDW -> Saturation_MODE_a [ 0 ] == - 1 ? _rtP -> P_168 : _rtB -> B_20_612_0
[ 0 ] ; _rtB -> B_20_1333_0 [ 1 ] = _rtDW -> Saturation_MODE_a [ 1 ] == 1 ?
_rtP -> P_167 : _rtDW -> Saturation_MODE_a [ 1 ] == - 1 ? _rtP -> P_168 :
_rtB -> B_20_612_0 [ 1 ] ; _rtB -> B_20_1333_0 [ 2 ] = _rtDW ->
Saturation_MODE_a [ 2 ] == 1 ? _rtP -> P_167 : _rtDW -> Saturation_MODE_a [ 2
] == - 1 ? _rtP -> P_168 : _rtB -> B_20_612_0 [ 2 ] ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> B_20_614_0 [ 0 ] = _rtP -> P_169 [ 0 ] ; _rtB ->
B_20_614_0 [ 1 ] = _rtP -> P_169 [ 1 ] ; _rtB -> B_20_614_0 [ 2 ] = _rtP ->
P_169 [ 2 ] ; } rtb_B_20_897_0 = ( ( _rtB -> B_20_605_0 [ 0 ] * _rtB ->
B_20_605_0 [ 0 ] + rtb_B_20_1060_0 * rtb_B_20_1060_0 ) + rtb_B_20_1077_0 *
rtb_B_20_1077_0 ) + rtb_B_20_57_0 * rtb_B_20_57_0 ; rtb_B_20_892_0 = _rtB ->
B_20_605_0 [ 0 ] / rtb_B_20_897_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> B_20_621_0 [ 0 ] = _rtP -> P_170 [ 0 ] ; _rtB -> B_20_621_0 [ 1 ] = _rtP
-> P_170 [ 1 ] ; _rtB -> B_20_621_0 [ 2 ] = _rtP -> P_170 [ 2 ] ; _rtB ->
B_20_621_0 [ 3 ] = _rtP -> P_170 [ 3 ] ; } if ( _rtDW -> q0q1q2q3_IWORK_p .
IcNeedsLoading ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE_i [ 0 ] = _rtB -> B_20_621_0 [ 0 ] ; ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_i [ 1 ] = _rtB -> B_20_621_0 [ 1 ]
; ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_i [ 2 ] =
_rtB -> B_20_621_0 [ 2 ] ; ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE_i [ 3 ] = _rtB -> B_20_621_0 [ 3 ] ; } B_20_622_0 [ 0 ] = ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_i [ 0 ] ;
B_20_622_0 [ 1 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE_i [ 1 ] ; B_20_622_0 [ 2 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_i [ 2 ] ; B_20_622_0 [ 3 ] = ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_i [ 3 ] ;
rtb_B_20_37_0 = - rtb_B_20_1060_0 / rtb_B_20_897_0 ; rtb_B_20_755_0 = -
rtb_B_20_1077_0 / rtb_B_20_897_0 ; rtb_B_20_897_0 = - rtb_B_20_57_0 /
rtb_B_20_897_0 ; _rtB -> B_20_633_0 = ( ( rtb_B_20_892_0 * B_20_622_0 [ 0 ] -
rtb_B_20_37_0 * B_20_622_0 [ 1 ] ) - rtb_B_20_755_0 * B_20_622_0 [ 2 ] ) -
rtb_B_20_897_0 * B_20_622_0 [ 3 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { if ( _rtB -> B_20_633_0 > 0.0 ) { _rtDW ->
Sign_MODE = 1 ; } else if ( _rtB -> B_20_633_0 < 0.0 ) { _rtDW -> Sign_MODE =
- 1 ; } else { _rtDW -> Sign_MODE = 0 ; } } _rtB -> B_20_634_0 = _rtDW ->
Sign_MODE ; } B_20_43_0_idx = _rtB -> B_20_634_0 * _rtB -> B_20_633_0 ;
B_20_43_0_idx_1 = ( ( ( rtb_B_20_892_0 * B_20_622_0 [ 1 ] + rtb_B_20_37_0 *
B_20_622_0 [ 0 ] ) + rtb_B_20_755_0 * B_20_622_0 [ 3 ] ) - rtb_B_20_897_0 *
B_20_622_0 [ 2 ] ) * _rtB -> B_20_634_0 ; B_20_43_0_idx_2 = ( ( (
rtb_B_20_892_0 * B_20_622_0 [ 2 ] - rtb_B_20_37_0 * B_20_622_0 [ 3 ] ) +
rtb_B_20_755_0 * B_20_622_0 [ 0 ] ) + rtb_B_20_897_0 * B_20_622_0 [ 1 ] ) *
_rtB -> B_20_634_0 ; B_20_43_0_idx_0 = ( ( ( rtb_B_20_892_0 * B_20_622_0 [ 3
] + rtb_B_20_37_0 * B_20_622_0 [ 2 ] ) - rtb_B_20_755_0 * B_20_622_0 [ 1 ] )
+ rtb_B_20_897_0 * B_20_622_0 [ 0 ] ) * _rtB -> B_20_634_0 ; rtb_B_20_468_0 =
( ( B_20_43_0_idx * B_20_43_0_idx + B_20_43_0_idx_1 * B_20_43_0_idx_1 ) +
B_20_43_0_idx_2 * B_20_43_0_idx_2 ) + B_20_43_0_idx_0 * B_20_43_0_idx_0 ; if
( ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_d != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_d = 0 ; } rtb_B_20_468_0 =
muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; } else { if ( rtb_B_20_468_0 < 0.0 )
{ rtb_B_20_468_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_468_0
) ) ; } else { rtb_B_20_468_0 = muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; }
_rtDW -> sqrt_DWORK1_d = 1 ; } rtb_B_20_37_0 = B_20_43_0_idx_2 /
rtb_B_20_468_0 ; rtb_B_20_755_0 = B_20_43_0_idx_0 / rtb_B_20_468_0 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_661_0 = _rtP -> P_171 ; }
rtb_B_20_897_0 = B_20_43_0_idx_1 / rtb_B_20_468_0 ; rtb_B_20_468_0 =
B_20_43_0_idx / rtb_B_20_468_0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_685_0 = _rtP -> P_176 ; _rtB -> B_20_707_0 = _rtP -> P_181 ; _rtB ->
B_20_830_0 [ 0 ] = _rtP -> P_185 [ 0 ] * _rtB -> B_20_206_0 [ 0 ] * _rtP ->
P_186 ; _rtB -> B_20_830_0 [ 1 ] = _rtP -> P_185 [ 1 ] * _rtB -> B_20_206_0 [
0 ] * _rtP -> P_186 ; _rtB -> B_20_830_0 [ 2 ] = _rtP -> P_185 [ 2 ] * _rtB
-> B_20_206_0 [ 0 ] * _rtP -> P_186 ; _rtB -> B_20_719_0 [ 0 ] = _rtP ->
P_187 [ 0 ] * _rtB -> B_20_206_0 [ 1 ] * _rtP -> P_188 ; _rtB -> B_20_719_0 [
1 ] = _rtP -> P_187 [ 1 ] * _rtB -> B_20_206_0 [ 1 ] * _rtP -> P_188 ; _rtB
-> B_20_719_0 [ 2 ] = _rtP -> P_187 [ 2 ] * _rtB -> B_20_206_0 [ 1 ] * _rtP
-> P_188 ; _rtB -> B_20_722_0 [ 0 ] = _rtP -> P_189 [ 0 ] * _rtB ->
B_20_206_0 [ 2 ] * _rtP -> P_190 ; _rtB -> B_20_722_0 [ 1 ] = _rtP -> P_189 [
1 ] * _rtB -> B_20_206_0 [ 2 ] * _rtP -> P_190 ; _rtB -> B_20_722_0 [ 2 ] =
_rtP -> P_189 [ 2 ] * _rtB -> B_20_206_0 [ 2 ] * _rtP -> P_190 ; _rtB ->
B_20_723_0 [ 0 ] = ( ( _rtP -> P_184 * _rtP -> P_183 [ 0 ] + _rtB ->
B_20_830_0 [ 0 ] ) + _rtB -> B_20_719_0 [ 0 ] ) + _rtB -> B_20_722_0 [ 0 ] ;
_rtB -> B_20_723_0 [ 1 ] = ( ( _rtP -> P_184 * _rtP -> P_183 [ 1 ] + _rtB ->
B_20_830_0 [ 1 ] ) + _rtB -> B_20_719_0 [ 1 ] ) + _rtB -> B_20_722_0 [ 1 ] ;
_rtB -> B_20_723_0 [ 2 ] = ( ( _rtP -> P_184 * _rtP -> P_183 [ 2 ] + _rtB ->
B_20_830_0 [ 2 ] ) + _rtB -> B_20_719_0 [ 2 ] ) + _rtB -> B_20_722_0 [ 2 ] ;
} rtb_B_20_1339_0 [ 0 ] = ( ( ( ( _rtB -> B_20_661_0 - rtb_B_20_37_0 *
rtb_B_20_37_0 ) - rtb_B_20_755_0 * rtb_B_20_755_0 ) * _rtP -> P_172 * _rtB ->
B_20_614_0 [ 0 ] + ( rtb_B_20_897_0 * rtb_B_20_37_0 + rtb_B_20_468_0 *
rtb_B_20_755_0 ) * _rtP -> P_173 * _rtB -> B_20_614_0 [ 1 ] ) + (
rtb_B_20_897_0 * rtb_B_20_755_0 - rtb_B_20_468_0 * rtb_B_20_37_0 ) * _rtP ->
P_174 * _rtB -> B_20_614_0 [ 2 ] ) * _rtB -> B_20_723_0 [ 0 ] ;
rtb_B_20_1339_0 [ 1 ] = ( ( ( ( _rtB -> B_20_685_0 - rtb_B_20_897_0 *
rtb_B_20_897_0 ) - rtb_B_20_755_0 * rtb_B_20_755_0 ) * _rtP -> P_177 * _rtB
-> B_20_614_0 [ 1 ] + ( rtb_B_20_897_0 * rtb_B_20_37_0 - rtb_B_20_468_0 *
rtb_B_20_755_0 ) * _rtP -> P_175 * _rtB -> B_20_614_0 [ 0 ] ) + (
rtb_B_20_468_0 * rtb_B_20_897_0 + rtb_B_20_37_0 * rtb_B_20_755_0 ) * _rtP ->
P_178 * _rtB -> B_20_614_0 [ 2 ] ) * _rtB -> B_20_723_0 [ 1 ] ;
rtb_B_20_1339_0 [ 2 ] = ( ( ( rtb_B_20_897_0 * rtb_B_20_755_0 +
rtb_B_20_468_0 * rtb_B_20_37_0 ) * _rtP -> P_179 * _rtB -> B_20_614_0 [ 0 ] +
( rtb_B_20_37_0 * rtb_B_20_755_0 - rtb_B_20_468_0 * rtb_B_20_897_0 ) * _rtP
-> P_180 * _rtB -> B_20_614_0 [ 1 ] ) + ( ( _rtB -> B_20_707_0 -
rtb_B_20_897_0 * rtb_B_20_897_0 ) - rtb_B_20_37_0 * rtb_B_20_37_0 ) * _rtP ->
P_182 * _rtB -> B_20_614_0 [ 2 ] ) * _rtB -> B_20_723_0 [ 2 ] ; _rtB ->
B_20_843_0 [ 0 ] = _rtP -> P_191 * rtb_B_20_1339_0 [ 0 ] ; _rtB -> B_20_843_0
[ 1 ] = _rtP -> P_191 * rtb_B_20_1339_0 [ 1 ] ; _rtB -> B_20_843_0 [ 2 ] =
_rtP -> P_191 * rtb_B_20_1339_0 [ 2 ] ; _rtB -> B_20_852_0 [ 0 ] = ( ( _rtB
-> B_20_1333_0 [ 0 ] + _rtB -> B_20_843_0 [ 0 ] ) + 0.0 ) + 0.0 ; _rtB ->
B_20_852_0 [ 1 ] = ( ( _rtB -> B_20_1333_0 [ 1 ] + _rtB -> B_20_843_0 [ 1 ] )
+ 0.0 ) + 0.0 ; _rtB -> B_20_852_0 [ 2 ] = ( ( _rtB -> B_20_1333_0 [ 2 ] +
_rtB -> B_20_843_0 [ 2 ] ) + 0.0 ) + 0.0 ; ssCallAccelRunBlock ( S , 20 , 727
, SS_CALL_MDL_OUTPUTS ) ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) {
rtb_B_20_1339_0 [ i_0 ] = _rtB -> B_20_578_0 [ i_0 + 6 ] * _rtB -> B_20_996_0
[ 2 ] + ( _rtB -> B_20_578_0 [ i_0 + 3 ] * _rtB -> B_20_996_0 [ 1 ] + _rtB ->
B_20_578_0 [ i_0 ] * _rtB -> B_20_996_0 [ 0 ] ) ; } rtb_B_20_21_0 [ 0 ] =
_rtB -> B_20_996_0 [ 1 ] * rtb_B_20_1339_0 [ 2 ] ; rtb_B_20_21_0 [ 1 ] = _rtB
-> B_20_996_0 [ 2 ] * rtb_B_20_1339_0 [ 0 ] ; rtb_B_20_21_0 [ 2 ] = _rtB ->
B_20_996_0 [ 0 ] * rtb_B_20_1339_0 [ 1 ] ; rtb_B_20_21_0 [ 3 ] = _rtB ->
B_20_996_0 [ 2 ] * rtb_B_20_1339_0 [ 1 ] ; rtb_B_20_21_0 [ 4 ] = _rtB ->
B_20_996_0 [ 0 ] * rtb_B_20_1339_0 [ 2 ] ; rtb_B_20_21_0 [ 5 ] = _rtB ->
B_20_996_0 [ 1 ] * rtb_B_20_1339_0 [ 0 ] ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ )
{ rtb_B_20_1339_0 [ i_0 ] = _rtB -> B_20_579_0 [ i_0 + 6 ] * _rtB ->
B_20_996_0 [ 2 ] + ( _rtB -> B_20_579_0 [ i_0 + 3 ] * _rtB -> B_20_996_0 [ 1
] + _rtB -> B_20_579_0 [ i_0 ] * _rtB -> B_20_996_0 [ 0 ] ) ; }
rtb_B_20_1339_0 [ 0 ] = ( _rtB -> B_20_852_0 [ 0 ] - rtb_B_20_1339_0 [ 0 ] )
- ( rtb_B_20_21_0 [ 0 ] - rtb_B_20_21_0 [ 3 ] ) ; rtb_B_20_1339_0 [ 1 ] = (
_rtB -> B_20_852_0 [ 1 ] - rtb_B_20_1339_0 [ 1 ] ) - ( rtb_B_20_21_0 [ 1 ] -
rtb_B_20_21_0 [ 4 ] ) ; rtb_B_20_1339_0 [ 2 ] = ( _rtB -> B_20_852_0 [ 2 ] -
rtb_B_20_1339_0 [ 2 ] ) - ( rtb_B_20_21_0 [ 2 ] - rtb_B_20_21_0 [ 5 ] ) ;
rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( _rtB -> B_20_578_0 , rtb_B_20_1339_0 ,
_rtB -> B_20_733_0 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_734_0 = _rtP -> P_192 ; } rtb_B_20_468_0 = ( _rtB -> B_20_734_0 - ( ( (
B_20_622_0 [ 0 ] * B_20_622_0 [ 0 ] + B_20_622_0 [ 1 ] * B_20_622_0 [ 1 ] ) +
B_20_622_0 [ 2 ] * B_20_622_0 [ 2 ] ) + B_20_622_0 [ 3 ] * B_20_622_0 [ 3 ] )
) * _rtP -> P_193 ; _rtB -> B_20_738_0 = ( ( B_20_622_0 [ 1 ] * _rtB ->
B_20_996_0 [ 0 ] + B_20_622_0 [ 2 ] * _rtB -> B_20_996_0 [ 1 ] ) + B_20_622_0
[ 3 ] * _rtB -> B_20_996_0 [ 2 ] ) * - 0.5 + rtb_B_20_468_0 * B_20_622_0 [ 0
] ; _rtB -> B_20_739_0 = ( ( B_20_622_0 [ 0 ] * _rtB -> B_20_996_0 [ 0 ] +
B_20_622_0 [ 2 ] * _rtB -> B_20_996_0 [ 2 ] ) - B_20_622_0 [ 3 ] * _rtB ->
B_20_996_0 [ 1 ] ) * 0.5 + rtb_B_20_468_0 * B_20_622_0 [ 1 ] ; _rtB ->
B_20_740_0 = ( ( B_20_622_0 [ 0 ] * _rtB -> B_20_996_0 [ 1 ] + B_20_622_0 [ 3
] * _rtB -> B_20_996_0 [ 0 ] ) - B_20_622_0 [ 1 ] * _rtB -> B_20_996_0 [ 2 ]
) * 0.5 + rtb_B_20_468_0 * B_20_622_0 [ 2 ] ; _rtB -> B_20_741_0 = ( (
B_20_622_0 [ 0 ] * _rtB -> B_20_996_0 [ 2 ] + B_20_622_0 [ 1 ] * _rtB ->
B_20_996_0 [ 1 ] ) - B_20_622_0 [ 2 ] * _rtB -> B_20_996_0 [ 0 ] ) * 0.5 +
rtb_B_20_468_0 * B_20_622_0 [ 3 ] ; ssCallAccelRunBlock ( S , 20 , 742 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_20_928_0 [ 0 ] = _rtB -> B_20_605_0 [ 0 ] ;
_rtB -> B_20_928_0 [ 1 ] = rtb_B_20_1060_0 ; _rtB -> B_20_928_0 [ 2 ] =
rtb_B_20_1077_0 ; _rtB -> B_20_928_0 [ 3 ] = rtb_B_20_57_0 ;
ssCallAccelRunBlock ( S , 20 , 744 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 745 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 746 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 747 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 20 , 748 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 749 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 750 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 751 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_20_752_0 [ 0 ] = _rtP -> P_194 * _rtB ->
B_20_723_0 [ 0 ] ; _rtB -> B_20_752_0 [ 1 ] = _rtP -> P_194 * _rtB ->
B_20_723_0 [ 1 ] ; _rtB -> B_20_752_0 [ 2 ] = _rtP -> P_194 * _rtB ->
B_20_723_0 [ 2 ] ; } ssCallAccelRunBlock ( S , 20 , 753 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 20 , 754 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_20_756_0 [ 0 ] = _rtP -> P_198 [ 0
] * _rtDW -> NextOutput_d ; _rtB -> B_20_756_0 [ 1 ] = _rtP -> P_198 [ 1 ] *
_rtDW -> NextOutput_d ; _rtB -> B_20_756_0 [ 2 ] = _rtP -> P_198 [ 2 ] *
_rtDW -> NextOutput_d ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_758_0 = _rtP -> P_200 ; } rtb_B_20_1339_0 [ 0 ] = _rtP -> P_199 *
B_20_7_3_idx - B_20_7_0_idx ; rtb_B_20_1339_0 [ 1 ] = _rtP -> P_199 *
B_20_7_3_idx_0 - B_20_7_0_idx_0 ; rtb_B_20_1339_0 [ 2 ] = _rtP -> P_199 *
B_20_7_3_idx_1 - B_20_7_0_idx_1 ; rtb_B_20_468_0 = ( ( B_20_622_0 [ 0 ] *
B_20_622_0 [ 0 ] + B_20_622_0 [ 1 ] * B_20_622_0 [ 1 ] ) + B_20_622_0 [ 2 ] *
B_20_622_0 [ 2 ] ) + B_20_622_0 [ 3 ] * B_20_622_0 [ 3 ] ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_l != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_l = 0 ; } rtb_B_20_468_0 =
muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; } else { if ( rtb_B_20_468_0 < 0.0 )
{ rtb_B_20_468_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_468_0
) ) ; } else { rtb_B_20_468_0 = muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; }
_rtDW -> sqrt_DWORK1_l = 1 ; } rtb_B_20_37_0 = B_20_622_0 [ 2 ] /
rtb_B_20_468_0 ; rtb_B_20_755_0 = B_20_622_0 [ 3 ] / rtb_B_20_468_0 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_770_0 = _rtP -> P_201 ; }
rtb_B_20_1060_0 = B_20_622_0 [ 1 ] / rtb_B_20_468_0 ; rtb_B_20_468_0 =
B_20_622_0 [ 0 ] / rtb_B_20_468_0 ; _rtB -> B_20_786_0 = ( ( ( _rtB ->
B_20_770_0 - rtb_B_20_37_0 * rtb_B_20_37_0 ) - rtb_B_20_755_0 *
rtb_B_20_755_0 ) * _rtP -> P_202 * rtb_B_20_1339_0 [ 0 ] + ( rtb_B_20_1060_0
* rtb_B_20_37_0 + rtb_B_20_468_0 * rtb_B_20_755_0 ) * _rtP -> P_203 *
rtb_B_20_1339_0 [ 1 ] ) + ( rtb_B_20_1060_0 * rtb_B_20_755_0 - rtb_B_20_468_0
* rtb_B_20_37_0 ) * _rtP -> P_204 * rtb_B_20_1339_0 [ 2 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_794_0 = _rtP -> P_206 ; } _rtB
-> B_20_803_0 = ( ( ( _rtB -> B_20_794_0 - rtb_B_20_1060_0 * rtb_B_20_1060_0
) - rtb_B_20_755_0 * rtb_B_20_755_0 ) * _rtP -> P_207 * rtb_B_20_1339_0 [ 1 ]
+ ( rtb_B_20_1060_0 * rtb_B_20_37_0 - rtb_B_20_468_0 * rtb_B_20_755_0 ) *
_rtP -> P_205 * rtb_B_20_1339_0 [ 0 ] ) + ( rtb_B_20_468_0 * rtb_B_20_1060_0
+ rtb_B_20_37_0 * rtb_B_20_755_0 ) * _rtP -> P_208 * rtb_B_20_1339_0 [ 2 ] ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_816_0 = _rtP -> P_211 ; }
_rtB -> B_20_820_0 = ( ( rtb_B_20_1060_0 * rtb_B_20_755_0 + rtb_B_20_468_0 *
rtb_B_20_37_0 ) * _rtP -> P_209 * rtb_B_20_1339_0 [ 0 ] + ( rtb_B_20_37_0 *
rtb_B_20_755_0 - rtb_B_20_468_0 * rtb_B_20_1060_0 ) * _rtP -> P_210 *
rtb_B_20_1339_0 [ 1 ] ) + ( ( _rtB -> B_20_816_0 - rtb_B_20_1060_0 *
rtb_B_20_1060_0 ) - rtb_B_20_37_0 * rtb_B_20_37_0 ) * _rtP -> P_212 *
rtb_B_20_1339_0 [ 2 ] ; rtb_B_20_1339_0 [ 0 ] = _rtB -> B_20_786_0 ;
rtb_B_20_1339_0 [ 1 ] = _rtB -> B_20_803_0 ; rtb_B_20_1339_0 [ 2 ] = _rtB ->
B_20_820_0 ; rtb_B_20_468_0 = ( rtb_B_20_1339_0 [ 0 ] * rtb_B_20_1339_0 [ 0 ]
+ rtb_B_20_1339_0 [ 1 ] * rtb_B_20_1339_0 [ 1 ] ) + rtb_B_20_1339_0 [ 2 ] *
rtb_B_20_1339_0 [ 2 ] ; if ( rtb_B_20_468_0 < 0.0 ) { _rtB -> B_20_824_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_468_0 ) ) ; } else { _rtB
-> B_20_824_0 = muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; } _rtB -> B_20_825_0
[ 0 ] = rtb_B_20_1339_0 [ 0 ] * 0.0 ; _rtB -> B_20_825_0 [ 1 ] =
rtb_B_20_1339_0 [ 1 ] * 0.0 ; _rtB -> B_20_825_0 [ 2 ] = rtb_B_20_1339_0 [ 2
] * 0.0 ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> Switch_Mode_mk = ( _rtB
-> B_20_824_0 > _rtP -> P_213 ) ; } ssCallAccelRunBlock ( S , 20 , 827 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsMajorTimeStep ( S ) ) { if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0
] >= _rtP -> P_215 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 0 ] = _rtP -> P_215 ; } else if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0
] <= _rtP -> P_216 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 0 ] = _rtP -> P_216 ; } if ( ( ( X_ACStesbed1_T
* ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 1 ] >= _rtP ->
P_215 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 1 ] = _rtP -> P_215 ; } else if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 1
] <= _rtP -> P_216 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 1 ] = _rtP -> P_216 ; } if ( ( ( X_ACStesbed1_T
* ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 2 ] >= _rtP ->
P_215 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 2 ] = _rtP -> P_215 ; } else if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 2
] <= _rtP -> P_216 ) { ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 2 ] = _rtP -> P_216 ; } } _rtB -> B_20_1333_0 [
0 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 0 ] ; _rtB -> B_20_1333_0 [ 1 ] = ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 1
] ; _rtB -> B_20_1333_0 [ 2 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S )
) -> IntegratorLimited_CSTATE_ml [ 2 ] ; ssCallAccelRunBlock ( S , 20 , 829 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_830_0 [ 0 ] = _rtP -> P_217 [ 0 ] ; _rtB -> B_20_830_0 [ 1 ] = _rtP ->
P_217 [ 1 ] ; _rtB -> B_20_830_0 [ 2 ] = _rtP -> P_217 [ 2 ] ; memcpy ( &
_rtB -> B_20_831_0 [ 0 ] , & _rtP -> P_218 [ 0 ] , 9U * sizeof ( real_T ) ) ;
_rtB -> B_20_832_0 = _rtP -> P_219 ; _rtB -> B_20_833_0 = _rtP -> P_220 ;
_rtB -> B_20_834_0 = _rtP -> P_221 ; } ssCallAccelRunBlock ( S , 20 , 835 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_20_836_0 [ 0 ] = _rtB -> B_20_835_0 . j2000
[ 0 ] ; _rtB -> B_20_836_0 [ 1 ] = _rtB -> B_20_835_0 . j2000 [ 1 ] ; _rtB ->
B_20_836_0 [ 2 ] = _rtB -> B_20_835_0 . j2000 [ 2 ] ; rtb_B_20_1339_0 [ 0 ] =
_rtB -> B_20_835_0 . vj2000 [ 0 ] ; rtb_B_20_1339_0 [ 1 ] = _rtB ->
B_20_835_0 . vj2000 [ 1 ] ; rtb_B_20_1339_0 [ 2 ] = _rtB -> B_20_835_0 .
vj2000 [ 2 ] ; rtb_B_20_468_0 = ( _rtB -> B_20_836_0 [ 0 ] * _rtB ->
B_20_836_0 [ 0 ] + _rtB -> B_20_836_0 [ 1 ] * _rtB -> B_20_836_0 [ 1 ] ) +
_rtB -> B_20_836_0 [ 2 ] * _rtB -> B_20_836_0 [ 2 ] ; if ( rtb_B_20_468_0 <
0.0 ) { _rtB -> B_20_839_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
rtb_B_20_468_0 ) ) ; } else { _rtB -> B_20_839_0 = muDoubleScalarSqrt (
rtb_B_20_468_0 ) ; } _rtB -> B_20_840_0 [ 0 ] = _rtB -> B_20_836_0 [ 0 ] *
0.0 ; _rtB -> B_20_840_0 [ 1 ] = _rtB -> B_20_836_0 [ 1 ] * 0.0 ; _rtB ->
B_20_840_0 [ 2 ] = _rtB -> B_20_836_0 [ 2 ] * 0.0 ; if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> B_20_841_0 = _rtP -> P_222 ; } if ( ssIsMajorTimeStep ( S
) ) { _rtDW -> Switch_Mode_h = ( _rtB -> B_20_839_0 > _rtP -> P_223 ) ; } if
( _rtDW -> Switch_Mode_h ) { B_20_43_0_idx = _rtB -> B_20_836_0 [ 0 ] ;
B_20_43_0_idx_1 = _rtB -> B_20_836_0 [ 1 ] ; B_20_43_0_idx_2 = _rtB ->
B_20_836_0 [ 2 ] ; } else { B_20_43_0_idx = _rtB -> B_20_840_0 [ 0 ] ;
B_20_43_0_idx_1 = _rtB -> B_20_840_0 [ 1 ] ; B_20_43_0_idx_2 = _rtB ->
B_20_840_0 [ 2 ] ; } if ( _rtDW -> Switch_Mode_h ) { B_20_43_0_idx_0 = _rtB
-> B_20_839_0 ; } else { B_20_43_0_idx_0 = _rtB -> B_20_841_0 ; } _rtB ->
B_20_843_0 [ 0 ] = B_20_43_0_idx / B_20_43_0_idx_0 ; _rtB -> B_20_843_0 [ 1 ]
= B_20_43_0_idx_1 / B_20_43_0_idx_0 ; _rtB -> B_20_843_0 [ 2 ] =
B_20_43_0_idx_2 / B_20_43_0_idx_0 ; _rtB -> B_20_845_0 [ 0 ] =
rtb_B_20_1339_0 [ 1 ] * _rtB -> B_20_836_0 [ 2 ] - rtb_B_20_1339_0 [ 2 ] *
_rtB -> B_20_836_0 [ 1 ] ; _rtB -> B_20_845_0 [ 1 ] = rtb_B_20_1339_0 [ 2 ] *
_rtB -> B_20_836_0 [ 0 ] - rtb_B_20_1339_0 [ 0 ] * _rtB -> B_20_836_0 [ 2 ] ;
_rtB -> B_20_845_0 [ 2 ] = rtb_B_20_1339_0 [ 0 ] * _rtB -> B_20_836_0 [ 1 ] -
rtb_B_20_1339_0 [ 1 ] * _rtB -> B_20_836_0 [ 0 ] ; rtb_B_20_468_0 = ( _rtB ->
B_20_845_0 [ 0 ] * _rtB -> B_20_845_0 [ 0 ] + _rtB -> B_20_845_0 [ 1 ] * _rtB
-> B_20_845_0 [ 1 ] ) + _rtB -> B_20_845_0 [ 2 ] * _rtB -> B_20_845_0 [ 2 ] ;
if ( rtb_B_20_468_0 < 0.0 ) { _rtB -> B_20_848_0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtb_B_20_468_0 ) ) ; } else { _rtB -> B_20_848_0 =
muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; } _rtB -> B_20_849_0 [ 0 ] = _rtB ->
B_20_845_0 [ 0 ] * 0.0 ; _rtB -> B_20_849_0 [ 1 ] = _rtB -> B_20_845_0 [ 1 ]
* 0.0 ; _rtB -> B_20_849_0 [ 2 ] = _rtB -> B_20_845_0 [ 2 ] * 0.0 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_850_0 = _rtP -> P_224 ; } if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> Switch_Mode_e = ( _rtB -> B_20_848_0 >
_rtP -> P_225 ) ; } if ( _rtDW -> Switch_Mode_e ) { B_20_43_0_idx = _rtB ->
B_20_845_0 [ 0 ] ; B_20_43_0_idx_1 = _rtB -> B_20_845_0 [ 1 ] ;
B_20_43_0_idx_2 = _rtB -> B_20_845_0 [ 2 ] ; } else { B_20_43_0_idx = _rtB ->
B_20_849_0 [ 0 ] ; B_20_43_0_idx_1 = _rtB -> B_20_849_0 [ 1 ] ;
B_20_43_0_idx_2 = _rtB -> B_20_849_0 [ 2 ] ; } if ( _rtDW -> Switch_Mode_e )
{ B_20_43_0_idx_0 = _rtB -> B_20_848_0 ; } else { B_20_43_0_idx_0 = _rtB ->
B_20_850_0 ; } _rtB -> B_20_852_0 [ 0 ] = B_20_43_0_idx / B_20_43_0_idx_0 ;
_rtB -> B_20_852_0 [ 1 ] = B_20_43_0_idx_1 / B_20_43_0_idx_0 ; _rtB ->
B_20_852_0 [ 2 ] = B_20_43_0_idx_2 / B_20_43_0_idx_0 ; _rtB -> B_20_854_0 [ 0
] = _rtB -> B_20_843_0 [ 1 ] * _rtB -> B_20_852_0 [ 2 ] - _rtB -> B_20_843_0
[ 2 ] * _rtB -> B_20_852_0 [ 1 ] ; _rtB -> B_20_854_0 [ 1 ] = _rtB ->
B_20_843_0 [ 2 ] * _rtB -> B_20_852_0 [ 0 ] - _rtB -> B_20_843_0 [ 0 ] * _rtB
-> B_20_852_0 [ 2 ] ; _rtB -> B_20_854_0 [ 2 ] = _rtB -> B_20_843_0 [ 0 ] *
_rtB -> B_20_852_0 [ 1 ] - _rtB -> B_20_843_0 [ 1 ] * _rtB -> B_20_852_0 [ 0
] ; rtb_B_20_574_0 [ 0 ] = _rtB -> B_20_854_0 [ 0 ] ; rtb_B_20_574_0 [ 1 ] =
_rtB -> B_20_854_0 [ 1 ] ; rtb_B_20_574_0 [ 2 ] = _rtB -> B_20_854_0 [ 2 ] ;
rtb_B_20_574_0 [ 3 ] = _rtB -> B_20_843_0 [ 0 ] ; rtb_B_20_574_0 [ 4 ] = _rtB
-> B_20_843_0 [ 1 ] ; rtb_B_20_574_0 [ 5 ] = _rtB -> B_20_843_0 [ 2 ] ;
rtb_B_20_574_0 [ 6 ] = _rtB -> B_20_852_0 [ 0 ] ; rtb_B_20_574_0 [ 7 ] = _rtB
-> B_20_852_0 [ 1 ] ; rtb_B_20_574_0 [ 8 ] = _rtB -> B_20_852_0 [ 2 ] ; for (
i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB -> B_20_859_0 [ 3 * i_0 ] =
rtb_B_20_574_0 [ i_0 ] ; _rtB -> B_20_859_0 [ 1 + 3 * i_0 ] = rtb_B_20_574_0
[ i_0 + 3 ] ; _rtB -> B_20_859_0 [ 2 + 3 * i_0 ] = rtb_B_20_574_0 [ i_0 + 6 ]
; } _rtB -> B_20_860_0 = ( _rtB -> B_20_859_0 [ 0 ] + _rtB -> B_20_859_0 [ 4
] ) + _rtB -> B_20_859_0 [ 8 ] ; rtPrevAction = _rtDW -> If_ActiveSubsystem_o
; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB -> B_20_860_0 > 0.0 ) { rtAction
= 0 ; } else { rtAction = 1 ; } _rtDW -> If_ActiveSubsystem_o = rtAction ; }
else { rtAction = _rtDW -> If_ActiveSubsystem_o ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 :
ACStesbed1_PositiveTrace_Disable ( S ) ; break ; case 1 :
ACStesbed1_NegativeTrace_Disable ( S , & _rtDW -> NegativeTrace_g ) ; break ;
} } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) {
ACStesbed1_PositiveTrace_Enable ( S ) ; } ACStesbed1_PositiveTrace ( S , _rtB
-> B_20_860_0 , _rtB -> B_20_859_0 [ 5 ] , _rtB -> B_20_859_0 [ 7 ] , _rtB ->
B_20_859_0 [ 2 ] , _rtB -> B_20_859_0 [ 6 ] , _rtB -> B_20_859_0 [ 1 ] , _rtB
-> B_20_859_0 [ 3 ] , & _rtB -> B_20_864_0 [ 0 ] , & _rtB -> B_20_864_0 [ 1 ]
, & _rtB -> PositiveTrace_e , & _rtDW -> PositiveTrace_e , (
P_PositiveTrace_ACStesbed1_T * ) & _rtP -> PositiveTrace_e ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> PositiveTrace_e .
PositiveTrace_SubsysRanBC ) ; } break ; case 1 : if ( rtAction !=
rtPrevAction ) { ACStesbed1_NegativeTrace_Enable ( S ) ; }
ACStesbed1_NegativeTrace ( S , _rtB -> B_20_859_0 [ 0 ] , _rtB -> B_20_859_0
[ 4 ] , _rtB -> B_20_859_0 [ 8 ] , _rtB -> B_20_859_0 [ 1 ] , _rtB ->
B_20_859_0 [ 3 ] , _rtB -> B_20_859_0 [ 5 ] , _rtB -> B_20_859_0 [ 7 ] , _rtB
-> B_20_859_0 [ 2 ] , _rtB -> B_20_859_0 [ 6 ] , & _rtB -> B_20_864_0 [ 0 ] ,
& _rtB -> B_20_864_0 [ 1 ] , & _rtB -> B_20_864_0 [ 2 ] , & _rtB ->
B_20_864_0 [ 3 ] , & _rtB -> NegativeTrace_g , & _rtDW -> NegativeTrace_g , (
P_NegativeTrace_ACStesbed1_T * ) & _rtP -> NegativeTrace_g ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> NegativeTrace_g .
NegativeTrace_SubsysRanBC ) ; } break ; } if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> Switch_Mode_i = ( _rtB -> B_20_864_0 [ 0 ] >= _rtP -> P_227 ) ; } if
( _rtDW -> Switch_Mode_i ) { rtb_B_20_468_0 = _rtB -> B_20_833_0 ; } else {
rtb_B_20_468_0 = _rtB -> B_20_834_0 ; } B_20_43_0_idx = rtb_B_20_468_0 * _rtB
-> B_20_864_0 [ 0 ] ; B_20_43_0_idx_1 = rtb_B_20_468_0 * _rtB -> B_20_864_0 [
1 ] ; B_20_43_0_idx_2 = rtb_B_20_468_0 * _rtB -> B_20_864_0 [ 2 ] ;
B_20_43_0_idx_0 = rtb_B_20_468_0 * _rtB -> B_20_864_0 [ 3 ] ; rtb_B_20_468_0
= ( ( B_20_43_0_idx * B_20_43_0_idx + B_20_43_0_idx_1 * B_20_43_0_idx_1 ) +
B_20_43_0_idx_2 * B_20_43_0_idx_2 ) + B_20_43_0_idx_0 * B_20_43_0_idx_0 ;
rtb_B_20_37_0 = B_20_43_0_idx / rtb_B_20_468_0 ; if ( ssIsSampleHit ( S , 1 ,
0 ) ) { rtb_B_20_892_0 = ( ( _rtP -> P_229 [ 0 ] * _rtP -> P_230 [ 0 ] - _rtP
-> P_229 [ 1 ] * _rtP -> P_230 [ 1 ] ) - _rtP -> P_229 [ 2 ] * _rtP -> P_230
[ 2 ] ) - _rtP -> P_229 [ 3 ] * _rtP -> P_230 [ 3 ] ; if ( rtb_B_20_892_0 >=
_rtP -> P_232 ) { rtb_B_20_1281_0 = _rtP -> P_228 ; } else { rtb_B_20_1281_0
= _rtP -> P_231 ; } _rtB -> B_20_898_0 [ 0 ] = rtb_B_20_1281_0 *
rtb_B_20_892_0 ; _rtB -> B_20_898_0 [ 1 ] = ( ( ( _rtP -> P_229 [ 0 ] * _rtP
-> P_230 [ 1 ] + _rtP -> P_229 [ 1 ] * _rtP -> P_230 [ 0 ] ) + _rtP -> P_229
[ 2 ] * _rtP -> P_230 [ 3 ] ) - _rtP -> P_229 [ 3 ] * _rtP -> P_230 [ 2 ] ) *
rtb_B_20_1281_0 ; _rtB -> B_20_898_0 [ 2 ] = ( ( ( _rtP -> P_229 [ 0 ] * _rtP
-> P_230 [ 2 ] - _rtP -> P_229 [ 1 ] * _rtP -> P_230 [ 3 ] ) + _rtP -> P_229
[ 2 ] * _rtP -> P_230 [ 0 ] ) + _rtP -> P_229 [ 3 ] * _rtP -> P_230 [ 1 ] ) *
rtb_B_20_1281_0 ; _rtB -> B_20_898_0 [ 3 ] = ( ( ( _rtP -> P_229 [ 0 ] * _rtP
-> P_230 [ 3 ] + _rtP -> P_229 [ 1 ] * _rtP -> P_230 [ 2 ] ) - _rtP -> P_229
[ 2 ] * _rtP -> P_230 [ 1 ] ) + _rtP -> P_229 [ 3 ] * _rtP -> P_230 [ 0 ] ) *
rtb_B_20_1281_0 ; } if ( _rtDW -> q0q1q2q3_IWORK_g . IcNeedsLoading ) { ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_j [ 0 ] = _rtB
-> B_20_898_0 [ 0 ] ; ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
q0q1q2q3_CSTATE_j [ 1 ] = _rtB -> B_20_898_0 [ 1 ] ; ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_j [ 2 ] = _rtB -> B_20_898_0 [ 2 ]
; ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_j [ 3 ] =
_rtB -> B_20_898_0 [ 3 ] ; } _rtB -> B_20_899_0 [ 0 ] = ( ( X_ACStesbed1_T *
) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_j [ 0 ] ; _rtB -> B_20_899_0 [ 1
] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_j [ 1 ]
; _rtB -> B_20_899_0 [ 2 ] = ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) )
-> q0q1q2q3_CSTATE_j [ 2 ] ; _rtB -> B_20_899_0 [ 3 ] = ( ( X_ACStesbed1_T *
) ssGetContStates ( S ) ) -> q0q1q2q3_CSTATE_j [ 3 ] ; rtb_B_20_755_0 = -
B_20_43_0_idx_1 / rtb_B_20_468_0 ; rtb_B_20_1060_0 = - B_20_43_0_idx_2 /
rtb_B_20_468_0 ; rtb_B_20_468_0 = - B_20_43_0_idx_0 / rtb_B_20_468_0 ; _rtB
-> B_20_910_0 = ( ( rtb_B_20_37_0 * _rtB -> B_20_899_0 [ 0 ] - rtb_B_20_755_0
* _rtB -> B_20_899_0 [ 1 ] ) - rtb_B_20_1060_0 * _rtB -> B_20_899_0 [ 2 ] ) -
rtb_B_20_468_0 * _rtB -> B_20_899_0 [ 3 ] ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> B_20_911_0 = _rtP -> P_233 ; } if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> Switch_Mode_a = ( _rtB -> B_20_910_0 >= _rtP -> P_234 ) ; } if (
_rtDW -> Switch_Mode_a ) { rtb_B_20_1077_0 = _rtB -> B_20_832_0 ; } else {
rtb_B_20_1077_0 = _rtB -> B_20_911_0 ; } _rtB -> B_20_928_0 [ 0 ] =
rtb_B_20_1077_0 * _rtB -> B_20_910_0 ; _rtB -> B_20_928_0 [ 1 ] = ( ( (
rtb_B_20_37_0 * _rtB -> B_20_899_0 [ 1 ] + rtb_B_20_755_0 * _rtB ->
B_20_899_0 [ 0 ] ) + rtb_B_20_1060_0 * _rtB -> B_20_899_0 [ 3 ] ) -
rtb_B_20_468_0 * _rtB -> B_20_899_0 [ 2 ] ) * rtb_B_20_1077_0 ; _rtB ->
B_20_928_0 [ 2 ] = ( ( ( rtb_B_20_37_0 * _rtB -> B_20_899_0 [ 2 ] -
rtb_B_20_755_0 * _rtB -> B_20_899_0 [ 3 ] ) + rtb_B_20_1060_0 * _rtB ->
B_20_899_0 [ 0 ] ) + rtb_B_20_468_0 * _rtB -> B_20_899_0 [ 1 ] ) *
rtb_B_20_1077_0 ; _rtB -> B_20_928_0 [ 3 ] = ( ( ( rtb_B_20_37_0 * _rtB ->
B_20_899_0 [ 3 ] + rtb_B_20_755_0 * _rtB -> B_20_899_0 [ 2 ] ) -
rtb_B_20_1060_0 * _rtB -> B_20_899_0 [ 1 ] ) + rtb_B_20_468_0 * _rtB ->
B_20_899_0 [ 0 ] ) * rtb_B_20_1077_0 ; rtb_B_20_1339_0 [ 0 ] = _rtB ->
B_20_928_0 [ 0 ] * _rtB -> B_20_928_0 [ 1 ] ; rtb_B_20_1339_0 [ 1 ] = _rtB ->
B_20_928_0 [ 0 ] * _rtB -> B_20_928_0 [ 2 ] ; rtb_B_20_1339_0 [ 2 ] = _rtB ->
B_20_928_0 [ 0 ] * _rtB -> B_20_928_0 [ 3 ] ; for ( i_0 = 0 ; i_0 < 3 ; i_0
++ ) { _rtB -> B_20_930_0 [ i_0 ] = 0.0 ; _rtB -> B_20_930_0 [ i_0 ] += _rtB
-> B_20_831_0 [ i_0 ] * rtb_B_20_1339_0 [ 0 ] ; _rtB -> B_20_930_0 [ i_0 ] +=
_rtB -> B_20_831_0 [ i_0 + 3 ] * rtb_B_20_1339_0 [ 1 ] ; _rtB -> B_20_930_0 [
i_0 ] += _rtB -> B_20_831_0 [ i_0 + 6 ] * rtb_B_20_1339_0 [ 2 ] ; } if (
ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> B_20_931_0 [ 0 ] = _rtP -> P_235 *
_rtB -> B_20_930_0 [ 0 ] ; _rtB -> B_20_931_0 [ 1 ] = _rtP -> P_235 * _rtB ->
B_20_930_0 [ 1 ] ; _rtB -> B_20_931_0 [ 2 ] = _rtP -> P_235 * _rtB ->
B_20_930_0 [ 2 ] ; } rtb_B_20_892_0 = ( muDoubleScalarPower ( _rtB ->
B_20_836_0 [ 0 ] , 2.0 ) + muDoubleScalarPower ( _rtB -> B_20_836_0 [ 1 ] ,
2.0 ) ) + muDoubleScalarPower ( _rtB -> B_20_836_0 [ 2 ] , 2.0 ) ;
rtb_B_20_1339_0 [ 0 ] = _rtP -> P_236 * _rtB -> B_20_845_0 [ 0 ] /
rtb_B_20_892_0 ; rtb_B_20_1339_0 [ 1 ] = _rtP -> P_236 * _rtB -> B_20_845_0 [
1 ] / rtb_B_20_892_0 ; rtb_B_20_1339_0 [ 2 ] = _rtP -> P_236 * _rtB ->
B_20_845_0 [ 2 ] / rtb_B_20_892_0 ; rtb_B_20_468_0 = ( ( _rtB -> B_20_899_0 [
0 ] * _rtB -> B_20_899_0 [ 0 ] + _rtB -> B_20_899_0 [ 1 ] * _rtB ->
B_20_899_0 [ 1 ] ) + _rtB -> B_20_899_0 [ 2 ] * _rtB -> B_20_899_0 [ 2 ] ) +
_rtB -> B_20_899_0 [ 3 ] * _rtB -> B_20_899_0 [ 3 ] ; if ( ssIsMajorTimeStep
( S ) ) { if ( _rtDW -> sqrt_DWORK1_k != 0 ) { ssSetSolverNeedsReset ( S ) ;
_rtDW -> sqrt_DWORK1_k = 0 ; } rtb_B_20_468_0 = muDoubleScalarSqrt (
rtb_B_20_468_0 ) ; } else { if ( rtb_B_20_468_0 < 0.0 ) { rtb_B_20_468_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_468_0 ) ) ; } else {
rtb_B_20_468_0 = muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; } _rtDW ->
sqrt_DWORK1_k = 1 ; } rtb_B_20_37_0 = _rtB -> B_20_899_0 [ 2 ] /
rtb_B_20_468_0 ; rtb_B_20_755_0 = _rtB -> B_20_899_0 [ 3 ] / rtb_B_20_468_0 ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_945_0 = _rtP -> P_237 ; }
rtb_B_20_1060_0 = _rtB -> B_20_899_0 [ 1 ] / rtb_B_20_468_0 ; rtb_B_20_468_0
= _rtB -> B_20_899_0 [ 0 ] / rtb_B_20_468_0 ; if ( ssIsSampleHit ( S , 1 , 0
) ) { _rtB -> B_20_969_0 = _rtP -> P_242 ; _rtB -> B_20_991_0 = _rtP -> P_247
; } _rtB -> B_20_996_0 [ 0 ] = _rtB -> B_20_197_0 [ 0 ] - ( ( ( ( _rtB ->
B_20_945_0 - rtb_B_20_37_0 * rtb_B_20_37_0 ) - rtb_B_20_755_0 *
rtb_B_20_755_0 ) * _rtP -> P_238 * rtb_B_20_1339_0 [ 0 ] + ( rtb_B_20_1060_0
* rtb_B_20_37_0 + rtb_B_20_468_0 * rtb_B_20_755_0 ) * _rtP -> P_239 *
rtb_B_20_1339_0 [ 1 ] ) + ( rtb_B_20_1060_0 * rtb_B_20_755_0 - rtb_B_20_468_0
* rtb_B_20_37_0 ) * _rtP -> P_240 * rtb_B_20_1339_0 [ 2 ] ) ; _rtB ->
B_20_996_0 [ 1 ] = _rtB -> B_20_197_0 [ 1 ] - ( ( ( ( _rtB -> B_20_969_0 -
rtb_B_20_1060_0 * rtb_B_20_1060_0 ) - rtb_B_20_755_0 * rtb_B_20_755_0 ) *
_rtP -> P_243 * rtb_B_20_1339_0 [ 1 ] + ( rtb_B_20_1060_0 * rtb_B_20_37_0 -
rtb_B_20_468_0 * rtb_B_20_755_0 ) * _rtP -> P_241 * rtb_B_20_1339_0 [ 0 ] ) +
( rtb_B_20_468_0 * rtb_B_20_1060_0 + rtb_B_20_37_0 * rtb_B_20_755_0 ) * _rtP
-> P_244 * rtb_B_20_1339_0 [ 2 ] ) ; _rtB -> B_20_996_0 [ 2 ] = _rtB ->
B_20_197_0 [ 2 ] - ( ( ( rtb_B_20_1060_0 * rtb_B_20_755_0 + rtb_B_20_468_0 *
rtb_B_20_37_0 ) * _rtP -> P_245 * rtb_B_20_1339_0 [ 0 ] + ( rtb_B_20_37_0 *
rtb_B_20_755_0 - rtb_B_20_468_0 * rtb_B_20_1060_0 ) * _rtP -> P_246 *
rtb_B_20_1339_0 [ 1 ] ) + ( ( _rtB -> B_20_991_0 - rtb_B_20_1060_0 *
rtb_B_20_1060_0 ) - rtb_B_20_37_0 * rtb_B_20_37_0 ) * _rtP -> P_248 *
rtb_B_20_1339_0 [ 2 ] ) ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) {
rtb_B_20_1339_0 [ i_0 ] = _rtB -> B_20_831_0 [ i_0 + 6 ] * _rtB -> B_20_996_0
[ 2 ] + ( _rtB -> B_20_831_0 [ i_0 + 3 ] * _rtB -> B_20_996_0 [ 1 ] + _rtB ->
B_20_831_0 [ i_0 ] * _rtB -> B_20_996_0 [ 0 ] ) ; } _rtB -> B_20_1332_0 [ 0 ]
= _rtP -> P_249 * rtb_B_20_1339_0 [ 0 ] + _rtB -> B_20_931_0 [ 0 ] ; _rtB ->
B_20_1332_0 [ 1 ] = _rtP -> P_249 * rtb_B_20_1339_0 [ 1 ] + _rtB ->
B_20_931_0 [ 1 ] ; _rtB -> B_20_1332_0 [ 2 ] = _rtP -> P_249 *
rtb_B_20_1339_0 [ 2 ] + _rtB -> B_20_931_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { y [ i_0 ] = _rtB -> B_20_831_0
[ i_0 + 6 ] * _rtB -> B_20_197_0 [ 2 ] + ( _rtB -> B_20_831_0 [ i_0 + 3 ] *
_rtB -> B_20_197_0 [ 1 ] + _rtB -> B_20_831_0 [ i_0 ] * _rtB -> B_20_197_0 [
0 ] ) ; } tmp_0 [ 0 ] = _rtB -> B_20_197_0 [ 1 ] ; tmp_0 [ 1 ] = _rtB ->
B_20_197_0 [ 2 ] ; tmp_0 [ 2 ] = _rtB -> B_20_197_0 [ 0 ] ; tmp_0 [ 3 ] =
_rtB -> B_20_197_0 [ 2 ] ; tmp_0 [ 4 ] = _rtB -> B_20_197_0 [ 0 ] ; tmp_0 [ 5
] = _rtB -> B_20_197_0 [ 1 ] ; y_2 [ 0 ] = y [ 2 ] ; y_2 [ 1 ] = y [ 0 ] ;
y_2 [ 2 ] = y [ 1 ] ; y_2 [ 3 ] = y [ 1 ] ; y_2 [ 4 ] = y [ 2 ] ; y_2 [ 5 ] =
y [ 0 ] ; for ( i_0 = 0 ; i_0 < 6 ; i_0 ++ ) { rtb_B_20_21_0 [ i_0 ] = tmp_0
[ i_0 ] * y_2 [ i_0 ] ; } _rtB -> B_20_1002_0 [ 0 ] = rtb_B_20_21_0 [ 0 ] -
rtb_B_20_21_0 [ 3 ] ; _rtB -> B_20_1002_0 [ 1 ] = rtb_B_20_21_0 [ 1 ] -
rtb_B_20_21_0 [ 4 ] ; _rtB -> B_20_1002_0 [ 2 ] = rtb_B_20_21_0 [ 2 ] -
rtb_B_20_21_0 [ 5 ] ; memcpy ( & rtb_B_20_1301_0 [ 0 ] , & _rtP -> P_250 [ 0
] , 9U * sizeof ( real_T ) ) ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB ->
B_20_1005_0 [ i_0 ] = 0.0 ; _rtB -> B_20_1005_0 [ i_0 ] += _rtP -> P_250 [
i_0 ] * _rtB -> B_20_197_0 [ 0 ] ; _rtB -> B_20_1005_0 [ i_0 ] += _rtP ->
P_250 [ i_0 + 3 ] * _rtB -> B_20_197_0 [ 1 ] ; _rtB -> B_20_1005_0 [ i_0 ] +=
_rtP -> P_250 [ i_0 + 6 ] * _rtB -> B_20_197_0 [ 2 ] ; } _rtB -> B_20_1009_0
[ 0 ] = _rtB -> B_20_197_0 [ 1 ] * _rtP -> P_251 [ 2 ] - _rtB -> B_20_197_0 [
2 ] * _rtP -> P_251 [ 1 ] ; _rtB -> B_20_1009_0 [ 1 ] = _rtB -> B_20_197_0 [
2 ] * _rtP -> P_251 [ 0 ] - _rtB -> B_20_197_0 [ 0 ] * _rtP -> P_251 [ 2 ] ;
_rtB -> B_20_1009_0 [ 2 ] = _rtB -> B_20_197_0 [ 0 ] * _rtP -> P_251 [ 1 ] -
_rtB -> B_20_197_0 [ 1 ] * _rtP -> P_251 [ 0 ] ; } _rtB -> B_20_1010_0 [ 0 ]
= ( ( _rtB -> B_20_1332_0 [ 0 ] - _rtB -> B_20_1002_0 [ 0 ] ) - _rtB ->
B_20_1005_0 [ 0 ] ) - _rtB -> B_20_1009_0 [ 0 ] ; _rtB -> B_20_1010_0 [ 1 ] =
( ( _rtB -> B_20_1332_0 [ 1 ] - _rtB -> B_20_1002_0 [ 1 ] ) - _rtB ->
B_20_1005_0 [ 1 ] ) - _rtB -> B_20_1009_0 [ 1 ] ; _rtB -> B_20_1010_0 [ 2 ] =
( ( _rtB -> B_20_1332_0 [ 2 ] - _rtB -> B_20_1002_0 [ 2 ] ) - _rtB ->
B_20_1005_0 [ 2 ] ) - _rtB -> B_20_1009_0 [ 2 ] ; if ( ssIsMajorTimeStep ( S
) ) { _rtDW -> Saturation_MODE_as [ 0 ] = _rtB -> B_20_1010_0 [ 0 ] >= _rtP
-> P_252 ? 1 : _rtB -> B_20_1010_0 [ 0 ] > _rtP -> P_253 ? 0 : - 1 ; _rtDW ->
Saturation_MODE_as [ 1 ] = _rtB -> B_20_1010_0 [ 1 ] >= _rtP -> P_252 ? 1 :
_rtB -> B_20_1010_0 [ 1 ] > _rtP -> P_253 ? 0 : - 1 ; _rtDW ->
Saturation_MODE_as [ 2 ] = _rtB -> B_20_1010_0 [ 2 ] >= _rtP -> P_252 ? 1 :
_rtB -> B_20_1010_0 [ 2 ] > _rtP -> P_253 ? 0 : - 1 ; } rtb_B_20_1339_0 [ 0 ]
= _rtDW -> Saturation_MODE_as [ 0 ] == 1 ? _rtP -> P_252 : _rtDW ->
Saturation_MODE_as [ 0 ] == - 1 ? _rtP -> P_253 : _rtB -> B_20_1010_0 [ 0 ] ;
rtb_B_20_1339_0 [ 1 ] = _rtDW -> Saturation_MODE_as [ 1 ] == 1 ? _rtP ->
P_252 : _rtDW -> Saturation_MODE_as [ 1 ] == - 1 ? _rtP -> P_253 : _rtB ->
B_20_1010_0 [ 1 ] ; rtb_B_20_1339_0 [ 2 ] = _rtDW -> Saturation_MODE_as [ 2 ]
== 1 ? _rtP -> P_252 : _rtDW -> Saturation_MODE_as [ 2 ] == - 1 ? _rtP ->
P_253 : _rtB -> B_20_1010_0 [ 2 ] ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB
-> B_20_1012_0 [ 0 ] = rtb_B_20_1339_0 [ 0 ] ; _rtB -> B_20_1012_0 [ 1 ] =
rtb_B_20_1339_0 [ 1 ] ; _rtB -> B_20_1012_0 [ 2 ] = rtb_B_20_1339_0 [ 2 ] ; }
ssCallAccelRunBlock ( S , 20 , 1013 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 2 , 0 ) ) { rtb_B_20_892_0 = _rtP -> P_254 * _rtB ->
B_20_1012_0 [ 0 ] ; if ( rtb_B_20_892_0 >= _rtP -> P_255 ) { _rtB ->
B_20_1015_0 [ 0 ] = _rtP -> P_255 ; } else if ( rtb_B_20_892_0 <= _rtP ->
P_256 ) { _rtB -> B_20_1015_0 [ 0 ] = _rtP -> P_256 ; } else { _rtB ->
B_20_1015_0 [ 0 ] = rtb_B_20_892_0 ; } rtb_B_20_892_0 = _rtP -> P_254 * _rtB
-> B_20_1012_0 [ 1 ] ; if ( rtb_B_20_892_0 >= _rtP -> P_255 ) { _rtB ->
B_20_1015_0 [ 1 ] = _rtP -> P_255 ; } else if ( rtb_B_20_892_0 <= _rtP ->
P_256 ) { _rtB -> B_20_1015_0 [ 1 ] = _rtP -> P_256 ; } else { _rtB ->
B_20_1015_0 [ 1 ] = rtb_B_20_892_0 ; } rtb_B_20_892_0 = _rtP -> P_254 * _rtB
-> B_20_1012_0 [ 2 ] ; if ( rtb_B_20_892_0 >= _rtP -> P_255 ) { _rtB ->
B_20_1015_0 [ 2 ] = _rtP -> P_255 ; } else if ( rtb_B_20_892_0 <= _rtP ->
P_256 ) { _rtB -> B_20_1015_0 [ 2 ] = _rtP -> P_256 ; } else { _rtB ->
B_20_1015_0 [ 2 ] = rtb_B_20_892_0 ; } _rtB -> B_20_1016_0 [ 0 ] = _rtB ->
B_20_1141_0 [ 0 ] ; _rtB -> B_20_1016_0 [ 1 ] = _rtB -> B_20_1141_0 [ 1 ] ;
_rtB -> B_20_1016_0 [ 2 ] = _rtB -> B_20_1141_0 [ 2 ] ; } ssCallAccelRunBlock
( S , 20 , 1017 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> B_20_1018_0 [ 0 ] = _rtP -> P_257 [ 0 ] ; _rtB -> B_20_1018_0 [ 1 ]
= _rtP -> P_257 [ 1 ] ; _rtB -> B_20_1018_0 [ 2 ] = _rtP -> P_257 [ 2 ] ;
_rtB -> B_20_1019_0 = _rtP -> P_258 ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) {
memset ( & _rtB -> B_20_1033_0 [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; _rtB ->
B_20_1033_0 [ 0 ] = _rtB -> B_20_197_0 [ 0 ] ; _rtB -> B_20_1033_0 [ 4 ] =
_rtB -> B_20_197_0 [ 1 ] ; _rtB -> B_20_1033_0 [ 8 ] = _rtB -> B_20_197_0 [ 2
] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_20_1031_0 [ 0 ] = _rtB ->
B_20_197_0 [ 1 ] ; rtb_B_20_1031_0 [ 1 ] = _rtB -> B_20_197_0 [ 0 ] ;
rtb_B_20_1031_0 [ 2 ] = _rtP -> P_259 ; rtb_B_20_1031_0 [ 3 ] = _rtB ->
B_20_197_0 [ 2 ] ; rtb_B_20_1031_0 [ 4 ] = _rtP -> P_259 ; rtb_B_20_1031_0 [
5 ] = _rtB -> B_20_197_0 [ 0 ] ; rtb_B_20_1031_0 [ 6 ] = _rtP -> P_259 ;
rtb_B_20_1031_0 [ 7 ] = _rtB -> B_20_197_0 [ 2 ] ; rtb_B_20_1031_0 [ 8 ] =
_rtB -> B_20_197_0 [ 1 ] ; memcpy ( & _rtB -> B_20_1033_0 [ 9 ] , &
rtb_B_20_1031_0 [ 0 ] , 9U * sizeof ( real_T ) ) ; rtb_B_20_1281_0 = _rtP ->
P_260 ; rtb_B_20_1045_0 [ 0 ] = _rtP -> P_260 ; rtb_B_20_1045_0 [ 1 ] = _rtB
-> B_20_197_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB ->
B_20_1037_0 [ 0 ] = _rtP -> P_261 * _rtB -> B_20_197_0 [ 0 ] ; _rtB ->
B_20_1037_0 [ 1 ] = _rtP -> P_261 * _rtB -> B_20_197_0 [ 1 ] ; _rtB ->
B_20_1037_0 [ 2 ] = _rtP -> P_261 * _rtB -> B_20_197_0 [ 2 ] ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_20_1045_0 [ 2 ] = _rtB -> B_20_1037_0 [
1 ] ; rtb_B_20_1045_0 [ 3 ] = _rtB -> B_20_1037_0 [ 2 ] ; rtb_B_20_1045_0 [ 4
] = rtb_B_20_1281_0 ; rtb_B_20_1045_0 [ 5 ] = _rtB -> B_20_197_0 [ 0 ] ;
rtb_B_20_1045_0 [ 6 ] = _rtB -> B_20_197_0 [ 1 ] ; rtb_B_20_1045_0 [ 7 ] =
_rtB -> B_20_1037_0 [ 0 ] ; rtb_B_20_1045_0 [ 8 ] = rtb_B_20_1281_0 ; for (
i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 6 ; i ++ ) { _rtB ->
B_20_1046_0 [ i_0 + 3 * i ] = 0.0 ; _rtB -> B_20_1046_0 [ i_0 + 3 * i ] +=
_rtB -> B_20_1033_0 [ 3 * i ] * rtb_B_20_1045_0 [ i_0 ] ; _rtB -> B_20_1046_0
[ i_0 + 3 * i ] += _rtB -> B_20_1033_0 [ 3 * i + 1 ] * rtb_B_20_1045_0 [ i_0
+ 3 ] ; _rtB -> B_20_1046_0 [ i_0 + 3 * i ] += _rtB -> B_20_1033_0 [ 3 * i +
2 ] * rtb_B_20_1045_0 [ i_0 + 6 ] ; } } } if ( ssIsSampleHit ( S , 5 , 0 ) )
{ if ( _rtDW -> DiscreteTimeIntegrator_IC_LOADING_p != 0 ) { for ( i = 0 ; i
< 18 ; i ++ ) { _rtDW -> DiscreteTimeIntegrator_DSTATE_p [ i ] = 0.0 ; _rtB
-> B_20_1047_0 [ i ] = _rtDW -> DiscreteTimeIntegrator_DSTATE_p [ i ] ; } }
else { for ( i = 0 ; i < 18 ; i ++ ) { _rtB -> B_20_1047_0 [ i ] = _rtP ->
P_262 * _rtB -> B_20_1046_0 [ i ] + _rtDW -> DiscreteTimeIntegrator_DSTATE_p
[ i ] ; } } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i = 0 ; i < 18 ; i
++ ) { _rtB -> B_20_1123_0 [ i ] = _rtB -> B_20_1033_0 [ i ] + _rtB ->
B_20_1047_0 [ i ] ; } _rtB -> B_20_1049_0 = _rtP -> P_263 ; } _rtB ->
B_20_1121_0 [ 0 ] = _rtB -> B_20_1049_0 ; rtb_B_20_468_0 = ( ( _rtB ->
B_20_928_0 [ 0 ] * _rtB -> B_20_928_0 [ 0 ] + _rtB -> B_20_928_0 [ 1 ] * _rtB
-> B_20_928_0 [ 1 ] ) + _rtB -> B_20_928_0 [ 2 ] * _rtB -> B_20_928_0 [ 2 ] )
+ _rtB -> B_20_928_0 [ 3 ] * _rtB -> B_20_928_0 [ 3 ] ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtDW -> sqrt_DWORK1_dk != 0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> sqrt_DWORK1_dk = 0 ; } rtb_B_20_468_0
= muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; } else { if ( rtb_B_20_468_0 < 0.0
) { rtb_B_20_468_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs (
rtb_B_20_468_0 ) ) ; } else { rtb_B_20_468_0 = muDoubleScalarSqrt (
rtb_B_20_468_0 ) ; } _rtDW -> sqrt_DWORK1_dk = 1 ; } rtb_B_20_37_0 = _rtB ->
B_20_928_0 [ 1 ] / rtb_B_20_468_0 ; rtb_B_20_755_0 = _rtB -> B_20_928_0 [ 3 ]
/ rtb_B_20_468_0 ; rtb_B_20_1060_0 = _rtB -> B_20_928_0 [ 0 ] /
rtb_B_20_468_0 ; rtb_B_20_468_0 = _rtB -> B_20_928_0 [ 2 ] / rtb_B_20_468_0 ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_1073_0 = _rtP -> P_266 ; }
rtb_B_20_1077_0 = ( ( rtb_B_20_37_0 * rtb_B_20_755_0 + rtb_B_20_1060_0 *
rtb_B_20_468_0 ) * _rtP -> P_264 * _rtB -> B_20_1018_0 [ 0 ] + (
rtb_B_20_468_0 * rtb_B_20_755_0 - rtb_B_20_1060_0 * rtb_B_20_37_0 ) * _rtP ->
P_265 * _rtB -> B_20_1018_0 [ 1 ] ) + ( ( _rtB -> B_20_1073_0 - rtb_B_20_37_0
* rtb_B_20_37_0 ) - rtb_B_20_468_0 * rtb_B_20_468_0 ) * _rtP -> P_267 * _rtB
-> B_20_1018_0 [ 2 ] ; _rtB -> B_20_1121_0 [ 1 ] = rtb_B_20_1077_0 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_1081_0 = _rtP -> P_268 ; }
rtb_B_20_57_0 = ( ( ( _rtB -> B_20_1081_0 - rtb_B_20_468_0 * rtb_B_20_468_0 )
- rtb_B_20_755_0 * rtb_B_20_755_0 ) * _rtP -> P_269 * _rtB -> B_20_1018_0 [ 0
] + ( rtb_B_20_37_0 * rtb_B_20_468_0 + rtb_B_20_1060_0 * rtb_B_20_755_0 ) *
_rtP -> P_270 * _rtB -> B_20_1018_0 [ 1 ] ) + ( rtb_B_20_37_0 *
rtb_B_20_755_0 - rtb_B_20_1060_0 * rtb_B_20_468_0 ) * _rtP -> P_271 * _rtB ->
B_20_1018_0 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_1103_0
= _rtP -> P_273 ; } rtb_B_20_468_0 = ( ( ( _rtB -> B_20_1103_0 -
rtb_B_20_37_0 * rtb_B_20_37_0 ) - rtb_B_20_755_0 * rtb_B_20_755_0 ) * _rtP ->
P_274 * _rtB -> B_20_1018_0 [ 1 ] + ( rtb_B_20_37_0 * rtb_B_20_468_0 -
rtb_B_20_1060_0 * rtb_B_20_755_0 ) * _rtP -> P_272 * _rtB -> B_20_1018_0 [ 0
] ) + ( rtb_B_20_1060_0 * rtb_B_20_37_0 + rtb_B_20_468_0 * rtb_B_20_755_0 ) *
_rtP -> P_275 * _rtB -> B_20_1018_0 [ 2 ] ; rtb_B_20_1339_0 [ 0 ] = _rtP ->
P_276 * rtb_B_20_57_0 ; rtb_B_20_1339_0 [ 1 ] = _rtP -> P_276 *
rtb_B_20_468_0 ; rtb_B_20_1339_0 [ 2 ] = _rtP -> P_276 * rtb_B_20_1077_0 ;
_rtB -> B_20_1121_0 [ 2 ] = rtb_B_20_1339_0 [ 1 ] ; _rtB -> B_20_1121_0 [ 3 ]
= rtb_B_20_1339_0 [ 2 ] ; _rtB -> B_20_1121_0 [ 4 ] = _rtB -> B_20_1049_0 ;
_rtB -> B_20_1121_0 [ 5 ] = rtb_B_20_57_0 ; _rtB -> B_20_1121_0 [ 6 ] =
rtb_B_20_468_0 ; _rtB -> B_20_1121_0 [ 7 ] = rtb_B_20_1339_0 [ 0 ] ; _rtB ->
B_20_1121_0 [ 8 ] = _rtB -> B_20_1049_0 ; if ( ssIsSampleHit ( S , 5 , 0 ) )
{ for ( i = 0 ; i < 9 ; i ++ ) { if ( _rtDW ->
DiscreteTimeIntegrator1_SYSTEM_ENABLE_o != 0 ) { _rtB -> B_20_1123_0 [ i + 18
] = _rtDW -> DiscreteTimeIntegrator1_DSTATE_f [ i ] ; } else { _rtB ->
B_20_1123_0 [ i + 18 ] = _rtP -> P_277 * _rtB -> B_20_1121_0 [ i ] + _rtDW ->
DiscreteTimeIntegrator1_DSTATE_f [ i ] ; } } } if ( ssIsSampleHit ( S , 1 , 0
) ) { memcpy ( & _rtDW -> Pseudoinverse_X [ 0 ] , & _rtB -> B_20_1123_0 [ 0 ]
, 27U * sizeof ( real_T ) ) ; i = MWDSP_SVD_D ( & _rtDW -> Pseudoinverse_X [
0U ] , 3 , 9 , & _rtDW -> Pseudoinverse_S [ 0U ] , & _rtDW -> Pseudoinverse_E
[ 0U ] , & _rtDW -> Pseudoinverse_WORK [ 0U ] , & _rtDW -> Pseudoinverse_U [
0U ] , & _rtDW -> Pseudoinverse_V [ 0U ] , 1 ) ; if ( i == 0 ) {
MWDSPCG_Pseudoinverse_D ( & _rtDW -> Pseudoinverse_S [ 0U ] , & _rtDW ->
Pseudoinverse_U [ 0U ] , & _rtDW -> Pseudoinverse_V [ 0U ] , & _rtB ->
B_20_1124_0 [ 0U ] , 3 , 9 ) ; } } _rtB -> B_20_1126_0 [ 0 ] = _rtB ->
B_20_197_0 [ 1 ] * rtb_B_20_1128_0 [ 2 ] - _rtB -> B_20_197_0 [ 2 ] *
rtb_B_20_1128_0 [ 1 ] ; _rtB -> B_20_1126_0 [ 1 ] = _rtB -> B_20_197_0 [ 2 ]
* rtb_B_20_1128_0 [ 0 ] - _rtB -> B_20_197_0 [ 0 ] * rtb_B_20_1128_0 [ 2 ] ;
_rtB -> B_20_1126_0 [ 2 ] = _rtB -> B_20_197_0 [ 0 ] * rtb_B_20_1128_0 [ 1 ]
- _rtB -> B_20_197_0 [ 1 ] * rtb_B_20_1128_0 [ 0 ] ; if ( ssIsSampleHit ( S ,
5 , 0 ) ) { if ( _rtDW -> DiscreteTimeIntegrator2_SYSTEM_ENABLE_c != 0 ) {
_rtB -> B_20_1127_0 [ 0 ] = _rtDW -> DiscreteTimeIntegrator2_DSTATE_n [ 0 ] ;
_rtB -> B_20_1127_0 [ 1 ] = _rtDW -> DiscreteTimeIntegrator2_DSTATE_n [ 1 ] ;
_rtB -> B_20_1127_0 [ 2 ] = _rtDW -> DiscreteTimeIntegrator2_DSTATE_n [ 2 ] ;
} else { _rtB -> B_20_1127_0 [ 0 ] = _rtP -> P_279 * _rtB -> B_20_1126_0 [ 0
] + _rtDW -> DiscreteTimeIntegrator2_DSTATE_n [ 0 ] ; _rtB -> B_20_1127_0 [ 1
] = _rtP -> P_279 * _rtB -> B_20_1126_0 [ 1 ] + _rtDW ->
DiscreteTimeIntegrator2_DSTATE_n [ 1 ] ; _rtB -> B_20_1127_0 [ 2 ] = _rtP ->
P_279 * _rtB -> B_20_1126_0 [ 2 ] + _rtDW -> DiscreteTimeIntegrator2_DSTATE_n
[ 2 ] ; } } rtb_B_20_1128_0 [ 0 ] = ( 0.0 - rtb_B_20_1128_0 [ 0 ] ) - _rtB ->
B_20_1127_0 [ 0 ] ; rtb_B_20_1128_0 [ 1 ] = ( 0.0 - rtb_B_20_1128_0 [ 1 ] ) -
_rtB -> B_20_1127_0 [ 1 ] ; rtb_B_20_892_0 = ( 0.0 - rtb_B_20_1128_0 [ 2 ] )
- _rtB -> B_20_1127_0 [ 2 ] ; for ( i_0 = 0 ; i_0 < 9 ; i_0 ++ ) { y_0 [ i_0
] = _rtB -> B_20_1124_0 [ i_0 + 18 ] * rtb_B_20_892_0 + ( _rtB -> B_20_1124_0
[ i_0 + 9 ] * rtb_B_20_1128_0 [ 1 ] + _rtB -> B_20_1124_0 [ i_0 ] *
rtb_B_20_1128_0 [ 0 ] ) ; } _rtB -> B_20_1139_0 [ 0 ] = y_0 [ 0 ] ; _rtB ->
B_20_1139_0 [ 1 ] = y_0 [ 3 ] ; _rtB -> B_20_1139_0 [ 2 ] = y_0 [ 4 ] ; _rtB
-> B_20_1139_0 [ 3 ] = y_0 [ 3 ] ; _rtB -> B_20_1139_0 [ 4 ] = y_0 [ 1 ] ;
_rtB -> B_20_1139_0 [ 5 ] = y_0 [ 5 ] ; _rtB -> B_20_1139_0 [ 6 ] = y_0 [ 4 ]
; _rtB -> B_20_1139_0 [ 7 ] = y_0 [ 5 ] ; _rtB -> B_20_1139_0 [ 8 ] = y_0 [ 2
] ; ssCallAccelRunBlock ( S , 20 , 1140 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_20_1141_0 [ 0 ] = y_0 [ 6 ] / _rtB -> B_20_1019_0 ; _rtB -> B_20_1141_0 [ 1
] = y_0 [ 7 ] / _rtB -> B_20_1019_0 ; _rtB -> B_20_1141_0 [ 2 ] = y_0 [ 8 ] /
_rtB -> B_20_1019_0 ; ssCallAccelRunBlock ( S , 20 , 1142 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 1143 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 1144 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 1145 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 1146 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 1147 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 1148 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 1149 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_1150_0 = _rtP -> P_281 ; _rtB -> B_20_1151_0 = _rtP -> P_282 ; } if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> Switch_Mode_mke = ( _rtB -> B_20_899_0 [
0 ] >= _rtP -> P_283 ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_1153_0 = _rtP -> P_284 ; } rtb_B_20_468_0 = ( _rtB -> B_20_1153_0 - ( (
( _rtB -> B_20_899_0 [ 0 ] * _rtB -> B_20_899_0 [ 0 ] + _rtB -> B_20_899_0 [
1 ] * _rtB -> B_20_899_0 [ 1 ] ) + _rtB -> B_20_899_0 [ 2 ] * _rtB ->
B_20_899_0 [ 2 ] ) + _rtB -> B_20_899_0 [ 3 ] * _rtB -> B_20_899_0 [ 3 ] ) )
* _rtP -> P_285 ; _rtB -> B_20_1157_0 = ( ( _rtB -> B_20_899_0 [ 1 ] * _rtB
-> B_20_197_0 [ 0 ] + _rtB -> B_20_899_0 [ 2 ] * _rtB -> B_20_197_0 [ 1 ] ) +
_rtB -> B_20_899_0 [ 3 ] * _rtB -> B_20_197_0 [ 2 ] ) * - 0.5 +
rtb_B_20_468_0 * _rtB -> B_20_899_0 [ 0 ] ; _rtB -> B_20_1158_0 = ( ( _rtB ->
B_20_899_0 [ 0 ] * _rtB -> B_20_197_0 [ 0 ] + _rtB -> B_20_899_0 [ 2 ] * _rtB
-> B_20_197_0 [ 2 ] ) - _rtB -> B_20_899_0 [ 3 ] * _rtB -> B_20_197_0 [ 1 ] )
* 0.5 + rtb_B_20_468_0 * _rtB -> B_20_899_0 [ 1 ] ; _rtB -> B_20_1159_0 = ( (
_rtB -> B_20_899_0 [ 0 ] * _rtB -> B_20_197_0 [ 1 ] + _rtB -> B_20_899_0 [ 3
] * _rtB -> B_20_197_0 [ 0 ] ) - _rtB -> B_20_899_0 [ 1 ] * _rtB ->
B_20_197_0 [ 2 ] ) * 0.5 + rtb_B_20_468_0 * _rtB -> B_20_899_0 [ 2 ] ; _rtB
-> B_20_1160_0 = ( ( _rtB -> B_20_899_0 [ 0 ] * _rtB -> B_20_197_0 [ 2 ] +
_rtB -> B_20_899_0 [ 1 ] * _rtB -> B_20_197_0 [ 1 ] ) - _rtB -> B_20_899_0 [
2 ] * _rtB -> B_20_197_0 [ 0 ] ) * 0.5 + rtb_B_20_468_0 * _rtB -> B_20_899_0
[ 3 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_1161_0 = _rtP ->
P_286 ; } _rtB -> B_20_1171_0 [ 0 ] = _rtB -> B_20_1161_0 ; _rtB ->
B_20_1171_0 [ 1 ] = _rtB -> B_20_928_0 [ 3 ] ; _rtB -> B_20_1171_0 [ 2 ] =
_rtP -> P_287 * _rtB -> B_20_928_0 [ 2 ] ; _rtB -> B_20_1171_0 [ 3 ] = _rtP
-> P_288 * _rtB -> B_20_928_0 [ 3 ] ; _rtB -> B_20_1171_0 [ 4 ] = _rtB ->
B_20_1161_0 ; _rtB -> B_20_1171_0 [ 5 ] = _rtB -> B_20_928_0 [ 1 ] ; _rtB ->
B_20_1171_0 [ 6 ] = _rtB -> B_20_928_0 [ 2 ] ; _rtB -> B_20_1171_0 [ 7 ] =
_rtP -> P_289 * _rtB -> B_20_928_0 [ 1 ] ; _rtB -> B_20_1171_0 [ 8 ] = _rtB
-> B_20_1161_0 ; memcpy ( & rtb_B_20_574_0 [ 0 ] , & _rtB -> B_20_1171_0 [ 0
] , 9U * sizeof ( real_T ) ) ; LUf_int32_Treal_T ( rtb_B_20_574_0 ,
rtb_B_20_1339_0 , 3 ) ; for ( i = 0 ; i < 3 ; i ++ ) { k = ( int32_T )
muDoubleScalarFloor ( rtb_B_20_1339_0 [ i ] ) - 1 ; if ( k < 0 ) { k = 0 ; }
else { if ( k >= 3 ) { k = 2 ; } } rtb_B_20_1175_0 [ i ] = _rtB ->
B_20_1173_0 [ k ] ; rtb_B_20_1175_0 [ 3 + i ] = _rtB -> B_20_1173_0 [ 3 + k ]
; rtb_B_20_1175_0 [ 6 + i ] = _rtB -> B_20_1173_0 [ 6 + k ] ; } for ( i_0 = 0
; i_0 < 3 ; i_0 ++ ) { idxout = i_0 * 3 ; i = 1 ; idxB = idxout + 1 ;
rtb_B_20_37_0 = rtb_B_20_1175_0 [ idxB ] ; k = 0 ; while ( k < 1 ) {
rtb_B_20_37_0 -= rtb_B_20_574_0 [ i ] * rtb_B_20_1175_0 [ idxout ] ; i += 3 ;
k = 1 ; } rtb_B_20_1175_0 [ idxB ] = rtb_B_20_37_0 ; i = 2 ; idxB = idxout +
2 ; rtb_B_20_37_0 = rtb_B_20_1175_0 [ idxB ] ; for ( k = 0 ; k < 2 ; k ++ ) {
rtb_B_20_37_0 -= rtb_B_20_1175_0 [ idxout + k ] * rtb_B_20_574_0 [ i ] ; i +=
3 ; } rtb_B_20_1175_0 [ idxB ] = rtb_B_20_37_0 ; } for ( i_0 = 0 ; i_0 < 3 ;
i_0 ++ ) { idxout = i_0 * 3 ; i = idxout + 2 ; _rtB -> B_20_1176_0 [ i ] =
rtb_B_20_1175_0 [ i ] / rtb_B_20_574_0 [ 8 ] ; i = 7 ; idxB = idxout + 1 ;
rtb_B_20_37_0 = rtb_B_20_1175_0 [ idxB ] ; k = 2 ; while ( k > 1 ) {
rtb_B_20_37_0 -= _rtB -> B_20_1176_0 [ idxout + 2 ] * rtb_B_20_574_0 [ i ] ;
i -= 3 ; k = 1 ; } _rtB -> B_20_1176_0 [ idxB ] = rtb_B_20_37_0 /
rtb_B_20_574_0 [ i ] ; i = 6 ; rtb_B_20_37_0 = rtb_B_20_1175_0 [ idxout ] ;
for ( k = 2 ; k > 0 ; k -- ) { rtb_B_20_37_0 -= _rtB -> B_20_1176_0 [ idxout
+ k ] * rtb_B_20_574_0 [ i ] ; i -= 3 ; } _rtB -> B_20_1176_0 [ idxout ] =
rtb_B_20_37_0 / rtb_B_20_574_0 [ i ] ; } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) {
_rtB -> B_20_1332_0 [ i_0 ] = 0.0 ; _rtB -> B_20_1332_0 [ i_0 ] += _rtB ->
B_20_1176_0 [ i_0 ] * _rtB -> B_20_996_0 [ 0 ] ; _rtB -> B_20_1332_0 [ i_0 ]
+= _rtB -> B_20_1176_0 [ i_0 + 3 ] * _rtB -> B_20_996_0 [ 1 ] ; _rtB ->
B_20_1332_0 [ i_0 ] += _rtB -> B_20_1176_0 [ i_0 + 6 ] * _rtB -> B_20_996_0 [
2 ] ; } ssCallAccelRunBlock ( S , 20 , 1178 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_20_1179_0 = _rtP -> P_290 ; _rtB ->
B_20_1180_0 = _rtP -> P_291 * _rtB -> B_20_1179_0 ; } _rtB -> B_20_1332_0 [ 0
] = ( _rtB -> B_20_996_0 [ 0 ] - _rtB -> B_20_1179_0 * _rtB -> B_20_928_0 [ 1
] ) * _rtB -> B_20_1180_0 ; _rtB -> B_20_1332_0 [ 1 ] = ( _rtB -> B_20_996_0
[ 1 ] - _rtB -> B_20_1179_0 * _rtB -> B_20_928_0 [ 2 ] ) * _rtB ->
B_20_1180_0 ; _rtB -> B_20_1332_0 [ 2 ] = ( _rtB -> B_20_996_0 [ 2 ] - _rtB
-> B_20_1179_0 * _rtB -> B_20_928_0 [ 3 ] ) * _rtB -> B_20_1180_0 ;
ssCallAccelRunBlock ( S , 20 , 1184 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 1185 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 20 , 1186 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_20_1339_0
[ 0 ] = _rtB -> B_20_835_0 . vj2000 [ 0 ] ; rtb_B_20_1339_0 [ 1 ] = _rtB ->
B_20_835_0 . vj2000 [ 1 ] ; rtb_B_20_1339_0 [ 2 ] = _rtB -> B_20_835_0 .
vj2000 [ 2 ] ; _rtB -> B_20_1187_1 [ 0 ] = _rtB -> B_20_835_0 . j2000 [ 0 ] ;
_rtB -> B_20_1187_1 [ 1 ] = _rtB -> B_20_835_0 . j2000 [ 1 ] ; _rtB ->
B_20_1187_1 [ 2 ] = _rtB -> B_20_835_0 . j2000 [ 2 ] ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { memcpy ( & _rtB -> B_20_1188_0 [ 0 ] , & _rtP -> P_292 [ 0 ] ,
9U * sizeof ( real_T ) ) ; _rtB -> B_20_1190_0 = _rtP -> P_294 * _rtP ->
P_293 ; } rtb_B_20_892_0 = _rtB -> B_20_1333_0 [ 0 ] * _rtB -> B_20_1333_0 [
0 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_20_1204_0 [ 0 ] = _rtP ->
P_295 ; rtb_B_20_1204_0 [ 1 ] = _rtP -> P_296 [ 2 ] ; rtb_B_20_1204_0 [ 2 ] =
_rtP -> P_297 * _rtP -> P_296 [ 1 ] ; rtb_B_20_1204_0 [ 3 ] = _rtP -> P_297 *
_rtP -> P_296 [ 2 ] ; rtb_B_20_1204_0 [ 4 ] = _rtP -> P_295 ; rtb_B_20_1204_0
[ 5 ] = _rtP -> P_296 [ 0 ] ; rtb_B_20_1204_0 [ 6 ] = _rtP -> P_296 [ 1 ] ;
rtb_B_20_1204_0 [ 7 ] = _rtP -> P_297 * _rtP -> P_296 [ 0 ] ; rtb_B_20_1204_0
[ 8 ] = _rtP -> P_295 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i
< 3 ; i ++ ) { _rtB -> B_20_1205_0 [ i_0 + 3 * i ] = 0.0 ; _rtB ->
B_20_1205_0 [ i_0 + 3 * i ] += rtb_B_20_1204_0 [ 3 * i ] * rtb_B_20_1204_0 [
i_0 ] ; _rtB -> B_20_1205_0 [ i_0 + 3 * i ] += rtb_B_20_1204_0 [ 3 * i + 1 ]
* rtb_B_20_1204_0 [ i_0 + 3 ] ; _rtB -> B_20_1205_0 [ i_0 + 3 * i ] +=
rtb_B_20_1204_0 [ 3 * i + 2 ] * rtb_B_20_1204_0 [ i_0 + 6 ] ; } }
rtb_B_20_1219_0 [ 0 ] = _rtP -> P_298 ; rtb_B_20_1219_0 [ 1 ] = _rtP -> P_299
[ 2 ] ; rtb_B_20_1219_0 [ 2 ] = _rtP -> P_300 * _rtP -> P_299 [ 1 ] ;
rtb_B_20_1219_0 [ 3 ] = _rtP -> P_300 * _rtP -> P_299 [ 2 ] ; rtb_B_20_1219_0
[ 4 ] = _rtP -> P_298 ; rtb_B_20_1219_0 [ 5 ] = _rtP -> P_299 [ 0 ] ;
rtb_B_20_1219_0 [ 6 ] = _rtP -> P_299 [ 1 ] ; rtb_B_20_1219_0 [ 7 ] = _rtP ->
P_300 * _rtP -> P_299 [ 0 ] ; rtb_B_20_1219_0 [ 8 ] = _rtP -> P_298 ; for (
i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
B_20_1220_0 [ i_0 + 3 * i ] = 0.0 ; _rtB -> B_20_1220_0 [ i_0 + 3 * i ] +=
rtb_B_20_1219_0 [ 3 * i ] * rtb_B_20_1204_0 [ i_0 ] ; _rtB -> B_20_1220_0 [
i_0 + 3 * i ] += rtb_B_20_1219_0 [ 3 * i + 1 ] * rtb_B_20_1204_0 [ i_0 + 3 ]
; _rtB -> B_20_1220_0 [ i_0 + 3 * i ] += rtb_B_20_1219_0 [ 3 * i + 2 ] *
rtb_B_20_1204_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for (
i = 0 ; i < 3 ; i ++ ) { _rtB -> B_20_1222_0 [ i_0 + 3 * i ] = 0.0 ; _rtB ->
B_20_1222_0 [ i_0 + 3 * i ] += rtb_B_20_1204_0 [ 3 * i ] * rtb_B_20_1219_0 [
i_0 ] ; _rtB -> B_20_1222_0 [ i_0 + 3 * i ] += rtb_B_20_1204_0 [ 3 * i + 1 ]
* rtb_B_20_1219_0 [ i_0 + 3 ] ; _rtB -> B_20_1222_0 [ i_0 + 3 * i ] +=
rtb_B_20_1204_0 [ 3 * i + 2 ] * rtb_B_20_1219_0 [ i_0 + 6 ] ; } } _rtB ->
B_20_1227_0 = _rtP -> P_302 * _rtP -> P_301 ; } rtb_B_20_37_0 = _rtB ->
B_20_1333_0 [ 1 ] * _rtB -> B_20_1333_0 [ 1 ] ; if ( ssIsSampleHit ( S , 1 ,
0 ) ) { rtb_B_20_1241_0 [ 0 ] = _rtP -> P_303 ; rtb_B_20_1241_0 [ 1 ] = _rtP
-> P_304 [ 2 ] ; rtb_B_20_1241_0 [ 2 ] = _rtP -> P_305 * _rtP -> P_304 [ 1 ]
; rtb_B_20_1241_0 [ 3 ] = _rtP -> P_305 * _rtP -> P_304 [ 2 ] ;
rtb_B_20_1241_0 [ 4 ] = _rtP -> P_303 ; rtb_B_20_1241_0 [ 5 ] = _rtP -> P_304
[ 0 ] ; rtb_B_20_1241_0 [ 6 ] = _rtP -> P_304 [ 1 ] ; rtb_B_20_1241_0 [ 7 ] =
_rtP -> P_305 * _rtP -> P_304 [ 0 ] ; rtb_B_20_1241_0 [ 8 ] = _rtP -> P_303 ;
for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
B_20_1242_0 [ i_0 + 3 * i ] = 0.0 ; _rtB -> B_20_1242_0 [ i_0 + 3 * i ] +=
rtb_B_20_1241_0 [ 3 * i ] * rtb_B_20_1241_0 [ i_0 ] ; _rtB -> B_20_1242_0 [
i_0 + 3 * i ] += rtb_B_20_1241_0 [ 3 * i + 1 ] * rtb_B_20_1241_0 [ i_0 + 3 ]
; _rtB -> B_20_1242_0 [ i_0 + 3 * i ] += rtb_B_20_1241_0 [ 3 * i + 2 ] *
rtb_B_20_1241_0 [ i_0 + 6 ] ; } } rtb_B_20_1256_0 [ 0 ] = _rtP -> P_306 ;
rtb_B_20_1256_0 [ 1 ] = _rtP -> P_307 [ 2 ] ; rtb_B_20_1256_0 [ 2 ] = _rtP ->
P_308 * _rtP -> P_307 [ 1 ] ; rtb_B_20_1256_0 [ 3 ] = _rtP -> P_308 * _rtP ->
P_307 [ 2 ] ; rtb_B_20_1256_0 [ 4 ] = _rtP -> P_306 ; rtb_B_20_1256_0 [ 5 ] =
_rtP -> P_307 [ 0 ] ; rtb_B_20_1256_0 [ 6 ] = _rtP -> P_307 [ 1 ] ;
rtb_B_20_1256_0 [ 7 ] = _rtP -> P_308 * _rtP -> P_307 [ 0 ] ; rtb_B_20_1256_0
[ 8 ] = _rtP -> P_306 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i
< 3 ; i ++ ) { _rtB -> B_20_1257_0 [ i_0 + 3 * i ] = 0.0 ; _rtB ->
B_20_1257_0 [ i_0 + 3 * i ] += rtb_B_20_1256_0 [ 3 * i ] * rtb_B_20_1241_0 [
i_0 ] ; _rtB -> B_20_1257_0 [ i_0 + 3 * i ] += rtb_B_20_1256_0 [ 3 * i + 1 ]
* rtb_B_20_1241_0 [ i_0 + 3 ] ; _rtB -> B_20_1257_0 [ i_0 + 3 * i ] +=
rtb_B_20_1256_0 [ 3 * i + 2 ] * rtb_B_20_1241_0 [ i_0 + 6 ] ; } } for ( i_0 =
0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_20_1259_0 [
i_0 + 3 * i ] = 0.0 ; _rtB -> B_20_1259_0 [ i_0 + 3 * i ] += rtb_B_20_1241_0
[ 3 * i ] * rtb_B_20_1256_0 [ i_0 ] ; _rtB -> B_20_1259_0 [ i_0 + 3 * i ] +=
rtb_B_20_1241_0 [ 3 * i + 1 ] * rtb_B_20_1256_0 [ i_0 + 3 ] ; _rtB ->
B_20_1259_0 [ i_0 + 3 * i ] += rtb_B_20_1241_0 [ 3 * i + 2 ] *
rtb_B_20_1256_0 [ i_0 + 6 ] ; } } _rtB -> B_20_1264_0 = _rtP -> P_310 * _rtP
-> P_309 ; } rtb_B_20_755_0 = _rtB -> B_20_1333_0 [ 2 ] * _rtB -> B_20_1333_0
[ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { rtb_B_20_1278_0 [ 0 ] = _rtP ->
P_311 ; rtb_B_20_1278_0 [ 1 ] = _rtP -> P_312 [ 2 ] ; rtb_B_20_1278_0 [ 2 ] =
_rtP -> P_313 * _rtP -> P_312 [ 1 ] ; rtb_B_20_1278_0 [ 3 ] = _rtP -> P_313 *
_rtP -> P_312 [ 2 ] ; rtb_B_20_1278_0 [ 4 ] = _rtP -> P_311 ; rtb_B_20_1278_0
[ 5 ] = _rtP -> P_312 [ 0 ] ; rtb_B_20_1278_0 [ 6 ] = _rtP -> P_312 [ 1 ] ;
rtb_B_20_1278_0 [ 7 ] = _rtP -> P_313 * _rtP -> P_312 [ 0 ] ; rtb_B_20_1278_0
[ 8 ] = _rtP -> P_311 ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i
< 3 ; i ++ ) { _rtB -> B_20_1279_0 [ i_0 + 3 * i ] = 0.0 ; _rtB ->
B_20_1279_0 [ i_0 + 3 * i ] += rtb_B_20_1278_0 [ 3 * i ] * rtb_B_20_1278_0 [
i_0 ] ; _rtB -> B_20_1279_0 [ i_0 + 3 * i ] += rtb_B_20_1278_0 [ 3 * i + 1 ]
* rtb_B_20_1278_0 [ i_0 + 3 ] ; _rtB -> B_20_1279_0 [ i_0 + 3 * i ] +=
rtb_B_20_1278_0 [ 3 * i + 2 ] * rtb_B_20_1278_0 [ i_0 + 6 ] ; } }
rtb_B_20_1293_0 [ 0 ] = _rtP -> P_314 ; rtb_B_20_1293_0 [ 1 ] = _rtP -> P_315
[ 2 ] ; rtb_B_20_1293_0 [ 2 ] = _rtP -> P_316 * _rtP -> P_315 [ 1 ] ;
rtb_B_20_1293_0 [ 3 ] = _rtP -> P_316 * _rtP -> P_315 [ 2 ] ; rtb_B_20_1293_0
[ 4 ] = _rtP -> P_314 ; rtb_B_20_1293_0 [ 5 ] = _rtP -> P_315 [ 0 ] ;
rtb_B_20_1293_0 [ 6 ] = _rtP -> P_315 [ 1 ] ; rtb_B_20_1293_0 [ 7 ] = _rtP ->
P_316 * _rtP -> P_315 [ 0 ] ; rtb_B_20_1293_0 [ 8 ] = _rtP -> P_314 ; for (
i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
B_20_1294_0 [ i_0 + 3 * i ] = 0.0 ; _rtB -> B_20_1294_0 [ i_0 + 3 * i ] +=
rtb_B_20_1293_0 [ 3 * i ] * rtb_B_20_1278_0 [ i_0 ] ; _rtB -> B_20_1294_0 [
i_0 + 3 * i ] += rtb_B_20_1293_0 [ 3 * i + 1 ] * rtb_B_20_1278_0 [ i_0 + 3 ]
; _rtB -> B_20_1294_0 [ i_0 + 3 * i ] += rtb_B_20_1293_0 [ 3 * i + 2 ] *
rtb_B_20_1278_0 [ i_0 + 6 ] ; } } for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { for (
i = 0 ; i < 3 ; i ++ ) { _rtB -> B_20_1296_0 [ i_0 + 3 * i ] = 0.0 ; _rtB ->
B_20_1296_0 [ i_0 + 3 * i ] += rtb_B_20_1278_0 [ 3 * i ] * rtb_B_20_1293_0 [
i_0 ] ; _rtB -> B_20_1296_0 [ i_0 + 3 * i ] += rtb_B_20_1278_0 [ 3 * i + 1 ]
* rtb_B_20_1293_0 [ i_0 + 3 ] ; _rtB -> B_20_1296_0 [ i_0 + 3 * i ] +=
rtb_B_20_1278_0 [ 3 * i + 2 ] * rtb_B_20_1293_0 [ i_0 + 6 ] ; } } } for ( i =
0 ; i < 9 ; i ++ ) { rtb_B_20_574_0 [ i ] = ( ( ( ( rtb_B_20_892_0 * _rtB ->
B_20_1205_0 [ i ] + _rtB -> B_20_1333_0 [ 0 ] * _rtB -> B_20_1220_0 [ i ] ) +
_rtB -> B_20_1333_0 [ 0 ] * _rtB -> B_20_1222_0 [ i ] ) * _rtB -> B_20_1190_0
+ _rtB -> B_20_1188_0 [ i ] ) + ( ( rtb_B_20_37_0 * _rtB -> B_20_1242_0 [ i ]
+ _rtB -> B_20_1333_0 [ 1 ] * _rtB -> B_20_1257_0 [ i ] ) + _rtB ->
B_20_1333_0 [ 1 ] * _rtB -> B_20_1259_0 [ i ] ) * _rtB -> B_20_1227_0 ) + ( (
rtb_B_20_755_0 * _rtB -> B_20_1279_0 [ i ] + _rtB -> B_20_1333_0 [ 2 ] * _rtB
-> B_20_1294_0 [ i ] ) + _rtB -> B_20_1333_0 [ 2 ] * _rtB -> B_20_1296_0 [ i
] ) * _rtB -> B_20_1264_0 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( &
rtb_B_20_1301_0 [ 0 ] , & _rtP -> P_317 [ 0 ] , 9U * sizeof ( real_T ) ) ; }
rtb_B_20_468_0 = ( _rtB -> B_20_1187_1 [ 0 ] * _rtB -> B_20_1187_1 [ 0 ] +
_rtB -> B_20_1187_1 [ 1 ] * _rtB -> B_20_1187_1 [ 1 ] ) + _rtB -> B_20_1187_1
[ 2 ] * _rtB -> B_20_1187_1 [ 2 ] ; if ( rtb_B_20_468_0 < 0.0 ) { _rtB ->
B_20_1304_0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_468_0 ) ) ;
} else { _rtB -> B_20_1304_0 = muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; } _rtB
-> B_20_1305_0 [ 0 ] = _rtB -> B_20_1187_1 [ 0 ] * 0.0 ; _rtB -> B_20_1305_0
[ 1 ] = _rtB -> B_20_1187_1 [ 1 ] * 0.0 ; _rtB -> B_20_1305_0 [ 2 ] = _rtB ->
B_20_1187_1 [ 2 ] * 0.0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_1306_0 = _rtP -> P_318 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
Switch_Mode_b = ( _rtB -> B_20_1304_0 > _rtP -> P_319 ) ; } if ( _rtDW ->
Switch_Mode_b ) { B_20_43_0_idx = _rtB -> B_20_1187_1 [ 0 ] ; B_20_43_0_idx_1
= _rtB -> B_20_1187_1 [ 1 ] ; B_20_43_0_idx_2 = _rtB -> B_20_1187_1 [ 2 ] ; }
else { B_20_43_0_idx = _rtB -> B_20_1305_0 [ 0 ] ; B_20_43_0_idx_1 = _rtB ->
B_20_1305_0 [ 1 ] ; B_20_43_0_idx_2 = _rtB -> B_20_1305_0 [ 2 ] ; } if (
_rtDW -> Switch_Mode_b ) { B_20_43_0_idx_0 = _rtB -> B_20_1304_0 ; } else {
B_20_43_0_idx_0 = _rtB -> B_20_1306_0 ; } rtb_B_20_1077_0 = B_20_43_0_idx /
B_20_43_0_idx_0 ; rtb_B_20_57_0 = B_20_43_0_idx_1 / B_20_43_0_idx_0 ;
rtb_B_20_892_0 = B_20_43_0_idx_2 / B_20_43_0_idx_0 ; _rtB -> B_20_1322_0 [ 3
] = rtb_B_20_1077_0 ; _rtB -> B_20_1322_0 [ 4 ] = rtb_B_20_57_0 ; _rtB ->
B_20_1322_0 [ 5 ] = rtb_B_20_892_0 ; _rtB -> B_20_1311_0 [ 0 ] =
rtb_B_20_1339_0 [ 1 ] * _rtB -> B_20_1187_1 [ 2 ] - rtb_B_20_1339_0 [ 2 ] *
_rtB -> B_20_1187_1 [ 1 ] ; _rtB -> B_20_1311_0 [ 1 ] = rtb_B_20_1339_0 [ 2 ]
* _rtB -> B_20_1187_1 [ 0 ] - rtb_B_20_1339_0 [ 0 ] * _rtB -> B_20_1187_1 [ 2
] ; _rtB -> B_20_1311_0 [ 2 ] = rtb_B_20_1339_0 [ 0 ] * _rtB -> B_20_1187_1 [
1 ] - rtb_B_20_1339_0 [ 1 ] * _rtB -> B_20_1187_1 [ 0 ] ; rtb_B_20_468_0 = (
_rtB -> B_20_1311_0 [ 0 ] * _rtB -> B_20_1311_0 [ 0 ] + _rtB -> B_20_1311_0 [
1 ] * _rtB -> B_20_1311_0 [ 1 ] ) + _rtB -> B_20_1311_0 [ 2 ] * _rtB ->
B_20_1311_0 [ 2 ] ; if ( rtb_B_20_468_0 < 0.0 ) { _rtB -> B_20_1314_0 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( rtb_B_20_468_0 ) ) ; } else { _rtB
-> B_20_1314_0 = muDoubleScalarSqrt ( rtb_B_20_468_0 ) ; } _rtB ->
B_20_1315_0 [ 0 ] = _rtB -> B_20_1311_0 [ 0 ] * 0.0 ; _rtB -> B_20_1315_0 [ 1
] = _rtB -> B_20_1311_0 [ 1 ] * 0.0 ; _rtB -> B_20_1315_0 [ 2 ] = _rtB ->
B_20_1311_0 [ 2 ] * 0.0 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
B_20_1316_0 = _rtP -> P_320 ; } if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
Switch_Mode_p = ( _rtB -> B_20_1314_0 > _rtP -> P_321 ) ; } if ( _rtDW ->
Switch_Mode_p ) { B_20_43_0_idx = _rtB -> B_20_1311_0 [ 0 ] ; B_20_43_0_idx_1
= _rtB -> B_20_1311_0 [ 1 ] ; B_20_43_0_idx_2 = _rtB -> B_20_1311_0 [ 2 ] ; }
else { B_20_43_0_idx = _rtB -> B_20_1315_0 [ 0 ] ; B_20_43_0_idx_1 = _rtB ->
B_20_1315_0 [ 1 ] ; B_20_43_0_idx_2 = _rtB -> B_20_1315_0 [ 2 ] ; } if (
_rtDW -> Switch_Mode_p ) { B_20_43_0_idx_0 = _rtB -> B_20_1314_0 ; } else {
B_20_43_0_idx_0 = _rtB -> B_20_1316_0 ; } rtb_B_20_1339_0 [ 0 ] =
B_20_43_0_idx / B_20_43_0_idx_0 ; rtb_B_20_1339_0 [ 1 ] = B_20_43_0_idx_1 /
B_20_43_0_idx_0 ; rtb_B_20_1339_0 [ 2 ] = B_20_43_0_idx_2 / B_20_43_0_idx_0 ;
_rtB -> B_20_1322_0 [ 6 ] = rtb_B_20_1339_0 [ 0 ] ; _rtB -> B_20_1322_0 [ 7 ]
= rtb_B_20_1339_0 [ 1 ] ; _rtB -> B_20_1322_0 [ 8 ] = rtb_B_20_1339_0 [ 2 ] ;
_rtB -> B_20_1322_0 [ 0 ] = rtb_B_20_57_0 * rtb_B_20_1339_0 [ 2 ] -
rtb_B_20_892_0 * rtb_B_20_1339_0 [ 1 ] ; _rtB -> B_20_1322_0 [ 1 ] =
rtb_B_20_892_0 * rtb_B_20_1339_0 [ 0 ] - rtb_B_20_1077_0 * rtb_B_20_1339_0 [
2 ] ; _rtB -> B_20_1322_0 [ 2 ] = rtb_B_20_1077_0 * rtb_B_20_1339_0 [ 1 ] -
rtb_B_20_57_0 * rtb_B_20_1339_0 [ 0 ] ; _rtB -> B_20_1323_0 = ( _rtB ->
B_20_1322_0 [ 0 ] + _rtB -> B_20_1322_0 [ 4 ] ) + _rtB -> B_20_1322_0 [ 8 ] ;
rtPrevAction = _rtDW -> If_ActiveSubsystem_n ; if ( ssIsMajorTimeStep ( S ) )
{ if ( _rtB -> B_20_1323_0 > 0.0 ) { rtAction = 0 ; } else { rtAction = 1 ; }
_rtDW -> If_ActiveSubsystem_n = rtAction ; } else { rtAction = _rtDW ->
If_ActiveSubsystem_n ; } if ( rtPrevAction != rtAction ) { switch (
rtPrevAction ) { case 0 : ACStesbed1_PositiveTrace_Disable ( S ) ; break ;
case 1 : ACStesbed1_NegativeTrace_Disable ( S , & _rtDW -> NegativeTrace_o )
; break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction )
{ ACStesbed1_PositiveTrace_Enable ( S ) ; } ACStesbed1_PositiveTrace ( S ,
_rtB -> B_20_1323_0 , _rtB -> B_20_1322_0 [ 5 ] , _rtB -> B_20_1322_0 [ 7 ] ,
_rtB -> B_20_1322_0 [ 2 ] , _rtB -> B_20_1322_0 [ 6 ] , _rtB -> B_20_1322_0 [
1 ] , _rtB -> B_20_1322_0 [ 3 ] , & _rtB -> B_20_1327_0 [ 0 ] , & _rtB ->
B_20_1327_0 [ 1 ] , & _rtB -> PositiveTrace_f , & _rtDW -> PositiveTrace_f ,
( P_PositiveTrace_ACStesbed1_T * ) & _rtP -> PositiveTrace_f ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> PositiveTrace_f .
PositiveTrace_SubsysRanBC ) ; } break ; case 1 : if ( rtAction !=
rtPrevAction ) { ACStesbed1_NegativeTrace_Enable ( S ) ; }
ACStesbed1_NegativeTrace ( S , _rtB -> B_20_1322_0 [ 0 ] , _rtB ->
B_20_1322_0 [ 4 ] , _rtB -> B_20_1322_0 [ 8 ] , _rtB -> B_20_1322_0 [ 1 ] ,
_rtB -> B_20_1322_0 [ 3 ] , _rtB -> B_20_1322_0 [ 5 ] , _rtB -> B_20_1322_0 [
7 ] , _rtB -> B_20_1322_0 [ 2 ] , _rtB -> B_20_1322_0 [ 6 ] , & _rtB ->
B_20_1327_0 [ 0 ] , & _rtB -> B_20_1327_0 [ 1 ] , & _rtB -> B_20_1327_0 [ 2 ]
, & _rtB -> B_20_1327_0 [ 3 ] , & _rtB -> NegativeTrace_o , & _rtDW ->
NegativeTrace_o , ( P_NegativeTrace_ACStesbed1_T * ) & _rtP ->
NegativeTrace_o ) ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
NegativeTrace_o . NegativeTrace_SubsysRanBC ) ; } break ; } _rtB ->
B_20_1331_0 [ 0 ] = ( ( _rtB -> B_20_197_0 [ 1 ] * _rtB -> B_20_199_0 [ 2 ] -
_rtB -> B_20_197_0 [ 2 ] * _rtB -> B_20_199_0 [ 1 ] ) + _rtB -> B_20_1015_0 [
0 ] ) * _rtP -> P_323 ; _rtB -> B_20_1331_0 [ 1 ] = ( ( _rtB -> B_20_197_0 [
2 ] * _rtB -> B_20_199_0 [ 0 ] - _rtB -> B_20_197_0 [ 0 ] * _rtB ->
B_20_199_0 [ 2 ] ) + _rtB -> B_20_1015_0 [ 1 ] ) * _rtP -> P_323 ; _rtB ->
B_20_1331_0 [ 2 ] = ( ( _rtB -> B_20_197_0 [ 0 ] * _rtB -> B_20_199_0 [ 1 ] -
_rtB -> B_20_197_0 [ 1 ] * _rtB -> B_20_199_0 [ 0 ] ) + _rtB -> B_20_1015_0 [
2 ] ) * _rtP -> P_323 ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
Saturation_MODE_k [ 0 ] = _rtB -> B_20_1331_0 [ 0 ] >= _rtP -> P_324 ? 1 :
_rtB -> B_20_1331_0 [ 0 ] > _rtP -> P_325 ? 0 : - 1 ; _rtDW ->
Saturation_MODE_k [ 1 ] = _rtB -> B_20_1331_0 [ 1 ] >= _rtP -> P_324 ? 1 :
_rtB -> B_20_1331_0 [ 1 ] > _rtP -> P_325 ? 0 : - 1 ; _rtDW ->
Saturation_MODE_k [ 2 ] = _rtB -> B_20_1331_0 [ 2 ] >= _rtP -> P_324 ? 1 :
_rtB -> B_20_1331_0 [ 2 ] > _rtP -> P_325 ? 0 : - 1 ; } _rtB -> B_20_1332_0 [
0 ] = _rtDW -> Saturation_MODE_k [ 0 ] == 1 ? _rtP -> P_324 : _rtDW ->
Saturation_MODE_k [ 0 ] == - 1 ? _rtP -> P_325 : _rtB -> B_20_1331_0 [ 0 ] ;
_rtB -> B_20_1332_0 [ 1 ] = _rtDW -> Saturation_MODE_k [ 1 ] == 1 ? _rtP ->
P_324 : _rtDW -> Saturation_MODE_k [ 1 ] == - 1 ? _rtP -> P_325 : _rtB ->
B_20_1331_0 [ 1 ] ; _rtB -> B_20_1332_0 [ 2 ] = _rtDW -> Saturation_MODE_k [
2 ] == 1 ? _rtP -> P_324 : _rtDW -> Saturation_MODE_k [ 2 ] == - 1 ? _rtP ->
P_325 : _rtB -> B_20_1331_0 [ 2 ] ; _rtB -> B_20_1333_0 [ 0 ] = ( ( _rtB ->
B_20_1332_0 [ 0 ] + 0.0 ) + 0.0 ) + 0.0 ; _rtB -> B_20_1333_0 [ 1 ] = ( (
_rtB -> B_20_1332_0 [ 1 ] + 0.0 ) + 0.0 ) + 0.0 ; _rtB -> B_20_1333_0 [ 2 ] =
( ( _rtB -> B_20_1332_0 [ 2 ] + 0.0 ) + 0.0 ) + 0.0 ; ssCallAccelRunBlock ( S
, 20 , 1334 , SS_CALL_MDL_OUTPUTS ) ; for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) {
rtb_B_20_1339_0 [ i_0 ] = rtb_B_20_574_0 [ i_0 + 6 ] * _rtB -> B_20_197_0 [ 2
] + ( rtb_B_20_574_0 [ i_0 + 3 ] * _rtB -> B_20_197_0 [ 1 ] + rtb_B_20_574_0
[ i_0 ] * _rtB -> B_20_197_0 [ 0 ] ) ; } rtb_B_20_21_0 [ 1 ] = _rtB ->
B_20_197_0 [ 2 ] * rtb_B_20_1339_0 [ 0 ] ; rtb_B_20_21_0 [ 2 ] = _rtB ->
B_20_197_0 [ 0 ] * rtb_B_20_1339_0 [ 1 ] ; rtb_B_20_21_0 [ 4 ] = _rtB ->
B_20_197_0 [ 0 ] * rtb_B_20_1339_0 [ 2 ] ; rtb_B_20_21_0 [ 5 ] = _rtB ->
B_20_197_0 [ 1 ] * rtb_B_20_1339_0 [ 0 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ for ( i_0 = 0 ; i_0 < 3 ; i_0 ++ ) { _rtB -> B_20_1338_0 [ i_0 ] = 0.0 ;
_rtB -> B_20_1338_0 [ i_0 ] += rtb_B_20_1301_0 [ i_0 ] * _rtB -> B_20_197_0 [
0 ] ; _rtB -> B_20_1338_0 [ i_0 ] += rtb_B_20_1301_0 [ i_0 + 3 ] * _rtB ->
B_20_197_0 [ 1 ] ; _rtB -> B_20_1338_0 [ i_0 ] += rtb_B_20_1301_0 [ i_0 + 6 ]
* _rtB -> B_20_197_0 [ 2 ] ; } } rtb_B_20_1339_0 [ 0 ] = ( _rtB ->
B_20_1333_0 [ 0 ] - _rtB -> B_20_1338_0 [ 0 ] ) - ( _rtB -> B_20_197_0 [ 1 ]
* rtb_B_20_1339_0 [ 2 ] - _rtB -> B_20_197_0 [ 2 ] * rtb_B_20_1339_0 [ 1 ] )
; rtb_B_20_1339_0 [ 1 ] = ( _rtB -> B_20_1333_0 [ 1 ] - _rtB -> B_20_1338_0 [
1 ] ) - ( rtb_B_20_21_0 [ 1 ] - rtb_B_20_21_0 [ 4 ] ) ; rtb_B_20_1339_0 [ 2 ]
= ( _rtB -> B_20_1333_0 [ 2 ] - _rtB -> B_20_1338_0 [ 2 ] ) - ( rtb_B_20_21_0
[ 2 ] - rtb_B_20_21_0 [ 5 ] ) ; rt_mldivide_U1d3x3_U2d3_Yd3x1_snf (
rtb_B_20_574_0 , rtb_B_20_1339_0 , _rtB -> B_20_1340_0 ) ; if ( ssIsSampleHit
( S , 5 , 0 ) ) { ssCallAccelRunBlock ( S , 20 , 1341 , SS_CALL_MDL_OUTPUTS )
; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 20 , 1342
, SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 20 , 1343 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 20 , 1344 ,
SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_ACStesbed1_T * _rtB ;
P_ACStesbed1_T * _rtP ; DW_ACStesbed1_T * _rtDW ; _rtDW = ( ( DW_ACStesbed1_T
* ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_ACStesbed1_T * ) ssGetDefaultParam
( S ) ) ; _rtB = ( ( B_ACStesbed1_T * ) _ssGetBlockIO ( S ) ) ; _rtDW ->
q0q1q2q3_IWORK . IcNeedsLoading = 0 ; _rtDW -> Integrator_IWORK .
IcNeedsLoading = 0 ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtDW -> NextOutput
= rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed ) * _rtP -> P_64 + _rtP ->
P_63 ; } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ]
== _rtP -> P_68 ) { switch ( _rtDW -> IntegratorLimited_MODE [ 0 ] ) { case
INTG_UPPER_SAT : if ( _rtB -> B_20_291_0 [ 0 ] < 0.0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> IntegratorLimited_MODE [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( _rtB ->
B_20_291_0 [ 0 ] >= 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 0 ] =
INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S ) ; } break ; default :
ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_291_0 [ 0 ] < 0.0 ) { _rtDW
-> IntegratorLimited_MODE [ 0 ] = INTG_LEAVING_UPPER_SAT ; } else { _rtDW ->
IntegratorLimited_MODE [ 0 ] = INTG_UPPER_SAT ; } break ; } } else if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ]
== _rtP -> P_69 ) { switch ( _rtDW -> IntegratorLimited_MODE [ 0 ] ) { case
INTG_LOWER_SAT : if ( _rtB -> B_20_291_0 [ 0 ] > 0.0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> IntegratorLimited_MODE [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( _rtB ->
B_20_291_0 [ 0 ] <= 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 0 ] =
INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S ) ; } break ; default :
ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_291_0 [ 0 ] > 0.0 ) { _rtDW
-> IntegratorLimited_MODE [ 0 ] = INTG_LEAVING_LOWER_SAT ; } else { _rtDW ->
IntegratorLimited_MODE [ 0 ] = INTG_LOWER_SAT ; } break ; } } else { _rtDW ->
IntegratorLimited_MODE [ 0 ] = INTG_NORMAL ; } if ( ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] == _rtP -> P_68 ) {
switch ( _rtDW -> IntegratorLimited_MODE [ 1 ] ) { case INTG_UPPER_SAT : if (
_rtB -> B_20_291_0 [ 1 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE [ 1 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_20_291_0 [ 1 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE [ 1 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S ) ;
} break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_291_0 [ 1
] < 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_LEAVING_UPPER_SAT ;
} else { _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_UPPER_SAT ; } break ; }
} else if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE [ 1 ] == _rtP -> P_69 ) { switch ( _rtDW ->
IntegratorLimited_MODE [ 1 ] ) { case INTG_LOWER_SAT : if ( _rtB ->
B_20_291_0 [ 1 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE [ 1 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_20_291_0 [ 1 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE [ 1 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S ) ;
} break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_291_0 [ 1
] > 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_LEAVING_LOWER_SAT ;
} else { _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_LOWER_SAT ; } break ; }
} else { _rtDW -> IntegratorLimited_MODE [ 1 ] = INTG_NORMAL ; } if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ]
== _rtP -> P_68 ) { switch ( _rtDW -> IntegratorLimited_MODE [ 2 ] ) { case
INTG_UPPER_SAT : if ( _rtB -> B_20_291_0 [ 2 ] < 0.0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> IntegratorLimited_MODE [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } break ; case INTG_LEAVING_UPPER_SAT : if ( _rtB ->
B_20_291_0 [ 2 ] >= 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 2 ] =
INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S ) ; } break ; default :
ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_291_0 [ 2 ] < 0.0 ) { _rtDW
-> IntegratorLimited_MODE [ 2 ] = INTG_LEAVING_UPPER_SAT ; } else { _rtDW ->
IntegratorLimited_MODE [ 2 ] = INTG_UPPER_SAT ; } break ; } } else if ( ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ]
== _rtP -> P_69 ) { switch ( _rtDW -> IntegratorLimited_MODE [ 2 ] ) { case
INTG_LOWER_SAT : if ( _rtB -> B_20_291_0 [ 2 ] > 0.0 ) {
ssSetSolverNeedsReset ( S ) ; _rtDW -> IntegratorLimited_MODE [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } break ; case INTG_LEAVING_LOWER_SAT : if ( _rtB ->
B_20_291_0 [ 2 ] <= 0.0 ) { _rtDW -> IntegratorLimited_MODE [ 2 ] =
INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S ) ; } break ; default :
ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_291_0 [ 2 ] > 0.0 ) { _rtDW
-> IntegratorLimited_MODE [ 2 ] = INTG_LEAVING_LOWER_SAT ; } else { _rtDW ->
IntegratorLimited_MODE [ 2 ] = INTG_LOWER_SAT ; } break ; } } else { _rtDW ->
IntegratorLimited_MODE [ 2 ] = INTG_NORMAL ; } } if ( ssIsSampleHit ( S , 5 ,
0 ) ) { _rtDW -> DiscreteTimeIntegrator_DSTATE [ 0 ] += _rtP -> P_72 * _rtB
-> B_20_1340_0 [ 0 ] ; _rtDW -> DiscreteTimeIntegrator_DSTATE [ 1 ] += _rtP
-> P_72 * _rtB -> B_20_1340_0 [ 1 ] ; _rtDW -> DiscreteTimeIntegrator_DSTATE
[ 2 ] += _rtP -> P_72 * _rtB -> B_20_1340_0 [ 2 ] ; } { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 0 ] == _rtP -> P_74 ) { switch ( _rtDW ->
IntegratorLimited_MODE_l [ 0 ] ) { case INTG_UPPER_SAT : if ( _rtB ->
B_20_1012_0 [ 0 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_l [ 0 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_20_1012_0 [ 0 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_l [ 0 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1012_0
[ 0 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_l [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_l [ 0 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 0 ] == _rtP -> P_75 )
{ switch ( _rtDW -> IntegratorLimited_MODE_l [ 0 ] ) { case INTG_LOWER_SAT :
if ( _rtB -> B_20_1012_0 [ 0 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW
-> IntegratorLimited_MODE_l [ 0 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_20_1012_0 [ 0 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_l [ 0 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1012_0
[ 0 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_l [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_l [ 0 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_l [ 0 ]
= INTG_NORMAL ; } if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 1 ] == _rtP -> P_74 ) { switch ( _rtDW ->
IntegratorLimited_MODE_l [ 1 ] ) { case INTG_UPPER_SAT : if ( _rtB ->
B_20_1012_0 [ 1 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_l [ 1 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_20_1012_0 [ 1 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_l [ 1 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1012_0
[ 1 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_l [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_l [ 1 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 1 ] == _rtP -> P_75 )
{ switch ( _rtDW -> IntegratorLimited_MODE_l [ 1 ] ) { case INTG_LOWER_SAT :
if ( _rtB -> B_20_1012_0 [ 1 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW
-> IntegratorLimited_MODE_l [ 1 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_20_1012_0 [ 1 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_l [ 1 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1012_0
[ 1 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_l [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_l [ 1 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_l [ 1 ]
= INTG_NORMAL ; } if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_m [ 2 ] == _rtP -> P_74 ) { switch ( _rtDW ->
IntegratorLimited_MODE_l [ 2 ] ) { case INTG_UPPER_SAT : if ( _rtB ->
B_20_1012_0 [ 2 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_l [ 2 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_20_1012_0 [ 2 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_l [ 2 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1012_0
[ 2 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_l [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_l [ 2 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 2 ] == _rtP -> P_75 )
{ switch ( _rtDW -> IntegratorLimited_MODE_l [ 2 ] ) { case INTG_LOWER_SAT :
if ( _rtB -> B_20_1012_0 [ 2 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW
-> IntegratorLimited_MODE_l [ 2 ] = INTG_LEAVING_LOWER_SAT ; } break ; case
INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_20_1012_0 [ 2 ] <= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_l [ 2 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1012_0
[ 2 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_l [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_l [ 2 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_l [ 2 ]
= INTG_NORMAL ; } } if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtDW ->
DiscreteTimeIntegrator_IC_LOADING = 0U ; memcpy ( & _rtDW ->
DiscreteTimeIntegrator_DSTATE_i [ 0 ] , & _rtB -> B_20_324_0 [ 0 ] , 18U *
sizeof ( real_T ) ) ; _rtDW -> DiscreteTimeIntegrator1_SYSTEM_ENABLE = 0U ;
memcpy ( & _rtDW -> DiscreteTimeIntegrator1_DSTATE [ 0 ] , & _rtB ->
B_20_400_0 [ 18 ] , 9U * sizeof ( real_T ) ) ; _rtDW ->
DiscreteTimeIntegrator2_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE [ 0 ] = _rtB -> B_20_404_0 [ 0 ] ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE [ 1 ] = _rtB -> B_20_404_0 [ 1 ] ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE [ 2 ] = _rtB -> B_20_404_0 [ 2 ] ; } _rtDW ->
q0q1q2q3_IWORK_p . IcNeedsLoading = 0 ; if ( ssIsSampleHit ( S , 4 , 0 ) ) {
_rtDW -> NextOutput_d = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_o )
* _rtP -> P_196 + _rtP -> P_195 ; } { enum { INTG_NORMAL ,
INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT ,
INTG_LOWER_SAT } ; if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 0 ] == _rtP -> P_215 ) { switch ( _rtDW ->
IntegratorLimited_MODE_p [ 0 ] ) { case INTG_UPPER_SAT : if ( _rtB ->
B_20_1016_0 [ 0 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_p [ 0 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_20_1016_0 [ 0 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_p [ 0 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1016_0
[ 0 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_p [ 0 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_p [ 0 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0 ] == _rtP -> P_216
) { switch ( _rtDW -> IntegratorLimited_MODE_p [ 0 ] ) { case INTG_LOWER_SAT
: if ( _rtB -> B_20_1016_0 [ 0 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ;
_rtDW -> IntegratorLimited_MODE_p [ 0 ] = INTG_LEAVING_LOWER_SAT ; } break ;
case INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_20_1016_0 [ 0 ] <= 0.0 ) { _rtDW
-> IntegratorLimited_MODE_p [ 0 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset (
S ) ; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB ->
B_20_1016_0 [ 0 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_p [ 0 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_p [ 0 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_p [ 0 ]
= INTG_NORMAL ; } if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 1 ] == _rtP -> P_215 ) { switch ( _rtDW ->
IntegratorLimited_MODE_p [ 1 ] ) { case INTG_UPPER_SAT : if ( _rtB ->
B_20_1016_0 [ 1 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_p [ 1 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_20_1016_0 [ 1 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_p [ 1 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1016_0
[ 1 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_p [ 1 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_p [ 1 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 1 ] == _rtP -> P_216
) { switch ( _rtDW -> IntegratorLimited_MODE_p [ 1 ] ) { case INTG_LOWER_SAT
: if ( _rtB -> B_20_1016_0 [ 1 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ;
_rtDW -> IntegratorLimited_MODE_p [ 1 ] = INTG_LEAVING_LOWER_SAT ; } break ;
case INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_20_1016_0 [ 1 ] <= 0.0 ) { _rtDW
-> IntegratorLimited_MODE_p [ 1 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset (
S ) ; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB ->
B_20_1016_0 [ 1 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_p [ 1 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_p [ 1 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_p [ 1 ]
= INTG_NORMAL ; } if ( ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 2 ] == _rtP -> P_215 ) { switch ( _rtDW ->
IntegratorLimited_MODE_p [ 2 ] ) { case INTG_UPPER_SAT : if ( _rtB ->
B_20_1016_0 [ 2 ] < 0.0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW ->
IntegratorLimited_MODE_p [ 2 ] = INTG_LEAVING_UPPER_SAT ; } break ; case
INTG_LEAVING_UPPER_SAT : if ( _rtB -> B_20_1016_0 [ 2 ] >= 0.0 ) { _rtDW ->
IntegratorLimited_MODE_p [ 2 ] = INTG_UPPER_SAT ; ssSetSolverNeedsReset ( S )
; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB -> B_20_1016_0
[ 2 ] < 0.0 ) { _rtDW -> IntegratorLimited_MODE_p [ 2 ] =
INTG_LEAVING_UPPER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_p [ 2 ] =
INTG_UPPER_SAT ; } break ; } } else if ( ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 2 ] == _rtP -> P_216
) { switch ( _rtDW -> IntegratorLimited_MODE_p [ 2 ] ) { case INTG_LOWER_SAT
: if ( _rtB -> B_20_1016_0 [ 2 ] > 0.0 ) { ssSetSolverNeedsReset ( S ) ;
_rtDW -> IntegratorLimited_MODE_p [ 2 ] = INTG_LEAVING_LOWER_SAT ; } break ;
case INTG_LEAVING_LOWER_SAT : if ( _rtB -> B_20_1016_0 [ 2 ] <= 0.0 ) { _rtDW
-> IntegratorLimited_MODE_p [ 2 ] = INTG_LOWER_SAT ; ssSetSolverNeedsReset (
S ) ; } break ; default : ssSetSolverNeedsReset ( S ) ; if ( _rtB ->
B_20_1016_0 [ 2 ] > 0.0 ) { _rtDW -> IntegratorLimited_MODE_p [ 2 ] =
INTG_LEAVING_LOWER_SAT ; } else { _rtDW -> IntegratorLimited_MODE_p [ 2 ] =
INTG_LOWER_SAT ; } break ; } } else { _rtDW -> IntegratorLimited_MODE_p [ 2 ]
= INTG_NORMAL ; } } _rtDW -> q0q1q2q3_IWORK_g . IcNeedsLoading = 0 ; if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtDW -> DiscreteTimeIntegrator_IC_LOADING_p
= 0U ; memcpy ( & _rtDW -> DiscreteTimeIntegrator_DSTATE_p [ 0 ] , & _rtB ->
B_20_1047_0 [ 0 ] , 18U * sizeof ( real_T ) ) ; _rtDW ->
DiscreteTimeIntegrator1_SYSTEM_ENABLE_o = 0U ; memcpy ( & _rtDW ->
DiscreteTimeIntegrator1_DSTATE_f [ 0 ] , & _rtB -> B_20_1123_0 [ 18 ] , 9U *
sizeof ( real_T ) ) ; _rtDW -> DiscreteTimeIntegrator2_SYSTEM_ENABLE_c = 0U ;
_rtDW -> DiscreteTimeIntegrator2_DSTATE_n [ 0 ] = _rtB -> B_20_1127_0 [ 0 ] ;
_rtDW -> DiscreteTimeIntegrator2_DSTATE_n [ 1 ] = _rtB -> B_20_1127_0 [ 1 ] ;
_rtDW -> DiscreteTimeIntegrator2_DSTATE_n [ 2 ] = _rtB -> B_20_1127_0 [ 2 ] ;
} UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_ACStesbed1_T * _rtB ;
P_ACStesbed1_T * _rtP ; DW_ACStesbed1_T * _rtDW ; _rtDW = ( ( DW_ACStesbed1_T
* ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_ACStesbed1_T * ) ssGetDefaultParam
( S ) ) ; _rtB = ( ( B_ACStesbed1_T * ) _ssGetBlockIO ( S ) ) ; { ( (
XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE [ 0 ] = _rtB ->
B_20_435_0 ; ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE [ 1
] = _rtB -> B_20_436_0 ; ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) ->
q0q1q2q3_CSTATE [ 2 ] = _rtB -> B_20_437_0 ; ( ( XDot_ACStesbed1_T * )
ssGetdX ( S ) ) -> q0q1q2q3_CSTATE [ 3 ] = _rtB -> B_20_438_0 ; } { ( (
XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE [ 0 ] = _rtB ->
B_20_733_0 [ 0 ] ; ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) ->
Integrator_CSTATE [ 1 ] = _rtB -> B_20_733_0 [ 1 ] ; ( ( XDot_ACStesbed1_T *
) ssGetdX ( S ) ) -> Integrator_CSTATE [ 2 ] = _rtB -> B_20_733_0 [ 2 ] ; } {
( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE_n [ 0 ] = _rtB
-> B_20_756_0 [ 0 ] ; ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) ->
Integrator_CSTATE_n [ 1 ] = _rtB -> B_20_756_0 [ 1 ] ; ( ( XDot_ACStesbed1_T
* ) ssGetdX ( S ) ) -> Integrator_CSTATE_n [ 2 ] = _rtB -> B_20_756_0 [ 2 ] ;
} { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( _rtDW -> IntegratorLimited_MODE [
0 ] != INTG_UPPER_SAT ) && ( _rtDW -> IntegratorLimited_MODE [ 0 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) ->
IntegratorLimited_CSTATE [ 0 ] = _rtB -> B_20_291_0 [ 0 ] ; ( (
XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE [ 0 ] = FALSE ; } else { ( ( XDot_ACStesbed1_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE [ 0 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE [ 0 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed1_T *
) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] = TRUE ; }
} if ( ( _rtDW -> IntegratorLimited_MODE [ 1 ] != INTG_UPPER_SAT ) && ( _rtDW
-> IntegratorLimited_MODE [ 1 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed1_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = _rtB -> B_20_291_0 [
1 ] ; ( ( XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE [ 1 ] = FALSE ; } else { ( ( XDot_ACStesbed1_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE [ 1 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE [ 1 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed1_T *
) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] = TRUE ; }
} if ( ( _rtDW -> IntegratorLimited_MODE [ 2 ] != INTG_UPPER_SAT ) && ( _rtDW
-> IntegratorLimited_MODE [ 2 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed1_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = _rtB -> B_20_291_0 [
2 ] ; ( ( XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE [ 2 ] = FALSE ; } else { ( ( XDot_ACStesbed1_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE [ 2 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE [ 2 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed1_T *
) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] = TRUE ; }
} } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( _rtDW -> IntegratorLimited_MODE_l
[ 0 ] != INTG_UPPER_SAT ) && ( _rtDW -> IntegratorLimited_MODE_l [ 0 ] !=
INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) ->
IntegratorLimited_CSTATE_m [ 0 ] = _rtB -> B_20_1012_0 [ 0 ] ; ( (
XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE_m [ 0 ] = FALSE ; } else { ( ( XDot_ACStesbed1_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_m [ 0 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE_l [ 0 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE_l [ 0 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed1_T
* ) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE_m [ 0 ] = TRUE
; } } if ( ( _rtDW -> IntegratorLimited_MODE_l [ 1 ] != INTG_UPPER_SAT ) && (
_rtDW -> IntegratorLimited_MODE_l [ 1 ] != INTG_LOWER_SAT ) ) { ( (
XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_m [ 1 ] =
_rtB -> B_20_1012_0 [ 1 ] ; ( ( XDis_ACStesbed1_T * ) ssGetContStateDisabled
( S ) ) -> IntegratorLimited_CSTATE_m [ 1 ] = FALSE ; } else { ( (
XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_m [ 1 ] =
0.0 ; if ( ( _rtDW -> IntegratorLimited_MODE_l [ 1 ] == INTG_UPPER_SAT ) || (
_rtDW -> IntegratorLimited_MODE_l [ 1 ] == INTG_LOWER_SAT ) ) { ( (
XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE_m [ 1 ] = TRUE ; } } if ( ( _rtDW ->
IntegratorLimited_MODE_l [ 2 ] != INTG_UPPER_SAT ) && ( _rtDW ->
IntegratorLimited_MODE_l [ 2 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed1_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_m [ 2 ] = _rtB -> B_20_1012_0
[ 2 ] ; ( ( XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE_m [ 2 ] = FALSE ; } else { ( ( XDot_ACStesbed1_T * )
ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_m [ 2 ] = 0.0 ; if ( ( _rtDW ->
IntegratorLimited_MODE_l [ 2 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE_l [ 2 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed1_T
* ) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE_m [ 2 ] = TRUE
; } } } { ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_i [ 0
] = _rtB -> B_20_738_0 ; ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) ->
q0q1q2q3_CSTATE_i [ 1 ] = _rtB -> B_20_739_0 ; ( ( XDot_ACStesbed1_T * )
ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_i [ 2 ] = _rtB -> B_20_740_0 ; ( (
XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_i [ 3 ] = _rtB ->
B_20_741_0 ; } { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( ( _rtDW ->
IntegratorLimited_MODE_p [ 0 ] != INTG_UPPER_SAT ) && ( _rtDW ->
IntegratorLimited_MODE_p [ 0 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed1_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0 ] = _rtB ->
B_20_1016_0 [ 0 ] ; ( ( XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) )
-> IntegratorLimited_CSTATE_ml [ 0 ] = FALSE ; } else { ( ( XDot_ACStesbed1_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0 ] = 0.0 ; if ( ( _rtDW
-> IntegratorLimited_MODE_p [ 0 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE_p [ 0 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed1_T
* ) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0 ] =
TRUE ; } } if ( ( _rtDW -> IntegratorLimited_MODE_p [ 1 ] != INTG_UPPER_SAT )
&& ( _rtDW -> IntegratorLimited_MODE_p [ 1 ] != INTG_LOWER_SAT ) ) { ( (
XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_ml [ 1 ] =
_rtB -> B_20_1016_0 [ 1 ] ; ( ( XDis_ACStesbed1_T * ) ssGetContStateDisabled
( S ) ) -> IntegratorLimited_CSTATE_ml [ 1 ] = FALSE ; } else { ( (
XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_ml [ 1 ] =
0.0 ; if ( ( _rtDW -> IntegratorLimited_MODE_p [ 1 ] == INTG_UPPER_SAT ) || (
_rtDW -> IntegratorLimited_MODE_p [ 1 ] == INTG_LOWER_SAT ) ) { ( (
XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) ) ->
IntegratorLimited_CSTATE_ml [ 1 ] = TRUE ; } } if ( ( _rtDW ->
IntegratorLimited_MODE_p [ 2 ] != INTG_UPPER_SAT ) && ( _rtDW ->
IntegratorLimited_MODE_p [ 2 ] != INTG_LOWER_SAT ) ) { ( ( XDot_ACStesbed1_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_ml [ 2 ] = _rtB ->
B_20_1016_0 [ 2 ] ; ( ( XDis_ACStesbed1_T * ) ssGetContStateDisabled ( S ) )
-> IntegratorLimited_CSTATE_ml [ 2 ] = FALSE ; } else { ( ( XDot_ACStesbed1_T
* ) ssGetdX ( S ) ) -> IntegratorLimited_CSTATE_ml [ 2 ] = 0.0 ; if ( ( _rtDW
-> IntegratorLimited_MODE_p [ 2 ] == INTG_UPPER_SAT ) || ( _rtDW ->
IntegratorLimited_MODE_p [ 2 ] == INTG_LOWER_SAT ) ) { ( ( XDis_ACStesbed1_T
* ) ssGetContStateDisabled ( S ) ) -> IntegratorLimited_CSTATE_ml [ 2 ] =
TRUE ; } } } { ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_j
[ 0 ] = _rtB -> B_20_1157_0 ; ( ( XDot_ACStesbed1_T * ) ssGetdX ( S ) ) ->
q0q1q2q3_CSTATE_j [ 1 ] = _rtB -> B_20_1158_0 ; ( ( XDot_ACStesbed1_T * )
ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_j [ 2 ] = _rtB -> B_20_1159_0 ; ( (
XDot_ACStesbed1_T * ) ssGetdX ( S ) ) -> q0q1q2q3_CSTATE_j [ 3 ] = _rtB ->
B_20_1160_0 ; } }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_ACStesbed1_T * _rtB ;
P_ACStesbed1_T * _rtP ; ZCV_ACStesbed1_T * _rtZCSV ; DW_ACStesbed1_T * _rtDW
; _rtDW = ( ( DW_ACStesbed1_T * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( (
P_ACStesbed1_T * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_ACStesbed1_T * )
_ssGetBlockIO ( S ) ) ; if ( _rtDW -> If_ActiveSubsystem == 1 ) { } _rtZCSV
-> Switch_SwitchCond_ZC = _rtB -> B_20_87_0 - _rtP -> P_43 ; { enum {
INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( _rtDW -> IntegratorLimited_MODE [ 0
] == INTG_LEAVING_UPPER_SAT && ( ( X_ACStesbed1_T * ) ssGetContStates ( S ) )
-> IntegratorLimited_CSTATE [ 0 ] >= _rtP -> P_68 ) { ( ( ZCV_ACStesbed1_T *
) ssGetSolverZcSignalVector ( S ) ) -> IntegratorLimited_IntgUpLimit_ZC [ 0 ]
= 0.0 ; } else { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) )
-> IntegratorLimited_IntgUpLimit_ZC [ 0 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] - _rtP -> P_68 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 0 ] == INTG_LEAVING_LOWER_SAT && ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ]
<= _rtP -> P_69 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgLoLimit_ZC [ 0 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC [ 0 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 0 ] - _rtP -> P_69 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 1 ] == INTG_LEAVING_UPPER_SAT && ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ]
>= _rtP -> P_68 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgUpLimit_ZC [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC [ 1 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] - _rtP -> P_68 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 1 ] == INTG_LEAVING_LOWER_SAT && ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ]
<= _rtP -> P_69 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgLoLimit_ZC [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC [ 1 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 1 ] - _rtP -> P_69 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 2 ] == INTG_LEAVING_UPPER_SAT && ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ]
>= _rtP -> P_68 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgUpLimit_ZC [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC [ 2 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] - _rtP -> P_68 ; }
if ( _rtDW -> IntegratorLimited_MODE [ 2 ] == INTG_LEAVING_LOWER_SAT && ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ]
<= _rtP -> P_69 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S )
) -> IntegratorLimited_IntgLoLimit_ZC [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC [ 2 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE [ 2 ] - _rtP -> P_69 ; }
} { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT , INTG_LEAVING_LOWER_SAT ,
INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( _rtDW -> IntegratorLimited_MODE_l [
0 ] == INTG_LEAVING_UPPER_SAT && ( ( X_ACStesbed1_T * ) ssGetContStates ( S )
) -> IntegratorLimited_CSTATE_m [ 0 ] >= _rtP -> P_74 ) { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_m [ 0 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_m [ 0 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 0 ] - _rtP -> P_74 ;
} if ( _rtDW -> IntegratorLimited_MODE_l [ 0 ] == INTG_LEAVING_LOWER_SAT && (
( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [
0 ] <= _rtP -> P_75 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector (
S ) ) -> IntegratorLimited_IntgLoLimit_ZC_j [ 0 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_j [ 0 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 0 ] - _rtP -> P_75 ;
} if ( _rtDW -> IntegratorLimited_MODE_l [ 1 ] == INTG_LEAVING_UPPER_SAT && (
( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [
1 ] >= _rtP -> P_74 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector (
S ) ) -> IntegratorLimited_IntgUpLimit_ZC_m [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_m [ 1 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 1 ] - _rtP -> P_74 ;
} if ( _rtDW -> IntegratorLimited_MODE_l [ 1 ] == INTG_LEAVING_LOWER_SAT && (
( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [
1 ] <= _rtP -> P_75 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector (
S ) ) -> IntegratorLimited_IntgLoLimit_ZC_j [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_j [ 1 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 1 ] - _rtP -> P_75 ;
} if ( _rtDW -> IntegratorLimited_MODE_l [ 2 ] == INTG_LEAVING_UPPER_SAT && (
( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [
2 ] >= _rtP -> P_74 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector (
S ) ) -> IntegratorLimited_IntgUpLimit_ZC_m [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_m [ 2 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 2 ] - _rtP -> P_74 ;
} if ( _rtDW -> IntegratorLimited_MODE_l [ 2 ] == INTG_LEAVING_LOWER_SAT && (
( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [
2 ] <= _rtP -> P_75 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector (
S ) ) -> IntegratorLimited_IntgLoLimit_ZC_j [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_j [ 2 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_m [ 2 ] - _rtP -> P_75 ;
} } _rtZCSV -> Saturation_UprLim_ZC [ 0 ] = _rtB -> B_20_289_0 [ 0 ] - _rtP
-> P_95 ; _rtZCSV -> Saturation_LwrLim_ZC [ 0 ] = _rtB -> B_20_289_0 [ 0 ] -
_rtP -> P_96 ; _rtZCSV -> Saturation_UprLim_ZC [ 1 ] = _rtB -> B_20_289_0 [ 1
] - _rtP -> P_95 ; _rtZCSV -> Saturation_LwrLim_ZC [ 1 ] = _rtB -> B_20_289_0
[ 1 ] - _rtP -> P_96 ; _rtZCSV -> Saturation_UprLim_ZC [ 2 ] = _rtB ->
B_20_289_0 [ 2 ] - _rtP -> P_95 ; _rtZCSV -> Saturation_LwrLim_ZC [ 2 ] =
_rtB -> B_20_289_0 [ 2 ] - _rtP -> P_96 ; _rtZCSV -> Switch_SwitchCond_ZC_p =
_rtB -> B_20_76_0 [ 0 ] - _rtP -> P_126 ; _rtZCSV -> Switch_SwitchCond_ZC_b =
_rtB -> B_20_582_0 - _rtP -> P_162 ; _rtZCSV -> Switch_SwitchCond_ZC_j = _rtB
-> B_20_592_0 - _rtP -> P_164 ; _rtZCSV -> If_IfInput_ZC = 0.0 ; if ( _rtB ->
B_20_601_0 > 0.0 ) { _rtZCSV -> If_IfInput_ZC = 1.0 ; } { real_T * zcsv = & (
( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) -> NegativeTrace_f
. FindMaximumDiagonalValue_IfInput_ZC [ 0 ] ) ; int_T i ; for ( i = 0 ; i < 5
; i ++ ) { zcsv [ i ] = 0.0 ; } } if ( _rtDW -> If_ActiveSubsystem_f == 1 ) {
ACStesbed1_NegativeTrace_ZC ( _rtB -> B_20_600_0 [ 0 ] , _rtB -> B_20_600_0 [
4 ] , _rtB -> B_20_600_0 [ 8 ] , & _rtB -> NegativeTrace_f , & _rtDW ->
NegativeTrace_f , & _rtZCSV -> NegativeTrace_f ) ; } _rtZCSV ->
Saturation_UprLim_ZC_h [ 0 ] = _rtB -> B_20_612_0 [ 0 ] - _rtP -> P_167 ;
_rtZCSV -> Saturation_LwrLim_ZC_i [ 0 ] = _rtB -> B_20_612_0 [ 0 ] - _rtP ->
P_168 ; _rtZCSV -> Saturation_UprLim_ZC_h [ 1 ] = _rtB -> B_20_612_0 [ 1 ] -
_rtP -> P_167 ; _rtZCSV -> Saturation_LwrLim_ZC_i [ 1 ] = _rtB -> B_20_612_0
[ 1 ] - _rtP -> P_168 ; _rtZCSV -> Saturation_UprLim_ZC_h [ 2 ] = _rtB ->
B_20_612_0 [ 2 ] - _rtP -> P_167 ; _rtZCSV -> Saturation_LwrLim_ZC_i [ 2 ] =
_rtB -> B_20_612_0 [ 2 ] - _rtP -> P_168 ; _rtZCSV -> Sign_Input_ZC = _rtB ->
B_20_633_0 ; _rtZCSV -> Switch_SwitchCond_ZC_d = _rtB -> B_20_824_0 - _rtP ->
P_213 ; { enum { INTG_NORMAL , INTG_LEAVING_UPPER_SAT ,
INTG_LEAVING_LOWER_SAT , INTG_UPPER_SAT , INTG_LOWER_SAT } ; if ( _rtDW ->
IntegratorLimited_MODE_p [ 0 ] == INTG_LEAVING_UPPER_SAT && ( (
X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0
] >= _rtP -> P_215 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S
) ) -> IntegratorLimited_IntgUpLimit_ZC_b [ 0 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_b [ 0 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0 ] - _rtP -> P_215
; } if ( _rtDW -> IntegratorLimited_MODE_p [ 0 ] == INTG_LEAVING_LOWER_SAT &&
( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml
[ 0 ] <= _rtP -> P_216 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector
( S ) ) -> IntegratorLimited_IntgLoLimit_ZC_c [ 0 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_c [ 0 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 0 ] - _rtP -> P_216
; } if ( _rtDW -> IntegratorLimited_MODE_p [ 1 ] == INTG_LEAVING_UPPER_SAT &&
( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml
[ 1 ] >= _rtP -> P_215 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector
( S ) ) -> IntegratorLimited_IntgUpLimit_ZC_b [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_b [ 1 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 1 ] - _rtP -> P_215
; } if ( _rtDW -> IntegratorLimited_MODE_p [ 1 ] == INTG_LEAVING_LOWER_SAT &&
( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml
[ 1 ] <= _rtP -> P_216 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector
( S ) ) -> IntegratorLimited_IntgLoLimit_ZC_c [ 1 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_c [ 1 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 1 ] - _rtP -> P_216
; } if ( _rtDW -> IntegratorLimited_MODE_p [ 2 ] == INTG_LEAVING_UPPER_SAT &&
( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml
[ 2 ] >= _rtP -> P_215 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector
( S ) ) -> IntegratorLimited_IntgUpLimit_ZC_b [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgUpLimit_ZC_b [ 2 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 2 ] - _rtP -> P_215
; } if ( _rtDW -> IntegratorLimited_MODE_p [ 2 ] == INTG_LEAVING_LOWER_SAT &&
( ( X_ACStesbed1_T * ) ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml
[ 2 ] <= _rtP -> P_216 ) { ( ( ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector
( S ) ) -> IntegratorLimited_IntgLoLimit_ZC_c [ 2 ] = 0.0 ; } else { ( (
ZCV_ACStesbed1_T * ) ssGetSolverZcSignalVector ( S ) ) ->
IntegratorLimited_IntgLoLimit_ZC_c [ 2 ] = ( ( X_ACStesbed1_T * )
ssGetContStates ( S ) ) -> IntegratorLimited_CSTATE_ml [ 2 ] - _rtP -> P_216
; } } _rtZCSV -> Switch_SwitchCond_ZC_h = _rtB -> B_20_839_0 - _rtP -> P_223
; _rtZCSV -> Switch_SwitchCond_ZC_g = _rtB -> B_20_848_0 - _rtP -> P_225 ;
_rtZCSV -> If_IfInput_ZC_j = 0.0 ; if ( _rtB -> B_20_860_0 > 0.0 ) { _rtZCSV
-> If_IfInput_ZC_j = 1.0 ; } { real_T * zcsv = & ( ( ( ZCV_ACStesbed1_T * )
ssGetSolverZcSignalVector ( S ) ) -> NegativeTrace_g .
FindMaximumDiagonalValue_IfInput_ZC [ 0 ] ) ; int_T i ; for ( i = 0 ; i < 5 ;
i ++ ) { zcsv [ i ] = 0.0 ; } } if ( _rtDW -> If_ActiveSubsystem_o == 1 ) {
ACStesbed1_NegativeTrace_ZC ( _rtB -> B_20_859_0 [ 0 ] , _rtB -> B_20_859_0 [
4 ] , _rtB -> B_20_859_0 [ 8 ] , & _rtB -> NegativeTrace_g , & _rtDW ->
NegativeTrace_g , & _rtZCSV -> NegativeTrace_g ) ; } _rtZCSV ->
Switch_SwitchCond_ZC_i = _rtB -> B_20_864_0 [ 0 ] - _rtP -> P_227 ; _rtZCSV
-> Switch_SwitchCond_ZC_jw = _rtB -> B_20_910_0 - _rtP -> P_234 ; _rtZCSV ->
Saturation_UprLim_ZC_n [ 0 ] = _rtB -> B_20_1010_0 [ 0 ] - _rtP -> P_252 ;
_rtZCSV -> Saturation_LwrLim_ZC_h [ 0 ] = _rtB -> B_20_1010_0 [ 0 ] - _rtP ->
P_253 ; _rtZCSV -> Saturation_UprLim_ZC_n [ 1 ] = _rtB -> B_20_1010_0 [ 1 ] -
_rtP -> P_252 ; _rtZCSV -> Saturation_LwrLim_ZC_h [ 1 ] = _rtB -> B_20_1010_0
[ 1 ] - _rtP -> P_253 ; _rtZCSV -> Saturation_UprLim_ZC_n [ 2 ] = _rtB ->
B_20_1010_0 [ 2 ] - _rtP -> P_252 ; _rtZCSV -> Saturation_LwrLim_ZC_h [ 2 ] =
_rtB -> B_20_1010_0 [ 2 ] - _rtP -> P_253 ; _rtZCSV ->
Switch_SwitchCond_ZC_b1 = _rtB -> B_20_899_0 [ 0 ] - _rtP -> P_283 ; _rtZCSV
-> Switch_SwitchCond_ZC_o = _rtB -> B_20_1304_0 - _rtP -> P_319 ; _rtZCSV ->
Switch_SwitchCond_ZC_g0 = _rtB -> B_20_1314_0 - _rtP -> P_321 ; _rtZCSV ->
If_IfInput_ZC_f = 0.0 ; if ( _rtB -> B_20_1323_0 > 0.0 ) { _rtZCSV ->
If_IfInput_ZC_f = 1.0 ; } { real_T * zcsv = & ( ( ( ZCV_ACStesbed1_T * )
ssGetSolverZcSignalVector ( S ) ) -> NegativeTrace_o .
FindMaximumDiagonalValue_IfInput_ZC [ 0 ] ) ; int_T i ; for ( i = 0 ; i < 5 ;
i ++ ) { zcsv [ i ] = 0.0 ; } } if ( _rtDW -> If_ActiveSubsystem_n == 1 ) {
ACStesbed1_NegativeTrace_ZC ( _rtB -> B_20_1322_0 [ 0 ] , _rtB -> B_20_1322_0
[ 4 ] , _rtB -> B_20_1322_0 [ 8 ] , & _rtB -> NegativeTrace_o , & _rtDW ->
NegativeTrace_o , & _rtZCSV -> NegativeTrace_o ) ; } _rtZCSV ->
Saturation_UprLim_ZC_l [ 0 ] = _rtB -> B_20_1331_0 [ 0 ] - _rtP -> P_324 ;
_rtZCSV -> Saturation_LwrLim_ZC_hw [ 0 ] = _rtB -> B_20_1331_0 [ 0 ] - _rtP
-> P_325 ; _rtZCSV -> Saturation_UprLim_ZC_l [ 1 ] = _rtB -> B_20_1331_0 [ 1
] - _rtP -> P_324 ; _rtZCSV -> Saturation_LwrLim_ZC_hw [ 1 ] = _rtB ->
B_20_1331_0 [ 1 ] - _rtP -> P_325 ; _rtZCSV -> Saturation_UprLim_ZC_l [ 2 ] =
_rtB -> B_20_1331_0 [ 2 ] - _rtP -> P_324 ; _rtZCSV ->
Saturation_LwrLim_ZC_hw [ 2 ] = _rtB -> B_20_1331_0 [ 2 ] - _rtP -> P_325 ; }
static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 ,
832702971U ) ; ssSetChecksumVal ( S , 1 , 3133405747U ) ; ssSetChecksumVal (
S , 2 , 3217664428U ) ; ssSetChecksumVal ( S , 3 , 2066877222U ) ; { mxArray
* slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" )
; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat ,
1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.2" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( DW_ACStesbed1_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_ACStesbed1_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_ACStesbed1_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & ACStesbed1_rtDefaultP ) ; } static void mdlInitializeSampleTimes
( SimStruct * S ) { } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
