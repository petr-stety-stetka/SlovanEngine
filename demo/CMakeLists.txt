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

set(EXTERNAL_LIBS_PATH ${CMAKE_SOURCE_DIR}/external/libs/PC/${CMAKE_SYSTEM_PROCESSOR})

if(UNIX)
    set(LIBRARIES slovanEngine GL GLU ${EXTERNAL_LIBS_PATH}/libglfw3.a X11 Xxf86vm Xrandr Xi
            ${EXTERNAL_LIBS_PATH}/libGLEW.a Xinerama Xcursor ${EXTERNAL_LIBS_PATH}/libassimp.a rt m dl z
            ${EXTERNAL_LIBS_PATH}/libsoil2.a)
elseif(WIN32)
    set(LIBRARIES slovanEngine ${EXTERNAL_LIBS_PATH}/libglew.a ${EXTERNAL_LIBS_PATH}/libglfw3.a
            ${EXTERNAL_LIBS_PATH}/libsoil2.a ${EXTERNAL_LIBS_PATH}/libassimp.a opengl32 glu32 z)
else()
    message(SEND_ERROR "For now, you are on an unsupported platform!")
endif()

target_link_libraries(demo ${LIBRARIES})