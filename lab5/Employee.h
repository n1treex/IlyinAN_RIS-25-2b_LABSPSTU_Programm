#pragma once
#include "Person.h"

class Employee : public Person
{
protected:
    string position;
    double salary;
public:
    Employee(void);
    ~Employee(void);
    Employee(string n, int a, string pos, double sal);
    Employee(const Employee& e);
    
    string GetPosition() { return position; }
    double GetSalary() { return salary; }
    
    void SetPosition(string pos);
    void SetSalary(double sal);
    
    // Вычисление зарплаты (Оклад + Премия % от оклада)
    double CalculatePay(double premiumPercent);
    
    Employee& operator=(const Employee& e);
    friend istream& operator>>(istream& in, Employee& e);
    friend ostream& operator<<(ostream& out, const Employee& e);
    
    void Show() override;
};