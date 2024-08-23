// Created by SoloMazer
// Question:
  // Create the matrix as in the output of this program
// Algorithm:
  // The code generates a 10x10 matrix of fractions where each element is 1/(i + j
  // - 1), with i and j as row and column indices. It uses nested loops to compute
  // each fraction and prints them with 8 decimal places for precision, ensuring
  // proper alignment with std::setw(12). After completing each row, it moves to
  // the next, producing a well-formatted matrix of fractional values.

#include <iomanip>  // for std::setw, std::fixed, std::setprecision
#include <iostream>

int main() {
  const int rows{ 10 };
  const int cols{ 10 };

  // Create and fill the matrix
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= cols; ++j) {
      // Calculate the numerator and denominator
      int numerator = 1;
      int denominator = i + j - 1;

      // Print the fraction in the format 1/x with high precision
      std::cout << std::setw(12) << std::fixed << std::setprecision(8)
        << static_cast<double>(numerator) / denominator;
    }
    std::cout << std::endl;
  }

  return 0;
}
