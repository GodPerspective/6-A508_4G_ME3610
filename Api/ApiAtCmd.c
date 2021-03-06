//all UTF-8 done
#include "AllHead.h"

const u8 *cTxTESTMODESETStep1     ="AT+CGDCONT=1,\"IP\",\"ctnet\"";
const u8 *cTxTESTMODESETStep2     ="at+zsnt=6,0,0";
const u8 *cTxTESTMODESETStep3     ="at+zband=0,0,0,10";
const u8 *cTxQuitTestMode         ="at+zband=all,all,all,all";

const u8 *cTxCLVL            ="AT+CLVL=5";//5 此指令测试设置无效
const u8 *cTxCLVLC0           ="AT+CLVLC=0";//3
const u8 *cTxCLVLC1           ="AT+CLVLC=1";//3
const u8 *cTxCLVLC2           ="AT+CLVLC=2";//3
const u8 *cTxCLVLC3           ="AT+CLVLC=3";//3
const u8 *cTxCLVLC4           ="AT+CLVLC=4";//3
const u8 *cTxCLVLC5           ="AT+CLVLC=5";//3
const u8 *cTxCMVLC0           ="AT+CMVLC=0";//3
const u8 *cTxCMVLC1           ="AT+CMVLC=1";//3
const u8 *cTxCMVLC2           ="AT+CMVLC=2";//3
const u8 *cTxCMVLC3           ="AT+CMVLC=3";//3
const u8 *cTxCMVLC4           ="AT+CMVLC=4";//3
const u8 *cTxCMVLC5           ="AT+CMVLC=5";//3


#if 1//ME3630/3610
const u8 *cTxATE1               ="ATE1";
const u8 *cTxCSQ                ="AT+CSQ";
const u8 *cTxCPIN               ="AT+CPIN?";//查询SIM卡状态
const u8 *cTxCREG               ="AT+CREG?";//查询网络注册状态
const u8 *cTxZPAS               ="AT+ZPAS?";//查询模块网络状态

const u8 *cRxZREADY             ="ZREADY";
const u8 *cRxCSQ                ="CSQ: ";
const u8 *cRxCPINREADY          ="CPIN: READY";
const u8 *cRxSIMERROR           ="CME ERROR: SIM";
const u8 *cRxCREG               ="CREG: 0,";

const u8 *cRxZPAS_NOSERVICE     ="ZPAS: \"NO SERVICE\"";
const u8 *cRxZPAS_LIMITEDSERVICE="ZPAS: \"LIMITED SERVICE\"";
const u8 *cRxZPAS_GSM           ="ZPAS: \"GSM\"";
const u8 *cRxZPAS_GPRS          ="ZPAS: \"GPRS\"";
const u8 *cRxZPAS_CDMA          ="ZPAS: \"CDMA\"";
const u8 *cRxZPAS_EDGE          ="ZPAS: \"EDGE\"";
const u8 *cRxZPAS_EVDO          ="ZPAS: \"EVDO\"";
const u8 *cRxZPAS_EHRPD         ="ZPAS: \"EHRPD\"";
const u8 *cRxZPAS_UMTS          ="ZPAS: \"UMTS\"";
const u8 *cRxZPAS_HSDPA         ="ZPAS: \"HSDPA\"";
const u8 *cRxZPAS_HSUPA         ="ZPAS: \"HSUPA\"";
const u8 *cRxZPAS_HSPA          ="ZPAS: \"HSPA\"";
const u8 *cRxZPAS_HSPAPLUS      ="ZPAS: \"HSPA+\"";
const u8 *cRxZPAS_LTE           ="ZPAS: \"LTE\"";
const u8 *cRxZPAS_TDSCDMA       ="ZPAS: \"TD-SCDMA\"";

