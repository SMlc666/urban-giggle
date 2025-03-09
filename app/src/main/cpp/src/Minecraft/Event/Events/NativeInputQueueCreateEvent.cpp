//
// Created by qq103 on 2025/3/9.
//

#include "NativeInputQueueCreateEvent.hpp"

namespace Minecraft {
NativeInputQueueCreateEvent::NativeInputQueueCreateEvent(AInputQueue *inputQueue)
    : m_inputQueue(inputQueue) {
}

EventID NativeInputQueueCreateEvent::getID() const {
  return EventID::E_NATIVE_INPUT_QUEUE_CREATE;
}

std::string NativeInputQueueCreateEvent::getName() const {
  return "NativeInputQueueCreateEvent";
}

std::any NativeInputQueueCreateEvent::getData() const {
  return m_inputQueue;
}
} // namespace Minecraft