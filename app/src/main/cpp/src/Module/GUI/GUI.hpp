//
// Created by qq103 on 2025/3/8.
//

#pragma once
#include "GUITYPE.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <any>
namespace Module::GUI {

class GUI {
public:
  GUI(const std::string &name, const std::string &description, const std::any &value);
  [[nodiscard]] virtual GUITYPE getType() const = 0;
  virtual void toJson(nlohmann::json &j) const = 0;
  virtual void fromJson(const nlohmann::json &j) = 0;
  [[nodiscard]] std::string getName() const;
  [[nodiscard]] std::string getDescription() const;
  std::any getValue() const;
  void setValue(const std::any &value);
  const std::type_info &getValueType() const;

protected:
  std::any m_value;
  std::string m_name;
  std::string m_description;
};

} // namespace Module::GUI
