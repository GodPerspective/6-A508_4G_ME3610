#ifndef __APIVOICE_H
#define __APIVOICE_H

typedef enum{
  PersonalMode          = 0x00,
  ABELL                 = 0x01,
  AllGroupName          = 0x02,
  GroupSelected         = 0x03,
  NoSimCard             = 0x04,
  NetworkSearching      = 0x05,
  PowerLowPleaseCharge  = 0x06,
  FivePercentPower      = 0x07,
  TwentyPercentPower    = 0x08,
  FortyPercentPower     = 0x09,
  SixtyPercentPower     = 0x0a,
  EightyPercentPower    = 0x0b,
  OneHundredPercentPower= 0x0c,
  GroupMode             = 0x0d,
  HandsetMode           = 0x0e,
  HandfreeMode          = 0x0f,
  AllUserName           = 0x10,
  NoOnlineUser          = 0x11,
  LowBattery            = 0x12,
  LoggingIn             = 0x13,
  SimCardError          = 0x14,
  cs_unknow_network     = 0x15,//CS未知网络
  gprs_unknow_network   = 0x16,//GPRS未知网络
  gprs_refuse_enroll    = 0x17,//GPRS注册被拒绝 
  eps_unknow_network    = 0x18,//EPS未知网络 
  eps_refuse_enroll     = 0x19,//EPS注册被拒绝 
  all_unknow_network    = 0x1A,
  No_service            = 0x1B,
  set_network_auto      = 0x1C,
  set_network_3G_Auto   = 0x1D,
  set_network_2G_only   = 0x1F,
  punch_the_clock       = 0x20,//正在打卡
  punch_the_clock_fail  = 0x21,//打卡失败
  gps_not_located       = 0x22
   
}VOICEPLAY_TYPE;
typedef enum
{	
	VOICE_IDKEY	= 0x00,
	VOICE_IDPOWON	= 0x01,
	VOICE_IDCHCHG	= 0x02,
	VOICE_IDLOWBAT	= 0x04,
	VOICE_IDALARM	= 0x05,
	VOICE_IDSCAN	= 0x06,
	VOICE_IDRESET	= 0xFF
}VOICE_TYPE;
typedef enum{
	ATVOICE_FreePlay		= 0x0001,
	ATVOICE_CardError		= 0x0002,
	ATVOICE_SingalError	        = 0x0004,
	ATVOICE_CheckNet		= 0x0008,
	ATVOICE_Landing			= 0x0010,
	ATVOICE_LandSuccess	        = 0x0020,
	ATVOICE_LowAlarm		= 0x0040,
	ATVOICE_LowPowOff		= 0x0080,
	ATVOICE_Battery			= 0x0100,
	ATVOICE_Unline			= 0x0200
}AtVoiceType;

typedef enum
{
	VOICE_IDOFF	= 0x00,
	VOICE_IDCH	= 0x01,
	VOICE_IDPOW	= 0x02,
	VOICE_IDBATT= 0x03
}TPCONT_SEL;

extern void VOICE_Play(VOICEPLAY_TYPE id);

extern void VOICE_PowerOnInitial(void);
extern void VOICE_SetOutput(AtVoiceType Id, u8 *buf, u8 Len);
extern void VOICE_Renew(void);
extern void VOICE_1sProcess(void);

#endif