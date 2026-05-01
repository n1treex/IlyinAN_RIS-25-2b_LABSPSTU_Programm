#include "Applicant.h"
#include <iostream>
#include <string>
using namespace std;

Applicant make_applicant() {
    string s;
    string i;
    int d;
    cout<<"Enter name: ";
    cin >> s;
    cout << "Enter spec: ";
    cin >> i;
    cout << "Enter res: ";
    cin >> d;
    Applicant t(s,i,d);
    return t;
}

void print_applicant(Applicant t) {
    t.show();
}

int main() {
    Applicant t1;
    t1.show();
    Applicant t2("IgnatovLevAlekseevich","SoftwareEngineering",233);
    t2.show();
    Applicant t3=t2;
    t3.set_name("KosoturovAleksanderSpacesovich");
    t3.set_spec("SoftwareEngineering");
    t3.set_res(251);
    print_applicant(t3);
    t1 = make_applicant();
    t1.show();
}