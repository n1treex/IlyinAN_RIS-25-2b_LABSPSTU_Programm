#pragma once
#include "Person.h"

class Employee : public Person
{
public:
    Employee(void);
    ~Employee(void);
    Employee(string, int, string, double);
    Employee(const Employee&);

    int GetGruz() { return gruz; }        // В методичке у Lorry был метод Get_gruz()
    string GetPosition() { return position; }
    double GetSalary() { return salary; }

    void SetPosition(string);
    void SetSalary(double);
    void SetGruz(int);                     // Для соответствия стилю методички

    double CalculateTotalSalary(double);

    Employee& operator=(const Employee&);

    friend istream& operator>>(istream& in, Employee& e);
    friend ostream& operator<<(ostream& out, const Employee& e);

protected:
    string position;
    double salary;
    int gruz;                              // Как в методичке у Lorry
};