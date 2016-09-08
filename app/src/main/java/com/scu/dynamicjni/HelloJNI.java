package com.scu.dynamicjni;

/**
 * Created by zhangqianchu on 2016/9/8.
 */
public class HelloJNI {
    static {
        System.loadLibrary("hellojni");
    }
    public static native void printHello();
    public static native void printString(String str);
}
