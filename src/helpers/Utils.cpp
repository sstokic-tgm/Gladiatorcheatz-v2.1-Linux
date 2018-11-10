//
// Created by harcs on 11/10/18.
//

#include "Utils.h"

#include "../common.h"

struct dlinfo_t
{
    const char *library = nullptr;
    uintptr_t address = 0;
    size_t size = 0;
};

std::vector<dlinfo_t> libraries;

namespace Utils
{
    // taken form aixxe's cstrike-basehook-linux
    bool GetLibraryInformation(const char *library, uintptr_t *address, size_t *size)
    {
        if (libraries.size() == 0)
        {
            dl_iterate_phdr([](struct dl_phdr_info* info, size_t, void*)
                    {
                        dlinfo_t library_info = {};

                        library_info.library = info->dlpi_name;
                        library_info.address = info->dlpi_addr + info->dlpi_phdr[0].p_vaddr;
                        library_info.size = info->dlpi_phdr[0].p_memsz;

                        libraries.push_back(library_info);

                        return 0;
                    }, nullptr);
        }

        for(const dlinfo_t &current : libraries)
        {
            if(!strcasestr(current.library, library))
                continue;

            if(address)
                *address = current.address;

            if(size)
                *size = current.size;

            return true;
        }
        return false;
    }

    uint8_t *PatternScan(char *module, const char *signature)
    {
        static auto pattern_to_byte = [](const char *pattern)
        {
            auto bytes = std::vector<int>{};
            auto start = const_cast<char*>(pattern);
            auto end = const_cast<char*>(pattern) + strlen(pattern);

            for(auto current = start; current < end; ++current)
            {
                if(*current == '?')
                {
                    ++current;
                    if(*current == '?')
                        ++current;

                    bytes.push_back(-1);
                }
                else
                {
                    bytes.push_back(strtoul(current, &current, 16));
                }
            }
            return bytes;
        };

        uintptr_t moduleptr = 0;
        size_t sizeOfImage = 0;

        GetLibraryInformation(module, &moduleptr, &sizeOfImage);

        auto patternBytes = pattern_to_byte(signature);
        auto scanBytes = reinterpret_cast<uint8_t*>(moduleptr);

        auto s = patternBytes.size();
        auto d = patternBytes.data();

        for(auto i = 0ul; i < sizeOfImage - s; ++i)
        {
            bool found = true;

            for(auto j = 0ul; j < s; ++j)
            {
                if(scanBytes[i + j] != d[j] && d[j] != -1)
                {
                    found = false;
                    break;
                }
            }
            if(found)
                return &scanBytes[i];
        }
        return nullptr;
    }
}