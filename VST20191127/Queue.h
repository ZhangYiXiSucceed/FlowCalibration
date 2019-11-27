#ifndef Queue_H
#define Queue_H

#include <stdio.h>
#include <stdlib.h>

#include "ReadConfig.h"
#include "timer.h"

//#ifdef __GNUC__
//#define STRUCT_PACKED __attribute__ ((packed))
//#else
//#define STRUCT_PACKED
//#endif
//#define PACKED __attribute__((aligned(1),packed))  // 一字节对齐
//#pragma pack (1)

#define frame_head        0x5AA5
#define protocal_version  0x0001
#define ccu_dev_addr      0x0001
#define vst_dev_addr      0x0004
#define reserved_data     0xFFFF

#define cmd_event_route         0x4101

#define cmd_event_school_time     0x1401
#define cmd_event_heart           0x1402
#define cmd_event_vehicle_running 0x1403
#define cmd_event_vehicle_error   0x1404
#define cmd_event_intersection_info   0x1405
#define cmd_event_speed_limit         0x1406
#define cmd_event_people_police       0x1407
#define cmd_event_vehicle_collision   0x1408
#define cmd_event_traffic_info        0x1409
#define cmd_event_vehivle_error_info  0x1410
#define cmd_event_period_vehivle_inf0 0x1411
#define cmd_event_switch_drive_stat   0x1412
#define cmd_event_on_off_pathway      0x1413
#define cmd_event_off_pathway         0x1414
#define cmd_event_stop_distance       0x1415
#define cmd_event_



typedef struct item
{
    u32 Time_s;     //时间秒
    u32 Time_us;    //时间微妙
    u16 Time_span;  //时间间隔
	u16 Command;    //指令码
    s16 Times;      //尝试次数
    u16 len;        //数据区长度
    u8 * buff;
} Item;

typedef struct node * PNode;
typedef struct node
{
    Item data;
    PNode next;
} Node;

typedef struct
{
    PNode front;
    PNode rear;
    int size;
} Queue;

typedef struct Frame
{
   u16 FrameHead;
   u16 ProtocolVersion;
   u16 SourceDevAddr;

   u16 DeviceIDLow;
   u16 DeviceIDHigh;

   u16 DataType;
   u16 TargetDevAddr;
   u16 ReservedData;
   u32 DataLength;
   u8 Data[];
}FrameData;

#define FrameLength 20
typedef struct
{
   u16 Vehicle;
   u16 utcLow;
   u16 utcHigh;
   u8  time_ms;
   u8 route1;
   u32  route2;
   u32 time_departure;
}EventRoute;
#define EventRouteLength  16

typedef struct{
	u16 VehicleID;
	u16 utcLow;
	u16 utcHigh;
	u8  time_ms;
}EventSynTime;
#define EventSynTimeLength  7

typedef struct{
	u16 VehicleID;
	u16 utcLow;

	u16 utcHigh;
	u8 time_ms;
	u8 LongtitudeLow;

	u16 LongtitudeHigh1;
	u8 LongtitudeHigh2;
	u8 LatitudeLow;

	u16 LatitudeHigh1;
	u8 LatitudeHigh2;
	u8 speed;

	u8 acceleration;

}EventVehicleHeart;
#define EventHeartLength  17

typedef struct{
	u16 vehicle_speed_adv;
	u8 intersection_ID;
	u8 light_straight_stat;

	u8 signal_straight_count;
	u8 signal_left_stat;
	u8 signal_left_count;
	u8 signal_right_stat;

	u8 signal_right_count;
	u8 red_light_warnning;
}IntersectionInfo;
#define IntersectionInfoLength 10

typedef struct{
	u8 vehicle_speed_limit;
	u8 vehicle_distance_limit;
}LimitInfo;
#define LimitInfoLength  2

typedef struct{
	u8 passerby_warning;
	u8 passerby_warning_dir;
	u16 utcLow;

	u16 utcHigh;
	u8 time_ms;
}PasserbyWarning;
#define PasserbyWarningLength 7

typedef struct{
  u8 vehcile_collision_warning;
  u8 vehcile_collision_dir;
  u16 utcLow;

  u16 utcHigh;
  u8 time_ms;
}VehicleCollision;

#define VehicleCollisionLength 7

typedef struct{
   u8 traffic_condition;
   u16 traffic_distance;
   u8 utcLow;

   u16 utcHigh1;
   u8 utcHight2;
   u8 time_ms;
}TrafficWarning;
#define TrafficWarningLength  8


typedef  struct{
   u8 vehicle_warning;
   u16  vehicle_distance;
   u8 utcLow;

   u16 utcHigh1;
   u8 utcHigh2;
   u8 time_ms;
}VehicleWarning;

#define VehicleWarningLength  8

typedef struct{
	u16 VehicleID;
	u16 utcLow;

	u16 utcHigh;
	u8 time_ms;
	u8 log_stat;

	u8 drive_stat;
	u16 Fb_deviation;
	u8 Rb_deviationLow;

	u8 Rb_deviationHigh;
	u16 deviation_angle;
	u8 trip_mileLow;

	u8 trip_mileHigh;
	u16 magnetic_nail_numLow;
	u8 magnetic_nail_numHigh1;

	u8 magnetic_nail_numHigh2;
	u8 track_stat;
}PeriodVehicleInfo;
#define PeriodVehicleInfoLength  22

typedef struct{
   u16  VehicleID;
   u16  utcLow;

   u16 utcHigh;
   u8 time_ms;
   u8 drive_stat_switch;
}DriveSwitch;


Queue *TempQueue;
/*构造一个空队列*/
Queue *InitQueue();

/*销毁一个队列*/
void DestroyQueue(Queue *pqueue);

/*清空一个队列*/
void ClearQueue(Queue *pqueue);

/*判断队列是否为空*/
int IsEmpty(Queue *pqueue);

/*返回队列大小*/
int GetSize(Queue *pqueue);

/*返回队头元素*/
PNode GetFront(Queue *pqueue,Item *pitem);

/*返回队尾元素*/
PNode GetRear(Queue *pqueue,Item *pitem);

/*将新元素入队*/
PNode EnQueue(Queue *pqueue,Item item);

/*队头元素出队*/
PNode DeQueue(Queue *pqueue,Item *pitem);

/*遍历队列并对各数据项调用visit函数*/
void QueueTraverse(Queue *pqueue,void (*visit)());

//清除队列数据
void ClearQueue(Queue *pqueue);
//根据指令寻找某个节点
u8 FindQueueNode(Queue *pqueue,Item *pitem,u16 Command);

void TempCommandSchoolTime(u8 Buff[],int *DataLength);

void TempCommandHeartPacket(u8 Buff[],int *DataLength);


extern Queue *TempRecQueue;
extern Queue *TempSendQueue;
extern Queue *TempProcessQueue;

extern Queue *TempPlatformRecQueue;
extern Queue *TempPlatformSendQueue;
extern Queue *TempPlatformProcessQueue;
#endif


