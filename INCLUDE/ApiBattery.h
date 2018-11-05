#ifndef __APIBATTERY_H
#define __APIBATTERY_H

extern u8 BatteryLevel;
extern bool LobatteryTask_StartFlag;

extern void ADC_Init(void);
extern void ApiBattery_PowerOnInitial(void);
extern void LowVoltageDetection(void);
extern void KeyBatteryReport(void);

#endif