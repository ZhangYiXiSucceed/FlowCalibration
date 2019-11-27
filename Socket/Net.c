#include "Net.h"


int Sockfd_CCU = -1;          //CCUSocket句柄
int Sockfd_Platform = -1;     //平台端Socket句柄

u8 IsSocketPlatform=0;        //平台端网络是否连接标志位
u8 IsSocketCCU=0;                //CCU端网络是否连接标志位

unsigned char SendBuff_CCU[MaxLength];     //CCU收发数据数组
unsigned char RecBuff_CCU[MaxLength];

char SendBuff_Platform[MaxLength];
char RecBuff_Platform[MaxLength];

int ByteNum_CCU=0;
int ByteNum_Platform=0;

pthread_mutex_t CCURec_mutex_t = PTHREAD_MUTEX_INITIALIZER;   // 编译时初始化锁位解锁状态
pthread_mutex_t CCUSend_mutex_t = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t CCUProcess_mutex_t = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t PlatformRec_mutex_t = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t PlatformSend_mutex_t = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t PlatformProcess_mutex_t = PTHREAD_MUTEX_INITIALIZER;

void *pthread_NetRecFun_CCU(void *arg)
{
	char ServerIP[50];
	char Port[50];
	while(*(int*)arg)
	{
		if(Sockfd_CCU==-1)
		{
			ConfigGetKey("src\\NetConfig.dat", "net:server", "ServerIP", ServerIP);
			ConfigGetKey("src\\NetConfig.dat", "net:server", "ServerPort", Port);

			printf("%s---",ServerIP);
			printf("%s\n",Port);

//			strcpy(ServerIP,"47.100.170.9");
//			strcpy(Port,"6888");
			//char *ServerIP = "192.168.0.100";
			int ServerPort = atoi(Port);

			struct sockaddr_in ServerAddr;
			struct hostent *Host;

			Host = gethostbyname(ServerIP);


			Sockfd_CCU = socket(AF_INET,SOCK_STREAM,0);    //建立Socket通信链路

			if(Sockfd_CCU == -1)
			{
				printf("SocketRec_VST established failed!\n");
				sleep(2);
				continue;
			}
			bzero(&ServerAddr,sizeof(ServerAddr));
			ServerAddr.sin_family = AF_INET;
			ServerAddr.sin_port = htons(ServerPort);
			ServerAddr.sin_addr= *((struct in_addr *)malloc(sizeof(Host->h_addr)));
			ServerAddr.sin_addr= *((struct in_addr *)Host->h_addr);

			if(connect(Sockfd_CCU,(struct sockaddr*)&ServerAddr,sizeof(struct sockaddr))==-1)
			{
				close(Sockfd_CCU);
				Sockfd_CCU=-1;
				printf("SocketRec_VST connected failed!\n");
				sleep(5);
				continue;
			}
		}

		printf("connect Successfully*******Sockfd_VST=%d\n",Sockfd_CCU);
		fd_set rfds_Socket;
		FD_ZERO(&rfds_Socket);
		FD_SET(Sockfd_CCU, &rfds_Socket);
		int retval=select(Sockfd_CCU + 1, &rfds_Socket, NULL, NULL, NULL);
									 //tv控制选择的时间，若规定时间内没有收到数据
									 //则不监控该rfds。则若为NULL，一直等到接收到数据
									 //再继续程序执行。
		printf("retval=%d--rfds_Socket=%d*****Sockfd_CCU=%d\n",retval,rfds_Socket,Sockfd_CCU);
		if(retval==0)
		{
			printf("select error\n");
			continue;
		}
		while(Sockfd_CCU!=-1)
		{
			if(FD_ISSET(Sockfd_CCU, &rfds_Socket)) //接收到数据了
			{
				//bzero(RecBuff_VST, MaxLength);
				int  len = recv(Sockfd_CCU, RecBuff_CCU, MaxLength, 0);
				if(len<=0)
				{
					close(Sockfd_CCU);
					Sockfd_CCU=-1;
					break;
				}
				//sprintf(SendBuff_VST,"%s",RecBuff_VST);
				printf("%d***%s\n",len,RecBuff_CCU);
				//ByteNum_VST=len;

//				time_t Sec = (RecBuff_VST[17]<<24)|(RecBuff_VST[16]<<16)|(RecBuff_VST[15]<<8)|RecBuff_VST[14];
//				struct tm *pt;
//			    pt=gmtime(&Sec);
//
//                char s[100];
//                strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", pt);
//                printf("Time= %x: %s\r\n", (int)Sec, s);

				memcpy(SendBuff_Platform,RecBuff_CCU,len);
				ByteNum_Platform=len;
//				close(Sockfd);
//				Sockfd=-1;
			}
			else
			{
				printf("dont recieve data\n");
				sleep(1);
			}
		 }
	 }
}



