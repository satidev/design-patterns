#include "visitor_variant.h"
#include <iostream>
#include <variant>
#include <vector>

namespace Iglberger::VisitorVariant
{
void Circle::printName() const
{
    std::cout << "Circle" << std::endl;
}
void Square::printName() const
{
    std::cout << "Square" << std::endl;
}
void Draw::operator()(const Circle &c)
{
    std::cout << "Drawing";
    c.printName();
}
void Draw::operator()(const Square &s)
{
    std::cout << "Drawing";
    s.printName();
}

void Rotate::operator()(const Circle &c)
{
    std::cout << "Rotating";
    c.printName();
}
void Rotate::operator()(const Square &s)
{
    std::cout << "Rotating";
    s.printName();
}

void shapeVisitorExamples()
{
    using Shape = std::variant<Circle, Square>;

    auto shapes = std::vector<Shape>{};
    shapes.emplace_back(Circle{});
    shapes.emplace_back(Square{});

    for (auto const &shape: shapes) {
        std::visit(Draw{}, shape);
        std::visit(Rotate{}, shape);
    }
}

}// Iglberger::VisitorVariant.
