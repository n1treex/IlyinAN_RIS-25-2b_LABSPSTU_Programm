#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Vector v(5); // Вектор из 5 элементов

    cout << "Enter object Person:" << endl;
    Person p;
    cin >> p;

    cout << "\nEnter object Employee:" << endl;
    Employee e;
    cin >> e;

    Object* ptr = &p;
    v.Add(ptr); // добавляем базовый класс в вектор

    ptr = &e;
    v.Add(ptr); // добавляем производный класс в вектор

    cout << "\n--- Output elements ---";
    cout << v;

    // Демонстрация уникального метода производного класса
    double premium = 20.0; // 20% премия
    cout << "\n--- Raschet zarplati ---" << endl;
    cout << "Zarplata sotrudnika " << e.GetName()
         << " s premiey " << premium << "% sostavit: "
         << e.CalculatePay(premium) << endl;

    return 0;
}