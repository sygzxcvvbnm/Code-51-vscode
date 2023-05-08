#include <intrins.h>

/**
 * @brief 单片机主核心延时函数
 * 
 * @param i 毫秒级，1000ms=1s
 */
void delay(unsigned int i)		//@11.0592MHz
{
    int j = 0;
    for (j = 0; j <= i; j++){
        unsigned char i, j;
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}