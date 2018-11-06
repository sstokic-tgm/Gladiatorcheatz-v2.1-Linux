#pragma once

#define GetProcAddress dlsym

using CreateInterfaceFn = void*(*)(const char *pName, int *pReturnCode);
using InstantiateInterfaceFn = void*(*)();

class InterfaceReg
{
public:
    InstantiateInterfaceFn m_CreateFn;
    const char *m_pName;

    InterfaceReg *m_pNext;
};
