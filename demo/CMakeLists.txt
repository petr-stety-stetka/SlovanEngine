cmake_minimum_required(VERSION 2.8.4)
project(demo)

add_definitions(-DPC)
add_definitions(-DADDITIONAL_LOG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pthread")

set(SOURCE_FILES
src/PC/Main.cpp
src/Scenes/Scene0/Scene0.cpp
src/Scenes/Scene1/Scene1.cpp)
add_executable(demo ${SOURCE_FILES})

set(LIBRARIES slovanEngine GL GLU glfw X11 Xxf86vm Xrandr Xi GLEW)
target_link_libraries(demo ${LIBRARIES})