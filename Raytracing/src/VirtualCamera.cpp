//
// Created by szymo on 08/01/2023.
//

#include "VirtualCamera.h"
#include "../../Matrix/include/Matrix4x4.h"

VirtualCamera::VirtualCamera(const Vector3 &position) : position(position) {
    CalculateViewPoints();
}

void VirtualCamera::CalculateViewPoints() {
    Vector4 lookingDirection(position * -1);
    Vector4 lookingDirectionNormalized = lookingDirection;
    lookingDirectionNormalized.normalize();
    Vector4 pointDistance(lookingDirection / 2);
    Vector4 viewDistance(lookingDirection * ViewRatio);

    Matrix4x4 rotation;
    rotation.LoadIdentity();
    rotation.SetRotationAxis(90, {lookingDirection.x, 0, 0, 1});
    pointDistance = rotation * pointDistance;
    rotation.LoadIdentity();
    rotation.SetRotationAxis(45, {0, 0, lookingDirection.z, 1});
    pointDistance = rotation * pointDistance;

    view[0] = Vector3(lookingDirection - viewDistance + pointDistance);
    for(int i = 1; i < 4; i++){
        rotation.LoadIdentity();
        rotation.SetRotationAxis(90, {0, 0, lookingDirection.z, 1});
        pointDistance = rotation * pointDistance;
        view[i] = Vector3(lookingDirection - viewDistance + pointDistance);
    }
    printf("[%f, %f, %f]\n", view[0].x, view[0].y, view[0].z);
    printf("[%f, %f, %f]\n", view[1].x, view[1].y, view[1].z);
    printf("[%f, %f, %f]\n", view[2].x, view[2].y, view[2].z);
    printf("[%f, %f, %f]\n", view[3].x, view[3].y, view[3].z);
}


