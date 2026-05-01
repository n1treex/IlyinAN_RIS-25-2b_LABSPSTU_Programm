#include <iostream>
#include <string>
using namespace std;

class Applicant {
    string name;
    string spec;
    int res;
public:
    Applicant();
    Applicant(string, string, int);
    Applicant(const Applicant&);
    ~Applicant();
    string get_name();
    void set_name(string);
    string get_spec();
    void set_spec(string);
    int get_res();
    void set_res(int);
    void show();
};


