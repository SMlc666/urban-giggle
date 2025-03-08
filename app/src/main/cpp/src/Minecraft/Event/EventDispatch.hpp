//
// Created by qq103 on 2025/3/7.
//
#pragma once
#include "Events/Event.hpp"
#include "eventpp/eventdispatcher.h"
#include "Events/EventId.hpp"
namespace Minecraft {
extern eventpp::EventDispatcher<EventID, void(std::shared_ptr<Event>)> g_eventDispatcher;
} // namespace Minecraft
