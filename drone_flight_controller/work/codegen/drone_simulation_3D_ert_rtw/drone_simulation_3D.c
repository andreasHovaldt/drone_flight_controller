/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: drone_simulation_3D.c
 *
 * Code generated for Simulink model 'drone_simulation_3D'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Apr 12 14:45:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "drone_simulation_3D.h"
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
#include <string.h>

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Continuous states */
X rtX;

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* private model entry point functions */
extern void drone_simulation_3D_derivatives(void);

/* Forward declaration for local functions */
static void sum(const real_T x[12], real_T y[3]);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 24;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  drone_simulation_3D_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  drone_simulation_3D_step();
  drone_simulation_3D_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  drone_simulation_3D_step();
  drone_simulation_3D_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<Root>/Drone dynamics' */
static void sum(const real_T x[12], real_T y[3])
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

/* Model step function */
void drone_simulation_3D_step(void)
{
  real_T c[12];
  real_T local_motor_forces[12];
  real_T I_global[9];
  real_T R[9];
  real_T a[3];
  real_T alpha[3];
  real_T b[3];
  real_T b_ct;
  real_T c_st;
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
  real_T c_ct[9];
  real_T tmp_0[3];
  real_T rtb_Clock1;
  real_T rtb_Sum;
  real_T rtb_Sum1;
  real_T rtb_Sum2;
  real_T rtb_Sum3;
  real_T rtb_Sum4;
  real_T rtb_motor_forces_idx_0;
  real_T rtb_motor_forces_idx_2;
  real_T rtb_rpy_idx_0;
  real_T rtb_rpy_idx_1;
  real_T rtb_rpy_idx_2;
  static const int8_T f[3] = { 0, 0, 1 };

  static const real_T c_b[9] = { 1.132869584E-5, 0.0, 0.0, 0.0, 1.132869584E-5,
    0.0, 0.0, 0.0, 2.028869584E-5 };

  static const real_T h_0[12] = { 0.028284271247461905, 0.028284271247461898,
    0.0, 0.028284271247461905, -0.028284271247461898, 0.0, -0.028284271247461905,
    -0.028284271247461898, 0.0, -0.028284271247461905, 0.028284271247461898, 0.0
  };

  static const real_T g_0[3] = { 0.0, 0.0, -0.2935198 };

  __m128d tmp_6;
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  /* Clock: '<Root>/Clock1' */
  rtb_Clock1 = rtM->Timing.t[0];

  /* Sum: '<S3>/Sum2' incorporates:
   *  Integrator: '<Root>/Integrator2'
   *  Sin: '<Root>/y_ref'
   */
  rtb_Sum2 = sin(0.3 * rtb_Clock1) * 0.4 - rtX.Integrator2_CSTATE[1];

  /* Gain: '<S141>/Filter Coefficient' incorporates:
   *  Gain: '<S132>/Derivative Gain'
   *  Integrator: '<S133>/Filter'
   *  Sum: '<S133>/SumD'
   */
  rtDW.FilterCoefficient = (-9.87787035201578 * rtb_Sum2 - rtX.Filter_CSTATE) *
    11428.279760416;

  /* Sum: '<S3>/Sum4' incorporates:
   *  Gain: '<S143>/Proportional Gain'
   *  Integrator: '<Root>/Integrator1'
   *  Integrator: '<S138>/Integrator'
   *  Sum: '<S147>/Sum'
   */
  rtb_Sum4 = ((-25.9360289201711 * rtb_Sum2 + rtX.Integrator_CSTATE) +
              rtDW.FilterCoefficient) - rtX.Integrator1_CSTATE[0];

  /* Gain: '<S189>/Filter Coefficient' incorporates:
   *  Gain: '<S180>/Derivative Gain'
   *  Integrator: '<S181>/Filter'
   *  Sum: '<S181>/SumD'
   */
  rtDW.FilterCoefficient_k = (0.100094141409862 * rtb_Sum4 - rtX.Filter_CSTATE_m)
    * 114282.79760416;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Integrator: '<Root>/Integrator2'
   *  Sin: '<Root>/x_ref'
   */
  rtb_Sum1 = sin(0.5 * rtb_Clock1) * 0.5 - rtX.Integrator2_CSTATE[0];

  /* Gain: '<S93>/Filter Coefficient' incorporates:
   *  Gain: '<S84>/Derivative Gain'
   *  Integrator: '<S85>/Filter'
   *  Sum: '<S85>/SumD'
   */
  rtDW.FilterCoefficient_a = (9.87787035201578 * rtb_Sum1 - rtX.Filter_CSTATE_k)
    * 11428.279760416;

  /* Sum: '<S3>/Sum3' incorporates:
   *  Gain: '<S95>/Proportional Gain'
   *  Integrator: '<Root>/Integrator1'
   *  Integrator: '<S90>/Integrator'
   *  Sum: '<S99>/Sum'
   */
  rtb_Sum3 = ((25.9360289201711 * rtb_Sum1 + rtX.Integrator_CSTATE_e) +
              rtDW.FilterCoefficient_a) - rtX.Integrator1_CSTATE[1];

  /* Gain: '<S45>/Filter Coefficient' incorporates:
   *  Gain: '<S36>/Derivative Gain'
   *  Integrator: '<S37>/Filter'
   *  Sum: '<S37>/SumD'
   */
  rtDW.FilterCoefficient_e = (0.100094141408081 * rtb_Sum3 - rtX.Filter_CSTATE_i)
    * 114282.79760416;

  /* Gain: '<S285>/Filter Coefficient' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S276>/Derivative Gain'
   *  Integrator: '<Root>/Integrator1'
   *  Integrator: '<S277>/Filter'
   *  Sum: '<S277>/SumD'
   *  Sum: '<S3>/Sum5'
   */
  rtDW.FilterCoefficient_d = ((0.0 - rtX.Integrator1_CSTATE[2]) *
    0.00419193318594241 - rtX.Filter_CSTATE_c) * 1142.8279760416;

  /* Sum: '<S195>/Sum' incorporates:
   *  Gain: '<S191>/Proportional Gain'
   *  Integrator: '<S186>/Integrator'
   */
  rtb_rpy_idx_0 = (2.6281419514846 * rtb_Sum4 + rtX.Integrator_CSTATE_b) +
    rtDW.FilterCoefficient_k;

  /* Saturate: '<S193>/Saturation' */
  if (rtb_rpy_idx_0 > 1.0471975511965976) {
    /* MATLAB Function: '<S3>/MATLAB Function' */
    rtb_rpy_idx_0 = 1.0471975511965976;
  } else if (rtb_rpy_idx_0 < -1.0471975511965976) {
    /* MATLAB Function: '<S3>/MATLAB Function' */
    rtb_rpy_idx_0 = -1.0471975511965976;
  }

  /* End of Saturate: '<S193>/Saturation' */

  /* Sum: '<S51>/Sum' incorporates:
   *  Gain: '<S47>/Proportional Gain'
   *  Integrator: '<S42>/Integrator'
   */
  rtb_rpy_idx_1 = (2.62814195143783 * rtb_Sum3 + rtX.Integrator_CSTATE_f) +
    rtDW.FilterCoefficient_e;

  /* Saturate: '<S49>/Saturation' */
  if (rtb_rpy_idx_1 > 1.0471975511965976) {
    /* MATLAB Function: '<S3>/MATLAB Function' */
    rtb_rpy_idx_1 = 1.0471975511965976;
  } else if (rtb_rpy_idx_1 < -1.0471975511965976) {
    /* MATLAB Function: '<S3>/MATLAB Function' */
    rtb_rpy_idx_1 = -1.0471975511965976;
  }

  /* End of Saturate: '<S49>/Saturation' */

  /* Sum: '<S291>/Sum' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S287>/Proportional Gain'
   *  Integrator: '<Root>/Integrator1'
   *  Integrator: '<S282>/Integrator'
   *  Sum: '<S3>/Sum5'
   */
  rtb_rpy_idx_2 = ((0.0 - rtX.Integrator1_CSTATE[2]) * 0.00110066336636865 +
                   rtX.Integrator_CSTATE_h) + rtDW.FilterCoefficient_d;

  /* Saturate: '<S289>/Saturation' */
  if (rtb_rpy_idx_2 > 0.1) {
    /* MATLAB Function: '<S3>/MATLAB Function' */
    rtb_rpy_idx_2 = 0.1;
  } else if (rtb_rpy_idx_2 < -0.1) {
    /* MATLAB Function: '<S3>/MATLAB Function' */
    rtb_rpy_idx_2 = -0.1;
  }

  /* End of Saturate: '<S289>/Saturation' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Integrator: '<Root>/Integrator2'
   *  Sin: '<Root>/z_ref'
   */
  rtb_Clock1 = sin(0.4 * rtb_Clock1) * 0.8 - rtX.Integrator2_CSTATE[2];

  /* Gain: '<S237>/Filter Coefficient' incorporates:
   *  Gain: '<S228>/Derivative Gain'
   *  Integrator: '<S229>/Filter'
   *  Sum: '<S229>/SumD'
   */
  rtDW.FilterCoefficient_ku = (0.746963963799893 * rtb_Clock1 -
    rtX.Filter_CSTATE_n) * 11428.279760416;

  /* Sum: '<S243>/Sum' incorporates:
   *  Gain: '<S239>/Proportional Gain'
   *  Integrator: '<S234>/Integrator'
   */
  rtb_Sum = (1.96128095197019 * rtb_Clock1 + rtX.Integrator_CSTATE_i) +
    rtDW.FilterCoefficient_ku;

  /* MATLAB Function: '<Root>/Motor mixing algorithm' */
  b_ct = rtb_Sum + rtb_rpy_idx_0;
  rtb_motor_forces_idx_0 = (b_ct - rtb_rpy_idx_1) - rtb_rpy_idx_2;
  rtb_Sum -= rtb_rpy_idx_0;
  rtb_rpy_idx_0 = (rtb_Sum - rtb_rpy_idx_1) + rtb_rpy_idx_2;
  rtb_motor_forces_idx_2 = (rtb_Sum + rtb_rpy_idx_1) - rtb_rpy_idx_2;
  rtb_rpy_idx_1 = (b_ct + rtb_rpy_idx_1) + rtb_rpy_idx_2;

  /* Integrator: '<Root>/  ' */
  if (rtDW._IWORK != 0) {
    rtX._CSTATE[0] = 0.0;
    rtX._CSTATE[1] = 0.0;
    rtX._CSTATE[2] = 0.0;
  }

  /* Integrator: '<Root>/  ' */
  rtDW.u[0] = rtX._CSTATE[0];
  rtDW.u[1] = rtX._CSTATE[1];
  rtDW.u[2] = rtX._CSTATE[2];

  /* MATLAB Function: '<Root>/Drone dynamics' incorporates:
   *  Integrator: '<Root>/Integrator1'
   */
  local_motor_forces[0] = 0.0;
  local_motor_forces[1] = 0.0;
  local_motor_forces[2] = rtb_motor_forces_idx_0;
  local_motor_forces[3] = 0.0;
  local_motor_forces[4] = 0.0;
  local_motor_forces[5] = rtb_rpy_idx_0;
  local_motor_forces[6] = 0.0;
  local_motor_forces[7] = 0.0;
  local_motor_forces[8] = rtb_motor_forces_idx_2;
  local_motor_forces[9] = 0.0;
  local_motor_forces[10] = 0.0;
  local_motor_forces[11] = rtb_rpy_idx_1;
  if (rtb_motor_forces_idx_0 < 0.00013) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = (sqrt(1.0703800000000001E+15 * rtb_motor_forces_idx_0 -
                    1.373657841E+11) * 0.001868495301 + 966.0550459) * 0.1047198;
    rtb_Sum = rtb_Sum * rtb_Sum * 5.6217590777380778E-10;
  }

  if (rtb_rpy_idx_0 < 0.00013) {
    tmp[5] = 0.0;
  } else {
    rtb_motor_forces_idx_0 = (sqrt(1.0703800000000001E+15 * rtb_rpy_idx_0 -
      1.373657841E+11) * 0.001868495301 + 966.0550459) * 0.1047198;
    tmp[5] = rtb_motor_forces_idx_0 * rtb_motor_forces_idx_0 *
      5.6217590777380778E-10;
  }

  if (rtb_motor_forces_idx_2 < 0.00013) {
    rtb_motor_forces_idx_0 = 0.0;
  } else {
    rtb_motor_forces_idx_0 = (sqrt(1.0703800000000001E+15 *
      rtb_motor_forces_idx_2 - 1.373657841E+11) * 0.001868495301 + 966.0550459) *
      0.1047198;
    rtb_motor_forces_idx_0 = rtb_motor_forces_idx_0 * rtb_motor_forces_idx_0 *
      5.6217590777380778E-10;
  }

  if (rtb_rpy_idx_1 < 0.00013) {
    tmp[11] = 0.0;
  } else {
    rtb_rpy_idx_1 = (sqrt(1.0703800000000001E+15 * rtb_rpy_idx_1 -
                          1.373657841E+11) * 0.001868495301 + 966.0550459) *
      0.1047198;
    tmp[11] = rtb_rpy_idx_1 * rtb_rpy_idx_1 * 5.6217590777380778E-10;
  }

  rtb_rpy_idx_1 = cos(rtX.Integrator1_CSTATE[0]);
  rtb_rpy_idx_2 = sin(rtX.Integrator1_CSTATE[0]);
  if (fabs(rtb_rpy_idx_2) < 2.2204460492503131E-16) {
    rtb_rpy_idx_2 = 0.0;
  }

  if (fabs(rtb_rpy_idx_1) < 2.2204460492503131E-16) {
    rtb_rpy_idx_1 = 0.0;
  }

  b_ct = cos(rtX.Integrator1_CSTATE[1]);
  rtb_rpy_idx_0 = sin(rtX.Integrator1_CSTATE[1]);
  if (fabs(rtb_rpy_idx_0) < 2.2204460492503131E-16) {
    rtb_rpy_idx_0 = 0.0;
  }

  if (fabs(b_ct) < 2.2204460492503131E-16) {
    b_ct = 0.0;
  }

  rtb_motor_forces_idx_2 = cos(rtX.Integrator1_CSTATE[2]);
  c_st = sin(rtX.Integrator1_CSTATE[2]);
  if (fabs(c_st) < 2.2204460492503131E-16) {
    c_st = 0.0;
  }

  if (fabs(rtb_motor_forces_idx_2) < 2.2204460492503131E-16) {
    rtb_motor_forces_idx_2 = 0.0;
  }

  R[1] = 0.0;
  R[4] = rtb_rpy_idx_1;
  R[7] = -rtb_rpy_idx_2;
  R[2] = 0.0;
  R[5] = rtb_rpy_idx_2;
  R[8] = rtb_rpy_idx_1;
  b_ct_0[0] = b_ct;
  b_ct_0[3] = 0.0;
  b_ct_0[6] = rtb_rpy_idx_0;
  R[0] = 1.0;
  b_ct_0[1] = 0.0;
  R[3] = 0.0;
  b_ct_0[4] = 1.0;
  R[6] = 0.0;
  b_ct_0[7] = 0.0;
  b_ct_0[2] = -rtb_rpy_idx_0;
  b_ct_0[5] = 0.0;
  b_ct_0[8] = b_ct;
  c_ct[0] = rtb_motor_forces_idx_2;
  c_ct[3] = -c_st;
  c_ct[6] = 0.0;
  c_ct[1] = c_st;
  c_ct[4] = rtb_motor_forces_idx_2;
  c_ct[7] = 0.0;
  for (p1 = 0; p1 < 3; p1++) {
    for (p3 = 0; p3 < 3; p3++) {
      iEnd = 3 * p3 + p1;
      I_global[iEnd] = 0.0;
      I_global[iEnd] += b_ct_0[3 * p3] * R[p1];
      I_global[iEnd] += b_ct_0[3 * p3 + 1] * R[p1 + 3];
      I_global[iEnd] += b_ct_0[3 * p3 + 2] * R[p1 + 6];
    }

    c_ct[3 * p1 + 2] = f[p1];
  }

  for (p1 = 0; p1 < 3; p1++) {
    for (p3 = 0; p3 < 3; p3++) {
      iEnd = 3 * p3 + p1;
      R[iEnd] = 0.0;
      R[iEnd] += c_ct[3 * p3] * I_global[p1];
      R[iEnd] += c_ct[3 * p3 + 1] * I_global[p1 + 3];
      R[iEnd] += c_ct[3 * p3 + 2] * I_global[p1 + 6];
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
      rtb_rpy_idx_1 = h_0[p3 + 1];
      rtb_rpy_idx_2 = local_motor_forces[p3 + 1];
      c[p3 - 1] = rtb_rpy_idx_2 * h_0[p3] - rtb_rpy_idx_1 *
        local_motor_forces[p3];
      b_ct = h_0[p3 - 1];
      rtb_rpy_idx_0 = local_motor_forces[p3 - 1];
      c[p3] = rtb_rpy_idx_1 * rtb_rpy_idx_0 - b_ct * rtb_rpy_idx_2;
      c[p3 + 1] = b_ct * local_motor_forces[p3] - rtb_rpy_idx_0 * h_0[p3];
    }
  }

  sum(local_motor_forces, alpha);
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
    _mm_storeu_pd(&a[p1], _mm_div_pd(_mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
      (tmp_1, _mm_set1_pd(alpha[1])), _mm_mul_pd(tmp_2, _mm_set1_pd(alpha[0]))),
      _mm_mul_pd(tmp_3, _mm_set1_pd(alpha[2]))), _mm_loadu_pd(&g[p1])),
      _mm_set1_pd(0.02989)));
    _mm_storeu_pd(&b[p1], _mm_add_pd(_mm_mul_pd(tmp_6, _mm_set1_pd(rtDW.u[2])),
      _mm_add_pd(_mm_mul_pd(tmp_5, _mm_set1_pd(rtDW.u[1])), _mm_add_pd
                 (_mm_mul_pd(tmp_4, _mm_set1_pd(rtDW.u[0])), _mm_set1_pd(0.0)))));
  }

  /* MATLAB Function: '<Root>/Drone dynamics' */
  for (p1 = 2; p1 < 3; p1++) {
    a[p1] = (((R[p1 + 3] * alpha[1] + R[p1] * alpha[0]) + R[p1 + 6] * alpha[2])
             + g_0[p1]) / 0.02989;
    b[p1] = (I_global[p1 + 3] * rtDW.u[1] + I_global[p1] * rtDW.u[0]) +
      I_global[p1 + 6] * rtDW.u[2];
  }

  memcpy(&c_ct[0], &I_global[0], 9U * sizeof(real_T));
  p1 = 0;
  iEnd = 3;
  p3 = 6;
  rtb_rpy_idx_1 = fabs(I_global[0]);
  rtb_rpy_idx_2 = fabs(I_global[1]);
  b_ct = fabs(I_global[2]);
  if ((rtb_rpy_idx_2 > rtb_rpy_idx_1) && (rtb_rpy_idx_2 > b_ct)) {
    p1 = 3;
    iEnd = 0;
    c_ct[0] = I_global[1];
    c_ct[1] = I_global[0];
    c_ct[3] = I_global[4];
    c_ct[4] = I_global[3];
    c_ct[6] = I_global[7];
    c_ct[7] = I_global[6];
  } else if (b_ct > rtb_rpy_idx_1) {
    p1 = 6;
    p3 = 0;
    c_ct[0] = I_global[2];
    c_ct[2] = I_global[0];
    c_ct[3] = I_global[5];
    c_ct[5] = I_global[3];
    c_ct[6] = I_global[8];
    c_ct[8] = I_global[6];
  }

  c_ct[1] /= c_ct[0];
  c_ct[2] /= c_ct[0];
  c_ct[4] -= c_ct[1] * c_ct[3];
  c_ct[5] -= c_ct[2] * c_ct[3];
  c_ct[7] -= c_ct[1] * c_ct[6];
  c_ct[8] -= c_ct[2] * c_ct[6];
  if (fabs(c_ct[5]) > fabs(c_ct[4])) {
    itmp = iEnd;
    iEnd = p3;
    p3 = itmp;
    rtb_rpy_idx_1 = c_ct[1];
    c_ct[1] = c_ct[2];
    c_ct[2] = rtb_rpy_idx_1;
    rtb_rpy_idx_1 = c_ct[4];
    c_ct[4] = c_ct[5];
    c_ct[5] = rtb_rpy_idx_1;
    rtb_rpy_idx_1 = c_ct[7];
    c_ct[7] = c_ct[8];
    c_ct[8] = rtb_rpy_idx_1;
  }

  c_ct[5] /= c_ct[4];
  c_ct[8] -= c_ct[5] * c_ct[7];
  rtb_rpy_idx_1 = (c_ct[1] * c_ct[5] - c_ct[2]) / c_ct[8];
  rtb_rpy_idx_2 = -(c_ct[7] * rtb_rpy_idx_1 + c_ct[1]) / c_ct[4];
  I_global[p1] = ((1.0 - c_ct[3] * rtb_rpy_idx_2) - c_ct[6] * rtb_rpy_idx_1) /
    c_ct[0];
  I_global[p1 + 1] = rtb_rpy_idx_2;
  I_global[p1 + 2] = rtb_rpy_idx_1;
  rtb_rpy_idx_1 = -c_ct[5] / c_ct[8];
  rtb_rpy_idx_2 = (1.0 - c_ct[7] * rtb_rpy_idx_1) / c_ct[4];
  I_global[iEnd] = -(c_ct[3] * rtb_rpy_idx_2 + c_ct[6] * rtb_rpy_idx_1) / c_ct[0];
  I_global[iEnd + 1] = rtb_rpy_idx_2;
  I_global[iEnd + 2] = rtb_rpy_idx_1;
  rtb_rpy_idx_1 = 1.0 / c_ct[8];
  rtb_rpy_idx_2 = -c_ct[7] * rtb_rpy_idx_1 / c_ct[4];
  I_global[p3] = -(c_ct[3] * rtb_rpy_idx_2 + c_ct[6] * rtb_rpy_idx_1) / c_ct[0];
  I_global[p3 + 1] = rtb_rpy_idx_2;
  I_global[p3 + 2] = rtb_rpy_idx_1;
  sum(c, alpha);
  tmp[0] = 0.0;
  tmp[1] = 0.0;
  tmp[2] = -rtb_Sum;
  tmp[3] = 0.0;
  tmp[4] = 0.0;
  tmp[6] = 0.0;
  tmp[7] = 0.0;
  tmp[8] = -rtb_motor_forces_idx_0;
  tmp[9] = 0.0;
  tmp[10] = 0.0;
  sum(tmp, tmp_0);
  rtb_Sum = alpha[0] + tmp_0[0];
  rtb_motor_forces_idx_0 = alpha[1] + tmp_0[1];
  rtb_rpy_idx_1 = alpha[2] + tmp_0[2];
  alpha[0] = rtDW.u[1] * b[2] - b[1] * rtDW.u[2];
  alpha[1] = b[0] * rtDW.u[2] - rtDW.u[0] * b[2];
  alpha[2] = rtDW.u[0] * b[1] - b[0] * rtDW.u[1];
  for (p1 = 0; p1 <= 0; p1 += 2) {
    /* MATLAB Function: '<Root>/Drone dynamics' */
    tmp_4 = _mm_loadu_pd(&R[p1]);
    tmp_5 = _mm_loadu_pd(&R[p1 + 3]);
    tmp_6 = _mm_loadu_pd(&R[p1 + 6]);
    tmp_1 = _mm_loadu_pd(&alpha[p1]);
    _mm_storeu_pd(&b[p1], _mm_sub_pd(_mm_add_pd(_mm_mul_pd(tmp_6, _mm_set1_pd
      (rtb_rpy_idx_1)), _mm_add_pd(_mm_mul_pd(tmp_5, _mm_set1_pd
      (rtb_motor_forces_idx_0)), _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd
      (rtb_Sum)), _mm_set1_pd(0.0)))), tmp_1));
  }

  /* MATLAB Function: '<Root>/Drone dynamics' */
  for (p1 = 2; p1 < 3; p1++) {
    b[p1] = ((R[p1 + 3] * rtb_motor_forces_idx_0 + R[p1] * rtb_Sum) + R[p1 + 6] *
             rtb_rpy_idx_1) - alpha[p1];
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

  rtDW.ang_acc[0] = alpha[0];
  rtDW.ang_acc[1] = alpha[1];
  rtDW.ang_acc[2] = alpha[2];
  rtDW.lin_acc[0] = a[0];
  rtDW.lin_acc[1] = a[1];
  rtDW.lin_acc[2] = a[2];

  /* Integrator: '<Root>/ ' */
  if (rtDW._IWORK_n != 0) {
    rtX._CSTATE_c[0] = 0.0;
    rtX._CSTATE_c[1] = 0.0;
    rtX._CSTATE_c[2] = 0.0;
  }

  /* Integrator: '<Root>/ ' */
  rtDW.u_l[0] = rtX._CSTATE_c[0];
  rtDW.u_l[1] = rtX._CSTATE_c[1];
  rtDW.u_l[2] = rtX._CSTATE_c[2];

  /* Gain: '<S231>/Integral Gain' */
  rtDW.IntegralGain = 1.14419736118138 * rtb_Clock1;

  /* Gain: '<S279>/Integral Gain' incorporates:
   *  Constant: '<S3>/Constant'
   *  Integrator: '<Root>/Integrator1'
   *  Sum: '<S3>/Sum5'
   */
  rtDW.IntegralGain_k = (0.0 - rtX.Integrator1_CSTATE[2]) * 6.42119181386494E-5;

  /* Gain: '<S39>/Integral Gain' */
  rtDW.IntegralGain_m = 15.3323932638233 * rtb_Sum3;

  /* Gain: '<S87>/Integral Gain' */
  rtDW.IntegralGain_j = 15.1308948471523 * rtb_Sum1;

  /* Gain: '<S183>/Integral Gain' */
  rtDW.IntegralGain_i = 15.3323932640961 * rtb_Sum4;

  /* Gain: '<S135>/Integral Gain' */
  rtDW.IntegralGain_kv = -15.1308948471523 * rtb_Sum2;
  if (rtmIsMajorTimeStep(rtM)) {
    /* Update for Integrator: '<Root>/  ' */
    rtDW._IWORK = 0;

    /* Update for Integrator: '<Root>/ ' */
    rtDW._IWORK_n = 0;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void drone_simulation_3D_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for Integrator: '<S138>/Integrator' */
  _rtXdot->Integrator_CSTATE = rtDW.IntegralGain_kv;

  /* Derivatives for Integrator: '<S133>/Filter' */
  _rtXdot->Filter_CSTATE = rtDW.FilterCoefficient;

  /* Derivatives for Integrator: '<S186>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = rtDW.IntegralGain_i;

  /* Derivatives for Integrator: '<S181>/Filter' */
  _rtXdot->Filter_CSTATE_m = rtDW.FilterCoefficient_k;

  /* Derivatives for Integrator: '<S90>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = rtDW.IntegralGain_j;

  /* Derivatives for Integrator: '<S85>/Filter' */
  _rtXdot->Filter_CSTATE_k = rtDW.FilterCoefficient_a;

  /* Derivatives for Integrator: '<S42>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = rtDW.IntegralGain_m;

  /* Derivatives for Integrator: '<S37>/Filter' */
  _rtXdot->Filter_CSTATE_i = rtDW.FilterCoefficient_e;

  /* Derivatives for Integrator: '<S282>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = rtDW.IntegralGain_k;

  /* Derivatives for Integrator: '<S277>/Filter' */
  _rtXdot->Filter_CSTATE_c = rtDW.FilterCoefficient_d;

  /* Derivatives for Integrator: '<S234>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = rtDW.IntegralGain;

  /* Derivatives for Integrator: '<S229>/Filter' */
  _rtXdot->Filter_CSTATE_n = rtDW.FilterCoefficient_ku;

  /* Derivatives for Integrator: '<Root>/Integrator1' incorporates:
   *  Integrator: '<Root>/  '
   */
  _rtXdot->Integrator1_CSTATE[0] = rtDW.u[0];

  /* Derivatives for Integrator: '<Root>/Integrator2' incorporates:
   *  Integrator: '<Root>/ '
   */
  _rtXdot->Integrator2_CSTATE[0] = rtDW.u_l[0];

  /* Derivatives for Integrator: '<Root>/  ' */
  _rtXdot->_CSTATE[0] = rtDW.ang_acc[0];

  /* Derivatives for Integrator: '<Root>/ ' */
  _rtXdot->_CSTATE_c[0] = rtDW.lin_acc[0];

  /* Derivatives for Integrator: '<Root>/Integrator1' incorporates:
   *  Integrator: '<Root>/  '
   */
  _rtXdot->Integrator1_CSTATE[1] = rtDW.u[1];

  /* Derivatives for Integrator: '<Root>/Integrator2' incorporates:
   *  Integrator: '<Root>/ '
   */
  _rtXdot->Integrator2_CSTATE[1] = rtDW.u_l[1];

  /* Derivatives for Integrator: '<Root>/  ' */
  _rtXdot->_CSTATE[1] = rtDW.ang_acc[1];

  /* Derivatives for Integrator: '<Root>/ ' */
  _rtXdot->_CSTATE_c[1] = rtDW.lin_acc[1];

  /* Derivatives for Integrator: '<Root>/Integrator1' incorporates:
   *  Integrator: '<Root>/  '
   */
  _rtXdot->Integrator1_CSTATE[2] = rtDW.u[2];

  /* Derivatives for Integrator: '<Root>/Integrator2' incorporates:
   *  Integrator: '<Root>/ '
   */
  _rtXdot->Integrator2_CSTATE[2] = rtDW.u_l[2];

  /* Derivatives for Integrator: '<Root>/  ' */
  _rtXdot->_CSTATE[2] = rtDW.ang_acc[2];

  /* Derivatives for Integrator: '<Root>/ ' */
  _rtXdot->_CSTATE_c[2] = rtDW.lin_acc[2];
}

/* Model initialize function */
void drone_simulation_3D_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&rtM->solverInfo, false);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.01;
  rtmSetFirstInitCond(rtM, 1);

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[2] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE[2] = 0.0;

  /* InitializeConditions for Integrator: '<S138>/Integrator' */
  rtX.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S133>/Filter' */
  rtX.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S186>/Integrator' */
  rtX.Integrator_CSTATE_b = 0.0;

  /* InitializeConditions for Integrator: '<S181>/Filter' */
  rtX.Filter_CSTATE_m = 0.0;

  /* InitializeConditions for Integrator: '<S90>/Integrator' */
  rtX.Integrator_CSTATE_e = 0.0;

  /* InitializeConditions for Integrator: '<S85>/Filter' */
  rtX.Filter_CSTATE_k = 0.0;

  /* InitializeConditions for Integrator: '<S42>/Integrator' */
  rtX.Integrator_CSTATE_f = 0.0;

  /* InitializeConditions for Integrator: '<S37>/Filter' */
  rtX.Filter_CSTATE_i = 0.0;

  /* InitializeConditions for Integrator: '<S282>/Integrator' */
  rtX.Integrator_CSTATE_h = 0.0;

  /* InitializeConditions for Integrator: '<S277>/Filter' */
  rtX.Filter_CSTATE_c = 0.0;

  /* InitializeConditions for Integrator: '<S234>/Integrator' */
  rtX.Integrator_CSTATE_i = 0.0;

  /* InitializeConditions for Integrator: '<S229>/Filter' */
  rtX.Filter_CSTATE_n = 0.0;

  /* InitializeConditions for Integrator: '<Root>/  ' incorporates:
   *  Integrator: '<Root>/ '
   */
  if (rtmIsFirstInitCond(rtM)) {
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

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(rtM)) {
    rtmSetFirstInitCond(rtM, 0);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