void *pthread_NetSendFun_CCU(void *arg)
{
	char ServerIP[50];
	char Port[50];
	while(*(int*)arg)
	{
		if(Sockfd_CCU==-1)
		{

			signal(SIGPIPE, SIG_IGN);   //忽略收到退出进程信号

			ConfigGetKey("NetConfig.dat", "net:server", "ServerIP", ServerIP);
			ConfigGetKey("NetConfig.dat", "net:server", "ServerPort", Port);

			printf("%s---",ServerIP);
			printf("%s\n",Port);

			strcpy(ServerIP,"47.100.170.9");
			strcpy(Port,"6888");
			//char *ServerIP = "192.168.0.100";
			int ServerPort = atoi(Port);

			struct sockaddr_in ServerAddr;
			struct hostent *Host;

			Host = gethostbyname(ServerIP);

			Sockfd_CCU = socket(AF_INET,SOCK_STREAM,0);
			if(Sockfd_CCU == -1)
			{
				printf("SocketSend_VST established failed!\n");
				sleep(2);
				continue;
			}
			bzero(&ServerAddr,sizeof(ServerAddr));
			ServerAddr.sin_family = AF_INET;
			ServerAddr.sin_port = htons(ServerPort);
			ServerAddr.sin_addr= *((struct in_addr *)malloc(sizeof(Host->h_addr)));
			ServerAddr.sin_addr= *((struct in_addr *)Host->h_addr);

			if(connect(Sockfd_CCU,(struct sockaddr*)&ServerAddr,sizeof(struct sockaddr))==-1)
			{
				close(Sockfd_CCU);
				Sockfd_CCU=-1;
				printf("SocketSend_VST connected failed!\n");
				sleep(15);
				continue;
			}

		}
		if(ByteNum_CCU>0)
		{
			signal(SIGPIPE, SIG_IGN);   //忽略收到退出进程信号

			int len = send(Sockfd_CCU,RecBuff_CCU,ByteNum_CCU,0);
			printf("len=%d---",len);
			if(len==-1)
			{
				printf("Failed to Send Message!\n");
				close(Sockfd_CCU);
				Sockfd_CCU=-1;
                continue;
			}
			printf("NET_VST:%s--%d---%d\n",RecBuff_CCU,ByteNum_CCU,strlen(RecBuff_CCU));
			memset(SendBuff_CCU,0x00,sizeof(SendBuff_CCU));
			ByteNum_CCU=0;
			bzero(RecBuff_CCU, MaxLength);
		}
	}
}

