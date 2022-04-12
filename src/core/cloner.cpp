#include "cloner.h"

Cloner Cloner::instance;


/* INTERNAL METHODS */
Cloner::Cloner()
{
  InputFile = "";
  OutputFile = "";
  BlockSize = 512;
}

status Cloner::ISetInputFile(const string& file)
{
  if (file == "")
    return  Error::Status(io, "Cloner::ISetInputFile()", "Input file path can't be empty");
  else
    InputFile = file;

  return Error::Ok();
}

status Cloner::ISetOutputFile(const string& file)
{
  if (file == "")
    return  Error::Status(io, "Cloner::ISetOutputFile()", "Output file path can't be empty");
  else
    OutpurFile = file;
}

status Cloner::ISetBlockSize(size_t size)
{
  if(size <= 0)
    return Error::Status(critical, "Cloner::ISetBlockSize()", "BlockSize Can't be zero or negative.");
  else
    BlockSize = size;
  
  return Error::Ok();
}

status Cloner::IValidateData()
{
  if (InputFile == "")
    return Error::Status(io, "Cloner::IValidateData()", "Input file path can't be empty.");
  if (OutputFile == "")
    return Error:Status(io, "Cloner::IValidateData()", "Output file path can't be empty.");
  if (BlockSize <= 0)
    return Error::Status(critical, "ClonerIValidate()", "Block size can't be less or equal to 0.");

  return Error::Ok();
}

status Cloner::IRun()
{
  // TODO.
}

status Cloner::IStop()
{
  // TODO.
}



/* PUBLIC INTERFACE  */
status Cloner::InputFile(const string& file) { return Get().ISetInputFile(file); }
status Cloner::OutputFile(const string& file) { return Get().ISetOutputFile(file); }
status Cloner::ISetBlockSize(size_t size) { return Get().ISetBlockSize(size); }
string Cloner::InputFile() { return Get().IGetInputFile(); }
string Cloner::OutputFile() { return Get().IGetOutputFile(); }
string Cloner::BlockSize() { return Get().IGetBlockSize(); }
status Cloner::Run() { return Get().IRun(); }
status Cloner::Stop() { return Get().IStop(); }