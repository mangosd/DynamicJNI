//
// Created by zhangqianchu on 2016/9/8.
//

#include "com_scu_dynamicjni_HelloJNI.h"

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
    cls = env->FindClass("HelloJNI");
//    nm[0] = "printHello";
//    nm[0].signature="()V";
//    nm[0].fnPtr = (void*)printHello;
//
//
//    nm[1] = "printString";
//    nm[1].signature="(Ljava/lang/String;)V";
//    nm[1].fnPtr = (void*)printString;

    env->RegisterNatives(cls,nm,2);
    return JNI_VERSION_1_4;
}

void printHello(JNIEnv *env,jobject obj)
{
    printf("Hello World\n");
    return;
}

void printString(JNIEnv *env,jobject obj,jstring jstr)
{
    const char *str = env->GetStringUTFChars(jstr,0);
    printf("%s\n",str);
    return;
}