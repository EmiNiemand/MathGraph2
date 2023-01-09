project(Raytracing)

add_library(${PROJECT_NAME}
        src/Cube.cpp include/Cube.h src/VirtualCamera.cpp include/VirtualCamera.h)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME}
        Vectors
        Matrix
        Lines)