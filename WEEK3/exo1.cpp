#include<iostream>
#include<limits>
using namespace std;


int main() {
    int i;
    string str;
    cout << "Input a string: ";
    cin >> str;
    // cin.ignore in order to avoid that the user put a space in the string
    // otherwise, the code bug and the input string is delayed to the input integer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << str << endl;
    cout << "Input an integer number: ";
    cin >> i;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << i << endl;
    cout << "Input an integer number: ";
    cin >> i;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << i << endl;
    return 0;
}