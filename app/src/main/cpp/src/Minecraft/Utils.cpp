//
// Created by qq103 on 2025/3/7.
//

#include "Utils.hpp"
#include "Init/Init.hpp"
#include "Log/Log.hpp"
Init init_MinecraftUtils("init_MinecraftUtils", []() { TOOLBOX_LOG_D("init_MinecraftUtils"); },
                         9999);//需要等待MemTool先加载