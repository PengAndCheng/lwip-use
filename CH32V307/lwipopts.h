
#ifndef _LWIPOPTS_H_
#define _LWIPOPTS_H_

///4字节对齐，与cpu相关的还有arch/cc.h定义，与系统相关的还有sys_arch.h实现
#define MEM_ALIGNMENT 4


///不适用操作系统 虽然系统有操作系统，但是移植得方式采用的是无操作系统
#define NO_SYS  1

///不用C库堆内存
#define MEM_LIBC_MALLOC 0
///通过宏 MEM_USE_POOLS 可以使能内存堆基于内存池实现             不了解源码的情况下就把MEM_LIBC_MALLOC设为0就完事了
///通过宏 MEMP_MEM_MALLOC 可以实现内存池基于内存堆实现
///内存堆大小
#define MEM_SIZE 1024*20
///内存池大小
//由memp_std.h决定MEMP_MAX的

///不使用socket
#define LWIP_SOCKET 0
///不使用NETCONN
#define LWIP_NETCONN 0
///使用RAW
#define LWIP_RAW 1


//开启可被ping功能
#define LWIP_DEBUG LWIP_DBG_ON    //debug总开关

#define TCPIP_DEBUG LWIP_DBG_ON

#define LWIP_IGMP LWIP_DBG_ON

#define MEM_DEBUG LWIP_DBG_ON
#define MEMP_DEBUG LWIP_DBG_ON
#define NETIF_DEBUG LWIP_DBG_ON
#define ETHARP_DEBUG 0

#endif /* _LWIPOPTS_H_ */
