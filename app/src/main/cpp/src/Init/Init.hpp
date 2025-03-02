//
// Created by qq103 on 2025/3/1.
//

#ifndef MBLOADER_INIT_HPP
#define MBLOADER_INIT_HPP
#include <unordered_map>
#include <string>
#include <functional>
extern std::unordered_map<std::string, std::function<void()>> InitList;

class Init {
public:
  Init(const std::string& name, std::function<void()> func);
};


#endif //MBLOADER_INIT_HPP