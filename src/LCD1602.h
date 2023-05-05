#ifndef __LCD1602_H__
#define __LCD1602_H__

#define uint unsigned int
#define uchar unsigned char
//用户调用函数：
  //Line   起始行位置，范围：1~2
  //Column 起始列位置，范围：1~16

//LCD1602初始化函数
void LCD_Init();
//在LCD1602指定位置上显示一个字符
  //Char   要显示的字符
void LCD_ShowChar(uchar Line,uchar Column,char Char);
//在LCD1602指定位置开始显示所给字符串
  //String 要显示的字符串
void LCD_ShowString(uchar Line,uchar Column,char *String);
//在LCD1602指定位置开始显示所给数字
  //Number 要显示的数字，范围：0~65535
  //Length 要显示数字的长度，范围：1~5
void LCD_ShowNum(uchar Line,uchar Column,unsigned int Number,uchar Length);
//在LCD1602指定位置开始以有符号十进制显示所给数字
  //Number 要显示的数字，范围：-32768~32767
  //Length 要显示数字的长度，范围：1~5
void LCD_ShowSignedNum(uchar Line,uchar Column,int Number,uchar Length);
//在LCD1602指定位置开始以十六进制显示所给数字
  //Number 要显示的数字，范围：0~0xFFFF
  //Length 要显示数字的长度，范围：1~4
void LCD_ShowHexNum(uchar Line,uchar Column,unsigned int Number,uchar Length);
//在LCD1602指定位置开始以二进制显示所给数字
  //Number 要显示的数字，范围：0~1111 1111 1111 1111
  //Length 要显示数字的长度，范围：1~16
void LCD_ShowBinNum(uchar Line,uchar Column,unsigned int Number,uchar Length);

#endif
