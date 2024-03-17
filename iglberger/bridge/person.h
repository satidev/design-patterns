#ifndef PERSON_H
#define PERSON_H

#include <memory>

namespace Iglberger
{
struct Person
{
private:
    struct Impl;
    std::unique_ptr<Impl> const pimpl_;
public:
    Person();
    ~Person();

    Person(const Person &person);
    Person(Person &&person);
    Person &operator=(const Person &person);
    Person &operator=(Person &&person);

    void setYearOfBirth(int year);
    int getYearOfBirth() const noexcept;
};

void PersonPimplEx();
}

#endif //PERSON_H

