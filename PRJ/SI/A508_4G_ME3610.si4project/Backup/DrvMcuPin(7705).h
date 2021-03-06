#ifndef __DRVMCUPIN_H
#define __DRVMCUPIN_H

#include "stm8s.h"

typedef enum{
  OFF=0x00,
  ON=0x01
}IO_ONOFF;

typedef enum{
  LO=0x00,
  HI=0x01
}IO_HILO;

typedef union{
  struct
  {
    u16 Low: 8;
    u16 High: 8;
  }Byte;
  unsigned int Word;
}WordType;
typedef enum{
  KSTA_UP       = 0x00,
  KSTA_DOWN     = 0x01,
  KSTA_ERR      = 0x02,
  KSTA_ENTERY   = 0x03,
  KSTA_EXIT     = 0x04,
  KSTA_NULL     = 0xFF
}KEYSTA_TYPE;

typedef struct{
  u16  Adr;
  u8   Len;
  u8   Group;
}ADRLEN_INF;

/******************************************************************************
;--------1-LED hardware macro define
******************************************************************************/
#define GPIO_LED_Green          GPIOD
#define GPIO_LED_Red            GPIOD

#define GPIO_PIN_LED_Green      GPIO_PIN_3
#define GPIO_PIN_LED_Red        GPIO_PIN_2

/******************************************************************************
;--------2-TIM3:DELAY hardware macro define
******************************************************************************/
#define HSE_CLK

/******************************************************************************
;-------- 新功放 macro define
******************************************************************************/
#if 0 //not use
#define GPIO_GF_SCL              GPIOB
#define GPIO_PIN_GF_SCL          GPIO_PIN_6
                                  
#define GPIO_GF_SDA              GPIOB
#define GPIO_PIN_GF_SDA          GPIO_PIN_4 
#define READ_IIC_SDA             GPIO_ReadInputPin(GPIO_GF_SDA, GPIO_PIN_GF_SDA)
#endif

/******************************************************************************
;--------功放喇叭 hardware macro define
******************************************************************************/
#define GPIO_Noise_Mute         GPIOD
#define GPIO_PIN_Noise_Mute     GPIO_PIN_7

/******************************************************************************
;--------模块电源硬件开关 & 指示灯指示LED_MODE hardware macro define
******************************************************************************/
#define GPIO_Poweroff            GPIOD
#define GPIO_PIN_Poweroff       GPIO_PIN_4

#define GPIO_RSSI               GPIOB
#define GPIO_PIN_RSSI           GPIO_PIN_1
#define ReadInput_PIN_RSSI      GPIO_ReadInputPin(GPIO_RSSI, GPIO_PIN_RSSI)
/******************************************************************************
;--------5-KEY & KEYBOARD hardware macro define
******************************************************************************/
#define GPIO_Key_PTT            GPIOE
#define GPIO_Key_2              GPIOA
#define GPIO_Key_3              GPIOB
#define GPIO_Key_4              GPIOA
#define GPIO_Key_5              GPIOC
#define GPIO_Key_6              GPIOC
#define GPIO_Key_7              GPIOC
#define GPIO_Key_8              GPIOG
#define GPIO_Key_9              GPIOG
#define GPIO_Key_10             GPIOE

#define GPIO_PIN_Key_PTT        GPIO_PIN_5
#define GPIO_PIN_Key_2          GPIO_PIN_6
#define GPIO_PIN_Key_3          GPIO_PIN_7
#define GPIO_PIN_Key_4          GPIO_PIN_3
#define GPIO_PIN_Key_5          GPIO_PIN_5
#define GPIO_PIN_Key_6          GPIO_PIN_6
#define GPIO_PIN_Key_7          GPIO_PIN_7
#define GPIO_PIN_Key_8          GPIO_PIN_0
#define GPIO_PIN_Key_9          GPIO_PIN_1
#define GPIO_PIN_Key_10         GPIO_PIN_3

#define ReadInput_KEY_2         GPIO_ReadInputPin(GPIO_Key_2, GPIO_PIN_Key_2)
#define ReadInput_KEY_3         GPIO_ReadInputPin(GPIO_Key_3, GPIO_PIN_Key_3)
#define ReadInput_KEY_4         GPIO_ReadInputPin(GPIO_Key_4, GPIO_PIN_Key_4)
#define ReadInput_KEY_PTT       GPIO_ReadInputPin(GPIO_Key_PTT, GPIO_PIN_Key_PTT)

/******************************************************************************
;--------6-��ʾ������-HTG12832 hardware macro define
******************************************************************************/
/*LCDӲ������
���?         -508����    -518T����         
LCD DATA      -PB0         -PA6(SDI)
LCD CLK       -PE6         -PA7(SCK)      
LCD SYNC      -PE7         -PC7(RS)
LCD RST       -PC2         -PB14
LCD CS        -PC3         -PA8
LCD Backlight -PC4         -A0
*/
#define GPIO_LCD_DATA           GPIOB
#define GPIO_LCD_SYNC           GPIOE
#define GPIO_LCD_CLK            GPIOE
#define GPIO_LCD_RST            GPIOC
#define GPIO_LCD_CS             GPIOC
#define GPIO_LCD_Backlight      GPIOC

