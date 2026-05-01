#include "Money.h"
#include <iostream>
using namespace std;

// Инициализация с проверкой
bool Money::Init(int f, int s) {
    int valid[] = {1, 2, 5, 10, 50, 100, 500, 1000, 5000};

    int i = 0;
    while (i < 9 && f != valid[i]) {
        i++;
    }

    if (i == 9 || s <= 0) {
        return false; // ошибка
    }

    first = f;
    second = s;
    return true;
}

// Ввод с повтором до корректного значения
void Money::Read() {
    int f, s;
    bool ok;

    do {
        cout << "\nValue: ";
        cin >> f;
        cout << "Count: ";
        cin >> s;

        ok = Init(f, s);
        if (!ok) cout << "Repeat please\n";

    } while (!ok);
}

// Вывод
void Money::Show() {
    cout << "\nValue = " << first
         << "\nCount = " << second << "\n";
}

// Вычисление суммы
int Money::summa() {
    return first * second;
}

// Внешняя функция
Money make_Money(int f, int s) {
    Money res;
    if (!res.Init(f, s)) {
        cout << "Error\n";
        res.Init(1, 1);
    }
    return res;
}