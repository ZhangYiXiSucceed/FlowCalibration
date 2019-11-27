#include "Mythread.h"
#include "Net.h"
#include "Queue.h"
#include "ReadConfig.h"
#include "timer.h"




int main()
{
	TimerFunc();
	int connfd;
	int listenfd = ServerConnectSocket();
	while(1)
	{
		//accept函数从listen函数维护的监听队列里取一个客户连接请求处理
		struct sockaddr_in peeraddr;
		socklen_t peer_len = sizeof(peeraddr);
		printf("11111\n");
		connfd = accept(listenfd, (struct sockaddr*)&peeraddr, &peer_len);
		printf("=====================Client Connect Successfully=====================\n");
		printf("IP = %s:PORT = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

		char buf[MAXDATASIZE];

		fd_set rfds_Socket;
		FD_ZERO(&rfds_Socket);
		FD_SET(connfd, &rfds_Socket);
		int retval=select(connfd + 1, &rfds_Socket, NULL, NULL, NULL);
									 //tv控制选择的时间，若规定时间内没有收到数据
									 //则不监控该rfds。则若为NULL，一直等到接收到数据
									 //再继续程序执行。
		printf("retval=%d--rfds_Socket=%d\n",rfds_Socket);
		if(retval==0)
		{
			printf("select error\n");
			continue;
		}

		while(1)
		{
			if(FD_ISSET(connfd, &rfds_Socket)) //接收到数据了
			{
				bzero(buf, MAXDATASIZE);
				int  len = recv(connfd, buf, MAXDATASIZE, 0);
				if(len<=0)
				{
					//close(connfd);
					printf("client has closed!\n");
					connfd=-1;
					break;
				}
				printf("%s***%d\n",buf,len);
				send(connfd, buf, len, 0);
				memset(buf, '\0', MAXDATASIZE/sizeof (char));
			}
		}
	}
	close(connfd);
	close(listenfd);
	return 0;
}
