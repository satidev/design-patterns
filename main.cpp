#include "iglberger/visitor_gof.h"
#include "iglberger/visitor_variant.h"
#include "iglberger/visitor_acyclic.h"
#include "iglberger/05_strategy/strategy_ref_sem.h"
#include "iglberger/command_ref_sem.h"
#include "iglberger/05_strategy/strategy_val_sem.h"
#include "iglberger/command_val_sem.h"
#include "iglberger/06_adapter/adaptor_object.h"
#include "iglberger/06_adapter/adaptor_class.h"
#include "iglberger/06_adapter/adaptor_function.h"
#include "iglberger/06_observer/observer_push.h"
#include "iglberger/06_observer/observer_pull.h"
#include "iglberger/crtp.h"
//#include "iglberger/bridge/electric_car.h"
//#include "iglberger/bridge/person.h"
#include "iglberger/prototype.h"
#include "iglberger/decorator_ref.h"
#include "iglberger/decorator_compile_time.h"
#include "iglberger/singleton.h"
//#include "iglberger/extern_polymorph.h"
#include "iglberger/type_erasure.h"
#include "iglberger/type_erasure_sbo.h"
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

