#include "visitor_gof.h"
#include <vector>
#include <memory>

Shape::~Shape() = default;

void Shape::printName() const
{
    std::cout << "Shape" << std::endl;
}

void Circle::printName() const
{
    std::cout << "Circle." << std::endl;
}
void Square::printName() const
{
    std::cout << "Square." << std::endl;
}

void shapeVisitorExamples()
{
    auto shapes = std::vector<std::unique_ptr<Shape>>{};
    shapes.emplace_back(std::make_unique<Circle>());
    shapes.emplace_back(std::make_unique<Square>());

    for(auto const& shape:shapes){
        shape->accept(DrawVisitor{});
        shape->accept(RotateVisitor{});
    }
}