cmake_minimum_required(VERSION 3.8)

find_package(OpenGL REQUIRED)

add_library(platform ${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/common/platform_gl.cpp ${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/common/glfwApp.cpp ${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/osx/src/platform_osx.mm)	

set_property(TARGET platform PROPERTY CXX_STANDARD 14)
target_compile_definitions(platform PUBLIC PLATFORM_OSX)

target_include_directories(platform 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/osx/src>
		$<BUILD_INTERFACE:${GLFW_SOURCE_DIR}/include>)
target_link_libraries(platform PUBLIC ${CORE_LIBRARY} glfw ${OPENGL_gl_LIBRARY})

install(TARGETS platform 
	EXPORT 	platform-targets
	ARCHIVE  DESTINATION lib
  	LIBRARY  DESTINATION lib
  	RUNTIME  DESTINATION bin)