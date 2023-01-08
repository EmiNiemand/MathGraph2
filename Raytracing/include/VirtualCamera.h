//
// Created by szymo on 08/01/2023.
//

#ifndef MATHGRAPH2_VIRTUALCAMERA_H
#define MATHGRAPH2_VIRTUALCAMERA_H

#include "../../Vectors/include/Vector3.h"


class VirtualCamera {
    Vector3 position;
    Vector3 view[4];
    char Buffer[60][60];
    float ViewRatio = 1;
public:
    explicit VirtualCamera(const Vector3 &position);

private:
    void CalculateViewPoints();
};


#endif //MATHGRAPH2_VIRTUALCAMERA_H
