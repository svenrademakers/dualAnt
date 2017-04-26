project(Unit_test)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS} ../ ${CMAKE_CURRENT_SOURCE_DIR}/../External/etl/src)

add_executable(micro_tests test.cpp TestHbAlgo.cpp TestAntHost.cpp TestSensorSniffer.cpp)

target_link_libraries(micro_tests PerformanceAnalytics ${GTEST_LIBRARIES} /usr/local/lib/libgmock.a pthread )

