#ifndef ADAPTOR_FUNCTION_H
#define ADAPTOR_FUNCTION_H

#include <vector>
#include <numeric>

namespace Iglberger::AdaprorFunc
{
class Image
{
public:
    Image(size_t num_elems, float init_val)
    {
        data_ = std::vector<float>(num_elems, init_val);
    }
    std::vector<float> const &data() const
    {
        return data_;
    }
private:
    std::vector<float> data_;
};

inline auto cbegin(Image const &img)
{
    return img.data().cbegin();
}

inline auto cend(Image const &img)
{
    return img.data().cend();
}

template<typename FloatContainer>
float sumElems(FloatContainer const &c)
{
    using std::cbegin;
    using std::cend;
    return std::accumulate(cbegin(c), cend(c), 0.0f);
}
void funcAdaptorExample();

}// Iglberger::AdaprorFunc namespace.

#endif //ADAPTOR_FUNCTION_H


