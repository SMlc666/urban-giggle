//
// Created by qq103 on 2025/3/9.
//

#include "NativeActivityCreateEvent.hpp"
namespace Minecraft {
NativeActivityCreateEvent::NativeActivityCreateEvent(ANativeActivity *activity)
    : m_activity(activity) {
}
std::string NativeActivityCreateEvent::getName() const {
  return "NativeActivityCreateEvent";
}
EventID NativeActivityCreateEvent::getID() const {
  return EventID::E_NATIVE_ACTIVITY_CREATE;
}
std::any NativeActivityCreateEvent::getData() const {
  return m_activity;
}
} // namespace Minecraft