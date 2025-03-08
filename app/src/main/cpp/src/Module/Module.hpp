//
// Created by qq103 on 2025/3/2.
//

#pragma once
#include "Menu/Menu.hpp"
#include <string>
class Module {
public:
  Module() = default;
  [[nodiscard]] virtual const std::string &getName() const = 0;
  [[nodiscard]] virtual const std::string &getDescription() const = 0;
  [[nodiscard]] virtual Menu::MenuID getMenuID() const = 0;
};
