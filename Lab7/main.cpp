#include <iostream>
#include "Pair.h"
#include "List.h"

using namespace std;

int main() {
    // 1. Тестирование шаблона для стандартных типов данных (int)
    cout << "=== Test List<int> ===" << endl;
    List<int> list1(3, 0);
    cout << "Enter 3 numb list1:\n";
    cin >> list1;
    cout << "list1: " << list1 << endl;

    List<int> list2(3, 5);
    cout << "list2: " << list2 << endl;

    cout << "index list1[1]: " << list1[1] << endl;

    List<int> list3 = list1 + list2; // Сложение элементов a[i] + b[i]
    cout << "list3 (list1 + list2): " << list3 << endl;

    List<int> list4 = list1 + 10;    // Добавление константы
    cout << "list4 (list1 + 10): " << list4 << endl;


    // 2. Тестирование шаблона для пользовательского класса (Pair)
    cout << "\n=== Test List<Pair> ===" << endl;
    Pair defaultPair(1, 1.5);
    List<Pair> pairList1(2, defaultPair);
    cout << "Enter numbs for two pairs pairList1:\n";
    cin >> pairList1;
    cout << "pairList1: " << pairList1 << endl;

    Pair pairToAdd(2, 3.0);
    List<Pair> pairList2(2, pairToAdd);
    cout << "pairList2: " << pairList2 << endl;

    List<Pair> pairList3 = pairList1 + pairList2;
    cout << "pairList3 (pairList1 + pairList2): " << pairList3 << endl;

    Pair constantPair(10, 0.5);
    List<Pair> pairList4 = pairList1 + constantPair;
    cout << "pairList4 (pairList1 + constantPair): " << pairList4 << endl;

    return 0;
}