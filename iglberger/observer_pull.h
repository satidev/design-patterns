#ifndef OBSERVER_PULL_H
#define OBSERVER_PULL_H

#include <string>
#include <set>

namespace Iglberger::ObserverPull
{
template<typename Subject, typename StateTag>
struct Observer
{
    virtual ~Observer() = default;
    virtual void update(Subject const &, StateTag property) = 0;
};

struct Employee
{
public:
    enum class StateChange
    {
        NAME_CHANGED,
        SALARY_CHANGED
    };

    using EmployeeObserver = Observer<Employee, StateChange>;

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
        name_ = std::move(new_name);
        notify(StateChange::NAME_CHANGED);
    }
    void setSalary(float new_salary)
    {
        salary_ = new_salary;
        notify(StateChange::SALARY_CHANGED);
    }

    void notify(StateChange property);
    bool attach(EmployeeObserver *obs);
    bool detach(EmployeeObserver *obs);

private:
    std::string name_;
    float salary_;
    std::set<EmployeeObserver *> observers_;
};

class NameObserver: public Observer<Employee, Employee::StateChange>
{
public:
    void update(Employee const &e, Employee::StateChange property) override;
};

class SalaryObserver: public Observer<Employee, Employee::StateChange>
{
public:
    void update(Employee const &e, Employee::StateChange property) override;
};
void observerPullEx();
}// Iglberger::ObserverPull namespace.

#endif //OBSERVER_PULL_H


