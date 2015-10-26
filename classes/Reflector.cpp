#ifndef Reflector_cpp
#define Reflector_cpp

#include <iostream>

#include "Reflector.hpp"
#include "../Utils.hpp"

Reflector::Reflector(){
}

int Reflector::reflect(int input){
  if(debugging){
    std::cout << "Reflector reflects " << input << " to " << (input+13)%26 << std::endl;
  }
  return (input+13)%26;
}

#endif
