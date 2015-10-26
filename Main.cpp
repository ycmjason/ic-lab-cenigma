#include <stdexcept>
#include <iostream>

#include "classes/Enigma.hpp"
#include "Utils.hpp"

int main(int argc, char **argv){
  const int ROTOR_COUNT = argc-2;
  Enigma enigma(ROTOR_COUNT);
  try{
    enigma.setPlugboardByFilename(argv[argc-1]);
  }catch(char *msg){
    std::cout << msg << std::endl;
  }
  for(int i = 1; i <= ROTOR_COUNT; ++i){
    enigma.addRotorByFilename(argv[i]);
  }

  /**** main loop for enigma ****/
  char input;
  while(std::cin >> input){
    // skip the space characters
    if(input ==  ' ' || input == '\t' ||
       input == '\r' || input == '\n'){
      std::cout << input;
      continue;
    }

    std::cout << enigma.encrypt(input);
  }

  /**** clean up memory prevent memory leak ***/

  return 0;
}
