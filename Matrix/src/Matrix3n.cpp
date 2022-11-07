//
// Created by szymo on 07/11/2022.
//

#include "../include/Matrix3n.h"

Matrix3n::Matrix3n() {

}

Matrix3n::Matrix3n(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8) {
    matrixData[0] = m0;
    matrixData[1] = m3;
    matrixData[2] = m6;
    matrixData[3] = m1;
    matrixData[4] = m4;
    matrixData[5] = m7;
    matrixData[6] = m2;
    matrixData[7] = m5;
    matrixData[8] = m8;
}

Matrix3n::~Matrix3n() {

}