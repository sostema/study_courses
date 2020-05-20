#include <iostream>

int main() {
  int a, b;

  std::cin >> a >> b;
  int c = (a * a - b) * (a * a - b) - 4 * a * (b * b) + 4 * ((a * a * a) - 5) * ((a * a * a) - 5);
  std::cout << c;
  return 0;
}