//
// Created by harcs on 11/10/18.
//

#pragma once

#include <cstdint>
#include <cstdio>

namespace Utils
{
    bool GetLibraryInformation(const char *library, uintptr_t *address, size_t *size);
    uint8_t *PatternScan(char *module, const char *signature);
}