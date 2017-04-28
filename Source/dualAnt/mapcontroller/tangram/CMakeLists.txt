
add_library(DualAntMapViewer ${CMAKE_CURRENT_SOURCE_DIR}/MapViewerTangram.cpp)
target_compile_features( DualAntMapViewer PUBLIC cxx_generalized_initializers)

target_include_directories(DualAntMapViewer 
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/tangram-es/core/deps/earcut/glfw/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/tangram-es/core/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/*.hpp>
		$<INSTALL_INTERFACE:include/dualant/mapviewer>)
	
install(FILES MapViewerTangram.hpp DESTINATION include/dualant/mapviewer)
install(TARGETS DualAntMapViewer 
	EXPORT 	DualAntMapViewer-targets
    	ARCHIVE  DESTINATION lib
    	LIBRARY  DESTINATION lib
    	RUNTIME  DESTINATION bin)

install(EXPORT DualAntMapViewer-targets FILE DualAntMapViewer-config.cmake DESTINATION lib/cmake/DualAntMapViewer)
