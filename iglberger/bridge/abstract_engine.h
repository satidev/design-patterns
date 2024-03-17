#ifndef ABSTRACT_ENGINE_H
#define ABSTRACT_ENGINE_H

namespace Iglberger
{
struct AbstractEngine
{
    virtual ~AbstractEngine() = default;
    virtual void start() const = 0;
    virtual void stop() const = 0;
};
}// Iglberger namespace.

#endif //ABSTRACT_ENGINE_H


