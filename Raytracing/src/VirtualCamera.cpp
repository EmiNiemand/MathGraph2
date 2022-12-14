//
// Created by szymo on 08/01/2023.
//

#include "VirtualCamera.h"
#include "../../Matrix/include/Matrix4x4.h"
#include "../../Lines/include/Line.h"

VirtualCamera::VirtualCamera(const Vector3 &position) : position(position) {
}

// TODO: check in geogebra
void VirtualCamera::CalculateViewPoints() {
    Vector4 lookingDirection(position * -1);
    Vector4 pointDistance(lookingDirection / 2);

    Vector4 screenHor;
    Vector4 screenVert;
    float margin = 0.0001;
    if(std::abs(lookingDirection.x) >= margin || std::abs(lookingDirection.z) >= margin){
        Vector4 up(0, 1, 0, 1);
        screenHor = Vector4::cross(pointDistance, up);
//        printf("Hor [%f, %f, %f]\n", screenHor.x, screenHor.y, screenHor.z);
        Vector4 normalized = screenHor / Vector3(screenHor).length();
//        printf("[%f, %f, %f]\n", normalized.x, normalized.y, normalized.z);
        screenVert = Vector4::cross(pointDistance, normalized);
//        printf("Vert [%f, %f, %f]\n", screenVert.x, screenVert.y, screenVert.z);
    }
    else {
        Vector4 up(0, 0, 1, 1);
        screenHor = Vector4::cross(pointDistance, up);
//        printf("[%f, %f, %f]\n", screenHor.x, screenHor.y, screenHor.z);
        Vector4 normalized = screenHor / Vector3(screenHor).length();
//        printf("[%f, %f, %f]\n", normalized.x, normalized.y, normalized.z);
        screenVert = Vector4::cross(pointDistance, normalized);
//        printf("[%f, %f, %f]\n", screenVert.x, screenVert.y, screenVert.z);
    }

    Vector3 normalizedHor = screenHor / Vector3(screenHor).length();
//    printf("Hor length %f\n", normalizedHor.length());
    Vector3 normalizedVert = screenVert / Vector3(screenVert).length();
//    printf("Vert length %f\n", normalizedVert.length());
//    printf("Hor [%f, %f, %f]\n", normalizedHor.x, normalizedHor.y, normalizedHor.z);
//    printf("Hor [%f, %f, %f]\n", normalizedVert.x, normalizedVert.y, normalizedVert.z);
    view[0] = pointDistance * -1 + (normalizedHor + normalizedVert) * ViewRatio;
    view[1] = pointDistance * -1 - (normalizedHor + normalizedVert) * ViewRatio;

//    printf("View0 [%f, %f, %f]\n", view[0].x, view[0].y, view[0].z);
//    printf("View1 [%f, %f, %f]\n", view[1].x, view[1].y, view[1].z);
    CalculateRaycastPoints(normalizedHor, normalizedVert);
}

void VirtualCamera::CalculateRaycastPoints(Vector3 vecHor, Vector3 vecVert) {
    float length = Vector3(view[0] - view[1]).length() / std::sqrt(2) / 60;

    for(int i = 0; i < 60; i++) {
        for(int j = 0; j < 60; j++) {
            pointsToRaycast[i][j] = view[0] - (vecHor * (length * j) + vecHor * (length / 2) + vecVert * (length * i) + vecVert * (length / 2));
//            printf("Point %i %i [%f, %f, %f]\n", i, j, pointsToRaycast[i][j].x, pointsToRaycast[i][j].y, pointsToRaycast[i][j].z);
        }
    }

}

void VirtualCamera::CalculateRenderBuffer(Cube cube) {
    CalculateViewPoints();
    for(int i = 0; i < 60; i++) {
        for(int j = 0 ; j < 60; j++) {
            bool isInCube = false;
            Line line(position, pointsToRaycast[i][j]);
            for(int k = 0; k < 6; k ++) {
                isInCube = isInCube || CheckIsInCube(cube, line.IntersectionPointWithPlane(cube.getCubePlanes()[k]));
            }
            if(isInCube) {
                Buffer[i][j] = '0';
            }
            else {
                Buffer[i][j] = '.';
            }
        }
    }
}

bool VirtualCamera::CheckIsInCube(Cube cube, Vector3 point) {
    if(point.x <= cube.getCubePoints()[7].x && point.x >= cube.getCubePoints()[0].x &&
            point.y <= cube.getCubePoints()[1].y && point.y >= cube.getCubePoints()[0].y &&
            point.z <= cube.getCubePoints()[4].z && point.z >= cube.getCubePoints()[0].z) {
        return true;
    }
    return false;
}

void VirtualCamera::Render() {
    for(int i = 0; i < 60; i++) {
        for(int j = 0 ; j < 60; j++) {
            printf("%c ", Buffer[i][j]);
        }
        printf("\n");
    }
}

void VirtualCamera::Pitch(float value) {
    Matrix4x4 rotation;
    rotation.LoadIdentity();
    rotation.SetRotationX(value);
    position = rotation * position;
}

void VirtualCamera::Yaw(float value) {
    Matrix4x4 rotation;
    rotation.LoadIdentity();
    rotation.SetRotationY(value);
    position = rotation * position;
}

void VirtualCamera::Roll(float value) {
    Matrix4x4 rotation;
    rotation.LoadIdentity();
    rotation.SetRotationZ(value);
    position = rotation * position;
}

void VirtualCamera::Zoom(float value) {
    Vector3 zoom = position;
    zoom.normalize();
    zoom *= value;
    position -= zoom;
}

const Vector3 &VirtualCamera::getPosition() const {
    return position;
}

void VirtualCamera::setViewRatio(float viewRatio) {
    ViewRatio = viewRatio;
}
