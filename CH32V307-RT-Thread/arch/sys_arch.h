
#ifndef _ARCH_SYS_ARCH_H_
#define _ARCH_SYS_ARCH_H_


#include <rtthread.h>


typedef rt_sem_t sys_sem_t;
typedef rt_mutex_t sys_mutex_t;
typedef rt_mailbox_t  sys_mbox_t;
typedef rt_thread_t sys_thread_t;


#define SYS_MBOX_SIZE 10
#define SYS_LWIP_TIMER_NAME "timer"
#define SYS_LWIP_MBOX_NAME "mbox"
#define SYS_LWIP_SEM_NAME "sem"
#define SYS_LWIP_MUTEX_NAME "mu"


#endif /* _ARCH_SYS_ARCH_H_ */
