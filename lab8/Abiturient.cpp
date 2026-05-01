#include "Abiturient.h"

Abiturient::Abiturient() : Person(), score(0), specialty("") {}
Abiturient::Abiturient(string N, int A, int S, string Sp) : Person(N, A), score(S), specialty(Sp) {}

void Abiturient::Show() {
    cout << "\nNAME: " << name << "\nAGE: " << age 
         << "\nSCORE: " << score << "\nSPECIALTY: " << specialty << endl;
}

void Abiturient::Input() {
    Person::Input();
    cout << "Score: "; cin >> score;
    cout << "Specialty: "; cin >> specialty;
}