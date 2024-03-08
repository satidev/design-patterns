cmake_minimum_required(VERSION 3.26)
project(design_patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(design_patterns main.cpp
        visitor_gof.h
        visitor_gof.cpp)
