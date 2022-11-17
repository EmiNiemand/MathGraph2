//
// Created by szymo on 07/11/2022.
//

#ifndef MATHGRAPH2_MATRIX4X4_H
#define MATHGRAPH2_MATRIX4X4_H


#include "Vector.h"

class Matrix4x4 {
private:
    float matrixData[16] = {0.0f};
public:
    Matrix4x4();
    Matrix4x4(float m0, float m1, float m2, float m3,
              float m4, float m5, float m6, float m7,
              float m8, float m9, float m10, float m11,
              float m12, float m13, float m14, float m15);
    Matrix4x4(const float* matrixData);
    Matrix4x4(const Matrix4x4 &mat);

    virtual ~Matrix4x4();

    const float *getMatrixData() const;

    void operator+=(const Matrix4x4& mat);
    void operator*=(float scalar);
    void operator*=(const Matrix4x4& mat);

    Matrix4x4 operator+(const Matrix4x4& mat) const;
    Matrix4x4 operator*(float scalar) const;
    Matrix4x4 operator*(const Matrix4x4& mat) const;

    void LoadIdentity();
    void Invert();
    void Transpose();
    float Det();

    void Translate(const Vector& translation);
    void Scale(const Vector& scale);
    void Scale(float scale);
    void SetRotationAxis(float angle, const Vector& axis);
    void SetRotationX(float angle);
    void SetRotationY(float angle);
    void SetRotationZ(float angle);

    std::string ToString();
};

#endif //MATHGRAPH2_MATRIX4X4_H
