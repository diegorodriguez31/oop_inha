#include <iostream>
#include "Rectangle.h"
using namespace std;

// InitMember and exchange points if necessary
bool Rectangle::InitMembers(const Point& ul, const Point& lr) {
    int minX, maxX, minY, maxY = 0;
    cout << "Before" << endl;
    ul.printPoint();
    lr.printPoint();
    try {   
        if (ul.getX() > lr.getX() || ul.getY() > lr.getY()) {
            if (lr.getX() < ul.getX()) {
                minX = lr.getX();
                maxX = ul.getX();
            } else {
                minX = ul.getX();
                maxX = lr.getX();
            }
            if (lr.getY() > ul.getY()) {
                minY = ul.getY();
                maxY = lr.getY();
            } else {
                minY = lr.getY();
                maxY = ul.getY();
            }
        m_upLeft.InitMembers(minX, maxY);
        m_lowRight.InitMembers(maxX, minY);
        cout << "After" <<endl;
        m_lowRight.printPoint();
        m_upLeft.printPoint();
        return true;
    } else {
        m_upLeft = ul;
        m_lowRight = lr;
        return true;
    }
    } catch (int e) {
        return false;
    }
}

void Rectangle::showRecInfo() const {
    cout << "Upper left: " << '[' << m_upLeft.getX() << ", " << m_upLeft.getY() << ']' << endl;
    cout << "Lower right: " << '[' << m_lowRight.getX() << ", " << m_lowRight.getY() << ']' << endl;
}

bool Rectangle::isInside(Point point) const {
    if (point.getX() > m_upLeft.getX() && point.getX() < m_lowRight.getX() && point.getY() > m_lowRight.getY() && point.getY() < m_upLeft.getY()) {
        return true;
    } else {
        return false;
    }
}