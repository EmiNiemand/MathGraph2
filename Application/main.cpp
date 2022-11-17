#include <iostream>
#include "Matrix4x4.h"

int main() {
    Matrix4x4 matrix;
    matrix.LoadIdentity();

    Matrix4x4 test(56, 232, 57, 635, 34, 121, 56, 389, 111, 65, 78, 34, 24, 87, 100, 55);
    Matrix4x4 test2(56, 232, 57, 635, 34, 121, 56, 389, 111, 65, 78, 34, 24, 87, 100, 55);
    test.Invert();
    printf(test.ToString().c_str());
    test *= test2;
    printf("\n");
    printf(test.ToString().c_str());

    return 0;
}
