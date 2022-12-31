#include <iostream>
using namespace std;

int maFunc(void* ptr) {
    int* p = (int*) ptr;
    return *p +  3;
}

int main() {
    int* a = new int;
    *a = 5;
    int b = maFunc(a);
    cout << b << endl;

    int c = 3;
    int d = maFunc(&c);
    cout << d << endl;

    return 0;
}