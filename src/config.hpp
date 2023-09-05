#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

#include <map>
#include <string>
#include <vector>

#include "consts.hpp"

namespace config {

class Config {
public:
  Config(int argc, char **argv);

private:
  ulong size = 0;
  uint block_size = 512;
  ulong count = 1;
  ubyte threads_count = 1;
  std::string input_file = "";
  std::string output_file = "";

  std::vector<std::string> valid_args{
      // Full string options.
      "proc",
      "size",
      "blocksize",
      "count",
      "input",
      "output",
      "continue",

      // Short options.
      "j",
      "s",
      "b",
      "c",
      "i",
      "o"
  };

  void check_conflicting_args(std::map<std::string, std::string> arg_list);
};

} // namespace config

#endif // _CONFIG_HPP_