#define GPIO_PIN_LCD_DATA       GPIO_PIN_0
#define GPIO_PIN_LCD_SYNC       GPIO_PIN_7
#define GPIO_PIN_LCD_CLK        GPIO_PIN_6
#define GPIO_PIN_LCD_RST        GPIO_PIN_2
#define GPIO_PIN_LCD_CS         GPIO_PIN_3
#define GPIO_PIN_LCD_Backlight  GPIO_PIN_4


#define MCU_LCD_RS(a)           if(a)\
                                GPIO_WriteHigh(GPIO_LCD_SYNC, GPIO_PIN_LCD_SYNC);\
                                else\
                                GPIO_WriteLow(GPIO_LCD_SYNC, GPIO_PIN_LCD_SYNC)
#define MCU_LCD_SDI(a)          if(a)\
                                GPIO_WriteHigh(GPIO_LCD_DATA, GPIO_PIN_LCD_DATA);\
                                else\
                                GPIO_WriteLow(GPIO_LCD_DATA, GPIO_PIN_LCD_DATA)										   
#define MCU_LCD_SCK(a)          if(a)\
                                GPIO_WriteHigh(GPIO_LCD_CLK, GPIO_PIN_LCD_CLK);\
                                else\
                                GPIO_WriteLow(GPIO_LCD_CLK, GPIO_PIN_LCD_CLK)	
#define MCU_LCD_RESET(a)        if(a)\
                                GPIO_WriteHigh(GPIO_LCD_RST, GPIO_PIN_LCD_RST);\
                                else\
                                GPIO_WriteLow(GPIO_LCD_RST, GPIO_PIN_LCD_RST)
#define MCU_LCD_CS(a)           if(a)\
                                GPIO_WriteHigh(GPIO_LCD_CS, GPIO_PIN_LCD_CS);\
                                else\
                                GPIO_WriteLow(GPIO_LCD_CS, GPIO_PIN_LCD_CS)
#define MCU_LCD_BACKLIGTH(a)    if(a)\
                                GPIO_WriteHigh(GPIO_LCD_Backlight, GPIO_PIN_LCD_Backlight);\
                                else\
                                GPIO_WriteLow(GPIO_LCD_Backlight, GPIO_PIN_LCD_Backlight)

#define GPIO_GT20_CLK           GPIOD
#define GPIO_GT20_CS            GPIOE
#define GPIO_GT20_SI            GPIOE
#define GPIO_GT20_SO            GPIOE

#define GPIO_PIN_GT20_CLK       GPIO_PIN_0
#define GPIO_PIN_GT20_CS        GPIO_PIN_0
#define GPIO_PIN_GT20_SI        GPIO_PIN_1
#define GPIO_PIN_GT20_SO        GPIO_PIN_2                      
                                

#define MCU_GT20_CS(a)	        if(a)\
                                GPIO_WriteHigh(GPIO_GT20_CS, GPIO_PIN_GT20_CS);\
                                else\
                                GPIO_WriteLow(GPIO_GT20_CS, GPIO_PIN_GT20_CS)
#define MCU_GT20_CLK(a)         if(a)\
                                GPIO_WriteHigh(GPIO_GT20_CLK, GPIO_PIN_GT20_CLK);\
                                else\
                                GPIO_WriteLow(GPIO_GT20_CLK, GPIO_PIN_GT20_CLK)										   
#define MCU_GT20_SO(a)          if(a)\
                                GPIO_WriteHigh(GPIO_GT20_SO, GPIO_PIN_GT20_SO);\
                                else\
                                GPIO_WriteLow(GPIO_GT20_SO, GPIO_PIN_GT20_SO)	
#define MCU_GT20_SI(a)          if(a)\
                                GPIO_WriteHigh(GPIO_GT20_SI, GPIO_PIN_GT20_SI);\
                                else\
                                GPIO_WriteLow(GPIO_GT20_SI, GPIO_PIN_GT20_SI)

#define MCU_GT20_SO_Read        GPIO_ReadInputPin(GPIO_GT20_SO, GPIO_PIN_GT20_SO)


/******************************************************************************
;--------7-Beep hardware macro define
******************************************************************************/
#define GPIO_BEEP               GPIOC
#define GPIO_PIN_BEEP           GPIO_PIN_1
/******************************************************************************
;--------8-BATTRY VEDT hardware macro define
******************************************************************************/
#define GPIO_VDET               GPIOB//AIN2
#define GPIO_PIN_VDET           GPIO_PIN_2

/******************************************************************************
;--------1-LED hardware macro define
******************************************************************************/
void LED_Init(void);
void Set_GreenLed(IO_ONOFF state);
void Set_RedLed(IO_ONOFF state);
void set_power_off(IO_ONOFF state);
/******************************************************************************
;--------2-TIM3:DELAY hardware macro define
******************************************************************************/
void Tim3_Timer_Init(void);
/*void TimingDelay_Decrement(void);
void Delay_ms(u16 nms);*/

/******************************************************************************
;--------4-Audio&MIC hardware macro define
******************************************************************************/
void MIC_GPIO_Init(void);
void AF_Mute_Init(void);
void Noise_Mute_Init(void);

void C_TEST_OUT_SET(void);

void MIC_IOMUT(IO_ONOFF OnOff);
void AUDIO_IOAFMUT(IO_ONOFF OnOff);
void AUDIO_IOAFPOW(IO_ONOFF OnOff);

/******************************************************************************
;--------5-KEY hardware macro define
******************************************************************************/
void Key_Init(void);

#endif