//#else
const u8 *cTxDIALMODE            ="at+dialmode=0";
const u8 *cTxCGDCONT_SET0        ="AT+CGDCONT=1,\"IP\",\"\"";//
const u8 *cTxCGDCONT_SET1        ="AT+CGDCONT=1,\"IP\",\"3gnet\"";
const u8 *cTxCGDCONT_SET2        ="AT+CGDCONT=1,\"IP\",\"etisalat.ae\"";//
const u8 *cTxCGDCONT_SET3        ="AT+CGDCONT=1,\"IP\",\"internet\"";//
const u8 *cTxCGDCONT_SET4        ="AT+CGDCONT=1,\"IP\",\"internet.proximus.be\"";//����ʱProximus
const u8 *cTxCGDCONT_SET5        ="AT+CGDCONT=1,\"IP\",\"internet.eplus.de\"";//E-plus
const u8 *cTxCGDCONT_SET6        ="AT+CGDCONT=1,\"IP\",\"surfo2\"";//
const u8 *cTxCGDCONT_SET7        ="AT+CGDCONT=1,\"IP\",\"internet.t-d1.de\"";//T-Mobile 
const u8 *cTxCGDCONT_SET8        ="AT+CGDCONT=1,\"IP\",\"web.vodafone.de\"";//Vodafone
const u8 *cTxCGDCONT_SET9        ="AT+CGDCONT=1,\"IP\",\"airtelgprs.com\"";    //印度AirTel
const u8 *cTxCGDCONT_SET10        ="AT+CGDCONT=1,\"IP\",\"bplgprs.com\"";      //印度BPL
const u8 *cTxCGDCONT_SET11        ="AT+CGDCONT=1,\"IP\",\"cellular internet\"";//印度Idea
const u8 *cTxCGDCONT_SET12        ="AT+CGDCONT=1,\"IP\",\"gprsmtnlmum\"";      //印度MTNL Mumbai 
const u8 *cTxCGDCONT_SET13        ="AT+CGDCONT=1,\"IP\",\"portalnmms\"";       //印度Orange 
const u8 *cTxCGDCONT_SET14        ="AT+CGDCONT=1,\"IP\",\"aycell\"";           //土耳其Aycell
const u8 *cTxCGDCONT_SET15        ="AT+CGDCONT=1,\"IP\",\"telsim\"";           //土耳其telsim
const u8 *cTxCGDCONT_SET16        ="AT+CGDCONT=1,\"IP\",\"Turkcell\"";         //土耳其Turkcell
//金灿 比利时客户

const u8 *cTxPOCID                      ="AT^POCID=2";
const u8 *cTxZICCID                     ="AT+ZICCID?";
const u8 *cTxCGDCONT_READ               ="at+cgdcont?";
const u8 *cTxPOWERUP                    ="at+cfun=1";
const u8 *cTxCGACT                      ="at+cgact=1,1";
const u8 *cTxZGACT1                     ="at+zgact=1,1";
const u8 *cTxZGACT0                     ="at+zgact=0,1";
const u8 *cTxPlayZtts                   ="AT+ZTTS=";
const u8 *cTxRESET                      ="at+cfun=1,1";
const u8 *cTxPOWEROFF                   ="at+cfun=0,0";
const u8 *cTxSetNetwork4GAuto           ="AT+ZSNTE=0";//优先4G
const u8 *cTxSetNetwork3GAuto           ="AT+ZSNTE=1";//优先3G
const u8 *cTxSetNetwork2GOnly           ="AT+ZSNTE=2";//仅限2G
const u8 *cTxSetNetwork3GOnly           ="AT+ZSNTE=3";//仅限3G(实测中电信卡设为仅限3G，会登不上，因为机器会先处于2G模式再转换为3G模式)
const u8 *cTxSetNetwork4GOnly           ="AT+ZSNTE=4";//仅限4G
const u8 *cRxZICCID             ="ZICCID: ";


