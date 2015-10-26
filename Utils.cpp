#ifndef Utils_cpp
#define Utils_cpp

#include <iostream>

bool debugging = false;

int char2int(char input){
  /**** debugging purpose ****/
  if(input < 'A' || input > 'Z' || input == ' ' ||
      input == '\t' || input == '\r' || input == '\n'){
    std::cout
      << "unallowed char '" << input << 
      "' is detected, check Utils.cpp char2int method" << std::endl;

  }

  return input - 'A';
}

char int2char(int input){
  if(input < 0 || input >= 26){
    std::cout
      << "Utils.cpp -> char2int, input, " << input << ", out of range." << std::endl;
  }
  return input + 'A';
}

void swap(int *xs, int tis, int tat){
  int temp = xs[tis];
  xs[tis] = xs[tat];
  xs[tat] = temp;
}


#endif
