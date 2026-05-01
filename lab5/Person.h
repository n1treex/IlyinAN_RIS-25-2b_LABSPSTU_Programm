#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Person : public Object
{
protected:
    string name;
    int age;
public:
    Person(void);
    virtual ~Person(void);
    Person(string n, int a);
    Person(const Person& p);

    string GetName() { return name; }
    int GetAge() { return age; }

    void SetName(string n);
    void SetAge(int a);

    Person& operator=(const Person& p);
    friend istream& operator>>(istream& in, Person& p);
    friend ostream& operator<<(ostream& out, const Person& p);

    void Show() override;
};