#include "sys.hpp"
#include <thread>

namespace sys {

ubyte get_cpu_count() {
  const ubyte cpu_count = std::thread::hardware_concurrency();
  if (cpu_count == 0)
    return 1;

  return cpu_count;
}

} // namespace sys
