LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE := hello_static

LOCAL_SRC_FILES := $(call all-subdir-c-files)

include $(BUILD_STATIC_LIBRARY)
