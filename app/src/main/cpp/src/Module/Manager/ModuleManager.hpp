//
// Created by qq103 on 2025/3/2.
//

#pragma once
#include "Module/Module.hpp"
#include <unordered_map>
namespace Module {
class ModuleManager {
public:
  ModuleManager() = default;
  ~ModuleManager() = default;
  void addModule(Module *module);
  void removeModule(const std::string &name);
  [[nodiscard]] Module *getModule(const std::string &name) const;
  [[nodiscard]] std::unordered_map<std::string, Module *> getModules() const;
  void forEach(const std::function<void(Module *)> &func);

private:
  std::unordered_map<std::string, Module *> m_modules;
};
} // namespace Module