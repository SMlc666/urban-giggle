//
// Created by qq103 on 2025/3/9.
//

#include "NativeInputQueueDestroyEvent.hpp"

namespace Minecraft {
NativeInputQueueDestroyEvent::NativeInputQueueDestroyEvent(AInputQueue *inputQueue)
    : m_inputQueue(inputQueue) {
}

EventID NativeInputQueueDestroyEvent::getID() const {
  return EventID::E_NATIVE_INPUT_QUEUE_DESTROY;
}

std::string NativeInputQueueDestroyEvent::getName() const {
  return "NativeInputQueueDestroyEvent";
}

std::any NativeInputQueueDestroyEvent::getData() const {
  return m_inputQueue;
}
} // namespace Minecraft