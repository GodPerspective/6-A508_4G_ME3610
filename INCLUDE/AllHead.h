#ifndef __ALLHEAD_H
#define __ALLHEAD_H

#include "stm8s.h"
#include <string.h>
#include "CommonLib.h"
#include "main.h"
#include "Task.h"
#include "sysclock.h"

#include "DrvMcuPin.h"
#include "DrvZM389.h"
#include "DrvUart1.h"

#include "ApiVoice.h"
#include "ApiAtCmd.h"
#include "ApiPocCmd.h"
#include "ApiDelay.h"
#include "ApiGpsCmd.h"
//功放
#include "DrvI2cAw87319.h"

//显示屏
#include "ApiDisplay.h"
#include "DrvHTG12832.h"
#include "DrvGT20L16S1Y.h"

//字库IC
#include "GT20L16P1Y.h"
#include "GT20L16P1Y_D.h"//字库补丁
#include "GT20L16P1Y2.h"//单字符补丁

//打卡解码-UTF8转UNICODE
#include "UTF8toUNICODE.h"

//写频
#include "DrvUart3.h"
#include "DrvEeprom.h"
#include "DataStructAddr.h"
#include "ApiMcuVersion.h"

//按键处理
#include "DrvKeyscan.h"
#include "ApiKeycmd.h"

//键盘处理
#include "DrvKeyboard.h"
#include "ApiKeyboard.h"

//菜单
#include "ApiMenu.h"

//电压检测
#include "ApiBattery.h"

//beep
#include "DrvBeep.h"
#include "DrvTone.h"

//LED
#include "ApiLED.h"

//使能英文语音
//#define CHINESE

#endif