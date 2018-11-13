//all UTF-8 done
#define DELLABEL
#include "AllHead.h"

#define DEL10MSLEN		0x0A
#define DEL_IDLE		0x00
#define DEL_RUN			0x01

typedef struct {
  union {
    struct {
      u16 b1ms    : 1;
      u16 b10ms 	: 1;
      u16 b100ms	: 1;
      u16 b500ms	: 1;
      u16 b1S		  : 1;
      u16 bTimeSet: 1;
      u16 bTime0	: 1;
      u16 bTime1	: 1;
      u16 b500Alternate : 1;
      u16		      : 7;
    }Bit;
    u16 Byte;
  }Msg;
  u8   c10msLen;
  u8   c100msLen;
  u8   c500msLen;
  u8   c1SLen;
  u8   c2SLen;
  u16  iTimer0;
  u16  iTimer1;
  struct{
    u8 alarm_count;
    u8 nosimcard_count;
    u8 csq_count;
    u8 poc_status_count;
    u8 poc_first_enter_into_group_flag_count;
    u16 TimeCount_Light;
    u8 TimeCount2;
    u8 receive_sos_statas_count;
    u8 login_step_6_count;
    u8 sys_mode_count;
    u8 network_activated_flag_count;
    u8 ZGIPDNS_count;
    u8 ZCONSTAT_count;
    u8 ztts_states_intermediate_count;
    u8 ztts_states_count;
    u8 ReceivedVoicePlayStatesCount;
    u8 ToneStateCount;
    u8 get_ccid_count;
    u8 get_cgdcont_count;
    u8 choose_write_freq_or_gps_count;
    u8 beidou_valid_count;
    u8 LobatteryTask_StartCount;
    u8 PrimaryLowPowerCount;
    u16 all_power_off_count;
    u8 punch_the_clock_gps_key_press_flag_count;
    u8 getting_info_flag_count;
    u8 voice_tone_play_count;
    u8 ready_return_to_default_state_flag_count;
    u8 poc_gps_value_for_display_flag_count;
    u8 ZPAS_count;
    u8 login_count;
    u8 tts_no_online_user_count;
  }Count;
  bool poc_gps_value_for_display_flag2;
  u8 BacklightTimeBuf[1];//
  u8 KeylockTimeBuf[1];//
}DEL_DRV;

u16 TimeCount;//
u16 TimeCount3;
bool LockingState_Flag;
u8 BacklightTimeCount;//
u16 KeylockTimeCount;//

static DEL_DRV	DelDrvObj;
static void DEL_100msProcess(void);
static void DEL_500msProcess(void);
static void DEL_1msProcess(void);
static void DEL_10msProcess(void);
static void DEL_TimerRenew(void);


void DEL_PowerOnInitial(void)//计时函数初始化
{

  DelDrvObj.Msg.Byte 	= 0x00;
  DelDrvObj.c10msLen    = DEL10MSLEN;
  DelDrvObj.c100msLen   = 0x0A;
  DelDrvObj.c500msLen   = 0x05;
  DelDrvObj.c1SLen      = 0x01;
  DelDrvObj.c2SLen      = 0x02;
  DelDrvObj.iTimer0     = 0;
  DelDrvObj.iTimer1     = 0;

  DelDrvObj.Count.alarm_count=0;
  DelDrvObj.Count.nosimcard_count=0;
  DelDrvObj.Count.csq_count=0;
  DelDrvObj.Count.poc_status_count=0;
  DelDrvObj.Count.poc_first_enter_into_group_flag_count=0;
  DelDrvObj.Count.TimeCount_Light=0;
  DelDrvObj.Count.TimeCount2=0;
  DelDrvObj.Count.receive_sos_statas_count=0;
  DelDrvObj.Count.login_step_6_count=0;
  DelDrvObj.Count.sys_mode_count=0;
  DelDrvObj.Count.network_activated_flag_count=0;
  DelDrvObj.Count.ZGIPDNS_count=0;
  DelDrvObj.Count.ZCONSTAT_count=0;
  DelDrvObj.Count.ztts_states_intermediate_count=0;
  DelDrvObj.Count.ztts_states_count=0;
  DelDrvObj.Count.ReceivedVoicePlayStatesCount=0;
  DelDrvObj.Count.ToneStateCount=0;
  DelDrvObj.Count.get_ccid_count=0;
  DelDrvObj.Count.get_cgdcont_count=0;
  DelDrvObj.Count.choose_write_freq_or_gps_count=0;
  DelDrvObj.Count.beidou_valid_count=0;
  DelDrvObj.Count.LobatteryTask_StartCount=0;
  DelDrvObj.Count.PrimaryLowPowerCount=0;
  DelDrvObj.Count.all_power_off_count=0;
  DelDrvObj.Count.punch_the_clock_gps_key_press_flag_count=0;
  DelDrvObj.Count.getting_info_flag_count=0;
  DelDrvObj.Count.voice_tone_play_count=0;
  DelDrvObj.Count.ready_return_to_default_state_flag_count=0;
  DelDrvObj.Count.poc_gps_value_for_display_flag_count=0;
  DelDrvObj.Count.ZPAS_count=0;
  DelDrvObj.Count.login_count=0;
  DelDrvObj.Count.tts_no_online_user_count=0;
  
  DelDrvObj.poc_gps_value_for_display_flag2=FALSE;
  
  //DelDrvObj.BacklightTimeBuf[0]=0;
  DelDrvObj.KeylockTimeBuf[0]=0;
  
  TimeCount=0;
  TimeCount3=0;
  LockingState_Flag=FALSE;
  BacklightTimeCount=0;
  KeylockTimeCount=0;
  
  Tim3_Timer_Init();
}

