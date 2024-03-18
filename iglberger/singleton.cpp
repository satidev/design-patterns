#include "singleton.h"
#include <cassert>

namespace Iglberger
{
void singletonEx()
{
    auto& inst1 = Singleton::getInstance();
    auto& inst2 = Singleton::getInstance();

    assert(&inst1 == &inst2);
}
}// Iglberger namespace.