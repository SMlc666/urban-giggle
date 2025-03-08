//
// Created by qq103 on 2025/3/7.
//

#include "EventDispatch.hpp"

namespace Minecraft {
eventpp::EventDispatcher<EventID, void(std::shared_ptr<Event>)> g_eventDispatcher;
} // namespace Minecraft