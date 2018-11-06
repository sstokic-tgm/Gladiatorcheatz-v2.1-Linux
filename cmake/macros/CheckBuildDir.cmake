#
# Force out-of-source build
#

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" BUILDING_IN_SOURCE)

if(BUILDING_IN_SOURCE)
  message("
    This project requires an out of source build.
    You must run cmake in a build directory.

    mkdir build
    cd build

    Then you can proceed to configure and build by using the following commands:

    cd build
    cmake ../

    NOTE: Given that you already tried to make an in-source build.
          CMake have already created several files & directories
          in your source tree. Run 'git status' to find them and
          remove them by doing:

    git clean -n -d
    git clean -f -d
    git checkout --
  ")
  message(FATAL_ERROR "Quitting configuration!")
endif()
