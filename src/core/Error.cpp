#include "Error.h"

using core::error::status;


status& status::operator= (const status& status2)
{
  if(this == &status2)
    return *this;

  error_code = status2.error_code;
  where = status2.where;
  message = status2.message; 

  return *this;
}

bool status::operator== (const status& status2)
{
  if (error_code != status2.error_code)
    return false;
  if (where != status2.where)
    return false;
  if (message != status2.message)
    return false;

  return true;
}

