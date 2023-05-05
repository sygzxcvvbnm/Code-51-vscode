#include <atmel/REGX52.H>
#define uint unsigned int
sfr AUXR=0X8E;    //NOTES:sbit是位操作，用于将某个sfr中具体位赋值给一个变量

void Timer0_Init()		//1毫秒@11.0592MHz
{
	AUXR |= 0x80;			//定时器时钟1T模式
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0xCD;				//设置定时初始值
	TH0 = 0xD4;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
    ET0 = 1;
    EA = 1;
    PT0 = 0; 
}

//main函数示例：

// void Timer1_Routine() interrupt 1{
//     static uint T0Count = 0;
//     TL0 = 0xCD;				//设置定时初始值
// 	TH0 = 0xD4;				//设置定时初始值
//     T0Count++;
//     if (T0Count >=100)
//     {
//         T0Count = 0;
//     }    
// }