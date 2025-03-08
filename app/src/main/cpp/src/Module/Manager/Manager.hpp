//
// Created by qq103 on 2025/3/2.
//

#pragma once
#include "Module/Module.hpp"
#include <unordered_map>
namespace Module {
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
} // namespace Module