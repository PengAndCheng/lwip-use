
#ifndef _SYS_ARCH_H_
#define _SYS_ARCH_H_

///依赖一些typedef
#include "arch/cc.h"
#include "lwip/arch.h"

///lwip/sys.h中有要求对这两个函数进行实现要求，非操作系统就使用开关中断吧
extern sys_prot_t sys_arch_protect(void);
extern void sys_arch_unprotect(sys_prot_t pval);

extern u32_t sys_now(void);

#endif /* _SYS_ARCH_H_ */
