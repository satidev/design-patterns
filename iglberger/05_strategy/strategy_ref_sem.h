#ifndef STRATEGY_REF_SEM_H
#define STRATEGY_REF_SEM_H

#include <memory>
#include <string>

// Strategy design pattern based on reference semantics using
// pointer-to-base class.
namespace Iglberger::StrategyRefSem
{
struct Shape
{
    virtual ~Shape() = default;

    // We identify draw function as a variation point where the implementation
    // details can change in the future.
    virtual void draw() = 0;

    virtual std::string name() const = 0;
};

// Encapsulate draw function as a strategy base class.
template<typename ShapeType>
struct DrawStrategy
{
    virtual ~DrawStrategy() = default;
    virtual void draw(ShapeType const &shape) = 0;
};

struct Circle final: public Shape
{
    // Dependency injection during construction.
    explicit Circle(std::unique_ptr<DrawStrategy<Circle>> ptr)
        :
        draw_strategy_{std::move(ptr)}
    {}

    void draw() override
    {
        // Delegate to strategy.
        draw_strategy_->draw(*this);
    }

    std::string name() const override
    {
        return std::string{"Circle"};
    }

private:
    // Composition over inheritance.
    std::unique_ptr<DrawStrategy<Circle>> draw_strategy_;
};

struct OpenGLCircleDrawStrategy final: public DrawStrategy<Circle>
{
    void draw(Circle const &shape) override;
};

struct VulkanCircleDrawStrategy final: public DrawStrategy<Circle>
{
    void draw(Circle const &shape) override;
};

struct Square final: public Shape
{
    explicit Square(std::unique_ptr<DrawStrategy<Square>> ptr)
        :
        draw_strategy_{std::move(ptr)}
    {}

    void draw() override;

    std::string name() const override
    {
        return std::string{"Square"};
    }
private:
    std::unique_ptr<DrawStrategy<Square>> draw_strategy_;
};

struct OpenGLSquareDrawStrategy final: public DrawStrategy<Square>
{
    void draw(Square const &shape) override;
};

struct VulkanSquareDrawStrategy final: public DrawStrategy<Square>
{
    void draw(Square const &shape) override;
};

void strategyExamples();

}// Iglberger::StrategyRefSem namespace.


#endif //STRATEGY_REF_SEM_H


