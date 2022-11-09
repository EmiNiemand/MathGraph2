//
// Created by szymo on 07/11/2022.
//

#include "../include/Matrix4x4.h"
#include <cstring>
#include <cmath>

Matrix4x4::Matrix4x4() = default;

Matrix4x4::Matrix4x4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9,
                     float m10, float m11, float m12, float m13, float m14, float m15) {
    matrixData[0] = m0;
    matrixData[1] = m1;
    matrixData[2] = m2;
    matrixData[3] = m3;
    matrixData[4] = m4;
    matrixData[5] = m5;
    matrixData[6] = m6;
    matrixData[7] = m7;
    matrixData[8] = m8;
    matrixData[9] = m9;
    matrixData[10] = m10;
    matrixData[11] = m11;
    matrixData[12] = m12;
    matrixData[13] = m13;
    matrixData[14] = m14;
    matrixData[15] = m15;
}

Matrix4x4::Matrix4x4(const float* data) {
    std::memcpy(matrixData, data, 16*sizeof(float));
}

Matrix4x4::Matrix4x4(const Matrix4x4& mat) {
    std::memcpy(matrixData, mat.getMatrixData(), 16*sizeof(float));
}

Matrix4x4::~Matrix4x4() = default;

const float *Matrix4x4::getMatrixData() const {
    return matrixData;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat) const{
    return {matrixData[0] + mat.getMatrixData()[0],
            matrixData[1] + mat.getMatrixData()[1],
            matrixData[2] + mat.getMatrixData()[2],
            matrixData[3] + mat.getMatrixData()[3],
            matrixData[4] + mat.getMatrixData()[4],
            matrixData[5] + mat.getMatrixData()[5],
            matrixData[6] + mat.getMatrixData()[6],
            matrixData[7] + mat.getMatrixData()[7],
            matrixData[8] + mat.getMatrixData()[8],
            matrixData[9] + mat.getMatrixData()[9],
            matrixData[10] + mat.getMatrixData()[10],
            matrixData[11] + mat.getMatrixData()[11],
            matrixData[12] + mat.getMatrixData()[12],
            matrixData[13] + mat.getMatrixData()[13],
            matrixData[14] + mat.getMatrixData()[14],
            matrixData[15] + mat.getMatrixData()[15]};
}

Matrix4x4 Matrix4x4::operator*(const float scalar) const {
    return {matrixData[0] * scalar,
            matrixData[1] * scalar,
            matrixData[2] * scalar,
            matrixData[3] * scalar,
            matrixData[4] * scalar,
            matrixData[5] * scalar,
            matrixData[6] * scalar,
            matrixData[7] * scalar,
            matrixData[8] * scalar,
            matrixData[9] * scalar,
            matrixData[10] * scalar,
            matrixData[11] * scalar,
            matrixData[12] * scalar,
            matrixData[13] * scalar,
            matrixData[14] * scalar,
            matrixData[15] * scalar};
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat) const {
    // TODO idea to check(hope it works)
    /*float data[16];
    int counter = 0;
    for(int i = 0; i <= 15; i += 4) {
        for (int j = 0; j < 4; j++){
            data[counter] = matrixData[0 + j] * mat.getMatrixData()[0 + i] + matrixData[4 + j] * mat.getMatrixData()[1 + i]
                    + matrixData[8 + j] * mat.getMatrixData()[2 + i] + matrixData[12 + j] * mat.getMatrixData()[3 + i];
            counter++;
        }
    }
    return data; //should work*/

    return {matrixData[0] * mat.getMatrixData()[0] + matrixData[4] * mat.getMatrixData()[1] + matrixData[8] * mat.getMatrixData()[2] + matrixData[12] * mat.getMatrixData()[3],
            matrixData[1] * mat.getMatrixData()[0] + matrixData[5] * mat.getMatrixData()[1] + matrixData[9] * mat.getMatrixData()[2] + matrixData[13] * mat.getMatrixData()[3],
            matrixData[2] * mat.getMatrixData()[0] + matrixData[6] * mat.getMatrixData()[1] + matrixData[10] * mat.getMatrixData()[2] + matrixData[14] * mat.getMatrixData()[3],
            matrixData[3] * mat.getMatrixData()[0] + matrixData[7] * mat.getMatrixData()[1] + matrixData[11] * mat.getMatrixData()[2] + matrixData[15] * mat.getMatrixData()[3],

            matrixData[0] * mat.getMatrixData()[4] + matrixData[4] * mat.getMatrixData()[5] + matrixData[8] * mat.getMatrixData()[6] + matrixData[12] * mat.getMatrixData()[7],
            matrixData[1] * mat.getMatrixData()[4] + matrixData[5] * mat.getMatrixData()[5] + matrixData[9] * mat.getMatrixData()[6] + matrixData[13] * mat.getMatrixData()[7],
            matrixData[2] * mat.getMatrixData()[4] + matrixData[6] * mat.getMatrixData()[5] + matrixData[10] * mat.getMatrixData()[6] + matrixData[14] * mat.getMatrixData()[7],
            matrixData[3] * mat.getMatrixData()[4] + matrixData[7] * mat.getMatrixData()[5] + matrixData[11] * mat.getMatrixData()[6] + matrixData[15] * mat.getMatrixData()[7],

            matrixData[0] * mat.getMatrixData()[8] + matrixData[4] * mat.getMatrixData()[9] + matrixData[8] * mat.getMatrixData()[10] + matrixData[12] * mat.getMatrixData()[11],
            matrixData[1] * mat.getMatrixData()[8] + matrixData[5] * mat.getMatrixData()[9] + matrixData[9] * mat.getMatrixData()[10] + matrixData[13] * mat.getMatrixData()[11],
            matrixData[2] * mat.getMatrixData()[8] + matrixData[6] * mat.getMatrixData()[9] + matrixData[10] * mat.getMatrixData()[10] + matrixData[14] * mat.getMatrixData()[11],
            matrixData[3] * mat.getMatrixData()[8] + matrixData[7] * mat.getMatrixData()[9] + matrixData[11] * mat.getMatrixData()[10] + matrixData[15] * mat.getMatrixData()[11],

            matrixData[0] * mat.getMatrixData()[12] + matrixData[4] * mat.getMatrixData()[13] + matrixData[14] * mat.getMatrixData()[12] + matrixData[12] * mat.getMatrixData()[15],
            matrixData[1] * mat.getMatrixData()[12] + matrixData[5] * mat.getMatrixData()[13] + matrixData[14] * mat.getMatrixData()[13] + matrixData[13] * mat.getMatrixData()[15],
            matrixData[2] * mat.getMatrixData()[12] + matrixData[6] * mat.getMatrixData()[13] + matrixData[14] * mat.getMatrixData()[14] + matrixData[14] * mat.getMatrixData()[15],
            matrixData[3] * mat.getMatrixData()[12] + matrixData[7] * mat.getMatrixData()[13] + matrixData[14] * mat.getMatrixData()[14] + matrixData[15] * mat.getMatrixData()[15]
    };

}