const u8 *cRxCGREG              ="CGREG: ";
const u8 *cRxCEREG              ="CEREG: ";
const u8 *cRxMODE               ="^MODE: ";
const u8 *cRxZGIPDNS            ="ZGIPDNS: 1";
const u8 *cRxZCONSTAT           ="ZCONSTAT: 1,1";
const u8 *cRxZLTENOCELL         ="ZLTENOCELL";
const u8 *cRxZMSRI              ="ZMSRI";
const u8 *cRxCGDCONT            ="CGDCONT:";
const u8 *cRxPASTATE1          ="PASTATE:1";
const u8 *cRxZTTS0             ="ZTTS: 0";
#endif
AtCmdDrv AtCmdDrvobj;
static void NetworkModeIcons_first(void);
void ApiAtCmd_PowerOnInitial(void)
{
  AtCmdDrvobj.Msg.Byte = 0;
  AtCmdDrvobj.ZLTENOCELL=0;
  AtCmdDrvobj.ZGIPDNS=0;
  AtCmdDrvobj.ZCONSTAT=0;
  AtCmdDrvobj.csq_param.act=0;
  AtCmdDrvobj.csq_param.rssi=0;
  AtCmdDrvobj.network_mode=m_NOSERVICE;
  AtCmdDrvobj.network_mode_old=m_NOSERVICE;
  AtCmdDrvobj.network_reg.creg=0;
  AtCmdDrvobj.network_reg.cgreg=0;
  AtCmdDrvobj.network_reg.cereg=0;
  memset(AtCmdDrvobj.ccid,0,sizeof(AtCmdDrvobj.ccid));
  AtCmdDrvobj.apn_set=0;
  AtCmdDrvobj.language_value=0;
  AtCmdDrvobj.Key3_PlayValue=0;
  AtCmdDrvobj.key_top_value=0;
  AtCmdDrvobj.key2_long_value=0;
  AtCmdDrvobj.key3_long_value=0;
  AtCmdDrvobj.key4_long_value=0;
  AtCmdDrvobj.boot_network_mode=0;
  AtCmdDrvobj.clvlc_spk_gain=0;
  AtCmdDrvobj.cmvlc_mic_gain=0;
  AtCmdDrvobj.test_mode=0;//美版模块测试专用标志位，美版模块需进入特殊状态才能在国内正常使用
  AtCmdDrvobj.Key3Option=Key3_OptionZero;
  AtCmdDrvobj.key_top_option=REMOTE_AND_LOCAL_ALARM;
  AtCmdDrvobj.punch_the_clock_gps_key_press_flag=FALSE;
  AtCmdDrvobj.getting_info_flag=FALSE;
  AtCmdDrvobj.voice_tone_play=FALSE;
  AtCmdDrvobj.ready_return_to_default_state_flag=FALSE;
  FILE_Read(0x230,1,&(AtCmdDrvobj.apn_set));//FILE_Read
  //FILE_Read(0x23A,1,&(AtCmdDrvobj.language_value));//FILE_Read
  FILE_Read(598,1,&(AtCmdDrvobj.Key3_PlayValue));
  FILE_Read(602,1,&AtCmdDrvobj.key_top_value);//顶部键的报警类型
  //FILE_Read(0x247,20,AtCmdDrvobj.testbuf);
  FILE_Read(599,1,&(AtCmdDrvobj.key2_long_value));//侧键1长键
  FILE_Read(597,1,&(AtCmdDrvobj.key3_long_value));//侧键2长键
  FILE_Read(601,1,&(AtCmdDrvobj.key4_long_value));//侧键2长键
  FILE_Read(0x248,1,&(AtCmdDrvobj.boot_network_mode));//开机默认网络模式
  FILE_Read(0x249,1,&(AtCmdDrvobj.clvlc_spk_gain));//spk音量增益
  FILE_Read(0x24A,1,&(AtCmdDrvobj.cmvlc_mic_gain));//mic咪头增益
  FILE_Read(0x23B,1,&(AtCmdDrvobj.test_mode));//美版模块测试专用标志位，美版模块需进入特殊状态才能在国内正常使用
  /*switch(AtCmdDrvobj.language_value)
  {
  case 0:
    AtCmdDrvobj.language_set=m_CHINESE;
    break;
  case 1:
    AtCmdDrvobj.language_set=m_ENGLISH;
    break;
  default:
    AtCmdDrvobj.language_set=m_CHINESE;
    break;
  }*/
  
#if 1//侧键1播报语音类型
  switch(AtCmdDrvobj.Key3_PlayValue)
  {
  case 0x00:
    AtCmdDrvobj.Key3Option=Key3_OptionZero;
    break;
  case 0x01:
    AtCmdDrvobj.Key3Option=Key3_OptionOne;
    break;
  case 0x02:
    AtCmdDrvobj.Key3Option=Key3_OptionTwo;
    break;
  case 0x03:
    AtCmdDrvobj.Key3Option=Key3_OptionThree;
    break;
  case 0x04:
    AtCmdDrvobj.Key3Option=Key3_OptionFour;
    break;
  default:
    break;
  }
#endif
  
  switch(AtCmdDrvobj.key_top_value)
  {
  case 0x00:
    AtCmdDrvobj.key_top_option=REMOTE_AND_LOCAL_ALARM;
    break;
  case 0x01:
    AtCmdDrvobj.key_top_option=REMOTE_ALARM_ONLY;
    break;
  case 0x02:
    AtCmdDrvobj.key_top_option=LOCAL_ALARM_ONLY;
    break;
  default:
    break;
  }
}

