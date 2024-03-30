#include "type_erasure_sbo.h"

namespace Iglberger::TypeErasureSBO
{
std::string Circle::name() const
{
    return std::string{"circle"};
}
std::string Square::name() const
{
    return std::string{"square"};
}
void typeErasureExample()
{
    // No pointers as it was in external polymorphism.
    // Shape becomes a value type.
    auto shape = Shape{Circle{}, OpenGLDraw{}};
    process(shape);

    // A deep copy as expected for a value.
    auto shape_2 = Shape{shape};
    process(shape_2);

    auto const shape_3 = Shape{Square{}, VulkanDraw{}};
    process(shape_3);


}
}
