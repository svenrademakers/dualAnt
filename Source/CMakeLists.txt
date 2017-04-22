set (CMAKE_CXX_STANDARD 11)
project (PerformanceAnalytics)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "./install")
add_library(${PROJECT_NAME} HbAlgo.cpp)
