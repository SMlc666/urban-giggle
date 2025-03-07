//
// Created by qq103 on 2025/3/7.
//

#include "EventDispatch.hpp"

namespace Minecraft {
eventpp::EventDispatcher<EventID, void()> g_eventDispatcher;
} // namespace Minecraft