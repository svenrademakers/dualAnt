cmake_minimum_required(VERSION 3.8)

#add_library(platform )

#target_include_directories(platform 
#	PUBLIC
#		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/interfaces>
#   		$<INSTALL_INTERFACE:include/platform>)
 
install(FILES 
		interfaces/SerialCommunication.h 
	DESTINATION
		include/platform)

#install(TARGETS platform 
#	EXPORT 	platform-targets
#    	ARCHIVE  DESTINATION lib
#    	LIBRARY  DESTINATION lib
#    	RUNTIME  DESTINATION bin)

#install(EXPORT platform-targets FILE platform-config.cmake DESTINATION lib/cmake/#dualant)

	
