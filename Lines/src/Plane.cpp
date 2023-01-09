//
// Created by szymo on 17/12/2022.
//

#include "Plane.h"
#include "Line.h"

Plane::Plane() {}

Plane::Plane(Vector3 A, Vector3 B, Vector3 C, Vector3 D) {
    Vector3 v1 = B - A;
    Vector3 v2 = C - B;
    normal = Vector3::cross(v1, v2);
    Vector3 negativeNormal = normal * -1;
    a = normal.x;
    b = normal.y;
    c = normal.z;
    d = Vector3::dotProduct(negativeNormal, A);

}

Plane::Plane(float a, float b, float c, float d) : a(a), b(b), c(c), d(d) {
    normal = Vector3(a, b, c);
}

Line Plane::IntersectionLineWithPlane(Plane plane) {
    Line result;

    result.direction = Vector3::cross(normal, plane.normal);
    float directionLength = std::pow(result.direction.length(), 2);

    if (directionLength == 0.f) {
        throw NoIntersectionException();
    }

    float value = (plane.b * d - b * plane.d) / (b * plane.c - plane.b * c);

    result.point.x = 0;
    result.point.y = (-c * value - d) / b;
    result.point.z = value;

    return result;
}

float Plane::CalcAngleWithPlane(Plane plane) {
    return Vector3::calcAngle(normal, plane.normal);
}

std::string Plane::toString() {
    return std::string("[" + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "]");
}
