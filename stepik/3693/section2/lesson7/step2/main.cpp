#include <iostream>

int main() {
  int a1, a2, a3, a4, a5;
  std::cin >> a1 >> a2 >> a3 >> a4 >> a5;
  std::cout << (a1 + 1) % 2 << " " << (a2 + 1) % 2 << " " << (a3 + 1) % 2 << " " << (a4 + 1) % 2 << " " << (a5 + 1) % 2;
  return 0;
}