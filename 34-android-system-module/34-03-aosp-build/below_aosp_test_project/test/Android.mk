LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	test.c test2.c 
LOCAL_MODULE:= test
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
