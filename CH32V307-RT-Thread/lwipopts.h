
#ifndef _LWIPOPTS_H_
#define _LWIPOPTS_H_

///4�ֽڶ��룬��cpu��صĻ���arch/cc.h���壬��ϵͳ��صĻ���sys_arch.hʵ��
#define MEM_ALIGNMENT 4


///�в���ϵͳ
#define NO_SYS  0

///����C����ڴ�
#define MEM_LIBC_MALLOC 0
///ͨ���� MEM_USE_POOLS ����ʹ���ڴ�ѻ����ڴ��ʵ��             ���˽�Դ�������¾Ͱ�MEM_LIBC_MALLOC��Ϊ0��������
///ͨ���� MEMP_MEM_MALLOC ����ʵ���ڴ�ػ����ڴ��ʵ��
///�ڴ�Ѵ�С
#define MEM_SIZE 1024*10
///�ڴ�ش�С
//��memp_std.h����MEMP_MAX��

///��ʹ��socket
#define LWIP_SOCKET 1
///��ʹ��NETCONN
#define LWIP_NETCONN 0
///ʹ��RAW
#define LWIP_RAW 0

///��Ҫ���ڽ��մӵײ�����ϲ㴫�ݹ�������Ϣ ��������޷���ʼ��
#define TCPIP_MBOX_SIZE 8              //"pbuf_free: p->ref > 0" failed at line 753 in pbuf.c
#define TCPIP_THREAD_STACKSIZE 800
#define TCPIP_THREAD_PRIO 4


///����ʹ��GCC �Դ� timeval �ṹ�嶨��,LWIP_TIMEVAL_PRIVATE����������,Ҳ���Ƕ���Ϊ��,��Ȼ����ᱨ��
#define LWIP_TIMEVAL_PRIVATE 0

#define LWIP_DEBUG LWIP_DBG_ON    //debug�ܿ���

#define TCPIP_DEBUG 0
#define LWIP_IGMP 0
#define MEM_DEBUG 0
#define MEMP_DEBUG 0
#define NETIF_DEBUG 0
#define ETHARP_DEBUG 0

#endif /* _LWIPOPTS_H_ */
