#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << (((x <= 2 && y >= 2) || (x >= 5 && y <= -3)) ? "Inside" : "Outside");
  return 0;
}