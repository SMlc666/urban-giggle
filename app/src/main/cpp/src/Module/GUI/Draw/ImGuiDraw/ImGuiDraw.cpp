//
// Created by qq103 on 2025/3/9.
//

#include "ImGuiDraw.hpp"
#include "imgui/imgui.h"
#include "Log/Log.hpp"
#include "Init/Init.hpp"
#include "Module/GUI/Draw/Draw.hpp"
#include "Minecraft/Event/EventDispatch.hpp"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "Module/GUI/Draw/Mutex.hpp"
#include "Utils/Utils.hpp"
#include <format>
#include <thread>
static void INITIMGUI() {
  ANativeActivity *activity = Module::GUI::Draw::activity;
  ANativeWindow *window = Utils::GetAndroidApp()->window;
  TOOLBOX_LOG_D("init_ImGuiDraw: ANativeActivity: %p, ANativeWindow: %p", activity, window);
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  Module::GUI::Draw::g_IniFilename = std::format("{}/imgui.ini", activity->externalDataPath);
  io.IniFilename = Module::GUI::Draw::g_IniFilename.c_str();
  ImGui::StyleColorsDark();
  ImGui_ImplAndroid_Init(window);
  ImGui_ImplOpenGL3_Init("#version 300 es");
  ImFontConfig font_cfg;
  font_cfg.SizePixels = 22.0f;
  io.Fonts->AddFontDefault(&font_cfg);
  ImGui::GetStyle().ScaleAllSizes(3.0f);
  TOOLBOX_LOG_D("init_ImGuiDraw: initialized");
  Module::GUI::Draw::g_initialized = true;
}
namespace Module::GUI::Draw {
bool g_initialized = false;
std::string g_IniFilename;
Init init_ImGuiDraw(
    "init_ImGuiDraw",
    []() {
      Minecraft::g_eventDispatcher.appendListener(
          Minecraft::EventID::E_EGL_SWAP_BUFFERS, [](std::shared_ptr<Minecraft::Event> event) {
            if (g_initialized) {
              std::lock_guard<std::mutex> lock(TouchDrawMutex);
              ImGui_ImplOpenGL3_NewFrame();
              ImGui_ImplAndroid_NewFrame();
              ImGui::NewFrame();
              ImGui::ShowDemoWindow();
              ImGui::Render();
              ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            } else {
              INITIMGUI();
            }
          });
      Minecraft::g_eventDispatcher.appendListener(Minecraft::EventID::E_NATIVE_WINDOW_DESTROY,
                                                  [](std::shared_ptr<Minecraft::Event> event) {
                                                    if (!g_initialized) {
                                                      return;
                                                    }
                                                    ImGui_ImplOpenGL3_Shutdown();
                                                    ImGui_ImplAndroid_Shutdown();
                                                    ImGui::DestroyContext();
                                                    g_initialized = false;
                                                  });
    },
    0); //注册事件
} // namespace Module::GUI::Draw
