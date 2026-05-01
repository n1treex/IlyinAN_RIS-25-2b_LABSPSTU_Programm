#include "List.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main() {
    try {
        List a(2);
        a[0] = 5; a[1] = 10;

        cout << "Trying negative index..." << endl;
        cout << a[-1]; // Генерация исключения
    }
    catch (error e) {
        e.what(); // Выведет: Index < 0
    }
    return 0;
}