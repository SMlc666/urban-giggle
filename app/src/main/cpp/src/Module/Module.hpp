//
// Created by qq103 on 2025/3/2.
//

#pragma once
#include "Menu/Menu.hpp"
#include <string>
#include "eventpp/eventdispatcher.h"
#include "Event/EventId.hpp"
namespace Module {
class Module {
public:
  Module() = default;
  [[nodiscard]] virtual const std::string &getName() const = 0;
  [[nodiscard]] virtual const std::string &getDescription() const = 0;
  [[nodiscard]] virtual MenuID getMenuID() const = 0;

protected:
  eventpp::EventDispatcher<EventId, void()> m_eventDispatcher;
};
} // namespace Module
