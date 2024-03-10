#ifndef VISITOR_ACYCLIC_H
#define VISITOR_ACYCLIC_H

namespace Iglberger::VisitorAcyclic
{
// Just for tagging.
struct AbstractVisitor
{
    virtual ~AbstractVisitor() = default;
};

template<typename ShapeType>
struct Visitor
{
    virtual ~Visitor() = default;
    virtual void visit(ShapeType const &s) const = 0;
};

struct Shape
{
    virtual ~Shape() = default;
    virtual void printName() const = 0;
    virtual void accept(AbstractVisitor const &) = 0;
};

struct Circle: public Shape
{
    ~Circle() override = default;
    void printName() const override;
    void accept(AbstractVisitor const &v) override;
};

struct Square: public Shape
{
    ~Square() override = default;
    void printName() const override;
    void accept(AbstractVisitor const &v) override;
};

struct DrawVisitor: public AbstractVisitor,
                    Visitor<Circle>,
                    Visitor<Square>
{
    void visit(Circle const &c) const override;
    void visit(Square const &s) const override;
};

struct RotateVisitor: public AbstractVisitor,
                      Visitor<Circle>,
                      Visitor<Square>
{
    void visit(Circle const &c) const override;
    void visit(Square const &s) const override;
};

void shapeVisitorExamples();

}// Iglberger::VisitorAcyclic namespace.

#endif //VISITOR_ACYCLIC_H


