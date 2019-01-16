#ifndef __APIATCMD_H
#define __APIATCMD_H

#include "AllHead.h"

typedef enum{
  m_NOSERVICE     =0x00,
  m_GSM           =0x01,
  m_GPRS          =0x02,
  m_CDMA          =0x03,
  m_EDGE          =0x04,
  m_EVDO          =0x05,
  m_EHRPD         =0x06,
  m_UMTS          =0x07,
  m_HSDPA         =0x08,
  m_HSUPA         =0x09,
  m_HSPA          =0x0a,
  m_HSPAPLUS      =0x0b,
  m_LTE           =0x0c,
  m_TDSCDMA       =0x0d,
  m_LIMITEDSERVICE=0x0e
}NETWORK_TYPE;
typedef enum{
  m_CHINESE       = 0x00,
  m_ENGLISH       = 0x01
}LANGUAGE_TYPE;

typedef enum{
  REMOTE_AND_LOCAL_ALARM        = 0x00,
  REMOTE_ALARM_ONLY             = 0x01,
  LOCAL_ALARM_ONLY              = 0x02,
}KEY_TOP_TYPE;

typedef struct{
  union{
    struct{
      u16  bCommunicationTest           :1;
      u16  bSimCardIn                   :1;
      u16  bNoSimCard                   :1;
      u16  bCGDCONT                     :1;
      u16  bZTTSStates                  :1;
      u16  bZTTSStates_Intermediate     :1;
      u16                               :10;
    }Bits;
    u16 Byte;
  }Msg;
  u8 ZLTENOCELL;
  u8 ZGIPDNS;
  u8 ZCONSTAT;
  struct{
    u8 rssi;//信号强度指示
    u8 act;//信号对应的当前制式
  }csq_param;
    NETWORK_TYPE network_mode;
    NETWORK_TYPE network_mode_old;
  struct{
    u8 creg;
    u8 cgreg;
    u8 cereg;
  }network_reg;//网络注册状态CREG/CGREG/CEREG
  u8 ccid[20];
  u8 apn_set;
  u8 language_value;
  LANGUAGE_TYPE language_set;
  u8 Key3_PlayValue;
  u8 key_top_value;
  u8 key2_long_value;
  u8 key3_long_value;
  u8 key4_long_value;
  u8 boot_network_mode;
  u8 clvlc_spk_gain;
  u8 cmvlc_mic_gain;
  //u8 testbuf[20];
  Key3_OptionType Key3Option;
  KEY_TOP_TYPE key_top_option;
  bool punch_the_clock_gps_key_press_flag;
  bool getting_info_flag;
  bool voice_tone_play;
  bool ready_return_to_default_state_flag;
}AtCmdDrv;

typedef enum{
  ATCOMM_ATE1                   = 0x00,
  ATCOMM_CPIN                   = 0x01,
  ATCOMM_CGDCONT_SET            = 0x02,
  ATCOMM_CREG                    = 0x03,
  ATCOMM_ZPAS                    = 0x04,
  ATCOMM_CGACT                  = 0x05,
  ATCOMM_ZGACT1                  = 0x06,
  ATCOMM_CSQ                    = 0x07,
  ATCOMM_ZTTS                   = 0x08,
  ATCOMM_RESET                  = 0x09,
  ATCOMM_POWEROFF               = 0x0A,
  ATCOMM_Test                   = 0x0B,
  ATCOMM_SetNetwork4GAuto       = 0x0C,
  ATCOMM_SetNetwork3GAuto       = 0x0D,
  ATCOMM_SetNetwork2GOnly       = 0x0E,
  ATCOMM_SetNetwork3GOnly       = 0x0F,
  ATCOMM_SetNetwork4GOnly       = 0x10,
  ATCOMM_ZGACT0                 = 0x11,
  ATCOMM_ZICCID                 = 0x12,
  ATCOMM_POCID                  = 0x13
}AtCommType;


extern AtCmdDrv AtCmdDrvobj;
extern u8 KeyDownUpChoose_GroupOrUser_Flag;

extern void ApiAtCmd_PowerOnInitial(void);
extern bool ApiAtCmd_WritCommand(AtCommType id, u8 *buf, u16 len);
extern bool ApiAtCmd_PlayVoice(AtVoiceType id, u8 *buf, u8 len);
extern void NetworkModeIcons(bool fresh);
extern void HDRCSQSignalIcons(void);
extern void ApiAtCmd_100msRenew(void);
extern void ApiCaretCmd_10msRenew(void);
extern void ApiAtCmd_10msRenew(void);
extern void boot_network_mode_selection(void);
extern void cmvlc_and_clvlc_spk_mic_gain_selection(void);

extern u32  CHAR_TO_Digital(u8 * pBuf, u8 Len);
extern void  Digital_TO_CHAR(u8 * pBuf, u32 data, u8 Len);
extern void  CHAR_TO_DIV_CHAR(u8 * pPrimary, u8 * pDestination, u8 Len);

#endif