/*
RODRIGUEZ Diego Guilhem
Exercise 3
*/

#include <iostream>
using namespace std;

// Function prototype (declaration)
int add(int, int);
int multiplication(int, int);

int main()
{
    int num1, num2, sum, mult;
    cout << "Enters two numbers to add: ";
    cin >> num1 >> num2;

    // Function call
    sum = add(num1, num2);
    cout << "Sum = " << sum << endl;

    // Using multiplication
    mult = multiplication(num1, num2);
    cout << "Product = " << mult << endl;
    return 0;
}

// Function definition
int add(int a, int b)
{
    int add;
    add = a + b;

    // Return statement
    return add;
}

/*
Multiplication function
a: first member
b: second member
*/
int multiplication(int a, int b) {
    return a*b;
}