#ifndef TRAPEZOIDALMAP_H
#define TRAPEZOIDALMAP_H

#include <vector>
#include "Trapezoid.h"

class TrapezoidalMap {

private:
    std::vector<Trapezoid> trapezoids;

public:
    TrapezoidalMap();

    size_t addTrapezoid(Trapezoid t);
    void overwriteTrapezoid(size_t i, Trapezoid t);

};

#endif // TRAPEZOIDALMAP_H
