cmake_minimum_required(VERSION 3.8)
project (dualant)

add_subdirectory(mapcontroller/tangram)

add_library(dualant
	mapcontroller/MapController.cpp
	ant/AntHost.cpp
	ant/AntMessage.cpp
	ant/AntMessageFactory.cpp
	HbAlgo.cpp
	SensorSniffer.cpp)
	
target_compile_features(dualant PUBLIC cxx_default_function_template_args)

target_include_directories(dualant PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ant>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/mapcontroller/>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/etl/src>
   		$<INSTALL_INTERFACE:include/dualant>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/platform/interfaces>)#temp

 
install(FILES 
		HbAlgo.hpp
		mapcontroller/IMapViewer.hpp 
		ant/AntHost.hpp
		ant/AntMessageFactory.hpp
	DESTINATION
		include/dualant)

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

#get_target_property(dualIncludes dualant INTERFACE_INCLUDE_DIRECTORIES)
#target_include_directories(micro_tests PRIVATE ${dualIncludes})

target_link_libraries(micro_tests  dualant GTest /usr/local/lib/libgmock.a pthread )
install(TARGETS micro_tests DESTINATION bin)

#add_subdirectory (examples)



	
