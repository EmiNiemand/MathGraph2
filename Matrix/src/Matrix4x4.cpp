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

#pragma region Overloading operators
void Matrix4x4::operator+=(const Matrix4x4 &mat) {
    for(int i = 0; i < 16; i++){
        matrixData[i] += mat.getMatrixData()[i];
    }
}

void Matrix4x4::operator*=(float scalar) {
    for(float& data : matrixData){
        data *= scalar;
    }
}

void Matrix4x4::operator*=(const Matrix4x4 &mat) {
    //TODO: doesn't work, need to fix
    //int counter = 0;
    //for(int i = 0; i <= 15; i += 4) {
    //    for (int j = 0; j < 4; j++){
    //        matrixData[counter] = matrixData[0 + j] * mat.getMatrixData()[0 + i] + matrixData[4 + j] * mat.getMatrixData()[1 + i]
    //                + matrixData[8 + j] * mat.getMatrixData()[2 + i] + matrixData[12 + j] * mat.getMatrixData()[3 + i];
    //        counter++;
    //    }
    //}
    float matrix[16];
    matrix[0] = matrixData[0] * mat.getMatrixData()[0] + matrixData[4] * mat.getMatrixData()[1] + matrixData[8] * mat.getMatrixData()[2] + matrixData[12] * mat.getMatrixData()[3];
    matrix[1] = matrixData[1] * mat.getMatrixData()[0] + matrixData[5] * mat.getMatrixData()[1] + matrixData[9] * mat.getMatrixData()[2] + matrixData[13] * mat.getMatrixData()[3];
    matrix[2] = matrixData[2] * mat.getMatrixData()[0] + matrixData[6] * mat.getMatrixData()[1] + matrixData[10] * mat.getMatrixData()[2] + matrixData[14] * mat.getMatrixData()[3];
    matrix[3] = matrixData[3] * mat.getMatrixData()[0] + matrixData[7] * mat.getMatrixData()[1] + matrixData[11] * mat.getMatrixData()[2] + matrixData[15] * mat.getMatrixData()[3];

    matrix[4] = matrixData[0] * mat.getMatrixData()[4] + matrixData[4] * mat.getMatrixData()[5] + matrixData[8] * mat.getMatrixData()[6] + matrixData[12] * mat.getMatrixData()[7];
    matrix[5] = matrixData[1] * mat.getMatrixData()[4] + matrixData[5] * mat.getMatrixData()[5] + matrixData[9] * mat.getMatrixData()[6] + matrixData[13] * mat.getMatrixData()[7];
    matrix[6] = matrixData[2] * mat.getMatrixData()[4] + matrixData[6] * mat.getMatrixData()[5] + matrixData[10] * mat.getMatrixData()[6] + matrixData[14] * mat.getMatrixData()[7];
    matrix[7] = matrixData[3] * mat.getMatrixData()[4] + matrixData[7] * mat.getMatrixData()[5] + matrixData[11] * mat.getMatrixData()[6] + matrixData[15] * mat.getMatrixData()[7];

    matrix[8] = matrixData[0] * mat.getMatrixData()[8] + matrixData[4] * mat.getMatrixData()[9] + matrixData[8] * mat.getMatrixData()[10] + matrixData[12] * mat.getMatrixData()[11];
    matrix[9] = matrixData[1] * mat.getMatrixData()[8] + matrixData[5] * mat.getMatrixData()[9] + matrixData[9] * mat.getMatrixData()[10] + matrixData[13] * mat.getMatrixData()[11];
    matrix[10] = matrixData[2] * mat.getMatrixData()[8] + matrixData[6] * mat.getMatrixData()[9] + matrixData[10] * mat.getMatrixData()[10] + matrixData[14] * mat.getMatrixData()[11];
    matrix[11] = matrixData[3] * mat.getMatrixData()[8] + matrixData[7] * mat.getMatrixData()[9] + matrixData[11] * mat.getMatrixData()[10] + matrixData[15] * mat.getMatrixData()[11];

    matrix[12] = matrixData[0] * mat.getMatrixData()[12] + matrixData[4] * mat.getMatrixData()[13] + matrixData[14] * mat.getMatrixData()[12] + matrixData[12] * mat.getMatrixData()[15];
    matrix[13] = matrixData[1] * mat.getMatrixData()[12] + matrixData[5] * mat.getMatrixData()[13] + matrixData[14] * mat.getMatrixData()[13] + matrixData[13] * mat.getMatrixData()[15];
    matrix[14] = matrixData[2] * mat.getMatrixData()[12] + matrixData[6] * mat.getMatrixData()[13] + matrixData[14] * mat.getMatrixData()[14] + matrixData[14] * mat.getMatrixData()[15];
    matrix[15] = matrixData[3] * mat.getMatrixData()[12] + matrixData[7] * mat.getMatrixData()[13] + matrixData[14] * mat.getMatrixData()[14] + matrixData[15] * mat.getMatrixData()[15];
    std::memcpy(matrixData, matrix, 16*sizeof(float));
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat) const{
    Matrix4x4 matrix = Matrix4x4(*this);
    matrix += mat;
    return matrix;
}

