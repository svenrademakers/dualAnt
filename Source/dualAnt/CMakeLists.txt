cmake_minimum_required(VERSION 3.8)
project (dualant)

add_library(dualant
	src/MapController.cpp
	src/ant/AntHost.cpp
	src/ant/AntMessage.cpp
	src/ant/AntMessageFactory.cpp
	src/HbAlgo.cpp
	src/SensorSniffer.cpp)
	
target_compile_features(dualant PUBLIC cxx_default_function_template_args)

target_include_directories(dualant 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/ant>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/interfaces>		
		$<INSTALL_INTERFACE:include/dualant>
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/ant>)
		
target_link_libraries(dualant PUBLIC etl)

install(DIRECTORY interfaces include DESTINATION include/dualant)

install(TARGETS dualant 
		EXPORT 	dualant-targets
    	ARCHIVE  DESTINATION lib
    	LIBRARY  DESTINATION lib
    	RUNTIME  DESTINATION bin)

install(EXPORT dualant-targets FILE dualant-config.cmake DESTINATION lib/cmake/dualant)

find_package(GTest REQUIRED)
 
add_executable(micro_tests 
	test/test.cpp
	test/TestAntHost.cpp
	test/TestHbAlgo.cpp
	test/TestMapController.cpp
	test/TestSensorSniffer.cpp)
	
target_compile_features(micro_tests PUBLIC cxx_default_function_template_args)

target_link_libraries(micro_tests  dualant GTest /usr/local/lib/libgmock.a pthread )
install(TARGETS micro_tests DESTINATION bin)
