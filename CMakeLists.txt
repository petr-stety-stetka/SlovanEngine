cmake_minimum_required(VERSION 2.8.4)
project(SlovanEngine)

add_definitions(-DPC)
add_definitions(-DADDITIONAL_LOG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pthread")

set(SOURCE_FILES
SlovanEngine/Core/Renderer/Renderer.cpp
SlovanEngine/Core/Loggers/FPSLogger.cpp
SlovanEngine/Core/Shader/Shader.cpp
SlovanEngine/Core/Shader/Matrices.cpp
SlovanEngine/Core/ShaderPrograms/TestProgram.cpp
SlovanEngine/Core/VertexData/VertexArrayObject.cpp
SlovanEngine/Core/Constants/Constants.cpp
SlovanEngine/Core/Objects/GameObject.cpp
SlovanEngine/Core/Cameras/Camera.cpp
SlovanEngine/PC/Renderer/PCRenderer.cpp
SlovanEngine/PC/Loggers/Logger.cpp
SlovanEngine/Core/ShaderPrograms/ShaderPrograms.cpp)

add_library(slovanEngine STATIC ${SOURCE_FILES})

target_link_libraries(slovanEngine ${LIBRARIES})

add_subdirectory(demo)