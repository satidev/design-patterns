#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <memory>
#include <string>
#include <utility>

namespace Iglberger::Prototype
{
struct Pet
{
private:
    std::string name_;
protected:
    explicit Pet(std::string name)
        :
        name_{std::move(name)}
    {

    }

public:
    virtual ~Pet() = default;
    virtual std::unique_ptr<Pet> clone() = 0;
    std::string getName() const noexcept
    {
        return name_;
    }
    void setName(std::string name)
    {
        name_ = std::move(name);
    }
};

struct Sheep: public Pet
{
public:
    explicit Sheep(std::string name)
        :
        Pet{std::move(name)}
    {

    }
    std::unique_ptr<Pet> clone() override;
};

void prototypeEx();
}

#endif //PROTOTYPE_H


