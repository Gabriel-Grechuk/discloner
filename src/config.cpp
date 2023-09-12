#include <cstring>
#include <fstream>
#include <iostream>

#include "config.hpp"
#include "consts.hpp"
#include "io.hpp"
#include "tools.hpp"

#define CHECK_ARG(x, y, z) (std::strcmp(x, y) == 0 || std::strcmp(x, z) == 0)

namespace config {

Config::Config(const int argc, const char **argv) {
  std::vector<std::pair<std::string, std::string>> mapped_args =
      validate_args(argc, argv);

  for (auto &arg : mapped_args) {
    if (CHECK_ARG(arg.first.c_str(), "--proc", "-j")) {
      const auto buff = std::atoi(arg.second.c_str());
      if (buff == 0)
        continue;

      threads_count = buff;
      continue;
    }

    else if (CHECK_ARG(arg.first.c_str(), "--size", "-s")) {
      const auto buff = tools::size_str_to_ulong(arg.second);
      if (buff == 0)
        continue;

      size = buff;
      continue;
    }

    else if (CHECK_ARG(arg.first.c_str(), "--blocksize", "-b")) {
      const auto buff = std::atoi(arg.second.c_str());
      if (buff == 0)
        continue;

      block_size = buff;
      continue;
    }

    else if (CHECK_ARG(arg.first.c_str(), "--count", "-c")) {
      const auto buff = std::atoi(arg.second.c_str());
      if (buff == 0)
        continue;

      count = buff;
      continue;
    }

    else if (CHECK_ARG(arg.first.c_str(), "--input", "-i")) {
      std::ifstream buff(arg.second.c_str());
      if (!buff.good()) {
        io::error("Input file not found: \033[31m", arg.second, "\033[0m");
        exit(2);
      }

      input_file = arg.second;
      continue;
    }

    else if (CHECK_ARG(arg.first.c_str(), "--output", "-o")) {
      output_files.push_back(arg.second);
      continue;
    }

    else if (std::strcmp(arg.first.c_str(), "--continue") == 0) {
      continue_last_process = true;
      continue;
    }

    else if (check_if_arg_str(arg.first.c_str())) {
      io::error("It really should not happen... Invalid arg after arg "
                "validation: \033[31m",
                arg.first, "\033[0m");
      exit(2);
    }
  }
}

std::vector<std::pair<std::string, std::string>>
Config::validate_args(const int argc, const char **argv) {
  ubyte count_proc = 0;
  ubyte count_size = 0;
  ubyte count_block_size = 0;
  ubyte count_count = 0;
  ubyte count_input = 0;
  ubyte count_output = 0;

  for (uint i = 1; i < argc; i++) {
    if (CHECK_ARG(argv[i], "--proc", "-j")) {
      ++count_proc;
      continue;
    } else if (CHECK_ARG(argv[i], "--size", "-s")) {
      ++count_size;
      continue;
    } else if (CHECK_ARG(argv[i], "--blocksize", "-b")) {
      ++count_block_size;
      continue;
    } else if (CHECK_ARG(argv[i], "--count", "-c")) {
      ++count_size;
      continue;
    } else if (CHECK_ARG(argv[i], "--input", "-i")) {
      ++count_input;
      continue;
    } else if (CHECK_ARG(argv[i], "--output", "-o")) {
      ++count_output;
      continue;
    } else if (std::strcmp(argv[i], "--continue") == 0) {
      continue;
    } else if (check_if_arg_str(argv[i])) {
      io::error("Invalid arg: \033[31m", argv[i], "\033[0m");
      exit(1);
    }
  }

  if (count_proc > 1) {
    io::error("Too much thread args.");
    exit(1);
  }

  else if (count_size > 1) {
    io::error("Too much size args.");
    exit(1);
  }

  else if (count_block_size > 1) {
    io::error("Too much block size args.");
    exit(1);
  }

  else if (count_count > 1) {
    io::error("Too much count args.");
    exit(1);
  }

  else if (count_input > 1) {
    io::error("Too much input args.");
    exit(1);
  }

  else if (count_input == 0) {
    io::error("Input file required.");
    exit(1);
  }

  else if (count_output == 0) {
    io::error("Output file required.");
    exit(1);
  }

  std::vector<std::pair<std::string, std::string>> args;

  bool ignore_next = false;
  for (uint i = 1; i < argc; i++) {
    if (ignore_next) {
      ignore_next = false;
      continue;
    }

    if (!check_if_arg_str(argv[i]))
      io::error("Here: Invalid arg: \033[31m", argv[i], "\033[0m");
    else
      ignore_next = true;

    if (std::strcmp(argv[i], "--continue") == 0) {
      args.push_back(std::make_pair("--continue", "true"));
      ignore_next = false;
      continue;
    }

    args.push_back(std::make_pair(argv[i], argv[i + 1]));
  }

  return args;
}

bool Config::check_if_arg_str(const char *str) {
  if (str[0] == '-')
    return true;
  else
    return false;
}

void Config::print_loaded_args() {
  io::info("Loaded config:");

  io::log("  size: ", size);
  io::log("  block size: ", block_size);
  io::log("  number of threads: ", (int)threads_count);
  io::log("  count: ", count);
  io::log("  continue last process: ", continue_last_process);
  io::log("  input file: ", input_file);

  io::log("  output files: ", input_file);
  for (auto &file : output_files) {
    io::log("    ", file);
  }
}

} // namespace config
