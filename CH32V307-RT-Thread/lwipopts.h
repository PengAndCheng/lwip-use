
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
#define MEM_SIZE 1024*16
///�ڴ�ش�С
//��memp_std.h����MEMP_MAX��

///API�׼�
#define LWIP_SOCKET 0
#define LWIP_NETCONN 1
#define LWIP_RAW 0
///ʹ�ò���ϵͳʱ ����api�������ȳߴ磬��Щ�����ã�ʹ��ʱû��debug�����û����Щ���þͲ��� netconn_new
#define DEFAULT_RAW_RECVMBOX_SIZE 0
#define DEFAULT_TCP_RECVMBOX_SIZE 4
#define DEFAULT_UDP_RECVMBOX_SIZE 4
///û������Ͳ���ʹ�� netconn_listen
#define DEFAULT_ACCEPTMBOX_SIZE 4

///��Ҫ���ڽ��մӵײ�����ϲ㴫�ݹ�������Ϣ ��������޷���ʼ��
#define TCPIP_MBOX_SIZE 8              //"pbuf_free: p->ref > 0" failed at line 753 in pbuf.c
#define TCPIP_THREAD_STACKSIZE 1500
#define TCPIP_THREAD_PRIO 5


///����ʹ��GCC �Դ� timeval �ṹ�嶨��,LWIP_TIMEVAL_PRIVATE����������,Ҳ���Ƕ���Ϊ��,��Ȼ����ᱨ��
#define LWIP_TIMEVAL_PRIVATE 0

#define LWIP_DEBUG LWIP_DBG_ON    //debug�ܿ���

#define TCPIP_DEBUG LWIP_DBG_ON
#define LWIP_IGMP 0
#define MEM_DEBUG 0
#define MEMP_DEBUG 0
#define NETIF_DEBUG 0
#define ETHARP_DEBUG 0

#endif /* _LWIPOPTS_H_ */
