#ifndef POINT2D_H
#define POINT2D_H

#include <unordered_map>

class Point2D {

private:
    size_t x;
    size_t y;

public:
    Point2D();
    Point2D(size_t _x, size_t _y);

    size_t getX();
    size_t getY();
    void setX(size_t _x);
    void setY(size_t _y);

};

#endif // POINT2D_H
