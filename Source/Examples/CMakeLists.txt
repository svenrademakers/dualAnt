include_directories(${CMAKE_SOURCE_DIR}/External/tangram-es/core/include \ 
	${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/osx/src
	${CMAKE_SOURCE_DIR}/mapcontroller/mapviewer/tangram
	${CMAKE_SOURCE_DIR}/mapcontroller)

add_executable(dualAntApplication Main.mm ${CMAKE_SOURCE_DIR}/external/tangram-es/platforms/osx/src/platform_osx.mm ) 
target_link_libraries(dualAntApplication ${PROJECT_NAME})
target_compile_features( dualAntApplication PUBLIC cxx_generalized_initializers)

