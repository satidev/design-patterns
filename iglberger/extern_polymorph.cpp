#include "extern_polymorph.h"
#include <memory>

namespace Iglberger::ExternPolymorph
{
std::string Circle::name() const
{
    return std::string{"circle"};
}
std::string Square::name() const
{
    return std::string{"square"};
}
void externPolymorphEx()
{
    using Shape = std::unique_ptr<DrawableShapeConcept>;
    auto shapes = std::vector<Shape>{};

    shapes.emplace_back(std::make_unique<DrawableShapeModel<Circle>>(Circle{},
        OpenGLDraw{}));
    shapes.emplace_back(std::make_unique<DrawableShapeModel<Square>>(Square{},
        OpenGLDraw{}));
    shapes.emplace_back(std::make_unique<DrawableShapeModel<Circle>>(Circle{},
                                                                     VulkanDraw{}));
    shapes.emplace_back(std::make_unique<DrawableShapeModel<Square>>(Square{},
                                                                     VulkanDraw{}));
    for(auto const &shape:shapes){
        shape->draw();
    }
}
}
