#include "strategy.h"

namespace HeadFirst::Strategy
{
void strategyExamples()
{
    auto duck = ModelDuck{};
    duck.fly();
    duck.setFlyBehaviour(FlyWithWings{});
    duck.fly();
}
}// HeadFirst::Strategy namespace.
