cmake_minimum_required(VERSION 2.8.4)
project(MyGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -lGLU -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -DPC")

set(SOURCE_FILES
Engine/PC/Main/SlovanEngine.cpp
Engine/PC/Renderer/PCRenderer.cpp
Engine/Core/Renderer/Renderer.cpp
Engine/PC/Loggers/Logger.cpp
Engine/Core/Loggers/FPSLogger.cpp
MyGame/PC/Main.cpp
MyGame/Scene/Scene0/Scene0.cpp
MyGame/Scene/Scene1/Scene1.cpp)
add_executable(MyGame ${SOURCE_FILES})