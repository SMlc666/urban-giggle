//
// Created by qq103 on 2025/3/8.
//

#include "Config.hpp"
#include <fstream>
namespace Module {
Config::Config(const std::string &config_file_path) : config_file_path_(config_file_path) {
  if (!std::filesystem::exists(config_file_path_)) {
    throw std::runtime_error("Config file not found: " + config_file_path_.string());
  }

  try {
    std::ifstream file(config_file_path_);
    if (!file.is_open()) {
      throw std::runtime_error("Failed to open config file: " + config_file_path_.string());
    }

    config_data_ = nlohmann::json::parse(file);
  } catch (const nlohmann::json::parse_error &e) {
    throw std::runtime_error("JSON parse error: " + std::string(e.what()));
  } catch (const std::exception &e) {
    throw std::runtime_error("Failed to read config: " + std::string(e.what()));
  }
}

Config::Config(const std::filesystem::path &config_file_path) : Config(config_file_path.string()) {
}

std::string Config::getConfigFilePath() const {
  return config_file_path_.string();
}

std::filesystem::path Config::getConfigFilePathFS() const {
  return config_file_path_;
}

void Config::saveConfig() {
  try {
    std::ofstream file(config_file_path_);
    if (!file.is_open()) {
      throw std::runtime_error("Failed to open config file for writing: " +
                               config_file_path_.string());
    }

    file << config_data_.dump(4);
    if (file.fail()) {
      throw std::runtime_error("Failed to write config data to file");
    }
  } catch (const std::exception &e) {
    throw std::runtime_error("Config save failed: " + std::string(e.what()));
  }
}

nlohmann::json &Config::getConfigData() {
  return config_data_;
}
} // namespace Module