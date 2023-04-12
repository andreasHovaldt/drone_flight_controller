/*
 * drone_simulation_3D_data.c
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

/* Block parameters (default storage) */
P rtP = {
  /* Mask Parameter: PIDController2_D
   * Referenced by: '<S132>/Derivative Gain'
   */
  -9.87787035201578,

  /* Mask Parameter: PIDController3_D
   * Referenced by: '<S180>/Derivative Gain'
   */
  0.100094141409862,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S84>/Derivative Gain'
   */
  9.87787035201578,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S36>/Derivative Gain'
   */
  0.100094141408081,

  /* Mask Parameter: PIDController5_D
   * Referenced by: '<S276>/Derivative Gain'
   */
  0.00419193318594241,

  /* Mask Parameter: PIDController4_D
   * Referenced by: '<S228>/Derivative Gain'
   */
  0.746963963799893,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S39>/Integral Gain'
   */
  15.3323932638233,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S87>/Integral Gain'
   */
  15.1308948471523,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S135>/Integral Gain'
   */
  -15.1308948471523,

  /* Mask Parameter: PIDController3_I
   * Referenced by: '<S183>/Integral Gain'
   */
  15.3323932640961,

  /* Mask Parameter: PIDController4_I
   * Referenced by: '<S231>/Integral Gain'
   */
  1.14419736118138,

  /* Mask Parameter: PIDController5_I
   * Referenced by: '<S279>/Integral Gain'
   */
  6.42119181386494E-5,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S133>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController3_InitialCondition
   * Referenced by: '<S181>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S85>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S37>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController5_InitialCondition
   * Referenced by: '<S277>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController4_InitialCondition
   * Referenced by: '<S229>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialConditi_n
   * Referenced by: '<S138>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController3_InitialConditi_e
   * Referenced by: '<S186>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_i
   * Referenced by: '<S90>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_i
   * Referenced by: '<S42>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController5_InitialConditi_b
   * Referenced by: '<S282>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController4_InitialConditi_g
   * Referenced by: '<S234>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController3_LowerSaturationL
   * Referenced by: '<S193>/Saturation'
   */
  -1.0471975511965976,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S49>/Saturation'
   */
  -1.0471975511965976,

  /* Mask Parameter: PIDController5_LowerSaturationL
   * Referenced by: '<S289>/Saturation'
   */
  -0.1,

  /* Mask Parameter: PIDController2_N
   * Referenced by: '<S141>/Filter Coefficient'
   */
  11428.279760416,

  /* Mask Parameter: PIDController3_N
   * Referenced by: '<S189>/Filter Coefficient'
   */
  114282.79760416,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S93>/Filter Coefficient'
   */
  11428.279760416,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S45>/Filter Coefficient'
   */
  114282.79760416,

  /* Mask Parameter: PIDController5_N
   * Referenced by: '<S285>/Filter Coefficient'
   */
  1142.8279760416,

  /* Mask Parameter: PIDController4_N
   * Referenced by: '<S237>/Filter Coefficient'
   */
  11428.279760416,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S143>/Proportional Gain'
   */
  -25.9360289201711,

  /* Mask Parameter: PIDController3_P
   * Referenced by: '<S191>/Proportional Gain'
   */
  2.6281419514846,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S95>/Proportional Gain'
   */
  25.9360289201711,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S47>/Proportional Gain'
   */
  2.62814195143783,

  /* Mask Parameter: PIDController5_P
   * Referenced by: '<S287>/Proportional Gain'
   */
  0.00110066336636865,

  /* Mask Parameter: PIDController4_P
   * Referenced by: '<S239>/Proportional Gain'
   */
  1.96128095197019,

  /* Mask Parameter: PIDController3_UpperSaturationL
   * Referenced by: '<S193>/Saturation'
   */
  1.0471975511965976,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S49>/Saturation'
   */
  1.0471975511965976,

  /* Mask Parameter: PIDController5_UpperSaturationL
   * Referenced by: '<S289>/Saturation'
   */
  0.1,

  /* Expression: 0.4
   * Referenced by: '<Root>/y_ref'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<Root>/y_ref'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/y_ref'
   */
  0.3,

  /* Expression: 0
   * Referenced by: '<Root>/y_ref'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/x_ref'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<Root>/x_ref'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/x_ref'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<Root>/x_ref'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 0.8
   * Referenced by: '<Root>/z_ref'
   */
  0.8,

  /* Expression: 0
   * Referenced by: '<Root>/z_ref'
   */
  0.0,

  /* Expression: 0.4
   * Referenced by: '<Root>/z_ref'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<Root>/z_ref'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0
};
