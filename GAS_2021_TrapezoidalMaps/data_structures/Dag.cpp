#include "Dag.h"

Dag::Dag() {

    DagNode boundingBox(0, 3);
    dag.push_back(boundingBox);

}

size_t Dag::addNode(DagNode node) {

    dag.push_back(node);
    return dag.size() - 1;

}

void Dag::overwriteNode(size_t id, DagNode node){

    assert(id < dag.size());
    dag[id] = node;

}
