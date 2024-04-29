#ifndef TYPE_ERASURE_SBO_H
#define TYPE_ERASURE_SBO_H

#include <array>
#include <functional>
#include <iostream>

namespace Iglberger::TypeErasureSBO
{
template<size_t Capacity = 64U, size_t Alignment = alignof(void *)>
struct Shape
{
private:

    // Instead of unique pointer m an array of ordered bytes.
    alignas(Alignment) std::array<std::byte, Capacity> buffer_;

    struct ShapeConcept
    {
        virtual ~ShapeConcept() = default;
        virtual void process() const = 0;
        virtual void clone(ShapeConcept *memory) const = 0;
        virtual void move(ShapeConcept *memory) const = 0;
    };

    template<typename ShapeT>
    struct OwningModel: public ShapeConcept
    {
    public:
        using ProcessCommand = std::function<void(ShapeT const &)>;
    private:
        ShapeT shape_;
        ProcessCommand command_;

    public:

        explicit OwningModel(ShapeT shape, ProcessCommand command)
            :
            shape_{std::move(shape)},
            command_{std::move(command)}
        {}

        void process() const override
        {
            command_(shape_);
        }
        void clone(ShapeConcept *memory) const override
        {
            // T* construct_at( T* p, Args&&... args ):
            // Creates a T object initialized with arguments args... at given address p.
            std::construct_at(static_cast<OwningModel<ShapeT> *>(memory), *this);
        }
        void move(ShapeConcept *memory) const override
        {
            // Moves an OwningModel object from one buffer to another.
            std::construct_at(static_cast<OwningModel<ShapeT> *>(memory), std::move(*this));
        }
    };

    ShapeConcept *pimpl()
    {
        return reinterpret_cast<ShapeConcept *>(buffer_.data());
    }
    ShapeConcept const *pimpl() const
    {
        return reinterpret_cast<ShapeConcept const *>(buffer_.data());
    }

public:
    Shape(Shape const &shape)
    {
        shape.pimpl()->clone(pimpl());
    }
    Shape &operator=(Shape const &shape)
    {
        Shape copy(shape);
        buffer_.swap(shape.buffer_);
        return *this;
    }
    Shape(Shape &&shape) noexcept
    {
        shape.pimpl()->move(pimpl());
    }
    Shape &operator=(Shape &&other) noexcept
    {
        Shape copy(std::move(other));
        buffer_.swap(copy.buffer_);
        return *this;
    }
    ~Shape()
    {
        std::destroy_at(pimpl());
    }

    template<typename ShapeT>
    Shape(ShapeT const &shape, OwningModel<ShapeT>::ProcessCommand command)
    {
        static_assert(sizeof(OwningModel<ShapeT>) <= Capacity, "Given type is too large");
        static_assert(alignof(OwningModel<ShapeT>) <= Alignment, "Given type is misaligned");

        std::construct_at(static_cast<OwningModel<ShapeT> *>(pimpl()),
                          std::move(shape), std::move(command));
    }
private:
    // Hidden friend function.
    // A free function which can be injected to surrounding namespace
    // at the same can access private members of the shape class.
    friend void process(Shape const &shape){
        shape.pimpl()->process();
    }
};

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

#endif //TYPE_ERASURE_SBO_H


