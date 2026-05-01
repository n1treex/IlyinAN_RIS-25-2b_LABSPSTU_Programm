#include "Employee.h"

Employee::Employee(void) : Person()
{
    position = "";
    salary = 0.0;
}

Employee::~Employee(void)
{
}

Employee::Employee(string n, int a, string pos, double sal) : Person(n, a)
{
    position = pos;
    salary = sal;
}

Employee::Employee(const Employee& e) : Person(e)
{
    position = e.position;
    salary = e.salary;
}

void Employee::SetPosition(string pos)
{
    position = pos;
}

void Employee::SetSalary(double sal)
{
    salary = sal;
}

double Employee::CalculatePay(double premiumPercent)
{
    return salary + (salary * premiumPercent / 100.0);
}

Employee& Employee::operator=(const Employee& e)
{
    if (&e == this) return *this;
    name = e.name;
    age = e.age;
    position = e.position;
    salary = e.salary;
    return *this;
}

istream& operator>>(istream& in, Employee& e)
{
    cout << "\nName: "; in >> e.name;
    cout << "Age: "; in >> e.age;
    cout << "Position: "; in >> e.position;
    cout << "Salary: "; in >> e.salary;
    return in;
}

ostream& operator<<(ostream& out, const Employee& e)
{
    out << "\nNAME: " << e.name;
    out << "\nAGE: " << e.age;
    out << "\nPOSITION: " << e.position;
    out << "\nSALARY: " << e.salary << "\n";
    return out;
}

void Employee::Show()
{
    cout << "\nNAME: " << name;
    cout << "\nAGE: " << age;
    cout << "\nPOSITION: " << position;
    cout << "\nSALARY: " << salary << "\n";
}