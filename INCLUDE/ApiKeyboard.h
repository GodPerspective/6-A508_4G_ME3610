#ifndef __APIKEYBOARD_H
#define __APIKEYBOARD_H

extern u8 MenuMode_Flag;
extern u8 BacklightTimeSetCount;
extern u8 KeylockTimeSetCount;
extern s8 KeyPersonalCallingCount;//个呼上下键计数
extern s8 PersonalCallingNum;
extern u8 MenuModeCount;
extern s8 KeyUpDownCount;//组呼上下键计数
extern s8 GroupCallingNum;
extern u8 groupCallingcount;//由GroupCallingNum换算，范围0-4；
extern u8 user_calling_count;//由PersonalCallingNum换算，范围0-4；
extern u8 KeyDownUpChoose_GroupOrUser_Flag;
extern bool LockingState_EnterOK_Flag;
extern u8 TheMenuLayer_Flag;//所处菜单层级；默认状态：1 一级菜单：1 二级菜单：2
extern u8 network_count;

extern void ApiKeyboard_PowerOnInitial(void);
extern void keyboard_process(void);
extern void changing_group_voice_and_display(u8 a);
extern void changing_user_voice_and_display(u8 a);
extern void return_group_and_clear_flag(void);
extern void voice_tone(void);
#endif