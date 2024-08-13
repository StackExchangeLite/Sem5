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