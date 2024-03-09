#ifndef COMMAND_REF_SEM_H
#define COMMAND_REF_SEM_H

#include <memory>
#include <stack>

namespace CommandRefSem
{
struct CalcCommand
{
    virtual ~CalcCommand() = default;
    virtual int execute(int i) const = 0;
    virtual int undo(int i) const = 0;
};

struct Add final: public CalcCommand
{
public:
    explicit Add(int operand)
        :
        operand_{operand}
    {}
    int execute(int i) const override
    {
        return i + operand_;
    }
    int undo(int i) const override
    {
        return i - operand_;
    }
private:
    int operand_{};
};

struct Subtract final: public CalcCommand
{
public:
    explicit Subtract(int operand)
        :
        operand_{operand}
    {}
    int execute(int i) const override
    {
        return i - operand_;
    }
    int undo(int i) const override
    {
        return i + operand_;
    }
private:
    int operand_{};
};

struct Calculator
{
public:
    void compute(std::unique_ptr<CalcCommand> command);
    void undoLast();
    int result() const noexcept
    {
        return current_;
    }
    void clear()
    {
        while (!std::empty(stack_)) {
            stack_.pop();
        }
        current_ = 0;
    }
private:
    std::stack<std::unique_ptr<CalcCommand>> stack_;
    int current_{};
};

void commandExample();
}// CommandRefSem namespace.

#endif //COMMAND_REF_SEM_H

