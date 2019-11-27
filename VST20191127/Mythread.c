#include "Mythread.h"

pthread_t VST1Rec_Id;
pthread_t VST1Send_Id;
pthread_t VST1Process_Id;

pthread_t PlatformRec_Id;
pthread_t PlatformSend_Id;
pthread_t PlatformProcess_Id;

int MyThreadStart(void*(*start_rountine)(void*),pthread_t *thread,void *arg)
{
	memset(thread,0x00,sizeof(pthread_t));
	int TempReturnValue;

	TempReturnValue = pthread_create(thread,NULL,start_rountine,arg);  //创建线程函数
	if(TempReturnValue!=0)
	{
		printf("thread created failed!\n");
	}
	else
	{
		int id = pthread_self();
		printf("thread id = %d\n",id);
	}
	return TempReturnValue;
}
void MyThreadStop(pthread_t *pthread)
{
  	if(*pthread!=0)
  	{
  		pthread_join(*pthread, NULL);
  		printf("thread is over!\n");
  	}
}


