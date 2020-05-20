#include <iostream>

int main() {
  int a, b, c;
  int r1, r2, r3;
  std::cin >> a >> b >> c;
  r1 = (a * b * c * c + a * b * b * c + a * b * c * c);
  r2 = (3 * a * a - 2 * b * b * b + 4 * c * c);
  r3 = (5 * a * b + a * a * b * b * c * c - 6);
  std::cout << r1 << std::endl << r2 << std::endl << r3 << std::endl << r1 * r1 - 4 * r2 * r2 + r3 * r3;
  return 0;
}