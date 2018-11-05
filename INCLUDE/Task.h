#ifndef __TASK_H
#define __TASK_H

typedef enum {
  TASK_LOGIN            = 0x00,
  TASK_NORMAL           = 0x01,
  TASK_LOW_BATTERY      = 0x02,
  TASK_POWEROFF         = 0x03
}TASK_CODE;

typedef enum{
  BATTERY_HEALTH        = 0x00,
  BATTERY_LOW_LEVEL_1   = 0x01,
  BATTERY_LOW_LEVEL_2   = 0x02,
  BATTERY_POWER_OFF     = 0x03
}BATTERY_TYPE;

typedef struct{
  TASK_CODE Id;
  u8 login_set_account;
  u8 login_step;
  BATTERY_TYPE battery_states;
}TaskDrv;

extern TaskDrv TaskDrvobj;

extern u8 Key_PersonalCalling_Flag;

extern void Task_Init(void);
extern void Task_login_progress(void);
extern void Task_normal_progress(void);
extern void Task_low_battery_progress(void);
extern void Task_PowerOff(void);

typedef enum{
  Key3_OptionZero       =       0x00,
  Key3_OptionOne        =       0x01,
  Key3_OptionTwo        =       0x02,
  Key3_OptionThree      =       0x03,
  Key3_OptionFour       =       0x04,
  Key3_OptionFive       =       0x05
}Key3_OptionType;



#if 0


extern void Task_PowerOnInitial(void);
extern bool task_status_account_config(void);
extern bool TASK_PersonalKeyMode(void);
extern void TASK_PersonalKeyModeSet(bool a);

TASKAPI bool KEY_4_Flag;

TASKAPI bool EnterPttMoment_Flag;
TASKAPI bool NoUseNum;
TASKAPI u8 NetworkType_2Gor3G_Flag;
TASKAPI bool TASK_Ptt_StartPersonCalling_Flag;
TASKAPI bool Task_Landing_Flag;
TASKAPI void Delay_100ms(u8 T);
TASKAPI u8 Key_PersonalCalling_Flag;
TASKAPI void Task_RunStart(void);
TASKAPI void Task_RunNormalOperation(void);
TASKAPI void TASK_WriteFreq(void);
TASKAPI void Task_RunNormalOperation(void);
TASKAPI void TASK_RunLoBattery(void);
TASKAPI u8 PersonCallIco_Flag;//������ʾ�������ͼ���ж�״̬
TASKAPI u8 TaskStartDeleteDelay1;
TASKAPI u8 TaskStartDeleteDelay2;
TASKAPI u8 TaskStartDeleteDelay3;
TASKAPI u8 TaskStartDeleteDelay4;
TASKAPI u8 TaskStartDeleteDelay5;
TASKAPI u8 TaskStartDeleteDelay6;
#endif

#endif