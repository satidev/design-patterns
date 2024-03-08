cmake_minimum_required(VERSION 3.26)
project(design_patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(design_patterns main.cpp
        iglberger/visitor_gof.h
        iglberger/visitor_gof.cpp)
