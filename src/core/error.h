#ifndef _ERROR_H_
#define _ERROR_H_I

#include <string>

using std::string; 



enum ErrorLevel : short int
{
  runtime = 2,
  io = 1, 
  ok = 0,
  critial = -1,
  fatal = -2
};



typedef struct status
{
  ErrorLevel status;
  string where;
  string message;
} status;



class Error
{
  private:
    /* DATA */
    static Error instance; // This hold  the only instance of this class in the entire program.

    /* INTERNAL METHODS */
    Error(){}
    status IStatus(ErrorLevel error, string where, string message);
    status IStatus(string where, string message); // Default runtime error.
    status IOk(); // Return a ok status.
   

  public:
    //Error(const &Error) = delete;

    /* PUBLIC INTERFACE */
    static Error& Get() { return instance; }
    static status Status(ErrorLevel error, string where, string message);
    static status Status(string where, string message);
    static status Ok();
};

#endif

