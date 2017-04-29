cmake_minimum_required(VERSION 3.8)

add_library(platform ${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/osx/src/platform_osx.mm)	

set_property(TARGET platform PROPERTY CXX_STANDARD 14)
target_compile_definitions(platform PUBLIC PLATFORM_OSX)

target_link_libraries(platform PRIVATE ${CORE_LIBRARY})

install(TARGETS platform 
	EXPORT 	platform-targets
	ARCHIVE  DESTINATION lib
  	LIBRARY  DESTINATION lib
  	RUNTIME  DESTINATION bin)

#install(EXPORT platform-targets FILE platform-config.cmake DESTINATION lib/cmake/platform)
