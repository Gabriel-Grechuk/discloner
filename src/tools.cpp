#include "tools.hpp"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <regex>

#include "consts.hpp"

namespace tools {

int extract_number(std::string str) {
  std::string buff("");
  int value = 0;

  for (const auto &c : str) {
    if (std::isdigit(c))
      buff += c;
  }

  if (buff.compare("") == 0)
    return 0;

  value = std::atoi(buff.c_str());

  return value;
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

ulong size_str_to_ulong(std::string str) {
  ulong input_value = extract_number(str);

  const std::regex b_regex("[0-9]+[Bb]+");
  const std::regex kb_regex("[0-9]+[KBkb]+");
  const std::regex mb_regex("[0-9]+[MBmb]+");
  const std::regex gb_regex("[0-9]+[GBgb]+");
  const std::regex tb_regex("[0-9]+[TBtb]+");

  if (std::regex_match(str, b_regex))
    return input_value;
  else if (std::regex_match(str, kb_regex))
    return input_value * 1000;
  else if (std::regex_match(str, mb_regex))
    return input_value * 1000000;
  else if (std::regex_match(str, gb_regex))
    return input_value * 1000000000;
  else if (std::regex_match(str, tb_regex))
    return input_value * 1000000000000;
  else
    return 0;
}

} // namespace tools
