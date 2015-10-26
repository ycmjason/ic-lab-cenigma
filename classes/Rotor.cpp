#ifndef Rotor_cpp
#define Rotor_cpp

#include <iostream>
#include <fstream>

#include "Rotor.hpp"

#include "../Constants.hpp"
#include "../Utils.hpp"

Rotor::Rotor(char *filename):rotation_count(0){
//  std::cout << "reading some rotor " << filename << std::endl;

  std::ifstream rotorfile(filename);
  for(int i = 0; i < NUM_OF_ALPHABETS; ++i){
    int iMapsTo;
    rotorfile >> iMapsTo;
    this->mappings_offset[i] = iMapsTo - i;
    this->unmappings_offset[iMapsTo] = i - iMapsTo;
  }
  if(debugging){
    this->showRotor();
  }
}

int Rotor::map(int input){
  int output = (input + this->mappings_offset[input] + NUM_OF_ALPHABETS) % NUM_OF_ALPHABETS;
  if(debugging){
    std::cout << "Rotor maps " << int2char(input) << "(" << input << ") => " <<
      int2char(output) << "(" << output << ")" << std::endl;
  }
  return output;
}

int Rotor::unmap(int input){
  int output = (input + this->unmappings_offset[input] + NUM_OF_ALPHABETS) % NUM_OF_ALPHABETS;
  if(debugging){
    std::cout << "Rotor unmaps " << int2char(input) << "(" << input << ") => " <<
      int2char(output) << "(" << output << ")" << std::endl;
  }
  return output;
}

void Rotor::rotate(){
  for(int i = 0; i < 25; ++i){
    swap(this->mappings_offset, i, i+1);
    swap(this->unmappings_offset, i, i+1);
  }
  this->rotation_count = (this->rotation_count + 1) % 26;
  /*if(debugging){
    this->showRotor();
  }*/
}

bool Rotor::isCompleteRotation(){
  return (this->rotation_count == 0);
}

/**** debugging purpose ****/
void Rotor::showRotor(){
  for(int i = 0; i < 26; ++i){
    int mapped = this->map(i);
  }
}

#endif
