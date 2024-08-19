// Created by SoloMazer
// Question: 
  // Compute the taylor series of exp(x) upto 10 terms (x_0 = 0) 
  // at x = 1, and compare the result with the exact value of exp(1).
// Algorithm: 
  // The taylor series expansion of exp(x) at x = 1, is equal to 
  // 1 + 1/1! + 1/2! + 1/3! + ... + 1/n! We use this fact to compute the
  // factorials using a factorial function and store their inverses as 
  // terms of the taylor series. Keep iterating the process until number 
  // of terms = max limit of terms given by the user. Add all these terms 
  // and print the result.

#include <iostream>

// Fetching required terms in taylor expansion
int getUserInput(){
   int userInput{};
   std::cout << "Enter number of terms in the taylor expansion:\n ";
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
     std::cout << "Numbers of terms in a taylor series can't be negative. \nPlease input a non-negative number." << std::endl;
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
