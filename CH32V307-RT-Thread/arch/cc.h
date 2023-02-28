
#ifndef _ARCH_CC_H_
#define _ARCH_CC_H_


typedef int sys_prot_t;

///使用lwip提供的"errno.h"就定义这个，否则要编译器有这个功能
#define LWIP_PROVIDE_ERRNO

#endif /* _ARCH_CC_H_ */
