//
// Created by qq103 on 2025/3/8.
//

#include "ModuleLoadEvent.hpp"
Minecraft::ModuleLoadEvent::ModuleLoadEvent(uintptr_t module_base_addr, void *module_handle)
    : m_module_base_addr(module_base_addr), m_module_handle(module_handle) {
}
Minecraft::EventID Minecraft::ModuleLoadEvent::getID() const {
  return EventID::E_MODULE_LOAD;
}
std::string Minecraft::ModuleLoadEvent::getName() const {
  return "ModuleLoadEvent";
}
std::any Minecraft::ModuleLoadEvent::getData() const {
  return Data{m_module_base_addr, m_module_handle};
}