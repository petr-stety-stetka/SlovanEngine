cmake_minimum_required(VERSION 2.8.4)
project(SlovanEngine)

add_definitions(-DPC)
add_definitions(-DADDITIONAL_LOG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pthread")

set(SOURCE_FILES
src/Core/Renderer/Renderer.cpp
src/Core/Loggers/FPSLogger.cpp
src/Core/Shader/Shader.cpp
src/Core/Shader/Matrices.cpp
src/Core/ShaderPrograms/TestProgram.cpp
src/Core/VertexData/VertexArrayObject.cpp
src/Core/Constants/Constants.cpp
src/Core/Objects/GameObject.cpp
src/Core/Cameras/Camera.cpp
src/PC/Renderer/PCRenderer.cpp
src/PC/Loggers/Logger.cpp)

add_library(slovanEngine STATIC ${SOURCE_FILES})

target_link_libraries(slovanEngine ${LIBRARIES})

add_subdirectory(demo)

#install libslovanEngine.a
install(TARGETS slovanEngine DESTINATION "lib")

#install headers files
install(DIRECTORY src/Core DESTINATION "include/SlovanEngine" FILES_MATCHING PATTERN "*.h")
install(DIRECTORY src/PC DESTINATION "include/SlovanEngine" FILES_MATCHING PATTERN "*.h")

#uninstall target
configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
				"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake" IMMEDIATE @ONLY)

add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
