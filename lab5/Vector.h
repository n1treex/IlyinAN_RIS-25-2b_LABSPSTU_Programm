#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector
{
private:
    Object** beg; // указатель на первый элемент вектора
    int size;     // размер
    int cur;      // текущая позиция
public:
    Vector(void);
    Vector(int);
    ~Vector(void);
    void Add(Object*);
    friend ostream& operator<<(ostream& out, const Vector& v);
};