// Created by SoloMazer
// Question:
  // Create the matrix as in the output of this program.
// Algorithm:
  // The code generates a square matrix where the main diagonal contains 2,
  // the elements immediately off the diagonal are -1, and all other
  // elements are 0. The size of the matrix is specified by the user,
  // and the matrix is printed with proper alignment.

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
      if (i == j) {
        // Main diagonal
        std::cout << std::setw(4) << 2;
      } else if (std::abs(i - j) == 1) {
        // Off-diagonals
        std::cout << std::setw(4) << -1;
      } else {
        // All other elements
        std::cout << std::setw(4) << 0;
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
