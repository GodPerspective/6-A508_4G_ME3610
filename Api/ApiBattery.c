//all UTF-8 done
#include "AllHead.h"

u8 BatteryLevel=0;
u8 Count=0;
u8 Count2=0;
u8 Count3=0;
bool LobatteryTask_StartFlag=FALSE;

static u16 OneChannelGetADValue(ADC2_Channel_TypeDef ADC2_Channel,\
  ADC2_SchmittTrigg_TypeDef ADC2_SchmittTriggerChannel);

void ADC_Init(void)
{
  ADC2_Init(ADC2_CONVERSIONMODE_CONTINUOUS , ADC2_CHANNEL_2, ADC2_PRESSEL_FCPU_D18,\
    ADC2_EXTTRIG_TIM, DISABLE, ADC2_ALIGN_RIGHT, ADC2_SCHMITTTRIG_CHANNEL10,DISABLE);
  ADC2_Cmd(ENABLE);
}

//ADC2单通道选择读取AD值
static u16 OneChannelGetADValue(ADC2_Channel_TypeDef ADC2_Channel,\
  ADC2_SchmittTrigg_TypeDef ADC2_SchmittTriggerChannel)
{
  uint16_t ADConversion_Value;
  /**< 连续转换模式 */
  /**< 使能通道 */
  /**< ADC时钟：fADC2 = fcpu/18 */
  /**< 这里设置了从TIM TRGO 启动转换，但实际是没有用到的*/
  /**  不使能 ADC2_ExtTriggerState**/
  /**< 转换数据右对齐 */
  /**< 不使能通道10的斯密特触发器 */
  /**  不使能通道10的斯密特触发器状态 */
  ADC2_Init(ADC2_CONVERSIONMODE_CONTINUOUS , ADC2_Channel, ADC2_PRESSEL_FCPU_D18,\
    ADC2_EXTTRIG_TIM, DISABLE, ADC2_ALIGN_RIGHT, ADC2_SchmittTriggerChannel,DISABLE);
  ADC2_Cmd(ENABLE);
  ADC2_StartConversion();
  ADConversion_Value = ADC2_GetConversionValue();
  return ADConversion_Value;
}

void ApiBattery_PowerOnInitial(void)
{
  BatteryLevel=0;
  Count=0;
  Count2=0;
  Count3=0;
  LobatteryTask_StartFlag=FALSE;
}

void LowVoltageDetection(void)
{
  u16 ADValue=0;

  ADValue=OneChannelGetADValue(ADC2_CHANNEL_2,ADC2_SCHMITTTRIG_CHANNEL2);
  
 if(TaskDrvobj.Id==TASK_LOGIN)
 {
   if(ADValue<=355&&ADValue>=200)
   {
     Count3++;
     if(Count3>100)
     {
       LobatteryTask_StartFlag=TRUE;
     } 
   }
   else
   {
     Count3=0;
   }
   
   if(ADValue<=350&&ADValue>=200)
   {
     if(MenuMode_Flag==0)
       api_disp_icoid_output( eICO_IDBATT , TRUE, TRUE);
     BatteryLevel=0;
   }//电池电量0级
   else if(ADValue<=360&&ADValue>350)
   {
     if(MenuMode_Flag==0)
       api_disp_icoid_output( eICO_IDBATT1, TRUE, TRUE);//图标：1格电池
     BatteryLevel=1;
   }//电池电量1级
   else if(ADValue<=375&&ADValue>365)
   {
     if(MenuMode_Flag==0)
       api_disp_icoid_output( eICO_IDBATT2, TRUE, TRUE);//图标：2格电池
     BatteryLevel=2;
   }//电池电量2级
   else if(ADValue<=390&&ADValue>380)
   {
     if(MenuMode_Flag==0)
       api_disp_icoid_output( eICO_IDBATT3, TRUE, TRUE);//图标：3格电池
     BatteryLevel=3;
   }//电池电量3级
   else if(ADValue<=405&&ADValue>395)
   {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT4, TRUE, TRUE);//图标：4格电池
        BatteryLevel=4;
   }//电池电量4级
   else if(ADValue<=500&&ADValue>410)
   {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT5, TRUE, TRUE);//图标：5格电池
        BatteryLevel=5;
   }//电池电量5级
   else{}
 }
 else
 {
    if(ADValue<=345&&ADValue>=200)//345为3.42播报
    {
      Count++;
      if(Count>=100)
      {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT, TRUE, TRUE);
        TaskDrvobj.Id=TASK_LOW_BATTERY;
        TaskDrvobj.battery_states=BATTERY_LOW_LEVEL_2;
        Count=0;
      }
    }
    else if(ADValue<=350&&ADValue>345)
    {
      Count2++;
      if(Count2>=100)
      {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT, TRUE, TRUE);
        BatteryLevel=0;
        TaskDrvobj.Id=TASK_NORMAL;
        TaskDrvobj.battery_states=BATTERY_LOW_LEVEL_1;
        Count2=0;
        
      }
    }
    else
    {
      TaskDrvobj.Id=TASK_NORMAL;
      if(ADValue<=350&&ADValue>=200)
      {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT , TRUE, TRUE);
        BatteryLevel=0;
      }//电池电量0级
      else if(ADValue<=360&&ADValue>350)
      {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT1, TRUE, TRUE);//图标：1格电池
        BatteryLevel=1;
      }//电池电量1级
      else if(ADValue<=375&&ADValue>365)
      {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT2, TRUE, TRUE);//图标：2格电池
        BatteryLevel=2;
      }//电池电量2级
      else if(ADValue<=390&&ADValue>380)
      {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT3, TRUE, TRUE);//图标：3格电池
        BatteryLevel=3;
      }//电池电量3级
      else if(ADValue<=405&&ADValue>395)
      {
        if(MenuMode_Flag==0)
        api_disp_icoid_output( eICO_IDBATT4, TRUE, TRUE);//图标：4格电池
        BatteryLevel=4;
      }//电池电量4级
      else if(ADValue<=500&&ADValue>410)
      {
        if(MenuMode_Flag==0)
          api_disp_icoid_output( eICO_IDBATT5, TRUE, TRUE);//图标：5格电池
        BatteryLevel=5;
      }//电池电量5级
      else
      {
      }
      if(TaskDrvobj.battery_states==BATTERY_LOW_LEVEL_2)//识别从低电量到高电量的状态
      {
        KEYCMD_PersonalKeyModeSet(FALSE);
        MenuMode_Flag=0;
        get_screen_display_group_name();////选择显示当前群组昵称（群组或单呼临时群组）
        KeyDownUpChoose_GroupOrUser_Flag=0;
        api_disp_icoid_output( eICO_IDMESSAGEOff, TRUE, TRUE);//图标：空-非选状态
        api_disp_all_screen_refresh();// 全屏统一刷新
        KeyUpDownCount=0;
        TaskDrvobj.battery_states=BATTERY_HEALTH;
      }
    }
  }
}
void KeyBatteryReport(void)
{
  switch(BatteryLevel)
  {
  case 0:
    VOICE_Play(FivePercentPower);//百分之五
    break;
  case 1:
    VOICE_Play(TwentyPercentPower);//百分之20
    break;
  case 2:
    VOICE_Play(FortyPercentPower);//百分之40
    break;
  case 3:
    VOICE_Play(SixtyPercentPower);//百分之60
    break;
  case 4:
    VOICE_Play(EightyPercentPower);//百分80
    break;
  case 5:
    VOICE_Play(OneHundredPercentPower);//百分百
    break;
  default:
    break;
  }

}