Matrix4x4 Matrix4x4::operator*(const float scalar) const {
    Matrix4x4 matrix = Matrix4x4(*this);
    matrix *= scalar;
    return matrix;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat) const {
    Matrix4x4 matrix = Matrix4x4(*this);
    matrix *= mat;
    return matrix;
}
#pragma endregion

void Matrix4x4::LoadIdentity() {
    memset(matrixData, 0, 16 * sizeof(float));
    matrixData[0] = 1.0f;
    matrixData[5] = 1.0f;
    matrixData[10] = 1.0f;
    matrixData[15] = 1.0f;
}

void Matrix4x4::Invert() {
    float detValue = Det();
    if(detValue == 0) {
        printf("Cannot calculate inverse matrix [det = 0]\n");
        return;
    }

    float result[16];

    result[0] = matrixData[5] * matrixData[10] * matrixData[15] -
                matrixData[5] * matrixData[11] * matrixData[14] -
                matrixData[9] * matrixData[6] * matrixData[15] +
                matrixData[9] * matrixData[7] * matrixData[14] +
                matrixData[13] * matrixData[6] * matrixData[11] -
                matrixData[13] * matrixData[7] * matrixData[10];

    result[4] = -matrixData[4] * matrixData[10] * matrixData[15] +
                matrixData[4] * matrixData[11] * matrixData[14] +
                matrixData[8] * matrixData[6] * matrixData[15] -
                matrixData[8] * matrixData[7] * matrixData[14] -
                matrixData[12] * matrixData[6] * matrixData[11] +
                matrixData[12] * matrixData[7] * matrixData[10];

    result[8] = matrixData[4] * matrixData[9] * matrixData[15] -
                matrixData[4] * matrixData[11] * matrixData[13] -
                matrixData[8] * matrixData[5] * matrixData[15] +
                matrixData[8] * matrixData[7] * matrixData[13] +
                matrixData[12] * matrixData[5] * matrixData[11] -
                matrixData[12] * matrixData[7] * matrixData[9];

    result[12] = -matrixData[4] * matrixData[9] * matrixData[14] +
                 matrixData[4] * matrixData[10] * matrixData[13] +
                 matrixData[8] * matrixData[5] * matrixData[14] -
                 matrixData[8] * matrixData[6] * matrixData[13] -
                 matrixData[12] * matrixData[5] * matrixData[10] +
                 matrixData[12] * matrixData[6] * matrixData[9];

    result[1] = -matrixData[1] * matrixData[10] * matrixData[15] +
                matrixData[1] * matrixData[11] * matrixData[14] +
                matrixData[9] * matrixData[2] * matrixData[15] -
                matrixData[9] * matrixData[3] * matrixData[14] -
                matrixData[13] * matrixData[2] * matrixData[11] +
                matrixData[13] * matrixData[3] * matrixData[10];

    result[5] = matrixData[0] * matrixData[10] * matrixData[15] -
                matrixData[0] * matrixData[11] * matrixData[14] -
                matrixData[8] * matrixData[2] * matrixData[15] +
                matrixData[8] * matrixData[3] * matrixData[14] +
                matrixData[12] * matrixData[2] * matrixData[11] -
                matrixData[12] * matrixData[3] * matrixData[10];

    result[9] = -matrixData[0] * matrixData[9] * matrixData[15] +
                matrixData[0] * matrixData[11] * matrixData[13] +
                matrixData[8] * matrixData[1] * matrixData[15] -
                matrixData[8] * matrixData[3] * matrixData[13] -
                matrixData[12] * matrixData[1] * matrixData[11] +
                matrixData[12] * matrixData[3] * matrixData[9];

    result[13] = matrixData[0] * matrixData[9] * matrixData[14] -
                 matrixData[0] * matrixData[10] * matrixData[13] -
                 matrixData[8] * matrixData[1] * matrixData[14] +
                 matrixData[8] * matrixData[2] * matrixData[13] +
                 matrixData[12] * matrixData[1] * matrixData[10] -
                 matrixData[12] * matrixData[2] * matrixData[9];

    result[2] = matrixData[1] * matrixData[6] * matrixData[15] -
                matrixData[1] * matrixData[7] * matrixData[14] -
                matrixData[5] * matrixData[2] * matrixData[15] +
                matrixData[5] * matrixData[3] * matrixData[14] +
                matrixData[13] * matrixData[2] * matrixData[7] -
                matrixData[13] * matrixData[3] * matrixData[6];

    result[6] = -matrixData[0] * matrixData[6] * matrixData[15] +
                matrixData[0] * matrixData[7] * matrixData[14] +
                matrixData[4] * matrixData[2] * matrixData[15] -
                matrixData[4] * matrixData[3] * matrixData[14] -
                matrixData[12] * matrixData[2] * matrixData[7] +
                matrixData[12] * matrixData[3] * matrixData[6];

    result[10] = matrixData[0] * matrixData[5] * matrixData[15] -
                 matrixData[0] * matrixData[7] * matrixData[13] -
                 matrixData[4] * matrixData[1] * matrixData[15] +
                 matrixData[4] * matrixData[3] * matrixData[13] +
                 matrixData[12] * matrixData[1] * matrixData[7] -
                 matrixData[12] * matrixData[3] * matrixData[5];

    result[14] = -matrixData[0] * matrixData[5] * matrixData[14] +
                 matrixData[0] * matrixData[6] * matrixData[13] +
                 matrixData[4] * matrixData[1] * matrixData[14] -
                 matrixData[4] * matrixData[2] * matrixData[13] -
                 matrixData[12] * matrixData[1] * matrixData[6] +
                 matrixData[12] * matrixData[2] * matrixData[5];

    result[3] = -matrixData[1] * matrixData[6] * matrixData[11] +
                matrixData[1] * matrixData[7] * matrixData[10] +
                matrixData[5] * matrixData[2] * matrixData[11] -
                matrixData[5] * matrixData[3] * matrixData[10] -
                matrixData[9] * matrixData[2] * matrixData[7] +
                matrixData[9] * matrixData[3] * matrixData[6];

    result[7] = matrixData[0] * matrixData[6] * matrixData[11] -
                matrixData[0] * matrixData[7] * matrixData[10] -
                matrixData[4] * matrixData[2] * matrixData[11] +
                matrixData[4] * matrixData[3] * matrixData[10] +
                matrixData[8] * matrixData[2] * matrixData[7] -
                matrixData[8] * matrixData[3] * matrixData[6];

    result[11] = -matrixData[0] * matrixData[5] * matrixData[11] +
                 matrixData[0] * matrixData[7] * matrixData[9] +
                 matrixData[4] * matrixData[1] * matrixData[11] -
                 matrixData[4] * matrixData[3] * matrixData[9] -
                 matrixData[8] * matrixData[1] * matrixData[7] +
                 matrixData[8] * matrixData[3] * matrixData[5];

    result[15] = matrixData[0] * matrixData[5] * matrixData[10] -
                 matrixData[0] * matrixData[6] * matrixData[9] -
                 matrixData[4] * matrixData[1] * matrixData[10] +
                 matrixData[4] * matrixData[2] * matrixData[9] +
                 matrixData[8] * matrixData[1] * matrixData[6] -
                 matrixData[8] * matrixData[2] * matrixData[5];

    //TODO calc result/det to matrix data
    for(auto &value : result) {
        value = value/detValue;
    }
    std::memcpy(matrixData, result, 16*sizeof(float));
}

