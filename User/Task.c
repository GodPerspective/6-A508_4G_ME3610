#include "AllHead.h"

TaskDrv TaskDrvobj;
const u8 *cTxHardwareid         ="at^hardwareid=2,0";
u8 Key_PersonalCalling_Flag;

void Task_Init(void)
{
  TaskDrvobj.Id = TASK_LOGIN;
  TaskDrvobj.login_set_account=FALSE;
  TaskDrvobj.battery_states=BATTERY_HEALTH;
  TaskDrvobj.login_step=0;
}

void Task_login_progress(void)
{
  UART3_ToMcuMain();//读取写频数据
  switch(TaskDrvobj.login_step)
  {
  case 0:
    if(AtCmdDrvobj.Msg.Bits.bCommunicationTest==1)//开启上报回复
    {
      ApiAtCmd_WritCommand(ATCOMM_ATE1,0,0);//出货前将此处屏蔽，解决poc识别TX指令造成干扰
      ApiAtCmd_WritCommand(ATCOMM_CPIN,0,0);//查询SIM卡状态
      TaskDrvobj.login_step=1;
    }
    break;
  case 1:
    //api_lcd_pwr_on_hint(14,2,GBK,"-1");
    if(AtCmdDrvobj.Msg.Bits.bSimCardIn==1)//已插卡
    {
      VOICE_Play(ABELL);
      ApiAtCmd_WritCommand(ATCOMM_SetNetworkAuto,0,0);//默认设置为网络模式自动选择
      ApiAtCmd_WritCommand(ATCOMM_CREG,0,0);//查询网络注册状态
      TaskDrvobj.login_step=2;
    }
    break;
  case 2:
    //api_lcd_pwr_on_hint(14,2,GBK,"-2");
    if(AtCmdDrvobj.network_reg.creg==1||AtCmdDrvobj.network_reg.creg==5)//注册上网络
    {
      ApiPocCmd_WritCommand(PocComm_set_tone_volume,0,0);//打开POC应用
      ApiAtCmd_WritCommand(ATCOMM_ZPAS,0,0);//查询模块网络状态
      ApiPocCmd_WritCommand(PocComm_OpenPOC,0,0);//打开POC应用
      ApiPocCmd_WritCommand(PocComm_SetParam,0,0);//配置登录账号密码、IP
      ApiPocCmd_WritCommand(PocComm_SetURL,0,0);//设置URL
      VOICE_Play(LoggingIn);
      DISPLAY_Show(d_LoggingIn);
      TaskDrvobj.login_step=3;
    }
    break;
  default:
    //api_lcd_pwr_on_hint(14,2,GBK,"-7");
    break;
  }
}



