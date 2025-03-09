//
// Created by qq103 on 2025/3/9.
//
#include <android/input.h>
#include "Init/Init.hpp"
#include "Minecraft/Event/EventDispatch.hpp"
#include "imgui/backends/imgui_impl_android.h"
#include "Minecraft/Event/Events/NativeInputEvent.hpp"
#include "Module/GUI/Draw/Mutex.hpp"
namespace Module::GUI::Draw {
Init init_ImGuiBridge(
    "init_ImGuiBridge",
    []() {
      Minecraft::g_eventDispatcher.appendListener(
          Minecraft::EventID::E_NATIVE_INPUT, [](std::shared_ptr<Minecraft::Event> event) {
            std::lock_guard<std::mutex> lockGuard(TouchDrawMutex);
            auto Data = any_cast<Minecraft::NativeInputEvent::Data>(event->getData());
            ImGui_ImplAndroid_HandleInputEvent(Data.event);
          });
    },
    0);
} // namespace Module::GUI::Draw