bool ApiAtCmd_WritCommand(AtCommType id, u8 *buf, u16 len)
{
  bool r = TRUE;
  DrvMC8332_TxPort_SetValidable(ON);
  switch(id)
  {
  case ATCOMM_ATE1:
    DrvGD83_UART_TxCommand((u8*)cTxATE1, strlen((char const*)cTxATE1));
    break;
  case ATCOMM_CPIN:
    DrvGD83_UART_TxCommand((u8*)cTxCPIN, strlen((char const*)cTxCPIN));
    break;
  case ATCOMM_CGDCONT_SET:
    switch(AtCmdDrvobj.apn_set)
    {
    case 0:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET0, strlen((char const*)cTxCGDCONT_SET0));
      break;
    case 1:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET1, strlen((char const*)cTxCGDCONT_SET1));
      break;
    case 2:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET2, strlen((char const*)cTxCGDCONT_SET2));
      break;
    case 3:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET3, strlen((char const*)cTxCGDCONT_SET3));
      break;
    case 4:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET4, strlen((char const*)cTxCGDCONT_SET4));
      break;
    case 5:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET5, strlen((char const*)cTxCGDCONT_SET5));
      break;
    case 6:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET6, strlen((char const*)cTxCGDCONT_SET6));
      break;
    case 7:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET7, strlen((char const*)cTxCGDCONT_SET7));
      break;
    case 8:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET8, strlen((char const*)cTxCGDCONT_SET8));
      break;
    case 9:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET9, strlen((char const*)cTxCGDCONT_SET9));
      break;
    case 10:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET10, strlen((char const*)cTxCGDCONT_SET10));
      break;
    case 11:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET11, strlen((char const*)cTxCGDCONT_SET11));
      break;
    case 12:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET12, strlen((char const*)cTxCGDCONT_SET12));
      break;
    case 13:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET13, strlen((char const*)cTxCGDCONT_SET13));
      break;
    case 14:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET14, strlen((char const*)cTxCGDCONT_SET14));
      break;
    case 15:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET15, strlen((char const*)cTxCGDCONT_SET15));
      break;
    case 16:
      DrvGD83_UART_TxCommand((u8*)cTxCGDCONT_SET16, strlen((char const*)cTxCGDCONT_SET16));
      break;
    default:
      break;
    }
    break;
  case ATCOMM_CREG:
    DrvGD83_UART_TxCommand((u8*)cTxCREG, strlen((char const*)cTxCREG));
    break;
  case ATCOMM_ZPAS:
    DrvGD83_UART_TxCommand((u8*)cTxZPAS, strlen((char const*)cTxZPAS));
    break;
  case ATCOMM_CGACT:
    DrvGD83_UART_TxCommand((u8*)cTxCGACT, strlen((char const*)cTxCGACT));
    AtCmdDrvobj.ZGIPDNS=1;
    break;
  case ATCOMM_ZGACT1:
    DrvGD83_UART_TxCommand((u8*)cTxZGACT1, strlen((char const*)cTxZGACT1));
    AtCmdDrvobj.ZCONSTAT=1;
    break;
  case ATCOMM_CSQ:
    DrvGD83_UART_TxCommand((u8*)cTxCSQ, strlen((char const*)cTxCSQ));
    break;
  case ATCOMM_ZTTS:
    DrvGD83_UART_TxCommand((u8*)cTxPlayZtts, strlen((char const*)cTxPlayZtts));
    break;
  case ATCOMM_RESET:
    DrvGD83_UART_TxCommand((u8*)cTxRESET, strlen((char const*)cTxRESET));
    break;
  case ATCOMM_POWEROFF:
    DrvGD83_UART_TxCommand((u8*)cTxPOWEROFF, strlen((char const*)cTxPOWEROFF));
    break;
  case ATCOMM_Test:
    DrvGD83_UART_TxCommand(buf, len);
    break;
  case ATCOMM_ZGACT0:
    DrvGD83_UART_TxCommand((u8*)cTxZGACT0, strlen((char const*)cTxZGACT0));
    break;
  case ATCOMM_SetNetwork4GAuto:
    DrvGD83_UART_TxCommand((u8*)cTxSetNetwork4GAuto, strlen((char const*)cTxSetNetwork4GAuto));
    break;
  case ATCOMM_SetNetwork3GAuto:
    DrvGD83_UART_TxCommand((u8*)cTxSetNetwork3GAuto, strlen((char const*)cTxSetNetwork3GAuto));
    break;
  case ATCOMM_SetNetwork2GOnly:
    DrvGD83_UART_TxCommand((u8*)cTxSetNetwork2GOnly, strlen((char const*)cTxSetNetwork2GOnly));
    break;
  case ATCOMM_SetNetwork3GOnly:
    DrvGD83_UART_TxCommand((u8*)cTxSetNetwork3GOnly, strlen((char const*)cTxSetNetwork3GOnly));
    break;
  case ATCOMM_SetNetwork4GOnly:
    DrvGD83_UART_TxCommand((u8*)cTxSetNetwork4GOnly, strlen((char const*)cTxSetNetwork4GOnly));
    break;
  case ATCOMM_ZICCID:
    DrvGD83_UART_TxCommand((u8*)cTxZICCID, strlen((char const*)cTxZICCID));
    break;
  case ATCOMM_POCID:
    DrvGD83_UART_TxCommand((u8*)cTxPOCID, strlen((char const*)cTxPOCID));
    break;
  default:
    break;
  }
  r = DrvMc8332_UART_TxTail();
  DrvMC8332_TxPort_SetValidable(OFF);
  return r;
}

void ApiAtCmd_100msRenew(void)
{

}

