#ifndef ADAPTOR_OBJECT_H
#define ADAPTOR_OBJECT_H

#include <vector>
#include <iostream>
#include <cassert>

// Object adaptor where adaptee is a member variable.
// We are realizing stack data structure by using stl vector under the hood.
namespace Iglberger::AdaptorObject
{
// Stack is adaptor class.
template<typename T>
class Stack
{
private:
    // STL vector is the adaptee.
    std::vector<T> vec_ = std::vector<T>{};

public:
    Stack() = default;

    // The following functionalities are the target interface.
    T &top()
    {
        return vec_.back();
    }
    bool empty() const
    {
        return vec_.empty();
    }
    size_t size() const
    {
        return vec_.size();
    }
    void push(T const &val)
    {
        vec_.push_back(val);
    }
    void pop()
    {
        vec_.pop_back();
    }
};
// Client code that expects the target interface.
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
}// Iglberger::AdaptorObject namespace.

#endif //ADAPTOR_OBJECT_H


