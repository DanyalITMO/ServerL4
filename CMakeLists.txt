cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 17)

add_executable(server main.cpp ServerSocket.cpp ServerSocket.h DataSocket.cpp DataSocket.h Statistic.cpp Statistic.h Helper.cpp Helper.h)