void ApiCaretCmd_10msRenew(void)
{
  u8 * pBuf, Len;
  while((Len = DrvMC8332_CaretNotify_Queue_front(&pBuf)) != 0)
  {
  }
}

void ApiAtCmd_10msRenew(void)
{
  u8 * pBuf, ucRet, Len, i;
  u8 comma_count=0;
  u8 temp_buf1[10]={0};
  u8 temp_buf2[10]={0};
  while((Len = DrvMC8332_AtNotify_Queue_front(&pBuf)) != 0)
  {
/*****开机收到会收到ZREADY**************/
    ucRet = memcmp(pBuf, cRxZREADY, 6);
    if(ucRet==0x00)
    {
      if(AtCmdDrvobj.Msg.Bits.bCommunicationTest==1)
      {
        DISPLAY_Show(d_receive_zready);
      }
      else
      {
        AtCmdDrvobj.Msg.Bits.bCommunicationTest=1;
      }
    }
/****信号获取及判断CSQ-测试ok*********************/
    ucRet = memcmp(pBuf, cRxCSQ, 5);
    if(ucRet == 0x00)
    {
      for(i = 0x00; i < Len; i++)
      {
        if(pBuf[i]==',')
        {
          if(comma_count==0)
          {
            memcpy(temp_buf1,pBuf+5,i-5);
            AtCmdDrvobj.csq_param.rssi=CHAR_TO_Digital(temp_buf1,i-5);//获取当前信号强度
          }
          if(comma_count==1)
          {
            memcpy(temp_buf2,pBuf+i+1,Len-i-1);
            AtCmdDrvobj.csq_param.act=CHAR_TO_Digital(temp_buf2,Len-i-1);
          }
          comma_count++;
        }
      }
      comma_count=0;
      if(MenuMode_Flag==0)
      {
        HDRCSQSignalIcons();
      }
    }
/******查询SIM卡状态*************/
    ucRet = memcmp(pBuf, cRxCPINREADY, 11);
    if(ucRet==0x00)//收到CPIN: READY
    {
      AtCmdDrvobj.Msg.Bits.bSimCardIn=1;
      AtCmdDrvobj.Msg.Bits.bNoSimCard=0;
    }
    ucRet = memcmp(pBuf, cRxSIMERROR, 14);
    if(ucRet==0x00)//收到CME ERROR: SIM
    {
      AtCmdDrvobj.Msg.Bits.bSimCardIn=0;
      AtCmdDrvobj.Msg.Bits.bNoSimCard=1;
    }
/*****获取网络注册状态*********/
    ucRet = memcmp(pBuf, cRxCREG, 8);
    if(ucRet==0x00)
    {
      AtCmdDrvobj.network_reg.creg=CHAR_TO_Digital(pBuf+8,1);
    }
/*****获取模块网络状态********************/
    ucRet = memcmp(pBuf, cRxZPAS_NOSERVICE, strlen((char const *)cRxZPAS_NOSERVICE));
    if(ucRet==0x00)//无服务
    {
      AtCmdDrvobj.network_mode=m_NOSERVICE;
    }

    ucRet = memcmp(pBuf, cRxZPAS_LIMITEDSERVICE, strlen((char const *)cRxZPAS_LIMITEDSERVICE));
    if(ucRet==0x00)//限制服务
    {
      AtCmdDrvobj.network_mode=m_LIMITEDSERVICE;
    }
    
    ucRet = memcmp(pBuf, cRxZPAS_GSM, strlen((char const *)cRxZPAS_GSM));
    if(ucRet==0x00)//2G
    {
      AtCmdDrvobj.network_mode=m_GSM;
    }

    ucRet = memcmp(pBuf, cRxZPAS_GPRS, strlen((char const *)cRxZPAS_GPRS));
    if(ucRet==0x00)//2G
    {
      AtCmdDrvobj.network_mode=m_GPRS;
    }

    ucRet = memcmp(pBuf, cRxZPAS_CDMA, strlen((char const *)cRxZPAS_CDMA));
    if(ucRet==0x00)//2G
    {
      AtCmdDrvobj.network_mode=m_CDMA;
    }
    ucRet = memcmp(pBuf, cRxZPAS_EDGE, strlen((char const *)cRxZPAS_EDGE));
    if(ucRet==0x00)//e
    {
      AtCmdDrvobj.network_mode=m_EDGE;
    }
    ucRet = memcmp(pBuf, cRxZPAS_EVDO, strlen((char const *)cRxZPAS_EVDO));
    if(ucRet==0x00)//3G
    {
      AtCmdDrvobj.network_mode=m_EVDO;
    }

    ucRet = memcmp(pBuf, cRxZPAS_EHRPD, strlen((char const *)cRxZPAS_EHRPD));
    if(ucRet==0x00)//eH
    {
      AtCmdDrvobj.network_mode=m_EHRPD;
    }

    ucRet = memcmp(pBuf, cRxZPAS_UMTS, strlen((char const *)cRxZPAS_UMTS));
    if(ucRet==0x00)//3G
    {
      AtCmdDrvobj.network_mode=m_UMTS;
    }

    ucRet = memcmp(pBuf, cRxZPAS_HSDPA, strlen((char const *)cRxZPAS_HSDPA));
    if(ucRet==0x00)//H
    {
      AtCmdDrvobj.network_mode=m_HSDPA;
    }

    ucRet = memcmp(pBuf, cRxZPAS_HSUPA, strlen((char const *)cRxZPAS_HSUPA));
    if(ucRet==0x00)//H
    {
      AtCmdDrvobj.network_mode=m_HSUPA;
    }

    ucRet = memcmp(pBuf, cRxZPAS_HSPA, strlen((char const *)cRxZPAS_HSPA));
    if(ucRet==0x00)//H
    {
      AtCmdDrvobj.network_mode=m_HSPA;
    }

    ucRet = memcmp(pBuf, cRxZPAS_HSPAPLUS, strlen((char const *)cRxZPAS_HSPAPLUS));
    if(ucRet==0x00)//H+
    {
      AtCmdDrvobj.network_mode=m_HSPAPLUS;
    }

    ucRet = memcmp(pBuf, cRxZPAS_LTE, strlen((char const *)cRxZPAS_LTE));
    if(ucRet==0x00)//4G
    {
      AtCmdDrvobj.network_mode=m_LTE;
    }

    ucRet = memcmp(pBuf, cRxZPAS_TDSCDMA, strlen((char const *)cRxZPAS_TDSCDMA));
    if(ucRet==0x00)//4G
    {
      AtCmdDrvobj.network_mode=m_TDSCDMA;
    }
/******************************************/
    ucRet = memcmp(pBuf, cRxCGREG, 7);
    if(ucRet==0x00)
    {
      AtCmdDrvobj.network_reg.cgreg=CHAR_TO_Digital(pBuf+7,1);
    }
    
    ucRet = memcmp(pBuf, cRxCEREG, 7);
    if(ucRet==0x00)
    {
      AtCmdDrvobj.network_reg.cereg=CHAR_TO_Digital(pBuf+7,1);
    }
/*****************************/
    ucRet = memcmp(pBuf, cRxCGDCONT, 8);
    if(ucRet==0x00)
    {
      AtCmdDrvobj.Msg.Bits.bCGDCONT=1;
    }
/*****主动上报IP地址/DNS服务器地址ZGIPDNS***************/
    ucRet = memcmp(pBuf, cRxZGIPDNS, 10);
    if(ucRet==0x00)
    {
      AtCmdDrvobj.ZGIPDNS=2;
    }
/*****发送zgact回复RNDIS链接情况***************/
    ucRet = memcmp(pBuf, cRxZCONSTAT, 13);
    if(ucRet==0x00)
    {
      AtCmdDrvobj.ZCONSTAT=2;
      AtCmdDrvobj.network_reg.creg=0;
      AtCmdDrvobj.network_reg.cereg=0;
      AtCmdDrvobj.network_reg.cgreg=0;
    }
/********LTE丢网指示***********************/
    ucRet = memcmp(pBuf, cRxZLTENOCELL, 10);
    if(ucRet==0x00)
    {
      AtCmdDrvobj.ZLTENOCELL=1;
    }
/*******语音播放喇叭控制标志位*******************/
#if 1

    ucRet = memcmp(pBuf, cRxZTTS0, 7);
    if(ucRet == 0x00)
    {
      //AtCmdDrvobj.Msg.Bits.bZTTSStates=0;//语音播报结束，关闭播放标志位
      AtCmdDrvobj.Msg.Bits.bZTTSStates_Intermediate=1;//语音播报结束，延迟2s关闭播放
    }
#endif
/****未插卡CMEERROR**********************/

/****数据业务拨号ZPPPSTATUS*************/

/****信号获取及判断CSQ*********************/
  }
}

