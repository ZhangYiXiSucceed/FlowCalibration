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
		//accept������listen����ά���ļ���������ȡһ���ͻ�����������
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
									 //tv����ѡ���ʱ�䣬���涨ʱ����û���յ�����
									 //�򲻼�ظ�rfds������ΪNULL��һֱ�ȵ����յ�����
									 //�ټ�������ִ�С�
		printf("retval=%d--rfds_Socket=%d\n",rfds_Socket);
		if(retval==0)
		{
			printf("select error\n");
			continue;
		}

		while(1)
		{
			if(FD_ISSET(connfd, &rfds_Socket)) //���յ�������
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
