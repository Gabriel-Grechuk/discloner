#ifndef _CLONER_H_
#define _CLONER_H_

#include <cstddef>
#include <string>

#include "error.h"


using std::string;
using std::size_t;



// I'm goin to use the singleton pattern. So you cannot instantiate this class,
// but can access it from anywhere.
class Cloner
{
  private:
    /* DATA */
    static Cloner instance; // The only instance of this class in the entire program.

    string InputFile;
    string OutputFile;
    size_t BlockSize;


    /* INTERNAL METHODS */
    Cloner();

    // Getters.
    string IGetInputFile() { return InputFile; }
    string IGetOutputFile() { return OutputFile; }
    string IGetBlockSize() { return BlockSize; }

    // Setters.
    status ISetInputFile(const string& file);
    status ISetOutputFile(const string& file);
    status ISetBlockSize(size_t size);

    // Validates the internal data before running.
    status IValidateData();

    // Runs and stops the Cloner.
    status IRun();
    status IStop();

  public:
    // Making sure that it can't be initiated by a copy constructor.
    Cloner(const Cloner&) = delete;
    Cloner& operator= (const Cloner&) = delete;

    /* PUBLIC INTERFACE */
    static Cloner& Get(){ return instance; }

    // Public setters.
    static status InputFile(const string& file);
    static status OutputFile(const string& file);
    static status BlockSize(size_t size);
    
    // Public
    static string InputFile();
    static string OutputFile();
    static size_t BlockSize();

    static status Run();
    static status Stop();
};


#endif

