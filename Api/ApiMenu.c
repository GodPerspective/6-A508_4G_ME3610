//all UTF-8 done
#include "AllHead.h"

#if 1
u8 ApiMenu_SwitchGroup_Flag=0;
u8 ApiMenu_SwitchCallUser_Flag=0;
u8 ApiMenu_SwitchOnlineUser_Flag=0;
u8 ApiMenu_GpsInfo_Flag=0;
u8 ApiMenu_NativeInfo_Flag=0;
u8 ApiMenu_BacklightTimeSet_Flag=0;
u8 ApiMenu_KeylockTimeSet_Flag=0;
u8 ApiMenu_BeiDouOrWritingFrequency_Flag=0;
#endif

void ApiMenu_init(void)
{
  ApiMenu_SwitchGroup_Flag=0;
  ApiMenu_SwitchCallUser_Flag=0;
  ApiMenu_SwitchOnlineUser_Flag=0;
  ApiMenu_GpsInfo_Flag=0;
  ApiMenu_NativeInfo_Flag=0;
  ApiMenu_BacklightTimeSet_Flag=0;
  ApiMenu_KeylockTimeSet_Flag=0;
  ApiMenu_BeiDouOrWritingFrequency_Flag=0;
}

void MenuDisplay(MenuDisplayType id)
{
  u8 Buf1[1];
  u8 Buf2[1];
  switch(id)
  {
  case Menu0:
    break;
  case Menu1://群组选择
    DISPLAY_Show(d_menu);
    DISPLAY_Show(d_menu_groupselect);
    break;
  case Menu2://GPS信息
    DISPLAY_Show(d_menu);
    DISPLAY_Show(d_menu_gpsinformation);
     break;
  case Menu3://背光灯时间
    DISPLAY_Show(d_menu);
    DISPLAY_Show(d_menu_backlighttime);
     if(ApiMenu_BacklightTimeSet_Flag==2)
     {
       ApiMenu_BacklightTimeSet_Flag=0;
       if(BacklightTimeSetCount==7)
       {
         Buf1[0]=0;
         FILE_Write2(0x236,1,Buf1);//背光时间【秒】
       }
       else
       {
         Buf1[0]=BacklightTimeSetCount;
         FILE_Write2(0x236,1,Buf1);//背光时间【秒】
       }
     }
     break;
  case Menu4://键盘锁时间
    DISPLAY_Show(d_menu);
    DISPLAY_Show(d_menu_keypadlocktime);
     if(ApiMenu_KeylockTimeSet_Flag==2)
     {
       ApiMenu_KeylockTimeSet_Flag=0;
       if(KeylockTimeSetCount==0x10)
       {
         //KeylockTimeCount=200;//如果=200则永远不锁屏
         Buf2[0]=KeylockTimeSetCount-0x10;
         FILE_Write2(0x247,1,Buf2);//键盘锁时间【秒】
       }
       else
       {
         //KeylockTimeCount=(KeylockTimeSetCount-0x10)*30;
         Buf2[0]=KeylockTimeSetCount-0x10;
         FILE_Write2(0x247,1,Buf2);//键盘锁时间【秒】
       }
     }
     break;
  case Menu5://软件版本
    DISPLAY_Show(d_menu);
    DISPLAY_Show(d_menu_softwareversion);
    break;
  case Menu_Locking_NoOperation:
    MenuDisplay(Menu_RefreshAllIco);
    get_screen_display_group_name();//选择显示当前群组昵称（群组或单呼临时群组）
    break;
  case Menu_unLocking:
    MenuDisplay(Menu_RefreshAllIco);
    get_screen_display_group_name();//选择显示当前群组昵称（群组或单呼临时群组）
    break;
  case Menu_RefreshAllIco:
    NetworkModeIcons();
    HDRCSQSignalIcons();
    if(LockingState_Flag==FALSE)
      api_disp_icoid_output( eICO_IDBANDWIDTHN, TRUE, TRUE);//无锁屏空图标
    else
      api_disp_icoid_output( eICO_IDBANDWIDTHW, TRUE, TRUE);//锁屏图标
    
    api_disp_icoid_output( BatteryLevel, TRUE, TRUE);//电池电量图标
    api_disp_icoid_output( eICO_IDTALKAR, TRUE, TRUE);//默认无发射无接收信号图标
//if(ShowTime_Flag==FALSE)
    {
      //if(VoiceType_FreehandOrHandset_Flag==0)
        api_disp_icoid_output( eICO_IDTemper, TRUE, TRUE);//免提模式
      //else
       // api_disp_icoid_output( eICO_IDMONITER, TRUE, TRUE);//听筒模式图标
      
      if(get_current_working_status()==m_group_mode)
        api_disp_icoid_output( eICO_IDPOWERM, TRUE, TRUE);//显示组呼图标
      else
        api_disp_icoid_output( eICO_IDPOWERH, TRUE, TRUE);//显示个呼图标
#if 1
      if(KeyDownUpChoose_GroupOrUser_Flag==0)
        api_disp_icoid_output( eICO_IDMESSAGEOff, TRUE, TRUE);//空图标-与选对应
      else
        api_disp_icoid_output( eICO_IDLOCKED, TRUE, TRUE);//选
#endif
    }
      break;
  case Menu_UnlockStep1_Ok:
    DISPLAY_Show(d_presswell);//显示请按#号键
    break;
  default:
    break;
  }
}

