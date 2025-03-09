//
// Created by qq103 on 2025/3/8.
//

#include "ConfigHelper.hpp"
#include "Module/GUIModule.hpp"
#include <nlohmann/json.hpp>
#include <typeindex>

namespace Module {
ConfigHelper::ConfigHelper(Config *config, ModuleManager *moduleManager)
    : moduleManager_(moduleManager), config_(config) {
}
void ConfigHelper::ModuleToConfig() {
  struct GUIModuleInfo {
    GUIModule *module{};
    GUI::Manager *manager{};
  };
  nlohmann::json json_buf;
  std::unordered_map<std::string, GUIModuleInfo> guiModules;
  moduleManager_->forEach([&](Module *module) {
    if (auto *guiModule = dynamic_cast<GUIModule *>(module)) {
      guiModules[guiModule->getName()] = {guiModule, &guiModule->getManager()};
    }
  });
  for (auto &item : guiModules) {
    json_buf[item.first] = nlohmann::json::object();
    item.second.manager->forEach(
        [&](std::shared_ptr<GUI::GUI> gui) { gui->toJson(json_buf[item.first]); });
  }
}
} // namespace Module