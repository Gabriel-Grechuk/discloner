#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>

namespace core {
namespace error {

  /* DATA TYPE */
  struct status
  {
    int error_code;
    std::string where;
    std::string message;

    status& operator= (const status& status2);
    bool operator== (const status& status2);
  };

  static status ok = {0, "", ""};    

  /* FUNCTIONS */
  static status genStatus(int error_code, const std::string& where, const std::string& message)
  {
    return status {error_code, where, message};
  }

} // namespace Error.
} // namespace Core.

#endif

