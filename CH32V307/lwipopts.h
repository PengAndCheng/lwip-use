
#ifndef _LWIPOPTS_H_
#define _LWIPOPTS_H_

///4�ֽڶ��룬��cpu��صĻ���arch/cc.h���壬��ϵͳ��صĻ���sys_arch.hʵ��
#define MEM_ALIGNMENT 4


///�����ò���ϵͳ ��Ȼϵͳ�в���ϵͳ��������ֲ�÷�ʽ���õ����޲���ϵͳ
#define NO_SYS  1

///����C����ڴ�
#define MEM_LIBC_MALLOC 0
///ͨ���� MEM_USE_POOLS ����ʹ���ڴ�ѻ����ڴ��ʵ��             ���˽�Դ�������¾Ͱ�MEM_LIBC_MALLOC��Ϊ0��������
///ͨ���� MEMP_MEM_MALLOC ����ʵ���ڴ�ػ����ڴ��ʵ��
///�ڴ�Ѵ�С
#define MEM_SIZE 1024*20
///�ڴ�ش�С
//��memp_std.h����MEMP_MAX��

///��ʹ��socket
#define LWIP_SOCKET 0
///��ʹ��NETCONN
#define LWIP_NETCONN 0
///ʹ��RAW
#define LWIP_RAW 1


//�����ɱ�ping����
#define LWIP_DEBUG LWIP_DBG_ON    //debug�ܿ���

#define TCPIP_DEBUG LWIP_DBG_ON

#define LWIP_IGMP LWIP_DBG_ON

#define MEM_DEBUG LWIP_DBG_ON
#define MEMP_DEBUG LWIP_DBG_ON
#define NETIF_DEBUG LWIP_DBG_ON
#define ETHARP_DEBUG 0

#endif /* _LWIPOPTS_H_ */
