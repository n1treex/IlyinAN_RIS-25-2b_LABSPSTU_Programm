#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Vector v(5); 

    cout << "Enter object Person:" << endl;
    Person p;
    cin >> p;

    cout << "\nEnter object Employee:" << endl;
    Employee e;
    cin >> e;

    Object* ptr = &p;
    v.Add(ptr); 

    ptr = &e;
    v.Add(ptr); 

    cout << "\n--- Output elements ---";
    cout << v;

  
    double premium = 20.0;
    cout << "\n--- Raschet zarplati ---" << endl;
    cout << "Zarplata sotrudnika " << e.GetName()
         << " s premiey " << premium << "% sostavit: "
         << e.CalculatePay(premium) << endl;

    return 0;
}
