#
# This empty Android.mk file exists to prevent the build system from
# automatically including any other Android.mk files under this directory.
#
#ifeq ($(TARGET_DEVICE),hon660)
LOCAL_PATH := $(call my-dir)

# if some modules are built directly from this directory (not subdirectories),
# their rules should be written here.

include $(all-subdir-makefiles)

#endif
