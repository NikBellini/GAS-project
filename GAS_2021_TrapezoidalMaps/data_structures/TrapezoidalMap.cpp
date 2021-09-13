#include "TrapezoidalMap.h"

TrapezoidalMap::TrapezoidalMap() {

    Trapezoid boundingBox(0);
    trapezoids.push_back(boundingBox);

}

size_t TrapezoidalMap::addTrapezoid(Trapezoid t) {

    trapezoids.push_back(t);
    return trapezoids.size() - 1;

}

void TrapezoidalMap::overwriteTrapezoid(size_t i, Trapezoid t) {

    assert(i < trapezoids.size());
    trapezoids[i] = t;

}
