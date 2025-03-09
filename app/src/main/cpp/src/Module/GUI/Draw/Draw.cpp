//
// Created by qq103 on 2025/3/9.
//
//处理和绘制有关的事件
#include <EGL/egl.h>
#include "Draw.hpp"
#include "Init/Init.hpp"
#include "Log/Log.hpp"
#include "Minecraft/Event/EventDispatch.hpp"
#include "Minecraft/Event/Events/ModuleLoadEvent.hpp"
#include "Minecraft/Event/Events/NativeActivityCreateEvent.hpp"
#include "Minecraft/Event/Events/NativeWindowCreateEvent.hpp"
#include "Minecraft/Event/Events/NativeWindowDestroyEvent.hpp"
#include "Minecraft/Event/Events/eglSwapBuffersEvent.hpp"
#include "Utils/Utils.hpp"
#include "MemTool/MemTool.hpp"
#include "imgui//imgui.h"
#include <thread>
MemTool::Hook eglSwapBuffersHook;
MemTool::Hook ANativeActivity_onCreateHook;
MemTool::Hook OnNativeWindowDestroyedHook;
MemTool::Hook OnNativeWindowCreatedHook;
ANativeActivity *Module::GUI::Draw::activity;
void ANativeActivity_onCreate_new(ANativeActivity *activity, void *savedState,
                                  size_t savedStateSize) {
  ANativeActivity_onCreateHook.callOld<void>(activity, savedState, savedStateSize);
  TOOLBOX_LOG_D("ANativeActivity_onCreate_new");
  Module::GUI::Draw::activity = activity;
  Minecraft::g_eventDispatcher.dispatch(
      Minecraft::EventID::E_NATIVE_ACTIVITY_CREATE,
      std::make_shared<Minecraft::NativeActivityCreateEvent>(activity));
}
void OnNativeWindowCreated_new(ANativeActivity *activity, ANativeWindow *window) {
  OnNativeWindowCreatedHook.callOld<void>(activity, window);
  TOOLBOX_LOG_D("OnNativeWindowCreated_new");
  Minecraft::g_eventDispatcher.dispatch(
      Minecraft::EventID::E_NATIVE_WINDOW_CREATE,
      std::make_shared<Minecraft::NativeWindowCreateEvent>(window));
}
void OnNativeWindowDestroyed_new(ANativeActivity *activity, ANativeWindow *window) {
  OnNativeWindowDestroyedHook.callOld<void>(activity, window);
  TOOLBOX_LOG_D("OnNativeWindowDestroyed_new");
  Minecraft::g_eventDispatcher.dispatch(
      Minecraft::EventID::E_NATIVE_WINDOW_DESTROY,
      std::make_shared<Minecraft::NativeWindowDestroyEvent>(window));
}
EGLBoolean eglSwapBuffers_new(EGLDisplay dpy, EGLSurface surface) {
  Minecraft::g_eventDispatcher.dispatch(
      Minecraft::EventID::E_EGL_SWAP_BUFFERS,
      std::make_shared<Minecraft::eglSwapBuffersEvent>(&dpy, &surface));
  return eglSwapBuffersHook.callOld<EGLBoolean>(dpy, surface);
}
Init init_Draw(
    "init_Draw",
    []() {
      TOOLBOX_LOG_D("init_Draw");
      eglSwapBuffersHook = MemTool::Hook("libEGL.so", "eglSwapBuffers", &eglSwapBuffers_new, false);
      Minecraft::g_eventDispatcher.appendListener(
          Minecraft::EventID::E_MODULE_LOAD, [](std::shared_ptr<Minecraft::Event> event) {
            ANativeActivity_onCreateHook =
                MemTool::Hook("libminecraftpe.so", "ANativeActivity_onCreate",
                              &ANativeActivity_onCreate_new, false);
          });
      Minecraft::g_eventDispatcher.appendListener(
          Minecraft::EventID::E_NATIVE_ACTIVITY_CREATE,
          [](std::shared_ptr<Minecraft::Event> event) {
            TOOLBOX_LOG_D("E_NATIVE_ACTIVITY_CREATE");
            auto *activity = std::any_cast<ANativeActivity *>(event->getData());
            OnNativeWindowCreatedHook = MemTool::Hook(activity->callbacks->onNativeWindowCreated,
                                                      &OnNativeWindowCreated_new, false);
            OnNativeWindowDestroyedHook = MemTool::Hook(
                activity->callbacks->onNativeWindowDestroyed, &OnNativeWindowDestroyed_new, false);
          });
    },
    0);