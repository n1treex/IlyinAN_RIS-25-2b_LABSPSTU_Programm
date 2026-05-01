#include "List.h"
#include "Error.h"

// Конструктор с параметром
List::List(int s) {
    if (s > MAX_SIZE) throw error("List size more than MAX_SIZE\n");
    size = s;
    beg = new int[s];
    for (int i = 0; i < size; i++) beg[i] = 0;
}

// Конструктор копирования
List::List(const List& v) {
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = v.beg[i];
}

// Деструктор
List::~List() {
    if (beg != nullptr) delete[] beg;
}

// Конструктор с параметром (массив)
List::List(int s, int *mas) {
    if (s > MAX_SIZE) throw error("List size more than MAX_SIZE\n");
    size = s;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = mas[i];
}

// Операция присваивания
const List& List::operator=(const List& v) {
    if (this == &v) return *this;
    if (beg != nullptr) delete[] beg;
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = v.beg[i];
    return *this;
}

// Дружественная функция вывода
ostream& operator<<(ostream& out, const List& v) {
    if (v.size == 0) out << "Empty\n";
    else {
        for (int i = 0; i < v.size; i++) out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}

// Дружественная функция ввода
istream& operator>>(istream& in, List& v) {
    for (int i = 0; i < v.size; i++) {
        cout << ">";
        in >> v.beg[i];
    }
    return in;
}

// Доступ по индексу
int& List::operator[](int i) {
    if (i < 0) throw error("Index < 0\n");
    if (i >= size) throw error("Index >= size\n");
    return beg[i];
}

// Добавление элемента в начало списка
List List::operator+(int a) {
    if (size + 1 > MAX_SIZE) throw error("Max size exceeded when adding element\n");
    
    List temp(size + 1);
    temp.beg[0] = a; // Добавляем элемент в начало
    for (int i = 0; i < size; i++) {
        temp.beg[i + 1] = beg[i];
    }
    return temp;
}

// Добавление списка к списку (a + b)
List List::operator+(const List& b) {
    if (size + b.size > MAX_SIZE) throw error("Max size exceeded when adding list\n");
    
    List temp(size + b.size);
    // Копируем элементы первого списка
    for (int i = 0; i < size; i++) {
        temp.beg[i] = beg[i];
    }
    // Добавляем элементы второго списка в конец
    for (int i = 0; i < b.size; i++) {
        temp.beg[size + i] = b.beg[i];
    }
    return temp;
}