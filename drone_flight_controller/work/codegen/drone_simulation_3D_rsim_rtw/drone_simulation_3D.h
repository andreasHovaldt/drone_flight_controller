/*
 * drone_simulation_3D.h
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

#ifndef RTW_HEADER_drone_simulation_3D_h_
#define RTW_HEADER_drone_simulation_3D_h_
#ifndef drone_simulation_3D_COMMON_INCLUDES_
#define drone_simulation_3D_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                /* drone_simulation_3D_COMMON_INCLUDES_ */

#include "drone_simulation_3D_types.h"
#include <stddef.h>
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME                     drone_simulation_3D
#define NSAMPLE_TIMES                  (2)                       /* Number of sample times */
#define NINPUTS                        (0)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (66)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
#define NCSTATES                       (24)                      /* Number of continuous states */
#elif NCSTATES != 24
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         (NULL)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T current_pos[3];               /* '<Root>/Integrator2' */
  real_T Sum2;                         /* '<S3>/Sum2' */
  real_T ProportionalGain;             /* '<S143>/Proportional Gain' */
  real_T Integrator;                   /* '<S138>/Integrator' */
  real_T DerivativeGain;               /* '<S132>/Derivative Gain' */
  real_T Filter;                       /* '<S133>/Filter' */
  real_T SumD;                         /* '<S133>/SumD' */
  real_T FilterCoefficient;            /* '<S141>/Filter Coefficient' */
  real_T Sum;                          /* '<S147>/Sum' */
  real_T Integrator1[3];               /* '<Root>/Integrator1' */
  real_T Sum4;                         /* '<S3>/Sum4' */
  real_T ProportionalGain_b;           /* '<S191>/Proportional Gain' */
  real_T Integrator_j;                 /* '<S186>/Integrator' */
  real_T DerivativeGain_m;             /* '<S180>/Derivative Gain' */
  real_T Filter_e;                     /* '<S181>/Filter' */
  real_T SumD_h;                       /* '<S181>/SumD' */
  real_T FilterCoefficient_k;          /* '<S189>/Filter Coefficient' */
  real_T Sum_o;                        /* '<S195>/Sum' */
  real_T Saturation;                   /* '<S193>/Saturation' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T ProportionalGain_m;           /* '<S95>/Proportional Gain' */
  real_T Integrator_e;                 /* '<S90>/Integrator' */
  real_T DerivativeGain_h;             /* '<S84>/Derivative Gain' */
  real_T Filter_j;                     /* '<S85>/Filter' */
  real_T SumD_j;                       /* '<S85>/SumD' */
  real_T FilterCoefficient_a;          /* '<S93>/Filter Coefficient' */
  real_T Sum_p;                        /* '<S99>/Sum' */
  real_T Sum3;                         /* '<S3>/Sum3' */
  real_T ProportionalGain_i;           /* '<S47>/Proportional Gain' */
  real_T Integrator_h;                 /* '<S42>/Integrator' */
  real_T DerivativeGain_l;             /* '<S36>/Derivative Gain' */
  real_T Filter_m;                     /* '<S37>/Filter' */
  real_T SumD_n;                       /* '<S37>/SumD' */
  real_T FilterCoefficient_e;          /* '<S45>/Filter Coefficient' */
  real_T Sum_h;                        /* '<S51>/Sum' */
  real_T Saturation_f;                 /* '<S49>/Saturation' */
  real_T Constant;                     /* '<S3>/Constant' */
  real_T Sum5;                         /* '<S3>/Sum5' */
  real_T ProportionalGain_d;           /* '<S287>/Proportional Gain' */
  real_T Integrator_l;                 /* '<S282>/Integrator' */
  real_T DerivativeGain_g;             /* '<S276>/Derivative Gain' */
  real_T Filter_ey;                    /* '<S277>/Filter' */
  real_T SumD_no;                      /* '<S277>/SumD' */
  real_T FilterCoefficient_d;          /* '<S285>/Filter Coefficient' */
  real_T Sum_e;                        /* '<S291>/Sum' */
  real_T Saturation_b;                 /* '<S289>/Saturation' */
  real_T Sum_pm;                       /* '<S3>/Sum' */
  real_T ProportionalGain_f;           /* '<S239>/Proportional Gain' */
  real_T Integrator_a;                 /* '<S234>/Integrator' */
  real_T DerivativeGain_a;             /* '<S228>/Derivative Gain' */
  real_T Filter_g;                     /* '<S229>/Filter' */
  real_T SumD_f;                       /* '<S229>/SumD' */
  real_T FilterCoefficient_ku;         /* '<S237>/Filter Coefficient' */
  real_T Sum_c;                        /* '<S243>/Sum' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T TmpSignalConversionAtInport2[3];
  real_T u[3];                         /* '<Root>/  ' */
  real_T u_l[3];                       /* '<Root>/ ' */
  real_T IntegralGain;                 /* '<S39>/Integral Gain' */
  real_T IntegralGain_j;               /* '<S87>/Integral Gain' */
  real_T IntegralGain_k;               /* '<S135>/Integral Gain' */
  real_T IntegralGain_i;               /* '<S183>/Integral Gain' */
  real_T IntegralGain_b;               /* '<S231>/Integral Gain' */
  real_T IntegralGain_kx;              /* '<S279>/Integral Gain' */
  real_T lin_acc[3];                   /* '<Root>/Drone dynamics' */
  real_T ang_acc[3];                   /* '<Root>/Drone dynamics' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Angacc_PWORK;                      /* '<Root>/Ang acc' */

  struct {
    void *LoggedData;
  } Angpos_PWORK;                      /* '<Root>/Ang pos' */

  struct {
    void *LoggedData;
  } Angvel_PWORK;                      /* '<Root>/Ang vel' */

  struct {
    void *LoggedData;
  } Linacc_PWORK;                      /* '<Root>/Lin acc' */

  struct {
    void *LoggedData;
  } Linpos_PWORK;                      /* '<Root>/Lin pos' */

  struct {
    void *LoggedData;
  } Linvel_PWORK;                      /* '<Root>/Lin vel' */

  struct {
    void *LoggedData;
  } Refcompcurrent_PWORK;              /* '<Root>/Ref comp current' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S3>/Scope' */

  int_T _IWORK;                        /* '<Root>/  ' */
  int_T _IWORK_n;                      /* '<Root>/ ' */
  int_T Saturation_MODE;               /* '<S193>/Saturation' */
  int_T Saturation_MODE_e;             /* '<S49>/Saturation' */
  int_T Saturation_MODE_g;             /* '<S289>/Saturation' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE[3];        /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S138>/Integrator' */
  real_T Filter_CSTATE;                /* '<S133>/Filter' */
  real_T Integrator1_CSTATE[3];        /* '<Root>/Integrator1' */
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
  real_T Integrator2_CSTATE[3];        /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S138>/Integrator' */
  real_T Filter_CSTATE;                /* '<S133>/Filter' */
  real_T Integrator1_CSTATE[3];        /* '<Root>/Integrator1' */
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
  boolean_T Integrator2_CSTATE[3];     /* '<Root>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<S138>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S133>/Filter' */
  boolean_T Integrator1_CSTATE[3];     /* '<Root>/Integrator1' */
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

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T Integrator2_CSTATE[3];        /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S138>/Integrator' */
  real_T Filter_CSTATE;                /* '<S133>/Filter' */
  real_T Integrator1_CSTATE[3];        /* '<Root>/Integrator1' */
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
} CStateAbsTol;

