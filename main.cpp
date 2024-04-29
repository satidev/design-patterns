#include "iglberger/04_visitor/visitor_gof.h"
#include "iglberger/04_visitor/visitor_variant.h"
#include "iglberger/04_visitor/visitor_acyclic.h"
#include "iglberger/05_strategy/strategy_ref_sem.h"
#include "iglberger/05_command/command_ref_sem.h"
#include "iglberger/05_strategy/strategy_val_sem.h"
#include "iglberger/05_command/command_val_sem.h"
#include "iglberger/06_adapter/adaptor_object.h"
#include "iglberger/06_adapter/adaptor_class.h"
#include "iglberger/06_adapter/adaptor_function.h"
#include "iglberger/06_observer/observer_push.h"
#include "iglberger/06_observer/observer_pull.h"
#include "iglberger/06_crtp/crtp.h"
//#include "iglberger/bridge/electric_car.h"
//#include "iglberger/bridge/person.h"
#include "iglberger/07_prototype/prototype.h"
#include "iglberger/09_decorator/decorator_ref.h"
#include "iglberger/09_decorator/decorator_compile_time.h"
#include "iglberger/10_singleton/singleton.h"
//#include "iglberger/extern_polymorph.h"
#include "iglberger/08_type_erasure/type_erasure.h"
#include "iglberger/08_type_erasure/type_erasure_sbo.h"
#include "nesteruk/03_factory/abstract_factory.h"
int main()
{
    //VisitorGOF::shapeVisitorExamples();
    //VisitorVariant::shapeVisitorExamples();
    //VisitorAcyclic::shapeVisitorExamples();
    //StrategyRefSem::strategyExamples();
    //CommandRefSem::commandExample();
    //StrategyValSem::strategyExamples();
    //Iglberger::CommandValSem::commandExample();
    //HeadFirst::Strategy::strategyExamples();
    //Iglberger::AdaptorClass::adaptorExample();
    //Iglberger::AdaprorFunc::funcAdaptorExample();
    //Iglberger::ObserverPush::observerPullExample();
    //Iglberger::ObserverPull::observerPullEx();
    //Iglberger::CRTP::CRTPExample();
    //Iglberger::PersonPimplEx();
    //Iglberger::Prototype::prototypeEx();
    //Iglberger::itemDecoratorEx();
    //Iglberger::DecoratorValCompileTime::decoratorValueCompileTimeEx();
    //Iglberger::singletonEx();
    //Iglberger::ExternPolymorph::externPolymorphEx();
    //Iglberger::TypeErasure::typeErasureExample();
    //std::cout << alignof(Struct) << std::endl;
    //Iglberger::TypeErasureSBO::typeErasureExample();
    Nesteruk::AbstractFactory::example();
}

