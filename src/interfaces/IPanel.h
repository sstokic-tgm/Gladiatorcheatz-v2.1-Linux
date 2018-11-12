#pragma once

class IPanel
{
public:
    const char *GetName(unsigned int vguiPanel)
    {
        typedef const char *(* tGetName)(void*, unsigned int);
        return vfunc<tGetName>(this, 37)(this, vguiPanel);
    }
#ifdef GetClassName
#undef GetClassName
#endif
    const char *GetClassName(unsigned int vguiPanel)
    {
        typedef const char *(* tGetClassName)(void*, unsigned int);
        return vfunc<tGetClassName>(this, 38)(this, vguiPanel);
    }
};
