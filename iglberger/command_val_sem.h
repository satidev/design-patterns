#ifndef COMMAND_VAL_SEM_H
#define COMMAND_VAL_SEM_H

#include <queue>
#include <functional>

namespace Iglberger::CommandValSem
{

struct Image
{

};

struct Scale
{
public:
    Scale() = default;
    explicit Scale(float scale_fact)
        :
        scale_fact_{scale_fact}
    {

    }
    void operator()(Image& img) const;
private:
    float scale_fact_ = 1.0f;
};

struct Rotate
{
    void operator()(Image & img) const;
};

struct ImageProcessor
{
public:
    void addCommand(std::function<void(Image &)> command)
    {
        command_queue_.push(std::move(command));
    }
    void run(Image &img)
    {
        while (!std::empty(command_queue_)) {
            command_queue_.front()(img);
            command_queue_.pop();
        }
    }

private:
    std::queue<std::function<void(Image &)>> command_queue_{};
};

void commandExample();

}// Iglberger::CommandValSem namespace.

#endif //COMMAND_VAL_SEM_H


