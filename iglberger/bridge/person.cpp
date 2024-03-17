#include "person.h"
#include <string>
#include <iostream>

namespace Iglberger
{
struct Person::Impl
{
    std::string name;
    int year_of_birth;
};
int Person::getYearOfBirth() const noexcept
{
    return pimpl_->year_of_birth;
}
Person::Person()
    :
    pimpl_{std::make_unique<Impl>()}
{

}
void Person::setYearOfBirth(int year)
{
    pimpl_->year_of_birth = year;
}
Person::Person(const Person &person)
    : pimpl_{std::make_unique<Impl>(*person.pimpl_)}
{

}
Person::Person(Person &&person)
    :
    pimpl_{std::make_unique<Impl>(std::move(*person.pimpl_))}
{

}
Person &Person::operator=(const Person &person)
{
    *pimpl_ = *person.pimpl_;
    return *this;
}
Person &Person::operator=(Person &&person)
{
    *pimpl_ = std::move(*person.pimpl_);
    return *this;
}

Person::~Person() = default;

void PersonPimplEx()
{
    auto person = Person{};
    person.setYearOfBirth(1990);
    std::cout << person.getYearOfBirth() << std::endl;
}
}
