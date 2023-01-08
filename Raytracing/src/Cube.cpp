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
}

void Cube::PrintCubePoints() {
    for(int i = 0; i < 8; i++) {
        printf("Point %i: [%f, %f, %f]\n", i, cubePoints[i].x, cubePoints[i].y, cubePoints[i].z);
    }
}
