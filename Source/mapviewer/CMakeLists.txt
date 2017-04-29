add_library(mapviewer ${CMAKE_CURRENT_SOURCE_DIR}/MapViewerTangram.cpp)

target_include_directories(mapviewer 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<INSTALL_INTERFACE:include/dualant/mapviewer>)

target_link_libraries(mapviewer PUBLIC dualant core)

install(FILES MapViewerTangram.hpp DESTINATION include/dualant/mapviewer)
install(TARGETS mapviewer 
		EXPORT 	mapviewer-targets
    	ARCHIVE  DESTINATION lib
    	LIBRARY  DESTINATION lib
    	RUNTIME  DESTINATION bin)

#install(EXPORT mapviewer-targets FILE mapviewer-config.cmake DESTINATION lib/cmake/mapviewer)
