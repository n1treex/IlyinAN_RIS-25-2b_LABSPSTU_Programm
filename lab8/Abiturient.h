#pragma once
#include "Person.h"

class Abiturient : public Person {
protected:
    int score;
    string specialty;
public:
    Abiturient();
    Abiturient(string, int, int, string);
    void Show() override;
    void Input() override;
};