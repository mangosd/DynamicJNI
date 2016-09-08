package com.scu.dynamicjni;

/**
 * Created by zhangqianchu on 2016/9/8.
 */
public class HelloJNI {
    static {
        System.loadLibrary("hellojni");
    }
    public native void printHello();
    public native void printString(String str);
}
