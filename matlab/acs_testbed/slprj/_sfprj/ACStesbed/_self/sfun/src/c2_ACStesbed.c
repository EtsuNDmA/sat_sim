/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ACStesbed_sfun.h"
#include "c2_ACStesbed.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ACStesbed_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[19] = { "x", "q", "r", "Q", "R",
  "nargin", "nargout", "W", "rz_estin", "W_estin", "Pin", "dh", "h", "gb", "J",
  "Mass", "rz_est", "W_est", "P" };

static const char * c2_b_debug_family_names[8] = { "A", "Y", "c", "nargin",
  "nargout", "x", "P", "X" };

static const char * c2_c_debug_family_names[9] = { "nargin", "nargout", "x",
  "dh", "h", "gb", "J", "Mass", "Y" };

static const char * c2_d_debug_family_names[18] = { "L", "k", "n", "nargin",
  "nargout", "X", "Wm", "Wc", "R", "dh", "h", "gb", "J", "Mass", "y", "Y", "P",
  "Y1" };

static const char * c2_e_debug_family_names[4] = { "nargin", "nargout", "x", "Z"
};

static const char * c2_f_debug_family_names[13] = { "L", "k", "n", "nargin",
  "nargout", "X", "Wm", "Wc", "R", "y", "Y", "P", "Y1" };

static const char * c2_g_debug_family_names[32] = { "L", "m", "alpha", "ki",
  "beta", "lambda", "c", "Wm", "Wc", "X", "x1", "X1", "P1", "X2", "z1", "Z1",
  "P2", "Z2", "P12", "K", "Q", "R", "nargin", "nargout", "x", "P", "z", "dh",
  "h", "gb", "J", "Mass" };

/* Function Declarations */
static void initialize_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance);
static void initialize_params_c2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance);
static void enable_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance);
static void disable_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance);
static void set_sim_state_c2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance);
static void sf_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance);
static void initSimStructsc2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_P, const char_T *c2_identifier, real_T c2_y[16]);
static void c2_b_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_W_est, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_d_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_rz_est, const char_T *c2_identifier);
static real_T c2_f_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[36]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_i_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_j_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_k_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[27]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_l_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[12]);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(uint32_T c2_u);
static void c2_b_info_helper(const mxArray **c2_info);
static void c2_c_info_helper(const mxArray **c2_info);
static real_T c2_mpower(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_a);
static void c2_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static real_T c2_eml_div(SFc2_ACStesbedInstanceStruct *chartInstance, real_T
  c2_x, real_T c2_y);
static void c2_eml_error(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_b_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_ukf(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[4],
                   real_T c2_P[16], real_T c2_z[3], real_T c2_dh[3], real_T
                   c2_h[3], real_T c2_gb[3], real_T c2_J[9], real_T c2_Mass,
                   real_T c2_b_x[4], real_T c2_b_P[16]);
static void c2_sigmas(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[4],
                      real_T c2_P[16], real_T c2_X[36]);
static void c2_eml_matlab_zpotrf(SFc2_ACStesbedInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_b_A[16], int32_T *c2_info);
static void c2_check_forloop_overflow_error(SFc2_ACStesbedInstanceStruct
  *chartInstance, boolean_T c2_overflow);
static void c2_eml_xgemv(SFc2_ACStesbedInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, int32_T c2_ia0, int32_T c2_ix0, real_T c2_y[16], int32_T
  c2_iy0, real_T c2_b_y[16]);
static void c2_b_eml_error(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_ut(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_X[36],
                  real_T c2_Wm[9], real_T c2_Wc[9], real_T c2_R[16], real_T
                  c2_dh[3], real_T c2_h[3], real_T c2_gb[3], real_T c2_J[9],
                  real_T c2_Mass, real_T c2_y[4], real_T c2_Y[36], real_T c2_P
                  [16], real_T c2_Y1[36]);
static void c2_F(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[4],
                 real_T c2_dh[3], real_T c2_h[3], real_T c2_gb[3], real_T c2_J[9],
                 real_T c2_Mass, real_T c2_Y[4]);
static void c2_b_mpower(SFc2_ACStesbedInstanceStruct *chartInstance, real_T
  c2_a[9], real_T c2_c[9]);
static void c2_inv(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[9],
                   real_T c2_y[9]);
static void c2_inv3x3(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[9],
                      real_T c2_y[9]);
static real_T c2_abs(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x);
static real_T c2_norm(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[9]);
static void c2_eml_warning(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_b_eml_warning(SFc2_ACStesbedInstanceStruct *chartInstance, char_T
  c2_varargin_2[14]);
static void c2_c_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_diag(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_v[9],
                    real_T c2_d[81]);
static void c2_d_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_e_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_b_ut(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_X[36],
                    real_T c2_Wm[9], real_T c2_Wc[9], real_T c2_R[9], real_T
                    c2_y[3], real_T c2_Y[27], real_T c2_P[9], real_T c2_Y1[27]);
static void c2_H(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[4],
                 real_T c2_Z[3]);
static void c2_f_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_g_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_h_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_i_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_j_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_k_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance);
static void c2_m_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_sprintf, const char_T *c2_identifier, char_T c2_y[14]);
static void c2_n_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, char_T c2_y[14]);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_o_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_p_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ACStesbed, const char_T *c2_identifier);
static uint8_T c2_q_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static int32_T c2_b_eml_matlab_zpotrf(SFc2_ACStesbedInstanceStruct
  *chartInstance, real_T c2_A[16]);
static void c2_b_eml_xgemv(SFc2_ACStesbedInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, int32_T c2_ia0, int32_T c2_ix0, real_T c2_y[16], int32_T
  c2_iy0);
static void init_dsm_address_info(SFc2_ACStesbedInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_ACStesbed = 0U;
}

static void initialize_params_c2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance)
{
}

