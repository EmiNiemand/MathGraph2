//
// Created by szymo on 08/01/2023.
//

#include "../include/Cube.h"

Cube::Cube(float length) {
    length = length / 2;
    cubePoints[0] = Vector3(-length, -length, -length);
    cubePoints[1] = Vector3(-length, length, -length);
    cubePoints[2] = Vector3(length, length, -length);
    cubePoints[3] = Vector3(length, -length, -length);
    cubePoints[4] = Vector3(-length, -length, length);
    cubePoints[5] = Vector3(-length, length, length);
    cubePoints[6] = Vector3(length, length, length);
    cubePoints[7] = Vector3(length, -length, length);

    cubePlanes[0] = Plane(cubePoints[0], cubePoints[1], cubePoints[2], cubePoints[3]);
    cubePlanes[1] = Plane(cubePoints[0], cubePoints[1], cubePoints[4], cubePoints[5]);
    cubePlanes[2] = Plane(cubePoints[1], cubePoints[2], cubePoints[5], cubePoints[6]);
    cubePlanes[3] = Plane(cubePoints[4], cubePoints[5], cubePoints[6], cubePoints[7]);
    cubePlanes[4] = Plane(cubePoints[0], cubePoints[3], cubePoints[4], cubePoints[7]);
    cubePlanes[5] = Plane(cubePoints[2], cubePoints[3], cubePoints[6], cubePoints[7]);
}

void Cube::PrintCubePoints() {
    for(int i = 0; i < 8; i++) {
        printf("Point %i: [%f, %f, %f]\n", i, cubePoints[i].x, cubePoints[i].y, cubePoints[i].z);
    }
}

const Vector3 *Cube::getCubePoints() const {
    return cubePoints;
}

const Plane *Cube::getCubePlanes() const {
    return cubePlanes;
}
