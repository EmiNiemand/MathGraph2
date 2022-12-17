//
// Created by szymo on 17/12/2022.
//

#ifndef MATHGRAPH2_PLANE_H
#define MATHGRAPH2_PLANE_H

#include "Line.h"
#include "Vector3.h"

class Plane {
public:
    float a, b, c, d;
    Plane(float a, float b, float c, float d);

    Line IntersectionLineWithPlane(Plane plane);
};


#endif //MATHGRAPH2_PLANE_H
