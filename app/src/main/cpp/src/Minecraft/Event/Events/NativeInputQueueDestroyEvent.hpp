//
// Created by qq103 on 2025/3/9.
//

#pragma once
#include <android/input.h>
#include "Event.hpp"

namespace Minecraft {
class NativeInputQueueDestroyEvent : public Event {
private:
  AInputQueue *m_inputQueue;

public:
  NativeInputQueueDestroyEvent(AInputQueue *inputQueue);
  [[nodiscard]] EventID getID() const override;
  [[nodiscard]] std::string getName() const override;
  [[nodiscard]] std::any getData() const override;
};
} // namespace Minecraft