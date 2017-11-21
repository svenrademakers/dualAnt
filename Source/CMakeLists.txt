cmake_minimum_required(VERSION 3.8)

set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory (external)
add_subdirectory (platform)
add_subdirectory (dualant)
add_subdirectory (mapviewer)

#message(FATAL_ERROR ${CMAKE_BINARY_DIR}/lib)
add_executable(DemoApplication MACOSX_BUNDLE examples/DemoApplication.mm)
target_link_libraries(DemoApplication PUBLIC platform dualant mapviewer ${CORE_LIBRARY} )
set_property(TARGET DemoApplication PROPERTY CXX_STANDARD 14)

install(TARGETS DemoApplication 
	EXPORT	DemoApplication-targets
   	ARCHIVE	DESTINATION lib
   	LIBRARY DESTINATION lib
   	RUNTIME DESTINATION bin
   	BUNDLE	DESTINATION bin)
	 
   