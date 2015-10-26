#ifndef Enigma_hpp
#define Enigma_hpp

#include "Plugboard.hpp"
#include "RotorConnector.hpp"
#include "Reflector.hpp"

class Enigma{
  public:
    Enigma(int numberOfRotors);
    ~Enigma();
    void setPlugboardByFilename(char *filename);
    void addRotorByFilename(char *filename);
    char encrypt(char input);
  private:
    Plugboard *plugboard;
    RotorConnector *rotorConnector;
    Reflector *reflector;
};

#endif
