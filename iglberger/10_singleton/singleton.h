#ifndef SINGLETON_H
#define SINGLETON_H

#include <cassert>

namespace Iglberger
{
struct Singleton final
{
// Private constructor.
private:
    Singleton(){}

public:
    // Access point to unique instance.
    static Singleton& getInstance(){
        static Singleton inst{};// Thread-safe from C++11.
        return inst;
    }

    // Delete all copy and move operations.
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton& operator=(Singleton &&) = delete;
};

void singletonEx()
{
    auto& inst1 = Singleton::getInstance();
    auto& inst2 = Singleton::getInstance();
    assert(&inst1 == &inst2);
}
}// Iglberger namespace.

#endif //SINGLETON_H