#ifndef _NET_H__
#define _NET_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#include <fcntl.h>
#include <syslog.h>
#include <termios.h>
#include <time.h>
#include <sys/stat.h>   //获取一些文件相关的信息
#include <errno.h>      //错误号定义

#include "ReadConfig.h"
#include "Mythread.h"
#include "Queue.h"
#include "timer.h"

#define MaxLength   200
#define PORT        20041
#define BACKLOG     10
#define MAXDATASIZE  2048

#define LimitNum  20
#define File_DIR   "/home/vst_software/VST20191119/"


extern int ByteNum_VST;
extern int Sockfd_VST;
extern unsigned char SendBuff_VST[MaxLength];
extern unsigned char RecBuff_VST[MaxLength];

extern int ByteNum_Platform;
extern int Sockfd_Platform;
extern char SendBuff_Platform[MaxLength];
extern char RecBuff_Platform[MaxLength];

extern pthread_mutex_t CCURec_mutex_t;   // 编译时初始化锁位解锁状态
extern pthread_mutex_t CCUSend_mutex_t;
extern pthread_mutex_t CCUProcess_mutex_t;

extern pthread_mutex_t PlatformRec_mutex_t;
extern pthread_mutex_t PlatformSend_mutex_t;
extern pthread_mutex_t PlatformProcess_mutex_t;

typedef struct Arg{
	int arg;
	int listenfd;
	int connfd;
}Argument;
Argument  ArgVST1;

extern Argument  ArgVST1;

void *pthread_NetRecFun_CCU(void *arg);
void *pthread_NetSendFun_CCU(void *arg);

void *pthread_NetRecFun_Platform(void *arg);
void *pthread_NetSendFun_Platform(void *arg);
void *pthread_NetProcessFun_Platform(void *arg);

int ServerConnectSocket();
int ServerAcceptClient(int *listenfd);

void *PthreadNetRec_CCU(Argument*);
void *PthreadNetSend_CCU(Argument *Arg);
void *PthreadNetProcess_CCU(Argument *Arg);

void PacketData(Item *Temp,u8 buf[],u8 Sendbuff[],u16 Length);
#endif

