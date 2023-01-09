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
    Vector4 lookingDirection(position);
    Vector4 pointDistance(lookingDirection / 2);
    Vector4 viewDistance(lookingDirection / 2 * ViewRatio);

    Vector4 screenHor;
    Vector4 screenVert;
    if(std::ceil(std::abs(lookingDirection.x)) != 0 || std::ceil(std::abs(lookingDirection.z)) != 0){
        Vector4 up(0, 1, 0, 1);
        screenHor = Vector4::cross(viewDistance, up);
//        printf("[%f, %f, %f]\n", screenHor.x, screenHor.y, screenHor.z);
        Vector4 normalized = screenHor / Vector3(screenHor).length();
//        printf("[%f, %f, %f]\n", normalized.x, normalized.y, normalized.z);
        screenVert = Vector4::cross(viewDistance, normalized);
//        printf("[%f, %f, %f]\n", screenVert.x, screenVert.y, screenVert.z);
    }
    else {
        Vector4 up(0, 0, 1, 1);
        screenHor = Vector4::cross(viewDistance, up);
//        printf("[%f, %f, %f]\n", screenHor.x, screenHor.y, screenHor.z);
        Vector4 normalized = screenHor / Vector3(screenHor).length();
//        printf("[%f, %f, %f]\n", normalized.x, normalized.y, normalized.z);
        screenVert = Vector4::cross(viewDistance, normalized);
//        printf("[%f, %f, %f]\n", screenVert.x, screenVert.y, screenVert.z);
    }
    view[0] = pointDistance + screenHor + screenVert;
    view[1] = pointDistance + (screenHor + screenVert) * -1;
    printf("[%f, %f, %f]\n", view[0].x, view[0].y, view[0].z);
    printf("[%f, %f, %f]\n", view[1].x, view[1].y, view[1].z);
    CalculateRaycastPoints(screenHor, screenVert);
}

void VirtualCamera::CalculateRaycastPoints(Vector3 vecHor, Vector3 vecVert) {
    vecHor.normalize();
    vecVert.normalize();
    float length = Vector3(view[0] - view[1]).length() / std::sqrt(2) / 60;
//    printf("[%f, %f, %f]\n", length, length, length);

    for(int i = 0; i < 60; i++) {
        for(int j = 0; j < 60; j++) {
            pointsToRaycast[i][j] = view[0] - (vecHor * (length * i) + vecHor * (length / 2) + vecVert * (length * j) + vecVert * (length / 2));
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
            printf("%c", Buffer[i][j]);
        }
        printf("\n");
    }
}

void VirtualCamera::Pitch(float value) {
    Matrix4x4 rotation;
    rotation.LoadIdentity();
    rotation.SetRotationZ(value);
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
    rotation.SetRotationX(value);
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
