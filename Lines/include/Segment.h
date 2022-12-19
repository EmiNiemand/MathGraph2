//
// Created by szymo on 17/12/2022.
//

#ifndef MATHGRAPH2_SEGMENT_H
#define MATHGRAPH2_SEGMENT_H

#include "Vector3.h"

class Segment {
    Vector3 startPoint;
    Vector3 endPoint;
public:
    Segment(const Vector3 &startPoint, const Vector3 &endPoint);

    Vector3 IntersectionPointWithSegment(Segment segment);
};


#endif //MATHGRAPH2_SEGMENT_H
