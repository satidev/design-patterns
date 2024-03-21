#include "iglberger/visitor_gof.h"
#include "iglberger/visitor_variant.h"
#include "iglberger/visitor_acyclic.h"
#include "iglberger/strategy_ref_sem.h"
#include "iglberger/command_ref_sem.h"
#include "iglberger/strategy_val_sem.h"
#include "iglberger/command_val_sem.h"
#include "head_first/strategy.h"
#include "iglberger/adaptor_object.h"
#include "iglberger/adaptor_class.h"
#include "iglberger/adaptor_function.h"
#include "iglberger/observer_push.h"
#include "iglberger/observer_pull.h"
#include "iglberger/crtp.h"
//#include "iglberger/bridge/electric_car.h"
//#include "iglberger/bridge/person.h"
#include "iglberger/prototype.h"
#include "iglberger/decorator_ref.h"
#include "iglberger/decorator_compile_time.h"
#include "iglberger/singleton.h"
//#include "iglberger/extern_polymorph.h"
#include "iglberger/type_erasure.h"
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
    Iglberger::TypeErasure::typeErasureExample();
}

