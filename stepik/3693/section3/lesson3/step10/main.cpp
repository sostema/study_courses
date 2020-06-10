#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << (((x <= -5) || (x >= 6) || (x >= -2 && x <= 3 && y > 3)) ? "Inside" : "Outside");
  return 0;
}