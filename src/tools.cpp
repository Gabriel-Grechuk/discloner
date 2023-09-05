#include "tools.hpp"

#include <algorithm>
#include <cstring>

#include "consts.hpp"

namespace tools {

std::string normalize_str(std::string str) {
  char *bf;
  std::strcpy(bf, str.c_str());
  std::string buff;
  buff.copy(bf, str.length());

  buff.erase(
      std::remove_if(buff.begin(), buff.end(),
                     [](char c) { return std::isspace(c) || std::isalpha(c); }),
      str.end());

  return buff;
}

template <typename T> bool check_if_includes(std::vector<T> vec, T element) {
  for (auto const &vec_element : vec) {
    if (vec_element == element)
      return true;
  }

  return false;
}

bool check_if_includes_str(std::vector<std::string> vec, std::string element) {
  for (const auto &vec_element : vec) {
    if (vec_element.compare(element.c_str()) == 0)
      return true;
  }
  return false;
}

ulong size_str_to_ulong(std::string str) {}

} // namespace tools
