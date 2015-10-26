#ifndef Rotor_hpp
#define Rotor_hpp

#include "../Constants.hpp"

class Rotor{
  public:
    Rotor(char *filename);
    int map(int input);
    int unmap(int input);
    void rotate();
    bool isCompleteRotation();
    /**** debugging purpose ****/
    void showRotor();
  private:
    int mappings_offset[NUM_OF_ALPHABETS];
    int unmappings_offset[NUM_OF_ALPHABETS];
    int rotation_count;
};

#endif
