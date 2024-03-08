#ifndef VISITOR_VARIANT_H
#define VISITOR_VARIANT_H

namespace VisitorVariant
{
// No base class for shapes
struct Circle
{
    void printName() const;
};

struct Square
{
    void printName() const;
};

struct Draw
{
    void operator()(Circle const &c);
    void operator()(Square const &s);
};

struct Rotate
{
    void operator()(Circle const &c);
    void operator()(Square const &s);
};

void shapeVisitorExamples();

}// VisitorVariant namespace.

#endif //VISITOR_VARIANT_H


