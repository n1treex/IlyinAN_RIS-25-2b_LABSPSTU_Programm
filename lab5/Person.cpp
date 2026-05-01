#include "Person.h"

Person::Person(void)
{
    name = "";
    age = 0;
}

Person::~Person(void)
{
}

Person::Person(string n, int a)
{
    name = n;
    age = a;
}

Person::Person(const Person& p)
{
    name = p.name;
    age = p.age;
}

void Person::SetName(string n)
{
    name = n;
}

void Person::SetAge(int a)
{
    age = a;
}

Person& Person::operator=(const Person& p)
{
    if (&p == this) return *this;
    name = p.name;
    age = p.age;
    return *this;
}

istream& operator>>(istream& in, Person& p)
{
    cout << "\nName: "; in >> p.name;
    cout << "Age: "; in >> p.age;
    return in;
}

ostream& operator<<(ostream& out, const Person& p)
{
    out << "\nNAME: " << p.name;
    out << "\nAGE: " << p.age << "\n";
    return out;
}

void Person::Show()
{
    cout << "\nNAME: " << name;
    cout << "\nAGE: " << age << "\n";
}