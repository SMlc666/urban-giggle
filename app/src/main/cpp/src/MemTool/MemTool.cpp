//
// Created by qq103 on 2025/3/1.
//

#include "MemTool.hpp"
#include <shadowhook.h>
#include "Init/Init.hpp"
#include <format>
[[maybe_unused]] Init init_MemTool("init_MemTool", []() {
  int code = shadowhook_init(shadowhook_mode_t::SHADOWHOOK_MODE_UNIQUE, false);
  if (code != SHADOWHOOK_ERRNO_OK) {
    int error_num = shadowhook_get_errno();
    const char* error_msg = shadowhook_to_errmsg(error_num);
    throw std::runtime_error(std::format("shadowhook_init failed with code ,errornum, msg: {} {} {}",code,error_num,error_msg));
  }
});
MemTool::Hook::~Hook() {
  if (mAutoDestroy) {
    shadowhook_unhook(mStub);
  }
}