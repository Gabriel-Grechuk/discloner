#include <cstring>
#include <iostream>
#include <string>

#include "config.hpp"
#include "consts.hpp"
#include "io.hpp"
#include "tools.hpp"

namespace config {

Config::Config(int argc, char **argv) {
  std::map<std::string, std::string> mapped_args;
  std::vector<std::string> args;

  for (uint i = 0; i < argc; i++) {
    std::string buff;
    buff.copy(argv[i], std::strlen(argv[i]));
    args.push_back(buff);
  }

  for (ubyte i = 0; i <= argc; i++) {
    if (tools::check_if_includes_str(valid_args, args[i]))
      mapped_args[args[i]] = args[i + 1];
  }

  check_conflicting_args(mapped_args);
}

void Config::check_conflicting_args(
    std::map<std::string, std::string> arg_list) {

  if (tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                               "proc") &&
      tools::check_if_defined_in_map<std::string, std::string>(arg_list, "j")) {
    io::error("Option --proc conflicting with -j");
    exit(1);
  }

  else if (tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "size") &&
           tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "s")) {
    io::error("Option --size conflicting with -s");
    exit(1);
  }

  else if (tools::check_if_defined_in_map<std::string, std::string>(
               arg_list, "blocksize") &&
           tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "b")) {
    io::error("Option --blocksize conflicting with -b");
    exit(1);
  }

  else if (tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "count") &&
           tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "c")) {
    io::error("Option --count conflicting with -c");
    exit(1);
  }

  else if (tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "input") &&
           tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "i")) {
    io::error("Option --input conflicting with -i");
    exit(1);
  }

  else if (tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "output") &&
           tools::check_if_defined_in_map<std::string, std::string>(arg_list,
                                                                    "o")) {
    io::error("Option --output conflicting with -o");
    exit(1);
  }
}

} // namespace config
