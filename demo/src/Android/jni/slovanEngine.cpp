#include "slovanEngine.h"

#include "../../../../SlovanEngine/Android/Renderer/AndroidRenderer.h"
#include "../../Scenes/Scene0/Scene0.h"
#include "../../../../SlovanEngine/Core/Scene/Scene.h"
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include "../../../../SlovanEngine/Core/Loggers/Logger.h"
#include "../../../../SlovanEngine/Android/AssetsIO/AndroidIOSystem.h"

static AndroidRenderer AndroidRenderer;

void Java_com_slovanengine_demo_JNIWrapper_onSurfaceCreated(JNIEnv * env, jclass
cls)
{
Scene *firstScene = new Scene0;
AndroidRenderer.
setFirstScene(firstScene);
short UPS(60);
short FPS(0);
AndroidRenderer.
initialization(UPS, FPS
);
}

void Java_com_slovanengine_demo_JNIWrapper_onSurfaceChanged(JNIEnv * env, jclass
cls,
jint width, jint
height)
{
AndroidRenderer.
changeSize(width, height
);
}

void Java_com_slovanengine_demo_JNIWrapper_onDrawFrame(JNIEnv * env, jclass
cls)
{
AndroidRenderer.

renderLoop();

}

void Java_com_slovanengine_demo_JNIWrapper_onUpdateFrame(JNIEnv * env, jclass
cls)
{
AndroidRenderer.

updateLoop();

}

void Java_com_slovanengine_demo_JNIWrapper_onTerminate(JNIEnv * env, jclass
cls)
{
AndroidRenderer.

terminate();

}

void Java_com_slovanengine_demo_JNIWrapper_assetManagerLoad(JNIEnv * env, jclass
cls,
jobject assetManager
)
{
AndroidIOSystem::setAssetManager(AAssetManager_fromJava(env, assetManager));

if (

AndroidIOSystem::getAssetManager()

== NULL)
Logger::printError("Failed load assets manager");
}

