package com.slovanengine.demo;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;

/**
 * Renderer for Android.
 */
public class Renderer implements GLSurfaceView.Renderer
{
    /**
     * Called when the surface is created or recreated.
     *
     * @param gl     GL
     * @param config config EGL
     */
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config)
    {
        JNIWrapper.onSurfaceCreated();
    }

    /**
     * Called when the surface changed size.
     *
     * @param gl     GL
     * @param width  Width display in pixels.
     * @param height Height display in pixels.
     */
    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height)
    {
        JNIWrapper.onSurfaceChanged(width, height);
    }

    /**
     * Called to draw the current frame.
     *
     * @param gl GL
     */
    @Override
    public void onDrawFrame(GL10 gl)
    {
        JNIWrapper.onDrawFrame();
    }
}