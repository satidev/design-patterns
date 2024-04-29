#include "prototype.h"
#include <iostream>

namespace Iglberger::Prototype
{
std::unique_ptr<Pet> Sheep::clone()
{
    return std::make_unique<Sheep>(*this);
}

void prototypeEx()
{
    auto pet = Sheep{"sally"};
    std::cout << pet.getName() << std::endl;
    pet.setName("Dolly");
    auto clone = pet.clone();
    std::cout << clone->getName() << std::endl;

}
}
