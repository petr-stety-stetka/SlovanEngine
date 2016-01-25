package com.slovanengine.demo;

import android.content.res.AssetManager;

/**
 * JNI Wrapper for link C++ (C) code to Java.
 */
public class JNIWrapper
{
    static {
        System.loadLibrary("slovanEngine");
    }

    public static native void onSurfaceCreated();

    public static native void onSurfaceChanged(int width, int height);

    public static native void onDrawFrame();
    
    public static native void onUpdateFrame();
    
    public static native void onTerminate(); 

    public static native void assetManagerLoad(AssetManager assetManager);
}