void Matrix4x4::Transpose() {
    /*
    0 4 8  12
    1 5 9  13
    2 6 10 14
    3 7 11 15

    0  1  2  3
    4  5  6  7
    8  9  10 11
    12 13 14 15*/

    float helper[16];
    std::memcpy(helper, matrixData, 16*sizeof(float));

    matrixData[1] = helper[4];
    matrixData[2] = helper[8];
    matrixData[3] = helper[12];
    matrixData[4] = helper[1];

    matrixData[6] = helper[9];
    matrixData[7] = helper[13];
    matrixData[8] = helper[2];
    matrixData[9] = helper[6];

    matrixData[11] = helper[14];
    matrixData[12] = helper[3];
    matrixData[13] = helper[7];
    matrixData[14] = helper[11];
}

float Matrix4x4::Det() {

    return
        matrixData[0]*matrixData[5]*matrixData[10]*matrixData[15] +
        matrixData[0]*matrixData[9]*matrixData[14]*matrixData[7] +
        matrixData[0]*matrixData[13]*matrixData[6]*matrixData[11] -
        matrixData[0]*matrixData[13]*matrixData[10]*matrixData[7] -
        matrixData[0]*matrixData[9]*matrixData[6]*matrixData[15] -
        matrixData[0]*matrixData[5]*matrixData[14]*matrixData[11] -
        matrixData[4]*matrixData[1]*matrixData[10]*matrixData[15] -
        matrixData[8]*matrixData[1]*matrixData[14]*matrixData[7] -
        matrixData[12]*matrixData[1]*matrixData[6]*matrixData[11] +
        matrixData[12]*matrixData[1]*matrixData[10]*matrixData[7] +
        matrixData[8]*matrixData[1]*matrixData[6]*matrixData[15] +
        matrixData[4]*matrixData[1]*matrixData[14]*matrixData[11] +
        matrixData[4]*matrixData[9]*matrixData[2]*matrixData[15] +
        matrixData[8]*matrixData[13]*matrixData[2]*matrixData[7] +
        matrixData[12]*matrixData[5]*matrixData[2]*matrixData[11] -
        matrixData[12]*matrixData[9]*matrixData[2]*matrixData[7] -
        matrixData[8]*matrixData[5]*matrixData[2]*matrixData[15] -
        matrixData[4]*matrixData[13]*matrixData[2]*matrixData[11] -
        matrixData[4]*matrixData[9]*matrixData[14]*matrixData[3] -
        matrixData[8]*matrixData[13]*matrixData[6]*matrixData[3] -
        matrixData[12]*matrixData[5]*matrixData[10]*matrixData[3] +
        matrixData[12]*matrixData[9]*matrixData[6]*matrixData[3] +
        matrixData[8]*matrixData[5]*matrixData[14]*matrixData[3] +
        matrixData[4]*matrixData[13]*matrixData[10]*matrixData[3];

}

