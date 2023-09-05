#include "tools.hpp"

#include <algorithm>
#include <cstring>
#include <regex>

#include "consts.hpp"

namespace tools {

template <typename T> T extract_number(std::string str) {
  std::string buff(str);

  buff.erase(std::remove_if(buff.begin(), buff.end(),
                            [](char c) { return std::isdigit(c); }),
             str.end());

  if (buff.compare("") == 0)
    return 0;

  std::stringstream num;
  num << buff;

  T value;
  num >> value;

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
  uint input_value = extract_number<uint>(str);

  const std::regex b_regex("\\d+B|b");
  const std::regex kb_regex("\\d+KB|kb");
  const std::regex mb_regex("\\d+MB|mb");
  const std::regex gb_regex("\\d+GB|gb");
  const std::regex tb_regex("\\d+TB|tb");

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

template <typename T, typename U>
bool check_if_defined_in_map(std::map<T, U> map, T key);

} // namespace tools
