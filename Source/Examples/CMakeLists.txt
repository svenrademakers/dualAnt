cmake_minimum_required(VERSION 3.8)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/External/tangram-es/core/include)

add_executable(dualAntApplication hello_tangram/Main.cpp) 
target_link_libraries(dualAntApplication ${PROJECT_NAME})

