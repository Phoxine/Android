package com.android.server;
import android.content.Context;
import android.os.IHelloWorldService;
import android.util.Slog;

public class HelloWorldService extends IHelloWorldService.Stub{
	HelloWorldService(){
		init();
		Slog.v("HelloWorldService", 
				"HelloWorldService init result = " +addVal(3,5));
	}

	public int addVal(int a, int b){
		Slog.v("HelloWorldService", "HelloWorldService addVal "+a+"+"+b);
		return addValue(a,b);
	}

	private static native boolean init();
	private static native int addValue(int a, int b);

}
