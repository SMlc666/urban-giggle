//
// Created by qq103 on 2025/3/7.
//

#ifndef MINERAFT_TOOLBOX_EVENTDISPATCH_HPP
#define MINERAFT_TOOLBOX_EVENTDISPATCH_HPP
#include "eventpp/eventdispatcher.h"
#include "Events/EventId.hpp"
namespace Minecraft {
extern eventpp::EventDispatcher<EventID, void()> g_eventDispatcher;
} // namespace Minecraft

#endif //MINERAFT_TOOLBOX_EVENTDISPATCH_HPP
