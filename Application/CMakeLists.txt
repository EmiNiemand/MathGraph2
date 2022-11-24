project(Application)

add_executable(${PROJECT_NAME} main.cpp testMatrix.h)

target_link_libraries(${PROJECT_NAME} Vectors Matrix Quaternion)