void Task_normal_progress(void)
{
  UART3_ToMcuMain();//读取写频数据
  keyboard_process();
  key_process();

/***********判断正常进组；正常退出组;被单呼模式；退出单呼模式；主动开始单呼；单呼；主动退出单呼*************/
  if(get_current_working_status()==m_group_mode)//组呼模式
  {
    if(ApiPocCmd_GroupStates()==EnterGroup)
    {
      api_disp_icoid_output( eICO_IDPOWERM, TRUE, TRUE);//显示组呼图标
      api_lcd_pwr_on_hint(0,2,GBK,"                ");
      api_lcd_pwr_on_hint(0,2,UNICODE,GetNowWorkingGroupNameForDisplay());
      ApiPocCmd_GroupStatesSet(InGroup);
    }
    else if(ApiPocCmd_GroupStates()==InGroup)
    {
    }
    else//LeaveGroup
    {
    }
  }
  else //单呼模式
  {
    if(ApiPocCmd_GroupStates()==EnterGroup)
    {
      api_disp_icoid_output( eICO_IDPOWERH, TRUE, TRUE);//显示个呼图标
      DISPLAY_Show(d_individualcall);
      ApiPocCmd_GroupStatesSet(InGroup);
    }
    else if(ApiPocCmd_GroupStates()==InGroup)
    {
    }
    else//LeaveGroup
    {
    }
  }
  
/*********按PTT发射接收时的显示屏显示****************************************************************************************************************************/
  switch(ApiPocCmd_KeyPttState())//KeyPttState 0：未按PTT 1:按下ptt瞬间  2：按住PTT状态 3：松开PTT瞬间
  {
  case 0://未按PTT
    break;
  case 1://1:按下ptt瞬间
    ApiPocCmd_SetKeyPttState(2);
    voice_tone();
    api_disp_icoid_output( eICO_IDTX, TRUE, TRUE);//发射信号图标
    if(MenuMode_Flag!=0)
    {
      MenuDisplay(Menu_RefreshAllIco);
      MenuModeCount=1;
      TheMenuLayer_Flag=0;
      MenuMode_Flag=0;
      ApiMenu_SwitchGroup_Flag=0;
      ApiMenu_SwitchCallUser_Flag=0;
      ApiMenu_SwitchOnlineUser_Flag=0;
      ApiMenu_GpsInfo_Flag=0;
      ApiMenu_BacklightTimeSet_Flag=0;
      ApiMenu_KeylockTimeSet_Flag=0;
      ApiMenu_NativeInfo_Flag=0;
      ApiMenu_BeiDouOrWritingFrequency_Flag=0;
    }
    api_disp_all_screen_refresh();// 全屏统一刷新
    break;
  case 2://2：按住PTT状态
    //api_lcd_pwr_on_hint(0,2,UNICODE,GetSpeakingUserNameForDisplay());//显示本机正在讲话
    //api_disp_all_screen_refresh();// 全屏统一刷新
    break;
  case 3://3：松开PTT瞬间
    ApiPocCmd_SetKeyPttState(0);
    voice_tone();
    api_disp_icoid_output( eICO_IDTALKAR, TRUE, TRUE);//默认无发射无接收信号图标
    if(get_current_working_status()==m_group_mode)//组呼模式
    {
      api_lcd_pwr_on_hint(0,2,UNICODE,GetNowWorkingGroupNameForDisplay());//显示当前群组
    }
    else
    {
      DISPLAY_Show(d_individualcall);
    }
    api_disp_all_screen_refresh();// 全屏统一刷新
    break;
  default:
    break;
  }
  
  switch(ApiPocCmd_ReceivedVoicePlayStatesForDisplay())
  {
  case ReceivedNone:
    break;
  case ReceivedStartVoice:
    api_lcd_pwr_on_hint(0,2,GBK,"                ");
    api_lcd_pwr_on_hint(0,2,UNICODE,GetSpeakingUserNameForDisplay());
    voice_tone();
    api_disp_icoid_output( eICO_IDVOX, TRUE, TRUE);//接收信号图标
    ApiPocCmd_ReceivedVoicePlayStatesForDisplaySet(ReceivedBeingVoice);

    if(MenuMode_Flag!=0)
    {
      MenuDisplay(Menu_RefreshAllIco);
      MenuModeCount=1;
      TheMenuLayer_Flag=0;
      MenuMode_Flag=0;
      ApiMenu_SwitchGroup_Flag=0;
      ApiMenu_SwitchCallUser_Flag=0;
      ApiMenu_SwitchOnlineUser_Flag=0;
      ApiMenu_GpsInfo_Flag=0;
      ApiMenu_BacklightTimeSet_Flag=0;
      ApiMenu_KeylockTimeSet_Flag=0;
      ApiMenu_NativeInfo_Flag=0;
      ApiMenu_BeiDouOrWritingFrequency_Flag=0;
    }
    api_disp_all_screen_refresh();// 全屏统一刷新
#if 0 //解决换组或换呼状态下，被呼叫后按PTT或OK键会切换群组，而不是回复刚刚说话人的语音
    if(MenuMode_Flag!=0)
    {
      MenuDisplay(Menu_RefreshAllIco);
      MenuMode_Flag = 0;
    }
    KeyDownUpChoose_GroupOrUser_Flag=0;
    api_disp_icoid_output( eICO_IDMESSAGEOff, TRUE, TRUE);//S选择对应空图标
    KeyUpDownCount=0;
#endif
    break;
  case ReceivedBeingVoice:
    break;
  case ReceivedEndVoice:
    get_screen_display_group_name();
    voice_tone();
    api_disp_icoid_output( eICO_IDTALKAR, TRUE, TRUE);//无发射无接收空图标
    api_disp_all_screen_refresh();// 全屏统一刷新
    ApiPocCmd_ReceivedVoicePlayStatesForDisplaySet(ReceivedNone);
    break;
  default:
    break;
  }
/********控制功放喇叭*************************************/
#if 1
if(ApiAtCmd_bZTTSStates()==1)
{
  AUDIO_IOAFPOW(ON);
}
else
{
  if(ApiPocCmd_ReceivedVoicePlayStates()==TRUE)
  {
    AUDIO_IOAFPOW(ON);
  }
  else
  {
    if(poc_receive_sos_statas()==TRUE)
    {
       AUDIO_IOAFPOW(ON);
    }
    else
    {
  #if 0 //MCU Tone音
          if(AtCmdDrvobj.voice_tone_play==TRUE)//本地播放tone音
          {
            AUDIO_IOAFPOW(ON);
          }
          else
          {
            AUDIO_IOAFPOW(OFF);
          }
  #else //模块Tone音
        if(ApiPocCmd_ToneStateIntermediate()==TRUE)
        {
          AUDIO_IOAFPOW(ON);
        }
        else
        {
          AUDIO_IOAFPOW(OFF);
        }
  #endif
    }
  }
#endif
}
}
void Task_low_battery_progress(void)
{
  VOICE_Play(PowerLowPleaseCharge);
  DISPLAY_Show(d_PowerLowPleaseCharge);
  DEL_SetTimer(0,1000);
  while(1){if(DEL_GetTimer(0) == TRUE) {break;}}
  BEEP_Time(10);
}

void Task_PowerOff(void)
{
  api_lcd_pwr_on_hint(0,0,GBK,"                ");
  api_lcd_pwr_on_hint(0,2,GBK,"                ");
  set_power_off(OFF);//关闭模块电源
  Set_GreenLed(OFF);//关灯
  Set_RedLed(OFF);
  AUDIO_IOAFPOW(OFF);//关闭喇叭
  MCU_LCD_BACKLIGTH(OFF);//关闭背光灯
  asm("HALT");
  while(1)
  {
    
  }
}
