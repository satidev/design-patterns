cmake_minimum_required(VERSION 3.26)
project(design_patterns)

set(CMAKE_CXX_STANDARD 20)

add_executable(design_patterns main.cpp
        iglberger/04_visitor/visitor_gof.h
        iglberger/04_visitor/visitor_gof.cpp
        iglberger/04_visitor/visitor_variant.h
        iglberger/04_visitor/visitor_variant.cpp
        iglberger/04_visitor/visitor_acyclic.h
        iglberger/04_visitor/visitor_acyclic.cpp
        iglberger/05_strategy/strategy_ref_sem.h
        iglberger/05_strategy/strategy_ref_sem.cpp
        iglberger/05_command/command_ref_sem.h
        iglberger/05_command/command_ref_sem.cpp
        iglberger/05_strategy/strategy_val_sem.h
        iglberger/05_strategy/strategy_val_sem.cpp
        iglberger/05_command/command_val_sem.h
        iglberger/05_command/command_val_sem.cpp
        iglberger/06_adapter/adaptor_object.h
        iglberger/06_adapter/adaptor_class.h
        iglberger/06_adapter/adaptor_function.h
        iglberger/06_observer/observer_push.h
        iglberger/06_observer/observer_push.cpp
        iglberger/06_observer/observer_pull.h
        iglberger/06_observer/observer_pull.cpp
        iglberger/06_crtp/crtp.h
        iglberger/06_crtp/crtp.cpp
        iglberger/07_bridge/abstract_engine.h
        iglberger/07_bridge/electric_engine.h
        iglberger/07_bridge/electric_car.h
        iglberger/07_bridge/electric_car.cpp
        iglberger/07_bridge/car.h
        iglberger/07_bridge/person.h
        iglberger/07_bridge/person.cpp
        iglberger/07_prototype/prototype.h
        iglberger/07_prototype/prototype.cpp
        iglberger/09_decorator/decorator_ref.h
        iglberger/09_decorator/decorator_ref.cpp
        iglberger/09_decorator/decorator_compile_time.h
        iglberger/09_decorator/decorator_compile_time.cpp
        iglberger/10_singleton/singleton.h
        iglberger/07_extern_poly/extern_polymorph.h
        iglberger/07_extern_poly/extern_polymorph.cpp
        iglberger/08_type_erasure/type_erasure.h
        iglberger/08_type_erasure/type_erasure.cpp
        iglberger/08_type_erasure/type_erasure_sbo.h
        iglberger/08_type_erasure/type_erasure_sbo.cpp
        nesteruk/03_factory/factory_method.h
        nesteruk/03_factory/inner_factory.h
        nesteruk/03_factory/abstract_factory.h
)
