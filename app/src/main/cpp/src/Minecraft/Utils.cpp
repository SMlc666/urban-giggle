//
// Created by qq103 on 2025/3/7.
//

#include "Utils.hpp"
#include "Init/Init.hpp"
#include "Log/Log.hpp"
#include "MemTool/MemTool.hpp"
#include "Event/EventDispatch.hpp"
#include <thread>
namespace Minecraft {
uintptr_t g_ModuleBase;
template <typename T> T getMCModuleBase() {
  return reinterpret_cast<T>(g_ModuleBase);
}
} // namespace Minecraft
static const std::string libName = "libminecraftpe.so";
static Init init_MinecraftUtils(
    "init_MinecraftUtils",
    []() {
      TOOLBOX_LOG_D("init_MinecraftUtils");
      std::thread([]() {
        uintptr_t moduleBase = 0;
        while (moduleBase == 0) {
          moduleBase = MemTool::getModuleBase<uintptr_t>(libName);
        }
        Minecraft::g_ModuleBase = moduleBase;
        Minecraft::g_eventDispatcher.dispatch(
            Minecraft::EventID::E_MODULE_LOAD); //监听事件，需要优先级比该Init高
      }).detach();
    },
    9999); //需要等待MemTool先加载