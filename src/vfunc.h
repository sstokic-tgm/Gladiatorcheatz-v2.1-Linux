#pragma once

template <typename T>
__attribute__((always_inline)) inline T vfunc(void *base, int index)
{
    uintptr_t *vTable = *(uintptr_t**)base;
    return (T)vTable[index];
}
