#ifndef __TRIANGLE_H__
#define __TRIANGLE_H_

#include "Point.h"

class Triangle {
    double base;
    double height;

public:
    // Constructor
    Triangle(const double base, double height) : base(base), height(height) {}
    // Destructor
    ~Triangle() {}
    // Get the size of the triangle base
    int getBase();
    // Get the size of the triangle height
    int getHeight();
    // Get the area info of the triangle
    double area();
};
#endif