bool ApiAtCmd_PlayVoice(AtVoiceType id, u8 *buf, u8 len)
{
  u8 temp_buf[4];
  bool r = TRUE;
#if 1 //3630 3610播报本地TTS无其他提示，故在此处设立标志位
  AtCmdDrvobj.Msg.Bits.bZTTSStates=1;
  AtCmdDrvobj.Msg.Bits.bZTTSStates_Intermediate = 0;//播报新语音时将中间变量清零，等待收到ztts0重新打开标志位
#endif
  DrvMC8332_TxPort_SetValidable(ON);
  DrvGD83_UART_TxCommand((u8*)cTxPlayZtts, strlen((char const *)cTxPlayZtts));
  temp_buf[0] = 0x31;	// 1
  temp_buf[1] = 0x2C;	// ,
  temp_buf[2] = 0x22;	// "
  DrvGD83_UART_TxCommand(temp_buf, 3);
  switch(id)
  {
  case ATVOICE_FreePlay :
    DrvGD83_UART_TxCommand(buf, len);
    break;
  default:
    break;
  }
  temp_buf[0] = 0x22;	// "
  DrvGD83_UART_TxCommand(temp_buf, 1);
  r  = DrvMc8332_UART_TxTail();
  DrvMC8332_TxPort_SetValidable(OFF);
  return r;
}

