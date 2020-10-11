#pragma once

class IBaseLib
{
public:
    virtual ~IBaseLib() {}
};

class IInheritLib : public IBaseLib
{
public:
    virtual ~IInheritLib() {}
};

IBaseLib* NewInstance();
