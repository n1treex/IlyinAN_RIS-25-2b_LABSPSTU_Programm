#pragma once
#include <iostream>
using namespace std;

class Pair
{
    int first;      // первое число (int)
    double second;  // второе число (double)
public:
    // Конструкторы
    Pair() { first = 0; second = 0.0; }
    Pair(int f, double s) { first = f; second = s; }
    Pair(const Pair& p) { first = p.first; second = p.second; }
    ~Pair() {}

    // Селекторы и модификаторы
    int get_first() const { return first; }
    double get_second() const { return second; }
    void set_first(int f) { first = f; }
    void set_second(double s) { second = s; }

    // Перегруженные операции
    Pair& operator=(const Pair&);
    
    // Операции сравнения (добавлены const)
    bool operator>(const Pair& p) const;  
    bool operator<(const Pair& p) const; 
    
    // Операции декремента
    Pair& operator--();       // Префиксная: --first
    Pair operator--(int);     // Постфиксная: second--

    // Глобальные функции ввода-вывода
    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};
