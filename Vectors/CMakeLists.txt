project(Vectors)

add_library(${PROJECT_NAME}
        Vector.cpp Vector.h)

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}
        )
