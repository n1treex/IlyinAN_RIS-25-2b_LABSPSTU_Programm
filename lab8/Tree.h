#pragma once
#include "Object.h"

struct Node {
    Object* data;
    Node* left;
    Node* right;
};

class Tree {
protected:
    Node* root;
    void Clear(Node* t);
    void Print(Node* t);
    Node* AddNode(Node* t, Object* d);
    void GetStats(Node* t, int& sum, int& count);
public:
    Tree();
    virtual ~Tree();
    void Add();
    void Del();
    void Show();
    void HandleEvent(const TEvent& e);
    double GetAverageAge();
};