#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << (y >= -2 ? "Inside" : "Outside");
  return 0;
}