void Matrix4x4::Translate(const Vector& translation) {
    matrixData[12] = translation.x;
    matrixData[12] = translation.y;
    matrixData[12] = translation.z;
}

void Matrix4x4::Scale(const Vector &scale) {
    LoadIdentity();
    matrixData[0] = scale.x;
    matrixData[5] = scale.y;
    matrixData[10] = scale.z;
}

void Matrix4x4::Scale(const float scale) {
    LoadIdentity();
    matrixData[0] = scale;
    matrixData[5] = scale;
    matrixData[10] = scale;
}

void Matrix4x4::SetRotationAxis(const float angle, const Vector &axis) {
    Vector u = axis;
    u.normalize();

    auto sinAngle = (float)std::sin(M_PI * angle / 180);
    auto cosAngle = (float)std::cos(M_PI * angle / 180);
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

std::string Matrix4x4::ToString() {
    /*
        0 4 8  12
        1 5 9  13
        2 6 10 14
        3 7 11 15
     */
    std::string returnVal =
            std::to_string(matrixData[0]) + "\t" + std::to_string(matrixData[4]) + "\t" + std::to_string(matrixData[8]) + "\t" + std::to_string(matrixData[12]) + "\n" +
            std::to_string(matrixData[1]) + "\t" + std::to_string(matrixData[5]) + "\t" + std::to_string(matrixData[9]) + "\t" + std::to_string(matrixData[13]) + "\n" +
            std::to_string(matrixData[2]) + "\t" + std::to_string(matrixData[6]) + "\t" + std::to_string(matrixData[10]) + "\t" + std::to_string(matrixData[14]) + "\n" +
            std::to_string(matrixData[3]) + "\t" + std::to_string(matrixData[7]) + "\t" + std::to_string(matrixData[11]) + "\t" + std::to_string(matrixData[15]) + "\n";
    return returnVal;
}
