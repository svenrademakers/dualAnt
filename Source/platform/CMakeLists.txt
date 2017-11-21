cmake_minimum_required(VERSION 3.8)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	add_subdirectory(osx)
endif()
