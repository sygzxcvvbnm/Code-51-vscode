#ifndef _IIC_H
#define _IIC_H
#include <atmel/REGX52.H>


#define  u8 unsigned char
#define  u32 unsigned int
        
sbit SCL=P1^0;//时钟 D0（SCLK?
sbit SDIN=P1^1;//D1（MOSI） 数据
        
#define SCLK_Clr() SCL=0
#define SCLK_Set() SCL=1

#define SDIN_Clr() SDIN=0
#define SDIN_Set() SDIN=1


void IIC_Start();
void IIC_Stop();
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);
void IIC_Wait_Ack();



#endif

