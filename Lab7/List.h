#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class T>
class List {
private:
    int size;
    T* data;

public:
    // Конструктор с параметрами
    List(int s, T k) {
        size = s;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = k;
        }
    }

    // Конструктор копирования
    List(const List<T>& a) {
        size = a.size;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = a.data[i];
        }
    }

    // Деструктор
    ~List() {
        delete[] data;
    }

    // Операция присваивания
    List<T>& operator=(const List<T>& a) {
        if (this == &a) return *this;
        delete[] data;
        size = a.size;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = a.data[i];
        }
        return *this;
    }

    // Операция доступа по индексу
    T& operator[](int index) {
        if (index >= 0 && index < size) return data[index];
        std::cerr << "\nОшибка! Индекс за пределами списка.\n";
        static T dummy;
        return dummy;
    }

    // Операция сложения со списком: a[i] + b[i]
    List<T> operator+(const List<T>& other) const {
        int minSize = (size < other.size) ? size : other.size;
        List<T> temp(minSize, T());
        for (int i = 0; i < minSize; ++i) {
            temp.data[i] = data[i] + other.data[i];
        }
        return temp;
    }

    // Операция добавления константы ко всем элементам
    List<T> operator+(const T& k) const {
        List<T> temp(*this);
        for (int i = 0; i < size; ++i) {
            temp.data[i] = temp.data[i] + k;
        }
        return temp;
    }

    // Определение размера (дополнительно для удобства)
    int getSize() const {
        return size;
    }

    // Операции ввода-вывода
    template <class U>
    friend std::ostream& operator<<(std::ostream& out, const List<U>& a);
    
    template <class U>
    friend std::istream& operator>>(std::istream& in, List<U>& a);
};

template <class U>
std::ostream& operator<<(std::ostream& out, const List<U>& a) {
    for (int i = 0; i < a.size; ++i) {
        out << a.data[i] << "  ";
    }
    return out;
}

template <class U>
std::istream& operator>>(std::istream& in, List<U>& a) {
    for (int i = 0; i < a.size; ++i) {
        in >> a.data[i];
    }
    return in;
}
#endif