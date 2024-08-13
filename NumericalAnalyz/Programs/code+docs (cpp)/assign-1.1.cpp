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
