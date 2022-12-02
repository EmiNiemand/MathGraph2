//
// Created by masterktos on 22.11.22.
//

#ifndef MATHGRAPH2_QUATERNION_H
#define MATHGRAPH2_QUATERNION_H


#include "Vector3.h"

class Quaternion {
private:
    Vector3 vector;
    float scalar;

    static float Pow(float a);
public:
    Quaternion();
    Quaternion(float scalar, Vector3 vector);
    Quaternion(const Quaternion &q);

    void operator+=(Quaternion other);
    void operator-=(Quaternion other);
    void operator*=(Quaternion other);
    void operator/=(Quaternion other);

    Quaternion operator+(Quaternion other);
    Quaternion operator-(Quaternion other);
    Quaternion operator*(Quaternion other);
    Quaternion operator/(Quaternion other);

    Vector3 RotateVector(const Vector3& inputVector, float angle);

    Vector3 GetVector();
    float GetScalar() const;
    Quaternion Inverse();

    std::string ToString();
};


#endif //MATHGRAPH2_QUATERNION_H
