#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << "100: " << n / 100 << std::endl
            << "50: " << (n % 100) / 50 << std::endl
            << "10: " << ((n % 100) % 50) / 10 << std::endl;
  return 0;
}