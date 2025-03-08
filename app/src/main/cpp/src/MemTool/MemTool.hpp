//
// Created by qq103 on 2025/3/1.
//

#pragma once
#include "KittyMemory/KittyInclude.hpp"
#include <format>
#include <shadowhook.h>
#include <string>
#include <arm_neon.h>
namespace MemTool {
template <typename T> inline T getModuleBase(const std::string &moduleName) {
    KittyScanner::ElfScanner Module =
            KittyScanner::ElfScanner::createWithPath(moduleName);
  uintptr_t base = Module.base();
  return reinterpret_cast<T>(base);
}
size_t getModuleSize(const std::string &moduleName);
class [[maybe_unused]] Hook {
public:
  Hook() = default;
  template <typename U, typename T>
  [[maybe_unused]] Hook(U funcAddr, T *newAddr, bool autoDestroy = true)
      : mAutoDestroy(autoDestroy), mNewAddr(reinterpret_cast<void *>(newAddr)),
        mFuncAddr(reinterpret_cast<void *>(funcAddr)) {
    if (mFuncAddr == nullptr || mNewAddr == nullptr) {
      throw std::runtime_error("oldAddr or newAddr is nullptr");
    }
    mStub = shadowhook_hook_func_addr(mFuncAddr, mNewAddr, &mOldAddr);
    if (mStub == nullptr) {
      int error_num = shadowhook_get_errno();
      const char* error_msg = shadowhook_to_errmsg(error_num);
      throw std::runtime_error(
          std::format("shadowhook_init failed with errornum, msg: {} {}",
                      error_num, error_msg));
    }
  }
  template <typename T>
  [[maybe_unused]] Hook(const std::string &libName, const std::string &symName, T *newAddr,
                        bool autoDestroy = true)
      : mAutoDestroy(autoDestroy), mNewAddr(reinterpret_cast<void *>(newAddr)) {
    if (newAddr == nullptr) {
      throw std::runtime_error("newAddr is nullptr");
    }
    mStub = shadowhook_hook_sym_name(libName.c_str(), symName.c_str(), mNewAddr, &mOldAddr);
    if (mStub == nullptr) {
      int error_num = shadowhook_get_errno();
      const char* error_msg = shadowhook_to_errmsg(error_num);
      throw std::runtime_error(
          std::format("shadowhook_init failed with  errornum, msg: {} {}",
                      error_num, error_msg));
    }
  }
  ~Hook();
  template <typename T, typename... Args> [[maybe_unused]] T callOld(Args... args) {
    return reinterpret_cast<T (*)(Args...)>(mOldAddr)( // NOLINT(*-pro-type-reinterpret-cast)
        args...);
  }
  Hook(const Hook &) = delete;
  Hook &operator=(const Hook &) = delete;
  Hook(Hook &&) = default;
  Hook &operator=(Hook &&) = default;
  template <typename T = void *> T getOldAddr() const {
    return reinterpret_cast<T>(mOldAddr); // NOLINT(*-pro-type-reinterpret-cast)
  }
  template <typename T = void **> T getNewAddr() const {
    return reinterpret_cast<T>(mNewAddr); // NOLINT(*-pro-type-reinterpret-cast)
  }
  template <typename T = void *> T getFuncAddr() const {
    return reinterpret_cast<T>(mFuncAddr); // NOLINT(*-pro-type-reinterpret-cast)
  }

private:
  void *mOldAddr = nullptr;
  [[maybe_unused]] void *mNewAddr = nullptr;
  void *mFuncAddr = nullptr;
  bool mAutoDestroy = true;
  void *mStub = nullptr;
};

} // namespace MemTool