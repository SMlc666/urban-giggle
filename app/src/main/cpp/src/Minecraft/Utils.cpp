//
// Created by qq103 on 2025/3/7.
//

#include "Utils.hpp"
#include "Init/Init.hpp"
#include "Log/Log.hpp"
#include "MemTool/MemTool.hpp"
#include "Event/EventDispatch.hpp"
#include "Event/Events/ModuleLoadEvent.hpp"
#include <thread>
#include <android/dlext.h>
namespace Minecraft {
uintptr_t g_ModuleBase;
template <typename T> T getMCModuleBase() {
  return reinterpret_cast<T>(g_ModuleBase);
}
} // namespace Minecraft
static bool is_first_call = false;
MemTool::Hook android_dlopen_ext_;
void *android_dlopen_ext_new(const char *__filename, int __flags, const android_dlextinfo *__info) {
  //TOOLBOX_LOG_D("android_dlopen_ext_new %s", __filename);
  auto *ret = android_dlopen_ext_.callOld<void *>(__filename, __flags, __info);
  if (!is_first_call) {
    if (std::string(__filename).find("libminecraftpe.so") != std::string::npos) {
      is_first_call = true;
      uintptr_t moduleBase = MemTool::getModuleBase<uintptr_t>("libminecraftpe.so");
      Minecraft::g_ModuleBase = moduleBase;
      Minecraft::g_eventDispatcher.dispatch(Minecraft::EventID::E_MODULE_LOAD,
                                            std::make_shared<Minecraft::ModuleLoadEvent>(
                                                moduleBase)); //监听事件，需要优先级比该Init高
      //TOOLBOX_LOG_D("libminecraftpe.so base: %p", moduleBase);
    }
  }
  return ret;
}
static const std::string libName = "libminecraftpe.so";
static Init init_MinecraftUtils(
    "init_MinecraftUtils",
    []() {
      TOOLBOX_LOG_D("init_MinecraftUtils");
      android_dlopen_ext_ =
          MemTool::Hook(reinterpret_cast<void *>(&android_dlopen_ext), &android_dlopen_ext_new,
                        false); //用于获取libminecraftpe.so的基址
    },
    9999); //需要等待MemTool先加载