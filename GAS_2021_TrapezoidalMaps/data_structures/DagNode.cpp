#include "DagNode.h"

DagNode::DagNode(size_t t, size_t nId) {

    type = t;
    nodeId = nId;

}

void DagNode::setLeftAndRightChildId(size_t lId, size_t rId) {

    leftChildId = lId;
    rightChildId = rId;

}
