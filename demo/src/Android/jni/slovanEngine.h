#pragma once

#include <jni.h>

extern "C"
{
/*
 * Class:     com_slovanengine_demo_JNIWrapper
 * Method:    onSurfaceCreated
 */
JNIEXPORT void JNICALL
Java_com_slovanengine_demo_JNIWrapper_onSurfaceCreated(JNIEnv * , jclass ) ;

/*
 * Class:     com_slovanengine_demo_JNIWrapper
 * Method:    onSurfaceChanged
 */
JNIEXPORT void JNICALL
Java_com_slovanengine_demo_JNIWrapper_onSurfaceChanged(JNIEnv * , jclass , jint , jint ) ;

/*
 * Class:     com_slovanengine_demo_JNIWrapper
 * Method:    onDrawFrame
 */
JNIEXPORT void JNICALL
Java_com_slovanengine_demo_JNIWrapper_onDrawFrame(JNIEnv * , jclass ) ;

/*
 * Class:     com_slovanengine_demo_JNIWrapper
 * Method:    onUpdateFrame
 */
JNIEXPORT void JNICALL
Java_com_slovanengine_demo_JNIWrapper_onUpdateFrame(JNIEnv * , jclass ) ;

/*
  * Class:     com_slovanengine_demo_JNIWrapper
  * Method:    onTerminate
  */
JNIEXPORT void JNICALL
Java_com_slovanengine_demo_JNIWrapper_onTerminate(JNIEnv * , jclass ) ;

/*
 * Class:     com_slovanengine_demo_JNIWrapper
 * Method:    assetManagerLoad
 */
JNIEXPORT void JNICALL
Java_com_slovanengine_demo_JNIWrapper_assetManagerLoad(JNIEnv * , jclass , jobject ) ;
}
