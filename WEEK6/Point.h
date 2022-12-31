#ifndef __POINT_H__
#define __POINT_H_

const int POSMIN = 0;
const int POSMAX = 100;

class Point {
    int m_x;
    int m_y;
    bool isInRange(int pos);

public:
    bool InitMembers(int xpos, int ypos);
    bool setX(int xpos);
    bool setY(int ypos);
    int getX() const;
    int getY() const;
    void printPoint() const;
};

#endif