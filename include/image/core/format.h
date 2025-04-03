#pragma once

#include <filesystem>

namespace Image {

class Format {
public:
  enum Tp {
    PNG,
    JPEG,
    Undefined
  };

  static Tp FromPath(std::filesystem::path path) {
    std::string extension = path.extension().string();

    if (extension == ".png") {
      return PNG;
    } 
    if (extension == ".jpeg" || extension == ".jpg") {
      return JPEG;
    }
    throw std::runtime_error("undefined file format");
  }
  static Tp FromPath(const char *path) {
    return FromPath(std::filesystem::path(path));
  }
  static Tp FromPath(const std::string &path) {
    return FromPath(std::filesystem::path(path));
  }
};

}; // Image
