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
        iglberger/command_val_sem.cpp
        head_first/strategy.h
        head_first/strategy.cpp
        iglberger/adaptor_object.h
        iglberger/adaptor_object.cpp
        iglberger/adaptor_class.h
        iglberger/adaptor_class.cpp
        iglberger/adaptor_function.h
        iglberger/adaptor_function.cpp
        iglberger/observer_push.h
        iglberger/observer_push.cpp
        iglberger/observer_pull.h
        iglberger/observer_pull.cpp
        iglberger/crtp.h
        iglberger/crtp.cpp
        iglberger/bridge/abstract_engine.h
        iglberger/bridge/electric_engine.h
        iglberger/bridge/electric_car.h
        iglberger/bridge/electric_car.cpp
        iglberger/bridge/car.h
        iglberger/bridge/person.h
        iglberger/bridge/person.cpp
        iglberger/prototype.h
        iglberger/prototype.cpp
        iglberger/decorator_ref.h
        iglberger/decorator_ref.cpp
        iglberger/decorator_compile_time.h
        iglberger/decorator_compile_time.cpp
        iglberger/singleton.h
        iglberger/singleton.cpp
        iglberger/extern_polymorph.h
        iglberger/extern_polymorph.cpp
        iglberger/type_erasure.h
        iglberger/type_erasure.cpp)
