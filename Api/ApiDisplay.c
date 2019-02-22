//apiDisplayʹ��GBK�򿪣���������ΪUTF-8
#include "AllHead.h"
#include <string.h>


const u8 CHAR_HIGH[2][8]  = { 0x02, 0x02, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02,0x02, 0x02, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02 };
const u8 CHAR_WIDTH[2][8] = { 0x08, 0x10, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10,0x08, 0x10, 0x06, 0x08, 0x08, 0x08, 0x10, 0x10 };
const u8 BitTab[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

const u8 Ico_DataBuf[32][32]=
{
{0x00,0xF8,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0xE0,0x00,
0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00},//0-电池电量0

{0x00,0xF8,0x08,0xE8,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0xE0,0x00,
0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00},//1-电池电量1

{0x00,0xF8,0x08,0xE8,0x08,0xE8,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0xE0,0x00,
0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00},//2-电池电量2

{0x00,0xF8,0x08,0xE8,0x08,0xE8,0x08,0xE8,0x08,0x08,0x08,0x08,0x08,0xF8,0xE0,0x00,   //3-电池电量3
0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00},

{0x00,0xF8,0x08,0xE8,0x08,0xE8,0x08,0xE8,0x08,0xE8,0x08,0x08,0x08,0xF8,0xE0,0x00,
0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00},//4-电池电量4

{0x00,0xF8,0x08,0xE8,0x08,0xE8,0x08,0xE8,0x08,0xE8,0x08,0xE8,0x08,0xF8,0xE0,0x00,
0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00},//5-电池电量5

#if 1//国�?�版选显示为“s�??
{0X00,0X00,0X00,0X00,0X38,0X7C,0XEC,0XCC,0XCC,0X9C,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X07,0X06,0X06,0X06,0X07,0X03,0X00,0X00,0X00,0X00,0X00,0X00},//�??//6

#else
{0X00,0X00,0X10,0X11,0XF2,0X00,0X28,0X26,0XE4,0X3F,0XE4,0X24,0X20,0X00,0X00,0X00,
0X00,0X00,0X08,0X04,0X03,0X04,0X0A,0X09,0X08,0X08,0X09,0X0A,0X0B,0X00,0X00,0X00},//�??//6

#endif

{0X04,0X0C,0X14,0XFC,0X14,0X0C,0X04,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X0F,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//0格信�??//7

{0X04,0X0C,0X14,0XFC,0X14,0X0C,0X04,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X0F,0X00,0X0C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//1格信�??//8

{0X04,0X0C,0X14,0XFC,0X14,0X0C,0X04,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X0F,0X00,0X0C,0X00,0X0F,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//2格信�??//9

{0X04,0X0C,0X14,0XFC,0X14,0X0C,0X04,0X00,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X0F,0X00,0X0C,0X00,0X0F,0X00,0X0F,0X00,0X00,0X00,0X00,0X00,0X00},//3格信�??//10

{0X04,0X0C,0X14,0XFC,0X14,0X0C,0X04,0X00,0X00,0XC0,0X00,0XF0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X0F,0X00,0X0C,0X00,0X0F,0X00,0X0F,0X00,0X0F,0X00,0X00,0X00,0X00},//4格信�??//11

{0X04,0X0C,0X14,0XFC,0X14,0X0C,0X04,0X00,0X00,0XC0,0X00,0XF0,0X00,0XFC,0X00,0X00,
0X00,0X00,0X00,0X0F,0X00,0X0C,0X00,0X0F,0X00,0X0F,0X00,0X0F,0X00,0X0F,0X00,0X00},//5格信�??//12

{0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//无发射无接收状态（空图标）//13
 
{0X00,0X7C,0X82,0X39,0X44,0X82,0X10,0XB8,0X10,0X82,0X44,0X39,0X82,0X7C,0X00,0X00,
0X00,0X00,0X00,0X01,0X00,0X00,0X0C,0X0F,0X0C,0X00,0X00,0X01,0X00,0X00,0X00,0X00},//发射�??//14

{0X82,0X44,0X39,0X82,0X7C,0X00,0X10,0XB8,0X10,0X00,0X7C,0X82,0X39,0X44,0X82,0X00,
0X00,0X00,0X01,0X00,0X00,0X00,0X0C,0X0F,0X0C,0X00,0X00,0X00,0X01,0X00,0X00,0X00},//接收�??//15

{0X00,0X00,0X00,0X00,0X48,0X48,0XB8,0X00,0XE0,0X10,0X08,0X48,0X48,0XD0,0X00,0X00,
0X00,0X00,0X00,0X00,0X02,0X02,0X01,0X00,0X00,0X01,0X02,0X02,0X02,0X03,0X00,0X00},//3G//16

{0X00,0X00,0X00,0X10,0X08,0X88,0X70,0X00,0XE0,0X10,0X08,0X48,0X48,0XD0,0X00,0X00,
0X00,0X00,0X00,0X02,0X03,0X02,0X02,0X00,0X00,0X01,0X02,0X02,0X02,0X03,0X00,0X00},//2G//17
 
{0XC0,0XE0,0XEC,0XFE,0XFE,0XEC,0XC0,0X80,0XC0,0XEC,0XFE,0XFE,0XEC,0XE0,0XC0,0X00,
0X01,0X03,0X03,0X03,0X03,0X03,0X01,0X01,0X01,0X03,0X03,0X03,0X03,0X03,0X01,0X00},//组呼//18
 
{0X00,0X00,0X00,0X00,0XC0,0XE0,0XEC,0XFE,0XFE,0XEC,0XE0,0XC0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X03,0X03,0X03,0X03,0X03,0X03,0X01,0X00,0X00,0X00,0X00},//�??�??//19

{0X00,0X00,0XF0,0XF0,0XF0,0XF8,0XFC,0XFE,0X00,0X08,0XF0,0X02,0X04,0XF8,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0X03,0X07,0X00,0X01,0X00,0X04,0X02,0X01,0X00,0X00},//免提模式//20

{0X00,0X00,0X00,0X0E,0X1F,0X3F,0X66,0XC0,0X80,0X00,0X80,0XC0,0XC0,0X80,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X03,0X03,0X03,0X03,0X01,0X00,0X00},//�??筒模�??//21
 
{0X00,0X00,0XF0,0X08,0X0E,0X09,0X69,0XE9,0X69,0X09,0X0E,0X08,0XF0,0X00,0X00,0X00,
0X00,0X00,0X03,0X04,0X04,0X04,0X04,0X05,0X04,0X04,0X04,0X04,0X03,0X00,0X00,0X00},//锁屏图标//22
 
{0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//空图�??//23
 
{0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//空白图标（与选ico对应�??//24

{0X00,0XC0,0XA0,0X90,0X8C,0XFC,0X80,0X00,0XF0,0X08,0X04,0X44,0X44,0XC8,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X03,0X00,0X00,0X00,0X01,0X02,0X02,0X02,0X03,0X00,0X00},//25-4G

{0X00,0X00,0XFC,0X24,0X24,0X24,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X01,0X01,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//26-E
 
{0X00,0X00,0XFC,0X20,0X20,0X20,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X00,0X00,0X00,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//27-H
 
{0X00,0X00,0XF8,0X40,0X40,0X40,0XF8,0X00,0X20,0X20,0XF8,0X20,0X20,0X00,0X00,0X00,
0X00,0X00,0X03,0X00,0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//28-H+
 
{0X00,0X00,0X04,0X04,0XFC,0X04,0X04,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//29-T
 
{0X00,0X00,0X88,0X50,0X20,0X50,0X88,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00},//30-x
 
{0x00,0xF8,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0xE0,0x00,
0x00,0x03,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x00,0x00},//31
};
#ifdef CHINESE
const u8 *dp_abell              = "   ŷ��Խ���   ";//1
const u8 *dp_personal_mode      = "   ����ģʽ     ";//2
const u8 *dp_no_sim_card        = "   ��忨       ";//3
const u8 *dp_network_search     = "��������...     ";//4
const u8 *dp_account_config     = "���ڵ�¼...     ";//5
const u8 *dp_please_charge      = "������,����   ";//6
const u8 *dp_menu               = "�˵�            ";//7
const u8 *dp_group_select       = "Ⱥ��ѡ��        ";//8
const u8 *dp_gps_information    = "GPS��Ϣ         ";//9
const u8 *dp_backlight_time     = "�����ʱ��      ";//10
const u8 *dp_keypad_lock_time   = "������ʱ��      ";//11
const u8 *dp_software_version   = "�����汾        ";//12
const u8 *dp_press_well         = "�밴#��         ";//13
const u8 *dp_latitude0          = "γ��:00.000000  ";//14
const u8 *dp_longitude0         = "����:000.000000 ";//15
const u8 *dp_backlight          = "�����ʱ��      ";//16
const u8 *dp_keypad_lock        = "������ʱ��      ";//17
const u8 *dp_close              = "�ر�            ";//18
const u8 *dp_individual_call    = "��ʱȺ��        ";//19
const u8 *dp_version            = "�����汾        ";//20
const u8 *dp_press_ok_then_well = "�Ȱ�OK���ٰ�#�� ";//21
const u8 *dp_status_offline     = "״̬������      ";//22

const u8 *dp_SimCardError       = "��4G�ź�        ";//23
const u8 *dp_cs_unknow_network  = "CSδ֪����      ";//24
const u8 *dp_gprs_unknow_network= "GPRSδ֪����    ";//25
const u8 *dp_gprs_refuse_enroll = "GPRSע�ᱻ�ܾ�  ";//26
const u8 *dp_eps_unknow_network = "EPSδ֪����     ";//27
const u8 *dp_eps_refuse_enroll  = "EPSע�ᱻ�ܾ�   ";//28
const u8 *dp_all_unknow_network = "���������쳣    ";//29
const u8 *dp_no_service         = "�޷���          ";//30
const u8 *dp_getting_info       = "��ȡ��...       ";//31
const u8 *dp_not_in_groups      = "����Ⱥ��        ";//32
const u8 *dp_punch_the_clock    = "���ڴ�...     ";//33
const u8 *dp_punch_the_clock_fail="��ʧ��        ";//34
const u8 *dp_gps_not_located    = "GPSδ��λ       ";//35
const u8 *dp_receive_zready     = "�쳣�յ�ZREADY  ";//36
const u8 *dp_init               = "��ʼ��...       ";//37
const u8 *dp_2min_end_reset     = "2minδ��½����  ";//38

#else

  #ifdef CONEXIS
const u8 *dp_abell              = "     ABELL      ";//1
  #else
const u8 *dp_abell              = "    CONEXIS     ";//1
  #endif
const u8 *dp_personal_mode      = "Personal Mode   ";//2
const u8 *dp_no_sim_card        = "No SIM Card     ";//3
const u8 *dp_network_search     = "Network Search  ";//4
const u8 *dp_account_config     = "Account Config..";//5
const u8 *dp_please_charge      = " Please charge  ";//6
const u8 *dp_menu               = "Menu            ";//7
const u8 *dp_group_select       = "Group Select    ";//8
const u8 *dp_gps_information    = "GPS Information ";//9
const u8 *dp_backlight_time     = "Backlight Time  ";//10
const u8 *dp_keypad_lock_time   = "Keypad Lock Time";//11
const u8 *dp_software_version   = "Software Version";//12
const u8 *dp_press_well         = "Press #         ";//13
const u8 *dp_latitude0          = "Lat :00.000000  ";//14
const u8 *dp_longitude0         = "Lng :000.000000 ";//15
const u8 *dp_backlight          = "Backlight       ";//16
const u8 *dp_keypad_lock        = "Keypad Lock     ";//17
const u8 *dp_close              = "Close           ";//18
const u8 *dp_individual_call    = "Individual Call ";//19
const u8 *dp_version            = "A508L_ME3630:   ";//20
const u8 *dp_press_ok_then_well = "Press OK then # ";//21
const u8 *dp_status_offline     = "Status:Offline  ";//22

const u8 *dp_SimCardError       = "LTE NO CELL     ";//23
const u8 *dp_cs_unknow_network  = "CS NET unknow   ";//24
const u8 *dp_gprs_unknow_network= "GPRS NET unknow ";//25
const u8 *dp_gprs_refuse_enroll = "GPRS Signup Fail";//26
const u8 *dp_eps_unknow_network = "EPS NET unknow  ";//27
const u8 *dp_eps_refuse_enroll  = "EPS Signup Fail ";//28
const u8 *dp_all_unknow_network = "All NET unknow  ";//29
const u8 *dp_no_service         = "No service      ";//30
const u8 *dp_getting_info       = "getting info... ";//31
const u8 *dp_not_in_groups      = "Not in groups   ";//32
const u8 *dp_punch_the_clock    = "Checking in...  ";//33
const u8 *dp_punch_the_clock_fail="Checkin fail    ";//34
const u8 *dp_gps_not_located    = "Gps not located ";//35
const u8 *dp_receive_zready     = "receive ZREADY  ";//36

const u8 *dp_init               = "Initializing... ";//37
const u8 *dp_2min_end_reset     = "Logining 2 mins ";//38
#endif //#ifdef CHINESE

u8 DisDataBit[64]  = {0};
u8 DisDataBuf[512] = {0};

u16 CharCode;

static void DISP_DataBuf(DISP_CHAR DisInfo, u8 *CharData);
static void DISP_MulTypePro(DISP_CHAR CharInfo, u8 *CharData);
static void DISP_MulTypePro2(DISP_CHAR CharInfo, u8 *CharData);//UNICODE显示


void ApiDisplay_PowerOnInitial(void)
{
  CharCode=0;
}
void DISPLAY_Show(DISPLAY_TYPE id)
{
#ifdef CHINESE
    switch(id)
    {
    case d_ABELL://1
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)"                ");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_abell);
        break;
    case d_PersonalMode://2
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_personal_mode);
      break;
    case d_AllGroupName://3
      api_lcd_pwr_on_hint(0,2,GBK,"                ");//清屏
      api_lcd_pwr_on_hint(0,2,UNICODE,GetAllGroupNameForDisplay(groupCallingcount));//��ʾ��ǰѡ�е�Ⱥ����
      break;
    case d_NoSimCard://4
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_no_sim_card);
      break;
    case d_NetworkSearching://5
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_network_search);
      break;
    case d_AllUserName://6
      api_lcd_pwr_on_hint(0,2,GBK,"                ");//清屏
      api_lcd_pwr_on_hint(0,2,UNICODE,GetAllUserNameForDisplay(PersonalCallingNum));//��ʾ��ǰѡ�е�Ⱥ����
      break;
    case d_LoggingIn://7
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_account_config);
      break;
    case d_PowerLowPleaseCharge://8
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_please_charge);
      break;
    case d_menu://9
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_menu);
      break;
    case d_menu_groupselect://10
      api_lcd_pwr_on_hint(13,0,GBK,"1/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_group_select);
      break;
    case d_menu_gpsinformation://11
      api_lcd_pwr_on_hint(13,0,GBK,"2/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_gps_information);
      break;
    case d_menu_backlighttime://12
      api_lcd_pwr_on_hint(13,0,GBK,"3/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_backlight_time);
      break;
    case d_menu_keypadlocktime://13
      api_lcd_pwr_on_hint(13,0,GBK,"4/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_keypad_lock_time);
      break;
    case d_menu_softwareversion://14
      api_lcd_pwr_on_hint(13,0,GBK,"5/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_software_version);
      break;
    case d_presswell://15
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_press_well);
      break;
    case d_longitude_and_latitude0://16
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_latitude0);//清屏
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_longitude0);//清屏
      break;
    case d_backlight://17
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_backlight);
      break;
    case d_keypadlock://18
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_keypad_lock);
      break;
    case d_close://19
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_close);
      break;
    case d_individualcall://20
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_individual_call);//Individual Call临时群组
      break;
    case d_version://21
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_version);
      break;
    case d_press_ok_then_well://22
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_press_ok_then_well);
      break;
    case d_status_offline://23
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_status_offline);
      break;
    case d_SimCardError://24
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_SimCardError);
      break;
    case d_cs_unknow_network://25
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_cs_unknow_network);
      break;
    case d_gprs_unknow_network://26
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_gprs_unknow_network);
      break;
    case d_gprs_refuse_enroll://27
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_gprs_refuse_enroll);
      break;
    case d_eps_unknow_network://28
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_eps_unknow_network);
      break;
    case d_eps_refuse_enroll://29
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_eps_refuse_enroll);
      break;
    case d_all_unknow_network://30
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_all_unknow_network);
      break;
    case d_no_service://31
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_no_service);
      break;
    case d_getting_info://32
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_getting_info);
      break;
    case d_not_in_groups://33
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_not_in_groups);
      break;
    case d_punch_the_clock://34
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_punch_the_clock);
      break;
    case d_punch_the_clock_fail://35
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_punch_the_clock_fail);
      break;
    case d_gps_not_located://36
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_gps_not_located);
      break;
    case d_receive_zready://37
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_receive_zready);
      break;
    case d_init://38
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_init);
      break;
    case d_2min_end_reset://39
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_2min_end_reset);
      break;
    default:
      break;
    }
