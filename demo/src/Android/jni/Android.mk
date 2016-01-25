LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := assimp
LOCAL_SRC_FILES := ../../../../external/libs/android/$(TARGET_ARCH_ABI)/libassimp.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := slovanEngine
LOCAL_SRC_FILES := slovanEngine.cpp \
../../../../SlovanEngine/Android/Renderer/AndroidRenderer.cpp \
../../../../SlovanEngine/Android/AssetsIO/AndroidIOSystem.cpp \
../../../../SlovanEngine/Android/AssetsIO/ZippedFile.cpp \
../../../../SlovanEngine/Core/Renderer/Renderer.cpp \
../../../../SlovanEngine/Android/AssetsIO/ReadAssetFile.cpp \
../../Scenes/Scene0/Scene0.cpp \
../../Scenes/Scene1/Scene1.cpp \
../../../../SlovanEngine/Core/Cameras/Camera.cpp \
../../../../SlovanEngine/Core/Cameras/FPSCamera.cpp \
../../../../SlovanEngine/Core/Cameras/Camera2D.cpp \
../../../../SlovanEngine/Core/Constants/Constants.cpp \
../../../../SlovanEngine/Core/Objects/GameObjectOld.cpp \
../../../../SlovanEngine/Core/VertexData/VertexArrayObject.cpp \
../../../../SlovanEngine/Core/Shader/Matrices.cpp \
../../../../SlovanEngine/Core/ShaderPrograms/TestProgram.cpp \
../../../../SlovanEngine/Core/ShaderPrograms/AssimpProgram.cpp \
../../../../SlovanEngine/PC/Input/Keyboard.cpp \
../../../../SlovanEngine/PC/Input/Mouse.cpp \
../../../../SlovanEngine/Core/Shader/Shader.cpp \
../../../../SlovanEngine/Android/Loggers/Logger.cpp \
../../../../SlovanEngine/Core/Loggers/FPSLogger.cpp \
../../../../SlovanEngine/Core/ShaderPrograms/ShaderPrograms.cpp \
../../../../SlovanEngine/Core/GraphicModels/Texture.cpp \
../../../../SlovanEngine/Core/GraphicModels/Model.cpp \
../../../../SlovanEngine/Core/GraphicModels/Mesh.cpp \
../../../../SlovanEngine/Core/Objects/GameObject.cpp \
../../../../external/SOIL2/SOIL2.c \
../../../../external/SOIL2/etc1_utils.c \
../../../../external/SOIL2/image_DXT.c \
../../../../external/SOIL2/image_helper.c

LOCAL_C_INCLUDES := ../../../../SlovanEngine
LOCAL_LDLIBS += -lGLESv2 -lGLESv3 -landroid -llog -lEGL
LOCAL_SHARED_LIBRARIES += assimp
LOCAL_CFLAGS += -DANDROID -DADDITIONAL_LOG
LOCAL_CPPFLAGS += -DANDROID -DADDITIONAL_LOG
APP_CPPFLAGS += -std=c++11
include $(BUILD_SHARED_LIBRARY)

