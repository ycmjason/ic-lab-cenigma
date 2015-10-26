#ifndef RotorConnector_cpp
#define RotorConnector_cpp

#include <iostream>

#include "RotorConnector.hpp"
#include "Rotor.hpp"

RotorConnector::RotorConnector(int size){
  this->max = size;
  this->size = 0;
  this->rotors = new Rotor*[size];
}
RotorConnector::~RotorConnector(){
  delete this->rotors;
}

void RotorConnector::addByFilename(char *filename){
  if(this->size >= max){
    std::cout << "Connector reaches the maximum size" << std::endl;
    return;
  }
  this->rotors[this->size++] = new Rotor(filename);
}

void RotorConnector::rotate(){
  if(this->size > 0){
    int i=0;
    do{
      rotors[i]->rotate();
    } while(rotors[i]->isCompleteRotation() && ++i < this->size);
  }
}

int RotorConnector::map(int input){
  for(int i = 0; i < this->size; ++i){
    input = rotors[i]->map(input);
  }
  return input;
}

int RotorConnector::unmapAndRotate(int input){
  for(int i = this->size-1; i >= 0; --i){
    input = rotors[i]->unmap(input);
  }
  this->rotate();
  return input;
}

#endif
