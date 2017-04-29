
add_library(etl INTERFACE)
target_include_directories(etl INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/etl/src>)
install(TARGETS etl EXPORT etl-targets)
install(EXPORT etl-targets FILE etl-config.cmake DESTINATION lib/cmake/etl)

#add_subdirectory(glfw)
add_subdirectory(tangram-es)
