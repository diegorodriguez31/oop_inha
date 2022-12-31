#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include "Point.h"

class Circle {
    Point center;
    double radius;

public:
    Circle();
    Circle(Point center, double radius);
    Circle(double x, double y, double radius);
    ~Circle();
    void set(Point center, double radius);
    void info();
    double area();
    Point getCenter();
    void get(Point& center, double& radius);
    double getRadius();
    bool isInside(const Point& p);
};

#endif