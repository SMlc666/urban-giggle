//
// Created by qq103 on 2025/3/8.
//

#pragma once
#include "Event.hpp"
namespace Minecraft {
class ModuleLoadEvent : public Event {
private:
  uintptr_t m_module_base_addr;
  void *m_module_handle;

public:
  struct Data {
    uintptr_t module_base_addr;
    void *module_handle;
  };
  ModuleLoadEvent(uintptr_t module_base_addr, void *module_handle);
  [[nodiscard]] EventID getID() const override;
  [[nodiscard]] std::string getName() const override;
  [[nodiscard]] std::any getData() const override;
};
} // namespace Minecraft