static void enable_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[16];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[3];
  const mxArray *c2_c_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T *c2_rz_est;
  real_T (*c2_W_est)[3];
  real_T (*c2_P)[16];
  c2_P = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_W_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_rz_est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4), FALSE);
  for (c2_i0 = 0; c2_i0 < 16; c2_i0++) {
    c2_u[c2_i0] = (*c2_P)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_W_est)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = *c2_rz_est;
  c2_c_u = c2_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_ACStesbed;
  c2_d_u = c2_b_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[16];
  int32_T c2_i2;
  real_T c2_dv1[3];
  int32_T c2_i3;
  real_T *c2_rz_est;
  real_T (*c2_P)[16];
  real_T (*c2_W_est)[3];
  c2_P = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_W_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_rz_est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "P",
                      c2_dv0);
  for (c2_i2 = 0; c2_i2 < 16; c2_i2++) {
    (*c2_P)[c2_i2] = c2_dv0[c2_i2];
  }

  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                        "W_est", c2_dv1);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    (*c2_W_est)[c2_i3] = c2_dv1[c2_i3];
  }

  *c2_rz_est = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 2)), "rz_est");
  chartInstance->c2_is_active_c2_ACStesbed = c2_p_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "is_active_c2_ACStesbed");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_ACStesbed(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void sf_c2_ACStesbed(SFc2_ACStesbedInstanceStruct *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  int32_T c2_i13;
  real_T c2_W[3];
  real_T c2_rz_estin;
  int32_T c2_i14;
  real_T c2_W_estin[3];
  int32_T c2_i15;
  real_T c2_Pin[16];
  int32_T c2_i16;
  real_T c2_dh[3];
  int32_T c2_i17;
  real_T c2_h[3];
  int32_T c2_i18;
  real_T c2_gb[3];
  int32_T c2_i19;
  real_T c2_J[9];
  real_T c2_Mass;
  uint32_T c2_debug_family_var_map[19];
  real_T c2_x[4];
  real_T c2_q;
  real_T c2_r;
  real_T c2_Q[16];
  real_T c2_R[9];
  real_T c2_nargin = 9.0;
  real_T c2_nargout = 3.0;
  real_T c2_rz_est;
  real_T c2_W_est[3];
  real_T c2_P[16];
  int32_T c2_i20;
  int32_T c2_i21;
  static real_T c2_dv2[16] = { 1.0E-12, 0.0, 0.0, 0.0, 0.0, 1.0E-12, 0.0, 0.0,
    0.0, 0.0, 1.0E-12, 0.0, 0.0, 0.0, 0.0, 1.0E-12 };

  int32_T c2_i22;
  static real_T c2_dv3[9] = { 2.5000000000000004E-11, 0.0, 0.0, 0.0,
    2.5000000000000004E-11, 0.0, 0.0, 0.0, 2.5000000000000004E-11 };

  int32_T c2_i23;
  real_T c2_b_x[4];
  int32_T c2_i24;
  real_T c2_b_Pin[16];
  int32_T c2_i25;
  real_T c2_b_W[3];
  int32_T c2_i26;
  real_T c2_b_dh[3];
  int32_T c2_i27;
  real_T c2_b_h[3];
  int32_T c2_i28;
  real_T c2_b_gb[3];
  int32_T c2_i29;
  real_T c2_b_J[9];
  real_T c2_b_P[16];
  real_T c2_c_x[4];
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  real_T *c2_b_rz_estin;
  real_T *c2_b_rz_est;
  real_T *c2_b_Mass;
  real_T (*c2_b_W_est)[3];
  real_T (*c2_c_P)[16];
  real_T (*c2_c_J)[9];
  real_T (*c2_c_gb)[3];
  real_T (*c2_c_h)[3];
  real_T (*c2_c_dh)[3];
  real_T (*c2_c_Pin)[16];
  real_T (*c2_b_W_estin)[3];
  real_T (*c2_c_W)[3];
  c2_b_Mass = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c2_c_P = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_W_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_c_J = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 7);
  c2_c_gb = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
  c2_c_h = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c2_c_dh = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_rz_est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_c_Pin = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_W_estin = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_rz_estin = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_c_W = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_W)[c2_i4], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_rz_estin, 1U);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_W_estin)[c2_i5], 2U);
  }

  for (c2_i6 = 0; c2_i6 < 16; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_Pin)[c2_i6], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_rz_est, 4U);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_dh)[c2_i7], 5U);
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_h)[c2_i8], 6U);
  }

  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_gb)[c2_i9], 7U);
  }

  for (c2_i10 = 0; c2_i10 < 9; c2_i10++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_J)[c2_i10], 8U);
  }

  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_W_est)[c2_i11], 9U);
  }

  for (c2_i12 = 0; c2_i12 < 16; c2_i12++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_P)[c2_i12], 10U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_Mass, 11U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_rz_estin;
  c2_b_hoistedGlobal = *c2_b_Mass;
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    c2_W[c2_i13] = (*c2_c_W)[c2_i13];
  }

  c2_rz_estin = c2_hoistedGlobal;
  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    c2_W_estin[c2_i14] = (*c2_b_W_estin)[c2_i14];
  }

  for (c2_i15 = 0; c2_i15 < 16; c2_i15++) {
    c2_Pin[c2_i15] = (*c2_c_Pin)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    c2_dh[c2_i16] = (*c2_c_dh)[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
    c2_h[c2_i17] = (*c2_c_h)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 3; c2_i18++) {
    c2_gb[c2_i18] = (*c2_c_gb)[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 9; c2_i19++) {
    c2_J[c2_i19] = (*c2_c_J)[c2_i19];
  }

  c2_Mass = c2_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x, 0U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_q, 1U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_r, 2U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Q, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_R, 4U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 5U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 6U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_W, 7U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_rz_estin, 8U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_W_estin, 9U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Pin, 10U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_dh, 11U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_h, 12U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_gb, 13U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_J, 14U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_Mass, 15U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_rz_est, 16U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_W_est, 17U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
    c2_x[c2_i20] = c2_W_estin[c2_i20];
  }

  c2_x[3] = c2_rz_estin;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_q = 1.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_r = 5.0E-6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i21 = 0; c2_i21 < 16; c2_i21++) {
    c2_Q[c2_i21] = c2_dv2[c2_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i22 = 0; c2_i22 < 9; c2_i22++) {
    c2_R[c2_i22] = c2_dv3[c2_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i23 = 0; c2_i23 < 4; c2_i23++) {
    c2_b_x[c2_i23] = c2_x[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 16; c2_i24++) {
    c2_b_Pin[c2_i24] = c2_Pin[c2_i24];
  }

  for (c2_i25 = 0; c2_i25 < 3; c2_i25++) {
    c2_b_W[c2_i25] = c2_W[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 3; c2_i26++) {
    c2_b_dh[c2_i26] = c2_dh[c2_i26];
  }

  for (c2_i27 = 0; c2_i27 < 3; c2_i27++) {
    c2_b_h[c2_i27] = c2_h[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 3; c2_i28++) {
    c2_b_gb[c2_i28] = c2_gb[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 9; c2_i29++) {
    c2_b_J[c2_i29] = c2_J[c2_i29];
  }

  c2_ukf(chartInstance, c2_b_x, c2_b_Pin, c2_b_W, c2_b_dh, c2_b_h, c2_b_gb,
         c2_b_J, c2_Mass, c2_c_x, c2_b_P);
  for (c2_i30 = 0; c2_i30 < 4; c2_i30++) {
    c2_x[c2_i30] = c2_c_x[c2_i30];
  }

  for (c2_i31 = 0; c2_i31 < 16; c2_i31++) {
    c2_P[c2_i31] = c2_b_P[c2_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i32 = 0; c2_i32 < 3; c2_i32++) {
    c2_W_est[c2_i32] = c2_x[c2_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_rz_est = c2_x[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_rz_est = c2_rz_est;
  for (c2_i33 = 0; c2_i33 < 3; c2_i33++) {
    (*c2_b_W_est)[c2_i33] = c2_W_est[c2_i33];
  }

  for (c2_i34 = 0; c2_i34 < 16; c2_i34++) {
    (*c2_c_P)[c2_i34] = c2_P[c2_i34];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ACStesbedMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_ACStesbed(SFc2_ACStesbedInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T c2_b_inData[16];
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i35 = 0;
  for (c2_i36 = 0; c2_i36 < 4; c2_i36++) {
    for (c2_i37 = 0; c2_i37 < 4; c2_i37++) {
      c2_b_inData[c2_i37 + c2_i35] = (*(real_T (*)[16])c2_inData)[c2_i37 +
        c2_i35];
    }

    c2_i35 += 4;
  }

  c2_i38 = 0;
  for (c2_i39 = 0; c2_i39 < 4; c2_i39++) {
    for (c2_i40 = 0; c2_i40 < 4; c2_i40++) {
      c2_u[c2_i40 + c2_i38] = c2_b_inData[c2_i40 + c2_i38];
    }

    c2_i38 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_P, const char_T *c2_identifier, real_T c2_y[16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_P);
}

static void c2_b_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16])
{
  real_T c2_dv4[16];
  int32_T c2_i41;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i41 = 0; c2_i41 < 16; c2_i41++) {
    c2_y[c2_i41] = c2_dv4[c2_i41];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_P;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_P = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_P);
  c2_i42 = 0;
  for (c2_i43 = 0; c2_i43 < 4; c2_i43++) {
    for (c2_i44 = 0; c2_i44 < 4; c2_i44++) {
      (*(real_T (*)[16])c2_outData)[c2_i44 + c2_i42] = c2_y[c2_i44 + c2_i42];
    }

    c2_i42 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i45;
  real_T c2_b_inData[3];
  int32_T c2_i46;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i45 = 0; c2_i45 < 3; c2_i45++) {
    c2_b_inData[c2_i45] = (*(real_T (*)[3])c2_inData)[c2_i45];
  }

  for (c2_i46 = 0; c2_i46 < 3; c2_i46++) {
    c2_u[c2_i46] = c2_b_inData[c2_i46];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_W_est, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_W_est), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_W_est);
}

static void c2_d_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv5[3];
  int32_T c2_i47;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i47 = 0; c2_i47 < 3; c2_i47++) {
    c2_y[c2_i47] = c2_dv5[c2_i47];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_W_est;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i48;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_W_est = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_W_est), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_W_est);
  for (c2_i48 = 0; c2_i48 < 3; c2_i48++) {
    (*(real_T (*)[3])c2_outData)[c2_i48] = c2_y[c2_i48];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_rz_est, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_rz_est), &c2_thisId);
  sf_mex_destroy(&c2_rz_est);
  return c2_y;
}

static real_T c2_f_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_rz_est;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_rz_est = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_rz_est), &c2_thisId);
  sf_mex_destroy(&c2_rz_est);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  real_T c2_b_inData[9];
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i49 = 0;
  for (c2_i50 = 0; c2_i50 < 3; c2_i50++) {
    for (c2_i51 = 0; c2_i51 < 3; c2_i51++) {
      c2_b_inData[c2_i51 + c2_i49] = (*(real_T (*)[9])c2_inData)[c2_i51 + c2_i49];
    }

    c2_i49 += 3;
  }

  c2_i52 = 0;
  for (c2_i53 = 0; c2_i53 < 3; c2_i53++) {
    for (c2_i54 = 0; c2_i54 < 3; c2_i54++) {
      c2_u[c2_i54 + c2_i52] = c2_b_inData[c2_i54 + c2_i52];
    }

    c2_i52 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i55;
  real_T c2_b_inData[4];
  int32_T c2_i56;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i55 = 0; c2_i55 < 4; c2_i55++) {
    c2_b_inData[c2_i55] = (*(real_T (*)[4])c2_inData)[c2_i55];
  }

  for (c2_i56 = 0; c2_i56 < 4; c2_i56++) {
    c2_u[c2_i56] = c2_b_inData[c2_i56];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv6[4];
  int32_T c2_i57;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv6, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i57 = 0; c2_i57 < 4; c2_i57++) {
    c2_y[c2_i57] = c2_dv6[c2_i57];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_x;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i58;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_x = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_x), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_x);
  for (c2_i58 = 0; c2_i58 < 4; c2_i58++) {
    (*(real_T (*)[4])c2_outData)[c2_i58] = c2_y[c2_i58];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  real_T c2_b_inData[36];
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  real_T c2_u[36];
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i59 = 0;
  for (c2_i60 = 0; c2_i60 < 9; c2_i60++) {
    for (c2_i61 = 0; c2_i61 < 4; c2_i61++) {
      c2_b_inData[c2_i61 + c2_i59] = (*(real_T (*)[36])c2_inData)[c2_i61 +
        c2_i59];
    }

    c2_i59 += 4;
  }

  c2_i62 = 0;
  for (c2_i63 = 0; c2_i63 < 9; c2_i63++) {
    for (c2_i64 = 0; c2_i64 < 4; c2_i64++) {
      c2_u[c2_i64 + c2_i62] = c2_b_inData[c2_i64 + c2_i62];
    }

    c2_i62 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 9), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[36])
{
  real_T c2_dv7[36];
  int32_T c2_i65;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv7, 1, 0, 0U, 1, 0U, 2, 4, 9);
  for (c2_i65 = 0; c2_i65 < 36; c2_i65++) {
    c2_y[c2_i65] = c2_dv7[c2_i65];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_X;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[36];
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_X = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_X), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_X);
  c2_i66 = 0;
  for (c2_i67 = 0; c2_i67 < 9; c2_i67++) {
    for (c2_i68 = 0; c2_i68 < 4; c2_i68++) {
      (*(real_T (*)[36])c2_outData)[c2_i68 + c2_i66] = c2_y[c2_i68 + c2_i66];
    }

    c2_i66 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_i_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9])
{
  real_T c2_dv8[9];
  int32_T c2_i69;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv8, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i69 = 0; c2_i69 < 9; c2_i69++) {
    c2_y[c2_i69] = c2_dv8[c2_i69];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_J;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_J = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_J), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_J);
  c2_i70 = 0;
  for (c2_i71 = 0; c2_i71 < 3; c2_i71++) {
    for (c2_i72 = 0; c2_i72 < 3; c2_i72++) {
      (*(real_T (*)[9])c2_outData)[c2_i72 + c2_i70] = c2_y[c2_i72 + c2_i70];
    }

    c2_i70 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i73;
  real_T c2_b_inData[9];
  int32_T c2_i74;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i73 = 0; c2_i73 < 9; c2_i73++) {
    c2_b_inData[c2_i73] = (*(real_T (*)[9])c2_inData)[c2_i73];
  }

  for (c2_i74 = 0; c2_i74 < 9; c2_i74++) {
    c2_u[c2_i74] = c2_b_inData[c2_i74];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_j_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9])
{
  real_T c2_dv9[9];
  int32_T c2_i75;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv9, 1, 0, 0U, 1, 0U, 2, 1, 9);
  for (c2_i75 = 0; c2_i75 < 9; c2_i75++) {
    c2_y[c2_i75] = c2_dv9[c2_i75];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Wc;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i76;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_Wc = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Wc), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Wc);
  for (c2_i76 = 0; c2_i76 < 9; c2_i76++) {
    (*(real_T (*)[9])c2_outData)[c2_i76] = c2_y[c2_i76];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  real_T c2_b_inData[27];
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  real_T c2_u[27];
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i77 = 0;
  for (c2_i78 = 0; c2_i78 < 9; c2_i78++) {
    for (c2_i79 = 0; c2_i79 < 3; c2_i79++) {
      c2_b_inData[c2_i79 + c2_i77] = (*(real_T (*)[27])c2_inData)[c2_i79 +
        c2_i77];
    }

    c2_i77 += 3;
  }

  c2_i80 = 0;
  for (c2_i81 = 0; c2_i81 < 9; c2_i81++) {
    for (c2_i82 = 0; c2_i82 < 3; c2_i82++) {
      c2_u[c2_i82 + c2_i80] = c2_b_inData[c2_i82 + c2_i80];
    }

    c2_i80 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 9), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_k_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[27])
{
  real_T c2_dv10[27];
  int32_T c2_i83;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv10, 1, 0, 0U, 1, 0U, 2, 3, 9);
  for (c2_i83 = 0; c2_i83 < 27; c2_i83++) {
    c2_y[c2_i83] = c2_dv10[c2_i83];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Y1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[27];
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_Y1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Y1), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Y1);
  c2_i84 = 0;
  for (c2_i85 = 0; c2_i85 < 9; c2_i85++) {
    for (c2_i86 = 0; c2_i86 < 3; c2_i86++) {
      (*(real_T (*)[27])c2_outData)[c2_i86 + c2_i84] = c2_y[c2_i86 + c2_i84];
    }

    c2_i84 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  real_T c2_b_inData[12];
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  real_T c2_u[12];
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i87 = 0;
  for (c2_i88 = 0; c2_i88 < 3; c2_i88++) {
    for (c2_i89 = 0; c2_i89 < 4; c2_i89++) {
      c2_b_inData[c2_i89 + c2_i87] = (*(real_T (*)[12])c2_inData)[c2_i89 +
        c2_i87];
    }

    c2_i87 += 4;
  }

  c2_i90 = 0;
  for (c2_i91 = 0; c2_i91 < 3; c2_i91++) {
    for (c2_i92 = 0; c2_i92 < 4; c2_i92++) {
      c2_u[c2_i92 + c2_i90] = c2_b_inData[c2_i92 + c2_i90];
    }

    c2_i90 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_l_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[12])
{
  real_T c2_dv11[12];
  int32_T c2_i93;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv11, 1, 0, 0U, 1, 0U, 2, 4, 3);
  for (c2_i93 = 0; c2_i93 < 12; c2_i93++) {
    c2_y[c2_i93] = c2_dv11[c2_i93];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_K;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[12];
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_K = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_K), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_K);
  c2_i94 = 0;
  for (c2_i95 = 0; c2_i95 < 3; c2_i95++) {
    for (c2_i96 = 0; c2_i96 < 4; c2_i96++) {
      (*(real_T (*)[12])c2_outData)[c2_i96 + c2_i94] = c2_y[c2_i96 + c2_i94];
    }

    c2_i94 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_ACStesbed_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 138, 1),
                FALSE);
  c2_info_helper(&c2_nameCaptureInfo);
  c2_b_info_helper(&c2_nameCaptureInfo);
  c2_c_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  const mxArray *c2_rhs11 = NULL;
  const mxArray *c2_lhs11 = NULL;
  const mxArray *c2_rhs12 = NULL;
  const mxArray *c2_lhs12 = NULL;
  const mxArray *c2_rhs13 = NULL;
  const mxArray *c2_lhs13 = NULL;
  const mxArray *c2_rhs14 = NULL;
  const mxArray *c2_lhs14 = NULL;
  const mxArray *c2_rhs15 = NULL;
  const mxArray *c2_lhs15 = NULL;
  const mxArray *c2_rhs16 = NULL;
  const mxArray *c2_lhs16 = NULL;
  const mxArray *c2_rhs17 = NULL;
  const mxArray *c2_lhs17 = NULL;
  const mxArray *c2_rhs18 = NULL;
  const mxArray *c2_lhs18 = NULL;
  const mxArray *c2_rhs19 = NULL;
  const mxArray *c2_lhs19 = NULL;
  const mxArray *c2_rhs20 = NULL;
  const mxArray *c2_lhs20 = NULL;
  const mxArray *c2_rhs21 = NULL;
  const mxArray *c2_lhs21 = NULL;
  const mxArray *c2_rhs22 = NULL;
  const mxArray *c2_lhs22 = NULL;
  const mxArray *c2_rhs23 = NULL;
  const mxArray *c2_lhs23 = NULL;
  const mxArray *c2_rhs24 = NULL;
  const mxArray *c2_lhs24 = NULL;
  const mxArray *c2_rhs25 = NULL;
  const mxArray *c2_lhs25 = NULL;
  const mxArray *c2_rhs26 = NULL;
  const mxArray *c2_lhs26 = NULL;
  const mxArray *c2_rhs27 = NULL;
  const mxArray *c2_lhs27 = NULL;
  const mxArray *c2_rhs28 = NULL;
  const mxArray *c2_lhs28 = NULL;
  const mxArray *c2_rhs29 = NULL;
  const mxArray *c2_lhs29 = NULL;
  const mxArray *c2_rhs30 = NULL;
  const mxArray *c2_lhs30 = NULL;
  const mxArray *c2_rhs31 = NULL;
  const mxArray *c2_lhs31 = NULL;
  const mxArray *c2_rhs32 = NULL;
  const mxArray *c2_lhs32 = NULL;
  const mxArray *c2_rhs33 = NULL;
  const mxArray *c2_lhs33 = NULL;
  const mxArray *c2_rhs34 = NULL;
  const mxArray *c2_lhs34 = NULL;
  const mxArray *c2_rhs35 = NULL;
  const mxArray *c2_lhs35 = NULL;
  const mxArray *c2_rhs36 = NULL;
  const mxArray *c2_lhs36 = NULL;
  const mxArray *c2_rhs37 = NULL;
  const mxArray *c2_lhs37 = NULL;
  const mxArray *c2_rhs38 = NULL;
  const mxArray *c2_lhs38 = NULL;
  const mxArray *c2_rhs39 = NULL;
  const mxArray *c2_lhs39 = NULL;
  const mxArray *c2_rhs40 = NULL;
  const mxArray *c2_lhs40 = NULL;
  const mxArray *c2_rhs41 = NULL;
  const mxArray *c2_lhs41 = NULL;
  const mxArray *c2_rhs42 = NULL;
  const mxArray *c2_lhs42 = NULL;
  const mxArray *c2_rhs43 = NULL;
  const mxArray *c2_lhs43 = NULL;
  const mxArray *c2_rhs44 = NULL;
  const mxArray *c2_lhs44 = NULL;
  const mxArray *c2_rhs45 = NULL;
  const mxArray *c2_lhs45 = NULL;
  const mxArray *c2_rhs46 = NULL;
  const mxArray *c2_lhs46 = NULL;
  const mxArray *c2_rhs47 = NULL;
  const mxArray *c2_lhs47 = NULL;
  const mxArray *c2_rhs48 = NULL;
  const mxArray *c2_lhs48 = NULL;
  const mxArray *c2_rhs49 = NULL;
  const mxArray *c2_lhs49 = NULL;
  const mxArray *c2_rhs50 = NULL;
  const mxArray *c2_lhs50 = NULL;
  const mxArray *c2_rhs51 = NULL;
  const mxArray *c2_lhs51 = NULL;
  const mxArray *c2_rhs52 = NULL;
  const mxArray *c2_lhs52 = NULL;
  const mxArray *c2_rhs53 = NULL;
  const mxArray *c2_lhs53 = NULL;
  const mxArray *c2_rhs54 = NULL;
  const mxArray *c2_lhs54 = NULL;
  const mxArray *c2_rhs55 = NULL;
  const mxArray *c2_lhs55 = NULL;
  const mxArray *c2_rhs56 = NULL;
  const mxArray *c2_lhs56 = NULL;
  const mxArray *c2_rhs57 = NULL;
  const mxArray *c2_lhs57 = NULL;
  const mxArray *c2_rhs58 = NULL;
  const mxArray *c2_lhs58 = NULL;
  const mxArray *c2_rhs59 = NULL;
  const mxArray *c2_lhs59 = NULL;
  const mxArray *c2_rhs60 = NULL;
  const mxArray *c2_lhs60 = NULL;
  const mxArray *c2_rhs61 = NULL;
  const mxArray *c2_lhs61 = NULL;
  const mxArray *c2_rhs62 = NULL;
  const mxArray *c2_lhs62 = NULL;
  const mxArray *c2_rhs63 = NULL;
  const mxArray *c2_lhs63 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331294058U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703080U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1358175340U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703054U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811526U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c2_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c2_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eye"), "name", "name", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1368175830U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c2_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1368175830U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c2_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c2_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isinf"), "name", "name", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703056U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c2_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c2_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811582U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c2_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362251082U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c2_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmin"), "name", "name", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362251082U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c2_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326717522U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c2_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326717196U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c2_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmin"), "name", "name", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362251082U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c2_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size"),
                  "context", "context", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c2_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c2_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362251082U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c2_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1346503140U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c2_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362251082U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c2_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c2_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1373299308U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1319722766U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c2_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703080U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c2_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c2_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c2_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703066U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c2_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sqrt"), "name", "name", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343823186U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c2_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_error"), "name", "name",
                  36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343823158U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c2_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811538U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c2_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("chol"), "name", "name", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/chol.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1344464834U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c2_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/chol.m!cholesky"),
                  "context", "context", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c2_rhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/chol.m!cholesky"),
                  "context", "context", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331294058U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c2_rhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/chol.m!cholesky"),
                  "context", "context", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1346503140U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c2_rhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/chol.m!cholesky"),
                  "context", "context", 42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_error"), "name", "name",
                  42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343823158U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c2_rhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/chol.m!cholesky"),
                  "context", "context", 43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xpotrf"), "name", "name",
                  43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xpotrf.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811608U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c2_rhs43, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs43, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xpotrf.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_lapack_xpotrf"), "name",
                  "name", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xpotrf.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811612U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c2_rhs44, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs44, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xpotrf.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_matlab_zpotrf"), "name",
                  "name", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811624U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c2_rhs45, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs45, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c2_rhs46, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs46, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c2_rhs47, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs47, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1346503140U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c2_rhs48, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs48, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c2_rhs49, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs49, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c2_rhs50, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs50, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c2_rhs51, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs51, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c2_rhs52, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs52, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703070U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c2_rhs53, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs53, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1299069568U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c2_rhs54, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs54, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xdot"), "name", "name", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703068U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c2_rhs55, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs55, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1299069568U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c2_rhs56, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs56, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold"),
                  "context", "context", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("length"), "name", "name", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1303139006U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c2_rhs57, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs57, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 58);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 58);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c2_rhs58, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs58, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 59);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 59);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c2_rhs59, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs59, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_refblas_xdot"), "name",
                  "name", 60);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1299069572U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c2_rhs60, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs60, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_refblas_xdotx"), "name",
                  "name", 61);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1360271550U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c2_rhs61, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs61, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 62);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 62);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c2_rhs62, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs62, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 63);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c2_rhs63, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs63, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
  sf_mex_destroy(&c2_rhs11);
  sf_mex_destroy(&c2_lhs11);
  sf_mex_destroy(&c2_rhs12);
  sf_mex_destroy(&c2_lhs12);
  sf_mex_destroy(&c2_rhs13);
  sf_mex_destroy(&c2_lhs13);
  sf_mex_destroy(&c2_rhs14);
  sf_mex_destroy(&c2_lhs14);
  sf_mex_destroy(&c2_rhs15);
  sf_mex_destroy(&c2_lhs15);
  sf_mex_destroy(&c2_rhs16);
  sf_mex_destroy(&c2_lhs16);
  sf_mex_destroy(&c2_rhs17);
  sf_mex_destroy(&c2_lhs17);
  sf_mex_destroy(&c2_rhs18);
  sf_mex_destroy(&c2_lhs18);
  sf_mex_destroy(&c2_rhs19);
  sf_mex_destroy(&c2_lhs19);
  sf_mex_destroy(&c2_rhs20);
  sf_mex_destroy(&c2_lhs20);
  sf_mex_destroy(&c2_rhs21);
  sf_mex_destroy(&c2_lhs21);
  sf_mex_destroy(&c2_rhs22);
  sf_mex_destroy(&c2_lhs22);
  sf_mex_destroy(&c2_rhs23);
  sf_mex_destroy(&c2_lhs23);
  sf_mex_destroy(&c2_rhs24);
  sf_mex_destroy(&c2_lhs24);
  sf_mex_destroy(&c2_rhs25);
  sf_mex_destroy(&c2_lhs25);
  sf_mex_destroy(&c2_rhs26);
  sf_mex_destroy(&c2_lhs26);
  sf_mex_destroy(&c2_rhs27);
  sf_mex_destroy(&c2_lhs27);
  sf_mex_destroy(&c2_rhs28);
  sf_mex_destroy(&c2_lhs28);
  sf_mex_destroy(&c2_rhs29);
  sf_mex_destroy(&c2_lhs29);
  sf_mex_destroy(&c2_rhs30);
  sf_mex_destroy(&c2_lhs30);
  sf_mex_destroy(&c2_rhs31);
  sf_mex_destroy(&c2_lhs31);
  sf_mex_destroy(&c2_rhs32);
  sf_mex_destroy(&c2_lhs32);
  sf_mex_destroy(&c2_rhs33);
  sf_mex_destroy(&c2_lhs33);
  sf_mex_destroy(&c2_rhs34);
  sf_mex_destroy(&c2_lhs34);
  sf_mex_destroy(&c2_rhs35);
  sf_mex_destroy(&c2_lhs35);
  sf_mex_destroy(&c2_rhs36);
  sf_mex_destroy(&c2_lhs36);
  sf_mex_destroy(&c2_rhs37);
  sf_mex_destroy(&c2_lhs37);
  sf_mex_destroy(&c2_rhs38);
  sf_mex_destroy(&c2_lhs38);
  sf_mex_destroy(&c2_rhs39);
  sf_mex_destroy(&c2_lhs39);
  sf_mex_destroy(&c2_rhs40);
  sf_mex_destroy(&c2_lhs40);
  sf_mex_destroy(&c2_rhs41);
  sf_mex_destroy(&c2_lhs41);
  sf_mex_destroy(&c2_rhs42);
  sf_mex_destroy(&c2_lhs42);
  sf_mex_destroy(&c2_rhs43);
  sf_mex_destroy(&c2_lhs43);
  sf_mex_destroy(&c2_rhs44);
  sf_mex_destroy(&c2_lhs44);
  sf_mex_destroy(&c2_rhs45);
  sf_mex_destroy(&c2_lhs45);
  sf_mex_destroy(&c2_rhs46);
  sf_mex_destroy(&c2_lhs46);
  sf_mex_destroy(&c2_rhs47);
  sf_mex_destroy(&c2_lhs47);
  sf_mex_destroy(&c2_rhs48);
  sf_mex_destroy(&c2_lhs48);
  sf_mex_destroy(&c2_rhs49);
  sf_mex_destroy(&c2_lhs49);
  sf_mex_destroy(&c2_rhs50);
  sf_mex_destroy(&c2_lhs50);
  sf_mex_destroy(&c2_rhs51);
  sf_mex_destroy(&c2_lhs51);
  sf_mex_destroy(&c2_rhs52);
  sf_mex_destroy(&c2_lhs52);
  sf_mex_destroy(&c2_rhs53);
  sf_mex_destroy(&c2_lhs53);
  sf_mex_destroy(&c2_rhs54);
  sf_mex_destroy(&c2_lhs54);
  sf_mex_destroy(&c2_rhs55);
  sf_mex_destroy(&c2_lhs55);
  sf_mex_destroy(&c2_rhs56);
  sf_mex_destroy(&c2_lhs56);
  sf_mex_destroy(&c2_rhs57);
  sf_mex_destroy(&c2_lhs57);
  sf_mex_destroy(&c2_rhs58);
  sf_mex_destroy(&c2_lhs58);
  sf_mex_destroy(&c2_rhs59);
  sf_mex_destroy(&c2_lhs59);
  sf_mex_destroy(&c2_rhs60);
  sf_mex_destroy(&c2_lhs60);
  sf_mex_destroy(&c2_rhs61);
  sf_mex_destroy(&c2_lhs61);
  sf_mex_destroy(&c2_rhs62);
  sf_mex_destroy(&c2_lhs62);
  sf_mex_destroy(&c2_rhs63);
  sf_mex_destroy(&c2_lhs63);
}

