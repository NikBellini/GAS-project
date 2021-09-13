#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include "utils/Definitions.h"

class Trapezoid {

private:
    size_t id;
    size_t topSide;
    size_t bottomSide;
    size_t leftSide;
    size_t rightSide;
    size_t leftUpNeighour;
    size_t leftDownNeighour;
    size_t rightUpNeighour;
    size_t rightDownNeighour;

public:
    Trapezoid(size_t i);
    Trapezoid(size_t i, size_t top, size_t bottom, size_t left, size_t right, size_t leftUp, size_t leftDown, size_t rightUp, size_t rightDown);

    size_t getTopSideId();
    size_t getBottomSideId();
    size_t getLeftSideId();
    size_t getRightSideId();
    size_t getLeftUpNeighourId();
    size_t getLeftDownNeighourId();
    size_t getRightUpNeighourId();
    size_t getRightDownNeighourId();

    void setTopSideId();
    void setBottomSideId();
    void setLeftSideId();
    void setRightSideId();
    void setLeftUpNeighourId();
    void setLeftDownNeighourId();
    void setRightUpNeighourId();
    void setRightDownNeighourId();

};

#endif // TRAPEZOID_H
