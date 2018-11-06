#pragma once

#include <cstdint>

class ShadowVTManager
{
public:
    ShadowVTManager() : class_base(nullptr), method_count(0), shadow_vtable(nullptr), original_vtable(nullptr) {}
    ShadowVTManager(void *base) : class_base(base), method_count(0), shadow_vtable(nullptr), original_vtable(nullptr) {}
    ~ShadowVTManager()
    {
        RestoreTable();
        delete[] shadow_vtable;
    }

    inline void Setup(void *base = nullptr)
    {
        if(base != nullptr)
            class_base = base;

        if(class_base == nullptr) return;

        original_vtable = *(uintptr_t**)class_base;
        method_count = GetMethodCount(original_vtable);

        if(method_count == 0) return;

        shadow_vtable = new uintptr_t[method_count + 1]();

        shadow_vtable[0] = original_vtable[-1];
        std::memcpy(&shadow_vtable[1], original_vtable, method_count * sizeof(uintptr_t));

        *(uintptr_t**)class_base = &shadow_vtable[1];
    }

    template <typename T>
    inline void Hook(uint32_t index, T method)
    {
        assert(index < method_count);
        shadow_vtable[index + 1] = reinterpret_cast<uintptr_t>(method);
    }

    inline void Unhook(uint32_t index)
    {
        assert(index < method_count);
        shadow_vtable[index + 1] = original_vtable[index];
    }

    template <typename T>
    inline T GetOriginal(uint32_t index)
    {
        return reinterpret_cast<T>(original_vtable[index]);
    }

    inline void RestoreTable()
    {
        *(uintptr_t**)class_base = original_vtable;
        original_vtable = nullptr;
    }

private:
    inline uint32_t GetMethodCount(uintptr_t *vtable_start)
    {
        uint32_t len = -1;

        do ++len; while (vtable_start[len]);

        return len;
    }

    void *class_base;
    uint32_t method_count;
    uintptr_t *shadow_vtable;
    uintptr_t *original_vtable;
};
