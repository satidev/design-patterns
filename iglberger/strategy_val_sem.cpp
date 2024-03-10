#include "strategy_val_sem.h"
#include <iostream>
#include <memory>

namespace Iglberger::StrategyValSem
{

void OpenGLCircleDrawStrategy::operator()(const Circle &circle)
{
    std::cout << "Drawing " << circle.name() << " using OpenGL." << std::endl;
}

void VulkanCircleDrawStrategy(Circle const &circle)
{
    std::cout << "Drawing " << circle.name() << " using Vulkan." << std::endl;
}

void VulkanSquareDrawStrategy(Square const &circle)
{
    std::cout << "Drawing " << circle.name() << " using Vulkan." << std::endl;
}

void strategyExamples()
{
    auto shapes = std::vector<std::unique_ptr<Shape>>{};
    shapes.emplace_back(std::make_unique<Circle>(OpenGLCircleDrawStrategy{}));
    shapes.emplace_back(std::make_unique<Circle>(VulkanCircleDrawStrategy));
    shapes.emplace_back(std::make_unique<Circle>([](Circle const &circle)
                                                 {
                                                     std::cout << "Drawing " << circle.name()
                                                               << " using Metal." << std::endl;
                                                 }
    ));

    shapes.emplace_back(std::make_unique<Square>(OpenGLSquareDrawStrategy{}));
    shapes.emplace_back(std::make_unique<Square>(VulkanSquareDrawStrategy));
    shapes.emplace_back(std::make_unique<Square>([](Square const &square)
                                                 {
                                                     std::cout << "Drawing " << square.name()
                                                               << " using Metal." << std::endl;
                                                 }
    ));

    for (auto const &shape: shapes)
        shape->draw();
}
void OpenGLSquareDrawStrategy::operator()(const Square &circle)
{
    std::cout << "Drawing " << circle.name() << " using OpenGL." << std::endl;
}
}// Iglberger::StrategyValSem namespace.