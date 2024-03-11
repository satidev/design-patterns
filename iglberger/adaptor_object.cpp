#include "adaptor_object.h"
#include <iostream>
#include <cassert>

namespace Iglberger::AdaptorObject
{
void adaptorExample()
{
    auto stack = Stack<int>{};
    stack.push(100);
    stack.push(2);

    // Iterate through the stack
    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
    assert(stack.size() == 0u);
}

}//Iglberger::Adaptor namespace.
