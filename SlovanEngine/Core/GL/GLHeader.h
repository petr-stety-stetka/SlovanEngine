#pragma once

#if defined(PC)

#include <GL/glew.h>

#define GLFW_DLL

#include <GLFW/glfw3.h>

#elif defined(ANDROID)
    #include <GLES2/gl2.h>
    #include <GLES2/gl2ext.h>
    #include <GLES3/gl3.h>
    #include <GLES3/gl3ext.h>
    #include <GLES3/gl31.h>
#endif
