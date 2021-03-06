/**********************键盘头文件*********************************
* 晶振:12MHZ  晶振不能代替
* 一路定时器一个PWM波，52仿
* 不用的请在宏定义里面注释  这是关键
* PWM_Port0 = P1^2; //输出端口
* PWM_Port1 = P2^2; //输出端口
******************************************************************/
#ifndef __PWM
#define __PWM 1
/**********************包含文件**********************************************/
#include "HEAD.h"
/************************************宏定义************************************/
#define PWM_0 1  //PWM输出定时器0口 不用请注释
//#define PWM_1 1  //PWM输出定时器1口 不用请注释
/************************************位定义************************************/
sbit PWM_Port0 = P3^7; //输出端口
//sbit PWM_Port1 = P2^2; //输出端口
/*********************************全局变初始化***********************************/

#ifdef PWM_0
extern uint pwm_set_0;  //0号PWM波占空比  范围小于周期 0-65536（10000为1ms)
extern uint pwm_cycle_0;//0号PWM波周期    范围 0-65536（10000为1ms)
#endif

#ifdef PWM_1
extern uint pwm_set_1;  //0号PWM波占空比  范围小于周期 0-65536（10000为1ms)
extern uint pwm_cycle_1;//1号PWM波周期    范围 0-65536（10000为1ms)
#endif

/**********************************函数定义***********************************/
#ifdef PWM_0
void PWM_Init_0(void);//定时器0初始化
#endif

#ifdef PWM_1
void PWM_Init_1(void);//定时器1初始化
#endif

#endif