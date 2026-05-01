#ifndef PAIR_H
#define PAIR_H
#include <iostream>

class Pair {
private:
    int first;
    double second;

public:
    // Конструкторы
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}
    Pair(const Pair& other) : first(other.first), second(other.second) {}

    // Операция присваивания
    Pair& operator=(const Pair& other) {
        if (this == &other) return *this;
        first = other.first;
        second = other.second;
        return *this;
    }

    // Перегрузка сложения с другой парой (для операции a[i] + b[i] в контейнере)
    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }

    // Перегрузка операций ввода-вывода
    friend std::ostream& operator<<(std::ostream& out, const Pair& p) {
        out << p.first << ":" << p.second;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Pair& p) {
        std::cout << "Enter first (int): ";
        in >> p.first;
        std::cout << "Enter second (double): ";
        in >> p.second;
        return in;
    }
};
#endif