//
// Created by qq103 on 2025/3/8.
//

#pragma once

#include "Module.hpp"
#include "GUI/Manager/Manager.hpp"
namespace Module {

class GUIModule : public Module {
public:
  GUI::Manager &getManager();

protected:
  GUI::Manager manager;
};

} // namespace Module
