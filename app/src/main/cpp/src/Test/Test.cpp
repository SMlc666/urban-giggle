//
// Created by qq103 on 2025/3/7.
//
#ifdef _DEBUG_
#include "Test.hpp"
#include "Init/Init.hpp"
#include "Log/Log.hpp"
#include "MemTool/MemTool.hpp"
#include <thread>

Init init_Test("init-Test", []() {
  TOOLBOX_LOG_D("Test init");
  std::thread([]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    void *moduleBase = MemTool::getModuleBase<void *>("libminecraftpe.so");
    TOOLBOX_LOG_D("libminecraftpe.so base address: %p", moduleBase);
  }).detach(); }, 1);
#endif