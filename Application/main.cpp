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

    //cube.PrintCubePoints();

    camera.CalculateRenderBuffer(cube);
    camera.Render();


    // MAIN LOOP
    while(true) {
        char button;
        scanf("%c", &button);
        printf("Cam pos[%f %f %f]: ", camera.getPosition().x, camera.getPosition().y, camera.getPosition().z);
        if(button == 'e') {
            system("cls");
            camera.Zoom(0.5);
            camera.CalculateRenderBuffer(cube);
            camera.Render();
        }
        else if(button == 'q') {
            system("cls");
            camera.Zoom(-0.5);
            camera.CalculateRenderBuffer(cube);
            camera.Render();
        }
        else if(button == 'a') {
            system("cls");
            camera.Roll(-5);
            camera.CalculateRenderBuffer(cube);
            camera.Render();
        }
        else if(button == 'd') {
            system("cls");
            camera.Roll(5);
            camera.CalculateRenderBuffer(cube);
            camera.Render();
        }
        else if(button == 'w') {
            system("cls");
            camera.Yaw(5);
            camera.CalculateRenderBuffer(cube);
            camera.Render();
        }
        else if(button == 's') {
            system("cls");
            camera.Yaw(-5);
            camera.CalculateRenderBuffer(cube);
            camera.Render();
        }
        else if(button == 'z') {
            system("cls");
            camera.Pitch(-5);
            camera.CalculateRenderBuffer(cube);
            camera.Render();
        }
        else if(button == 'c') {
            system("cls");
            camera.Pitch(5);
            camera.CalculateRenderBuffer(cube);
            camera.Render();
        }
    }

}
