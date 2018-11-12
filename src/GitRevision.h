//
// Created by harcs on 11/11/18.
//

#pragma once

#include "CompilerDefs.h"

namespace GitRevision
{
    char const* GetHash();
    char const* GetDate();
    char const* GetBranch();
    char const* GetCMakeCommand();
    char const* GetCMakeVersion();
    char const* GetHostOSVersion();
    char const* GetBuildDirectory();
    char const* GetSourceDirectory();
    char const* GetFullVersion();
    char const* GetCompanyNameStr();
    char const* GetLegalCopyrightStr();
    char const* GetFileVersionStr();
    char const* GetProductVersionStr();
}
