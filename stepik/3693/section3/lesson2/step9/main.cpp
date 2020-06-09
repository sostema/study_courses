#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << (a > 0 && b < 0 && c < 0 ? "YES" : (a < 0 && b > 0 && c < 0 ? "YES" : (a < 0 && b < 0 && c > 0 ? "YES"
                                                                                                              : "NO")));
  return 0;
}