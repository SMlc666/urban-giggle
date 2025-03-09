//
// Created by qq103 on 2025/3/8.
//

#pragma once
#include "Config.hpp"
#include "Module/Manager/ModuleManager.hpp"
namespace Module {

class ConfigHelper {
public:
  ConfigHelper(Config *config, ModuleManager *moduleManager);
  void ModuleToConfig();
  void ConfigToModule();

private:
  Config *config_;
  ModuleManager *moduleManager_;
};

} // namespace Module
