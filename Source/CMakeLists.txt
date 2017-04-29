cmake_minimum_required(VERSION 3.8)

set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory (external)
add_subdirectory (platform)
add_subdirectory (dualAnt)
add_subdirectory (mapviewer)

#add_executable(DemoApplication MACOSX_BUNDLE examples/DemoApplication.mm)
#include_directories(${CORE_INCLUDE_DIRS})
#target_link_libraries(DemoApplication PUBLIC core)
#set_property(TARGET DemoApplication PROPERTY CXX_STANDARD 14)

#install(TARGETS DemoApplication 
#	EXPORT	dualant-targets
#   	ARCHIVE	DESTINATION lib
#   	LIBRARY DESTINATION lib
#   	RUNTIME DESTINATION bin
#   	BUNDLE	DESTINATION bin)
	 
   