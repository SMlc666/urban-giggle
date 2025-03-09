//
// Created by qq103 on 2025/3/8.
//

#pragma once
namespace Minecraft {
enum class EventID : int {
  E_MODULE_LOAD,
  E_NATIVE_ACTIVITY_CREATE,
  E_NATIVE_INPUT,
  E_NATIVE_WINDOW_CREATE,
  E_NATIVE_WINDOW_DESTROY,
  E_NATIVE_INPUT_QUEUE_CREATE,
  E_NATIVE_INPUT_QUEUE_DESTROY,
  E_EGL_SWAP_BUFFERS,
};
} // namespace Minecraft
