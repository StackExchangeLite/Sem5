##### All of the code used here is available on a public github repository here:  [MAT314-NA-progAssign1](https://github.com/StackExchangeLite/Sem5/tree/solomazer/NumericalAnalyz/Programs/code%2Bdocs%20(cpp))
###### 1. Write a code to generate Fibonacci series up to 20 terms with t1 = 0, t2 = 1. Following is my cpp code to produce the result.

```cpp
// Created by SoloMazer
// Fibonnaci series generator

#include <iostream>
int main(){

  //defining the maximum limit of fibonacci
  int n{};
  std::cout << "Enter the maximum limit for terms in fibonacci: ";
  std::cin >> n;

  // Checking for non-negative output
  if (n < 0){
	std::cout << "Fibonacci is not defined for negative numbers." << std::endl;
    return 1;
  }

  //variables for terms of fibonacci
  int t1{};
  int t2{1};
  int t3{};

  while (t3 < n){
      
      //Defining third term as it is in fibonacci sequence
      t3 = t1 + t2;
      
      if (t3 < n) {  
        // Only print if t3 is less than n
        std::cout << t3 << std::endl; 
      }
      
      //while loop update conditons
      t1 = t2;
      t2 = t3;
  }
  return 0;
}

```

###### 2. Write code to generate n factorial for n = 10.

```cpp
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
```

###### 3. Write code to convert given integer number to Binary representation. Test your code over 100 and 110.

```cpp
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

```

###### 4. Write code to convert given fractional number to Binary representation

```cpp
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
```

###### 5. Write code to compute the Taylor series of exp(x) upto 10 terms (x0 = 0) at x = 1, and compare the result with the exact value of exp(1). 
```cpp
// Created by SoloMazer
// Question: 
	// Compute the taylor series of exp(x) upto 10 terms (x_0 = 0) at x = 1, and compare the result with the exact value of exp(1).
// Algorithm: 
	// The taylor series expansion of exp(x) at x = 1, is equal to 1 + 1/1! + 1/2! + 1/3! + ... + 1/n! 
	// We use this fact to compute the factorials using a factorial function and store their inverses as terms of the taylor series. 
	// Keep iterating the process until number of terms = max limit of terms given by the user. Add all these terms and print the result.

#include <iostream>

// Fetching required terms in taylor expansion
int getUserInput(){
	int userInput{};
	std::cout << "Enter max number of terms: ";
	std::cin >> userInput;
	return userInput;
}

// Factorial Calculator (refer assign-1.2.cpp)
double factorial(double k){
	// Variable to hold the factorial result is initialised with 1
	// to prevent all factorials collapsing to zero, since 0 x (any number) = 0.
	double kf{1};
	
	while (k > 1) {
		kf *= k; // Multiply the current value of k to kf
		k--; // Decrease n after every loop
	}
	return kf;
}

int main(){
	//Calling the getUserInput function and storing the return value in numOfTerms
	int numOfTerms{getUserInput()};
	
	// Check for non-negative input
	if (numOfTerms < 0) {
		std::cout << "Numbers of terms in a taylor series can't be negative. \n Please input a non-negative number." << std::endl;
	}
	
	else {
		// Creating a variable to store the sum of terms in taylor series
		// Initialised with 1, cause the expansion starts with 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
		// In a sense this is accounting for the fact that 0! = 1.
		double exp_x{1};
		
		// For loop to compute the terms of taylor series
		for (int i = 1; i <= numOfTerms; i++) {
			// Defining a variable to hold each term of the series
			double kthTerm{1 / factorial(i)};
			// update condition to sum these terms
			exp_x = exp_x + kthTerm;
		}
		  
		// Printing the result
		std::cout << "The Taylor Series Approximation of exp(x) upto "<< numOfTerms << " Terms is: " << exp_x << '\n';
		// Comparing with the exact value of exp(1)
		std::cout << "The absolute error is: " << 2.71828 - exp_x << '\n';
		std::cout << "The relative error is: " << (2.71828 - exp_x) / 2.71828;
	}
return 0;
}
```

###### 6. a) Create the matrix as in the output of this program
```cpp
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
  const int rows{10};
  const int cols{10};

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
```

###### 6. b) Create the matrix as in the output of this program
```cpp
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
```

###### 6. c) Create the matrix as in the output of this program
```cpp
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
```

