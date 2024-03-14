#include "crtp.h"
#include <cassert>

namespace Iglberger::CRTP
{
void CRTPExample()
{
    auto dv = DynamicVector<int>{2u};
    dv[0] = 1;
    dv[1] = 2;
    assert(sum(dv) == 3);

    auto sv = StaticVector<int, 2U>{2u};
    sv[0] = 1;
    sv[1] = 2;
    assert(sum(sv) == 3);
    print(sv);
}

}// Iglberger::CRTP namespace.
