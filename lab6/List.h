#pragma once
#include <iostream>


struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val = 0) : data(val), next(nullptr), prev(nullptr) {}
};


class ListIterator {
    friend class List; 
    Node* elem;
public:
    ListIterator() { elem = nullptr; }
    ListIterator(Node* node) { elem = node; }
    ListIterator(const ListIterator& it) { elem = it.elem; }
    
    // Перегруженные операции сравнения
    bool operator==(const ListIterator& it) const { return elem == it.elem; }
    bool operator!=(const ListIterator& it) const { return elem != it.elem; }
    

    void operator++() { if (elem) elem = elem->next; }
    

    void operator--() { if (elem) elem = elem->prev; }
    
    int& operator*() const { return elem->data; }
};


class List {
private:
    int size;
    Node* head;
    Node* tail;

public:
    List();
    List(int s, int k = 0);
    List(const List& a);
    ~List();
    

    List& operator=(const List& a);
    

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