void *pthread_NetRecFun_Platform(void *arg)
{
	char ServerIP[50];
	char Port[50];

    ConfigGetKey(File_DIR"NetConfig.dat", "net:Local", "LocalIP", ServerIP);
    ConfigGetKey(File_DIR"NetConfig.dat", "net:Local", "LocalPort", Port);

    printf("%s---",ServerIP);
    printf("%s\n",Port);

	while(*(int*)arg)
	{
		if(Sockfd_Platform==-1)
		{
//			strcpy(ServerIP,"192.168.0.100");
//			strcpy(Port,"6321");
			//char *ServerIP = "192.168.0.100";
			int ServerPort = atoi(Port);

			struct sockaddr_in ServerAddr;
			struct hostent *Host;

			Host = gethostbyname(ServerIP);

			Sockfd_Platform = socket(AF_INET,SOCK_STREAM,0);    //建立Socket通信链路

			if(Sockfd_Platform == -1)
			{
				printf("Socket established failed!\n");
				sleep(2);
				continue;
			}
			bzero(&ServerAddr,sizeof(ServerAddr));
			ServerAddr.sin_family = AF_INET;
			ServerAddr.sin_port = htons(ServerPort);
			ServerAddr.sin_addr= *((struct in_addr *)malloc(sizeof(Host->h_addr)));
			ServerAddr.sin_addr = *((struct in_addr *)Host->h_addr);

			if(connect(Sockfd_Platform,(struct sockaddr*)&ServerAddr,sizeof(struct sockaddr))==-1)
			{
				close(Sockfd_Platform);
				Sockfd_Platform=-1;
				IsSocketPlatform=0;
				printf("SocketRec_Platform connected failed!\n");
				sleep(6);
				continue;
			}
		}
		printf("connect Successfully*******(Rec)Sockfd_Platform=%d\n",Sockfd_Platform);
		if(IsSocketPlatform==0)
        {
            printf("Enter the Check!\n");
            Sockfd_Platform=-1;
            continue;
        }
		printf("IsSocketPlatform=%d\n",IsSocketPlatform);
        IsSocketPlatform=1;
		fd_set rfds_Socket;
		FD_ZERO(&rfds_Socket);
		FD_SET(Sockfd_Platform, &rfds_Socket);
		int retval=select(Sockfd_Platform + 1, &rfds_Socket, NULL, NULL, NULL);
									 //tv控制选择的时间，若规定时间内没有收到数据
									 //则不监控该rfds。则若为NULL，一直等到接收到数据
									 //再继续程序执行。
		printf("retval=%d--rfds_Socket=%d\n",rfds_Socket);
		if(retval==0)
		{
			printf("select error\n");
			continue;
		}
		while(Sockfd_Platform!=-1)
		{
			if(FD_ISSET(Sockfd_Platform, &rfds_Socket)) //接收到数据了
			{
				bzero(RecBuff_Platform, MaxLength);
				int  len = recv(Sockfd_Platform, RecBuff_Platform, MaxLength, 0);
				if(len<=0)
				{
					close(Sockfd_Platform);
					PrintCurrentTime();
					printf("SocketRec_Platform connected failed!\n");
					Sockfd_Platform=-1;
					break;
				}

				printf("Printf_Platform_Rec:%s***%d\n",RecBuff_Platform,len);

				//防止队列溢出
				if(GetSize(TempPlatformRecQueue)>LimitNum)
				{
					Item TempData;

					pthread_mutex_lock(&PlatformRec_mutex_t);
					DeQueue(TempPlatformRecQueue,&TempData);
					pthread_mutex_unlock(&PlatformRec_mutex_t);

					free(TempData.buff);
				}

				u32 DataIndex=0;
				u32 TempFrameLength=0;
				//printf("%x****%x\n",RecBuff_Platform[37],RecBuff_Platform[38]);
				//printf("%x****%x\n",RecBuff_Platform[37+17],RecBuff_Platform[37+16]);
				while(len-DataIndex)
				{
					///printf("%d\n",DataIndex);
					TempFrameLength=RecBuff_Platform[DataIndex+19]<<24|RecBuff_Platform[DataIndex+18]<<16|RecBuff_Platform[DataIndex+17]<<8|RecBuff_Platform[DataIndex+16];
				//	printf("%x\n",RecBuff_Platform[DataIndex+16]);
				//	printf("%d\n",TempFrameLength);
					TempFrameLength+=FrameLength;
				//	printf("%d\n",TempFrameLength);
					TempFrameLength+=1;
					if(IsFrameHead(&RecBuff_Platform[DataIndex]))
					{
						u8 TempCheck = CheckSum(&RecBuff_Platform[DataIndex],TempFrameLength-1);
						if(TempCheck == RecBuff_Platform[TempFrameLength-1])
						{
							Item RX;

							RX.Times = 3;
							RX.len = TempFrameLength;
							RX.buff = (u8 *)malloc(RX.len);

							memset(RX.buff,0x00,RX.len);

							memcpy(RX.buff,RecBuff_Platform,RX.len);

							pthread_mutex_lock(&PlatformRec_mutex_t);
							EnQueue(TempPlatformRecQueue,RX);
							pthread_mutex_unlock(&PlatformRec_mutex_t);

							DataIndex+=TempFrameLength;
							//DataIndex-=1;
						}
						else
						{
							printf("Checkout is error!\n");
							break;
						}
					}
					else
					{
						printf("FrameHead is error!\n");
						break;
					}
				}
				memset(RecBuff_Platform,0x00,sizeof(RecBuff_Platform));
				//free(RX.buff);
			}
		 }
	 }
}
void *pthread_NetSendFun_Platform(void *arg)
{
	char ServerIP[50];
	char Port[50];
    ConfigGetKey(File_DIR"NetConfig.dat", "net:Local", "LocalIP", ServerIP);
    ConfigGetKey(File_DIR"NetConfig.dat", "net:Local", "LocalPort", Port);

    printf("%s---",ServerIP);
    printf("%s\n",Port);
	while(*(int*)arg)
	{
		if(Sockfd_Platform==-1)
		{
//			strcpy(ServerIP,"192.168.0.100");
//			strcpy(Port,"6321");
			//char *ServerIP = "192.168.0.100";
			int ServerPort = atoi(Port);

			struct sockaddr_in ServerAddr;
			struct hostent *Host;

			Host = gethostbyname(ServerIP);

			Sockfd_Platform = socket(AF_INET,SOCK_STREAM,0);

			if(Sockfd_Platform == -1)
			{
				printf("Socket established failed!\n");
				sleep(2);
				continue;
			}
			bzero(&ServerAddr,sizeof(ServerAddr));
			ServerAddr.sin_family = AF_INET;
			ServerAddr.sin_port = htons(ServerPort);
			ServerAddr.sin_addr= *((struct in_addr *)malloc(sizeof(Host->h_addr)));
			ServerAddr.sin_addr = *((struct in_addr *)Host->h_addr);

			if(connect(Sockfd_Platform,(struct sockaddr*)&ServerAddr,sizeof(struct sockaddr))==-1)
			{
				close(Sockfd_Platform);
				Sockfd_Platform=-1;
				printf("SocketSend_Platform connected failed!\n");
				sleep(5);
				IsSocketPlatform=0;
				continue;
			}
		}
		IsSocketPlatform=1;
		printf("connect Successfully*******(Send)Sockfd_Platform=%d\n",Sockfd_Platform);
		while(Sockfd_Platform!=-1)
		{
			if(!IsEmpty(TempPlatformSendQueue))
			{
				signal(SIGPIPE, SIG_IGN);   //忽略收到退出进程信号,交给系统处理

				Item TX;

				pthread_mutex_lock(&PlatformSend_mutex_t);
				DeQueue(TempPlatformSendQueue,&TX);
				pthread_mutex_unlock(&PlatformSend_mutex_t);

				int len = send(Sockfd_Platform,TX.buff,TX.len,0);
				printf("Printf_Platform_Send:%s***%d\n",TX.buff,len);
				if(len==-1)
				{
					if(TX.Times--)
					{
						pthread_mutex_lock(&PlatformSend_mutex_t);
						EnQueue(TempPlatformSendQueue,TX);
						pthread_mutex_unlock(&PlatformSend_mutex_t);

						printf("TX.Times=%d\n",TX.Times);
					}
					PrintCurrentTime();
					printf("Failed to Send Message!\n");
					close(Sockfd_Platform);
					Sockfd_Platform=-1;
					continue;
				}
				//memset(TX.buff,0x00,sizeof(TX.buff));

				free(TX.buff);
			}
		}
	}
}

