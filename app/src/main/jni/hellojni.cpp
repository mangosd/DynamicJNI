//
// Created by zhangqianchu on 2016/9/8.
//

//#include "com_scu_dynamicjni_HelloJNI.h"
#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#define TAG "myndk"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
void printHello(JNIEnv*env,jobject obj);
void printString(JNIEnv*env,jobject obj,jstring jstr);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm,void *reserved)
{
    // 定义一个JNINativeMethod数组，其中的成员就是Java代码中对应的native方法
//    static JNINativeMethod gMethods[] = {
//            { "hello", "()Ljava/lang/String;", (void*)native_hello},
//    };
    JNIEnv*env=NULL;
    JNINativeMethod nm[] = {{"printHello","()V",(void*)printHello},{"printString","(Ljava/lang/String;)V",(void*)printString}};
    jclass cls;
    jint result = -1;
    if(vm->GetEnv((void**)&env,JNI_VERSION_1_4)!=JNI_OK)
    {
        printf("Error");
        return JNI_ERR;
    }
    cls = env->FindClass("com/scu/dynamicjni/HelloJNI");
    //下面方法已经失效
//    nm[0] = "printHello";
//    nm[0].signature="()V";
//    nm[0].fnPtr = (void*)printHello;
//    nm[1] = "printString";
//    nm[1].signature="(Ljava/lang/String;)V";
//    nm[1].fnPtr = (void*)printString;

    env->RegisterNatives(cls,nm,2);
    return JNI_VERSION_1_4;
}

void printHello(JNIEnv *env,jobject obj)
{
    printf("Hello World\n");
    char buf[128]="ceshi";
    LOGE("hell=%s",buf);
//    char buf[128]="测试本地Toast提示";
//    jclass tclss = env->FindClass("android/widget/Toast");
//    jmethodID jid = env->GetStaticMethodID(tclss,"makeText","(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
//    jclass sclss = env->FindClass("java/lang/String");
//    jmethodID mid = env->GetMethodID(sclss,"<init>","([BLjava/lang/String;)V");
//    jsize len = strlen(buf);
//    jbyteArray barr = env->NewByteArray(len);
//    env->SetByteArrayRegion(barr,0,len,(jbyte*)buf);
//    jstring strencode = env->NewStringUTF("UTF-8");
//    jstring result = (jstring)env->NewObject(sclss,mid,barr,strencode);//最后一个表示使用utf-8编码的
//    jobject toastt =  env->CallStaticObjectMethod(tclss,jid,obj,result);
//    env->DeleteLocalRef(result);//注意这里要释放jstring的引用；一定要记得析构/释放/删除申请的空间。
//    env->DeleteLocalRef(strencode);
//    jmethodID show_id = env->GetMethodID(tclss,"show","()V");
//    env->CallVoidMethod(toastt,show_id);

    return;
}

void printString(JNIEnv *env,jobject obj,jstring jstr)
{
    const char *str = env->GetStringUTFChars(jstr,0);
    printf("%s\n",str);
    return;
}