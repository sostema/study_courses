#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << (a == b ? "YES" : (b == c ? "YES" : (a == c ? "YES" : "NO")));
  return 0;
}