#include <iostream>

int main() {
  int a;
  std::cin >> a;
  std::cout << ((a / 1000 == 0 && a / 100 > 0 && a % 2 == 0) ? "YES" : "NO");
  return 0;
}