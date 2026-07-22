/*
 * File: SF020_SysFaultMngt.h
 *
 * Code generated for Simulink model 'SF020_SysFaultMngt'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jun 11 19:25:09 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SF020_SysFaultMngt_h_
#define RTW_HEADER_SF020_SysFaultMngt_h_
#ifndef SF020_SysFaultMngt_COMMON_INCLUDES_
#define SF020_SysFaultMngt_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SF020_SysFaultMngt.h"
#endif                                 /* SF020_SysFaultMngt_COMMON_INCLUDES_ */

#include "Rte_Type.h"

/* Includes for objects with custom storage classes */
#include "XPSbW_PublicCon.h"
#include "XPSbW_PublicCal.h"
#include "Dem.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  BOOLEAN SF020_b_SysFaultStatusArray_UL_BOOLArrayB256[256];
                     /* '<Root>/SF020_b_SysFaultStatusArray_UL_BOOLArrayB256' */
} ARID_DEF_SF020_SysFaultMngt_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_SF020_SysFaultMngt_T SF020_SysFaultMngt_ARID_DEF;
                     /* '<Root>/SF020_b_SysFaultStatusArray_UL_BOOLArrayB256' */

/* Exported data declaration */

/* Volatile memory section */
#define VCU_START_SEC_MONITOR
#include "Rte_MemMap.h"

/* Declaration for custom storage class: MyMonitor */
extern boolean Monr_SF020_b_PreFaultStatusInput_UL[256];/* '<Root>/Data Store Memory' */
extern boolean Monr_SF020_b_SysFaultStatus_UL[256];/* '<Root>/Data Store Memory4' */
extern float32 Monr_SF020_f32_SysFaultDegFactor_UL;/* '<Root>/Data Store Memory1' */
extern uint8 Monr_SF020_u8_SysAssistType_UL;/* '<Root>/Data Store Memory2' */
extern uint8 Monr_SF020_u8_SysFaultIndex_UL;/* '<Root>/Data Store Memory3' */
extern uint8 Monr_SF020_u8_SysFaultProxyPara_UL;

#define VCU_STOP_SEC_MONITOR
#include "Rte_MemMap.h"

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
 * '<Root>' : 'SF020_SysFaultMngt'
 * '<S1>'   : 'SF020_SysFaultMngt/ModelChangelog'
 * '<S2>'   : 'SF020_SysFaultMngt/RecoverFault'
 * '<S3>'   : 'SF020_SysFaultMngt/SF020_SysFaultMngt_Cycle_5ms_sys'
 * '<S4>'   : 'SF020_SysFaultMngt/SF020_SysFaultMngt_Init'
 * '<S5>'   : 'SF020_SysFaultMngt/TriggerFault'
 * '<S6>'   : 'SF020_SysFaultMngt/ModelChangelog/ModelChangelog'
 * '<S7>'   : 'SF020_SysFaultMngt/RecoverFault/NoXTCRecover'
 * '<S8>'   : 'SF020_SysFaultMngt/RecoverFault/XTCRecover'
 * '<S9>'   : 'SF020_SysFaultMngt/RecoverFault/XTCRecover/DoNothing'
 * '<S10>'  : 'SF020_SysFaultMngt/RecoverFault/XTCRecover/RecoverXTC'
 * '<S11>'  : 'SF020_SysFaultMngt/RecoverFault/XTCRecover/RecoverXTC/Enumerated Constant'
 * '<S12>'  : 'SF020_SysFaultMngt/TriggerFault/NoXTCTrigger'
 * '<S13>'  : 'SF020_SysFaultMngt/TriggerFault/XTCTrigger'
 * '<S14>'  : 'SF020_SysFaultMngt/TriggerFault/XTCTrigger/DoNothing'
 * '<S15>'  : 'SF020_SysFaultMngt/TriggerFault/XTCTrigger/XTCTrigger'
 * '<S16>'  : 'SF020_SysFaultMngt/TriggerFault/XTCTrigger/XTCTrigger/Enumerated Constant'
 */

/*-
 * Requirements for '<Root>': SF020_SysFaultMngt


 */
#endif                                 /* RTW_HEADER_SF020_SysFaultMngt_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
