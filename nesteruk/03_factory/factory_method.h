#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

#include <cmath>

namespace Nesteruk::FactoryMethod
{
struct Point
{
    double x, y;
};

struct PointFactory
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

void example()
{
    auto const cart = PointFactory::NewCartesian(2.0, 3.0);
    auto const polar = PointFactory::NewPolar(1.0, 3.14);
}

}

#endif //FACTORY_METHOD_H


