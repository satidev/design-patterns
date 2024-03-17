#ifndef DECORATOR_REF_H
#define DECORATOR_REF_H

#include <string>

namespace Iglberger
{
struct Item
{
    virtual ~Item() = default;
    virtual float money() const = 0;
};

struct Book: public Item
{
private:
    std::string title_;
    float price_;
public:
    explicit Book(std::string title, float price)
        :
        title_{std::move(title)}, price_{price}
    {

    }
    std::string const &getTitle() const noexcept
    {
        return title_;
    }
    float money() const override
    {
        return price_;
    }
};

struct ConferenceTicket: public Item
{
private:
    std::string title_;
    float price_;
public:
    explicit ConferenceTicket(std::string title, float price)
        :
        title_{std::move(title)}, price_{price}
    {

    }
    std::string const &getTitle() const noexcept
    {
        return title_;
    }
    float money() const override
    {
        return price_;
    }
};

struct DecoratedItem: public Item
{
private:
    std::unique_ptr<Item> item_;
protected:
    explicit DecoratedItem(std::unique_ptr<Item> item)
        :
        item_{std::move(item)}
    {

    }
    Item &item()
    {
        return *item_;
    }
    Item const &item() const
    {
        return *item_;
    }
};

struct TaxedItem: public DecoratedItem
{
private:
    float tax_rate_perc_;

public:
    explicit TaxedItem(std::unique_ptr<Item> item,
                       float tax_rate_perc)
        :
        DecoratedItem{std::move(item)},
        tax_rate_perc_{tax_rate_perc}
    {

    }
    float money() const override
    {
        return item().money() * (1 + tax_rate_perc_ / 100.0f);
    }
};

struct DiscountedItem: public DecoratedItem
{
private:
    float discount_perc_;
public:
    explicit DiscountedItem(std::unique_ptr<Item> item,
                            float discount_perc)
        :
        DecoratedItem{std::move(item)},
        discount_perc_{discount_perc}
    {

    }
    float money() const override
    {
        return item().money() * (1.0f - discount_perc_ / 100.0f);
    }
};

void itemDecoratorEx();

}

#endif //DECORATOR_REF_H
