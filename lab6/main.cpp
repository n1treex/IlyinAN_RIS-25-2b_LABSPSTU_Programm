#include <iostream>
#include "List.h"

using namespace std;

int main() {
    // Тестирование конструкторов и ввода/вывода
    List a(5); // Создаем список из 5 нулей
    cout << "List 'a' (initialized with zeros): " << a << "\n";

    cout << "Enter 5 integer values for list 'a':\n";
    cin >> a;
    cout << "List 'a' after input: " << a << "\n\n";

    // Тестирование доступа по индексу []
    a[2] = 100;
    cout << "List 'a' after changing a[2] to 100: " << a << "\n\n";

    // Тестирование сложения a[i] + b[i] (+ вектор/список)
    List b(5, 10); // Список из 5 элементов, каждый равен 10
    cout << "List 'b' (all 10s): " << b << "\n";

    List c = a + b;
    cout << "List 'c' (result of a + b): " << c << "\n\n";

    // Тестирование добавления константы (+ число)
    List d = c + 50;
    cout << "List 'd' (result of c + 50): " << d << "\n\n";

    // Тестирование итератора и операции -- (переход к предыдущему элементу)
    cout << "Testing Iterator backwards traversal using '--':\n";
    cout << "Elements of list 'd' in reverse order: ";

    // Начинаем с последнего элемента
    ListIterator it = d.last();

    // Идем назад, пока не дойдем до начала (nullptr)
    while (it != ListIterator(nullptr)) {
        cout << *it << " ";
        --it; // Переход к предыдущему элементу
    }
    cout << "\n";

    return 0;
}