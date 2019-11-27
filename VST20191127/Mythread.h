#ifndef __MYTHREAD_H__
#define __MYTHREAD_H__

#include "pthread.h"
#include "string.h"
#include "stdio.h"

extern pthread_t VST1Rec_Id;
extern pthread_t VST1Send_Id;
extern pthread_t VST1Process_Id;

extern pthread_t PlatformRec_Id;
extern pthread_t PlatformSend_Id;
extern pthread_t PlatformProcess_Id;

int MyThreadStart(void *(*start_rountine)(void *),pthread_t *thread,void *arg);
void MyThreadStop(pthread_t *thread);
#endif


