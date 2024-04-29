#include "command_ref_sem.h"
#include <utility>
#include <iostream>

namespace Iglberger::CommandRefSem
{
void Calculator::compute(std::unique_ptr<CalcCommand> command)
{
    current_ = command->execute(current_);
    stack_.push(std::move(command));
}
void Calculator::undoLast()
{
    if (std::empty(stack_))
        return;
    // Access the pointer and move it.
    auto command = std::move(stack_.top());
    // Remove the invalid pointer.
    stack_.pop();

    current_ = command->undo(current_);
}

void commandExample()
{
    auto calc = Calculator{};
    calc.compute(std::make_unique<Add>(3));
    calc.compute(std::make_unique<Subtract>(1));
    calc.compute(std::make_unique<Add>(2));

    std::cout << "3 - 1 + 2 = " << calc.result() << std::endl;

    calc.undoLast();
    std::cout << "3 - 1 + 2 - 2 = " << calc.result() << std::endl;

    calc.clear();
}
}// Iglberger::CommandRefSem namespace.
