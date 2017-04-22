cmake_minimum_required(VERSION 3.8)
project (PerformanceAnalytics)

set (CMAKE_CXX_STANDARD 11)
add_subdirectory (Test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/External/etl/src)
add_library(${PROJECT_NAME} HbAlgo.cpp AntParser.cpp AntMessage.cpp AntMessageFactory.cpp)
