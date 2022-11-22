project(Quaternion)

add_library(${PROJECT_NAME}
        include/Quaternion.h src/Quaternion.cpp
        )

target_include_directories( ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

target_link_libraries(${PROJECT_NAME}
        )