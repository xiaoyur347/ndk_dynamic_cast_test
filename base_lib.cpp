#include "base_lib.h"

#if BASE_LIB_IN_HEADER == 0
IBaseLib::~IBaseLib()
{
}
#endif

#if INHERIT_LIB_IN_HEADER == 0
IInheritLib::~IInheritLib()
{
}
#endif

class RealLib: public IInheritLib
{
};

IBaseLib* NewInstance()
{
    return new RealLib();
}