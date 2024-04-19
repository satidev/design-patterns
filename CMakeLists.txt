cmake_minimum_required(VERSION 3.26)
project(design_patterns)

set(CMAKE_CXX_STANDARD 20)

add_executable(design_patterns main.cpp
        iglberger/visitor_gof.h
        iglberger/visitor_gof.cpp
        iglberger/visitor_variant.h
        iglberger/visitor_variant.cpp
        iglberger/visitor_acyclic.h
        iglberger/visitor_acyclic.cpp
        iglberger/05_strategy/strategy_ref_sem.h
        iglberger/05_strategy/strategy_ref_sem.cpp
        iglberger/command_ref_sem.h
        iglberger/command_ref_sem.cpp
        iglberger/05_strategy/strategy_val_sem.h
        iglberger/05_strategy/strategy_val_sem.cpp
        iglberger/command_val_sem.h
        iglberger/command_val_sem.cpp
        iglberger/adaptor_object.h
        iglberger/adaptor_object.cpp
        iglberger/adaptor_class.h
        iglberger/adaptor_class.cpp
        iglberger/adaptor_function.h
        iglberger/adaptor_function.cpp
        iglberger/06_observer/observer_push.h
        iglberger/06_observer/observer_push.cpp
        iglberger/06_observer/observer_pull.h
        iglberger/06_observer/observer_pull.cpp
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
        iglberger/type_erasure.cpp
        iglberger/type_erasure_sbo.h
        iglberger/type_erasure_sbo.cpp
        nesteruk/03_factory/factory_method.h
        nesteruk/03_factory/inner_factory.h
        nesteruk/03_factory/abstract_factory.h)
