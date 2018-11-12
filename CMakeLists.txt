# We require CMake >= 3.0
cmake_minimum_required(VERSION 3.0)

# Set projectname
project(Gladiatorcheatz_v2.1L)

# set macro-directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros)

# set default buildoptions for git to false
option(WITHOUT_GIT "Disable the GIT testing routines" 0)

# check build-directory and platform
include(CheckBuildDir)
include(CheckPlatform)

# Check if gcc >= 5.2
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.2)
        message(FATAL_ERROR "Your GCC seems outdated.")
    endif()
else()
    message(FATAL_ERROR "You must have GCC >= 5.2 installed in order to compile.")
endif()

# Set compile flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -std=c++14 -Wall -Wno-maybe-uninitialized -Wno-unused-result")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG -std=c++14 -Wall -Wno-maybe-uninitialized -Wno-unused-result")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g -DNDEBUG -std=c++14 -Wall -Wno-maybe-uninitialized -Wno-unused-result")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os -DNDEBUG -std=c++14 -Wall -Wno-maybe-uninitialized -Wno-unused-result")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

# Build in Release-mode by default if not explicitly set
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RELEASE)
endif(NOT CMAKE_BUILD_TYPE)

# Read all files
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

if(NOT WITHOUT_GIT)
    find_package(Git)
endif()

# Find revision ID and hash of the sourcetree
include(cmake/genrev.cmake)

# print out the results before continuing
include(cmake/showoptions.cmake)

# Build library
add_library(Gladiatorcheatz_v21L SHARED ${SOURCE_FILES})

# Set build-directive (used in core to tell which buildtype we used)
target_compile_definitions(Gladiatorcheatz_v21L PRIVATE -D_BUILD_DIRECTIVE="${CMAKE_BUILD_TYPE}")

# include the output directory, where the revision_data.h file is generated
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# a custom target that is always built
add_custom_target(revheader ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/revision_data.h)

# explicitly say that the executable depends on the revheader
add_dependencies(Gladiatorcheatz_v21L revheader)