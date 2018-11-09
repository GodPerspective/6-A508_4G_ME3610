//all UTF-8 done
#include "AllHead.h"
u8 LED_Conut=0;

void ApiLED_PowerOnInitial(void)
{
  LED_Conut=0;
}
#if 0//rssi test
void LED_IntOutputRenew(void)
{
  if(ReadInput_PIN_RSSI!=0)
  {
    Set_GreenLed(ON);
  }
  else
  {
    Set_GreenLed(OFF);
  }
}
#else
void LED_IntOutputRenew(void)
{
  if(TaskDrvobj.Id==TASK_LOGIN)
  {
    LED_Conut++;
    if(LED_Conut==5)
    {
      Set_GreenLed(ON);
    }
    if(LED_Conut==8)
    {
      Set_GreenLed(OFF);
      LED_Conut=0;
    }
  }
  else
  {
    if(poc_receive_sos_statas()==TRUE)
    {
    }
    else
    {
      if(ApiPocCmd_ReceivedVoicePlayStatesForLED()==TRUE)
      {
        Set_GreenLed(ON);
        Set_RedLed(OFF);
      }
      else
      {
        LED_Conut++;
        if(LED_Conut>=49)
        {
          if(beidou_valid()==TRUE)
          {
            Set_RedLed(ON);
          }
          else
          {
            Set_GreenLed(ON);
          }
        }
        if(LED_Conut>=51)
        {
          Set_GreenLed(OFF);
          Set_RedLed(OFF);
          LED_Conut=0;
        }
        if(LED_Conut<=48)
        {
          Set_GreenLed(OFF);
          if(WriteFreq_Flag==TRUE)//解决读频红灯常亮的问题，应该是闪红灯
          {
            Set_RedLed(OFF);
          }
          else
          {
          }
        }
      }
    }
  }
}
#endif