//
// Created by szymo on 17/12/2022.
//

#include "Sphere.h"


Sphere::Sphere(const Vector3 &center, float radius) : center(center), radius(radius) {}

std::vector<Vector3> Sphere::IntersectionPointWithLine(Line line) {
    std::vector<Vector3> result;

    Vector3 v = center - line.point;

    float a = Vector3::dotProduct(line.direction, line.direction);
    float b = -2 * (line.direction.x * (center.x - line.point.x) + line.direction.y * (center.y - line.point.y) + line.direction.z * (center.z - line.point.z));
    float c = Vector3::dotProduct(v, v) - std::pow(radius, 2);

    float delta = b*b - 4*a*c;

    if(delta < 0) {
        throw NoIntersectionException();
    }
    else if(delta == 0) {
        Vector3 point;
        float t = (-b + std::sqrt(delta)) / (2 * a);
        point = {line.point.x + line.direction.x * t, line.point.y + line.direction.y * t, line.point.z + line.direction.z * t};
        result.push_back(point);
    }
    else {
        Vector3 point;
        float t = (-b + std::sqrt(delta)) / (2 * a);
        point = {line.point.x + line.direction.x * t, line.point.y + line.direction.y * t, line.point.z + line.direction.z * t};
        result.push_back(point);

        t = (-b - std::sqrt(delta)) / (2 * a);
        point = {line.point.x + line.direction.x * t, line.point.y + line.direction.y * t, line.point.z + line.direction.z * t};
        result.push_back(point);
    }

    return result;
}