static const mxArray *c2_emlrt_marshallOut(char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), FALSE);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c2_y;
}

static void c2_b_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs64 = NULL;
  const mxArray *c2_lhs64 = NULL;
  const mxArray *c2_rhs65 = NULL;
  const mxArray *c2_lhs65 = NULL;
  const mxArray *c2_rhs66 = NULL;
  const mxArray *c2_lhs66 = NULL;
  const mxArray *c2_rhs67 = NULL;
  const mxArray *c2_lhs67 = NULL;
  const mxArray *c2_rhs68 = NULL;
  const mxArray *c2_lhs68 = NULL;
  const mxArray *c2_rhs69 = NULL;
  const mxArray *c2_lhs69 = NULL;
  const mxArray *c2_rhs70 = NULL;
  const mxArray *c2_lhs70 = NULL;
  const mxArray *c2_rhs71 = NULL;
  const mxArray *c2_lhs71 = NULL;
  const mxArray *c2_rhs72 = NULL;
  const mxArray *c2_lhs72 = NULL;
  const mxArray *c2_rhs73 = NULL;
  const mxArray *c2_lhs73 = NULL;
  const mxArray *c2_rhs74 = NULL;
  const mxArray *c2_lhs74 = NULL;
  const mxArray *c2_rhs75 = NULL;
  const mxArray *c2_lhs75 = NULL;
  const mxArray *c2_rhs76 = NULL;
  const mxArray *c2_lhs76 = NULL;
  const mxArray *c2_rhs77 = NULL;
  const mxArray *c2_lhs77 = NULL;
  const mxArray *c2_rhs78 = NULL;
  const mxArray *c2_lhs78 = NULL;
  const mxArray *c2_rhs79 = NULL;
  const mxArray *c2_lhs79 = NULL;
  const mxArray *c2_rhs80 = NULL;
  const mxArray *c2_lhs80 = NULL;
  const mxArray *c2_rhs81 = NULL;
  const mxArray *c2_lhs81 = NULL;
  const mxArray *c2_rhs82 = NULL;
  const mxArray *c2_lhs82 = NULL;
  const mxArray *c2_rhs83 = NULL;
  const mxArray *c2_lhs83 = NULL;
  const mxArray *c2_rhs84 = NULL;
  const mxArray *c2_lhs84 = NULL;
  const mxArray *c2_rhs85 = NULL;
  const mxArray *c2_lhs85 = NULL;
  const mxArray *c2_rhs86 = NULL;
  const mxArray *c2_lhs86 = NULL;
  const mxArray *c2_rhs87 = NULL;
  const mxArray *c2_lhs87 = NULL;
  const mxArray *c2_rhs88 = NULL;
  const mxArray *c2_lhs88 = NULL;
  const mxArray *c2_rhs89 = NULL;
  const mxArray *c2_lhs89 = NULL;
  const mxArray *c2_rhs90 = NULL;
  const mxArray *c2_lhs90 = NULL;
  const mxArray *c2_rhs91 = NULL;
  const mxArray *c2_lhs91 = NULL;
  const mxArray *c2_rhs92 = NULL;
  const mxArray *c2_lhs92 = NULL;
  const mxArray *c2_rhs93 = NULL;
  const mxArray *c2_lhs93 = NULL;
  const mxArray *c2_rhs94 = NULL;
  const mxArray *c2_lhs94 = NULL;
  const mxArray *c2_rhs95 = NULL;
  const mxArray *c2_lhs95 = NULL;
  const mxArray *c2_rhs96 = NULL;
  const mxArray *c2_lhs96 = NULL;
  const mxArray *c2_rhs97 = NULL;
  const mxArray *c2_lhs97 = NULL;
  const mxArray *c2_rhs98 = NULL;
  const mxArray *c2_lhs98 = NULL;
  const mxArray *c2_rhs99 = NULL;
  const mxArray *c2_lhs99 = NULL;
  const mxArray *c2_rhs100 = NULL;
  const mxArray *c2_lhs100 = NULL;
  const mxArray *c2_rhs101 = NULL;
  const mxArray *c2_lhs101 = NULL;
  const mxArray *c2_rhs102 = NULL;
  const mxArray *c2_lhs102 = NULL;
  const mxArray *c2_rhs103 = NULL;
  const mxArray *c2_lhs103 = NULL;
  const mxArray *c2_rhs104 = NULL;
  const mxArray *c2_lhs104 = NULL;
  const mxArray *c2_rhs105 = NULL;
  const mxArray *c2_lhs105 = NULL;
  const mxArray *c2_rhs106 = NULL;
  const mxArray *c2_lhs106 = NULL;
  const mxArray *c2_rhs107 = NULL;
  const mxArray *c2_lhs107 = NULL;
  const mxArray *c2_rhs108 = NULL;
  const mxArray *c2_lhs108 = NULL;
  const mxArray *c2_rhs109 = NULL;
  const mxArray *c2_lhs109 = NULL;
  const mxArray *c2_rhs110 = NULL;
  const mxArray *c2_lhs110 = NULL;
  const mxArray *c2_rhs111 = NULL;
  const mxArray *c2_lhs111 = NULL;
  const mxArray *c2_rhs112 = NULL;
  const mxArray *c2_lhs112 = NULL;
  const mxArray *c2_rhs113 = NULL;
  const mxArray *c2_lhs113 = NULL;
  const mxArray *c2_rhs114 = NULL;
  const mxArray *c2_lhs114 = NULL;
  const mxArray *c2_rhs115 = NULL;
  const mxArray *c2_lhs115 = NULL;
  const mxArray *c2_rhs116 = NULL;
  const mxArray *c2_lhs116 = NULL;
  const mxArray *c2_rhs117 = NULL;
  const mxArray *c2_lhs117 = NULL;
  const mxArray *c2_rhs118 = NULL;
  const mxArray *c2_lhs118 = NULL;
  const mxArray *c2_rhs119 = NULL;
  const mxArray *c2_lhs119 = NULL;
  const mxArray *c2_rhs120 = NULL;
  const mxArray *c2_lhs120 = NULL;
  const mxArray *c2_rhs121 = NULL;
  const mxArray *c2_lhs121 = NULL;
  const mxArray *c2_rhs122 = NULL;
  const mxArray *c2_lhs122 = NULL;
  const mxArray *c2_rhs123 = NULL;
  const mxArray *c2_lhs123 = NULL;
  const mxArray *c2_rhs124 = NULL;
  const mxArray *c2_lhs124 = NULL;
  const mxArray *c2_rhs125 = NULL;
  const mxArray *c2_lhs125 = NULL;
  const mxArray *c2_rhs126 = NULL;
  const mxArray *c2_lhs126 = NULL;
  const mxArray *c2_rhs127 = NULL;
  const mxArray *c2_lhs127 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 64);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1346503140U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c2_rhs64, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs64, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 65);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 65);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 65);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c2_rhs65, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs65, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 66);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 66);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 66);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c2_rhs66, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs66, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xgemv"), "name", "name",
                  67);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703070U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c2_rhs67, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs67, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 68);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1299069568U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c2_rhs68, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs68, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m!below_threshold"),
                  "context", "context", 69);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("length"), "name", "name", 69);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1303139006U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c2_rhs69, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs69, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m!below_threshold"),
                  "context", "context", 70);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 70);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362251082U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c2_rhs70, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs70, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m!below_threshold"),
                  "context", "context", 71);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 71);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c2_rhs71, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs71, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m"),
                  "context", "context", 72);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 72);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c2_rhs72, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs72, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m"),
                  "context", "context", 73);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 73);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c2_rhs73, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs73, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m"),
                  "context", "context", 74);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_refblas_xgemv"), "name",
                  "name", 74);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1360271552U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c2_rhs74, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs74, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m"),
                  "context", "context", 75);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 75);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c2_rhs75, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs75, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m"),
                  "context", "context", 76);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 76);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c2_rhs76, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs76, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m"),
                  "context", "context", 77);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 77);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 77);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811580U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c2_rhs77, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs77, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 78);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 78);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c2_rhs78, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs78, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m"),
                  "context", "context", 79);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 79);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 79);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c2_rhs79, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs79, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m"),
                  "context", "context", 80);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 80);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1346503140U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c2_rhs80, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs80, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m"),
                  "context", "context", 81);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 81);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c2_rhs81, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs81, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 82);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 82);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 82);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703066U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c2_rhs82, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs82, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zpotrf.m"),
                  "context", "context", 83);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xscal"), "name", "name",
                  83);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703072U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c2_rhs83, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs83, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"), "context",
                  "context", 84);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 84);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1299069568U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c2_rhs84, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs84, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m!below_threshold"),
                  "context", "context", 85);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("length"), "name", "name", 85);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1303139006U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c2_rhs85, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs85, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m"),
                  "context", "context", 86);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 86);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c2_rhs86, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs86, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 87);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c2_rhs87, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs87, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m"),
                  "context", "context", 88);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_refblas_xscal"), "name",
                  "name", 88);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m"),
                  "resolved", "resolved", 88);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1299069584U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c2_rhs88, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs88, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m"),
                  "context", "context", 89);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 89);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c2_rhs89, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs89, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m"),
                  "context", "context", 90);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 90);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c2_rhs90, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs90, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m"),
                  "context", "context", 91);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 91);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 91);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811580U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c2_rhs91, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs91, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m"),
                  "context", "context", 92);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 92);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 92);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c2_rhs92, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs92, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m"),
                  "context", "context", 93);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 93);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1346503140U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c2_rhs93, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs93, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/chol.m!cholesky"),
                  "context", "context", 94);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 94);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c2_rhs94, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs94, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/chol.m!cholesky"),
                  "context", "context", 95);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 95);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c2_rhs95, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs95, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 96);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 96);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811526U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c2_rhs96, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs96, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power"),
                  "context", "context", 97);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 97);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 97);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c2_rhs97, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs97, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power"),
                  "context", "context", 98);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("inv"), "name", "name", 98);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m"), "resolved",
                  "resolved", 98);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1305310800U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c2_rhs98, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs98, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 99);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 99);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c2_rhs99, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs99, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 100);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("abs"), "name", "name", 100);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 100);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703052U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c2_rhs100, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs100, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs100), "rhs", "rhs",
                  100);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs100), "lhs", "lhs",
                  100);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 101);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 101);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c2_rhs101, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs101, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs101), "rhs", "rhs",
                  101);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs101), "lhs", "lhs",
                  101);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 102);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811512U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c2_rhs102, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs102, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs102), "rhs", "rhs",
                  102);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs102), "lhs", "lhs",
                  102);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 103);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 103);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 103);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703066U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c2_rhs103, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs103, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs103), "rhs", "rhs",
                  103);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs103), "lhs", "lhs",
                  103);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 104);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 104);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 104);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c2_rhs104, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs104, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs104), "rhs", "rhs",
                  104);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs104), "lhs", "lhs",
                  104);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3"), "context",
                  "context", 105);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 105);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811578U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c2_rhs105, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs105, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs105), "rhs", "rhs",
                  105);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs105), "lhs", "lhs",
                  105);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 106);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("norm"), "name", "name", 106);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 106);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703068U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c2_rhs106, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs106, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs106), "rhs", "rhs",
                  106);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs106), "lhs", "lhs",
                  106);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 107);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c2_rhs107, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs107, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs107), "rhs", "rhs",
                  107);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs107), "lhs", "lhs",
                  107);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 108);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("abs"), "name", "name", 108);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 108);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703052U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c2_rhs108, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs108, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs108), "rhs", "rhs",
                  108);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs108), "lhs", "lhs",
                  108);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 109);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isnan"), "name", "name", 109);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 109);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703058U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c2_rhs109, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs109, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs109), "rhs", "rhs",
                  109);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs109), "lhs", "lhs",
                  109);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 110);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 110);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703756U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c2_rhs110, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs110, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs110), "rhs", "rhs",
                  110);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs110), "lhs", "lhs",
                  110);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 111);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 111);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811576U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c2_rhs111, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs111, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs111), "rhs", "rhs",
                  111);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs111), "lhs", "lhs",
                  111);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 112);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 112);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811582U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c2_rhs112, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs112, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs112), "rhs", "rhs",
                  112);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs112), "lhs", "lhs",
                  112);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 113);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 113);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 113);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c2_rhs113, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs113, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs113), "rhs", "rhs",
                  113);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs113), "lhs", "lhs",
                  113);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 114);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_warning"), "name", "name",
                  114);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 114);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811602U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c2_rhs114, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs114, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs114), "rhs", "rhs",
                  114);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs114), "lhs", "lhs",
                  114);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 115);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isnan"), "name", "name", 115);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 115);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703058U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c2_rhs115, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs115, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs115), "rhs", "rhs",
                  115);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs115), "lhs", "lhs",
                  115);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 116);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eps"), "name", "name", 116);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 116);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326717196U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c2_rhs116, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs116, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs116), "rhs", "rhs",
                  116);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs116), "lhs", "lhs",
                  116);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 117);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 117);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811582U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c2_rhs117, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs117, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs117), "rhs", "rhs",
                  117);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs117), "lhs", "lhs",
                  117);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 118);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_eps"), "name", "name", 118);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 118);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326717196U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c2_rhs118, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs118, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs118), "rhs", "rhs",
                  118);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs118), "lhs", "lhs",
                  118);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 119);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 119);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 119);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326717196U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c2_rhs119, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs119, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs119), "rhs", "rhs",
                  119);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs119), "lhs", "lhs",
                  119);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 120);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_flt2str"), "name", "name",
                  120);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "resolved",
                  "resolved", 120);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1360271550U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c2_rhs120, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs120, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs120), "rhs", "rhs",
                  120);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs120), "lhs", "lhs",
                  120);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "context",
                  "context", 121);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "name", "name", 121);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 121);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1319722768U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c2_rhs121, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs121, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs121), "rhs", "rhs",
                  121);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs121), "lhs", "lhs",
                  121);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 122);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 122);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c2_rhs122, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs122, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs122), "rhs", "rhs",
                  122);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs122), "lhs", "lhs",
                  122);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 123);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 123);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 123);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c2_rhs123, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs123, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs123), "rhs", "rhs",
                  123);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs123), "lhs", "lhs",
                  123);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 124);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  124);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703070U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c2_rhs124, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs124, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs124), "rhs", "rhs",
                  124);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs124), "lhs", "lhs",
                  124);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 125);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 125);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1299069568U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c2_rhs125, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs125, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs125), "rhs", "rhs",
                  125);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs125), "lhs", "lhs",
                  125);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 126);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 126);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 126);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c2_rhs126, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs126, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs126), "rhs", "rhs",
                  126);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs126), "lhs", "lhs",
                  126);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 127);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 127);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c2_rhs127, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs127, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs127), "rhs", "rhs",
                  127);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs127), "lhs", "lhs",
                  127);
  sf_mex_destroy(&c2_rhs64);
  sf_mex_destroy(&c2_lhs64);
  sf_mex_destroy(&c2_rhs65);
  sf_mex_destroy(&c2_lhs65);
  sf_mex_destroy(&c2_rhs66);
  sf_mex_destroy(&c2_lhs66);
  sf_mex_destroy(&c2_rhs67);
  sf_mex_destroy(&c2_lhs67);
  sf_mex_destroy(&c2_rhs68);
  sf_mex_destroy(&c2_lhs68);
  sf_mex_destroy(&c2_rhs69);
  sf_mex_destroy(&c2_lhs69);
  sf_mex_destroy(&c2_rhs70);
  sf_mex_destroy(&c2_lhs70);
  sf_mex_destroy(&c2_rhs71);
  sf_mex_destroy(&c2_lhs71);
  sf_mex_destroy(&c2_rhs72);
  sf_mex_destroy(&c2_lhs72);
  sf_mex_destroy(&c2_rhs73);
  sf_mex_destroy(&c2_lhs73);
  sf_mex_destroy(&c2_rhs74);
  sf_mex_destroy(&c2_lhs74);
  sf_mex_destroy(&c2_rhs75);
  sf_mex_destroy(&c2_lhs75);
  sf_mex_destroy(&c2_rhs76);
  sf_mex_destroy(&c2_lhs76);
  sf_mex_destroy(&c2_rhs77);
  sf_mex_destroy(&c2_lhs77);
  sf_mex_destroy(&c2_rhs78);
  sf_mex_destroy(&c2_lhs78);
  sf_mex_destroy(&c2_rhs79);
  sf_mex_destroy(&c2_lhs79);
  sf_mex_destroy(&c2_rhs80);
  sf_mex_destroy(&c2_lhs80);
  sf_mex_destroy(&c2_rhs81);
  sf_mex_destroy(&c2_lhs81);
  sf_mex_destroy(&c2_rhs82);
  sf_mex_destroy(&c2_lhs82);
  sf_mex_destroy(&c2_rhs83);
  sf_mex_destroy(&c2_lhs83);
  sf_mex_destroy(&c2_rhs84);
  sf_mex_destroy(&c2_lhs84);
  sf_mex_destroy(&c2_rhs85);
  sf_mex_destroy(&c2_lhs85);
  sf_mex_destroy(&c2_rhs86);
  sf_mex_destroy(&c2_lhs86);
  sf_mex_destroy(&c2_rhs87);
  sf_mex_destroy(&c2_lhs87);
  sf_mex_destroy(&c2_rhs88);
  sf_mex_destroy(&c2_lhs88);
  sf_mex_destroy(&c2_rhs89);
  sf_mex_destroy(&c2_lhs89);
  sf_mex_destroy(&c2_rhs90);
  sf_mex_destroy(&c2_lhs90);
  sf_mex_destroy(&c2_rhs91);
  sf_mex_destroy(&c2_lhs91);
  sf_mex_destroy(&c2_rhs92);
  sf_mex_destroy(&c2_lhs92);
  sf_mex_destroy(&c2_rhs93);
  sf_mex_destroy(&c2_lhs93);
  sf_mex_destroy(&c2_rhs94);
  sf_mex_destroy(&c2_lhs94);
  sf_mex_destroy(&c2_rhs95);
  sf_mex_destroy(&c2_lhs95);
  sf_mex_destroy(&c2_rhs96);
  sf_mex_destroy(&c2_lhs96);
  sf_mex_destroy(&c2_rhs97);
  sf_mex_destroy(&c2_lhs97);
  sf_mex_destroy(&c2_rhs98);
  sf_mex_destroy(&c2_lhs98);
  sf_mex_destroy(&c2_rhs99);
  sf_mex_destroy(&c2_lhs99);
  sf_mex_destroy(&c2_rhs100);
  sf_mex_destroy(&c2_lhs100);
  sf_mex_destroy(&c2_rhs101);
  sf_mex_destroy(&c2_lhs101);
  sf_mex_destroy(&c2_rhs102);
  sf_mex_destroy(&c2_lhs102);
  sf_mex_destroy(&c2_rhs103);
  sf_mex_destroy(&c2_lhs103);
  sf_mex_destroy(&c2_rhs104);
  sf_mex_destroy(&c2_lhs104);
  sf_mex_destroy(&c2_rhs105);
  sf_mex_destroy(&c2_lhs105);
  sf_mex_destroy(&c2_rhs106);
  sf_mex_destroy(&c2_lhs106);
  sf_mex_destroy(&c2_rhs107);
  sf_mex_destroy(&c2_lhs107);
  sf_mex_destroy(&c2_rhs108);
  sf_mex_destroy(&c2_lhs108);
  sf_mex_destroy(&c2_rhs109);
  sf_mex_destroy(&c2_lhs109);
  sf_mex_destroy(&c2_rhs110);
  sf_mex_destroy(&c2_lhs110);
  sf_mex_destroy(&c2_rhs111);
  sf_mex_destroy(&c2_lhs111);
  sf_mex_destroy(&c2_rhs112);
  sf_mex_destroy(&c2_lhs112);
  sf_mex_destroy(&c2_rhs113);
  sf_mex_destroy(&c2_lhs113);
  sf_mex_destroy(&c2_rhs114);
  sf_mex_destroy(&c2_lhs114);
  sf_mex_destroy(&c2_rhs115);
  sf_mex_destroy(&c2_lhs115);
  sf_mex_destroy(&c2_rhs116);
  sf_mex_destroy(&c2_lhs116);
  sf_mex_destroy(&c2_rhs117);
  sf_mex_destroy(&c2_lhs117);
  sf_mex_destroy(&c2_rhs118);
  sf_mex_destroy(&c2_lhs118);
  sf_mex_destroy(&c2_rhs119);
  sf_mex_destroy(&c2_lhs119);
  sf_mex_destroy(&c2_rhs120);
  sf_mex_destroy(&c2_lhs120);
  sf_mex_destroy(&c2_rhs121);
  sf_mex_destroy(&c2_lhs121);
  sf_mex_destroy(&c2_rhs122);
  sf_mex_destroy(&c2_lhs122);
  sf_mex_destroy(&c2_rhs123);
  sf_mex_destroy(&c2_lhs123);
  sf_mex_destroy(&c2_rhs124);
  sf_mex_destroy(&c2_lhs124);
  sf_mex_destroy(&c2_rhs125);
  sf_mex_destroy(&c2_lhs125);
  sf_mex_destroy(&c2_rhs126);
  sf_mex_destroy(&c2_lhs126);
  sf_mex_destroy(&c2_rhs127);
  sf_mex_destroy(&c2_lhs127);
}

