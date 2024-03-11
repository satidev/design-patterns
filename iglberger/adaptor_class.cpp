#include "adaptor_class.h"
#include <iostream>
#include <cassert>

namespace Iglberger::AdaptorClass
{
void adaptorExample()
{
    auto stack = Stack<int>{};
    stack.push(100);
    stack.push(2);

    // Iterate through the stack
    while (!stack.isEmpty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
    assert(stack.numElems() == 0u);
}

}// Iglberger::AdaptorClass namespace.
