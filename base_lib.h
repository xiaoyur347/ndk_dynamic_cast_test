#pragma once

#define CLASS_EXPORT __attribute__((visibility("default")))

#define BASE_LIB_IN_HEADER 1
#define INHERIT_LIB_IN_HEADER 1

class CLASS_EXPORT IBaseLib
{
public:
    virtual ~IBaseLib()
#if BASE_LIB_IN_HEADER == 1
    {}
#else
    ;
#endif
};

class CLASS_EXPORT IInheritLib : public IBaseLib
{
public:
    virtual ~IInheritLib()
#if INHERIT_LIB_IN_HEADER == 1
    {}
#else
    ;
#endif
};

IBaseLib* CLASS_EXPORT NewInstance();
