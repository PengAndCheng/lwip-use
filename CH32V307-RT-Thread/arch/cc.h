
#ifndef _ARCH_CC_H_
#define _ARCH_CC_H_


typedef int sys_prot_t;

///ʹ��lwip�ṩ��"errno.h"�Ͷ������������Ҫ���������������
#define LWIP_PROVIDE_ERRNO

///��Ҫ����������ο�LWIP_PLATFORM_ASSERT������û�������
///Ŀǰ����LWIP_ERROR�����������
#include <stdio.h>
#include <stdlib.h>
#define LWIP_PLATFORM_DIAG(x) do {printf("DIAG \"%s\" failed at line %d in %s\n", \
        x, __LINE__, __FILE__); } while(0)

#endif /* _ARCH_CC_H_ */
