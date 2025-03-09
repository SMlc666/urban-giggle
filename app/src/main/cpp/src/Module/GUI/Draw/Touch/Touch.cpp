//
// Created by qq103 on 2025/3/9.
//
//处理和Input相关的事件
#include "Init/Init.hpp"
#include "Minecraft/Event/EventDispatch.hpp"
#include "Minecraft/Event/Events/NativeInputEvent.hpp"
#include "Minecraft/Event/Events/NativeInputQueueCreateEvent.hpp"
#include "Minecraft/Event/Events/NativeInputQueueDestroyEvent.hpp"
#include "Utils/Utils.hpp"
#include "Log/Log.hpp"
#include <thread>
#include "MemTool/MemTool.hpp"
MemTool::Hook onInputEventHook;
MemTool::Hook onInputQueueCreatedHook;
MemTool::Hook onInputQueueDestroyedHook;
int32_t onInputEvent_(struct android_app *app, AInputEvent *event) {
  Minecraft::g_eventDispatcher.dispatch(Minecraft::EventID::E_NATIVE_INPUT,
                                        std::make_shared<Minecraft::NativeInputEvent>(event));
  return onInputEventHook.callOld<int32_t>(app, event);
}
void onInputQueueCreated_(ANativeActivity *activity, AInputQueue *queue) {
  onInputQueueCreatedHook.callOld<void>(activity, queue);
  Minecraft::g_eventDispatcher.dispatch(
      Minecraft::EventID::E_NATIVE_INPUT_QUEUE_CREATE,
      std::make_shared<Minecraft::NativeInputQueueCreateEvent>(queue));
  TOOLBOX_LOG_D("onInputQueueCreated");
}
void onInputQueueDestroyed_(ANativeActivity *activity, AInputQueue *queue) {

  onInputQueueDestroyedHook.callOld<void>(activity, queue);
  Minecraft::g_eventDispatcher.dispatch(
      Minecraft::EventID::E_NATIVE_INPUT_QUEUE_DESTROY,
      std::make_shared<Minecraft::NativeInputQueueDestroyEvent>(queue));
  TOOLBOX_LOG_D("onInputQueueDestroyed");
}
namespace Module::GUI::Draw {
Init init_Touch("init_Touch", []() {
  Minecraft::g_eventDispatcher.appendListener(
      Minecraft::EventID::E_NATIVE_ACTIVITY_CREATE, [](std::shared_ptr<Minecraft::Event> event) {
        auto *activity = std::any_cast<ANativeActivity *>(event->getData());
        onInputQueueCreatedHook =
            MemTool::Hook(activity->callbacks->onInputQueueCreated, &onInputQueueCreated_, false);
        onInputQueueDestroyedHook = MemTool::Hook(activity->callbacks->onInputQueueDestroyed,
                                                  &onInputQueueDestroyed_, false);
        Minecraft::g_eventDispatcher.appendListener(
            Minecraft::EventID::E_NATIVE_INPUT_QUEUE_CREATE,
            [](std::shared_ptr<Minecraft::Event> /*event*/) {
              auto *app = Utils::GetAndroidApp();
              onInputEventHook = MemTool::Hook(app->onInputEvent, &onInputEvent_, false);
            });
      });
});
} // namespace Module::GUI::Draw