#include <iostream>
using namespace std;

int maFunc(void* ptr) {
    int* p = (int*) ptr;
    return *p + 3;
}

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int operation(int x, int y, int(*f)(int,int)) {
    int result = (*f)(x,y);
    return result;
}

int main() {
    int *a = new (nothrow) int;
    if (a==nullptr) {
        cout << "Error allocation memory";
        return -1;
    }
    *a = 5;
    int b = maFunc(a);
    cout << b << endl;

    int c = 3;
    int d = maFunc(&c);
    cout << d << endl;

    int e = operation(b,d,sum);
    cout << e << endl;
    int f = operation(b,e,sub);
    cout << f << endl;

    delete a;
    return 0;
}