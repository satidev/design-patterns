#include "visitor_acyclic.h"
#include <iostream>
#include <vector>
#include <memory>

namespace VisitorAcyclic
{
void Circle::printName() const
{
    std::cout << "Circle" << std::endl;
}
void Circle::accept(const AbstractVisitor &v)
{
    if(auto const *cv = dynamic_cast<Visitor<Circle> const*>(&v)){
        cv->visit(*this);
    }
}
void Square::printName() const
{
    std::cout << "Square" << std::endl;
}
void Square::accept(const AbstractVisitor &v)
{
    if(auto const *cv = dynamic_cast<Visitor<Square> const*>(&v)){
        cv->visit(*this);
    }
}

void DrawVisitor::visit(Circle const &c) const
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

}// VisitorAcyclic namespace.
