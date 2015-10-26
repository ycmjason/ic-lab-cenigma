#ifndef Enigma_cpp
#define Enigma_cpp

#include "Enigma.hpp"
#include "Plugboard.hpp"
#include "RotorConnector.hpp"
#include "Reflector.hpp"

#include "../Utils.hpp"

Enigma::Enigma(int numberOfRotors){
  this->rotorConnector = new RotorConnector(numberOfRotors);
  this->reflector = new Reflector();
}

Enigma::~Enigma(){
  delete this->plugboard;
  delete this->rotorConnector;
  delete this->reflector;
}


void Enigma::setPlugboardByFilename(char *filename){
  try{
    this->plugboard = new Plugboard(filename);
  }catch(...){
    throw;
  }
}

void Enigma::addRotorByFilename(char *filename){
  this->rotorConnector->addByFilename(filename);
}

char Enigma::encrypt(char input){

  // encrypt by plugboard
  int output = this->plugboard->map(char2int(input));
  // encrypt by rotors
  output = this->rotorConnector->map(output);
  // reflect
  output = this->reflector->reflect(output);
  // decrypt by rotors
  output = this->rotorConnector->unmapAndRotate(output);
  // decrypt by plugboard
  output = this->plugboard->unmap(output);

  return int2char(output);
}

#endif
