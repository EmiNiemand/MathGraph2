//
// Created by szymo on 17/12/2022.
//

#include "Segment.h"
#include "Line.h"

Segment::Segment(const Vector3 &startPoint, const Vector3 &endPoint) : startPoint(startPoint), endPoint(endPoint) {}

Vector3 Segment::IntersectionPointWithSegment(Segment segment) {
    Vector3 qMinusP = segment.startPoint - startPoint;
    Vector3 s = segment.endPoint - segment.startPoint;
    Vector3 r = endPoint - startPoint;

    Vector3 result = startPoint + r * (Vector3::cross(qMinusP, s).length() / Vector3::cross(r, s).length());

    return result;
}
