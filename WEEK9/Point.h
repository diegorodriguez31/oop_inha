#ifndef __POINT_H__
#define __POINT_H__

class Point {
    double x, y;

public:
    Point();
    Point(double x, double y);
    void set(double x, double y);
    void info();
    void get(double& x, double& y);
    double getx();
    double gety();
    ~Point();
};

#endif