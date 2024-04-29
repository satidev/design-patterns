#ifndef DECORATOR_COMPILE_TIME_H
#define DECORATOR_COMPILE_TIME_H

#include <string>

namespace Iglberger::DecoratorValCompileTime
{
struct CppBook
{
private:
    std::string title_;
    float price_;

public:
    explicit CppBook(std::string title, float price)
        :
        title_{std::move(title)},
        price_{price}
    {

    }
    float money() const noexcept
    {
        return price_;
    }
};

template<typename Item>
struct DiscountedItem
{
private:
    float disc_percent_ = 0.20f;
    Item item_;
public:
    template<typename... Args>
    explicit DiscountedItem(float discount, Args &&... args)
        :
        disc_percent_{discount},
        item_{std::forward<Args>(args)...}
    {

    }
    float money() const noexcept
    {
        return item_.money() * (1.0 - disc_percent_ / 100.0f);
    }
};

template<typename Item>
struct TaxedItem
{
private:
    float tax_rate_ = 0.20f;
    Item item_;
public:
    template<typename... Args>
    explicit TaxedItem(float tax_rate, Args &&... args)
        :
        tax_rate_{tax_rate},
        item_{std::forward<Args>(args)...}
    {

    }
    float money() const noexcept
    {
        return item_.money() * (1.0 + tax_rate_ / 100.0f);
    }
};

void decoratorValueCompileTimeEx();

}

#endif //DECORATOR_COMPILE_TIME_H


