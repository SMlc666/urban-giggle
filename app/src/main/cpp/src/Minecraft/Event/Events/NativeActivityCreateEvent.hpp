//
// Created by qq103 on 2025/3/9.
//

#pragma once
#include <android/native_activity.h>
#include "Event.hpp"
namespace Minecraft {
class NativeActivityCreateEvent : public Event {
private:
  ANativeActivity *m_activity;

public:
  NativeActivityCreateEvent(ANativeActivity *activity);
  [[nodiscard]] EventID getID() const override;
  [[nodiscard]] std::string getName() const override;
  [[nodiscard]] std::any getData() const override;
};
} // namespace Minecraft