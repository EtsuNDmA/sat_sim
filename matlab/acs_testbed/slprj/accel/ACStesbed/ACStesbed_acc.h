#include "__cf_ACStesbed.h"
#ifndef RTW_HEADER_ACStesbed_acc_h_
#define RTW_HEADER_ACStesbed_acc_h_
#ifndef ACStesbed_acc_COMMON_INCLUDES_
#define ACStesbed_acc_COMMON_INCLUDES_
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
#include "ACStesbed_acc_types.h"
typedef struct { BusObject B_5_151_0 ; real_T B_5_5_0 ; real_T B_5_6_0 ;
real_T B_5_7_0 ; real_T B_5_8_0 ; real_T B_5_40_0 [ 9 ] ; real_T B_5_41_0 ;
real_T B_5_43_0 [ 3 ] ; real_T B_5_50_0 ; real_T B_5_55_0 ; real_T B_5_60_0 ;
real_T B_5_65_0 ; real_T B_5_89_0 ; real_T B_5_97_0 ; real_T B_5_119_0 ;
real_T B_5_139_0 [ 9 ] ; real_T B_5_143_0 [ 9 ] ; real_T B_5_148_0 [ 3 ] ;
real_T B_5_149_0 [ 3 ] ; real_T B_5_150_0 [ 3 ] ; real_T B_5_153_0 [ 3 ] ;
real_T B_5_154_0 [ 3 ] ; real_T B_5_156_0 [ 3 ] ; real_T B_5_157_0 [ 3 ] ;
real_T B_5_158_0 [ 3 ] ; real_T B_5_160_0 [ 3 ] ; real_T B_5_163_0 [ 3 ] ;
real_T B_5_174_0 ; real_T B_5_198_0 ; real_T B_5_220_0 ; real_T B_5_234_0 ;
real_T B_5_235_0 [ 3 ] ; real_T B_5_241_0 ; real_T B_5_242_0 [ 3 ] ; real_T
B_5_257_0 [ 4 ] ; real_T B_5_263_0 ; real_T B_5_266_0 ; real_T B_5_269_0 ;
real_T B_5_272_0 ; real_T B_5_291_0 [ 3 ] ; real_T B_5_292_0 [ 3 ] ; real_T
B_5_298_0 [ 3 ] ; real_T B_5_301_0 [ 3 ] ; real_T B_5_305_0 [ 3 ] ; real_T
B_5_306_0 [ 3 ] ; real_T B_5_308_0 [ 3 ] ; real_T B_5_311_0 [ 3 ] ; real_T
B_5_312_0 [ 3 ] ; real_T B_5_313_0 [ 3 ] ; real_T B_5_314_0 ; real_T
B_5_328_0 [ 18 ] ; real_T B_5_332_0 [ 3 ] ; real_T B_5_341_0 [ 18 ] ; real_T
B_5_342_0 [ 18 ] ; real_T B_5_344_0 ; real_T B_5_368_0 ; real_T B_5_376_0 ;
real_T B_5_398_0 ; real_T B_5_416_0 [ 9 ] ; real_T B_5_418_0 [ 27 ] ; real_T
B_5_419_0 [ 27 ] ; real_T B_5_421_0 [ 3 ] ; real_T B_5_422_0 [ 3 ] ; real_T
B_5_447_0 ; real_T B_5_451_0 ; real_T B_5_452_0 ; real_T B_5_453_0 ; real_T
B_5_454_0 ; real_T B_5_455_0 ; real_T B_5_465_0 [ 9 ] ; real_T B_5_467_0 [ 9
] ; real_T B_5_473_0 ; real_T B_5_474_0 ; real_T B_5_481_0 [ 9 ] ; real_T
B_5_483_0 ; real_T B_5_498_0 [ 9 ] ; real_T B_5_513_0 [ 9 ] ; real_T
B_5_515_0 [ 9 ] ; real_T B_5_520_0 ; real_T B_5_535_0 [ 9 ] ; real_T
B_5_550_0 [ 9 ] ; real_T B_5_552_0 [ 9 ] ; real_T B_5_557_0 ; real_T
B_5_572_0 [ 9 ] ; real_T B_5_587_0 [ 9 ] ; real_T B_5_589_0 [ 9 ] ; real_T
B_5_596_0 ; real_T B_5_647_0 ; real_T B_5_651_0 ; real_T B_5_652_0 ; real_T
B_5_653_0 ; real_T B_5_654_0 ; real_T B_5_658_0 [ 9 ] ; real_T B_5_667_0 [ 3
] ; real_T B_5_669_0 [ 3 ] ; real_T B_5_680_0 ; real_T B_5_704_0 ; real_T
B_5_726_0 ; real_T B_5_732_0 [ 3 ] ; real_T B_5_733_0 [ 3 ] ; real_T
B_5_736_0 [ 3 ] ; real_T B_5_739_0 [ 3 ] ; real_T B_5_745_0 [ 3 ] ; real_T
B_5_757_0 [ 3 ] ; real_T B_5_769_0 [ 3 ] ; real_T B_5_771_0 [ 3 ] ; real_T
B_5_775_0 [ 3 ] ; real_T B_5_777_0 ; real_T B_5_789_0 ; real_T B_5_805_0 ;
real_T B_5_813_0 ; real_T B_5_822_0 ; real_T B_5_835_0 ; real_T B_5_839_0 ;
real_T B_5_843_0 ; real_T B_5_844_0 [ 3 ] ; real_T B_5_0_0 [ 3 ] ; real_T
B_5_1_0 [ 3 ] ; real_T B_5_31_0 ; real_T B_5_36_0 [ 3 ] ; real_T B_5_225_0 [
3 ] ; real_T B_5_238_0 [ 3 ] ; real_T B_5_245_0 [ 3 ] ; real_T B_5_247_0 [ 3
] ; real_T B_5_274_0 ; real_T B_5_434_0 [ 9 ] ; real_T B_5_470_0 [ 9 ] ;
real_T B_5_439_0 [ 4 ] ; real_T B_5_436_0 [ 3 ] ; real_T B_5_744_0 [ 3 ] ;
real_T B_5_742_0 [ 3 ] ; real_T B_5_730_0 ; real_T B_5_713_0 ; real_T
B_5_696_0 ; real_T B_5_668_0 [ 3 ] ; } B_ACStesbed_T ; typedef struct {
real_T DiscreteTimeIntegrator_DSTATE [ 18 ] ; real_T
DiscreteTimeIntegrator1_DSTATE [ 9 ] ; real_T DiscreteTimeIntegrator2_DSTATE
[ 3 ] ; real_T Product_DWORK1 [ 9 ] ; real_T NextOutput ; real_T
Pseudoinverse_X [ 27 ] ; real_T Pseudoinverse_E [ 9 ] ; real_T
Pseudoinverse_WORK [ 3 ] ; real_T Pseudoinverse_S [ 4 ] ; real_T
Pseudoinverse_U [ 9 ] ; real_T Pseudoinverse_V [ 81 ] ; real_T
Product2_DWORK3 [ 9 ] ; real_T Product2_DWORK4 [ 9 ] ; real_T Product2_DWORK5
[ 9 ] ; real_T NextOutput_d ; struct { void * LoggedData ; } Scope_PWORK ;
void * ToWorkspace_PWORK ; void * FromWorkspace_PWORK [ 15 ] ; void *
HiddenToWks_InsertedFor_BusSelector1_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_Subsystem_at_outport_0_PWORK ; struct { void *
LoggedData ; } Scope_PWORK_d ; void *
HiddenToWks_InsertedFor_BINS_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_BINS_at_outport_1_PWORK ; struct { void * LoggedData
; } Scope_PWORK_p ; struct { void * LoggedData ; } Scope_PWORK_m ; struct {
void * LoggedData ; } Scope_PWORK_f ; void *
HiddenToWks_InsertedFor_Saturation_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_Tgrav_at_outport_0_PWORK ; struct { void * LoggedData
; } Scope_PWORK_c ; void * HiddenToWks_InsertedFor_Add_at_outport_0_PWORK ;
struct { void * LoggedData ; } Scope_PWORK_i ; struct { void * LoggedData ; }
FloatingScope_PWORK ; int32_T Product2_DWORK2 [ 3 ] ; uint32_T RandSeed ;
uint32_T RandSeed_o ; struct { int_T IcNeedsLoading ; } q0q1q2q3_IWORK ;
struct { int_T IcNeedsLoading ; } q0q1q2q3_IWORK_d ; int_T
FromWorkspace_IWORK [ 5 ] ; int_T IntegratorLimited_MODE [ 3 ] ; int_T
IntegratorLimited_MODE_k [ 3 ] ; int_T Saturation_MODE [ 3 ] ; int_T
Saturation_MODE_a [ 3 ] ; int8_T sqrt_DWORK1 ; int8_T sqrt_DWORK1_m ; int8_T
sqrt_DWORK1_h ; int8_T MathFunction1_DWORK1 ; int8_T MathFunction1_DWORK1_l ;
int8_T If_ActiveSubsystem ; int8_T PositiveTrace_SubsysRanBC ; int8_T
NegativeTrace_SubsysRanBC ; int8_T sqrt_DWORK1_n ; int8_T sqrt_DWORK1_o ;
int8_T sqrt_DWORK1_d ; int8_T sqrt_DWORK1_l ; int8_T MathFunction1_DWORK1_a ;
int8_T FindMaximumDiagonalValue_ActiveSubsystem ; int8_T
MaximumValueatDCM22_SubsysRanBC ; int8_T MaximumValueatDCM33_SubsysRanBC ;
int8_T MaximumValueatDCM11_SubsysRanBC ; int8_T sqrt_DWORK1_da ; int8_T
sqrt_DWORK1_a ; int8_T sqrt_DWORK1_i ; int8_T sqrt_DWORK1_f ; uint8_T
DiscreteTimeIntegrator_IC_LOADING ; uint8_T
DiscreteTimeIntegrator1_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator2_SYSTEM_ENABLE ; boolean_T Switch_Mode ; char
pad_Switch_Mode [ 7 ] ; } DW_ACStesbed_T ; typedef struct { real_T pqr_CSTATE
[ 3 ] ; real_T q0q1q2q3_CSTATE [ 4 ] ; real_T q0q1q2q3_CSTATE_f [ 4 ] ;
real_T Integrator_CSTATE [ 3 ] ; real_T IntegratorLimited_CSTATE [ 3 ] ;
real_T IntegratorLimited_CSTATE_d [ 3 ] ; real_T ubvbwb_CSTATE [ 3 ] ; real_T
xeyeze_CSTATE [ 3 ] ; } X_ACStesbed_T ; typedef struct { real_T pqr_CSTATE [
3 ] ; real_T q0q1q2q3_CSTATE [ 4 ] ; real_T q0q1q2q3_CSTATE_f [ 4 ] ; real_T
Integrator_CSTATE [ 3 ] ; real_T IntegratorLimited_CSTATE [ 3 ] ; real_T
IntegratorLimited_CSTATE_d [ 3 ] ; real_T ubvbwb_CSTATE [ 3 ] ; real_T
xeyeze_CSTATE [ 3 ] ; } XDot_ACStesbed_T ; typedef struct { boolean_T
pqr_CSTATE [ 3 ] ; boolean_T q0q1q2q3_CSTATE [ 4 ] ; boolean_T
q0q1q2q3_CSTATE_f [ 4 ] ; boolean_T Integrator_CSTATE [ 3 ] ; boolean_T
IntegratorLimited_CSTATE [ 3 ] ; boolean_T IntegratorLimited_CSTATE_d [ 3 ] ;
boolean_T ubvbwb_CSTATE [ 3 ] ; boolean_T xeyeze_CSTATE [ 3 ] ; }
XDis_ACStesbed_T ; typedef struct { real_T pqr_CSTATE [ 3 ] ; real_T
q0q1q2q3_CSTATE [ 4 ] ; real_T q0q1q2q3_CSTATE_f [ 4 ] ; real_T
Integrator_CSTATE [ 3 ] ; real_T IntegratorLimited_CSTATE [ 3 ] ; real_T
IntegratorLimited_CSTATE_d [ 3 ] ; real_T ubvbwb_CSTATE [ 3 ] ; real_T
xeyeze_CSTATE [ 3 ] ; } CStateAbsTol_ACStesbed_T ; typedef struct { real_T
IntegratorLimited_IntgUpLimit_ZC [ 3 ] ; real_T
IntegratorLimited_IntgLoLimit_ZC [ 3 ] ; real_T
IntegratorLimited_IntgUpLimit_ZC_o [ 3 ] ; real_T
IntegratorLimited_IntgLoLimit_ZC_l [ 3 ] ; real_T Saturation_UprLim_ZC [ 3 ]
; real_T Saturation_LwrLim_ZC [ 3 ] ; real_T Saturation_UprLim_ZC_h [ 3 ] ;
real_T Saturation_LwrLim_ZC_i [ 3 ] ; real_T Switch_SwitchCond_ZC ; }
ZCV_ACStesbed_T ; typedef struct { ZCSigState
IntegratorLimited_IntgUpLimit_ZCE [ 3 ] ; ZCSigState
IntegratorLimited_IntgLoLimit_ZCE [ 3 ] ; ZCSigState
IntegratorLimited_IntgUpLimit_ZCE_g [ 3 ] ; ZCSigState
IntegratorLimited_IntgLoLimit_ZCE_j [ 3 ] ; ZCSigState Saturation_UprLim_ZCE
[ 3 ] ; ZCSigState Saturation_LwrLim_ZCE [ 3 ] ; ZCSigState
Saturation_UprLim_ZCE_f [ 3 ] ; ZCSigState Saturation_LwrLim_ZCE_m [ 3 ] ;
ZCSigState Switch_SwitchCond_ZCE ; } PrevZCX_ACStesbed_T ; typedef struct {
real_T IdentityMatrix_ONE_VAL_RTP ; } ConstP_ACStesbed_T ; struct
P_ACStesbed_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T
P_4 ; real_T P_5 ; real_T P_6 [ 2 ] ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 [ 2 ] ; real_T P_14 ;
real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T
P_20 [ 2 ] ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 [ 3 ] ;
real_T P_25 [ 9 ] ; real_T P_26 [ 3 ] ; real_T P_27 ; real_T P_28 ; real_T
P_29 [ 9 ] ; real_T P_30 [ 9 ] ; real_T P_31 ; real_T P_32 [ 3 ] ; real_T
P_33 [ 4 ] ; real_T P_34 [ 4 ] ; real_T P_35 ; real_T P_36 ; real_T P_37 ;
real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ; real_T
P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T P_47 ; real_T P_48 [
9 ] ; real_T P_49 [ 9 ] ; real_T P_50 [ 9 ] ; real_T P_51 ; real_T P_52 ;
real_T P_53 ; real_T P_54 ; real_T P_55 [ 3 ] ; real_T P_56 [ 3 ] ; real_T
P_57 [ 3 ] ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ; real_T
P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T P_67 ;
real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ; real_T
P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ; real_T P_78 ;
real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 [ 4 ] ; real_T P_83 ;
real_T P_84 ; real_T P_85 [ 9 ] ; real_T P_86 [ 3 ] ; real_T P_87 ; real_T
P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 [ 3 ] ; real_T
P_93 ; real_T P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ;
real_T P_99 ; real_T P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ;
real_T P_104 ; real_T P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ;
real_T P_109 ; real_T P_110 ; real_T P_111 ; real_T P_112 ; real_T P_113 ;
real_T P_114 ; real_T P_115 ; real_T P_116 ; real_T P_117 ; real_T P_118 ;
real_T P_119 ; real_T P_120 ; real_T P_121 ; real_T P_122 ; real_T P_123 ;
real_T P_124 [ 9 ] ; real_T P_125 ; real_T P_126 ; real_T P_127 ; real_T
P_128 [ 3 ] ; real_T P_129 ; real_T P_130 ; real_T P_131 [ 3 ] ; real_T P_132
; real_T P_133 ; real_T P_134 ; real_T P_135 ; real_T P_136 [ 3 ] ; real_T
P_137 ; real_T P_138 ; real_T P_139 [ 3 ] ; real_T P_140 ; real_T P_141 ;
real_T P_142 ; real_T P_143 ; real_T P_144 [ 3 ] ; real_T P_145 ; real_T
P_146 ; real_T P_147 [ 3 ] ; real_T P_148 ; real_T P_149 [ 9 ] ; real_T P_150
; real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T P_154 ; real_T P_155 ;
real_T P_156 ; real_T P_157 ; real_T P_158 ; real_T P_159 [ 9 ] ; real_T
P_160 [ 9 ] ; real_T P_161 [ 9 ] ; real_T P_162 [ 9 ] ; real_T P_163 ; real_T
P_164 ; real_T P_165 ; real_T P_166 [ 3 ] ; real_T P_167 ; real_T P_168 ;
real_T P_169 ; real_T P_170 ; real_T P_171 ; real_T P_172 ; real_T P_173 ;
real_T P_174 ; real_T P_175 ; real_T P_176 ; real_T P_177 ; real_T P_178 ;
real_T P_179 [ 3 ] ; real_T P_180 ; real_T P_181 [ 3 ] ; real_T P_182 ;
real_T P_183 [ 3 ] ; real_T P_184 ; real_T P_185 [ 3 ] ; real_T P_186 ;
real_T P_187 ; real_T P_188 [ 3 ] ; real_T P_189 [ 9 ] ; real_T P_190 [ 3 ] ;
real_T P_191 [ 3 ] ; real_T P_192 ; real_T P_193 ; real_T P_194 ; real_T
P_195 [ 3 ] ; real_T P_196 ; real_T P_197 ; real_T P_198 ; real_T P_199 ;
real_T P_200 ; real_T P_201 ; real_T P_202 ; real_T P_203 ; real_T P_204 ;
real_T P_205 ; real_T P_206 ; real_T P_207 ; real_T P_208 ; real_T P_209 ;
real_T P_210 ; } ; extern P_ACStesbed_T ACStesbed_rtDefaultP ; extern const
ConstP_ACStesbed_T ACStesbed_rtConstP ;
#endif
