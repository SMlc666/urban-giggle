//
// Created by qq103 on 2025/3/2.
//

#include "ModuleManager.hpp"
void Module::ModuleManager::removeModule(const std::string &name) {
  m_modules.erase(name);
}
Module::Module *Module::ModuleManager::getModule(const std::string &name) const {
  return m_modules.at(name);
}
void Module::ModuleManager::addModule(Module *module) {
  m_modules[module->getName()] = module;
}
std::unordered_map<std::string, Module::Module *> Module::ModuleManager::getModules() const {
  return m_modules;
}
void Module::ModuleManager::forEach(const std::function<void(Module *)> &func) {
  for (auto &module : m_modules) {
    func(module.second);
  }
}