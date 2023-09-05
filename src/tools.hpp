#ifndef _TOOLS_HPP_
#define _TOOLS_HPP_

#include <map>
#include <string>
#include <vector>

namespace tools {

template <typename T> bool check_if_includes(std::vector<T> vec, T element);

int extract_number(std::string str);

bool check_if_includes_str(std::vector<std::string> vec, std::string element);

ulong size_str_to_ulong(std::string str);

template <class T, class U>
bool check_if_defined_in_map(std::map<T, U> map, T key) {
  if (map.find(key) == map.end())
    return false;

  return true;
}

} // namespace tools

#endif // _TOOLS_HPP_
