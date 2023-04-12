/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: drone_simulation_3D.h
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

#ifndef RTW_HEADER_drone_simulation_3D_h_
#define RTW_HEADER_drone_simulation_3D_h_
#ifndef drone_simulation_3D_COMMON_INCLUDES_
#define drone_simulation_3D_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                /* drone_simulation_3D_COMMON_INCLUDES_ */

#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T u[3];                         /* '<Root>/  ' */
  real_T u_l[3];                       /* '<Root>/ ' */
  real_T lin_acc[3];                   /* '<Root>/Drone dynamics' */
  real_T ang_acc[3];                   /* '<Root>/Drone dynamics' */
  real_T FilterCoefficient;            /* '<S141>/Filter Coefficient' */
  real_T FilterCoefficient_k;          /* '<S189>/Filter Coefficient' */
  real_T FilterCoefficient_a;          /* '<S93>/Filter Coefficient' */
  real_T FilterCoefficient_e;          /* '<S45>/Filter Coefficient' */
  real_T FilterCoefficient_d;          /* '<S285>/Filter Coefficient' */
  real_T FilterCoefficient_ku;         /* '<S237>/Filter Coefficient' */
  real_T IntegralGain;                 /* '<S231>/Integral Gain' */
  real_T IntegralGain_k;               /* '<S279>/Integral Gain' */
  real_T IntegralGain_m;               /* '<S39>/Integral Gain' */
  real_T IntegralGain_j;               /* '<S87>/Integral Gain' */
  real_T IntegralGain_i;               /* '<S183>/Integral Gain' */
  real_T IntegralGain_kv;              /* '<S135>/Integral Gain' */
  int_T _IWORK;                        /* '<Root>/  ' */
  int_T _IWORK_n;                      /* '<Root>/ ' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S138>/Integrator' */
  real_T Filter_CSTATE;                /* '<S133>/Filter' */
  real_T Integrator_CSTATE_b;          /* '<S186>/Integrator' */
  real_T Filter_CSTATE_m;              /* '<S181>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S90>/Integrator' */
  real_T Filter_CSTATE_k;              /* '<S85>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S42>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S37>/Filter' */
  real_T Integrator_CSTATE_h;          /* '<S282>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S277>/Filter' */
  real_T Integrator_CSTATE_i;          /* '<S234>/Integrator' */
  real_T Filter_CSTATE_n;              /* '<S229>/Filter' */
  real_T _CSTATE[3];                   /* '<Root>/  ' */
  real_T _CSTATE_c[3];                 /* '<Root>/ ' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S138>/Integrator' */
  real_T Filter_CSTATE;                /* '<S133>/Filter' */
  real_T Integrator_CSTATE_b;          /* '<S186>/Integrator' */
  real_T Filter_CSTATE_m;              /* '<S181>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S90>/Integrator' */
  real_T Filter_CSTATE_k;              /* '<S85>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S42>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S37>/Filter' */
  real_T Integrator_CSTATE_h;          /* '<S282>/Integrator' */
  real_T Filter_CSTATE_c;              /* '<S277>/Filter' */
  real_T Integrator_CSTATE_i;          /* '<S234>/Integrator' */
  real_T Filter_CSTATE_n;              /* '<S229>/Filter' */
  real_T _CSTATE[3];                   /* '<Root>/  ' */
  real_T _CSTATE_c[3];                 /* '<Root>/ ' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<Root>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<S138>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S133>/Filter' */
  boolean_T Integrator_CSTATE_b;       /* '<S186>/Integrator' */
  boolean_T Filter_CSTATE_m;           /* '<S181>/Filter' */
  boolean_T Integrator_CSTATE_e;       /* '<S90>/Integrator' */
  boolean_T Filter_CSTATE_k;           /* '<S85>/Filter' */
  boolean_T Integrator_CSTATE_f;       /* '<S42>/Integrator' */
  boolean_T Filter_CSTATE_i;           /* '<S37>/Filter' */
  boolean_T Integrator_CSTATE_h;       /* '<S282>/Integrator' */
  boolean_T Filter_CSTATE_c;           /* '<S277>/Filter' */
  boolean_T Integrator_CSTATE_i;       /* '<S234>/Integrator' */
  boolean_T Filter_CSTATE_n;           /* '<S229>/Filter' */
  boolean_T _CSTATE[3];                /* '<Root>/  ' */
  boolean_T _CSTATE_c[3];              /* '<Root>/ ' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[24];
  real_T odeF[3][24];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void drone_simulation_3D_initialize(void);
extern void drone_simulation_3D_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Ang acc' : Unused code path elimination
 * Block '<Root>/Ang pos' : Unused code path elimination
 * Block '<Root>/Ang vel' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Constant4' : Unused code path elimination
 * Block '<Root>/Lin acc' : Unused code path elimination
 * Block '<Root>/Lin pos' : Unused code path elimination
 * Block '<Root>/Lin vel' : Unused code path elimination
 * Block '<Root>/Ref comp current' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/Constant2' : Unused code path elimination
 * Block '<S3>/Constant3' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<Root>/To Workspace' : Unused code path elimination
 * Block '<Root>/To Workspace1' : Unused code path elimination
 * Block '<Root>/To Workspace2' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'drone_simulation_3D'
 * '<S1>'   : 'drone_simulation_3D/Drone dynamics'
 * '<S2>'   : 'drone_simulation_3D/Motor mixing algorithm'
 * '<S3>'   : 'drone_simulation_3D/Subsystem'
 * '<S4>'   : 'drone_simulation_3D/Subsystem/MATLAB Function'
 * '<S5>'   : 'drone_simulation_3D/Subsystem/PID Controller'
 * '<S6>'   : 'drone_simulation_3D/Subsystem/PID Controller1'
 * '<S7>'   : 'drone_simulation_3D/Subsystem/PID Controller2'
 * '<S8>'   : 'drone_simulation_3D/Subsystem/PID Controller3'
 * '<S9>'   : 'drone_simulation_3D/Subsystem/PID Controller4'
 * '<S10>'  : 'drone_simulation_3D/Subsystem/PID Controller5'
 * '<S11>'  : 'drone_simulation_3D/Subsystem/PID Controller/Anti-windup'
 * '<S12>'  : 'drone_simulation_3D/Subsystem/PID Controller/D Gain'
 * '<S13>'  : 'drone_simulation_3D/Subsystem/PID Controller/Filter'
 * '<S14>'  : 'drone_simulation_3D/Subsystem/PID Controller/Filter ICs'
 * '<S15>'  : 'drone_simulation_3D/Subsystem/PID Controller/I Gain'
 * '<S16>'  : 'drone_simulation_3D/Subsystem/PID Controller/Ideal P Gain'
 * '<S17>'  : 'drone_simulation_3D/Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'drone_simulation_3D/Subsystem/PID Controller/Integrator'
 * '<S19>'  : 'drone_simulation_3D/Subsystem/PID Controller/Integrator ICs'
 * '<S20>'  : 'drone_simulation_3D/Subsystem/PID Controller/N Copy'
 * '<S21>'  : 'drone_simulation_3D/Subsystem/PID Controller/N Gain'
 * '<S22>'  : 'drone_simulation_3D/Subsystem/PID Controller/P Copy'
 * '<S23>'  : 'drone_simulation_3D/Subsystem/PID Controller/Parallel P Gain'
 * '<S24>'  : 'drone_simulation_3D/Subsystem/PID Controller/Reset Signal'
 * '<S25>'  : 'drone_simulation_3D/Subsystem/PID Controller/Saturation'
 * '<S26>'  : 'drone_simulation_3D/Subsystem/PID Controller/Saturation Fdbk'
 * '<S27>'  : 'drone_simulation_3D/Subsystem/PID Controller/Sum'
 * '<S28>'  : 'drone_simulation_3D/Subsystem/PID Controller/Sum Fdbk'
 * '<S29>'  : 'drone_simulation_3D/Subsystem/PID Controller/Tracking Mode'
 * '<S30>'  : 'drone_simulation_3D/Subsystem/PID Controller/Tracking Mode Sum'
 * '<S31>'  : 'drone_simulation_3D/Subsystem/PID Controller/Tsamp - Integral'
 * '<S32>'  : 'drone_simulation_3D/Subsystem/PID Controller/Tsamp - Ngain'
 * '<S33>'  : 'drone_simulation_3D/Subsystem/PID Controller/postSat Signal'
 * '<S34>'  : 'drone_simulation_3D/Subsystem/PID Controller/preSat Signal'
 * '<S35>'  : 'drone_simulation_3D/Subsystem/PID Controller/Anti-windup/Passthrough'
 * '<S36>'  : 'drone_simulation_3D/Subsystem/PID Controller/D Gain/Internal Parameters'
 * '<S37>'  : 'drone_simulation_3D/Subsystem/PID Controller/Filter/Cont. Filter'
 * '<S38>'  : 'drone_simulation_3D/Subsystem/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S39>'  : 'drone_simulation_3D/Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S40>'  : 'drone_simulation_3D/Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S41>'  : 'drone_simulation_3D/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S42>'  : 'drone_simulation_3D/Subsystem/PID Controller/Integrator/Continuous'
 * '<S43>'  : 'drone_simulation_3D/Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S44>'  : 'drone_simulation_3D/Subsystem/PID Controller/N Copy/Disabled'
 * '<S45>'  : 'drone_simulation_3D/Subsystem/PID Controller/N Gain/Internal Parameters'
 * '<S46>'  : 'drone_simulation_3D/Subsystem/PID Controller/P Copy/Disabled'
 * '<S47>'  : 'drone_simulation_3D/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S48>'  : 'drone_simulation_3D/Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S49>'  : 'drone_simulation_3D/Subsystem/PID Controller/Saturation/Enabled'
 * '<S50>'  : 'drone_simulation_3D/Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S51>'  : 'drone_simulation_3D/Subsystem/PID Controller/Sum/Sum_PID'
 * '<S52>'  : 'drone_simulation_3D/Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S53>'  : 'drone_simulation_3D/Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S54>'  : 'drone_simulation_3D/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S55>'  : 'drone_simulation_3D/Subsystem/PID Controller/Tsamp - Integral/Passthrough'
 * '<S56>'  : 'drone_simulation_3D/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S57>'  : 'drone_simulation_3D/Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S58>'  : 'drone_simulation_3D/Subsystem/PID Controller/preSat Signal/Forward_Path'
 * '<S59>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Anti-windup'
 * '<S60>'  : 'drone_simulation_3D/Subsystem/PID Controller1/D Gain'
 * '<S61>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Filter'
 * '<S62>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Filter ICs'
 * '<S63>'  : 'drone_simulation_3D/Subsystem/PID Controller1/I Gain'
 * '<S64>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Ideal P Gain'
 * '<S65>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Ideal P Gain Fdbk'
 * '<S66>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Integrator'
 * '<S67>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Integrator ICs'
 * '<S68>'  : 'drone_simulation_3D/Subsystem/PID Controller1/N Copy'
 * '<S69>'  : 'drone_simulation_3D/Subsystem/PID Controller1/N Gain'
 * '<S70>'  : 'drone_simulation_3D/Subsystem/PID Controller1/P Copy'
 * '<S71>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Parallel P Gain'
 * '<S72>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Reset Signal'
 * '<S73>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Saturation'
 * '<S74>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Saturation Fdbk'
 * '<S75>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Sum'
 * '<S76>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Sum Fdbk'
 * '<S77>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Tracking Mode'
 * '<S78>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Tracking Mode Sum'
 * '<S79>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Tsamp - Integral'
 * '<S80>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Tsamp - Ngain'
 * '<S81>'  : 'drone_simulation_3D/Subsystem/PID Controller1/postSat Signal'
 * '<S82>'  : 'drone_simulation_3D/Subsystem/PID Controller1/preSat Signal'
 * '<S83>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Anti-windup/Passthrough'
 * '<S84>'  : 'drone_simulation_3D/Subsystem/PID Controller1/D Gain/Internal Parameters'
 * '<S85>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Filter/Cont. Filter'
 * '<S86>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S87>'  : 'drone_simulation_3D/Subsystem/PID Controller1/I Gain/Internal Parameters'
 * '<S88>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Ideal P Gain/Passthrough'
 * '<S89>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S90>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Integrator/Continuous'
 * '<S91>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Integrator ICs/Internal IC'
 * '<S92>'  : 'drone_simulation_3D/Subsystem/PID Controller1/N Copy/Disabled'
 * '<S93>'  : 'drone_simulation_3D/Subsystem/PID Controller1/N Gain/Internal Parameters'
 * '<S94>'  : 'drone_simulation_3D/Subsystem/PID Controller1/P Copy/Disabled'
 * '<S95>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S96>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Reset Signal/Disabled'
 * '<S97>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Saturation/Passthrough'
 * '<S98>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Saturation Fdbk/Disabled'
 * '<S99>'  : 'drone_simulation_3D/Subsystem/PID Controller1/Sum/Sum_PID'
 * '<S100>' : 'drone_simulation_3D/Subsystem/PID Controller1/Sum Fdbk/Disabled'
 * '<S101>' : 'drone_simulation_3D/Subsystem/PID Controller1/Tracking Mode/Disabled'
 * '<S102>' : 'drone_simulation_3D/Subsystem/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'drone_simulation_3D/Subsystem/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S104>' : 'drone_simulation_3D/Subsystem/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'drone_simulation_3D/Subsystem/PID Controller1/postSat Signal/Forward_Path'
 * '<S106>' : 'drone_simulation_3D/Subsystem/PID Controller1/preSat Signal/Forward_Path'
 * '<S107>' : 'drone_simulation_3D/Subsystem/PID Controller2/Anti-windup'
 * '<S108>' : 'drone_simulation_3D/Subsystem/PID Controller2/D Gain'
 * '<S109>' : 'drone_simulation_3D/Subsystem/PID Controller2/Filter'
 * '<S110>' : 'drone_simulation_3D/Subsystem/PID Controller2/Filter ICs'
 * '<S111>' : 'drone_simulation_3D/Subsystem/PID Controller2/I Gain'
 * '<S112>' : 'drone_simulation_3D/Subsystem/PID Controller2/Ideal P Gain'
 * '<S113>' : 'drone_simulation_3D/Subsystem/PID Controller2/Ideal P Gain Fdbk'
 * '<S114>' : 'drone_simulation_3D/Subsystem/PID Controller2/Integrator'
 * '<S115>' : 'drone_simulation_3D/Subsystem/PID Controller2/Integrator ICs'
 * '<S116>' : 'drone_simulation_3D/Subsystem/PID Controller2/N Copy'
 * '<S117>' : 'drone_simulation_3D/Subsystem/PID Controller2/N Gain'
 * '<S118>' : 'drone_simulation_3D/Subsystem/PID Controller2/P Copy'
 * '<S119>' : 'drone_simulation_3D/Subsystem/PID Controller2/Parallel P Gain'
 * '<S120>' : 'drone_simulation_3D/Subsystem/PID Controller2/Reset Signal'
 * '<S121>' : 'drone_simulation_3D/Subsystem/PID Controller2/Saturation'
 * '<S122>' : 'drone_simulation_3D/Subsystem/PID Controller2/Saturation Fdbk'
 * '<S123>' : 'drone_simulation_3D/Subsystem/PID Controller2/Sum'
 * '<S124>' : 'drone_simulation_3D/Subsystem/PID Controller2/Sum Fdbk'
 * '<S125>' : 'drone_simulation_3D/Subsystem/PID Controller2/Tracking Mode'
 * '<S126>' : 'drone_simulation_3D/Subsystem/PID Controller2/Tracking Mode Sum'
 * '<S127>' : 'drone_simulation_3D/Subsystem/PID Controller2/Tsamp - Integral'
 * '<S128>' : 'drone_simulation_3D/Subsystem/PID Controller2/Tsamp - Ngain'
 * '<S129>' : 'drone_simulation_3D/Subsystem/PID Controller2/postSat Signal'
 * '<S130>' : 'drone_simulation_3D/Subsystem/PID Controller2/preSat Signal'
 * '<S131>' : 'drone_simulation_3D/Subsystem/PID Controller2/Anti-windup/Passthrough'
 * '<S132>' : 'drone_simulation_3D/Subsystem/PID Controller2/D Gain/Internal Parameters'
 * '<S133>' : 'drone_simulation_3D/Subsystem/PID Controller2/Filter/Cont. Filter'
 * '<S134>' : 'drone_simulation_3D/Subsystem/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S135>' : 'drone_simulation_3D/Subsystem/PID Controller2/I Gain/Internal Parameters'
 * '<S136>' : 'drone_simulation_3D/Subsystem/PID Controller2/Ideal P Gain/Passthrough'
 * '<S137>' : 'drone_simulation_3D/Subsystem/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S138>' : 'drone_simulation_3D/Subsystem/PID Controller2/Integrator/Continuous'
 * '<S139>' : 'drone_simulation_3D/Subsystem/PID Controller2/Integrator ICs/Internal IC'
 * '<S140>' : 'drone_simulation_3D/Subsystem/PID Controller2/N Copy/Disabled'
 * '<S141>' : 'drone_simulation_3D/Subsystem/PID Controller2/N Gain/Internal Parameters'
 * '<S142>' : 'drone_simulation_3D/Subsystem/PID Controller2/P Copy/Disabled'
 * '<S143>' : 'drone_simulation_3D/Subsystem/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S144>' : 'drone_simulation_3D/Subsystem/PID Controller2/Reset Signal/Disabled'
 * '<S145>' : 'drone_simulation_3D/Subsystem/PID Controller2/Saturation/Passthrough'
 * '<S146>' : 'drone_simulation_3D/Subsystem/PID Controller2/Saturation Fdbk/Disabled'
 * '<S147>' : 'drone_simulation_3D/Subsystem/PID Controller2/Sum/Sum_PID'
 * '<S148>' : 'drone_simulation_3D/Subsystem/PID Controller2/Sum Fdbk/Disabled'
 * '<S149>' : 'drone_simulation_3D/Subsystem/PID Controller2/Tracking Mode/Disabled'
 * '<S150>' : 'drone_simulation_3D/Subsystem/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S151>' : 'drone_simulation_3D/Subsystem/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S152>' : 'drone_simulation_3D/Subsystem/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S153>' : 'drone_simulation_3D/Subsystem/PID Controller2/postSat Signal/Forward_Path'
 * '<S154>' : 'drone_simulation_3D/Subsystem/PID Controller2/preSat Signal/Forward_Path'
 * '<S155>' : 'drone_simulation_3D/Subsystem/PID Controller3/Anti-windup'
 * '<S156>' : 'drone_simulation_3D/Subsystem/PID Controller3/D Gain'
 * '<S157>' : 'drone_simulation_3D/Subsystem/PID Controller3/Filter'
 * '<S158>' : 'drone_simulation_3D/Subsystem/PID Controller3/Filter ICs'
 * '<S159>' : 'drone_simulation_3D/Subsystem/PID Controller3/I Gain'
 * '<S160>' : 'drone_simulation_3D/Subsystem/PID Controller3/Ideal P Gain'
 * '<S161>' : 'drone_simulation_3D/Subsystem/PID Controller3/Ideal P Gain Fdbk'
 * '<S162>' : 'drone_simulation_3D/Subsystem/PID Controller3/Integrator'
 * '<S163>' : 'drone_simulation_3D/Subsystem/PID Controller3/Integrator ICs'
 * '<S164>' : 'drone_simulation_3D/Subsystem/PID Controller3/N Copy'
 * '<S165>' : 'drone_simulation_3D/Subsystem/PID Controller3/N Gain'
 * '<S166>' : 'drone_simulation_3D/Subsystem/PID Controller3/P Copy'
 * '<S167>' : 'drone_simulation_3D/Subsystem/PID Controller3/Parallel P Gain'
 * '<S168>' : 'drone_simulation_3D/Subsystem/PID Controller3/Reset Signal'
 * '<S169>' : 'drone_simulation_3D/Subsystem/PID Controller3/Saturation'
 * '<S170>' : 'drone_simulation_3D/Subsystem/PID Controller3/Saturation Fdbk'
 * '<S171>' : 'drone_simulation_3D/Subsystem/PID Controller3/Sum'
 * '<S172>' : 'drone_simulation_3D/Subsystem/PID Controller3/Sum Fdbk'
 * '<S173>' : 'drone_simulation_3D/Subsystem/PID Controller3/Tracking Mode'
 * '<S174>' : 'drone_simulation_3D/Subsystem/PID Controller3/Tracking Mode Sum'
 * '<S175>' : 'drone_simulation_3D/Subsystem/PID Controller3/Tsamp - Integral'
 * '<S176>' : 'drone_simulation_3D/Subsystem/PID Controller3/Tsamp - Ngain'
 * '<S177>' : 'drone_simulation_3D/Subsystem/PID Controller3/postSat Signal'
 * '<S178>' : 'drone_simulation_3D/Subsystem/PID Controller3/preSat Signal'
 * '<S179>' : 'drone_simulation_3D/Subsystem/PID Controller3/Anti-windup/Passthrough'
 * '<S180>' : 'drone_simulation_3D/Subsystem/PID Controller3/D Gain/Internal Parameters'
 * '<S181>' : 'drone_simulation_3D/Subsystem/PID Controller3/Filter/Cont. Filter'
 * '<S182>' : 'drone_simulation_3D/Subsystem/PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S183>' : 'drone_simulation_3D/Subsystem/PID Controller3/I Gain/Internal Parameters'
 * '<S184>' : 'drone_simulation_3D/Subsystem/PID Controller3/Ideal P Gain/Passthrough'
 * '<S185>' : 'drone_simulation_3D/Subsystem/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S186>' : 'drone_simulation_3D/Subsystem/PID Controller3/Integrator/Continuous'
 * '<S187>' : 'drone_simulation_3D/Subsystem/PID Controller3/Integrator ICs/Internal IC'
 * '<S188>' : 'drone_simulation_3D/Subsystem/PID Controller3/N Copy/Disabled'
 * '<S189>' : 'drone_simulation_3D/Subsystem/PID Controller3/N Gain/Internal Parameters'
 * '<S190>' : 'drone_simulation_3D/Subsystem/PID Controller3/P Copy/Disabled'
 * '<S191>' : 'drone_simulation_3D/Subsystem/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S192>' : 'drone_simulation_3D/Subsystem/PID Controller3/Reset Signal/Disabled'
 * '<S193>' : 'drone_simulation_3D/Subsystem/PID Controller3/Saturation/Enabled'
 * '<S194>' : 'drone_simulation_3D/Subsystem/PID Controller3/Saturation Fdbk/Disabled'
 * '<S195>' : 'drone_simulation_3D/Subsystem/PID Controller3/Sum/Sum_PID'
 * '<S196>' : 'drone_simulation_3D/Subsystem/PID Controller3/Sum Fdbk/Disabled'
 * '<S197>' : 'drone_simulation_3D/Subsystem/PID Controller3/Tracking Mode/Disabled'
 * '<S198>' : 'drone_simulation_3D/Subsystem/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S199>' : 'drone_simulation_3D/Subsystem/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S200>' : 'drone_simulation_3D/Subsystem/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S201>' : 'drone_simulation_3D/Subsystem/PID Controller3/postSat Signal/Forward_Path'
 * '<S202>' : 'drone_simulation_3D/Subsystem/PID Controller3/preSat Signal/Forward_Path'
 * '<S203>' : 'drone_simulation_3D/Subsystem/PID Controller4/Anti-windup'
 * '<S204>' : 'drone_simulation_3D/Subsystem/PID Controller4/D Gain'
 * '<S205>' : 'drone_simulation_3D/Subsystem/PID Controller4/Filter'
 * '<S206>' : 'drone_simulation_3D/Subsystem/PID Controller4/Filter ICs'
 * '<S207>' : 'drone_simulation_3D/Subsystem/PID Controller4/I Gain'
 * '<S208>' : 'drone_simulation_3D/Subsystem/PID Controller4/Ideal P Gain'
 * '<S209>' : 'drone_simulation_3D/Subsystem/PID Controller4/Ideal P Gain Fdbk'
 * '<S210>' : 'drone_simulation_3D/Subsystem/PID Controller4/Integrator'
 * '<S211>' : 'drone_simulation_3D/Subsystem/PID Controller4/Integrator ICs'
 * '<S212>' : 'drone_simulation_3D/Subsystem/PID Controller4/N Copy'
 * '<S213>' : 'drone_simulation_3D/Subsystem/PID Controller4/N Gain'
 * '<S214>' : 'drone_simulation_3D/Subsystem/PID Controller4/P Copy'
 * '<S215>' : 'drone_simulation_3D/Subsystem/PID Controller4/Parallel P Gain'
 * '<S216>' : 'drone_simulation_3D/Subsystem/PID Controller4/Reset Signal'
 * '<S217>' : 'drone_simulation_3D/Subsystem/PID Controller4/Saturation'
 * '<S218>' : 'drone_simulation_3D/Subsystem/PID Controller4/Saturation Fdbk'
 * '<S219>' : 'drone_simulation_3D/Subsystem/PID Controller4/Sum'
 * '<S220>' : 'drone_simulation_3D/Subsystem/PID Controller4/Sum Fdbk'
 * '<S221>' : 'drone_simulation_3D/Subsystem/PID Controller4/Tracking Mode'
 * '<S222>' : 'drone_simulation_3D/Subsystem/PID Controller4/Tracking Mode Sum'
 * '<S223>' : 'drone_simulation_3D/Subsystem/PID Controller4/Tsamp - Integral'
 * '<S224>' : 'drone_simulation_3D/Subsystem/PID Controller4/Tsamp - Ngain'
 * '<S225>' : 'drone_simulation_3D/Subsystem/PID Controller4/postSat Signal'
 * '<S226>' : 'drone_simulation_3D/Subsystem/PID Controller4/preSat Signal'
 * '<S227>' : 'drone_simulation_3D/Subsystem/PID Controller4/Anti-windup/Passthrough'
 * '<S228>' : 'drone_simulation_3D/Subsystem/PID Controller4/D Gain/Internal Parameters'
 * '<S229>' : 'drone_simulation_3D/Subsystem/PID Controller4/Filter/Cont. Filter'
 * '<S230>' : 'drone_simulation_3D/Subsystem/PID Controller4/Filter ICs/Internal IC - Filter'
 * '<S231>' : 'drone_simulation_3D/Subsystem/PID Controller4/I Gain/Internal Parameters'
 * '<S232>' : 'drone_simulation_3D/Subsystem/PID Controller4/Ideal P Gain/Passthrough'
 * '<S233>' : 'drone_simulation_3D/Subsystem/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S234>' : 'drone_simulation_3D/Subsystem/PID Controller4/Integrator/Continuous'
 * '<S235>' : 'drone_simulation_3D/Subsystem/PID Controller4/Integrator ICs/Internal IC'
 * '<S236>' : 'drone_simulation_3D/Subsystem/PID Controller4/N Copy/Disabled'
 * '<S237>' : 'drone_simulation_3D/Subsystem/PID Controller4/N Gain/Internal Parameters'
 * '<S238>' : 'drone_simulation_3D/Subsystem/PID Controller4/P Copy/Disabled'
 * '<S239>' : 'drone_simulation_3D/Subsystem/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S240>' : 'drone_simulation_3D/Subsystem/PID Controller4/Reset Signal/Disabled'
 * '<S241>' : 'drone_simulation_3D/Subsystem/PID Controller4/Saturation/Passthrough'
 * '<S242>' : 'drone_simulation_3D/Subsystem/PID Controller4/Saturation Fdbk/Disabled'
 * '<S243>' : 'drone_simulation_3D/Subsystem/PID Controller4/Sum/Sum_PID'
 * '<S244>' : 'drone_simulation_3D/Subsystem/PID Controller4/Sum Fdbk/Disabled'
 * '<S245>' : 'drone_simulation_3D/Subsystem/PID Controller4/Tracking Mode/Disabled'
 * '<S246>' : 'drone_simulation_3D/Subsystem/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S247>' : 'drone_simulation_3D/Subsystem/PID Controller4/Tsamp - Integral/Passthrough'
 * '<S248>' : 'drone_simulation_3D/Subsystem/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S249>' : 'drone_simulation_3D/Subsystem/PID Controller4/postSat Signal/Forward_Path'
 * '<S250>' : 'drone_simulation_3D/Subsystem/PID Controller4/preSat Signal/Forward_Path'
 * '<S251>' : 'drone_simulation_3D/Subsystem/PID Controller5/Anti-windup'
 * '<S252>' : 'drone_simulation_3D/Subsystem/PID Controller5/D Gain'
 * '<S253>' : 'drone_simulation_3D/Subsystem/PID Controller5/Filter'
 * '<S254>' : 'drone_simulation_3D/Subsystem/PID Controller5/Filter ICs'
 * '<S255>' : 'drone_simulation_3D/Subsystem/PID Controller5/I Gain'
 * '<S256>' : 'drone_simulation_3D/Subsystem/PID Controller5/Ideal P Gain'
 * '<S257>' : 'drone_simulation_3D/Subsystem/PID Controller5/Ideal P Gain Fdbk'
 * '<S258>' : 'drone_simulation_3D/Subsystem/PID Controller5/Integrator'
 * '<S259>' : 'drone_simulation_3D/Subsystem/PID Controller5/Integrator ICs'
 * '<S260>' : 'drone_simulation_3D/Subsystem/PID Controller5/N Copy'
 * '<S261>' : 'drone_simulation_3D/Subsystem/PID Controller5/N Gain'
 * '<S262>' : 'drone_simulation_3D/Subsystem/PID Controller5/P Copy'
 * '<S263>' : 'drone_simulation_3D/Subsystem/PID Controller5/Parallel P Gain'
 * '<S264>' : 'drone_simulation_3D/Subsystem/PID Controller5/Reset Signal'
 * '<S265>' : 'drone_simulation_3D/Subsystem/PID Controller5/Saturation'
 * '<S266>' : 'drone_simulation_3D/Subsystem/PID Controller5/Saturation Fdbk'
 * '<S267>' : 'drone_simulation_3D/Subsystem/PID Controller5/Sum'
 * '<S268>' : 'drone_simulation_3D/Subsystem/PID Controller5/Sum Fdbk'
 * '<S269>' : 'drone_simulation_3D/Subsystem/PID Controller5/Tracking Mode'
 * '<S270>' : 'drone_simulation_3D/Subsystem/PID Controller5/Tracking Mode Sum'
 * '<S271>' : 'drone_simulation_3D/Subsystem/PID Controller5/Tsamp - Integral'
 * '<S272>' : 'drone_simulation_3D/Subsystem/PID Controller5/Tsamp - Ngain'
 * '<S273>' : 'drone_simulation_3D/Subsystem/PID Controller5/postSat Signal'
 * '<S274>' : 'drone_simulation_3D/Subsystem/PID Controller5/preSat Signal'
 * '<S275>' : 'drone_simulation_3D/Subsystem/PID Controller5/Anti-windup/Passthrough'
 * '<S276>' : 'drone_simulation_3D/Subsystem/PID Controller5/D Gain/Internal Parameters'
 * '<S277>' : 'drone_simulation_3D/Subsystem/PID Controller5/Filter/Cont. Filter'
 * '<S278>' : 'drone_simulation_3D/Subsystem/PID Controller5/Filter ICs/Internal IC - Filter'
 * '<S279>' : 'drone_simulation_3D/Subsystem/PID Controller5/I Gain/Internal Parameters'
 * '<S280>' : 'drone_simulation_3D/Subsystem/PID Controller5/Ideal P Gain/Passthrough'
 * '<S281>' : 'drone_simulation_3D/Subsystem/PID Controller5/Ideal P Gain Fdbk/Disabled'
 * '<S282>' : 'drone_simulation_3D/Subsystem/PID Controller5/Integrator/Continuous'
 * '<S283>' : 'drone_simulation_3D/Subsystem/PID Controller5/Integrator ICs/Internal IC'
 * '<S284>' : 'drone_simulation_3D/Subsystem/PID Controller5/N Copy/Disabled'
 * '<S285>' : 'drone_simulation_3D/Subsystem/PID Controller5/N Gain/Internal Parameters'
 * '<S286>' : 'drone_simulation_3D/Subsystem/PID Controller5/P Copy/Disabled'
 * '<S287>' : 'drone_simulation_3D/Subsystem/PID Controller5/Parallel P Gain/Internal Parameters'
 * '<S288>' : 'drone_simulation_3D/Subsystem/PID Controller5/Reset Signal/Disabled'
 * '<S289>' : 'drone_simulation_3D/Subsystem/PID Controller5/Saturation/Enabled'
 * '<S290>' : 'drone_simulation_3D/Subsystem/PID Controller5/Saturation Fdbk/Disabled'
 * '<S291>' : 'drone_simulation_3D/Subsystem/PID Controller5/Sum/Sum_PID'
 * '<S292>' : 'drone_simulation_3D/Subsystem/PID Controller5/Sum Fdbk/Disabled'
 * '<S293>' : 'drone_simulation_3D/Subsystem/PID Controller5/Tracking Mode/Disabled'
 * '<S294>' : 'drone_simulation_3D/Subsystem/PID Controller5/Tracking Mode Sum/Passthrough'
 * '<S295>' : 'drone_simulation_3D/Subsystem/PID Controller5/Tsamp - Integral/Passthrough'
 * '<S296>' : 'drone_simulation_3D/Subsystem/PID Controller5/Tsamp - Ngain/Passthrough'
 * '<S297>' : 'drone_simulation_3D/Subsystem/PID Controller5/postSat Signal/Forward_Path'
 * '<S298>' : 'drone_simulation_3D/Subsystem/PID Controller5/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_drone_simulation_3D_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
