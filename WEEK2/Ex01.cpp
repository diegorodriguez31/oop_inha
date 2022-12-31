/*
RODRIGUEZ Diego Guilhem
Exercise 1
*/

#include <iostream>
using namespace std;

int main() {
    int country, city; 
        cout << "Select a country" << endl;
    cout << "(1)Korea, (2)Japan, (3)France, (4)Germany" << endl;
    cin >> country;
    switch (country) {
    case 1:
        cout << "Select a city: (1)Seoul, (2)Incheon" << endl;
        cin >> city;
        if (city == 1)
            cout << "You select Seoul Korea." << endl;
        else
            cout << "You select Incheon Korea." << endl;
        break;
    case 2:
        cout << "Select a city: (1)Osaka, (2)Tokyo" << endl;
        cin >> city;
        if (city == 1)
            cout << "You select Osaka Japan." << endl;
        else
            cout << "You select Tokyo Japan." << endl;
        break;
    // Adding France country with two cities: Toulouse and Paris
    case 3:
        cout << "Select a city: (1)Toulouse, (2)Paris" << endl;
        cin >> city;
        if (city == 1)
            cout << "You select Toulouse France." << endl;
        else
            cout << "You select Paris France." << endl;
        break;
    case 4:
        cout << "Select a city: (1)Berlin, (2)Munich" << endl;
        cin >> city;
        if (city == 1)
            cout << "You select Berlin Germany." << endl;
        else
            cout << "You select Munich Germany." << endl;
        break;
    default:
        cout << "Please select 1, 2 or 3 for country" << endl;
    }
    return 0;
}