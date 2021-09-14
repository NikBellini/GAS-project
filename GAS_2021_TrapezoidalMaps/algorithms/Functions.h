#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cg3/geometry/point2.h>
#include <cg3/geometry/segment2.h>
#include "data_structures/Dag.h"
#include "data_structures/TrapezoidalMap.h"
#include "managers/trapezoidalmap_manager.h"

size_t dagQuery(const cg3::Point2d &point, Dag dag, TrapezoidalMapDataset dataset);
void addSegment(const cg3::Segment2d &segment, TrapezoidalMap &trap, Dag &dag, TrapezoidalMapDataset dataset);
void findCrossedTrapezoids(const cg3::Segment2d &segment, std::vector<size_t> &intersectedTrapezoids, Dag &dag);
void updateTrapezoidAllSegmentVertex(size_t trapezoidId, TrapezoidalMap &trap, const cg3::Segment2d &segment);
void updateTrapezoidNoSegmentVertex(size_t trapezoidId, TrapezoidalMap &trap, const cg3::Segment2d &segment);
void updateTrapezoidLeftSegmentVertex(size_t trapezoidId, TrapezoidalMap &trap, const cg3::Segment2d &segment);
void updateTrapezoidRightSegmentVertex(size_t trapezoidId, TrapezoidalMap &trap, const cg3::Segment2d &segment);

#endif // FUNCTIONS_H
