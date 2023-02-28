
#ifndef _ETHERNETIF_H_
#define _ETHERNETIF_H_

#include "lwip/err.h"
#include "lwip/netif.h"

//在ethernetif_init尾部被调用，自身产生MAC地址，自身尾部调用PHY初始化
static void low_level_init(struct netif *netif);

//在ethernetif_init注册给netif->linkoutput = low_level_output;
static err_t low_level_output(struct netif *netif, struct pbuf *p);

//网卡来数据后调用此函数获取pbuf，在ethernetif_input函数被调用
static struct pbuf * low_level_input(struct netif *netif);


void lwip_poll_recv(void);




//ethernetif末尾带if，注意区分协议栈中的ethernet_input末尾不带if
//当网卡数据来时调用这个函数，这个函数会调用low_level_input
static void ethernetif_input(struct netif *netif);

//初始化链路层
err_t ethernetif_init(struct netif *netif);

#endif /* _ETHERNETIF_H_ */
