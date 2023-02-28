
#ifndef _LWIPOPTS_H_
#define _LWIPOPTS_H_

///4字节对齐，与cpu相关的还有arch/cc.h定义，与系统相关的还有sys_arch.h实现
#define MEM_ALIGNMENT 4


///有操作系统
#define NO_SYS  0

///不用C库堆内存
#define MEM_LIBC_MALLOC 0
///通过宏 MEM_USE_POOLS 可以使能内存堆基于内存池实现             不了解源码的情况下就把MEM_LIBC_MALLOC设为0就完事了
///通过宏 MEMP_MEM_MALLOC 可以实现内存池基于内存堆实现
///内存堆大小
#define MEM_SIZE 1024*10
///内存池大小
//由memp_std.h决定MEMP_MAX的

///不使用socket
#define LWIP_SOCKET 1
///不使用NETCONN
#define LWIP_NETCONN 0
///使用RAW
#define LWIP_RAW 0

///主要用于接收从底层或者上层传递过来的消息 不定义就无法初始化
#define TCPIP_MBOX_SIZE 8              //"pbuf_free: p->ref > 0" failed at line 753 in pbuf.c
#define TCPIP_THREAD_STACKSIZE 800
#define TCPIP_THREAD_PRIO 4


///如若使用GCC 自带 timeval 结构体定义,LWIP_TIMEVAL_PRIVATE这个必须关了,也就是定义为零,不然编译会报错。
#define LWIP_TIMEVAL_PRIVATE 0

#define LWIP_DEBUG LWIP_DBG_ON    //debug总开关

#define TCPIP_DEBUG 0
#define LWIP_IGMP 0
#define MEM_DEBUG 0
#define MEMP_DEBUG 0
#define NETIF_DEBUG 0
#define ETHARP_DEBUG 0

#endif /* _LWIPOPTS_H_ */
