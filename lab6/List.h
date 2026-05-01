#pragma once
#include <iostream>

// Структура узла двусвязного списка
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val = 0) : data(val), next(nullptr), prev(nullptr) {}
};

// Класс-итератор для последовательного доступа
class ListIterator {
    friend class List; // Дружественный класс для доступа к приватным полям
    Node* elem;
public:
    ListIterator() { elem = nullptr; }
    ListIterator(Node* node) { elem = node; }
    ListIterator(const ListIterator& it) { elem = it.elem; }
    
    // Перегруженные операции сравнения
    bool operator==(const ListIterator& it) const { return elem == it.elem; }
    bool operator!=(const ListIterator& it) const { return elem != it.elem; }
    
    // Переход к следующему элементу
    void operator++() { if (elem) elem = elem->next; }
    
    // Переход к предыдущему элементу (требование варианта 13)
    void operator--() { if (elem) elem = elem->prev; }
    
    // Операция разыменования
    int& operator*() const { return elem->data; }
};

// Класс-контейнер СПИСОК
class List {
private:
    int size;
    Node* head;
    Node* tail;

public:
    // Конструкторы и деструктор
    List();
    List(int s, int k = 0);
    List(const List& a);
    ~List();
    
    // Операция присваивания
    List& operator=(const List& a);
    
    // Требуемые операции по варианту 13:
    int& operator[](int index);            // Доступ по индексу
    List operator+(const List& a);         // Сложение элементов списков a[i]+b[i]
    List operator+(int k);                 // Добавление константы ко всем элементам
    
    // Дополнительные методы
    int getSize() const { return size; }
    
    // Операции ввода-вывода
    friend std::ostream& operator<<(std::ostream& out, const List& a);
    friend std::istream& operator>>(std::istream& in, List& a);
    
    // Методы для работы с итератором
    ListIterator first() const { return ListIterator(head); }
    ListIterator last() const { return ListIterator(tail); }
};