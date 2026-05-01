#include "Tree.h"
#include "Person.h"
#include "Abiturient.h"

Tree::Tree() : root(nullptr) {}
Tree::~Tree() { Clear(root); }

void Tree::Clear(Node* t) {
    if (t) {
        Clear(t->left);
        Clear(t->right);
        delete t->data;
        delete t;
    }
}

void Tree::Add() {
    Object* p;
    cout << "1. Person, 2. Abiturient: ";
    int y; cin >> y;
    if (y == 1) p = new Person;
    else p = new Abiturient;
    p->Input();
    root = AddNode(root, p);
}

Node* Tree::AddNode(Node* t, Object* d) {
    if (!t) {
        t = new Node;
        t->data = d;
        t->left = t->right = nullptr;
    }
    else if (d->GetAge() < t->data->GetAge()) t->left = AddNode(t->left, d);
    else t->right = AddNode(t->right, d);
    return t;
}

void Tree::Show() {
    if (!root) cout << "Tree is empty" << endl;
    else Print(root);
}

void Tree::Print(Node* t) {
    if (t) {
        Print(t->left);
        t->data->Show();
        Print(t->right);
    }
}

void Tree::GetStats(Node* t, int& sum, int& count) {
    if (t) {
        sum += t->data->GetAge();
        count++;
        GetStats(t->left, sum, count);
        GetStats(t->right, sum, count);
    }
}

double Tree::GetAverageAge() {
    int sum = 0, count = 0;
    GetStats(root, sum, count);
    return (count == 0) ? 0 : (double)sum / count;
}

void Tree::Del() {
    Clear(root);
    root = nullptr;
    cout << "Tree cleared." << endl;
}