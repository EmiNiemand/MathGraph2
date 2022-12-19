project(Lines)

add_library(${PROJECT_NAME}
        src/Line.cpp include/Line.h
        src/Plane.cpp include/Plane.h
        src/Segment.cpp include/Segment.h
        src/Sphere.cpp include/Sphere.h)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME}
        Vectors)