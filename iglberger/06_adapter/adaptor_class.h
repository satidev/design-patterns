#ifndef ADAPTOR_CLASS_H
#define ADAPTOR_CLASS_H

#include <vector>
#include <iostream>
#include <cassert>

namespace Iglberger::AdaptorClass
{
// Class adaptor where the functionalities of adaptee are inherited.
template<typename T>
// Stack is the adaptor where vector is the adaptee.
class Stack: private std::vector<T>
{
public:
    Stack()
        :
        std::vector<T>{}
    {

    }
    // Target interface.
    T &top()
    {
        return this->back();
    }
    bool isEmpty() const
    {
        return this->empty();
    }
    size_t numElems() const
    {
        return this->size();
    }
    void push(T const &val)
    {
        this->push_back(val);
    }
    void pop()
    {
        this->pop_back();
    }
};
// Client code that uses the target interface.
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

#endif //ADAPTOR_CLASS_H


