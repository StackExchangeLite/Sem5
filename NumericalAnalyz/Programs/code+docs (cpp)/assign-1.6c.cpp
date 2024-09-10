// Created by SoloMazer
// Question:
  // Create the matrix as in the output of this program.
// Algorithm:
  // The code generates a square matrix of size n where each element is (2 + i)^j,
  // with i as the row index and j as the column index. It formats and prints the 
  // matrix with proper alignment to display powers of increasing bases starting from 2.

#include <cmath>    // for std::pow
#include <iomanip>  // for std::setw
#include <iostream>

int main() {
  int size{};

  // Ask the user for the size of the matrix
  std::cout << "Enter the size of the square matrix: ";
  std::cin >> size;

  // Check for valid input
  if (size <= 0) {
    std::cerr << "Matrix size must be a positive integer." << std::endl;
    return 1;
  }

  // Create and print the matrix
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      // Base is 2 + i and exponent is j
      int base = 2 + i;
      int exponent = j;
      int value = std::pow(base, exponent);
      // Print the value with width for alignment
      std::cout << std::setw(10) << value;
    }
    std::cout << std::endl;
  }

  return 0;
}
