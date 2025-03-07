//
// Created by qq103 on 2025/3/2.
//

#ifndef MINERAFT_TOOLBOX_MANAGER_HPP
#define MINERAFT_TOOLBOX_MANAGER_HPP
#include "Module/Module.hpp"
#include <unordered_map>
class Manager {
public:
  Manager() = default;
  ~Manager() = default;
  void addModule(Module *module);
  void removeModule(const std::string &name);
  Module *getModule(const std::string &name) const;
  std::unordered_map<std::string, Module *> getModules() const;

private:
  std::unordered_map<std::string, Module *> m_modules;
};

#endif // MINERAFT_TOOLBOX_MANAGER_HPP
