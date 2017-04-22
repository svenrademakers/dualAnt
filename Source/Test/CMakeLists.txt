project(Unit_test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ../ ${CMAKE_CURRENT_SOURCE_DIR}/../External/etl/src)

add_executable(runAllTests test.cpp TestHbAlgo.cpp TestAntParser.cpp)
target_link_libraries(runAllTests PerformanceAnalytics ${GTEST_LIBRARIES} pthread )