void NetworkModeIcons(bool fresh)
{
  if(AtCmdDrvobj.network_mode_old!=AtCmdDrvobj.network_mode)//如果网络制式已切换
  {
    AtCmdDrvobj.network_mode_old=AtCmdDrvobj.network_mode;
    NetworkModeIcons_first();
  }
  else
  {
    if(fresh==TRUE)//强行刷新，菜单退出使用
    {
      NetworkModeIcons_first();
    }
  }
}

static void NetworkModeIcons_first(void)
{
    switch(AtCmdDrvobj.network_mode)
    {
    case m_NOSERVICE:
    case m_LIMITEDSERVICE:
      api_disp_icoid_output( eICO_IDSPEAKEROff, TRUE, TRUE);//图标：X-无信号
      break;
    case m_GSM:
    case m_GPRS:
    case m_CDMA:
      api_disp_icoid_output( eICO_IDPOWERL, TRUE, TRUE);//图标：2G 
      break;
    case m_EDGE:
      api_disp_icoid_output( eICO_IDVOXOff, TRUE, TRUE);//图标：E
      break;
    case m_EVDO:
    case m_EHRPD:
    case m_UMTS:
      api_disp_icoid_output( eICO_IDEmergency, TRUE, TRUE);//图标：3G
      break;
    case m_HSDPA:
    case m_HSUPA:
    case m_HSPA:
      api_disp_icoid_output( eICO_IDSCANOff, TRUE, TRUE);//图标：H
      break;
    case m_HSPAPLUS:
      api_disp_icoid_output( eICO_IDLOCKEDOff, TRUE, TRUE);//图标：H+
      break;
    case m_TDSCDMA:
      api_disp_icoid_output( eICO_IDTALKAROff, TRUE, TRUE);//图标：T
      break;
    case m_LTE:
      api_disp_icoid_output( eICO_IDOffStart, TRUE, TRUE);//图标：4G
      break;
    default:
      break;
    }
    api_disp_all_screen_refresh();
}

void HDRCSQSignalIcons(void)
{
  if(AtCmdDrvobj.csq_param.rssi==99||AtCmdDrvobj.csq_param.rssi==0)//当无信号时
  {
    api_disp_icoid_output( eICO_IDMESSAGE, TRUE, TRUE);//图标：0格信号
  }
  else if(AtCmdDrvobj.csq_param.rssi>0&&AtCmdDrvobj.csq_param.rssi<15)
  {
    api_disp_icoid_output( eICO_IDMESSAGE, TRUE, TRUE);//图标：0格信号
  }
  else if(AtCmdDrvobj.csq_param.rssi>=15&&AtCmdDrvobj.csq_param.rssi<17)
  {
    api_disp_icoid_output( eICO_IDRXFULL, TRUE, TRUE);//图标：1格信号
  }
  else if(AtCmdDrvobj.csq_param.rssi>=17&&AtCmdDrvobj.csq_param.rssi<19)
  {
    api_disp_icoid_output( eICO_IDRXNULL, TRUE, TRUE);//图标：2格信号
  }
  else if(AtCmdDrvobj.csq_param.rssi>=19&&AtCmdDrvobj.csq_param.rssi<21)
  {
    api_disp_icoid_output( eICO_IDSCAN, TRUE, TRUE);//图标：3格信号
  }
  else if(AtCmdDrvobj.csq_param.rssi>=21&&AtCmdDrvobj.csq_param.rssi<23)
  {
    api_disp_icoid_output( eICO_IDSCANPA, TRUE, TRUE);//图标：4格信号
  }
  else if(AtCmdDrvobj.csq_param.rssi>=23)//5��
  {
    api_disp_icoid_output( eICO_IDSPEAKER, TRUE, TRUE);//图标：5格信号
  }

  api_disp_all_screen_refresh();// 全屏统一刷新
}

