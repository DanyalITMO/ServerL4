cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 17)


set(SOURCES
    source/DataSocket.cpp
    source/Helper.cpp
    source/main.cpp
    source/ServerSocket.cpp
    source/Statistic.cpp
)
include_directories(include)

add_executable(server ${SOURCES})