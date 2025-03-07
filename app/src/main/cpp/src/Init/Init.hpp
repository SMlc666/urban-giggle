//
// Created by qq103 on 2025/3/1.
//

#ifndef MBLOADER_INIT_HPP
#define MBLOADER_INIT_HPP
#include <unordered_map>
#include <string>
#include <functional>
struct init_list {
  std::function<void()> func;
  int priority;
};
extern std::unordered_map<std::string, init_list> InitList;

class Init {
public:
  Init(const std::string &name, std::function<void()> func, int mpriority = 0);
  [[nodiscard]] int getPriority() const;

private:
  int priority;
};


#endif //MBLOADER_INIT_HPP