#include "List.h"

List::List(int s) {
    if (s > MAX_SIZE) throw 1; // превышение размера
    size = s;
    beg = new int[s];
    for (int i = 0; i < size; i++) beg[i] = 0;
}

List::List(const List& v) {
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = v.beg[i];
}

List::~List() {
    if (beg != nullptr) delete[] beg;
}

List::List(int s, int *mas) {
    if (s > MAX_SIZE) throw 1;
    size = s;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = mas[i];
}

const List& List::operator=(const List& v) {
    if (this == &v) return *this;
    if (beg != nullptr) delete[] beg;
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++) beg[i] = v.beg[i];
    return *this;
}

ostream& operator<<(ostream& out, const List& v) {
    if (v.size == 0) out << "Empty\n";
    else {
        for (int i = 0; i < v.size; i++) out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}

istream& operator>>(istream& in, List& v) {
    for (int i = 0; i < v.size; i++) {
        cout << ">";
        in >> v.beg[i];
    }
    return in;
}

int& List::operator[](int i) {
    if (i < 0) throw 2; // отрицательный индекс
    if (i >= size) throw 3; // индекс больше или равен размеру
    return beg[i];
}

List List::operator+(int a) {
    if (size + 1 > MAX_SIZE) throw 4; // превышение MAX_SIZE при добавлении
    List temp(size + 1);
    temp.beg[0] = a; // Добавляем элемент в начало
    for (int i = 0; i < size; i++) {
        temp.beg[i + 1] = beg[i];
    }
    return temp;
}

List List::operator+(const List& b) {
    if (size + b.size > MAX_SIZE) throw 5; // превышение MAX_SIZE
    List temp(size + b.size);
    for (int i = 0; i < size; i++) {
        temp.beg[i] = beg[i];
    }
    for (int i = 0; i < b.size; i++) {
        temp.beg[size + i] = b.beg[i];
    }
    return temp;
}