LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION :=cpp #针对C++的支持，标记c++文件的扩展名名称
LOCAL_MODULE := hellojni
LOCAL_SRC_FILES := hellojni.cpp
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)