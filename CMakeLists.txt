cmake_minimum_required(VERSION 3.26)
project(design_patterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(design_patterns main.cpp
        iglberger/visitor_gof.h
        iglberger/visitor_gof.cpp
        iglberger/visitor_variant.h
        iglberger/visitor_variant.cpp
        iglberger/visitor_acyclic.h
        iglberger/visitor_acyclic.cpp
        iglberger/strategy_ref_sem.h
        iglberger/strategy_ref_sem.cpp
        iglberger/command_ref_sem.h
        iglberger/command_ref_sem.cpp
        iglberger/strategy_val_sem.h
        iglberger/strategy_val_sem.cpp
        iglberger/command_val_sem.h
        iglberger/command_val_sem.cpp)
