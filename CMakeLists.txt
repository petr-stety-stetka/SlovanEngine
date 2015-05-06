cmake_minimum_required(VERSION 2.8.4)
project(Game)
add_definitions(-DPC)
add_definitions(-DADDITIONAL_LOG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -lGL -lGLU -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lGLEW")

set(SOURCE_FILES
Engine/PC/Main/SlovanEngine.cpp
Engine/PC/Renderer/PCRenderer.cpp
Engine/Core/Renderer/Renderer.cpp
Engine/PC/Loggers/Logger.cpp
Engine/Core/Loggers/FPSLogger.cpp
Engine/Core/Geometry/Vector.cpp
Engine/Core/Geometry/Point2D.cpp
Engine/Core/Geometry/Point3D.cpp
Game/PC/Main.cpp
Game/Scene/Scene0/Scene0.cpp
Game/Scene/Scene1/Scene1.cpp)
add_executable(Game ${SOURCE_FILES})