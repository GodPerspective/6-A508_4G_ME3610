#include "AllHead.h"
//ME3610
//test
void main_all_init(void);
void main_task(void);

void main(void)
{
  
#if 1//bootloader set
  FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
  FLASH_Unlock(FLASH_MEMTYPE_DATA);
  FLASH_ProgramOptionByte(0x487E,0x55);
  FLASH_ProgramOptionByte(0x487F,0xAA);
  FLASH_Lock(FLASH_MEMTYPE_DATA);
#endif

  main_all_init();

  while(1)
  {
    switch(TaskDrvobj.Id)
    {
     case TASK_LOGIN:
      LowVoltageDetection();
      DEL_Renew();
      Task_login_progress();
      if(poccmd_states_poc_status()==LandSuccess)
      {
        DISPLAY_Show(d_not_in_groups);
        TaskDrvobj.Id=TASK_NORMAL;
        TaskDrvobj.login_step=0;
      }
      break;
    case TASK_NORMAL:
      LowVoltageDetection();
      DEL_Renew();
      Task_normal_progress();
      break;
    case TASK_LOW_BATTERY:
      LowVoltageDetection();
      DEL_Renew();
      Task_low_battery_progress();
      break;
    case TASK_POWEROFF:
      Task_PowerOff();
      break;
    default:
      break;
    }
  }
}

void main_all_init(void)
{
  disableInterrupts();
  SystemClock_Init(HSE_Clock);
  ITC_SetSoftwarePriority(ITC_IRQ_UART1_RX,ITC_PRIORITYLEVEL_3);
  ITC_SetSoftwarePriority(ITC_IRQ_UART1_TX,ITC_PRIORITYLEVEL_3);
  ITC_SetSoftwarePriority(ITC_IRQ_UART3_RX,ITC_PRIORITYLEVEL_2);
  ITC_SetSoftwarePriority(ITC_IRQ_TIM1_OVF,ITC_PRIORITYLEVEL_2);
  ITC_SetSoftwarePriority(ITC_IRQ_TIM3_OVF,ITC_PRIORITYLEVEL_1);
  
  //任务初始化
  Task_Init();
  
  //模块UART通信处理初始化
  DrvUart1_init();
  DrvMC8332_Software_Initial();
  ApiPocCmd_PowerOnInitial();
  ApiAtCmd_PowerOnInitial();
  
  //定时相关初始化
  DEL_PowerOnInitial();
  
  //UART3口及数据处理初始化 写频和GPS数据共用同一个UART
  Uart3_Init();
  ApiBeidou_PowerOnInitial();
  
  //功放及播放相关初始化
  Noise_Mute_Init();
  VOICE_PowerOnInitial();

  //显示屏及显示驱动初始化
  drv_gt20_pwr_on_init();
  drv_htg_pwr_on_init();
  ApiDisplay_PowerOnInitial();
  
  //菜单初始化
  ApiMenu_init();
  
  //键盘初始化
  Key_Init();
  ApiKeyCmd_PowerOnInitial();
  ApiKeyboard_PowerOnInitial();

  //LED灯初始化
  LED_Init();
  ApiLED_PowerOnInitial();
  
  //版本管理初始化
  ApiMcuVersion_PowerOnInitial();

  //BEEP音相关处理初始化
  BEEP_PowerOnInitial();
  TONE_PowerOnInitial();
  
  //ADC电压采集及低电报警相关初始化
  ADC_Init();
  ApiBattery_PowerOnInitial();
  
  //模拟开关初始化-用于读写频和gps数据切换
  bdcon_and_nfccon_pin_init();

  //IIC-AW87319
  //iic_init();

  //开启所有中断
  enableInterrupts();

  AUDIO_IOAFPOW(ON);//打开功放

#if 0//  GPS数据：01 
  set_bdcon_io(ON);
  set_nfccon_io(OFF);
#else//写频：11
  set_bdcon_io(ON);
  set_nfccon_io(ON);
#endif
  DISPLAY_Show(d_ABELL);
  set_C_Reset(OFF);
  BEEP_Time(100);
  set_C_Reset(ON);
  MCU_LCD_BACKLIGTH(ON);
  api_disp_icoid_output( eICO_IDMESSAGE, TRUE, TRUE);//图标：0格信号
  api_disp_icoid_output( eICO_IDSPEAKEROff, TRUE, TRUE);//图标：X-无信号
  api_disp_icoid_output( eICO_IDBATT, TRUE, TRUE);//图标：0格电池
  api_disp_icoid_output( eICO_IDTemper, TRUE, TRUE);//免提模式
  
  //ApiAtCmd_WritCommand(ATCOMM_RESET,(void*)0, 0);
}

#ifdef USE_FULL_ASSERT        

/**
  * @brief  Reports the name of the source file and the source line number
  * where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{
  while (1)
  {
  }
}
#endif
