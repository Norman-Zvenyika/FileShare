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

// u32 serialization
vec pack109::serialize(u32 item){
  vec bytes; // 1 tag byte + 4 int byes
  bytes.push_back(PACK109_U32);
  int i = (sizeof(u32) * 2) - 2;
  for (i; i >= 0; i -= 2){
    int shift = (item >> i * 4);
    u8 byte = shift & 0x000000FF;
    bytes.push_back((u8)byte);
  }
  return bytes;
}

//u32 deserialization
u32 pack109::deserialize_u32(vec bytes) {
  u32 result = 0;
  if (bytes[0] == PACK109_U32){
    int j = (sizeof(u32) * 2) - 2;
    for (int i = 1; i <= sizeof(u32); i++){
      u32 shifted = (u32)bytes[i] << j * 4;
      result = result | shifted;
      j -= 2;
    }
    return result;
  }
  else{
    throw;
  }
}

//u64 serialization
vec pack109::serialize(u64 item) {
  vec bytes;
  bytes.push_back(PACK109_U64);
  for(int i= 7; i>=0;i--) {
    u64 shifted = item >> (8 * i);
    bytes.push_back((u8) shifted & 0x00000000000000FF);
  }
  return bytes;
}

//u64 deserialize
u64 pack109::deserialize_u64(vec bytes) {
  u64 result = 0;
  if(bytes[0] == PACK109_U64) {
    int posOfByte = 1;
    for(int i=7; i>=0; i--) {
      u64 shifted = (u64)(bytes[posOfByte]) << (8*i);
      result = result | shifted;
      posOfByte++;
    }
    return result;
  }
  else {
    throw;
  }
}

//i8 serialize
vec pack109::serialize(i8 item) {
  vec bytes;
  bytes.push_back(PACK109_I8);
  bytes.push_back((u8)item);   //size of i8 is 1 byte, which is equivalent to u8
  return bytes;
}