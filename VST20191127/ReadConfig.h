#ifndef __READCONFIG_H__
#define __READCONFIG_H__

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <syslog.h>

#include <stddef.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdint.h>

#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

extern int  FileCopy(void *source_file, void *dest_file);
extern int  SplitSectionToNameIndex(char *section, char **name, char **index);
extern int  JoinNameIndexToSection(char **section, char *name, char *index);
extern int  ConfigGetKey(void *CFG_file, void *section, void *key, void *buf);
extern int  ConfigSetKey(void *CFG_file, void *section, void *key, void *buf);
extern int  ConfigGetSections(void *CFG_file, char *sections[]);
extern int  ConfigGetKeys(void *CFG_file, void *section, char *keys[]);

extern void INIFileTstmain(void);

#define byte  char
#define  u8     char
#define  s8     signed char
#define u16  unsigned short
#define s16   short
#define u32  unsigned int
#define s32   int


typedef struct
{
    u32 FixPara;//固定为DSKJ
    u32 gwaddr;//网关地址
    u16 seq;//序号
    u16 len;//数据区长度，不包含CRC 长度
    u16 command;//命令区长度
    u8 dat[];
} FramHead_t;
#define  FramHead_len  14

typedef struct
{
    u8 rfchannel;
    u8 txpower;
    u8 bw;
    u8 sf;
    u32 GMT;
    u16 BAT;
    u16 RSSI4G;
    u32 ERR;
    u32 VERSION;
    u32 NUMBER;
} CammadUploadHeart_t;

#define CammadUploadHeart_len   24

#endif
