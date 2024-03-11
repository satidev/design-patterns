#ifndef ADAPTOR_CLASS_H
#define ADAPTOR_CLASS_H

#include <vector>

namespace Iglberger::AdaptorClass
{
template<typename T>
class Stack: private std::vector<T>
{
public:
    Stack()
        :
        std::vector<T>{}
    {

    }
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

void adaptorExample();
}// Iglberger::AdaptorClass namespace.

#endif //ADAPTOR_CLASS_H


