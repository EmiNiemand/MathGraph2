project(Matrix)

add_library(${PROJECT_NAME}
        include/Matrix4x4.h src/Matrix4x4.cpp)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME}
        Vectors
        )