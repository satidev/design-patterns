#include "adaptor_function.h"
#include <iostream>
#include <cassert>

namespace Iglberger::AdaprorFunc
{
void funcAdaptorExample()
{
    auto const vec = std::vector<float>(5u, 1.0f);
    auto const img = Image{5u, 1.0f};
    assert(sumElems(vec) == sumElems(img));
}

}// Iglberger::AdaprorFunc namespace.
