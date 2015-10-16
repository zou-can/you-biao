/**********************用户函数文件*********************************
*  晶振:11.0592MHZ
*  定时器1 外部中断0 编码器
******************************************************************/

/**********************包含文件*******************/
#include "head.h"
/*********************************全局变初始化***********************************/
uchar speed = 0;            
uchar mcs = 0;          
uint Data_Show = 0;  
uint user_count = 0;
uint user_time = 0;
//uint pwm_count = 0;
/******************************************************************************/
/* 函数名称  : USER_Timer_Init                                                */
/* 函数描述  : 用户定时器初始化                                               */
/* 输入参数  : void                                                           */
/* 参数描述  : 无                                                             */
/* 返回值    : 无                                                             */
/******************************************************************************/	
void USER_Timer_Init(void)
{
	EA = 0;
	PT1 = 1;       
	PX0 = 0; //外部优先级降低
	TMOD &= 0X0F;//清掉定时器1
	TMOD |= 0x10;//设置定时器1
	//IE = 0x89;			
  TH1 = 0x4c;			
	TL1 = 0x00;	
  ET1 = 1;				
	TR1 = 1;			
	
	IT0 = 1;	//下降沿触发  问题之最			
	EX0 = 1;			
	//EA = 1;					
}


/******************************************************************************/
/* 函数名称  : USER_T1_time                                                   */
/* 函数描述  : 编码器定时器                                                   */
/* 输入参数  : void                                                           */
/* 参数描述  : 无                                                             */
/* 返回值    : 无                                                             */
/******************************************************************************/	
void USER_T1_time(void) interrupt 3
{
	TR1 = 0;
	TH1 = 0x4c;  
	TL1 = 0x00;
	user_count++;
	//pwm_count++;
	if(user_count >= 20)//1s
	{
		EX0 = 0;
		user_count = 0;
		user_time++;
		Data_Show = mcs*2.502;   //编码器算法
		mcs = 0;
		//if(user_time % 10 == 0)//10s累加一次
		if(user_time % 10 == 0)
			trip_data += (mps_data / 360); //里程累加
		EX0 = 1;
	}
	TR1 = 1;
}

/******************************************************************************/
/* 函数名称  : USER_Ex_INT0                                                   */
/* 函数描述  : 编码器外部中断                                                 */
/* 输入参数  : void                                                           */
/* 参数描述  : 无                                                             */
/* 返回值    : 无                                                             */
/******************************************************************************/	
void Ex_INT0() interrupt 0
{
	mcs++;
}