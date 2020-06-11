#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << ((x <= -5 && y >= -7) ? "Inside" : "Outside");
  return 0;
}