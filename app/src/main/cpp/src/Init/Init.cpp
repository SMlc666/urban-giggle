//
// Created by qq103 on 2025/3/1.
//

#include "Init.hpp"

std::unordered_map<std::string, std::function<void()>> InitList;
Init::Init(const std::string& name, std::function<void()> func) {
  InitList[name] = func;
}