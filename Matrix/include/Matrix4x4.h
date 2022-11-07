//
// Created by szymo on 07/11/2022.
//

#ifndef MATHGRAPH2_MATRIX4X4_H
#define MATHGRAPH2_MATRIX4X4_H


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

    Matrix4x4 operator+(const Matrix4x4& mat) const;
    Matrix4x4 operator*(float scalar) const;
    Matrix4x4 operator*(const Matrix4x4& mat) const;

    void LoadIdentity();
    void InvertMatrix();
    Matrix4x4 GetInverseOfMatrix() const;
    Matrix4x4 GetTransposeOfMatrix() const;
    //TODO Vec3
    /*void SetTranslationPart(const Vector3& translation);
    void SetScale(const Vector3& scale);
    void SetUniformScale(float scale);
    void SetRotationAxis(float angle, Vector3& axis);*/
    void SetRotationX(float angle);
    void SetRotationY(float angle);
    void SetRotationZ(float angle);
private:
    void setMatrixAsInverseOfGivenMatrix(const Matrix4x4& mat);
    void setMatrixAsTransposeOfGivenMatrix(const Matrix4x4& mat);
};

#endif //MATHGRAPH2_MATRIX4X4_H
