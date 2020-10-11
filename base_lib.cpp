#include "base_lib.h"

class RealLib: public IInheritLib
{
};

IBaseLib* NewInstance()
{
    return new RealLib();
}