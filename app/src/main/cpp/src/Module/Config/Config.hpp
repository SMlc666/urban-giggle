//
// Created by qq103 on 2025/3/8.
//

#pragma once
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>
namespace Module {
class Config {
public:
  Config() = default;
  Config(const std::string &config_file_path);
  Config(const std::filesystem::path &config_file_path);
  std::string getConfigFilePath() const;
  std::filesystem::path getConfigFilePathFS() const;
  void saveConfig();
  nlohmann::json &getConfigData();

private:
  std::filesystem::path config_file_path_;
  nlohmann::json config_data_;
};

} // namespace Module
