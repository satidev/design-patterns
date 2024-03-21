#ifndef TYPE_ERASURE_H
#define TYPE_ERASURE_H

#include <string>
#include <memory>
#include <functional>
#include <iostream>

// The code was adapted from the book C++ Software Design: Design Principles and Patterns for High-Quality Software.
// Guideline 32: Consider replacing inheritance hierarchies with type erasure.
namespace Iglberger::TypeErasure
{
// No base class for shapes.
// Circle and Square are unrelated.
struct Circle
{
    std::string name() const;
};

struct Square
{
    std::string name() const;
};

}

// These are implementation details to create a wrapped type.
namespace Iglberger::TypeErasure::Detail
{
// Also present in external polymorphism.
// Base class for external hierarchy.
struct ShapeConcept
{
public:

    // All shapes must be destructible.
    virtual ~ShapeConcept() = default;

    // All shapes must be processable with a functor.
    virtual void process() const = 0;

    // Prototype design pattern to copy derived class.
    // All shapes must be copyable.
    virtual std::unique_ptr<ShapeConcept> clone() const = 0;
};

template<typename ShapeT>
struct OwningShapeModel: public ShapeConcept
{
public:
    using ShapeProcCommand = std::function<void(ShapeT const &)>;
private:
    ShapeT shape_;
    ShapeProcCommand command_;
public:
    explicit OwningShapeModel(ShapeT const &shape,
                              ShapeProcCommand command)
        :
        shape_{std::move(shape)},
        command_{std::move(command)}
    {

    }
    void process() const override
    {
        command_(shape_);
    }
    std::unique_ptr<ShapeConcept> clone() const override
    {
        return std::make_unique<OwningShapeModel<ShapeT>>(*this);
    }
};

}

namespace Iglberger::TypeErasure
{
// The actual wrapper type which behave as a polymorphic type.
struct Shape
{
private:
    // A bridge to the real shape type, or implementation details.
    std::unique_ptr<Detail::ShapeConcept> pimpl_;
public:
    // Templated constructor to take any kind of shape.
    template<typename ShapeT>
    explicit Shape(ShapeT const &shape,
                   typename Detail::OwningShapeModel<ShapeT>::ShapeProcCommand command)
    {
        using Model = Detail::OwningShapeModel<ShapeT>;
        pimpl_ = std::make_unique<Model>(std::move(shape), std::move(command));
    }// At this point memory of the real type has been erased!

    // If you want the Shape as value type, you have to provide
    // all special member functions and destructors.
    // Compiler generated destructor and move operations are enough since
    // we have only a unique pointer as a data member.
    ~Shape() = default;
    Shape(Shape &&) = default;
    Shape &operator=(Shape &&) = default;

    // Since unique pointers are not copyable, we have to write our own
    // copy operations.
    Shape(Shape const &shape)
        :
        // Since the type has been erased,
        // this copy operation was only possible due to the implementation of
        // clone function.
        pimpl_{shape.pimpl_->clone()}
    {

    }
    Shape& operator=(Shape const &shape){
        Shape copy(shape);
        pimpl_.swap(copy.pimpl_);
        return *this;
    }
private:
    // Hidden friend function.
    // A free function which can be injected to surrounding namespace
    // at the same can access private members of the shape class.
    friend void process(Shape const &shape){
        shape.pimpl_->process();
    }
};

struct OpenGLDraw
{
public:
    void operator()(Circle const &circle)
    {
        drawShape(circle);
    }
    void operator()(Square const &square)
    {
        drawShape(square);
    }

private:
    template<typename ShapeT>
    void drawShape(ShapeT const &shape);
};

template<typename ShapeT>
void OpenGLDraw::drawShape(ShapeT const &shape)
{
    std::cout << "Drawing " << shape.name() <<" using openGL." << std::endl;
}

struct VulkanDraw
{
public:
    void operator()(Circle const &circle)
    {
        drawShape(circle);
    }
    void operator()(Square const &square)
    {
        drawShape(square);
    }

private:
    template<typename ShapeT>
    void drawShape(ShapeT const &shape);
};
template<typename ShapeT>
void VulkanDraw::drawShape(const ShapeT &shape)
{
    std::cout << "Drawing " << shape.name() <<" using Vulkan." << std::endl;
}

void typeErasureExample();
}

#endif //TYPE_ERASURE_H

