//
// Created by qq103 on 2025/3/9.
//

#include "Utils.hpp"
#include "Module/GUI/Draw/Draw.hpp"
android_app *Utils::GetAndroidApp() {
  if (Module::GUI::Draw::activity == nullptr) {
    return nullptr;
  }
  return reinterpret_cast<android_app *>(Module::GUI::Draw::activity->instance);
}