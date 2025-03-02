#include <jni.h>
#include <string>
#include "Log/Log.hpp"
JNIEnv* g_env = nullptr;
JavaVM *g_jvm = nullptr;
extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  g_jvm = vm;
  TOOLBOX_LOG_D("JNI_OnLoad");
  if (vm->GetEnv(reinterpret_cast<void**>(&g_env), JNI_VERSION_1_6)!= JNI_OK) {
    return -1;
  }
  TOOLBOX_LOG_D("JNI_OnLoad: g_env=%p", g_env);
  TOOLBOX_LOG_D("JNI_OnLoad: g_jvm=%p", g_jvm);
  return JNI_VERSION_1_6;
}