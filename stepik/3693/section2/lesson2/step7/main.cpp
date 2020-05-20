#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << a * 100 + b * 10 + c << std::endl;
  std::cout << a * 100 + b + c * 10 << std::endl;
  std::cout << a * 10 + b * 100 + c << std::endl;
  std::cout << a + b * 100 + c * 10 << std::endl;
  std::cout << a * 10 + b + c * 100 << std::endl;
  std::cout << a + b * 10 + c * 100 << std::endl;

  return 0;
}