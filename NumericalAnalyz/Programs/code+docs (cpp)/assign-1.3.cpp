// Created by stellarterror
// Question:
  // Write cpp code to convert given integer number to Binary representation.
// Algorithm:
  // This C++ code converts an integer to its binary representation by using a 
  // std::bitset to create a 32-bit binary string, then removing leading zeros 
  // for a clean output. It handles edge cases like zero by ensuring it outputs
  // "0" if necessary.

#include <bitset>
#include <iostream>
#include <string>

std::string intToBinary(int number) {

  // Use bitset to convert the integer to binary representation
  std::bitset<32> binary(number);
  
  // Convert the bitset to string and remove leading zeros
  std::string binaryString = binary.to_string();
  
  // Remove leading zeros for cleaner output
  size_t firstOne = binaryString.find('1');
  
  if (firstOne != std::string::npos) {
    binaryString = binaryString.substr(firstOne);
  } else {
    binaryString = "0";  // In case of zero
  }
  
  return binaryString;
}

int main() {

  int number;
  std::cout << "Enter an integer: ";
  std::cin >> number;

  std::string binaryRepresentation = intToBinary(number);
  std::cout << "Binary representation: " << binaryRepresentation << std::endl;

  return 0;
}
