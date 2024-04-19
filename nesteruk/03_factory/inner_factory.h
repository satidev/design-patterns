#ifndef INNER_FACTORY_H
#define INNER_FACTORY_H

#include <cmath>

namespace Nesteruk::InnerFactory
{
struct Point
{
private:
    double x_, y_;

public:
    explicit Point(double x, double y)
        :
        x_{x}, y_{y}
    {}

public:
    struct InnerFactory
    {
        static Point NewCartesian(double x, double y)
        {
            return Point{x, y};
        }

        static Point NewPolar(double radius, double angle_rad)
        {
            return Point{radius * std::cos(angle_rad), radius * std::sin(angle_rad)};
        }
    };

};

void example()
{
    auto const cart = Point::InnerFactory::NewCartesian(2.0, 3.0);
    auto const polar = Point::InnerFactory::NewPolar(1.0, 3.14);
}

}

#endif //INNER_FACTORY_H


