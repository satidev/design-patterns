#include "decorator_compile_time.h"
#include <iostream>

namespace Iglberger::DecoratorValCompileTime
{
void decoratorValueCompileTimeEx()
{
    auto const item = TaxedItem<DiscountedItem<CppBook>>{15.0f,20.0f,
                                     std::string{"Modern C++ design"},
                                     499.0f};
    std::cout << item.money() << std::endl;
}
}
