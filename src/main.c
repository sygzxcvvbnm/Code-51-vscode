#include <atmel/REGX52.H>
#include <intrins.h>
#include "delay_ms_11.0592.h"
#include "Nixie8.h"
#include "LCD1602.h"
#include "MatrixKey_P1.h"
#include "Timer0.h"
#include "OLED.h"
#include "iic.h"

#define uint unsigned int
#define uchar unsigned char

uchar KeyNum;
    uint s;
    uint m;
    uint h;
    uint d;
uint l;

void main(){
    Timer0_Init();
    OLED_Init();
    OLED_Clear();
    while(1){
        
        OLED_ShowCHinese(0,0,0);//
        OLED_ShowCHinese(16,0,1);//
        OLED_ShowCHinese(16*2,0,2);//
        OLED_ShowCHinese(16*3,0,3);//
        OLED_ShowCHinese(16*4,0,4);//
        OLED_ShowCHinese(16*5,0,5);//
        OLED_ShowCHinese(16*0,2,6);//
        OLED_ShowCHinese(16*2,2,7);//
        OLED_ShowCHinese(16*4,2,8);//
        OLED_ShowCHinese(16*6,2,9);//
        OLED_ShowString(16*6,0,":",16);
        OLED_ShowString(16*1,4,":",16);
        OLED_ShowString(16*3,4,":",16);
        OLED_ShowString(16*5,4,":",16);
        OLED_ShowNum(16*0,4,00,2,16);
        OLED_ShowNum(16*2,4,00,2,16);
        OLED_ShowNum(16*4,4,00,2,16);
        OLED_ShowNum(16*6,4,00,2,16);

        for ( d = 1; d < 30; d++){       
            for ( h = 1; h < 24; h++){
                for ( m = 1; m < 60; m++){
                    for ( s = 0; s < 60;){
                        OLED_ShowNum(16*6,4,s,2,16); 
                    } 
                    OLED_ShowNum(16*4,4,m,2,16); 
                }      
                OLED_ShowNum(16*2,4,h,2,16); 
            }  
            OLED_ShowNum(16*0,4,d,2,16);             
        }
    }
}    

void Timer1_Routine() interrupt 1{
    static uint T0Count = 0;
    TL0 = 0xCD;				//设置定时初始值
	TH0 = 0xD4;				//设置定时初始值
    T0Count++;
    if (T0Count >=660)
    {
        s++;
        T0Count = 0;
    }    
}