void *pthread_NetProcessFun_Platform(void *arg)
{
	while(*(int*)arg)
	{
		if(IsSocketPlatform!=0)
		{
			//printf("Sockfd_Platform=%d\n",Sockfd_Platform);
			if(!IsEmpty(TempPlatformRecQueue))
			{
				//防止队列溢出，保留最新的队列数据。
				if(GetSize(TempPlatformSendQueue)>LimitNum)
				{
					Item TempData;

					pthread_mutex_lock(&PlatformSend_mutex_t);
					DeQueue(TempPlatformSendQueue,&TempData);
					pthread_mutex_unlock(&PlatformSend_mutex_t);

					free(TempData.buff);
				}

				Item TX;

				pthread_mutex_lock(&PlatformRec_mutex_t);
				DeQueue(TempPlatformRecQueue,&TX);
				pthread_mutex_unlock(&PlatformRec_mutex_t);

				///memset(SendBuff_Platform,0x00,sizeof(SendBuff_Platform));
				//strcpy(SendBuff_Platform,TX.buff);

				//printf("%s\n",TX.buff);

				u16 TempCommand=TX.buff[11]<<8|TX.buff[10];
				//printf("%X\n",TempCommand);
				switch(TempCommand)
				{
				   case  cmd_event_route:
				   {
						if(!IsEmpty(TempPlatformProcessQueue))
						{
							Item TX;

							pthread_mutex_lock(&PlatformProcess_mutex_t);
							DeQueue(TempPlatformProcessQueue,&TX);
							pthread_mutex_unlock(&PlatformProcess_mutex_t);

						//	printf("%X\n",TX.Command);

							if(TX.Command!=cmd_event_route)
							{
								pthread_mutex_lock(&PlatformProcess_mutex_t);
								EnQueue(TempPlatformProcessQueue,TX);
								pthread_mutex_unlock(&PlatformProcess_mutex_t);
							}
							else
							{
								free(TX.buff);
								printf("clear data\n");
							}
							printf("Enter this1!\n");
						}
						struct timeval tv;
						tv.tv_sec = TX.buff[25]<<24|TX.buff[24]<<16|TX.buff[23]<<8|TX.buff[22];

						struct tm *pt;
						pt=gmtime(&tv.tv_sec);

						char s[100];
						strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", pt);

						Item RX;
						RX.Times = 3;
						RX.len = strlen(s)+6;
						RX.buff = (u8 *)malloc(RX.len);

						memset(RX.buff,0x00,RX.len);

						sprintf(RX.buff,"Time= %s",s);
						//memcpy(RX.buff,TX.buff,RX.len);

						pthread_mutex_lock(&PlatformSend_mutex_t);
						EnQueue(TempPlatformSendQueue,RX);
						pthread_mutex_unlock(&PlatformSend_mutex_t);

						printf("Enter this2!\n");

				   }
				   break;
				   default:
				   break;
				}
				printf("Process_Platform OK!\n");

				free(TX.buff);
			}

			if(!IsEmpty(TempPlatformProcessQueue))
			{
				Item TX;

				pthread_mutex_lock(&PlatformProcess_mutex_t);
				DeQueue(TempPlatformProcessQueue,&TX);
				pthread_mutex_unlock(&PlatformProcess_mutex_t);

				if(TX.Time_s==0)
				{
					struct timeval tv;
					gettimeofday(&tv, NULL);

					TX.Time_s = tv.tv_sec;
					TX.Time_us= tv.tv_usec;

					pthread_mutex_lock(&PlatformProcess_mutex_t);
					EnQueue(TempPlatformProcessQueue,TX);
					pthread_mutex_unlock(&PlatformProcess_mutex_t);

					switch(TX.Command)
					{
					   case cmd_event_route:
					   {
							Item RX;
							u8 buf[50];
							memset(buf,0x00,sizeof(buf));

							PacketData(&RX,buf,TX.buff,TX.len);

							RX.Times = 3;
							RX.len =FrameLength+TX.len+1;
							RX.buff =(u8 *)malloc(RX.len);

							memcpy(RX.buff,buf,RX.len);

							pthread_mutex_lock(&PlatformSend_mutex_t);
							EnQueue(TempPlatformSendQueue,RX);
							pthread_mutex_unlock(&PlatformSend_mutex_t);

							printf("first time data!\n");
					   }
					   break;
					   default:
					   break;
					}
				}
				else
				{
					struct timeval tv;
					gettimeofday(&tv, NULL);

					int TempTime =(tv.tv_sec-TX.Time_s)*1000+(int)(tv.tv_usec-TX.Time_us)/1000;
					//printf("TempTime=%d\n",TempTime);
					//sleep(1);
					if(TempTime>TX.Time_span)
					{
						//printf("%d***%d***%d\n",tv.tv_sec,TX.Time_s,(tv.tv_sec-TX.Time_s)*1000);
						//printf("%d***%d***%d\n",tv.tv_usec,TX.Time_us,(tv.tv_usec-TX.Time_us)/1000);
						//printf("TempTime=%d\n",TempTime);
						if(TX.Times--)
						{
							TX.Time_s = tv.tv_sec;
							TX.Time_us= tv.tv_usec;

							pthread_mutex_lock(&PlatformProcess_mutex_t);
							EnQueue(TempPlatformProcessQueue,TX);
							pthread_mutex_unlock(&PlatformProcess_mutex_t);

							switch(TX.Command)
							{
							   case cmd_event_route:
							   {
									Item RX;
									u8 buf[50];

									memset(buf,0x00,sizeof(buf));

									PacketData(&RX,buf,TX.buff,TX.len);

									RX.Times = 3;
									RX.len =FrameLength+TX.len+1;
									RX.buff =(u8 *)malloc(RX.len);

									memcpy(RX.buff,buf,RX.len);

									pthread_mutex_lock(&PlatformSend_mutex_t);
									EnQueue(TempPlatformSendQueue,RX);
									pthread_mutex_unlock(&PlatformSend_mutex_t);
							   }
							   break;
							   default:
							   break;
							}
							  printf("Overtime times=%d!\n",3-TX.Times);
						}
						else
						{
							free(TX.buff);
						}
					}
					else
					{
						pthread_mutex_lock(&PlatformProcess_mutex_t);
						EnQueue(TempPlatformProcessQueue,TX);
						pthread_mutex_unlock(&PlatformProcess_mutex_t);
					}
				}
			}
		}
	}
}


