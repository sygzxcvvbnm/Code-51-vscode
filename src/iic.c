#include "iic.h"
#include <atmel/REGX52.H>

void IIC_Start()
{

        SCLK_Set() ;
        SDIN_Set();
        SDIN_Clr();
        SCLK_Clr();
}

void IIC_Stop()
{
        SCLK_Set() ;
//        SCLK_Clr();
        SDIN_Clr();
        SDIN_Set();
        
}

void IIC_Wait_Ack()
{
        SCLK_Set() ;
        SCLK_Clr();
}

void Write_IIC_Byte(unsigned char IIC_Byte)
{
        unsigned char i;
        unsigned char m,da;
        da=IIC_Byte;
        SCLK_Clr();
        for(i=0;i<8;i++)               
        {
                m=da;
                //        SCLK_Clr();
                m=m&0x80;
                if(m==0x80)
                {SDIN_Set();}
                else SDIN_Clr();
                        da=da<<1;
                SCLK_Set();
                SCLK_Clr();
                }
}

void Write_IIC_Command(unsigned char IIC_Command)
{
   IIC_Start();
   Write_IIC_Byte(0x78);            //Slave address,SA0=0
        IIC_Wait_Ack();        
   Write_IIC_Byte(0x00);                        //write command
        IIC_Wait_Ack();        
   Write_IIC_Byte(IIC_Command);
        IIC_Wait_Ack();        
   IIC_Stop();
}

void Write_IIC_Data(unsigned char IIC_Data)
{
   IIC_Start();
   Write_IIC_Byte(0x78);                        //D/C#=0; R/W#=0
        IIC_Wait_Ack();        
   Write_IIC_Byte(0x40);                        //write data
        IIC_Wait_Ack();        
   Write_IIC_Byte(IIC_Data);
        IIC_Wait_Ack();        
   IIC_Stop();
}
