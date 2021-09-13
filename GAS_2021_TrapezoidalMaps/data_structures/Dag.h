#ifndef DAG_H
#define DAG_H

#include <vector>
#include "DagNode.h"

class Dag {

private:
    std::vector<DagNode> dag;

public:
    Dag();

    size_t addNode(DagNode node);
    void overwriteNode(size_t id, DagNode node);

};

#endif // DAG_H