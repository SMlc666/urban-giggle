//
// Created by qq103 on 2025/3/7.
//

#ifdef _DEBUG_
#include "Test.hpp"
#include "Init/Init.hpp"
#include "Log/Log.hpp"
#include "MemTool/MemTool.hpp"
#include <thread>
#include "Minecraft/Event/EventDispatch.hpp"
#include "Minecraft/Event/Events/ModuleLoadEvent.hpp"
static Init init_Test(
    "init-Test",
    []() {
      TOOLBOX_LOG_D("Test init");
      Minecraft::g_eventDispatcher.appendListener(
          Minecraft::EventID::E_MODULE_LOAD, [](std::shared_ptr<Minecraft::Event> event) {
            TOOLBOX_LOG_D("%s received", event->getName().c_str());
            uintptr_t modulebase = any_cast<uintptr_t>(event->getData());
            TOOLBOX_LOG_D("Module base address: 0x%p", modulebase);
          });
    },
    1);
#endif