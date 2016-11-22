#include "__cf_ACStesbed1.h"
#ifndef RTW_HEADER_ACStesbed1_acc_private_h_
#define RTW_HEADER_ACStesbed1_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)   (((v1)==(v2))?((double)(v1)):  (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?   muDoubleScalarFloor((v) + 0.5) :   muDoubleScalarCeil((v) - 0.5) )
#endif
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#endif
#endif
extern real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; extern real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; extern void
MWDSPCG_Pseudoinverse_D ( const real_T pS [ ] , const real_T pU [ ] , const
real_T pV [ ] , real_T pX [ ] , const int32_T M , const int32_T N ) ; extern
void LUf_int32_Treal_T ( real_T outU [ ] , real_T outP [ ] , const int32_T N
) ; extern void rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( const real_T u0 [ 9 ] ,
const real_T u1 [ 3 ] , real_T y [ 3 ] ) ; void
ACStesbed1_PositiveTrace_Enable ( SimStruct * const S ) ; void
ACStesbed1_PositiveTrace_Disable ( SimStruct * const S ) ; void
ACStesbed1_PositiveTrace ( SimStruct * const S , real_T rtu_traceDCM , real_T
rtu_DCM , real_T rtu_DCM_p , real_T rtu_DCM_i , real_T rtu_DCM_g , real_T
rtu_DCM_m , real_T rtu_DCM_j , real_T * rty_qwqxqyqz , real_T rty_qwqxqyqz_g
[ 3 ] , B_PositiveTrace_ACStesbed1_T * localB , DW_PositiveTrace_ACStesbed1_T
* localDW , P_PositiveTrace_ACStesbed1_T * localP ) ; void
ACStesbed1_NegativeTrace_Enable ( SimStruct * const S ) ; void
ACStesbed1_NegativeTrace_ZC ( real_T rtu_DCM , real_T rtu_DCM_b , real_T
rtu_DCM_k , B_NegativeTrace_ACStesbed1_T * localB ,
DW_NegativeTrace_ACStesbed1_T * localDW , ZCV_NegativeTrace_ACStesbed1_T *
localZCSV ) ; void ACStesbed1_NegativeTrace_Disable ( SimStruct * const S ,
DW_NegativeTrace_ACStesbed1_T * localDW ) ; void ACStesbed1_NegativeTrace (
SimStruct * const S , real_T rtu_DCM , real_T rtu_DCM_b , real_T rtu_DCM_k ,
real_T rtu_DCM_k3 , real_T rtu_DCM_a , real_T rtu_DCM_ky , real_T rtu_DCM_n ,
real_T rtu_DCM_as , real_T rtu_DCM_o , real_T * rty_1 , real_T * rty_2 ,
real_T * rty_3 , real_T * rty_4 , B_NegativeTrace_ACStesbed1_T * localB ,
DW_NegativeTrace_ACStesbed1_T * localDW , P_NegativeTrace_ACStesbed1_T *
localP ) ;
#endif
