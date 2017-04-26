cmake_minimum_required(VERSION 3.8)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/External/tangram-es/core/include)


add_executable(testTanny MACOSX_BUNDLE hello_tangram/Main.cpp)
