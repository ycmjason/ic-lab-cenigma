#ifndef RotorConnector_hpp
#define RotorConnector_hpp

#include "Rotor.hpp"

class RotorConnector{
  public:
    RotorConnector(int size);
    ~RotorConnector();
    void addByFilename(char* filename);
    void rotate();
    int map(int input);
    int unmapAndRotate(int input);
  private:
    Rotor **rotors;
    int max;
    int size;
};

#endif
