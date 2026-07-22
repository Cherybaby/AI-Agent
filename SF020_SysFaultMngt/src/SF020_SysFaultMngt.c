/*
 * File: SF020_SysFaultMngt.c
 *
 * Code generated for Simulink model 'SF020_SysFaultMngt'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jun 12 08:59:05 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SF020_SysFaultMngt.h"
#include "rtwtypes.h"
#include <string.h>
#include "Rte_Type.h"
#include "XPSbW_PublicCon.h"
#include "XPSbW_PublicCal.h"

/* Exported data definition */

/* Volatile memory section */
#define VCU_START_SEC_MONITOR
#include "Rte_MemMap.h"

/* Definition for custom storage class: MyMonitor */
boolean Monr_SF020_b_PreFaultStatusInput_UL[256];/* '<Root>/Data Store Memory' */
boolean Monr_SF020_b_SysFaultStatus_UL[256];/* '<Root>/Data Store Memory4' */
float32 Monr_SF020_f32_SysFaultDegFactor_UL;/* '<Root>/Data Store Memory1' */
uint8 Monr_SF020_u8_DTCIndex_UL;       /* '<Root>/Data Store Memory5' */
uint8 Monr_SF020_u8_SysAssistType_UL;  /* '<Root>/Data Store Memory2' */
uint8 Monr_SF020_u8_SysFaultIndex_UL;  /* '<Root>/Data Store Memory3' */
uint8 Monr_SF020_u8_SysFaultProxyPara_UL;

#define VCU_STOP_SEC_MONITOR
#include "Rte_MemMap.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_SF020_SysFaultMngt_T SF020_SysFaultMngt_ARID_DEF;
                     /* '<Root>/SF020_b_SysFaultStatusArray_UL_BOOLArrayB256' */
static void SF020_SysFaultMngt_NoXTCRecover(boolean *rty_Ret);
void RecoverFault(uint8 XtcId, boolean *Ret);
void TriggerFault(uint8 XtcId, uint8 Para, boolean *Ret);

/*
 * Output and update for action system:
 *    '<S2>/NoXTCRecover'
 *    '<S13>/DoNothing'
 */
static void SF020_SysFaultMngt_NoXTCRecover(boolean *rty_Ret)
{
  /* SignalConversion generated from: '<S7>/Ret' incorporates:
   *  Constant: '<S7>/Constant3'
   */
  *rty_Ret = Con_XPSbW_b_False_UL;
}

