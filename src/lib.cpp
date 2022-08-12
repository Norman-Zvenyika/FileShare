//cite homwork 8
#include <vector>
#include <stdio.h>
#include <ostream>
#include <iostream>
#include <sstream>
#include "pack109.hpp"
using namespace std;

//bool serialization
vec pack109::serialize(bool item)
{
  vec bytes;
  if (item == true){
    bytes.push_back(PACK109_TRUE);
  }
  else{
    bytes.push_back(PACK109_FALSE);
  }
  return bytes;
}