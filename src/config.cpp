#include <cstring>
#include <map>
#include <string>

#include "config.hpp"
#include "consts.hpp"
#include "tools.hpp"

namespace config {

Config::Config(int argc, char *argv[]) {
  std::map<std::string, std::string> mapped_args;
  std::vector<std::string> args;

  for (uint i = 0; i <= argc; i++) {
    std::string buff;
    buff.copy(argv[i], std::strlen(argv[i]));
    args.push_back(buff);
  }

  for (ubyte i = 0; i <= argc; i++) {
    if (tools::check_if_includes_str(valid_args, args[i]))
      mapped_args[args[i]] = args[i + 1];
  }

  
}

} // namespace config