static void c2_c_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs128 = NULL;
  const mxArray *c2_lhs128 = NULL;
  const mxArray *c2_rhs129 = NULL;
  const mxArray *c2_lhs129 = NULL;
  const mxArray *c2_rhs130 = NULL;
  const mxArray *c2_lhs130 = NULL;
  const mxArray *c2_rhs131 = NULL;
  const mxArray *c2_lhs131 = NULL;
  const mxArray *c2_rhs132 = NULL;
  const mxArray *c2_lhs132 = NULL;
  const mxArray *c2_rhs133 = NULL;
  const mxArray *c2_lhs133 = NULL;
  const mxArray *c2_rhs134 = NULL;
  const mxArray *c2_lhs134 = NULL;
  const mxArray *c2_rhs135 = NULL;
  const mxArray *c2_lhs135 = NULL;
  const mxArray *c2_rhs136 = NULL;
  const mxArray *c2_lhs136 = NULL;
  const mxArray *c2_rhs137 = NULL;
  const mxArray *c2_lhs137 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 128);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 128);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 128);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c2_rhs128, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs128, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs128), "rhs", "rhs",
                  128);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs128), "lhs", "lhs",
                  128);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 129);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 129);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1360271550U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c2_rhs129, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs129, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs129), "rhs", "rhs",
                  129);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs129), "lhs", "lhs",
                  129);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 130);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("cross"), "name", "name", 130);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "resolved",
                  "resolved", 130);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811642U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c2_rhs130, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs130, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs130), "rhs", "rhs",
                  130);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs130), "lhs", "lhs",
                  130);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "context",
                  "context", 131);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mtimes"), "name", "name", 131);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 131);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 131);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703078U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c2_rhs131, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs131, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs131), "rhs", "rhs",
                  131);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs131), "lhs", "lhs",
                  131);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 132);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("diag"), "name", "name", 132);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 132);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "resolved",
                  "resolved", 132);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363703054U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c2_rhs132, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs132, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs132), "rhs", "rhs",
                  132);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs132), "lhs", "lhs",
                  132);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 133);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name",
                  133);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 133);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 133);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331294058U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c2_rhs133, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs133, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs133), "rhs", "rhs",
                  133);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs133), "lhs", "lhs",
                  133);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 134);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 134);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323159778U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c2_rhs134, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs134, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs134), "rhs", "rhs",
                  134);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs134), "lhs", "lhs",
                  134);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 135);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 135);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 135);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286811596U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c2_rhs135, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs135, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs135), "rhs", "rhs",
                  135);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs135), "lhs", "lhs",
                  135);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 136);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 136);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1346503140U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c2_rhs136, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs136, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs136), "rhs", "rhs",
                  136);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs136), "lhs", "lhs",
                  136);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 137);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("inv"), "name", "name", 137);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m"), "resolved",
                  "resolved", 137);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1305310800U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c2_rhs137, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c2_lhs137, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs137), "rhs", "rhs",
                  137);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs137), "lhs", "lhs",
                  137);
  sf_mex_destroy(&c2_rhs128);
  sf_mex_destroy(&c2_lhs128);
  sf_mex_destroy(&c2_rhs129);
  sf_mex_destroy(&c2_lhs129);
  sf_mex_destroy(&c2_rhs130);
  sf_mex_destroy(&c2_lhs130);
  sf_mex_destroy(&c2_rhs131);
  sf_mex_destroy(&c2_lhs131);
  sf_mex_destroy(&c2_rhs132);
  sf_mex_destroy(&c2_lhs132);
  sf_mex_destroy(&c2_rhs133);
  sf_mex_destroy(&c2_lhs133);
  sf_mex_destroy(&c2_rhs134);
  sf_mex_destroy(&c2_lhs134);
  sf_mex_destroy(&c2_rhs135);
  sf_mex_destroy(&c2_lhs135);
  sf_mex_destroy(&c2_rhs136);
  sf_mex_destroy(&c2_lhs136);
  sf_mex_destroy(&c2_rhs137);
  sf_mex_destroy(&c2_lhs137);
}

static real_T c2_mpower(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  real_T c2_e_a;
  real_T c2_b;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  c2_e_a = c2_d_a;
  c2_b = c2_d_a;
  return c2_e_a * c2_b;
}

static void c2_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static real_T c2_eml_div(SFc2_ACStesbedInstanceStruct *chartInstance, real_T
  c2_x, real_T c2_y)
{
  return c2_x / c2_y;
}

