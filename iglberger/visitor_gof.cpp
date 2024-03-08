#include "visitor_gof.h"
#include <vector>
#include <memory>

namespace VisitorGOF
{
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

    for (auto const &shape: shapes) {
        shape->accept(DrawVisitor{});
        shape->accept(RotateVisitor{});
    }
}

void DrawVisitor::visit(const Circle &c) const
{
    std::cout << "Drawing";
    c.printName();
}
void DrawVisitor::visit(const Square &s) const
{
    std::cout << "Drawing";
    s.printName();
}
void RotateVisitor::visit(const Circle &c) const
{
    std::cout << "Rotating";
    c.printName();
}
void RotateVisitor::visit(const Square &s) const
{
    std::cout << "Rotating";
    s.printName();
}

}// VisitorGOF namespace.