#include<reg51.h>
#include "Delay.h"
#include "LCD1602.h"
sbit SW1=P1^0;//锯齿
sbit SW2=P1^1;//三角
sbit SW3=P1^2;//正弦
sbit SW4=P1^3;//方波

sbit begin=P1^4;
unsigned int t1=2000,t2=2000,t3=2000,t4=2000;
unsigned char Result=0;
unsigned int m=0;

void delay_tt(unsigned char t)
{   
    m=t/1000; 
    while(m>0)
    {
        LCD_ShowNum(1,1,m,1);
        m--;
        Delay(1000);
    }
}

void main()
{
	TMOD=0x20;
	TL1=0xF4; 
	TH1=0xF4;
	PCON=0x00; 
	SCON=0x50; 
	TR1=1;
	LCD_Init();
	Delay(10);

	while(1)  
	{   
		if(begin==0) 
		{
			if(SW1==0)
			{Delay(20);t1=t1+1000;}
			if(SW2==0)
			{Delay(20);t2=t2+1000;}
			if(SW3==0)
			{Delay(20);t3=t3+1000;}
			if(SW4==0)
			{Delay(20);t4=t4+1000;}
		}
		else
		{		
			SBUF=1; 
			do{LCD_ShowString(2,1,"SAW");
				while(t1>0)
				{
					LCD_ShowNum(1,1,t1,4);
					t1=t1-1000;
					Delay(1000);
				}
			}while(!TI);
			TI=0;
			
			SBUF=2; 
			do{LCD_ShowString(2,1,"TRI");
				while(t2>0)
				{
					LCD_ShowNum(1,1,t2,4);
					t2=t2-1000;
					Delay(1000);
				}
			}while(!TI);
			TI=0;
			
			SBUF=3; 
			do{LCD_ShowString(2,1,"SIN");
				while(t3>0)
				{
					LCD_ShowNum(1,1,t3,4);
					t3=t3-1000;
					Delay(1000);
				}
			}while(!TI);
			TI=0;
			
			SBUF=4; 
			do{LCD_ShowString(2,1,"SQU");
				while(t4>0)
				{
					LCD_ShowNum(1,1,t4,4);
					t4=t4-1000;
					Delay(1000);
				}
			}while(!TI);
			TI=0;
			break;
		}
	}
}