// Created by SoloMazer
// Factorial calculator (basic version)
#include <iostream>

int main() {
  // Defining n (to find n factorial)
  int n{};
  std::cout << "Enter n: ";
  std::cin >> n;

  // Check for non-negative input
  if (n < 0) {
    std::cout << "Factorial is not defined for negative numbers." << std::endl;
    return 1;  // Exit with error code
  }

  int nf{1};  // Variable to hold the factorial result
  while (n > 1) {
    nf *= n;  // Multiply the current value of n to nf
    n--;      // Decrease n after every loop
  }

  // Outputing the the result of factorial
  std::cout << " n Factorial is: " << nf << std::endl;

  return 0;
}
