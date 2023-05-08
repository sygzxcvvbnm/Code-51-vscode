#ifndef _OLED_H_
#define _OLED_H_
#include <atmel/REGX52.H>

#define u8             unsigned char    // 8位字符
#define u32            unsigned int     // 32位字符

#define OLED_CMD       0 // 写命令
#define OLED_DATA      1 // 写数据
#define OLED_MODE      0

#define OLED_CS_Clr()  OLED_CS = 0
#define OLED_CS_Set()  OLED_CS = 1

#define OLED_RST_Clr() OLED_RST = 0
#define OLED_RST_Set() OLED_RST = 1

#define OLED_DC_Clr()  OLED_DC = 0
#define OLED_DC_Set()  OLED_DC = 1

// OLED模式设置
// 0:4线串行模式
// 1:并行8080模式

#define SIZE       16
#define XLevelL    0x02
#define XLevelH    0x10
#define Max_Column 128
#define Max_Row    64
#define Brightness 0xFF
#define X_WIDTH    128
#define Y_WIDTH    64

void delay_ms(unsigned int ms);

// OLED控制用函数
void OLED_WR_Byte(unsigned dat, unsigned cmd);
// OLED显示屏开
void OLED_Display_On(void);
// OLED显示屏关
void OLED_Display_Off(void);
// OLED清屏
void OLED_Clear(void);
// void OLED_DrawPoint(u8 x,u8 y,u8 t);
// void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);

// OLED显示字符
void OLED_ShowChar(u8 x, u8 y, u8 chr, u8 Char_Size);
// OLED显示数字
void OLED_ShowNum(u8 x, u8 y, u32 num, u8 len, u8 size);
// OLED显示字符串
void OLED_ShowString(u8 x, u8 y, u8 *p, u8 Char_Size);
void OLED_Set_Pos(unsigned char x, unsigned char y);
// OLED显示中文字符
void OLED_ShowCHinese(u8 x, u8 y, u8 no);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
// OLED显示图片
void oled_showpictues(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[]);
// void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
// void Delay_50ms(unsigned int Del_50ms);
// void Delay_1ms(unsigned int Del_1ms);
// void fill_picture(unsigned char fill_Data);
// void Picture();

// OLED屏幕初始化
void OLED_Init(void);

#endif
