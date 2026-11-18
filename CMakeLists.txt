cmake_minimum_required(VERSION 3.16)

project(test C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

#CPM.cmake
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake)

#顺序有意义
add_subdirectory(Func)
add_subdirectory(Core)
