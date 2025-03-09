//
// Created by qq103 on 2025/3/9.
//

#include "NativeWindowCreateEvent.hpp"

namespace Minecraft {
NativeWindowCreateEvent::NativeWindowCreateEvent(ANativeWindow *window) : m_window(window) {
}

EventID NativeWindowCreateEvent::getID() const {
  return EventID::E_NATIVE_WINDOW_CREATE;
}

std::string NativeWindowCreateEvent::getName() const {
  return "NativeWindowCreateEvent";
}

std::any NativeWindowCreateEvent::getData() const {
  return m_window;
}
} // namespace Minecraft