#include <iostream>

#include "Line.h"
#include "Segment.h"
#include "Sphere.h"
#include "Cube.h"
#include "VirtualCamera.h"

int main() {
    float length;
    printf("Enter cube length:");
    scanf("%f", &length);

    float x,y,z;
    printf("Enter position of camera:");
    scanf("%f %f %f", &x, &y, &z);

    Cube cube(length);
    VirtualCamera camera({x, y, z});

    cube.PrintCubePoints();

    // MAIN LOOP
    while(true) {
        //system("cls");
    }

}
