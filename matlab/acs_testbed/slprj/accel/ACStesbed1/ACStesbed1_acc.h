#include "__cf_ACStesbed1.h"
#ifndef RTW_HEADER_ACStesbed1_acc_h_
#define RTW_HEADER_ACStesbed1_acc_h_
#ifndef ACStesbed1_acc_COMMON_INCLUDES_
#define ACStesbed1_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "multiword_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dspsvd_rt.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#endif
#include "ACStesbed1_acc_types.h"
typedef struct { real_T B_5_0_0 ; } B_PositiveTrace_ACStesbed1_T ; typedef
struct { int8_T PositiveTrace_SubsysRanBC ; int8_T sqrt_DWORK1 ; char
pad_sqrt_DWORK1 [ 6 ] ; } DW_PositiveTrace_ACStesbed1_T ; typedef struct {
real_T B_8_0_0 ; real_T B_8_2_0 ; real_T B_8_4_0 ; real_T B_8_5_0 [ 2 ] ;
real_T B_7_0_0 ; real_T B_7_2_0 ; real_T B_7_7_0 ; real_T B_7_8_0 [ 2 ] ;
real_T B_6_0_0 ; real_T B_6_2_0 ; real_T B_6_7_0 ; real_T B_6_8_0 [ 2 ] ; }
B_NegativeTrace_ACStesbed1_T ; typedef struct { int8_T
NegativeTrace_SubsysRanBC ; int8_T FindMaximumDiagonalValue_ActiveSubsystem ;
int8_T MaximumValueatDCM22_SubsysRanBC ; int8_T
MaximumValueatDCM33_SubsysRanBC ; int8_T MaximumValueatDCM11_SubsysRanBC ;
int8_T sqrt_DWORK1 ; int8_T sqrt_DWORK1_p ; int8_T sqrt_DWORK1_a ; boolean_T
Switch_Mode ; boolean_T Switch_Mode_k ; boolean_T Switch_Mode_f ; char
pad_Switch_Mode_f [ 5 ] ; } DW_NegativeTrace_ACStesbed1_T ; typedef struct {
real_T FindMaximumDiagonalValue_IfInput_ZC [ 2 ] ; real_T
Switch_SwitchCond_ZC_n ; real_T Switch_SwitchCond_ZC_l ; real_T
Switch_SwitchCond_ZC_nf ; } ZCV_NegativeTrace_ACStesbed1_T ; typedef struct {
ZCSigState FindMaximumDiagonalValue_IfInput_ZCE [ 2 ] ; ZCSigState
Switch_SwitchCond_ZCE_i ; ZCSigState Switch_SwitchCond_ZCE_gr ; ZCSigState
Switch_SwitchCond_ZCE_e ; } ZCE_NegativeTrace_ACStesbed1_T ; typedef struct {
BusObject B_20_835_0 ; real_T B_20_0_0 ; real_T B_20_2_0 [ 3 ] ; real_T
B_20_3_0 ; real_T B_20_8_0 [ 3 ] ; real_T B_20_9_0 [ 3 ] ; real_T B_20_10_0 [
3 ] ; real_T B_20_13_0 ; real_T B_20_14_0 [ 3 ] ; real_T B_20_18_0 [ 3 ] ;
real_T B_20_19_0 [ 3 ] ; real_T B_20_22_0 [ 3 ] ; real_T B_20_25_0 ; real_T
B_20_26_0 [ 3 ] ; real_T B_20_41_0 [ 4 ] ; real_T B_20_49_0 ; real_T
B_20_75_0 [ 4 ] ; real_T B_20_76_0 [ 4 ] ; real_T B_20_79_0 ; real_T
B_20_82_0 ; real_T B_20_85_0 ; real_T B_20_87_0 ; real_T B_20_88_0 ; real_T
B_20_128_0 ; real_T B_20_136_0 ; real_T B_20_158_0 ; real_T B_20_179_0 [ 9 ]
; real_T B_20_182_0 [ 9 ] ; real_T B_20_183_0 [ 3 ] ; real_T B_20_189_0 [ 3 ]
; real_T B_20_190_0 [ 3 ] ; real_T B_20_191_0 [ 3 ] ; real_T B_20_192_0 [ 3 ]
; real_T B_20_196_0 [ 3 ] ; real_T B_20_197_0 [ 3 ] ; real_T B_20_198_0 [ 3 ]
; real_T B_20_206_0 [ 3 ] ; real_T B_20_209_0 [ 3 ] ; real_T B_20_210_0 [ 3 ]
; real_T B_20_213_0 [ 3 ] ; real_T B_20_224_0 ; real_T B_20_248_0 ; real_T
B_20_270_0 ; real_T B_20_281_0 [ 3 ] ; real_T B_20_284_0 [ 3 ] ; real_T
B_20_288_0 [ 3 ] ; real_T B_20_289_0 [ 3 ] ; real_T B_20_291_0 [ 3 ] ; real_T
B_20_294_0 [ 3 ] ; real_T B_20_295_0 [ 3 ] ; real_T B_20_296_0 ; real_T
B_20_310_0 [ 18 ] ; real_T B_20_314_0 [ 3 ] ; real_T B_20_323_0 [ 18 ] ;
real_T B_20_324_0 [ 18 ] ; real_T B_20_326_0 ; real_T B_20_350_0 ; real_T
B_20_358_0 ; real_T B_20_380_0 ; real_T B_20_398_0 [ 9 ] ; real_T B_20_400_0
[ 27 ] ; real_T B_20_401_0 [ 27 ] ; real_T B_20_403_0 [ 3 ] ; real_T
B_20_404_0 [ 3 ] ; real_T B_20_428_0 ; real_T B_20_429_0 ; real_T B_20_431_0
; real_T B_20_435_0 ; real_T B_20_436_0 ; real_T B_20_437_0 ; real_T
B_20_438_0 ; real_T B_20_439_0 ; real_T B_20_449_0 [ 9 ] ; real_T B_20_451_0
[ 9 ] ; real_T B_20_457_0 ; real_T B_20_458_0 ; real_T B_20_465_1 [ 3 ] ;
real_T B_20_469_0 ; real_T B_20_506_0 ; real_T B_20_543_0 ; real_T B_20_578_0
[ 9 ] ; real_T B_20_579_0 [ 9 ] ; real_T B_20_582_0 ; real_T B_20_583_0 [ 3 ]
; real_T B_20_584_0 ; real_T B_20_589_0 [ 3 ] ; real_T B_20_592_0 ; real_T
B_20_593_0 [ 3 ] ; real_T B_20_594_0 ; real_T B_20_600_0 [ 9 ] ; real_T
B_20_601_0 ; real_T B_20_605_0 [ 4 ] ; real_T B_20_612_0 [ 3 ] ; real_T
B_20_614_0 [ 3 ] ; real_T B_20_621_0 [ 4 ] ; real_T B_20_633_0 ; real_T
B_20_634_0 ; real_T B_20_661_0 ; real_T B_20_685_0 ; real_T B_20_707_0 ;
real_T B_20_723_0 [ 3 ] ; real_T B_20_733_0 [ 3 ] ; real_T B_20_734_0 ;
real_T B_20_738_0 ; real_T B_20_739_0 ; real_T B_20_740_0 ; real_T B_20_741_0
; real_T B_20_752_0 [ 3 ] ; real_T B_20_756_0 [ 3 ] ; real_T B_20_758_0 ;
real_T B_20_770_0 ; real_T B_20_786_0 ; real_T B_20_794_0 ; real_T B_20_803_0
; real_T B_20_816_0 ; real_T B_20_820_0 ; real_T B_20_824_0 ; real_T
B_20_825_0 [ 3 ] ; real_T B_20_831_0 [ 9 ] ; real_T B_20_832_0 ; real_T
B_20_833_0 ; real_T B_20_834_0 ; real_T B_20_836_0 [ 3 ] ; real_T B_20_839_0
; real_T B_20_840_0 [ 3 ] ; real_T B_20_841_0 ; real_T B_20_845_0 [ 3 ] ;
real_T B_20_848_0 ; real_T B_20_849_0 [ 3 ] ; real_T B_20_850_0 ; real_T
B_20_859_0 [ 9 ] ; real_T B_20_860_0 ; real_T B_20_864_0 [ 4 ] ; real_T
B_20_898_0 [ 4 ] ; real_T B_20_899_0 [ 4 ] ; real_T B_20_910_0 ; real_T
B_20_911_0 ; real_T B_20_930_0 [ 3 ] ; real_T B_20_931_0 [ 3 ] ; real_T
B_20_945_0 ; real_T B_20_969_0 ; real_T B_20_991_0 ; real_T B_20_1002_0 [ 3 ]
; real_T B_20_1005_0 [ 3 ] ; real_T B_20_1009_0 [ 3 ] ; real_T B_20_1010_0 [
3 ] ; real_T B_20_1012_0 [ 3 ] ; real_T B_20_1015_0 [ 3 ] ; real_T
B_20_1016_0 [ 3 ] ; real_T B_20_1018_0 [ 3 ] ; real_T B_20_1019_0 ; real_T
B_20_1033_0 [ 18 ] ; real_T B_20_1037_0 [ 3 ] ; real_T B_20_1046_0 [ 18 ] ;
real_T B_20_1047_0 [ 18 ] ; real_T B_20_1049_0 ; real_T B_20_1073_0 ; real_T
B_20_1081_0 ; real_T B_20_1103_0 ; real_T B_20_1121_0 [ 9 ] ; real_T
B_20_1123_0 [ 27 ] ; real_T B_20_1124_0 [ 27 ] ; real_T B_20_1126_0 [ 3 ] ;
real_T B_20_1127_0 [ 3 ] ; real_T B_20_1150_0 ; real_T B_20_1151_0 ; real_T
B_20_1153_0 ; real_T B_20_1157_0 ; real_T B_20_1158_0 ; real_T B_20_1159_0 ;
real_T B_20_1160_0 ; real_T B_20_1161_0 ; real_T B_20_1171_0 [ 9 ] ; real_T
B_20_1173_0 [ 9 ] ; real_T B_20_1179_0 ; real_T B_20_1180_0 ; real_T
B_20_1187_1 [ 3 ] ; real_T B_20_1188_0 [ 9 ] ; real_T B_20_1190_0 ; real_T
B_20_1205_0 [ 9 ] ; real_T B_20_1220_0 [ 9 ] ; real_T B_20_1222_0 [ 9 ] ;
real_T B_20_1227_0 ; real_T B_20_1242_0 [ 9 ] ; real_T B_20_1257_0 [ 9 ] ;
real_T B_20_1259_0 [ 9 ] ; real_T B_20_1264_0 ; real_T B_20_1279_0 [ 9 ] ;
real_T B_20_1294_0 [ 9 ] ; real_T B_20_1296_0 [ 9 ] ; real_T B_20_1304_0 ;
real_T B_20_1305_0 [ 3 ] ; real_T B_20_1306_0 ; real_T B_20_1311_0 [ 3 ] ;
real_T B_20_1314_0 ; real_T B_20_1315_0 [ 3 ] ; real_T B_20_1316_0 ; real_T
B_20_1322_0 [ 9 ] ; real_T B_20_1323_0 ; real_T B_20_1327_0 [ 4 ] ; real_T
B_20_1331_0 [ 3 ] ; real_T B_20_1338_0 [ 3 ] ; real_T B_20_1340_0 [ 3 ] ;
real_T B_20_199_0 [ 3 ] ; real_T B_20_416_0 [ 9 ] ; real_T B_20_1139_0 [ 9 ]
; real_T B_20_722_0 [ 3 ] ; real_T B_20_719_0 [ 3 ] ; real_T B_20_996_0 [ 3 ]
; real_T B_20_854_0 [ 3 ] ; real_T B_20_1141_0 [ 3 ] ; real_T B_20_1176_0 [ 9
] ; real_T B_20_830_0 [ 3 ] ; real_T B_20_928_0 [ 4 ] ; real_T B_20_852_0 [ 3
] ; real_T B_20_843_0 [ 3 ] ; real_T B_20_1332_0 [ 3 ] ; real_T B_20_1333_0 [
3 ] ; B_NegativeTrace_ACStesbed1_T NegativeTrace_o ;
B_PositiveTrace_ACStesbed1_T PositiveTrace_f ; B_NegativeTrace_ACStesbed1_T
NegativeTrace_g ; B_PositiveTrace_ACStesbed1_T PositiveTrace_e ;
B_NegativeTrace_ACStesbed1_T NegativeTrace_f ; B_PositiveTrace_ACStesbed1_T
PositiveTrace_p ; } B_ACStesbed1_T ; typedef struct { real_T
DiscreteTimeIntegrator_DSTATE [ 3 ] ; real_T DiscreteTimeIntegrator_DSTATE_i
[ 18 ] ; real_T DiscreteTimeIntegrator1_DSTATE [ 9 ] ; real_T
DiscreteTimeIntegrator2_DSTATE [ 3 ] ; real_T DiscreteTimeIntegrator_DSTATE_p
[ 18 ] ; real_T DiscreteTimeIntegrator1_DSTATE_f [ 9 ] ; real_T
DiscreteTimeIntegrator2_DSTATE_n [ 3 ] ; real_T NextOutput ; real_T
Pseudoinverse_X [ 27 ] ; real_T Pseudoinverse_E [ 9 ] ; real_T
Pseudoinverse_WORK [ 3 ] ; real_T Pseudoinverse_S [ 4 ] ; real_T
Pseudoinverse_U [ 9 ] ; real_T Pseudoinverse_V [ 81 ] ; real_T Divide_DWORK1
[ 9 ] ; real_T Divide_DWORK3 [ 3 ] ; real_T NextOutput_d ; void *
FromWorkspace_PWORK [ 15 ] ; void *
HiddenToWks_InsertedFor_BusSelector1_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_Subsystem_at_outport_0_PWORK ; struct { void *
LoggedData ; } Scope_PWORK ; void *
HiddenToWks_InsertedFor_BINS_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_BINS_at_outport_1_PWORK ; struct { void * LoggedData
; } Scope_PWORK_p ; struct { void * LoggedData ; } Scope_PWORK_m ; void *
HiddenToWks_InsertedFor_BusSelector_at_outport_1_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector_at_outport_3_PWORK ; void *
HiddenToWks_InsertedFor_Saturation_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_Tgrav_at_outport_0_PWORK ; struct { void * LoggedData
; } Torquesscope_PWORK ; void *
HiddenToWks_InsertedFor_Add_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_Gain2_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_Gain3_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_Gain4_at_outport_0_PWORK ; struct { void * LoggedData
; } RcmScope_PWORK ; struct { void * LoggedData ; } Scope_PWORK_f ; void *
HiddenToWks_InsertedFor_BusSelector1_at_outport_0_PWORK_c ; void *
HiddenToWks_InsertedFor_Subsystem_at_outport_0_PWORK_e ; void *
FromWorkspace_PWORK_i [ 15 ] ; struct { void * LoggedData ; } Scope_PWORK_h ;
struct { void * LoggedData ; } deltaDscope_PWORK ; void *
HiddenToWks_InsertedFor_BINS_at_outport_0_PWORK_k ; void *
HiddenToWks_InsertedFor_BINS_at_outport_1_PWORK_e ; struct { void *
LoggedData ; } Scope_PWORK_d ; struct { void * LoggedData ; } Scope_PWORK_pc
; void * HiddenToWks_InsertedFor_BusSelector_at_outport_1_PWORK_b ; void *
HiddenToWks_InsertedFor_BusSelector_at_outport_3_PWORK_o ; void *
HiddenToWks_InsertedFor_Saturation_at_outport_0_PWORK_e ; struct { void *
LoggedData ; } FloatingScope_PWORK ; int32_T Divide_DWORK2 [ 3 ] ; uint32_T
RandSeed ; uint32_T RandSeed_o ; int_T FromWorkspace_IWORK [ 5 ] ; struct {
int_T IcNeedsLoading ; } q0q1q2q3_IWORK ; struct { int_T IcNeedsLoading ; }
Integrator_IWORK ; struct { int_T IcNeedsLoading ; } q0q1q2q3_IWORK_p ; int_T
FromWorkspace_IWORK_f [ 5 ] ; struct { int_T IcNeedsLoading ; }
q0q1q2q3_IWORK_g ; int_T IntegratorLimited_MODE [ 3 ] ; int_T
IntegratorLimited_MODE_l [ 3 ] ; int_T Saturation_MODE [ 3 ] ; int_T
Saturation_MODE_a [ 3 ] ; int_T Sign_MODE ; int_T IntegratorLimited_MODE_p [
3 ] ; int_T Saturation_MODE_as [ 3 ] ; int_T Saturation_MODE_k [ 3 ] ; int8_T
MathFunction1_DWORK1 ; int8_T MathFunction1_DWORK1_l ; int8_T
If_ActiveSubsystem ; int8_T PositiveTrace_SubsysRanBC ; int8_T
NegativeTrace_SubsysRanBC ; int8_T sqrt_DWORK1 ; int8_T sqrt_DWORK1_h ;
int8_T sqrt_DWORK1_n ; int8_T MathFunction1_DWORK1_a ; int8_T
MathFunction1_DWORK1_i ; int8_T If_ActiveSubsystem_f ; int8_T sqrt_DWORK1_d ;
int8_T sqrt_DWORK1_l ; int8_T MathFunction1_DWORK1_ah ; int8_T
MathFunction1_DWORK1_lp ; int8_T MathFunction1_DWORK1_b ; int8_T
If_ActiveSubsystem_o ; int8_T sqrt_DWORK1_k ; int8_T sqrt_DWORK1_dk ; int8_T
MathFunction1_DWORK1_ae ; int8_T MathFunction1_DWORK1_d ; int8_T
If_ActiveSubsystem_n ; int8_T FindMaximumDiagonalValue_ActiveSubsystem ;
int8_T MaximumValueatDCM22_SubsysRanBC ; int8_T
MaximumValueatDCM33_SubsysRanBC ; int8_T MaximumValueatDCM11_SubsysRanBC ;
int8_T sqrt_DWORK1_da ; int8_T sqrt_DWORK1_a ; int8_T sqrt_DWORK1_i ; int8_T
sqrt_DWORK1_f ; uint8_T DiscreteTimeIntegrator_IC_LOADING ; uint8_T
DiscreteTimeIntegrator1_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator2_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator_IC_LOADING_p ; uint8_T
DiscreteTimeIntegrator1_SYSTEM_ENABLE_o ; uint8_T
DiscreteTimeIntegrator2_SYSTEM_ENABLE_c ; boolean_T Switch_Mode ; boolean_T
Switch_Mode_m ; boolean_T Switch_Mode_f ; boolean_T Switch_Mode_j ; boolean_T
Switch_Mode_mk ; boolean_T Switch_Mode_h ; boolean_T Switch_Mode_e ;
boolean_T Switch_Mode_i ; boolean_T Switch_Mode_a ; boolean_T Switch_Mode_mke
; boolean_T Switch_Mode_b ; boolean_T Switch_Mode_p ; char pad_Switch_Mode_p
[ 4 ] ; DW_NegativeTrace_ACStesbed1_T NegativeTrace_o ;
DW_PositiveTrace_ACStesbed1_T PositiveTrace_f ; DW_NegativeTrace_ACStesbed1_T
NegativeTrace_g ; DW_PositiveTrace_ACStesbed1_T PositiveTrace_e ;
DW_NegativeTrace_ACStesbed1_T NegativeTrace_f ; DW_PositiveTrace_ACStesbed1_T
PositiveTrace_p ; } DW_ACStesbed1_T ; typedef struct { real_T q0q1q2q3_CSTATE
[ 4 ] ; real_T Integrator_CSTATE [ 3 ] ; real_T Integrator_CSTATE_n [ 3 ] ;
real_T IntegratorLimited_CSTATE [ 3 ] ; real_T IntegratorLimited_CSTATE_m [ 3
] ; real_T q0q1q2q3_CSTATE_i [ 4 ] ; real_T IntegratorLimited_CSTATE_ml [ 3 ]
; real_T q0q1q2q3_CSTATE_j [ 4 ] ; } X_ACStesbed1_T ; typedef struct { real_T
q0q1q2q3_CSTATE [ 4 ] ; real_T Integrator_CSTATE [ 3 ] ; real_T
Integrator_CSTATE_n [ 3 ] ; real_T IntegratorLimited_CSTATE [ 3 ] ; real_T
IntegratorLimited_CSTATE_m [ 3 ] ; real_T q0q1q2q3_CSTATE_i [ 4 ] ; real_T
IntegratorLimited_CSTATE_ml [ 3 ] ; real_T q0q1q2q3_CSTATE_j [ 4 ] ; }
XDot_ACStesbed1_T ; typedef struct { boolean_T q0q1q2q3_CSTATE [ 4 ] ;
boolean_T Integrator_CSTATE [ 3 ] ; boolean_T Integrator_CSTATE_n [ 3 ] ;
boolean_T IntegratorLimited_CSTATE [ 3 ] ; boolean_T
IntegratorLimited_CSTATE_m [ 3 ] ; boolean_T q0q1q2q3_CSTATE_i [ 4 ] ;
boolean_T IntegratorLimited_CSTATE_ml [ 3 ] ; boolean_T q0q1q2q3_CSTATE_j [ 4
] ; } XDis_ACStesbed1_T ; typedef struct { real_T q0q1q2q3_CSTATE [ 4 ] ;
real_T Integrator_CSTATE [ 3 ] ; real_T Integrator_CSTATE_n [ 3 ] ; real_T
IntegratorLimited_CSTATE [ 3 ] ; real_T IntegratorLimited_CSTATE_m [ 3 ] ;
real_T q0q1q2q3_CSTATE_i [ 4 ] ; real_T IntegratorLimited_CSTATE_ml [ 3 ] ;
real_T q0q1q2q3_CSTATE_j [ 4 ] ; } CStateAbsTol_ACStesbed1_T ; typedef struct
{ real_T Switch_SwitchCond_ZC ; real_T IntegratorLimited_IntgUpLimit_ZC [ 3 ]
; real_T IntegratorLimited_IntgLoLimit_ZC [ 3 ] ; real_T
IntegratorLimited_IntgUpLimit_ZC_m [ 3 ] ; real_T
IntegratorLimited_IntgLoLimit_ZC_j [ 3 ] ; real_T Saturation_UprLim_ZC [ 3 ]
; real_T Saturation_LwrLim_ZC [ 3 ] ; real_T Switch_SwitchCond_ZC_p ; real_T
Switch_SwitchCond_ZC_b ; real_T Switch_SwitchCond_ZC_j ; real_T If_IfInput_ZC
; real_T Saturation_UprLim_ZC_h [ 3 ] ; real_T Saturation_LwrLim_ZC_i [ 3 ] ;
real_T Sign_Input_ZC ; real_T Switch_SwitchCond_ZC_d ; real_T
IntegratorLimited_IntgUpLimit_ZC_b [ 3 ] ; real_T
IntegratorLimited_IntgLoLimit_ZC_c [ 3 ] ; real_T Switch_SwitchCond_ZC_h ;
real_T Switch_SwitchCond_ZC_g ; real_T If_IfInput_ZC_j ; real_T
Switch_SwitchCond_ZC_i ; real_T Switch_SwitchCond_ZC_jw ; real_T
Saturation_UprLim_ZC_n [ 3 ] ; real_T Saturation_LwrLim_ZC_h [ 3 ] ; real_T
Switch_SwitchCond_ZC_b1 ; real_T Switch_SwitchCond_ZC_o ; real_T
Switch_SwitchCond_ZC_g0 ; real_T If_IfInput_ZC_f ; real_T
Saturation_UprLim_ZC_l [ 3 ] ; real_T Saturation_LwrLim_ZC_hw [ 3 ] ;
ZCV_NegativeTrace_ACStesbed1_T NegativeTrace_o ;
ZCV_NegativeTrace_ACStesbed1_T NegativeTrace_g ;
ZCV_NegativeTrace_ACStesbed1_T NegativeTrace_f ; } ZCV_ACStesbed1_T ; typedef
struct { ZCSigState Switch_SwitchCond_ZCE ; ZCSigState
IntegratorLimited_IntgUpLimit_ZCE [ 3 ] ; ZCSigState
IntegratorLimited_IntgLoLimit_ZCE [ 3 ] ; ZCSigState
IntegratorLimited_IntgUpLimit_ZCE_b [ 3 ] ; ZCSigState
IntegratorLimited_IntgLoLimit_ZCE_b [ 3 ] ; ZCSigState Saturation_UprLim_ZCE
[ 3 ] ; ZCSigState Saturation_LwrLim_ZCE [ 3 ] ; ZCSigState
Switch_SwitchCond_ZCE_f ; ZCSigState Switch_SwitchCond_ZCE_l ; ZCSigState
Switch_SwitchCond_ZCE_h ; ZCSigState If_IfInput_ZCE ; ZCSigState
Saturation_UprLim_ZCE_f [ 3 ] ; ZCSigState Saturation_LwrLim_ZCE_m [ 3 ] ;
ZCSigState Sign_Input_ZCE ; ZCSigState Switch_SwitchCond_ZCE_n ; ZCSigState
IntegratorLimited_IntgUpLimit_ZCE_o [ 3 ] ; ZCSigState
IntegratorLimited_IntgLoLimit_ZCE_l [ 3 ] ; ZCSigState
Switch_SwitchCond_ZCE_g ; ZCSigState Switch_SwitchCond_ZCE_m ; ZCSigState
If_IfInput_ZCE_h ; ZCSigState Switch_SwitchCond_ZCE_b ; ZCSigState
Switch_SwitchCond_ZCE_k ; ZCSigState Saturation_UprLim_ZCE_e [ 3 ] ;
ZCSigState Saturation_LwrLim_ZCE_f [ 3 ] ; ZCSigState Switch_SwitchCond_ZCE_o
; ZCSigState Switch_SwitchCond_ZCE_fp ; ZCSigState Switch_SwitchCond_ZCE_p ;
ZCSigState If_IfInput_ZCE_i ; ZCSigState Saturation_UprLim_ZCE_i [ 3 ] ;
ZCSigState Saturation_LwrLim_ZCE_m4 [ 3 ] ; ZCE_NegativeTrace_ACStesbed1_T
NegativeTrace_o ; ZCE_NegativeTrace_ACStesbed1_T NegativeTrace_g ;
ZCE_NegativeTrace_ACStesbed1_T NegativeTrace_f ; } PrevZCX_ACStesbed1_T ;
typedef struct { real_T pooled1 ; } ConstP_ACStesbed1_T ; struct
P_PositiveTrace_ACStesbed1_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; } ;
struct P_NegativeTrace_ACStesbed1_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ;
real_T P_3 [ 2 ] ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T
P_8 ; real_T P_9 ; real_T P_10 [ 2 ] ; real_T P_11 ; real_T P_12 ; real_T
P_13 ; real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 [ 2 ] ; real_T
P_18 ; real_T P_19 ; real_T P_20 ; } ; struct P_ACStesbed1_T_ { real_T P_0 ;
real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 [
2 ] ; real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ;
real_T P_12 ; real_T P_13 [ 2 ] ; real_T P_14 ; real_T P_15 ; real_T P_16 ;
real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 [ 2 ] ; real_T P_21 ;
real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 [ 3 ] ; real_T P_26 ;
real_T P_27 ; real_T P_28 ; real_T P_29 [ 3 ] ; real_T P_30 ; real_T P_31 ;
real_T P_32 [ 3 ] ; real_T P_33 ; real_T P_34 ; real_T P_35 [ 4 ] ; real_T
P_36 ; real_T P_37 ; real_T P_38 [ 4 ] ; real_T P_39 [ 4 ] ; real_T P_40 ;
real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T
P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ;
real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 ; real_T P_56 ; real_T
P_57 ; real_T P_58 [ 9 ] ; real_T P_59 [ 9 ] ; real_T P_60 [ 9 ] ; real_T
P_61 [ 3 ] ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T
P_66 [ 3 ] ; real_T P_67 [ 3 ] ; real_T P_68 ; real_T P_69 ; real_T P_70 ;
real_T P_71 [ 3 ] ; real_T P_72 ; real_T P_73 [ 3 ] ; real_T P_74 ; real_T
P_75 ; real_T P_76 ; real_T P_77 ; real_T P_78 ; real_T P_79 ; real_T P_80 ;
real_T P_81 ; real_T P_82 ; real_T P_83 ; real_T P_84 ; real_T P_85 ; real_T
P_86 ; real_T P_87 ; real_T P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91 ;
real_T P_92 ; real_T P_93 [ 9 ] ; real_T P_94 [ 3 ] ; real_T P_95 ; real_T
P_96 ; real_T P_97 ; real_T P_98 ; real_T P_99 ; real_T P_100 [ 3 ] ; real_T
P_101 ; real_T P_102 ; real_T P_103 ; real_T P_104 ; real_T P_105 ; real_T
P_106 ; real_T P_107 ; real_T P_108 ; real_T P_109 ; real_T P_110 ; real_T
P_111 ; real_T P_112 ; real_T P_113 ; real_T P_114 ; real_T P_115 ; real_T
P_116 ; real_T P_117 ; real_T P_118 ; real_T P_119 ; real_T P_120 ; real_T
P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ; real_T P_125 ; real_T
P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ; real_T P_130 ; real_T
P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ; real_T P_135 [ 9 ] ;
real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T P_139 [ 3 ] ; real_T
P_140 ; real_T P_141 ; real_T P_142 [ 3 ] ; real_T P_143 ; real_T P_144 ;
real_T P_145 ; real_T P_146 ; real_T P_147 [ 3 ] ; real_T P_148 ; real_T
P_149 ; real_T P_150 [ 3 ] ; real_T P_151 ; real_T P_152 ; real_T P_153 ;
real_T P_154 ; real_T P_155 [ 3 ] ; real_T P_156 ; real_T P_157 ; real_T
P_158 [ 3 ] ; real_T P_159 ; real_T P_160 [ 9 ] ; real_T P_161 ; real_T P_162
; real_T P_163 ; real_T P_164 ; real_T P_165 [ 4 ] ; real_T P_166 ; real_T
P_167 ; real_T P_168 ; real_T P_169 [ 3 ] ; real_T P_170 [ 4 ] ; real_T P_171
; real_T P_172 ; real_T P_173 ; real_T P_174 ; real_T P_175 ; real_T P_176 ;
real_T P_177 ; real_T P_178 ; real_T P_179 ; real_T P_180 ; real_T P_181 ;
real_T P_182 ; real_T P_183 [ 3 ] ; real_T P_184 ; real_T P_185 [ 3 ] ;
real_T P_186 ; real_T P_187 [ 3 ] ; real_T P_188 ; real_T P_189 [ 3 ] ;
real_T P_190 ; real_T P_191 ; real_T P_192 ; real_T P_193 ; real_T P_194 ;
real_T P_195 ; real_T P_196 ; real_T P_197 ; real_T P_198 [ 3 ] ; real_T
P_199 ; real_T P_200 ; real_T P_201 ; real_T P_202 ; real_T P_203 ; real_T
P_204 ; real_T P_205 ; real_T P_206 ; real_T P_207 ; real_T P_208 ; real_T
P_209 ; real_T P_210 ; real_T P_211 ; real_T P_212 ; real_T P_213 ; real_T
P_214 ; real_T P_215 ; real_T P_216 ; real_T P_217 [ 3 ] ; real_T P_218 [ 9 ]
; real_T P_219 ; real_T P_220 ; real_T P_221 ; real_T P_222 ; real_T P_223 ;
real_T P_224 ; real_T P_225 ; real_T P_226 [ 4 ] ; real_T P_227 ; real_T
P_228 ; real_T P_229 [ 4 ] ; real_T P_230 [ 4 ] ; real_T P_231 ; real_T P_232
; real_T P_233 ; real_T P_234 ; real_T P_235 ; real_T P_236 ; real_T P_237 ;
real_T P_238 ; real_T P_239 ; real_T P_240 ; real_T P_241 ; real_T P_242 ;
real_T P_243 ; real_T P_244 ; real_T P_245 ; real_T P_246 ; real_T P_247 ;
real_T P_248 ; real_T P_249 ; real_T P_250 [ 9 ] ; real_T P_251 [ 3 ] ;
real_T P_252 ; real_T P_253 ; real_T P_254 ; real_T P_255 ; real_T P_256 ;
real_T P_257 [ 3 ] ; real_T P_258 ; real_T P_259 ; real_T P_260 ; real_T
P_261 ; real_T P_262 ; real_T P_263 ; real_T P_264 ; real_T P_265 ; real_T
P_266 ; real_T P_267 ; real_T P_268 ; real_T P_269 ; real_T P_270 ; real_T
P_271 ; real_T P_272 ; real_T P_273 ; real_T P_274 ; real_T P_275 ; real_T
P_276 ; real_T P_277 ; real_T P_278 ; real_T P_279 ; real_T P_280 ; real_T
P_281 ; real_T P_282 ; real_T P_283 ; real_T P_284 ; real_T P_285 ; real_T
P_286 ; real_T P_287 ; real_T P_288 ; real_T P_289 ; real_T P_290 ; real_T
P_291 ; real_T P_292 [ 9 ] ; real_T P_293 ; real_T P_294 ; real_T P_295 ;
real_T P_296 [ 3 ] ; real_T P_297 ; real_T P_298 ; real_T P_299 [ 3 ] ;
real_T P_300 ; real_T P_301 ; real_T P_302 ; real_T P_303 ; real_T P_304 [ 3
] ; real_T P_305 ; real_T P_306 ; real_T P_307 [ 3 ] ; real_T P_308 ; real_T
P_309 ; real_T P_310 ; real_T P_311 ; real_T P_312 [ 3 ] ; real_T P_313 ;
real_T P_314 ; real_T P_315 [ 3 ] ; real_T P_316 ; real_T P_317 [ 9 ] ;
real_T P_318 ; real_T P_319 ; real_T P_320 ; real_T P_321 ; real_T P_322 [ 4
] ; real_T P_323 ; real_T P_324 ; real_T P_325 ; P_NegativeTrace_ACStesbed1_T
NegativeTrace_o ; P_PositiveTrace_ACStesbed1_T PositiveTrace_f ;
P_NegativeTrace_ACStesbed1_T NegativeTrace_g ; P_PositiveTrace_ACStesbed1_T
PositiveTrace_e ; P_NegativeTrace_ACStesbed1_T NegativeTrace_f ;
P_PositiveTrace_ACStesbed1_T PositiveTrace_p ; } ; extern P_ACStesbed1_T
ACStesbed1_rtDefaultP ; extern const ConstP_ACStesbed1_T ACStesbed1_rtConstP
;
#endif
