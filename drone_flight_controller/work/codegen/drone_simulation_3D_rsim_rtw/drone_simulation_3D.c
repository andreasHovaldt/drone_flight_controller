/*
 * drone_simulation_3D.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "drone_simulation_3D".
 *
 * Model version              : 1.38
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Apr 12 14:10:33 2023
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "drone_simulation_3D.h"
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
#include <string.h>
#include "drone_simulation_3D_private.h"
#include "drone_simulation_3D_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "drone_simulation_3D_rsim_rtw\\drone_simulation_3D_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 0;
const int_T gblNumModelInputs = 0;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { -1 };

const int_T gblInportDims[] = { -1 } ;

const int_T gblInportComplex[] = { -1 };

const int_T gblInportInterpoFlag[] = { -1 };

const int_T gblInportContinuous[] = { -1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (default storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (default storage) */
DW rtDW;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Forward declaration for local functions */
static void drone_simulation_3D_sum(const real_T x[12], real_T y[3]);

/* Function for MATLAB Function: '<Root>/Drone dynamics' */
static void drone_simulation_3D_sum(const real_T x[12], real_T y[3])
{
  int32_T xj;
  y[0] = x[0];
  y[1] = x[1];
  y[2] = x[2];
  for (xj = 0; xj < 3; xj++) {
    int32_T xoffset;
    xoffset = (xj + 1) * 3;
    y[0] += x[xoffset];
    y[1] += x[xoffset + 1];
    y[2] += x[xoffset + 2];
  }
}

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  /* InitializeConditions for Integrator: '<S138>/Integrator' */
  rtX.Integrator_CSTATE = rtP.PIDController2_InitialConditi_n;

  /* InitializeConditions for Integrator: '<S133>/Filter' */
  rtX.Filter_CSTATE = rtP.PIDController2_InitialCondition;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE[0] = rtP.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[0] = rtP.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE[1] = rtP.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[1] = rtP.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE[2] = rtP.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[2] = rtP.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S186>/Integrator' */
  rtX.Integrator_CSTATE_b = rtP.PIDController3_InitialConditi_e;

  /* InitializeConditions for Integrator: '<S181>/Filter' */
  rtX.Filter_CSTATE_m = rtP.PIDController3_InitialCondition;

  /* InitializeConditions for Integrator: '<S90>/Integrator' */
  rtX.Integrator_CSTATE_e = rtP.PIDController1_InitialConditi_i;

  /* InitializeConditions for Integrator: '<S85>/Filter' */
  rtX.Filter_CSTATE_k = rtP.PIDController1_InitialCondition;

  /* InitializeConditions for Integrator: '<S42>/Integrator' */
  rtX.Integrator_CSTATE_f = rtP.PIDController_InitialConditio_i;

  /* InitializeConditions for Integrator: '<S37>/Filter' */
  rtX.Filter_CSTATE_i = rtP.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S282>/Integrator' */
  rtX.Integrator_CSTATE_h = rtP.PIDController5_InitialConditi_b;

  /* InitializeConditions for Integrator: '<S277>/Filter' */
  rtX.Filter_CSTATE_c = rtP.PIDController5_InitialCondition;

  /* InitializeConditions for Integrator: '<S234>/Integrator' */
  rtX.Integrator_CSTATE_i = rtP.PIDController4_InitialConditi_g;

  /* InitializeConditions for Integrator: '<S229>/Filter' */
  rtX.Filter_CSTATE_n = rtP.PIDController4_InitialCondition;

  /* InitializeConditions for Integrator: '<Root>/  ' incorporates:
   *  Integrator: '<Root>/ '
   */
  if (ssIsFirstInitCond(rtS)) {
    rtX._CSTATE[0] = 0.0;
    rtX._CSTATE[1] = 0.0;
    rtX._CSTATE[2] = 0.0;
    rtX._CSTATE_c[0] = 0.0;
    rtX._CSTATE_c[1] = 0.0;
    rtX._CSTATE_c[2] = 0.0;
  }

  rtDW._IWORK = 1;

  /* End of InitializeConditions for Integrator: '<Root>/  ' */

  /* InitializeConditions for Integrator: '<Root>/ ' */
  rtDW._IWORK_n = 1;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace' */
  {
    int_T dimensions[1] = { 3 };

    rtDW.ToWorkspace_PWORK.LoggedData = rt_CreateLogVar(
      ssGetRTWLogInfo(rtS),
      ssGetTStart(rtS),
      ssGetTFinal(rtS),
      0.0,
      (&ssGetErrorStatus(rtS)),
      "XYZ",
      SS_DOUBLE,
      0,
      0,
      0,
      3,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.0,
      1);
    if (rtDW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace1' */
  {
    int_T dimensions[1] = { 3 };

    rtDW.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
      ssGetRTWLogInfo(rtS),
      ssGetTStart(rtS),
      ssGetTFinal(rtS),
      0.0,
      (&ssGetErrorStatus(rtS)),
      "RPY",
      SS_DOUBLE,
      0,
      0,
      0,
      3,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.0,
      1);
    if (rtDW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace2' */
  {
    int_T dimensions[1] = { 3 };

    rtDW.ToWorkspace2_PWORK.LoggedData = rt_CreateLogVar(
      ssGetRTWLogInfo(rtS),
      ssGetTStart(rtS),
      ssGetTFinal(rtS),
      0.0,
      (&ssGetErrorStatus(rtS)),
      "refXYZ",
      SS_DOUBLE,
      0,
      0,
      0,
      3,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.0,
      1);
    if (rtDW.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  real_T c[12];
  real_T local_motor_forces[12];
  real_T I_global[9];
  real_T R[9];
  real_T alpha[3];
  real_T b[3];
  real_T b_ct;
  real_T b_st;
  real_T c_ct;
  real_T c_st;
  real_T ct;
  real_T st;
  int32_T iEnd;
  int32_T itmp;
  int32_T p1;
  int32_T p3;
  static const real_T g[3] = { 0.0, 0.0, -0.2935198 };

  static const real_T h[12] = { 0.028284271247461905, 0.028284271247461898, 0.0,
    0.028284271247461905, -0.028284271247461898, 0.0, -0.028284271247461905,
    -0.028284271247461898, 0.0, -0.028284271247461905, 0.028284271247461898, 0.0
  };

  __m128d tmp_1;
  __m128d tmp_4;
  __m128d tmp_5;
  real_T tmp[12];
  real_T b_ct_0[9];
  real_T c_ct_0[9];
  real_T rtb_motor_forces[4];
  real_T rtb_rpy[3];
  real_T tmp_0[3];
  real_T rtb_motor_forces_tmp;
  real_T rtb_motor_forces_tmp_0;
  real_T rtb_x_ref;
  real_T rtb_y_ref;
  real_T rtb_z_ref;
  static const int8_T f[3] = { 0, 0, 1 };

  static const real_T c_b[9] = { 1.132869584E-5, 0.0, 0.0, 0.0, 1.132869584E-5,
    0.0, 0.0, 0.0, 2.028869584E-5 };

  static const real_T h_0[12] = { 0.028284271247461905, 0.028284271247461898,
    0.0, 0.028284271247461905, -0.028284271247461898, 0.0, -0.028284271247461905,
    -0.028284271247461898, 0.0, -0.028284271247461905, 0.028284271247461898, 0.0
  };

  static const real_T g_0[3] = { 0.0, 0.0, -0.2935198 };

  __m128d tmp_6;

  /* Sin: '<Root>/y_ref' incorporates:
   *  Sin: '<Root>/x_ref'
   *  Sin: '<Root>/z_ref'
   */
  rtb_z_ref = ssGetTaskTime(rtS,0);
  rtb_y_ref = sin(rtP.y_ref_Freq * rtb_z_ref + rtP.y_ref_Phase) * rtP.y_ref_Amp
    + rtP.y_ref_Bias;

  /* Integrator: '<S138>/Integrator' */
  rtB.Integrator = rtX.Integrator_CSTATE;

  /* Integrator: '<S133>/Filter' */
  rtB.Filter = rtX.Filter_CSTATE;

  /* Integrator: '<Root>/Integrator2' */
  rtB.current_pos[0] = rtX.Integrator2_CSTATE[0];

  /* Integrator: '<Root>/Integrator1' */
  rtB.Integrator1[0] = rtX.Integrator1_CSTATE[0];

  /* Integrator: '<Root>/Integrator2' */
  rtB.current_pos[1] = rtX.Integrator2_CSTATE[1];

  /* Integrator: '<Root>/Integrator1' */
  rtB.Integrator1[1] = rtX.Integrator1_CSTATE[1];

  /* Integrator: '<Root>/Integrator2' */
  rtB.current_pos[2] = rtX.Integrator2_CSTATE[2];

  /* Integrator: '<Root>/Integrator1' */
  rtB.Integrator1[2] = rtX.Integrator1_CSTATE[2];

  /* Sum: '<S3>/Sum2' */
  rtB.Sum2 = rtb_y_ref - rtB.current_pos[1];

  /* Gain: '<S143>/Proportional Gain' */
  rtB.ProportionalGain = rtP.PIDController2_P * rtB.Sum2;

  /* Gain: '<S132>/Derivative Gain' */
  rtB.DerivativeGain = rtP.PIDController2_D * rtB.Sum2;

  /* Sum: '<S133>/SumD' */
  rtB.SumD = rtB.DerivativeGain - rtB.Filter;

  /* Gain: '<S141>/Filter Coefficient' */
  rtB.FilterCoefficient = rtP.PIDController2_N * rtB.SumD;

  /* Sum: '<S147>/Sum' */
  rtB.Sum = (rtB.ProportionalGain + rtB.Integrator) + rtB.FilterCoefficient;

  /* Sum: '<S3>/Sum4' */
  rtB.Sum4 = rtB.Sum - rtB.Integrator1[0];

  /* Gain: '<S191>/Proportional Gain' */
  rtB.ProportionalGain_b = rtP.PIDController3_P * rtB.Sum4;

  /* Integrator: '<S186>/Integrator' */
  rtB.Integrator_j = rtX.Integrator_CSTATE_b;

  /* Gain: '<S180>/Derivative Gain' */
  rtB.DerivativeGain_m = rtP.PIDController3_D * rtB.Sum4;

  /* Integrator: '<S181>/Filter' */
  rtB.Filter_e = rtX.Filter_CSTATE_m;

  /* Sum: '<S181>/SumD' */
  rtB.SumD_h = rtB.DerivativeGain_m - rtB.Filter_e;

  /* Gain: '<S189>/Filter Coefficient' */
  rtB.FilterCoefficient_k = rtP.PIDController3_N * rtB.SumD_h;

  /* Sum: '<S195>/Sum' */
  rtB.Sum_o = (rtB.ProportionalGain_b + rtB.Integrator_j) +
    rtB.FilterCoefficient_k;

  /* Saturate: '<S193>/Saturation' */
  if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.Saturation_MODE = rtB.Sum_o >= rtP.PIDController3_UpperSaturationL ? 1 :
      rtB.Sum_o > rtP.PIDController3_LowerSaturationL ? 0 : -1;
  }

  /* Saturate: '<S193>/Saturation' */
  rtB.Saturation = rtDW.Saturation_MODE == 1 ?
    rtP.PIDController3_UpperSaturationL : rtDW.Saturation_MODE == -1 ?
    rtP.PIDController3_LowerSaturationL : rtB.Sum_o;

  /* Sin: '<Root>/x_ref' */
  rtb_x_ref = sin(rtP.x_ref_Freq * rtb_z_ref + rtP.x_ref_Phase) * rtP.x_ref_Amp
    + rtP.x_ref_Bias;

  /* Sum: '<S3>/Sum1' */
  rtB.Sum1 = rtb_x_ref - rtB.current_pos[0];

  /* Gain: '<S95>/Proportional Gain' */
  rtB.ProportionalGain_m = rtP.PIDController1_P * rtB.Sum1;

  /* Integrator: '<S90>/Integrator' */
  rtB.Integrator_e = rtX.Integrator_CSTATE_e;

  /* Gain: '<S84>/Derivative Gain' */
  rtB.DerivativeGain_h = rtP.PIDController1_D * rtB.Sum1;

  /* Integrator: '<S85>/Filter' */
  rtB.Filter_j = rtX.Filter_CSTATE_k;

  /* Sum: '<S85>/SumD' */
  rtB.SumD_j = rtB.DerivativeGain_h - rtB.Filter_j;

  /* Gain: '<S93>/Filter Coefficient' */
  rtB.FilterCoefficient_a = rtP.PIDController1_N * rtB.SumD_j;

  /* Sum: '<S99>/Sum' */
  rtB.Sum_p = (rtB.ProportionalGain_m + rtB.Integrator_e) +
    rtB.FilterCoefficient_a;

  /* Sum: '<S3>/Sum3' */
  rtB.Sum3 = rtB.Sum_p - rtB.Integrator1[1];

  /* Gain: '<S47>/Proportional Gain' */
  rtB.ProportionalGain_i = rtP.PIDController_P * rtB.Sum3;

  /* Integrator: '<S42>/Integrator' */
  rtB.Integrator_h = rtX.Integrator_CSTATE_f;

  /* Gain: '<S36>/Derivative Gain' */
  rtB.DerivativeGain_l = rtP.PIDController_D * rtB.Sum3;

  /* Integrator: '<S37>/Filter' */
  rtB.Filter_m = rtX.Filter_CSTATE_i;

  /* Sum: '<S37>/SumD' */
  rtB.SumD_n = rtB.DerivativeGain_l - rtB.Filter_m;

  /* Gain: '<S45>/Filter Coefficient' */
  rtB.FilterCoefficient_e = rtP.PIDController_N * rtB.SumD_n;

  /* Sum: '<S51>/Sum' */
  rtB.Sum_h = (rtB.ProportionalGain_i + rtB.Integrator_h) +
    rtB.FilterCoefficient_e;

  /* Saturate: '<S49>/Saturation' */
  if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.Saturation_MODE_e = rtB.Sum_h >= rtP.PIDController_UpperSaturationLi ?
      1 : rtB.Sum_h > rtP.PIDController_LowerSaturationLi ? 0 : -1;
  }

  /* Saturate: '<S49>/Saturation' */
  rtB.Saturation_f = rtDW.Saturation_MODE_e == 1 ?
    rtP.PIDController_UpperSaturationLi : rtDW.Saturation_MODE_e == -1 ?
    rtP.PIDController_LowerSaturationLi : rtB.Sum_h;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Constant: '<S3>/Constant' */
    rtB.Constant = rtP.Constant_Value;
  }

  /* Sum: '<S3>/Sum5' */
  rtB.Sum5 = rtB.Constant - rtB.Integrator1[2];

  /* Gain: '<S287>/Proportional Gain' */
  rtB.ProportionalGain_d = rtP.PIDController5_P * rtB.Sum5;

  /* Integrator: '<S282>/Integrator' */
  rtB.Integrator_l = rtX.Integrator_CSTATE_h;

  /* Gain: '<S276>/Derivative Gain' */
  rtB.DerivativeGain_g = rtP.PIDController5_D * rtB.Sum5;

  /* Integrator: '<S277>/Filter' */
  rtB.Filter_ey = rtX.Filter_CSTATE_c;

  /* Sum: '<S277>/SumD' */
  rtB.SumD_no = rtB.DerivativeGain_g - rtB.Filter_ey;

  /* Gain: '<S285>/Filter Coefficient' */
  rtB.FilterCoefficient_d = rtP.PIDController5_N * rtB.SumD_no;

  /* Sum: '<S291>/Sum' */
  rtB.Sum_e = (rtB.ProportionalGain_d + rtB.Integrator_l) +
    rtB.FilterCoefficient_d;

  /* Saturate: '<S289>/Saturation' */
  if (ssIsModeUpdateTimeStep(rtS)) {
    rtDW.Saturation_MODE_g = rtB.Sum_e >= rtP.PIDController5_UpperSaturationL ?
      1 : rtB.Sum_e > rtP.PIDController5_LowerSaturationL ? 0 : -1;
  }

  /* Saturate: '<S289>/Saturation' */
  rtB.Saturation_b = rtDW.Saturation_MODE_g == 1 ?
    rtP.PIDController5_UpperSaturationL : rtDW.Saturation_MODE_g == -1 ?
    rtP.PIDController5_LowerSaturationL : rtB.Sum_e;

  /* MATLAB Function: '<S3>/MATLAB Function' */
  rtb_rpy[0] = rtB.Saturation;
  rtb_rpy[1] = rtB.Saturation_f;
  rtb_rpy[2] = rtB.Saturation_b;

  /* Sin: '<Root>/z_ref' */
  rtb_z_ref = sin(rtP.z_ref_Freq * rtb_z_ref + rtP.z_ref_Phase) * rtP.z_ref_Amp
    + rtP.z_ref_Bias;

  /* Sum: '<S3>/Sum' */
  rtB.Sum_pm = rtb_z_ref - rtB.current_pos[2];

  /* Gain: '<S239>/Proportional Gain' */
  rtB.ProportionalGain_f = rtP.PIDController4_P * rtB.Sum_pm;

  /* Integrator: '<S234>/Integrator' */
  rtB.Integrator_a = rtX.Integrator_CSTATE_i;

  /* Gain: '<S228>/Derivative Gain' */
  rtB.DerivativeGain_a = rtP.PIDController4_D * rtB.Sum_pm;

  /* Integrator: '<S229>/Filter' */
  rtB.Filter_g = rtX.Filter_CSTATE_n;

  /* Sum: '<S229>/SumD' */
  rtB.SumD_f = rtB.DerivativeGain_a - rtB.Filter_g;

  /* Gain: '<S237>/Filter Coefficient' */
  rtB.FilterCoefficient_ku = rtP.PIDController4_N * rtB.SumD_f;

  /* Sum: '<S243>/Sum' */
  rtB.Sum_c = (rtB.ProportionalGain_f + rtB.Integrator_a) +
    rtB.FilterCoefficient_ku;

  /* MATLAB Function: '<Root>/Motor mixing algorithm' */
  rtb_motor_forces_tmp_0 = rtB.Sum_c + rtb_rpy[0];
  rtb_motor_forces[0] = (rtb_motor_forces_tmp_0 - rtb_rpy[1]) - rtb_rpy[2];
  rtb_motor_forces_tmp = rtB.Sum_c - rtb_rpy[0];
  rtb_motor_forces[1] = (rtb_motor_forces_tmp - rtb_rpy[1]) + rtb_rpy[2];
  rtb_motor_forces[2] = (rtb_motor_forces_tmp + rtb_rpy[1]) - rtb_rpy[2];
  rtb_motor_forces[3] = (rtb_motor_forces_tmp_0 + rtb_rpy[1]) + rtb_rpy[2];
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Constant: '<Root>/Constant3' */
    rtB.Constant3 = rtP.Constant3_Value;
  }

  /* SignalConversion generated from: '<Root>/ ' */
  rtB.TmpSignalConversionAtInport2[0] = rtB.Constant3;
  rtB.TmpSignalConversionAtInport2[1] = rtB.Constant3;
  rtB.TmpSignalConversionAtInport2[2] = rtB.Constant3;

  /* Integrator: '<Root>/  ' */
  if (ssIsModeUpdateTimeStep(rtS)) {
    if (rtDW._IWORK != 0) {
      rtX._CSTATE[0] = rtB.TmpSignalConversionAtInport2[0];
      rtX._CSTATE[1] = rtB.TmpSignalConversionAtInport2[1];
      rtX._CSTATE[2] = rtB.TmpSignalConversionAtInport2[2];
    }

    /* Integrator: '<Root>/  ' */
    rtB.u[0] = rtX._CSTATE[0];
    rtB.u[1] = rtX._CSTATE[1];
    rtB.u[2] = rtX._CSTATE[2];
  } else {
    /* Integrator: '<Root>/  ' */
    rtB.u[0] = rtX._CSTATE[0];
    rtB.u[1] = rtX._CSTATE[1];
    rtB.u[2] = rtX._CSTATE[2];
  }

  /* End of Integrator: '<Root>/  ' */

  /* MATLAB Function: '<Root>/Drone dynamics' */
  local_motor_forces[0] = 0.0;
  local_motor_forces[1] = 0.0;
  local_motor_forces[2] = rtb_motor_forces[0];
  local_motor_forces[3] = 0.0;
  local_motor_forces[4] = 0.0;
  local_motor_forces[5] = rtb_motor_forces[1];
  local_motor_forces[6] = 0.0;
  local_motor_forces[7] = 0.0;
  local_motor_forces[8] = rtb_motor_forces[2];
  local_motor_forces[9] = 0.0;
  local_motor_forces[10] = 0.0;
  local_motor_forces[11] = rtb_motor_forces[3];
  if (rtb_motor_forces[0] < 0.00013) {
    rtb_motor_forces_tmp_0 = 0.0;
  } else {
    rtb_motor_forces_tmp_0 = (sqrt(1.0703800000000001E+15 * rtb_motor_forces[0]
      - 1.373657841E+11) * 0.001868495301 + 966.0550459) * 0.1047198;
    rtb_motor_forces_tmp_0 = rtb_motor_forces_tmp_0 * rtb_motor_forces_tmp_0 *
      5.6217590777380778E-10;
  }

  if (rtb_motor_forces[1] < 0.00013) {
    tmp[5] = 0.0;
  } else {
    rtb_motor_forces_tmp = (sqrt(1.0703800000000001E+15 * rtb_motor_forces[1] -
      1.373657841E+11) * 0.001868495301 + 966.0550459) * 0.1047198;
    tmp[5] = rtb_motor_forces_tmp * rtb_motor_forces_tmp *
      5.6217590777380778E-10;
  }

  if (rtb_motor_forces[2] < 0.00013) {
    rtb_motor_forces_tmp = 0.0;
  } else {
    rtb_motor_forces_tmp = (sqrt(1.0703800000000001E+15 * rtb_motor_forces[2] -
      1.373657841E+11) * 0.001868495301 + 966.0550459) * 0.1047198;
    rtb_motor_forces_tmp = rtb_motor_forces_tmp * rtb_motor_forces_tmp *
      5.6217590777380778E-10;
  }

  if (rtb_motor_forces[3] < 0.00013) {
    tmp[11] = 0.0;
  } else {
    ct = (sqrt(1.0703800000000001E+15 * rtb_motor_forces[3] - 1.373657841E+11) *
          0.001868495301 + 966.0550459) * 0.1047198;
    tmp[11] = ct * ct * 5.6217590777380778E-10;
  }

  ct = cos(rtB.Integrator1[0]);
  st = sin(rtB.Integrator1[0]);
  if (fabs(st) < 2.2204460492503131E-16) {
    st = 0.0;
  }

  if (fabs(ct) < 2.2204460492503131E-16) {
    ct = 0.0;
  }

  b_ct = cos(rtB.Integrator1[1]);
  b_st = sin(rtB.Integrator1[1]);
  if (fabs(b_st) < 2.2204460492503131E-16) {
    b_st = 0.0;
  }

  if (fabs(b_ct) < 2.2204460492503131E-16) {
    b_ct = 0.0;
  }

  c_ct = cos(rtB.Integrator1[2]);
  c_st = sin(rtB.Integrator1[2]);
  if (fabs(c_st) < 2.2204460492503131E-16) {
    c_st = 0.0;
  }

  if (fabs(c_ct) < 2.2204460492503131E-16) {
    c_ct = 0.0;
  }

  R[1] = 0.0;
  R[4] = ct;
  R[7] = -st;
  R[2] = 0.0;
  R[5] = st;
  R[8] = ct;
  b_ct_0[0] = b_ct;
  b_ct_0[3] = 0.0;
  b_ct_0[6] = b_st;
  R[0] = 1.0;
  b_ct_0[1] = 0.0;
  R[3] = 0.0;
  b_ct_0[4] = 1.0;
  R[6] = 0.0;
  b_ct_0[7] = 0.0;
  b_ct_0[2] = -b_st;
  b_ct_0[5] = 0.0;
  b_ct_0[8] = b_ct;
  c_ct_0[0] = c_ct;
  c_ct_0[3] = -c_st;
  c_ct_0[6] = 0.0;
  c_ct_0[1] = c_st;
  c_ct_0[4] = c_ct;
  c_ct_0[7] = 0.0;
  for (p1 = 0; p1 < 3; p1++) {
    for (p3 = 0; p3 < 3; p3++) {
      iEnd = 3 * p3 + p1;
      I_global[iEnd] = 0.0;
      I_global[iEnd] += b_ct_0[3 * p3] * R[p1];
      I_global[iEnd] += b_ct_0[3 * p3 + 1] * R[p1 + 3];
      I_global[iEnd] += b_ct_0[3 * p3 + 2] * R[p1 + 6];
    }

    c_ct_0[3 * p1 + 2] = f[p1];
  }

  for (p1 = 0; p1 < 3; p1++) {
    for (p3 = 0; p3 < 3; p3++) {
      iEnd = 3 * p3 + p1;
      R[iEnd] = 0.0;
      R[iEnd] += c_ct_0[3 * p3] * I_global[p1];
      R[iEnd] += c_ct_0[3 * p3 + 1] * I_global[p1 + 3];
      R[iEnd] += c_ct_0[3 * p3 + 2] * I_global[p1 + 6];
    }

    for (p3 = 0; p3 < 3; p3++) {
      iEnd = 3 * p3 + p1;
      b_ct_0[iEnd] = 0.0;
      b_ct_0[iEnd] += c_b[3 * p3] * R[p1];
      b_ct_0[iEnd] += c_b[3 * p3 + 1] * R[p1 + 3];
      b_ct_0[iEnd] += c_b[3 * p3 + 2] * R[p1 + 6];
    }
  }

  for (p1 = 0; p1 < 3; p1++) {
    for (p3 = 0; p3 < 3; p3++) {
      iEnd = 3 * p3 + p1;
      I_global[iEnd] = 0.0;
      I_global[iEnd] += b_ct_0[p1] * R[p3];
      I_global[iEnd] += b_ct_0[p1 + 3] * R[p3 + 3];
      I_global[iEnd] += b_ct_0[p1 + 6] * R[p3 + 6];
    }
  }

  for (p1 = 0; p1 <= 9; p1 += 3) {
    iEnd = p1 + 1;
    itmp = p1 - 1;
    for (p3 = p1 + 1; p3 <= itmp; p3 += 2) {
      tmp_4 = _mm_loadu_pd(&local_motor_forces[p3 + 1]);
      tmp_5 = _mm_loadu_pd(&local_motor_forces[p3]);
      tmp_6 = _mm_loadu_pd(&h[p3 + 1]);
      _mm_storeu_pd(&c[p3 - 1], _mm_sub_pd(_mm_mul_pd(tmp_4, _mm_loadu_pd(&h[p3])),
        _mm_mul_pd(tmp_6, tmp_5)));
      tmp_4 = _mm_loadu_pd(&local_motor_forces[p3 - 1]);
      tmp_5 = _mm_loadu_pd(&local_motor_forces[p3 + 1]);
      _mm_storeu_pd(&c[p3], _mm_sub_pd(_mm_mul_pd(tmp_6, tmp_4), _mm_mul_pd
        (_mm_loadu_pd(&h[p3 - 1]), tmp_5)));
      tmp_4 = _mm_loadu_pd(&local_motor_forces[p3]);
      tmp_5 = _mm_loadu_pd(&local_motor_forces[p3 - 1]);
      _mm_storeu_pd(&c[p3 + 1], _mm_sub_pd(_mm_mul_pd(_mm_loadu_pd(&h[p3 - 1]),
        tmp_4), _mm_mul_pd(tmp_5, _mm_loadu_pd(&h[p3]))));
    }

    for (p3 = iEnd; p3 <= p1 + 1; p3++) {
      ct = h_0[p3 + 1];
      st = local_motor_forces[p3 + 1];
      c[p3 - 1] = st * h_0[p3] - ct * local_motor_forces[p3];
      b_ct = h_0[p3 - 1];
      b_st = local_motor_forces[p3 - 1];
      c[p3] = ct * b_st - b_ct * st;
      c[p3 + 1] = b_ct * local_motor_forces[p3] - b_st * h_0[p3];
    }
  }

  drone_simulation_3D_sum(local_motor_forces, alpha);
  for (p1 = 0; p1 <= 0; p1 += 2) {
    __m128d tmp_2;
    __m128d tmp_3;

    /* MATLAB Function: '<Root>/Drone dynamics' */
    tmp_4 = _mm_loadu_pd(&I_global[p1]);
    tmp_5 = _mm_loadu_pd(&I_global[p1 + 3]);
    tmp_6 = _mm_loadu_pd(&I_global[p1 + 6]);
    tmp_1 = _mm_loadu_pd(&R[p1 + 3]);
    tmp_2 = _mm_loadu_pd(&R[p1]);
    tmp_3 = _mm_loadu_pd(&R[p1 + 6]);
    _mm_storeu_pd(&rtb_rpy[p1], _mm_div_pd(_mm_add_pd(_mm_add_pd(_mm_add_pd
      (_mm_mul_pd(tmp_1, _mm_set1_pd(alpha[1])), _mm_mul_pd(tmp_2, _mm_set1_pd
      (alpha[0]))), _mm_mul_pd(tmp_3, _mm_set1_pd(alpha[2]))), _mm_loadu_pd
      (&g[p1])), _mm_set1_pd(0.02989)));
    _mm_storeu_pd(&b[p1], _mm_add_pd(_mm_mul_pd(tmp_6, _mm_set1_pd(rtB.u[2])),
      _mm_add_pd(_mm_mul_pd(tmp_5, _mm_set1_pd(rtB.u[1])), _mm_add_pd(_mm_mul_pd
      (tmp_4, _mm_set1_pd(rtB.u[0])), _mm_set1_pd(0.0)))));
  }

  /* MATLAB Function: '<Root>/Drone dynamics' */
  for (p1 = 2; p1 < 3; p1++) {
    rtb_rpy[p1] = (((R[p1 + 3] * alpha[1] + R[p1] * alpha[0]) + R[p1 + 6] *
                    alpha[2]) + g_0[p1]) / 0.02989;
    b[p1] = (I_global[p1 + 3] * rtB.u[1] + I_global[p1] * rtB.u[0]) +
      I_global[p1 + 6] * rtB.u[2];
  }

  memcpy(&c_ct_0[0], &I_global[0], 9U * sizeof(real_T));
  p1 = 0;
  iEnd = 3;
  p3 = 6;
  ct = fabs(I_global[0]);
  st = fabs(I_global[1]);
  b_ct = fabs(I_global[2]);
  if ((st > ct) && (st > b_ct)) {
    p1 = 3;
    iEnd = 0;
    c_ct_0[0] = I_global[1];
    c_ct_0[1] = I_global[0];
    c_ct_0[3] = I_global[4];
    c_ct_0[4] = I_global[3];
    c_ct_0[6] = I_global[7];
    c_ct_0[7] = I_global[6];
  } else if (b_ct > ct) {
    p1 = 6;
    p3 = 0;
    c_ct_0[0] = I_global[2];
    c_ct_0[2] = I_global[0];
    c_ct_0[3] = I_global[5];
    c_ct_0[5] = I_global[3];
    c_ct_0[6] = I_global[8];
    c_ct_0[8] = I_global[6];
  }

  c_ct_0[1] /= c_ct_0[0];
  c_ct_0[2] /= c_ct_0[0];
  c_ct_0[4] -= c_ct_0[1] * c_ct_0[3];
  c_ct_0[5] -= c_ct_0[2] * c_ct_0[3];
  c_ct_0[7] -= c_ct_0[1] * c_ct_0[6];
  c_ct_0[8] -= c_ct_0[2] * c_ct_0[6];
  if (fabs(c_ct_0[5]) > fabs(c_ct_0[4])) {
    itmp = iEnd;
    iEnd = p3;
    p3 = itmp;
    ct = c_ct_0[1];
    c_ct_0[1] = c_ct_0[2];
    c_ct_0[2] = ct;
    ct = c_ct_0[4];
    c_ct_0[4] = c_ct_0[5];
    c_ct_0[5] = ct;
    ct = c_ct_0[7];
    c_ct_0[7] = c_ct_0[8];
    c_ct_0[8] = ct;
  }

  c_ct_0[5] /= c_ct_0[4];
  c_ct_0[8] -= c_ct_0[5] * c_ct_0[7];
  ct = (c_ct_0[1] * c_ct_0[5] - c_ct_0[2]) / c_ct_0[8];
  st = -(c_ct_0[7] * ct + c_ct_0[1]) / c_ct_0[4];
  I_global[p1] = ((1.0 - c_ct_0[3] * st) - c_ct_0[6] * ct) / c_ct_0[0];
  I_global[p1 + 1] = st;
  I_global[p1 + 2] = ct;
  ct = -c_ct_0[5] / c_ct_0[8];
  st = (1.0 - c_ct_0[7] * ct) / c_ct_0[4];
  I_global[iEnd] = -(c_ct_0[3] * st + c_ct_0[6] * ct) / c_ct_0[0];
  I_global[iEnd + 1] = st;
  I_global[iEnd + 2] = ct;
  ct = 1.0 / c_ct_0[8];
  st = -c_ct_0[7] * ct / c_ct_0[4];
  I_global[p3] = -(c_ct_0[3] * st + c_ct_0[6] * ct) / c_ct_0[0];
  I_global[p3 + 1] = st;
  I_global[p3 + 2] = ct;
  drone_simulation_3D_sum(c, alpha);
  tmp[0] = 0.0;
  tmp[1] = 0.0;
  tmp[2] = -rtb_motor_forces_tmp_0;
  tmp[3] = 0.0;
  tmp[4] = 0.0;
  tmp[6] = 0.0;
  tmp[7] = 0.0;
  tmp[8] = -rtb_motor_forces_tmp;
  tmp[9] = 0.0;
  tmp[10] = 0.0;
  drone_simulation_3D_sum(tmp, tmp_0);
  rtb_motor_forces_tmp_0 = alpha[0] + tmp_0[0];
  rtb_motor_forces_tmp = alpha[1] + tmp_0[1];
  ct = alpha[2] + tmp_0[2];
  alpha[0] = rtB.u[1] * b[2] - b[1] * rtB.u[2];
  alpha[1] = b[0] * rtB.u[2] - rtB.u[0] * b[2];
  alpha[2] = rtB.u[0] * b[1] - b[0] * rtB.u[1];
  for (p1 = 0; p1 <= 0; p1 += 2) {
    /* MATLAB Function: '<Root>/Drone dynamics' */
    tmp_4 = _mm_loadu_pd(&R[p1]);
    tmp_5 = _mm_loadu_pd(&R[p1 + 3]);
    tmp_6 = _mm_loadu_pd(&R[p1 + 6]);
    tmp_1 = _mm_loadu_pd(&alpha[p1]);
    _mm_storeu_pd(&b[p1], _mm_sub_pd(_mm_add_pd(_mm_mul_pd(tmp_6, _mm_set1_pd(ct)),
      _mm_add_pd(_mm_mul_pd(tmp_5, _mm_set1_pd(rtb_motor_forces_tmp)),
                 _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd(rtb_motor_forces_tmp_0)),
      _mm_set1_pd(0.0)))), tmp_1));
  }

  /* MATLAB Function: '<Root>/Drone dynamics' */
  for (p1 = 2; p1 < 3; p1++) {
    b[p1] = ((R[p1 + 3] * rtb_motor_forces_tmp + R[p1] * rtb_motor_forces_tmp_0)
             + R[p1 + 6] * ct) - alpha[p1];
  }

  for (p1 = 0; p1 <= 0; p1 += 2) {
    /* MATLAB Function: '<Root>/Drone dynamics' */
    tmp_4 = _mm_loadu_pd(&I_global[p1]);
    tmp_5 = _mm_loadu_pd(&I_global[p1 + 3]);
    tmp_6 = _mm_loadu_pd(&I_global[p1 + 6]);
    _mm_storeu_pd(&alpha[p1], _mm_add_pd(_mm_mul_pd(tmp_6, _mm_set1_pd(b[2])),
      _mm_add_pd(_mm_mul_pd(tmp_5, _mm_set1_pd(b[1])), _mm_add_pd(_mm_mul_pd
      (tmp_4, _mm_set1_pd(b[0])), _mm_set1_pd(0.0)))));
  }

  /* MATLAB Function: '<Root>/Drone dynamics' */
  for (p1 = 2; p1 < 3; p1++) {
    alpha[p1] = (I_global[p1 + 3] * b[1] + I_global[p1] * b[0]) + I_global[p1 +
      6] * b[2];
  }

  rtB.ang_acc[0] = alpha[0];
  rtB.ang_acc[1] = alpha[1];
  rtB.ang_acc[2] = alpha[2];
  rtB.lin_acc[0] = rtb_rpy[0];
  rtB.lin_acc[1] = rtb_rpy[1];
  rtB.lin_acc[2] = rtb_rpy[2];

  /* Integrator: '<Root>/ ' */
  if (ssIsModeUpdateTimeStep(rtS)) {
    if (rtDW._IWORK_n != 0) {
      rtX._CSTATE_c[0] = rtB.TmpSignalConversionAtInport2[0];
      rtX._CSTATE_c[1] = rtB.TmpSignalConversionAtInport2[1];
      rtX._CSTATE_c[2] = rtB.TmpSignalConversionAtInport2[2];
    }

    /* Integrator: '<Root>/ ' */
    rtB.u_l[0] = rtX._CSTATE_c[0];
    rtB.u_l[1] = rtX._CSTATE_c[1];
    rtB.u_l[2] = rtX._CSTATE_c[2];
  } else {
    /* Integrator: '<Root>/ ' */
    rtB.u_l[0] = rtX._CSTATE_c[0];
    rtB.u_l[1] = rtX._CSTATE_c[1];
    rtB.u_l[2] = rtX._CSTATE_c[2];
  }

  /* End of Integrator: '<Root>/ ' */
  /* ToWorkspace: '<Root>/To Workspace' */
  if (ssGetLogOutput(rtS)) {
    rt_UpdateLogVar((LogVar *)(LogVar*) (rtDW.ToWorkspace_PWORK.LoggedData),
                    &rtB.current_pos[0], 0);
  }

  /* ToWorkspace: '<Root>/To Workspace1' */
  if (ssGetLogOutput(rtS)) {
    rt_UpdateLogVar((LogVar *)(LogVar*) (rtDW.ToWorkspace1_PWORK.LoggedData),
                    &rtB.Integrator1[0], 0);
  }

  /* SignalConversion generated from: '<Root>/To Workspace2' */
  rtb_rpy[0] = rtb_x_ref;
  rtb_rpy[1] = rtb_y_ref;
  rtb_rpy[2] = rtb_z_ref;

  /* ToWorkspace: '<Root>/To Workspace2' */
  if (ssGetLogOutput(rtS)) {
    rt_UpdateLogVar((LogVar *)(LogVar*) (rtDW.ToWorkspace2_PWORK.LoggedData),
                    &rtb_rpy[0], 0);
  }

  /* Gain: '<S39>/Integral Gain' */
  rtB.IntegralGain = rtP.PIDController_I * rtB.Sum3;

  /* Gain: '<S87>/Integral Gain' */
  rtB.IntegralGain_j = rtP.PIDController1_I * rtB.Sum1;

  /* Gain: '<S135>/Integral Gain' */
  rtB.IntegralGain_k = rtP.PIDController2_I * rtB.Sum2;

  /* Gain: '<S183>/Integral Gain' */
  rtB.IntegralGain_i = rtP.PIDController3_I * rtB.Sum4;

  /* Gain: '<S231>/Integral Gain' */
  rtB.IntegralGain_b = rtP.PIDController4_I * rtB.Sum_pm;

  /* Gain: '<S279>/Integral Gain' */
  rtB.IntegralGain_kx = rtP.PIDController5_I * rtB.Sum5;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  /* Update for Integrator: '<Root>/  ' */
  rtDW._IWORK = 0;

  /* Update for Integrator: '<Root>/ ' */
  rtDW._IWORK_n = 0;
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) ssGetdX(rtS));

  /* Derivatives for Integrator: '<S138>/Integrator' */
  _rtXdot->Integrator_CSTATE = rtB.IntegralGain_k;

  /* Derivatives for Integrator: '<S133>/Filter' */
  _rtXdot->Filter_CSTATE = rtB.FilterCoefficient;

  /* Derivatives for Integrator: '<S186>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = rtB.IntegralGain_i;

  /* Derivatives for Integrator: '<S181>/Filter' */
  _rtXdot->Filter_CSTATE_m = rtB.FilterCoefficient_k;

  /* Derivatives for Integrator: '<S90>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = rtB.IntegralGain_j;

  /* Derivatives for Integrator: '<S85>/Filter' */
  _rtXdot->Filter_CSTATE_k = rtB.FilterCoefficient_a;

  /* Derivatives for Integrator: '<S42>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = rtB.IntegralGain;

  /* Derivatives for Integrator: '<S37>/Filter' */
  _rtXdot->Filter_CSTATE_i = rtB.FilterCoefficient_e;

  /* Derivatives for Integrator: '<S282>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = rtB.IntegralGain_kx;

  /* Derivatives for Integrator: '<S277>/Filter' */
  _rtXdot->Filter_CSTATE_c = rtB.FilterCoefficient_d;

  /* Derivatives for Integrator: '<S234>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = rtB.IntegralGain_b;

  /* Derivatives for Integrator: '<S229>/Filter' */
  _rtXdot->Filter_CSTATE_n = rtB.FilterCoefficient_ku;

  /* Derivatives for Integrator: '<Root>/Integrator2' incorporates:
   *  Integrator: '<Root>/ '
   */
  _rtXdot->Integrator2_CSTATE[0] = rtB.u_l[0];

  /* Derivatives for Integrator: '<Root>/Integrator1' incorporates:
   *  Integrator: '<Root>/  '
   */
  _rtXdot->Integrator1_CSTATE[0] = rtB.u[0];

  /* Derivatives for Integrator: '<Root>/  ' */
  _rtXdot->_CSTATE[0] = rtB.ang_acc[0];

  /* Derivatives for Integrator: '<Root>/ ' */
  _rtXdot->_CSTATE_c[0] = rtB.lin_acc[0];

  /* Derivatives for Integrator: '<Root>/Integrator2' incorporates:
   *  Integrator: '<Root>/ '
   */
  _rtXdot->Integrator2_CSTATE[1] = rtB.u_l[1];

  /* Derivatives for Integrator: '<Root>/Integrator1' incorporates:
   *  Integrator: '<Root>/  '
   */
  _rtXdot->Integrator1_CSTATE[1] = rtB.u[1];

  /* Derivatives for Integrator: '<Root>/  ' */
  _rtXdot->_CSTATE[1] = rtB.ang_acc[1];

  /* Derivatives for Integrator: '<Root>/ ' */
  _rtXdot->_CSTATE_c[1] = rtB.lin_acc[1];

  /* Derivatives for Integrator: '<Root>/Integrator2' incorporates:
   *  Integrator: '<Root>/ '
   */
  _rtXdot->Integrator2_CSTATE[2] = rtB.u_l[2];

  /* Derivatives for Integrator: '<Root>/Integrator1' incorporates:
   *  Integrator: '<Root>/  '
   */
  _rtXdot->Integrator1_CSTATE[2] = rtB.u[2];

  /* Derivatives for Integrator: '<Root>/  ' */
  _rtXdot->_CSTATE[2] = rtB.ang_acc[2];

  /* Derivatives for Integrator: '<Root>/ ' */
  _rtXdot->_CSTATE_c[2] = rtB.lin_acc[2];
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* ZeroCrossings for root system: '<Root>' */
void MdlZeroCrossings(void)
{
  ZCV *_rtZCSV;
  _rtZCSV = ((ZCV *) ssGetSolverZcSignalVector(rtS));

  /* ZeroCrossings for Saturate: '<S193>/Saturation' */
  _rtZCSV->Saturation_UprLim_ZC = rtB.Sum_o -
    rtP.PIDController3_UpperSaturationL;
  _rtZCSV->Saturation_LwrLim_ZC = rtB.Sum_o -
    rtP.PIDController3_LowerSaturationL;

  /* ZeroCrossings for Saturate: '<S49>/Saturation' */
  _rtZCSV->Saturation_UprLim_ZC_o = rtB.Sum_h -
    rtP.PIDController_UpperSaturationLi;
  _rtZCSV->Saturation_LwrLim_ZC_e = rtB.Sum_h -
    rtP.PIDController_LowerSaturationLi;

  /* ZeroCrossings for Saturate: '<S289>/Saturation' */
  _rtZCSV->Saturation_UprLim_ZC_p = rtB.Sum_e -
    rtP.PIDController5_UpperSaturationL;
  _rtZCSV->Saturation_LwrLim_ZC_d = rtB.Sum_e -
    rtP.PIDController5_LowerSaturationL;
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 24);         /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0); /* Number of periodic continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 0);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);      /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 86);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 66);            /* Number of block outputs */
  ssSetNumBlockParams(rtS, 58);        /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 1.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * drone_simulation_3D(void)
{
  static struct _ssMdlInfo mdlInfo;
  static struct _ssBlkInfo2 blkInfo2;
  static struct _ssBlkInfoSLSize blkInfoSLSize;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  (void) memset((char *)&blkInfo2, 0,
                sizeof(struct _ssBlkInfo2));
  (void) memset((char *)&blkInfoSLSize, 0,
                sizeof(struct _ssBlkInfoSLSize));
  ssSetBlkInfo2Ptr(rtS, &blkInfo2);
  ssSetBlkInfoSLSizePtr(rtS, &blkInfoSLSize);
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));
  }

  /* states (continuous)*/
  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x, 0,
                  sizeof(X));
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "drone_simulation_3D");
  ssSetPath(rtS, "drone_simulation_3D");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 51.0);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 4);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssPeriodicStatesInfo periodicStatesInfo;
    ssSetPeriodicStatesInfo(rtS, &periodicStatesInfo);
  }

  {
    static ssJacobianPerturbationBounds jacobianPerturbationBounds;
    ssSetJacobianPerturbationBounds(rtS, &jacobianPerturbationBounds);
  }

  {
    static ssSolverInfo slvrInfo;
    static boolean_T contStatesDisabled[24];
    static real_T absTol[24] = { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6,
      1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6,
      1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6 };

    static uint8_T absTolControl[24] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U };

    static real_T contStateJacPerturbBoundMinVec[24];
    static real_T contStateJacPerturbBoundMaxVec[24];
    static uint8_T zcAttributes[6] = { (ZC_EVENT_ALL), (ZC_EVENT_ALL),
      (ZC_EVENT_ALL), (ZC_EVENT_ALL), (ZC_EVENT_ALL), (ZC_EVENT_ALL) };

    /* Initialize cont state perturbation bound */
    {
      int i;
      for (i = 0; i < 24; ++i) {
        contStateJacPerturbBoundMinVec[i] = 0;
        contStateJacPerturbBoundMaxVec[i] = rtGetInf();
      }
    }

    ssSetSolverRelTol(rtS, 0.001);
    ssSetStepSize(rtS, 0.0);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 1.02);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 0);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 0);
    ssSetNonContDerivSigInfos(rtS, (NULL));
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "VariableStepAuto");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetAbsTolVector(rtS, absTol);
    ssSetAbsTolControlVector(rtS, absTolControl);
    ssSetSolverAbsTol_Obsolete(rtS, absTol);
    ssSetSolverAbsTolControl_Obsolete(rtS, absTolControl);
    ssSetJacobianPerturbationBoundsMinVec(rtS, contStateJacPerturbBoundMinVec);
    ssSetJacobianPerturbationBoundsMaxVec(rtS, contStateJacPerturbBoundMaxVec);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelLogDataIfInInterval(rtS, rt_UpdateTXXFYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetModelDerivatives(rtS, MdlDerivatives);
    ssSetSolverZcSignalAttrib(rtS, zcAttributes);
    ssSetSolverNumZcSignals(rtS, 6);
    ssSetModelZeroCrossings(rtS, MdlZeroCrossings);
    ssSetSolverConsecutiveZCsStepRelTol(rtS, 2.8421709430404007E-13);
    ssSetSolverMaxConsecutiveZCs(rtS, 1000);
    ssSetSolverConsecutiveZCsError(rtS, 2);
    ssSetSolverMaskedZcDiagnostic(rtS, 1);
    ssSetSolverIgnoredZcDiagnostic(rtS, 1);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
    ssSetSolverShapePreserveControl(rtS, 2);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 6);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 344102616U);
  ssSetChecksumVal(rtS, 1, 268445277U);
  ssSetChecksumVal(rtS, 2, 270014698U);
  ssSetChecksumVal(rtS, 3, 1195129220U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
