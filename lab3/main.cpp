#include "Pair.h"
#include <iostream>
using namespace std;

int main()
{
    Pair a;
    Pair b;
    Pair c;

    cout << "--- Enter first pair ---" << endl;
    cin >> a;
    cout << "--- Enter second pair ---" << endl;
    cin >> b;

    // Проверка префиксного --
    cout << "\nPrefix -- for a (--a):" << endl;
    --a;
    cout << "a = " << a << endl;

    // Проверка постфиксного --
    cout << "\nPostfix -- for b (b--) with assignment to c:" << endl;
    c = b--;
    cout << "c (old b) = " << c << endl;
    cout << "b (new)      = " << b << endl;

    // Проверка операций сравнения
    cout << "\n--- Comparison ---" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    if (a > b)
    {
        cout << "a > b" << endl;
    }
    else if (a < b)
    {
        cout << "a < b" << endl;
    }
    else
    {
        cout << "a = b" << endl;
    }

    return 0;  
}
