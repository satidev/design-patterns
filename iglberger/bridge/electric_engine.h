#ifndef ELECTRIC_ENGINE_H
#define ELECTRIC_ENGINE_H

#include "abstract_engine.h"

#include <iostream>

namespace Iglberger
{
struct ElectricEngine: public AbstractEngine
{
    void start() const override
    {
        std::cout << "Engine started" << std::endl;
    }
    void stop() const override
    {
        std::cout << "Engine stopped" << std::endl;
    }
};

}

#endif //ELECTRIC_ENGINE_H