//根据写频软件参数boot_network_mode选择默认开机的网络模式（4G/3G/2G）
void boot_network_mode_selection(void)
{
  switch(AtCmdDrvobj.boot_network_mode)
  {
  case 0:
    ApiAtCmd_WritCommand(ATCOMM_SetNetwork4GAuto,0,0);//默认设置为网络模式自动选择，优先4G
    break;
  case 1:
    ApiAtCmd_WritCommand(ATCOMM_SetNetwork3GAuto,0,0);//默认设置为网络模式自动选择，优先3G
    break;
  case 2:
    ApiAtCmd_WritCommand(ATCOMM_SetNetwork2GOnly,0,0);//默认设置为网络模式仅限2G
    break;
  case 3:
    ApiAtCmd_WritCommand(ATCOMM_SetNetwork3GOnly,0,0);//默认设置为网络模式仅限3G
    break;
  case 4:
    ApiAtCmd_WritCommand(ATCOMM_SetNetwork4GOnly,0,0);//默认设置为网络模式仅限4G
    break;
  default:
    ApiAtCmd_WritCommand(ATCOMM_SetNetwork4GAuto,0,0);//默认设置为网络模式自动选择，优先4G
    break;
  }
}

//根据写频软件参数选择默认开机的spk和mic增益
void cmvlc_and_clvlc_spk_mic_gain_selection(void)
{
  ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCLVL, strlen((char const*)cTxCLVL));
      
  switch(AtCmdDrvobj.clvlc_spk_gain)
  {
  case 0:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCLVLC0, strlen((char const*)cTxCLVLC0));
    break;
  case 1:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCLVLC1, strlen((char const*)cTxCLVLC1));
    break;
  case 2:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCLVLC2, strlen((char const*)cTxCLVLC2));
    break;
  case 3:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCLVLC3, strlen((char const*)cTxCLVLC3));
    break;
  case 4:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCLVLC4, strlen((char const*)cTxCLVLC4));
    break;
  case 5:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCLVLC5, strlen((char const*)cTxCLVLC5));
    break;
  default:
    break;
  }
  
  switch(AtCmdDrvobj.cmvlc_mic_gain)
  {
  case 0:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCMVLC0, strlen((char const*)cTxCMVLC0));
    break;
  case 1:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCMVLC1, strlen((char const*)cTxCMVLC1));
    break;
  case 2:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCMVLC2, strlen((char const*)cTxCMVLC2));
    break;
  case 3:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCMVLC3, strlen((char const*)cTxCMVLC3));
    break;
  case 4:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCMVLC4, strlen((char const*)cTxCMVLC4));
    break;
  case 5:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxCMVLC5, strlen((char const*)cTxCMVLC5));
    break;
  default:
    break;
  }
}


//美版模块测试专用标志位，美版模块需进入特殊状态才能在国内正常使用
void U1C_test_mode(void)//是否进入美版测试状态
{
  switch(AtCmdDrvobj.test_mode)
  {
  case 0:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxQuitTestMode, strlen((char const*)cTxQuitTestMode));
    break;
  case 1:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxTESTMODESETStep1, strlen((char const*)cTxTESTMODESETStep1));
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxTESTMODESETStep2, strlen((char const*)cTxTESTMODESETStep2));
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxTESTMODESETStep3, strlen((char const*)cTxTESTMODESETStep3));
    break;
  default:
    ApiAtCmd_WritCommand(ATCOMM_Test,(u8*)cTxQuitTestMode, strlen((char const*)cTxQuitTestMode));
    break;
  }
}

u32  CHAR_TO_Digital(u8 * pBuf, u8 Len)
{
	u8 i;
	u32 buf = 0;
	for(i = 0; i < Len; i++)
	{
		buf *= 10;
#if 0
                if(pBuf[i]>=0x30&&pBuf[i]<=0x39)
                {
                  buf += (pBuf[i] - 0x30);
                }
                else
                {
                  buf += (0x30 - 0x30);
                }
#else
                buf += (pBuf[i] - 0x30);
#endif
		
	}
	return buf;
}
void  Digital_TO_CHAR(u8 * pBuf, u32 data, u8 Len)
{
	u8 i;
	for(i = Len-1; i != 0; i--)
	{
		pBuf[i] = data%10 + 0x30;
		data /= 10;
	}
	pBuf[0] = data+0x30;
}

void  CHAR_TO_DIV_CHAR(u8 * pPrimary, u8 * pDestination, u8 Len)
{
	u8 i, j , buf;
	for(i =0; i != Len; i++)
	{
		buf = (pPrimary[i] >> 0x04) & 0x0F;
		j = i * 2;
		if(buf < 0x0A)
		{
			pDestination[j] = buf + 0x30;
		}
		else
		{
			pDestination[j] = buf + 0x57;
		}
		buf = pPrimary[i] & 0x0F;
		if(buf < 0x0A)
		{
			pDestination [j + 1] = buf + 0x30;
		}
		else
		{
			pDestination[j + 1] = buf + 0x57;
		}
	}
}

