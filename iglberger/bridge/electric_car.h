#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

#include "abstract_engine.h"
#include <iostream>
#include <iostream>

#include "car.h"

namespace Iglberger
{
struct ElectricCar: public AbstractCar
{
public:
    ElectricCar();
    void drive() override{
        std::cout << "Driving." << std::endl;
    }
};
void bridgePimplEx();
}

#endif //ELECTRIC_CAR_H

