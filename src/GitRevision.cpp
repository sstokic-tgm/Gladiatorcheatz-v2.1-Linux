//
// Created by harcs on 11/11/18.
//

#include "GitRevision.h"
#include "revision_data.h"

char const* GitRevision::GetHash()
{
    return _HASH;
}

char const* GitRevision::GetDate()
{
    return _DATE;
}

char const* GitRevision::GetBranch()
{
    return _BRANCH;
}

char const* GitRevision::GetCMakeCommand()
{
    return _CMAKE_COMMAND;
}

char const* GitRevision::GetCMakeVersion()
{
    return _CMAKE_VERSION;
}

char const* GitRevision::GetHostOSVersion()
{
    return _CMAKE_HOST_SYSTEM;
}

char const* GitRevision::GetBuildDirectory()
{
    return _BUILD_DIRECTORY;
}

char const* GitRevision::GetSourceDirectory()
{
    return _SOURCE_DIRECTORY;
}

#if GLAD_PLATFORM == GLAD_PLATFORM_WINDOWS
#  ifdef _WIN64
#    define GLAD_PLATFORM_STR "Win64"
#  else
#    define GLAD_PLATFORM_STR "Win32"
#  endif
#elif GLAD_PLATFORM == GLAD_PLATFORM_APPLE
#  define GLAD_PLATFORM_STR "MacOSX"
#elif GLAD_PLATFORM == GLAD_PLATFORM_INTEL
#  define GLAD_PLATFORM_STR "Intel"
#else // GLAD_PLATFORM_UNIX
#  define GLAD_PLATFORM_STR "Unix"
#endif

#ifndef GLAD_API_USE_DYNAMIC_LINKING
#  define GLAD_LINKAGE_TYPE_STR "Static"
#else
#  define GLAD_LINKAGE_TYPE_STR "Dynamic"
#endif

char const* GitRevision::GetFullVersion()
{
    return "Gladiatorcheatz rev. " VER_PRODUCTVERSION_STR  " (" GLAD_PLATFORM_STR ", " _BUILD_DIRECTIVE ", " GLAD_LINKAGE_TYPE_STR ")";
}

char const* GitRevision::GetCompanyNameStr()
{
    return VER_COMPANYNAME_STR;
}

char const* GitRevision::GetLegalCopyrightStr()
{
    return VER_LEGALCOPYRIGHT_STR;
}

char const* GitRevision::GetFileVersionStr()
{
    return VER_FILEVERSION_STR;
}

char const* GitRevision::GetProductVersionStr()
{
    return VER_PRODUCTVERSION_STR;
}