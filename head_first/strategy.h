#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <functional>

namespace HeadFirst::Strategy
{
struct FlyWithWings
{
    void operator()()
    {
        std::cout << "Fly with wings." << std::endl;
    }
};

struct FlyNoWay
{
    void operator()()
    {
        std::cout << "I cannot fly!." << std::endl;
    }
};

class Duck
{
public:
    using FlyBehaviour = std::function<void()>;
    void fly()
    {
        behaviour_();
    }
    void setFlyBehaviour(FlyBehaviour &&behaviour)
    {
        behaviour_ = std::move(behaviour);
    }
    virtual void display() const = 0;

private:
    FlyBehaviour behaviour_ = FlyNoWay{};
};

struct ModelDuck: public Duck
{
    void display() const override
    {
        std::cout << "I am a model duck." << std::endl;
    }
};

void strategyExamples();
}//HeadFirst::Strategy namespace.

#endif //STRATEGY_H