/* Continuous State Perturb Min  */
typedef struct {
  real_T Integrator2_CSTATE[3];        /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S138>/Integrator' */
  real_T Filter_CSTATE;                /* '<S133>/Filter' */
  real_T Integrator1_CSTATE[3];        /* '<Root>/Integrator1' */
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
} CXPtMin;

/* Continuous State Perturb Max  */
typedef struct {
  real_T Integrator2_CSTATE[3];        /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S138>/Integrator' */
  real_T Filter_CSTATE;                /* '<S133>/Filter' */
  real_T Integrator1_CSTATE[3];        /* '<Root>/Integrator1' */
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
} CXPtMax;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Saturation_UprLim_ZC;         /* '<S193>/Saturation' */
  real_T Saturation_LwrLim_ZC;         /* '<S193>/Saturation' */
  real_T Saturation_UprLim_ZC_o;       /* '<S49>/Saturation' */
  real_T Saturation_LwrLim_ZC_e;       /* '<S49>/Saturation' */
  real_T Saturation_UprLim_ZC_p;       /* '<S289>/Saturation' */
  real_T Saturation_LwrLim_ZC_d;       /* '<S289>/Saturation' */
} ZCV;

/* Parameters (default storage) */
struct P_ {
  real_T PIDController2_D;             /* Mask Parameter: PIDController2_D
                                        * Referenced by: '<S132>/Derivative Gain'
                                        */
  real_T PIDController3_D;             /* Mask Parameter: PIDController3_D
                                        * Referenced by: '<S180>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S84>/Derivative Gain'
                                        */
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S36>/Derivative Gain'
                                        */
  real_T PIDController5_D;             /* Mask Parameter: PIDController5_D
                                        * Referenced by: '<S276>/Derivative Gain'
                                        */
  real_T PIDController4_D;             /* Mask Parameter: PIDController4_D
                                        * Referenced by: '<S228>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S39>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S87>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S135>/Integral Gain'
                                        */
  real_T PIDController3_I;             /* Mask Parameter: PIDController3_I
                                        * Referenced by: '<S183>/Integral Gain'
                                        */
  real_T PIDController4_I;             /* Mask Parameter: PIDController4_I
                                        * Referenced by: '<S231>/Integral Gain'
                                        */
  real_T PIDController5_I;             /* Mask Parameter: PIDController5_I
                                        * Referenced by: '<S279>/Integral Gain'
                                        */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S133>/Filter'
                               */
  real_T PIDController3_InitialCondition;
                              /* Mask Parameter: PIDController3_InitialCondition
                               * Referenced by: '<S181>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S85>/Filter'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S37>/Filter'
                               */
  real_T PIDController5_InitialCondition;
                              /* Mask Parameter: PIDController5_InitialCondition
                               * Referenced by: '<S277>/Filter'
                               */
  real_T PIDController4_InitialCondition;
                              /* Mask Parameter: PIDController4_InitialCondition
                               * Referenced by: '<S229>/Filter'
                               */
  real_T PIDController2_InitialConditi_n;
                              /* Mask Parameter: PIDController2_InitialConditi_n
                               * Referenced by: '<S138>/Integrator'
                               */
  real_T PIDController3_InitialConditi_e;
                              /* Mask Parameter: PIDController3_InitialConditi_e
                               * Referenced by: '<S186>/Integrator'
                               */
  real_T PIDController1_InitialConditi_i;
                              /* Mask Parameter: PIDController1_InitialConditi_i
                               * Referenced by: '<S90>/Integrator'
                               */
  real_T PIDController_InitialConditio_i;
                              /* Mask Parameter: PIDController_InitialConditio_i
                               * Referenced by: '<S42>/Integrator'
                               */
  real_T PIDController5_InitialConditi_b;
                              /* Mask Parameter: PIDController5_InitialConditi_b
                               * Referenced by: '<S282>/Integrator'
                               */
  real_T PIDController4_InitialConditi_g;
                              /* Mask Parameter: PIDController4_InitialConditi_g
                               * Referenced by: '<S234>/Integrator'
                               */
  real_T PIDController3_LowerSaturationL;
                              /* Mask Parameter: PIDController3_LowerSaturationL
                               * Referenced by: '<S193>/Saturation'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S49>/Saturation'
                               */
  real_T PIDController5_LowerSaturationL;
                              /* Mask Parameter: PIDController5_LowerSaturationL
                               * Referenced by: '<S289>/Saturation'
                               */
  real_T PIDController2_N;             /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S141>/Filter Coefficient'
                                        */
  real_T PIDController3_N;             /* Mask Parameter: PIDController3_N
                                        * Referenced by: '<S189>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S93>/Filter Coefficient'
                                        */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S45>/Filter Coefficient'
                                        */
  real_T PIDController5_N;             /* Mask Parameter: PIDController5_N
                                        * Referenced by: '<S285>/Filter Coefficient'
                                        */
  real_T PIDController4_N;             /* Mask Parameter: PIDController4_N
                                        * Referenced by: '<S237>/Filter Coefficient'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S143>/Proportional Gain'
                                        */
  real_T PIDController3_P;             /* Mask Parameter: PIDController3_P
                                        * Referenced by: '<S191>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S95>/Proportional Gain'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S47>/Proportional Gain'
                                        */
  real_T PIDController5_P;             /* Mask Parameter: PIDController5_P
                                        * Referenced by: '<S287>/Proportional Gain'
                                        */
  real_T PIDController4_P;             /* Mask Parameter: PIDController4_P
                                        * Referenced by: '<S239>/Proportional Gain'
                                        */
  real_T PIDController3_UpperSaturationL;
                              /* Mask Parameter: PIDController3_UpperSaturationL
                               * Referenced by: '<S193>/Saturation'
                               */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S49>/Saturation'
                               */
  real_T PIDController5_UpperSaturationL;
                              /* Mask Parameter: PIDController5_UpperSaturationL
                               * Referenced by: '<S289>/Saturation'
                               */
  real_T y_ref_Amp;                    /* Expression: 0.4
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_ref_Bias;                   /* Expression: 0
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_ref_Freq;                   /* Expression: 0.3
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T y_ref_Phase;                  /* Expression: 0
                                        * Referenced by: '<Root>/y_ref'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T x_ref_Amp;                    /* Expression: 0.5
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_ref_Bias;                   /* Expression: 0
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_ref_Freq;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T x_ref_Phase;                  /* Expression: 0
                                        * Referenced by: '<Root>/x_ref'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T z_ref_Amp;                    /* Expression: 0.8
                                        * Referenced by: '<Root>/z_ref'
                                        */
  real_T z_ref_Bias;                   /* Expression: 0
                                        * Referenced by: '<Root>/z_ref'
                                        */
  real_T z_ref_Freq;                   /* Expression: 0.4
                                        * Referenced by: '<Root>/z_ref'
                                        */
  real_T z_ref_Phase;                  /* Expression: 0
                                        * Referenced by: '<Root>/z_ref'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
extern P rtP;                          /* parameters */

/* Simulation Structure */
extern SimStruct *const rtS;

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

/* user code (bottom of header file) */
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif                                 /* RTW_HEADER_drone_simulation_3D_h_ */
