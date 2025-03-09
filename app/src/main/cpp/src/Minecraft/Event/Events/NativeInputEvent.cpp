//
// Created by qq103 on 2025/3/9.
//

#include "NativeInputEvent.hpp"
namespace Minecraft {
NativeInputEvent::NativeInputEvent(AInputEvent *event) : m_event(event) {
}
std::string NativeInputEvent::getName() const {
  return "NativeInputEvent";
}
EventID NativeInputEvent::getID() const {
  return EventID::E_NATIVE_INPUT;
}
std::any NativeInputEvent::getData() const {
  return Data{m_event};
}
} // namespace Minecraft