void Matrix4x4::LoadIdentity() {
    memset(matrixData, 0, 16 * sizeof(float));
    matrixData[0] = 1.0f;
    matrixData[5] = 1.0f;
    matrixData[10] = 1.0f;
    matrixData[15] = 1.0f;
}

// TODO make it for 4x4 matrix
void Matrix4x4::setMatrixAsInverseOfGivenMatrix(const Matrix4x4& mat) {
    float t1 = mat.getMatrixData()[0] * mat.getMatrixData()[4];
    float t2 = mat.getMatrixData()[0] * mat.getMatrixData()[7];
    float t3 = mat.getMatrixData()[3] * mat.getMatrixData()[1];
    float t4 = mat.getMatrixData()[6] * mat.getMatrixData()[1];
    float t5 = mat.getMatrixData()[3] * mat.getMatrixData()[2];
    float t6 = mat.getMatrixData()[6] * mat.getMatrixData()[2];

    float det = t1 * mat.getMatrixData()[8] - t2 * mat.getMatrixData()[5] - t3 * mat.getMatrixData()[8] +
            t4 * mat.getMatrixData()[5] + t5 * mat.getMatrixData()[7] - t6 * mat.getMatrixData()[4];

    if(det == 0.0f) return;

    float invd = 1.0f / det;

    float m0 = (mat.getMatrixData()[4] * mat.getMatrixData()[8] - mat.getMatrixData()[7] * mat.getMatrixData()[5]) * invd;
    float m3 = -(mat.getMatrixData()[3] * mat.getMatrixData()[8] - mat.getMatrixData()[6] * mat.getMatrixData()[5]) * invd;
    float m6 = (mat.getMatrixData()[3] * mat.getMatrixData()[7] - mat.getMatrixData()[6] * mat.getMatrixData()[4]) * invd;
    float m1 = -(mat.getMatrixData()[1] * mat.getMatrixData()[8] - mat.getMatrixData()[7] * mat.getMatrixData()[2]) * invd;
    float m4 = (mat.getMatrixData()[0] * mat.getMatrixData()[8] - t6) * invd;
    float m7 = -(t2 - t4) * invd;
    float m2 = (mat.getMatrixData()[1] * mat.getMatrixData()[5] - mat.getMatrixData()[4] * mat.getMatrixData()[2]) * invd;
    float m5 = -(mat.getMatrixData()[0] * mat.getMatrixData()[5] - t5) * invd;
    float m8 = (t1 - t3) * invd;

    matrixData[0] = m0;
    matrixData[3] = m3;
    matrixData[6] = m6;
    matrixData[1] = m1;
    matrixData[4] = m4;
    matrixData[7] = m7;
    matrixData[2] = m2;
    matrixData[5] = m5;
    matrixData[8] = m8;
}