#else
    switch(id)
    {
    case d_ABELL://1
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_abell);
        break;
    case d_PersonalMode://2
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_personal_mode);
      break;
    case d_AllGroupName://3
      api_lcd_pwr_on_hint(0,2,GBK,"                ");//����
      api_lcd_pwr_on_hint(0,2,UNICODE,GetAllGroupNameForDisplay(groupCallingcount));//��ʾ��ǰѡ�е�Ⱥ����
      break;
    case d_NoSimCard://4
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_no_sim_card);
      break;
    case d_NetworkSearching://5
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_network_search);
      break;
    case d_AllUserName://6
      api_lcd_pwr_on_hint(0,2,GBK,"                ");//����
      api_lcd_pwr_on_hint(0,2,UNICODE,GetAllUserNameForDisplay(PersonalCallingNum));//��ʾ��ǰѡ�е�Ⱥ����
      break;
    case d_LoggingIn://7
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_account_config);
      break;
    case d_PowerLowPleaseCharge://8
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_please_charge);
      break;
    case d_menu://9
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_menu);
      break;
    case d_menu_groupselect://10
      api_lcd_pwr_on_hint(13,0,GBK,"1/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_group_select);
      break;
    case d_menu_gpsinformation://11
      api_lcd_pwr_on_hint(13,0,GBK,"2/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_gps_information);
      break;
    case d_menu_backlighttime://12
      api_lcd_pwr_on_hint(13,0,GBK,"3/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_backlight_time);
      break;
    case d_menu_keypadlocktime://13
      api_lcd_pwr_on_hint(13,0,GBK,"4/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_keypad_lock_time);
      break;
    case d_menu_softwareversion://14
      api_lcd_pwr_on_hint(13,0,GBK,"5/5");
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_software_version);
      break;
    case d_presswell://15
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_press_well);
      break;
    case d_longitude_and_latitude0://16
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_latitude0);//����
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_longitude0);//����
      break;
    case d_backlight://17
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_backlight);
      break;
    case d_keypadlock://18
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_keypad_lock);
      break;
    case d_close://19
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_close);
      break;
    case d_individualcall://20
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_individual_call);//Individual Call��ʱȺ��
      break;
    case d_version://21
      api_lcd_pwr_on_hint(0,0,GBK,(u8 *)dp_version);
      break;
    case d_press_ok_then_well://22
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_press_ok_then_well);
      break;
    case d_status_offline://23
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_status_offline);
      break;
    case d_SimCardError://24
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_SimCardError);
      break;
    case d_cs_unknow_network://25
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_cs_unknow_network);
      break;
    case d_gprs_unknow_network://26
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_gprs_unknow_network);
      break;
    case d_gprs_refuse_enroll://27
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_gprs_refuse_enroll);
      break;
    case d_eps_unknow_network://28
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_eps_unknow_network);
      break;
    case d_eps_refuse_enroll://29
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_eps_refuse_enroll);
      break;
    case d_all_unknow_network://30
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_all_unknow_network);
      break;
    case d_no_service://31
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_no_service);
      break;
    case d_getting_info://32
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_getting_info);
      break;
    case d_not_in_groups://33
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_not_in_groups);
      break;
    case d_punch_the_clock://34
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_punch_the_clock);
      break;
    case d_punch_the_clock_fail://35
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_punch_the_clock_fail);
      break;
    case d_gps_not_located://36
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_gps_not_located);
      break;
    case d_receive_zready://37
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_receive_zready);
      break;
    case d_init://38
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_init);
      break;
    case d_2min_end_reset://39
      api_lcd_pwr_on_hint(0,2,GBK,(u8 *)dp_2min_end_reset);
      break;
    default:
      break;
    }
