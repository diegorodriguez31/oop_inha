#include <iostream>
#include "Point.h"
using namespace std;

bool Point::isInRange(int pos) {
    return (pos >= POSMIN && pos <= POSMAX);
}

bool Point::InitMembers(int xpos, int ypos) {
    if (isInRange(xpos) && isInRange(ypos)) {
        m_x = xpos;
        m_y = ypos;
        return true;
    }
    return false;
}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}

bool Point::setX(int xpos) {
    if (isInRange(xpos)) {
        m_x = xpos;
        return true;
    }
    return false;
}

bool Point::setY(int ypos) {
    if (isInRange(ypos)) {
        m_y = ypos;
        return true;
    }
    return false;
}

void Point::printPoint() const {
    cout << "[ " << m_x << ", " << m_y << " ]" << endl;
}