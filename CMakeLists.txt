cmake_minimum_required(VERSION 2.8.4)
project(SlovanEngine)

add_definitions(-DPC)
add_definitions(-DADDITIONAL_LOG)
#add_definitions(-DGLOB_MEASURE_TIME=1)
add_definitions(-DGLEW_STATIC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pthread")

set(SOURCE_FILES
        ${SOIL2_SOURCE}
        SlovanEngine/Core/Renderer/Renderer.cpp
        SlovanEngine/Core/Loggers/FPSLogger.cpp
        SlovanEngine/Core/Shader/Shader.cpp
        SlovanEngine/Core/Shader/Matrices.cpp
        SlovanEngine/Core/ShaderPrograms/TestProgram.cpp
        SlovanEngine/Core/VertexData/VertexArrayObject.cpp
        SlovanEngine/Core/Constants/Constants.cpp
        SlovanEngine/Core/GraphicModels/BasicGeometryShape.cpp
        SlovanEngine/Core/Cameras/Camera.cpp
        SlovanEngine/PC/Renderer/PCRenderer.cpp
        SlovanEngine/PC/Loggers/Logger.cpp
        SlovanEngine/Core/ShaderPrograms/ShaderPrograms.cpp
        SlovanEngine/Core/GraphicModels/Mesh.cpp
        SlovanEngine/Core/GraphicModels/Model.cpp
        SlovanEngine/Core/ShaderPrograms/AssimpProgram.cpp
        SlovanEngine/Core/Objects/Model3D.cpp
        SlovanEngine/Core/GraphicModels/Texture.cpp
        SlovanEngine/PC/Input/Keyboard.cpp
        SlovanEngine/PC/Input/Mouse.cpp
        SlovanEngine/Core/Cameras/FPSCamera.cpp
        SlovanEngine/Core/Cameras/Camera.cpp
        SlovanEngine/Core/Cameras/Camera2D.cpp
        #SlovanEngine/Core/Objects/Texture2D.cpp
        #SlovanEngine/Core/Objects/Texture2D.h
        SlovanEngine/Core/Objects/Model3D.cpp
        SlovanEngine/Core/Objects/Model3D.h
        #SlovanEngine/Core/Objects/Texture3D.cpp
        #SlovanEngine/Core/Objects/Texture3D.h
        )

add_library(slovanEngine STATIC ${SOURCE_FILES})
add_subdirectory(demo)

