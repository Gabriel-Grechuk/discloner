#ifndef _IO_HPP_
#define _IO_HPP_

#include <iostream>
#include <string>

namespace io {

template <class... Args> void error(Args... args) {
  (std::cout << "[ \033[41m\033[97mERROR\033[0m ] " << ... << args) << "\n";
}

template <class... Args> void info(Args... args) {

  (std::cout << "[ \033[1m\033[32mINFO\033[0m ] " << ... << args) << "\n";
}

template <class... Args> void log(Args... args) {

  (std::cout << ... << args) << "\n";
}

} // namespace io

#endif // _IO_HPP_
