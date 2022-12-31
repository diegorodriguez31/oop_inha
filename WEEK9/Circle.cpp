#include <iostream>
#include <cmath>
#include "Circle.h"
#define _USE_MATH_DEFINES
using namespace std;

Circle::Circle(){
    center.set(0, 0);
    radius = 0;
}

Circle::Circle(Point center, double radius) {
    this->center = center;
    this->radius = radius;
}

Circle::Circle(double x, double y, double radius) {
    this -> center = Point(x,y);
    this -> radius = radius;
}

Circle::~Circle() {
    cout << "Destruction of class instance" << endl;
    this->info();
}

void Circle::get(Point& center, double& radius)
{
    center = this->center;
    radius = this->radius;
}

void Circle::info() {
    cout << "Center: ";
    this->center.info();
    cout << "Radius: " << this->radius << endl;
}

double Circle::area() {
    return M_PI * pow(this->radius, 2);
}

Point Circle::getCenter() {
    return Point(center);
}


double Circle::getRadius() {
    return this->radius;
}

bool Circle::isInside(const Point& p)
{
    double x_center, y_center, x_p, y_p;
    center.get(x_center, y_center);
    Point p_copy = Point(p);
    p_copy.get(x_p, y_p);
    double distance = sqrt(pow(x_center - x_p, 2) + pow(y_center - y_p, 2));
    if (distance <= radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}