#include <iostream>
#include "Matrix4x4.h"

int main() {

    // IDENTITY MATRIX
    // ---------------
    Matrix4x4 matrix;
    matrix.LoadIdentity();
    printf("Identity matrix: \n%s\n", matrix.ToString().c_str());

    // MATRIX ADDITION
    // ---------------
    Matrix4x4 testAdd(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    Matrix4x4 testAdd2(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    printf("m1:\n%s\n", testAdd.ToString().c_str());
    printf("m2:\n%s\n", testAdd2.ToString().c_str());
    printf("Addition: m1 + m2 \n%s\n", (testAdd + testAdd2).ToString().c_str());
    printf("Addition: m1 + m2 \n%s\n", (testAdd2 + testAdd).ToString().c_str());

    // MATRIX TRANSPOSE
    // ----------------
    testAdd.Transpose();
    printf("m1 after transpose:\n%s\n", testAdd.ToString().c_str());
    testAdd.Transpose();

    // MATRIX DETERMINANT
    // ------------------
    printf("Determinant of identity matrix: %f\n", matrix.Det());
    printf("Determinant of transposed m1: %f\n\n", testAdd.Det());

    // MULTIPLICATION BY SCALAR
    // ------------------------
    printf("m1 multiplied by 5 (scalar):\n%s\n", (testAdd*5).ToString().c_str());

    // MULTIPLICATION BY MATRIX
    // ------------------------
    printf("m1 multiplied by m2:\n%s\n", (testAdd*testAdd2).ToString().c_str());

    // MATRIX ROTATION
    // ---------------
    matrix.LoadIdentity();
    matrix.SetRotationX(45);
    printf("Identity matrix rotated 45 degrees on X axis:\n%s\n", matrix.ToString().c_str());
    matrix.LoadIdentity();
    matrix.SetRotationY(45);
    printf("Identity matrix rotated 45 degrees on Y axis:\n%s\n", matrix.ToString().c_str());
    matrix.LoadIdentity();
    matrix.SetRotationZ(45);
    printf("Identity matrix rotated 45 degrees on Z axis:\n%s\n", matrix.ToString().c_str());

    // MATRIX INVERSION
    // ----------------
    Matrix4x4 inverseTest(56, 232, 57, 635, 34, 121, 56, 389, 111, 65, 78, 34, 24, 87, 100, 55);
    Matrix4x4 inverseTest2(56, 232, 57, 635, 34, 121, 56, 389, 111, 65, 78, 34, 24, 87, 100, 55);
    printf("m3:\n%s\n", inverseTest.ToString().c_str());
    printf("m4:\n%s\n", inverseTest2.ToString().c_str());
    inverseTest2.Invert();
    printf("m4 after inversion:\n%s\n", inverseTest2.ToString().c_str());
    printf("m3*[inverted]m4:\n%s\n", (inverseTest * inverseTest2).ToString().c_str());

    // VECTOR ROTATION
    // ---------------
    matrix.SetRotationY(90.0f);
    Vector vector(1, 0, 0, 1);
    printf("Matrix that rotates vector by 90 degrees on Y axis:\n%s\n", matrix.ToString().c_str());
    printf("Vector to rotate:\n%s\n", vector.toString().c_str());
    printf("Vector after rotation:\n%s\n\n", (matrix * vector).toString().c_str());

    // NON-COMMUTABILITY OF MATRIX MULTIPLICATION
    // ------------------------------------------
    printf("Example showing non-commutability of matrix multiplication\n");
    printf("m1 * m2: \n%s\n", (testAdd*testAdd2).ToString().c_str());
    printf("m2 * m1: \n%s\n", (testAdd2*testAdd).ToString().c_str());

    return 0;
}
