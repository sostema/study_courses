#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << (((x >= 4) || (y >= 3)) ? "Inside" : "Outside");
  return 0;
}