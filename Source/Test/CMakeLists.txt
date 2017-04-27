
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS} 
	./
	${CMAKE_CURRENT_SOURCE_DIR}/../
	${CMAKE_CURRENT_SOURCE_DIR}/../mapcontroller 
	${CMAKE_CURRENT_SOURCE_DIR}/../external/etl/src)

add_executable(micro_tests 
	test.cpp 
	TestHbAlgo.cpp 
	../ant/test/TestAntHost.cpp 
	TestSensorSniffer.cpp
	../mapcontroller/test/TestMapController.cpp)

target_link_libraries(micro_tests ${PROJECT_NAME} ${GTEST_LIBRARIES} /usr/local/lib/libgmock.a pthread )

