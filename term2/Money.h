#pragma once
class Money {
public:
    int first;
    int second;

    bool Init(int, int);
    void Read();
    void Show();
    int summa();
};

Money make_Money(int, int);


