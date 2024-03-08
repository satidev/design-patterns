#ifndef VISITOR_GOF_H
#define VISITOR_GOF_H

#include <iostream>

namespace VisitorGOF
{

class Circle;
class Square;

class ShapeVisitor
{
public:
    virtual void visit(Circle const &c) const = 0;
    virtual void visit(Square const &c) const = 0;
};

class Shape
{
public:
    virtual ~Shape() = 0;
    virtual void printName() const = 0;
    virtual void accept(ShapeVisitor const& v) = 0;
};

class Circle final: public Shape
{
public:
    ~Circle() override = default;
    void printName() const override;
    void accept(ShapeVisitor const &v) override{
        v.visit(*this);
    }
};

class Square final: public Shape
{
public:
    ~Square() override = default;
    void printName() const override;
    void accept(ShapeVisitor const &v) override{
        v.visit(*this);
    }
};

class DrawVisitor final: public ShapeVisitor
{
public:
    void visit(Circle const &c) const override{
        std::cout << "Drawing ";
        c.printName();
    }
    void visit(Square const &c) const override{
        std::cout << "Drawing ";
        c.printName();
    }
};

class RotateVisitor final: public ShapeVisitor
{
public:
    void visit(Circle const &c) const override{
        std::cout << "Rotating ";
        c.printName();
    }
    void visit(Square const &c) const override{
        std::cout << "Rotating ";
        c.printName();
    }
};

void shapeVisitorExamples();

}// VisitorGOF namespace.


#endif //VISITOR_GOF_H


