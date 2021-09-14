#ifndef DAGNODE_H
#define DAGNODE_H

#include <cg3/geometry/point2.h>
#include "utils/Definitions.h"

class DagNode {

private:
    size_t type; //0=point, 1=segment, 2=trapezoid, 3=bounding box
    size_t nodeId; //Contains the index of the point, the segment or the trapezoid
    size_t leftChildId; //Contains the index of the left child in the DAG
    size_t rightChildId; //Contains the index of the right child in the DAG

public:
    DagNode(size_t nId, size_t t);

    void setLeftAndRightChildId(size_t lId, size_t rId);
    size_t getNodeType();
    size_t getNodeId();
    size_t getNodeLeftChildId();
    size_t getNodeRightChildId();

};

#endif // DAGNODE_H
