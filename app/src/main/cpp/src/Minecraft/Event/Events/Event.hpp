//
// Created by qq103 on 2025/3/8.
//

#ifndef MINECRAFT_TOOLBOX_EVENT_HPP
#define MINECRAFT_TOOLBOX_EVENT_HPP
#include <string>
#include <any>
#include "EventId.hpp"
namespace Minecraft {
class Event {
public:
  Event() = default;
  virtual ~Event() = default;
  [[nodiscard]] virtual EventID getID() const = 0;
  [[nodiscard]] virtual std::string getName() const = 0;
  [[nodiscard]] virtual std::any getData() const = 0;
  Event(const Event &) = default;
  Event &operator=(const Event &) = default;
  Event(Event &&) = default;
  Event &operator=(Event &&) = default;
};

} // namespace Minecraft

#endif //MINECRAFT_TOOLBOX_EVENT_HPP
