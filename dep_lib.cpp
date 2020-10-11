#include "dep_lib.h"
#include "base_lib.h"
#include <stdio.h>

void init()
{
    IBaseLib* pBase = NewInstance();
    IInheritLib* pInherit = dynamic_cast<IInheritLib*>(pBase);
    printf("pBase=%p, pInherit=%p\n", pBase, pInherit);
}