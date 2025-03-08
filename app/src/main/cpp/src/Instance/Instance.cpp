//
// Created by qq103 on 2025/3/2.
//

#include "Instance.hpp"
#include "Init/Init.hpp"
#include "Log/Log.hpp"
namespace Instance {
Module::Manager manager;
Init init_Instance("init_Instance",
                   []() { TOOLBOX_LOG_D("Manager addr %p", &getManager()); });
Module::Manager &getManager() {
  return manager;
}
} // namespace Instance