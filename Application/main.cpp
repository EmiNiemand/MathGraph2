#include <iostream>

#include "Quaternion.h"

int main() {
    Quaternion q1(1, Vector3(2, 3, 4));
    Quaternion q2(9, Vector3(8, 7, 6));

    printf("Q1: %s\n", q1.ToString().c_str());
    printf("Q2: %s\n\n", q2.ToString().c_str());

    printf("==================== Quaternion addition =====================\n\n");
    printf("Q1 + Q2: %s\n", (q1+q2).ToString().c_str());
    printf("Q2 + Q1: %s\n\n", (q2+q1).ToString().c_str());

    printf("=================== Quaternion subtraction ===================\n\n");
    printf("Q1 - Q2: %s\n", (q1-q2).ToString().c_str());
    printf("Q2 - Q1: %s\n\n", (q2-q1).ToString().c_str());

    printf("================= Quaternion multiplication ==================\n\n");
    printf("Q1 * Q2: %s\n", (q1*q2).ToString().c_str());
    printf("Q2 * Q1: %s\n\n", (q2*q1).ToString().c_str());

    printf("==================== Quaternion division =====================\n\n");
    printf("Q1 / Q2: %s\n", (q1/q2).ToString().c_str());
    printf("Q2 / Q1: %s\n\n", (q2/q1).ToString().c_str());



    printf("=========================== TASKS ============================\n\n");

    printf("====================== Vector rotation =======================\n\n");

    Quaternion quaternion(0, Vector3(1, 0, 0));
    Vector3 vector(-1, -1, -1);

    printf("Vector: \t%s\n", vector.toString().c_str());
    printf("Quaternion: \t%s\n\n", quaternion.ToString().c_str());
    printf("Rotating vector around x axis by 270 degrees (Rotating vector with quaternion):\n");
    printf("\t%s\n\n", quaternion.RotateVector(vector, 270).toString().c_str());

    printf("=== Showing non-commutability of quaternion multiplication ===\n\n");

    quaternion = Quaternion(1, Vector3(2, 3, 4));
    Quaternion quaternion2(4, Vector3(3, 2, 1));

    printf("Q1: %s\n", quaternion.ToString().c_str());
    printf("Q2: %s\n\n", quaternion2.ToString().c_str());
    printf("Q1 * Q2: \n\t%s\n", (quaternion * quaternion2).ToString().c_str());
    printf("Q2 * Q1: \n\t%s\n", (quaternion2 * quaternion).ToString().c_str());
}
