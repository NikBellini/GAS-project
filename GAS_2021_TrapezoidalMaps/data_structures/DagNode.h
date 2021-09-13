#ifndef DAGNODE_H
#define DAGNODE_H

#include <cg3/geometry/point2.h>
#include "utils/Definitions.h"

class DagNode {

private:
    size_t type; //0=point, 1=segment, 2=trapezoid, 3=bounding box
    size_t nodeId;
    size_t leftChildId;
    size_t rightChildId;

public:
    DagNode(size_t nId, size_t t);

    void setLeftAndRightChildId(size_t lId, size_t rId);

};

#endif // DAGNODE_H
