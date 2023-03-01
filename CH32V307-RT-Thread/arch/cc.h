
#ifndef _ARCH_CC_H_
#define _ARCH_CC_H_


typedef int sys_prot_t;

///使用lwip提供的"errno.h"就定义这个，否则要编译器有这个功能
#define LWIP_PROVIDE_ERRNO

///需要定义这个，参考LWIP_PLATFORM_ASSERT，否则没有输出，
///目前发现LWIP_ERROR依赖这个定义
#include <stdio.h>
#include <stdlib.h>
#define LWIP_PLATFORM_DIAG(x) do {printf("DIAG \"%s\" failed at line %d in %s\n", \
        x, __LINE__, __FILE__); } while(0)

#endif /* _ARCH_CC_H_ */
