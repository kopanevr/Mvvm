cmake_minimum_required(VERSION 3.10)
project(Mvvm)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR src)

file(GLOB SOURCE_FILES
    "${SRC_DIR}/*.c"
    "${SRC_DIR}/*.cpp")

add_executable(Mvvm ${SOURCE_FILES})

target_include_directories(Mvvm PUBLIC inc)
