
#ifndef _ETHERNETIF_H_
#define _ETHERNETIF_H_

#include "lwip/err.h"
#include "lwip/netif.h"

//��ethernetif_initβ�������ã��������MAC��ַ������β������PHY��ʼ��
static void low_level_init(struct netif *netif);

//��ethernetif_initע���netif->linkoutput = low_level_output;
static err_t low_level_output(struct netif *netif, struct pbuf *p);

//���������ݺ���ô˺�����ȡpbuf����ethernetif_input����������
static struct pbuf * low_level_input(struct netif *netif);


void lwip_poll_recv(void);




//ethernetifĩβ��if��ע������Э��ջ�е�ethernet_inputĩβ����if
//������������ʱ�������������������������low_level_input
static void ethernetif_input(struct netif *netif);

//��ʼ����·��
err_t ethernetif_init(struct netif *netif);

#endif /* _ETHERNETIF_H_ */
