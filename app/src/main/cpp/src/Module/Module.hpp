//
// Created by qq103 on 2025/3/2.
//

#ifndef MINERAFT_TOOLBOX_MODULE_HPP
#define MINERAFT_TOOLBOX_MODULE_HPP
#include "Menu/Menu.hpp"
#include <string>
class Module {
public:
  Module(const std::string &name, const std::string &description,
         Menu::MenuID menuID);
  Module(const std::string &name, Menu::MenuID menuID);
  [[nodiscard]] const std::string &getName() const;
  [[nodiscard]] const std::string &getDescription() const;
  [[nodiscard]] bool hasDescription() const;
  [[nodiscard]] Menu::MenuID getMenuID() const;

private:
  std::string m_name;
  std::string m_description;
  Menu::MenuID m_menuID;
};

#endif // MINERAFT_TOOLBOX_MODULE_HPP
