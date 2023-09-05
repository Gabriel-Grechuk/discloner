#ifndef _TOOLS_HPP_
#define _TOOLS_HPP_

#include <string>
#include <vector>

namespace tools {
std::string normalize_str(std::string str);

template <typename T> bool check_if_includes(std::vector<T> vec, T element);

bool check_if_includes_str(std::vector<std::string> vec, std::string element);
} // namespace tools

#endif // _TOOLS_HPP_
