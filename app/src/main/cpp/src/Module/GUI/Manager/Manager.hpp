//
// Created by qq103 on 2025/3/8.
//

#pragma once
#include <functional>
#include <vector>
#include "Module/GUI/GUI.hpp"
namespace Module::GUI {
class Manager {
public:
  Manager() = default;
  std::vector<std::shared_ptr<GUI>> &getGUIs();
  void addGUI(std::shared_ptr<GUI> gui);
  void forEach(std::function<void(std::shared_ptr<GUI>)> func);

private:
  std::vector<std::shared_ptr<GUI>> mGUIs;
};

} // namespace Module::GUI
