#include "Init/Init.hpp"
#include "KittyMemory/KittyInclude.hpp"
#include "Log/Log.hpp"
#include "MemTool/MemTool.hpp"
#include "frida-gum/frida-gum.h"
#include <jni.h>
#include <shadowhook.h>
#include <string>
#include <thread>
JNIEnv* g_env = nullptr;
JavaVM *g_jvm = nullptr;
extern "C" jint JNI_OnLoad(JavaVM *vm, void * /*reserved*/) {
  g_jvm = vm;
  TOOLBOX_LOG_D("JNI_OnLoad");
  if (vm->GetEnv(reinterpret_cast<void**>(&g_env), JNI_VERSION_1_6)!= JNI_OK) {
    return JNI_ERR;
  }
  TOOLBOX_LOG_D("JNI_OnLoad: g_env=%p", g_env);
  TOOLBOX_LOG_D("JNI_OnLoad: g_jvm=%p", g_jvm);
  gum_init();
  for (auto &var : InitList) {
    TOOLBOX_LOG_D("InitList: %s", var.first.c_str());
    try {
      var.second();
    } catch (const std::exception &e) {
      TOOLBOX_LOG_E("InitList exception: %s", e.what());
      return JNI_ERR;
    }
  }
  return JNI_VERSION_1_6;
}
