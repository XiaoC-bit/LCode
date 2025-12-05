cmake_minimum_required(VERSION 3.15)
project(leetcode CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows MinGW 下编译优化等
if (MINGW)
    add_compile_options(-Wall -Wextra -O2)
endif()

# include 与 src 下的公共代码
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB COMMON_SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)

# 自动扫描 problems 下所有子目录
file(GLOB PROBLEM_DIRS RELATIVE ${PROJECT_SOURCE_DIR}/problems
    ${PROJECT_SOURCE_DIR}/problems/*)

foreach(dir ${PROBLEM_DIRS})
    if (IS_DIRECTORY "${PROJECT_SOURCE_DIR}/problems/${dir}")
        add_subdirectory(problems/${dir})
    endif()
endforeach()
