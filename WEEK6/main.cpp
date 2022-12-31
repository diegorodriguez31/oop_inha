#include <iostream>
#include "Rectangle.h"
using namespace std;

int main(){
    Point pos1;
    if(!pos1.InitMembers(-2,4))
        cout << "pos1-1: FailureofInit" << endl;
    if(!pos1.InitMembers(2,4))
        cout << "pos1-2: FailureofInit" << endl;
    Point pos2;
    if(!pos2.InitMembers(5,9))
        cout << "pos2: FailureofInit" << endl;
    
    Rectangle rec;
    if(!rec.InitMembers(pos2,pos1))
        cout << "rec-1: FailureofInit" << endl;
    rec.showRecInfo();

    Point pos3;
    pos3.InitMembers(3,6);
    cout << "pos3: [" << pos3.getX() << ", " << pos3.getY() << ']' << endl;
    if (rec.isInside(pos3)) {
        cout << "pos3 is inside the rectangle" << endl;
    } else {
        cout << "pos3 is outside the rectangle" << endl;
    }

    /*Triangle t1{ 10.5, 4.5};
    Triangle t2{ 7.0, 3.0};

    cout << "Triangle t1{ 10.5, 4.5}" << endl;
    cout << "Base: " << t1.getBase() << endl;
    cout << "Height: " << t1.getHeight() << endl;
    cout << "Area: " << t1.area() << endl << endl;

    cout << "Triangle t2{ 7.0, 3.0}" << endl;
    cout << "Base: " << t1.getBase() << endl;
    cout << "Height: " << t1.getHeight() << endl;
    cout << "Area: " << t1.area() << endl << endl;*/
    return 0;
}