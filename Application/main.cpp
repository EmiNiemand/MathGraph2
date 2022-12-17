#include <iostream>

#include "../Lines/lib/Line.h"

int main() {
    Line line({-2, 5, 0}, {3, 1, 5});
    Line line2({-2, 4, 0}, {1, -5, 3});
    printf("Zadanie1:\n");
    try{
        printf("Intersection Point [line -> line2]: %s\n", line.IntersectionPointWithLine(line2).toString().c_str());
        printf("Intersection Point [line2 -> line]: %s\n", line.IntersectionPointWithLine(line2).toString().c_str());
    }
    catch(NoIntersectionException e) {
        printf("There is no intersecting point\n");
    }

    printf("Zadanie2:\n");
    printf("Angle between line and line2: %f\n", line.CalcAngleWithLine(line2) * 180 / M_PI);

    printf("Zadanie3:\n");
    Line line3({-2, 2, -1}, {3, -1, 2});
    Plane plane({2, 3, 3, -8});
    printf("Intersection Point [line3 -> plane]: %s\n", line3.IntersectionPointWithPlane(plane).toString().c_str());

    printf("Zadanie4:\n");
    printf("Angle between line and plane [line3 -> plane]: %f\n", line3.CalcAngleWithPlane(plane) * 180 / M_PI);
}