static void c2_eml_error(SFc2_ACStesbedInstanceStruct *chartInstance)
{
  int32_T c2_i97;
  static char_T c2_cv0[48] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'c', 'h', 'o', 'l', '_', 'm', 'a', 't', 'r', 'i', 'x', 'M',
    'u', 's', 't', 'B', 'e', 'P', 'o', 's', 'D', 'e', 'f', 'W', 'i', 't', 'h',
    'R', 'e', 'a', 'l', 'D', 'i', 'a', 'g' };

  char_T c2_u[48];
  const mxArray *c2_y = NULL;
  for (c2_i97 = 0; c2_i97 < 48; c2_i97++) {
    c2_u[c2_i97] = c2_cv0[c2_i97];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 48), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static void c2_b_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_ukf(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[4],
                   real_T c2_P[16], real_T c2_z[3], real_T c2_dh[3], real_T
                   c2_h[3], real_T c2_gb[3], real_T c2_J[9], real_T c2_Mass,
                   real_T c2_b_x[4], real_T c2_b_P[16])
{
  uint32_T c2_debug_family_var_map[32];
  real_T c2_L;
  real_T c2_m;
  real_T c2_alpha;
  real_T c2_ki;
  real_T c2_beta;
  real_T c2_lambda;
  real_T c2_c;
  real_T c2_Wm[9];
  real_T c2_Wc[9];
  real_T c2_X[36];
  real_T c2_x1[4];
  real_T c2_X1[36];
  real_T c2_P1[16];
  real_T c2_X2[36];
  real_T c2_z1[3];
  real_T c2_Z1[27];
  real_T c2_P2[9];
  real_T c2_Z2[27];
  real_T c2_P12[12];
  real_T c2_K[12];
  real_T c2_Q[16];
  real_T c2_R[9];
  real_T c2_nargin = 12.0;
  real_T c2_nargout = 2.0;
  int32_T c2_i98;
  static real_T c2_dv12[9] = { 2.5000000000000004E-11, 0.0, 0.0, 0.0,
    2.5000000000000004E-11, 0.0, 0.0, 0.0, 2.5000000000000004E-11 };

  int32_T c2_i99;
  static real_T c2_dv13[16] = { 1.0E-12, 0.0, 0.0, 0.0, 0.0, 1.0E-12, 0.0, 0.0,
    0.0, 0.0, 1.0E-12, 0.0, 0.0, 0.0, 0.0, 1.0E-12 };

  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  static real_T c2_dv14[9] = { -999998.99997124437, 124999.99999640555,
    124999.99999640555, 124999.99999640555, 124999.99999640555,
    124999.99999640555, 124999.99999640555, 124999.99999640555,
    124999.99999640555 };

  int32_T c2_i103;
  int32_T c2_i104;
  real_T c2_c_x[4];
  int32_T c2_i105;
  real_T c2_c_P[16];
  real_T c2_dv15[36];
  int32_T c2_i106;
  int32_T c2_i107;
  real_T c2_b_X[36];
  int32_T c2_i108;
  real_T c2_dv16[9];
  int32_T c2_i109;
  real_T c2_b_Wc[9];
  int32_T c2_i110;
  real_T c2_dv17[16];
  int32_T c2_i111;
  real_T c2_b_dh[3];
  int32_T c2_i112;
  real_T c2_b_h[3];
  int32_T c2_i113;
  real_T c2_b_gb[3];
  int32_T c2_i114;
  real_T c2_b_J[9];
  real_T c2_b_X2[36];
  real_T c2_b_P1[16];
  real_T c2_b_X1[36];
  real_T c2_b_x1[4];
  int32_T c2_i115;
  int32_T c2_i116;
  int32_T c2_i117;
  int32_T c2_i118;
  int32_T c2_i119;
  real_T c2_c_X1[36];
  int32_T c2_i120;
  real_T c2_dv18[9];
  int32_T c2_i121;
  real_T c2_c_Wc[9];
  int32_T c2_i122;
  real_T c2_dv19[9];
  real_T c2_b_Z2[27];
  real_T c2_b_P2[9];
  real_T c2_b_Z1[27];
  real_T c2_b_z1[3];
  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_i125;
  int32_T c2_i126;
  int32_T c2_i127;
  int32_T c2_i128;
  real_T c2_d_Wc[9];
  real_T c2_b[81];
  int32_T c2_i129;
  int32_T c2_i130;
  int32_T c2_i131;
  int32_T c2_i132;
  int32_T c2_i133;
  int32_T c2_i134;
  int32_T c2_i135;
  int32_T c2_i136;
  int32_T c2_i137;
  int32_T c2_i138;
  real_T c2_b_b[27];
  int32_T c2_i139;
  int32_T c2_i140;
  int32_T c2_i141;
  real_T c2_C[12];
  int32_T c2_i142;
  int32_T c2_i143;
  int32_T c2_i144;
  int32_T c2_i145;
  int32_T c2_i146;
  int32_T c2_i147;
  int32_T c2_i148;
  int32_T c2_i149;
  int32_T c2_i150;
  int32_T c2_i151;
  real_T c2_a[12];
  int32_T c2_i152;
  real_T c2_c_P2[9];
  int32_T c2_i153;
  int32_T c2_i154;
  int32_T c2_i155;
  int32_T c2_i156;
  int32_T c2_i157;
  int32_T c2_i158;
  int32_T c2_i159;
  int32_T c2_i160;
  int32_T c2_i161;
  int32_T c2_i162;
  int32_T c2_i163;
  int32_T c2_i164;
  int32_T c2_i165;
  int32_T c2_i166;
  int32_T c2_i167;
  int32_T c2_i168;
  int32_T c2_i169;
  int32_T c2_i170;
  int32_T c2_i171;
  int32_T c2_i172;
  int32_T c2_i173;
  int32_T c2_i174;
  int32_T c2_i175;
  real_T c2_c_b[12];
  int32_T c2_i176;
  int32_T c2_i177;
  int32_T c2_i178;
  int32_T c2_i179;
  int32_T c2_i180;
  int32_T c2_i181;
  int32_T c2_i182;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 32U, 34U, c2_g_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_L, 0U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_m, 1U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_alpha, 2U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ki, 3U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_beta, 4U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_lambda, 5U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_c, 6U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Wm, 7U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Wc, 8U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_X, 9U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x1, 10U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_X1, 11U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P1, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_X2, 13U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_z1, 14U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Z1, 15U, c2_h_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P2, 16U, c2_d_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Z2, 17U, c2_h_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P12, 18U, c2_i_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_K, 19U, c2_i_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Q, 20U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_R, 21U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 22U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 23U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x, 24U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P, 25U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_z, 26U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_dh, 27U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_h, 28U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_gb, 29U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_J, 30U, c2_d_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Mass, 31U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_x, MAX_uint32_T, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_P, MAX_uint32_T, c2_sf_marshallOut,
    c2_sf_marshallIn);
  for (c2_i98 = 0; c2_i98 < 9; c2_i98++) {
    c2_R[c2_i98] = c2_dv12[c2_i98];
  }

  for (c2_i99 = 0; c2_i99 < 16; c2_i99++) {
    c2_Q[c2_i99] = c2_dv13[c2_i99];
  }

  for (c2_i100 = 0; c2_i100 < 16; c2_i100++) {
    c2_b_P[c2_i100] = c2_P[c2_i100];
  }

  _SFD_SYMBOL_SWITCH(25U, 33U);
  for (c2_i101 = 0; c2_i101 < 4; c2_i101++) {
    c2_b_x[c2_i101] = c2_x[c2_i101];
  }

  _SFD_SYMBOL_SWITCH(24U, 32U);
  CV_EML_FCN(0, 3);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 76);
  c2_L = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 77);
  c2_m = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
  c2_alpha = 0.001;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
  c2_ki = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 80);
  c2_beta = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 81);
  c2_lambda = -3.999996;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 82);
  c2_c = 4.0000000001150227E-6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 83);
  for (c2_i102 = 0; c2_i102 < 9; c2_i102++) {
    c2_Wm[c2_i102] = c2_dv14[c2_i102];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 84);
  for (c2_i103 = 0; c2_i103 < 9; c2_i103++) {
    c2_Wc[c2_i103] = c2_Wm[c2_i103];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 85);
  c2_Wc[0] += (1.0 - c2_mpower(chartInstance, 0.001)) + c2_beta;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 86);
  c2_c = 0.0020000000000287557;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
  for (c2_i104 = 0; c2_i104 < 4; c2_i104++) {
    c2_c_x[c2_i104] = c2_b_x[c2_i104];
  }

  for (c2_i105 = 0; c2_i105 < 16; c2_i105++) {
    c2_c_P[c2_i105] = c2_b_P[c2_i105];
  }

  c2_sigmas(chartInstance, c2_c_x, c2_c_P, c2_dv15);
  for (c2_i106 = 0; c2_i106 < 36; c2_i106++) {
    c2_X[c2_i106] = c2_dv15[c2_i106];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
  for (c2_i107 = 0; c2_i107 < 36; c2_i107++) {
    c2_b_X[c2_i107] = c2_X[c2_i107];
  }

  for (c2_i108 = 0; c2_i108 < 9; c2_i108++) {
    c2_dv16[c2_i108] = c2_dv14[c2_i108];
  }

  for (c2_i109 = 0; c2_i109 < 9; c2_i109++) {
    c2_b_Wc[c2_i109] = c2_Wc[c2_i109];
  }

  for (c2_i110 = 0; c2_i110 < 16; c2_i110++) {
    c2_dv17[c2_i110] = c2_dv13[c2_i110];
  }

  for (c2_i111 = 0; c2_i111 < 3; c2_i111++) {
    c2_b_dh[c2_i111] = c2_dh[c2_i111];
  }

  for (c2_i112 = 0; c2_i112 < 3; c2_i112++) {
    c2_b_h[c2_i112] = c2_h[c2_i112];
  }

  for (c2_i113 = 0; c2_i113 < 3; c2_i113++) {
    c2_b_gb[c2_i113] = c2_gb[c2_i113];
  }

  for (c2_i114 = 0; c2_i114 < 9; c2_i114++) {
    c2_b_J[c2_i114] = c2_J[c2_i114];
  }

  c2_ut(chartInstance, c2_b_X, c2_dv16, c2_b_Wc, c2_dv17, c2_b_dh, c2_b_h,
        c2_b_gb, c2_b_J, c2_Mass, c2_b_x1, c2_b_X1, c2_b_P1, c2_b_X2);
  for (c2_i115 = 0; c2_i115 < 4; c2_i115++) {
    c2_x1[c2_i115] = c2_b_x1[c2_i115];
  }

  for (c2_i116 = 0; c2_i116 < 36; c2_i116++) {
    c2_X1[c2_i116] = c2_b_X1[c2_i116];
  }

  for (c2_i117 = 0; c2_i117 < 16; c2_i117++) {
    c2_P1[c2_i117] = c2_b_P1[c2_i117];
  }

  for (c2_i118 = 0; c2_i118 < 36; c2_i118++) {
    c2_X2[c2_i118] = c2_b_X2[c2_i118];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 91);
  for (c2_i119 = 0; c2_i119 < 36; c2_i119++) {
    c2_c_X1[c2_i119] = c2_X1[c2_i119];
  }

  for (c2_i120 = 0; c2_i120 < 9; c2_i120++) {
    c2_dv18[c2_i120] = c2_dv14[c2_i120];
  }

  for (c2_i121 = 0; c2_i121 < 9; c2_i121++) {
    c2_c_Wc[c2_i121] = c2_Wc[c2_i121];
  }

  for (c2_i122 = 0; c2_i122 < 9; c2_i122++) {
    c2_dv19[c2_i122] = c2_dv12[c2_i122];
  }

  c2_b_ut(chartInstance, c2_c_X1, c2_dv18, c2_c_Wc, c2_dv19, c2_b_z1, c2_b_Z1,
          c2_b_P2, c2_b_Z2);
  for (c2_i123 = 0; c2_i123 < 3; c2_i123++) {
    c2_z1[c2_i123] = c2_b_z1[c2_i123];
  }

  for (c2_i124 = 0; c2_i124 < 27; c2_i124++) {
    c2_Z1[c2_i124] = c2_b_Z1[c2_i124];
  }

  for (c2_i125 = 0; c2_i125 < 9; c2_i125++) {
    c2_P2[c2_i125] = c2_b_P2[c2_i125];
  }

  for (c2_i126 = 0; c2_i126 < 27; c2_i126++) {
    c2_Z2[c2_i126] = c2_b_Z2[c2_i126];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 92);
  for (c2_i127 = 0; c2_i127 < 36; c2_i127++) {
    c2_b_X1[c2_i127] = c2_X2[c2_i127];
  }

  for (c2_i128 = 0; c2_i128 < 9; c2_i128++) {
    c2_d_Wc[c2_i128] = c2_Wc[c2_i128];
  }

  c2_diag(chartInstance, c2_d_Wc, c2_b);
  c2_d_eml_scalar_eg(chartInstance);
  c2_d_eml_scalar_eg(chartInstance);
  for (c2_i129 = 0; c2_i129 < 4; c2_i129++) {
    c2_i130 = 0;
    c2_i131 = 0;
    for (c2_i132 = 0; c2_i132 < 9; c2_i132++) {
      c2_b_X2[c2_i130 + c2_i129] = 0.0;
      c2_i133 = 0;
      for (c2_i134 = 0; c2_i134 < 9; c2_i134++) {
        c2_b_X2[c2_i130 + c2_i129] += c2_b_X1[c2_i133 + c2_i129] * c2_b[c2_i134
          + c2_i131];
        c2_i133 += 4;
      }

      c2_i130 += 4;
      c2_i131 += 9;
    }
  }

  c2_i135 = 0;
  for (c2_i136 = 0; c2_i136 < 3; c2_i136++) {
    c2_i137 = 0;
    for (c2_i138 = 0; c2_i138 < 9; c2_i138++) {
      c2_b_b[c2_i138 + c2_i135] = c2_Z2[c2_i137 + c2_i136];
      c2_i137 += 3;
    }

    c2_i135 += 9;
  }

  c2_h_eml_scalar_eg(chartInstance);
  c2_h_eml_scalar_eg(chartInstance);
  for (c2_i139 = 0; c2_i139 < 12; c2_i139++) {
    c2_P12[c2_i139] = 0.0;
  }

  for (c2_i140 = 0; c2_i140 < 12; c2_i140++) {
    c2_P12[c2_i140] = 0.0;
  }

  for (c2_i141 = 0; c2_i141 < 12; c2_i141++) {
    c2_C[c2_i141] = c2_P12[c2_i141];
  }

  for (c2_i142 = 0; c2_i142 < 12; c2_i142++) {
    c2_P12[c2_i142] = c2_C[c2_i142];
  }

  for (c2_i143 = 0; c2_i143 < 12; c2_i143++) {
    c2_C[c2_i143] = c2_P12[c2_i143];
  }

  for (c2_i144 = 0; c2_i144 < 12; c2_i144++) {
    c2_P12[c2_i144] = c2_C[c2_i144];
  }

  for (c2_i145 = 0; c2_i145 < 4; c2_i145++) {
    c2_i146 = 0;
    c2_i147 = 0;
    for (c2_i148 = 0; c2_i148 < 3; c2_i148++) {
      c2_P12[c2_i146 + c2_i145] = 0.0;
      c2_i149 = 0;
      for (c2_i150 = 0; c2_i150 < 9; c2_i150++) {
        c2_P12[c2_i146 + c2_i145] += c2_b_X2[c2_i149 + c2_i145] * c2_b_b[c2_i150
          + c2_i147];
        c2_i149 += 4;
      }

      c2_i146 += 4;
      c2_i147 += 9;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 93);
  for (c2_i151 = 0; c2_i151 < 12; c2_i151++) {
    c2_a[c2_i151] = c2_P12[c2_i151];
  }

  for (c2_i152 = 0; c2_i152 < 9; c2_i152++) {
    c2_c_P2[c2_i152] = c2_P2[c2_i152];
  }

  c2_inv(chartInstance, c2_c_P2, c2_b_P2);
  c2_i_eml_scalar_eg(chartInstance);
  c2_i_eml_scalar_eg(chartInstance);
  for (c2_i153 = 0; c2_i153 < 12; c2_i153++) {
    c2_K[c2_i153] = 0.0;
  }

  for (c2_i154 = 0; c2_i154 < 12; c2_i154++) {
    c2_K[c2_i154] = 0.0;
  }

  for (c2_i155 = 0; c2_i155 < 12; c2_i155++) {
    c2_C[c2_i155] = c2_K[c2_i155];
  }

  for (c2_i156 = 0; c2_i156 < 12; c2_i156++) {
    c2_K[c2_i156] = c2_C[c2_i156];
  }

  for (c2_i157 = 0; c2_i157 < 12; c2_i157++) {
    c2_C[c2_i157] = c2_K[c2_i157];
  }

  for (c2_i158 = 0; c2_i158 < 12; c2_i158++) {
    c2_K[c2_i158] = c2_C[c2_i158];
  }

  for (c2_i159 = 0; c2_i159 < 4; c2_i159++) {
    c2_i160 = 0;
    c2_i161 = 0;
    for (c2_i162 = 0; c2_i162 < 3; c2_i162++) {
      c2_K[c2_i160 + c2_i159] = 0.0;
      c2_i163 = 0;
      for (c2_i164 = 0; c2_i164 < 3; c2_i164++) {
        c2_K[c2_i160 + c2_i159] += c2_a[c2_i163 + c2_i159] * c2_b_P2[c2_i164 +
          c2_i161];
        c2_i163 += 4;
      }

      c2_i160 += 4;
      c2_i161 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
  for (c2_i165 = 0; c2_i165 < 12; c2_i165++) {
    c2_a[c2_i165] = c2_K[c2_i165];
  }

  for (c2_i166 = 0; c2_i166 < 3; c2_i166++) {
    c2_b_z1[c2_i166] = c2_z[c2_i166] - c2_z1[c2_i166];
  }

  c2_j_eml_scalar_eg(chartInstance);
  c2_j_eml_scalar_eg(chartInstance);
  for (c2_i167 = 0; c2_i167 < 4; c2_i167++) {
    c2_b_x1[c2_i167] = 0.0;
    c2_i168 = 0;
    for (c2_i169 = 0; c2_i169 < 3; c2_i169++) {
      c2_b_x1[c2_i167] += c2_a[c2_i168 + c2_i167] * c2_b_z1[c2_i169];
      c2_i168 += 4;
    }
  }

  for (c2_i170 = 0; c2_i170 < 4; c2_i170++) {
    c2_b_x[c2_i170] = c2_x1[c2_i170] + c2_b_x1[c2_i170];
  }

  _SFD_SYMBOL_SWITCH(24U, 32U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 95);
  for (c2_i171 = 0; c2_i171 < 12; c2_i171++) {
    c2_a[c2_i171] = c2_K[c2_i171];
  }

  c2_i172 = 0;
  for (c2_i173 = 0; c2_i173 < 4; c2_i173++) {
    c2_i174 = 0;
    for (c2_i175 = 0; c2_i175 < 3; c2_i175++) {
      c2_c_b[c2_i175 + c2_i172] = c2_P12[c2_i174 + c2_i173];
      c2_i174 += 4;
    }

    c2_i172 += 3;
  }

  c2_k_eml_scalar_eg(chartInstance);
  c2_k_eml_scalar_eg(chartInstance);
  for (c2_i176 = 0; c2_i176 < 4; c2_i176++) {
    c2_i177 = 0;
    c2_i178 = 0;
    for (c2_i179 = 0; c2_i179 < 4; c2_i179++) {
      c2_b_P1[c2_i177 + c2_i176] = 0.0;
      c2_i180 = 0;
      for (c2_i181 = 0; c2_i181 < 3; c2_i181++) {
        c2_b_P1[c2_i177 + c2_i176] += c2_a[c2_i180 + c2_i176] * c2_c_b[c2_i181 +
          c2_i178];
        c2_i180 += 4;
      }

      c2_i177 += 4;
      c2_i178 += 3;
    }
  }

  for (c2_i182 = 0; c2_i182 < 16; c2_i182++) {
    c2_b_P[c2_i182] = c2_P1[c2_i182] - c2_b_P1[c2_i182];
  }

  _SFD_SYMBOL_SWITCH(25U, 33U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -95);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_sigmas(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[4],
                      real_T c2_P[16], real_T c2_X[36])
{
  uint32_T c2_debug_family_var_map[8];
  real_T c2_A[16];
  real_T c2_Y[16];
  real_T c2_c;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i183;
  real_T c2_b_A[16];
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_info;
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_jmax;
  int32_T c2_a;
  int32_T c2_b_jmax;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_c_j;
  int32_T c2_b_a;
  int32_T c2_i184;
  int32_T c2_c_jmax;
  int32_T c2_c_a;
  int32_T c2_c_b;
  int32_T c2_d_a;
  int32_T c2_d_b;
  boolean_T c2_b_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_i185;
  int32_T c2_i186;
  int32_T c2_i187;
  int32_T c2_i188;
  real_T c2_e_b[16];
  int32_T c2_i189;
  int32_T c2_i190;
  int32_T c2_i191;
  int32_T c2_i192;
  int32_T c2_i193;
  int32_T c2_i194;
  int32_T c2_i195;
  int32_T c2_i196;
  int32_T c2_i197;
  int32_T c2_i198;
  int32_T c2_i199;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_A, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Y, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_c, 2U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 3U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 4U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x, 5U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_X, 7U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  c2_c = 0.0020000000000287557;
  CV_EML_FCN(0, 5);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 133U);
  for (c2_i183 = 0; c2_i183 < 16; c2_i183++) {
    c2_b_A[c2_i183] = c2_P[c2_i183];
  }

  for (c2_j = 1; c2_j < 5; c2_j++) {
    c2_b_j = c2_j;
  }

  c2_info = c2_b_eml_matlab_zpotrf(chartInstance, c2_b_A);
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  if (c2_d_info == 0) {
    c2_jmax = 4;
  } else {
    c2_b_eml_error(chartInstance);
    c2_a = c2_d_info - 1;
    c2_jmax = c2_a;
  }

  c2_b_jmax = c2_jmax;
  c2_b = c2_b_jmax;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, c2_overflow);
  }

  for (c2_c_j = 1; c2_c_j <= c2_b_jmax; c2_c_j++) {
    c2_b_j = c2_c_j;
    c2_b_a = c2_b_j + 1;
    c2_i184 = c2_b_a;
    c2_c_jmax = c2_jmax;
    c2_c_a = c2_i184;
    c2_c_b = c2_c_jmax;
    c2_d_a = c2_c_a;
    c2_d_b = c2_c_b;
    if (c2_d_a > c2_d_b) {
      c2_b_overflow = FALSE;
    } else {
      c2_b_overflow = (c2_d_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
    }

    for (c2_i = c2_i184; c2_i <= c2_c_jmax; c2_i++) {
      c2_b_i = c2_i;
      c2_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 2, 0) -
                1) << 2)) - 1] = 0.0;
    }
  }

  c2_i185 = 0;
  for (c2_i186 = 0; c2_i186 < 4; c2_i186++) {
    c2_i187 = 0;
    for (c2_i188 = 0; c2_i188 < 4; c2_i188++) {
      c2_e_b[c2_i188 + c2_i185] = c2_b_A[c2_i187 + c2_i186];
      c2_i187 += 4;
    }

    c2_i185 += 4;
  }

  for (c2_i189 = 0; c2_i189 < 16; c2_i189++) {
    c2_A[c2_i189] = 0.0020000000000287557 * c2_e_b[c2_i189];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 134U);
  c2_i190 = 0;
  for (c2_i191 = 0; c2_i191 < 4; c2_i191++) {
    for (c2_i192 = 0; c2_i192 < 4; c2_i192++) {
      c2_Y[c2_i192 + c2_i190] = c2_x[c2_i192];
    }

    c2_i190 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 135U);
  for (c2_i193 = 0; c2_i193 < 4; c2_i193++) {
    c2_X[c2_i193] = c2_x[c2_i193];
  }

  c2_i194 = 0;
  for (c2_i195 = 0; c2_i195 < 4; c2_i195++) {
    for (c2_i196 = 0; c2_i196 < 4; c2_i196++) {
      c2_X[(c2_i196 + c2_i194) + 4] = c2_Y[c2_i196 + c2_i194] + c2_A[c2_i196 +
        c2_i194];
    }

    c2_i194 += 4;
  }

  c2_i197 = 0;
  for (c2_i198 = 0; c2_i198 < 4; c2_i198++) {
    for (c2_i199 = 0; c2_i199 < 4; c2_i199++) {
      c2_X[(c2_i199 + c2_i197) + 20] = c2_Y[c2_i199 + c2_i197] - c2_A[c2_i199 +
        c2_i197];
    }

    c2_i197 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -135);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_eml_matlab_zpotrf(SFc2_ACStesbedInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_b_A[16], int32_T *c2_info)
{
  int32_T c2_i200;
  for (c2_i200 = 0; c2_i200 < 16; c2_i200++) {
    c2_b_A[c2_i200] = c2_A[c2_i200];
  }

  *c2_info = c2_b_eml_matlab_zpotrf(chartInstance, c2_b_A);
}

