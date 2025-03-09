//
// Created by qq103 on 2025/3/9.
//

#include "NativeWindowDestroyEvent.hpp"

namespace Minecraft {
NativeWindowDestroyEvent::NativeWindowDestroyEvent(ANativeWindow *window) : m_window(window) {
}

EventID NativeWindowDestroyEvent::getID() const {
  return EventID::E_NATIVE_WINDOW_DESTROY;
}

std::string NativeWindowDestroyEvent::getName() const {
  return "NativeWindowDestroyEvent";
}

std::any NativeWindowDestroyEvent::getData() const {
  return m_window;
}
} // namespace Minecraft