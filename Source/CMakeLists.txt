cmake_minimum_required(VERSION 3.8)
project (PerformanceAnalytics)

set (CMAKE_CXX_STANDARD 11)
add_subdirectory (Test)

add_library(${PROJECT_NAME} HbAlgo.cpp)
