#ifndef Plugboard_cpp
#define Plugboard_cpp

#include <iostream>
#include <fstream>

#include "Plugboard.hpp"

#include "../Constants.hpp"
#include "../Utils.hpp"

Plugboard::Plugboard(char *filename){
//  std::cout << "reading some plugboard " << filename << std::endl;
  /**** set all mappings_offset to -1 which identify there is no mapping ****/
  for (int i=0; i<NUM_OF_ALPHABETS; i++){
    this->mappings_offset[i] = 0;
  }

  std::ifstream plugboardfile(filename);
  if(!plugboardfile.is_open()){
    throw "failed to open file";
  }

  int temp, temp2;
  while(plugboardfile >> temp >> temp2){ 
    int offset = temp2 - temp;
    this->mappings_offset[temp] = offset;
    this->mappings_offset[temp2] = -(offset);
  }
}

int Plugboard::map(int input){
  if(debugging){
    std::cout << "Plugboard maps " << input << "=>" << input + this->mappings_offset[input] << std::endl;
  }
  return input + this->mappings_offset[input];
}

int Plugboard::unmap(int input){
  if(debugging){
    std::cout << "Plugboard unmaps " << input << "=>" << input + this->mappings_offset[input] << std::endl;
  }
  return map(input);
}

void Plugboard::showPlugboard(){
  /* for debugging purpose, shows plugboard mapping */
  for (int i=0; i<NUM_OF_ALPHABETS; i++){
    int mapped = this->map(i);
    std::cout << int2char(i) << "(" << i << ") -> " <<
      int2char(mapped) << "(" << mapped << ")" << std::endl;
  }
}

#endif
