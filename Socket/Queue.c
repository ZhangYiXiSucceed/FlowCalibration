#include "Queue.h"

Queue *TempRecQueue;
Queue *TempSendQueue;
Queue *TempProcessQueue;

Queue *TempPlatformRecQueue;
Queue *TempPlatformSendQueue;
Queue *TempPlatformProcessQueue;


/*构造一个空队列*/
Queue *InitQueue()
{
	Queue *pqueue = (Queue *)malloc(sizeof(Queue));
	if(pqueue!=NULL)
	{
		pqueue->front = NULL;
		pqueue->rear = NULL;
		pqueue->size = 0;
	}
	return pqueue;
}

/*销毁一个队列*/
void DestroyQueue(Queue *pqueue)
{
	if(IsEmpty(pqueue)!=1)
		ClearQueue(pqueue);
	free(pqueue);
}

/*清空一个队列*/
void ClearQueue(Queue *pqueue)
{
	while(IsEmpty(pqueue)!=1)
	{
		Item it;
		DeQueue(pqueue,& it);
		free(it.buff);
	}
}

/*判断队列是否为空*/
int IsEmpty(Queue *pqueue)
{
	if(pqueue->front==NULL&&pqueue->rear==NULL&&pqueue->size==0)
		return 1;
	else
		return 0;
}

/*返回队列大小*/
int GetSize(Queue *pqueue)
{
	return pqueue->size;
}

/*返回队头元素*/
PNode GetFront(Queue *pqueue,Item *pitem)
{
	if(IsEmpty(pqueue)!=1&&pitem!=NULL)
	{
		*pitem = (pqueue->front->data);
	}
	return pqueue->front;
}

/*返回队尾元素*/

PNode GetRear(Queue *pqueue,Item *pitem)
{
	if(IsEmpty(pqueue)!=1&&pitem!=NULL)
	{
		*pitem = pqueue->rear->data;
	}
	return pqueue->rear;
}

/*将新元素入队*/
PNode EnQueue(Queue *pqueue,Item item)
{
	PNode pnode = (PNode)malloc(sizeof(Node));
	if(pnode != NULL)
	{
		pnode->data= item;
		pnode->next = NULL;
		
		if(IsEmpty(pqueue))
		{
			pqueue->front = pnode;
		}
		else
		{
			pqueue->rear->next = pnode;
		}
		pqueue->rear = pnode;
		pqueue->size++;
	}
	return pnode;
}

/*队头元素出队*/
PNode DeQueue(Queue *pqueue,Item *pitem)
{
	PNode pnode = pqueue->front;
	if(IsEmpty(pqueue)!=1&&pnode!=NULL)
	{
		if(pitem!=NULL)
			*pitem = pnode->data;
		pqueue->size--;
		pqueue->front = pnode->next;
		free(pnode);
		if(pqueue->size==0)
			pqueue->rear = NULL;
	}
	return pqueue->front;
}
/*寻找队列中某个指令节点*/
u8 FindQueueNode(Queue *pqueue,Item *pitem,u16 Command)
{
	PNode pnode=pqueue->front;
	while((IsEmpty(pqueue)!=1)&&(pnode!=NULL))
	{
		//printf("cmd--%x\n",pnode->data.Command);
		if(pnode->data.Command==Command)
		{
			*pitem=pnode->data;
             return 1;
		}
		else
		{
			pnode=pnode->next;
			continue;
		}
	}
	return 0;
}
/*返回队首*/
void BackQueue(Queue *pqueue,Item *pitem)
{
	PNode pnode = (PNode)malloc(sizeof(Node));
	pnode->next=pqueue->front;
	pnode->data=*pitem;
	pqueue->front=pnode;
}

/*遍历队列并对各数据项调用visit函数*/
void QueueTraverse(Queue *pqueue,void (*visit)())
{
	PNode pnode = pqueue->front;
	int i = pqueue->size;
	while(i--)
	{
		visit(pnode->data);
		pnode = pnode->next;
	}
		
}
void TempCommandSchoolTime(u8 Buff[],int *DataLength)
{

	memset(Buff,0x00,sizeof(Buff));

	FramHead_t *Fr=(FramHead_t *)Buff;
	Fr->FixPara=0x44534B4A;
	Fr->gwaddr=11000010;
	Fr->seq=0x01;
	Fr->len=0x00;
	Fr->command=0x10;

	u16 * CRC=(u16*)(& Buff[FramHead_len]);
	*CRC=CalCRC(Buff,FramHead_len);

	*DataLength = FramHead_len+2;


	Item tx;

	tx.Times = 3;
	tx.len = FramHead_len+2;
	tx.buff = (u8 *)malloc(tx.len);
	memcpy(tx.buff,Buff,tx.len);

	EnQueue(TempQueue,tx);
}
unsigned char  GateWayVersion[4]= { 0x20,0x19,0x01,0x15}; //系统版本

void TempCommandHeartPacket(u8 Buff[],int *DataLength)
{
	memset(Buff,0x00,sizeof(Buff));

	FramHead_t *Fr=(FramHead_t *)Buff;
	Fr->FixPara=0x44534B4A;
	Fr->gwaddr=11000010;
	Fr->seq=0x01;
	Fr->len=CammadUploadHeart_len;
	Fr->command=0x13;

	CammadUploadHeart_t *uploadheart=(CammadUploadHeart_t*)(&Buff[FramHead_len]);
	uploadheart->rfchannel=13;
	uploadheart->txpower=13;
	uploadheart->bw=9;
	uploadheart->sf=7;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	uploadheart->GMT=tv.tv_sec;
	uploadheart->BAT=24;
	uploadheart->RSSI4G=0;
	uploadheart->ERR=0;
	uploadheart->VERSION=*((u32 *)GateWayVersion);
	uploadheart->NUMBER=0;

	u16 * CRC=(u16*)(& Buff[FramHead_len+CammadUploadHeart_len]);
	*CRC=CalCRC(Buff,FramHead_len+CammadUploadHeart_len);

	*DataLength =  FramHead_len + CammadUploadHeart_len + 2;
}
