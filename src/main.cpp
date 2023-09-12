#include "config.hpp"

int main(const int argc, const char **argv) {
  config::Config conf(argc, argv);

  conf.print_loaded_args();

  return 0;
}
