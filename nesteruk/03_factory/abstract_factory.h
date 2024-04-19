#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include <string>
#include <memory>
#include <iostream>

namespace Nesteruk::AbstractFactory
{
struct AbstractProduct
{
    virtual ~AbstractProduct() = default;
    virtual std::string name() const = 0;
};

// Concrete products
struct Computer: public AbstractProduct
{
    std::string name() const override
    {
        return std::string{"computer"};
    }
};

struct Phone: public AbstractProduct
{
    std::string name() const override
    {
        return std::string{"phone"};
    }
};

struct AbstractFactory
{
    virtual std::unique_ptr<AbstractProduct> make() const = 0;
};

struct ComputerFactory: AbstractFactory
{
    std::unique_ptr<AbstractProduct> make() const override
    {
        return std::make_unique<Computer>();
    }
};

struct PhoneFactory: AbstractFactory
{
    std::unique_ptr<AbstractProduct> make() const override
    {
        return std::make_unique<Phone>();
    }
};

void example()
{
    auto prod_1 = ComputerFactory{}.make();
    std::cout << prod_1->name() << std::endl;

    auto prod_2 = PhoneFactory{}.make();
    std::cout << prod_2->name() << std::endl;
}

}

#endif //ABSTRACT_FACTORY_H


