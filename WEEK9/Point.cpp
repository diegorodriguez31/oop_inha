#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

void Point::info() {
    cout << "[" << x << "," << y << "]";
}

void Point::get(double& x, double& y) {
    x = this->x;
    y = this->y;
}

double Point::getx(void) {
    return x;;
}

double Point::gety(void) {
    return y;
}

Point::~Point() {
    cout << "Destruction of class instance" << endl;
    this->info();
}

void Point::set(double x, double y) {
    this->x = x;
    this->y = y;
}