#include "Trapezoid.h"

Trapezoid::Trapezoid(size_t i) {

    id = i;
    topSide = ID_NONE;
    bottomSide = ID_NONE;
    leftSide = ID_NONE;
    rightSide = ID_NONE;
    leftUpNeighour = ID_NONE;
    leftDownNeighour = ID_NONE;
    rightUpNeighour = ID_NONE;
    rightDownNeighour = ID_NONE;

}

Trapezoid::Trapezoid(size_t i, size_t top, size_t bottom, size_t left, size_t right, size_t leftUp, size_t leftDown, size_t rightUp, size_t rightDown) {

    id = i;
    topSide = top;
    bottomSide = bottom;
    leftSide = left;
    rightSide = right;
    leftUpNeighour = leftUp;
    leftDownNeighour = leftDown;
    rightUpNeighour = rightUp;
    rightDownNeighour = rightDown;

}
