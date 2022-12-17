//
// Created by szymo on 17/12/2022.
//

#include "../lib/Line.h"

Line::Line(const Vector3 &point, const Vector3 &direction) : point(point), direction(direction) {}

Vector3 Line::IntersectionPointWithLine(Line line) {
    Vector3 delta = line.point - point;
    Vector3 cross = Vector3::cross(direction, line.direction);

    if (std::abs(Vector3::dotProduct(delta, cross)) > 0.001) {
        throw NoIntersectionException();
    }

    float m2 = Vector3::cross(direction, line.direction).length();
    m2 *= m2;

    Vector3 cross1 = Vector3::cross(delta, line.direction);
    Vector3 cross2 = Vector3::cross(direction, line.direction);
    float s = Vector3::dotProduct(cross1, cross2) / m2;

    return point + direction * s;
}

Vector3 Line::IntersectionPointWithPlane(Plane plane) {
    float ts = plane.a * (direction.x) + plane.b * (direction.y) + plane.c * (direction.z);
    float values = -plane.d - (plane.a * (point.x) + plane.b * (point.y) + plane.c * (point.z));
    float t = values/ts;

    return Vector3(point.x + direction.x * t, point.y + direction.y * t, point.z + direction.z * t);
}

float Line::CalcAngleWithLine(Line line) {
    return Vector3::calcAngle(direction, line.direction);
}

float Line::CalcAngleWithPlane(Plane plane) {
    Vector3 normal(plane.a, plane.b, plane.c);
    float angle = M_PI / 2 - Vector3::calcAngle(normal, direction);
    return angle;
}
