#include "electric_car.h"
#include "electric_engine.h"

namespace Iglberger
{
ElectricCar::ElectricCar()
    :
    AbstractCar{std::make_unique<ElectricEngine>()}
{

}

void bridgePimplEx()
{
    auto e = ElectricCar{};
    e.drive();
}
}
