cmake_minimum_required(VERSION 3.22) # 设置所需的CMake版本

project(UTIL) # 定义项目名称

set(CMAKE_BUILD_TYPE "Debug")

# 指定C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



add_subdirectory(Sort)
add_subdirectory(Design)
add_subdirectory(Log)
add_subdirectory(Thread)
add_subdirectory(TimeStamp)
add_subdirectory(Timer)
add_subdirectory(Memory)