static void c2_check_forloop_overflow_error(SFc2_ACStesbedInstanceStruct
  *chartInstance, boolean_T c2_overflow)
{
  int32_T c2_i201;
  static char_T c2_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i202;
  static char_T c2_cv2[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c2_b_u[23];
  const mxArray *c2_b_y = NULL;
  if (!c2_overflow) {
  } else {
    for (c2_i201 = 0; c2_i201 < 34; c2_i201++) {
      c2_u[c2_i201] = c2_cv1[c2_i201];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i202 = 0; c2_i202 < 23; c2_i202++) {
      c2_b_u[c2_i202] = c2_cv2[c2_i202];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_eml_xgemv(SFc2_ACStesbedInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, int32_T c2_ia0, int32_T c2_ix0, real_T c2_y[16], int32_T
  c2_iy0, real_T c2_b_y[16])
{
  int32_T c2_i203;
  for (c2_i203 = 0; c2_i203 < 16; c2_i203++) {
    c2_b_y[c2_i203] = c2_y[c2_i203];
  }

  c2_b_eml_xgemv(chartInstance, c2_m, c2_n, c2_ia0, c2_ix0, c2_b_y, c2_iy0);
}

static void c2_b_eml_error(SFc2_ACStesbedInstanceStruct *chartInstance)
{
  int32_T c2_i204;
  static char_T c2_cv3[19] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'p', 'o', 's', 'd', 'e', 'f' };

  char_T c2_u[19];
  const mxArray *c2_y = NULL;
  for (c2_i204 = 0; c2_i204 < 19; c2_i204++) {
    c2_u[c2_i204] = c2_cv3[c2_i204];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 19), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static void c2_ut(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_X[36],
                  real_T c2_Wm[9], real_T c2_Wc[9], real_T c2_R[16], real_T
                  c2_dh[3], real_T c2_h[3], real_T c2_gb[3], real_T c2_J[9],
                  real_T c2_Mass, real_T c2_y[4], real_T c2_Y[36], real_T c2_P
                  [16], real_T c2_Y1[36])
{
  uint32_T c2_debug_family_var_map[18];
  real_T c2_L;
  real_T c2_k;
  real_T c2_n;
  real_T c2_nargin = 11.0;
  real_T c2_nargout = 4.0;
  int32_T c2_i205;
  int32_T c2_i206;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_i207;
  real_T c2_b_X[4];
  int32_T c2_i208;
  real_T c2_b_dh[3];
  int32_T c2_i209;
  real_T c2_b_h[3];
  int32_T c2_i210;
  real_T c2_b_gb[3];
  int32_T c2_i211;
  real_T c2_b_J[9];
  real_T c2_dv20[4];
  int32_T c2_d_k;
  int32_T c2_i212;
  real_T c2_a;
  int32_T c2_e_k;
  int32_T c2_i213;
  real_T c2_b[4];
  int32_T c2_i214;
  int32_T c2_i215;
  int32_T c2_i216;
  int32_T c2_i217;
  int32_T c2_i218;
  int32_T c2_i219;
  real_T c2_b_a[36];
  int32_T c2_i220;
  real_T c2_b_Wc[9];
  real_T c2_b_b[81];
  int32_T c2_i221;
  int32_T c2_i222;
  int32_T c2_i223;
  int32_T c2_i224;
  real_T c2_b_y[36];
  int32_T c2_i225;
  int32_T c2_i226;
  int32_T c2_i227;
  int32_T c2_i228;
  int32_T c2_i229;
  int32_T c2_i230;
  real_T c2_c_b[36];
  int32_T c2_i231;
  int32_T c2_i232;
  int32_T c2_i233;
  int32_T c2_i234;
  real_T c2_c_y[16];
  int32_T c2_i235;
  int32_T c2_i236;
  int32_T c2_i237;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c2_d_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_L, 0U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k, 1U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_n, 2U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 3U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 4U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_X, 5U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Wm, 6U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Wc, 7U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_dh, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_h, 10U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_gb, 11U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_J, 12U, c2_d_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Mass, 13U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y, 14U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Y, 15U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Y1, 17U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  c2_n = 4.0;
  CV_EML_FCN(0, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 113);
  c2_L = 9.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 114);
  for (c2_i205 = 0; c2_i205 < 4; c2_i205++) {
    c2_y[c2_i205] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 115);
  for (c2_i206 = 0; c2_i206 < 36; c2_i206++) {
    c2_Y[c2_i206] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 116);
  c2_k = 1.0;
  c2_b_k = 0;
  while (c2_b_k < 9) {
    c2_k = 1.0 + (real_T)c2_b_k;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 117);
    c2_c_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_k), 1, 9, 2, 0) - 1;
    for (c2_i207 = 0; c2_i207 < 4; c2_i207++) {
      c2_b_X[c2_i207] = c2_X[c2_i207 + (c2_c_k << 2)];
    }

    for (c2_i208 = 0; c2_i208 < 3; c2_i208++) {
      c2_b_dh[c2_i208] = c2_dh[c2_i208];
    }

    for (c2_i209 = 0; c2_i209 < 3; c2_i209++) {
      c2_b_h[c2_i209] = c2_h[c2_i209];
    }

    for (c2_i210 = 0; c2_i210 < 3; c2_i210++) {
      c2_b_gb[c2_i210] = c2_gb[c2_i210];
    }

    for (c2_i211 = 0; c2_i211 < 9; c2_i211++) {
      c2_b_J[c2_i211] = c2_J[c2_i211];
    }

    c2_F(chartInstance, c2_b_X, c2_b_dh, c2_b_h, c2_b_gb, c2_b_J, c2_Mass,
         c2_dv20);
    c2_d_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Y", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_k), 1, 9, 2, 0) - 1;
    for (c2_i212 = 0; c2_i212 < 4; c2_i212++) {
      c2_Y[c2_i212 + (c2_d_k << 2)] = c2_dv20[c2_i212];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 118);
    c2_a = c2_Wm[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Wm", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_k), 1, 9, 1, 0) - 1];
    c2_e_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Y", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_k), 1, 9, 2, 0) - 1;
    for (c2_i213 = 0; c2_i213 < 4; c2_i213++) {
      c2_b[c2_i213] = c2_Y[c2_i213 + (c2_e_k << 2)];
    }

    for (c2_i214 = 0; c2_i214 < 4; c2_i214++) {
      c2_b[c2_i214] *= c2_a;
    }

    for (c2_i215 = 0; c2_i215 < 4; c2_i215++) {
      c2_y[c2_i215] += c2_b[c2_i215];
    }

    c2_b_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 120);
  c2_i216 = 0;
  for (c2_i217 = 0; c2_i217 < 9; c2_i217++) {
    for (c2_i218 = 0; c2_i218 < 4; c2_i218++) {
      c2_Y1[c2_i218 + c2_i216] = c2_Y[c2_i218 + c2_i216] - c2_y[c2_i218];
    }

    c2_i216 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 121);
  for (c2_i219 = 0; c2_i219 < 36; c2_i219++) {
    c2_b_a[c2_i219] = c2_Y1[c2_i219];
  }

  for (c2_i220 = 0; c2_i220 < 9; c2_i220++) {
    c2_b_Wc[c2_i220] = c2_Wc[c2_i220];
  }

  c2_diag(chartInstance, c2_b_Wc, c2_b_b);
  c2_d_eml_scalar_eg(chartInstance);
  c2_d_eml_scalar_eg(chartInstance);
  for (c2_i221 = 0; c2_i221 < 4; c2_i221++) {
    c2_i222 = 0;
    c2_i223 = 0;
    for (c2_i224 = 0; c2_i224 < 9; c2_i224++) {
      c2_b_y[c2_i222 + c2_i221] = 0.0;
      c2_i225 = 0;
      for (c2_i226 = 0; c2_i226 < 9; c2_i226++) {
        c2_b_y[c2_i222 + c2_i221] += c2_b_a[c2_i225 + c2_i221] * c2_b_b[c2_i226
          + c2_i223];
        c2_i225 += 4;
      }

      c2_i222 += 4;
      c2_i223 += 9;
    }
  }

  c2_i227 = 0;
  for (c2_i228 = 0; c2_i228 < 4; c2_i228++) {
    c2_i229 = 0;
    for (c2_i230 = 0; c2_i230 < 9; c2_i230++) {
      c2_c_b[c2_i230 + c2_i227] = c2_Y1[c2_i229 + c2_i228];
      c2_i229 += 4;
    }

    c2_i227 += 9;
  }

  c2_e_eml_scalar_eg(chartInstance);
  c2_e_eml_scalar_eg(chartInstance);
  for (c2_i231 = 0; c2_i231 < 4; c2_i231++) {
    c2_i232 = 0;
    c2_i233 = 0;
    for (c2_i234 = 0; c2_i234 < 4; c2_i234++) {
      c2_c_y[c2_i232 + c2_i231] = 0.0;
      c2_i235 = 0;
      for (c2_i236 = 0; c2_i236 < 9; c2_i236++) {
        c2_c_y[c2_i232 + c2_i231] += c2_b_y[c2_i235 + c2_i231] * c2_c_b[c2_i236
          + c2_i233];
        c2_i235 += 4;
      }

      c2_i232 += 4;
      c2_i233 += 9;
    }
  }

  for (c2_i237 = 0; c2_i237 < 16; c2_i237++) {
    c2_P[c2_i237] = c2_c_y[c2_i237] + c2_R[c2_i237];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -121);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_F(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[4],
                 real_T c2_dh[3], real_T c2_h[3], real_T c2_gb[3], real_T c2_J[9],
                 real_T c2_Mass, real_T c2_Y[4])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i238;
  real_T c2_a[9];
  int32_T c2_i239;
  real_T c2_b[3];
  int32_T c2_i240;
  real_T c2_y[3];
  int32_T c2_i241;
  int32_T c2_i242;
  int32_T c2_i243;
  int32_T c2_i244;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_c1;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_e_y;
  real_T c2_c2;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_f_y;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_c3;
  real_T c2_c[3];
  real_T c2_h_a;
  real_T c2_h_b;
  real_T c2_h_y;
  real_T c2_i_a;
  int32_T c2_i245;
  int32_T c2_i246;
  real_T c2_b_J[9];
  int32_T c2_i247;
  int32_T c2_i248;
  int32_T c2_i249;
  int32_T c2_i250;
  int32_T c2_i251;
  real_T c2_i_b[4];
  int32_T c2_i252;
  int32_T c2_i253;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_c_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_dh, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_h, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_gb, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_J, 6U, c2_d_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Mass, 7U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Y, 8U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  for (c2_i238 = 0; c2_i238 < 9; c2_i238++) {
    c2_a[c2_i238] = c2_J[c2_i238];
  }

  for (c2_i239 = 0; c2_i239 < 3; c2_i239++) {
    c2_b[c2_i239] = c2_x[c2_i239];
  }

  c2_c_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i240 = 0; c2_i240 < 3; c2_i240++) {
    c2_y[c2_i240] = 0.0;
    c2_i241 = 0;
    for (c2_i242 = 0; c2_i242 < 3; c2_i242++) {
      c2_y[c2_i240] += c2_a[c2_i241 + c2_i240] * c2_b[c2_i242];
      c2_i241 += 3;
    }
  }

  for (c2_i243 = 0; c2_i243 < 3; c2_i243++) {
    c2_b[c2_i243] = c2_x[c2_i243];
  }

  for (c2_i244 = 0; c2_i244 < 3; c2_i244++) {
    c2_y[c2_i244] += c2_h[c2_i244];
  }

  c2_b_a = c2_b[1];
  c2_b_b = c2_y[2];
  c2_b_y = c2_b_a * c2_b_b;
  c2_c_a = c2_b[2];
  c2_c_b = c2_y[1];
  c2_c_y = c2_c_a * c2_c_b;
  c2_c1 = c2_b_y - c2_c_y;
  c2_d_a = c2_b[2];
  c2_d_b = c2_y[0];
  c2_d_y = c2_d_a * c2_d_b;
  c2_e_a = c2_b[0];
  c2_e_b = c2_y[2];
  c2_e_y = c2_e_a * c2_e_b;
  c2_c2 = c2_d_y - c2_e_y;
  c2_f_a = c2_b[0];
  c2_f_b = c2_y[1];
  c2_f_y = c2_f_a * c2_f_b;
  c2_g_a = c2_b[1];
  c2_g_b = c2_y[0];
  c2_g_y = c2_g_a * c2_g_b;
  c2_c3 = c2_f_y - c2_g_y;
  c2_c[0] = c2_c1;
  c2_c[1] = c2_c2;
  c2_c[2] = c2_c3;
  c2_h_a = c2_Mass;
  c2_h_b = c2_x[3];
  c2_h_y = c2_h_a * c2_h_b;
  c2_i_a = c2_h_y;
  c2_b[0] = -c2_gb[1];
  c2_b[1] = c2_gb[0];
  c2_b[2] = 0.0;
  for (c2_i245 = 0; c2_i245 < 3; c2_i245++) {
    c2_b[c2_i245] *= c2_i_a;
  }

  for (c2_i246 = 0; c2_i246 < 9; c2_i246++) {
    c2_b_J[c2_i246] = c2_J[c2_i246];
  }

  c2_b_mpower(chartInstance, c2_b_J, c2_a);
  for (c2_i247 = 0; c2_i247 < 3; c2_i247++) {
    c2_c[c2_i247] = (-c2_c[c2_i247] - c2_dh[c2_i247]) + c2_b[c2_i247];
  }

  c2_c_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i248 = 0; c2_i248 < 3; c2_i248++) {
    c2_y[c2_i248] = 0.0;
    c2_i249 = 0;
    for (c2_i250 = 0; c2_i250 < 3; c2_i250++) {
      c2_y[c2_i248] += c2_a[c2_i249 + c2_i248] * c2_c[c2_i250];
      c2_i249 += 3;
    }
  }

  for (c2_i251 = 0; c2_i251 < 3; c2_i251++) {
    c2_i_b[c2_i251] = c2_y[c2_i251];
  }

  c2_i_b[3] = 0.0;
  for (c2_i252 = 0; c2_i252 < 4; c2_i252++) {
    c2_i_b[c2_i252] *= 0.1;
  }

  for (c2_i253 = 0; c2_i253 < 4; c2_i253++) {
    c2_Y[c2_i253] = c2_x[c2_i253] + c2_i_b[c2_i253];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_b_mpower(SFc2_ACStesbedInstanceStruct *chartInstance, real_T
  c2_a[9], real_T c2_c[9])
{
  int32_T c2_i254;
  real_T c2_b_a[9];
  for (c2_i254 = 0; c2_i254 < 9; c2_i254++) {
    c2_b_a[c2_i254] = c2_a[c2_i254];
  }

  c2_inv(chartInstance, c2_b_a, c2_c);
}

static void c2_inv(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[9],
                   real_T c2_y[9])
{
  int32_T c2_i255;
  real_T c2_b_x[9];
  int32_T c2_i256;
  real_T c2_c_x[9];
  real_T c2_n1x;
  int32_T c2_i257;
  real_T c2_b_y[9];
  real_T c2_n1xinv;
  real_T c2_a;
  real_T c2_b;
  real_T c2_c_y;
  real_T c2_rc;
  real_T c2_d_x;
  boolean_T c2_b_b;
  real_T c2_e_x;
  int32_T c2_i258;
  static char_T c2_cv4[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c2_u[8];
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_g_y = NULL;
  char_T c2_str[14];
  int32_T c2_i259;
  char_T c2_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  for (c2_i255 = 0; c2_i255 < 9; c2_i255++) {
    c2_b_x[c2_i255] = c2_x[c2_i255];
  }

  c2_inv3x3(chartInstance, c2_b_x, c2_y);
  for (c2_i256 = 0; c2_i256 < 9; c2_i256++) {
    c2_c_x[c2_i256] = c2_x[c2_i256];
  }

  c2_n1x = c2_norm(chartInstance, c2_c_x);
  for (c2_i257 = 0; c2_i257 < 9; c2_i257++) {
    c2_b_y[c2_i257] = c2_y[c2_i257];
  }

  c2_n1xinv = c2_norm(chartInstance, c2_b_y);
  c2_a = c2_n1x;
  c2_b = c2_n1xinv;
  c2_c_y = c2_a * c2_b;
  c2_rc = 1.0 / c2_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c2_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c2_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c2_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c2_d_x = c2_rc;
    c2_b_b = muDoubleScalarIsNaN(c2_d_x);
    guard3 = FALSE;
    if (c2_b_b) {
      guard3 = TRUE;
    } else {
      if (c2_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c2_e_x = c2_rc;
      for (c2_i258 = 0; c2_i258 < 8; c2_i258++) {
        c2_u[c2_i258] = c2_cv4[c2_i258];
      }

      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c2_b_u = 14.0;
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c2_c_u = 6.0;
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c2_d_u = c2_e_x;
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c2_m_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c2_d_y, 14, c2_e_y, 14,
        c2_f_y), 14, c2_g_y), "sprintf", c2_str);
      for (c2_i259 = 0; c2_i259 < 14; c2_i259++) {
        c2_b_str[c2_i259] = c2_str[c2_i259];
      }

      c2_b_eml_warning(chartInstance, c2_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c2_eml_warning(chartInstance);
  }
}

static void c2_inv3x3(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[9],
                      real_T c2_y[9])
{
  int32_T c2_p1;
  int32_T c2_p2;
  int32_T c2_p3;
  real_T c2_absx11;
  real_T c2_absx21;
  real_T c2_absx31;
  real_T c2_t1;
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_c_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_d_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_e_y;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_f_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_g_y;
  int32_T c2_itmp;
  real_T c2_f_x;
  real_T c2_h_y;
  real_T c2_z;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_i_y;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_j_y;
  real_T c2_g_x;
  real_T c2_k_y;
  real_T c2_t3;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_l_y;
  real_T c2_h_x;
  real_T c2_m_y;
  real_T c2_t2;
  int32_T c2_h_a;
  int32_T c2_c;
  real_T c2_i_a;
  real_T c2_h_b;
  real_T c2_n_y;
  real_T c2_j_a;
  real_T c2_i_b;
  real_T c2_o_y;
  real_T c2_i_x;
  real_T c2_p_y;
  real_T c2_b_z;
  int32_T c2_k_a;
  int32_T c2_b_c;
  int32_T c2_l_a;
  int32_T c2_c_c;
  real_T c2_j_x;
  real_T c2_q_y;
  real_T c2_m_a;
  real_T c2_j_b;
  real_T c2_r_y;
  real_T c2_k_x;
  real_T c2_s_y;
  int32_T c2_n_a;
  int32_T c2_d_c;
  real_T c2_o_a;
  real_T c2_k_b;
  real_T c2_t_y;
  real_T c2_p_a;
  real_T c2_l_b;
  real_T c2_u_y;
  real_T c2_l_x;
  real_T c2_v_y;
  real_T c2_c_z;
  int32_T c2_q_a;
  int32_T c2_e_c;
  int32_T c2_r_a;
  int32_T c2_f_c;
  real_T c2_w_y;
  real_T c2_s_a;
  real_T c2_m_b;
  real_T c2_x_y;
  real_T c2_m_x;
  real_T c2_y_y;
  int32_T c2_t_a;
  int32_T c2_g_c;
  real_T c2_u_a;
  real_T c2_n_b;
  real_T c2_ab_y;
  real_T c2_v_a;
  real_T c2_o_b;
  real_T c2_bb_y;
  real_T c2_n_x;
  real_T c2_cb_y;
  real_T c2_d_z;
  int32_T c2_w_a;
  int32_T c2_h_c;
  int32_T c2_x_a;
  int32_T c2_i_c;
  boolean_T guard1 = FALSE;
  c2_p1 = 0;
  c2_p2 = 3;
  c2_p3 = 6;
  c2_absx11 = c2_abs(chartInstance, c2_x[0]);
  c2_absx21 = c2_abs(chartInstance, c2_x[1]);
  c2_absx31 = c2_abs(chartInstance, c2_x[2]);
  guard1 = FALSE;
  if (c2_absx21 > c2_absx11) {
    if (c2_absx21 > c2_absx31) {
      c2_p1 = 3;
      c2_p2 = 0;
      c2_t1 = c2_x[0];
      c2_x[0] = c2_x[1];
      c2_x[1] = c2_t1;
      c2_t1 = c2_x[3];
      c2_x[3] = c2_x[4];
      c2_x[4] = c2_t1;
      c2_t1 = c2_x[6];
      c2_x[6] = c2_x[7];
      c2_x[7] = c2_t1;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    if (c2_absx31 > c2_absx11) {
      c2_p1 = 6;
      c2_p3 = 0;
      c2_t1 = c2_x[0];
      c2_x[0] = c2_x[2];
      c2_x[2] = c2_t1;
      c2_t1 = c2_x[3];
      c2_x[3] = c2_x[5];
      c2_x[5] = c2_t1;
      c2_t1 = c2_x[6];
      c2_x[6] = c2_x[8];
      c2_x[8] = c2_t1;
    }
  }

  c2_x[1] = c2_eml_div(chartInstance, c2_x[1], c2_x[0]);
  c2_x[2] = c2_eml_div(chartInstance, c2_x[2], c2_x[0]);
  c2_a = c2_x[1];
  c2_b = c2_x[3];
  c2_b_y = c2_a * c2_b;
  c2_x[4] -= c2_b_y;
  c2_b_a = c2_x[2];
  c2_b_b = c2_x[3];
  c2_c_y = c2_b_a * c2_b_b;
  c2_x[5] -= c2_c_y;
  c2_c_a = c2_x[1];
  c2_c_b = c2_x[6];
  c2_d_y = c2_c_a * c2_c_b;
  c2_x[7] -= c2_d_y;
  c2_d_a = c2_x[2];
  c2_d_b = c2_x[6];
  c2_e_y = c2_d_a * c2_d_b;
  c2_x[8] -= c2_e_y;
  c2_b_x = c2_x[5];
  c2_c_x = c2_b_x;
  c2_f_y = muDoubleScalarAbs(c2_c_x);
  c2_d_x = c2_x[4];
  c2_e_x = c2_d_x;
  c2_g_y = muDoubleScalarAbs(c2_e_x);
  if (c2_f_y > c2_g_y) {
    c2_itmp = c2_p2;
    c2_p2 = c2_p3;
    c2_p3 = c2_itmp;
    c2_t1 = c2_x[1];
    c2_x[1] = c2_x[2];
    c2_x[2] = c2_t1;
    c2_t1 = c2_x[4];
    c2_x[4] = c2_x[5];
    c2_x[5] = c2_t1;
    c2_t1 = c2_x[7];
    c2_x[7] = c2_x[8];
    c2_x[8] = c2_t1;
  }

  c2_f_x = c2_x[5];
  c2_h_y = c2_x[4];
  c2_z = c2_f_x / c2_h_y;
  c2_x[5] = c2_z;
  c2_e_a = c2_x[5];
  c2_e_b = c2_x[7];
  c2_i_y = c2_e_a * c2_e_b;
  c2_x[8] -= c2_i_y;
  c2_f_a = c2_x[5];
  c2_f_b = c2_x[1];
  c2_j_y = c2_f_a * c2_f_b;
  c2_g_x = c2_j_y - c2_x[2];
  c2_k_y = c2_x[8];
  c2_t3 = c2_g_x / c2_k_y;
  c2_g_a = c2_x[7];
  c2_g_b = c2_t3;
  c2_l_y = c2_g_a * c2_g_b;
  c2_h_x = -(c2_x[1] + c2_l_y);
  c2_m_y = c2_x[4];
  c2_t2 = c2_h_x / c2_m_y;
  c2_h_a = c2_p1 + 1;
  c2_c = c2_h_a;
  c2_i_a = c2_x[3];
  c2_h_b = c2_t2;
  c2_n_y = c2_i_a * c2_h_b;
  c2_j_a = c2_x[6];
  c2_i_b = c2_t3;
  c2_o_y = c2_j_a * c2_i_b;
  c2_i_x = (1.0 - c2_n_y) - c2_o_y;
  c2_p_y = c2_x[0];
  c2_b_z = c2_i_x / c2_p_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_c), 1, 9, 1, 0) - 1] = c2_b_z;
  c2_k_a = c2_p1 + 2;
  c2_b_c = c2_k_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_b_c), 1, 9, 1, 0) - 1] = c2_t2;
  c2_l_a = c2_p1 + 3;
  c2_c_c = c2_l_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_c_c), 1, 9, 1, 0) - 1] = c2_t3;
  c2_j_x = -c2_x[5];
  c2_q_y = c2_x[8];
  c2_t3 = c2_j_x / c2_q_y;
  c2_m_a = c2_x[7];
  c2_j_b = c2_t3;
  c2_r_y = c2_m_a * c2_j_b;
  c2_k_x = 1.0 - c2_r_y;
  c2_s_y = c2_x[4];
  c2_t2 = c2_k_x / c2_s_y;
  c2_n_a = c2_p2 + 1;
  c2_d_c = c2_n_a;
  c2_o_a = c2_x[3];
  c2_k_b = c2_t2;
  c2_t_y = c2_o_a * c2_k_b;
  c2_p_a = c2_x[6];
  c2_l_b = c2_t3;
  c2_u_y = c2_p_a * c2_l_b;
  c2_l_x = -(c2_t_y + c2_u_y);
  c2_v_y = c2_x[0];
  c2_c_z = c2_l_x / c2_v_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_d_c), 1, 9, 1, 0) - 1] = c2_c_z;
  c2_q_a = c2_p2 + 2;
  c2_e_c = c2_q_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_e_c), 1, 9, 1, 0) - 1] = c2_t2;
  c2_r_a = c2_p2 + 3;
  c2_f_c = c2_r_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_f_c), 1, 9, 1, 0) - 1] = c2_t3;
  c2_w_y = c2_x[8];
  c2_t3 = 1.0 / c2_w_y;
  c2_s_a = -c2_x[7];
  c2_m_b = c2_t3;
  c2_x_y = c2_s_a * c2_m_b;
  c2_m_x = c2_x_y;
  c2_y_y = c2_x[4];
  c2_t2 = c2_m_x / c2_y_y;
  c2_t_a = c2_p3 + 1;
  c2_g_c = c2_t_a;
  c2_u_a = c2_x[3];
  c2_n_b = c2_t2;
  c2_ab_y = c2_u_a * c2_n_b;
  c2_v_a = c2_x[6];
  c2_o_b = c2_t3;
  c2_bb_y = c2_v_a * c2_o_b;
  c2_n_x = -(c2_ab_y + c2_bb_y);
  c2_cb_y = c2_x[0];
  c2_d_z = c2_n_x / c2_cb_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_g_c), 1, 9, 1, 0) - 1] = c2_d_z;
  c2_w_a = c2_p3 + 2;
  c2_h_c = c2_w_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_h_c), 1, 9, 1, 0) - 1] = c2_t2;
  c2_x_a = c2_p3 + 3;
  c2_i_c = c2_x_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_i_c), 1, 9, 1, 0) - 1] = c2_t3;
}

