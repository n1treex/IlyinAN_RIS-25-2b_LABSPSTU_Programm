#include <iostream>
#include "Person.h"
#include "Employee.h"
using namespace std;

void f1(Person& p)
{
    p.SetName("Fedor");
    cout << p;
}

Person f2()
{
    Employee e("Sasha", 1, "Manager", 3000);
    return e;
}

int main()
{
    // Работа с классом Person
    Person a;
    cin >> a;
    cout << a;

    Person b("Daniil", 4);
    cout << b;

    a = b;
    cout << a;

    // Работа с классом Employee
    Employee c;
    cin >> c;
    cout << c;

    // Принцип подстановки
    f1(c);
    a = f2();
    cout << a;
    return 0;
}