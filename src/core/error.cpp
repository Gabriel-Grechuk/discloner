#include <string>

#include "error.h"


// Defines the only instance of this class in the entire program. 
Error Error::instance;


/* INTERNAL METHODS */
status Error::IStatus(ErrorLevel error, string where, string message)
{
  status ThisError;

  ThisError.status = error;
  ThisError.where = where;
  ThisError.message = message;

  return ThisError;
}


status Error::IStatus(string where, string message)
{
  status ThisError;

  ThisError.status = runtime; // Runtime error for default.
  ThisError.where = where;
  ThisError.message = message;

  return ThisError;
}


status Error::IOk()
{
  status ThisError;

  ThisError.status = ok;
  ThisError.where = "";
  ThisError.message = "";

  return ThisError;
}



/* PUBLIC INTERFACE */
status Error::Status(ErrorLevel error, string where, string message)
{
  return Get().IStatus(error, where, message);
}


status Error::Status(string where, string message)
{
  return Get().IStatus(where, message);
}


status Error::Ok()
{
  return Get().IOk();
}