static real_T c2_abs(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  return muDoubleScalarAbs(c2_b_x);
}

static real_T c2_norm(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[9])
{
  real_T c2_y;
  int32_T c2_j;
  real_T c2_b_j;
  real_T c2_s;
  int32_T c2_i;
  real_T c2_b_i;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  boolean_T c2_b;
  boolean_T exitg1;
  c2_y = 0.0;
  c2_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c2_j < 3)) {
    c2_b_j = 1.0 + (real_T)c2_j;
    c2_s = 0.0;
    for (c2_i = 0; c2_i < 3; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_b_x = c2_x[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 3, 1, 0) + 3 * ((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_j),
        1, 3, 2, 0) - 1)) - 1];
      c2_c_x = c2_b_x;
      c2_b_y = muDoubleScalarAbs(c2_c_x);
      c2_s += c2_b_y;
    }

    c2_d_x = c2_s;
    c2_b = muDoubleScalarIsNaN(c2_d_x);
    if (c2_b) {
      c2_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c2_s > c2_y) {
        c2_y = c2_s;
      }

      c2_j++;
    }
  }

  return c2_y;
}

static void c2_eml_warning(SFc2_ACStesbedInstanceStruct *chartInstance)
{
  int32_T c2_i260;
  static char_T c2_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c2_u[27];
  const mxArray *c2_y = NULL;
  for (c2_i260 = 0; c2_i260 < 27; c2_i260++) {
    c2_u[c2_i260] = c2_varargin_1[c2_i260];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c2_y));
}

static void c2_b_eml_warning(SFc2_ACStesbedInstanceStruct *chartInstance, char_T
  c2_varargin_2[14])
{
  int32_T c2_i261;
  static char_T c2_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c2_u[33];
  const mxArray *c2_y = NULL;
  int32_T c2_i262;
  char_T c2_b_u[14];
  const mxArray *c2_b_y = NULL;
  for (c2_i261 = 0; c2_i261 < 33; c2_i261++) {
    c2_u[c2_i261] = c2_varargin_1[c2_i261];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c2_i262 = 0; c2_i262 < 14; c2_i262++) {
    c2_b_u[c2_i262] = c2_varargin_2[c2_i262];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c2_y, 14, c2_b_y));
}

static void c2_c_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_diag(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_v[9],
                    real_T c2_d[81])
{
  int32_T c2_i263;
  int32_T c2_j;
  int32_T c2_b_j;
  for (c2_i263 = 0; c2_i263 < 81; c2_i263++) {
    c2_d[c2_i263] = 0.0;
  }

  for (c2_j = 1; c2_j < 10; c2_j++) {
    c2_b_j = c2_j;
    c2_d[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_j), 1, 9, 1, 0) + 9 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 9, 2, 0) - 1)) -
      1] = c2_v[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_j), 1, 9, 1, 0) - 1];
  }
}

static void c2_d_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_e_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_b_ut(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_X[36],
                    real_T c2_Wm[9], real_T c2_Wc[9], real_T c2_R[9], real_T
                    c2_y[3], real_T c2_Y[27], real_T c2_P[9], real_T c2_Y1[27])
{
  uint32_T c2_debug_family_var_map[13];
  real_T c2_L;
  real_T c2_k;
  real_T c2_n;
  real_T c2_nargin = 11.0;
  real_T c2_nargout = 4.0;
  int32_T c2_i264;
  int32_T c2_i265;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_i266;
  real_T c2_b_X[4];
  real_T c2_dv21[3];
  int32_T c2_d_k;
  int32_T c2_i267;
  real_T c2_a;
  int32_T c2_e_k;
  int32_T c2_i268;
  real_T c2_b[3];
  int32_T c2_i269;
  int32_T c2_i270;
  int32_T c2_i271;
  int32_T c2_i272;
  int32_T c2_i273;
  int32_T c2_i274;
  real_T c2_b_a[27];
  int32_T c2_i275;
  real_T c2_b_Wc[9];
  real_T c2_b_b[81];
  int32_T c2_i276;
  int32_T c2_i277;
  int32_T c2_i278;
  int32_T c2_i279;
  real_T c2_b_y[27];
  int32_T c2_i280;
  int32_T c2_i281;
  int32_T c2_i282;
  int32_T c2_i283;
  int32_T c2_i284;
  int32_T c2_i285;
  real_T c2_c_b[27];
  int32_T c2_i286;
  int32_T c2_i287;
  int32_T c2_i288;
  int32_T c2_i289;
  real_T c2_c_y[9];
  int32_T c2_i290;
  int32_T c2_i291;
  int32_T c2_i292;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c2_f_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_L, 0U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k, 1U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_n, 2U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 3U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 4U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_X, 5U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Wm, 6U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Wc, 7U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R, 8U, c2_d_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Y, 10U, c2_h_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P, 11U, c2_d_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Y1, 12U, c2_h_sf_marshallOut,
    c2_h_sf_marshallIn);
  c2_n = 3.0;
  CV_EML_FCN(0, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 113);
  c2_L = 9.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 114);
  for (c2_i264 = 0; c2_i264 < 3; c2_i264++) {
    c2_y[c2_i264] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 115);
  for (c2_i265 = 0; c2_i265 < 27; c2_i265++) {
    c2_Y[c2_i265] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 116);
  c2_k = 1.0;
  c2_b_k = 0;
  while (c2_b_k < 9) {
    c2_k = 1.0 + (real_T)c2_b_k;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 117);
    c2_c_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("X", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_k), 1, 9, 2, 0) - 1;
    for (c2_i266 = 0; c2_i266 < 4; c2_i266++) {
      c2_b_X[c2_i266] = c2_X[c2_i266 + (c2_c_k << 2)];
    }

    c2_H(chartInstance, c2_b_X, c2_dv21);
    c2_d_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Y", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_k), 1, 9, 2, 0) - 1;
    for (c2_i267 = 0; c2_i267 < 3; c2_i267++) {
      c2_Y[c2_i267 + 3 * c2_d_k] = c2_dv21[c2_i267];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 118);
    c2_a = c2_Wm[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Wm", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_k), 1, 9, 1, 0) - 1];
    c2_e_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Y", (int32_T)
      _SFD_INTEGER_CHECK("k", c2_k), 1, 9, 2, 0) - 1;
    for (c2_i268 = 0; c2_i268 < 3; c2_i268++) {
      c2_b[c2_i268] = c2_Y[c2_i268 + 3 * c2_e_k];
    }

    for (c2_i269 = 0; c2_i269 < 3; c2_i269++) {
      c2_b[c2_i269] *= c2_a;
    }

    for (c2_i270 = 0; c2_i270 < 3; c2_i270++) {
      c2_y[c2_i270] += c2_b[c2_i270];
    }

    c2_b_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 120);
  c2_i271 = 0;
  for (c2_i272 = 0; c2_i272 < 9; c2_i272++) {
    for (c2_i273 = 0; c2_i273 < 3; c2_i273++) {
      c2_Y1[c2_i273 + c2_i271] = c2_Y[c2_i273 + c2_i271] - c2_y[c2_i273];
    }

    c2_i271 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 121);
  for (c2_i274 = 0; c2_i274 < 27; c2_i274++) {
    c2_b_a[c2_i274] = c2_Y1[c2_i274];
  }

  for (c2_i275 = 0; c2_i275 < 9; c2_i275++) {
    c2_b_Wc[c2_i275] = c2_Wc[c2_i275];
  }

  c2_diag(chartInstance, c2_b_Wc, c2_b_b);
  c2_f_eml_scalar_eg(chartInstance);
  c2_f_eml_scalar_eg(chartInstance);
  for (c2_i276 = 0; c2_i276 < 3; c2_i276++) {
    c2_i277 = 0;
    c2_i278 = 0;
    for (c2_i279 = 0; c2_i279 < 9; c2_i279++) {
      c2_b_y[c2_i277 + c2_i276] = 0.0;
      c2_i280 = 0;
      for (c2_i281 = 0; c2_i281 < 9; c2_i281++) {
        c2_b_y[c2_i277 + c2_i276] += c2_b_a[c2_i280 + c2_i276] * c2_b_b[c2_i281
          + c2_i278];
        c2_i280 += 3;
      }

      c2_i277 += 3;
      c2_i278 += 9;
    }
  }

  c2_i282 = 0;
  for (c2_i283 = 0; c2_i283 < 3; c2_i283++) {
    c2_i284 = 0;
    for (c2_i285 = 0; c2_i285 < 9; c2_i285++) {
      c2_c_b[c2_i285 + c2_i282] = c2_Y1[c2_i284 + c2_i283];
      c2_i284 += 3;
    }

    c2_i282 += 9;
  }

  c2_g_eml_scalar_eg(chartInstance);
  c2_g_eml_scalar_eg(chartInstance);
  for (c2_i286 = 0; c2_i286 < 3; c2_i286++) {
    c2_i287 = 0;
    c2_i288 = 0;
    for (c2_i289 = 0; c2_i289 < 3; c2_i289++) {
      c2_c_y[c2_i287 + c2_i286] = 0.0;
      c2_i290 = 0;
      for (c2_i291 = 0; c2_i291 < 9; c2_i291++) {
        c2_c_y[c2_i287 + c2_i286] += c2_b_y[c2_i290 + c2_i286] * c2_c_b[c2_i291
          + c2_i288];
        c2_i290 += 3;
      }

      c2_i287 += 3;
      c2_i288 += 9;
    }
  }

  for (c2_i292 = 0; c2_i292 < 9; c2_i292++) {
    c2_P[c2_i292] = c2_c_y[c2_i292] + c2_R[c2_i292];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -121);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_H(SFc2_ACStesbedInstanceStruct *chartInstance, real_T c2_x[4],
                 real_T c2_Z[3])
{
  uint32_T c2_debug_family_var_map[4];
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c2_e_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_x, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Z, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_Z[0] = c2_x[0];
  c2_Z[1] = c2_x[1];
  c2_Z[2] = c2_x[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_f_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_g_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_h_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_i_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_j_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_k_eml_scalar_eg(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

static void c2_m_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_sprintf, const char_T *c2_identifier, char_T c2_y[14])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_sprintf);
}

