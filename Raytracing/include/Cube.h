//
// Created by szymo on 08/01/2023.
//

#ifndef MATHGRAPH2_CUBE_H
#define MATHGRAPH2_CUBE_H


#include "../../Vectors/include/Vector3.h"

class Cube {
    Vector3 cubePoints[8];
public:
    Cube(float length);

    void PrintCubePoints();
};


#endif //MATHGRAPH2_CUBE_H
