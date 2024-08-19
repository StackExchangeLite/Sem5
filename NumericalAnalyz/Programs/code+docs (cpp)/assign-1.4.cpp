// Created by SoloMazer
// Question:
  // Write cpp code to convert given fractional number to Binary representation
// Algorithm:
  // This C++ code converts a fractional number to binary by separately converting
  // its integer and fractional parts and then combining them, allowing for a
  // specified precision in the fractional part.

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Function to convert the integer part of a number to binary
std::string intToBinary(int number) {
  std::string binaryString;
  if (number == 0) return "0";
  while (number > 0) {
    binaryString = std::to_string(number % 2) + binaryString;
    number /= 2;
  }
  return binaryString;
}

// Function to convert the fractional part of a number to binary
std::string fractionToBinary(double fraction, int precision = 10) {
  std::string binaryString;
  while (fraction > 0 && binaryString.length() < precision) {
    fraction *= 2;
    if (fraction >= 1) {
      binaryString += '1';
      fraction -= 1;
    } else {
      binaryString += '0';
    }
  }
  return binaryString;
}

std::string floatToBinary(double number, int precision = 10) {
  int intPart = static_cast<int>(number);
  double fracPart = number - intPart;

  std::string binaryInteger = intToBinary(intPart);
  std::string binaryFraction = fractionToBinary(fracPart, precision);

  if (binaryFraction.empty()) return binaryInteger;
  return binaryInteger + '.' + binaryFraction;
}

int main() {
  double number;
  int precision;

  std::cout << "Enter a fractional number: ";
  std::cin >> number;

  std::cout << "Enter precision for fractional part (number of bits): ";
  std::cin >> precision;

  std::string binaryRepresentation = floatToBinary(number, precision);
  std::cout << "Binary representation: " << binaryRepresentation << std::endl;

  return 0;
}
