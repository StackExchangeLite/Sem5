// // Created by SoloMazer
// // Integer to Binary converter
// #include <iostream>
// #include <vector>

// int main() {
//    // Take decimal user input
//    int x{};
//    std::cout << "Enter your integer: ";
//    std::cin >> x;

//    if (x == 0) {
//       std::cout << "Binary: 0" << std::endl;
//       return 0;
//    }

//    std::vector<int> binary; // Vector to store binary digits

//    // Convert decimal to binary
//    while (x > 0) {
//       binary.push_back(x % 2); // Store the remainder (0 or 1)
//       x /= 2; // Divide x by 2
//    }

//    // Output the binary representation (reverse the vector)
//    std::cout << "Binary: ";
//    for (auto it = binary.rbegin(); it != binary.rend(); ++it) {
//       std::cout << *it; // Print from last to first to get correct order
//    }
//    std::cout << std::endl;

//    return 0;
// }