#endif//ifdef CHINESE
}

void api_disp_char_output(DISP_CHAR CharInfo, u8 *CharData)
{	
	DISP_MulTypePro(CharInfo, CharData);
	return;
}

void api_disp_char_output2(DISP_CHAR CharInfo, u8 *CharData)//UNICODE显示，群组信�??显示屏显示使�??
{	
	DISP_MulTypePro2(CharInfo, CharData);
	return;
}

void api_lcd_pwr_on_hint(u8 x,u8 y,ENCODETYPE encode,u8 *CharData)
{
	DISP_CHAR stCharInfo;
	stCharInfo.DispType  = DISP_IDCNASC816;
	//stCharInfo.DispAddX  = 0;
	stCharInfo.DispAddY  = y;
	stCharInfo.DispAddX  = x;//一�??16�??英文字�??
        stCharInfo.DispLenth = LCD_DISP_LEN_MAX;
        
        if(encode==GBK)
        {
          api_disp_char_output(stCharInfo,CharData);
        }
        else//encode==UNICODE
        {
#ifdef CHINESE
            api_disp_char_output2(stCharInfo,CharData);//UNICODE显示，群组信�??显示屏显示使�??
#else
            api_disp_char_output(stCharInfo,CharData);
#endif
        }
	api_disp_all_screen_refresh();// 全屏统一刷新
}
void api_lcd_pwr_on_hint4(u8 *CharData)//UNICODE显示
{
	DISP_CHAR stCharInfo;
	stCharInfo.DispType  = DISP_IDCNASC816;
	//stCharInfo.DispAddX  = 0;
	stCharInfo.DispAddY  = 0x02;//左上角显示汉�??
	stCharInfo.DispAddX  = 0;//一�??16�??英文字�??
        stCharInfo.DispLenth = LCD_DISP_LEN_MAX;
        
	api_disp_char_output2(stCharInfo,CharData);//UNICODE显示，群组信�??显示屏显示使�??

	//MCU_LCD_BACKLIGTH(OFF);
	api_disp_all_screen_refresh();// 全屏统一刷新
}
void api_lcd_pwr_on_hint5(u8 *CharData)//UNICODE显示
{
	DISP_CHAR stCharInfo;
	stCharInfo.DispType  = DISP_IDCNASC816;
	//stCharInfo.DispAddX  = 0;
	stCharInfo.DispAddY  = 0x00;//左上角显示汉�??
	stCharInfo.DispAddX  = 0;//一�??16�??英文字�??
        stCharInfo.DispLenth = LCD_DISP_LEN_MAX;
        
	api_disp_char_output2(stCharInfo,CharData);//UNICODE显示，群组信�??显示屏显示使�??

	//MCU_LCD_BACKLIGTH(OFF);
	api_disp_all_screen_refresh();// 全屏统一刷新
}
/*******************************************************************************
* Description	: 刷新屏幕数据显示
* Input		: void
* Output		: void
* Return		: void
* Others		: void
********************************************************************************/
void api_disp_all_screen_refresh(void)
{
	u8 Page, XAlias;
	u16 iPoint;

	for (Page = 0; Page < PAGE_MAX; Page++)
	{
		iPoint = Page * 0x80;
		drv_htg_set_address(0, Page);
		for (XAlias = 0; XAlias < COL_MAX; XAlias++)
		{
			drv_htg_write_data(DisDataBuf[iPoint]);
			iPoint++;
		}
	}
	//bDisDataBufUsed = FALSE;
}





