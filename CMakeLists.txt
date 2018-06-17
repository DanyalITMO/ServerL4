cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 17)


set(SOURCES
        source/Helper.cpp
        source/main.cpp
        source/Statistic.cpp
)
include_directories(include)

add_executable(server ${SOURCES})
target_link_libraries(server network)