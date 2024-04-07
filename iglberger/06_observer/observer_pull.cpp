#include "observer_pull.h"
#include <iostream>

namespace Iglberger::ObserverPull
{
void observerPullEx()
{
    auto emp = Employee{"shiras", 45.0f};
    auto salary_obs = SalaryObserver{};
    auto name_obs = NameObserver{};
    emp.attach(&salary_obs);
    emp.attach(&name_obs);
    emp.setSalary(50.0f);
    emp.setName("John");
}
bool Employee::attach(Employee::EmployeeObserver *obs)
{
    auto const [pos, success] = observers_.insert(obs);
    return success;
}
bool Employee::detach(Employee::EmployeeObserver *obs)
{
    auto const num_elems_detached = observers_.erase(obs);
    return num_elems_detached > 0U;
}
void Employee::notify(Employee::StateChange property)
{
    for (auto ptr: observers_) {
        ptr->update(*this, property);
    }
}

void NameObserver::update(const Employee &e, Employee::StateChange property)
{
    if (property == Employee::StateChange::NAME_CHANGED) {
        std::cout << "Name changed to " << e.getName() << std::endl;
    }
}
void SalaryObserver::update(const Employee &e, Employee::StateChange property)
{
    if (property == Employee::StateChange::SALARY_CHANGED) {
        std::cout << "Salary changed to " << e.getSalary() << std::endl;
    }
}
}// Iglberger::ObserverPull namespace.