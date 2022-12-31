#include "Point.h"
#include "Circle.h"
#include <iostream>
using namespace std;

int main(void) {
    cout << "Exercice 1" << endl << endl;
    double x, y;
    Point p{10.5, 20.99};
    p.info();
    p.get(x,y);

    cout << endl << x << "," << y << endl;

    cout << endl << "Exercice 2" << endl << endl;

    Circle c1;
    Circle c2 {};

    Point p2{10.5, 20.5};

    Circle c3{p2, 20.0};
    Circle c4{20.5, 10.5, 10.0};

    cout << "c1.info: "; c1.info();
    cout << "c2.info: "; c2.info();
    cout << "c3.info: "; c3.info();
    cout << "c4.info: "; c4.info();

    cout << endl << "Exercice 3" << endl << endl;

    cout << "Area of c3 : " << c3.area() << endl;
    Point cent = c3.getCenter();
    cout << "Center of c3 : " << cent.getx() << " , " << cent.gety() << endl;
    cout << "Radius od c3: " << c3.getRadius()  << endl;
    cout << "isInside : " << c4.isInside(Point{ 25.0, 8.0 }) << endl;

    return 0;
}