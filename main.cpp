#include "iglberger/visitor_gof.h"
#include "iglberger/visitor_variant.h"
#include "iglberger/visitor_acyclic.h"
int main()
{
    VisitorGOF::shapeVisitorExamples();
    VisitorVariant::shapeVisitorExamples();
    VisitorAcyclic::shapeVisitorExamples();
}

