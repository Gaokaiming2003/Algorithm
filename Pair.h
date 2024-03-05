#ifndef PAIR_H
#define PAIR_H
#include<iostream>

struct Pair
{
   int key;
   std::string val;
   Pair(int key, std::string val){
      this -> key = key;
      this -> val = val;
   }
};

#endif
