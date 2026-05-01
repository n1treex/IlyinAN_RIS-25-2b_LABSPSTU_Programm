#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
    Person(void);
    virtual ~Person(void);
    Person(string, int);
    Person(const Person&);

    string GetName() { return name; }
    int GetAge() { return age; }

    void SetName(string);
    void SetAge(int);

    Person& operator=(const Person&);

    friend istream& operator>>(istream& in, Person& p);
    friend ostream& operator<<(ostream& out, const Person& p);

protected:
    string name;
    int age;
};