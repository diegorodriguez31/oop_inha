#ifndef __RECTANGLE_H__
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle {
    Point m_upLeft;
    Point m_lowRight;

public:
    bool InitMembers(const Point &ul, const Point &lr);
    void showRecInfo() const;
    bool isInside(Point point) const;
};

#endif