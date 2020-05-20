#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << 18 * a * a - 4 * (a * a - 2 * a * b + b * b) * (a * a - 2 * a * b + b * b) - 4 * a * c + c * c;
  return 0;
}