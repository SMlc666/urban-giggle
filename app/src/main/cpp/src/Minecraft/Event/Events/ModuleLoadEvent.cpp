//
// Created by qq103 on 2025/3/8.
//

#include "ModuleLoadEvent.hpp"
Minecraft::ModuleLoadEvent::ModuleLoadEvent(uintptr_t module_base_addr)
    : m_module_base_addr(module_base_addr) {
}
Minecraft::EventID Minecraft::ModuleLoadEvent::getID() const {
  return EventID::E_MODULE_LOAD;
}
std::string Minecraft::ModuleLoadEvent::getName() const {
  return "ModuleLoadEvent";
}
std::any Minecraft::ModuleLoadEvent::getData() const {
  return m_module_base_addr;
}