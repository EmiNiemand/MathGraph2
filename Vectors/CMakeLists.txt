project(Vectors)

add_library(${PROJECT_NAME}
        src/Vector4.cpp include/Vector4.h
        src/Vector3.cpp include/Vector3.h)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )
