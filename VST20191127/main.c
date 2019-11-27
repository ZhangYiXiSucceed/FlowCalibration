/*********************************************************************
Project:808 VST项目，作为CCU的服务器，作为平台端的客户端。


工程说明:
      1.6个线程搭建完毕，对CCU为服务器程序，对监控平台为客户端程序， 191023
      2.测试网络中断后，对平台段仍然可以连接上继续通信，CCU重新连接后也可以继续通信  191023
      3.队列搭建4个，分别为CCU读写和平台端读写队列   191023
      4.发送什么数据返回什么数据，测试响应时间，关键信息加上时间，（100ms基本保持可以，50ms可能会连包）191024
      5.定义协议结构体，实现一个协议。191028
      6.实现重发机制，发送数据之后，如果未响应，则重新发送三次，三次之后还未响应，则丢弃该包数据。191028
      7.实现队列访问互锁。191031
      8.CCU的协议实现。 191104
      9.实现重发三次再扔掉当前数据，而不是重发一次回到队尾。191105
      10.修正校验、多次接收数据错误和多次接收不同数据校验错误的bug.191105
      11.服务器打开的不是指定的端口原因是，客户端还处于连接中，服务器就关了，导致端口占用，第二次开的时候，端口被随机分配成其他。191105
      12.修改了函数的命名VST，改成CCU。191105
      13.平台端服务器未开，但是VST客户端却连接成功，原因可能是发送和接收同时连接的原因，暂时减少了频次，通过发送来确认接收成功
**********************************************************************/

#include "Mythread.h"
#include "Net.h"
#include "Queue.h"
#include "ReadConfig.h"
#include "timer.h"
int main()
{
	int connfd;
	int ArgPlatformRec=1;
	int ArgPlatformSend=1;
	int ArgPlatformProcess=1;
	int temp;

	int listenfd = ServerConnectSocket();
    ArgVST1.listenfd=listenfd;

    TempRecQueue = InitQueue();           //CCU接收队列
    TempSendQueue = InitQueue();          //CCU发送队列
    TempProcessQueue = InitQueue();       //CCU处理队列

    TempPlatformRecQueue = InitQueue();      //平台接收队列
    TempPlatformSendQueue = InitQueue();     //平台发送队列
    TempPlatformProcessQueue = InitQueue();  //平台处理队列

    PrintCurrentTime();

    temp = MyThreadStart(pthread_NetRecFun_Platform,&PlatformRec_Id,&ArgPlatformRec);
	if(temp == 0)
	{
	   printf("PlatformRecfun threadFunc successfully!\n");
	}
	temp = MyThreadStart(pthread_NetSendFun_Platform,&PlatformSend_Id,&ArgPlatformSend);
	if(temp == 0)
	{
	   printf("PlatformSendfun threadFunc successfully!\n");
	}
	temp = MyThreadStart(pthread_NetProcessFun_Platform,&PlatformProcess_Id,&ArgPlatformProcess);
	if(temp == 0)
	{
	   printf("PlatformProcessfun threadFunc successfully!\n");
	}
	TimerFunc();
	while(1)
	{
		connfd = ServerAcceptClient(&listenfd);   //等待客户端连接，连接之后，开启三个线程收发解析，进行数据交互
		(ArgVST1.connfd)=connfd;
		ArgVST1.arg=1;
		printf("connfd=%d\n",connfd);
		temp = MyThreadStart(PthreadNetRec_CCU,&VST1Rec_Id,&ArgVST1);
		if(temp == 0)
		{
		   printf("CCURecfun threadFunc successfully!\n");
		}
		temp = MyThreadStart(PthreadNetSend_CCU,&VST1Send_Id,&ArgVST1);
		if(temp == 0)
		{
		   printf("CCUSendfun threadFunc successfully!\n");
		}
		temp = MyThreadStart(PthreadNetProcess_CCU,&VST1Process_Id,&ArgVST1);
		if(temp == 0)
		{
		   printf("CCUProcessfun threadFunc successfully!\n");
		}
	}
	close(connfd);
	close(listenfd);
	return 0;
}
