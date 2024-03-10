#include "iglberger/visitor_gof.h"
#include "iglberger/visitor_variant.h"
#include "iglberger/visitor_acyclic.h"
#include "iglberger/strategy_ref_sem.h"
#include "iglberger/command_ref_sem.h"
#include "iglberger//strategy_val_sem.h"
int main()
{
    //VisitorGOF::shapeVisitorExamples();
    //VisitorVariant::shapeVisitorExamples();
    //VisitorAcyclic::shapeVisitorExamples();
    //StrategyRefSem::strategyExamples();
    //CommandRefSem::commandExample();
    StrategyValSem::strategyExamples();
}

