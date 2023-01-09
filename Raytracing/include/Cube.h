//
// Created by szymo on 08/01/2023.
//

#ifndef MATHGRAPH2_CUBE_H
#define MATHGRAPH2_CUBE_H


#include "../../Vectors/include/Vector3.h"
#include "../../Lines/include/Plane.h"

class Cube {
    Vector3 cubePoints[8];
    Plane cubePlanes[6];
public:
    Cube(float length);

    void PrintCubePoints();

    const Vector3 *getCubePoints() const;

    const Plane *getCubePlanes() const;
};


#endif //MATHGRAPH2_CUBE_H
