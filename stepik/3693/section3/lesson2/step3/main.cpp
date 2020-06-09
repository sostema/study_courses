#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << ((a == b || b == c || a == c) ? "NO" : "YES");
  return 0;
}