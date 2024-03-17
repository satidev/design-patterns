#ifndef CAR_H
#define CAR_H

#include "abstract_engine.h"
#include <memory>

namespace Iglberger
{
struct AbstractCar
{
private:
    std::unique_ptr<AbstractEngine> pimpl_;

protected:
    explicit AbstractCar(std::unique_ptr<AbstractEngine> e)
        :
        pimpl_{std::move(e)}
    {

    }
public:
    virtual ~AbstractCar() = default;
    virtual void drive() = 0;
    AbstractEngine const *getEngine() const noexcept
    {
        return pimpl_.get();
    }
    AbstractEngine *getEngine() noexcept
    {
        return pimpl_.get();
    }
};
}

#endif //CAR_H

