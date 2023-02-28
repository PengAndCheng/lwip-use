

#include "sys_arch.h"

sys_prot_t sys_arch_protect(void){
    //return rt_hw_interrupt_disable();
    return 1234;
}

void sys_arch_unprotect(sys_prot_t pval){
    //rt_hw_interrupt_enable(pval);
}

u32_t sys_now(void){
    extern unsigned int app_tick_get(void);
    return app_tick_get();
}
