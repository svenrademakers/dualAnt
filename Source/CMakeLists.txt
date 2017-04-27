cmake_minimum_required(VERSION 3.8)
project (dualant)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

include_directories(
	./
	${CMAKE_CURRENT_SOURCE_DIR}/external/etl/src 
	mapcontroller
	mapcontroller/mapviewer
	mapcontroller/mapviewer/tangram
	platform/interfaces)
	
add_library(${PROJECT_NAME} HbAlgo.cpp
	SensorSniffer.cpp
	ant/AntHost.cpp 
	ant/AntMessageFactory.cpp 
	ant/AntMessage.cpp 
	mapcontroller/MapController.cpp
	mapcontroller/mapviewer/tangram/MapViewerTangram.cpp)
		
add_subdirectory (test)
add_subdirectory (examples)



	
