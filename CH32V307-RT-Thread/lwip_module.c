
#include <stdio.h>


#include "lwip/tcpip.h"
#include "eth_driver.h"


//注册函数
extern err_t ethernetif_init(struct netif *netif);
extern err_t ethernet_input(struct pbuf *p, struct netif *netif);

//网络接口数据
struct netif net;
struct netif* net_get(void){
    return &net;
};
//网口链路变化通知
static int net_link = 0;
void net_set_link(int value)
{
    printf("net_set_link %d.\n",value);
    net_link = value;
    if (value == 1) {
        netif_set_link_up(&net);
    }else {
        netif_set_link_down(&net);
    }
}
static uint8_t hwaddr[6] = {0x84, 0xc2, 0xe4, 0x01, 0x02, 0x03};
uint8_t *hwaddr_get(void){
    return hwaddr;
}

//被引用的数据一定要使用static或全局
static ip4_addr_t ipaddr;
static ip4_addr_t netmask;
static ip4_addr_t gw;
static ip4_addr_t pingip;

void tcpip_init_done_callback(void *arg){
    printf("tcpip_init_done_cb start.\r\n");

    IP4_ADDR(&ipaddr, 192,168,1,66);
    IP4_ADDR(&netmask, 255,255,255,0);
    IP4_ADDR(&gw, 192,168,1,1);

    netif_add(&net, &ipaddr, &netmask, &gw, NULL, ethernetif_init, ethernet_input);

    netif_set_default(&net);

    netif_set_up(&net);
}

void ttest(void *p){
    while(1){
        printf("ttest.\r\n");
        rt_thread_mdelay(1000);
    }
}

void lwip_module_init(void){
    ///参数1初始化完成回调函数 参数2初始化完成回调参数
    tcpip_init(tcpip_init_done_callback,0);

    //sys_thread_new("ttest", ttest, NULL, 512, 5);
}

void lwip_module_poll(void){
    /* 是否接收到数据 */
    FrameTypeDef* f = eth_frame_get();
    if(f->length)
    {
        int recv_length = f->length;
        f->length=0;
        uint8_t *recv_ptr = (uint8_t *)f->buffer;

        #if 1
        int i;
        printf("receive counter:%d.\n",ETH->MMCRGUFCR);
        printf("read_length:%d\n",recv_length);
        printf("Received@0x%08x\n",recv_ptr);
        for(i=0;i<6;i++)
            printf("%02x ",*(uint8_t*)(recv_ptr+i));
            printf("\n");
        for(i=6;i<12;i++)
            printf("%02x ",*(uint8_t*)(recv_ptr+i));
            printf("\n");
        for(i=12;i<22;i++)
            printf("%02x ",*(uint8_t*)(recv_ptr+i));
        printf("END!\n\n");
        #endif

        //进行地址过滤 先不找MAC硬件过滤的方法了，先快速成型
        extern uint8_t *hwaddr_get(void);
        uint8_t* hwaddr = hwaddr_get();
        int hwaddr_cnt = 0;
        int FF_cnt = 0;
        for (int i = 0; i < 6; ++i) {
            if (recv_ptr[i] == hwaddr[i]) {
                hwaddr_cnt++;
            }
            if (recv_ptr[i] == 0xff) {
                FF_cnt++;
            }
        }
        if (hwaddr_cnt == 6 || FF_cnt == 6) {
            extern void ethernetif_input_cb(uint8_t* data, int len);
            ethernetif_input_cb(recv_ptr,recv_length);
        }
        f->length = 0;
    }
}
