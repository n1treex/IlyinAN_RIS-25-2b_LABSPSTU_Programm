#include "Person.h"

Person::Person() : name(""), age(0) {}
Person::Person(string N, int A) : name(N), age(A) {}
Person::~Person() {}

void Person::Show() {
    cout << "\nNAME: " << name << "\nAGE: " << age << endl;
}

void Person::Input() {
    cout << "\nName: "; cin >> name;
    cout << "Age: "; cin >> age;
}

void Person::HandleEvent(const TEvent& e) {
    if (e.what == evMessage) {
        switch (e.command) {
            case cmAverageAge:
           
                break;
        }
    }
}
