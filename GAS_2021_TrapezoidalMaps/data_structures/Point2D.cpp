#include "Point2D.h"

Point2D::Point2D() {

    x = 0;
    y = 0;

}

Point2D::Point2D(size_t _x, size_t _y) {

    x = _x;
    y = _y;

}

size_t Point2D::getX() {

    return x;

}

size_t Point2D::getY() {

    return y;

}

void Point2D::setX(size_t _x) {

    x = _x;

}

void Point2D::setY(size_t _y) {

    y = _y;

}
