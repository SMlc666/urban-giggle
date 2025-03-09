//
// Created by qq103 on 2025/3/9.
//

#pragma once
#include <android/input.h>
#include "Event.hpp"
namespace Minecraft {
class NativeInputEvent : public Event {
private:
  AInputEvent *m_event;

public:
  struct Data {
    AInputEvent *event;
  };
  NativeInputEvent(AInputEvent *event);
  [[nodiscard]] EventID getID() const override;
  [[nodiscard]] std::string getName() const override;
  [[nodiscard]] std::any getData() const override;
};
} // namespace Minecraft