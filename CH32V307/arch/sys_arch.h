
#ifndef _SYS_ARCH_H_
#define _SYS_ARCH_H_

///����һЩtypedef
#include "arch/cc.h"
#include "lwip/arch.h"

///lwip/sys.h����Ҫ�����������������ʵ��Ҫ�󣬷ǲ���ϵͳ��ʹ�ÿ����жϰ�
extern sys_prot_t sys_arch_protect(void);
extern void sys_arch_unprotect(sys_prot_t pval);

extern u32_t sys_now(void);

#endif /* _SYS_ARCH_H_ */
