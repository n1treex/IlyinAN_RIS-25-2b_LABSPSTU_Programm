#include "List.h"

// Конструктор по умолчанию
List::List() : size(0), head(nullptr), tail(nullptr) {}

// Конструктор с параметрами
List::List(int s, int k) : size(s), head(nullptr), tail(nullptr) {
    for (int i = 0; i < size; ++i) {
        Node* newNode = new Node(k);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

// Конструктор копирования
List::List(const List& a) : size(a.size), head(nullptr), tail(nullptr) {
    Node* curr = a.head;
    while (curr) {
        Node* newNode = new Node(curr->data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        curr = curr->next;
    }
}

// Деструктор
List::~List() {
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = tail = nullptr;
    size = 0;
}

// Операция присваивания
List& List::operator=(const List& a) {
    if (this == &a) return *this;
    
    // Очищаем текущий список
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = tail = nullptr;
    
    // Копируем данные
    size = a.size;
    Node* a_curr = a.head;
    while (a_curr) {
        Node* newNode = new Node(a_curr->data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        a_curr = a_curr->next;
    }
    return *this;
}

// Доступ по индексу (поиск с начала списка)
int& List::operator[](int index) {
    if (index < 0 || index >= size) {
        std::cerr << "\nError! Index out of bounds\n";
        exit(1); 
    }
    Node* curr = head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }
    return curr->data;
}

// Сложение элементов двух списков a[i] + b[i]
List List::operator+(const List& a) {
    int min_size = (size < a.size) ? size : a.size;
    List result(min_size);
    
    Node* curr1 = head;
    Node* curr2 = a.head;
    Node* currRes = result.head;
    
    for (int i = 0; i < min_size; ++i) {
        currRes->data = curr1->data + curr2->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
        currRes = currRes->next;
    }
    return result;
}

// Добавление константы
List List::operator+(int k) {
    List result(size);
    Node* curr1 = head;
    Node* currRes = result.head;
    
    while (curr1 && currRes) {
        currRes->data = curr1->data + k;
        curr1 = curr1->next;
        currRes = currRes->next;
    }
    return result;
}

// Ввод
std::istream& operator>>(std::istream& in, List& a) {
    Node* curr = a.head;
    while (curr) {
        in >> curr->data;
        curr = curr->next;
    }
    return in;
}

// Вывод
std::ostream& operator<<(std::ostream& out, const List& a) {
    Node* curr = a.head;
    while (curr) {
        out << curr->data << " ";
        curr = curr->next;
    }
    return out;
}