void Matrix4x4::InvertMatrix() {
    setMatrixAsInverseOfGivenMatrix(*this);
}

Matrix4x4 Matrix4x4::GetInverseOfMatrix() const {
    Matrix4x4 result;
    result.setMatrixAsInverseOfGivenMatrix(*this);
    return result;
}

void Matrix4x4::setMatrixAsTransposeOfGivenMatrix(const Matrix4x4 &mat) {
   /*
    0 4 8  12
    1 5 9  13
    2 6 10 14
    3 7 11 15

    0  1  2  3
    4  5  6  7
    8  9  10 11
    12 13 14 15*/

    matrixData[1] = mat.getMatrixData()[4];
    matrixData[2] = mat.getMatrixData()[8];
    matrixData[3] = mat.getMatrixData()[12];
    matrixData[4] = mat.getMatrixData()[1];

    matrixData[6] = mat.getMatrixData()[9];
    matrixData[7] = mat.getMatrixData()[13];
    matrixData[8] = mat.getMatrixData()[2];
    matrixData[9] = mat.getMatrixData()[6];

    matrixData[11] = mat.getMatrixData()[14];
    matrixData[12] = mat.getMatrixData()[3];
    matrixData[13] = mat.getMatrixData()[7];
    matrixData[14] = mat.getMatrixData()[11];
}

Matrix4x4 Matrix4x4::GetTransposeOfMatrix() const {
    Matrix4x4 result;
    result.setMatrixAsTransposeOfGivenMatrix(*this);
    return result;
}

void Matrix4x4::SetTranslationPart(const Vector& translation) {
    matrixData[12] = translation.x;
    matrixData[12] = translation.y;
    matrixData[12] = translation.z;
}

void Matrix4x4::SetScale(const Vector &scale) {
    LoadIdentity();
    matrixData[0] = scale.x;
    matrixData[5] = scale.y;
    matrixData[10] = scale.z;
}

void Matrix4x4::SetUniformScale(const float scale) {
    LoadIdentity();
    matrixData[0] = scale;
    matrixData[5] = scale;
    matrixData[10] = scale;
}

void Matrix4x4::SetRotationAxis(const float angle, const Vector &axis) {
    Vector3 u = axis.getNormalized();

    float sinAngle = std::sin(M_PI * angle / 180);
    float cosAngle = std::cos(M_PI * angle / 180);
    float oneMinusCosAngle = 1.0f - cosAngle;

    LoadIdentity();

    matrixData[0] = u.x * u.x + cosAngle * (1 - (u.x * u.x));
    matrixData[4] = u.x * u.y * oneMinusCosAngle - sinAngle * u.z;
    matrixData[8] = u.x * u.z * oneMinusCosAngle + sinAngle * u.y;

    matrixData[1] = u.x * u.y * oneMinusCosAngle + sinAngle * u.z;
    matrixData[5] = u.y * u.y + cosAngle * (1 - (u.y * u.y));
    matrixData[9] = u.y * u.z * oneMinusCosAngle - sinAngle * u.x;

    matrixData[2] = u.x * u.z * oneMinusCosAngle - sinAngle * u.y;
    matrixData[6] = u.y * u.z *oneMinusCosAngle + sinAngle * u.x;
    matrixData[10] = u.z * u.z + cosAngle * (1 - (u.z * u.z));
}

void Matrix4x4::SetRotationX(const float angle) {
    LoadIdentity();

    matrixData[5] = (float)std::cos(M_PI * angle / 180);
    matrixData[6] = (float)std::sin(M_PI * angle / 180);

    matrixData[9] = -matrixData[6];
    matrixData[10] = matrixData[5];
}

void Matrix4x4::SetRotationY(const float angle) {
    LoadIdentity();

    matrixData[0] = (float)std::cos(M_PI * angle / 180);
    matrixData[2] = -(float)std::sin(M_PI * angle / 180);

    matrixData[8] = -matrixData[2];
    matrixData[10] = matrixData[0];
}

void Matrix4x4::SetRotationZ(const float angle) {
    LoadIdentity();

    matrixData[0] = (float)std::cos(M_PI * angle / 180);
    matrixData[1] = (float)std::sin(M_PI * angle / 180);

    matrixData[4] = -matrixData[1];
    matrixData[5] = matrixData[0];
}