/*******************************************************************************
* Description	: Mixed type display process
* Input			: CharInfo : char display location and type information
				: *CharData: display char data
* Output		: void
* Return		: void
* Others		: void
********************************************************************************/
static void DISP_MulTypePro(DISP_CHAR CharInfo, u8 *CharData)
{
  //u8 CharCodeH;
  //u8 CharCodeL;
  u16 CharCode;
  DISP_CHAR DisInfo;
  u8  iLen = 0;//34
  u8  CharBuf[34];
  DisInfo = CharInfo;
  if ((CharInfo.DispType & 0x80) != 0x00)
  {
    DisInfo.DispLenth = 0x00;
    for (; *CharData != 0x00; DisInfo.DispLenth++)
    {
      if (DisInfo.DispLenth >= CharInfo.DispLenth) { return; }//（修改当显示长度�??16时的显示�??题）
      CharCode = *CharData;
      DisInfo.DispAddX = CharInfo.DispAddX + iLen;
      DisInfo.DispType = (DISP_TYPE)(CharInfo.DispType & BASETYPE);
      if (*CharData >= 0x80)//为中文字�??
      {
        iLen++;
        CharData++;
        CharCode <<= 0x08;
        CharCode |= (*CharData);
        DisInfo.DispType = DISP_IDCN1516;
        DisInfo.DispLenth++;//当显示中文，长度�??16时的显示�??�??
        //CharCodeH=(CharCode&0xff00)>>8;
        //CharCodeL=CharCode&0x00ff;
      }
      //GB2312_16_GetData(0xa3,0x65+0x80,CharBuf);//CharData[0]
      //GB2312_16_GetData(0xa3,0x42+0x80,CharBuf);
      drv_gt20_data_output(DisInfo.DispType, CharCode, CharBuf);
      //UNICODE_16_GetData(0xff42,CharBuf);
			DISP_DataBuf(DisInfo, CharBuf);
                        
			CharData++;
			iLen++;
		}
	}

	return;
}
static void DISP_MulTypePro2(DISP_CHAR CharInfo, u8 *CharData)//UNICODE显示
{
  u8  CharBuf2[32];
  DISP_CHAR DisInfo;
  u8  iLen = 0;//34
  DisInfo = CharInfo;
  if ((CharInfo.DispType & 0x80) != 0x00)
  {
    DisInfo.DispLenth = 0x00;
    for (; (*CharData != 0x00)||(*(CharData+1) != 0x00); DisInfo.DispLenth++)//添加*(CharData+1)判断，�?�致0x00也会进入�??�??，故在循�??内�?�理0x0000
    {
      if (DisInfo.DispLenth >= CharInfo.DispLenth) { return; }//（修改当显示长度�??16时的显示�??题）
      CharCode = *CharData;
      if(CharCode!=0x0000)//解决0x00显示屏占半个字�?�的�??�??
      {
        DisInfo.DispAddX = CharInfo.DispAddX + iLen;
        DisInfo.DispType = (DISP_TYPE)(CharInfo.DispType & BASETYPE);
        if (*CharData >= 0x4E)//为中文字�??//UNICODE范围�??4E00-9FA5
        {
          iLen++;
          CharData++;
          CharCode <<= 0x08;
          CharCode |= (*CharData);
          DisInfo.DispType = DISP_IDCN1516;
          DisInfo.DispLenth++;//当显示中文，长度�??16时的显示�??�??
        }
        drv_gt20_data_output2(DisInfo.DispType, CharCode, CharBuf2);
        DISP_DataBuf(DisInfo, CharBuf2);
        iLen++;
      }
      CharData++;
    }
  }
  return;
}
/*******************************************************************************
* Description	: display data process
* Input			: DisInfo : display char location and type information
				: *CharData: display char data
* Output		: void
* Return		: void
* Others		: void
********************************************************************************/
static void DISP_DataBuf(DISP_CHAR DisInfo, u8 *CharData)
{
	u16 iPt;
	u8  High, Width, xCol, yPage, nType, bType;
        //DisInfo.DispType = DISP_IDCN1516;//添加后数字和字母�??以显示一�??
	//bDisDataBufUsed = TRUE;
	yPage = DisInfo.DispAddY;
	nType = (DisInfo.DispType & NROWTYPE);//汉字�??0x01&0x10=0 字母�??0x05&0x10=0
	bType = (DisInfo.DispType & BASETYPE);//汉字�??0x01&0x0f=1 字母�??0x05&0x0f=5
	// if (DISP_OverBound(DisInfo) != TRUE) return;
	xCol  = (nType != 0x00) ? DisInfo.DispAddX : (DisInfo.DispAddX * 0x08);//一直取DisInfo.DispAddX * 0x08
	for (High = 0; High < CHAR_HIGH[0][bType]; High++)//汉字：CHAR_HIGH=2 字母：CHAR_HIGH=2
	{
		iPt = xCol + yPage * 0x80;//iPt�??8*8像素
		for (Width = 0; Width < CHAR_WIDTH[0][bType]; Width++)//汉字：CHAR_WIDTH=16 字母：CHAR_WIDTH=8
		{
			if (iPt < 512)//�??改当显示长度�??16时的显示�??�??
			{
				if (DisDataBuf[iPt] != (*CharData))
				{
					if (iPt == 3*0x80)
					{
						iPt = iPt;
					}
					DisDataBuf[iPt] = *CharData;//[512]
					DisDataBit[iPt / 0x08] |= BitTab[iPt % 0x08];//[64]
				}
				CharData++;
				iPt++;
			}
		}
		yPage++;
	}
	//bDisDataBufUsed = FALSE;
}

