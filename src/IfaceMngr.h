//
// Created by harcs on 11/7/18.
//

#pragma once

#include "Singleton.h"

class IfaceMngr : public Singleton<IfaceMngr>
{
public:
    template<typename T>
    T *getIface(const char *modName, const char *ifaceName, bool exact = false)
    {
        T *iface = nullptr;
        InterfaceReg *ifaceRegList;
        int partMatchLen = strlen(ifaceName);

        void *library = dlopen(modName, RTLD_NOLOAD | RTLD_NOW | RTLD_LOCAL);
        if(!library)
            return nullptr;

        void *ifaceFn = dlsym(library, "s_pInterfaceRegs");
        if(!ifaceFn)
        {
            dlclose(library);
            return nullptr;
        }

        dlclose(library);

        ifaceRegList = *reinterpret_cast<InterfaceReg**>(ifaceFn);

        for(InterfaceReg *cur = ifaceRegList; cur; cur = cur->m_pNext)
        {
            if(exact)
            {
                if(strcmp(cur->m_pName, ifaceName) == 0)
                    iface = reinterpret_cast<T*>(cur->m_CreateFn());
            }
            else
            {
                if(!strncmp(cur->m_pName, ifaceName, partMatchLen) && atoi(cur->m_pName + partMatchLen) > 0)
                    iface = reinterpret_cast<T*>(cur->m_CreateFn());
            }
        }
        return iface;
    }
};