#include "strategy_ref_sem.h"
#include <iostream>
#include <vector>

namespace StrategyRefSem
{
void Circle::draw()
{
    draw_strategy_->draw(*this);
}
void OpenGLCircleDrawStrategy::draw(const Circle &shape)
{
    std::cout << "Drawing " << shape.name() << " using OpenGL." << std::endl;
}

void VulkanCircleDrawStrategy::draw(const Circle &shape)
{
    std::cout << "Drawing " << shape.name() << " using Vulkan." << std::endl;
}

void OpenGLSquareDrawStrategy::draw(const Square &shape)
{
    std::cout << "Drawing " << shape.name() << " using OpenGL." << std::endl;
}
void VulkanSquareDrawStrategy::draw(const Square &shape)
{
    std::cout << "Drawing " << shape.name() << " using Vulkan." << std::endl;
}

void Square::draw()
{
    draw_strategy_->draw(*this);
}

void strategyExamples()
{
    auto shapes = std::vector<std::unique_ptr<Shape>>{};
    shapes.emplace_back(std::make_unique<Circle>(std::make_unique<OpenGLCircleDrawStrategy>()));
    shapes.emplace_back(std::make_unique<Circle>(std::make_unique<VulkanCircleDrawStrategy>()));
    shapes.emplace_back(std::make_unique<Square>(std::make_unique<OpenGLSquareDrawStrategy>()));
    shapes.emplace_back(std::make_unique<Square>(std::make_unique<VulkanSquareDrawStrategy>()));

    for (auto const &shape: shapes)
        shape->draw();
}
} //StrategyRefSem namespace.
