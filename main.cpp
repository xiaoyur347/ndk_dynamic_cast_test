#include "dep_lib.h"
#include <dlfcn.h>

typedef void (*func_ptr)();

void do_dlopen()
{
    void *pBase = dlopen("libbase_lib.so", RTLD_LOCAL);
    (void)pBase;
    void *pDep = dlopen("libdep_lib.so", RTLD_LOCAL);
    func_ptr ptr = (func_ptr)dlsym(pDep, "init");
    (*ptr)();
}

int main()
{
    do_dlopen();
    return 0;
}