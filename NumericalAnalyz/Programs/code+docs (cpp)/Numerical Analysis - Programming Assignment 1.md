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

int main(){

	// Defining n (to find n factorial)
	int n{};
	std::cout << "Enter n: ";
	std::cin >> n;
	
	// Check for non-negative input
	if (n < 0) {
		std::cout << "Factorial is not defined for negative numbers." << std::endl;
		return 1; // Exit with error code
	}
	
	int nf{1}; // Variable to hold the factorial result
	
	while (n > 1) {
		nf *= n; // Multiply the current value of n to nf
		n--; // Decrease n after every loop
	}
	
	// Outputing the the result of factorial
	std::cout << " n Factorial is: " << nf << std::endl;
	
return 0;
}
```

###### 3. Write code to convert given integer number to Binary representation. Test your code over 100 and 110.

```cpp

```

4.

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