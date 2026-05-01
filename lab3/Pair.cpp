#include "Pair.h"

// Перегрузка присваивания
Pair& Pair::operator=(const Pair& p)
{
    if (&p == this) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

// Перегрузка сравнения > (добавлена const)
bool Pair::operator>(const Pair& p) const
{
    // Сначала сравниваем first
    if (first > p.first) return true;
    if (first < p.first) return false;
    // Если first равны, сравниваем second
    return (second > p.second);
}

// Перегрузка сравнения < (добавлена const)
bool Pair::operator<(const Pair& p) const
{
    // Сначала сравниваем first
    if (first < p.first) return true;
    if (first > p.first) return false;
    // Если first равны, сравниваем second
    return (second < p.second);
}

// Префиксный декремент: уменьшает first
Pair& Pair::operator--()
{
    --first;
    return *this;
}

// Постфиксный декремент: уменьшает second
Pair Pair::operator--(int)
{
    Pair temp(*this);  // сохраняем текущее состояние
    second -= 1.0;     // уменьшаем второе число
    return temp;
}

// Ввод
istream& operator>>(istream& in, Pair& p)
{
    cout << "first (int)= ";
    in >> p.first;
    cout << "second (double)= ";
    in >> p.second;
    return in;
}

// Вывод
ostream& operator<<(ostream& out, const Pair& p)
{
    return (out << p.first << " : " << p.second);
}