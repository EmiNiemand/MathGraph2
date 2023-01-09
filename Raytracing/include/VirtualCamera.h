//
// Created by szymo on 08/01/2023.
//

#ifndef MATHGRAPH2_VIRTUALCAMERA_H
#define MATHGRAPH2_VIRTUALCAMERA_H

#include "../../Vectors/include/Vector3.h"
#include "Cube.h"

class VirtualCamera {
    Vector3 position;
    Vector3 view[2];
    Vector3 pointsToRaycast[60][60];
    char Buffer[60][60];
    float ViewRatio = 1;
    float ZDeg = 0;
public:
    explicit VirtualCamera(const Vector3 &position);
    void CalculateRenderBuffer(Cube cube);
    void Render();

    const Vector3 &getPosition() const;

    void setViewRatio(float viewRatio);

    void Pitch(float value);
    void Yaw(float value);
    void Roll(float value);
    void Zoom(float value);
private:
    void CalculateViewPoints();
    void CalculateRaycastPoints(Vector3 vecHor, Vector3 vecVert);
    bool CheckIsInCube(Cube cube, Vector3 point);
};


#endif //MATHGRAPH2_VIRTUALCAMERA_H
