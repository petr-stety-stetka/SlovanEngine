package com.slovanengine.demo;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class MainActivity extends Activity {

	public static Context context;
	static private GLSurfaceView glSurfaceView;
	public static boolean runUpdateLoop = true;
	Thread updateThread;
	private AssetManager assetManager;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		assetManager = getResources().getAssets();
		JNIWrapper.assetManagerLoad(assetManager);

		glSurfaceView = new GLSurfaceView(this);

		final ActivityManager activityManager = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
		final ConfigurationInfo configurationInfo = activityManager.getDeviceConfigurationInfo();
		final boolean supportGLES3 = configurationInfo.reqGlEsVersion >= 0x30000;

		if (supportGLES3) 
			glSurfaceView.setEGLContextClientVersion(3);
		else
			glSurfaceView.setEGLContextClientVersion(2);
		

		glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0); // For working emulator
		final Renderer renderer = new Renderer();
		glSurfaceView.setRenderer(renderer);

		glSurfaceView.setPreserveEGLContextOnPause(true);

		setContentView(glSurfaceView);
		context = this;
	}

	@Override
	protected void onResume() {
		super.onResume();
		runUpdateLoop = true;
		updateThread = new Thread()
		{
            public void run() 
            {
                while(runUpdateLoop)
                {
                	JNIWrapper.onUpdateFrame();
                }
            }
        };
        updateThread.start();
		glSurfaceView.onResume();
		
	}

	protected void onPause() {
		super.onPause();
		runUpdateLoop = false;
		glSurfaceView.onPause();
	}

	@Override
	public void onBackPressed() {
		JNIWrapper.onTerminate();
		runUpdateLoop = false;
		// Full stop app
		System.exit(0);
	}
}
