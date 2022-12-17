//
// Created by szymo on 17/12/2022.
//

#include "../lib/Plane.h"

Plane::Plane(float a, float b, float c, float d) : a(a), b(b), c(c), d(d) {}

Line Plane::IntersectionLineWithPlane(Plane plane) {
    return Line({1,1,1}, {1,1,1});
}
