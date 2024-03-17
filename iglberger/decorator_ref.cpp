#include "decorator_ref.h"
#include <iostream>

namespace Iglberger
{
void itemDecoratorEx()
{
    auto item_1 = std::make_unique<TaxedItem>(
        std::make_unique<Book>("Modern C++ design", 19.0f),
        7.0);
    std::cout << item_1->money() << std::endl;

    auto item_2 = std::make_unique<TaxedItem>(
        std::make_unique<DiscountedItem>(
            std::make_unique<ConferenceTicket>("Cppcon", 999.0f), 20.0f),
        19.0f);
    std::cout << item_2->money() << std::endl;
}
}
