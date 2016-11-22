#include "__cf_ACStesbed.h"
#ifndef RTW_HEADER_ACStesbed_private_h_
#define RTW_HEADER_ACStesbed_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
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
const real_T u1 [ 3 ] , real_T y [ 3 ] ) ; extern void fri4zeczvq ( SimStruct
* const rtS ) ; extern void e5wfebyea4 ( dmxskfrz2h * localDW ) ; extern void
f3tc5mwqyz ( SimStruct * const rtS ) ; extern void p0vdevk3x1 ( SimStruct *
const rtS , real_T maudr00odw , real_T gewvozca5r , real_T p1m1oo3sdu ,
real_T co1y0npz4d , real_T g3oii5p4ay , real_T ezygnxhmp5 , real_T bxfr00c5zn
, real_T * htakh3tv3v , real_T mtfgysrxxh [ 3 ] , dmxskfrz2h * localDW ,
oj32fzmstd * localP ) ; extern void nc5u50jta2 ( SimStruct * const rtS ) ;
extern void eeuk0bnkti ( h4iasb5pte * localDW ) ; extern void o132e2hrwv (
real_T lk5yn01b43 , real_T igihmdkbau , real_T opvldjancg , ppxmmlhmiq *
localB , h4iasb5pte * localDW , p4bsjadjac * localZCSV ) ; extern void
nws40mclpe ( SimStruct * const rtS , h4iasb5pte * localDW ) ; extern void
azz3d4nxce ( SimStruct * const rtS , real_T lk5yn01b43 , real_T igihmdkbau ,
real_T opvldjancg , real_T jautdjk1eb , real_T hgmdlfu242 , real_T psnq5apkya
, real_T a1t4mjaq2j , real_T jwwcum0heq , real_T g3k04yx2hq , real_T *
d5l114dofg , real_T * idw2bnt5im , real_T * mtatrlkgji , real_T * aweaz3zeyc
, ppxmmlhmiq * localB , h4iasb5pte * localDW , a0yd1qizj0 * localP ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