/* Model step function for TID1 */
void SF020_SysFaultMngt_Cycle_5ms(void)
                               /* Explicit Task: SF020_SysFaultMngt_Cycle_5ms */
{
  /* CODEGEN_MERGED_CODE_START */
  Monr_SF020_u8_SysFaultIndex_UL = 0U;
  boolean value;
  boolean* ret = &value;

  UINT8 DiagStatus_AbnormalResetFault_st;
  UINT8 DiagStatus_RAMErrFault_st;
  UINT8 DiagStatus_PFlsErrFault_st;
  UINT8 DiagStatus_DFlsErrFault_st;
  UINT8 DiagStatus_eepromFatalFault_st;
  UINT8 DiagStatus_MCUFataFault_st;
  UINT8 DiagStatus_OsFatalFault_st;
  UINT8 DiagStatus_PMICVpreFault_st;
  UINT8 DiagStatus_PMICVcoreFault_st;
  UINT8 DiagStatus_PMICAdcFault_st;
  UINT8 DiagStatus_PMICTasFault_st;
  UINT8 DiagStatus_PMICCanVFault_st;
  UINT8 DiagStatus_PMICSPIFault_st;
  UINT8 DiagStatus_PMICGenFault_st;
  UINT8 DiagStatus_GDUGenFault_st;
  UINT8 DiagStatus_GDUVoltCompFault_st;
  UINT8 DiagStatus_GDUCurrFault_st;
  UINT8 DiagStatus_GDUCommFault_st;
  UINT8 DiagStatus_GDUPhaseAFault_st;
  UINT8 DiagStatus_GDUPhaseBFault_st;
  UINT8 DiagStatus_GDUPhaseCFault_st;
  UINT8 DiagStatus_GDUSelfFault_st;
  UINT8 ES014_u8_MotAnAgCorrFault_st;
  UINT8 ES013_u8_MotAnAgMeasFault_st;
  UINT8 ES013_u8_MotAnAgPSinFault_st;
  UINT8 ES013_u8_MotAnAgPCosFault_st;
  UINT8 ES013_u8_MotAnAgNSinFault_st;
  UINT8 ES013_u8_MotAnAgNCosFault_st;
  UINT8 MF005_u8_AbnormalMotCtrlFault_st;
  UINT8 ES008_u8_GDRefVltgErrorFault_st;
  UINT8 ES005_u8_MotCurrMeasFault_st;
  UINT8 ES005_u8_MotCurrAMeasFault_st;
  UINT8 ES005_u8_MotCurrBMeasFault_st;
  UINT8 ES005_u8_MotCurrCMeasFault_st;
  UINT8 DiagStatus_MCUFault_st;
  UINT8 ES001_u8_TasSent1SignalFault_st;
  UINT8 ES001_u8_TasSent1ProtFault_st;
  UINT8 ES001_u8_HwAgAOverLimFault_st;
  UINT8 ES010_u8_TasSent2SignalFault_st;
  UINT8 ES010_u8_TasSent2ProtFault_st;
  UINT8 ES010_u8_HwAgBOverLimFault_st;
  UINT8 ES008_u8_PeriVltgErrorFault_st;
  UINT8 ES002_u8_HwTqCorrFault_st;
  UINT8 DiagStatus_SlightResetFault_st;
  UINT8 DiagStatus_eepromSlightFault_st;
  UINT8 ES011_u8_TasSent5SignalFault_st;
  UINT8 ES012_u8_HwAgCorrFault_st;
  UINT8 ES011_u8_TasSent5ProtFault_st;
  UINT8 ES012_u8_HwAgCalibrationFault_st;
  UINT8 MC005_u8_IMC1Fault_st;
  UINT8 MC005_u8_IMC2Fault_st;
  UINT8 ES008_u8_HiVltgErrorFault_st;
  UINT8 ES008_u8_HiVltgFatalErrorFault_st;
  UINT8 ES008_u8_LowVltgErrorFault_st;
  UINT8 ES008_u8_LowVltgFatalErrorFault_st;
  UINT8 ES008_u8_VltgCorrErrorSlightFault_st;
  UINT8 ES008_u8_VltgCorrErrorFatalFault_st;
  UINT8 ES007_u8_TempNTC1Fault_st;
  UINT8 ES007_u8_TempNTC2Fault_st;
  UINT8 ES007_u8_TempNTCCorrFault_st;
  UINT8 ES008_u8_MotBrdgVltgADCFault_st;
  UINT8 ES008_u8_EPSSupplyVltgADCFault_st;
  UINT8 ES008_u8_SbcSupplyVltgADCFault_st;
  UINT8 MF004_u8_ThermalProtectFault_st;
  UINT8 MF010_u8_MotStallLimitFault_st;
  UINT8 MC005_u8_IPCHeartBeatSignalFault_st;
  UINT8 MC001_u8_VCANBusoff_st;
  UINT8 MC001_u8_PrivateCANFault_st;
  UINT8 MC001_u8_LDCUMsgMissingFault_st;
  UINT8 MC001_u8_ESPMsgMissingFault_st;
  UINT8 MC001_u8_CDCUMsgMissingFault_st;
  UINT8 MC001_u8_MFSMsgMissingFault_st;
  UINT8 MC001_u8_XPUMsgMissingFault_st;
  UINT8 MC001_u8_DPBMsgMissingFault_st;
  UINT8 MC001_u8_XPUMsg1E2EFault_st;
  UINT8 MC001_u8_ESPMsg1E2EFault_st;
  UINT8 MC001_u8_MFSMsg1E2EFault_st;
  UINT8 MC001_u8_LDCUMsg1E2EFault_st;
  UINT8 MC001_u8_CDCUMsg1E2EFault_st;
  UINT8 MC001_u8_LDCUMsg2E2EFault_st;
  UINT8 MC001_u8_ESPMsg2E2EFault_st;
  UINT8 MC001_u8_LDCUMsg3E2EFault_st;
  UINT8 MC001_u8_DPBMsg1E2EFault_st;
  UINT8 MC001_u8_XPUSignal1Fault_st;
  UINT8 MC001_u8_ESPSignal1Fault_st;
  UINT8 MC001_u8_MFSSignal1Fault_st;
  UINT8 MC001_u8_ESPSignal2Fault_st;
  UINT8 MC001_u8_ESPSignal3Fault_st;
  UINT8 MC001_u8_ESPSignal4Fault_st;
  UINT8 MC001_u8_LDCUSignal1Fault_st;
  UINT8 MC001_u8_DPBSignal1Fault_st;
  UINT8 MC001_u8_LDCUSignal2Fault_st;
  UINT8 MC001_u8_LDCUSignal3Fault_st;
  UINT8 MC001_u8_LDCUSignal4Fault_st;
  UINT8 SF035_u8_ChatterRednAssiFault_st;
  UINT8 SF022_u8_EOTNotLearnedFault_st;
  UINT8 SF026_u8_MecFricTooHiFault_st;
  UINT8 SF010_u8_SysStErrorFault_st;
  UINT8 ES003_u8_MotAgCalibrationFault_st;
  UINT8 SF012_u8_RCOModlErrorFault_st;
  UINT8 SF010_u8_SysStSyncErrorFault_st;

  (void)Rte_Read_DiagStatus_AbnormalResetFault_st_gdu8(&DiagStatus_AbnormalResetFault_st);
  (void)Rte_Read_DiagStatus_RAMErrFault_st_gdu8(&DiagStatus_RAMErrFault_st);
  (void)Rte_Read_DiagStatus_PFlsErrFault_st_gdu8(&DiagStatus_PFlsErrFault_st);
  (void)Rte_Read_DiagStatus_DFlsErrFault_st_gdu8(&DiagStatus_DFlsErrFault_st);
  (void)Rte_Read_DiagStatus_eepromFatalFault_st_gdu8(&DiagStatus_eepromFatalFault_st);
  (void)Rte_Read_DiagStatus_MCUFataFault_st_gdu8(&DiagStatus_MCUFataFault_st);
  (void)Rte_Read_DiagStatus_OsFatalFault_st_gdu8(&DiagStatus_OsFatalFault_st);
  (void)Rte_Read_DiagStatus_PMICVpreFault_st_gdu8(&DiagStatus_PMICVpreFault_st);
  (void)Rte_Read_DiagStatus_PMICVcoreFault_st_gdu8(&DiagStatus_PMICVcoreFault_st);
  (void)Rte_Read_DiagStatus_PMICAdcFault_st_gdu8(&DiagStatus_PMICAdcFault_st);
  (void)Rte_Read_DiagStatus_PMICTasFault_st_gdu8(&DiagStatus_PMICTasFault_st);
  (void)Rte_Read_DiagStatus_PMICCanVFault_st_gdu8(&DiagStatus_PMICCanVFault_st);
  (void)Rte_Read_DiagStatus_PMICSPIFault_st_gdu8(&DiagStatus_PMICSPIFault_st);
  (void)Rte_Read_DiagStatus_PMICGenFault_st_gdu8(&DiagStatus_PMICGenFault_st);
  (void)Rte_Read_DiagStatus_GDUGenFault_st_gdu8(&DiagStatus_GDUGenFault_st);
  (void)Rte_Read_DiagStatus_GDUVoltCompFault_st_gdu8(&DiagStatus_GDUVoltCompFault_st);
  (void)Rte_Read_DiagStatus_GDUCurrFault_st_gdu8(&DiagStatus_GDUCurrFault_st);
  (void)Rte_Read_DiagStatus_GDUCommFault_st_gdu8(&DiagStatus_GDUCommFault_st);
  (void)Rte_Read_DiagStatus_GDUPhaseAFault_st_gdu8(&DiagStatus_GDUPhaseAFault_st);
  (void)Rte_Read_DiagStatus_GDUPhaseBFault_st_gdu8(&DiagStatus_GDUPhaseBFault_st);
  (void)Rte_Read_DiagStatus_GDUPhaseCFault_st_gdu8(&DiagStatus_GDUPhaseCFault_st);
  (void)Rte_Read_DiagStatus_GDUSelfFault_st_gdu8(&DiagStatus_GDUSelfFault_st);
  (void)Rte_Read_ES014_u8_MotAnAgCorrFault_st_gdu8(&ES014_u8_MotAnAgCorrFault_st);
  (void)Rte_Read_ES013_u8_MotAnAgMeasFault_st_gdu8(&ES013_u8_MotAnAgMeasFault_st);
  (void)Rte_Read_ES013_u8_MotAnAgPSinFault_st_gdu8(&ES013_u8_MotAnAgPSinFault_st);
  (void)Rte_Read_ES013_u8_MotAnAgPCosFault_st_gdu8(&ES013_u8_MotAnAgPCosFault_st);
  (void)Rte_Read_ES013_u8_MotAnAgNSinFault_st_gdu8(&ES013_u8_MotAnAgNSinFault_st);
  (void)Rte_Read_ES013_u8_MotAnAgNCosFault_st_gdu8(&ES013_u8_MotAnAgNCosFault_st);
  (void)Rte_Read_MF005_u8_AbnormalMotCtrlFault_st_gdu8(&MF005_u8_AbnormalMotCtrlFault_st);
  (void)Rte_Read_ES008_u8_GDRefVltgErrorFault_st_gdu8(&ES008_u8_GDRefVltgErrorFault_st);
  (void)Rte_Read_ES005_u8_MotCurrMeasFault_st_gdu8(&ES005_u8_MotCurrMeasFault_st);
  (void)Rte_Read_ES005_u8_MotCurrAMeasFault_st_gdu8(&ES005_u8_MotCurrAMeasFault_st);
  (void)Rte_Read_ES005_u8_MotCurrBMeasFault_st_gdu8(&ES005_u8_MotCurrBMeasFault_st);
  (void)Rte_Read_ES005_u8_MotCurrCMeasFault_st_gdu8(&ES005_u8_MotCurrCMeasFault_st);
  (void)Rte_Read_DiagStatus_MCUFault_st_gdu8(&DiagStatus_MCUFault_st);
  (void)Rte_Read_ES001_u8_TasSent1SignalFault_st_gdu8(&ES001_u8_TasSent1SignalFault_st);
  (void)Rte_Read_ES001_u8_TasSent1ProtFault_st_gdu8(&ES001_u8_TasSent1ProtFault_st);
  (void)Rte_Read_ES001_u8_HwAgAOverLimFault_st_gdu8(&ES001_u8_HwAgAOverLimFault_st);
  (void)Rte_Read_ES010_u8_TasSent2SignalFault_st_gdu8(&ES010_u8_TasSent2SignalFault_st);
  (void)Rte_Read_ES010_u8_TasSent2ProtFault_st_gdu8(&ES010_u8_TasSent2ProtFault_st);
  (void)Rte_Read_ES010_u8_HwAgBOverLimFault_st_gdu8(&ES010_u8_HwAgBOverLimFault_st);
  (void)Rte_Read_ES008_u8_PeriVltgErrorFault_st_gdu8(&ES008_u8_PeriVltgErrorFault_st);
  (void)Rte_Read_ES002_u8_HwTqCorrFault_st_gdu8(&ES002_u8_HwTqCorrFault_st);
  (void)Rte_Read_DiagStatus_SlightResetFault_st_gdu8(&DiagStatus_SlightResetFault_st);
  (void)Rte_Read_DiagStatus_eepromSlightFault_st_gdu8(&DiagStatus_eepromSlightFault_st);
  (void)Rte_Read_ES011_u8_TasSent5SignalFault_st_gdu8(&ES011_u8_TasSent5SignalFault_st);
  (void)Rte_Read_ES012_u8_HwAgCorrFault_st_gdu8(&ES012_u8_HwAgCorrFault_st);
  (void)Rte_Read_ES011_u8_TasSent5ProtFault_st_gdu8(&ES011_u8_TasSent5ProtFault_st);
  (void)Rte_Read_ES012_u8_HwAgCalibrationFault_st_gdu8(&ES012_u8_HwAgCalibrationFault_st);
  (void)Rte_Read_MC005_u8_IMC1Fault_st_gdu8(&MC005_u8_IMC1Fault_st);
  (void)Rte_Read_MC005_u8_IMC2Fault_st_gdu8(&MC005_u8_IMC2Fault_st);
  (void)Rte_Read_ES008_u8_HiVltgErrorFault_st_gdu8(&ES008_u8_HiVltgErrorFault_st);
  (void)Rte_Read_ES008_u8_HiVltgFatalErrorFault_st_gdu8(&ES008_u8_HiVltgFatalErrorFault_st);
  (void)Rte_Read_ES008_u8_LowVltgErrorFault_st_gdu8(&ES008_u8_LowVltgErrorFault_st);
  (void)Rte_Read_ES008_u8_LowVltgFatalErrorFault_st_gdu8(&ES008_u8_LowVltgFatalErrorFault_st);
  (void)Rte_Read_ES008_u8_VltgCorrErrorSlightFault_st_gdu8(&ES008_u8_VltgCorrErrorSlightFault_st);
  (void)Rte_Read_ES008_u8_VltgCorrErrorFatalFault_st_gdu8(&ES008_u8_VltgCorrErrorFatalFault_st);
  (void)Rte_Read_ES007_u8_TempNTC1Fault_st_gdu8(&ES007_u8_TempNTC1Fault_st);
  (void)Rte_Read_ES007_u8_TempNTC2Fault_st_gdu8(&ES007_u8_TempNTC2Fault_st);
  (void)Rte_Read_ES007_u8_TempNTCCorrFault_st_gdu8(&ES007_u8_TempNTCCorrFault_st);
  (void)Rte_Read_ES008_u8_MotBrdgVltgADCFault_st_gdu8(&ES008_u8_MotBrdgVltgADCFault_st);
  (void)Rte_Read_ES008_u8_EPSSupplyVltgADCFault_st_gdu8(&ES008_u8_EPSSupplyVltgADCFault_st);
  (void)Rte_Read_ES008_u8_SbcSupplyVltgADCFault_st_gdu8(&ES008_u8_SbcSupplyVltgADCFault_st);
  (void)Rte_Read_MF004_u8_ThermalProtectFault_st_gdu8(&MF004_u8_ThermalProtectFault_st);
  (void)Rte_Read_MF010_u8_MotStallLimitFault_st_gdu8(&MF010_u8_MotStallLimitFault_st);
  (void)Rte_Read_MC005_u8_IPCHeartBeatSignalFault_st_gdu8(&MC005_u8_IPCHeartBeatSignalFault_st);
  (void)Rte_Read_MC001_u8_VCANBusoff_st_gdu8(&MC001_u8_VCANBusoff_st);
  (void)Rte_Read_MC001_u8_PrivateCANFault_st_gdu8(&MC001_u8_PrivateCANFault_st);
  (void)Rte_Read_MC001_u8_LDCUMsgMissingFault_st_gdu8(&MC001_u8_LDCUMsgMissingFault_st);
  (void)Rte_Read_MC001_u8_ESPMsgMissingFault_st_gdu8(&MC001_u8_ESPMsgMissingFault_st);
  (void)Rte_Read_MC001_u8_CDCUMsgMissingFault_st_gdu8(&MC001_u8_CDCUMsgMissingFault_st);
  (void)Rte_Read_MC001_u8_MFSMsgMissingFault_st_gdu8(&MC001_u8_MFSMsgMissingFault_st);
  (void)Rte_Read_MC001_u8_XPUMsgMissingFault_st_gdu8(&MC001_u8_XPUMsgMissingFault_st);
  (void)Rte_Read_MC001_u8_DPBMsgMissingFault_st_gdu8(&MC001_u8_DPBMsgMissingFault_st);
  (void)Rte_Read_MC001_u8_XPUMsg1E2EFault_st_gdu8(&MC001_u8_XPUMsg1E2EFault_st);
  (void)Rte_Read_MC001_u8_ESPMsg1E2EFault_st_gdu8(&MC001_u8_ESPMsg1E2EFault_st);
  (void)Rte_Read_MC001_u8_MFSMsg1E2EFault_st_gdu8(&MC001_u8_MFSMsg1E2EFault_st);
  (void)Rte_Read_MC001_u8_LDCUMsg1E2EFault_st_gdu8(&MC001_u8_LDCUMsg1E2EFault_st);
  (void)Rte_Read_MC001_u8_CDCUMsg1E2EFault_st_gdu8(&MC001_u8_CDCUMsg1E2EFault_st);
  (void)Rte_Read_MC001_u8_LDCUMsg2E2EFault_st_gdu8(&MC001_u8_LDCUMsg2E2EFault_st);
  (void)Rte_Read_MC001_u8_ESPMsg2E2EFault_st_gdu8(&MC001_u8_ESPMsg2E2EFault_st);
  (void)Rte_Read_MC001_u8_LDCUMsg3E2EFault_st_gdu8(&MC001_u8_LDCUMsg3E2EFault_st);
  (void)Rte_Read_MC001_u8_DPBMsg1E2EFault_st_gdu8(&MC001_u8_DPBMsg1E2EFault_st);
  (void)Rte_Read_MC001_u8_XPUSignal1Fault_st_gdu8(&MC001_u8_XPUSignal1Fault_st);
  (void)Rte_Read_MC001_u8_ESPSignal1Fault_st_gdu8(&MC001_u8_ESPSignal1Fault_st);
  (void)Rte_Read_MC001_u8_MFSSignal1Fault_st_gdu8(&MC001_u8_MFSSignal1Fault_st);
  (void)Rte_Read_MC001_u8_ESPSignal2Fault_st_gdu8(&MC001_u8_ESPSignal2Fault_st);
  (void)Rte_Read_MC001_u8_ESPSignal3Fault_st_gdu8(&MC001_u8_ESPSignal3Fault_st);
  (void)Rte_Read_MC001_u8_ESPSignal4Fault_st_gdu8(&MC001_u8_ESPSignal4Fault_st);
  (void)Rte_Read_MC001_u8_LDCUSignal1Fault_st_gdu8(&MC001_u8_LDCUSignal1Fault_st);
  (void)Rte_Read_MC001_u8_DPBSignal1Fault_st_gdu8(&MC001_u8_DPBSignal1Fault_st);
  (void)Rte_Read_MC001_u8_LDCUSignal2Fault_st_gdu8(&MC001_u8_LDCUSignal2Fault_st);
  (void)Rte_Read_MC001_u8_LDCUSignal3Fault_st_gdu8(&MC001_u8_LDCUSignal3Fault_st);
  (void)Rte_Read_MC001_u8_LDCUSignal4Fault_st_gdu8(&MC001_u8_LDCUSignal4Fault_st);
  (void)Rte_Read_SF035_u8_ChatterRednAssiFault_st_gdu8(&SF035_u8_ChatterRednAssiFault_st);
  (void)Rte_Read_SF022_u8_EOTNotLearnedFault_st_gdu8(&SF022_u8_EOTNotLearnedFault_st);
  (void)Rte_Read_SF026_u8_MecFricTooHiFault_st_gdu8(&SF026_u8_MecFricTooHiFault_st);
  (void)Rte_Read_SF010_u8_SysStErrorFault_st_gdu8(&SF010_u8_SysStErrorFault_st);
  (void)Rte_Read_ES003_u8_MotAgCalibrationFault_st_gdu8(&ES003_u8_MotAgCalibrationFault_st);
  (void)Rte_Read_SF012_u8_RCOModlErrorFault_st_gdu8(&SF012_u8_RCOModlErrorFault_st);
  (void)Rte_Read_SF010_u8_SysStSyncErrorFault_st_gdu8(&SF010_u8_SysStSyncErrorFault_st);

  if ((DiagStatus_AbnormalResetFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_AbnormalResetFault_st, *ret);
  }
  else if ((DiagStatus_AbnormalResetFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_RAMErrFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_RAMErrFault_st, *ret);
  }
  else if ((DiagStatus_RAMErrFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_PFlsErrFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_PFlsErrFault_st, *ret);
  }
  else if ((DiagStatus_PFlsErrFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_DFlsErrFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_DFlsErrFault_st, *ret);
  }
  else if ((DiagStatus_DFlsErrFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_eepromFatalFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_eepromFatalFault_st, *ret);
  }
  else if ((DiagStatus_eepromFatalFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_MCUFataFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_MCUFataFault_st, *ret);
  }
  else if ((DiagStatus_MCUFataFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_OsFatalFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_OsFatalFault_st, *ret);
  }
  else if ((DiagStatus_OsFatalFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_PMICVpreFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_PMICVpreFault_st, *ret);
  }
  else if ((DiagStatus_PMICVpreFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_PMICVcoreFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_PMICVcoreFault_st, *ret);
  }
  else if ((DiagStatus_PMICVcoreFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_PMICAdcFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_PMICAdcFault_st, *ret);
  }
  else if ((DiagStatus_PMICAdcFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_PMICTasFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_PMICTasFault_st, *ret);
  }
  else if ((DiagStatus_PMICTasFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_PMICCanVFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_PMICCanVFault_st, *ret);
  }
  else if ((DiagStatus_PMICCanVFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_PMICSPIFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_PMICSPIFault_st, *ret);
  }
  else if ((DiagStatus_PMICSPIFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_PMICGenFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_PMICGenFault_st, *ret);
  }
  else if ((DiagStatus_PMICGenFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_GDUGenFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_GDUGenFault_st, *ret);
  }
  else if ((DiagStatus_GDUGenFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_GDUVoltCompFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_GDUVoltCompFault_st, *ret);
  }
  else if ((DiagStatus_GDUVoltCompFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_GDUCurrFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_GDUCurrFault_st, *ret);
  }
  else if ((DiagStatus_GDUCurrFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_GDUCommFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_GDUCommFault_st, *ret);
  }
  else if ((DiagStatus_GDUCommFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_GDUPhaseAFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_GDUPhaseAFault_st, *ret);
  }
  else if ((DiagStatus_GDUPhaseAFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_GDUPhaseBFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_GDUPhaseBFault_st, *ret);
  }
  else if ((DiagStatus_GDUPhaseBFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_GDUPhaseCFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_GDUPhaseCFault_st, *ret);
  }
  else if ((DiagStatus_GDUPhaseCFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_GDUSelfFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_GDUSelfFault_st, *ret);
  }
  else if ((DiagStatus_GDUSelfFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES014_u8_MotAnAgCorrFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES014_u8_MotAnAgCorrFault_st, *ret);
  }
  else if ((ES014_u8_MotAnAgCorrFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES013_u8_MotAnAgMeasFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES013_u8_MotAnAgMeasFault_st, *ret);
  }
  else if ((ES013_u8_MotAnAgMeasFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES013_u8_MotAnAgPSinFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES013_u8_MotAnAgPSinFault_st, *ret);
  }
  else if ((ES013_u8_MotAnAgPSinFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES013_u8_MotAnAgPCosFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES013_u8_MotAnAgPCosFault_st, *ret);
  }
  else if ((ES013_u8_MotAnAgPCosFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES013_u8_MotAnAgNSinFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES013_u8_MotAnAgNSinFault_st, *ret);
  }
  else if ((ES013_u8_MotAnAgNSinFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES013_u8_MotAnAgNCosFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES013_u8_MotAnAgNCosFault_st, *ret);
  }
  else if ((ES013_u8_MotAnAgNCosFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MF005_u8_AbnormalMotCtrlFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MF005_u8_AbnormalMotCtrlFault_st, *ret);
  }
  else if ((MF005_u8_AbnormalMotCtrlFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_GDRefVltgErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_GDRefVltgErrorFault_st, *ret);
  }
  else if ((ES008_u8_GDRefVltgErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES005_u8_MotCurrMeasFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES005_u8_MotCurrMeasFault_st, *ret);
  }
  else if ((ES005_u8_MotCurrMeasFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES005_u8_MotCurrAMeasFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES005_u8_MotCurrAMeasFault_st, *ret);
  }
  else if ((ES005_u8_MotCurrAMeasFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES005_u8_MotCurrBMeasFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES005_u8_MotCurrBMeasFault_st, *ret);
  }
  else if ((ES005_u8_MotCurrBMeasFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES005_u8_MotCurrCMeasFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES005_u8_MotCurrCMeasFault_st, *ret);
  }
  else if ((ES005_u8_MotCurrCMeasFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_MCUFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_MCUFault_st, *ret);
  }
  else if ((DiagStatus_MCUFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES001_u8_TasSent1SignalFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES001_u8_TasSent1SignalFault_st, *ret);
  }
  else if ((ES001_u8_TasSent1SignalFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES001_u8_TasSent1ProtFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES001_u8_TasSent1ProtFault_st, *ret);
  }
  else if ((ES001_u8_TasSent1ProtFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES001_u8_HwAgAOverLimFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES001_u8_HwAgAOverLimFault_st, *ret);
  }
  else if ((ES001_u8_HwAgAOverLimFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES010_u8_TasSent2SignalFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES010_u8_TasSent2SignalFault_st, *ret);
  }
  else if ((ES010_u8_TasSent2SignalFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES010_u8_TasSent2ProtFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES010_u8_TasSent2ProtFault_st, *ret);
  }
  else if ((ES010_u8_TasSent2ProtFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES010_u8_HwAgBOverLimFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES010_u8_HwAgBOverLimFault_st, *ret);
  }
  else if ((ES010_u8_HwAgBOverLimFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_PeriVltgErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_PeriVltgErrorFault_st, *ret);
  }
  else if ((ES008_u8_PeriVltgErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES002_u8_HwTqCorrFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES002_u8_HwTqCorrFault_st, *ret);
  }
  else if ((ES002_u8_HwTqCorrFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_SlightResetFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_SlightResetFault_st, *ret);
  }
  else if ((DiagStatus_SlightResetFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((DiagStatus_eepromSlightFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, DiagStatus_eepromSlightFault_st, *ret);
  }
  else if ((DiagStatus_eepromSlightFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES011_u8_TasSent5SignalFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES011_u8_TasSent5SignalFault_st, *ret);
  }
  else if ((ES011_u8_TasSent5SignalFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES012_u8_HwAgCorrFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES012_u8_HwAgCorrFault_st, *ret);
  }
  else if ((ES012_u8_HwAgCorrFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES011_u8_TasSent5ProtFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES011_u8_TasSent5ProtFault_st, *ret);
  }
  else if ((ES011_u8_TasSent5ProtFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES012_u8_HwAgCalibrationFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES012_u8_HwAgCalibrationFault_st, *ret);
  }
  else if ((ES012_u8_HwAgCalibrationFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC005_u8_IMC1Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC005_u8_IMC1Fault_st, *ret);
  }
  else if ((MC005_u8_IMC1Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC005_u8_IMC2Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC005_u8_IMC2Fault_st, *ret);
  }
  else if ((MC005_u8_IMC2Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_HiVltgErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_HiVltgErrorFault_st, *ret);
  }
  else if ((ES008_u8_HiVltgErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_HiVltgFatalErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_HiVltgFatalErrorFault_st, *ret);
  }
  else if ((ES008_u8_HiVltgFatalErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_LowVltgErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_LowVltgErrorFault_st, *ret);
  }
  else if ((ES008_u8_LowVltgErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_LowVltgFatalErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_LowVltgFatalErrorFault_st, *ret);
  }
  else if ((ES008_u8_LowVltgFatalErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_VltgCorrErrorSlightFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_VltgCorrErrorSlightFault_st, *ret);
  }
  else if ((ES008_u8_VltgCorrErrorSlightFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_VltgCorrErrorFatalFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_VltgCorrErrorFatalFault_st, *ret);
  }
  else if ((ES008_u8_VltgCorrErrorFatalFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES007_u8_TempNTC1Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES007_u8_TempNTC1Fault_st, *ret);
  }
  else if ((ES007_u8_TempNTC1Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES007_u8_TempNTC2Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES007_u8_TempNTC2Fault_st, *ret);
  }
  else if ((ES007_u8_TempNTC2Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES007_u8_TempNTCCorrFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES007_u8_TempNTCCorrFault_st, *ret);
  }
  else if ((ES007_u8_TempNTCCorrFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_MotBrdgVltgADCFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_MotBrdgVltgADCFault_st, *ret);
  }
  else if ((ES008_u8_MotBrdgVltgADCFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_EPSSupplyVltgADCFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_EPSSupplyVltgADCFault_st, *ret);
  }
  else if ((ES008_u8_EPSSupplyVltgADCFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES008_u8_SbcSupplyVltgADCFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES008_u8_SbcSupplyVltgADCFault_st, *ret);
  }
  else if ((ES008_u8_SbcSupplyVltgADCFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MF004_u8_ThermalProtectFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MF004_u8_ThermalProtectFault_st, *ret);
  }
  else if ((MF004_u8_ThermalProtectFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MF010_u8_MotStallLimitFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MF010_u8_MotStallLimitFault_st, *ret);
  }
  else if ((MF010_u8_MotStallLimitFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC005_u8_IPCHeartBeatSignalFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC005_u8_IPCHeartBeatSignalFault_st, *ret);
  }
  else if ((MC005_u8_IPCHeartBeatSignalFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_VCANBusoff_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_VCANBusoff_st, *ret);
  }
  else if ((MC001_u8_VCANBusoff_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_PrivateCANFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_PrivateCANFault_st, *ret);
  }
  else if ((MC001_u8_PrivateCANFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_LDCUMsgMissingFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_LDCUMsgMissingFault_st, *ret);
  }
  else if ((MC001_u8_LDCUMsgMissingFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_ESPMsgMissingFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_ESPMsgMissingFault_st, *ret);
  }
  else if ((MC001_u8_ESPMsgMissingFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_CDCUMsgMissingFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_CDCUMsgMissingFault_st, *ret);
  }
  else if ((MC001_u8_CDCUMsgMissingFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_MFSMsgMissingFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_MFSMsgMissingFault_st, *ret);
  }
  else if ((MC001_u8_MFSMsgMissingFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_XPUMsgMissingFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_XPUMsgMissingFault_st, *ret);
  }
  else if ((MC001_u8_XPUMsgMissingFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_DPBMsgMissingFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_DPBMsgMissingFault_st, *ret);
  }
  else if ((MC001_u8_DPBMsgMissingFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_XPUMsg1E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_XPUMsg1E2EFault_st, *ret);
  }
  else if ((MC001_u8_XPUMsg1E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_ESPMsg1E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_ESPMsg1E2EFault_st, *ret);
  }
  else if ((MC001_u8_ESPMsg1E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_MFSMsg1E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_MFSMsg1E2EFault_st, *ret);
  }
  else if ((MC001_u8_MFSMsg1E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_LDCUMsg1E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_LDCUMsg1E2EFault_st, *ret);
  }
  else if ((MC001_u8_LDCUMsg1E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_CDCUMsg1E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_CDCUMsg1E2EFault_st, *ret);
  }
  else if ((MC001_u8_CDCUMsg1E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_LDCUMsg2E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_LDCUMsg2E2EFault_st, *ret);
  }
  else if ((MC001_u8_LDCUMsg2E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_ESPMsg2E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_ESPMsg2E2EFault_st, *ret);
  }
  else if ((MC001_u8_ESPMsg2E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_LDCUMsg3E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_LDCUMsg3E2EFault_st, *ret);
  }
  else if ((MC001_u8_LDCUMsg3E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_DPBMsg1E2EFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_DPBMsg1E2EFault_st, *ret);
  }
  else if ((MC001_u8_DPBMsg1E2EFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_XPUSignal1Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_XPUSignal1Fault_st, *ret);
  }
  else if ((MC001_u8_XPUSignal1Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_ESPSignal1Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_ESPSignal1Fault_st, *ret);
  }
  else if ((MC001_u8_ESPSignal1Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_MFSSignal1Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_MFSSignal1Fault_st, *ret);
  }
  else if ((MC001_u8_MFSSignal1Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_ESPSignal2Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_ESPSignal2Fault_st, *ret);
  }
  else if ((MC001_u8_ESPSignal2Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_ESPSignal3Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_ESPSignal3Fault_st, *ret);
  }
  else if ((MC001_u8_ESPSignal3Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_ESPSignal4Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_ESPSignal4Fault_st, *ret);
  }
  else if ((MC001_u8_ESPSignal4Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_LDCUSignal1Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_LDCUSignal1Fault_st, *ret);
  }
  else if ((MC001_u8_LDCUSignal1Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_DPBSignal1Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_DPBSignal1Fault_st, *ret);
  }
  else if ((MC001_u8_DPBSignal1Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_LDCUSignal2Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_LDCUSignal2Fault_st, *ret);
  }
  else if ((MC001_u8_LDCUSignal2Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_LDCUSignal3Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_LDCUSignal3Fault_st, *ret);
  }
  else if ((MC001_u8_LDCUSignal3Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((MC001_u8_LDCUSignal4Fault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, MC001_u8_LDCUSignal4Fault_st, *ret);
  }
  else if ((MC001_u8_LDCUSignal4Fault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((SF035_u8_ChatterRednAssiFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, SF035_u8_ChatterRednAssiFault_st, *ret);
  }
  else if ((SF035_u8_ChatterRednAssiFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((SF022_u8_EOTNotLearnedFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, SF022_u8_EOTNotLearnedFault_st, *ret);
  }
  else if ((SF022_u8_EOTNotLearnedFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((SF026_u8_MecFricTooHiFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, SF026_u8_MecFricTooHiFault_st, *ret);
  }
  else if ((SF026_u8_MecFricTooHiFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((SF010_u8_SysStErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, SF010_u8_SysStErrorFault_st, *ret);
  }
  else if ((SF010_u8_SysStErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((ES003_u8_MotAgCalibrationFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, ES003_u8_MotAgCalibrationFault_st, *ret);
  }
  else if ((ES003_u8_MotAgCalibrationFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((SF012_u8_RCOModlErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, SF012_u8_RCOModlErrorFault_st, *ret);
  }
  else if ((SF012_u8_RCOModlErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  if ((SF010_u8_SysStSyncErrorFault_st >= 1U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 0U))
  {
    TriggerFault(Monr_SF020_u8_SysFaultIndex_UL, SF010_u8_SysStSyncErrorFault_st, *ret);
  }
  else if ((SF010_u8_SysStSyncErrorFault_st == 0U) && (Monr_SF020_b_SysFaultStatus_UL[Monr_SF020_u8_SysFaultIndex_UL] == 1U))
  {
    RecoverFault(Monr_SF020_u8_SysFaultIndex_UL, *ret);
  }
  else
  {
    /* no action */
  }
  Monr_SF020_u8_SysFaultIndex_UL++;

  /* CODEGEN_MERGED_CODE_END */

  /* local block i/o variables */
  float32 rtb_DataStoreRead1_mxfa;
  uint8 rtb_DataStoreRead2_hyp3;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SF020_SysFaultMngt_Cycle_5ms' incorporates:
   *  SubSystem: '<Root>/SF020_SysFaultMngt_Cycle_5ms_sys'
   */
  /* Outport: '<Root>/SF020_u8_SysFaultLevel_UL_gdu8' incorporates:
   *  Constant: '<S3>/Constant'
   */
  (void)Rte_Write_SF020_u8_SysFaultLevel_UL_gdu8((UINT8)((uint8)
    Con_XPSbW_u8_Zero_UL));

  /* Outport: '<Root>/SF020_b_SysFaultStatusArray_UL_BOOLArrayB256' incorporates:
   *  DataStoreRead: '<S3>/Data Store Read'
   */
  (void)memcpy
    (&SF020_SysFaultMngt_ARID_DEF.SF020_b_SysFaultStatusArray_UL_BOOLArrayB256[0],
     &Monr_SF020_b_SysFaultStatus_UL[0], (sizeof(BOOLEAN)) << 8U);

  /* Outport: '<Root>/SF020_f32_SysAssDegradeFactor_UL_gdf32' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  (void)Rte_Write_SF020_f32_SysAssDegradeFactor_UL_gdf32((FLOAT32)
    Con_XPSbW_f32_One_UL);

  /* Outport: '<Root>/SF020_u8_MotCtrlAssistType_UL_gdu8' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  (void)Rte_Write_SF020_u8_MotCtrlAssistType_UL_gdu8((UINT8)((uint8)
    Con_XPSbW_u8_Zero_UL));

  /* DataStoreRead: '<S3>/Data Store Read1' */
  rtb_DataStoreRead1_mxfa = Monr_SF020_f32_SysFaultDegFactor_UL;

  /* DataStoreRead: '<S3>/Data Store Read2' */
  rtb_DataStoreRead2_hyp3 = Monr_SF020_u8_SysAssistType_UL;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SF020_SysFaultMngt_Cycle_5ms' */
  (void)Rte_Write_SF020_b_SysFaultStatusArray_UL_BOOLArrayB256
    (SF020_SysFaultMngt_ARID_DEF.SF020_b_SysFaultStatusArray_UL_BOOLArrayB256);
}

/* Output function */
void RecoverFault(uint8 XtcId, boolean *Ret)
{
  /* local block i/o variables */
  uint8 rtb_DiagnosticMonitorCaller;
  boolean rtb_Merge;

  /* Outputs for Function Call SubSystem: '<Root>/RecoverFault' */
  /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
   *  Constant: '<S2>/Constant'
   */
  Monr_SF020_u8_SysFaultProxyPara_UL = ((uint8)Con_XPSbW_u8_Zero_UL);

  /* If: '<S2>/If1' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read1'
   *  Selector: '<S2>/Selector1'
   *  SignalConversion generated from: '<S2>/XtcId'
   */
  if (Monr_SF020_b_SysFaultStatus_UL[(XtcId)]) {
    /* Outputs for IfAction SubSystem: '<S2>/XTCRecover' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* If: '<S8>/If' incorporates:
     *  ArithShift: '<S8>/Shift Arithmetic2'
     *  Constant: '<S11>/Constant'
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/Constant2'
     *  DataTypeConversion: '<S8>/Data Type Conversion1'
     *  FunctionCaller: '<S10>/DiagnosticMonitorCaller'
     *  S-Function (sfix_bitop): '<S8>/Bitwise Operator1'
     *  Selector: '<S8>/Selector1'
     */
    if (((CalT_XPSbW_u32_FaultMfgTable_UL[(XtcId)] >> ((uint32)
           CalC_XPSbW_u8_FaultRecoverableBitPos_UL)) & 1U) != 0U) {
      /* Outputs for IfAction SubSystem: '<S8>/RecoverXTC' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Assignment: '<S10>/Assignment' incorporates:
       *  Constant: '<S10>/Constant'
       *  DataStoreWrite: '<S10>/Data Store Write1'
       */
      Monr_SF020_b_SysFaultStatus_UL[(XtcId)] = Con_XPSbW_b_False_UL;

      /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
       *  DataStoreWrite: '<S10>/Data Store Write2'
       *  S-Function (sfix_bitop): '<S10>/Bitwise Operator1'
       */
      Monr_SF020_u8_DTCIndex_UL = (uint8)(CalT_XPSbW_u32_FaultMfgTable_UL[(XtcId)]
        & 255U);

      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S10>/Constant1'
       *  SignalConversion generated from: '<S10>/Ret'
       */
      rtb_Merge = Con_XPSbW_b_True_UL;
      rtb_DiagnosticMonitorCaller = Rte_Call_DiagnosticMonitor_SetEventStatus
        (DEM_EVENT_STATUS_PASSED);

      /* End of Outputs for SubSystem: '<S8>/RecoverXTC' */
    } else {
      /* Outputs for IfAction SubSystem: '<S8>/DoNothing' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S9>/Constant3'
       *  SignalConversion generated from: '<S9>/Ret'
       */
      rtb_Merge = Con_XPSbW_b_False_UL;

      /* End of Outputs for SubSystem: '<S8>/DoNothing' */
    }

    /* End of If: '<S8>/If' */
    /* End of Outputs for SubSystem: '<S2>/XTCRecover' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/NoXTCRecover' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    SF020_SysFaultMngt_NoXTCRecover(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S2>/NoXTCRecover' */
  }

  /* End of If: '<S2>/If1' */

  /* SignalConversion generated from: '<S2>/Ret' */
  *Ret = rtb_Merge;

  /* End of Outputs for SubSystem: '<Root>/RecoverFault' */
}

/* Output function */
void TriggerFault(uint8 XtcId, uint8 Para, boolean *Ret)
{
  /* local block i/o variables */
  uint8 rtb_DiagnosticMonitorCaller_dbyk;
  boolean rtb_Merge_nfic;

  /* Outputs for Function Call SubSystem: '<Root>/TriggerFault' */
  /* If: '<S5>/If' incorporates:
   *  DataStoreRead: '<S5>/Data Store Read1'
   *  Selector: '<S5>/Selector1'
   *  SignalConversion generated from: '<S5>/XtcId'
   */
  if (Monr_SF020_b_SysFaultStatus_UL[(XtcId)]) {
    /* Outputs for IfAction SubSystem: '<S5>/NoXTCTrigger' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* DataStoreWrite: '<S12>/Data Store Write' incorporates:
     *  Constant: '<S12>/Constant'
     */
    Monr_SF020_u8_SysFaultProxyPara_UL = ((uint8)Con_XPSbW_u8_Zero_UL);

    /* Merge: '<S5>/Merge' incorporates:
     *  Constant: '<S12>/Constant3'
     *  SignalConversion generated from: '<S12>/Ret'
     */
    rtb_Merge_nfic = Con_XPSbW_b_False_UL;

    /* End of Outputs for SubSystem: '<S5>/NoXTCTrigger' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/XTCTrigger' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* DataStoreWrite: '<S13>/Data Store Write' incorporates:
     *  SignalConversion generated from: '<S5>/Para'
     */
    Monr_SF020_u8_SysFaultProxyPara_UL = Para;

    /* If: '<S13>/If' incorporates:
     *  ArithShift: '<S13>/Shift Arithmetic2'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S16>/Constant'
     *  DataTypeConversion: '<S13>/Data Type Conversion3'
     *  FunctionCaller: '<S15>/DiagnosticMonitorCaller'
     *  S-Function (sfix_bitop): '<S13>/Bitwise Operator1'
     *  Selector: '<S13>/Selector1'
     */
    if (((CalT_XPSbW_u32_FaultMfgTable_UL[(XtcId)] >> ((uint32)
           CalC_XPSbW_u8_FaultMfgInhabitBitPos_UL)) & 1U) != 0U) {
      /* Outputs for IfAction SubSystem: '<S13>/DoNothing' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      SF020_SysFaultMngt_NoXTCRecover(&rtb_Merge_nfic);

      /* End of Outputs for SubSystem: '<S13>/DoNothing' */
    } else {
      /* Outputs for IfAction SubSystem: '<S13>/XTCTrigger' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* Assignment: '<S15>/Assignment' incorporates:
       *  Constant: '<S15>/Constant'
       *  DataStoreWrite: '<S15>/Data Store Write'
       */
      Monr_SF020_b_SysFaultStatus_UL[(XtcId)] = Con_XPSbW_b_True_UL;

      /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
       *  DataStoreWrite: '<S15>/Data Store Write1'
       *  S-Function (sfix_bitop): '<S15>/Bitwise Operator1'
       */
      Monr_SF020_u8_DTCIndex_UL = (uint8)(CalT_XPSbW_u32_FaultMfgTable_UL[(XtcId)]
        & 255U);

      /* Merge: '<S5>/Merge' incorporates:
       *  Constant: '<S15>/Constant3'
       *  SignalConversion generated from: '<S15>/Ret'
       */
      rtb_Merge_nfic = Con_XPSbW_b_True_UL;
      rtb_DiagnosticMonitorCaller_dbyk =
        Rte_Call_DiagnosticMonitor_SetEventStatus(DEM_EVENT_STATUS_FAILED);

      /* End of Outputs for SubSystem: '<S13>/XTCTrigger' */
    }

    /* End of If: '<S13>/If' */
    /* End of Outputs for SubSystem: '<S5>/XTCTrigger' */
  }

  /* End of If: '<S5>/If' */

  /* SignalConversion generated from: '<S5>/Ret' */
  *Ret = rtb_Merge_nfic;

  /* End of Outputs for SubSystem: '<Root>/TriggerFault' */
}

/* Model initialize function */
void SF020_SysFaultMngt_Init(void)
{
  /* Registration code */

  /* states (dwork) */

  /* custom states */
  Monr_SF020_f32_SysFaultDegFactor_UL = 0.0F;
  Monr_SF020_u8_SysFaultIndex_UL = 0U;
  Monr_SF020_u8_SysAssistType_UL = 0U;
  Monr_SF020_u8_DTCIndex_UL = 0U;
  Monr_SF020_u8_SysFaultProxyPara_UL = 0U;

  {
    sint32 i;
    for (i = 0; i < 256; i++) {
      Monr_SF020_b_PreFaultStatusInput_UL[i] = false;
    }
  }

  {
    sint32 i;
    for (i = 0; i < 256; i++) {
      Monr_SF020_b_SysFaultStatus_UL[i] = false;
    }
  }

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  Monr_SF020_f32_SysFaultDegFactor_UL = 1.0F;

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SF020_SysFaultMngt_Cycle_5ms' incorporates:
   *  SubSystem: '<Root>/SF020_SysFaultMngt_Cycle_5ms_sys'
   */
  /* Start for Outport: '<Root>/SF020_u8_SysFaultLevel_UL_gdu8' incorporates:
   *  Constant: '<S3>/Constant'
   */
  (void)Rte_Write_SF020_u8_SysFaultLevel_UL_gdu8((UINT8)((uint8)
    Con_XPSbW_u8_Zero_UL));

  /* Start for Outport: '<Root>/SF020_f32_SysAssDegradeFactor_UL_gdf32' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  (void)Rte_Write_SF020_f32_SysAssDegradeFactor_UL_gdf32((FLOAT32)
    Con_XPSbW_f32_One_UL);

  /* Start for Outport: '<Root>/SF020_u8_MotCtrlAssistType_UL_gdu8' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  (void)Rte_Write_SF020_u8_MotCtrlAssistType_UL_gdu8((UINT8)((uint8)
    Con_XPSbW_u8_Zero_UL));

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SF020_SysFaultMngt_Cycle_5ms' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
