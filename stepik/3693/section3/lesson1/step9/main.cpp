#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << ((n / 10) % 2 == n % 2 ? "YES" : "NO");
  return 0;
}