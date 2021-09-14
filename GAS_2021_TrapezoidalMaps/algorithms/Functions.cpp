#include "Functions.h"

size_t dagQuery(const cg3::Point2d &point, Dag &dag) {

    return 0;

}

size_t dagQueryForConstruction(const cg3::Segment2d &segment, Dag &dag, bool isLeftVertex) {

    size_t index;
    const cg3::Point2d point = segment.p1();
    bool found;
    index = TrapezoidalMapDataset::getPoint(point, found);
    return 0;

}

size_t dagQueryByPointId() {



}

void addSegment(const cg3::Segment2d &segment, TrapezoidalMap &trap, Dag &dag) {

    //Segment ordered by x coordinate
    cg3::Segment2d xOrderedSegment;

    if (segment.p1().x() < segment.p2().x()) {
        xOrderedSegment = segment;
    } else {
        xOrderedSegment = cg3::Segment2d(segment.p2(), segment.p1());
    }

    //Finding the intersected trapezoids
    std::vector<size_t> intersectedTrapezoids = std::vector<size_t>();
    findCrossedTrapezoids(segment, intersectedTrapezoids, dag);
    assert(intersectedTrapezoids.size() > 0);

    /*
    //Update the only intersected trapezoid
    if(intersectedTrapezoids.size() == 1) {
        updateTrapezoidAllSegmentVertex(intersectedTrapezoids[0], trap, xOrderedSegment);
    }

    //Update the two intersected trapezoids
    if(intersectedTrapezoids.size() == 2) {
        updateTrapezoidLeftSegmentVertex(intersectedTrapezoids[0], trap, xOrderedSegment);
        updateTrapezoidRightSegmentVertex(intersectedTrapezoids[1], trap, xOrderedSegment);
    }

    //Update all the intersected trapezoids
    if(intersectedTrapezoids.size() > 2) {
        updateTrapezoidLeftSegmentVertex(intersectedTrapezoids[0], trap, xOrderedSegment);

        for(std::size_t i = 1; i < intersectedTrapezoids.size() - 1; i++) {
            updateTrapezoidNoSegmentVertex(intersectedTrapezoids[i], trap, xOrderedSegment);
        }

        updateTrapezoidRightSegmentVertex(intersectedTrapezoids[intersectedTrapezoids.size() - 1], trap, xOrderedSegment);
    }
    */

}

void findCrossedTrapezoids(const cg3::Segment2d &segment, std::vector<size_t> &intersectedTrapezoids, Dag &dag) {

    assert(segment.p1().x() < segment.p2().x());
    assert(intersectedTrapezoids.size() == 0);

    bool isLeftVertex = true;
    std::size_t firstTrapezoid = dagQueryForConstruction(segment, dag, isLeftVertex);
    intersectedTrapezoids.push_back(firstTrapezoid);

}
