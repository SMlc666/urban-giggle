//
// Created by qq103 on 2025/3/8.
//

#pragma once
#include "GUITYPE.hpp"
#include <string>
#include <any>
namespace Module::GUI {

class GUI {
public:
  GUI(const std::string &name, const std::string &description, const std::any &value);
  [[nodiscard]] virtual GUITYPE getType() const = 0;
  [[nodiscard]] std::string getName() const;
  [[nodiscard]] std::string getDescription() const;
  std::any getValue() const;
  void setValue(const std::any &value);

protected:
  std::any m_value;
  std::string m_name;
  std::string m_description;
};

} // namespace Module::GUI
