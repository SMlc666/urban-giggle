//
// Created by qq103 on 2025/3/9.
//

#pragma once
#include <android/native_window.h>
#include "Event.hpp"
namespace Minecraft {

class NativeWindowCreateEvent : public Event {
private:
  ANativeWindow *m_window;

public:
  explicit NativeWindowCreateEvent(ANativeWindow *window);
  [[nodiscard]] EventID getID() const override;
  [[nodiscard]] std::string getName() const override;
  [[nodiscard]] std::any getData() const override;
};

} // namespace Minecraft
