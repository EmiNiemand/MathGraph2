#include <iostream>

#include "Line.h"
#include "Segment.h"
#include "Sphere.h"

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

    Line line3({-2, 2, -1}, {3, -1, 2});
    Plane plane({2, 3, 3, -8});

    //https://math.libretexts.org/Bookshelves/Calculus/Supplemental_Modules_(Calculus)/Multivariable_Calculus/1%3A_Vectors_in_Space/Intersection_of_a_Line_and_a_Plane
    printf("Zadanie3:\n");
    printf("Intersection Point [line3 -> plane]: %s\n", line3.IntersectionPointWithPlane(plane).toString().c_str());

    printf("Zadanie4:\n");
    printf("Angle between line and plane [line3 -> plane]: %f\n", line3.CalcAngleWithPlane(plane) * 180 / M_PI);

    Plane plane2({2, -1, 1, -8});
    Plane plane3({4, 3, 1, 14});

    //https://www.youtube.com/watch?v=O6O_64zIEYI
    printf("Zadanie5:\n");
    try {
        printf("Line between plane2 and plane3 [plane2 -> plane3]: %s\n", plane2.IntersectionLineWithPlane(plane3).toString().c_str());
    }
    catch(NoIntersectionException e) {
        printf("There is no intersecting line\n");
    }

    printf("Zadanie6:\n");
    printf("Angle between plane2 and plane3 [plane2 -> plane3]: %f\n", plane2.CalcAngleWithPlane(plane3) * 180 / M_PI);

    Segment segment({5, 5, 4}, {10, 10, 6});
    Segment segment2({5, 5, 5}, {10, 10, 3});

    //https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
    printf("Zadanie7:\n");
    printf("Intersection Point [segment -> segment2]: %s\n", segment.IntersectionPointWithSegment(segment2).toString().c_str());

    Sphere sphere({0, 0, 0}, std::sqrt(26));
    Line line4({3, -1, -2}, {5 - 3, 3 - (-1), -4 - (-2)});
    //http://www.ambrnet.com/TrigoCalc/Sphere/SpherLineIntersection_.htm
    printf("Zadanie 1(8):\n");
    std::vector<Vector3> result = sphere.IntersectionPointWithLine(line4);
    int i = 1;
    for (Vector3 v : result) {
        printf("Intersection Point nr[%i] [sphere -> line]: %s\n", i, v.toString().c_str());
        i++;
    }

    printf("Zadanie 2(9):\n");
    printf("I TRIED SO HARD AND GOT SO FAR BUT IN THE END THAT DOESN'T EVEN MATTER\n");

}
