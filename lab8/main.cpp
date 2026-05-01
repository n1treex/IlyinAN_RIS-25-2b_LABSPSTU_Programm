#include "Dialog.h"
#include <iostream>
using namespace std;
int main() {
    Dialog D;
    cout << "Commands: m (make), + (add), - (clear), s (show), z (avg age), q (quit)" << endl;
    D.Execute();
    return 0;
}