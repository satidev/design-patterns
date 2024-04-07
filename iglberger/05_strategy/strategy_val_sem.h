#ifndef STRATEGY_VAL_SEM_H
#define STRATEGY_VAL_SEM_H

#include <string>
#include <functional>

// Strategy design pattern using value semantics-based solution
// using std::function.
namespace Iglberger::StrategyValSem
{
// Base class.
struct Shape
{
    virtual ~Shape() = default;
    // We identify the draw function as a variation point where the implementation
    // details can be changed.
    virtual void draw() = 0;
    virtual std::string name() const = 0;
};

struct Circle final: public Shape
{
    // Dependency injection while construction.
    // Passing std::function value not a poiter.
    explicit Circle(std::function<void(Circle const &)> strategy)
        :
        draw_strategy_{std::move(strategy)}
    {}

    void draw() override
    {
        draw_strategy_(*this);
    }

    std::string name() const override
    {
        return std::string{"Circle"};
    }
private:
    std::function<void(Circle const &)> draw_strategy_;
};

struct Square final: public Shape
{
    explicit Square(std::function<void(Square const &)> strategy)
        :
        draw_strategy_{std::move(strategy)}
    {}

    void draw() override
    {
        draw_strategy_(*this);
    }

    std::string name() const override
    {
        return std::string{"Square"};
    }
private:
    std::function<void(Square const &)> draw_strategy_;
};

// Function object.
struct OpenGLCircleDrawStrategy
{
    void operator()(Circle const &circle);
};

struct OpenGLSquareDrawStrategy
{
    void operator()(Square const &circle);
};

//Free function.
void VulkanCircleDrawStrategy(Circle const &circle);
void VulkanSquareDrawStrategy(Square const &circle);

void strategyExamples();

}// Iglberger::StrategyValSem namespace.

#endif //STRATEGY_VAL_SEM_H


