
#include <stdio.h>


#include "lwip/tcpip.h"
#include "eth_driver.h"


//ע�ắ��
extern err_t ethernetif_init(struct netif *netif);
extern err_t ethernet_input(struct pbuf *p, struct netif *netif);

//����ӿ�����
struct netif net;
struct netif* net_get(void){
    return &net;
};
//������·�仯֪ͨ
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

//�����õ�����һ��Ҫʹ��static��ȫ��
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
    ///����1��ʼ����ɻص����� ����2��ʼ����ɻص�����
    tcpip_init(tcpip_init_done_callback,0);

    //sys_thread_new("ttest", ttest, NULL, 512, 5);
}

void lwip_module_poll(void){
    /* �Ƿ���յ����� */
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

        //���е�ַ���� �Ȳ���MACӲ�����˵ķ����ˣ��ȿ��ٳ���
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
