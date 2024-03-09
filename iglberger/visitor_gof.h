#ifndef VISITOR_GOF_H
#define VISITOR_GOF_H

#include <iostream>

namespace VisitorGOF
{
struct Circle;
struct Square;

struct ShapeVisitor
{
    virtual ~ShapeVisitor() = default;
    virtual void visit(Circle const &c) const = 0;
    virtual void visit(Square const &c) const = 0;
};

struct Shape
{
    virtual ~Shape() = default;
    virtual void printName() const = 0;
    virtual void accept(ShapeVisitor const &v) = 0;
};

struct Circle final: public Shape
{
    ~Circle() override = default;
    void printName() const override;
    void accept(ShapeVisitor const &v) override
    {
        v.visit(*this);
    }
};

struct Square final: public Shape
{
    ~Square() override = default;
    void printName() const override;
    void accept(ShapeVisitor const &v) override
    {
        v.visit(*this);
    }
};

struct DrawVisitor final: public ShapeVisitor
{
    ~DrawVisitor() override = default;
    void visit(Circle const &c) const override;
    void visit(Square const &s) const override;
};

struct RotateVisitor final: public ShapeVisitor
{
    ~RotateVisitor() override = default;
    void visit(Circle const &c) const override;
    void visit(Square const &s) const override;
};

void shapeVisitorExamples();

}// VisitorGOF namespace.


#endif //VISITOR_GOF_H


