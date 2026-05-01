#pragma once
#include "Object.h"
#include <string>
#include <iostream>

using namespace std;

class Person : public Object {
protected:
    string name;
    int age;
public:
    Person();
    Person(string, int);
    virtual ~Person();
    void Show() override;
    void Input() override;
    void HandleEvent(const TEvent& e) override;
    int GetAge() override { return age; }
};