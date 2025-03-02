//
// Created by qq103 on 2025/3/2.
//

#ifndef MINERAFT_TOOLBOX_LOG_HPP
#define MINERAFT_TOOLBOX_LOG_HPP
#include <android/log.h>

#define TOOLBOX_LOG_TAG "ToolBox"
#define TOOLBOX_LOG_D(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, TOOLBOX_LOG_TAG, __VA_ARGS__))
#define TOOLBOX_LOG_I(...) ((void)__android_log_print(ANDROID_LOG_INFO, TOOLBOX_LOG_TAG, __VA_ARGS__))
#define TOOLBOX_LOG_W(...) ((void)__android_log_print(ANDROID_LOG_WARN, TOOLBOX_LOG_TAG, __VA_ARGS__))
#define TOOLBOX_LOG_E(...) ((void)__android_log_print(ANDROID_LOG_ERROR, TOOLBOX_LOG_TAG, __VA_ARGS__))
#define TOOLBOX_LOG_F(...) ((void)__android_log_print(ANDROID_LOG_FATAL, TOOLBOX_LOG_TAG, __VA_ARGS__))
#endif // MINERAFT_TOOLBOX_LOG_HPP
