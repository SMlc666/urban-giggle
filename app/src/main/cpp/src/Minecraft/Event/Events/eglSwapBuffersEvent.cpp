//
// Created by qq103 on 2025/3/9.
//

#include "eglSwapBuffersEvent.hpp"

namespace Minecraft {
eglSwapBuffersEvent::eglSwapBuffersEvent(EGLDisplay *display, EGLSurface *surface)
    : m_display(display), m_surface(surface) {
}
std::string eglSwapBuffersEvent::getName() const {
  return "eglSwapBuffersEvent";
}
EventID eglSwapBuffersEvent::getID() const {
  return EventID::E_EGL_SWAP_BUFFERS;
}
std::any eglSwapBuffersEvent::getData() const {
  return Data{m_display, m_surface};
}
} // namespace Minecraft