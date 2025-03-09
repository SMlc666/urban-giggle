//
// Created by qq103 on 2025/3/8.
//

#include "GUI.hpp"

Module::GUI::GUI::GUI(const std::string &name, const std::string &description,
                      const std::any &value)
    : m_name(name), m_description(description), m_value(value) {
}
std::string Module::GUI::GUI::getName() const {
  return m_name;
}
std::string Module::GUI::GUI::getDescription() const {
  return m_description;
}
std::any Module::GUI::GUI::getValue() const {
  return m_value;
}
void Module::GUI::GUI::setValue(const std::any &value) {
  m_value = value;
}
const std::type_info &Module::GUI::GUI::getValueType() const {
  return m_value.type();
}