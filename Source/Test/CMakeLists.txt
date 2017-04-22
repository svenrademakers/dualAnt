project(Unit_test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runAllTests test.cpp)
target_link_libraries(runAllTests ${GTEST_LIBRARIES} pthread)

