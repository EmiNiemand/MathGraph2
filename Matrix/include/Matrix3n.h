//
// Created by szymo on 07/11/2022.
//

#ifndef MATHGRAPH2_MATRIX3N_H
#define MATHGRAPH2_MATRIX3N_H


class Matrix3n {
private:
    float matrixData[9] = {0.0};
public:
    Matrix3n();
    // TODO change to vector / list for obvious reason
    Matrix3n(float m0, float m3, float m6,
             float m1, float m4, float m7,
             float m2, float m5, float m8);

    virtual ~Matrix3n();

    // TODO no idea wtf is this, but need to discuss it
//    Matrix3n& operator=(const R4DMatrix3n& value);
};


#endif //MATHGRAPH2_MATRIX3N_H
