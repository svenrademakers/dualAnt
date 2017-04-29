
add_library(etl INTERFACE)
target_include_directories(etl INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/etl/src>)
install(TARGETS etl EXPORT etl-targets)
install(EXPORT etl-targets FILE etl-config.cmake DESTINATION lib/cmake/etl)

add_subdirectory(tangram-es)
#target_include_directories(${CORE_LIBRARY} 
#	INTERFACE
#	 	$<BUILD_INTERFACE:${GLFW_SOURCE_DIR}/include>
#   	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/common>
#    	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/osx/src>    	
#		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/tangram-es/core/src>
#		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/tangram-es/core/include/tangram>
#		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/tangram-es>)
		
#set_property(TARGET ${CORE_LIBRARY} PROPERTY IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib)
		