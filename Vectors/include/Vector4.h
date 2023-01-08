//
// Created by szymo on 08/10/2022.
//

#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H

#include <iostream>
#include <cmath>

class Vector3;
class Matrix4x4;

class Vector4 {
public:
    float x, y, z, w;
    Vector4();
    Vector4(float x, float y, float z, float w);
    Vector4(Vector4 p1, Vector4 p2);
    Vector4(const Vector4 &v);
    Vector4(Vector3 vector3);
    ~Vector4();

    void operator+=(const Vector4& v);
    void operator-=(const Vector4& v);
    void operator*=(const float& s);
    void operator/=(const float& s);

    Vector4 operator+(const Vector4& v);
    Vector4 operator-(const Vector4& v);
    Vector4 operator*(const float& s);
    Vector4 operator/(const float& s);

    void add(Vector4 v);
    void sub(Vector4 v);
    void mul(float s);
    void div(float s);

    float length();
    void normalize();
    static Vector4 dot(Vector4& v1, Vector4& v2);
    static float dotProduct(Vector4& v1, Vector4& v2);
    static Vector4 cross(Vector4& v1, Vector4& v2);

    static float calcAngle(Vector4& v1, Vector4& v2);

    std::string toString();
};


#endif //VECTORS_VECTOR_H
