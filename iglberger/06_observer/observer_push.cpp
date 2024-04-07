#include "observer_push.h"
#include <iostream>

namespace Iglberger::ObserverPush
{
void observerPullExample()
{
    auto emp = Employee{"shiras", 30000.0f};
    auto obs = EmployeeObserver{};
    emp.attach(&obs);
    emp.setSalary(34.0f);
    emp.detach(&obs);
    emp.setSalary(39.0f);
}

void EmployeeObserver::updateNameChange(const std::string &old_name, const std::string &new_name)
{
    std::cout << old_name << " is changed to " << new_name << std::endl;
}
void EmployeeObserver::updateSalaryChange(float old_salary, float new_salary)
{
    std::cout << old_salary << " is changed to " << new_salary << std::endl;
}
bool Employee::attach(EmployeeObserver *obs)
{
    auto const [pos, success] = observers_.insert(obs);
    return success;
}
bool Employee::detach(EmployeeObserver *obs)
{
    auto const num_elems_detached = observers_.erase(obs);
    return num_elems_detached > 0U;
}
}// Iglberger::ObserverPush namespace.
