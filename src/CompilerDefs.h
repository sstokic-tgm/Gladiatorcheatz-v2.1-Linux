//
// Created by harcs on 11/11/18.
//

#pragma once

#define GLAD_PLATFORM_WINDOWS   0
#define GLAD_PLATFORM_UNIX      1
#define GLAD_PLATFORM_APPLE     2
#define GLAD_PLATFORM_INTEL     3

// must be first (win 64 also define _WIN32)
#if defined(_WIN64)
#  define GLAD_PLATFORM GLAD_PLATFORM_WINDOWS
#elif defined(__WIN32__) || defined(WIN32) || defined(_WIN32)
#  define GLAD_PLATFORM GLAD_PLATFORM_WINDOWS
#elif defined(__APPLE_CC__)
#  define GLAD_PLATFORM GLAD_PLATFORM_APPLE
#elif defined(__INTEL_COMPILER)
#  define GLAD_PLATFORM GLAD_PLATFORM_INTEL
#else
#  define GLAD_PLATFORM GLAD_PLATFORM_UNIX
#endif
