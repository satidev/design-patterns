#ifndef EXTERN_POLYMORPH_H
#define EXTERN_POLYMORPH_H

#include <string>
#include <functional>
#include <iostream>
namespace Iglberger::ExternPolymorph
{
// No base class for shapes
struct Circle
{
    std::string name() const;
};

struct Square
{
    std::string name() const;
};

struct DrawableShapeConcept
{
    virtual ~DrawableShapeConcept() = default;
    virtual void draw() = 0;
};

template<typename ShapeT>
struct DrawableShapeModel: public DrawableShapeConcept
{
public:
    using DrawStrategy = std::function<void(ShapeT const &)>;
private:
    ShapeT shape_;
    DrawStrategy drawer_;
public:
    explicit DrawableShapeModel(ShapeT shape,
                                DrawableShapeModel<ShapeT>::DrawStrategy drawer)
        :
        shape_{std::move(shape)},
        drawer_{std::move(drawer)}
    {

    }
    void draw() override
    {
        drawer_(shape_);
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

void externPolymorphEx();

}

#endif //EXTERN_POLYMORPH_H


