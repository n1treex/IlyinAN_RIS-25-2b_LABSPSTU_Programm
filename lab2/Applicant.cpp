#include "Applicant.h"
#include <iostream>
#include <string>
using namespace std;

Applicant::Applicant() {
    name = "";
    spec = "";
    res = 0;
}

Applicant::Applicant(string N, string K, int S) {
    name = N;
    spec = K;
    res = S;
    cout<< "Constructor with parameters for an object"<<this<<endl;
}

Applicant::Applicant(const Applicant &t) {
    name = t.name;
    spec = t.spec;
    res = t.res;
    cout << "Copy constructor for an object"<<this<<endl;
}

Applicant::~Applicant() {
    cout << "Destructor for an object"<<this<<endl;
}

string Applicant::get_name() {
    return name;
}

string Applicant::get_spec() {
    return spec;
}

int Applicant::get_res() {
    return res;
}

void Applicant::set_name(string N) {
    name = N;
}
void Applicant::set_spec(string K) {
    spec = K;
}
void Applicant::set_res(int S) {
    res = S;
}

void Applicant::show() {
    cout<<"name: "<<name<<endl;
    cout<<"spec: "<<spec<<endl;
    cout<<"res: "<<res<<endl;
}