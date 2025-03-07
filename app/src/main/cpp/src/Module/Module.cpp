//
// Created by qq103 on 2025/3/2.
//

#include "Module.hpp"
Module::Module(const std::string &name, const std::string &description,
               Menu::MenuID menuID)
    : m_name(name), m_description(description), m_menuID(menuID) {}
Module::Module(const std::string &name, Menu::MenuID menuID) {
  Module(name, "", menuID);
}
const std::string &Module::getName() const { return m_name; }
const std::string &Module::getDescription() const { return m_description; }
Menu::MenuID Module::getMenuID() const { return m_menuID; }
bool Module::hasDescription() const { return !m_description.empty(); }