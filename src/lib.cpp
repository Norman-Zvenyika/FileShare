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

//bool deserialization
bool pack109::deserialize_bool(vec bytes){
  if (bytes.size() < 1){
    throw;
  }
  if (bytes[0] == PACK109_TRUE){
    return true;
  }
  else if (bytes[0] == PACK109_FALSE){
    return false;
  }
  else{
    throw;
  }
}

//u8 serialization
vec pack109::serialize(u8 item){
  vec bytes;
  bytes.push_back(PACK109_U8);
  bytes.push_back(item);
  return bytes;
}

//u8 deserialization
u8 pack109::deserialize_u8(vec bytes){
  if (bytes.size() < 2){
    throw;
  }
  if (bytes[0] == PACK109_U8){
    return bytes[1];
  }
  else{
    throw;
  }
}