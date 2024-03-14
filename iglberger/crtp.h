#ifndef CRTP_H
#define CRTP_H

#include <vector>
#include <array>
#include <numeric>
#include <iostream>

namespace Iglberger::CRTP
{
template<typename Derived>
class DenseVector
{
protected:
    ~DenseVector() = default;
private:
    Derived &derived()
    {
        return static_cast<Derived &>(*this);
    }
    Derived const &derived() const
    {
        return static_cast<Derived const &>(*this);
    }
public:
    decltype(auto) operator[](size_t idx)
    {
        return derived()[idx];
    }
    decltype(auto) operator[](size_t idx) const
    {
        return derived()[idx];
    }
    decltype(auto) cbegin() const
    {
        return derived().cbegin();
    }
    decltype(auto) cend() const
    {
        return derived().cend();
    }
};

template<typename T>
class DynamicVector: public DenseVector<DynamicVector<T>>
{
private:
    std::vector<T> data_;

public:
    using const_iterator = typename std::vector<T>::const_iterator;
    using value_type = typename std::vector<T>::value_type;

    explicit DynamicVector(size_t num_elem)
    {
        data_ = std::vector<T>(num_elem, T{});
    }
    T &operator[](size_t idx)
    {
        return data_[idx];
    }
    T const &operator[](size_t idx) const
    {
        return data_[idx];
    }

    const_iterator cbegin() const
    {
        return std::cbegin(data_);
    }
    const_iterator cend() const
    {
        return std::cend(data_);
    }
};

template<typename T, size_t size>
class StaticVector: public DenseVector<StaticVector<T, size>>
{
private:
    std::array<T, size> data_;

public:
    using const_iterator = typename std::array<T, size>::const_iterator;
    using value_type = typename std::array<T, size>::value_type;

    explicit StaticVector(size_t num_elem)
    {
        data_.fill(T{});
    }
    T &operator[](size_t idx)
    {
        return data_[idx];
    }
    T const &operator[](size_t idx) const
    {
        return data_[idx];
    }

    const_iterator cbegin() const
    {
        return std::cbegin(data_);
    }
    const_iterator cend() const
    {
        return std::cend(data_);
    }
};
template<typename Derived>
void print(DenseVector<Derived> const &dv)
{
    for(auto it = dv.cbegin(); it != dv.cend(); ++it)
        std::cout << *it << std::endl;
}

template<typename Derived>
auto sum(DenseVector<Derived> const &dv)
{
    auto const init_val = decltype(dv[0]){};
    return std::accumulate(dv.cbegin(), dv.cend(), init_val);
}

void CRTPExample();

}// Iglberger::CRTP namespace.

#endif //CRTP_H