void SubmenuMenuDisplay(SubmenuMenuDisplayType id)
{
  u8 Buf1[22];//={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  u8 Buf2[22];//={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  switch(id)
  {
  case GroupSwitch: 
    MenuDisplay(Menu_RefreshAllIco);
    api_lcd_pwr_on_hint(0,2,GBK,"                ");//清屏
    api_lcd_pwr_on_hint(0,2,UNICODE,GetNowWorkingGroupNameForDisplay());//显示当前群组昵称
    break;
  case GpsInfoMenu:
     api_lcd_pwr_on_hint(0,0,GBK,"                ");//清屏
     api_lcd_pwr_on_hint(0,2,GBK,"                ");//清屏
    if(delay_gps_value_for_display_flag2()==FALSE)
    {
      DISPLAY_Show(d_longitude_and_latitude0);
    }
    else
    {
      //换算并显示经度
      Buf1[0]=0xce;
      Buf1[1]=0xb3;
      Buf1[2]=0xb6;
      Buf1[3]=0xc8;
      Buf1[4]=0x3a;
      COML_DecToAsc(poc_latitude_integer(), Buf1+5);
      COML_StringReverse(2,Buf1+5);
      Buf1[7]=0x2e;
      COML_DecToAsc(poc_latitude_float(), Buf1+8);
      COML_StringReverse(6,Buf1+8);
      Buf1[14]='\0';
      Buf1[15]='\0';
      Buf1[16]='\0';
      Buf1[17]='\0';
      Buf1[18]='\0';
      api_lcd_pwr_on_hint(0,0,GBK,Buf1);
      //换算并显示纬度
      Buf2[0]=0xbe;
      Buf2[1]=0xad;
      Buf2[2]=0xb6;
      Buf2[3]=0xc8;
      Buf2[4]=0x3a;
      COML_DecToAsc(poc_longitude_integer(), Buf2+5);
      COML_StringReverse(3,Buf2+5);
      Buf2[8]=0x2e;
      COML_DecToAsc(poc_longitude_float(), Buf2+9);
      COML_StringReverse(6,Buf2+9);
      Buf2[15]='\0';
      Buf1[16]='\0';
      Buf1[17]='\0';
      Buf1[18]='\0';
      Buf1[19]='\0';
      api_lcd_pwr_on_hint(0,2,GBK,Buf2);
    }
    break;
  case NativeInfoMenu:
    MCU_VERSIONForMenu();
    break;
  case BacklightTimeSet:
    BacklightTimeSetCount=read_backlight_time_value();
    if(BacklightTimeSetCount==0)
    {
      BacklightTimeSetCount=7;
    }
    Level3MenuDisplay(BacklightTimeSetCount);
    break;
  case KeylockTimeSet:
    KeylockTimeSetCount=read_key_lock_time_value()+0x10;
    Level3MenuDisplay(KeylockTimeSetCount);
    break;
  case BeiDouOrWritingFrequencySwitch:
    api_lcd_pwr_on_hint(0,0,GBK,"                ");//清屏
     api_lcd_pwr_on_hint(0,2,GBK,"  非此版本功能  ");
    break;
  }
}

