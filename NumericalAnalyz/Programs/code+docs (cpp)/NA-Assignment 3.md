###### Following is my implementation of *regula-falsi* method, as mentioned in the third question of assignment 3 for the function $\sin(x) + x^2 -1$ .
```cpp
#include <cmath>
#include <iostream>

double f(double x) { return std::sin(x) + x * x - 1; }

int main() {

  double a{}, b{};
  std::cout << "Enter the lower bound of [a, b]: ";
  std::cin >> a;
  std::cout << "Enter the upper bound of [a, b]: ";
  std::cin >> b;

  uint n{0};
  double tol{std::numeric_limits<double>::epsilon()};

  if (f(a) * f(b) >= 0) {
    std::cout << "Invalid bounds, intersection with x-axis is not forced in "
                 "the interval.\n";
    return EXIT_FAILURE;
  } else {
    while (true) {

      double x{a - (f(a) * (a - b)) / (f(a) - f(b))};

      if (f(x) == 0) {
        std::cout << "Solution is: ( " << x << ", " << f(x) << ")\n";
        return 0;
      } else if (fabs(f(x)) < tol) {
        std::cout << "Approx solution is: ( " << x << ", " << f(x) << ")\n";
        return 0;
      } else if (f(a) * f(x) < 0) {
        b = x;
      } else {
        a = x;
      }
      n++;
      std::cout << "Iteration: " << n << "\n";
    }
  }
  return 0;
}
```

###### Following output was obtained:
```
Enter the lower bound of [a, b]: 0
Enter the upper bound of [a, b]: 2
Iteration: 1
Iteration: 2
Iteration: 3
Iteration: 4
Iteration: 5
Iteration: 6
Iteration: 7
Iteration: 8
Iteration: 9
Iteration: 10
Iteration: 11
Iteration: 12
Iteration: 13
Iteration: 14
Iteration: 15
Iteration: 16
Iteration: 17
Iteration: 18
Iteration: 19
Iteration: 20
Iteration: 21
Iteration: 22
Iteration: 23
Iteration: 24
Iteration: 25
Iteration: 26
Iteration: 27
Iteration: 28
Approx solution is: ( 0.636733, -1.11022e-16)
```