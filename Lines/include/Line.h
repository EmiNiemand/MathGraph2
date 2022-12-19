//
// Created by szymo on 17/12/2022.
//

#ifndef MATHGRAPH2_LINE_H
#define MATHGRAPH2_LINE_H

#include "Plane.h"

class NoIntersectionException : std::exception {
};

class Line {
public:
    Vector3 direction;
    Vector3 point;

    Line();
    Line(const Vector3 &point, const Vector3 &direction);

    Vector3 IntersectionPointWithLine(Line line);
    Vector3 IntersectionPointWithPlane(Plane plane);

    float CalcAngleWithLine(Line line);
    float CalcAngleWithPlane(Plane plane);

    std::string toString();
};


#endif //MATHGRAPH2_LINE_H
