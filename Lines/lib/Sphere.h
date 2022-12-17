//
// Created by szymo on 17/12/2022.
//

#ifndef MATHGRAPH2_SPHERE_H
#define MATHGRAPH2_SPHERE_H

#include "Vector3.h"
#include "Line.h"

#include <vector>

class Sphere {
Vector3 center;
float radius;
public:
    Sphere(const Vector3 &center, float radius);

    std::vector<Vector3> IntersectionPointWithLine(Line line);
};


#endif //MATHGRAPH2_SPHERE_H
