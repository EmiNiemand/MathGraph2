//
// Created by szymo on 17/12/2022.
//

#ifndef MATHGRAPH2_PLANE_H
#define MATHGRAPH2_PLANE_H

#include "Vector3.h"

class Line;

class Plane {
public:

    float a, b, c, d;
    Vector3 normal;

    Plane();
    Plane(float a, float b, float c, float d);
    Plane(Vector3 A, Vector3 B, Vector3 C, Vector3 D);

    Line IntersectionLineWithPlane(Plane plane);
    float CalcAngleWithPlane(Plane plane);

    std::string toString();
};


#endif //MATHGRAPH2_PLANE_H
