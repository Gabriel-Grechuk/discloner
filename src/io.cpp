#include "io.hpp"

#include <iostream>

void io::error(std::string str) {
  std::cout << "[ \033[41m\033[97mERROR\033[0m ] " << str << std::endl;
}