void Level3MenuDisplay(Level3MenuDisplayType id)
{
  switch(id)
  {
  case BacklightTimeSet_0s:
    DISPLAY_Show(d_backlight);
    api_lcd_pwr_on_hint(13,0,GBK,"7/7");
    DISPLAY_Show(d_close);
    break;
  case BacklightTimeSet_10s:
    DISPLAY_Show(d_backlight);
    api_lcd_pwr_on_hint(13,0,GBK,"1/7");
    api_lcd_pwr_on_hint(0,2,GBK,"5s              ");
    break;
  case BacklightTimeSet_20s:
    DISPLAY_Show(d_backlight);
    api_lcd_pwr_on_hint(13,0,GBK,"2/7");
    api_lcd_pwr_on_hint(0,2,GBK,"10s             ");
    break;
  case BacklightTimeSet_30s:
    DISPLAY_Show(d_backlight);
    api_lcd_pwr_on_hint(13,0,GBK,"3/7");
    api_lcd_pwr_on_hint(0,2,GBK,"15s             ");
    break;
  case BacklightTimeSet_40s:
    DISPLAY_Show(d_backlight);
    api_lcd_pwr_on_hint(13,0,GBK,"4/7");
    api_lcd_pwr_on_hint(0,2,GBK,"20s             ");
    break;
  case BacklightTimeSet_50s:
    DISPLAY_Show(d_backlight);
    api_lcd_pwr_on_hint(13,0,GBK,"5/7");
    api_lcd_pwr_on_hint(0,2,GBK,"25s             ");
    break;
  case BacklightTimeSet_60s:
    DISPLAY_Show(d_backlight);
    api_lcd_pwr_on_hint(13,0,GBK,"6/7");
    api_lcd_pwr_on_hint(0,2,GBK,"30s             ");
    break;
  case KeylockTimeSet_0s:
    DISPLAY_Show(d_keypadlock);
    api_lcd_pwr_on_hint(13,0,GBK,"7/7");
    DISPLAY_Show(d_close);
    break;
  case KeylockTimeSet_30s:
    DISPLAY_Show(d_keypadlock);
    api_lcd_pwr_on_hint(13,0,GBK,"1/7");
    api_lcd_pwr_on_hint(0,2,GBK,"5s              ");
    break;
  case KeylockTimeSet_60s:
    DISPLAY_Show(d_keypadlock);
    api_lcd_pwr_on_hint(13,0,GBK,"2/7");
    api_lcd_pwr_on_hint(0,2,GBK,"10s             ");
    break;
  case KeylockTimeSet_90s:
    DISPLAY_Show(d_keypadlock);
    api_lcd_pwr_on_hint(13,0,GBK,"3/7");
    api_lcd_pwr_on_hint(0,2,GBK,"15s             ");
    break;
  case KeylockTimeSet_120s:
    DISPLAY_Show(d_keypadlock);
    api_lcd_pwr_on_hint(13,0,GBK,"4/7");
    api_lcd_pwr_on_hint(0,2,GBK,"20s             ");
    break;
  case KeylockTimeSet_150s:
    DISPLAY_Show(d_keypadlock);
    api_lcd_pwr_on_hint(13,0,GBK,"5/7");
    api_lcd_pwr_on_hint(0,2,GBK,"25s             ");
    break;
  case KeylockTimeSet_180s:
    DISPLAY_Show(d_keypadlock);
    api_lcd_pwr_on_hint(13,0,GBK,"6/7");
    api_lcd_pwr_on_hint(0,2,GBK,"30s             ");
    break;
  default:
    break;
  }

}
