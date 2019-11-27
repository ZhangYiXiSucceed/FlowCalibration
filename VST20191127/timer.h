#ifndef  __TIMER_H__
#define  __TIMER_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <termios.h>

#include "ReadConfig.h"

#define T 5
#define longtitude   3001234567
#define latitude     501234567


void TimerFunc();
void handler();
u16 CalCRC(u8* buffer, u16 Length);
void PrintCurrentTime();
u8 CheckSum(u8 *buf,u16 len);
u8 IsFrameHead(u8 *buf);
void PrintProtocolData(u8 *buf,u16 len);

void VST_To_CCU_RouteData();
void CCU_To_VST_TimeData();
void CCU_To_VST_HeartData();
void CCU_To_VST_VehicleRunningData();
void CCU_To_VST_VehicleErrorData();
void CCU_To_VST_IntersectionData();

#endif

