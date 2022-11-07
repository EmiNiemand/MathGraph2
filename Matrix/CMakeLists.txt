file(GLOB_RECURSE SOURCE_FILES
        *.c
        *.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES
        *.h
        *.hpp)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} src/Matrix3n.cpp include/Matrix3n.h src/Matrix4x4.cpp include/Matrix4x4.h)