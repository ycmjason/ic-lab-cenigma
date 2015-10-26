#ifndef Plugboard_hpp
#define Plugboard_hpp

#include "../Constants.hpp"

class Plugboard{
  public:
    Plugboard(char *filename);
    int map(int input);
    int unmap(int input);
    /**** debugging purpose ****/
    void showPlugboard();
  private:
    int mappings_offset[NUM_OF_ALPHABETS];
};

#endif
