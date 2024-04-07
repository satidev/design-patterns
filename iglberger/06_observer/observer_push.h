#ifndef OBSERVER_PUSH_H
#define OBSERVER_PUSH_H

#include <string>
#include <utility>
#include <set>

// Subject pushes the relevant detail to the observers.
namespace Iglberger::ObserverPush
{
class EmployeeObserver
{
public:
    void updateNameChange(std::string const &old_name,
                          std::string const &new_name);
    void updateSalaryChange(float old_salary, float new_salary);
};

class Employee
{
public:
    Employee(std::string name, float salary)
        :
        name_{std::move(name)}, salary_{salary}
    {

    }
    std::string const &getName() const noexcept
    {
        return name_;
    }
    float getSalary() const noexcept
    {
        return salary_;
    }
    void setName(std::string new_name)
    {
        auto const old_name = name_;
        name_ = std::move(new_name);
        for(auto obs: observers_){
            obs->updateNameChange(old_name, new_name);
        }
    }
    void setSalary(float new_salary)
    {
        auto const old_salary = salary_;
        salary_ = new_salary;
        for(auto obs: observers_){
            obs->updateSalaryChange(old_salary, new_salary);
        }
    }

    bool attach(EmployeeObserver *obs);
    bool detach(EmployeeObserver *obs);

private:
    std::string name_;
    float salary_;
    // Pointer is a unique identifier.
    // set avoids duplication of observers.
    // Non-owning pointers.
    std::set<EmployeeObserver*> observers_;
};

void observerPullExample();

}// Iglberger::ObserverPush namespace.

#endif //OBSERVER_PUSH_H