void DEL_Interrupt(void)
{
  DelDrvObj.c10msLen--;
  DelDrvObj.Msg.Bit.b1ms = DEL_RUN;
  if (DelDrvObj.c10msLen == 0x00) //10ms interrupt process
  {
    DEL_TimerRenew();//delay timer renew process
    DelDrvObj.Msg.Bit.b10ms = DEL_RUN;
    DelDrvObj.c10msLen = DEL10MSLEN;
    DelDrvObj.c100msLen--;
    if (DelDrvObj.c100msLen == 0x00) //100ms interrupt process
    {
      DelDrvObj.Msg.Bit.b100ms = DEL_RUN;
      DelDrvObj.c100msLen = 0x0A;
      DelDrvObj.c500msLen--;
      if (DelDrvObj.c500msLen == 0x00) //500ms interrupt process
      {	
        DelDrvObj.Msg.Bit.b500ms = DEL_RUN;
        DelDrvObj.c500msLen = 0x05;
        DelDrvObj.c1SLen--;
        if (DelDrvObj.c1SLen == 0x00) //1s interrupt process
        {
          DelDrvObj.Msg.Bit.b1S = DEL_RUN;
          DelDrvObj.c1SLen = 0x02;	
          DelDrvObj.c2SLen--;
          if (DelDrvObj.c2SLen == 0x00)	//2s interrupt process
          {
            //DelDrvObj.Msg.Bit.b2S = DEL_RUN;
            DelDrvObj.c2SLen = 0x02;
          }
        }
      }
    }
  }
  return;
}

void DEL_Renew(void) 
{
  DEL_1msProcess();
  DEL_10msProcess();
  DEL_100msProcess();
  DEL_500msProcess();
  return;
}

void Delay_100ms(u8 T)
{
  u16 i;
  u8 j,k,l;
    for(j = 0; j < 83; j++)
    for(l = 0; l < 10; l++)
        for(k = 0; k < 100; k++)
          for(i = 0; i < T; i++)
      {
        nop();
      }
  return;
}

void DEL_Soft1ms(u16 iLen) 
{
  u16 i;
  for(; iLen > 0; iLen--)
  {
    for( i = 0 ; i < 250; i++)
    {
      nop();
      nop();
      nop();
      nop();
      nop();
    }
  }
  return;
}

bool DEL_SetTimer(u8 cId,u16 iLen)
{
  DelDrvObj.Msg.Bit.bTimeSet = 0x01;
  switch (cId)
  {
  case 0x00:
    if(iLen == 0x00)
    {
      DelDrvObj.Msg.Bit.bTime0 = DEL_IDLE;
    }
    else
    {
      DelDrvObj.Msg.Bit.bTime0 = DEL_RUN;
    }
    DelDrvObj.iTimer0 = iLen;
    break;
  case 0x01:
    if(iLen == 0x00)
    {
      DelDrvObj.Msg.Bit.bTime1 = DEL_IDLE;
    }
    else
    {
      DelDrvObj.Msg.Bit.bTime1 = DEL_RUN;
    }
    DelDrvObj.iTimer1 = iLen;
    break;
  default:
    return FALSE;
  }
  DelDrvObj.Msg.Bit.bTimeSet = 0x00;
  return TRUE;
}

bool DEL_GetTimer(u8 cId)
{
	bool r;

	r = FALSE;
	//1
        switch (cId)
	{
	case 0x00:
		if ((DelDrvObj.Msg.Bit.bTime0 == DEL_RUN) && (DelDrvObj.iTimer0 == 0x00))
		{
			r = TRUE;
			DelDrvObj.Msg.Bit.bTime0 = DEL_IDLE;
		}
		break;
	case 0x01:
		if ((DelDrvObj.Msg.Bit.bTime1 == DEL_RUN) && (DelDrvObj.iTimer1 == 0x00))
		{
			r = TRUE;
			DelDrvObj.Msg.Bit.bTime1 = DEL_IDLE;			
		}
		break;
	default:
		break;
	}
	return r;
}

