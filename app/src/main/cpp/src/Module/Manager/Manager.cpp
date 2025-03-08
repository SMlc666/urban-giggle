//
// Created by qq103 on 2025/3/2.
//

#include "Manager.hpp"
void Module::Manager::removeModule(const std::string &name) {
  m_modules.erase(name);
}
Module::Module *Module::Manager::getModule(const std::string &name) const {
  return m_modules.at(name);
}
void Module::Manager::addModule(Module *module) {
  m_modules[module->getName()] = module;
}
std::unordered_map<std::string, Module::Module *> Module::Manager::getModules() const {
  return m_modules;
}