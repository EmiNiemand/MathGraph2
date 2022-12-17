project(Lines)

add_library(${PROJECT_NAME} src/Line.cpp lib/Line.h src/Plane.cpp lib/Plane.h)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME}
        Vectors)