//显示屏图�??
/*******************************************************************************
* Description   : ico-id display process
* Input		: IcoInfo : ico data location information
		: IcoID : display ico-id
		: IcoDefault : ico display default location
* Output	: void
* Return	: void
* Others	: void
********************************************************************************/
void api_disp_icoid_output(u8 IcoIdIndex, bool IcoDefault,bool on_off)
{
	DISP_ICO IcoInfo;
	u8 IcoDataBuf[LCD_ICO_BUF_LEN];//LCD_ICO_BUF_LEN=32
  /* 两个字节存一�??像素 */
  if (on_off == TRUE)
  {
    //api_read_eeprom_data(IcoInf.iAdr, IcoDataLen, &IcoDataBuf[0]);
    memcpy(IcoDataBuf, &Ico_DataBuf[IcoIdIndex][0], LCD_ICO_BUF_LEN);
    }
    else
    {
      memset(&IcoDataBuf[0], 0x00, LCD_ICO_BUF_LEN);
    }
    if (IcoDefault == TRUE)	//使用默�?�图标位�??配置信息
	  {
      api_diap_ico_pos_get(&IcoInfo, IcoIdIndex);
    }
    api_disp_ico_output(IcoInfo, &IcoDataBuf[0]);
    return;
}

/*******************************************************************************
* Description	: ico data display process
* Input			: IcoInfo : ico display location information
				: *IcoData: display ico data
* Output		: void
* Return		: void
* Others		: void
********************************************************************************/
void api_disp_ico_output(DISP_ICO IcoInfo, u8 *IcoData)
{
	u16 iPt;
	u8  High, Width, yPage, xAxis;
	u8 *ptr;
        
	yPage = IcoInfo.DispAddY;
	xAxis = IcoInfo.DispAddX * 0x08;
	ptr = IcoData;
	for (High = 0; High < IcoInfo.DispHigh / 0x08; High++)
	{
		iPt = xAxis + yPage * 0x80;
		for (Width = 0; Width < IcoInfo.DispWidth; Width++)
		{
			if (DisDataBuf[iPt] != (*ptr))
			{
				DisDataBuf[iPt] = *ptr;
				//DisDrvObj.Msg.Bit.bRefresh = DISP_RUN;
				DisDataBit[iPt / 0x08] |= BitTab[iPt % 0x08];
			}
			ptr++;
			iPt++;
		}
		yPage++;
	}
}
/*******************************************************************************
* Description	: ico default location display process
* Input			: IcoInfo : ico display location information
				: IcoID : ico-id
* Output		: void
* Return		: void
* Others		: void
********************************************************************************/
void api_diap_ico_pos_get(DISP_ICO *pIcoInfo, u16 IcoID)
{
	switch (IcoID)
	{
    case eICO_IDMESSAGE://图标�??0格信�??
    case eICO_IDRXFULL://图标�??1格信�??
    case eICO_IDRXNULL://图标�??2格信�??
    case eICO_IDSCAN://图标�??3格信�??
    case eICO_IDSCANPA://图标�??4格信�??
    case eICO_IDSPEAKER://图标�??5格信�??
      pIcoInfo->DispAddX = 0x00;
      break;
    case eICO_IDSPEAKEROff://图标：X-无信�??
    case eICO_IDTALKAROff://图标：T
    case eICO_IDLOCKEDOff://图标：H+
    case eICO_IDSCANOff://图标：H
    case eICO_IDVOXOff://图标：E
    case eICO_IDOffStart://图标�??4G
    case eICO_IDEmergency://图标�??3G
    case eICO_IDPOWERL://图标�??2G
      pIcoInfo->DispAddX = 0x02;
      break;
    case eICO_IDTemper://图标：喇�??-免提模式
    case eICO_IDMONITER://图标：听�??-�??筒模�??
      pIcoInfo->DispAddX = 0x04;
      break;
    case eICO_IDPOWERM://图标：组�??
    case eICO_IDPOWERH://图标：个�??
      pIcoInfo->DispAddX = 0x06;
      break;
    case eICO_IDBANDWIDTHW://图标：锁�??
    case eICO_IDBANDWIDTHN://图标：空-无锁�??
      pIcoInfo->DispAddX = 0x0c;
      break;
    case eICO_IDTALKAR://图标：无-无发射无接收
    case eICO_IDTX://图标：发�??
    case eICO_IDVOX://图标：接�??
      pIcoInfo->DispAddX = 0x0a;
      break;
    case eICO_IDMESSAGEOff://图标：空-非选状�??
    case eICO_IDLOCKED://图标：选或s
      pIcoInfo->DispAddX = 0x08;
      break;
    case eICO_IDBATT://图标：空电池
    case eICO_IDBATT1://图标�??1格电�??
    case eICO_IDBATT2://图标�??2格电�??
    case eICO_IDBATT3://图标�??3格电�??
    case eICO_IDBATT4://图标�??4格电�??
    case eICO_IDBATT5://图标�??5格电�??
      pIcoInfo->DispAddX = 0x0e;
      break;
    default:
      break;
	}
  pIcoInfo->DispAddY = 0x00;
	pIcoInfo->DispWidth= 0x10;
	pIcoInfo->DispHigh = 0x10;
}
//附：从字库中读数�??函数说明 u8 r_dat_bat(u32 address,u8 byte_long,u8 *p_arr)实现参考代码�?
/****************************************************
u8 r_dat_bat(u32 address,u8 byte_long,u8 *p_arr)
Address  �?? 表示字�?�点阵在�??片中的字节地址�??
byte_long�?? �??读点阵数�??字节数�?
*p_arr   �?? �??保存读出的点阵数�??的数组�?
*****************************************************/
//u8 r_dat_bat(u32 address,u8 byte_long,u8 *p_arr)
unsigned char r_dat_bat(unsigned long address,unsigned long byte_long,unsigned char *p_arr)
{
	unsigned int j=0;
	MCU_GT20_CS(LO);
	SendByte(address); //发送指令及地址
	for(j=0;j<byte_long;j++)
	{
	 p_arr[j]=ReadByte();//读取数据到数组中
	}
	MCU_GT20_CS(HI);
	return p_arr[0];	
}
void SendByte(u32 cmd)
{
	u8 i;
	cmd=cmd|0x03000000;
	for(i=0;i<32;i++)
	{
		MCU_GT20_CLK(LO);
		if(cmd&0x80000000)
			MCU_GT20_SI(HI);
		else 
			MCU_GT20_SI(LO);
		MCU_GT20_CLK(HI);
		cmd=cmd<<1;
	}					
}

u8 ReadByte(void)
{
	u8 i;
	u8 dat=0;
	MCU_GT20_CLK(HI); 	
	for(i=0;i<8;i++)
	{
		MCU_GT20_CLK(LO); 
		dat=dat<<1;
		if(MCU_GT20_SO_Read)
			dat=dat|0x01;
		else 
			dat&=0xfe;
		MCU_GT20_CLK(HI); 	
	}	
	return dat;
        
        

}
