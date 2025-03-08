//
// Created by qq103 on 2025/3/8.
//

#include "Manager.hpp"
std::vector<std::shared_ptr<Module::GUI::GUI>> &Module::GUI::Manager::getGUIs() {
  return mGUIs;
}
void Module::GUI::Manager::addGUI(std::shared_ptr<Module::GUI::GUI> gui) {
  mGUIs.emplace_back(gui);
}
void Module::GUI::Manager::forEach(std::function<void(std::shared_ptr<Module::GUI::GUI>)> func) {
  for (auto &gui : mGUIs) {
    func(gui);
  }
}