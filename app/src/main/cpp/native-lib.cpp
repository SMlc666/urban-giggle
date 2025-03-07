#include "Init/Init.hpp"
#include "Log/Log.hpp"
#include <jni.h>
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
  std::vector<init_list> mInitList;
  mInitList.reserve(InitList.size());
  for (auto &var : InitList) {
    mInitList.push_back(var.second);
  }
  std::sort(mInitList.begin(), mInitList.end(),
            [](const init_list &a, const init_list &b) {
              return a.priority > b.priority;
            });
  for (auto &var : mInitList) {
    try {
      var.func();
    } catch (const std::exception &e) {
      TOOLBOX_LOG_E("InitList exception: %s", e.what());
      return JNI_ERR;
    }
  }
  return JNI_VERSION_1_6;
}
