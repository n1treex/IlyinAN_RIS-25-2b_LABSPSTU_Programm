#include "Employee.h"

Employee::Employee(void) : Person()
{
    position = "";
    salary = 0.0;
    gruz = 0;
}

Employee::~Employee(void)
{
}

Employee::Employee(string N, int A, string P, double S) : Person(N, A)
{
    position = P;
    salary = S;
    gruz = 0;
}


Employee::Employee(const Employee& e)
{
    name = e.name;
    age = e.age;
    position = e.position;
    salary = e.salary;
    gruz = e.gruz;
}

void Employee::SetPosition(string P)
{
    position = P;
}

void Employee::SetSalary(double S)
{
    salary = S;
}

void Employee::SetGruz(int G)
{
    gruz = G;
}

double Employee::CalculateTotalSalary(double bonusPercent)
{
    return salary + (salary * bonusPercent / 100.0);
}

Employee& Employee::operator=(const Employee& e)
{
    if (&e == this) return *this;
    name = e.name;
    age = e.age;
    position = e.position;
    salary = e.salary;
    gruz = e.gruz;
    return *this;
}

istream& operator>>(istream& in, Employee& e)
{
    cout << "\nName: ";
    in >> e.name;
    cout << "Age: ";
    in >> e.age;
    cout << "Position: ";
    in >> e.position;
    cout << "Salary: ";
    in >> e.salary;
    return in;
}

ostream& operator<<(ostream& out, const Employee& e)
{
    out << "\nNAME: " << e.name;
    out << "\nAGE: " << e.age;
    out << "\nPOSITION: " << e.position;
    out << "\nSALARY: " << e.salary;
    out << "\n";
    return out;
}
