cmake_minimum_required(VERSION 3.8)

add_library(platform dummy.cpp)	

set_property(TARGET platform PROPERTY CXX_STANDARD 14)

target_compile_definitions(platform PUBLIC PLATFORM_OSX)

target_include_directories(platform PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(platform PRIVATE ${CORE_LIBRARY})

install(TARGETS platform 
	EXPORT 	platform-targets
	ARCHIVE  DESTINATION lib
  	LIBRARY  DESTINATION lib
  	RUNTIME  DESTINATION bin)

#install(EXPORT platform-targets FILE platform-config.cmake DESTINATION lib/cmake/platform)
