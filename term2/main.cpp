#include "Money.h"
#include <iostream>
using namespace std;
int main() {
    Money A;
    Money B;

    A.Init(100, 5);
    B.Read();

    A.Show();
    B.Show();

    cout << "A.summa(" << A.first << ", " << A.second << ") = " << A.summa() << "\n";
    cout << "B.summa(" << B.first << ", " << B.second << ") = " << B.summa() << "\n";

    // указатель на объект
    Money* X = new Money;
    X->Init(50, 3);
    X->Show();
    cout << "X.summa(" << X->first << ", " << X->second << ") = " << X->summa() << "\n";
    delete X;

    // массив объектов
    Money arr[3];
    for (int i = 0; i < 3; i++) {
        arr[i].Read();
    }

    for (int i = 0; i < 3; i++) {
        arr[i].Show();
    }

    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "].summa = " << arr[i].summa() << "\n";
    }

    // динамический массив
    Money* p_arr = new Money[3];

    for (int i = 0; i < 3; i++) {
        p_arr[i].Read();
    }

    for (int i = 0; i < 3; i++) {
        p_arr[i].Show();
    }

    for (int i = 0; i < 3; i++) {
        cout << "p_arr[" << i << "].summa = " << p_arr[i].summa() << "\n";
    }

    delete[] p_arr;

    // make_Money
    int f, s;
    cout << "\nValue: "; cin >> f;
    cout << "Count: "; cin >> s;

    Money M = make_Money(f, s);
    M.Show();

    return 0;
}