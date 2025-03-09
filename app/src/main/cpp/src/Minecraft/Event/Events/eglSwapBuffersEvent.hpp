//
// Created by qq103 on 2025/3/9.
//

#pragma once
#include "Event.hpp"
#include <EGL/egl.h>
namespace Minecraft {
class eglSwapBuffersEvent : public Event {
private:
  EGLDisplay *m_display;
  EGLSurface *m_surface;

public:
  struct Data {
    EGLDisplay *display;
    EGLSurface *surface;
  };
  eglSwapBuffersEvent(EGLDisplay *display, EGLSurface *surface);
  [[nodiscard]] EventID getID() const override;
  [[nodiscard]] std::string getName() const override;
  [[nodiscard]] std::any getData() const override;
};
} // namespace Minecraft