static void DEL_TimerRenew(void)
{
  if(DelDrvObj.Msg.Bit.bTimeSet == 0x00)
  {
    if (DelDrvObj.iTimer0 != 0x00)
    {
      DelDrvObj.iTimer0--;
    }
    if (DelDrvObj.iTimer1 != 0x00)
    {
      DelDrvObj.iTimer1--;
    }
  }
  return;
}

static void DEL_100msProcess(void)
{
  if (DelDrvObj.Msg.Bit.b100ms == DEL_RUN)
  {
    DelDrvObj.Msg.Bit.b100ms = DEL_IDLE;
    LED_IntOutputRenew();//LED output renew process
    ApiBeidou_Get_location_Information();
    if(DelDrvObj.Msg.Bit.b500Alternate == DEL_IDLE)
    {
      DelDrvObj.Msg.Bit.b500Alternate = DEL_RUN;
      ApiAtCmd_100msRenew();
    }
    else
    {
      DelDrvObj.Msg.Bit.b500Alternate = DEL_IDLE;
    }

/******背光灯处理*********************************/
    FILE_Read(0x236,1,DelDrvObj.BacklightTimeBuf);//读取码片背光灯时间
    FILE_Read(0x247,1,DelDrvObj.KeylockTimeBuf);//读取键盘锁时间
    BacklightTimeCount=5*DelDrvObj.BacklightTimeBuf[0];
    DelDrvObj.Count.TimeCount_Light++;
    if(DelDrvObj.Count.TimeCount_Light>=10*BacklightTimeCount)//10s
    {
      MCU_LCD_BACKLIGTH(OFF);//关闭背光灯
      DelDrvObj.Count.TimeCount_Light=10*BacklightTimeCount;
    }
    else
    {
      MCU_LCD_BACKLIGTH(ON);//打开背光灯
    }
    
    if(get_keyboard_key_states()==m_key_loosen_moment)
    {
      DelDrvObj.Count.TimeCount_Light=0;//背光灯计数器清零
    }
/*******键盘锁处理**********/
    if(DelDrvObj.KeylockTimeBuf[0]==0)
      KeylockTimeCount=200*10;//=200则用不锁屏
    else
      KeylockTimeCount=5*DelDrvObj.KeylockTimeBuf[0];
    
    if(TaskDrvobj.Id==TASK_NORMAL)
    {
      if(KeylockTimeCount==200*10)
      {
        TimeCount=0;
      }
      else
      {
        TimeCount++;
        if(TimeCount>=KeylockTimeCount*10) //超时锁屏
        {
          if(TimeCount==KeylockTimeCount*10)
          {
            LockingState_Flag=TRUE;//超时锁定标志位
            MenuDisplay(Menu_RefreshAllIco);
            get_screen_display_group_name();//显示当前群组或用户
            api_disp_all_screen_refresh();// 

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
          TimeCount=KeylockTimeCount*10+1;
        }
        else
        {
        }
        
        if(LockingState_EnterOK_Flag==TRUE)//锁定界面按下ok键
        {
          TimeCount3++;
          if(TimeCount3>=4*10)//4s
          {
            TimeCount3=0;
            LockingState_EnterOK_Flag=FALSE;
            MenuDisplay(Menu_Locking_NoOperation);
          }
        }
        else
        {
          if(get_keyboard_key_states()==m_key_loosen_moment&&TimeCount>=KeylockTimeCount*10)//����10����ٰ�������ʾ����OK���ٰ�*����
          {
            DelDrvObj.Count.TimeCount2++;
            DISPLAY_Show(d_press_ok_then_well);//显示先按ok再按#
            if(DelDrvObj.Count.TimeCount2>=1*10)//0.5s
            {
              DelDrvObj.Count.TimeCount2=0;
              set_keyboard_key_states(m_key_idle);
              MenuDisplay(Menu_Locking_NoOperation);
            }
          }
        }
      }
      if(get_keyboard_key_states()==m_key_loosen_moment&&TimeCount<KeylockTimeCount*10)//���������ּ��̰���
      {
        TimeCount=0;//当有按键按下，计数器清零
        set_keyboard_key_states(m_key_idle);
      }
    }
/******喇叭控制相关函数************************/
    if(ApiAtCmd_bZTTSStates_Intermediate()==1)//语音播报喇叭延迟2秒关闭
    {
      DelDrvObj.Count.ztts_states_intermediate_count++;
      if(DelDrvObj.Count.ztts_states_intermediate_count>10*2)
      {
        set_ApiAtCmd_bZTTSStates_Intermediate(0);
        set_ApiAtCmd_bZTTSStates(0);
        DelDrvObj.Count.ztts_states_intermediate_count = 0;
      }
    }
    else
    {
      if(ApiAtCmd_bZTTSStates()==1)
      {
        DelDrvObj.Count.ztts_states_count++;
        if(DelDrvObj.Count.ztts_states_count>10*20)
        {
          set_ApiAtCmd_bZTTSStates(0);
          DelDrvObj.Count.ztts_states_count=0;
        }
      }
    }
    
    if(ApiPocCmd_ReceivedVoicePlayStatesIntermediate()==TRUE)//对讲语音
    {
      DelDrvObj.Count.ReceivedVoicePlayStatesCount++;  
      if(DelDrvObj.Count.ReceivedVoicePlayStatesCount>10*1)
      {
        ApiPocCmd_ReceivedVoicePlayStatesIntermediateSet(FALSE);
        ApiPocCmd_ReceivedVoicePlayStatesSet(FALSE);
        DelDrvObj.Count.ReceivedVoicePlayStatesCount=0;
      }
    }
    
    if(ApiPocCmd_ToneStateIntermediate()==TRUE)//bb音
    {
      DelDrvObj.Count.ToneStateCount++;
      if(DelDrvObj.Count.ToneStateCount>5)
      {
        ApiPocCmd_ToneStateIntermediateSet(FALSE);
        DelDrvObj.Count.ToneStateCount=0;
      }
    }
    else
    {
      DelDrvObj.Count.ToneStateCount=0;
    }
/**********************************************/
  }
  return;
}

static void DEL_500msProcess(void)			//delay 500ms process server
{
  if (DelDrvObj.Msg.Bit.b500ms == DEL_RUN) 
  {
    DelDrvObj.Msg.Bit.b500ms = DEL_IDLE;
    VOICE_1sProcess();
/********^MODE:0 播报无服务*********/
/*********开机检测SIM卡*************/
    if(AtCmdDrvobj.Msg.Bits.bNoSimCard==1)
    {
        DelDrvObj.Count.nosimcard_count++;
        if(DelDrvObj.Count.nosimcard_count>2*8)
        {
          DelDrvObj.Count.nosimcard_count=0;
          VOICE_Play(NoSimCard);
          DISPLAY_Show(d_NoSimCard);
        }
    }
    else
    {
      DelDrvObj.Count.nosimcard_count=0;
    }
/*****处于登录Step1，隔5s发一次AT+CPIN?**********/
    if(TaskDrvobj.login_step==1)
    {
      DelDrvObj.Count.get_ccid_count++;
      if(DelDrvObj.Count.get_ccid_count>2*5)
      {
        DelDrvObj.Count.get_ccid_count=0;
        ApiAtCmd_WritCommand(ATCOMM_CPIN,0,0);
      }
    }
    else
    {
      DelDrvObj.Count.get_ccid_count=0;
    }
/*****处于登录step2状态，隔5s发一次AT+CREG?**********/
    if(TaskDrvobj.login_step==2)
    {
      DelDrvObj.Count.get_cgdcont_count++;
      if(DelDrvObj.Count.get_cgdcont_count>2*5)
      {
        DelDrvObj.Count.get_cgdcont_count=0;
        ApiAtCmd_WritCommand(ATCOMM_CREG,0,0);
        ApiAtCmd_WritCommand(ATCOMM_SetNetworkAuto,0,0);//默认设置为网络模式自动选择
      }
    }
    else
    {
      DelDrvObj.Count.get_cgdcont_count=0;
    }
/******处于step3状态，隔15s发一次登录请求*******************/
    if(TaskDrvobj.login_step==3)
    {
      DelDrvObj.Count.login_count++;
      if(DelDrvObj.Count.login_count>2*15)
      {
        login_step_3();
        DelDrvObj.Count.login_count=0;
      }
    }
    else
    {
      DelDrvObj.Count.login_count=0;
    }
/**********显示初始化*************/
    if(TaskDrvobj.Id==TASK_LOGIN
       &&AtCmdDrvobj.Msg.Bits.bNoSimCard==0
       &&TaskDrvobj.login_step<2)
    {
      DISPLAY_Show(d_init);
    }
/*********卡异常*****************/
    if(AtCmdDrvobj.ZLTENOCELL==1)
    {
      VOICE_Play(SimCardError);
      DISPLAY_Show(d_SimCardError);
      AtCmdDrvobj.ZLTENOCELL=2;
    }
/*********定时5s发一次[AT+CSQ?]*************************************************/
    DelDrvObj.Count.csq_count++;
    if(DelDrvObj.Count.csq_count==1)
    {
      if(TaskDrvobj.Id==TASK_LOGIN&&TaskDrvobj.login_step==2)//������������
      {
        VOICE_Play(NetworkSearching);
        DISPLAY_Show(d_NetworkSearching);
      }
    }
    if(DelDrvObj.Count.csq_count>=2*9)
    {
      DelDrvObj.Count.csq_count=0;
      ApiAtCmd_WritCommand(ATCOMM_CSQ,0, 0);
      if(MenuMode_Flag==0)
      {
        HDRCSQSignalIcons();
      }
    }
    
/*****定时发送AT+ZPAS?获取当前网络类型*************/
    NetworkModeIcons(FALSE);//实时刷新当前网络类型，查询到新的类型则刷新一次
    DelDrvObj.Count.ZPAS_count++;
    if(DelDrvObj.Count.ZPAS_count>=2*10)
    {
      DelDrvObj.Count.ZPAS_count=0;
      ApiAtCmd_WritCommand(ATCOMM_ZPAS,0,0);//查询模块网络状态
    }
/******网络注册异常处理********/
    switch(AtCmdDrvobj.network_reg.creg)
    {
    case 4://CS未知网络
      if(AtCmdDrvobj.network_reg.cgreg==4&&AtCmdDrvobj.network_reg.cereg==4)
      {
        //DISPLAY_Show(d_all_unknow_network);
        //VOICE_Play(all_unknow_network);
        AtCmdDrvobj.network_reg.creg=0;
        AtCmdDrvobj.network_reg.cgreg=0;
        AtCmdDrvobj.network_reg.cereg=0;
      }
      else
      {
        //DISPLAY_Show(d_cs_unknow_network);
        //VOICE_Play(cs_unknow_network);
        AtCmdDrvobj.network_reg.creg=0;
      }
      break;
    default:
      //0:CS网络没有注册
      //1:CS注册了本地网络
      //2:CS没有注册，正在搜索新运营商
      //3:CS网络注册被拒绝
      //5:CS注册了漫游网络
      break;
    }
    switch(AtCmdDrvobj.network_reg.cgreg)
    {
    case 3://GPRS网络注册被拒绝
      DISPLAY_Show(d_gprs_refuse_enroll);
      VOICE_Play(gprs_refuse_enroll);
      AtCmdDrvobj.network_reg.cgreg=0;
      break;
    case 4://GPRS未知网络
      if(AtCmdDrvobj.network_reg.creg!=4)
      {
        DISPLAY_Show(d_gprs_unknow_network);
        VOICE_Play(gprs_unknow_network);
        AtCmdDrvobj.network_reg.cgreg=0;
      }
      break;
    default:
      //0:GPRS网络没有注册
      //1:GPRS注册了本地网络
      //2:GPRS没有注册，正在搜索新运营商
      //5:注册了漫游网络
      break;
    }
    
    switch(AtCmdDrvobj.network_reg.cereg)
    {
    case 3://EPS网络注册被拒绝
      DISPLAY_Show(d_eps_refuse_enroll);
      VOICE_Play(eps_refuse_enroll);
      AtCmdDrvobj.network_reg.cereg=0;
      break;
    case 4://EPS未知网络
      if(AtCmdDrvobj.network_reg.creg!=4)
      {
        DISPLAY_Show(d_eps_unknow_network);
        VOICE_Play(eps_unknow_network);
        AtCmdDrvobj.network_reg.cereg=0;
      }
      break;
    default:
      //0:EPS网络没有注册
      //1:EPS注册了本地网络
      //2:EPS没有注册，正在搜索新运营商
      //5:EPS注册了漫游网络
      break;
    }
    
/****如果未收到CGDCONT，则过5秒发一次*****/
    if(AtCmdDrvobj.ZGIPDNS==1)
    {
      DelDrvObj.Count.ZGIPDNS_count++;
      if(DelDrvObj.Count.ZGIPDNS_count>2*5)
      {
        DelDrvObj.Count.ZGIPDNS_count=0;
        ApiAtCmd_WritCommand(ATCOMM_CGACT,0,0);
      }
    }
    else
    {
      DelDrvObj.Count.ZGIPDNS_count=0;
    }

    if(AtCmdDrvobj.ZCONSTAT==1)
    {
      DelDrvObj.Count.ZCONSTAT_count++;
      if(DelDrvObj.Count.ZCONSTAT_count>2*5)
      {
        ApiAtCmd_WritCommand(ATCOMM_ZGACT1,0,0);//PDP����������2
        DelDrvObj.Count.ZCONSTAT_count=0;
      }
    }
    else
    {
      DelDrvObj.Count.ZCONSTAT_count=0;
    }
/******满足条件登录POC********/
    if(TaskDrvobj.login_step==6&&AtCmdDrvobj.csq_param.rssi>=30&&AtCmdDrvobj.csq_param.rssi!=0&&AtCmdDrvobj.csq_param.rssi!=99)//�յ�ZCONSTAT����ָʾ���ӳ�2s��¼POC
    {
      DelDrvObj.Count.login_step_6_count++;
      if(DelDrvObj.Count.login_step_6_count>2*2)
      {
        TaskDrvobj.login_step=7;
        DelDrvObj.Count.login_step_6_count=0;
      }
    }
    else
    {
      DelDrvObj.Count.login_step_6_count=0;
    }
/********正常模式下切换网络后收到creg、cereg、cgreg处理***********/
    if(TaskDrvobj.Id==TASK_NORMAL&&(AtCmdDrvobj.network_reg.cereg==1||AtCmdDrvobj.network_reg.cereg==5
     ||AtCmdDrvobj.network_reg.cgreg==1||AtCmdDrvobj.network_reg.cgreg==5))
    {
      DelDrvObj.Count.network_activated_flag_count++;
      if(DelDrvObj.Count.network_activated_flag_count==1)
      {
        ApiAtCmd_WritCommand(ATCOMM_CGACT,0,0);
      }
      else if(DelDrvObj.Count.network_activated_flag_count>2*5)
      {
        DelDrvObj.Count.network_activated_flag_count=11;
      }
      else
      {}
    }
    else
    {
      DelDrvObj.Count.network_activated_flag_count=0;
    }
    
    if(TaskDrvobj.Id==TASK_NORMAL&&AtCmdDrvobj.ZGIPDNS==2)
    {
      ApiAtCmd_WritCommand(ATCOMM_ZGACT1,0,0);
      AtCmdDrvobj.ZGIPDNS=0;
    }
    
/*******收到离线指令，屏幕提示离线状态*******/
    if(poccmd_states_poc_status()==OffLine)
    {
      DISPLAY_Show(d_status_offline);
    }
/*******处于未登录成功状态过2分钟未登陆重启*******/
    if(poccmd_states_poc_status()!=LandSuccess&&AtCmdDrvobj.Msg.Bits.bNoSimCard!=1)
    {
      DelDrvObj.Count.poc_status_count++;
      
      if(DelDrvObj.Count.poc_status_count>2*2*60)
      {
        DISPLAY_Show(d_2min_end_reset);
        set_power_off(OFF);//关闭模块电源
      }
      if(DelDrvObj.Count.poc_status_count>2*2*60+2*4)
      {
        DelDrvObj.Count.poc_status_count=0;
        set_power_off(ON);//关闭模块电源
        main_all_init();//重启
      }
    }
    else
    {
      DelDrvObj.Count.poc_status_count=0;
    }
    
/**登录成功后更新群组信息，若获取不完整则重新获取直到完整**/
    if(poc_first_enter_into_group_flag()==TRUE)
    {
      DelDrvObj.Count.poc_first_enter_into_group_flag_count++;
      if(DelDrvObj.Count.poc_first_enter_into_group_flag_count==3)
      {
        ApiPocCmd_WritCommand(PocComm_GroupListInfo,0,0);
      }
      if(DelDrvObj.Count.poc_first_enter_into_group_flag_count>=3)
      {
        DelDrvObj.Count.poc_first_enter_into_group_flag_count=4;
      }
    }
/******按单呼键若无在线成员则播报无在线成员****************/
    if(PocCmdDrvobj.getting_user_all_done_flag==3&&no_online_user()==TRUE)
    {
      DelDrvObj.Count.tts_no_online_user_count++;
      if(DelDrvObj.Count.tts_no_online_user_count>1)
      {
        DelDrvObj.Count.tts_no_online_user_count=0;
        PocCmdDrvobj.getting_user_all_done_flag=0;
        VOICE_Play(NoOnlineUser);//无在线成员
        return_group_and_clear_flag();//清空所有标志位返回默认群组状态
      }
    }
    else
    {
      DelDrvObj.Count.tts_no_online_user_count=0;
    }
/********收到0x8a则进入一键报警********/
    if(poc_receive_sos_statas()==TRUE)
    {
      BEEP_SetOutput(BEEP_IDPowerOff,ON,0x00,TRUE);
      ApiPocCmd_ToneStateSet(TRUE);
      AUDIO_IOAFPOW(ON);
      DelDrvObj.Count.receive_sos_statas_count++;
      if(DelDrvObj.Count.receive_sos_statas_count>=2*5)
      {
        Set_RedLed(OFF);
        set_poc_receive_sos_statas(FALSE);
        DelDrvObj.Count.receive_sos_statas_count=0;
        BEEP_SetOutput(BEEP_IDPowerOff,OFF,0x00,TRUE);
        ApiPocCmd_ToneStateSet(FALSE);
        AUDIO_IOAFPOW(OFF);
      }
    }
    else
    {
      DelDrvObj.Count.receive_sos_statas_count=0;
    }
    

/*****获取中：换组时更新组列表后播报及显示当前选中的用户名************/
    if(AtCmdDrvobj.getting_info_flag==TRUE&&PocCmdDrvobj.getting_group_all_done_flag==2)
    {
      PocCmdDrvobj.getting_group_all_done_flag=0;
      changing_group_voice_and_display(GroupCallingNum-1);
      PocCmdDrvobj.getting_info_flag=KEYNONE;
      AtCmdDrvobj.getting_info_flag=FALSE;
    }
/*****获取中：换组时更新组列表后播报及显示当前选中的用户名************/
    if(AtCmdDrvobj.getting_info_flag==TRUE&&PocCmdDrvobj.getting_user_all_done_flag==3)
    {
      PocCmdDrvobj.getting_user_all_done_flag=0;
      changing_user_voice_and_display(PersonalCallingNum);
      PocCmdDrvobj.getting_info_flag=KEYNONE;
      AtCmdDrvobj.getting_info_flag=FALSE;
    }
/*******解决处于获取中状态超过2秒则重新获取一次组列表或用户列表*********/
    if(AtCmdDrvobj.getting_info_flag==TRUE)
    {
      DelDrvObj.Count.getting_info_flag_count++;
      if(DelDrvObj.Count.getting_info_flag_count>=2*2)
      {
        DelDrvObj.Count.getting_info_flag_count=0;
        if(KEYCMD_PersonalKeyMode()==TRUE)
        {
          ApiPocCmd_WritCommand(PocComm_UserListInfo,0,0);
        }
        else
        {
          ApiPocCmd_WritCommand(PocComm_GroupListInfo,0,0);
        }
      }
    }
    else
    {
      DelDrvObj.Count.getting_info_flag_count=0;
    }
/****登录成功一分钟后禁用写频功能，开启外部定位上报模式*********/
    if(TaskDrvobj.Id==TASK_NORMAL)
    {
      DelDrvObj.Count.choose_write_freq_or_gps_count++;
      if(DelDrvObj.Count.choose_write_freq_or_gps_count>2*60)
      {
        GPIO_WriteLow(GPIOB,GPIO_PIN_3);//NFC
        GPIO_WriteHigh(GPIOB,GPIO_PIN_4);//����
        DelDrvObj.Count.choose_write_freq_or_gps_count = 2*60+1;
      }
    }
    else
    {
      DelDrvObj.Count.choose_write_freq_or_gps_count = 0;
    }    
/****定位成功后5s上报一次定位*****/
    if(beidou_valid()==TRUE&&ReadInput_KEY_PTT!=0)//当定位成功,且没有按下PTT则上报位置
    {
      DelDrvObj.Count.beidou_valid_count++;
      if(DelDrvObj.Count.beidou_valid_count>2*5)
      {
        ApiPocCmd_WritCommand(PocComm_SetGps,0,0);
        DelDrvObj.Count.beidou_valid_count=0;
      }
    }
    else
    {
      DelDrvObj.Count.beidou_valid_count=0;
    }
/******登录状态下的低电报警**********************************************/
    if(LobatteryTask_StartFlag==TRUE)
    {
      DelDrvObj.Count.LobatteryTask_StartCount++;
      if(DelDrvObj.Count.LobatteryTask_StartCount==1)
      {
        VOICE_Play(PowerLowPleaseCharge);
        DISPLAY_Show(d_PowerLowPleaseCharge);
      }
      if(DelDrvObj.Count.LobatteryTask_StartCount>2*5)
      {
        DelDrvObj.Count.LobatteryTask_StartCount=0;
        LobatteryTask_StartFlag=FALSE;
      }
    }
/*********登录成功后的初级报警30一次********************************/
  if(TaskDrvobj.battery_states==BATTERY_LOW_LEVEL_1)
    {
      DelDrvObj.Count.PrimaryLowPowerCount++;
      if(DelDrvObj.Count.PrimaryLowPowerCount>=2*30)
      {
        DelDrvObj.Count.PrimaryLowPowerCount=0;
        VOICE_Play(LowBattery);
        TaskDrvobj.battery_states=BATTERY_HEALTH;
      }
    }
/*******低电标志超过120s,则断电进入电池保护模式******************/
    if(TaskDrvobj.Id==TASK_LOW_BATTERY)
    {
      DelDrvObj.Count.all_power_off_count++;
      if(DelDrvObj.Count.all_power_off_count>=2*3)//低电模式有延时10s,6=60s
      {
        DelDrvObj.Count.all_power_off_count=2*3+1;
        TaskDrvobj.Id=TASK_POWEROFF;
      }
    }
    else
    {
      DelDrvObj.Count.all_power_off_count=0;
    }
  /********打卡功能：按下打卡键超5秒钟提示打卡失败*******************/
    if(AtCmdDrvobj.punch_the_clock_gps_key_press_flag==TRUE)
    {
      DelDrvObj.Count.punch_the_clock_gps_key_press_flag_count++;
      if(DelDrvObj.Count.punch_the_clock_gps_key_press_flag_count==2*5)//5s后播报定位失败
      {
        if(beidou_valid()==TRUE)//如果定位成功，则播报打卡失败
        {
          VOICE_Play(punch_the_clock_fail);
          DISPLAY_Show(d_punch_the_clock_fail);
        }
        else//如果未定位成功，则播报未定位
        {
          VOICE_Play(gps_not_located);
          DISPLAY_Show(d_gps_not_located);
        }
        DelDrvObj.Count.punch_the_clock_gps_key_press_flag_count=0;
        AtCmdDrvobj.punch_the_clock_gps_key_press_flag=FALSE;
        AtCmdDrvobj.ready_return_to_default_state_flag=TRUE;
      }
    }
    else
    {
      DelDrvObj.Count.punch_the_clock_gps_key_press_flag_count=0;
    }
/***********消除打卡后屏幕的提示信息*********************/
    if(AtCmdDrvobj.ready_return_to_default_state_flag==TRUE)
    {
      DelDrvObj.Count.ready_return_to_default_state_flag_count++;
      if(DelDrvObj.Count.ready_return_to_default_state_flag_count>=2*5)
      {
        DelDrvObj.Count.ready_return_to_default_state_flag_count=0;
        AtCmdDrvobj.ready_return_to_default_state_flag=FALSE;
        if(get_current_working_status()==m_personal_mode)
        {
          ApiPocCmd_WritCommand(PocComm_EnterGroup,0,0);
        }
        return_group_and_clear_flag();//返回默认群组标志位
      }
    }
/****定位成功后6s后在菜单模式下才能查看到经纬度信息（解决刚定位成功查看经纬度异常的问题）*********************************************************/
    if(poc_gps_value_for_display_flag()==TRUE)
    {
      DelDrvObj.Count.poc_gps_value_for_display_flag_count++;
      if(DelDrvObj.Count.poc_gps_value_for_display_flag_count>2*6)
      {
        DelDrvObj.Count.poc_gps_value_for_display_flag_count=0;
        DelDrvObj.poc_gps_value_for_display_flag2=TRUE;
      }
    }
    else
    {
      DelDrvObj.Count.poc_gps_value_for_display_flag_count=0;
      DelDrvObj.poc_gps_value_for_display_flag2=FALSE;
    }
  }
}


static void DEL_1msProcess(void)
{
  if (DelDrvObj.Msg.Bit.b1ms == DEL_RUN)
  {
    DelDrvObj.Msg.Bit.b1ms = DEL_IDLE;
    //ApiPocCmd_83_1msRenew();
    ApiPocCmd_10msRenew();
    ApiCaretCmd_10msRenew();
    ApiAtCmd_10msRenew();
    
  }
  return;
}

static void DEL_10msProcess(void)
{
  if (DelDrvObj.Msg.Bit.b10ms == DEL_RUN) 
  {
    keyboard_scan();
    DelDrvObj.Msg.Bit.b10ms = DEL_IDLE;
    
/**********对讲Tone音本地播放（MZ389新基带版本要求）******************/
#if 0
    if(AtCmdDrvobj.voice_tone_play==TRUE)
    {
      DelDrvObj.Count.voice_tone_play_count++;
      if(DelDrvObj.Count.voice_tone_play_count>=5)//0.2s tone��
      {
        BEEP_SetOutput(BEEP_IDPowerOff,OFF,0x00,TRUE);
        AUDIO_IOAFPOW(OFF);
        DelDrvObj.Count.voice_tone_play_count=0;
        AtCmdDrvobj.voice_tone_play=FALSE;
      }
    }
#endif
/**********************************************************************/
    DelDrvObj.Count.alarm_count++;
      if(poc_receive_sos_statas()==TRUE)
      {
        if(DelDrvObj.Count.alarm_count>=3)
      {
        //Test_PWM_LED();//报警音30ms进一次
        DelDrvObj.Count.alarm_count = 0;
      }
      }

  }
  return;
}

u8 read_backlight_time_value(void)
{
  return DelDrvObj.BacklightTimeBuf[0];
}
u8 read_key_lock_time_value(void)
{
  return DelDrvObj.KeylockTimeBuf[0];
}
bool delay_gps_value_for_display_flag2(void)
{
  return DelDrvObj.poc_gps_value_for_display_flag2;
}