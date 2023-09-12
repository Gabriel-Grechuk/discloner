#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

#include <map>
#include <string>
#include <vector>

#include "consts.hpp"
#include "sys.hpp"

namespace config {

class Config {
public:
  Config(const int argc, const char **argv);

  // Getters.
  ulong get_size() { return size; }
  uint get_block_size() { return block_size; }
  ulong get_count() { return count; }
  ubyte get_threads_count() { return threads_count; }
  std::string get_input_file() { return input_file; }
  std::vector<std::string> get_output_files() { return output_files; }

  void print_loaded_args();

private:
  ulong size = 0;
  uint block_size = 512;
  ulong count = 0;
  ubyte threads_count = sys::get_cpu_count();
  bool continue_last_process = false;
  std::string input_file = "";
  std::vector<std::string> output_files;

  std::vector<std::string> valid_args{// Full string options.
                                      "--proc", "--size", "--blocksize",
                                      "--count", "--input", "--output",
                                      "--continue",

                                      // Short options.
                                      "-j", "-s", "-b", "-c", "-i", "-o"};

  std::vector<std::pair<std::string, std::string>>
  validate_args(const int argc, const char **argv);
  bool check_if_arg_str(const char *str);
};

} // namespace config

#endif // _CONFIG_HPP_
