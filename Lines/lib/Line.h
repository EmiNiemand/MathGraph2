//
// Created by szymo on 17/12/2022.
//

#ifndef MATHGRAPH2_LINE_H
#define MATHGRAPH2_LINE_H

#include "Vector3.h"
#include "Plane.h"

class NoIntersectionException : std::exception {
};

class Line {
    Vector3 direction;
    Vector3 point;
public:
    Line(const Vector3 &point, const Vector3 &direction);

    Vector3 IntersectionPointWithLine(Line line);
    Vector3 IntersectionPointWithPlane(Plane plane);

    float CalcAngleWithLine(Line line);
    float CalcAngleWithPlane(Plane plane);
};


#endif //MATHGRAPH2_LINE_H
