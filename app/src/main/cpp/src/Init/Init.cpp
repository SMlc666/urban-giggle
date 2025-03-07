//
// Created by qq103 on 2025/3/1.
//

#include "Init.hpp"

std::unordered_map<std::string, init_list> InitList;
Init::Init(const std::string &name, std::function<void()> func, int mpriority)
    : priority(mpriority) {
  InitList[name] = {func, mpriority};
}
int Init::getPriority() const { return priority; }