static void c2_n_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, char_T c2_y[14])
{
  char_T c2_cv5[14];
  int32_T c2_i293;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_cv5, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c2_i293 = 0; c2_i293 < 14; c2_i293++) {
    c2_y[c2_i293] = c2_cv5[c2_i293];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_o_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i294;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i294, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i294;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_p_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_ACStesbed, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_ACStesbed), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_ACStesbed);
  return c2_y;
}

static uint8_T c2_q_emlrt_marshallIn(SFc2_ACStesbedInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static int32_T c2_b_eml_matlab_zpotrf(SFc2_ACStesbedInstanceStruct
  *chartInstance, real_T c2_A[16])
{
  int32_T c2_info;
  int32_T c2_colj;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_jm1;
  int32_T c2_b_a;
  int32_T c2_b;
  int32_T c2_jj;
  int32_T c2_n;
  int32_T c2_ix0;
  int32_T c2_iy0;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_e_n;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  real_T c2_d;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_f_n;
  int32_T c2_b_b;
  int32_T c2_c_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_c_a;
  int32_T c2_d_a;
  real_T c2_ajj;
  int32_T c2_d_b;
  int32_T c2_nmj;
  int32_T c2_e_a;
  int32_T c2_jjp1;
  int32_T c2_f_a;
  int32_T c2_coljp1;
  int32_T c2_b_jm1;
  int32_T c2_e_b;
  int32_T c2_f_b;
  boolean_T c2_b_overflow;
  int32_T c2_b_k;
  int32_T c2_c_k;
  int32_T c2_c_jm1;
  int32_T c2_g_b;
  int32_T c2_h_b;
  boolean_T c2_c_overflow;
  int32_T c2_d_k;
  real_T c2_y;
  real_T c2_z;
  int32_T c2_g_n;
  real_T c2_g_a;
  int32_T c2_f_ix0;
  int32_T c2_h_n;
  real_T c2_h_a;
  int32_T c2_g_ix0;
  int32_T c2_i_n;
  real_T c2_i_a;
  int32_T c2_h_ix0;
  int32_T c2_i_ix0;
  int32_T c2_j_a;
  int32_T c2_c;
  int32_T c2_i_b;
  int32_T c2_b_c;
  int32_T c2_k_a;
  int32_T c2_j_b;
  int32_T c2_i295;
  int32_T c2_l_a;
  int32_T c2_k_b;
  int32_T c2_m_a;
  int32_T c2_l_b;
  boolean_T c2_d_overflow;
  int32_T c2_e_k;
  int32_T c2_f_k;
  boolean_T exitg1;
  c2_info = 0;
  c2_b_eml_scalar_eg(chartInstance);
  c2_colj = 1;
  c2_j = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c2_j < 5)) {
    c2_b_j = c2_j;
    c2_a = c2_b_j - 1;
    c2_jm1 = c2_a;
    c2_b_a = c2_colj;
    c2_b = c2_jm1;
    c2_jj = c2_b_a + c2_b;
    c2_n = c2_jm1;
    c2_ix0 = c2_colj;
    c2_iy0 = c2_colj;
    c2_b_n = c2_n;
    c2_b_ix0 = c2_ix0;
    c2_b_iy0 = c2_iy0;
    c2_c_n = c2_b_n;
    c2_c_ix0 = c2_b_ix0;
    c2_c_iy0 = c2_b_iy0;
    c2_d_n = c2_c_n;
    c2_d_ix0 = c2_c_ix0;
    c2_d_iy0 = c2_c_iy0;
    c2_e_n = c2_d_n;
    c2_e_ix0 = c2_d_ix0;
    c2_e_iy0 = c2_d_iy0;
    c2_d = 0.0;
    if (c2_e_n < 1) {
    } else {
      c2_ix = c2_e_ix0;
      c2_iy = c2_e_iy0;
      c2_f_n = c2_e_n;
      c2_b_b = c2_f_n;
      c2_c_b = c2_b_b;
      if (1 > c2_c_b) {
        c2_overflow = FALSE;
      } else {
        c2_overflow = (c2_c_b > 2147483646);
      }

      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_overflow);
      }

      for (c2_k = 1; c2_k <= c2_f_n; c2_k++) {
        c2_d += c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
          ("", (real_T)c2_ix), 1, 16, 1, 0) - 1] *
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_iy), 1, 16, 1, 0) - 1];
        c2_c_a = c2_ix + 1;
        c2_ix = c2_c_a;
        c2_d_a = c2_iy + 1;
        c2_iy = c2_d_a;
      }
    }

    c2_ajj = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_jj), 1, 16, 1, 0) - 1] - c2_d;
    if (c2_ajj > 0.0) {
      c2_ajj = muDoubleScalarSqrt(c2_ajj);
      c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_jj), 1, 16, 1, 0) - 1] = c2_ajj;
      if (c2_b_j < 4) {
        c2_d_b = c2_b_j;
        c2_nmj = 4 - c2_d_b;
        c2_e_a = c2_jj + 4;
        c2_jjp1 = c2_e_a;
        c2_f_a = c2_colj + 4;
        c2_coljp1 = c2_f_a;
        c2_b_jm1 = c2_jm1;
        c2_e_b = c2_b_jm1;
        c2_f_b = c2_e_b;
        if (1 > c2_f_b) {
          c2_b_overflow = FALSE;
        } else {
          c2_b_overflow = (c2_f_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
        }

        for (c2_b_k = 1; c2_b_k <= c2_b_jm1; c2_b_k++) {
          c2_c_k = c2_b_k;
          c2_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c2_c_k), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                   "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 2,
                   0) - 1) << 2)) - 1] = c2_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_c_k), 1, 4, 1, 0) +
            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
        }

        c2_b_eml_xgemv(chartInstance, c2_jm1, c2_nmj, c2_coljp1, c2_colj, c2_A,
                       c2_jjp1);
        c2_c_jm1 = c2_jm1;
        c2_g_b = c2_c_jm1;
        c2_h_b = c2_g_b;
        if (1 > c2_h_b) {
          c2_c_overflow = FALSE;
        } else {
          c2_c_overflow = (c2_h_b > 2147483646);
        }

        if (c2_c_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_c_overflow);
        }

        for (c2_d_k = 1; c2_d_k <= c2_c_jm1; c2_d_k++) {
          c2_c_k = c2_d_k;
          c2_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c2_c_k), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                   "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 2,
                   0) - 1) << 2)) - 1] = c2_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_c_k), 1, 4, 1, 0) +
            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
        }

        c2_y = c2_ajj;
        c2_z = 1.0 / c2_y;
        c2_g_n = c2_nmj;
        c2_g_a = c2_z;
        c2_f_ix0 = c2_jjp1;
        c2_h_n = c2_g_n;
        c2_h_a = c2_g_a;
        c2_g_ix0 = c2_f_ix0;
        c2_i_n = c2_h_n;
        c2_i_a = c2_h_a;
        c2_h_ix0 = c2_g_ix0;
        c2_i_ix0 = c2_h_ix0;
        c2_j_a = c2_i_n;
        c2_c = c2_j_a;
        c2_i_b = c2_c - 1;
        c2_b_c = c2_i_b << 2;
        c2_k_a = c2_h_ix0;
        c2_j_b = c2_b_c;
        c2_i295 = c2_k_a + c2_j_b;
        c2_l_a = c2_i_ix0;
        c2_k_b = c2_i295;
        c2_m_a = c2_l_a;
        c2_l_b = c2_k_b;
        if (c2_m_a > c2_l_b) {
          c2_d_overflow = FALSE;
        } else {
          c2_d_overflow = (c2_l_b > 2147483643);
        }

        if (c2_d_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_d_overflow);
        }

        for (c2_e_k = c2_i_ix0; c2_e_k <= c2_i295; c2_e_k += 4) {
          c2_f_k = c2_e_k;
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_f_k), 1, 16, 1, 0) - 1] = c2_i_a *
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_f_k), 1, 16, 1, 0) - 1];
        }

        c2_colj = c2_coljp1;
      }

      c2_j++;
    } else {
      c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_jj), 1, 16, 1, 0) - 1] = c2_ajj;
      c2_info = c2_b_j;
      exitg1 = TRUE;
    }
  }

  return c2_info;
}

static void c2_b_eml_xgemv(SFc2_ACStesbedInstanceStruct *chartInstance, int32_T
  c2_m, int32_T c2_n, int32_T c2_ia0, int32_T c2_ix0, real_T c2_y[16], int32_T
  c2_iy0)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  int32_T c2_b_ia0;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_alpha1;
  int32_T c2_c_ia0;
  int32_T c2_c_ix0;
  real_T c2_beta1;
  int32_T c2_c_iy0;
  char_T c2_TRANSA;
  int32_T c2_var;
  ptrdiff_t c2_m_t;
  int32_T c2_b_var;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_incx_t;
  ptrdiff_t c2_incy_t;
  double * c2_alpha1_t;
  double * c2_beta1_t;
  double * c2_yiy0_t;
  double * c2_yix0_t;
  double * c2_yia0_t;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_ia0 = c2_ia0;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  if (c2_b_m < 1) {
  } else if (c2_b_n < 1) {
  } else {
    c2_c_m = c2_b_m;
    c2_c_n = c2_b_n;
    c2_alpha1 = -1.0;
    c2_c_ia0 = c2_b_ia0;
    c2_c_ix0 = c2_b_ix0;
    c2_beta1 = 1.0;
    c2_c_iy0 = c2_b_iy0;
    c2_TRANSA = 'T';
    c2_var = c2_c_m;
    c2_m_t = (ptrdiff_t)(c2_var);
    c2_b_var = c2_c_n;
    c2_n_t = (ptrdiff_t)(c2_b_var);
    c2_lda_t = (ptrdiff_t)(4);
    c2_incx_t = (ptrdiff_t)(1);
    c2_incy_t = (ptrdiff_t)(4);
    c2_alpha1_t = (double *)(&c2_alpha1);
    c2_beta1_t = (double *)(&c2_beta1);
    c2_yiy0_t = (double *)(&c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_c_iy0), 1, 16, 1, 0) - 1]);
    c2_yix0_t = (double *)(&c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_c_ix0), 1, 16, 1, 0) - 1]);
    c2_yia0_t = (double *)(&c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_c_ia0), 1, 16, 1, 0) - 1]);
    dgemv(&c2_TRANSA, &c2_m_t, &c2_n_t, c2_alpha1_t, c2_yia0_t, &c2_lda_t,
          c2_yix0_t, &c2_incx_t, c2_beta1_t, c2_yiy0_t, &c2_incy_t);
  }
}

static void init_dsm_address_info(SFc2_ACStesbedInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_ACStesbed_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2048134483U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(702192784U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1675634112U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2351342759U);
}

mxArray *sf_c2_ACStesbed_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4TwJltDyiyVfTPCs02Y6SB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_ACStesbed_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_ACStesbed_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_ACStesbed(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[7],T\"P\",},{M[1],M[12],T\"W_est\",},{M[1],M[5],T\"rz_est\",},{M[8],M[0],T\"is_active_c2_ACStesbed\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ACStesbed_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ACStesbedInstanceStruct *chartInstance;
    chartInstance = (SFc2_ACStesbedInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ACStesbedMachineNumber_,
           2,
           1,
           1,
           12,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_ACStesbedMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ACStesbedMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ACStesbedMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"W");
          _SFD_SET_DATA_PROPS(1,1,1,0,"rz_estin");
          _SFD_SET_DATA_PROPS(2,1,1,0,"W_estin");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Pin");
          _SFD_SET_DATA_PROPS(4,2,0,1,"rz_est");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dh");
          _SFD_SET_DATA_PROPS(6,1,1,0,"h");
          _SFD_SET_DATA_PROPS(7,1,1,0,"gb");
          _SFD_SET_DATA_PROPS(8,1,1,0,"J");
          _SFD_SET_DATA_PROPS(9,2,0,1,"W_est");
          _SFD_SET_DATA_PROPS(10,2,0,1,"P");
          _SFD_SET_DATA_PROPS(11,1,1,0,"Mass");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,6,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,483);
        _SFD_CV_INIT_EML_FCN(0,1,"F",513,-1,627);
        _SFD_CV_INIT_EML_FCN(0,2,"H",654,-1,712);
        _SFD_CV_INIT_EML_FCN(0,3,"ukf",714,-1,4153);
        _SFD_CV_INIT_EML_FCN(0,4,"ut",4155,-1,4771);
        _SFD_CV_INIT_EML_FCN(0,5,"sigmas",4773,-1,5014);
        _SFD_CV_INIT_EML_FOR(0,1,0,4616,4626,4724);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_rz_estin;
          real_T *c2_rz_est;
          real_T *c2_Mass;
          real_T (*c2_W)[3];
          real_T (*c2_W_estin)[3];
          real_T (*c2_Pin)[16];
          real_T (*c2_dh)[3];
          real_T (*c2_h)[3];
          real_T (*c2_gb)[3];
          real_T (*c2_J)[9];
          real_T (*c2_W_est)[3];
          real_T (*c2_P)[16];
          c2_Mass = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c2_P = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 3);
          c2_W_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_J = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 7);
          c2_gb = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 6);
          c2_h = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
          c2_dh = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c2_rz_est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Pin = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 3);
          c2_W_estin = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c2_rz_estin = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_W = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_W);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_rz_estin);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_W_estin);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_Pin);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_rz_est);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_dh);
          _SFD_SET_DATA_VALUE_PTR(6U, *c2_h);
          _SFD_SET_DATA_VALUE_PTR(7U, *c2_gb);
          _SFD_SET_DATA_VALUE_PTR(8U, *c2_J);
          _SFD_SET_DATA_VALUE_PTR(9U, *c2_W_est);
          _SFD_SET_DATA_VALUE_PTR(10U, *c2_P);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_Mass);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ACStesbedMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "NaA5Unipkk30WtViX6YULC";
}

static void sf_opaque_initialize_c2_ACStesbed(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_ACStesbedInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*)
    chartInstanceVar);
  initialize_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_ACStesbed(void *chartInstanceVar)
{
  enable_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_ACStesbed(void *chartInstanceVar)
{
  disable_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_ACStesbed(void *chartInstanceVar)
{
  sf_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_ACStesbed(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ACStesbed();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_ACStesbed(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_ACStesbed();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_ACStesbed(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_ACStesbed(S);
}

static void sf_opaque_set_sim_state_c2_ACStesbed(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_ACStesbed(S, st);
}

static void sf_opaque_terminate_c2_ACStesbed(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ACStesbedInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ACStesbed_optimization_info();
    }

    finalize_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_ACStesbed((SFc2_ACStesbedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ACStesbed(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ACStesbed((SFc2_ACStesbedInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_ACStesbed(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ACStesbed_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,9);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(681133888U));
  ssSetChecksum1(S,(2164241338U));
  ssSetChecksum2(S,(2226352665U));
  ssSetChecksum3(S,(188955205U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_ACStesbed(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_ACStesbed(SimStruct *S)
{
  SFc2_ACStesbedInstanceStruct *chartInstance;
  chartInstance = (SFc2_ACStesbedInstanceStruct *)utMalloc(sizeof
    (SFc2_ACStesbedInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_ACStesbedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_ACStesbed;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_ACStesbed;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_ACStesbed;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_ACStesbed;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_ACStesbed;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_ACStesbed;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_ACStesbed;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_ACStesbed;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ACStesbed;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_ACStesbed;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_ACStesbed;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_ACStesbed_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ACStesbed(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ACStesbed(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ACStesbed(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ACStesbed_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
