#include "List.h"
#include <iostream>
using namespace std;

int main() {
    try {
        List a(3);
        cout << "Enter list a:" << endl;
        cin >> a;
        cout << "List a: " << a;

        List b(2);
        cout << "Enter list b:" << endl;
        cin >> b;

        List c = a + b;
        cout << "List a + b: " << c;

        List d = a + 99; // Добавление числа 99 в начало
        cout << "List a + 99 (added to start): " << d;

        cout << "Element a[1]: " << a[1] << endl;

        // Генерация исключения
        cout << "Triggering out of bounds exception (a[10])..." << endl;
        cout << a[10] << endl;
    }
    catch (int e) {
        cout << "ERROR CODE: " << e << "!!!" << endl;
    }
    return 0;
}