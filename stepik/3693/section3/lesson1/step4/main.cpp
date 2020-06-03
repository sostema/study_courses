#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << (n%10==9 ? "YES" : "NO");
  return 0;
}