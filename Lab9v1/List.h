#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 30; // максимальный размер списка

class List {
    int size; // текущий размер
    int *beg; // указатель на начало динамического массива

public:
    List() { size = 0; beg = nullptr; } // конструктор без параметров
    List(int s); // конструктор с параметром
    List(int s, int *mas); // конструктор с параметром-массивом
    List(const List& v); // конструктор копирования
    ~List(); // деструктор

    const List& operator=(const List& v); // операция присваивания
    int& operator[](int i); // доступ по индексу
    
    List operator+(int a); // добавление элемента в начало списка
    List operator+(const List& b); // добавление списка к списку

    friend ostream& operator<<(ostream& out, const List& v);
    friend istream& operator>>(istream& in, List& v);
};