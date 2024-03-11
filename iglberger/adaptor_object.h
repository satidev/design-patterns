#ifndef ADAPTOR_OBJECT_H
#define ADAPTOR_OBJECT_H

#include <vector>

namespace Iglberger::AdaptorObject
{
template<typename T>
class Stack
{
public:
    Stack() = default;

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

private:
    std::vector<T> vec_ = std::vector<T>{};
};

void adaptorExample();
}// Iglberger::AdaptorObject namespace.

#endif //ADAPTOR_OBJECT_H


