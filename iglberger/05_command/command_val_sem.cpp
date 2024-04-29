#include "command_val_sem.h"
#include <iostream>

namespace Iglberger::CommandValSem
{
void Scale::operator()(Image &img) const
{
    std::cout << "Scaling image with factor " << scale_fact_ << "." <<std::endl;
}
void Rotate::operator()(Image &img) const
{
    std::cout << "Rotating image." << std::endl;
}

void commandExample()
{
    auto proc = ImageProcessor{};
    proc.addCommand(Scale{3.0f});
    proc.addCommand(Rotate{});
    auto img = Image{};
    proc.run(img);
}
}// Iglberger::CommandValSem namespace.
