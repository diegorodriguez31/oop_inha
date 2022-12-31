/*
RODRIGUEZ Diego Guilhem
Exercise 2
*/

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int x;
    int max = INT_MIN;
    int min = INT_MAX;
    cout << "Type an integer number:";
    cin >> max;
    min = max;
    for (int i = 1; i < 10; i++) {
        cout << "Type an integer number:";
        cin >> x;
        if (x > max)
            max = x;
        if (x < min)
            min = x;
    }
    cout << "The maximum number you typed is " << max << endl;
    cout << "The minimum number you typed is " << min << endl;
    return 0;
}