int ServerConnectSocket()
{
	int listenfd;

	//创建一个socket描述符，此描述符仅是本主机上的一个普通文件描述符而已
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("listenfd=%d\n", listenfd);

	//定义一个结构体变量servaddr，用来记录给定的IP和port信息，为bind函数做准备
	struct sockaddr_in serveraddr;
	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT); //把端口转化为网络字节序，即大端模式
	serveraddr.sin_addr.s_addr = INADDR_ANY;

	//把“本地含义的描述符”绑定到一个IP和Port上，此时这个socket才具备对外连接的能力
	bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

	//创建一个监听队列，用来保存用户的请求连接信息（ip、port、protocol)
	listen(listenfd, BACKLOG);

	printf("======bind success,waiting for client's request!!!======\n");
	//让操作系统回填client的连接信息（ip、port、protocol）
	struct sockaddr_in peeraddr;
	socklen_t peer_len = sizeof(peeraddr);

	return listenfd;
}
int ServerAcceptClient(int *listenfd)
{
	struct sockaddr_in peeraddr;
	socklen_t peer_len = sizeof(peeraddr);
	printf("11111\n");
	//accept函数从listen函数维护的监听队列里取一个客户连接请求处理
	int connfd = accept(*listenfd, (struct sockaddr*)&peeraddr, &peer_len);
	PrintCurrentTime();
	printf("=====================CCU Client Connect Successfully=====================\n");
	printf("IP = %s:PORT = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
	return connfd;
}


void *PthreadNetRec_CCU(Argument *Arg)
{
	char buf[MAXDATASIZE];

	while(Arg->arg)
	{
		fd_set rfds_Socket;
		FD_ZERO(&rfds_Socket);
		FD_SET(Arg->connfd, &rfds_Socket);
		int retval=select((Arg->connfd) + 1, &rfds_Socket, NULL, NULL, NULL);
									 //tv控制选择的时间，若规定时间内没有收到数据
									 //则不监控该rfds。则若为NULL，一直等到接收到数据
									 //再继续程序执行。
		printf("retval=%d--rfds_Socket=%d\n",rfds_Socket);
		if(retval==0)
		{
			printf("select error\n");
			return NULL;
		}
		IsSocketCCU=1;
		while(1)
		{
			if(FD_ISSET((Arg->connfd), &rfds_Socket)) //接收到数据了
			{
				bzero(buf, MAXDATASIZE);
				int  len = recv((Arg->connfd), buf, MAXDATASIZE, 0);
				if(len<=0)
				{
					//close(connfd);
					PrintCurrentTime();
					printf("Rec:client has closed!\n");
					Arg->connfd=-1;
					Arg->arg=0;
					MyThreadStop(&VST1Rec_Id);
					IsSocketCCU=0;
					break;
				}
				printf("Printf_Rec:%s***%d\n",buf,len);
				PrintProtocolData(buf,len);

				if(GetSize(TempRecQueue)>LimitNum)
				{
					Item TempData;

					pthread_mutex_lock(&CCURec_mutex_t);
					DeQueue(TempRecQueue,&TempData);
					pthread_mutex_unlock(&CCURec_mutex_t);

					free(TempData.buff);
				}

				u32 DataIndex=0;            //帧索引，可识别多条帧指令
				u32 TempFrameLength=0;      //帧长度
				while(len-DataIndex)
				{
					//printf("%d\n",DataIndex);
					TempFrameLength=buf[DataIndex+19]<<24|buf[DataIndex+18]<<16|buf[DataIndex+17]<<8|buf[DataIndex+16];  //数据域长度
					//	printf("%x\n",RecBuff_Platform[DataIndex+16]);
				    //printf("%d\n",TempFrameLength);
					TempFrameLength+=FrameLength;    //再加帧头等长度
					TempFrameLength+=1;              //再加校验长度
					//printf("%d\n",TempFrameLength);
					if(IsFrameHead(&buf[DataIndex]))   //检验帧头
					{
						u8 TempCheck = CheckSum(&buf[DataIndex],TempFrameLength-1);
						if(TempCheck == buf[DataIndex+TempFrameLength-1])   //检验帧校验
						{
							Item RX;

							RX.Times = 3;
							RX.len = TempFrameLength;
							RX.buff = (u8 *)malloc(RX.len);

							memset(RX.buff,0x00,RX.len);

							memcpy(RX.buff,&buf[DataIndex],RX.len);

							pthread_mutex_lock(&CCURec_mutex_t);
							EnQueue(TempRecQueue,RX);
							pthread_mutex_unlock(&CCURec_mutex_t);

							DataIndex+=TempFrameLength;    //修改索引，进行下一帧的查找
							//DataIndex-=1;
						}
						else
						{
							printf("Checkout is error!\n");
							break;
						}
					}
					else
					{
						printf("FrameHead is error!\n");
						break;
					}
				}
				memset(buf,0x00,sizeof(buf));
			}
		}
	}
	return NULL;
}

void *PthreadNetSend_CCU(Argument *Arg)
{
	while(Arg->arg)
	{
		IsSocketCCU=1;
		signal(SIGPIPE, SIG_IGN);   //忽略收到退出进程信号,交给系统处理

		if(!IsEmpty(TempSendQueue))
		{
			Item TX;

			pthread_mutex_lock(&CCUSend_mutex_t);
			DeQueue(TempSendQueue,&TX);
			pthread_mutex_unlock(&CCUSend_mutex_t);

			int len = send(Arg->connfd,TX.buff,TX.len,0);
			printf("Printf_Send:%s***%d\n",TX.buff,len);
			if(len==-1)
			{
				PrintCurrentTime();
				printf("Send:client has closed!\n");
				Arg->connfd=-1;
				Arg->arg=0;
				IsSocketCCU=0;
				MyThreadStop(&VST1Send_Id);
				break;
			}
			free(TX.buff);
		}
	}
}
void *PthreadNetProcess_CCU(Argument *Arg)
{
	while(Arg->arg)
	{
		if(IsSocketCCU!=0)           //建立连接之后才进行帧解析
		{
			if(!IsEmpty(TempRecQueue))      //对接收队列进行处理
			{
				//防止队列溢出，保留最新的队列数据。
				if(GetSize(TempSendQueue)>LimitNum)
				{
					Item TempData;

					pthread_mutex_lock(&CCUSend_mutex_t);
					DeQueue(TempSendQueue,&TempData);
					pthread_mutex_unlock(&CCUSend_mutex_t);

					free(TempData.buff);
				}

				Item TX;

				pthread_mutex_lock(&CCURec_mutex_t);
				DeQueue(TempRecQueue,&TX);
				pthread_mutex_unlock(&CCURec_mutex_t);

				u16 TempCommand=TX.buff[11]<<8|TX.buff[10];    //帧指令码
				//printf("%X\n",TempCommand);
				switch(TempCommand)
				{
				   case  cmd_event_route:
				   {
					   printf("=====cmd_event_route data=====\n");
						if(!IsEmpty(TempProcessQueue))
						{
							Item *TX=&(TempProcessQueue->front->data);
							if(TX->Command==cmd_event_route)
							{
								Item TempData;

								pthread_mutex_lock(&CCUProcess_mutex_t);
								DeQueue(TempProcessQueue,&TempData);
								pthread_mutex_unlock(&CCUProcess_mutex_t);

								free(TempData.buff);
								printf("clear data\n");
							}
//							free(TX);
							printf("Enter this1!\n");
						}
						EventRoute *event_route=(EventRoute *)&(TX.buff[FrameLength]);
						struct timeval tv;
						tv.tv_sec = (event_route->utcHigh)<<16|event_route->utcLow;
//							TX.buff[25]<<24|TX.buff[24]<<16|TX.buff[23]<<8|TX.buff[22];

						struct tm *pt;
						pt=gmtime(&tv.tv_sec);

						char s[100];
						strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", pt);

						printf("Time= %s\n",s);

//						Item RX;
//						RX.Times = 3;
//						RX.len = strlen(s)+6;
//						RX.buff = (u8 *)malloc(RX.len);
//
//						memset(RX.buff,0x00,RX.len);
//
//						sprintf(RX.buff,"Time= %s",s);
//
//						pthread_mutex_lock(&CCUSend_mutex_t);
//						EnQueue(TempSendQueue,RX);
//						pthread_mutex_unlock(&CCUSend_mutex_t);



				   }
				   break;
				   case cmd_event_school_time:
				   {
					   printf("=====cmd_event_school_time data=====\n");
					   if(!IsEmpty(TempProcessQueue))
					   {
						   Item *TX=&(TempProcessQueue->front->data);

							if(TX->Command==cmd_event_school_time)
							{
								Item TempData;

								pthread_mutex_lock(&CCUProcess_mutex_t);
								DeQueue(TempProcessQueue,&TempData);
								pthread_mutex_unlock(&CCUProcess_mutex_t);

								free(TempData.buff);
								printf("clear data\n");
							}
//							free(TX);
							printf("Enter this1!\n");
					   }

					    EventSynTime *event_time=(EventSynTime *)&TX.buff[FrameLength];
					    struct timeval tv;
						tv.tv_sec = event_time->utcHigh<<16|event_time->utcLow;
							//TX.buff[25]<<24|TX.buff[24]<<16|TX.buff[23]<<8|TX.buff[22];

						struct tm *pt;
						pt=gmtime(&tv.tv_sec);

						char s[100];
						strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", pt);

						printf("Time= %s\n",s);
//						Item RX;
//						RX.Times = 3;
//						RX.len = strlen(s)+6;
//						RX.buff = (u8 *)malloc(RX.len);
//
//						memset(RX.buff,0x00,RX.len);
//						sprintf(RX.buff,"Time= %s",s);
//						//memcpy(RX.buff,TX.buff,RX.len);
//
//						pthread_mutex_lock(&CCUSend_mutex_t);
//						EnQueue(TempSendQueue,RX);
//						pthread_mutex_unlock(&CCUSend_mutex_t);


				   }
				   break;

				   case cmd_event_heart:
				   {
					   printf("=====cmd_event_heart data=====\n");
					   if(!IsEmpty(TempProcessQueue))
					   {
						   Item *TX=&(TempProcessQueue->front->data);

							if(TX->Command==cmd_event_heart)
							{
								Item TempData;

								pthread_mutex_lock(&CCUProcess_mutex_t);
								DeQueue(TempProcessQueue,&TempData);
								pthread_mutex_unlock(&CCUProcess_mutex_t);

								free(TempData.buff);
								printf("clear data\n");
							}
   //							free(TX);
							printf("Enter this1!\n");
					   }

					    EventVehicleHeart *event_vehicle_heart=(EventVehicleHeart *)&TX.buff[FrameLength];
  
						struct timeval tv;
						tv.tv_sec = event_vehicle_heart->utcHigh<<16|event_vehicle_heart->utcLow;

						struct tm *pt;
						pt=gmtime(&tv.tv_sec);

						char s[100];
						strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", pt);

						printf("Time= %s\n",s);

						u32 Templongtitude =  event_vehicle_heart->LongtitudeHigh2<<24|event_vehicle_heart->LongtitudeHigh1<<8|event_vehicle_heart->LongtitudeLow;
						u32 Tempatitude =  event_vehicle_heart->LatitudeHigh2<<24|event_vehicle_heart->LatitudeHigh1<<8|event_vehicle_heart->LatitudeLow;
						u8 acceleration = event_vehicle_heart->acceleration;
                        u8 speed = event_vehicle_heart->speed;
						printf("long=%011.7f---atti=%011.7f---speed=%d---acc=%d\n",(double)Templongtitude/10000000,(double)Tempatitude/10000000,speed,acceleration);

				   }
				   break;
				   case cmd_event_vehicle_running:
				   {
					   printf("=====cmd_event_vehicle_running data=====\n");
					   if(!IsEmpty(TempProcessQueue))
					   {
						   Item *TX=&(TempProcessQueue->front->data);

							if(TX->Command==cmd_event_heart)
							{
								Item TempData;

								pthread_mutex_lock(&CCUProcess_mutex_t);
								DeQueue(TempProcessQueue,&TempData);
								pthread_mutex_unlock(&CCUProcess_mutex_t);

								free(TempData.buff);
								printf("clear data\n");
							}
	  //							free(TX);
							printf("Enter this1!\n");
					   }
					    EventVehicleHeart *event_vehicle_heart=(EventVehicleHeart *)&TX.buff[FrameLength];

						struct timeval tv;
						tv.tv_sec = event_vehicle_heart->utcHigh<<16|event_vehicle_heart->utcLow;

						struct tm *pt;
						pt=gmtime(&tv.tv_sec);

						char s[100];
						strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", pt);

						printf("Time= %s\n",s);

						u32 Templongtitude =  event_vehicle_heart->LongtitudeHigh2<<24|event_vehicle_heart->LongtitudeHigh1<<8|event_vehicle_heart->LongtitudeLow;
						u32 Tempatitude =  event_vehicle_heart->LatitudeHigh2<<24|event_vehicle_heart->LatitudeHigh1<<8|event_vehicle_heart->LatitudeLow;
						u8 acceleration = event_vehicle_heart->acceleration;
                        u8 speed = event_vehicle_heart->speed;
                        u8 dir =  TX.buff[37];


						printf("long=%011.7f---atti=%011.7f---speed=%d---acc=%d---dir=%d\n",(double)Templongtitude/10000000,(double)Tempatitude/10000000,speed,acceleration,dir);
				   }
				   break;
				   case cmd_event_vehicle_error:
				   {
					   printf("=====cmd_event_vehicle_error data=====\n");
					   if(!IsEmpty(TempProcessQueue))
					   {
						   Item *TX=&(TempProcessQueue->front->data);

							if(TX->Command==cmd_event_heart)
							{
								Item TempData;

								pthread_mutex_lock(&CCUProcess_mutex_t);
								DeQueue(TempProcessQueue,&TempData);
								pthread_mutex_unlock(&CCUProcess_mutex_t);

								free(TempData.buff);
								printf("clear data\n");
							}
	  //							free(TX);
							printf("Enter this1!\n");
					   }

					   EventVehicleHeart *event_vehicle_heart=(EventVehicleHeart *)&TX.buff[FrameLength];
					   
					   struct timeval tv;
					   tv.tv_sec = event_vehicle_heart->utcHigh<<16|event_vehicle_heart->utcLow;

						struct tm *pt;
						pt=gmtime(&tv.tv_sec);

						char s[100];
						strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", pt);

						printf("Time= %s\n",s);

						u32 Templongtitude =  event_vehicle_heart->LongtitudeHigh2<<24|event_vehicle_heart->LongtitudeHigh1<<8|event_vehicle_heart->LongtitudeLow;
						u32 Tempatitude =  event_vehicle_heart->LatitudeHigh2<<24|event_vehicle_heart->LatitudeHigh1<<8|event_vehicle_heart->LatitudeLow;
						u8 acceleration = event_vehicle_heart->acceleration;
                        u8 speed = event_vehicle_heart->speed;
						u8 vel_stat = TX.buff[37];

						printf("long=%011.7f---atti=%011.7f---speed=%d---acc=%d---stat=%d\n",(double)Templongtitude/10000000,(double)Tempatitude/10000000,speed,acceleration,vel_stat);
				   }
				   break;
				   case cmd_event_intersection_info:
				   {
					   printf("=====cmd_event_intersection_info data=====\n");
					   if(!IsEmpty(TempProcessQueue))
					   {
						   Item *TX=&(TempProcessQueue->front->data);

							if(TX->Command==cmd_event_intersection_info)
							{
								Item TempData;

								pthread_mutex_lock(&CCUProcess_mutex_t);
								DeQueue(TempProcessQueue,&TempData);
								pthread_mutex_unlock(&CCUProcess_mutex_t);

								free(TempData.buff);
								printf("clear data\n");
							}
	  //							free(TX);
							printf("Enter this1!\n");
					   }
					   IntersectionInfo *intersection_info=(IntersectionInfo *)&(TX.buff[FrameLength]);

					   printf("speed=%d---ID=%d---stra_stat=%d---stra_count=%d\n",intersection_info->vehicle_speed_adv,intersection_info->intersection_ID,intersection_info->light_straight_stat,intersection_info->signal_straight_count);
					   printf("left_stat=%d---let_count=%d---right_stat=%d---right_count=%d\n",intersection_info->signal_left_stat,intersection_info->signal_left_count,intersection_info->signal_right_stat,intersection_info->signal_right_count);
				   }
				   break;
				   default:
				   break;
				}
				printf("Process OK!\n");

				free(TX.buff);
			}

			if(!IsEmpty(TempProcessQueue))
			{
				Item *TX=&(TempProcessQueue->front->data);
				if(TX->Time_s==0)
				{
					struct timeval tv;
					gettimeofday(&tv, NULL);

					TX->Time_s = tv.tv_sec;
					TX->Time_us= tv.tv_usec;

					switch(TX->Command)
					{
					   case cmd_event_route:
					   {
							Item RX;

							RX.Times = 3;
							RX.len =TX->len;
							RX.buff =(u8 *)malloc(RX.len);

							memcpy(RX.buff,TX->buff,RX.len);

							pthread_mutex_lock(&CCUSend_mutex_t);
							EnQueue(TempSendQueue,RX);
							pthread_mutex_unlock(&CCUSend_mutex_t);

							printf("cmd_event_route data!\n");
					   }
					   break;

					   case cmd_event_school_time:
					   {
						    Item RX;

							RX.Times = 3;
							RX.len =TX->len;
							RX.buff =(u8 *)malloc(RX.len);

							memcpy(RX.buff,TX->buff,RX.len);

							pthread_mutex_lock(&CCUSend_mutex_t);
							EnQueue(TempSendQueue,RX);
							pthread_mutex_unlock(&CCUSend_mutex_t);

							printf("cmd_event_school_time data!\n");
					   }
					   break;
					   case cmd_event_heart:
					   {
						   Item RX;

							RX.Times = 3;
							RX.len =TX->len;
							RX.buff =(u8 *)malloc(RX.len);

							memcpy(RX.buff,TX->buff,RX.len);

							pthread_mutex_lock(&CCUSend_mutex_t);
							EnQueue(TempSendQueue,RX);
							pthread_mutex_unlock(&CCUSend_mutex_t);

							printf("cmd_event_heart data!\n");
					   }
					   default:
					   break;
					}
				}
				else
				{
					struct timeval tv;
					gettimeofday(&tv, NULL);

					int TempTime =(tv.tv_sec-TX->Time_s)*1000+(int)(tv.tv_usec-TX->Time_us)/1000;

					if(TempTime>TX->Time_span)   //判断报文是否超时
					{
						if(TX->Times--)
						{
							TX->Time_s = tv.tv_sec;
							TX->Time_us= tv.tv_usec;
							switch(TX->Command)
							{
							   case cmd_event_route:
							   {
									Item RX;

									RX.Times = 3;
									RX.len =TX->len;
									RX.buff =(u8 *)malloc(RX.len);

									memcpy(RX.buff,TX->buff,RX.len);

									pthread_mutex_lock(&CCUSend_mutex_t);
									EnQueue(TempSendQueue,RX);
									pthread_mutex_unlock(&CCUSend_mutex_t);
							   }
							   break;
							   case cmd_event_school_time:
							   {
								    Item RX;

									RX.Times = 3;
									RX.len =TX->len;
									RX.buff =(u8 *)malloc(RX.len);

									memcpy(RX.buff,TX->buff,RX.len);

									pthread_mutex_lock(&CCUSend_mutex_t);
									EnQueue(TempSendQueue,RX);
									pthread_mutex_unlock(&CCUSend_mutex_t);
							   }
							   break;
							   case cmd_event_heart:
							   {
								   Item RX;

									RX.Times = 3;
									RX.len =TX->len;
									RX.buff =(u8 *)malloc(RX.len);

									memcpy(RX.buff,TX->buff,RX.len);

									pthread_mutex_lock(&CCUSend_mutex_t);
									EnQueue(TempSendQueue,RX);
									pthread_mutex_unlock(&CCUSend_mutex_t);
							   }
							   break;
							   default:
							   break;
							}
							 printf("Overtime times=%d!\n",3-TX->Times);
						}
						else               //重发三次未有响应，直接清除该条报文
						{
							Item TempData;
							pthread_mutex_lock(&CCUProcess_mutex_t);
							DeQueue(TempProcessQueue,&TempData);
							pthread_mutex_unlock(&CCUProcess_mutex_t);

							free(TempData.buff);
						}
					}
				}
//				free(TX);
			}
		}
	}
}

void PacketData(Item *Temp,u8 buf[],u8 Sendbuff[],u16 Length)
{
	FrameData *EventInfo=(FrameData *)buf;

	EventInfo->FrameHead=frame_head;
	EventInfo->ProtocolVersion=protocal_version;
	EventInfo->SourceDevAddr=vst_dev_addr;
	EventInfo->DeviceIDLow=0x5678;    //ID=0x12345678,地位在前，高位在后，
	EventInfo->DeviceIDHigh=0x1234;

	EventInfo->DataType=cmd_event_school_time;
	EventInfo->TargetDevAddr=ccu_dev_addr;
	EventInfo->ReservedData=reserved_data;
	EventInfo->DataLength=Length;

	memcpy(&buf[FrameLength],Sendbuff,Length);

	buf[FrameLength+Length]=CheckSum(buf,FrameLength+Length);
}

